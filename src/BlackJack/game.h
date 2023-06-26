#ifndef GAME_H
#define GAME_H

#include "Dealer.h"
#include "Deck.h"
#include "User.h"

namespace BlackJack{
    class Game
    {
    public:
        Game(std::string DeckTexture);
        Game(const std::vector<User>& users, std::string DeckTexture);

        void Start();

        inline void AddUser(const User& user) { m_Dealer->AddUser(user); }
        inline void AddUsers(const std::vector<User>& users) { m_Dealer->AddUsers(users); }

        inline Deck* GetDeck() const { return m_Deck.get(); }
        inline Dealer* GetDealer() const { return m_Dealer.get(); }

    private:
        std::unique_ptr<Deck> m_Deck;
        std::unique_ptr<Dealer> m_Dealer;
    };
}

#endif // GAME_H
