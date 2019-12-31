#include <string>

#include "SDL.h"
#include "Logger.h"

SDL_Texture* loadTexture(const std::string& filename, SDL_Renderer *renderer) {
	//Initialize to nullptr to avoid dangling pointer issues
	SDL_Texture* texture = nullptr;
	//Load the image
	SDL_Surface* loadedImage = SDL_LoadBMP(filename.c_str());
	//If the loading went ok, convert to texture and return the texture
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		//Make sure converting went ok too
		if (texture == nullptr) {
			Debug::LogError("CreateTextureFromSurface: Failed to load texture from file using loadTexture");
		}
	} else {
		Debug::LogError("LoadBMP: Failed to load BMP from file using loadTexture");
	}
	return texture;
}