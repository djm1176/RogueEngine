#include "Game.h"


class Roguelike : public Game {
	// Inherited via Game
	virtual void ProcessInput() override {
		Debug::Log("Hello, world! This is Process Input!");
	}

	virtual void Update() override {
		Debug::Log("Hello, world! This is Update!");
	}

	virtual void Render() override {
		Debug::Log("Hello, world! This is Render!");
		Exit();
	}
};


#undef main
int main() {
	Roguelike game;
	game.Init("Test window", 100, 100, 640, 480, SDL_WindowFlags::SDL_WINDOW_SHOWN, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	return 0;
}