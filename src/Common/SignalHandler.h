#pragma once

#include <functional>

namespace Tools {
	class SignalHandler
	{
	public:
		static bool install(std::function<void(void)> t);
	};
}
