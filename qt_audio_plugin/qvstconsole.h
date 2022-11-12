#ifndef QVSTCONSOLE_H
#define QVSTCONSOLE_H

#include <QObject>

class QVstConsolePrivate;

// TODO implement this
class QVstConsole : public QObject
{
    Q_OBJECT
public:
    QVstConsole(QObject* parent = nullptr);
    ~QVstConsole();

    void writeLine(const char* str);
private:
    QVstConsolePrivate* d_ptr;
};

#endif
