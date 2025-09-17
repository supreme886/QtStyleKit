#ifndef QSKWIDGETSCOLLECTION_H
#define QSKWIDGETSCOLLECTION_H

#include <QtUiPlugin/QDesignerCustomWidgetInterface>
#include "button.h"

class ButtonPlugin : public QObject, public QDesignerCustomWidgetInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QDesignerCustomWidgetInterface")
    Q_INTERFACES(QDesignerCustomWidgetInterface)

public:
    explicit ButtonPlugin(QObject *parent = nullptr) : QObject(parent) {}

    QWidget *createWidget(QWidget *parent) override { return new QSK::Button(parent); }
    QString name() const override { return QStringLiteral("Button"); }
    QString group() const override { return QStringLiteral("QtStyleKit"); }
    QIcon icon() const override { return QIcon(); }
    QString toolTip() const override { return QStringLiteral("Custom Button"); }
    QString whatsThis() const override { return QStringLiteral("Custom styled button"); }
    bool isContainer() const override { return false; }
    QString includeFile() const override { return QStringLiteral("button.h"); }
};

#endif // QSKWIDGETSCOLLECTION_H
