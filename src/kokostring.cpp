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
		std::string Uppercase(const std::string& str){
			std::string new_str;
			for(int i = 0; i < str.length(); i ++){
				new_str += toupper(str[i]);
			}
			return new_str;
		}

		// Return a new string
		std::string Lowercase(const std::string& str){
			std::string new_str;
			for(int i = 0; i < str.length(); i ++){
				new_str += tolower(str[i]);
			}
			return new_str;
		}
	}
}