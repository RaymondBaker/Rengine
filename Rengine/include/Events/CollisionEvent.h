#pragma once

#include "Event.h"
#include <iostream>


namespace Ren {
	class CollisionEvent : public Event
	{
	public:
		CollisionEvent(const uint64_t obj1_id, const uint64_t obj2_id) 
			: Event (EventType::Collision), obj1_id (obj1_id), obj2_id (obj2_id) {
		}
		std::string to_string() const override {
			return "CollisionEvent";
		}
		const uint64_t obj1_id, obj2_id;
	};
}
