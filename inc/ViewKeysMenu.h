#include "main.h"

void ViewKeysMenu(void) {
    int page = 0;   // página atual
    int totalPages = 10; // 100 índices / 10 por página
    int key;

    while (1) {
        clearScreen();

        /* Fundo e barra */
        XuiCanvasSetBackground(XuiRootCanvas(), XUI_BG_CENTER, NULL, COLOR_BLACK);
        XuiCanvasDrawRect(XuiRootCanvas(), 0, 0, XuiRootCanvas()->width, 40, COLOR_GREEN, 0, 1);
        XuiCanvasDrawText(XuiRootCanvas(), 50, 13, 18, font_medium, XUI_TEXT_BOLD, COLOR_BLACK, "CONSULTA DE CHAVES");

        /* Mostrar 10 índices por página */
        int start = page * 10 + 1;
        int end   = start + 9;
        if (end > 100) end = 100;

        int y = 80;
        for (int i = start; i <= end; i++) {
            char buffer[64];
            snprintf(buffer, sizeof(buffer), "Indice %d: DUKPT/MK presente", i);
            XuiCanvasDrawText(XuiRootCanvas(), 50, y, 18, font_medium, XUI_TEXT_NORMAL, COLOR_WHITE, buffer);
            y += 25;
        }

        /* Instruções de navegação */
        XuiCanvasDrawText(XuiRootCanvas(), 50, 320, 18, font_medium, XUI_TEXT_NORMAL, COLOR_WHITE, "[←] Página anterior");
        XuiCanvasDrawText(XuiRootCanvas(), 50, 350, 18, font_medium, XUI_TEXT_NORMAL, COLOR_WHITE, "[→] Próxima página");
        XuiCanvasDrawText(XuiRootCanvas(), 50, 380, 18, font_medium, XUI_TEXT_NORMAL, COLOR_WHITE, "[CANCEL] Voltar");

        /* Espera tecla */
        XuiClearKey();
        while (!XuiHasKey()) OsSleep(50);
        key = XuiGetKey();

        if (key == XUI_KEYLEFT && page > 0) page--;          // anterior
        else if (key == XUI_KEYRIGHT && page < totalPages-1) page++; // próxima
        else if (key == XUI_KEYCANCEL) break;                // sair
    }
}
