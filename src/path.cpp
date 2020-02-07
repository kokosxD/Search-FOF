#include <iostream>
#include <filesystem>
#include <vector>
#include "path.h"

namespace kokos{

	namespace path{

		bool IsDir(const std::string& path){
			return std::filesystem::is_directory(path);
		}

		bool IsFile(const std::string& path){
			return std::filesystem::is_regular_file(path);
		}

		int GetSize(const std::string& path){
			if(IsDir(path)){
				return 0;
			}
			else if(IsFile(path)){
				return std::filesystem::file_size(path);
			}
			throw NotDirectoryOrFile("The given path is not a directory or file");
			return 0;
		}

		std::vector<std::string> GetFOF(const std::string& dir){
			std::vector<std::string> fof;
			for(const std::filesystem::directory_entry& f : std::filesystem::directory_iterator(dir)){
				fof.push_back(f.path().string());
			}
			return fof;
		}

		std::string Join(const std::string& path_1, const std::string& path_2){
			return (std::filesystem::path(path_1) / std::filesystem::path(path_2)).string();
		}

		// Return a new directory that is X times back that the given one
		std::string DirBack(const std::string& dir, int& times){
			std::string new_dir = dir;
			for(int i = 0; i < times; i ++){
				new_dir = std::filesystem::path(new_dir).parent_path().string();
			}
			return new_dir;
		}
	}
}
