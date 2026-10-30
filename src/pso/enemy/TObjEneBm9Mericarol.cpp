#include "pso/misc/MaterialOpacityFade.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBm9Mericarol.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"

#include "pso/player/TUnk_804928CC.h"

#include "pso/enemy/TObjEneBm9Mericarol_Bomb.h"
#include "pso/boss/TBoss8Dragon.h"

#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/TLobby.h"
#include "pso/enemy/TObjEneDD_800BB804.h"
#include "pso/boss/TBoss4Type3_800D9960.h"
#include "pso/unk/text_802D1C84.h"

struct VBase_802D0C14 { char pad[0x18]; };

struct VObj_802D0C14 : VBase_802D0C14 {
    virtual void m0(s32);
};

struct S_802D0C14 { u8 pad[0x3C0]; void *arr[2]; };

struct VBase18_802D0D3C { char pad[0x18]; };
struct VObj18_802D0D3C : VBase18_802D0D3C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85(s32, s32);
    virtual void m86();
};

extern "C" {
extern const f32 lbl_805DE704;
void run_task__19TObjEneBm9MericarolFv(u8 *arg0);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjEneBm9Mericarol__sub_802D073C(s32 arg0);
f32 random_ratio__9TObjCharaFv(s32);
extern const f32 lbl_805DE6F4;
extern const f32 lbl_805DE714;
extern const f32 lbl_805DE728;
extern const f32 lbl_805DE740;
extern const f32 lbl_805DE744;
extern const f32 lbl_805DE748;
void TObjEneBm9Mericarol__sub_802CEDA0(u8 *arg0, s32 arg1);
void TObjEneBm9Mericarol__sub_802CF368(u8 *actor, s32 arg1);
void TObjEneBm9Mericarol__sub_802CF4F8(u8 *arg0, s32 arg1);
void TObjEneDD__sub_802CF7B4(u8 *arg0, s32 arg1);
void TObjPlayer__sub_802CFB64(u8 *arg0, s32 arg1);
void TObjEneBm9Mericarol__sub_802D01D8(u8 *actor, s32 arg1);
void TObjEneBm9Mericarol__sub_802D05BC(u8 *arg0, s32 arg1);
void dispatch_state_handler__19TObjEneBm9MericarolFiUii(s32 arg0, u32 arg1, s32 arg2);
s32 obj_isState2_324__9TObjCharaFv(s32);
int get_player_data__10TObjPlayerFi(int a0);
s32 is_valid_target__9TObjEneDDFv(s32);
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805DE74C;
void queue_destruction__7TObjectFv(void *arg0);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 __dt__17AreaAttackHistoryFv(s32 arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
s32 __destroy_arr(void *, void *, u32, u32);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
u8 *__dt__19TObjEneBm9MericarolFPvs(u8 *arg0, s16 arg1);
void TObjEneBm9Mericarol__sub_802D093C(void);
void TObjEneBm9Mericarol__sub_802D0940(void);
void vfunc_61__19TObjEneBm9MericarolFv(void);
void vfunc_28__19TObjEneBm9MericarolFv(void);
void vfunc_63__19TObjEneBm9MericarolFv(void *arg0);
void vfunc_62__19TObjEneBm9MericarolFv(void *arg0);
void vfunc_88__19TObjEneBm9MericarolFv(void *arg0);
s32 clear_attack_receipts__9TObjEneDDFv(void);
void TLobby__sub_8001FE7C(void*, int);
struct Obj_802D0D3C;
Obj_802D0D3C *TObjEneBm9Mericarol__ct(Obj_802D0D3C *, void *, s32);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
void fn_802D1C84(void);

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_105__19TObjEneBm9MericarolFv();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFPl();
extern "C" void vfunc_84__9TObjEneDDFv();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_89__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" int vfunc_104__12TObjEneDD_STFf(void *p);
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void draw_color_variant__19TObjEneBm9MericarolFv();
extern "C" void render__19TObjEneBm9MericarolFv(u8 *arg0);
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" u8 lbl_80472324[];
extern "C" u8 lbl_80472338[];
extern "C" u8 lbl_80472354[];
extern "C" u8 lbl_80472370[];
extern "C" u8 lbl_8047238C[];
extern "C" u8 lbl_804723A8[];
extern "C" u8 lbl_804723C4[];
extern "C" u8 lbl_804723E0[];
extern "C" u8 lbl_804723FC[];
extern "C" u8 lbl_80472418[];
extern "C" u8 lbl_80472434[];
extern "C" u8 lbl_8047244C[];
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *lbl_804E15BC[2];
extern void *lbl_804E15C4[9];
extern void *lbl_804E15F8[2];
extern void *lbl_804E1600[9];
struct Res_802D0D3C {
    u8 pad0[0x42C];
    s32 *f42C;
    s32 f430;
};

struct Obj_802D0D3C {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt18;
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    u8 pad38[0xB8 - 0x38];
    s16 fB8;
    u8 padBA[0x326 - 0xBA];
    s16 f326;
    u8 pad328[0x350 - 0x328];
    void *f350;
    u8 pad354[0x37C - 0x354];
    f32 f37C;
    u8 pad380[0x3C0 - 0x380];
    s32 f3C0;
    s32 f3C4;
    u8 a3C8[4][0x1C];
    s32 f438;
    f32 f43C;
    u8 pad440[0x44C - 0x440];
    s32 f44C;
    s32 f450;
    s32 f454;
    s32 f458;
    u8 pad45C[0x46C - 0x45C];
    u8 o46C[0x14];
    void **vt480;
    u8 pad484[0x488 - 0x484];
    void *f488;
    void *f48C;
    s32 f490;
    s32 f494;
    s32 f498;
    s32 f49C;
    s32 f4A0;
    f32 f4A4;
    u8 pad4A8[4];
    s32 f4AC;
};

typedef void (*VFn0_802D0D3C)(void *);
typedef void (*VFn2_802D0D3C)(void *, s32, s32);

void __ct__12TObjEneDD_STFP7TObject(void *, void *);
void __construct_array(void *, void *, void *, u32, u32);
void invoke_initialization_hook__9TObjEneDDFPv(void *, s32);
void init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, s32);
void reset_hp__9TObjEneDDFPUcPUcPUc(void *, s32, s32, s32);
s32 create__13TUnk_80494968FUlUl(s32, s32);
void initialize_enemy_state__9TObjEneDDFl(void *, s32);
void *__ct__14TObjCollidableFP7TObject(void *, s32);
void init_collision_body_parts(void *, void *, s32);
u8 *__ct__17AreaAttackHistoryFl(u8 *arg0, s32 arg1);
void __ct__15RenderFadeStateFv(void *);
extern const s32 lbl_80472318[];
extern s32 lbl_805D3F28;
extern const f32 lbl_805DE6EC;
extern const f32 lbl_805DE70C;
extern const f32 lbl_805DE750;

void *lbl_804E1548[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x200, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804E1564[22] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x42480000, (void *)0x0,
    (void *)0x0, (void *)0x9d03, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *lbl_804E15BC[2] = {
    (void *)&lbl_80472324, (void *)0x0,
};
void *lbl_804E15C4[9] = {
    (void *)&lbl_80472338, (void *)&lbl_80472354, (void *)&lbl_80472370, (void *)&lbl_8047238C,
    (void *)&lbl_804723A8, (void *)&lbl_804723C4, (void *)&lbl_804723E0, (void *)&lbl_804723FC,
    (void *)0x0,
};
void *lbl_804E15E8[4] = {
    (void *)&lbl_80472418, (void *)&lbl_804E15BC, (void *)&lbl_804E15C4, (void *)0x10008,
};
__declspec(section ".data") void *lbl_804E15F8[2] = {
    (void *)&lbl_80472434, (void *)0x0,
};
void *lbl_804E1600[9] = {
    (void *)&lbl_80472338, (void *)&lbl_80472354, (void *)&lbl_80472370, (void *)&lbl_8047238C,
    (void *)&lbl_804723A8, (void *)&lbl_804723C4, (void *)&lbl_804723E0, (void *)&lbl_804723FC,
    (void *)0x0,
};
void *lbl_804E1624[4] = {
    (void *)&lbl_8047244C, (void *)&lbl_804E15F8, (void *)&lbl_804E1600, (void *)0x10008,
};
void *lbl_804E1634[36] = {
    (void *)0x30000, (void *)0x3, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x5, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x6, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x5, (void *)0x3f000000, (void *)0x0,
    (void *)0x20003, (void *)0x7, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x4, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f333333, (void *)0x0,
};
void *TObjEneBm9Mericarol__vtable[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__19TObjEneBm9MericarolFPvs, (void *)&run_task__19TObjEneBm9MericarolFv,
    (void *)&render__19TObjEneBm9MericarolFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__19TObjEneBm9MericarolFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__19TObjEneBm9MericarolFv, (void *)&vfunc_62__19TObjEneBm9MericarolFv, (void *)&vfunc_63__19TObjEneBm9MericarolFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_state_handler__19TObjEneBm9MericarolFiUii,
    (void *)&vfunc_88__19TObjEneBm9MericarolFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&vfunc_105__19TObjEneBm9MericarolFv, (void *)&draw_color_variant__19TObjEneBm9MericarolFv,
};
#define TObjEneBm9Mericarol__vtable ((u8 *)TObjEneBm9Mericarol__vtable)
u32 bm9_mericarol_phase_hp_table[3];
u32 lbl_80540B64[3];
u32 lbl_80540B70[3];
u32 mericarol_phase_param_table[3];
u32 lbl_80540B88[4];

void TObjEneBm9Mericarol__sub_802D073C(s32 arg0) {
    play_persistent_sound((((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3A810))), (arg0), (arg0 + 0x38), 0, 0);
}

s32 TObjEneBm9Mericarol::get_phase() { return *(s32*)((char*)this + 0x45c); }

#pragma push
#pragma opt_common_subs off
void TObjEneBm9Mericarol::init_size_tier_and_offsets() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    s32 temp_r0;
    *(s32 *)((s8 *)arg0 + 0x45C) = (s32) *(s32 *)((s8 *)arg0 + 0x368);
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x45C);
    if ((temp_r0 < 0) || (temp_r0 > 2)) {
        temp_f1 = random_ratio__9TObjCharaFv((s32) arg0);
        if (temp_f1 > lbl_805DE728) {
            *(s32 *)((s8 *)arg0 + 0x45C) = 2;
        } else if (temp_f1 > lbl_805DE740) {
            *(s32 *)((s8 *)arg0 + 0x45C) = 1;
        } else {
            *(s32 *)((s8 *)arg0 + 0x45C) = 0;
        }
    }
    *(f32 *)((s8 *)arg0 + 0x440) = (f32) (lbl_805DE744 + *(f32 *)((s8 *)arg0 + 0x354));
    *(f32 *)((s8 *)arg0 + 0x444) = (f32) (lbl_805DE748 + *(f32 *)((s8 *)arg0 + 0x358));
    if (*(f32 *)((s8 *)arg0 + 0x444) < lbl_805DE6F4) {
        *(f32 *)((s8 *)arg0 + 0x444) = (f32) lbl_805DE6F4;
    }
    *(f32 *)((s8 *)arg0 + 0x448) = (f32) (lbl_805DE714 + *(f32 *)((s8 *)arg0 + 0x35C));
}
#pragma pop

