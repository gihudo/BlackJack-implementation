#pragma once
#include "Dealer.h"
#include "Deck.h"
#include "User.h"

namespace BlackJack{
	class Game
	{
	private:
		std::unique_ptr<Deck> m_Deck;
		std::unique_ptr<Dealer> m_Dealer;
		std::shared_ptr<std::vector<User>> m_Users;
	public:
		Game();
		Game(std::shared_ptr<std::vector<User>> users);

		void Start();

		inline void AddUser(const User& user) { m_Users->push_back(user); }

		inline Deck* GetDeck() const { return m_Deck.get(); }
		inline Dealer* GetDealer() const { return m_Dealer.get(); }
	};
}