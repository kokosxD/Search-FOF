#include <string>
#include "utils.h"

void kokos::print() noexcept{
    std::cout << std::flush;
}

void kokos::pause() noexcept{
    std::system("pause");
}

kokos::kokoEnviron::~kokoEnviron(){
	delete var;
}

void kokos::kokoEnviron::Select(const char* var_name){
	_dupenv_s(&var, &size, var_name);
}

char* kokos::kokoEnviron::Get() const{
	return var;
}

std::string kokos::Input(){
	std::string input = std::string("");
	std::getline(std::cin, input);
	return input;
}