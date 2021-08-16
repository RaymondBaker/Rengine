#include <iostream>
#include <SDL.h>

#include "Scripting/ScriptEngine.h"
#include "Scripting/SchemeBindings.h"
#include "Events/EventManager.h"
#include "Scene/Node.h"

#include <sol/sol.hpp>


const int screen_width = 600, screen_height = 600;



// Find a way to get console bakc
int main(int argc, char* args[])
{
    (void)argc;
    (void)args;

    sol::state lua;
	// open some common libraries
	lua.open_libraries(sol::lib::base, sol::lib::package);
	lua.script("print('bark bark bark! yeehaw')");

	std::cout << std::endl;

    auto scripting_engine = Ren::ScriptEngine();
    //scripting_engine.bind_funcs("Ren", Ren::cfuns);
    //scripting_engine.print_bound_funcs();

    //scripting_engine.load_script();
    //scripting_engine.call_func("ccall");
    //scripting_engine.call_update_routine(64.0f);
    //scripting_engine.call_draw_routine();

    //Ren::EventManager event_man;

    //sexp eventmanager_type = scripting_engine.register_c_type("EventManager", sizeof(Ren::EventManager));
    //sexp event_man_sexp = scripting_engine.make_cpointer(eventmanager_type, &event_man);

    //scripting_engine.bind_func("Register-Callback", Ren::register_callback_argc, Ren::register_callback);
    //scripting_engine.call_init_routine(event_man_sexp);
    //scripting_engine.call_sexp("init", { event_man_sexp });



    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    {
        printf("SDL could not be initialized!\n"
            "SDL_Error: %s\n", SDL_GetError());
        return 0;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("Basic C SDL project",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        screen_width, screen_height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_VULKAN);
    if (!window)
    {
        printf("Window could not be created!\n"
            "SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

	// Event loop exit flag
	bool quit = false;



    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Ren::EventManager event_man(&scripting_engine);
    Ren::Node node(event_man);
    Ren::Node node2(event_man);

    event_man.push_event(std::make_unique<Ren::CollisionEvent>(12, 45));
    event_man.handle_events();

	// Event loop
	while (!quit)
	{
        quit = event_man.push_sdl_events();

        event_man.handle_events();

		// Clear screen
		SDL_RenderClear(renderer);

		// Set renderer color red to draw the square
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

		// Update screen
		SDL_RenderPresent(renderer);
	}


	// Destroy window
	SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;

}