#include "plugcontroller.h"
#include "../include/plugids.h"
#include <base/source/fstreamer.h>
#include <pluginterfaces/base/ibstream.h>

using namespace Steinberg;
using namespace Steinberg::Basic;

tresult PlugController::initialize(FUnknown *context)
{
    tresult result = EditController::initialize(context);

    if (result == kResultTrue) {
        //---Create Parameters------------
		parameters.addParameter (STR16 ("Bypass"), nullptr, 1, 0,
		                         Vst::ParameterInfo::kCanAutomate | Vst::ParameterInfo::kIsBypass,
		                         Basic::kBypassId);

		parameters.addParameter (STR16 ("Parameter 1"), STR16 ("dB"), 0, .5,
		                         Vst::ParameterInfo::kCanAutomate, Basic::kParamVolId, 0,
		                         STR16 ("Param1"));
		parameters.addParameter (STR16 ("Parameter 2"), STR16 ("On/Off"), 1, 1.,
		                         Vst::ParameterInfo::kCanAutomate, Basic::kParamOnId, 0,
		                         STR16 ("Param2"));
    }
    return kResultTrue;
}

//IPlugView *PlugController::createView(FIDString name)
//{
//    if (name && strcmp(name, "editor") == 0) {
//        auto* view = new VSTGUI::VST3Editor(this, "view", "plug.uidesc");
//        return view;
//    }
//    return nullptr;
//}

tresult PlugController::setComponentState(IBStream *state)
{
    if (!state)
        return kResultFalse;
    IBStreamer streamer(state, kLittleEndian);

    float savedParam1 = 0.f;
    if (streamer.readFloat(savedParam1) == false)
        return kResultFalse;
    setParamNormalized(Basic::kParamVolId, savedParam1);

    int8 savedParam2 = 0;
    if (streamer.readInt8(savedParam2) == false)
        return kResultFalse;
    setParamNormalized(Basic::kParamOnId, savedParam2);

    // read the bypass
    int32 bypassState;
    if (streamer.readInt32(bypassState) == false)
        return kResultFalse;
    setParamNormalized (kBypassId, bypassState ? 1 : 0);

    return kResultOk;

}


