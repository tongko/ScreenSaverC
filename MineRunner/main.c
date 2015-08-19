#include "StdAfx.h"
#include "singleton.h"
#include "argsprse.h"
#include "settings.h"

//	Global constants
#define	CLSID		TEXT("C6E62DA8-66FB-4600-B6F5-2230FB2558D9")

//	Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


INT WINAPI WinMain(HINSTANCE	hInstance,
				   HINSTANCE	hPrevInsstance,
				   LPSTR		lpCmdLine,
				   INT			nCmdShow) {
	
	PSAVER_ARGS pArgs = malloc(sizeof(SAVER_ARGS));
	SAVER_ARGS args;

	//	Verify only 1 instance is running.
	InitSingleton(CLSID);
	if (IsOtherInstanceRunning()) {
		return EXIT_SUCCESS;
	}

	//	Parse command line arguments
	DWORD error = ParseArguments(lpCmdLine, &pArgs);
	if (error != ERROR_SUCCESS)
	{
		PrintError(NULL, error);
		if (pArgs != NULL)
			free(pArgs);
		return EXIT_FAILURE;
	}

	args = (*pArgs);
	LPTSTR lpszCmdLine = (LPTSTR)malloc(300);

	switch (args.nOption)
	{
	case SAVER_SETTINGS_DLG:
		//ShowSettingsDialog(hInstance, NULL);
		break;
	case SAVER_SETTINGS_DLG_MODAL:
		//ShowSettingsDialog(hInstance, (HWND)args.hwndAttach);
		break;
	case SAVER_CHILD_SHOW:
		break;
	case SAVER_SHOW:
		break;
	default:
		break;
	}

	swprintf(lpszCmdLine, 150, L"Option: %d - HWND: %d", args.nOption, args.hwndAttach);
	MessageBox(NULL, lpszCmdLine, L"Text", MB_OK);

	free(lpszCmdLine);
	free(pArgs);
	return EXIT_SUCCESS;
}