#include "Game.h"


class Roguelike : public Game {
	// Inherited via Game
	virtual void ProcessInput() override {
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

	virtual void Update() override {
		
	}

	virtual void Render() override {
		
		
	}
};


#undef main
int main() {
	Roguelike game;
	game.Init("Test window", 100, 100, 640, 480, SDL_WindowFlags::SDL_WINDOW_SHOWN, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	return 0;
}