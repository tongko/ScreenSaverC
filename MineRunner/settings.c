#include "settings.h"

INT_PTR CALLBACK SettingsDlgProc(HWND hWndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (wParam == IDOK) {
			EndDialog(hWndDlg, wParam);
			return TRUE;
		}
		break;
	default:
		return FALSE;
	}
}

INT WINAPI ShowSettingsDialog(HINSTANCE hInstance) {
	if (!IsWindow(g_hwndSettings)) {
		g_hwndSettings = CreateDialog(hInstance,
			MAKEINTRESOURCE(IDD_DLG_SETTINGS),
			NULL,
			(DLGPROC)SettingsDlgProc);
	}

	return ShowWindow(g_hwndSettings, SW_SHOW);
}

INT WINAPI ShowSettingDialogModal(HINSTANCE hInstance) {
	HWND hwndFore = GetForegroundWindow();
	return DialogBox(hInstance,
		MAKEINTRESOURCE(IDD_DLG_SETTINGS),
		hwndFore,
		(DLGPROC)SettingsDlgProc);

}