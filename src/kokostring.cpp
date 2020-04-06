#include "kokostring.h"

const char kokos::String::ToUpper(const char& character) noexcept{
	const unsigned int aschii_code = static_cast<unsigned int>(character);

	// If its lowercase
	if(aschii_code > 97 && aschii_code < 122){
		return static_cast<char>(aschii_code - 32);
	}

	return character;
}

const char kokos::String::ToLower(const char& character) noexcept{
	const unsigned int aschii_code = static_cast<unsigned int>(character);

	// If its uppercase
	if(aschii_code > 65 && aschii_code < 90){
		return static_cast<char>(aschii_code + 32);
	}

	return character;
}

void kokos::String::UpdateUppercase(std::string& str) noexcept{
	for(unsigned int i = 0; i < str.size(); i++){
		str[i] = ToUpper(str[i]);
	}
}

void kokos::String::UpdateLowercase(std::string& str) noexcept{
	for(unsigned int i = 0; i < str.size(); i++){
		str[i] = ToLower(str[i]);
	}
}

std::string kokos::String::Uppercase(std::string str) noexcept{
	UpdateUppercase(str);
	return str;
}

std::string kokos::String::Lowercase(std::string str) noexcept{
	UpdateLowercase(str);
	return str;
}