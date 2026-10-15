// ui_helpers.h
#ifndef UI_HELPERS_H
#define UI_HELPERS_H

#include <xui.h>
#include <stdbool.h>

/* Fontes */
extern XuiFont *font_bold;
extern XuiFont *font_medium;
extern XuiFont *font_verdana;

void clearScreen(void);
void writeCenterText(XuiWindow *canvas, char *text, int pos_y, int mode,
                     int fontSize, XuiFont *font, bool color_black);
void fontDestroy();
#endif
