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

        void AddUsers(const std::vector<User>& users);
        void AddUser(const User& user);
        void Distribute(Deck& deck);

        inline std::vector<User> GetUsers() const { return m_Users; }
    private:
        std::vector<User> m_Users;
    };
}
#endif // DEALER_H
