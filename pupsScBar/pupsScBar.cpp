#include <windows.h>
#include <commctrl.h>

#include "resource.h"

#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment (lib, "comctl32.lib")

ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE hInstance;

HWND hWnd;
HWND hwndBtn11, hwndBtn12, hwndBtn13, hwndBtn14;
HWND hwndBtn21, hwndBtn22, hwndBtn23;
HWND hwndBtn31, hwndBtn32, hwndBtn33, hwndBtn34, hwndBtn35, hwndBtn36, hwndBtn37, hwndBtn38;
HWND hwndBtn41, hwndBtn42, hwndBtn43, hwndBtn44, hwndBtn45, hwndBtn46, hwndBtn47, hwndBtn48;
HWND hwndBtn50;
HWND hwndBtn51, hwndBtn52, hwndBtn53, hwndBtn54, hwndBtn55, hwndBtn56, hwndBtn57, hwndBtn58, hwndBtn59;
HWND hwndBtn61, hwndBtn62;
HWND hwndBtn99;

BYTE animatedTransparency = 255;

//LPTSTR lpMsgBuf;
//FormatMessage(0x00001300, NULL, GetLastError(), 0x0409, (LPTSTR)&lpMsgBuf, 0, NULL);
//MessageBox(NULL, (LPCTSTR)lpMsgBuf, TEXT("Message"), MB_OK);

//UINT a = 1;
//wchar_t buf[255];
//wsprintf(buf, L"%u", a);
//MessageBox(NULL, (LPCTSTR)buf, TEXT("Message"), MB_OK);

//MessageBox(NULL, TEXT("1"), TEXT("Message"), MB_OK);

int CALLBACK WinMain(HINSTANCE hInstanceMain, HINSTANCE, LPSTR, int nCmdShow)
{
	hInstance = hInstanceMain;
	
	MSG msg;

	MyRegisterClass(hInstance);
	InitInstance(hInstance, nCmdShow);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(167, 154, 231));;
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("pupsScBar");

	return RegisterClass(&wc);
}

