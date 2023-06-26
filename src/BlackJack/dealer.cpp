#include "Dealer.h"

namespace BlackJack {
    void Dealer::Hit(Deck& deck) { m_Hand.push_back(deck.GetCard()); }

    void Dealer::Stand() {}

    void Dealer::AddUsers(const std::vector<User>& users) { m_Users.insert(m_Users.begin(), users.begin(), users.end()); }

    void Dealer::AddUser(const User& user) { m_Users.push_back(user); }

    void Dealer::Distribute(Deck& deck)
    {
        Hit(deck);
        Hit(deck);

        for (auto user : m_Users) {
            user.Hit(deck);
            user.Hit(deck);
        }
    }
}
