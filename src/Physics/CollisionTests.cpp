/**
 * @file CollisionTests.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 30/01/2024
 */
#include "OakEngine/Physics/CollisionTests.h"
#include "OakEngine/Physics/Colliders/CircleCollider.h"

#include <cassert>


namespace oak {
	using namespace Collisions;

	Points Collisions::testCircleCircle(Collider* a, Transform* aTrans, Collider* b, Transform* bTrans) {
		assert(a->getType() == Collider::Circle && b->getType() == Collider::Circle);

		auto circleA = dynamic_cast<CircleCollider*>(a);
		auto circleB = dynamic_cast<CircleCollider*>(b);

		Vec2 centerA = circleA->getOrigin() + aTrans->position;
		Vec2 centerB = circleB->getOrigin() + bTrans->position;

		Vec2 ab = centerB - centerA;
		float distance = ab.length();

		if (distance > circleA->getR() + circleB->getR()) {
			return CollisionPoints{};
		}

		Vec2 normal = ab.normalised();

		Vec2 deepA = centerA + normal * circleA->getR();
		Vec2 deepB = centerB - normal * circleB->getR();

		return {deepA, deepB};
	}
}