HWND CreateButton(int wPosition, char flag, LPCWSTR exeFileWithIcon)
{
	HICON hIconL; HICON hIconS;

	HWND hwndBtn = CreateWindow(TEXT("BUTTON"), TEXT("s"), WS_VISIBLE | WS_CHILD | BS_ICON, 1, wPosition, 43, 24, hWnd, NULL, hInstance, NULL);
	if (flag == 'E') ExtractIconEx(exeFileWithIcon, 0, &hIconL, &hIconS, 1);
	if (flag == 'A') hIconS = (HICON)LoadImage(hInstance, MAKEINTRESOURCE(IDI_ICON0), IMAGE_ICON, 16, 16, LR_SHARED);
	SendMessage(hwndBtn, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconS);

	HWND hwndBtnTip = CreateWindowEx(NULL, TOOLTIPS_CLASS, NULL, WS_POPUP | TTS_ALWAYSTIP | TTS_BALLOON, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);
	TOOLINFO toolInfo = { 0 };
	toolInfo.cbSize = sizeof(toolInfo);
	toolInfo.hwnd = hWnd;
	toolInfo.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
	toolInfo.uId = (UINT_PTR)hwndBtn;
		wchar_t toolTipText[255];
		wsprintf(toolTipText, L"%s", exeFileWithIcon);
		wchar_t * found = wcsrchr(toolTipText, '.');
		if (found) *found = 0;
		found = wcsrchr(toolTipText, '\\');
		//toolInfo.lpszText = (LPWSTR)(found + 1);
		toolInfo.lpszText = (LPWSTR)exeFileWithIcon;
	SendMessage(hwndBtnTip, TTM_ADDTOOL, 0, (LPARAM)&toolInfo);

	return hwndBtn;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hWnd = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOOLWINDOW, TEXT("pupsScBar"), TEXT("pupsScBar"), WS_POPUP, 63, 0, 45, 768, NULL, NULL, hInstance, NULL);
	SetLayeredWindowAttributes(hWnd, 0, animatedTransparency, LWA_ALPHA);

	HWND hWndTip = CreateWindowEx(NULL, TOOLTIPS_CLASS, NULL, WS_POPUP | TTS_ALWAYSTIP | TTS_BALLOON, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, hWnd, NULL, hInstance, NULL);
	TOOLINFO toolInfo = { 0 };
	toolInfo.cbSize = sizeof(toolInfo);
	toolInfo.hwnd = hWnd;
	toolInfo.uFlags = TTF_IDISHWND | TTF_SUBCLASS;
	toolInfo.uId = (UINT_PTR)hWnd;
	toolInfo.lpszText = (LPWSTR)L"Msk 10 FFM 09 Ldn 08 NYC 03 LA 00 "\
								L"Msk 14 FFM 13 Ldn 12 NYC 07 LA 04 "\
								L"Msk 18 FFM 17 Ldn 16 NYC 11 LA 08 "\
								L"Msk 22 FFM 21 Ldn 20 NYC 15 LA 12 ";
	SendMessage(hWndTip, TTM_ADDTOOL, 0, (LPARAM)&toolInfo);
	SendMessage(hWndTip, TTM_SETMAXTIPWIDTH, 0, 211);
	
	hwndBtn11 = CreateButton(  0, 'E', (LPCWSTR)L"C:\\Users\\God\\Desktop\\FirefoxPortable\\FirefoxPortable.exe");
	hwndBtn12 = CreateButton( 25, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe");
	hwndBtn13 = CreateButton( 50, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Opera\\launcher.exe");
//	hwndBtn14 = CreateButton(75, 'E', (LPCWSTR)L"C:\\Windows\\SystemApps\\Microsoft.MicrosoftEdge_8wekyb3d8bbwe\\MicrosoftEdge.exe");
	hwndBtn14 = CreateButton(75, 'E', (LPCWSTR)L"C:\\!me\\Tor Browser\\Browser\\firefox.exe");

	hwndBtn21 = CreateButton(125, 'E', (LPCWSTR)L"C:\\dist\\putty.exe");
	hwndBtn22 = CreateButton(150, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Skype\\Phone\\Skype.exe");
//	hwndBtn23 = CreateButton(175, 'E', (LPCWSTR)L"C:\\!me\\projects\\SSHConnectFX\\SSHConnectFX.ico");

	hwndBtn31 = CreateButton(225, 'E', (LPCWSTR)L"C:\\java\\eclipse\\eclipse.exe");
	hwndBtn32 = CreateButton(250, 'E', (LPCWSTR)L"C:\\java\\NetBeans 8.1\\bin\\netbeans64.exe");

	hwndBtn41 = CreateButton(400, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Common7\\IDE\\devenv.exe");
	hwndBtn42 = CreateButton(425, 'E', (LPCWSTR)L"C:\\oracle\\middleware\\mwhome_1\\jdeveloper\\jdeveloper.exe");
	hwndBtn43 = CreateButton(450, 'E', (LPCWSTR)L"C:\\Windows\\explorer.exe");
	hwndBtn44 = CreateButton(475, 'E', (LPCWSTR)L"C:\\dist\\sqldeveloper\\sqldeveloper.exe");
	hwndBtn45 = CreateButton(500, 'A', NULL);
	hwndBtn46 = CreateButton(525, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\PLSQL Developer\\plsqldev.exe");
	hwndBtn47 = CreateButton(550, 'E', (LPCWSTR)L"C:\\Windows\\explorer.exe");
	hwndBtn48 = CreateButton(575, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Java\\jre1.8.0_45\\bin\\javacpl.exe");

	hwndBtn50 = CreateButton(625, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Microsoft Office\\OFFICE11\\WINWORD.EXE");
	
	hwndBtn51 = CreateButton(675, 'E', (LPCWSTR)L"C:\\dict\\prMainhatten.exe");
	hwndBtn52 = CreateButton(700, 'E', (LPCWSTR)L"C:\\Program Files\\Le Robert\\The Collins-Robert French Dictionary\\RobertCollins.exe");

	hwndBtn61 = CreateButton(350, 'E', (LPCWSTR)L"C:\\Program Files (x86)\\Far\\Far.exe");

	hwndBtn99 = CreateButton(743, 'A', NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	SetTimer(hWnd, 1, 10000, NULL);

	return TRUE;
}
void StartFile(LPCWSTR exeFileToStart)
{
	ShellExecuteW(NULL, NULL, exeFileToStart, NULL, NULL, SW_SHOWNORMAL);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
		if ((HWND)lParam == hwndBtn11) StartFile(L"C:\\Users\\God\\Desktop\\FirefoxPortable\\FirefoxPortable.exe");
		if ((HWND)lParam == hwndBtn12) StartFile(L"C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe");
		if ((HWND)lParam == hwndBtn13) StartFile(L"C:\\Program Files (x86)\\Opera\\launcher.exe");
//		if ((HWND)lParam == hwndBtn14) ShellExecuteW(NULL, NULL, L"C:\\Windows\\explorer.exe", L"shell:Appsfolder\\Microsoft.MicrosoftEdge_8wekyb3d8bbwe!MicrosoftEdge", NULL, SW_SHOWNORMAL);
		if ((HWND)lParam == hwndBtn14) StartFile(L"C:\\!me\\Tor Browser\\Browser\\firefox.exe");

		if ((HWND)lParam == hwndBtn21) StartFile(L"C:\\dist\\putty.exe");
		if ((HWND)lParam == hwndBtn22) StartFile(L"C:\\Program Files (x86)\\Skype\\Phone\\Skype.exe");
		//if ((HWND)lParam == hwndBtn23) ShellExecuteW(NULL, NULL, L"C:\\ProgramData\\Oracle\\Java\\javapath\\javaw.exe", L"C:\\!me\\projects\\SSHConnectFX\\SSHConnectFX.jar", NULL, SW_SHOWNORMAL);

		if ((HWND)lParam == hwndBtn31) StartFile(L"C:\\java\\eclipse\\eclipse.exe");
		if ((HWND)lParam == hwndBtn32) StartFile(L"C:\\java\\NetBeans 8.1\\bin\\netbeans64.exe");

		if ((HWND)lParam == hwndBtn41) StartFile(L"C:\\Program Files (x86)\\Microsoft Visual Studio 14.0\\Common7\\IDE\\devenv.exe");
		if ((HWND)lParam == hwndBtn42) StartFile(L"C:\\oracle\\middleware\\mwhome_1\\jdeveloper\\jdeveloper.exe");
		if ((HWND)lParam == hwndBtn43) StartFile(L"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Oracle\\OracleHome1\\WebLogic Server 12.2.1\\Tools");
		if ((HWND)lParam == hwndBtn44) StartFile(L"C:\\dist\\sqldeveloper\\sqldeveloper.exe");
		if ((HWND)lParam == hwndBtn45) StartFile(L"C:\\oracle\\product\\12.1.0\\dbhome_1\\BIN\\sqlplus.exe");
		if ((HWND)lParam == hwndBtn46) StartFile(L"C:\\Program Files (x86)\\PLSQL Developer\\!PLSQL Developer.bat");
		if ((HWND)lParam == hwndBtn47) StartFile(L"C:\\dist\\SysInternalsSuite");
		if ((HWND)lParam == hwndBtn48) StartFile(L"C:\\Program Files (x86)\\Java\\jre1.8.0_45\\bin\\javacpl.exe");

		if ((HWND)lParam == hwndBtn50) StartFile(L"C:\\Program Files (x86)\\Microsoft Office\\OFFICE11\\WINWORD.EXE");

		if ((HWND)lParam == hwndBtn51) ShellExecuteW(NULL, NULL, L"C:\\dict\\prMainhatten.exe", NULL, L"C:\\dict", SW_SHOWNORMAL);
		if ((HWND)lParam == hwndBtn52) StartFile(L"C:\\Program Files\\Le Robert\\The Collins-Robert French Dictionary\\RobertCollins.exe");
		if ((HWND)lParam == hwndBtn61) StartFile(L"C:\\Program Files (x86)\\Far\\Far.exe");
		if ((HWND)lParam == hwndBtn99) return DefWindowProc(hWnd, message, wParam, lParam);
		PostQuitMessage(0);
		break;
	case WM_TIMER:
		SetLayeredWindowAttributes(hWnd, 0, animatedTransparency--, LWA_ALPHA);
		if (animatedTransparency == 254) SetTimer(hWnd, 1, 1, NULL);
		if (animatedTransparency == 0) PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == 27) PostQuitMessage(0);
		break;
	case WM_ACTIVATE:
		SetFocus(hwndBtn11);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
	