#ifndef __UNIKEY_DLG_MACRO_TABLE_H__
#define __UNIKEY_DLG_MACRO_TABLE_H__

#include <gtk/gtk.h>

#include "mactab.h"

GtkWidget* unikey_macro_dialog_new();
void unikey_macro_dialog_load_macro(GtkDialog* dialog, CMacroTable macro);
void unikey_macro_dialog_save_macro(GtkDialog* dialog, CMacroTable* macro);

#endif // __UNIKEY_DLG_MACRO_TABLE_H__
