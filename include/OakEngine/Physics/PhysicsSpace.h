/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_PHYSICSSPACE_H
#define OAKENGINE_PHYSICSSPACE_H

#include "OakEngine/Physics/BaseObject.h"
#include "OakEngine/Physics/DetectedCollision.h"

#include "DataStructs/Vector.h"

namespace oak::Physics {
	using Collision = Collisions::DetectedCollision;

	class PhysicsSpace {
	private:
		Vector<BaseObject*> objects;
		Vector<Collision> collisions;
	public:
		void addObject(BaseObject* newObject);

		void spaceStep();

		void handleCollisions();
	};
}

#endif //OAKENGINE_PHYSICSSPACE_H
