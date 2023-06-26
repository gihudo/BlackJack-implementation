#include "card.h"
#include "qpainter.h"

namespace BlackJack {
    Card::Card(unsigned int value, Suit suit, const std::string& img)
        :m_Value(value), m_Suit(suit), m_Img(new QGraphicsPixmapItem(QPixmap(QString::fromStdString(img))))
    {}

    Card::~Card()
    {
        delete m_Img;
    }


    QRectF Card::boundingRect() const
    {
        qreal margin = 1.0;
        return QRectF(-margin, -margin, 300 + 2 * margin, 450 + 2 * margin);
    }

    void Card::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
    {
        painter->setPen(Qt::black);
        painter->drawRect(boundingRect());

        if (m_Img != nullptr) {
            QPointF imagePosition(0, 0);
            painter->drawPixmap(imagePosition, m_Img->pixmap());
        }
    }
}
