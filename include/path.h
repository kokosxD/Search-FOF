#pragma once
#include <filesystem>
#include <string>
#include <vector>

namespace kokos{
	namespace Path{
		std::string Join();

		template<typename First, typename... Rest>
		std::string Join(const First& path, const Rest&... paths){
			return (std::filesystem::path(path) / std::filesystem::path(Join(paths...))).string();
		}

		const bool IsDir(const std::string& path) noexcept;

		const bool IsFile(const std::string& path) noexcept;

		const unsigned int GetSize(const std::string& path);

		std::vector<std::string> GetFOF(const std::string& dir) noexcept;

		std::string& DirBack(std::string dir, const unsigned int& times);

		void UpdateEscape(std::string& path);

		std::string Escape(const std::string& path);
	}
}