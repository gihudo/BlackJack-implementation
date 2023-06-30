#include "card.h"
#include "qpainter.h"

static const qreal CARD_SCALE = 0.5;

static const qreal ANIM_DURATION = 250;
static const qreal XSTART_POSITION = 250;
static const qreal YSTART_POSITION = 250;
static const qreal CARD_OFFSET = 100;

namespace BlackJack {
    Card::Card(unsigned int value, Suit suit, const std::string& img)
        :m_Value(value), m_Suit(suit), m_Img(new QGraphicsPixmapItem(QPixmap(QString::fromStdString(img))))
    {
        this->SetX(XSTART_POSITION);
        this->SetY(YSTART_POSITION);
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
            painter->scale(CARD_SCALE, CARD_SCALE);
            painter->drawPixmap(QPointF(0, 0), m_Img->pixmap());
        }
    }

    void Card::SetY(qreal y)
    {
        moveBy(0, y - m_Y);
        m_Y = y;
    }

    void Card::SetX(qreal x)
    {
        moveBy(x - m_X, 0);
        m_X = x;
    }

    Card* Card::Animate(unsigned int index, const QPointF& position)
    {
        QTimer::singleShot(index * ANIM_DURATION, [=]() {
            m_Animation = new QParallelAnimationGroup(this);

            auto xAnimation = new QPropertyAnimation(this, "x", this);
            xAnimation->setStartValue(XSTART_POSITION);
            xAnimation->setEndValue(position.x() + CARD_OFFSET * index);
            xAnimation->setEasingCurve(QEasingCurve::Linear);
            xAnimation->setDuration(ANIM_DURATION);
            m_Animation->addAnimation(xAnimation);

            auto yAnimation = new QPropertyAnimation(this, "y", this);
            yAnimation->setStartValue(YSTART_POSITION);
            yAnimation->setEndValue(position.y());
            yAnimation->setEasingCurve(QEasingCurve::Linear);
            yAnimation->setDuration(ANIM_DURATION);
            m_Animation->addAnimation(yAnimation);

            m_Animation->start();
        });

        return this;
    }
}
