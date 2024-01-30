/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_ENTRYPOINT_H
#define OAKENGINE_ENTRYPOINT_H

#include "OakEngine/Engine.h"
#include "OakEngine/Logs/Logs.h"

namespace oak {
	extern Engine* createApplication();
}

int main(int argc, char** argv) {
	oak::Logs().init();

	auto app = oak::createApplication();

	LOG_INFO("HELLo there");

	app->run();

	delete app;
}

#endif //OAKENGINE_ENTRYPOINT_H
