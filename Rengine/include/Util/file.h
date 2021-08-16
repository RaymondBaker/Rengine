#pragma once
#include <fstream>
#include <filesystem>
#include <sstream>


namespace Ren
{
	namespace fs = std::filesystem;

	static std::string read_file(const fs::path& file_path) {
		std::ifstream t(file_path.c_str());

		std::stringstream buffer;
		buffer << t.rdbuf();

		return buffer.str();
	}
}
