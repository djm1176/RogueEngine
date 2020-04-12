#pragma once

#include <string>

#include "SDL.h"
#include "Logger.h"

class Graphics {
	friend class Game;
	//friend const SDL_Texture& SpritesheetManager::loadSpritesheet(std::string, std::string);
	friend class SpritesheetManager;
	//Singleton Design Pattern
	//SINGLETON_LINK https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
	//Credit to: Martin York
public:
	static Graphics* instance() {
		static Graphics* instance;
		return instance;
	}

private:
	Graphics() {}

	SDL_Renderer* m_Renderer = nullptr;

public:
	Graphics(Graphics const&) = delete;
	void operator=(Graphics const&) = delete;

private:
	bool init(SDL_Window* m_Window, SDL_RendererFlags rendererFlags) {
		//Instantiate Renderer
		m_Renderer = SDL_CreateRenderer(m_Window, -1, rendererFlags);
		return m_Renderer = nullptr;
	}

	SDL_Texture* loadTexture(const std::string& filename) {
		//Initialize to nullptr to avoid dangling pointer issues
		SDL_Texture* texture = nullptr;
		//Load the image
		SDL_Surface* loadedImage = SDL_LoadBMP(filename.c_str());
		//If the loading went ok, convert to texture and return the texture
		if (loadedImage != nullptr) {
			texture = SDL_CreateTextureFromSurface(m_Renderer, loadedImage);
			SDL_FreeSurface(loadedImage);
			//Make sure converting went ok too
			if (texture == nullptr) {
				Debug::LogError("CreateTextureFromSurface: Failed to load texture from file using loadTexture");
			}
		} else {
			Debug::LogError("LoadBMP: Failed to load BMP from file using loadTexture (filepath: '" + filename + "')");
		}
		return texture;
	}

	void Render() {
		
	}

	void blit(SDL_Texture* tex, SDL_Rect* rect) {
		SDL_RenderCopy(m_Renderer, tex, nullptr, rect);
	}

};