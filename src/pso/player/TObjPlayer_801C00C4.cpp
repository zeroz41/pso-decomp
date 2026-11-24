#include "types.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void set_field_0_s32(void*, s32);

void TObjPlayer::forward_801C210C(void *provider, int id) { set_field_0_s32(provider, id); }

u8 is_action_id_none(s32 animation_number) {
    return (u8) (animation_number == -1);
}

}

int get_player_action_provider_selector() { return player_action_provider_selector; }

extern "C" {

int PlayerActionProvider::vfunc_7(s32, s32) { return 0; }
BmlMotionEntry *PlayerActionProvider::vfunc_76() { return NULL; }

u8 TObjPlayer__sub_801C010C(const PlayerTechniqueState *techs, s16 technique) {
    return techs->levels[technique];
}

void PlayerTechniqueState::set_technique_id(s16 v) { technique = v; }

u8 TObjPlayer__sub_801C0124(const PlayerTechniqueState *state, s16 i) {
    return state->learned_levels[i];
}

u8 TObjPlayer::get_item_count_max() { return 255; }

}
