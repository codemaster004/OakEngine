/**
 * @file BaseCollider.cpp
 * @brief [Description of file]
 *
 * @author Filip Dabkowski
 * @date 28/01/2024
 */
#include "OakEngine/Physics/Colliders/BaseCollider.h"
#include "OakEngine/Common/Components/Transform.h"

#include "OakEngine/Physics/CollisionTests.h"

#include "OakEngine/Common/Templates.h"


#define N_COLLIDERS 2

namespace oak {
	using namespace Collisions;

	using CollisionTestFunc = Points (*)(Collider*, Transform*, Collider*, Transform*);


	struct CollisionTests {
		CollisionTestFunc functions[N_COLLIDERS][N_COLLIDERS] = {
			{nullptr, nullptr},
			{nullptr, testCircleCircle},
		};
	};


	Points BaseCollider::detectCollision(Collider* a, Transform* aTrans,
										 Collider* b, Transform* bTrans) {
		static const CollisionTests tests{};

		bool swap = b->getType() > a->getType();
		if (swap) {
			oak::swap(a, b);
		}

		Points result = tests.functions[a->getType()][b->getType()](a, aTrans, b, bTrans);

		if (swap) {
			result.normal *= -1;
		}

		return result;
	}

	void Collider::setOrigin(float newX, float newY) {
		origin = {newX, newY};
	}

	Vec2& Collider::getOrigin() {
		return origin;
	}
}