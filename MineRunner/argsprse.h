#pragma once

#include "StdAfx.h"

#define		SAVER_SETTINGS_DLG			0x01	//	Blank - Show the Settings dialog box.
#define		SAVER_SETTINGS_DLG_MODAL	0x02	//	/c - Show the Settings dialog box, modal to the foreground window.
#define		SAVER_CHILD_SHOW			0x04	//	/p <HWND> - Preview Screen Saver as child of window <HWND>.
#define		SAVER_SHOW					0x08	//	/s - Run the Screen Saver.

typedef struct tagSAVER_ARGS {
	UINT	nOption;
	HWND	hwndAttach;
} SAVER_ARGS, * PSAVER_ARGS;

DWORD WINAPI ParseArguments(LPCSTR, PSAVER_ARGS*);