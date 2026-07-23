#include <windows.h>
#include "Logger.h"
#include "ini.h"
#include "memory.h"
#include "Hook.h"
#include "Addresses.h"
#include "ResolutionHook.h"
#include "Trampoline.h"
#include "globals.h"
#include "Patches.h"

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD reason,
                      LPVOID reserved)
{
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:

        DisableThreadLibraryCalls(hModule);

        Log("================================");
        Log("Air Conflicts Widescreen Fix");
        Log("DLL loaded successfully.");

        LoadIni();

        PatchResolutionPreset();
        
        /*
        LogAddress("ResolutionHook =", (void*)&ResolutionHook);

        g_ResolutionHook.Address =
            (void*)Address::ResolutionHook;

        g_ResolutionHook.Destination =
            (void*)&ResolutionHook;

        SaveOriginalBytes(g_ResolutionHook);

        LogHex("Original bytes:",
            g_ResolutionHook.Original,
            5);

        CreateTrampoline(g_ResolutionHook);

        InstallHook(g_ResolutionHook);
        */

        break;
    }

    return TRUE;
}