/**
 * @file PhysicsSpace.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 28/01/2024
 */
#include "OakEngine/Physics/PhysicsSpace.h"


using namespace oak::Physics;

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

			Collider::detectCollision(objA->collider, objA->transform, objB->collider, objB->transform);
		}
	}
}