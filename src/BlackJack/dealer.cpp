#include "Dealer.h"

namespace BlackJack {
    void Dealer::Hit(Deck& deck) { m_Hand.push_back(deck.GetCard()); }

    void Dealer::Stand() {}

    void Dealer::setUsers(std::shared_ptr<std::vector<User>> users) { m_Users = users; }

    void Dealer::Distribute(Deck& deck)
    {
        Hit(deck);
        Hit(deck);

        for (auto user : *m_Users.get()) {
            user.Hit(deck);
            user.Hit(deck);
        }
    }
}
