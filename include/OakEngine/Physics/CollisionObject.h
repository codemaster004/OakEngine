/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_COLLISIONOBJECT_H
#define OAKENGINE_COLLISIONOBJECT_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/Colliders/BaseCollider.h"
#include "OakEngine/Common/Components/Transform.h"
#include "OakEngine/Physics/DetectedCollision.h"


namespace oak::Physics {

	using CollisionFunction = void (*)(Collisions::DetectedCollision);


	/// Base Game Object
	struct CollisionObject {
	protected:
		Transform* _transform = nullptr;
		Collisions::BaseCollider* _collider = nullptr;

		CollisionFunction _onCollision = nullptr;

		bool _isStatic = false;
		bool _isDynamic = false;
		bool _isTrigger = false;

	public:

		CollisionObject() {
			setStatic(true);
			_transform = new Transform;
		}

		CollisionObject(float x, float y) {
			setStatic(true);
			_transform = new Transform{x, y, 1, 1};
		}

		/* Getters & Setters for protected values */

		void setTransform(Transform* transform);

		Transform* getTransform();

		void setCollider(Collisions::BaseCollider* collider);

		Collisions::BaseCollider* getCollider();

		void setOnCollision(CollisionFunction function);

		CollisionFunction getOnCollision();

		void setStatic(bool value);

		[[nodiscard]]
		bool isStatic() const;

		void setDynamic(bool value);

		[[nodiscard]]
		bool isDynamic() const;

		void setTrigger(bool value);

		[[nodiscard]]
		bool isTrigger() const;
	};


	/// Game movable game object
	struct DynamicObject : public CollisionObject {
	protected:
		Vec2 _force;
		Vec2 _velocity;

		float _mass;
		bool _applyGravity;

		float _friction;
		float _elasticity;

	public:
		DynamicObject(float x, float y) {
			setStatic(false);
			setDynamic(true);
			this->_transform = new Transform{x, y, 1, 1};
		}

		/* Getters & Setters for protected values */

		void setVelocity(const Vec2& vel);

		[[nodiscard]]
		Vec2 getVelocity() const;

		void setForce(const Vec2& f);

		[[nodiscard]]
		Vec2 getForce() const;

		void setMass(float m);

		[[nodiscard]]
		float getMass() const;
	};

}

#endif //OAKENGINE_COLLISIONOBJECT_H
