/**
 * Created by Filip Dabkowski on 28/01/2024.
 */

#ifndef OAKENGINE_BASECOLLIDER_H
#define OAKENGINE_BASECOLLIDER_H

#include "OakEngine/Math/Vec2.h"
#include "OakEngine/Physics/CollisionPoints.h"

#include "cfloat"


namespace oak {
	using namespace oak;

	namespace Physics {
		typedef struct Transform Transform;
	}

	namespace Collisions {
		using namespace Math;


		/// A structure to represent a range of projection in a 1D plane.
		/// It consists of two floats representing the minimum and maximum values of a projection range.
		struct Range {
			float min = FLT_MAX; ///< The minimum value.
			float max = FLT_MIN; ///< The maximum value.

			void update(float newVal) {
				if (newVal < min) {
					min = newVal;
				} else if (newVal > max) {
					max = newVal;
				}
			}

		};


		/// For representation of pre calculated projections onto X-axis and Y-axis
		struct Range2 {
			Range xAxis; ///< Range of values on X axis
			Range yAxis; ///< Range of values on Y axis

			void update(float newX, float newY) {
				xAxis.update(newX);
				yAxis.update(newY);
			}

			void update(Vec2 newVec) {
				update(newVec.x, newVec.y);
			}
		};


		/// Bounding box of of a shape with simplest representation of rectangle in 2D space
		struct Rect {
			float x, y; ///< Origin cords of rectangle corner
			float w, h; ///< width, height of rectangle to create representation in capacity

			static void updateRectAxis(float newVal, float& minValue, float& range) {
				if (newVal < minValue)
					minValue = newVal;
				else if (newVal > minValue + range)
					range = newVal - minValue;
			}

			void update(float newX, float newY) {
				// Potentially updateRectAxis X coordinate or box width
				updateRectAxis(newX, x, w);
				// Potentially updateRectAxis Y coordinate or box height
				updateRectAxis(newY, y, h);
			}
		};


		struct BaseCollider {
		public:
			enum Type {
				Line,
				Circle,
			};

			/* General Draw Functions */

			virtual void drawCollider(Physics::Transform* transform) = 0;

			/* General Collide Check */

			static Points detectCollision(BaseCollider* a, Physics::Transform* aTrans,
										  BaseCollider* b, Physics::Transform* bTrans);

			virtual Vec2 getFurthestPoint(Vec2 axis) = 0;

			/* Getters & Setters */

			virtual Vec2 getCentroid() = 0;

			virtual Range2 getRange() = 0;

			virtual Range getRangeX() = 0;

			virtual Range getRangeY() = 0;

			void setOrigin(float newX, float newY);

			[[nodiscard]]
			Vec2& getOrigin();

			[[nodiscard]]
			virtual Type getType() const = 0;

		protected:
			Vec2 origin{};
		};


		using Collider = BaseCollider;
	}
}

#endif //OAKENGINE_BASECOLLIDER_H
