/**
 * Created by Filip Dabkowski on 31/01/2024.
 */

#ifndef OAKENGINE_EVENT_H
#define OAKENGINE_EVENT_H

#include "OakEngine/Core.h"

namespace oak {

	enum class EventType {
		None = 0,
		AppCreated, AppClosed,
		KeyPressed, KeyReleased,
	};

	enum EventCategory {
		None = 0,
		EventCategoryApp = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
	};


	class Event {
	public:

		virtual EventType getEventType() const = 0;

		virtual int getCategoryFlags() const = 0;

		inline bool isInCategory(EventCategory category) {
			return getCategoryFlags() & category;
		}

	protected:
		bool t_handled = false;
	};


#define EVENT_TYPE(type) EventType getEventType() const override { return EventType::type; }
#define EVENT_CATEGORY(categories) int getCategoryFlags() const override { return categories; }

}

#endif //OAKENGINE_EVENT_H
