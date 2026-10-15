#include "main.h"


/* ===================== ENTRADA DE VALOR ===================== */
int getTransactionValue(void) {
    clearScreen();
    writeCenterText(XuiRootCanvas(), "Digite o valor :", 100,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);

    // Mostra imagem de aproximação (BMP é o formato suportado)
   // XuiWindow *img = XuiWindowCreateImage(XuiRootCanvas(),
                                         // "./res/aproximacao.bmp",
                                          //50, 150, 64, 64);
    long valor = 0;   // guarda em centavos
    int key;
    char buffer[32];

    while (1) {
        XuiClearKey();
        while (!XuiHasKey()) OsSleep(50);
        key = XuiGetKey();

        switch (key) {
            case XUI_KEY0: valor = valor * 10; break;
            case XUI_KEY1: valor = valor * 10 + 1; break;
            case XUI_KEY2: valor = valor * 10 + 2; break;
            case XUI_KEY3: valor = valor * 10 + 3; break;
            case XUI_KEY4: valor = valor * 10 + 4; break;
            case XUI_KEY5: valor = valor * 10 + 5; break;
            case XUI_KEY6: valor = valor * 10 + 6; break;
            case XUI_KEY7: valor = valor * 10 + 7; break;
            case XUI_KEY8: valor = valor * 10 + 8; break;
            case XUI_KEY9: valor = valor * 10 + 9; break;
            case XUI_KEYENTER: return (int)valor; // confirma
        }

        // Atualiza a tela com o valor formatado
        snprintf(buffer, sizeof(buffer), "R$ %ld,%02ld", valor / 100, valor % 100);

        // Limpa a área do valor
        XuiCanvasDrawRect(XuiRootCanvas(), 0, 140, XuiRootCanvas()->width, 40, COLOR_BACKGROUND, 1, 1);

        // Redesenha o valor
        writeCenterText(XuiRootCanvas(), buffer, 150,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
    }

    return 0;
}
