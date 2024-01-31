/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_COLLISIONTESTS_H
#define OAKENGINE_COLLISIONTESTS_H

#include "OakEngine/Physics/PhysicsObject.h"


namespace oak::Collisions {

	CollisionPoints testCircleCircle(BaseCollider*, Transform*, BaseCollider*, Transform*);

//	CollisionPoints testCircleLine(Collider* circle, Transform* cTrans,
//								   Collider* line, Transform* lTrans);
}


#endif //OAKENGINE_COLLISIONTESTS_H
