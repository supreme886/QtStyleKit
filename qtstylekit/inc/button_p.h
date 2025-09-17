#ifndef BUTTON_P_H
#define BUTTON_P_H

#include <QColor>
#include "common.h"

QSK_NAMESPACE_BEGIN

class Button;
class ButtonPrivate
{
    QSK_DECLARE_DPTR_PUBLIC(Button)
public:
    ButtonPrivate(Button *_q);
    ~ButtonPrivate();

    void init();

    QColor bgColor;
    QColor slidColor;
    QColor textColor;
    QColor highlightColor;
    int radius;
    Qt::PenStyle borderStyle;
};

QSK_NAMESPACE_END

#endif // BUTTON_P_H
