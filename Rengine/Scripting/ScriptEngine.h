#pragma once
#include <vector>
#include <janet.h>
#include <filesystem>

namespace Ren
{
	namespace fs = std::filesystem;

	class ScriptEngine {
	public:
		ScriptEngine();
		~ScriptEngine();
		void load_script(const fs::path& file_path = "Scripts/main.janet");


		void bind_funcs(const char* func_prefix, const JanetReg* cfuns)
		{
			//if you use janet_cfuns without prefix it takes a prefix param and does nothing with it
			janet_cfuns_prefix(m_env, func_prefix, cfuns);
		}

		Janet get_func(const char* func_name) {
			auto j_func_name = janet_wrap_string(func_name);
			auto func = janet_table_get(m_env, j_func_name);
			return func;
		}

		Janet call_func(const char* func_name) {
			auto j_func = janet_unwrap_function(get_func(func_name));
			Janet out;
			janet_pcall(j_func, 0, NULL, &out, NULL);
		}

		//void call_update_routine(float delta_time);
		//void call_init_routine(sexp event_manager);
		//void call_draw_routine();

		//void call_sexp(const char* proc_name, std::initializer_list<sexp> args);
		//void call_sexp(sexp proc, std::initializer_list<sexp> args);

		//sexp register_c_type(const char* name, unsigned int len);
		//sexp make_cpointer(sexp type_id, void* object);

	private:
		//bool check_for_errors(sexp res);

		JanetTable* m_env;

		//sexp m_ctx;
		//sexp m_env;
		//sexp m_std_err;
	protected:
	};
}
