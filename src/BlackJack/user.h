#ifndef USER_H
#define USER_H

#include "Deck.h"
#include "Player.h"

namespace BlackJack {
    enum State {
        OutOfBalance    = 0b001,
        NotPlaying      = 0b010,
        Playing         = 0b100,
    };

    class User : public Player
    {
    public:
        User(const std::string& nickname, unsigned int balance);

        void Hit(Deck& deck) override;
        void Stand() override;

        State GetState() const;
        bool IsState(State state) const;
        void SetState(const State& state);

        std::string GetNickname() const;
        void SetNickname(const std::string& nickname);
    private:
        std::string m_Nickname;
        unsigned int m_Balance;
        State m_State = Playing;
    };
}
#endif // USER_H
