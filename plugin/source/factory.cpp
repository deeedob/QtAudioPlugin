#include <public.sdk/source/main/pluginfactory.h>
#include "plugin_controller.h"
#include "plugin_processor.h"
#include "../include/ids.h"
#include "../include/version.h"

#define stringSubCategory	"Fx"	// Subcategory for this Plug-in (to be changed if needed, see PlugType in ivstaudioprocessor.h)

BEGIN_FACTORY_DEF (stringCompanyName, stringCompanyWeb,	stringCompanyEmail)

        DEF_CLASS2 (INLINE_UID_FROM_FUID(ProcessorUID),
                    PClassInfo::kManyInstances,	// cardinality
                    kVstAudioEffectClass,	// the component category (do not changed this)
                    stringPluginName,		// here the Plug-in name (to be changed)
                    Vst::kDistributable,	// means that component and controller could be distributed on different computers
                    stringSubCategory,		// Subcategory for this Plug-in (to be changed)
                    FULL_VERSION_STR,		// Plug-in version (to be changed)
                    kVstVersionString,		// the VST 3 SDK version (do not changed this, use always this define)
                    PluginProcessor::createInstance)	// function pointer called when this component should be instantiated

        DEF_CLASS2 (INLINE_UID_FROM_FUID(ControllerUID),
                    PClassInfo::kManyInstances,  // cardinality
                    kVstComponentControllerClass,// the Controller category (do not changed this)
                    stringPluginName "Controller",	// controller name (could be the same than component name)
                    0,						// not used here
                    "",						// not used here
                    FULL_VERSION_STR,		// Plug-in version (to be changed)
                    kVstVersionString,		// the VST 3 SDK version (do not changed this, use always this define)
                    PluginController::createInstance)// function pointer called when this component should be instantiated

END_FACTORY
