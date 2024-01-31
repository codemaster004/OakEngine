/**
 * Created by Filip Dabkowski on 31/01/2024.
 */

#ifndef OAKENGINE_DYNAMICOBJECT_H
#define OAKENGINE_DYNAMICOBJECT_H

#include "OakEngine/Physics/PhysicsObject.h"

namespace oak::Physics {

	/// Game movable game object
	struct DynamicObject : public PhysicsObject {
	protected:
		Vec2 t_force; ///< Physical Force or Acceleration vector
		Vec2 t_velocity; ///< Physical Speed vector
		float t_gravity; ///< Gravity value to be applied

		float t_mass; ///< Mass or Weights of the object
		bool t_processGravity; ///< Flag to determine whether to apply gravity

		float t_friction; ///< Friction coefficient applied when moving.
		float t_elasticity; ///< How elastic (bouncy) object is

	public:
		DynamicObject() : PhysicsObject() {
			t_isStatic = false;
			t_isDynamic = true;

			t_force = {};
			t_velocity = {};
			t_gravity = 0;

			t_mass = 1;
			t_processGravity = false;

			t_friction = 0;
			t_elasticity = 0;
		}

		DynamicObject(float x, float y) : PhysicsObject(x, y) {
			t_isStatic = false;
			t_isDynamic = true;

			t_force = {};
			t_velocity = {};
			t_gravity = 0;

			t_mass = 1;
			t_processGravity = false;

			t_friction = 0;
			t_elasticity = 0;
		}

		void applyGravity();

		void moveObject();

		/* Getters & Setters for protected values */

		void setVelocity(const Vec2& vel);

		[[nodiscard]]
		Vec2 velocity() const;

		void setForce(const Vec2& f);

		[[nodiscard]]
		Vec2 force() const;

		void setGravity(float g);

		[[nodiscard]]
		float gravity() const;

		void setMass(float m);

		[[nodiscard]]
		float mass() const;

		void setProcessGravity(bool v);

		[[nodiscard]]
		bool processGravity() const;
	};
}
#endif //OAKENGINE_DYNAMICOBJECT_H
