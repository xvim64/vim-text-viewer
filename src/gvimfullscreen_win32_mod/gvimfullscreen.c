// cl /LD gmax.c user32.lib

#include <windows.h>

// ------------------------------------------------------------

#define WX_EDGE   (WS_EX_CLIENTEDGE | WS_EX_WINDOWEDGE)
#define WX_NORMAL (WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_EX_CLIENTEDGE | WS_EX_WINDOWEDGE | WS_THICKFRAME | WS_DLGFRAME)

#ifndef LWA_ALPHA
#define LWA_ALPHA 2
#endif

#ifndef WS_EX_LAYERED
#define WS_EX_LAYERED 0x00080000
#endif

#define ALPHA_MIN 100
#define ALPHA_MAX 255

#define X_SIZE 9

// ------------------------------------------------------------

static int g_x  = 0;
static int g_y  = 0;
static int g_dx = 0;
static int g_dy = 0;
static HWND hVim = NULL;
static int g_ypd = 0;

// ------------------------------------------------------------

int x[X_SIZE] = {0, };

// ------------------------------------------------------------

BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM lParam)
{
	char lpszClassName[100];

	UNREFERENCED_PARAMETER(lParam);

	GetClassName(hWnd, lpszClassName, 100);
	if ( strcmp(lpszClassName, "VimTextArea") == 0 )
	{
		SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WX_EDGE);
		SetWindowPos(hWnd, HWND_TOP, 0, g_ypd, g_dx, g_dy, SWP_SHOWWINDOW);
	}

	return TRUE;
}

// ------------------------------------------------------------

BOOL CALLBACK FindWindowProc(HWND hWnd, LPARAM lParam)
{
	HWND* pphWnd = (HWND*)lParam;

	if (GetParent(hWnd))
	{
		*pphWnd = NULL;
		return TRUE;
	}
	*pphWnd = hWnd;

	return FALSE;
}

// ------------------------------------------------------------

static HWND GetVimHandle()
{
	if (hVim) {
		return hVim;
	}
	HMODULE hDllKernel32 = LoadLibrary("kernel32");
	if (hDllKernel32) {
		HWND (WINAPI *pfnGetConsoleWindow)();
		pfnGetConsoleWindow = (HWND (WINAPI *)()) GetProcAddress(hDllKernel32, "GetConsoleWindow");
		if (pfnGetConsoleWindow) {
			hVim = (HWND) pfnGetConsoleWindow();
			if (hVim) {
				ShowWindow(hVim, SW_SHOW);
				return hVim;
			}
		}
	}
	DWORD dwThreadID = GetCurrentThreadId();
	EnumThreadWindows(dwThreadID, FindWindowProc, (LPARAM)&hVim);

	return hVim;
}

// ------------------------------------------------------------

size_t strtoint(char *strPos) {
	char * token = NULL;
	char * context = NULL;
	size_t i = 0;

	token = strtok_s(strPos, " ,", &context);
	while (token) {
		if (i < X_SIZE) {
			x[i] = atoi(token);
		}
		i++;
		token = strtok_s(NULL, " ,", &context);
	}
	return i;
}

// ------------------------------------------------------------

BOOL IsSetFullPos(char *strPos)
{
	MONITORINFO mi;
	HMONITOR hMonitor;
	RECT rc1;
	RECT rc2;
	int dx1, dy1;
	int dx2, dy2;
	size_t n = 0;
	double double_x = 0;
	double double_y = 0;
	double double_dx = .0;
	double double_dy = .0;

	if (GetVimHandle()) {
		GetWindowRect(hVim, &rc1);
		hMonitor = MonitorFromRect(&rc1, MONITOR_DEFAULTTONEAREST);

		// get the work area or entire monitor rect.
		mi.cbSize = sizeof(mi);
		GetMonitorInfo(hMonitor, &mi);

		n = strtoint(strPos);
		g_ypd = x[0];

		if (n == 5 && x[3] > 0 && x[4] > 0) {
			g_x  = x[1];
			g_y  = x[2];
			g_dx = x[3];
			g_dy = x[4];
		} else {
			g_x = mi.rcMonitor.left;
			g_y = mi.rcMonitor.top;
			g_dx = mi.rcMonitor.right  - g_x;
			g_dy = mi.rcMonitor.bottom - g_y;

			switch (n) {
			case 9:
				SystemParametersInfo(SPI_GETWORKAREA, 0, &rc2, FALSE);

				dx1 = g_dx;
				dy1 = g_dy;

				// fullscreen size without taskbar
				dx2 = rc2.right  - rc2.left;
				dy2 = rc2.bottom - rc2.top;

				if (dx1 - dx2 > 5) {
					g_dx = dx2;
				} else {
					g_dx = dx1;
				}

				if (dy1 - dy2 > 5) {
					g_dy = dy2;
				} else {
					g_dy = dy1;
				}

				double_dx = (double)g_dx;
				double_dy = (double)g_dy;

				if (x[1] > 1) {
					double_x = double_dx / x[1];
					if (x[2] > 1)
						double_x *= x[2];
					g_x = (int)double_x;
				}
				if (x[3] > 1) {
					double_y = double_dy / x[3];
					if (x[4] > 1)
						double_y *= x[4];
					g_y = (int)double_y;
				}
				if (x[5] > 1) {
					double_dx /= x[5];
					if (x[6] > 1)
						double_dx *= x[6];
					g_dx = (int)double_dx;
				}
				if (x[7] > 1) {
					double_dy /= x[7];
					if (x[8] > 1)
						double_dy *= x[8];
					g_dy = (int)double_dy;
				}
				break;
			}
		}
		return TRUE;
	}
	return FALSE;
}

