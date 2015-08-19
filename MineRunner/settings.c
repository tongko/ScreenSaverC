#include "settings.h"

INT_PTR CALLBACK SettingsDlgProc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (wParam == IDOK) {
			EndDialog(hWndDlg, 0);
			return TRUE;
		}
		break;
	default:
		return FALSE;
	}
}

INT WINAPI ShowSettingsDialog(HINSTANCE hInstance, HWND hWndParent) {
	DialogBox(hInstance,
			  MAKEINTRESOURCE(IDD_DLG_SETTINGS),
			  hWndParent,
			  (DLGPROC)SettingsDlgProc);
}