#pragma once

namespace config{
    inline constexpr bool vsync_active = 
    #ifdef USE_VSYNC
        true;
    #else
        false;
    #endif
}