s32 TObjEneBm9Mericarol::find_nearby_target() {
    s32 arg0 = (s32)this;
    s32 best = 0;
    s32 n = TLobby::get_game_mode();
    s32 pl;
    s32 i;
    for (i = 0; i < n; i++) {
        pl = get_player_data__10TObjPlayerFi(i);
        if (is_valid_target__9TObjEneDDFv(pl) != 0 && obj_isState2_324__9TObjCharaFv(pl) == 0) {
            best = pl;
            break;
        }
    }
    if (is_valid_target__9TObjEneDDFv(best) != 0 && horizontal_distance_squared((void *)(arg0 + 0x38), (void *)(best + 0x38)) < lbl_805DE74C) {
        return best;
    }
    return 0;
}

s32 TObjEneBm9Mericarol::try_set_mode8_if_flag2() {
    if (this->m_454 & 2) {
        transition_enemy_state(8);
        return 1;
    }
    return 0;
}
void TObjEneBm9Mericarol__sub_802D093C(void) {  }
void TObjEneBm9Mericarol__sub_802D0940(void) {  }
void TObjEneBm9Mericarol::vfunc_88() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (this->m_300 - *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneBm9Mericarol::sync_center_position() {
    u8 *arg0 = (u8 *)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    this->m_300 = (f32) (this->m_300 + lbl_805DE704);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

void TObjEneBm9Mericarol::vfunc_61() {  }
void TObjEneBm9Mericarol::vfunc_62() {
    if ((s16) this->mode != 0xA) {
        if (this->m_454 & 0x20) {
            clear_attack_receipts__9TObjEneDDFv();
            return;
        }
        transition_enemy_state(0xA);
    }
}
void TObjEneBm9Mericarol::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0xB) && (temp_r0 != 0xC)) {
        transition_enemy_state(0xB);
    }
}
void TObjEneBm9Mericarol::vfunc_28() {  }

