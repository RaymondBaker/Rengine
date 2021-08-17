#pragma once
#include <cstdint>

namespace Ren {
	class EntityManager {
	public:
		EntityManager() {

		}

		uint64_t add_entity () {
			return next_entity_id++;
		}


	private:
		static uint64_t next_entity_id;

	};
}
