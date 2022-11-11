cmake_minimum_required(VERSION 3.24)

project(custom_vst
        VERSION 1.0.0
        DESCRIPTION "VST3 Basic Example"
        )

option(SMTG_ADD_VST3_PLUGINS_SAMPLES "Add VST3 Plug-ins Samples to the solution" ON)
option(SMTG_ADD_VSTGUI "Add VSTGUI Support" ON)

set(ROOT "${CMAKE_CURRENT_SOURCE_DIR}/3rdParty/vst3sdk")
set(SDK_ROOT "${ROOT}")
set(SDK_BASE "${SDK_ROOT}/base")
set(SDK_CMAKE "${SDK_ROOT}/cmake")
set(SDK_PLUGINTERFACES "${SDK_ROOT}/pluginterfaces")
set(SDK_PUBLIC "${SDK_ROOT}/public.sdk")
set(SDK_GUI "${SDK_ROOT}/vstgui4")

list(APPEND CMAKE_MODULE_PATH "${SDK_CMAKE}/modules")

include(SMTG_VST3_SDK)
smtg_setup_platform_toolset()
set(SDK_IDE_LIBS_FOLDER FOLDER "Libraries")

set(public_sdk_SOURCE_DIR "${SDK_PUBLIC}")
set(pluginterfaces_SOURCE_DIR "${SDK_PLUGINTERFACES}")

if(SMTG_ADD_VSTGUI)
    smtg_enable_vstgui_support(VSTGUI_SOURCE_DIR "${SDK_GUI}")
endif(SMTG_ADD_VSTGUI)

# add base libraries
set(VST_SDK ON)
include_directories(${ROOT} ${SDK_ROOT})
add_subdirectory(${SDK_BASE})
add_subdirectory(${SDK_PLUGINTERFACES})
add_subdirectory(${SDK_PUBLIC})
#add_subdirectory(${SDK_GUI})

# Add hosting examples, it includes the validator (must be done before any plug-ins to support running the validator after building)
set(SDK_IDE_HOSTING_EXAMPLES_FOLDER FOLDER "HostingExamples")
add_subdirectory(${SDK_ROOT}/public.sdk/samples/vst-hosting)

# Add utilities
set(SDK_IDE_UTILITIES_FOLDER FOLDER "Utilities")
add_subdirectory(${SDK_PUBLIC}/samples/vst-utilities)

add_subdirectory(example)
add_subdirectory(plugin)
add_subdirectory(widgets-gui)