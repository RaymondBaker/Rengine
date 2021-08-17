#pragma once

#include <string>


namespace Ren {

	//Or have smth like int event, vec2 event, string event and just a custom number to map to different instances
	enum class EventType {
		Collision,
		UserInput,
		GameQuit,
		KeyEvent
	};

	class Event
	{
	public:
		Event(EventType _type) : type (_type) {
		}
		virtual ~Event() {}
		virtual std::string to_string() const = 0;
		const EventType type;
	private:

	};
}
