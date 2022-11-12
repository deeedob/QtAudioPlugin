#pragma once

#include <qvstcontroller.h>

class PluginController : public QVstController
{
public:
    PluginController();

    static FUnknown* createInstance(void*) {
        return (Steinberg::Vst::IEditController*) new PluginController();
    }

    Steinberg::IPlugView* createView(Steinberg::FIDString name) PLUGIN_API override;
    Steinberg::tresult initialize(FUnknown *context) override;
};