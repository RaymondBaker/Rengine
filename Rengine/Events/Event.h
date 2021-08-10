#pragma once



namespace Ren {

	enum class EventType {
		Collision,
		UserInput,
		GameQuit
	};



	class Event
	{
	public:
		Event(EventType _type) {
			type = _type;
		}
		EventType type;
	private:

	};
}
