/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_DETECTEDCOLLISION_H
#define OAKENGINE_DETECTEDCOLLISION_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/CollisionPoints.h"

typedef struct Object Object; // todo remove hopefully include full object


namespace oak::Collision {
	using namespace Math;


	struct DetectedCollision {
		Object* A; ///< Object A taking part in the collision.
		Object* B; ///< Object B taking part in the collision.
		Vec2 a, b; ///< Points of collision

		Vec2 normal; ///< B - A normalized
		float depth = 0; ///< Length of B - A
		bool hasCollision = false; ///< Collision flag

		DetectedCollision(Object* objA, Object* objB, Points points) : A(objA), B(objB) {
			a = points.a;
			b = points.b;
			normal = points.normal;
			depth = points.depth;
			hasCollision = points.hasCollision;
		}

	};
}


#endif //OAKENGINE_DETECTEDCOLLISION_H
