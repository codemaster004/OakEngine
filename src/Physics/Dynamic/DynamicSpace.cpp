/**
 * @file DynamicSpace.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 31/01/2024
 */
#include "OakEngine/Physics/Dynamic/DynamicSpace.h"
#include "OakEngine/Physics/Dynamic/DynamicObject.h"

namespace oak::Physics {
	void DynamicSpace::addDynamicObject(DynamicObject* newObject) {
		if (newObject->processGravity())
			newObject->setGravity(t_gravity);

		addObject(newObject);
	}

	void DynamicSpace::applyGravity() {
		for (PhysicsObject* obj: objects) {
			if (!obj->isDynamic())
				continue;

			auto dynamicObj = (DynamicObject*) obj;
			dynamicObj->applyGravity();
		}
	}

	void DynamicSpace::moveObjects() {
		for (PhysicsObject* obj: objects) {
			if (!obj->isDynamic())
				continue;

			auto dynamicObj = (DynamicObject*) obj;
			dynamicObj->moveObject();
		}
	}

	void DynamicSpace::step() {
		applyGravity();
		handleCollisions();
		moveObjects();
	}
}