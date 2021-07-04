#ifndef __HELPER_H
#define __HELPER_H

#include<fstream>
#include<Windows.h>
#include<cstdlib>
#include"Encryption.h"
#include"Additional.h"


class Helper {
	std::string username;
	std::string file_location;
	Additional AOBJ;
public:
	Helper() {
			char name[100];
			std::string username;
			DWORD nUserName = sizeof(name);
			if (GetUserName((TCHAR*)name, &nUserName))
				this->username = name;

	}

	template <class T>
	bool WriteToFile(const T& t, std::string filename) {
		auto path = AOBJ.directoryPath() + filename;
		{
			Encryption EOBJ;	
			try
			{
				std::ofstream file(path, std::ios::app | std::ios::binary | std::ios::out);
				if (!file) return false;
				//std::string data = EOBJ.Process(t);
				std::string data = t;
				file << data;
				file.close();

				return true;
			}
			catch (...)
			{
				return false;
			}

		}
	}
};

#endif // !__HELPER_H


