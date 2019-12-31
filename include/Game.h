#pragma once

#include "SDL.h"
#include "Flags.h"
#include "Logger.h"
#include "Cleanup.h"
#include "Vector.h"

class Game {
public:
	Game();
	~Game();

	//Internally required methods
	bool Init(const char* title, int xPos, int yPos, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
	void Exit();

	bool IsRunning() { return m_isRunning; }


	//User-defined required methods
	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

private:
	void m_ProcessInput();

	bool m_initSuccess;
	bool m_isRunning;
	SDL_Thread* m_GameThread;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};

