#include <iostream>

namespace kokos{

	namespace string{

		// Update the old string
		void UpdateUppercase(std::string& str){
			for(int i = 0; i < str.length(); i ++){
				str[i] = toupper(str[i]);
			}
		}

		// Update the old string
		void UpdateLowercase(std::string& str){
			for(int i = 0; i < str.length(); i ++){
				str[i] = tolower(str[i]);
			}
		}

		// Return a new string
		std::string Uppercase(std::string str){
			for(int i = 0; i < str.length(); i ++){
				str[i] = toupper(str[i]);
			}
			return str;
		}

		// Return a new string
		std::string Lowercase(std::string str){
			for(int i = 0; i < str.length(); i ++){
				str[i] = tolower(str[i]);
			}
			return str;
		}
	}
}