/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_POSITIONSOLVER_H
#define OAKENGINE_POSITIONSOLVER_H

#include "OakEngine/Physics/Solvers/Solver.h"

namespace oak::Collisions {
	class PositionSolver : public Solver {
	public:
		void solve(Vector<DetectedCollision> &collisions) override;
	};
}

#endif //OAKENGINE_POSITIONSOLVER_H
