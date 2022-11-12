#ifndef QVSTAUDIOEFFECT_H
#define QVSTAUDIOEFFECT_H

#include <pluginterfaces/base/funknown.h>
#include <public.sdk/source/vst/vstaudioeffect.h>

class QVstAudioEffect : public Steinberg::Vst::AudioEffect
{
public:
    QVstAudioEffect();

    Steinberg::tresult process(Steinberg::Vst::ProcessData &data) override;
    Steinberg::tresult setActive(Steinberg::TBool state) override;

protected:
    virtual void parameterChanged(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue value);
    virtual void processAudio(Steinberg::Vst::ProcessData &data);
    virtual void processEvents(Steinberg::Vst::IEventList *eventList);
    virtual void processActive(bool state);
    virtual void noteOn(int number, float velocity);
    virtual void noteOff(int number, float velocity);

private:
    bool m_active;
};

#endif
