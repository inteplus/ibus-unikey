#ifndef __UNIKEY_UTILS_H__
#define __UNIKEY_UTILS_H__

#include <gio/gio.h>

#include "ukengine.h"
#include "engine_const.h"

extern const gchar*          Unikey_IMNames[];
extern const UkInputMethod   Unikey_IM[];
extern const unsigned int    NUM_INPUTMETHOD;
extern const gchar*          Unikey_OCNames[];
extern const unsigned int    Unikey_OC[];
extern const unsigned int    NUM_OUTPUTCHARSET;

IBusComponent* ibus_unikey_get_component();
int latinToUtf(unsigned char* dst, unsigned char* src, int inSize, int* pOutSize);

#define get_macro_file() (g_build_filename(g_getenv("HOME"), UNIKEY_MACRO_FILE, NULL))

gboolean ibus_unikey_config_get_string(GSettings* settings,
                                    const gchar* key,
                                    gchar** result);
void ibus_unikey_config_set_string(GSettings* settings,
                                    const gchar* key,
                                    const gchar* value);

gboolean ibus_unikey_config_get_boolean(GSettings* settings,
                                    const gchar* key,
                                    gboolean* result);
void ibus_unikey_config_set_boolean(GSettings* settings,
                                    const gchar* key,
                                    gboolean value);

#endif // __UNIKEY_UTILS_H__
