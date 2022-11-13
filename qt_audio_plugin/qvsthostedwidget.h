#ifndef QVSTHOSTEDWIDGET_H
#define QVSTHOSTEDWIDGET_H

#include <QWidget>

class QVstHostedWidget : public QWidget
{
    Q_OBJECT
    friend class QVstEditorView;
public:
    explicit QVstHostedWidget(QObject* parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());
    ~QVstHostedWidget() override;
private:
    void initialize();
};

#endif //CUSTOM_VST_QVSTHOSTEDWIDGET_H
