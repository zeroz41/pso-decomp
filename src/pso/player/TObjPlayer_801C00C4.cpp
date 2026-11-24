#include "types.h"
#include "pso/player/TObjPlayer_801C00C4.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void set_field_0_s32(void*, s32);

void TObjPlayer::forward_801C210C(void *p, int v) { set_field_0_s32(p, v); }

    extern int player_action_provider_selector;

u8 is_action_id_none(s32 animation_number) {
    return (u8) (animation_number == -1);
}

int TObjPlayer::get_hold_effect_count() {  return player_action_provider_selector; }

int TUnk_804DDD28::vfunc_7(s32, s32) { return 0; }
BmlMotionEntry *TUnk_804DDD28::vfunc_76() { return NULL; }

u8 TObjPlayer__sub_801C010C(const PlayerTechniqueState *state, s32 technique) {
    return state->levels[(s16)technique];
}

void PlayerTechniqueState::set_technique_id(s16 v) { technique = v; }

u8 TObjPlayer__sub_801C0124(const PlayerTechniqueState *state, s16 i) {
    return state->learned_levels[i];
}

u8 TObjPlayer::get_item_count_max() { return 255; }

}
