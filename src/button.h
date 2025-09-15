#ifndef BUTTON_H
#define BUTTON_H

#include <QObject>
#include <QAbstractButton>

#include "common/common.h"

QSK_NAMESPACE_BEGIN

class ButtonPrivate;

class Button : public QAbstractButton
{
    Q_OBJECT
    QSK_DECLARE_DPTR_PRIVATE(Button)
    QSK_PROPERTY(bool, autoInsertSpace, false)
public:
    explicit Button(QWidget *parent = nullptr);

signals:
};

QSK_NAMESPACE_END

#endif // BUTTON_H
