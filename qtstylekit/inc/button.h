#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QPushButton>

#include "button_p.h"
#include "common.h"

QSK_NAMESPACE_BEGIN

class ButtonPrivate;

class QSK_LIBRARY Button : public QPushButton
{
    Q_OBJECT
    QSK_DECLARE_DPTR_PRIVATE(Button)

    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor)
    Q_PROPERTY(QColor slidColor READ slidColor WRITE setSlidColor)
    Q_PROPERTY(QColor textColor READ textColor WRITE setTextColor)
    Q_PROPERTY(QColor highlightColor READ highlightColor WRITE setHighlightColor)
    Q_PROPERTY(Qt::PenStyle borderStyle READ borderStyle WRITE setBorderStyle)
public:
    explicit Button(QWidget *parent = nullptr);

    void setBackgroundColor(const QColor &bgColor);
    QColor backgroundColor();

    void setSlidColor(const QColor &slidColor);
    QColor slidColor();

    void setTextColor(const QColor &textColor);
    QColor textColor();

    void setHighlightColor(const QColor &highlightColor);
    QColor highlightColor();

    void setBorderStyle(Qt::PenStyle borderStyle);
    Qt::PenStyle borderStyle();

protected:
    void paintEvent(QPaintEvent *e) override;
    void initStyleKitOption(QStyleOptionButton *option);
};

QSK_NAMESPACE_END

#endif // BUTTON_H
