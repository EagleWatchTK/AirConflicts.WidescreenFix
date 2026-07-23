#include "Hook.h"

#include <windows.h>

#include <cstring>

#include "Logger.h"

void SaveOriginalBytes(Hook& hook)
{
    memcpy(hook.Original, hook.Address, 5);

    Log("Original bytes saved.");
}

bool WriteJump(void* from, void* to)
{
    DWORD offset =
        (DWORD)to - (DWORD)from - 5;

    BYTE patch[5];

    patch[0] = 0xE9;

    *(DWORD*)&patch[1] = offset;

    DWORD oldProtect;

    if (!VirtualProtect(from, 5,
        PAGE_EXECUTE_READWRITE,
        &oldProtect))
    {
        Log("VirtualProtect failed.");
        return false;
    }

    memcpy(from, patch, 5);

    VirtualProtect(from, 5,
        oldProtect,
        &oldProtect);

    FlushInstructionCache(
        GetCurrentProcess(),
        from,
        5);

    Log("Jump written.");

    return true;
}

bool InstallHook(Hook& hook)
{
    Log("Installing hook...");

    if (!WriteJump(
        hook.Address,
        hook.Destination))
    {
        return false;
    }

    hook.Installed = true;

    Log("Hook installed.");

    return true;
}