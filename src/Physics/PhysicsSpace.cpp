/**
 * @file PhysicsSpace.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 28/01/2024
 */
#include "OakEngine/Logs/Logs.h"
#include "OakEngine/Physics/PhysicsSpace.h"


namespace oak::Physics {

	using Points = Collisions::CollisionPoints;
	using Collider = Collisions::BaseCollider;

	void PhysicsSpace::addObject(BaseObject* newObject) {
		if (newObject == nullptr) {
			OAK_LOG_WARN("PhysicsSpace an attempt to add Non Existing Object");
			return;
		}

		if (newObject->collider == nullptr) {
			OAK_LOG_WARN("PhysicsSpace an attempt to add Non Collectable Object");
		}

		objects.pushBack(newObject);
	}

	void PhysicsSpace::addSolver(Collisions::Solver* newSolver) {
		if (newSolver == nullptr) {
			OAK_LOG_WARN("PhysicsSpace an attempt to add Non Existing Solver");
			return;
		}

		solvers.pushBack(newSolver);
	}

	void PhysicsSpace::spaceStep() {
		for (BaseObject* object: objects) {
			object->velocity += object->force;
			object->transform->position += object->velocity;
		}
	}

	void PhysicsSpace::handleCollisions() {
		for (BaseObject* objA: objects) {
			for (BaseObject* objB: objects) {
				if (objA == objB)
					break; // Break for considering only uniq pairs

				Points points = Collider::detectCollision(objA->collider, objA->transform,
														  objB->collider, objB->transform);
				collisions.emplaceBack(objA, objB, points); // Create Collision object
			}
		}

		for (Collisions::Solver* solver: solvers) {
			solver->solve(collisions);
		}

		collisions.clear();
	}
}