/**
 * @file Engine.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 28/01/2024
 */

#include "OakEngine/Engine.h"

namespace oak {

	void Engine::run() {
		while (isRunning) {
			gameTick();
			SDL_Delay((int) (1.0 / 60 * 1e3));
		}
	}

	void Engine::gameMechanics() {

	}

	void Engine::gameTick() {
		handleInputs();
		gameMechanics();
		stepObjects();
		renderFrame();
	}

	void Engine::handleInputs() {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				// handle system QUIT case
				case SDL_QUIT:
					isRunning = false;
					break;
				case SDL_KEYDOWN: // Additional case to QUIT on Esc key
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						isRunning = false;
					}
					break;
			}
		}
	}

	void Engine::stepObjects() {

	}

	void Engine::renderFrame() {
		t_window->update();
	}

	void Engine::clean() {

	}
}