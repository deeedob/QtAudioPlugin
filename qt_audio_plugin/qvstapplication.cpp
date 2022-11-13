#include "qvstapplication.h"

//struct QVstApplicationPrivate
//{
//    Qt::HANDLE handle;
//    QVstConsole* console;
//};

//static void msgHandler(QtMsgType type, const QMessageLogContext &contect, const QString &text)
//{
//    QByteArray baText = text.toLatin1();
//    switch (type) {
//        case QtFatalMsg:
//        case QtCriticalMsg:
//        case QtWarningMsg:
//        case QtDebugMsg:
//        default: {
//            QVstConsole *pConsole = QVstApplication::instance()->console();
//            if (pConsole != nullptr) {
//                QVstApplication::instance()->console()->writeLine(baText.constData());
//            }
//            break;
//        }
//    }
//}

QVstApplication::QVstApplication(int argc, char** argv)
    : QApplication(argc, argv)
{
    //d_ptr = new QVstApplicationPrivate;
    //d_ptr->handle = handle;
    //d_ptr->console = nullptr;
    //if ((flags & Flags::Flag_CreateConsole) != 0)
    //    d_ptr->console = new QVstConsole(this);
    setAttribute(Qt::AA_NativeWindows, true);
}

QVstApplication::~QVstApplication()
{
    //delete d_ptr;
}

QVstApplication *QVstApplication::createInstance()
{
    QApplication* app = qApp;
    if (app)
        return static_cast<QVstApplication*>(app);

    int argc = 0;
    auto* instance = new QVstApplication(argc, nullptr);
    //if ((flags & Flag_CreateConsole) != 0)
    //    qInstallMessageHandler(msgHandler);
    return instance;
}

QVstApplication *QVstApplication::instance()
{
    return static_cast<QVstApplication*>(qApp);
}

//QVstConsole *QVstApplication::console() const
//{
//    return d_ptr->console;
//}