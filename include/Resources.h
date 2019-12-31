#pragma once

#include <string>
#include <iostream>

#include "SDL.h"

namespace Resources {

	static std::string GetResourcePath(const std::string& subdirectory = "") {
#ifdef _WIN32
		const char PATH_SEP = '\\';
#else
		const char PATH_SEP = '/';
#endif
		static std::string baseRes;
		if (baseRes.empty()) {
			char* basePath = SDL_GetBasePath();
			if (basePath) {
				baseRes = basePath;
				SDL_free(basePath);
			} else {
				std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
				return "";
			}
			//We replace the last bin/ with res/ to get the the resource path
			size_t pos = baseRes.rfind("bin");
			baseRes = baseRes.substr(0, pos) + "res" + PATH_SEP;
		}
		return subdirectory.empty() ? baseRes : baseRes + subdirectory + PATH_SEP;
	}

}