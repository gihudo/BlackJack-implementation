#pragma once
#include <vector>
#include <numeric>
#include <time.h>
#include <memory>
#include <stdexcept>

#define A 1
#define J 10
#define Q 10
#define K 10

namespace BlackJack {
	class Deck
	{
	private:
		std::vector<int> m_Deck;
		bool m_IsEmpty;
		int m_Seed;
	public:
		Deck();
		Deck(const std::vector<int>& deck);

		void Shuffle();
		int GetCard();
		bool IsEmpty() const;
	};
}