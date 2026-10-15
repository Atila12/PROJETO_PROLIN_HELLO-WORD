#include "main.h"
#include <signal.h>
/* ===================== CRASH REPORT ===================== */
static void CrashReportInit(void)
{
	signal(SIGILL,    OsSaveCrashReport);
	signal(SIGABRT,   OsSaveCrashReport);
	signal(SIGBUS,    OsSaveCrashReport);
	signal(SIGFPE,    OsSaveCrashReport);
	signal(SIGSEGV,   OsSaveCrashReport);
	signal(SIGSTKFLT, OsSaveCrashReport);
	signal(SIGPIPE,   OsSaveCrashReport);
}
