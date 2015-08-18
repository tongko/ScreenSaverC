#include "singleton.h"

VOID WINAPI InitSingleton(LPCTSTR lpszInstanceName) {
	g_hMutex = CreateMutex(NULL, FALSE, lpszInstanceName);
	g_dwLastError = GetLastError();
}

VOID WINAPI FinalizeSingleton(VOID) {
	if (g_hMutex != NULL) {
		CloseHandle(g_hMutex);
		g_hMutex = NULL;
	}
}

BOOL WINAPI IsOtherInstanceRunning(VOID) {
	return g_dwLastError == ERROR_ALREADY_EXISTS;
}