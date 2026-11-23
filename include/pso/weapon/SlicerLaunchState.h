#ifndef PSO_WEAPON_SLICERLAUNCHSTATE_H
#define PSO_WEAPON_SLICERLAUNCHSTATE_H
#include "types.h"
#include <dolphin/mtx.h>
#include "pso/system/NinjaTypes.h"

// What a slicer-type weapon's emit_marker_effects fills in and hands to
// TTecSlicer::create (0x48 bytes on the stack of TUnk_804A4238/4338/5A28/
// 5B20/64E8/ECDC0 and TItemEffPG_8034EFDC). The fields are the ones
// TTecSlicer copies into its own playerId..spinVelocity block; the struct
// name is inferred from init_slicer_launch_state.
struct SlicerLaunchState {
    u16 player_id;           // get_entity_id(owner), 0xFFFF for none
    u8 pad_2[2];
    NJS_TEXLIST *texlist;    // the weapon's texture list
    NJS_OBJECT *model;       // the weapon's second_model
    s32 item_id;             // get_item_id(), -1 for none
    s16 attack_kind;         // -1 for none
    s16 combo_stage;         // get_validated_attack_stage, -1 for none
    f32 damage_multiplier;   // query_extended_state, 1.0 by default
    NJS_ARGB color;          // get_weapon_color, all 0.0 by default
    s32 facing;              // the owner's rotation_y
    s32 spin_velocity;       // -0x2AAA by default
    Vec first_joint;         // get_joint_position results
    Vec second_joint;
};

// The defaults of a SlicerLaunchState. TUnk_804A4238.cpp keeps the copy the
// game links; TUnk_804A5B20's TU compiled this inline body too:
// its literal pool opens with these 1.0/0.0, emitted with the weak copy right
// after emit_marker_effects, ahead of update_idle's literals.
#ifndef SLICER_LAUNCH_STATE_OUT_OF_LINE
inline void init_slicer_launch_state(void *state) {
    SlicerLaunchState *s = (SlicerLaunchState *)state;
    s->player_id = 0xFFFF;
    s->item_id = -1;
    s->texlist = 0;
    s->attack_kind = -1;
    s->combo_stage = -1;
    s->damage_multiplier = 1.0f;
    s->color.b = 0.0f;
    s->color.g = 0.0f;
    s->color.r = 0.0f;
    s->color.a = 0.0f;
    s->spin_velocity = -0x2AAA;
}
#else
void init_slicer_launch_state(void *state);
#endif

#endif
