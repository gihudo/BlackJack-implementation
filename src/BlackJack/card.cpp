#include "card.h"
#include "qpainter.h"

static const qreal CARD_SCALE = 0.5;

static const int ANIM_DURATION = 1500;
static const qreal ANIM_START_POSITION = 250;
static const qreal ANIM_END_POSITION = -100;

namespace BlackJack {
    Card::Card(unsigned int value, Suit suit, const std::string& img)
        :m_Value(value), m_Suit(suit), m_Img(new QGraphicsPixmapItem(QPixmap(QString::fromStdString(img))))
    {
        m_Img->setPos(QPointF(-m_Img->boundingRect().size().width(), 0));
    }

    Card::~Card()
    {
        delete m_Img;
    }

    QRectF Card::boundingRect() const
    {
        qreal margin = 1.0;
        return QRectF(-margin, -margin, (300 + 2 * margin) * CARD_SCALE, (450 + 2 * margin) * CARD_SCALE);
    }

    void Card::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
    {
        painter->setPen(Qt::black);
        painter->drawRect(boundingRect());

        if (m_Img != nullptr) {
            QPointF imagePosition(0, 0);
            painter->scale(CARD_SCALE, CARD_SCALE);
            painter->drawPixmap(imagePosition, m_Img->pixmap());
        }
    }

    void Card::SetX(qreal x)
    {
        moveBy(x - m_X, 0);
        m_X = x;
    }

    Card* Card::Animate(int count_delay)
    {
        QTimer::singleShot(count_delay * 1000, [=]() {
            m_Animation = new QPropertyAnimation(this, "x", this);
            m_Animation->setStartValue(ANIM_START_POSITION);
            m_Animation->setEndValue(ANIM_END_POSITION);
            m_Animation->setEasingCurve(QEasingCurve::Linear);
            m_Animation->setDuration(ANIM_DURATION);
            m_Animation->start();
        });

        return this;
    }
}
