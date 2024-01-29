/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_COLLISIONTESTS_H
#define OAKENGINE_COLLISIONTESTS_H

#include "OakEngine/Physics/BaseObject.h"

namespace oak::Collisions {
	using namespace Physics;

	Points testCircleCircle(Collider*, Transform*, Collider*, Transform*) {
		return {};
	}

//	Points testCircleCircle(BaseCollider* a, Physics::Transform* aTrans,
//							BaseCollider* b, Physics::Transform* bTrans);

//	CollisionPoints testCircleLine(Collider* circle, Transform* cTrans,
//								   Collider* line, Transform* lTrans);
}

#endif //OAKENGINE_COLLISIONTESTS_H
