#pragma once

#include <qvstaudioeffect.h>

class PluginProcessor : public QVstAudioEffect
{
public:
    PluginProcessor();
    static FUnknown* createInstance(void*) { return (Steinberg::Vst::IAudioProcessor*) new PluginProcessor(); }

    Steinberg::tresult initialize(FUnknown *context) override;

protected:
    void processActive(bool state) override;
    void processAudio(Steinberg::Vst::ProcessData &data) override;
    void parameterChanged(Steinberg::Vst::ParamID id, Steinberg::Vst::ParamValue value) override;
    void noteOn(int number, float velocity) override;
    void noteOff(int number, float velocity) override;
};