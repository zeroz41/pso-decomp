#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastResults.h"

struct T_803131B4 { u8 pad[0x8]; s32 arr[1]; };

struct Ids_80313138 { u16 a; s16 b; };

extern "C" {
s32 *TObjPlayer__sub_803131B4(T_803131B4 *self, s32 i);
s32 test_flags_any(s32 *flags, s32 mask);

void TObjPlayer::update_children() { { int n = TObjPlayer::get_max_children(this); int i; for (i = 0; i < n; i++) { ((PhotonBlastRequestSlot *)((char*)this + 0x8 + i * 4))->clear(); } } }

s16 PhotonBlastRequest::get_kind() {
    if ((kind < 0 || kind >= 6) && kind != -1) {
        return 0;
    }
    return kind;
}

void PhotonBlastRequest::reset() {
    Ids_80313138 *o = (Ids_80313138 *)this;
    o->a = 0xFFFF;
    o->b = -1;
    ((FlagWord *)((u8 *)o + 4))->reset();
    ((TObjPlayer *)this)->update_children();
}

int TObjPlayer::query_field40() { return test_flags_any((s32 *)((char*)this + 0x40), 4); }
int TObjPlayer__sub_803131AC(void) { return 4; }

s32 *TObjPlayer__sub_803131B4(T_803131B4 *self, s32 i) {
    return &self->arr[i];
}

void TObjPlayer::process_indexed_element(s32 arg1) {
    saddr arg0 = (saddr)this;
    ((PhotonBlastRequest *)(arg0 + (arg1 * 0x18)))->reset();
}

void TObjPlayer::check_flag_at_4() { ((FlagWord *)((char*)this + 0x4))->set(1); }
int TObjPlayer__sub_80313218(void* p) { return (test_flags_any((s32 *)((char*)p + 0x4), 1)) == 0; }
void TObjPlayer::set_field_0(s16 v) { *(s16*)((char*)this + 0x0) = v; }
void TObjPlayer__sub_80313250(void *arg0, s32 arg1) {
    *(s16 *)((s8 *)arg0 + 2) = (s16) (*(s16 *)((s8 *)arg0 + 2) + arg1);
}
int TObjPlayer::get_max_children(void*) { return 4; }

}
