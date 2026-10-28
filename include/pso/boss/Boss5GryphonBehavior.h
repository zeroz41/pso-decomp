#ifndef PSO_BOSS_BOSS5GRYPHONBEHAVIOR_H
#define PSO_BOSS_BOSS5GRYPHONBEHAVIOR_H

#include "types.h"

struct TBoss5Gryphon;
struct TBoss8Dragon;
extern "C" {
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2);
void TBoss8Dragon__sub_8005E040(void *arg0);
void TBoss8Dragon__sub_8005E17C(void);
s32 TBoss8Dragon__sub_8005E1E8(f32 farg0);
f32 TBoss8Dragon__sub_8005EAD0(void *arg0, void *arg1, int arg2);
s32 TBoss8Dragon__sub_8005FAE0(u8 *arg0);
void TBoss8Dragon__sub_8005FB90(u8 *arg0);
void TBoss8Dragon__sub_80063EF4(s32 arg0);
void TBoss8Dragon__sub_80063FB8(s32 arg0, s32 arg1, f32 farg0);
void TBoss8Dragon__sub_800640A4(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_80064114(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_800641A8(u8 *arg0);
void TBoss8Dragon__sub_8006435C(u8 *arg0);
void TBoss8Dragon__sub_800646F0(s32 arg0);
void TBoss8Dragon__sub_80064828(u8 *arg0);
void TBoss8Dragon__sub_800648C8(u8 *arg0);
void TBoss8Dragon__sub_80064DB8(u8 *arg0);
void TBoss8Dragon__sub_80064E3C(u8 *arg0);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *arg0, u8 *arg1);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *arg1);
int emit_part_attack_effect__13TBoss5GryphonFPvi(void *arg0, int arg1);
}
void handle_6x9F_gal_gryphon_boss_actions(void *arg0);
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *arg0);
extern "C" {
void move_along_angle__13TBoss5GryphonFPvif(void *arg0, s32 arg1, f32 farg0);
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, s32 arg1, s32 arg2);
void set_animation_by_state__12TBoss8DragonFPv(TBoss8Dragon *arg0);
void set_flag_4e4__12TBoss8DragonFPv(void *p);
void spawn_ancient_trap__12TBoss8DragonFii(s32 arg0, s32 arg1);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void turn_toward_angle_limited__13TBoss5GryphonFPvii(void *selfv, s32 arg1, s32 arg2);
void run_task__13TBoss5GryphonFv(u8 *arg0);
}

// --- C functions defined in Boss5GryphonBehavior.cpp ---
extern "C" {
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2);
void TBoss8Dragon__sub_8005E040(void *arg0);
void TBoss8Dragon__sub_8005E17C(void);
s32 TBoss8Dragon__sub_8005E1E8(f32 farg0);
f32 TBoss8Dragon__sub_8005EAD0(void *arg0, void *arg1, int arg2);
s32 TBoss8Dragon__sub_8005FAE0(u8 *arg0);
void TBoss8Dragon__sub_8005FB90(u8 *arg0);
void TBoss8Dragon__sub_80063EF4(s32 arg0);
void TBoss8Dragon__sub_80063FB8(s32 arg0, s32 arg1, f32 farg0);
void TBoss8Dragon__sub_800640A4(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_80064114(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_800641A8(u8 *ene_dd);
void TBoss8Dragon__sub_8006435C(u8 *ene_dd);
void TBoss8Dragon__sub_800646F0(s32 arg0);
void TBoss8Dragon__sub_80064828(u8 *arg0);
void TBoss8Dragon__sub_800648C8(u8 *arg0);
void TBoss8Dragon__sub_80064DB8(u8 *arg0);
void TBoss8Dragon__sub_80064E3C(u8 *arg0);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *arg1);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *arg1);
int emit_part_attack_effect__13TBoss5GryphonFPvi(void *ene_dd, int arg1);
void move_along_angle__13TBoss5GryphonFPvif(void *arg0, s32 arg1, f32 farg0);
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, s32 arg1, s32 arg2);
void set_animation_by_state__12TBoss8DragonFPv(TBoss8Dragon *boss8_dragon);
void set_flag_4e4__12TBoss8DragonFPv(void *p);
void spawn_ancient_trap__12TBoss8DragonFii(s32 arg0, s32 arg1);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void turn_toward_angle_limited__13TBoss5GryphonFPvii(void *selfv, s32 arg1, s32 arg2);
}
// --- end of C functions

#endif
