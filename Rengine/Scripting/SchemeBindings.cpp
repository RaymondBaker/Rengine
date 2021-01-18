#include "SchemeBindings.h"
#include <iostream>
#include "../Events/EventManager.h"

namespace Ren {

	sexp custom_print(sexp ctx, sexp self, sexp_sint_t n, sexp arg1 ) {
		std::cout << "called c from scheme" << "\n";
		if (sexp_stringp(arg1))
		{
			std::cout << sexp_string_length(arg1) << "\n";
			std::cout << (unsigned char*)sexp_string_data(arg1) << "\n";
		}
		return SEXP_NULL;
	}

	// arg1 event manager
	// arg2 event type int
	// arg3 callback proc
	sexp register_callback(sexp ctx, sexp self, sexp_sint_t n, sexp event_manager, sexp event_type, sexp callback_proc)
	{
		//Somehow this is not a c pointer
		//if (sexp_cpointerp(event_manager))
		//{
		//	std::cerr << "Register-Callback requires proc as third argument" << "\n";
		//}
		if (sexp_procedurep(callback_proc))
		{
			std::cout << "Callback Event: " << sexp_unbox_fixnum(event_type) << "\n";

			auto event_man = static_cast<EventManager*>(sexp_cpointer_value(event_manager));
			event_man->deleteme();

			//add arg3 to event manager
			return SEXP_TRUE;
		}
		else
		{
			std::cerr << "Register-Callback requires proc as third argument" << "\n";
			return SEXP_FALSE;
		}
	}

}