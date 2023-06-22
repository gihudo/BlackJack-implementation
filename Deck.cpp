#include "Deck.h"

namespace BlackJack {
	/*
	Seed for random generation is based on deck creation time
	Note:	It is better to use a more secure method for random generation,
			but as it`s a test, I think it`s fine
	*/

	Deck::Deck()
		:m_IsEmpty(false), m_Seed(time(NULL))
	{
		m_Deck = { 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A,
					2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A,
					2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A,
					2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A
		};
	}

	Deck::Deck(const std::vector<int>& deck)
		:m_Deck(deck), m_IsEmpty(false), m_Seed(time(NULL)) {}

	void Deck::Shuffle()
	{
		srand(m_Seed);
		for (int i = 0; i < m_Deck.size(); i++) {
			std::swap(m_Deck[i], m_Deck[rand() % m_Deck.size()]);
		}
	}

	int Deck::GetCard()
	{
		if (m_IsEmpty)
			throw std::out_of_range("The deck is empty");

		int card = m_Deck[0];
		m_Deck.erase(m_Deck.begin());
		m_IsEmpty = m_Deck.size() == 0;

		return card;
	}

	bool Deck::IsEmpty() const { return m_IsEmpty; }
}