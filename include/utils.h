#pragma once
#include <iostream>

namespace kokos{
    void print() noexcept;

    template<typename First, typename... Rest>
    void print(const First& arg, const Rest&... args) noexcept{
        std::cout << arg;
        print(args...);
    }

    void pause() noexcept;

	class kokoEnviron{
	private:
		char* var = nullptr;
		unsigned long long int size = 0;
	public:
		~kokoEnviron();

		void Select(const char* var_name);

		char* Get() const;
	};

	std::string Input();
}