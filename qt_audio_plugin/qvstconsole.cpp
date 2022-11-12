#include "qvstconsole.h"
#include <cstdio>

struct QVstConsolePrivate
{

};

QVstConsole::QVstConsole(QObject *parent)
    : QObject(parent)
{
    d_ptr = new QVstConsolePrivate;
}

QVstConsole::~QVstConsole()
{
    delete d_ptr;
}

void QVstConsole::writeLine(const char *str)
{
    char buf[256] = {0};
    snprintf(buf, 255, "%s\n", str);
}