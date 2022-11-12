#include "plugin_processor.h"
#include "../include/ids.h"

PluginProcessor::PluginProcessor()
    : QVstAudioEffect()
{
    setControllerClass(ControllerUID);
}

Steinberg::tresult PluginProcessor::initialize(Steinberg::FUnknown *context) {
    Steinberg::tresult res = Steinberg::Vst::AudioEffect::initialize(context);
    if (res == Steinberg::kResultOk) {
        addEventInput(STR16("MIDI in"), 1);
        addAudioOutput(STR16("Stereo Out"), Steinberg::Vst::SpeakerArr::kStereo);
    }
    return res;
}

void PluginProcessor::processActive(bool state) {
    QVstAudioEffect::processActive(state);
}

void PluginProcessor::processAudio(Steinberg::Vst::ProcessData &data) {
    QVstAudioEffect::processAudio(data);
}

void PluginProcessor::parameterChanged(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue value) {
    switch (id) {
        case Param_Attack:
            break;
        case Param_Decay:
            break;
        case Param_Modulation:
            break;
        case Param_Sustain:
            break;
        case Param_Release:
            break;
        case Param_Volume:
            break;
    }
}

void PluginProcessor::noteOn(int number, float velocity) {
    QVstAudioEffect::noteOn(number, velocity);
}

void PluginProcessor::noteOff(int number, float velocity) {
    QVstAudioEffect::noteOff(number, velocity);
}
