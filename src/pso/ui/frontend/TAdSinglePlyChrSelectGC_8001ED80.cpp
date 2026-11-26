#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResource.h"

u8 *TAdSinglePlyChrSelectGC::get_global_state() {
    return (u8 *)system_save_payload;
}

s32 BmlResource::get_arena_offset() { return arena_offset; }
