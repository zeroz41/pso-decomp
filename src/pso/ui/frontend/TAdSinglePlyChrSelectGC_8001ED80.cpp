#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResource.h"

SystemSaveData *TAdSinglePlyChrSelectGC::get_global_state() {
    return system_save_payload;
}

s32 BmlResource::get_arena_offset() { return arena_offset; }
