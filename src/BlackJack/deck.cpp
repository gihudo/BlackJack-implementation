#include "Deck.h"

namespace BlackJack {
    /*
        Seed for random generation is based on deck creation time
        Note:	It is better to use a more secure method for random generation,
                but as it`s a test, I think it`s fine
    */

    Deck::Deck(std::string texture)
        :m_IsEmpty(false), m_Seed(time(NULL)), m_Texture(texture)
    {
        std::vector<std::unique_ptr<Card>> clubs;
        for (int i = 0; i < 8; ++i)
            clubs.emplace_back(std::make_unique<Card>(i, Clubs, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(J, Clubs, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(Q, Clubs, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(K, Clubs, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(A, Clubs, m_Texture));

        std::vector<std::unique_ptr<Card>> spades;
        for (int i = 0; i < 8; ++i)
            clubs.emplace_back(std::make_unique<Card>(i, Spades, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(J, Spades, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(Q, Spades, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(K, Spades, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(A, Spades, m_Texture));

        std::vector<std::unique_ptr<Card>> hearts;
        for (int i = 0; i < 8; ++i)
            clubs.push_back(std::make_unique<Card>(i, Hearts, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(J, Hearts, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(Q, Hearts, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(K, Hearts, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(A, Hearts, m_Texture));

        std::vector<std::unique_ptr<Card>> diamonds;
        for (int i = 0; i < 8; ++i)
            clubs.push_back(std::make_unique<Card>(i, Diamonds, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(J, Diamonds, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(Q, Diamonds, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(K, Diamonds, m_Texture));
        clubs.emplace_back(std::make_unique<Card>(A, Diamonds, m_Texture));

        //m_Deck.insert(m_Deck.end(), std::make_move_iterator(clubs.begin()), std::make_move_iterator(clubs.end()));
        //m_Deck.insert(m_Deck.end(), std::make_move_iterator(spades.begin()), std::make_move_iterator(spades.end()));
        //m_Deck.insert(m_Deck.end(), std::make_move_iterator(hearts.begin()), std::make_move_iterator(hearts.end()));
        //m_Deck.insert(m_Deck.end(), std::make_move_iterator(diamonds.begin()), std::make_move_iterator(diamonds.end()));

        //m_Deck.insert(clubs.begin(), clubs.end(), m_Deck.end());
        //m_Deck.insert(spades.begin(), spades.end(), m_Deck.end());
        //m_Deck.insert(hearts.begin(), hearts.end(), m_Deck.end());
        //m_Deck.insert(diamonds.begin(), diamonds.end(), m_Deck.end());
    }

    void Deck::Shuffle()
    {
        srand(m_Seed);
        for (int i = 0; i < m_Deck.size(); i++) {
            std::swap(m_Deck[i], m_Deck[rand() % m_Deck.size()]);
        }
    }

    std::shared_ptr<Card> Deck::GetCard()
    {
        if (m_IsEmpty)
            throw std::out_of_range("The deck is empty");

        std::shared_ptr<Card> card = m_Deck[0];
        m_Deck.erase(m_Deck.begin());
        m_IsEmpty = m_Deck.size() == 0;

        return card;
    }

    bool Deck::IsEmpty() const { return m_IsEmpty; }
}
