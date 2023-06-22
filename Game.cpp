#include "Game.h"

namespace BlackJack {
	Game::Game()
		:m_Dealer(std::make_unique<Dealer>()),
		m_Deck(std::make_unique<Deck>()),
		m_Users(std::make_shared<std::vector<User>>())
	{}

	Game::Game(std::shared_ptr<std::vector<User>> users)
		:Game()
	{
		m_Dealer->setUsers(std::move(users));
	}

	void Game::Start()
	{
		if (m_Users == nullptr)
			throw std::exception("There is no users to start a game");

		m_Deck->Shuffle();
		m_Dealer->setUsers(m_Users);
		m_Dealer->Distribute(*m_Deck);
	}
}