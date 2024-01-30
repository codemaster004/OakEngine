/**
 * Created by Filip Dabkowski on 29/01/2024.
 */

#ifndef OAKENGINE_CIRCLECOLLIDER_H
#define OAKENGINE_CIRCLECOLLIDER_H

#include "OakEngine/Physics/Colliders/BaseCollider.h"


namespace oak::Collisions {

	struct CircleCollider : public BaseCollider {
	private:
		float radius;

	public:

		explicit CircleCollider(float radius) : radius(radius) {}

		Vec2 getFurthestPoint(Vec2 axis) override;

		void drawCollider(Transform* transform) override;

		/* Getters */

		[[nodiscard]]
		float getR() const {
			return radius;
		}

		/* Default Getters */

		Vec2 getCentroid() override;

		Range2 getRange() override;

		Range getRangeX() override;

		Range getRangeY() override;

		[[nodiscard]]
		Type getType() const override {
			return BaseCollider::Circle;
		}
	};
}

#endif //OAKENGINE_CIRCLECOLLIDER_H
