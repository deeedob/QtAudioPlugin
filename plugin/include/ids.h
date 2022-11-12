#pragma once

#include <pluginterfaces/base/funknown.h>

enum {
    Param_Attack,
    Param_Decay,
    Param_Sustain,
    Param_Release,
    Param_Modulation,
    Param_Volume
};

// HERE you have to define new unique class ids: for processor and for controller
// you can use GUID creator tools like https://www.guidgenerator.com/
static const Steinberg::FUID ProcessorUID (0x41E3A6A2, 0xC1991743, 0xA64945DC, 0x3FB7D51D);
static const Steinberg::FUID ControllerUID (0xFAF056D1, 0x245C8945, 0x916485C6, 0x714C768E);