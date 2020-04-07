#pragma once

#include "SDL.h"
#include "Flags.h"
#include "Logger.h"
#include "Cleanup.h"
#include "Vector.h"
#include "Graphics.h"
#include "Resources.h"
#include "GameObject.h"
#include "Transform.h"

class Game {
public:
	Game();
	~Game();

	//Internally required methods
	
	bool Init(const char* title, int xPos, int yPos, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags);
	void Exit();

	bool IsRunning() { return m_isRunning; }

	SDL_Renderer* GetRenderer() { return m_Renderer; }

	//User-defined required methods
	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	//virtual void OnRender() = 0; Rendering moved to internal call; should not be handled by source game code
	virtual void OnExit() = 0;

private:
	void m_ProcessInput();

	bool m_initSuccess;
	bool m_isRunning;
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

};

