#include <windows.h>
#include <cstring>

void WriteMemory(void* address, const void* data, int size)
{
    DWORD oldProtect;

    VirtualProtect(address, size, PAGE_EXECUTE_READWRITE, &oldProtect);

    memcpy(address, data, size);

    VirtualProtect(address, size, oldProtect, &oldProtect);

    FlushInstructionCache(GetCurrentProcess(), address, size);
}