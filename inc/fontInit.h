#include "main.h"

void fontInit(void) {
    font_bold    = XuiCreateFont("./res/font/Barlow-Bold.ttf", 0, 0);
    font_medium  = XuiCreateFont("./res/font/Barlow-Medium.ttf", 0, 0);
    font_verdana = XuiCreateFont("./res/font/verdana.ttf", 0, 0);
}
