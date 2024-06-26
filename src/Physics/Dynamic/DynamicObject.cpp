/**
 * @file DynamicObject.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 31/01/2024
 */
#include "OakEngine/Physics/Dynamic/DynamicObject.h"

namespace oak::Physics {
	void DynamicObject::applyGravity() {
		t_velocity.y += t_gravity * t_mass;
	}

	void DynamicObject::moveObject() {
		t_transform->position += t_velocity;
	}

	/* Getters & Setters */

	void DynamicObject::setVelocity(const Vec2& vel) {
		t_velocity = vel;
	}

	Vec2 DynamicObject::velocity() const {
		return t_velocity;
	}

	void DynamicObject::setForce(const Vec2& f) {
		t_force = f;
	}

	Vec2 DynamicObject::force() const {
		return t_force;
	}

	void DynamicObject::setMass(float m) {
		t_mass = m;
	}

	float DynamicObject::mass() const {
		return t_mass;
	}

	void DynamicObject::setProcessGravity(bool v) {
		t_processGravity = v;
	}

	bool DynamicObject::processGravity() const {
		return t_processGravity;
	}

	void DynamicObject::setGravity(float g) {
		t_gravity = g;
	}

	float DynamicObject::gravity() const {
		return t_gravity;
	}
}