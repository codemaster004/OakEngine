/**
 * @file CollisionObject.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 30/01/2024
 */
#include "OakEngine/Physics/CollisionObject.h"


namespace oak::Physics {

	void CollisionObject::setTransform(Transform* transform) {
		delete _transform;
		this->_transform = transform;
	}

	Transform* CollisionObject::getTransform() {
		return this->_transform;
	}

	void CollisionObject::setCollider(Collisions::BaseCollider* collider) {
		delete _collider;
		this->_collider = collider;
	}

	Collisions::BaseCollider* CollisionObject::getCollider() {
		return this->_collider;
	}

	void CollisionObject::setOnCollision(CollisionFunction function) {
		this->_onCollision = function;
	}

	CollisionFunction CollisionObject::getOnCollision() {
		return this->_onCollision;
	}

	void CollisionObject::setStatic(bool value) {
		this->_isStatic = value;
	}

	bool CollisionObject::isStatic() const {
		return this->_isStatic;
	}

	void CollisionObject::setDynamic(bool value) {
		this->_isDynamic = value;
	}

	bool CollisionObject::isDynamic() const {
		return this->_isDynamic;
	}

	void CollisionObject::setTrigger(bool value) {
		this->_isTrigger = value;
	}

	bool CollisionObject::isTrigger() const {
		return this->_isTrigger;
	}

	/* Dynamic Object */

	void DynamicObject::setVelocity(const Vec2& vel) {
		_velocity = vel;
	}

	Vec2 DynamicObject::getVelocity() const {
		return _velocity;
	}

	void DynamicObject::setForce(const Vec2& f) {
		_force = f;
	}

	Vec2 DynamicObject::getForce() const {
		return _force;
	}

	void DynamicObject::setMass(float m) {
		_mass = m;
	}

	float DynamicObject::getMass() const {
		return _mass;
	}
}