/**
 * Created by Filip Dabkowski on 01/02/2024.
 */

#ifndef OAKENGINE_MACWINDOW_H
#define OAKENGINE_MACWINDOW_H

#include "OakEngine/Window/Window.h"

#include "SDL.h"


namespace oak {
	class MacWindow : public Window {
	public:
		MacWindow() = default;

		~MacWindow() override;

		void init(const WindowProps& props) override;

		void update() override;

		void setCallback(EventFunction onEvent) override {
			t_eventCallback = onEvent;
		}

	private:
		SDL_Window* t_window = nullptr;
		SDL_Renderer* t_renderer = nullptr;
	};
}

#endif //OAKENGINE_MACWINDOW_H
