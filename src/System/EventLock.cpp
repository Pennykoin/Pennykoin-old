#include "EventLock.h"
#include <System/Event.h>

namespace System {
	EventLock::EventLock(Event& event) : event(event) {
		while (!event.get()) {
			event.wait();
		}

		event.clear();
	}

	EventLock::~EventLock() {
		event.set();
	}
}