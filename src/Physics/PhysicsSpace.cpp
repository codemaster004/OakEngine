/**
 * @file PhysicsSpace.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 28/01/2024
 */
#include "OakEngine/Physics/PhysicsSpace.h"


namespace oak::Physics {

	using Points = Collisions::CollisionPoints;
	using Collider = Collisions::BaseCollider;

	void PhysicsSpace::addObject(Object* newObject) {
		if (newObject == nullptr)
			return;

		objects.pushBack(newObject);
	}

	void PhysicsSpace::spaceStep() {
		for (Object* object: objects) {
			object->velocity += object->force;
			object->transform->position += object->velocity;
		}
	}

	void PhysicsSpace::handleCollisions() {
		for (Object* objA: objects) {
			for (Object* objB: objects) {
				if (objA == objB)
					break; // Break for considering only uniq pairs

				Points points = Collider::detectCollision(objA->collider, objA->transform,
														  objB->collider, objB->transform);
				collisions.emplaceBack(objA, objB, points); // Create Collision object
			}
		}

		collisions.clear();
	}
}