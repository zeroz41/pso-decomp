#include "types.h"
#include "pso/player/TObjPlayer_801AA508.h"
#include "pso/player/TObjPlayer_801AA5C0.h"
#include "pso/system/memory.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

s32 __destroy_arr(s32, s32 *, s32, s32);

s16 TObjPlayer::get_evp() { return (this->evp); }
u16 TObjPlayer::get_section_id() { return *(u16*)((char*)this + 0x0); }
void TObjPlayer::set_field_2(s16 v) { *(s16*)((char*)this + 0x2) = v; }
void TObjPlayer::set_type(s16 v) { *(s16*)((char*)this + 0x0) = v; }
s32 TObjPlayer__sub_801AA528(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        __destroy_arr(arg0 + 8, (s32 *)TObjPlayer__sub_801AA584, 4, 4);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

}
