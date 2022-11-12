#include "qvstcontroller.h"
#include "qvsteditorview.h"
#include <pluginterfaces/base/ibstream.h>
#include <pluginterfaces/base/ustring.h>
#include <pluginterfaces/vst/ivstinterappaudio.h>

QVstController::QVstController()
    : EditController()
{}

Steinberg::tresult QVstController::initialize(Steinberg::FUnknown *context)
{
    Steinberg::tresult res = Steinberg::Vst::EditController::initialize(context);
    return res;
}

Steinberg::tresult QVstController::terminate()
{
    return Steinberg::Vst::EditController::terminate();
}

Steinberg::tresult QVstController::setComponentState(Steinberg::IBStream *state)
{
    if (state == nullptr)
        return Steinberg::kResultFalse;

    Steinberg::int32 n_params = getParameterCount();
    for (int i = 0; i < n_params; ++i) {
        Steinberg::Vst::Parameter* param = parameters.getParameterByIndex(i);
        Steinberg::Vst::ParamValue val = 0.0;
        if (state->read(&val, sizeof(Steinberg::Vst::ParamValue)) != Steinberg::kResultOk) {
            return Steinberg::kResultFalse;
        }
        param->setNormalized(val);
    }
    return Steinberg::kResultOk;
}

Steinberg::IPlugView *QVstController::createView(Steinberg::FIDString name)
{
    if (strcmp(name, Steinberg::Vst::ViewType::kEditor) == 0)
        return new QVstEditorView(this);
    return nullptr;
}

Steinberg::tresult QVstController::queryInterface(const char *_iid, void **obj)
{
    QUERY_INTERFACE(_iid, obj, Steinberg::Vst::IMidiMapping::iid, Steinberg::Vst::IMidiMapping)
    return Steinberg::Vst::EditController::queryInterface(_iid, obj);
}

Steinberg::tresult QVstController::getMidiControllerAssignment(Steinberg::int32 busIndex, Steinberg::int16 channel,
                                                               Steinberg::Vst::CtrlNumber midiControllerNumber,
                                                               Steinberg::Vst::ParamID &id)
{
    if (m_midiCtrlMap.contains(midiControllerNumber)) {
        id = m_midiCtrlMap.value(midiControllerNumber);
        return Steinberg::kResultTrue;
    }
    return Steinberg::kResultFalse;
}

void QVstController::addParameter(Steinberg::Vst::ParamID id, const QString &name, quint32 stepCount, double defaultValue, const QString &units, quint16 midiCtrl)
{
    auto* wchName = new wchar_t[name.length() + 1];
    name.toWCharArray(wchName);
    wchName[name.length()] = 0;
    wchar_t* wchUnits = nullptr;

    if (!units.isEmpty()) {
        wchUnits = new wchar_t[units.length() + 1];
        units.toWCharArray(wchUnits);
        wchUnits[units.length()] = 0;
    }
    Steinberg::Vst::Parameter* param = parameters.addParameter((Steinberg::Vst::TChar*)wchName, (Steinberg::Vst::TChar*)wchUnits, stepCount, defaultValue, 0, id);

    if (midiCtrl != 0)
        m_midiCtrlMap.insert(midiCtrl, param->getInfo().id);

    delete[] wchUnits;
    delete[] wchName;
}
