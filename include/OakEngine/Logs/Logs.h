/**
 * Created by Filip Dabkowski on 30/01/2024.
 */

#ifndef OAKENGINE_LOGS_H
#define OAKENGINE_LOGS_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace oak {
	class Logs {
	private:
		static std::shared_ptr<spdlog::logger> s_AppLogger;
		static std::shared_ptr<spdlog::logger> s_OakLogger;

	public:
		// Initialize the logging system with specified log levels for production and development
		static void init(spdlog::level::level_enum level = spdlog::level::trace);

		// Get a reference to the production logger instance
		inline static std::shared_ptr<spdlog::logger>& getAppLogger() {
			return s_AppLogger;
		}

		// Get a reference to the development logger instance
		inline static std::shared_ptr<spdlog::logger>& getOakLogger() {
			return s_OakLogger;
		}
	};
}


// Developer Loggers
#define OAK_LOG_TRACE(...) oak::Logs::getOakLogger()->trace(__VA_ARGS__)
#define OAK_LOG_INFO(...) oak::Logs::getOakLogger()->info(__VA_ARGS__)
#define OAK_LOG_WARN(...) oak::Logs::getOakLogger()->warn(__VA_ARGS__)
#define OAK_LOG_ERROR(...) oak::Logs::getOakLogger()->error(__VA_ARGS__)

// Public app Loggers
#define LOG_TRACE(...) oak::Logs::getAppLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...) oak::Logs::getAppLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) oak::Logs::getAppLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) oak::Logs::getAppLogger()->error(__VA_ARGS__)

#endif //OAKENGINE_LOGS_H
