#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H

#include "types.h"

struct NJS_OBJECT;
struct GinjaTextureList;

struct TBoss5Gryphon;
struct TBoss8Dragon;
extern "C" {
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
}
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon);
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon);
extern "C" {
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
}

struct BmlResource;

// Gal Gryphon's particle model archive and texture list, loaded with the boss.
extern BmlResource *boss5_gryphon_bml_resource;
extern GinjaTextureList *boss5_gryphon_texture_list;

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
