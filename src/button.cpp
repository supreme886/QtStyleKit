#include "button.h"

QSK_NAMESPACE_BEGIN

class ButtonPrivate
{
public:
    ButtonPrivate(Button *_q) : q_ptr(_q) {}

    QColor highlightColor = Qt::red;
private:
    QSK_DECLARE_DPTR_PUBLIC(Button)
};


Button::Button(QWidget *parent)
    : QAbstractButton{parent}
{}

QSK_NAMESPACE_END
