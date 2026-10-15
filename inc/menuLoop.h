#include "main.h"

#include "auto_detect_loop.h"
/* ===================== MENU ATUALIZADO ===================== */
int menuLoop(void) {
    int key;
    while (1) {
        clearScreen();
        int screenW = XuiRootCanvas()->width;
        int headerH = 50;

        XuiCanvasDrawRect(XuiRootCanvas(), 0, 0, screenW, headerH, COLOR_INDIGO1, 0, 1);
        writeCenterText(XuiRootCanvas(), "MENU PRINCIPAL", 12,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_bold, 0);

        writeCenterText(XuiRootCanvas(), "1 - ICC Detect", 100, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "2 - CTLS Detect", 150, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "3 - MAG Detect", 200, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "4 - Detectar Automaticamente", 250, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        /* Novas opções */
        writeCenterText(XuiRootCanvas(), "5 - Injetar Chaves", 300, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "6 - Ver Chaves", 350, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "7 - Apagar chaves", 400, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "8 - Encrypt", 450, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
        writeCenterText(XuiRootCanvas(), "[CANCEL] Sair", 500, NO_CLEAR_SCREEN, FONT_SIZE_18, font_medium, 1);

        XuiClearKey();
        while (!XuiHasKey()) OsSleep(50);

		key = XuiGetKey();
		OsLog(LOG_DEBUG, "[menuLoop] XuiGetKey = %d", key);

		switch(key) {
			case XUI_KEY1:
				destroyMenuButtons();
				icc_detect();
				break;
			case XUI_KEY2:
				destroyMenuButtons();
				ctls_detect();
				break;
			case XUI_KEY3:
				destroyMenuButtons();
				mag_detect();
				break;
			case XUI_KEY4:
				destroyMenuButtons();
				auto_detect_loop();
				break;
			case XUI_KEY5:
				destroyMenuButtons();
				Menu();
				break;
			case XUI_KEY6:
				view_keys();
				break;
			case XUI_KEY7:
				clearKeys();
				break;
			case XUI_KEY8:
				encrypt_menu();
				break;
			case XUI_KEYCANCEL:
				OsLog(LOG_DEBUG, "[menuLoop] EXIT APP >>> ");
				destroyMenuButtons();
				return 0;
			default:
				break;
		}
    }
    return 0;
}
