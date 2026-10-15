#include "main.h"


// 2) Ver chaves
void view_keys(void) {
	int ret, iLoop, align = 0;
	char buffer[64] = {0};
	unsigned char bufferKsn[20+1]={0};

    clearScreen();
    writeCenterText(XuiRootCanvas(), "Consultando chaves...", 100, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
    OsPedOpen();
    for (iLoop = 1; iLoop <= 100; iLoop++) {
    	ret = checkDUKPT(iLoop, bufferKsn);
    	if (ret == 0) {
    		snprintf(buffer, sizeof(buffer),"DUKPT %d: %s", iLoop, bufferKsn);
            writeCenterText(XuiRootCanvas(), buffer, 120 + (align * 15), NO_CLEAR_SCREEN, FONT_SIZE_18, font_medium, true);

    		memset(buffer, 0, sizeof(buffer));
    		memset(bufferKsn, 0, sizeof(bufferKsn));
    		align++;
    	}

    }

    if (align == 0) {
    	clearScreen();
    	writeCenterText(XuiRootCanvas(), "Nenhuma chave encontrada", 100, NO_CLEAR_SCREEN, FONT_SIZE_22, font_medium, true);
    }

    //OsSleep(3000);
    XuiGetKey();
}
