#include <iostream>
#pragma once

namespace kokos{

    void print();

    template<typename first, typename ... rest>
    void print(first arg, const rest&... args){
        std::cout << arg << std::endl;
        print(args...);
    }

    std::string input(const std::string& message);

    void pause();
}