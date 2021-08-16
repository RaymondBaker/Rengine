#pragma once

struct SDL_Rect;
struct SDL_Texture;

namespace Ren {
	class SpriteBatch
	{
	public:
		void draw(SDL_Rect src_rect, SDL_Rect dest_rect, SDL_Texture* texture);
	private:
	protected:
	};
}
