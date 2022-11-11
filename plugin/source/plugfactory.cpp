#include <public.sdk/source/main/pluginfactory.h>
#include "plugcontroller.h"
#include "plugprocessor.h"
#include "../include/plugids.h"
#include "../include/version.h"

#define stringSubCategory	"Fx"	// Subcategory for this Plug-in (to be changed if needed, see PlugType in ivstaudioprocessor.h)

BEGIN_FACTORY_DEF (stringCompanyName, stringCompanyWeb,	stringCompanyEmail)

        DEF_CLASS2 (INLINE_UID_FROM_FUID(Steinberg::Basic::MyProcessorUID),
                    PClassInfo::kManyInstances,	// cardinality
                    kVstAudioEffectClass,	// the component category (do not changed this)
                    stringPluginName,		// here the Plug-in name (to be changed)
                    Vst::kDistributable,	// means that component and controller could be distributed on different computers
                    stringSubCategory,		// Subcategory for this Plug-in (to be changed)
                    FULL_VERSION_STR,		// Plug-in version (to be changed)
                    kVstVersionString,		// the VST 3 SDK version (do not changed this, use always this define)
                    Steinberg::Basic::PlugProcessor::createInstance)	// function pointer called when this component should be instantiated

        DEF_CLASS2 (INLINE_UID_FROM_FUID(Steinberg::Basic::MyControllerUID),
                    PClassInfo::kManyInstances,  // cardinality
                    kVstComponentControllerClass,// the Controller category (do not changed this)
                    stringPluginName "Controller",	// controller name (could be the same than component name)
                    0,						// not used here
                    "",						// not used here
                    FULL_VERSION_STR,		// Plug-in version (to be changed)
                    kVstVersionString,		// the VST 3 SDK version (do not changed this, use always this define)
                    Steinberg::Basic::PlugController::createInstance)// function pointer called when this component should be instantiated

END_FACTORY