extern u32 TBoss4Type3_shared_instance;
extern u32 lbl_805D6864;
extern u32 lbl_805D6868;

void dispatch_state_handler__19TObjEneBm9MericarolFiUii(s32 actor, u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        ((TObjEneBm9Mericarol *)actor)->handle_action(msg);
        return;
    case 1:
        TObjEneBm9Mericarol__sub_802D05BC((u8 *)actor, (msg));
        return;
    case 2:
        ((TObjEneBm9Mericarol *)actor)->handle_event(msg);
        return;
    case 3:
        TObjEneBm9Mericarol__sub_802D01D8((u8 *)actor, (msg));
        return;
    case 4:
        ((TObjEneBm9Mericarol *)actor)->handle_shot_state((msg));
        return;
    case 5:
        TObjPlayer__sub_802CFB64((u8 *)actor, (msg));
        return;
    case 6:
        TObjEneDD__sub_802CF7B4((u8 *)actor, (msg));
        return;
    case 10:
        TObjEneBm9Mericarol__sub_802CF368((u8 *)actor, (msg));
        return;
    case 11:
        ((TObjEneBm9Mericarol *)actor)->state_burrow(msg);
        return;
    case 7:
        TObjEneBm9Mericarol__sub_802CF4F8((u8 *)actor, (msg));
        return;
    case 8:
        ((TObjEneBm9Mericarol *)actor)->handle_motion_event(msg);
        return;
    case 9:
        TObjEneBm9Mericarol__sub_802CEDA0((u8 *)actor, (msg));
        return;
    case 12:
        ((TObjEneBm9Mericarol *)actor)->handle_state_message(msg);
    default:
        return;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm9Mericarol::run_task() {
    s16 temp_r3_2;
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_105();
        return;
    }
    temp_r3 = this->m_454;
    if (temp_r3 & 0x10) {
        if ((u32) this->m_390 == 0U) {
            this->m_454 = (s32) (temp_r3 & 0xFFFFFFEF);
        }
    } else if ((u32) this->m_390 != 0U) {
        this->m_454 = (s32) (temp_r3 | 0x10);
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else {
        temp_r3_2 = this->mode;
        if ((temp_r3_2 == 0) || (temp_r3_2 == 1)) {
            ((TObjEneBm9Mericarol *)this)->fade.reset_color();
            transition_enemy_state(2);
        }
    }
    this->sync_center_position();
    ((TObjEnemy *)((u8 *)this))->submit_default_cursor_candidate();
    this->vfunc_100();
}
#pragma pop

u8 *__dt__19TObjEneBm9MericarolFPvs(u8 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        *(void **)((s8 *)arg0 + 0x18) = TObjEneBm9Mericarol__vtable;
        for (i = 0; i < 2; i++) {
            if (((S_802D0C14 *)arg0)->arr[i] != NULL) {
                queue_destruction__7TObjectFv(((S_802D0C14 *)arg0)->arr[i]);
                ((S_802D0C14 *)arg0)->arr[i] = NULL;
            }
        }
        if (*(void **)((s8 *)arg0 + 0x488) != NULL) {
            __dt__17AreaAttackHistoryFv((s32)(*(void **)((s8 *)arg0 + 0x488)), 1);
            *(void **)((s8 *)arg0 + 0x488) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x48C) != NULL) {
            free_collision_body_parts(*(void **)((s8 *)arg0 + 0x48C));
            if (*(VObj_802D0C14 **)((s8 *)arg0 + 0x48C) != NULL) {
                (*(VObj_802D0C14 **)((s8 *)arg0 + 0x48C))->m0(1);
            }
            *(void **)((s8 *)arg0 + 0x48C) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x4AC) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x4AC));
            *(void **)((s8 *)arg0 + 0x4AC) = NULL;
        }
        free_collision_body_parts(arg0);
        ((TObjEneBm9Mericarol *)arg0)->fade.MaterialOpacityFade::~MaterialOpacityFade();
        __destroy_arr(arg0 + 0x3C8, (void *) __dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

Obj_802D0D3C *TObjEneBm9Mericarol__ct(Obj_802D0D3C *self, void *parent, s32 arg2) {
    s32 ph;
    s32 i;
    void *p;

    __ct__12TObjEneDD_STFP7TObject(self, parent);
    self->vt18 = TObjEneBm9Mericarol__vtable;
    __construct_array(self->a3C8, (void *)__ct__15RenderFadeStateFv, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
    __ct__19MaterialOpacityFadeFv((self->o46C));
    self->f0 = lbl_805D3F28;
    invoke_initialization_hook__9TObjEneDDFPv(self, arg2);
    ((TObjEneBm9Mericarol *)self)->init_size_tier_and_offsets();
    self->f438 = 0;
    if (random_ratio__9TObjCharaFv((s32)self) <= lbl_805DE750) {
        self->f438 |= 0x400;
    }
    ((TObjEneDD *)self)->init_position_vectors();
    self->f34 = ((Res_802D0D3C *)lbl_805D6868)->f42C[2];
    self->f24 = ((Res_802D0D3C *)lbl_805D6868)->f42C[3];
    init_model__9TObjEneDDFP13CollisionBodyl(self, lbl_804E1564, 1);
    ((TObjMotion *)self)->set_field_d8((s32)lbl_804E1634);
    ((TObjMotion *)self)->set_field_dc(((Res_802D0D3C *)lbl_805D6868)->f430);
    self->fB8 = 2;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    ph = ((TObjEneBm9Mericarol *)self)->get_phase();
    reset_hp__9TObjEneDDFPUcPUcPUc(self, bm9_mericarol_phase_hp_table[ph], lbl_80540B64[ph], lbl_80540B70[ph]);
    self->f3C0 = create__13TUnk_80494968FUlUl(0xA0303030, lbl_80472318[ph]);
    self->f3C4 = create__13TUnk_80494968FUlUl(0xA0303030, lbl_80472318[ph]);
    ((TObjChara *)self)->add_flags_2e4(0x12);
    self->f350 = lbl_804E1548;
    switch (((TObjEneBm9Mericarol *)self)->get_phase()) {
    case 0:
        initialize_enemy_state__9TObjEneDDFl(self, 0x38);
        break;
    case 1:
        initialize_enemy_state__9TObjEneDDFl(self, 0x39);
        break;
    case 2:
        initialize_enemy_state__9TObjEneDDFl(self, 0x3A);
        break;
    }
    self->f37C = lbl_805DE6EC;
    ((TObjEneDD_ST *)self)->enemy_init_acquire_period(0x1E);
    ((TObjEneDD_ST *)self)->enemy_init_validate_period(0x1E);
    self->f43C = lbl_805DE70C;
    self->f44C = 0;
    self->f450 = 0;
    self->f454 = 0;
    self->f458 = 0;
    ((TObjEneBm9Mericarol *)self)->fade.reset_obstruction_fade();
    p = __nw__7TObjectFUl(0xAC);
    if (p != NULL) {
        p = __ct__14TObjCollidableFP7TObject(p, 0);
    }
    self->f48C = p;
    init_collision_body_parts(self->f48C, (u8 *)lbl_804E1564 + 0x2C, 1);
    p = ::operator new(0x10);
    if (p != NULL) {
        p = __ct__17AreaAttackHistoryFl((u8 *)p, 8);
    }
    self->f488 = p;
    self->f490 = 0;
    self->f494 = 0;
    self->f498 = 0;
    self->f49C = 0;
    self->f4A0 = 0;
    self->f4A4 = lbl_805DE70C;
    self->f4AC = 0;
    ((TObjEneBm9Mericarol *)self)->sync_center_position();
    ((TObjEneBm9Mericarol *)self)->vfunc_88();
    ((TObjEneDD *)self)->transform_part_positions();
    self->f326 = 0;
    ((VObj18_802D0D3C *)self)->m85(self->f326, 4);
    ((TObjEnemy *)self)->sub_8002AE64();
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(self->a3C8[i]))->activate_and_dispatch();
    }
    return self;
}

