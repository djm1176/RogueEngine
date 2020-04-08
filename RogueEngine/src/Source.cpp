#include "Game.h"
#include "Graphics.h"

class Roguelike : public Game {

	// Inherited via Game
	virtual void OnStart() override {

	}

	virtual void OnUpdate() override {

	}

	virtual void OnExit() override {

	}

};


#undef main
int main() {
	Roguelike game;
	game.Init("Test window", 100, 100, 640, 480, SDL_WindowFlags::SDL_WINDOW_SHOWN, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	return 0;
}