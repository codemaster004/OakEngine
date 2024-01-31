/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_PHYSICSOBJECT_H
#define OAKENGINE_PHYSICSOBJECT_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/Colliders/BaseCollider.h"
#include "OakEngine/Common/Components/Transform.h"


namespace oak {
	namespace Collisions {
		struct DetectedCollision;
	}

	namespace Physics {

		using CollisionFunction = void (*)(Collisions::DetectedCollision);


		/// Base Game Object
		struct PhysicsObject {
		protected:
			Transform* t_transform; ///< Describes Objects position in the world
			Collisions::BaseCollider* t_collider; ///< Collider of the Object

			CollisionFunction t_onCollision; ///< Callback function that will be called if is a trigger

			bool t_isStatic; ///< This object only exists and does not move
			bool t_isDynamic; ///< This object can move, interact with gravity, additional properties.
			bool t_isTrigger; ///< If colliding with this object an onCollision event will be triggered

		public:

			PhysicsObject() {
				t_transform = new Transform;
				t_collider = nullptr;
				t_onCollision = nullptr;

				t_isStatic = true;
				t_isDynamic = false;
				t_isTrigger = false;
			}

			PhysicsObject(float x, float y) {
				t_transform = new Transform{x, y, 1, 1};

				t_isStatic = true;
				t_isDynamic = false;
				t_isTrigger = false;

				t_collider = nullptr;
				t_onCollision = nullptr;
			}

			/* Getters & Setters for protected values */

			void setTransform(Transform* t);

			Transform* transform();

			void setCollider(Collisions::BaseCollider* collider);

			Collisions::BaseCollider* collider();

			void setOnCollision(CollisionFunction func);

			CollisionFunction onCollision();

			void setStatic(bool v);

			[[nodiscard]]
			bool isStatic() const;

			void setDynamic(bool v);

			[[nodiscard]]
			bool isDynamic() const;

			void setTrigger(bool v);

			[[nodiscard]]
			bool isTrigger() const;
		};

	}
}
#endif //OAKENGINE_PHYSICSOBJECT_H
