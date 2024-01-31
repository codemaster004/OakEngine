/**
 * Created by Filip Dabkowski on 31/01/2024.
 */

#ifndef OAKENGINE_DYNAMICSPACE_H
#define OAKENGINE_DYNAMICSPACE_H

#include "OakEngine/Physics/PhysicsSpace.h"
#include "OakEngine/Physics/Dynamic/DynamicObject.h"

namespace oak::Physics {
	class DynamicSpace : public PhysicsSpace {
	private:
		float t_gravity = 9.81;

	public:
		void addDynamicObject(DynamicObject* newObject);

		void applyGravity();

		void moveObjects();

		void step();
	};
}

#endif //OAKENGINE_DYNAMICSPACE_H
