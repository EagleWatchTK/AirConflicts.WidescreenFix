#include "Patches.h"

#include <windows.h>

#include "Addresses.h"
#include "Ini.h"
#include "Logger.h"

void PatchResolutionPreset()
{
    DWORD oldProtect;

    DWORD* width =
        (DWORD*)Address::WidthPreset1600;

    DWORD* height =
        (DWORD*)Address::HeightPreset1200;

    if (!VirtualProtect(width,
        sizeof(DWORD),
        PAGE_EXECUTE_READWRITE,
        &oldProtect))
    {
        Log("VirtualProtect failed (width).");
        return;
    }

    *width = (DWORD)gResolution.Width;

    VirtualProtect(width,
        sizeof(DWORD),
        oldProtect,
        &oldProtect);

    if (!VirtualProtect(height,
        sizeof(DWORD),
        PAGE_EXECUTE_READWRITE,
        &oldProtect))
    {
        Log("VirtualProtect failed (height).");
        return;
    }

    *height = (DWORD)gResolution.Height;

    VirtualProtect(height,
        sizeof(DWORD),
        oldProtect,
        &oldProtect);

    FlushInstructionCache(
        GetCurrentProcess(),
        nullptr,
        0);


    char buffer[128];

    wsprintfA(
        buffer,
        "Patched preset to %dx%d",
        gResolution.Width,
        gResolution.Height);

    Log(buffer);

}