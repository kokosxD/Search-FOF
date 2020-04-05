#include <filesystem>
#include "path.h"

std::string kokos::Path::Join(){
	return std::string("");
}

const bool kokos::Path::IsDir(const std::string& path) noexcept{
	return std::filesystem::is_directory(path);
}

const bool kokos::Path::IsFile(const std::string& path) noexcept{
	return std::filesystem::is_regular_file(path);
}

const unsigned int kokos::Path::GetSize(const std::string& path){
	unsigned int size = 0;

	if(IsDir(path)){
		for(const std::string& fof : GetFOF(path)){
			size += GetSize(fof);
		}
		return size;
	}
	else if(IsFile(path)){
		return std::filesystem::file_size(path);
	}
	return size;
}

std::vector<std::string> kokos::Path::GetFOF(const std::string& dir) noexcept{
	std::vector<std::string> fof = std::vector<std::string>();
	for(const std::filesystem::directory_entry& d : std::filesystem::directory_iterator(dir)){
		fof.push_back(d.path().string());
	}
	return fof;
}

// Returns a new directory that is X times back than the given
std::string& kokos::Path::DirBack(std::string dir, const unsigned int& times){
	for(unsigned int i = 0; i < times; i++){
		dir = std::filesystem::path(dir).parent_path().string();
	}
	return dir;
}

void kokos::Path::UpdateEscape(std::string& path){
	try{
		while(true){
			path.replace(path.find("\\"), 1, "/");
		}
	}
	catch(std::out_of_range){}
}

std::string kokos::Path::Escape(const std::string& path){
	std::string escaped_path = path;
	try{
		while(true){
			escaped_path.replace(path.find("\\"), 1, "/");
		}
	}
	catch(std::out_of_range){ return escaped_path; }
}