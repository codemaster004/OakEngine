/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_OAK_H
#define OAKENGINE_OAK_H

// Designed only for use of client applications

// ENTRY POINT
#include "OakEngine/EntryPoint.h"

// Core
#include "OakEngine/Core.h"

// Main Engine Class
#include "OakEngine/Engine.h"

// Math
#include "OakEngine/Math/Vec2.h"

// Common
#include "OakEngine/Common/Templates.h"
#include "OakEngine/Common/Components/Transform.h"

// Events
#include "OakEngine/Events/Event.h"
#include "OakEngine/Events/KeyboardEvents.h"
#include "OakEngine/Events/AppEvents.h"

// PHYSICS
#include "OakEngine/Physics/PhysicsObject.h"
#include "OakEngine/Physics/CollisionPoints.h"
#include "OakEngine/Physics/CollisionTests.h"
#include "OakEngine/Physics/DetectedCollision.h"
#include "OakEngine/Physics/PhysicsSpace.h"

// Physics/Dynamic
#include "OakEngine/Physics/Dynamic/DynamicObject.h"
#include "OakEngine/Physics/Dynamic/DynamicSpace.h"

// Physics/Colliders
#include "OakEngine/Physics/Colliders/BaseCollider.h"
#include "OakEngine/Physics/Colliders/CircleCollider.h"

// Physics/Solvers
#include "OakEngine/Physics/Solvers/Solver.h"
#include "OakEngine/Physics/Solvers/PositionSolver.h"

#endif //OAKENGINE_OAK_H
