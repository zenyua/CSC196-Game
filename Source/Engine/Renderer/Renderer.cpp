#include "Renderer.h"
#include <SDL2-2.28.0/include/SDL.h>

namespace kiko {
	SDL_Renderer* renderer{ nullptr };
	SDL_Window* window{ nullptr };

	void CreateWindow(const std::string& title, int width, int height) {
		SDL_Init(SDL_INIT_VIDEO);

		window = SDL_CreateWindow(title.c_str(), 100, 100, width, 
			height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC
			| SDL_RENDERER_ACCELERATED);
	}
	
	bool Renderer::Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO);
		return true;
	}

	void Renderer::Shutdown()
	{
	}

	void Renderer::CreateWindow(const std::string& title, int width, int height)
	{
		m_width = width;
		m_height = height;
		window = SDL_CreateWindow(title.c_str(), 100, 100, m_width,
			m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC
			| SDL_RENDERER_ACCELERATED);
	}

	void Renderer::BeginFrame()
	{
		SDL_RenderClear(m_renderer);
	}

	void Renderer::EndFrame()
	{
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::SetColor(int r, int g, int b, int a)
	{
		SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
	}

	void Renderer::DrawLine(int x1, int y1, int x2, int y2)
	{
		SDL_RenderDrawLine(m_renderer, x1, y1, x2, y2);
	}

	void Renderer::DrawPoint(int x, int y)
	{
		SDL_RenderDrawPoint(m_renderer, x, y);
	}

	void Renderer::DrawPoint(float x, float y)
	{
		SDL_RenderDrawPointF(m_renderer, x, y);
	}

}