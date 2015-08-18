#pragma once

#include "StdAfx.h"

HANDLE			g_hMutex;
DWORD			g_dwLastError;

VOID WINAPI InitSingleton(LPCTSTR);

VOID WINAPI FinalizeSingleton(VOID);

BOOL WINAPI IsOtherInstanceRunning(VOID);