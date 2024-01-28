/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_BASEOBJECT_H
#define OAKENGINE_BASEOBJECT_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/Colliders/BaseCollider.h"


namespace oak::Physics {
	using namespace Math;
	using namespace Collisions;

	/// Describes an object location
	struct Transform {
		Vec2 position;
		Vec2 scale;
	};

	/// Base Game Object
	struct BaseObject {
		Transform* transform;
		Collider* collider;

		Vec2 velocity{};
		Vec2 force{};
		float mass = 0;
	};

	using Object = BaseObject;

}

#endif //OAKENGINE_BASEOBJECT_H
