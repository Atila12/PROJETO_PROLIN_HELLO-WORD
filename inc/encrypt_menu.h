#include "main.h"

// 3) Encrypt
void encrypt_menu(void) {
    clearScreen();
    writeCenterText(XuiRootCanvas(), "Escolha operação de Encrypt:", 100,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_bold, true);

    writeCenterText(XuiRootCanvas(), "1 - PIN com DUKPT", 150,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
    writeCenterText(XuiRootCanvas(), "2 - Dados com MK", 200,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);

    XuiClearKey();
    while (!XuiHasKey()) OsSleep(50);
    int key = XuiGetKey();

    if (key == XUI_KEY1) {
        // Coleta PIN e retorna pinblock
        writeCenterText(XuiRootCanvas(), "Coletando PIN...", 250,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
        // Exemplo: OsPinGetDUKPT(1, pinblock);
    } else if (key == XUI_KEY2) {
        // Encripta dado "76696E6970616C7A"
        writeCenterText(XuiRootCanvas(), "Encriptando dados...", 250,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
        // Exemplo: OsEncryptMK(1, "76696E6970616C7A", pinblock);

    }

    OsSleep(2000);
    writeCenterText(XuiRootCanvas(), "Operação concluída!", 300,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_bold, true);
    OsSleep(2000);
}
