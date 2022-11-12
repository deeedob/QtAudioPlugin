#include <pluginterfaces/base/ibstream.h>
#include <pluginterfaces/vst/ivstparameterchanges.h>
#include <pluginterfaces/vst/ivstevents.h>
#include "qvstaudioeffect.h"

QVstAudioEffect::QVstAudioEffect()
    : Steinberg::Vst::AudioEffect(), m_active(false)
{ }


Steinberg::tresult QVstAudioEffect::setActive(Steinberg::TBool state)
{
    if (state)
        m_active = true;
    else
        m_active = false;
    processActive(m_active);
    return Steinberg::Vst::AudioEffect::setActive(state);
}

Steinberg::tresult QVstAudioEffect::process(Steinberg::Vst::ProcessData &data)
{
    if (!m_active)
        return Steinberg::kResultFalse;
    //process parameters
    if (data.inputParameterChanges) {
        Steinberg::int32 nParams = data.inputParameterChanges->getParameterCount();
        for (Steinberg::int32 i = 0; i < nParams; ++i) {
            Steinberg::Vst::IParamValueQueue* paramQueue = data.inputParameterChanges->getParameterData(i);
            if (paramQueue) {
                Steinberg::Vst::ParamValue value;
                Steinberg::int32 sampleOffset;
                Steinberg::int32 nPoints = paramQueue->getPointCount();
                if (paramQueue->getPoint(nPoints - 1, sampleOffset, value) == Steinberg::kResultTrue)
                    parameterChanged(paramQueue->getParameterId(), value);
            }
        }
    }
    processEvents(data.inputEvents);
    processAudio(data);
    return Steinberg::kResultOk;
}

void QVstAudioEffect::parameterChanged(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue value)
{
    (void)id;
    (void)value;
}

void QVstAudioEffect::processAudio(Steinberg::Vst::ProcessData &data)
{
    (void)data;
}

void QVstAudioEffect::processEvents(Steinberg::Vst::IEventList *eventList)
{
    if (eventList == nullptr)
        return;
    Steinberg::int32 nEvents = eventList->getEventCount();
    for (Steinberg::int32 i = 0; i < nEvents; ++i) {
        Steinberg::Vst::Event event;
        eventList->getEvent(i, event);
        switch (event.type) {
            case Steinberg::Vst::Event::kNoteOnEvent:
                noteOn(static_cast<int>(event.noteOn.pitch), event.noteOn.velocity);
                break;
            case Steinberg::Vst::Event::kNoteOffEvent:
                noteOff(static_cast<int>(event.noteOff.pitch), event.noteOff.velocity);
            break;
            default:
                break;
        }
    }
}

void QVstAudioEffect::processActive(bool state)
{
    (void)state;
}

void QVstAudioEffect::noteOn(int number, float velocity)
{
    (void)number;
    (void)velocity;
}

void QVstAudioEffect::noteOff(int number, float velocity)
{
    (void)number;
    (void)velocity;
}
