/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_SOLVER_H
#define OAKENGINE_SOLVER_H

#include "DataStructs/Vector.h"

#include "OakEngine/Physics/DetectedCollision.h"

namespace oak::Collisions {
	class Solver {
	public:
		virtual void solve(Vector<DetectedCollision>& collisions) = 0;
	};
}

#endif //OAKENGINE_SOLVER_H
