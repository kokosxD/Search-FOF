#include <iostream>
#pragma once

namespace kokos{

	namespace string{
		void UpdateUppercase(std::string& str);

		void UpdateLowercase(std::string& str);

		std::string Uppercase(const std::string& str);

		std::string Lowercase(const std::string& str);
	}
}