#pragma once

#include "ILogger.h"
#include "LoggerMessage.h"

namespace Logging {
	class LoggerRef {
	public:
		LoggerRef(ILogger& logger, const std::string& category);
		LoggerMessage operator()(Level level = INFO, const std::string& color = DEFAULT) const;
		ILogger& getLogger() const;

	private:
		ILogger* logger;
		std::string category;
	};
}
