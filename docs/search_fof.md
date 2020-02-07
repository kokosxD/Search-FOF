# Search for files and folders
```C++
#include <iostream>
#include <vector>
#include "search.h"
#include "utils.h"

int main(){
	std::string dir = std::filesystem::current_path().string();
	std::string keyword = kokos::input("Enter the keyword:\t");

	std::vector<std::string> results = kokos::Search(dir, keyword);
	for(const std::string result : results){
		kokos::print(result);
	}

	kokos::pause();
	return 0;
}
```
