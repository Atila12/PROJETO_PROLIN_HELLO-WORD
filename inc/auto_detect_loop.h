#include "main.h"

/* ===================== DETECÇÃO AUTOMÁTICA ===================== */

void auto_detect_loop(void) {
    long valor = getTransactionValue();   // usuário digita valor
    int opcao = paymentOptions();         // escolhe forma de pagamento

    clearScreen();
    if (opcao == XUI_KEY1) {
        writeCenterText(XuiRootCanvas(), "Débito selecionado", 100,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);

        /* Espera inserção do cartão com chip */
        writeCenterText(XuiRootCanvas(), "Insira o cartão", 150,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
        icc_detect();   // só continua quando o cartão for detectado

    } else if (opcao == XUI_KEY2) {
        writeCenterText(XuiRootCanvas(), "Crédito selecionado", 100,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);

        /* Espera aproximação/contactless */
        writeCenterText(XuiRootCanvas(), "Aproxime o cartão", 150,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
        ctls_detect();  // só continua quando o cartão for detectado

    } else if (opcao == XUI_KEY3) {
        writeCenterText(XuiRootCanvas(), "Pix selecionado", 100,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);

        /* Simulação de leitura via QR/tarja */
        writeCenterText(XuiRootCanvas(), "Aproxime ou leia QR", 150,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
        mag_detect();   // só continua quando detectado
    }

    /* Tela de processamento */
    clearScreen();
    writeCenterText(XuiRootCanvas(), "Processando...", 150,
                    NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
    OsSleep(3000);

    /* Resultado da transação */
    clearScreen();
    int aprovado = 1; // simulação: sempre aprovado

    if (aprovado) {
        writeCenterText(XuiRootCanvas(), "Transação Aprovada", 150,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_bold, true);
    } else {
        writeCenterText(XuiRootCanvas(), "Transação Não Autorizada", 150,
                        NO_CLEAR_SCREEN, FONT_SIZE_22, font_bold, true);
    }

    OsSleep(3000);

    /* Volta ao menu */
    menuLoop();
}
