#pragma once

struct SDL_Renderer;
struct SDL_Window;

namespace Ren 
{
	class SpriteBatch;

	class Renderer
	{
	public:
		Renderer(SDL_Window *window);
		~Renderer();
		void clear();
		void draw(SpriteBatch &sprite_batch);
		void present();
	private:
		SDL_Renderer *m_renderer;
	protected:
	};
}

