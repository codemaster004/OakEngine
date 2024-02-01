/**
 * Created by Filip Dabkowski on 01/02/2024.
 */

#ifndef OAKENGINE_APPEVENTS_H
#define OAKENGINE_APPEVENTS_H

#include "OakEngine/Events/Event.h"

namespace oak {
	class AppCreatedEvent : public Event {
	public:
		EVENT_TYPE(AppCreated)

		EVENT_CATEGORY(EventCategoryApp)

	};


	class AppClosedEvent : public Event {
	public:
		EVENT_TYPE(AppClosed)

		EVENT_CATEGORY(EventCategoryApp)

	};
}

#endif //OAKENGINE_APPEVENTS_H
