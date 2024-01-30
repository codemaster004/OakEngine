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

	void PhysicsSpace::addObject(CollisionObject* newObject) {
		if (newObject == nullptr) {
			OAK_LOG_WARN("PhysicsSpace an attempt to add Non Existing Object");
			return;
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
		for (CollisionObject* object: objects) {

			object->velocity += object->force;
			object->transform->position += object->velocity;
		}
	}

	void PhysicsSpace::handleCollisions() {
		for (CollisionObject* objA: objects) {
			for (CollisionObject* objB: objects) {
				if (objA == objB)
					break; // Break for considering only uniq pairs

				if (objA->collider == nullptr || objB->collider == nullptr)
					continue; // make sure both have colliders

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