#include "Trampoline.h"

#include <windows.h>
#include <cstring>

#include "Logger.h"

bool CreateTrampoline(Hook& hook)
{
    BYTE* code = (BYTE*)VirtualAlloc(
        nullptr,
        32,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE);

    if (!code)
    {
        Log("VirtualAlloc failed.");
        return false;
    }

    hook.Trampoline = code;

    LogAddress("Trampoline =", code);

    // Copy the overwritten instructions
    memcpy(code, hook.Original, 5);

    // Build a JMP back to the original code
    BYTE* jump = code + 5;

    jump[0] = 0xE9;

    DWORD returnAddress =
        (DWORD)hook.Address + 5;

    DWORD offset =
        returnAddress -
        ((DWORD)jump + 5);

    *(DWORD*)(jump + 1) = offset;

    Log("Trampoline built.");

    LogHex("Trampoline bytes:", code, 10);

    return true;
}