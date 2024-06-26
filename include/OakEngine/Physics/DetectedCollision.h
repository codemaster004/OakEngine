/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_DETECTEDCOLLISION_H
#define OAKENGINE_DETECTEDCOLLISION_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/CollisionPoints.h"
#include "OakEngine/Physics/PhysicsObject.h"


namespace oak::Collisions {
	struct DetectedCollision {
		Physics::PhysicsObject* A; ///< Object A taking part in the collision.
		Physics::PhysicsObject* B; ///< Object B taking part in the collision.
		Vec2 a, b; ///< Points of collision

		Vec2 normal; ///< B - A normalized
		float depth = 0; ///< Length of B - A
		bool hasCollision = false; ///< Collision flag

		DetectedCollision() {
			A = nullptr;
			B = nullptr;
		}

		DetectedCollision(Physics::PhysicsObject*& objA, Physics::PhysicsObject*& objB, CollisionPoints& points)
			: A(objA), B(objB) {
			a = points.a;
			b = points.b;
			normal = points.normal;
			depth = points.depth;
			hasCollision = points.hasCollision;
		}

	};
}


#endif //OAKENGINE_DETECTEDCOLLISION_H
