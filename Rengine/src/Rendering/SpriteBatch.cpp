#include "Rendering/SpriteBatch.h"

#include <SDL.h>
#include <spdlog/spdlog.h>

namespace Ren {
	void SpriteBatch::draw(SDL_Rect src_rect, SDL_Rect dest_rect, SDL_Texture* texture)
	{
		if (!m_renderer) {
			spdlog::error("Tried to draw without renderer set");
			return;
		}
		SDL_RenderCopy(m_renderer, texture, &src_rect, &dest_rect);
	}
}