void TObjEneBm9Mericarol::free_shared_instances() {
    if ((u32) lbl_805D6864 != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)lbl_805D6864, 1);
        lbl_805D6864 = 0U;
    }
    if ((u32) TBoss4Type3_shared_instance != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)TBoss4Type3_shared_instance, 1);
        TBoss4Type3_shared_instance = 0U;
    }
    fn_802D1C84();
    if ((u32) lbl_805D6868 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D6868, 1);
        lbl_805D6868 = 0U;
    }
}

extern void *tl_04;

void *TObjEneBm9Mericarol::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4B0);
    if (o != NULL) {
        o = TObjEneBm9Mericarol__ct((Obj_802D0D3C *)o, tl_04, (s32)arg0);
    }
    return o;
}

struct MotionEntry_802D1130 { s32 flags; s32 index; f32 speed; s32 pad; };
struct MotionPair_802D1130 { s32 id; s32 motion; };
struct SpawnPos_802D1130 { MotionPair_802D1130 *motions; s32 w[3]; };
s32 is_split_screen();
void TObjPlayer__sub_800F0928(void);
void *init_trail_buffer__11TBoss4Type3FPvifff(void *, s32, f32, f32, f32);
extern const s32 lbl_804722E8[];
extern const s32 lbl_804722F4[];
extern const s32 lbl_80472300[];
extern const s32 lbl_8047230C[];
extern const SpawnPos_802D1130 lbl_80472480;
extern const f32 lbl_805DE754;
extern u32 lbl_805D686C;
extern u32 lbl_805D6870;
extern u32 lbl_805D6874;
extern u32 lbl_805D6878;

