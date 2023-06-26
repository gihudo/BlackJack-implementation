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

    class Card: public QObject, public QGraphicsItem
    {
        Q_OBJECT
    public:
        Card(unsigned int value, Suit suit, const std::string& img);
        ~Card();

        inline unsigned int GetValue() const { return m_Value; };

        inline unsigned int GetSuit() const { return m_Suit; };

        inline bool IsSuit(Suit suit) const { return m_Suit == suit; };

        QRectF boundingRect() const override;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    signals:

    public slots:

    private:
        unsigned int m_Value;
        Suit m_Suit;
        QGraphicsPixmapItem* m_Img;
    };
}

#endif // CARD_H
