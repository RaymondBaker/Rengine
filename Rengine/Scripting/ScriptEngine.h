#pragma once
#include <vector>
#include <janet.h>
#include <iostream>
#include <filesystem>

namespace Ren
{
	namespace fs = std::filesystem;

	// ONLY ONE PER THREAD
	class ScriptEngine {
	public:
		ScriptEngine();
		~ScriptEngine();
		void load_script(const fs::path& file_path = "Scripts/main.janet");
		void bind_funcs(const std::string& func_prefix, const JanetReg* cfuns);
		void register_pointer(const std::string& name, void* c_pointer, const std::string& doc_string = "TODO make doc string");

		void print_bound_funcs() {
			std::cout << "Available C funcs:" << '\n';
			std::cout << "-----------------------------------------------------------" << '\n';
			for (auto i : m_bound_funcs) {
				std::cout << i << '\n';
			}
			std::cout << "-----------------------------------------------------------" << '\n';
		}

		static Janet j_print_bound_funcs(int32_t argc, Janet* argv) {
			// Throw error in janet if more than one arg passed
			janet_fixarity(argc, 1);

			//TODO test if this segfaults when something other than scriptengine is sent to it
				// ALSO dynamic cast might be better here if static doesn't throw
			auto script_eng = static_cast<ScriptEngine*>(janet_getpointer(argv, 0));
			script_eng->print_bound_funcs();
			return janet_wrap_nil();
		}

	private:

		std::vector<std::string> m_bound_funcs;

		JanetTable* m_env;

		static constexpr JanetReg cfuns[] = {
			{
				"Print-Bound-Functions", j_print_bound_funcs, "Print functions bound to c++ funcs"
			},
			{
				NULL, NULL, NULL
			}
		};
	protected:
	};
}
