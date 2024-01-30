/**
 * @file Logs.cpp
 * @brief [Description of file]
 * 
 * @author Filip Dabkowski
 * @date 30/01/2024
 */
#include "OakEngine/Logs/Logs.h"


namespace oak {

	std::shared_ptr<spdlog::logger> Logs::s_OakLogger; // Dev logger
	std::shared_ptr<spdlog::logger> Logs::s_AppLogger; // Public logger

	void Logs::init(spdlog::level::level_enum level) {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_OakLogger = spdlog::stdout_color_mt("OAK");
		s_OakLogger->set_level(level);

		s_AppLogger = spdlog::stdout_color_mt("APP");
		s_AppLogger->set_level(level);
	}
}
