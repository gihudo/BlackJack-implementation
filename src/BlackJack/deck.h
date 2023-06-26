#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <vector>
#include <numeric>
#include <time.h>
#include <memory>
#include <stdexcept>

namespace BlackJack {
    class Deck
    {
    public:
        Deck(std::string texture);

        void Shuffle();
        Card* GetCard();
        bool IsEmpty() const;
    private:
        std::vector<Card*> m_Deck;
        bool m_IsEmpty;
        int m_Seed;
        std::string m_Texture;
    };
}

#endif // DECK_H
