#include "main.h"

int GuiInit(int statusbar_height)
{
	char value[128];
	char rotate_str[32];
	char statusbar_str[32];
	int ret;
	char *xui_argv[10];
	int  xui_argc;

	ret = OsRegGetValue("ro.fac.lcd.rotate", value);
	if (ret > 0) {
		snprintf(rotate_str, sizeof(rotate_str), "ROTATE=%s", value);
	}
	else {
		strcpy(rotate_str, "ROTATE=0");
	}

	if (statusbar_height > 0) {
		snprintf(statusbar_str, sizeof(statusbar_str), "STATUSBAR=%d", statusbar_height);
	}
	else {
		strcpy(statusbar_str, "STATUSBAR=0");
	}

	xui_argv[0] = rotate_str;
	xui_argv[1] = statusbar_str;
	xui_argv[2] = NULL;
	xui_argc = 2;

	ret = XuiOpen(xui_argc, xui_argv);
	if (ret == XUI_RET_OK) {
		return RET_OK;
	}
	else {
		return -1;
	}
}
