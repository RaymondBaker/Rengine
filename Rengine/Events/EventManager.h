#pragma once
#include <iostream>

namespace Ren {
	class EventManager
	{
	public:
		void deleteme() { std::cout << "called function: " << m_test << std::endl; }
	private:
		int m_test = 2;
	protected:
	};
}

