#include "LoggerRef.h"

namespace Logging {
	LoggerRef::LoggerRef(ILogger& logger, const std::string& category) : logger(&logger), category(category) {
	}

	LoggerMessage LoggerRef::operator()(Level level, const std::string& color) const {
		return LoggerMessage(*logger, category, level, color);
	}

	ILogger& LoggerRef::getLogger() const {
		return *logger;
	}
}