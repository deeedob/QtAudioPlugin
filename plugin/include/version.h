#pragma once

#include <pluginterfaces/base/fplatform.h>

#define MAJOR_VERSION_STR "1"
#define MAJOR_VERSION_INT 1

#define SUB_VERSION_STR "1"
#define SUB_VERSION_INT 1

#define RELEASE_NUMBER_STR "0"
#define RELEASE_NUMBER_INT 0

#define BUILD_NUMBER_STR "1" // Build number to be sure that each result could identified.
#define BUILD_NUMBER_INT 1

// Version with build number (example "1.0.3.342")
#define FULL_VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR "." BUILD_NUMBER_STR

// Version without build number (example "1.0.3")
#define VERSION_STR MAJOR_VERSION_STR "." SUB_VERSION_STR "." RELEASE_NUMBER_STR

#define stringOriginalFilename  "basic.vst3"
#define stringPluginName		"Basic"
#if SMTG_PLATFORM_64
    #define stringFileDescription	stringPluginName"Basic VST3 (64Bit)"
#else
    #define stringFileDescription	stringPluginName"Basic VST3"
#endif

#define stringCompanyName		"Dennis Oberst"
#define stringCompanyWeb		"https://0xcafe.net"
#define stringCompanyEmail		"mailto:ddob@gmail.com"
#define stringLegalCopyright	"� 2022 Dennis Oberst"
#define stringLegalTrademarks	""
