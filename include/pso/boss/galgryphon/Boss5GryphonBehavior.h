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
f32 TBoss8Dragon__sub_8005EAD0(void *self, void *arg1, int arg2);
void apply_lightning_hit(s32 arg0, s32 arg1, f32 farg0);
void apply_tornado_hit(s32 arg0, saddr arg1);
void apply_shockwave_hit(s32 arg0, s32 arg1);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 self, s32 arg1, s32 arg2, s32 arg3);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *entry);
}
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon);
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon);
extern "C" {
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, saddr arg1, s32 arg2);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void run_task__13TBoss5GryphonFv(u8 *arg0);
}

// --- C functions defined in Boss5GryphonBehavior.cpp ---
extern "C" {
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2);
void TBoss8Dragon__sub_8005E17C(NJS_OBJECT *);
f32 TBoss8Dragon__sub_8005EAD0(void *self, void *arg1, int arg2);
void apply_lightning_hit(s32 arg0, s32 arg1, f32 farg0);
void apply_shockwave_hit(s32 arg0, s32 arg1);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 self, s32 arg1, s32 arg2, s32 arg3);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *entry);
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, saddr arg1, s32 arg2);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
}
// --- end of C functions

struct BmlResource;

// Gal Gryphon's particle model archive and texture list, loaded with the boss.
extern BmlResource *boss5_gryphon_bml_resource;
extern GinjaTextureList *boss5_gryphon_texture_list;

#endif
