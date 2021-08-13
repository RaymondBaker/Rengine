#pragma once

#include "Event.h"
#include <iostream>
#include <SDL_keycode.h>


namespace Ren {
	enum class KeyEventType {
		KeyDown,
		KeyUp
	};
	class KeyEvent : public Event
	{
	public:
		KeyEvent(SDL_Keycode key_code, KeyEventType key_event_type) : Event (EventType::KeyEvent), key_code(key_code), key_event_type (key_event_type) {}
		std::string to_string() const override {
			switch (key_event_type) {
			case KeyEventType::KeyDown:
				return "KeyDown";
			case KeyEventType::KeyUp:
				return "KeyUp";
			}
		}
		const SDL_Keycode key_code;
		const KeyEventType key_event_type;
	};
}
