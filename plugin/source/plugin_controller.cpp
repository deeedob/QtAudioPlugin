#include <pluginterfaces/base/ustring.h>
#include <pluginterfaces/base/ibstream.h>
#include "plugin_controller.h"
#include "plugin_view.h"
#include "../include/ids.h"

PluginController::PluginController()
    : QVstController()
{}

Steinberg::tresult PluginController::initialize(Steinberg::FUnknown *context)
{
    Steinberg::tresult res = Steinberg::Vst::EditController::initialize(context);
    if (res == Steinberg::kResultOk) {
        addParameter(Param_Attack, "Attack", 0, 0.0, "s");
        addParameter(Param_Decay, "Decay", 0, 0.0, "s");
        addParameter(Param_Sustain, "Sustain", 0, 0.0, "s");
        addParameter(Param_Release, "Release", 0, 0.0, "s");
        addParameter(Param_Modulation, "Modulation", 0, 0.0);
    }
    return res;
}

Steinberg::IPlugView* PluginController::createView(Steinberg::FIDString name) PLUGIN_API
{
    if (strcmp(name, Steinberg::Vst::ViewType::kEditor) == 0)
        return new PluginView(this);
    return nullptr;
}
