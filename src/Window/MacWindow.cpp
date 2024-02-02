/**
 * @file MacWindow.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 02/02/2024
 */
#include "OakEngine/Logs/Logs.h"
#include "OakEngine/Window/MacWindow.h"


namespace oak {
	Window* Window::createWindow(const WindowProps& props) {
		Window* newWindow = new MacWindow();
		newWindow->init(props);
		return newWindow;
	}

	MacWindow::~MacWindow() {
		SDL_DestroyWindow(t_window);
		SDL_DestroyRenderer(t_renderer);
		SDL_Quit();
	}

	void MacWindow::init(const WindowProps& props) {
		t_props.width = props.width;
		t_props.height = props.height;
		t_props.title = props.title;

		// If SDL did not manage to set itself up.
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			OAK_LOG_ERROR("SDL Initialization Error accrued!");
			return;
		}

		// Try creating window.
		t_window = SDL_CreateWindow(t_props.title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
									t_props.width, t_props.height, SDL_WINDOW_RESIZABLE);

		if (t_window == nullptr) {
			OAK_LOG_ERROR("Could not create Renderer!");
			return;
		}

		// Try creating renderer for drawing on the actual window.
		t_renderer = SDL_CreateRenderer(t_window, -1, 0);
		if (t_renderer == nullptr) {
			OAK_LOG_ERROR("Could not create Renderer!");
			return;
		}

		// Set the default drawing color for renderer.
		SDL_SetRenderDrawColor(t_renderer, 30, 30, 30, 255);

		OAK_LOG_INFO("Window created successfully");

	}

	void MacWindow::update() {
		// Clear objects in renderer on graphics card
		SDL_RenderClear(t_renderer);

		// Show on screen everything that is inside the current renderer;
		SDL_SetRenderDrawColor(t_renderer, 30, 30, 30, 255);
		SDL_RenderPresent(t_renderer);
	}
}