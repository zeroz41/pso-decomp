#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer.h"

struct T_803131B4 { u8 pad[0x8]; s32 arr[1]; };

struct Ids_80313138 { u16 a; s16 b; };

extern "C" {
s32 *TObjPlayer__sub_803131B4(T_803131B4 *self, s32 i);
int test_flags_any(void*, int);
int TObjPlayer__sub_801AA64C(void* a0 = 0);
int set__8FlagWordFUl(void*, int);

void TObjPlayer::update_children() { { int n = TObjPlayer::get_max_children(this); int i; for (i = 0; i < n; i++) { TObjPlayer__sub_801AA64C((char*)this + 0x8 + i * 4); } } }

s16 TObjPlayer__sub_80313114(u8 *arg0) {
    s16 temp_r3;
    temp_r3 = *(s16 *)((s8 *)arg0 + 2);
    if (((temp_r3 < 0) || (temp_r3 >= 6)) && (temp_r3 != -1)) {
        return 0;
    }
    return temp_r3;
}

void TObjPlayer::reset_id_entry() {
    Ids_80313138 *o = (Ids_80313138 *)this;
    o->a = 0xFFFF;
    o->b = -1;
    ((FlagWord *)((u8 *)o + 4))->reset();
    update_children();
}

int TObjPlayer::query_field40() { return test_flags_any((char*)this + 0x40, 4); }
int TObjPlayer__sub_803131AC(void) { return 4; }

s32 *TObjPlayer__sub_803131B4(T_803131B4 *self, s32 i) {
    return &self->arr[i];
}

void TObjPlayer::process_indexed_element(s32 arg1) {
    s32 arg0 = (s32)this;
    ((TObjPlayer *)(arg0 + (arg1 * 0x18)))->reset_id_entry();
}

int TObjPlayer::check_flag_at_4() { return set__8FlagWordFUl((char*)this + 0x4, 1); }
int TObjPlayer__sub_80313218(void* p) { return (test_flags_any((char*)p + 0x4, 1)) == 0; }
void TObjPlayer::set_field_0(s16 v) { *(s16*)((char*)this + 0x0) = v; }
void TObjPlayer__sub_80313250(void *arg0, s32 arg1) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) + arg1);
}
int TObjPlayer::get_max_children(void*) { return 4; }

}
