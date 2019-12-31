#include "Game.h"

class Roguelike : public Game {

	SDL_Texture* testTexture;
	SDL_Rect testRect;

	// Inherited via Game
	virtual void Start() override {
		testTexture = loadTexture(Resources::GetResourcePath() + "64.bmp", GetRenderer());

		testRect.x = 0;
		testRect.y = 0;
		testRect.w = 64;
		testRect.h = 64;

	}

	virtual void Update() override {

	}

	virtual void Render() override {
		blit(testTexture, GetRenderer(), &testRect);
	}
};


#undef main
int main() {
	Roguelike game;
	game.Init("Test window", 100, 100, 640, 480, SDL_WindowFlags::SDL_WINDOW_SHOWN, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	return 0;
}