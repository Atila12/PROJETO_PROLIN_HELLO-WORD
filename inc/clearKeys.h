#include "main.h"

void clearKeys() {
	int ret;

	clearScreen();
    XuiCanvasDrawRect(XuiRootCanvas(), 0, 0, XuiRootCanvas()->width, 40, COLOR_GREEN, 0, 1);
    XuiCanvasDrawText(XuiRootCanvas(), 50, 13, 18, font_medium, XUI_TEXT_BOLD, COLOR_BLACK, "APAGAR CHAVES");
	ret = OsPedEraseKeys();
	OsLog(LOG_DEBUG, "OsPedEraseKeys = %d", ret);

	writeCenterText(XuiRootCanvas(), "CHAVES REMOVIDAS!", 120, NO_CLEAR_SCREEN, FONT_SIZE_18, font_medium, true);
	writeCenterText(XuiRootCanvas(), "Pressione uma tecla para voltar!", 160, NO_CLEAR_SCREEN, FONT_SIZE_14, font_medium, true);
	XuiGetKey();

}
