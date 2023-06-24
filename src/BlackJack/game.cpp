#include "Game.h"

namespace BlackJack {
    Game::Game(std::string texture)
        :m_Dealer(std::make_unique<Dealer>()),
        m_Deck(std::make_unique<Deck>(texture)),
        m_Users(nullptr)
    {}

    Game::Game(std::shared_ptr<std::vector<User>> users, std::string texture)
        :Game(texture)
    {
        m_Dealer->setUsers(users);
    }

    void Game::Start()
    {
        if (m_Users == nullptr)
            return;

        m_Deck->Shuffle();
        m_Dealer->setUsers(m_Users);
        m_Dealer->Distribute(*m_Deck);
    }
}
