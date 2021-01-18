#include "Renderer.h"
#include <SDL.h>
#include <vector>
#include "SpriteBatch.h"

namespace Ren {
    Renderer::Renderer(SDL_Window* window)
    {
        m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(m_renderer);
    }

    void Renderer::clear()
    {
        SDL_RenderClear(m_renderer);
    }

    void Renderer::draw(SpriteBatch sprite_batch)
    {

    }

    void Renderer::present()
    {
        SDL_RenderPresent(m_renderer);
    }
}
