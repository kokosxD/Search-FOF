#include <iostream>
#pragma once

class NotDirectoryOrFile : std::exception{

private:
	const char* error;

public:

	NotDirectoryOrFile(const std::string& message){
		error = message.c_str();
	}

	const char* what() const throw(){
		return error;
	}
};

namespace kokos{

	namespace path{

		bool IsDir(const std::string& path);

		bool IsFile(const std::string& path);

		int GetSize(const std::string& path);

		std::vector<std::string> GetFOF(const std::string& dir);

		std::string Join(const std::string& path_1, const std::string& path_2);

		std::string DirBack(const std::string& dir, int& times);
	}
}