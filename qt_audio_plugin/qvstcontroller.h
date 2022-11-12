#ifndef QVSTCONTROLLER_H
#define QVSTCONTROLLER_H
#include <QString>
#include <QMap>
#include <pluginterfaces/base/funknown.h>
#include <pluginterfaces/vst/ivstmidicontrollers.h>
#include <public.sdk/source/vst/vsteditcontroller.h>

class QVstController : public virtual Steinberg::Vst::EditController,
                       public virtual Steinberg::Vst::IMidiMapping
{
public:
    QVstController();
    ~QVstController() override = default;

    Steinberg::tresult initialize(FUnknown *context) override;
    Steinberg::tresult terminate() override;
    Steinberg::tresult queryInterface(const char *_iid, void **obj) override;
    Steinberg::tresult getMidiControllerAssignment(Steinberg::int32 busIndex, Steinberg::int16 channel,
                                                   Steinberg::Vst::CtrlNumber midiControllerNumber,
                                                   Steinberg::Vst::ParamID &id) override;
    Steinberg::tresult setComponentState(Steinberg::IBStream *state) override;
    Steinberg::IPlugView *createView(Steinberg::FIDString name) PLUGIN_API override;

    void addParameter(Steinberg::Vst::ParamID id, const QString& name, quint32 stepCount, double defaultValue = 0.0, const QString& units = QString(), quint16 midiCtrl = 0 );

    DELEGATE_REFCOUNT(Steinberg::Vst::EditController)

private:
    QMap<Steinberg::Vst::CtrlNumber, Steinberg::Vst::ParamID> m_midiCtrlMap;
};

#endif
