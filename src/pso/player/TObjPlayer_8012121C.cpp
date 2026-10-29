#include "types.h"
#include "pso/player/TObjPlayer_8012121C.h"
#include "pso/player/TObjPlayer.h"

int TObjPlayer::is_flag_b0_4() { return this->motion_flags & 0x4; }
void TObjPlayer__sub_80121228(void* p, u32 v) { *(u32*)((char*)p + 0x28) |= v; }
s16 get_captured_target_collider_index(void* p) { return *(s16*)((char*)p + 0x2); }
u16 TObjPlayer::get_uid() { return *(u16*)((char*)this + 0x0); }

struct Obj_80121248 { u8 pad[0x4]; s32 arr[1]; };

extern "C" {
s32 *get_captured_target_entry(Obj_80121248 *self, s32 i);

s32 *get_captured_target_entry(Obj_80121248 *self, s32 i) {
    return &self->arr[i];
}

s32 get_captured_target_count(s32 *arg0) {
    s32 temp_r3;
    temp_r3 = *arg0;
    if ((temp_r3 < 0) || (temp_r3 > 0xA)) {
        return 0;
    }
    return temp_r3;
}

}
