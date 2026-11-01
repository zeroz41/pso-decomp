#include "types.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

u32 TLobby__sub_8002058C(u32, s32, void *, void *, s32, s32, s32);

void TAdSinglePlyChrSelectGC::start_character_load_task() {
    u32 var_r31;

    if ((TLobby::tmp_buf_is_free() != 0) && (this->try_acquire_slot() != 0)) {
        var_r31 = (int)::operator new(0x440);
        if (var_r31 != 0U) {
            var_r31 = TLobby__sub_8002058C(var_r31, 6, ((u8 *)this) + 0x60, ((u8 *)this) + 0x64, 0, 0, ((TLobby *)(this->m_24))->start_load_default());
        }
        *(u32 *)((s8 *)((u8 *)this) + 0x68) = var_r31;
        if (var_r31 != 0U) {
            *(s32 *)((s8 *)((u8 *)this) + 0x74) = 0x12C;
            this->m_2c = 1;
        }
    }
}

}
