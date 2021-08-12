#pragma once

#include "Event.h"
#include <iostream>


namespace Ren {
	class CollisionEvent : public Event
	{
	public:
		CollisionEvent() : Event (EventType::Collision) {
			i = 6969;
			g = 0;
		}
		std::string to_string() const override {
			return "CollisionEvent";
		}
		int i;
		int g;
	};
}
