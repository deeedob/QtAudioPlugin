#include <base/source/fstreamer.h>
#include <pluginterfaces/base/ibstream.h>
#include <pluginterfaces/vst/ivstparameterchanges.h>
#include "plugprocessor.h"
#include "../include/plugids.h"

using namespace Steinberg;
using namespace Steinberg::Basic;

PlugProcessor::PlugProcessor()
{
    setControllerClass(MyControllerUID);
}

tresult PlugProcessor::initialize(FUnknown *context)
{
    tresult result = AudioEffect::initialize(context);

    if (result != kResultTrue)
        return kResultFalse;

    addAudioInput(STR16("AudioInput"), Vst::SpeakerArr::kStereo);
    addAudioInput(STR16("AudioInput"), Vst::SpeakerArr::kStereo);
    return kResultTrue;
}

// we only support one in and output bus and these buses must have the same number of channels
tresult PlugProcessor::setBusArrangements(Steinberg::Vst::SpeakerArrangement *inputs,
                                          Steinberg::int32 numIns,
                                          Steinberg::Vst::SpeakerArrangement *outputs,
                                          Steinberg::int32 numOuts)
{
    if (numIns == 1 && numOuts == 1 && inputs[0] == outputs[0])
        return AudioEffect::setBusArrangements (inputs, numIns, outputs, numOuts);
    return kResultFalse;
}

// here you get, with setup, information about:
// sampleRate, processMode, maximum number of samples per audio block
tresult PlugProcessor::setupProcessing(Vst::ProcessSetup& setup)
{
    return AudioEffect::setupProcessing(setup);
}

tresult PlugProcessor::setActive(TBool state)
{
    if (state) // Initialize
    {
        // Allocate Memory Here
        // Ex: algo.create ();
    }
    else // Release
    {
        // Free Memory if still allocated
        // Ex: if(algo.isCreated ()) { algo.destroy (); }
    }
    return AudioEffect::setActive (state);
}

tresult PlugProcessor::process(Vst::ProcessData &data)
{
    	//--- Read inputs parameter changes-----------
	if (data.inputParameterChanges)
	{
		int32 numParamsChanged = data.inputParameterChanges->getParameterCount ();
		for (int32 index = 0; index < numParamsChanged; index++)
		{
			Vst::IParamValueQueue* paramQueue = data.inputParameterChanges->getParameterData (index);
			if (paramQueue) {
				Vst::ParamValue value;
				int32 sampleOffset;
				int32 numPoints = paramQueue->getPointCount ();
				switch (paramQueue->getParameterId ()) {
					case BasicParams::kParamVolId:
						if (paramQueue->getPoint (numPoints - 1, sampleOffset, value) ==
						    kResultTrue)
							m_param1 = value;
						break;
					case BasicParams::kParamOnId:
						if (paramQueue->getPoint (numPoints - 1, sampleOffset, value) ==
						    kResultTrue)
							m_param2 = value > 0 ? 1 : 0;
						break;
					case BasicParams::kBypassId:
						if (paramQueue->getPoint (numPoints - 1, sampleOffset, value) ==
						    kResultTrue)
							m_bypass = (value > 0.5f);
						break;
				}
			}
		}
    }
        // Process Audio Here
        if (data.numInputs == 0  || data.numOutputs == 0)   //nothing todo
            return kResultOk;
        if (data.numSamples > 0) {
            // process algorithm
            // Ex: algo.process (data.inputs[0].channelBuffers32, data.outputs[0].channelBuffers32,
            // data.numSamples);
        }
        return kResultOk;
}

tresult PlugProcessor::setState(IBStream *state)
{
    if (!state)
        return kResultFalse;

    // called when we load a preset or project, the model has to be reloaded
    IBStreamer streamer (state, kLittleEndian);

    float savedParam1 = 0.f;
    if (streamer.readFloat (savedParam1) == false)
        return kResultFalse;

    int32 savedParam2 = 0;
    if (streamer.readInt32 (savedParam2) == false)
        return kResultFalse;

    int32 savedBypass = 0;
    if (streamer.readInt32 (savedBypass) == false)
        return kResultFalse;

    m_param1 = savedParam1;
    m_param2 = savedParam2 > 0 ? 1 : 0;
    m_bypass = savedBypass > 0;

    return kResultOk;
}

tresult PlugProcessor::getState(IBStream *state)
{
    // here we need to save the model (preset or project)
    float toSaveParam1 = m_param1;
    int32 toSaveParam2 = m_param2;
    int32 toSaveBypass = m_bypass ? 1 : 0;

    IBStreamer streamer (state, kLittleEndian);
    streamer.writeFloat (toSaveParam1);
    streamer.writeInt32 (toSaveParam2);
    streamer.writeInt32 (toSaveBypass);

    return kResultOk;
}


