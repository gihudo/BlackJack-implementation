#pragma once
#include "Deck.h"
#include <string>

namespace BlackJack {
	class Player
	{
	protected:
		std::vector<int> m_Hand;
	public:
		virtual void Hit(Deck& deck) = 0;
		virtual void Stand() = 0;

		inline unsigned int CheckHand() const { return std::accumulate(m_Hand.begin(), m_Hand.end(), 0); }
	};
}