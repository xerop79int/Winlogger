#ifndef __ADDITIONAL_H
#define __ADDITIONAL_H

#include<iostream>
#include<Windows.h>
#include <Lmcons.h>
//#include<SFML/Audio.hpp>
#include<fstream>
#include<string>


class Additional {
	// Clipboard Code
	std::string text = "";
	std::string username;

public:
	std::string GetClipboard();

	// Screenshot Code
	void Screenshot();

	// Disable animation Windows Code

	void disableAnimationWindows();

	void getUsername();

	std::string directoryPath();
	void makedirectory();

	//Microphone Recording Code
	//sf::SoundBufferRecorder recorder;
	//void recordingMicrophoneStart();
	//void recordingMicrophoneStop();

};
#endif // !_ADDITIONAL_H
