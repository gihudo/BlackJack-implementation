#include "User.h"

namespace BlackJack {
    User::User(const std::string& nickname, unsigned int balance)
        : m_Nickname(nickname), m_Balance(balance) {}

    void User::Hit(Deck& deck) { m_Hand.push_back(deck.GetCard()); }

    void User::Stand() { SetState(NotPlaying); }

    void User::SetState(const State& state) { m_State = state; }

    State User::GetState() const { return m_State; }

    bool User::IsState(State state) const { return (m_State & state) == state; }

    std::string User::GetNickname() const { return m_Nickname; };

    void User::SetNickname(const std::string& nickname) { m_Nickname = nickname; };
}

// Essential! Do not Delete The Cat!
/*
                    / )
                   ( (
     A.-.A  .-""-.  ) )
    / , , \/      \/ /
   =\  t  ;=    /   /
     `--,'  .""|   /
         || |  \\ \
        ((,_|  ((,_\
*/