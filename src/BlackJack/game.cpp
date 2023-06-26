#include "Game.h"

namespace BlackJack {
    Game::Game(std::string DeckTexture)
        :m_Dealer(std::make_unique<Dealer>()),
        m_Deck(std::make_unique<Deck>(DeckTexture))
    {}

    Game::Game(const std::vector<User>& users, std::string DeckTexture)
        :Game(DeckTexture)
    {
        m_Dealer->AddUsers(users);
    }

    void Game::Start()
    {
        if (m_Dealer->GetUsers().empty())
            return;

        m_Deck->Shuffle();
        m_Dealer->Distribute(*m_Deck);
    }
}
