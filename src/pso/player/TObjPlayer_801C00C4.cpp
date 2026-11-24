#include "types.h"
#include "pso/unk/TUnk_804DDD28.h"
#include "pso/player/PlayerTechniqueState.h"
#include "pso/player/TObjPlayer.h"

struct O_801C0124 { u8 pad[0x48]; u8 arr[1]; };

extern "C" {
u8 TObjPlayer__sub_801C010C(PlayerTechniqueState *techs, s16 technique);
u8 TObjPlayer__sub_801C0124(O_801C0124 *techs, s16 technique);
void set_field_0_s32(void*, s32);

void TObjPlayer::forward_801C210C(void *provider, int id) { set_field_0_s32(provider, id); }

extern int player_action_provider_selector;

u8 is_action_id_none(s32 animation_number) {
    return (u8) (animation_number == -1);
}

int TObjPlayer::get_hold_effect_count() { return player_action_provider_selector; }

int TUnk_804DDD28::vfunc_7(s32, s32) { return 0; }
BmlMotionEntry *TUnk_804DDD28::vfunc_76() { return NULL; }

u8 TObjPlayer__sub_801C010C(PlayerTechniqueState *techs, s16 technique) {
    return techs->levels[technique];
}

void PlayerTechniqueState::set_technique_id(s16 v) { technique = v; }

u8 TObjPlayer__sub_801C0124(O_801C0124 *techs, s16 technique) {
    return techs->arr[technique];
}

u8 TObjPlayer::get_item_count_max() { return 255; }

}
