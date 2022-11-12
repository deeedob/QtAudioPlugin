#include "qvstparametercontainer.h"
#include <public.sdk/source/vst/vsteditcontroller.h>

QVstParameterContainer::QVstParameterContainer(Steinberg::Vst::EditController *editController, QObject *parent)
    : QObject(parent), m_editController(editController)
{ }


int QVstParameterContainer::count()
{
    return m_editController->getParameterCount();
}

void QVstParameterContainer::setValue(const QString &name, double value)
{
    int n = m_editController->getParameterCount();
    for (int i = 0; i < n; ++i) {
        Steinberg::Vst::ParameterInfo info;
        m_editController->getParameterInfo(i, info);
        auto title = QString::fromUtf16(info.title);
        if (title == name) {
            setValue(info.id, value);
            return;
        }
    }
}

void QVstParameterContainer::setValue(int id, double value)
{
    m_editController->beginEdit(id);
    m_editController->performEdit(id, value);
    m_editController->endEdit(id);
}
