#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H

#include "types.h"

struct NJS_OBJECT;
struct GinjaTextureList;

struct TBoss5Gryphon;
struct TBoss8Dragon;
extern "C" {
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2);
void TBoss8Dragon__sub_8005E17C(NJS_OBJECT *);
void apply_lightning_hit(s32 owner, s32 pos, f32 inner);
void apply_tornado_hit(s32 owner, saddr pos);
void apply_shockwave_hit(s32 owner, s32 pos);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
}
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon);
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon);
extern "C" {
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void run_task__13TBoss5GryphonFv(u8 *arg0);
}

struct BmlResource;

// Gal Gryphon's particle model archive and texture list, loaded with the boss.
extern BmlResource *boss5_gryphon_bml_resource;
extern GinjaTextureList *boss5_gryphon_texture_list;

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
extern const f32 lbl_805D8DC0;
extern const f32 lbl_805D8DC4;
extern const f32 lbl_805D8DC8;
extern const f32 gryphon_four;
extern const f32 gryphon_fifty;
extern const f32 lbl_805D8DD4;
extern const f32 lbl_805D8DD8;
extern const f32 gryphon_seven;
extern const f32 lbl_805D8DE0;
extern const f32 gryphon_seventeen;
extern const f32 lbl_805D8DE8;
extern const f32 lbl_805D8DEC;
extern const f32 gryphon_sixty;
extern const f32 gryphon_twenty_five;
extern const f32 gryphon_five;
extern const f32 gryphon_nineteen;
extern const f32 gryphon_fifteen;
extern const f32 gryphon_three_quarters;
extern const f32 lbl_805D8E08;
extern const f32 gryphon_eleven;
extern const f32 gryphon_ten;
extern const f32 gryphon_nine;
extern const f32 lbl_805D8E18;
extern const f32 lbl_805D8E1C;
extern const f32 gryphon_sixty_seven;
extern const f32 lbl_805D8E24;
extern const f32 gryphon_quarter_turn;
extern const f32 lbl_805D8E2C;
extern const f32 lbl_805D8E30;
extern const f32 gryphon_quarter;
extern const f32 gryphon_one_and_half;
extern const f32 lbl_805D8E3C;
extern const f32 lbl_805D8E40;
extern const f32 lbl_805D8E44;
extern const f32 lbl_805D8E48;
extern const f32 lbl_805D8E4C;
extern const f32 lbl_805D8E50;
extern const f32 gryphon_negative_four;
extern const f32 lbl_805D8E58;
extern const f32 gryphon_eighteen;
extern const f32 gryphon_sixty_eight;
extern const f32 lbl_805D8E64;
extern const f32 lbl_805D8E68;
extern const f32 lbl_805D8E6C;
extern const f32 lbl_805D8E70;
extern const f32 lbl_805D8E74;
extern const f32 lbl_805D8E78;
extern const f32 lbl_805D8E7C;
extern const f32 lbl_805D8E80;
extern const f32 lbl_805D8E84;
extern const f32 gryphon_negative_thirty;
extern const f32 lbl_805D8E8C;
extern const f32 lbl_805D8E90;
extern const f32 gryphon_twenty_three;
extern const f32 gryphon_twenty_four;
extern const f32 lbl_805D8E9C;
extern const f32 lbl_805D8EA0;
extern const f32 lbl_805D8EA4;
extern const f32 gryphon_twenty_seven;
extern const f32 gryphon_thirty;
extern const f32 gryphon_twenty_eight;
extern const f32 lbl_805D8EB4;
extern const f32 gryphon_seventy;
extern const f32 gryphon_fourteen;
extern const f32 gryphon_twenty_one;
extern const f32 lbl_805D8EC4;
extern const f32 gryphon_thousand;

#endif
