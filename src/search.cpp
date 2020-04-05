#include <filesystem>
#include "search.h"
#include "path.h"
#include "kokostring.h"

std::vector<std::string> kokos::Search(const std::string& dir, const std::string& keyword){
	std::vector<std::string> results = std::vector<std::string>();
	std::vector<std::string> r = std::vector<std::string>();
	for(const std::string& result : Path::GetFOF(dir)){
		try{
			if(Path::IsDir(result)){
				if(String::Lowercase(std::filesystem::path(result).filename().string()).find(kokos::String::Lowercase(keyword)) != std::string::npos){
					results.push_back(result);
				}

				r = Search(Path::Join(dir, result), keyword);
				results.insert(results.end(), r.begin(), r.end());
			}

			// Some special Windows files are not treated like folders or files
			else if(Path::IsFile(result)){
				if(String::Lowercase(std::filesystem::path(result).filename().string()).find(kokos::String::Lowercase(keyword)) != std::string::npos){
					results.push_back(result);
				}
			}
		}

		// Ignore errors and continue
		catch(std::filesystem::filesystem_error){}
	}
	return results;
}