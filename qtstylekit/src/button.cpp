#include "button.h"

#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOptionButton>

QSK_NAMESPACE_BEGIN

ButtonPrivate::ButtonPrivate(Button *_q): q_ptr(_q)
{
}

ButtonPrivate::~ButtonPrivate()
{
}

void ButtonPrivate::init()
{
    bgColor = QColor(QSK_QRGB_LITERAL("#1890ff"));
    slidColor = QColor(QSK_QRGB_LITERAL("#1890ff"));
    textColor = Qt::white;
    highlightColor = Qt::red;
    radius = 5;
    borderStyle = Qt::DashLine;
}

Button::Button(QWidget *parent)
    : QPushButton(parent),
      d_ptr(new ButtonPrivate(this))
{
    d_ptr->init();
}

void Button::setBackgroundColor(const QColor &bgColor)
{
    Q_D(Button);
    d_ptr->bgColor = bgColor;
    update();
}

QColor Button::backgroundColor()
{
    Q_D(Button);
    return d_ptr->bgColor;
}

void Button::setSlidColor(const QColor &slidColor)
{
    Q_D(Button);
    d_ptr->slidColor = slidColor;
    update();
}

QColor Button::slidColor()
{
    Q_D(Button);
    return d_ptr->slidColor;
}

void Button::setTextColor(const QColor &textColor)
{
    Q_D(Button);
    d_ptr->textColor = textColor;
    update();
}

QColor Button::textColor()
{
    Q_D(Button);
    return d_ptr->textColor;
}

void Button::setHighlightColor(const QColor &highlightColor)
{
    Q_D(Button);
    d_ptr->highlightColor = highlightColor;
    update();
}

QColor Button::highlightColor()
{
    Q_D(Button);
    return d_ptr->highlightColor;
}

void Button::setBorderStyle(Qt::PenStyle borderStyle)
{
    Q_D(Button);
    d_ptr->borderStyle = borderStyle;
    update();
}

Qt::PenStyle Button::borderStyle()
{
    return d_ptr->borderStyle;
}

void Button::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)
    QStylePainter p(this);
    QStyleOptionButton option;
    initStyleKitOption(&option);

    p.setPen(borderStyle());
    QPainterPath path;
    path.addRoundedRect(option.rect, 5, 5);
    p.setClipPath(path);

    p.drawControl(QStyle::CE_PushButton, option);
}

void Button::initStyleKitOption(QStyleOptionButton *option)
{
    initStyleOption(option);
    option->palette.setColor(QPalette::Button, backgroundColor());
    qDebug() <<Q_FUNC_INFO << backgroundColor();
    // option.features = QStyleOptionButton::Flat;
}

QSK_NAMESPACE_END
