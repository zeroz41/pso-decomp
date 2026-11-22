#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONBEHAVIOR_H

#include "types.h"

struct NJS_OBJECT;

struct TBoss5Gryphon;
struct TBoss8Dragon;
extern "C" {
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2);
void TBoss8Dragon__sub_8005E040(void *arg0);
void TBoss8Dragon__sub_8005E17C(NJS_OBJECT *);
s32 TBoss8Dragon__sub_8005E1E8(f32 farg0);
f32 TBoss8Dragon__sub_8005EAD0(void *arg0, void *arg1, int arg2);
s32 TBoss8Dragon__sub_8005FAE0(u8 *arg0);
void TBoss8Dragon__sub_8005FB90(u8 *arg0);
void TBoss8Dragon__sub_80063EF4(saddr arg0);
void apply_lightning_hit(s32 arg0, s32 arg1, f32 farg0);
void apply_tornado_hit(s32 arg0, saddr arg1);
void apply_shockwave_hit(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_800641A8(u8 *ene_dd);
void TBoss8Dragon__sub_8006435C(u8 *ene_dd);
void TBoss8Dragon__sub_800646F0(saddr arg0);
void TBoss8Dragon__sub_80064828(u8 *boss8_dragon);
void TBoss8Dragon__sub_800648C8(u8 *boss8_dragon);
void TBoss8Dragon__sub_80064DB8(u8 *boss5_gryphon);
void TBoss8Dragon__sub_80064E3C(u8 *boss5_gryphon);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *entry);
void emit_part_attack_effect__13TBoss5GryphonFPvi(void *ene_dd, int arg1);
}
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon);
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon);
extern "C" {
void move_along_angle__13TBoss5GryphonFPvif(void *arg0, s32 ang, f32 farg0);
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, saddr arg1, s32 arg2);
void set_animation_by_state__12TBoss8DragonFPv(TBoss5Gryphon *gryphon);
void spawn_ancient_trap__12TBoss8DragonFii(s32 arg0, s32 id);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void turn_toward_angle_limited__13TBoss5GryphonFPvii(void *selfv, s32 ang, s32 arg2);
void run_task__13TBoss5GryphonFv(u8 *arg0);
}

// --- C functions defined in Boss5GryphonBehavior.cpp ---
extern "C" {
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2);
void TBoss8Dragon__sub_8005E040(void *arg0);
void TBoss8Dragon__sub_8005E17C(NJS_OBJECT *);
s32 TBoss8Dragon__sub_8005E1E8(f32 farg0);
f32 TBoss8Dragon__sub_8005EAD0(void *arg0, void *arg1, int arg2);
s32 TBoss8Dragon__sub_8005FAE0(u8 *arg0);
void TBoss8Dragon__sub_8005FB90(u8 *arg0);
void TBoss8Dragon__sub_80063EF4(saddr arg0);
void apply_lightning_hit(s32 arg0, s32 arg1, f32 farg0);
void apply_shockwave_hit(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_800641A8(u8 *ene_dd);
void TBoss8Dragon__sub_8006435C(u8 *ene_dd);
void TBoss8Dragon__sub_800646F0(saddr arg0);
void TBoss8Dragon__sub_80064828(u8 *boss8_dragon);
void TBoss8Dragon__sub_800648C8(u8 *boss8_dragon);
void TBoss8Dragon__sub_80064DB8(u8 *boss5_gryphon);
void TBoss8Dragon__sub_80064E3C(u8 *boss5_gryphon);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *entry);
void emit_part_attack_effect__13TBoss5GryphonFPvi(void *ene_dd, int arg1);
void move_along_angle__13TBoss5GryphonFPvif(void *arg0, s32 ang, f32 farg0);
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, saddr arg1, s32 arg2);
void set_animation_by_state__12TBoss8DragonFPv(TBoss5Gryphon *gryphon);
void spawn_ancient_trap__12TBoss8DragonFii(s32 arg0, s32 id);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void turn_toward_angle_limited__13TBoss5GryphonFPvii(void *selfv, s32 ang, s32 arg2);
}
// --- end of C functions

struct BmlResource;

// Gal Gryphon's particle model archive and texture list, loaded with the boss.
extern BmlResource *boss5_gryphon_bml_resource;
extern saddr boss5_gryphon_texture_list;

#endif
