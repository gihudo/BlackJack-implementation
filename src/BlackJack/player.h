#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include <string>

namespace BlackJack {
    class Player
    {
    public:
        virtual void Hit(Deck& deck) = 0;
        virtual void Stand() = 0;

        unsigned int CheckHand() const
        {
            unsigned int sum = 0;
            for (int i = 0; i < m_Hand.size(); i++)
                sum += m_Hand[i]->GetValue();
            return sum;
        }

        inline std::vector<Card*> GetHand() { return m_Hand; }
    protected:
        std::vector<Card*> m_Hand;
    };
}

#endif // PLAYER_H
