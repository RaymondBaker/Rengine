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
	
	    // One of several ways to begin the Janet vm.
	    //janet_dostring(m_env, "(print `hello, world!`)", "main", NULL);
	
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

	//void ScriptEngine::call_update_routine(float delta_time) {
	//	/* declare and preserve local variables */
	//	//sexp res;
	//	//sexp_gc_var3(obj1, obj2, obj3);
	//	//sexp_gc_preserve3(m_ctx, obj1, obj2, obj3);

	//	///* construct a Scheme expression to eval */
	//	//obj1 = sexp_intern(m_ctx, "update", -1);
	//	//obj3 = sexp_make_flonum(m_ctx, delta_time);
	//	//obj2 = sexp_list2(m_ctx, obj1, obj3);

	//	//res = sexp_eval(m_ctx, obj2, NULL);
	//	//check_for_errors(res);


	//	///* release the local variables */
	//	//sexp_gc_release2(m_ctx);
	//}

	//void ScriptEngine::call_init_routine(sexp event_manager) {
	//	///* declare and preserve local variables */
	//	//sexp res;
	//	//sexp_gc_var2(obj1, obj2);
	//	//sexp_gc_preserve2(m_ctx, obj1, obj2);

	//	///* construct a Scheme expression to eval */
	//	//obj1 = sexp_intern(m_ctx, "init", -1);
	//	//obj2 = sexp_list2(m_ctx, obj1, event_manager);

	//	//res = sexp_eval(m_ctx, obj2, NULL);
	//	//check_for_errors(res);


	//	///* release the local variables */
	//	//sexp_gc_release2(m_ctx);
	//}


	//void ScriptEngine::call_draw_routine() {
		///* declare and preserve local variables */
		//sexp res;
		//sexp_gc_var2(obj1, obj2);
		//sexp_gc_preserve2(m_ctx, obj1, obj2);

		////sexp_eval_string(m_ctx, "(test-func)", -1, NULL);

		///* construct a Scheme expression to eval */
		//obj1 = sexp_intern(m_ctx, "draw", -1);
		//obj2 = sexp_cons(m_ctx, obj1, SEXP_NULL);
		////sexp_make_cpointer(m_ctx, )
		//res = sexp_eval(m_ctx, obj2, NULL);
		//check_for_errors(res);

		///* release the local variables */
		//sexp_gc_release2(m_ctx);
	//}


	//void ScriptEngine::call_sexp(const char* proc_name, std::initializer_list<sexp> args)
	//{
	//	//sexp res;
	//	//sexp_gc_var1(obj1);
	//	//sexp_gc_preserve1(m_ctx, obj1);


	//	///* construct a Scheme expression to eval */
	//	//obj1 = sexp_intern(m_ctx, proc_name, -1);
	//	//for (auto arg : args) {
	//	//	obj1 = sexp_cons(m_ctx, obj1, arg);
	//	//}
	//	//obj1 = sexp_cons(m_ctx, obj1, SEXP_NULL);
	//	//res = sexp_eval(m_ctx, obj1, NULL);
	//	//check_for_errors(res);

	//	///* release the local variables */
	//	//sexp_gc_release2(m_ctx);
	//}

	//void ScriptEngine::call_sexp(sexp proc, std::initializer_list<sexp> args) {
	//	//sexp res;
	//	//sexp_gc_var1(obj1);
	//	//sexp_gc_preserve1(m_ctx, obj1);


	//	///* construct a Scheme expression to eval */
	//	//obj1 = proc;

	//	//for (auto arg : args) {
	//	//	obj1 = sexp_cons(m_ctx, obj1, arg);
	//	//}

	//	//obj1 = sexp_cons(m_ctx, obj1, SEXP_NULL);
	//	//res = sexp_eval(m_ctx, obj1, NULL);
	//	//check_for_errors(res);

	//	///* release the local variables */
	//	//sexp_gc_release2(m_ctx);
	//}

	//sexp ScriptEngine::register_c_type(const char* name, unsigned int len)
	//{
	//	//sexp res;
	//	//sexp_gc_var1(obj1);
	//	//sexp_gc_preserve1(m_ctx, obj1);

	//	//obj1 = sexp_c_string(m_ctx, name, len);
	//	//
	//	//// Change from null if you want scheme to call free on object
	//	//res = sexp_register_c_type(m_ctx, obj1, NULL);
	//	//if (check_for_errors(res))
	//	//{
	//	//	return SEXP_NULL;
	//	//}

	//	//return res;

	//	//sexp_gc_release2(m_ctx);
	//}

	//sexp ScriptEngine::make_cpointer(sexp type_id, void* object)
	//{
	//	//sexp res;

	//	//// if 1 for last arg it calls finalizer on cleanup
	//	//res = sexp_make_cpointer(m_ctx, sexp_type_tag(type_id), object, SEXP_NULL, 0);

	//	//if (check_for_errors(res))
	//	//{
	//	//	return SEXP_NULL;
	//	//}

	//	//return res;
	//}

//	bool ScriptEngine::check_for_errors(sexp res)
//	{
//		//if (sexp_exceptionp(res)) {
//		//	std::cerr << "\n\nScript Error!:\n\t";
//		//	sexp_print_exception(m_ctx, res, m_std_err);
//		//	std::cerr << std::endl;
//		//	return true;
//		//}
//		//return false;
//		return false;
//	}

}

