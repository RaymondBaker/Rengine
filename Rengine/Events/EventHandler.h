#pragma once

#include "Event.h"
#include <functional>
#include <iostream>

namespace Ren {

	class EventHandler
	{
	public:
		EventHandler(EventType event_type, std::function<void (Event &e)> callback) {
			// TODO handle overflow or atleast error out if you do
			m_id = next_id++;
			m_event_type = event_type;
			m_callback = callback;
		}
		inline void handle(Event& e) {
			if (e.type == m_event_type) {
				//TODO: use dynamic_cast on debug and static_cast on release
				//;
				m_callback(e);
			}
		}
		inline uint64_t get_id() {
			return m_id;
		}
	private:
		static uint64_t next_id;
		uint64_t m_id;

		std::function<void (Event &e)> m_callback;
		EventType m_event_type;
	};
}
