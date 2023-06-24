#ifndef DEALER_H
#define DEALER_H

#include "Player.h"
#include "User.h"

namespace BlackJack {
    class Dealer : public Player
    {
    public:
        void Hit(Deck& deck) override;
        void Stand() override;

        void setUsers(std::shared_ptr<std::vector<User>> users);
        void Distribute(Deck& deck);
    private:
        std::shared_ptr<std::vector<User>> m_Users;
    };
}
#endif // DEALER_H
