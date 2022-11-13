#include "qvsthostedwidget.h"
#include <qvstapplication.h>
#include <QEvent>

QVstHostedWidget::QVstHostedWidget(QObject *parent, Qt::WindowFlags flags)
    : QWidget(nullptr, flags)
{
    if (parent != nullptr)
        QObject::setParent(parent);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    setAttribute(Qt::WA_NativeWindow, true);
    initialize();
}

QVstHostedWidget::~QVstHostedWidget()
{

}

void QVstHostedWidget::initialize()
{
    setVisible(true);
    QEvent evt(QEvent::EmbeddingControl);
    QVstApplication::sendEvent(this, &evt);
    move(0, 0);
    resize(QSize(500, 200));
    update();
}