#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>

#define A 1
#define J 10
#define Q 10
#define K 10

namespace BlackJack {
    enum Suit {
        Spades,
        Hearts,
        Diamonds,
        Clubs
    };

    class Card: public QObject
    {
        Q_OBJECT
    public:
        Card(unsigned int value, Suit suit, const std::string& img);

        unsigned int GetValue() const;

        unsigned int GetSuit() const;
        bool IsSuit(Suit suit) const;

        QGraphicsPixmapItem* GetImg() const;
    private:
        unsigned int m_Value;
        Suit m_Suit;
        QGraphicsPixmapItem* m_Img;
    };
}

#endif // CARD_H
