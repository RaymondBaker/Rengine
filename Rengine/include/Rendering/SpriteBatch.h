#pragma once

struct SDL_Rect;
struct SDL_Texture;
struct SDL_Renderer;

namespace Ren {
	class SpriteBatch
	{
	public:
		// loads all draw calls
		void draw(SDL_Rect src_rect, SDL_Rect dest_rect, SDL_Texture* texture);
		// organizes and draws in batchs
		void blit() {}
	private:
		SDL_Renderer *m_renderer;
	protected:
	};
}
