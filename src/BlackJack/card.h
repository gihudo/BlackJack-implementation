#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>
#include <QTimer>

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
        Q_PROPERTY(qreal x READ x WRITE SetX)
    public:
        Card(unsigned int value, Suit suit, const std::string& img);
        ~Card();

        inline unsigned int GetValue() const { return m_Value; };

        inline unsigned int GetSuit() const { return m_Suit; };

        inline bool IsSuit(Suit suit) const { return m_Suit == suit; };

        inline qreal x() const { return m_X; };

        QRectF boundingRect() const override;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

        Card* Animate(int count_delay);
    signals:

    public slots:
        void SetX(qreal x);

    private:
        unsigned int m_Value;
        Suit m_Suit;

        qreal m_X;
        QGraphicsPixmapItem* m_Img;
        QPropertyAnimation * m_Animation;
    };
}

#endif // CARD_H
