#pragma once

#include "SDL.h"
#include "Flags.h"

class Game {
public:
	Game();
	~Game();

	//Internally required methods
	bool Init(const char* title, int xPos, int yPos, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
	void Exit();

	bool IsRunning() { return m_isRunning; }


	//User-defined required methods
	virtual void ProcessInput() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	bool m_initSuccess;
	bool m_isRunning;
	SDL_Thread* m_GameThread;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};

