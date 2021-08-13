#include "EventManager.h"
#include <SDL.h>
#include "KeyEvent.h"

namespace Ren {
	bool EventManager::push_sdl_events() {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				return true;
				break;
			case SDL_KEYDOWN:
				push_event(std::make_unique<KeyEvent>(e.key.keysym.sym, KeyEventType::KeyDown));
				break;
			case SDL_KEYUP:
				push_event(std::make_unique<KeyEvent>(e.key.keysym.sym, KeyEventType::KeyUp));
				break;
			}
		}
		return false;
	}
}