// ------------------------------------------------------------

// Return Normal(1), Maximized(2), FullScreen(3)
int __declspec(dllexport) State()
{
	// Determine the current state of the window

	WINDOWPLACEMENT wPos;
	if (GetVimHandle()) {
		if (GetWindowLong(hVim,GWL_STYLE) & WS_CAPTION) {
			GetWindowPlacement( hVim, &wPos );
			if (wPos.showCmd == SW_SHOWMAXIMIZED) {
				return 2;
			}
			return 1;
		}
		return 3;
	}
	return 0; // ERROR
}

// ------------------------------------------------------------

BOOL __declspec(dllexport) IsFull()
{
	// Determine the current state of the window

	if ( GetVimHandle() && !(GetWindowLong(hVim,GWL_STYLE) & WS_CAPTION) ) {
		return TRUE;
	}
	return FALSE;
}

BOOL __declspec(dllexport) IsWin()
{
	// Determine the current state of the window

	if ( GetVimHandle() && (GetWindowLong(hVim,GWL_STYLE) & WS_CAPTION) ) {
		return TRUE;
	}
	return FALSE;
}

// ------------------------------------------------------------

BOOL __declspec(dllexport) FullRefresh(char *strPos)
{
	if (GetVimHandle() && IsSetFullPos(strPos)) {
		if (IsFull()) {
			SetWindowPos(hVim, HWND_TOP, g_x, g_y, g_dx, g_dy, SWP_SHOWWINDOW);
			EnumChildWindows(hVim, EnumChildProc, 0);
		}
	}
	return IsFull();
}

BOOL __declspec(dllexport) FullOn(char *strPos)
{
	if (GetVimHandle() && IsSetFullPos(strPos)) {
		if (IsWin()) {
			// Remove border, caption, and edges
			SetWindowLong(hVim, GWL_STYLE,	 GetWindowLong(hVim, GWL_EXSTYLE) & ~WS_BORDER);
			SetWindowLong(hVim, GWL_STYLE,	 GetWindowLong(hVim, GWL_STYLE)   & ~WS_CAPTION);
			SetWindowLong(hVim, GWL_EXSTYLE, GetWindowLong(hVim, GWL_STYLE)   & ~WX_EDGE);
		}

		SetWindowPos(hVim, HWND_TOP, g_x, g_y, g_dx, g_dy, SWP_SHOWWINDOW);

		// Now need to find the child text area window
		// and set it's size accordingly
		EnumChildWindows(hVim, EnumChildProc, 0);
	}
	return IsFull();
}

