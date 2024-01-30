/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_TRANSFORM_H
#define OAKENGINE_TRANSFORM_H

#include "OakEngine/Math/Vec2.h"


namespace oak {

	/// Describes an object location
	struct Transform {
		Math::Vec2 position;
		Math::Vec2 scale;
	};
}

#endif //OAKENGINE_TRANSFORM_H
