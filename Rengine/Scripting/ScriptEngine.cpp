#include "ScriptEngine.h"
#include "../Rendering/Renderer.h"
#include <iostream>
#include "../Util/file.h"

namespace Ren 
{
	ScriptEngine::ScriptEngine()
	{
	    janet_init();

	    // Get the core janet environment. This contains all of the C functions in the core
	    // as well as the code in src/boot/boot.janet.
	    m_env = janet_core_env(NULL);
	
		// Give Script access to this pointer
		register_pointer("script_eng", this, "C pointer to ScriptEngine");

		bind_funcs("Script-Eng", cfuns);
	}

	ScriptEngine::~ScriptEngine()
	{
	    // Use this to free all resources allocated by Janet.
	    janet_deinit();
	}

	void ScriptEngine::load_script(const fs::path& file_path) 
	{
		//TODO: Check if file exists

		
		auto src_code = read_file(file_path);


		// Change this if it's running all the time
		janet_dostring(m_env, src_code.c_str(), "main", NULL);
	}

	void ScriptEngine::bind_funcs(const std::string& func_prefix, const JanetReg* cfuns)
	{
		//if you use janet_cfuns without prefix it takes a prefix param and does nothing with it
		janet_cfuns_prefix(m_env, func_prefix.c_str(), cfuns);


		auto i = 0;
		auto func = cfuns[i];
		while (func.name != NULL) {
			m_bound_funcs.push_back('\t' + func_prefix + '/' + std::string(func.name) + '\n' + "\t\t" + func.documentation);
			func = cfuns[++i];
		}
	}
	void ScriptEngine::register_pointer(const std::string& name, void* c_pointer, const std::string& doc_string)
	{
		auto j_this = janet_wrap_pointer(c_pointer);
		janet_def(m_env, name.c_str(), j_this, doc_string.c_str());
	}
}

