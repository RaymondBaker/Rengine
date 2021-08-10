#pragma once
#include "../Events/EventManager.h"
#include "../Events/EventHandler.h"

namespace Ren {
	class Node
	{
	public:
		Node(EventManager &event_Manager) {
			// TODO handle overflow or atleast error out if you do
			m_id = next_id++;
			m_event_handler_id = event_Manager.add_handler(EventHandler(EventType::Collision,
				[this](Event& e) {
					//auto event_ = static_cast<T>(e)
					this->test(e);
				}));
		}

		~Node() {
			// Remove eventhandler from event_manager
		}

		void test(Event& e) {
			std::cout << "it worked " << m_id << " " << m_event_handler_id << std::endl;
		}
		
		uint64_t get_id() {
			return m_id;
		}

	private:
		static uint64_t next_id;
		uint64_t m_id = 0;
		uint64_t m_event_handler_id;
	};
}
