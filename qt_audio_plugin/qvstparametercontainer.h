#ifndef QVSTPARAMETERCONTAINER_H
#define QVSTPARAMETERCONTAINER_H

#include <QObject>

namespace Steinberg {
    namespace Vst {
        class EditController;
    }
}

class QVstParameterContainer : public QObject
{
    Q_OBJECT
public:
    QVstParameterContainer(Steinberg::Vst::EditController* editController, QObject* parent = nullptr);
    ~QVstParameterContainer() = default;
    int count();

public slots:
    void setValue(const QString& name, double value);
    void setValue(int id, double value);

private:
    Steinberg::Vst::EditController* m_editController;
};


#endif
