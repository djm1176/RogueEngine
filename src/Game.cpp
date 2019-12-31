#include "Game.h"

Game::Game() {}
Game::~Game() {}

static int GameThread(void* ptr);

bool Game::Init(const char* title, int xPos, int yPos, int width, int height, SDL_WindowFlags windowFlags, SDL_RendererFlags rendererFlags) {
	if (m_initSuccess) {
		//Previously initialized this Game
		return false;
	}

	Debug::Log("Begin startup");
	m_initSuccess = false;
	//Initialize SDL components
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		//Failed to initialize one or more component(s)
		Debug::LogError("\tFailed to initialize one or more component(s) of SDL2");
		return false;
	}
	Debug::Log("\tInitialized SDL2");

	//Instantiate Window
	m_Window = SDL_CreateWindow(title, xPos, yPos, width, height, windowFlags);
	if (m_Window == nullptr) {
		//Failed to instantiate SDL Window
		Debug::LogError("\tFailed to initialize SDL2 Window");
		return false;
	}
	Debug::Log("\tCreated Game Window");

	//Instantiate Renderer
	m_Renderer = SDL_CreateRenderer(m_Window, -1, rendererFlags);
	if (m_Renderer == nullptr) {
		//Failed to instantiate primary renderer
		Debug::LogError("\tFailed to initialize SDL2 Renderer");
		Cleanup(m_Window);
		return false;
	}
	Debug::Log("\tCreated Game Renderer");
	Debug::Log("\nStartup successful\n");

	//Initialization successful
	m_initSuccess = true;
	m_isRunning = true;

	Start();

	while (m_isRunning) {
		m_ProcessInput();

		Update();
		Render();
	}

	return true;
}

void Game::Exit() {
	m_isRunning = false;
	Debug::Log("Exiting Game");
	Cleanup(m_Window, m_Renderer);
	
	SDL_Quit();
}

void Game::m_ProcessInput() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_EventType::SDL_QUIT:
		Exit();
		break;

	default:
		break;
	}
}