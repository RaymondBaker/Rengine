#include "EventManager.h"
#include <SDL.h>
#include "KeyDownEvent.h"

namespace Ren {
	bool EventManager::push_sdl_events() {
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_QUIT:
				return true;
				break;
			case SDL_KEYDOWN:
				push_event(std::make_unique<KeyDownEvent>(e.key.keysym.sym));
				break;
			}
		}
		return false;
	}
}