void TBoss4Type3__sub_802D1130(void) {
    s32 i;
    void *p;
    MotionPair_802D1130 *pair;

    if (is_split_screen() != 0) {
        lbl_805D6868 = load_enemy_bml_resource((u8 *)lbl_804E1624);
    } else {
        lbl_805D6868 = load_enemy_bml_resource((u8 *)lbl_804E15E8);
    }
    lbl_805D686C = 0;
    lbl_805D6870 = 0;
    ((f32 *)lbl_80540B88)[0] = lbl_805DE70C;
    ((f32 *)lbl_80540B88)[1] = lbl_805DE70C;
    ((f32 *)lbl_80540B88)[2] = lbl_805DE70C;
    lbl_805D6874 = 0;
    lbl_805D6878 = 0;
    fn_802D1CC8();
    TObjPlayer__sub_800F0928();
    for (i = 0; i < 3; i++) {
        bm9_mericarol_phase_hp_table[i] = (u32)TLobby::register_boss(lbl_804722E8[i]);
        lbl_80540B64[i] = (u32)TLobby::dispatch_shared_handler_b(lbl_804722F4[i]);
        lbl_80540B70[i] = (u32)TLobby::register_object(lbl_80472300[i]);
        mericarol_phase_param_table[i] = (u32)TLobby::dispatch_shared_handler_a(lbl_8047230C[i]);
    }
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805DE70C, lbl_805DE704, lbl_805DE754);
    }
    TBoss4Type3_shared_instance = (u32)p;
    p = ::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, lbl_805DE70C, lbl_805DE704, lbl_805DE754);
    }
    lbl_805D6864 = (u32)p;
    set_motion_packed_rotation();
    pair = (MotionPair_802D1130 *)((Res_802D0D3C *)lbl_805D6868)->f430 + ((MotionEntry_802D1130 *)lbl_804E1634)[8].index;
    draw_trail_with_colors((u8 *)TBoss4Type3_shared_instance, ((Res_802D0D3C *)lbl_805D6868)->f42C[2], pair->motion, 0x20, 0x21);
    pair = (MotionPair_802D1130 *)((Res_802D0D3C *)lbl_805D6868)->f430 + ((MotionEntry_802D1130 *)lbl_804E1634)[8].index;
    draw_trail_with_colors((u8 *)lbl_805D6864, ((Res_802D0D3C *)lbl_805D6868)->f42C[2], pair->motion, 0x2A, 0x2B);
    clear_motion_packed_rotation();
    {
        SpawnPos_802D1130 pos = lbl_80472480;
        pair = (MotionPair_802D1130 *)((Res_802D0D3C *)lbl_805D6868)->f430;
        pos.motions = pair;
        TLobby::spawn_npc_enemy(0x42, ((Res_802D0D3C *)lbl_805D6868)->f42C[2], ((Res_802D0D3C *)lbl_805D6868)->f42C[3], (s32)&pos,
            *(f32 *)&lbl_804E1564[3], lbl_805DE70C);
    }
}

}
