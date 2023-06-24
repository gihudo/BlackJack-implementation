#ifndef GAME_H
#define GAME_H

#include "Dealer.h"
#include "Deck.h"
#include "User.h"

namespace BlackJack{
    class Game
    {
    public:
        Game(std::string texture);
        Game(std::shared_ptr<std::vector<User>> users, std::string texture);

        void Start();

        inline void AddUser(User& user) { m_Users->push_back(std::move(user)); }

        inline Deck* GetDeck() const { return m_Deck.get(); }
        inline Dealer* GetDealer() const { return m_Dealer.get(); }
    private:
        std::unique_ptr<Deck> m_Deck;
        std::unique_ptr<Dealer> m_Dealer;
        std::shared_ptr<std::vector<User>> m_Users;
    };
}

#endif // GAME_H
