#include <iostream>

namespace kokos{

    void print(){}

    std::string input(const std::string& message){
        std::string input;
        std::cout << message;
        std::cin >> input;
        std::cout << std::endl;
        return input;
    }

    void pause(){
        std::system("pause");
    }
}