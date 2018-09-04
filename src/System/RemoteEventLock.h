#pragma once

namespace System {
	class Dispatcher;
	class Event;

	class RemoteEventLock {
	public:
		RemoteEventLock(Dispatcher& dispatcher, Event& event);
		~RemoteEventLock();

	private:
		Dispatcher& dispatcher;
		Event& event;
	};
}
