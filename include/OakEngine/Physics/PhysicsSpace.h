/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_PHYSICSSPACE_H
#define OAKENGINE_PHYSICSSPACE_H

#include "DataStructs/Vector.h"

#include "OakEngine/Physics/CollisionObject.h"
#include "OakEngine/Physics/DetectedCollision.h"
#include "OakEngine/Physics/Solvers/Solver.h"


namespace oak::Physics {
	using Collision = Collisions::DetectedCollision;

	class PhysicsSpace {
	private:
		Vector<CollisionObject*> objects;
		Vector<Collision> collisions;

		Vector<Collisions::Solver*> solvers;

	public:
		void addObject(CollisionObject* newObject);
		// todo: remove object

		void addSolver(Collisions::Solver* newSolver);
		// todo: remove solver

		void spaceStep();

		void handleCollisions();
	};
}

#endif //OAKENGINE_PHYSICSSPACE_H
