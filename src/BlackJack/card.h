#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QParallelAnimationGroup>

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
        Q_PROPERTY(qreal y READ y WRITE SetY)
    public:
        Card(unsigned int value, Suit suit, const std::string& img);
        ~Card();

        inline unsigned int GetValue() const { return m_Value; };

        inline unsigned int GetSuit() const { return m_Suit; };

        inline bool IsSuit(Suit suit) const { return m_Suit == suit; };

        inline qreal x() const { return m_X; };
        inline qreal y() const { return m_Y; };

        QRectF boundingRect() const override;

        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

        Card* Animate(unsigned int index, const QPointF& position);
    signals:

    public slots:
        void SetX(qreal x);
        void SetY(qreal y);
    private:
        unsigned int m_Value;
        Suit m_Suit;

        qreal m_X;
        qreal m_Y;

        QGraphicsPixmapItem* m_Img;
        QParallelAnimationGroup* m_Animation;
    };
}

#endif // CARD_H
