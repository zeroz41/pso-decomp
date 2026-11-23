#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H

#include "types.h"

struct NJS_OBJECT;
struct Vec;
struct NJS_TEXLIST;

struct TBoss5Gryphon;
void handle_6x9F_gal_gryphon_boss_actions(void *data);
void handle_6xA0_gal_gryphon_boss_actions(void *data);
// The follow camera offsets for the Gal Gryphon arena: the running gryphon's flight mode ones,
// or the default pair before it exists.
void get_gryphon_follow_camera_offsets(Vec *target_offset, Vec *eye_offset);

struct BmlResource;

// Block 0x20 of the gryphon's parameters (boss5_gryphon_behavior_params[2]).
struct Boss5GryphonAttackParams {
    f32 snarl_power;          // apply_snarl_hit, times its scale
    f32 shockwave_power;      // apply_shockwave_hit
    f32 tornado_power;        // apply_tornado_hit
    f32 lightning_power;      // apply_lightning_hit
    f32 landing_radius;       // emit_landing_impact
    f32 pad_14;
    s32 collider_5_value;     // update_body_colliders gives it to bodies[5].unk_28
    s32 collider_1_4_value;   // bodies[1..4].unk_28
    s32 collider_0_value;     // bodies[0].unk_28
    s32 collider_6_9_value;   // bodies[6..9].unk_28
    s32 action_level;         // indexes the action probability tables; unlocks scripts and lightning
    s32 pad_2C;
};

// One of the gryphon's parameter blocks: TLobby::dispatch_shared_handler_a of
// boss5_gryphon_behavior_param_ids (0x1E, 0x1F, 0x20). The first two lead with the follow camera's
// (y, z) target offset and eye offset pairs per flight mode, one run of twelve floats over both
// (fill_follow_camera_params).
union Boss5GryphonParams {
    f32 camera[6];
    Boss5GryphonAttackParams attack;
};

extern Boss5GryphonParams *boss5_gryphon_behavior_params[3];

// Gal Gryphon's particle model archive and texture list, loaded with the boss.
extern BmlResource *boss5_gryphon_bml_resource;
extern NJS_TEXLIST *boss5_gryphon_texture_list;

// The highest floor the gryphon's ground effects stand on: the lightning, wing and tornado
// floor probes clamp to it (and use it when there is no floor); a tornado is not spawned above it.
extern const f32 gryphon_max_floor_height;

// Gal Gryphon tuning constants (.sdata2 0x805D8D80..0x805D8ECC), defined in Boss5GryphonBehaviorSdata2.cpp.
extern const f32 gryphon_twelve;
extern const f32 gryphon_ground_height;
extern const f32 gryphon_one;
extern const f32 gryphon_forty;
extern const f32 gryphon_three;
extern const f32 gryphon_negative_thousand;
extern const f32 gryphon_random_unit_scale;
extern const f32 gryphon_u32_range;
extern const f32 gryphon_point_six;
extern const f32 gryphon_point_nine;
extern const f32 gryphon_point_three;
extern const f32 gryphon_point_four;
extern const f32 gryphon_point_eight;
extern const f32 gryphon_point_two;
extern const f32 gryphon_roar_frame;
extern const f32 gryphon_seventy_five;
extern const f32 gryphon_thirty_two_and_half;
extern const f32 gryphon_offscreen_drop;
extern const f32 gryphon_arena_radius_sq;
extern const f32 gryphon_four;
extern const f32 gryphon_fifty;
extern const f32 gryphon_three_hundred_sixty;
extern const f32 gryphon_three_quarter_turn;
extern const f32 gryphon_seven;
extern const f32 gryphon_dive_roll_scale;
extern const f32 gryphon_seventeen;
extern const f32 gryphon_point_two_eight;
extern const f32 gryphon_flight_height;
extern const f32 gryphon_sixty;
extern const f32 gryphon_twenty_five;
extern const f32 gryphon_five;
extern const f32 gryphon_nineteen;
extern const f32 gryphon_fifteen;
extern const f32 gryphon_three_quarters;
extern const f32 gryphon_point_eight_six;
extern const f32 gryphon_eleven;
extern const f32 gryphon_ten;
extern const f32 gryphon_nine;
extern const f32 gryphon_two_point_three;
extern const f32 gryphon_nineteen_and_half;
extern const f32 gryphon_sixty_seven;
extern const f32 gryphon_eighty_one_and_half;
extern const f32 gryphon_quarter_turn;
extern const f32 gryphon_five_64ths_turn;
extern const f32 gryphon_two_hundred_thirty;
extern const f32 gryphon_quarter;
extern const f32 gryphon_one_and_half;
extern const f32 gryphon_two_point_one;
extern const f32 gryphon_sixty_six_and_half;
extern const f32 gryphon_three_32nds_turn;
extern const f32 gryphon_one_hundred_sixteen_and_half;
extern const f32 gryphon_three_hundred;
extern const f32 gryphon_one_hundred_twenty;
extern const f32 gryphon_negative_four;
extern const f32 gryphon_three_and_half;
extern const f32 gryphon_eighteen;
extern const f32 gryphon_sixty_eight;
extern const f32 gryphon_two_hundred_ten;
extern const f32 gryphon_four_hundred_twenty;
extern const f32 gryphon_four_hundred_sixty_three;
extern const f32 gryphon_two_hundred_ninety;
extern const f32 gryphon_four_hundred_five;
extern const f32 gryphon_four_hundred_fifty_five;
extern const f32 gryphon_two_hundred_sixty_five;
extern const f32 gryphon_six_hundred;
extern const f32 gryphon_one_hundred_ten;
extern const f32 gryphon_negative_thirty;
extern const f32 gryphon_one_hundred_fifteen;
extern const f32 gryphon_four_hundred_eighty_four;
extern const f32 gryphon_twenty_three;
extern const f32 gryphon_twenty_four;
extern const f32 gryphon_twenty_and_half;
extern const f32 gryphon_one_hundred_fifty;
extern const f32 gryphon_point_one_five;
extern const f32 gryphon_twenty_seven;
extern const f32 gryphon_thirty;
extern const f32 gryphon_twenty_eight;
extern const f32 gryphon_one_point_eight;
extern const f32 gryphon_seventy;
extern const f32 gryphon_fourteen;
extern const f32 gryphon_twenty_one;
extern const f32 gryphon_offscreen_height;
extern const f32 gryphon_thousand;

#endif
