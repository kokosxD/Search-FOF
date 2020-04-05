# Search for files and folders
```C++
#include "search.h"
#include "path.h"
#include "timer.h"
#include "utils.h"
#include "defines.h"

int main(){

	// Get current user's directory
	kokos::kokoEnviron user_dir = kokos::kokoEnviron();

	// It needs administrator permissions
	user_dir.Select("UserProfile");
	std::string dir = user_dir.Get();

	// Get desktop directory
	kokos::Path::UpdateEscape(dir);
	dir = kokos::Path::Join(dir, "Desktop");

	// Get input
	kokos::print("Enter a keyword:", TAB);
	std::string keyword = kokos::Input();
	std::string show = std::string("");
	while(true){
		kokos::print("Show results (yes, no)?", TAB);
		show = kokos::Input();
		if(show == "yes" || show == "no"){ break; }
	}
	const bool show_results = show == "yes" ? true : false;

	// Search
	kokos::Timer timer = kokos::Timer();
	timer.Start();
	std::vector<std::string> results = kokos::Search(dir, keyword);
	if(show_results){
		for(const std::string& result : results){
			kokos::print(result, NEW_LINE);
		}
	}
	const unsigned int search_time = timer.Stop();

	// Show results
	kokos::print("Number of results:", TAB, results.size(), NEW_LINE);
	kokos::print("Search time:", TAB, TAB, search_time, NEW_LINE);

	kokos::pause();
	return 0;
}
```
