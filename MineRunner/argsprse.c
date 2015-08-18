#include "argsprse.h"

PSAVER_ARGS WINAPI ParseArguments(LPCSTR lpszCmdLine) {
	
	PSAVER_ARGS pArgs = malloc(sizeof(SAVER_ARGS));
	pArgs->nOption = SAVER_SETTINGS_DLG;
	pArgs->hwndAttach = NULL;

	char c = *lpszCmdLine;
	if (c == '/' || c == '-') {
		lpszCmdLine++;
		c = *lpszCmdLine;
		if (c == 's') {
			pArgs->nOption = SAVER_SHOW;
		}
		else if (c == 'p') {
			pArgs->nOption = SAVER_CHILD_SHOW;
			lpszCmdLine++;
			pArgs->hwndAttach = (HWND)atoi(lpszCmdLine);
		}
		else if (c == 'c') {
			pArgs->nOption = SAVER_SETTINGS_DLG_MODAL;
		}
		else {
			pArgs->nOption = SAVER_SETTINGS_DLG;
		}
	}

	return pArgs;
}