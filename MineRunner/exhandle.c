#include <stdio.h>
#include <tchar.h>
#include "exhandle.h"

#define	MSG_FORMAT	L"%0.*s (0x%x)"

LPCTSTR WINAPI GetSystemErrorText(DWORD dwError, LPTSTR lpszBuff, ULONG nBuffSize) {
	DWORD dwRetLen;
	LPTSTR lpszTemp = NULL;

	if (nBuffSize < 16) {
		if (nBuffSize > 0) {
			lpszBuff[0] = L'\0';
		}

		return lpszBuff;
	}

	dwRetLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ARGUMENT_ARRAY,
							 NULL,
							 dwError,
							 LANG_NEUTRAL, 
							 lpszTemp, 
							 0, 
							 NULL);
	if (!dwRetLen || lpszTemp == NULL) {
		lpszBuff[0] = L'\0';
	}
	else {
		size_t nMaxLen = wcslen(MSG_FORMAT) + wcslen(lpszTemp);
		lpszTemp[wcslen(lpszTemp) - 2] = L'\0';	//	remove cr and newline character
		swprintf(lpszBuff, nMaxLen, L"%0.*s (0x%x)", nBuffSize - 16, lpszTemp, dwError);
		LocalFree((HLOCAL)lpszTemp);
	}

	return lpszBuff;
}

LPCTSTR WINAPI GetApplicationErrorText(DWORD dwError, LPTSTR lpszBuff, ULONG nBuffSize) {
	DWORD dwRetLen;
	LPTSTR lpszTemp = NULL;

	if (nBuffSize < 16) {
		if (nBuffSize > 0) {
			lpszBuff[0] = L'\0';
		}

		return lpszBuff;
	}

	dwRetLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_ARGUMENT_ARRAY,
							 NULL,
							 dwError,
							 LANG_NEUTRAL,
							 lpszTemp,
							 0,
							 NULL);

	if (!dwRetLen || lpszTemp == NULL) {
		lpszBuff[0] = '\0';
	}
	else {
		size_t nMaxLen = wcslen(MSG_FORMAT) + wcslen(lpszTemp);
		lpszTemp[wcslen(lpszTemp) - 2] = L'\0';
		swprintf(lpszBuff, nMaxLen, L"%0.*s (0x%x)", nBuffSize - 16, lpszTemp, dwError);
		LocalFree((HLOCAL)lpszTemp);
	}

	return lpszBuff;
}

LPCTSTR WINAPI GetErrorText(DWORD dwError) {
	TCHAR buffer[300];
	LPCTSTR lpszText;

	if (dwError < 0x020000000)
		lpszText = GetSystemErrorText(dwError, buffer, 300);
	else
		lpszText = GetApplicationErrorText(dwError, buffer, 300);

	return lpszText;
}

VOID WINAPI PrintError(HWND hwndOwner, DWORD dwError) {
	LPCTSTR lpszText = GetErrorText(dwError);

	MessageBox(hwndOwner, lpszText, TEXT("Error!"), MB_OK | MB_ICONERROR);

	exit(EXIT_FAILURE);
}

VOID WINAPI PrintWarning(HWND hwndOwner, DWORD dwError) {
	LPCTSTR lpszText = GetErrorText(dwError);

	MessageBox(hwndOwner, lpszText, TEXT("Warning!"), MB_OK | MB_ICONASTERISK);
}