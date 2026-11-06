#include "types.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdEp3Exist.h"

extern "C" {

s32 TAdEp3Exist__sub_8036F574();

s32 TLobby::destroy_ep3_exist(s32 arg0, s16 arg1) {
    if (arg0 != 0) {
        TAdEp3Exist::free_if_valid(arg0, 0);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

void *TLobby::reset_counters() {
    TAdEp3Exist__sub_8036F574();
    this->m_up = 0;
    this->m_down = 0;
    *(s32 *)((s8 *)this + 0x18) = 0;
    *(s32 *)((s8 *)this + 0x1C) = 0;
    *(s32 *)((s8 *)this + 0x20) = 0;
    *(s32 *)((s8 *)this + 0x24) = 0;
    *(s32 *)((s8 *)this + 0x28) = 0;
    *(s32 *)((s8 *)this + 0x2C) = 0;
    return this;
}

}
