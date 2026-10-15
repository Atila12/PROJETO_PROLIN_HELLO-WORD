#include "main.h"

/* Implementação */
int Menu(void)
{
    int iRet;
    char buffer[50]={0};

    OsLog(LOG_DEBUG, "==== Start Menu: ");

    /* fundo preto */
    XuiCanvasSetBackground(XuiRootCanvas(), XUI_BG_CENTER, NULL, COLOR_BLACK);

    /* barra verde no topo */
    XuiCanvasDrawRect(XuiRootCanvas(), 0, 0, XuiRootCanvas()->width, 40, COLOR_GREEN, 0, 1);
    XuiCanvasDrawText(XuiRootCanvas(), 50, 13, 18, font_medium, XUI_TEXT_BOLD, COLOR_BLACK, "INJEÇÃO DE CHAVE");

    iRet = OsPedOpen();
    OsLog(LOG_DEBUG, "OsPedOpen:%d", iRet);

    OsLog(LOG_DEBUG, "==== Iniciara injecao.. ");

    for(int i=1; i<= 100; i++) {
    	if (XuiHasKey()) {
    		if (XuiGetKey() == XUI_KEYCANCEL) {
    			XuiClearArea(XuiRootCanvas(), 0, 120, XuiRootCanvas()->width, 20);
    			writeCenterText(XuiRootCanvas(), "OPERAÇÃO CANCELADA", 120, NO_CLEAR_SCREEN, FONT_SIZE_18, font_medium, false);
    			break;
    		}
    	}

    	memset(buffer, 0, sizeof(buffer));
    	iRet = InjectDukpt(i);   // sua função de injeção
    	if (iRet == 0)
    		snprintf(buffer, sizeof(buffer), "DUKPT %d OK", i);
    	else
    		snprintf(buffer, sizeof(buffer), "DUKPT %d ERR", i);
    	XuiClearArea(XuiRootCanvas(), 0, 120, XuiRootCanvas()->width, 20);
    	writeCenterText(XuiRootCanvas(), buffer, 120, NO_CLEAR_SCREEN, FONT_SIZE_18, font_medium, false);
    }

    XuiGetKey();

    /* limpa área para mostrar resultado */
    XuiClearArea(XuiRootCanvas(), 0, 100, XuiRootCanvas()->width, 200);

    OsPedClose();

    return 0;
}

