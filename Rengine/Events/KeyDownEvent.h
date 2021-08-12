#pragma once

#include "Event.h"
#include <iostream>
#include <SDL_keycode.h>


namespace Ren {
	class KeyDownEvent : public Event
	{
	public:
		KeyDownEvent(SDL_Keycode key_code) : Event (EventType::KeyDown), key_code(key_code) {}
		std::string to_string() const override {
			return "KeyDownEvent";
		}
		const SDL_Keycode key_code;
	};
}
