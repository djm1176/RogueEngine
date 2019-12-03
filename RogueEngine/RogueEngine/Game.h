#pragma once

#include "SDL.h"
#include "Flags.h"

class Game {
public:
	Game();
	~Game();

	bool Init(const char* title, int xPos, int yPos, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
	
	void ProcessInput();
	void Update();
	void Render();
	void Exit();
	bool IsRunning() { return m_isRunning; }

private:
	bool m_initSuccess;
	bool m_isRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};

