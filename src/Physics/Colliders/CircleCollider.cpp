/**
 * @file CircleCollider.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 29/01/2024
 */
#include "OakEngine/Physics/Colliders/CircleCollider.h"


namespace oak::Collisions {

	void CircleCollider::drawCollider(Transform* transform) {
		Vec2 worldPos = origin + transform->position;
//		ColliderDrawing::drawCircle(oak::Engine::renderer, {(int) worldPos.x, (int) worldPos.y, radius});
	}


	Vec2 CircleCollider::getFurthestPoint(Vec2 axis) {
		return this->origin + axis * radius;
	}


	Vec2 CircleCollider::getCentroid() {
		return origin;
	}


	Range2 CircleCollider::getRange() {
		return Range2{};
	}


	Range CircleCollider::getRangeX() {
		return Range{origin.x - radius, origin.x + radius};
	}

	Range CircleCollider::getRangeY() {
		return Range{origin.y - radius, origin.y + radius};
	}
}