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
        std::vector<Card*> clubs;
        for (int i = 2; i <= 10; ++i)
            clubs.emplace_back(new Card(i, Clubs, ":/resources/resources/" + texture + "/clubs/" + std::to_string(i) +".png"));
        clubs.emplace_back(new Card(J, Clubs, ":/resources/resources/" + texture + "/clubs/" + "j.png"));
        clubs.emplace_back(new Card(Q, Clubs, ":/resources/resources/" + texture + "/clubs/" + "q.png"));
        clubs.emplace_back(new Card(K, Clubs, ":/resources/resources/" + texture + "/clubs/" + "k.png"));
        clubs.emplace_back(new Card(A, Clubs, ":/resources/resources/" + texture + "/clubs/" + "a.png"));

        std::vector<Card*> spades;
        for (int i = 2; i <= 10; ++i)
            spades.emplace_back(new Card(i, Spades, ":/resources/resources/" + texture + "/spades/" + std::to_string(i) +".png"));
        spades.emplace_back(new Card(J, Spades, ":/resources/resources/" + texture + "/spades/" + "j.png"));
        spades.emplace_back(new Card(Q, Spades, ":/resources/resources/" + texture + "/spades/" + "q.png"));
        spades.emplace_back(new Card(K, Spades, ":/resources/resources/" + texture + "/spades/" + "k.png"));
        spades.emplace_back(new Card(A, Spades, ":/resources/resources/" + texture + "/spades/" + "a.png"));

        std::vector<Card*> hearts;
        for (int i = 2; i <= 10; ++i)
            hearts.emplace_back(new Card(i, Hearts, ":/resources/resources/" + texture + "/hearts/" + std::to_string(i) +".png"));
        hearts.emplace_back(new Card(J, Hearts, ":/resources/resources/" + texture + "/hearts/" + "j.png"));
        hearts.emplace_back(new Card(Q, Hearts, ":/resources/resources/" + texture + "/hearts/" + "q.png"));
        hearts.emplace_back(new Card(K, Hearts, ":/resources/resources/" + texture + "/hearts/" + "k.png"));
        hearts.emplace_back(new Card(A, Hearts, ":/resources/resources/" + texture + "/hearts/" + "a.png"));

        std::vector<Card*> diamonds;
        for (int i = 2; i <= 10; ++i)
            diamonds.emplace_back(new Card(i, Diamonds, ":/resources/resources/" + texture + "/diamonds/" + std::to_string(i) +".png"));
        diamonds.emplace_back(new Card(J, Diamonds, ":/resources/resources/" + texture + "/diamonds/" + "j.png"));
        diamonds.emplace_back(new Card(Q, Diamonds, ":/resources/resources/" + texture + "/diamonds/" + "q.png"));
        diamonds.emplace_back(new Card(K, Diamonds, ":/resources/resources/" + texture + "/diamonds/" + "k.png"));
        diamonds.emplace_back(new Card(A, Diamonds, ":/resources/resources/" + texture + "/diamonds/" + "a.png"));

        m_Deck.insert(m_Deck.end(), clubs.begin(), clubs.end());
        m_Deck.insert(m_Deck.end(), spades.begin(), spades.end());
        m_Deck.insert(m_Deck.end(), hearts.begin(), hearts.end());
        m_Deck.insert(m_Deck.end(), diamonds.begin(), diamonds.end());
    }

    void Deck::Shuffle()
    {
        srand(m_Seed);
        for (int i = 0; i < m_Deck.size(); i++) {
            std::swap(m_Deck[i], m_Deck[rand() % m_Deck.size()]);
        }
    }

    Card* Deck::GetCard()
    {
        if (m_IsEmpty)
            throw std::out_of_range("The deck is empty");

        Card* card = m_Deck[0];
        m_Deck.erase(m_Deck.begin());
        m_IsEmpty = m_Deck.size() == 0;

        return card;
    }

    bool Deck::IsEmpty() const { return m_IsEmpty; }
}
