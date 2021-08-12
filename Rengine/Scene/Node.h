#pragma once
#include "../Events/EventManager.h"
#include "../Events/EventHandler.h"
#include "../Events/CollisionEvent.h"
#include "../Events/KeyDownEvent.h"

namespace Ren {
	class Node
	{
	public:
		Node(EventManager &event_Manager) {
			// TODO handle overflow or atleast error out if you do
			m_id = next_id++;
			m_event_handler_id = event_Manager.add_handler(EventHandler(EventType::Collision,
				[this](std::unique_ptr<Event> const &e) {
					// Covarient functions wont work here because it is stored in a Event
					// doesn't fail if it's the wrong type Make sure code is good
					auto event_ = static_cast<CollisionEvent*>(e.get());
					this->test(event_);
				}));
			m_event_handler_id = event_Manager.add_handler(EventHandler(EventType::KeyDown,
				[this](std::unique_ptr<Event> const &e) {
					// Covarient functions wont work here because it is stored in a Event
					// doesn't fail if it's the wrong type Make sure code is good
					auto event_ = static_cast<KeyDownEvent*>(e.get());
					this->handle_keydown(event_);
				}));
		}

		~Node() {
			// Remove eventhandler from event_manager
		}

		void handle_keydown(KeyDownEvent* e) {
			std::cout << "Got: " << e->to_string() << std::endl;
			std::cout << e->key_code << std::endl;
		}

		void test(CollisionEvent *e) {
			std::cout << "Got: " << e->to_string() << std::endl;
		}
		
		uint64_t get_id() {
			return m_id;
		}

	private:
		static uint64_t next_id;
		uint64_t m_id = 0;
		// make this a vector so you can store more event handlers
		uint64_t m_event_handler_id;
	};
}
