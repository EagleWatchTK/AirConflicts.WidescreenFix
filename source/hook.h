#pragma once

#include <windows.h>

struct Hook
{
    BYTE Original[5];

    void* Address;
    void* Destination;
    void* Trampoline;

    bool Installed;
};

void SaveOriginalBytes(Hook& hook);
bool InstallHook(Hook& hook);
bool WriteJump(void* from, void* to);