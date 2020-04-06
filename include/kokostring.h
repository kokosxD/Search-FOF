#pragma once
#include <string>

namespace kokos{
	namespace String{
		const char ToUpper(const char& character) noexcept;

		const char ToLower(const char& character) noexcept;

		void UpdateUppercase(std::string& str) noexcept;

		void UpdateLowercase(std::string& str) noexcept;

		std::string Uppercase(std::string str) noexcept;

		std::string Lowercase(std::string str) noexcept;
	}
}