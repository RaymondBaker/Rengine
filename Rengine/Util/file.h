#pragma once
#include <fstream>
#include <filesystem>


namespace Ren
{
	namespace fs = std::filesystem;

	static std::string read_file(const fs::path& file_path) {
		std::ifstream t(file_path.c_str());

		t.seekg(0, std::ios::end);
		size_t size = t.tellg();
		std::string buffer(size, ' ');
		t.seekg(0);
		t.read(&buffer[0], size); 

		return buffer;
	}
}
