#include "Game.h"
#include "Graphics.h"

class Roguelike : public Game {

	SDL_Texture* testTexture;
	SDL_Rect* testRect;

	ObjectManager manager;

	GameObject& go{manager.addGameObject()};

	// Inherited via Game
	virtual void OnStart() override {
		testTexture = loadTexture(Resources::GetResourcePath() + "red128.bmp", GetRenderer());
		testRect = new SDL_Rect();


		testRect->x = 0;
		testRect->y = 0;
		testRect->w = 64;
		testRect->h = 64;

		
		go.addComponent<Transform>();
		Debug::Log(go.getComponent<Transform>().position());
	}

	virtual void OnUpdate() override {
		testRect->x = rand() % 500;
		testRect->y = rand() % 500;
	}

	//TODO: Rendering should be done internally and not really exposed to the game
	virtual void OnRender() override {
		blit(testTexture, GetRenderer(), testRect);
	}

	virtual void OnExit() override {
		SDL_DestroyTexture(testTexture);
	}

};


#undef main
int main() {
	Roguelike game;
	game.Init("Test window", 100, 100, 640, 480, SDL_WindowFlags::SDL_WINDOW_SHOWN, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	return 0;
}