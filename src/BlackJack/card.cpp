#include "card.h"

namespace BlackJack {
    Card::Card(unsigned int value, Suit suit, const std::string& img)
        :m_Value(value), m_Suit(suit), m_Img(new QGraphicsPixmapItem(QPixmap(QString::fromStdString(img))))
    {}

    unsigned int Card::GetValue() const { return m_Value; };

    unsigned int Card::GetSuit() const { return m_Suit; };

    bool Card::IsSuit(Suit suit) const { return m_Suit == suit; };

    QGraphicsPixmapItem* Card::GetImg() const { return m_Img; }
}
