#include <iostream>
#include <filesystem>
#include <vector>
#include <locale>
#include "path.h"
#include "utils.h"
#include "kokostring.h"
#include "search.h"

File::File(const std::string& _dir){
	dir = _dir;
	size = kokos::path::GetSize(dir);
}

namespace kokos{
	std::vector<std::string> Search(const std::string& dir, std::string& keyword){
		std::vector<std::string> results;
		for(std::string result : kokos::path::GetFOF(dir)){
			try{
				if(kokos::path::IsDir(result)){
					if(kokos::string::Lowercase(std::filesystem::path(result).filename().string()).find(kokos::string::Lowercase(keyword)) != std::string::npos){
						results.push_back(std::filesystem::path(result).filename().string());

						// Add the full path
						// results.push_back(result);
					}
					std::vector<std::string> r = Search(kokos::path::Join(dir, result), keyword);
					results.insert(results.end(), r.begin(), r.end());
				}
				else if(kokos::path::IsFile(result)){
					if(kokos::string::Lowercase(std::filesystem::path(result).filename().string()).find(kokos::string::Lowercase(keyword)) != std::string::npos){
						results.push_back(std::filesystem::path(result).filename().string());

						// Add the full path
						// results.push_back(result);
					}
				}
			}
			catch(std::filesystem::filesystem_error){}
		}
		return results;
	}
}