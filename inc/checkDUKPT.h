#include "main.h"

int checkDUKPT(int iIndex, unsigned char *output) {
	unsigned char ksn[10+1] = {0};
	int ret;

	ret = OsPedGetKsnDukpt (iIndex, ksn);
	OsLog(LOG_DEBUG, "OsPedGetKsnDukpt[%d] = %d", iIndex, ret);
	if (ret == 0) {
		bcd2Asc(ksn, 10, output);
		return 0;
	}

	return -1;
}
