#include <windows.h>

#include "Logger.h"
#include "ini.h"

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

        break;
    }

    return TRUE;
}