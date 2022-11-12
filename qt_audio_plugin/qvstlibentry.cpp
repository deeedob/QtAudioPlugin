// We need to start a QApplication when the shared library is loaded
#include "qvstapplication.h"

#ifdef HAVE_WINDOWS
    BOOL APIENTRY DllMain( HMODULE hModule,
                           DWORD  ul_reason_for_call,
                           LPVOID lpReserved)
    {
        switch (ul_reason_for_call)
        {
        case DLL_PROCESS_ATTACH:
            printf("DllMain, DLL_PROCESS_ATTACH\n");
            break;
        case DLL_THREAD_ATTACH:
            printf("DllMain, DLL_THREAD_ATTACH\n");
            break;
        case DLL_THREAD_DETACH:
            printf("DllMain, DLL_THREAD_DETACH\n");
            break;
        case DLL_PROCESS_DETACH:
            printf("DllMain, DLL_PROCESS_DETACH\n");
            break;
        default:
            printf("DllMain, ????\n");
            break;
        }
        return TRUE;
    }
    #else //Unix, Linux etc
    #ifdef __cplusplus
    extern "C" {
    #endif
        // gets called when the shared library gets loaded
        __attribute__((constructor))
        static void initializer(int argc, char** argv, char** envp)
        {
            QVstApplication::Flags flags = QVstApplication::Flag_None;
            #ifdef QVST_CONSOLE
                flags |= QVstApplication::Flag_CreateConsole;
            #endif
            //QVstApplication::createInstance();
            //QApplication app(argc, argv);
            //app.exec();
        }
        // gets called after shared lib exit
        __attribute__((destructor))
        static void finalizer()
        {
            delete qApp;
        }

    #ifdef __cplusplus
    };
    #endif
#endif
