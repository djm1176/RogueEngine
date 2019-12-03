#include "Game.h"

#undef main
int main() {
	Game game;
	if (!game.Init("Test window", 100, 100, 640, 480, SDL_WindowFlags::SDL_WINDOW_SHOWN, SDL_RendererFlags::SDL_RENDERER_ACCELERATED)) {
		return 1;
	}

	while (game.IsRunning()) {
		game.ProcessInput();
		game.Update();
		game.Render();
	}

	game.Exit();

	return 0;
}