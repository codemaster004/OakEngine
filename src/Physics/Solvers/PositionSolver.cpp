/**
 * @file PositionSolver.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 30/01/2024
 */
#include "OakEngine/Physics/Solvers/PositionSolver.h"


namespace oak::Collisions {
	void PositionSolver::solve(Vector<DetectedCollision>& collisions) {
		for (DetectedCollision collision : collisions) {
			if (!collision.hasCollision)
				continue;

			Vec2 mTranslateVec = collision.normal * collision.depth;
			mTranslateVec /= 1;

			collision.A->transform->position -= mTranslateVec;
			collision.B->transform->position += mTranslateVec;
		}
	}
}