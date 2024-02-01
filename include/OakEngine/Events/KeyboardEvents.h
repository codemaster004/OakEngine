/**
 * Created by Filip Dabkowski on 31/01/2024.
 */

#ifndef OAKENGINE_KEYBOARDEVENTS_H
#define OAKENGINE_KEYBOARDEVENTS_H

#include "OakEngine/Events/Event.h"

namespace oak {

	using KeyCode = long long;


	class KeyEvent : public Event {
	public:
		EVENT_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

		inline KeyCode keyCode() { return t_keyCode; }

	protected:
		KeyEvent() {}

		KeyCode t_keyCode;
	};


	class KeyPressedEvent : KeyEvent {
	public:
		KeyPressedEvent(KeyCode key, bool repeated) : t_repeated(repeated) {
			t_keyCode = key;
		}

		EVENT_TYPE(KeyPressed)

	private:
		bool t_repeated;
	};


	class KeyReleasedEvent : KeyEvent {
	public:
		KeyReleasedEvent(KeyCode key) {
			t_keyCode = key;
		}

		EVENT_TYPE(KeyPressed)
	};

}

#endif //OAKENGINE_KEYBOARDEVENTS_H
