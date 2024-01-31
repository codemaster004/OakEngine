/**
 * @file PhysicsObject.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 30/01/2024
 */
#include "OakEngine/Physics/PhysicsObject.h"


namespace oak::Physics {

	void PhysicsObject::setTransform(Transform* t) {
		delete t_transform;
		t_transform = t;
	}

	Transform* PhysicsObject::transform() {
		return t_transform;
	}

	void PhysicsObject::setCollider(Collisions::BaseCollider* collider) {
		delete t_collider;
		t_collider = collider;
	}

	Collisions::BaseCollider* PhysicsObject::collider() {
		return t_collider;
	}

	void PhysicsObject::setOnCollision(CollisionFunction func) {
		t_onCollision = func;
	}

	CollisionFunction PhysicsObject::onCollision() {
		return t_onCollision;
	}

	/* Flags */

	void PhysicsObject::setStatic(bool v) {
		t_isStatic = v;
	}

	bool PhysicsObject::isStatic() const {
		return t_isStatic;
	}

	void PhysicsObject::setDynamic(bool v) {
		t_isDynamic = v;
	}

	bool PhysicsObject::isDynamic() const {
		return t_isDynamic;
	}

	void PhysicsObject::setTrigger(bool v) {
		t_isTrigger = v;
	}

	bool PhysicsObject::isTrigger() const {
		return t_isTrigger;
	}
}