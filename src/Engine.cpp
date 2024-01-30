/**
 * @file Engine.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 28/01/2024
 */

#include "OakEngine/Engine.h"

namespace oak {

	SDL_Renderer* Engine::renderer = nullptr;

	float Engine::delta = 1.0 / 60;


	void Engine::run() {
		while (isRunning) {
			gameTick();
			SDL_Delay((int) (Engine::delta * 1e3));
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
		// Clear objects in renderer on graphics card
		SDL_RenderClear(renderer);

		// Show on screen everything that is inside the current renderer;
		SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
		SDL_RenderPresent(renderer);
	}


	bool Engine::initialize(const char* title, int width, int height) {
		// If SDL did not manage to set itself up.
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			printf("Initialization Error accrued!");
			return false;
		}

		// Try creating window.
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,
								  SDL_WINDOW_RESIZABLE);
		if (window == nullptr) {
			printf("Could not create Renderer!");
			return false;
		}

		// Try creating renderer for drawing on the actual window.
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == nullptr) {
			printf("Could not create Renderer!");
			return false;
		}

		// Set the default drawing color for renderer.
		SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);

		return true;
	}


	void Engine::clean() {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}
}