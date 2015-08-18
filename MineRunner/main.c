#include "StdAfx.h"
#include "singleton.h"

//	Global constants
#define	CLSID		TEXT("C6E62DA8-66FB-4600-B6F5-2230FB2558D9")

//	Prototype
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


INT WINAPI WinMain(HINSTANCE	hInstance,
				   HINSTANCE	hPrevInstance,
				   LPSTR		lpCmdLine,
				   INT			nCmdShow) {
	//	Verify only 1 instance is running.
	InitSingleton(CLSID);
	if (IsOtherInstanceRunning()) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}