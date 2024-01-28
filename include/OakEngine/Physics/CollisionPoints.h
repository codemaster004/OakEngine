/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_COLLISIONPOINTS_H
#define OAKENGINE_COLLISIONPOINTS_H

#include "OakEngine/Math/Vec2.h"


namespace oak::Collision {
	using namespace Math;

	struct CollisionPoints {
		Vec2 a; ///< Furthest point of A into B
		Vec2 b; ///< Furthest point of A into B
		Vec2 normal; ///< B - A normalized
		float depth = 0; ///< Length of B - A
		bool hasCollision = false;

		CollisionPoints() = default;


		CollisionPoints(Vec2 a, Vec2 b) : a(a), b(b) {
			Vec2 ab = b - a;
			if (ab.length() > 0) {
				hasCollision = true;
				depth = ab.length();
				normal = ab.normalised();
			}
		}
	};

	using Points = CollisionPoints;
}

#endif //OAKENGINE_COLLISIONPOINTS_H
