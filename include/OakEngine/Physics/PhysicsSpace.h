/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_PHYSICSSPACE_H
#define OAKENGINE_PHYSICSSPACE_H

#include "DataStructs/Vector.h"

#include "OakEngine/Physics/PhysicsObject.h"
#include "OakEngine/Physics/DetectedCollision.h"
#include "OakEngine/Physics/Solvers/Solver.h"


namespace oak::Physics {
	using Collision = Collisions::DetectedCollision;

	class PhysicsSpace {
	protected:
		Vector<PhysicsObject*> objects;
		Vector<Collision> collisions;

		Vector<Collisions::Solver*> solvers;

	public:
		void addObject(PhysicsObject* newObject);
		// todo: remove object

		void addSolver(Collisions::Solver* newSolver);
		// todo: remove solver

		void handleCollisions();
	};
}

#endif //OAKENGINE_PHYSICSSPACE_H
