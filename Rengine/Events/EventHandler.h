#pragma once

#include "Event.h"
#include <functional>
#include <iostream>

namespace Ren {

	class EventHandler
	{
	public:
		EventHandler(EventType event_type, std::function<void (std::unique_ptr<Event> const &e)> callback) {
			// TODO handle overflow or atleast error out if you do
			m_id = next_id++;
			m_event_type = event_type;
			m_callback = callback;
		}
		inline void handle(std::unique_ptr<Event> const &e) {
			if (e->type == m_event_type) {
				m_callback(e);
			}
		}
		inline uint64_t get_id() {
			return m_id;
		}
	private:
		static uint64_t next_id;
		uint64_t m_id;

		std::function<void (std::unique_ptr<Event> const &e)> m_callback;
		EventType m_event_type;
	};
}
