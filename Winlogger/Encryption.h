#ifndef __ENCRYPTION_H_
#define __ENCRYPTION_H_

#include<iostream>
#include<string>
#include<fstream>

class Encryption {
	std::string file_name;
	std::string text;
	std::string plain_text;
	std::string cipher_text;
	int key = 36;

public:
	Encryption(std::string file_name = "",
		std::string text = "",
		std::string plain_text = "",
		std::string cipher_text = "")
		: file_name(file_name),
		text(text),
		plain_text(plain_text),
		cipher_text(cipher_text) {}
	
	std::string Process(std::string t) {
		// Empty all the variables
		plain_text = "";
		cipher_text = "";
		text = "";

		plain_text = t.c_str();
		Algorithm_Encrypt();

		return cipher_text;
	}

	void Algorithm_Encrypt() {

			RF_Encrypt(12);

			// text.length()
			// using for loop to rev the string and to increment the key in each single character
			for (int i = text.length() - 1; i >= 0; i--) {
				char result = static_cast<int>(text[i]) + key;
				cipher_text = cipher_text + result;
			}
		}

	void RF_Encrypt(int RF_key)
	{
		// create the matrix to cipher plain text 
		// key = rows , length(text) = columns 
		char rail[50][500];

		// filling the rail matrix to distinguish filled 
		// spaces from blank ones 
		for (int i = 0; i < RF_key; i++)
			for (int j = 0; j < plain_text.length(); j++)
				rail[i][j] = '\n';

		// to find the direction 
		bool dir_down = false;
		int row = 0, col = 0;

		for (int i = 0; i < plain_text.length(); i++)
		{
			// check the direction of flow 
			// reverse the direction if we've just 
			// filled the top or bottom rail 
			if (row == 0 || row == RF_key - 1)
				dir_down = !dir_down;

			// fill the corresponding alphabet 
			rail[row][col++] = plain_text[i];

			// find the next row using direction flag 
			dir_down ? row++ : row--;
		}

		//now we can construct the cipher using the rail matrix 
		for (int i = 0; i < RF_key; i++)
			for (int j = 0; j < plain_text.length(); j++)
				if (rail[i][j] != '\n')
					text.push_back(rail[i][j]);
	
		delete[] rail;
	}
};
#endif // !__ENCRYPTION_H_

