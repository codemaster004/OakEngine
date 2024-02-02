/**
 * Created by Filip Dabkowski on 01/02/2024.
 */

#ifndef OAKENGINE_WINDOW_H
#define OAKENGINE_WINDOW_H

#include "OakEngine/Events/Event.h"

namespace oak {
	struct WindowProps {
		int width, height;
		const char* title;

		explicit WindowProps(int width=640, int height=480, const char* title="Powered by Oak")
		: width(width), height(height), title(title) {

		}
	};

	using EventFunction = void (*)(Event&);


	class Window {
	public:
		virtual ~Window() = default;

		virtual void init(const WindowProps& props) = 0;

		virtual void update() = 0;

		virtual void setCallback(EventFunction onEvent) = 0;

		static Window* createWindow(const WindowProps& props);

	protected:
		WindowProps t_props;

		EventFunction t_eventCallback = nullptr;
	};
}

#endif //OAKENGINE_WINDOW_H
