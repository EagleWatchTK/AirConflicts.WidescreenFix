#pragma once

#include <cstdint>

namespace Address
{
    constexpr uintptr_t ResolutionHook   = 0x0043151D;

    constexpr uintptr_t ResolutionWidth  = 0x0060DB70;
    constexpr uintptr_t ResolutionHeight = 0x0060DB74;

    constexpr uintptr_t WidthPreset1600  = 0x0043150F;
    constexpr uintptr_t HeightPreset1200 = 0x00431519;
}