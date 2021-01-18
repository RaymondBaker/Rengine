#pragma once
//todo replace with forward delc
#include <chibi/eval.h>

namespace Ren {
	sexp custom_print(sexp ctx, sexp self, sexp_sint_t n, sexp arg1);

	const unsigned int register_callback_argc = 3;
	sexp register_callback(sexp ctx, sexp self, sexp_sint_t n, sexp arg1, sexp arg2, sexp arg3);
}
