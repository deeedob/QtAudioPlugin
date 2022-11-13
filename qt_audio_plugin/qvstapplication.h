#ifndef QVSTAPPLICATION_H
#define QVSTAPPLICATION_H

#include <QApplication>
//#include "qvstconsole.h"

class QVstApplicationPrivate;

// TODO add logging/console/debug options
class QVstApplication : public QApplication
{
    Q_OBJECT
public:

    enum Flags {
        Flag_None = 0,
        Flag_CreateConsole = 1
    };

    static QVstApplication* createInstance();
    static QVstApplication* instance();

    ~QVstApplication() override;

    //QVstConsole* console() const;
private:
    QVstApplication(int argc, char** argv);
    //QVstApplicationPrivate* d_ptr;
};


#endif
