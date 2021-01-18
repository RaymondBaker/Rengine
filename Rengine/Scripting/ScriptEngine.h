#pragma once
#include <chibi/eval.h>
#include <vector>

namespace Ren
{
	class ScriptEngine {
	public:
		ScriptEngine();
		~ScriptEngine();
		void load_script(const char* main_file = "Scripts/main.scm");


		template<typename T>
		void bind_func(const char* func_name, unsigned int arg_num, T function)
		{
			sexp_define_foreign(m_ctx, m_env, func_name, arg_num, function);
		}

		void call_update_routine(float delta_time);
		void call_init_routine(sexp event_manager);
		void call_draw_routine();

		void call_sexp(const char* proc_name, std::initializer_list<sexp> args);
		void call_sexp(sexp proc, std::initializer_list<sexp> args);

		sexp register_c_type(const char* name, unsigned int len);
		sexp make_cpointer(sexp type_id, void* object);

	private:
		bool check_for_errors(sexp res);

		sexp m_ctx;
		sexp m_env;
		sexp m_std_err;
	protected:
	};
}
