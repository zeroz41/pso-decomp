#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

u8 *TAdSinglePlyChrSelectGC::get_global_state() {
    return (u8 *)system_save_payload;
}

s32 TLobby__sub_8001ED88(void* p) { return *(s32*)((char*)p + 0x428); }
