#include <windows.h>

#include "ResolutionHook.h"
#include "globals.h"
#include "Logger.h"

void ResolutionHookCpp(DWORD ecx)
{
    DWORD value18 = *(DWORD*)(ecx + 0x18);
    DWORD value1C = *(DWORD*)(ecx + 0x1C);
    DWORD value20 = *(DWORD*)(ecx + 0x20);
    DWORD value24 = *(DWORD*)(ecx + 0x24);

    char buffer[256];

    wsprintfA(
        buffer,
        "+18=%u +1C=%u +20=%u +24=%u",
        value18,
        value1C,
        value20,
        value24);

    Log(buffer);
}

extern "C" __declspec(naked) void ResolutionHook()
{
    __asm
    {
        pushfd
        pushad

        push ecx
        call ResolutionHookCpp
        add esp, 4

        popad
        popfd

        mov eax, dword ptr [g_ResolutionHook + 16]
        jmp eax
    }
}