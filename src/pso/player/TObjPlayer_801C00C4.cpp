#include "types.h"
#include "pso/player/TObjPlayer_801C00C4.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/player/TObjPlayer.h"

struct O_801C010C { u8 pad[0x5c]; u8 arr[1]; };

struct O_801C0124 { u8 pad[0x48]; u8 arr[1]; };

extern "C" {
u8 TObjPlayer__sub_801C010C(O_801C010C *self, s16 i);
u8 TObjPlayer__sub_801C0124(O_801C0124 *self, s16 i);
int TObjPlayer__sub_801C210C(void*);

int TObjPlayer::forward_801C210C() { return TObjPlayer__sub_801C210C(this); }

    extern int player_action_provider_selector;

u8 is_action_id_none(s32 arg0) {
    return (u8) (arg0 == -1);
}

int TObjPlayer::get_hold_effect_count() {  return player_action_provider_selector; }

int TUnk_804DDD28::vfunc_7(s32, s32) { return 0; }
int TUnk_804DDD28::vfunc_76() { return 0; }

u8 TObjPlayer__sub_801C010C(O_801C010C *self, s16 i) {
    return self->arr[i];
}

void TObjPlayer::set_technique_id(s16 v) { this->m_flags = v; }

u8 TObjPlayer__sub_801C0124(O_801C0124 *self, s16 i) {
    return self->arr[i];
}

int TObjPlayer::get_item_count_max() { return 255; }

}
