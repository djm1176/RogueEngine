#pragma once

#include <string>
#include <map>
#include <stdexcept>
#include "SDL.h"
#include "Game.h"
#include "Graphics.h"

/// <summary>
/// Controls the loading and management of Spritesheets.
/// </summary>
class SpritesheetManager {
public:
	const SDL_Texture& loadSpritesheet(std::string filename, std::string name) {
		SDL_Texture* _sheet = nullptr;
		try {
			_sheet = mSpritesheets.at(name);
			return *_sheet; //Spritesheet found, return it
		} catch (const std::out_of_range& exception) {}
		

		//Otherwise, generate a new Spritesheet
		//TODO: This should be its own function
		_sheet = Graphics::instance()->loadTexture(filename);
	}
	
	const SDL_Texture* getSpritesheet(std::string name) {
		SDL_Texture* _sheet = nullptr;
		try {
			_sheet = mSpritesheets.at(name);
		} catch (const std::out_of_range & exception) {}
		return _sheet;
	}

private:
	//TODO: EFF Internally keep track with an int instead of string
	std::map <std::string, SDL_Texture*> mSpritesheets;

};