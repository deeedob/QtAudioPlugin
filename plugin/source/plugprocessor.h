#pragma once

#include <public.sdk/source/vst/vstaudioeffect.h>

namespace Steinberg {
    namespace Basic {
        class PlugProcessor : public Vst::AudioEffect
        {
        public:
            PlugProcessor();
            static FUnknown* createInstance(void*) { return (Vst::IAudioProcessor*) new PlugProcessor(); }

            tresult initialize(FUnknown *context) override;
            tresult setBusArrangements(Vst::SpeakerArrangement *inputs, int32 numIns, Vst::SpeakerArrangement *outputs,int32 numOuts) override;
            tresult setupProcessing(Vst::ProcessSetup &setup) override;
            tresult setActive(TBool state) override;
            tresult process(Vst::ProcessData &data) override;
            tresult setState(IBStream *state) override;
            tresult getState(IBStream *state) override;
        protected:
            Vst::ParamValue m_param1 = 0;
            int16 m_param2 = 0;
            bool m_bypass = false;
        };
    }
}