BOOL __declspec(dllexport) FullOff()
{
	if (GetVimHandle()) {
		if (IsFull()) {
			// Already full screen, so restore all the previous styles
			SetWindowLong(hVim, GWL_EXSTYLE, GetWindowLong(hVim, GWL_EXSTYLE) | WS_BORDER);
			SetWindowLong(hVim, GWL_STYLE,	 GetWindowLong(hVim, GWL_STYLE)   | WX_NORMAL);

			SendMessage(hVim, WM_SYSCOMMAND, SC_RESTORE,  0);
			SendMessage(hVim, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		}
	}
	return IsFull();
}

BOOL __declspec(dllexport) FullToggle(char *strPos)
{
	if (GetVimHandle()) {
		if (IsWin() && IsSetFullPos(strPos)) {
			SetWindowLong(hVim, GWL_STYLE,	 GetWindowLong(hVim, GWL_EXSTYLE) & ~WS_BORDER);
			SetWindowLong(hVim, GWL_STYLE,	 GetWindowLong(hVim, GWL_STYLE)   & ~WS_CAPTION);
			SetWindowLong(hVim, GWL_EXSTYLE, GetWindowLong(hVim, GWL_STYLE)   & ~WX_EDGE);

			SetWindowPos(hVim, HWND_TOP, g_x, g_y, g_dx, g_dy, SWP_SHOWWINDOW);

			// Now need to find the child text area window
			// and set it's size accordingly
			EnumChildWindows(hVim, EnumChildProc, 0);
		} else {
			// Already full screen, so restore all the previous styles
			SetWindowLong(hVim, GWL_EXSTYLE, GetWindowLong(hVim, GWL_EXSTYLE) | WS_BORDER);
			SetWindowLong(hVim, GWL_STYLE,	 GetWindowLong(hVim, GWL_STYLE)   | WX_NORMAL);

			SendMessage(hVim, WM_SYSCOMMAND, SC_RESTORE,  0);
			SendMessage(hVim, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		}
	}
	return IsFull();
}

// ------------------------------------------------------------

BOOL __declspec(dllexport) IsMax()
{
	WINDOWPLACEMENT wPos;
	if ( GetVimHandle() && (GetWindowLong(hVim,GWL_STYLE) & WS_CAPTION) ) {
		GetWindowPlacement( hVim, &wPos );
		if (wPos.showCmd == SW_SHOWMAXIMIZED) {
			return TRUE;
		}
	}
	return FALSE;
}

BOOL __declspec(dllexport) IsNormal()
{
	WINDOWPLACEMENT wPos;
	if ( GetVimHandle() && (GetWindowLong(hVim,GWL_STYLE) & WS_CAPTION) ) {
		GetWindowPlacement( hVim, &wPos );
		// Not
		if ( !(wPos.showCmd == SW_SHOWMAXIMIZED) ) {
			return TRUE;
		}
	}
	return FALSE;
}

// ------------------------------------------------------------

BOOL __declspec(dllexport) MaxOn()
{
	if (IsFull()) {
		FullOff();
	}
	if (!IsMax()) {
		SendMessage(hVim, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	}
	return IsMax();
}

BOOL __declspec(dllexport) MaxOff()
{
	if (IsFull()) {
		FullOff();
	}
	if (IsMax()) {
		SendMessage(hVim, WM_SYSCOMMAND, SC_RESTORE, 0);
	}
	return IsMax();
}

BOOL __declspec(dllexport) MaxToggle()
{
	if (IsFull()) {
		FullOff();
	}
	else if (IsMax()) {
		SendMessage(hVim, WM_SYSCOMMAND, SC_RESTORE, 0);
	} else {
		SendMessage(hVim, WM_SYSCOMMAND, SC_MAXIMIZE, 0);
	}
	return IsMax();
}

// ------------------------------------------------------------

BOOL __declspec(dllexport) IsTop()
{
	if ( GetVimHandle() && (GetWindowLong(hVim, GWL_EXSTYLE) & WS_EX_TOPMOST) ) {
		return TRUE;
	}
	return FALSE;
}

// ------------------------------------------------------------

BOOL __declspec(dllexport) TopOn()
{
	if (!IsTop()) {
		SetWindowPos(hVim, HWND_TOPMOST  , 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	}
	return IsTop();
}

BOOL __declspec(dllexport) TopOff()
{
	if (IsTop()) {
		SetWindowPos(hVim, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	}
	return IsTop();
}

BOOL __declspec(dllexport) TopToggle()
{
	if (IsTop()) {
		SetWindowPos(hVim, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	} else {
		SetWindowPos(hVim, HWND_TOPMOST  , 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE);
	}
	return IsTop();
}

// ------------------------------------------------------------

LONG __declspec(dllexport) Alpha(LONG nAlpha)
{
	HMODULE hDllUser32 = LoadLibrary("user32");
	if (hDllUser32) {
		BOOL (WINAPI *pfnSetLayeredWindowAttributes)(HWND,DWORD,BYTE,DWORD);

		pfnSetLayeredWindowAttributes = (BOOL (WINAPI *)(HWND,DWORD,BYTE,DWORD)) GetProcAddress(hDllUser32, "SetLayeredWindowAttributes");

		if (pfnSetLayeredWindowAttributes) {
			if (GetVimHandle()) {
				if (nAlpha < ALPHA_MIN) {
					nAlpha = ALPHA_MIN;
				} else if (nAlpha > ALPHA_MAX) {
					nAlpha = ALPHA_MAX;
				}
				if (nAlpha == ALPHA_MAX) {
					SetWindowLong(hVim, GWL_EXSTYLE, GetWindowLong(hVim, GWL_EXSTYLE) & ~WS_EX_LAYERED);
				} else {
					SetWindowLong(hVim, GWL_EXSTYLE, GetWindowLong(hVim, GWL_EXSTYLE) | WS_EX_LAYERED);
					pfnSetLayeredWindowAttributes(hVim, 0, (BYTE)nAlpha, LWA_ALPHA);
				}
			}
		}
		FreeLibrary(hDllUser32);
	}
	return nAlpha;
}

// ------------------------------------------------------------
