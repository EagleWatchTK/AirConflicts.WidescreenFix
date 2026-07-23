#include "Memory.h"
#include "Ini.h"

void PatchResolution()
{
    *(int*)0x0060DB70 = gResolution.Width;
    *(int*)0x0060DB74 = gResolution.Height;
}