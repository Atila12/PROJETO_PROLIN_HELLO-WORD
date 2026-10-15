#include "main.h"


/* ===================== OPÇÕES DE PAGAMENTO ===================== */
int paymentOptions(void) {
    int key;
    clearScreen();
    writeCenterText(XuiRootCanvas(), "Escolha a forma de pagamento:", 50,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_bold, true);
    writeCenterText(XuiRootCanvas(), "1 - Débito", 120,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
    writeCenterText(XuiRootCanvas(), "2 - Crédito", 170,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);
    writeCenterText(XuiRootCanvas(), "3 - Pix", 220,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, 1);

    XuiClearKey();
    while (!XuiHasKey()) OsSleep(50);
    key = XuiGetKey();

    return key;
}
