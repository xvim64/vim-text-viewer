#include <windows.h>
#include <wchar.h>

#define CMD_SIZE 2048
#define ENVHOME_SIZE (MAX_PATH+5)

int APIENTRY wWinMain(
	_In_     HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR        lpCmdLine,
	_In_ int           nCmdShow)
{
	STARTUPINFOW si = {0, };
	PROCESS_INFORMATION pi;

	wchar_t * cmd;
	wchar_t cmd2[CMD_SIZE] = { 0, };
	wchar_t envHome[ENVHOME_SIZE] = { 0, };
	wchar_t szHome[MAX_PATH];
	wchar_t ex[]   = L"\\vim82\\gvim.exe";
	wchar_t info[] = L"\\config\\_viminfo.txt";
	wchar_t rc[]   = L"\\config\\_vimrc.txt";
	size_t i = 0;
	size_t n = 0;
	size_t pos = 0;
	BOOL bPos = FALSE;
	size_t size_cmd2 = 0;
	size_t size_lpCmdLine = 0;
	BOOL bFree = 0;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	// get home path
	GetModuleFileNameW(NULL, szHome, MAX_PATH);
	n = wcslen(szHome);
	while (i < n) {
		if (szHome[i] == L'\\') {
			bPos = TRUE;
			pos = i;
		}
		i++;
	}
	if (bPos) {
		szHome[pos] = 0;
	}

	// set home path : makes Vim Text Viewer portable
	swprintf(envHome, ENVHOME_SIZE, L"HOME=%ls", szHome);
	_wputenv(envHome);

	swprintf(cmd2, CMD_SIZE, L"\"%ls%ls\" -i \"%ls%ls\" -u \"%ls%ls\"", szHome, ex, szHome, info, szHome, rc);
	size_cmd2      = wcslen(cmd2);
	size_lpCmdLine = wcslen(lpCmdLine);

	if (size_lpCmdLine == 0) {
		cmd = cmd2;
	} else if (size_cmd2 + 1 + size_lpCmdLine < CMD_SIZE) {
		swprintf(cmd2, CMD_SIZE, L"\"%ls%ls\" -i \"%ls%ls\" -u \"%ls%ls\" %ls", szHome, ex, szHome, info, szHome, rc, lpCmdLine);
		cmd = cmd2;
	} else {
		cmd = (wchar_t *) calloc(size_cmd2+1+size_lpCmdLine+1,sizeof(wchar_t));
		if (cmd == NULL) {
			exit(1);
		}
		bFree = TRUE;
		swprintf(cmd, CMD_SIZE, L"\"%ls%ls\" -i \"%ls%ls\" -u \"%ls%ls\" %ls", szHome, ex, szHome, info, szHome, rc, lpCmdLine);
	}

	if (!CreateProcessW(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
		if (bFree) {
			free(cmd);
		}
		exit(1);
	}

	if (bFree) {
		free(cmd);
	}

	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	return 0;
}
