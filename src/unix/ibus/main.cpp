#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <cstdlib>
#include <cstdio>

#include <libintl.h>
#include <locale.h>

#include <ibus.h>
#include "utils.h"
#include "engine.h"
#include "unikey.h"

static IBusBus* bus         = NULL;
static IBusFactory* factory = NULL;

/* option */
static gboolean xml     = FALSE;
static gboolean ibus    = FALSE;
static gboolean verbose = FALSE;
static gboolean version = FALSE;

static const GOptionEntry entries[] =
{
    { "xml",     'x', 0, G_OPTION_ARG_NONE, &xml,     "generate xml for engines", NULL },
    { "ibus",    'i', 0, G_OPTION_ARG_NONE, &ibus,    "component is executed by ibus", NULL },
    { "verbose", 'v', 0, G_OPTION_ARG_NONE, &verbose, "verbose", NULL },
    { "version", 'V', 0, G_OPTION_ARG_NONE, &version, "print ibus-unikey version", NULL },
    { NULL },
};

static void ibus_disconnected_cb(IBusBus* bus, gpointer user_data)
{
    ibus_quit();
}

static void start_component(void)
{
    GList* engines;
    GList* p;
    IBusComponent* component;

    ibus_init();

    bus = ibus_bus_new();
    g_signal_connect(bus, "disconnected", G_CALLBACK(ibus_disconnected_cb), NULL);

    component = ibus_unikey_get_component();

    factory = ibus_factory_new(ibus_bus_get_connection(bus));

    engines = ibus_component_get_engines(component);
    for (p = engines; p != NULL; p = p->next)
    {
        IBusEngineDesc* engine = (IBusEngineDesc*)p->data;
        ibus_factory_add_engine(factory, ibus_engine_desc_get_name(engine), IBUS_TYPE_UNIKEY_ENGINE);
    }

    if (ibus)
        ibus_bus_request_name(bus, "org.freedesktop.IBus.Unikey", 0);
    else
        ibus_bus_register_component(bus, component);

    g_object_unref(component);

    ibus_unikey_init(bus);
    ibus_main();
    ibus_unikey_exit();
}

int main(gint argc, gchar** argv)
{
    GError* error = NULL;
    GOptionContext* context;

    setlocale(LC_ALL, "");
    bindtextdomain(GETTEXT_PACKAGE, LOCALEDIR);
    textdomain(GETTEXT_PACKAGE);

    context = g_option_context_new("- ibus unikey engine component");

    g_option_context_add_main_entries(context, entries, "ibus-unikey");

    if (!g_option_context_parse(context, &argc, &argv, &error)) {
        g_print("Option parsing failed: %s\n", error->message);
        exit(-1);
    }

    start_component();

    return 0;
}
