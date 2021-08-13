#pragma once
#include <iostream>
#include <queue>
#include <list>
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
		std::list<EventHandler>::iterator add_handler(EventHandler &handler) {
			m_event_handlers.push_back(handler);
			return --m_event_handlers.end();
		}
		std::list<EventHandler>::iterator add_handler(EventHandler&& handler) {
			return add_handler(handler);
		}
		void delete_handler(std::list<EventHandler>::iterator &handler_it) {
			m_event_handlers.erase(handler_it);
		}
	private:
		ScriptEngine *m_script_eng;
		std::queue<std::unique_ptr<Event>> m_event_queue;
		//TODO use double linked list and have node keep a reference to the actual location for deletion
		std::list<EventHandler> m_event_handlers;
	protected:
	};
}

