#pragma once
#include <iostream>
#include <queue>
#include "Event.h"
#include "../Scripting/ScriptEngine.h"
#include "EventHandler.h"

namespace Ren {
	class EventManager
	{
	public:
		EventManager(ScriptEngine* script_eng) {
			m_script_eng = script_eng;
		}

		// Returns true when quit event is found
		bool push_sdl_events();

		void push_event(std::unique_ptr<Event> e) {
			m_event_queue.push(std::move(e));
		}

		void handle_events() {
			while (!m_event_queue.empty()) {
				auto &e = m_event_queue.front();

				for (auto& handler : m_event_handlers)
					handler.handle(e);

				m_event_queue.pop();
			}
		}


		//TODO find way to consolidate these
		uint64_t add_handler(EventHandler &handler) {
			m_event_handlers.push_back(handler);
			return handler.get_id();
		}
		uint64_t add_handler(EventHandler&& handler) {
			return add_handler(handler);
		}
	private:
		ScriptEngine *m_script_eng;
		std::queue<std::unique_ptr<Event>> m_event_queue;
		std::vector<EventHandler> m_event_handlers;
	protected:
	};
}

