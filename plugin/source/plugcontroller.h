#pragma once
#include <public.sdk/source/vst/vsteditcontroller.h>

namespace Steinberg {
    namespace Basic {
        class PlugController : public Vst::EditController
        {

        public:
            static FUnknown* createInstance(void*) { return (Vst::IEditController*) new PlugController(); }

            tresult initialize(FUnknown *context) override;
            //IPlugView* createView(FIDString name) PLUGIN_API override;
            tresult setComponentState(IBStream *state) override;
        };
    }
}