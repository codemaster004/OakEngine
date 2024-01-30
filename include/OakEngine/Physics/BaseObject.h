/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_BASEOBJECT_H
#define OAKENGINE_BASEOBJECT_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/Colliders/BaseCollider.h"
#include "OakEngine/Common/Components/Transform.h"


namespace oak::Physics {

	/// Base Game Object
	struct BaseObject {
		Transform* transform = nullptr;
		Collisions::BaseCollider* collider = nullptr;

		Vec2 velocity{};
		Vec2 force{};
		float mass = 0;

		BaseObject() {
			transform = new Transform;
		}

		BaseObject(float x, float y) {
			transform = new Transform{x, y, 1, 1};
		}
	};

}

#endif //OAKENGINE_BASEOBJECT_H
