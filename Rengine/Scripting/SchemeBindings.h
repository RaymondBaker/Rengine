#pragma once
//todo replace with forward delc
#include <janet.h>
#include <iostream>

namespace Ren {
	static Janet custom_print(int32_t argc, Janet* argv) {
		// Throw error in janet if more than one arg passed
		janet_fixarity(argc, 1);
		auto string = janet_getstring(argv, 0);
			   
		std::cout << string << std::endl;

		return janet_wrap_nil();
	}

	static const JanetReg cfuns[] = {
		{
			"custom_print", custom_print, "testing c bindings"
		},
		{
			NULL, NULL, NULL
		}
	};

	//sexp custom_print(sexp ctx, sexp self, sexp_sint_t n, sexp arg1);
	//const unsigned int register_callback_argc = 3;
	//sexp register_callback(sexp ctx, sexp self, sexp_sint_t n, sexp event_manager, sexp event_type, sexp callback_proc);
}
