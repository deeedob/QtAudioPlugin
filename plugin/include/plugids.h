#pragma once

namespace Steinberg {
    namespace Basic {
        // HERE are defined the parameter Ids which are exported to the host
        enum BasicParams : Vst::ParamID
        {
            kBypassId = 100,

            kParamVolId = 102,
            kParamOnId = 1000
        };

        // HERE you have to define new unique class ids: for processor and for controller
        // you can use GUID creator tools like https://www.guidgenerator.com/
        static const FUID MyProcessorUID (0x41E3A6A2, 0xC1991743, 0xA64945DC, 0x3FB7D51D);
        static const FUID MyControllerUID (0xFAF056D1, 0x245C8945, 0x916485C6, 0x714C768E);
    }
}