#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBm5Wolf.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss5Gryphon.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneBm3FlyNest.h"

extern "C" const f64 TObjEneBm5Wolf__data_8043B5B0;
struct Vec_800B5D4C;
struct Col_800B5D4C;
struct Wolf_800B5D4C;
struct VBase_18_7b3d65;
struct VBase_18_4225ac;
struct VBase_18_8bca97;
struct Arg_800B7530;
struct Base_800B7530;
struct Arg_800B74B8;
struct Base_800B74B8;
struct Vec_800B50CC;
struct Vec_800B56CC;
struct Node_800B6B50;
struct List_800B6B50;
struct Ang_800B4AD4;
struct VBase_800B4AD4;
struct Vec_800B7018;
struct Obj_800B7018;
struct Vec_800B53F0;
struct Base_800B53F0;
struct Vec_800B62AC;
struct VBase_18_b7c757;
struct Vec_800B4D88;
struct Node_800B4D88;
struct List_800B4D88;
struct VBase_18_a3e1a1;
struct VBase_800B4820;
struct VBase2_800B4820;
struct VBase_18_26a62c;
struct Vec_800B4824;
struct Ent16_800B4824;
struct Ent8_800B4824;
struct Stack_800B7808;
struct Seq_800B76E0;
struct Ent_800B76E0;
struct Cur_800B76E0;
struct Obj_800B76E0;
struct Vec_800B78F8;
struct Wolf_800B78F8;
struct Vec_800B79E0;
struct Obj_800B79E0;
struct Stack_800B7C14;
struct Wolf_800B7DDC;
struct VBase_18;
struct RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C;
struct RecoveredGlobal_800B85D0_TObjEneBm5Wolf__data_80500B78;
struct RecoveredGlobal_800B85A0_TObjEneBm5Wolf__data_80500B8C;
struct RecoveredGlobal_800B8600_TObjEneBm5Wolf__data_80500B78;
struct Node_800B850C;
struct Wolf_800B850C;
struct DBase_800B8174;
struct VBase_18_484afe;
struct HpTbl_800B8244;
struct WolfRes_800B8244;
struct Vec_800B86B4;
struct G_800B86B4;
struct Spawn_800B86B4;
struct Obj_800B86B4;
struct Wolf_800B86B4;
struct O_800B8A24;
struct Globals_800B8A40;
extern "C" {
f32 random_ratio__9TObjCharaFv(s32);
f32 atan2_float(f64, f64);
void approach_target__14TObjEneBm5WolfFPvf(void *arg0, f32 farg0);
s32 transition_enemy_state__9TObjEneDDFl(void *, s32);
s32 approach_angle_limited(int, int, int);
f32 sin_table_lookup(s32 angle);
f32 cos_table_lookup(s32 angle);
void *find_entity_by_id(u16 id);
void advance_pose_turn__14TObjEneBm5WolfFPvi(Wolf_800B7DDC *s, s32 target);
}
s32 actor_rand_int(s32 arg0, s32 arg1);
extern "C" {
f32 normalize_vector_xz__FP3Vec(void *);
void play_sound__14TObjEneBm5WolfFPv(void *arg0);
s32 get_group_id__14TObjEneBm5WolfFPv(void* p);
void calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(void *arg0, s32 arg1, void *arg2, s32 *arg3);
s32 rotate_xz_pair_by_angle(void *, void *, s32);
s32 check_v2_mode__9TObjEneDDFv();
void select_subtype__14TObjEneBm5WolfFv(u8 *arg0);
Wolf_800B850C * find_pack_leader__14TObjEneBm5WolfFi(s32 id);
void *fn_800B8B00(void *p);
s16 get_entity_id();
void update_collision_center__14TObjEneBm5WolfFv(u8 *arg0);
u8 * __dt__14TObjEneBm5WolfFv(u8 *arg0, s16 arg1);
void run_task__14TObjEneBm5WolfFv(u8 *arg0);
void vfunc_62__14TObjEneBm5WolfFv(void* p);
void vfunc_63__14TObjEneBm5WolfFv(void *arg0);
void vfunc_88__14TObjEneBm5WolfFv(void *arg0);
s32 destroy__14TObjEneBm5WolfFis(s32 arg0, s16 arg1);
void TObjEneBm5Wolf__sub_800B8A24(O_800B8A24 *self);
u8 * TObjEneBm5Wolf__ct(u8 *arg0, void *arg1, void *arg2);
extern void* bm5_wolf_decision_row[];
extern void* TObjEneBm5Wolf__collider_params[];
extern void* bm_ene_bm5_wolf_resource_descriptor[];
extern void* wolf_action_table[];
extern s32 TObjEneBm5Wolf__stat_params[];
extern s32 wolf_stat_handle_a_table[];
extern s32 wolf_stat_handle_b_table[];
extern u32 TObjEneBm5Wolf__instance_list[];
extern u32 TObjEneBm5Wolf__pack_member_list[];
extern const f32 TObjEneBm5Wolf__data_805D9DB4;
extern void* lbl_804922F8[];
extern Wolf_800B86B4* TObjEneBm5Wolf__bml_resource;
extern u8 lbl_8043B3C8[];
extern u8 lbl_8043B3DC[];
extern u8 lbl_8043B3F0[];
extern u8 lbl_8043B408[];
extern u8 lbl_8043B424[];
extern u8 lbl_8043B440[];
extern u8 lbl_8043B458[];
extern u8 lbl_8043B470[];
extern u8 lbl_8043B488[];
extern u8 lbl_8043B4A0[];
extern u8 lbl_8043B4B8[];
extern u8 lbl_8043B4D0[];
extern u8 lbl_8043B4E8[];
extern u8 lbl_8043B504[];
extern u8 lbl_8043B520[];
extern u8 lbl_8043B538[];
extern u8 lbl_8043B550[];
void *bm5_wolf_decision_row[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TObjEneBm5Wolf__collider_params[33] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40c00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x40c00000, (void *)0x0,
    (void *)0x0, (void *)0x9d03, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x40c00000, (void *)0x0, (void *)0x0,
    (void *)0x9d03, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *bm_ene_bm5_wolf_model_names[3] = {
    (void *)&lbl_8043B3C8, (void *)&lbl_8043B3DC, (void *)0x0,
};
void *bm_ene_bm5_wolf_motion_names[15] = {
    (void *)&lbl_8043B3F0, (void *)&lbl_8043B408, (void *)&lbl_8043B424, (void *)&lbl_8043B440,
    (void *)&lbl_8043B458, (void *)&lbl_8043B470, (void *)&lbl_8043B488, (void *)&lbl_8043B4A0,
    (void *)&lbl_8043B4B8, (void *)&lbl_8043B4D0, (void *)&lbl_8043B4E8, (void *)&lbl_8043B504,
    (void *)&lbl_8043B520, (void *)&lbl_8043B538, (void *)0x0,
};
void *bm_ene_bm5_wolf_resource_descriptor[4] = {
    (void *)&lbl_8043B550, (void *)&bm_ene_bm5_wolf_model_names, (void *)&bm_ene_bm5_wolf_motion_names, (void *)0x2000e,
};
void *wolf_action_table[76] = {
    (void *)0x10000, (void *)0xc, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0xd, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x20008, (void *)0x1, (void *)0x3fc00000, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f000000, (void *)0x0,
    (void *)0x2000a, (void *)0x2, (void *)0x3fc00000, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3fc00000, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f800000, (void *)0x0,
    (void *)0x2000b, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x9, (void *)0x3f800000, (void *)0x0,
};
__declspec(section ".data") s32 TObjEneBm5Wolf__stat_params[2];
__declspec(section ".data") s32 wolf_stat_handle_a_table[2];
__declspec(section ".data") s32 wolf_stat_handle_b_table[2];
__declspec(section ".data") s32 lbl_80500B58[2];
}

#define approach_target__14TObjEneBm5WolfFPvf ((void (*)(void *, f32))approach_target__14TObjEneBm5WolfFPvf)
#define advance_pose_turn__14TObjEneBm5WolfFPvi ((s32 (*)(void *, s32))advance_pose_turn__14TObjEneBm5WolfFPvi)
#define play_sound__14TObjEneBm5WolfFPv ((void * (*)(void *))play_sound__14TObjEneBm5WolfFPv)
#define get_group_id__14TObjEneBm5WolfFPv ((s32 (*)())get_group_id__14TObjEneBm5WolfFPv)
#define calc_rotated_vector__14TObjEneBm5WolfFPviPvPv ((void (*)(void *, s32, void *, void *))calc_rotated_vector__14TObjEneBm5WolfFPviPvPv)
#define select_subtype__14TObjEneBm5WolfFv ((s32 (*)(void *))select_subtype__14TObjEneBm5WolfFv)
#define find_pack_leader__14TObjEneBm5WolfFi ((u32 (*)(s32))find_pack_leader__14TObjEneBm5WolfFi)
#define update_collision_center__14TObjEneBm5WolfFv ((s32 (*)(void *))update_collision_center__14TObjEneBm5WolfFv)
#define vfunc_62__14TObjEneBm5WolfFv ((void (*)(void))vfunc_62__14TObjEneBm5WolfFv)
#define vfunc_63__14TObjEneBm5WolfFv ((void (*)(void))vfunc_63__14TObjEneBm5WolfFv)
#define vfunc_88__14TObjEneBm5WolfFv ((void (*)(void))vfunc_88__14TObjEneBm5WolfFv)
struct Ang_800B4AD4;
struct Arg_800B74B8;
struct Arg_800B7530;
struct Base_800B53F0;
struct Base_800B74B8;
struct Base_800B7530;
struct Cur_800B76E0;
struct Ent_800B76E0;
struct List_800B4D88;
struct List_800B6B50;
struct Node_800B4D88;
struct Node_800B6B50;
struct Obj_800B7018;
struct Obj_800B74B8;
struct Obj_800B7530;
struct Obj_800B76E0;
struct Obj_800B79E0;
struct Seq_800B76E0;
struct Stack_800B7808;
struct VBase2_800B4820;
struct VBase_18_4225ac;
struct VBase_18_7b3d65;
struct VBase_18_8bca97;
struct VBase_18_a3e1a1;
struct VBase_18_b7c757;
struct VBase_800B4820;
struct VBase_800B4AD4;
struct VEne_800B4820;
struct VObj2_800B4820;
struct VObj_18_4225ac;
struct VObj_18_7b3d65;
struct VObj_18_8bca97;
struct VObj_18_a3e1a1;
struct VObj_18_b7c757;
struct VObj_800B4AD4;
struct VObj_800B53F0;
struct Vec_800B4D88;
struct Vec_800B50CC;
struct Vec_800B53F0;
struct Vec_800B56CC;
struct Vec_800B62AC;
struct Vec_800B7018;
struct Vec_800B78F8;
struct Vec_800B79E0;
struct Wolf_800B78F8;
struct Vec_800B5D4C { f32 x, y, z; };

struct Col_800B5D4C { u8 pad[0x18]; u32 flags; };

struct Wolf_800B5D4C {
    u8 pad0[0x38];
    Vec_800B5D4C pos;
    f32 f44;
    u8 pad48[0x4C - 0x48];
    f32 f4C;
    u8 pad50[0x60 - 0x50];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Col_800B5D4C *col;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0xC8 - 0xBA];
    f32 fC8;
    u8 padCC[0x390 - 0xCC];
    Wolf_800B5D4C *target;
    u8 pad394[0x400 - 0x394];
    f32 f400;
    f32 f404;
    u8 pad408[0x41C - 0x408];
    s32 f41C;
    s32 f420;
    s32 f424;
    s32 f428;
    s32 f42C;
    u8 pad430[0x434 - 0x430];
    f32 f434;
    f32 f438;
    u8 pad43C[0x444 - 0x43C];
    Vec_800B5D4C f444;
    Vec_800B5D4C f450;
};

extern "C" {
s32 is_vec_xz_cross_negative(void *, void *);
void play_footsteps__14TObjEneBm5WolfFPv(u8 *arg0);
f32 calc_circle_offset__14TObjEneBm5WolfFPvPvPv(Obj_800B79E0 *self, Vec_800B79E0 *target, Vec_800B79E0 *out);
void set_state_by_timer__14TObjEneBm5WolfFi(s32 arg0);
f32 rand_range__9TObjEneDDFff(void *actor, f32 low, f32 high);
extern const f32 TObjEneBm5Wolf__data_805D9D78;
extern const f32 TObjEneBm5Wolf__data_805D9D80;
extern const f32 TObjEneBm5Wolf__data_805D9DAC;
extern const f32 lbl_805D9DCC;
extern const f32 TObjEneBm5Wolf__data_805D9DD0;
extern const f32 lbl_805D9DF8;
extern const f32 lbl_805D9DFC;
extern const f32 lbl_805D9E00;
extern const f32 lbl_805D9E04;
extern const f32 lbl_805D9E08;
extern const f32 lbl_805D9E0C;
void enemy_copy_target_destination__12TObjEneDD_STFv(void *);
void update_velocity__9TObjEneDDFv(void *);
void play_variant_sound__14TObjEneBm5WolfFPv(void *arg0);
void spawn_recoil_dust__14TObjEneBm5WolfFiPv(s32 arg0, u8 *arg1);
s32 play_effect_if_v2__10TObjPlayerFl(s32);
s32 play_sound_effect(void *, void *, s32, s32);
int get_flag_bit0__14TObjEneBm5WolfFPv(void* p);
void select_target__14TObjEneBm5WolfFPv(void *arg0);
void schedule_pack_reaction__14TObjEneBm5WolfFPvis(void *arg0, s32 arg1, s16 arg2);
f32 calc_death_slide_speed__14TObjEneBm5WolfFPvf(Obj_800B76E0 *arg0, f32 farg0);
s32 select_death_direction__14TObjEneBm5WolfFPvPv(Wolf_800B78F8 *s, s32 *heading);
s32 calc_lunge_aim__14TObjEneBm5WolfFPv(u8 *arg0);
}

struct VBase_18_7b3d65
{
  char pad[0x18];
};

struct VObj_18_7b3d65 : VBase_18_7b3d65 {
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
    virtual void m85();
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct VBase_18_4225ac { char pad[0x18]; };

struct VObj_18_4225ac : VBase_18_4225ac {
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};

struct VBase_18_8bca97 { char pad[0x18]; };

struct VObj_18_8bca97 : VBase_18_8bca97 {
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct Arg_800B7530 { s32 kind; s32 val; s32 kind2; f32 fval; };

struct Base_800B7530 { u8 pad[0x18]; };

struct Obj_800B7530 : Base_800B7530 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(void *target, Arg_800B7530 *arg, s32, s32, s32);
    u8 pad2[0x3e0 - 0x1c]; u16 target_id;
};

struct Arg_800B74B8 { s32 kind; s32 val; s32 kind2; f32 fval; };

struct Base_800B74B8 { u8 pad[0x18]; };

struct Obj_800B74B8 : Base_800B74B8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(void *target, Arg_800B74B8 *arg, s32, s32, s32);
    u8 pad2[0x3e0 - 0x1c]; u16 target_id;
};

struct Vec_800B50CC { f32 x, y, z; };

struct Vec_800B56CC { f32 x, y, z; };

struct Node_800B6B50 { s32 f0; Node_800B6B50 *next; };

struct List_800B6B50 { Node_800B6B50 *head; u8 pad[8]; };

struct Ang_800B4AD4 { s32 x, y, z; };

struct VBase_800B4AD4 { u8 pad[0x18]; };

struct VObj_800B4AD4 : VBase_800B4AD4 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void m104();
};
struct Vec_800B7018 { f32 x, y, z; };
struct Obj_800B7018 {
    u8 pad0[0x38];
    Vec_800B7018 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xB0 - 0x64];
    s32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3E4 - 0xC4];
    s32 f3E4;
    u8 pad3E8[0x408 - 0x3E8];
    u32 f408;
    f32 f40C;
    u8 pad410[0x434 - 0x410];
    f32 f434;
    f32 f438;
    u8 pad43C[0x444 - 0x43C];
    Vec_800B7018 f444;
};

struct Vec_800B53F0 { f32 x, y, z; };

struct Base_800B53F0 { u8 pad[0x18]; };

struct VObj_800B53F0 : Base_800B53F0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
};

struct Vec_800B62AC { f32 x, y, z; };

struct VBase_18_b7c757 { char pad[0x18]; };

struct VObj_18_b7c757 : VBase_18_b7c757 {
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
    virtual void m85();
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};

struct Vec_800B4D88 { f32 x, y, z; };

struct Node_800B4D88 { s32 f0; Node_800B4D88 *next; };

struct List_800B4D88 { Node_800B4D88 *head; u8 pad[8]; };

struct VBase_18_a3e1a1 { char pad[0x18]; };

struct VObj_18_a3e1a1 : VBase_18_a3e1a1 {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};

extern "C" {
s32 enemy_validate_retained_target(void *);
s32 is_passing_frame__10TObjMotionFf(void *, f32);
extern const f32 TObjEneBm5Wolf__data_805D9DEC;
extern const f32 lbl_805D9E38;
void enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 spawn_particle_effect(s32, s32);
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern const f32 TObjEneBm5Wolf__data_805D9D8C;
extern const f32 TObjEneBm5Wolf__data_805D9DA4;
extern const f32 TObjEneBm5Wolf__data_805D9DA8;
extern const f32 TObjEneBm5Wolf__data_805D9DB0;
extern const f32 lbl_805D9DC4;
extern const f32 TObjEneBm5Wolf__data_805D9DC8;
extern const f32 TObjEneBm5Wolf__data_805D9DE0;
extern const f32 TObjEneBm5Wolf__data_805D9DF4;
extern const f32 lbl_805D9E10;
#define play_footsteps__14TObjEneBm5WolfFPv ((void (*)(void *actor))&play_footsteps__14TObjEneBm5WolfFPv)
#define play_variant_sound__14TObjEneBm5WolfFPv ((s32 (*)(void *))&play_variant_sound__14TObjEneBm5WolfFPv)
#define set_state_by_timer__14TObjEneBm5WolfFi ((void (*)(void *actor))&set_state_by_timer__14TObjEneBm5WolfFi)
extern const f32 TObjEneBm5Wolf__data_805D9D84;
extern const f32 TObjEneBm5Wolf__data_805D9DBC;
extern const f32 lbl_805D9E14;
extern const f32 lbl_805D9E18;
extern const f32 lbl_805D9E1C;
extern const f32 lbl_805D9E20;
extern const f32 lbl_805D9E24;
extern const f32 lbl_805D9E28;
extern const f32 lbl_805D9E2C;
extern const f32 lbl_805D9E30;
extern "C" {
void queue_destruction__7TObjectFv(void *self);
void appearing_state__14TObjEneBm5WolfFPvi(Obj_800B7018 *o, s32 arg1);
void dispatch_state__14TObjEneBm5WolfFPvUii(TObjEneBm5Wolf *arg0, u32 state, s32 event);
#define spawn_recoil_dust__14TObjEneBm5WolfFiPv ((s32 (*)(void *, void *))&spawn_recoil_dust__14TObjEneBm5WolfFiPv)
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
extern const f32 lbl_805D9DA0;
void returning_state__14TObjEneBm5WolfFPvi(u8 *arg0, s32 arg1);
s32 get_flag_b4__9TObjEneDDFv();
extern const f32 lbl_805D9E34;
s32 is_main_phase_15__9TObjEneDDFv();
void draw_blob_shadow(s32 arg0);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 rotate_matrix_z(s32, s32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern s32 TObjEneBm5Wolf__spawn_timer;
extern s32 TObjEneBm5Wolf__data_805D5128;
extern const f32 lbl_805D9D70;
extern const f32 TObjEneBm5Wolf__data_805D9D74;
extern const f32 TObjEneBm5Wolf__data_805D9D7C;
extern const f32 lbl_805D9D88;
extern const f32 lbl_805D9D90;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__14TObjEneBm5WolfFv(u8 *arg0);
u32 csnVectorUnder(void *, void *, s32);
#define get_flag_bit0__14TObjEneBm5WolfFPv ((s32 (*)(void *))&get_flag_bit0__14TObjEneBm5WolfFPv)
#define select_target__14TObjEneBm5WolfFPv ((s32 (*)(void *))&select_target__14TObjEneBm5WolfFPv)
extern const f32 lbl_805D9DB8;
extern const f32 lbl_805D9DC0;
#define schedule_pack_reaction__14TObjEneBm5WolfFPvis ((s32 (*)(void *, s32, u16))&schedule_pack_reaction__14TObjEneBm5WolfFPvis)
#define calc_death_slide_speed__14TObjEneBm5WolfFPvf ((f32 (*)(void *, void *, f32))&calc_death_slide_speed__14TObjEneBm5WolfFPvf)
#define select_death_direction__14TObjEneBm5WolfFPvPv ((s32 (*)(void *, void *))&select_death_direction__14TObjEneBm5WolfFPvPv)
s32 vec3_add_to(void *, void *);
extern const f32 lbl_805D9D94;
extern const f32 lbl_805D9D98;
extern const f32 lbl_805D9D9C;
#define calc_lunge_aim__14TObjEneBm5WolfFPv ((s32 (*)(void *, int))&calc_lunge_aim__14TObjEneBm5WolfFPv)
s32 TObjEneDD__sub_800BA378(void *, void *);
extern const f32 lbl_805D9DD8;
extern const f32 lbl_805D9DDC;
extern const f32 lbl_805D9DE4;
extern const f32 TObjEneBm5Wolf__data_805D9DE8;
extern const f32 TObjEneBm5Wolf__data_805D9DF0;
struct VBase_800B4820 { char pad[0x18]; };
struct VEne_800B4820 : VBase_800B4820 {
#define VPAD(n) virtual s32 _v##n() { return 0; }
    VPAD(0) VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7) VPAD(8) VPAD(9)
    VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15) VPAD(16) VPAD(17) VPAD(18) VPAD(19)
    VPAD(20) VPAD(21) VPAD(22) VPAD(23) VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29)
    VPAD(30) VPAD(31) VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39)
    VPAD(40) VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47) VPAD(48) VPAD(49)
    VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55) VPAD(56) VPAD(57) VPAD(58) VPAD(59)
    VPAD(60) VPAD(61) VPAD(62) VPAD(63) VPAD(64) VPAD(65) VPAD(66) VPAD(67) VPAD(68) VPAD(69)
    VPAD(70) VPAD(71) VPAD(72) VPAD(73) VPAD(74) VPAD(75) VPAD(76) VPAD(77) VPAD(78) VPAD(79)
    VPAD(80) VPAD(81) VPAD(82) VPAD(83) VPAD(84) VPAD(85) VPAD(86)
    virtual s32 m87();
    VPAD(88) VPAD(89) VPAD(90) VPAD(91) VPAD(92) VPAD(93)
    virtual s32 m94();
#undef VPAD
};
struct VBase2_800B4820 { char pad[0x18]; };
struct VObj2_800B4820 : VBase2_800B4820 { virtual void *m0(); virtual void *m1(); virtual void *m2(); virtual void *m3(); virtual void *m4(); virtual void *m5(); virtual void *m6(); virtual void *m7(); virtual void *m8(); virtual void *m9(); virtual void *m10(); virtual void *m11(); virtual void *m12(); virtual void *m13(); virtual void *m14(); virtual void *m15(); virtual void *m16(); virtual void *m17(); virtual void *m18(); virtual void *m19(); virtual void *m20(); virtual void *m21(); virtual void *m22(); virtual void *m23(); virtual void *m24(); virtual void *m25(); virtual void *m26(); virtual void *m27(); virtual void *m28(); virtual void *m29(); virtual void *m30(); virtual void *m31(); virtual void *m32(); virtual void *m33(); virtual void *m34(); virtual void *m35(); virtual void *m36(); virtual void *m37(); virtual void *m38(); virtual void *m39(); virtual void *m40(); virtual void *m41(); virtual void *m42(); virtual void *m43(); virtual void *m44(); virtual void *m45(); virtual void *m46(); virtual void *m47(); virtual void *m48(); virtual void *m49(); virtual void *m50(); virtual void *m51(); virtual void *m52(); virtual void *m53(); virtual void *m54(); virtual void *m55(); virtual void *m56(); virtual void *m57(); virtual void *m58(); virtual void *m59(); virtual void *m60(); virtual void *m61(); virtual void *m62(); virtual void *m63(); virtual void *m64(); virtual void *m65(); virtual void *m66(); virtual void *m67(); virtual void *m68(); virtual void *m69(); virtual void *m70(); virtual void *m71(); virtual void *m72(); virtual void *m73(); virtual void *m74(); virtual void *m75(); virtual void *m76(); virtual void *m77(); virtual void *m78(); virtual void *m79(); virtual void *m80(); virtual void *m81(); virtual void *m82(); virtual void *m83(); virtual void *m84(); virtual void *m85(); virtual void *m86(); virtual void *m87(); virtual void *m88(); virtual void *m89(); virtual void *m90(); virtual void *m91(); virtual void *m92(); virtual s32 m93(); };

void update_state__14TObjEneBm5WolfFPv(void *arg0);
s32 get_target_info__9TObjEneDDFv();

void TObjEneBm3FlyNest::render_shadows() {  }
struct VBase_18_26a62c { char pad[0x18]; };
struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Vec_800B4824 { f32 x, y, z; };
struct Ent16_800B4824 { s32 f0; s32 f4; s32 f8; s32 fC; };
struct Ent8_800B4824 { s32 f0; u8 *f4; };

s32 update_player_state__9TObjEneDDFv(void *, int, int);
s32 pack_debug_text_position(s32 arg0, s32 arg1);
s32 TObjMapWarp__sub_80141CB0(void *, void *, int, int);
s32 debug_printf_at(s32, const char *, ...);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern char lbl_8043B584[];
extern char lbl_8043B590[];
extern char lbl_8043B59C[];

#pragma push
#pragma opt_common_subs off
void render_debug__14TObjEneBm5WolfFPv(u8 *ene_bm5_wolf) {
    f32 var_f31;
    s32 idx;
    u32 n;
    u8 *temp_r30;
    u32 temp_r3;

    if (get_target_info__9TObjEneDDFv() != 0) {
        debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B584, *(s32 *)((s8 *)ene_bm5_wolf + 0x3DC));
        if (*(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3d8 != 0) {
            debug_printf_at(pack_debug_text_position(0, 1), lbl_8043B590);
        } else {
            debug_printf_at(pack_debug_text_position(0, 1), lbl_8043B59C);
        }
    }
    if (((VObj_18_26a62c *)(ene_bm5_wolf))->m8(lbl_805D9D70, TObjEneBm5Wolf__data_805D9D74) != 0) {
        update_player_state__9TObjEneDDFv(ene_bm5_wolf, 0, 0);
        TObjFish::set_global_param(((TObjEneBm5Wolf *)ene_bm5_wolf)->texlist);
        push_matrix();
        post_translate_matrix(ene_bm5_wolf + 0x38);
        rotate_matrix_y(0, ((TObjEneBm5Wolf *)ene_bm5_wolf)->rotation_y);
        idx = (s32) *(f32 *)((s8 *)ene_bm5_wolf + 0x360);
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x13) {
            idx = 0x12;
        }
        temp_r30 = (*(Ent8_800B4824 * *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->motion_list)[(*(Ent16_800B4824 * *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->action_table)[idx].f4].f4;
        var_f31 = *(f32 *)((s8 *)ene_bm5_wolf + 0x364);
        if (var_f31 < TObjEneBm5Wolf__data_805D9D78) {
            var_f31 = TObjEneBm5Wolf__data_805D9D78;
        } else {
            n = *(u32 *)((s8 *)temp_r30 + 4);
            if (var_f31 > (n - 1)) {
                var_f31 = (f32) n;
            }
        }
        translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D7C);
        TObjPlayer::toggle_particle_effect();
        TObjPlayer::set_global_flag();
        draw_model_motion((void *)(*(s32 *)((s8 *)ene_bm5_wolf + 0x34)), temp_r30, var_f31);
        TObjPlayer::clear_global_state();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    temp_r3 = find_pack_leader__14TObjEneBm5WolfFi(*(s32 *)((s8 *)ene_bm5_wolf + 0x3DC));
    if (temp_r3 != 0) {
        TObjMapWarp__sub_80141CB0((void *)(ene_bm5_wolf + 0x2FC), (void *)(temp_r3 + 0x2FC), 0xFFC0C0C0, 0xFF6060FF);
        return;
    }
    {
    Vec_800B4824 v;
    VecCopy((Vec *)&v, (const Vec *)(ene_bm5_wolf + 0x2FC));
    v.y += TObjEneBm5Wolf__data_805D9D80;
    TObjMapWarp__sub_80141CB0(ene_bm5_wolf + 0x2FC, &v, 0xFFC0C0C0, 0xFF6060FF);
    }
}
#pragma pop

__declspec(section ".rodata") extern const f64 TObjEneBm5Wolf__data_8043B5B0 = 10430.38043493439;

void update_state__14TObjEneBm5WolfFPv(void *ene_bm5_wolf) {
    s32 temp_r31;

    if (get_target_info__9TObjEneDDFv() != 0) {
        temp_r31 = ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3d8;
        select_subtype__14TObjEneBm5WolfFv(ene_bm5_wolf);
        if (temp_r31 != (s32) ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3d8) {
            if (temp_r31 != 0) {
                ((TObjEneBm5Wolf *)ene_bm5_wolf)->update_default();
            } else {
                ((TObjEneBm5Wolf *)ene_bm5_wolf)->apply_global_to_position();
            }
        }
        update_collision_center__14TObjEneBm5WolfFv(ene_bm5_wolf);
    }
}

void TObjEneBm5Wolf::render() {
    Ang_800B4AD4 rot;
    s32 var_r31;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_800B4AD4 *)((u8 *)this))->m104();
        return;
    }
    if (!(this->m_408 & 2) && ((s16) this->mode != 0x11)) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r31 = ((VObj_800B4AD4 *)((u8 *)this))->m9(lbl_805D9E88, lbl_805D9E84, TObjEneBm5Wolf__data_805D9D74);
        } else if (((VObj_800B4AD4 *)((u8 *)this))->m8(lbl_805D9D70, TObjEneBm5Wolf__data_805D9D74) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            if ((s16) this->mode != 0x10) {
                direction_to_rotation_xz(((u8 *)this) + 0x248, &rot.x, &rot.z);
                push_matrix();
                post_translate_matrix(((u8 *)this) + 0x38);
                translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D84, TObjEneBm5Wolf__data_805D9D78);
                rotate_matrix_z(0, rot.z);
                rotate_matrix_x(0, rot.x);
                rotate_matrix_y(0, this->rotation_y);
                translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D7C);
                scale_matrix(0, lbl_805D9D88, TObjEneBm5Wolf__data_805D9D8C, lbl_805D9D90);
                rotate_matrix_x(0, -0x4000);
                draw_blob_shadow(0);
                pop_matrix();
            }
            this->update_secondary_light();
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D78, TObjEneBm5Wolf__data_805D9D7C);
            if (this->m_408 & 4) {
                translate_matrix(0, TObjEneBm5Wolf__data_805D9D78, *(f32 *)((s8 *)((u8 *)this) + 0x40C), TObjEneBm5Wolf__data_805D9D78);
            }
            TObjEneBm5Wolf__spawn_timer = 0;
            TObjEneBm5Wolf__data_805D5128 = -((s32) this->turnOffset / 2);
            TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneBm5Wolf::advance_spawn_timer));
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (var_r31 == 1) {
                this->draw();
            } else {
                this->draw_motion_model();
            }
            TObjEneRe7Berura::set_global_state((s32)NULL);
            pop_matrix();
            this->update_primary_light();
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneBm5Wolf::advance_spawn_timer() {
    if (((s32) TObjEneBm5Wolf__spawn_timer >= 0x16) && ((s32) TObjEneBm5Wolf__spawn_timer < 0x18)) {
        rotate_matrix_y(0, TObjEneBm5Wolf__data_805D5128);
    }
    TObjEneBm5Wolf__spawn_timer += 1;
}

void TObjEneBm5Wolf::despawn_state(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction__7TObjectFv(this);
        break;
    }
}

#define F(T, o) (*(T *)(arg0 + (o)))
void TObjEneBm5Wolf::update_dying_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 *tgt;
    Node_800B4D88 *n;
    u8 *e;
    f32 k;
    Vec_800B4D88 pos;
    Vec_800B4D88 vel;
    f32 c;
    tgt = (s32 *)(arg0 + 0x42C);
    switch (arg1) {
    case 4:
        this->vfunc_96();
        ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
        play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AD1D)), arg0 + 0x38, 0, 0);
        play_effect_if_v2__10TObjPlayerFl(-0x300);
        if (select_death_direction__14TObjEneBm5WolfFPvPv(arg0, tgt) == 0) {
            F(s16, 0xB8) = 0xF;
        } else {
            F(s16, 0xB8) = 0xE;
        }
        TBoss8Dragon__sub_800BB7D4(arg0, 0xF1);
        F(s32, 0x41C) = 0;
        F(f32, 0x434) = calc_death_slide_speed__14TObjEneBm5WolfFPvf(arg0, F(u8 *, 0xD8), *(f32 *)((s8 *)(F(u8 *, 0xD8)) + 0x98));
        F(f32, 0x37C) = F(f32, 0x43C) = TObjEneBm5Wolf__data_805D9D78;
        if (F(s32, 0x3D8) != 0) {
            k = TObjEneBm5Wolf__data_805D9D80;
            for (n = (*(List_800B4D88 *)&TObjEneBm5Wolf__pack_member_list).head; n != NULL; n = n->next) {
                e = (u8 *)play_sound__14TObjEneBm5WolfFPv(n);
                if (e != NULL && *(s32 *)((s8 *)e + 0x3DC) == F(s32, 0x3DC)) {
                    schedule_pack_reaction__14TObjEneBm5WolfFPvis(e, (s32)(k * random_ratio__9TObjCharaFv((s32)arg0)) + 0x14, F(u16, 0x2D4));
                }
            }
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (F(s32, 0x41C) == 2) {
            transition_enemy_state__9TObjEneDDFl(arg0, 0x11);
        }
        break;
    case 1:
        break;
    case 0:
        switch (F(s32, 0x41C)) {
        case 0:
            ((TObjMotion *)arg0)->advance_animation();
            if (((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) {
                F(s32, 0x41C) = 1;
                pos.y = TObjEneBm5Wolf__data_805D9D78;
                if (F(s16, 0xB8) == 0xE) {
                    pos.x = lbl_805D9D94;
                    pos.z = TObjEneBm5Wolf__data_805D9D7C;
                } else {
                    pos.x = lbl_805D9D98;
                    pos.z = TObjEneBm5Wolf__data_805D9D7C;
                }
                rotate_xz_pair_by_angle(&pos.x, &pos.z, F(s32, 0x60));
                vec3_add_to(&pos, arg0 + 0x38);
                TObjPlayer::spawn_dead_spot_type2((s32)&pos, 0x32);
                ((TObjPlayer *)(&pos))->spawn_effect_at_ground(0x46);
            }
            F(s32, 0x60) = approach_angle_limited(F(s32, 0x60), *tgt, 0x300);
            F(s32, 0x60) = (s16)F(s32, 0x60);
            if (F(f32, 0x37C) < lbl_805D9D9C) {
                F(f32, 0x37C) = F(f32, 0x37C) + F(f32, 0x434);
            }
            VecCopy((Vec *)&vel, (const Vec *)(arg0 + 0x308));
            c = normalize_vector_xz__FP3Vec(&vel);
            ((TObjEneDD *)arg0)->move_clamped_on_ground(vel.x, vel.z, c);
            if (is_passing_frame__10TObjMotionFf(arg0, lbl_805D9DA0) != 0) {
                spawn_recoil_dust__14TObjEneBm5WolfFiPv(arg0, &vel);
            }
            F(f32, 0x308) = F(f32, 0x308) * TObjEneBm5Wolf__data_805D9DA4;
            F(f32, 0x310) = F(f32, 0x310) * TObjEneBm5Wolf__data_805D9DA4;
            advance_pose_turn__14TObjEneBm5WolfFPvi(arg0, F(s32, 0x60));
            ((VObj_18_b7c757 *)(arg0))->m86();
            break;
        case 1:
            F(f32, 0x3C) = F(f32, 0x3C) - TObjEneBm5Wolf__data_805D9DA8;
            F(f32, 0x43C) = F(f32, 0x43C) + TObjEneBm5Wolf__data_805D9DA8;
            if (F(f32, 0x43C) > TObjEneBm5Wolf__data_805D9D74) {
                F(s32, 0x41C) = 2;
            }
            break;
        }
        break;
    case 5:
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::hurt_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->vfunc_96();
        TBoss8Dragon__sub_800BB7D4(arg0, 0xF1);
        this->roamingTimer = 0;
        this->m_42c = 0;
        this->requested_action = 6;
        this->roamingSubstate = 0;
        if (this->referenceHp - this->hp < 0x14) {
            play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AB1B)), (u8 *)&this->position, 0, 0);
            play_effect_if_v2__10TObjPlayerFl(-0x500);
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if ((this->motion_flags) & 0x10) {
            switch (this->m_378) {
            case 11:
                transition_enemy_state__9TObjEneDDFl((void *) arg0, 0xD);
                break;
            case 2:
                transition_enemy_state__9TObjEneDDFl((void *) arg0, 7);
                break;
            default:
                transition_enemy_state__9TObjEneDDFl((void *) arg0, this->m_378);
                break;
            }
        }
        break;
    case 0: {
        Vec_800B50CC v;
        ((TObjMotion *)arg0)->advance_animation();
        VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x308));
        {
        f32 c = normalize_vector_xz__FP3Vec(&v);
        ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(v.x, v.z, c);
        }
        if (this->roamingSubstate == 0) {
            (*(f32 *)&this->unk_308) *= TObjEneBm5Wolf__data_805D9DAC;
            this->m_310 *= TObjEneBm5Wolf__data_805D9DAC;
        } else {
            (*(f32 *)&this->unk_308) *= TObjEneBm5Wolf__data_805D9DB0;
            this->m_310 *= TObjEneBm5Wolf__data_805D9DB0;
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x300);
            this->rotation_y = (s16) this->rotation_y;
            if (is_passing_frame__10TObjMotionFf(arg0, lbl_805D9DA0) != 0) {
                spawn_recoil_dust__14TObjEneBm5WolfFiPv(arg0, &v);
            }
        }
        this->vfunc_89();
        break;
    }
    case 5:
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

void TObjEneBm5Wolf::action(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        ((VEne_800B4820 *)arg0)->m94();
        ((TObjEneDD *)arg0)->set_field_378(7);
        this->requested_action = 0xB;
        this->roamingSubstate = 0;
        find_pack_leader__14TObjEneBm5WolfFi((s32)(*(s32 *)&this->_pad3DC));
        return;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 7);
        }
    case 5:
        return;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        advance_pose_turn__14TObjEneBm5WolfFPvi(arg0, this->rotation_y);
        if (is_passing_frame__10TObjMotionFf(arg0, TObjEneBm5Wolf__data_805D9DB4) != 0) {
            play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3AA1A)), (u8 *)&this->position, 0, 0);
            play_effect_if_v2__10TObjPlayerFl(-0x100);
        }
        this->roamingSubstate = (this->roamingSubstate + 1);
        if (this->roamingSubstate == 0x1E) {
            apply_mourning_zalure();
        } else if (this->roamingSubstate == 0x28) {
            apply_mourning_jellen();
        }
        ((VEne_800B4820 *)arg0)->m87();
        break;
    }
}

void TObjEneBm5Wolf::repositioning_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        ((TObjEneDD *)arg0)->set_field_378(0xD);
        this->vfunc_96();
        this->roamingSubstate = 0;
        this->m_42c = 0;
        this->roamingTimer = 0;
        return;
    case 3:
        if (this->roamingSubstate == 2) {
            if (this->target != 0U) {
                transition_enemy_state__9TObjEneDDFl(arg0, 0xA);
            } else {
                transition_enemy_state__9TObjEneDDFl(arg0, 7);
            }
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (this->roamingSubstate) {
        case 0: {
            f32 dx;
            f32 dz;
            this->m_42c = ((this->roamingTimer >> 1) << 0xC) + 0x1800;
            if (this->roamingTimer & 1) {
                this->m_42c = -this->m_42c;
            }
            if (get_flag_bit0__14TObjEneBm5WolfFPv(arg0) == 0) {
                this->m_42c = -this->m_42c;
            }
            this->m_42c += this->rotation_y;
            (this->roamingTimer)++;
            if (this->roamingTimer > 8) {
                this->roamingSubstate = 2;
            }
            dx = lbl_805D9DB8 * sin_table_lookup(this->m_42c);
            dz = lbl_805D9DB8 * cos_table_lookup(this->m_42c);
            *(f32 *)(this->m_410 + 0x38) = *(f32 *)((s8 *)arg0 + 0x38) + dx;
            *(f32 *)(this->m_410 + 0x3C) = *(f32 *)((s8 *)arg0 + 0x3C);
            *(f32 *)(this->m_410 + 0x40) = *(f32 *)((s8 *)arg0 + 0x40) + dz;
            ((TObjPlayer *)(this->m_410))->update_collisions();
            if (!(*(s32 *)((s8 *)(*(void **)(this->m_410 + 0xA4)) + 0x18) & 0x380000)) {
                dx *= TObjEneBm5Wolf__data_805D9DBC;
                dz *= TObjEneBm5Wolf__data_805D9DBC;
                if (((TBoss5Gryphon *)arg0)->enemy_probe_wall_ahead(dx, dz, TObjEneBm5Wolf__data_805D9D8C) == 0U) {
                    Vec_800B53F0 v;
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x2FC));
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder(&v, (u8 *)&this->m_120, 0x15) != 0U) {
                        this->roamingSubstate = 1;
                        this->requested_action = 0x12;
                        *(f32 *)((s8 *)arg0 + 0x3A0) = sin_table_lookup(this->m_42c);
                        *(f32 *)((s8 *)arg0 + 0x3A4) = TObjEneBm5Wolf__data_805D9D78;
                        *(f32 *)((s8 *)arg0 + 0x3A8) = cos_table_lookup(this->m_42c);
                    }
                }
            }
            break;
        }
        case 1:
            if (((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) {
                select_target__14TObjEneBm5WolfFPv(arg0);
                this->roamingSubstate = 2;
            }
            play_proximity_effect();
            ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), lbl_805D9DC0);
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0xF00);
            advance_pose_turn__14TObjEneBm5WolfFPvi(arg0, this->m_42c);
            this->vfunc_89();
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void returning_state__14TObjEneBm5WolfFPvi(u8 *actor, s32 arg1) {
    Vec_800B56CC *home = (Vec_800B56CC *)(actor + 0x450);
    f32 lim = *(f32 *)((s8 *)actor + 0x434);
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 1;
        ((TObjEneDD *)actor)->set_field_378(0xC);
        ((TObjEneBm5Wolf *)(actor))->vfunc_96();
        *(f32 *)((s8 *)actor + 0x400) = lbl_805D9DC4;
        *(s32 *)((s8 *)actor + 0x41C) = 0;
        VecCopy((Vec *)home, (const Vec *)(actor + 0x38));
        TObjBoss2Tunnel::calc_scaled_value(0x200, lbl_805D9DC4);
        *(s32 *)((s8 *)actor + 0x430) = *(s32 *)((s8 *)actor + 0x60);
        if (((TObjEneDD_ST *)actor)->enemy_has_live_target() != 0) {
            Vec_800B56CC a;
            Vec_800B56CC d;
            u8 *t;
            a.x = sin_table_lookup((s32)(*(s32 *)((s8 *)actor + 0x60)));
            a.z = cos_table_lookup((s32)(*(s32 *)((s8 *)actor + 0x60)));
            t = *(u8 **)((s8 *)actor + 0x390);
            d.x = *(f32 *)((s8 *)t + 0x38) - *(f32 *)((s8 *)actor + 0x38);
            d.z = *(f32 *)((s8 *)t + 0x40) - *(f32 *)((s8 *)actor + 0x40);
            if (is_vec_xz_cross_negative(&a, &d) != 0) {
                *(s32 *)((s8 *)actor + 0x42C) = 0x5000;
            } else {
                *(s32 *)((s8 *)actor + 0x42C) = -0x5000;
            }
        } else if (((f32 (*)(void *)) random_ratio__9TObjCharaFv)(actor) < TObjEneBm5Wolf__data_805D9DAC) {
            *(s32 *)((s8 *)actor + 0x42C) = 0x5000;
        } else {
            *(s32 *)((s8 *)actor + 0x42C) = -0x5000;
        }
        *(s32 *)((s8 *)actor + 0x42C) = *(s32 *)((s8 *)actor + 0x42C) + *(s32 *)((s8 *)actor + 0x430);
        break;
    case 3:
        if (*(u8 **)((s8 *)actor + 0x390) == NULL || *(s32 *)((s8 *)actor + 0x41C) > 0x96) {
            transition_enemy_state__9TObjEneDDFl(actor, 7);
        } else if (*(f32 *)((s8 *)actor + 0x3AC) < lim) {
            transition_enemy_state__9TObjEneDDFl(actor, 0xA);
        }
        break;
    case 5:
        break;
    case 0:
        (*(s32 *)((s8 *)actor + 0x41C))++;
        ((TObjMotion *)actor)->advance_animation();
        if (((TObjEneEpsilon *)actor)->update_death_check() != 0) {
            play_footsteps__14TObjEneBm5WolfFPv(actor);
            *(s32 *)((s8 *)actor + 0x42C) = approach_angle_limited(*(s32 *)((s8 *)actor + 0x42C), *(s32 *)((s8 *)actor + 0x430), 0x100);
            *(f32 *)((s8 *)actor + 0x394) = TObjEneBm5Wolf__data_805D9DC8 * sin_table_lookup((s32)(*(s32 *)((s8 *)actor + 0x42C))) + home->x;
            *(f32 *)((s8 *)actor + 0x39C) = TObjEneBm5Wolf__data_805D9DC8 * cos_table_lookup((s32)(*(s32 *)((s8 *)actor + 0x42C))) + home->z;
            update_velocity__9TObjEneDDFv(actor);
            approach_target__14TObjEneBm5WolfFPvf(actor, lbl_805D9DCC);
            *(f32 *)((s8 *)actor + 0xC8) = TObjEneBm5Wolf__data_805D9DD0 * *(f32 *)((s8 *)actor + 0x404);
            enemy_turn_and_move_on_ground(actor, 0x500, *(f32 *)((s8 *)actor + 0x404));
            ((TObjEneBm5Wolf *)actor)->turn_pose_to_target();
            ((TObjEneBm5Wolf *)(actor))->vfunc_89();
        }
        break;
    }
}
#pragma pop

__declspec(section ".sdata2") extern const f32 lbl_805D9D70 = 400.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D74 = 20.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D78 = 0.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D7C = -10.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D80 = 50.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D84 = 0.30000001192092896f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D88 = 1.2000000476837158f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9D8C = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D90 = 3.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D94 = 12.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D98 = -12.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9D9C = 28.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DA0 = 22.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DA4 = 0.800000011920929f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DA8 = 0.10000000149011612f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DAC = 0.5f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DB0 = 0.8999999761581421f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DB4 = 10.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DB8 = 16.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DBC = 2.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DC0 = 1.7999999523162842f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DC4 = 1.600000023841858f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DC8 = 90.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DCC = 0.20000000298023224f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DD0 = 1.100000023841858f;
#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::update_lunge(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    f32 temp_f3;
    s32 temp_r4;
    switch (arg1) {
    case 4:
        this->requested_action = 0xC;
        ((TObjEneDD *)arg0)->set_field_378(0xD);
        this->vfunc_96();
        this->m_408 = (s32) (this->m_408 & 0xFFFFFFFD);
        temp_r4 = this->m_408 | 4;
        this->m_408 = temp_r4;
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        this->m_42c = calc_lunge_aim__14TObjEneBm5WolfFPv(arg0, temp_r4);
        this->m_430 = 0;
        if (this->destinationDistance > 40.0f) {
            this->destinationDistance = 40.0f;
        }
        temp_f3 = this->destinationDistance / lbl_805D9DD8;
        this->desiredSpeed = temp_f3;
        this->currentSpeed = temp_f3;
        this->nearTarget = 0;
        *(f32 *)&this->_pad40C = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        this->stoppingDistance = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        this->m_43c = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D74);
        *(f32 *)&this->unk_438 = (f32) lbl_805D9DDC;
        return;
    case 3:
        if ((s32) this->roamingSubstate == 2) {
            transition_enemy_state__9TObjEneDDFl(arg0, 0xD);
        }
        break;
    case 0:
        switch (this->roamingSubstate) {
        case 0:
            ((TObjMotion *)arg0)->advance_animation();
            if (((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) {
                if ((s32) this->nearTarget != 0) {
                    this->roamingSubstate = 2;
                } else {
                    this->roamingSubstate = 1;
                    this->roamingTimer = 0;
                }
            }
            if (is_passing_frame__10TObjMotionFf(arg0, TObjEneBm5Wolf__data_805D9DE0) != 0) {
                spawn_particle_effect((s32)(arg0 + 0x38), 0xF3);
            }
            if (is_passing_frame__10TObjMotionFf(arg0, lbl_805D9DE4) != 0) {
                play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x3E420)), (u8 *)&this->position, 0, 0);
            }
            if (is_passing_frame__10TObjMotionFf(arg0, TObjEneBm5Wolf__data_805D9DE8) != 0) {
                play_sound_effect((void *)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A821)), (u8 *)&this->position, 0, 0);
                play_effect_if_v2__10TObjPlayerFl(-0x500);
            }
            if (is_passing_frame__10TObjMotionFf(arg0, (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9D74))) != 0) {
                this->nearTarget = 0;
                if (enemy_validate_retained_target(arg0) != 0) {
                    if (((VObj_18_a3e1a1 *)(this->target))->m18(arg0, (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0) {
                        ((VObj_18_a3e1a1 *)(this->target))->m20(arg0, (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                        ((VObj_18_a3e1a1 *)(this->target))->m23(arg0, TObjEneBm5Wolf__data_805D9DEC);
                        this->nearTarget = 1;
                        if ((check_v2_mode__9TObjEneDDFv() != 0) && (random_ratio__9TObjCharaFv((s32)arg0) <= (*(f32 *)&TObjEneBm5Wolf__data_805D9DA8))) {
                            if ((s32) this->m_3d8 != 0) {
                                TObjEneDD__sub_800BA378(arg0, this->target);
                            } else {
                                TObjEneDD::send_damage_message((s32)arg0, (u8 *)this->target);
                            }
                        }
                    }
                }
            }
            approach_target__14TObjEneBm5WolfFPvf(arg0, (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DA8)));
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_42c, 0x1000);
            this->rotation_y = (s32) (s16) this->rotation_y;
            advance_pose_turn__14TObjEneBm5WolfFPvi(arg0, this->rotation_y);
            if (this->frame <= TObjEneBm5Wolf__data_805D9DF0) {
                ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), this->currentSpeed);
                temp_f2 = this->frame - TObjEneBm5Wolf__data_805D9DF4;
                *(f32 *)&this->_pad40C = (f32) ((this->stoppingDistance + ((*(f32 *)&this->unk_438 * (temp_f2 * temp_f2)) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D74))) - *(f32 *)((s8 *)arg0 + 0x3C));
            } else {
                if ((s32) this->nearTarget == 0) {
                    this->currentSpeed = (f32) (this->currentSpeed * (*(f32 *)&TObjEneBm5Wolf__data_805D9DA4));
                    ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), this->currentSpeed);
                }
                *(f32 *)&this->_pad40C = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
            }
            break;
        case 1:
            ((TObjMotion *)arg0)->advance_animation();
            this->roamingTimer = (this->roamingTimer + 1);
            if ((s32) this->roamingTimer >= 0xA) {
                this->roamingSubstate = 2;
            }
            advance_pose_turn__14TObjEneBm5WolfFPvi(arg0, this->rotation_y);
            if ((s32) this->nearTarget == 0) {
                this->currentSpeed = (f32) (this->currentSpeed * (*(f32 *)&TObjEneBm5Wolf__data_805D9DA4));
                ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), this->currentSpeed);
            }
            break;
        }
        this->vfunc_89();
        return;
    case 5:
        *(f32 *)&this->_pad40C = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::circling_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec_800B5D4C *b;
    Wolf_800B5D4C *self = (Wolf_800B5D4C *)arg0;
    Vec_800B5D4C *a;
    f32 vx;
    f32 vz;
    a = &self->f444;
    b = &self->f450;
    switch (arg1) {
    case 4:
        self->fB8 = 1;
        ((TObjEneDD *)self)->set_field_378(10);
        this->vfunc_96();
        self->f400 = lbl_805D9DF8;
        self->f41C = 0;
        self->f420 = 0;
        self->f424 = 0;
        self->f428 = 0;
        self->f42C = 0;
        self->f434 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        self->f438 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        a->x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        a->y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        a->z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        b->x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        b->y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        b->z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        ((TObjEneDD_ST *)self)->set_active();
        break;
    case 3:
        if (self->target == NULL) {
            transition_enemy_state__9TObjEneDDFl(self, 7);
            break;
        }
        if (self->f41C > 450) {
            self->f41C = 0;
            if (((f32 (*)(void))random_ratio__9TObjCharaFv)() < (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC)) {
                transition_enemy_state__9TObjEneDDFl(self, 11);
            }
        } else if (self->f41C > 45) {
            f32 dz = self->pos.z - self->target->pos.z;
            f32 dx = self->pos.x - self->target->pos.x;
            f32 d = dx * dx + dz * dz;
            if (d >= lbl_805D9DFC) {
                ((void (*)(void *))set_state_by_timer__14TObjEneBm5WolfFi)(self);
            } else if (d < lbl_805D9E00) {
                transition_enemy_state__9TObjEneDDFl(self, 11);
            } else {
                f32 c;
                vx = sin_table_lookup(self->target->angle);
                c = cos_table_lookup(self->target->angle);
                vz = vx * b->x + c * b->z;
                if (vz < cos_table_lookup(0x6AAA)) {
                    transition_enemy_state__9TObjEneDDFl(self, 11);
                }
            }
        }
        break;
    case 0:
        ((TObjMotion *)self)->advance_animation();
        if (((TObjEneEpsilon *)self)->update_death_check() != 0) {
            if (self->f424 == 0) {
                Vec_800B5D4C fwd;
                Vec_800B5D4C to;
                self->f424 = 1;
                VecCopy((Vec *)a, (const Vec *)&self->target->pos);
                self->f434 = calc_circle_offset__14TObjEneBm5WolfFPvPvPv((Obj_800B79E0 *)self, (Vec_800B79E0 *)a, (Vec_800B79E0 *)b);
                self->f438 = rand_range__9TObjEneDDFff(self, (*(f32 *)&TObjEneBm5Wolf__data_805D9D80), lbl_805D9E04);
                fwd.x = sin_table_lookup(self->angle);
                fwd.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
                fwd.z = cos_table_lookup(self->angle);
                to.x = self->target->pos.x - self->pos.x;
                to.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
                to.z = self->target->pos.z - self->pos.z;
                if (is_vec_xz_cross_negative(&fwd, &to) != 0) {
                    self->f42C = -1;
                } else {
                    self->f42C = 1;
                }
            }
            self->f41C++;
            play_footsteps__14TObjEneBm5WolfFPv((u8 *)self);
            if (self->f428 > 0) {
                self->f428--;
                if (self->f42C > 0) {
                    self->f434 -= (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC);
                } else {
                    self->f434 += (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC);
                }
            } else {
                f32 cur = self->f434;
                f32 tgt = self->f438;
                f32 diff = cur - tgt;
                if (diff > (*(f32 *)&lbl_805D9DCC)) {
                    self->f434 = cur - (*(f32 *)&lbl_805D9DCC);
                } else if (diff < lbl_805D9E08) {
                    self->f434 = cur + (*(f32 *)&lbl_805D9DCC);
                } else {
                    self->f434 = tgt;
                }
            }
            switch (self->f424) {
            case 1: {
                self->f400 = lbl_805D9DF8;
                approach_target__14TObjEneBm5WolfFPvf(self, lbl_805D9E0C);
                calc_circle_offset__14TObjEneBm5WolfFPvPvPv((Obj_800B79E0 *)self, (Vec_800B79E0 *)a, (Vec_800B79E0 *)b);
                if (self->f42C >= 0) {
                    vx = b->z;
                    vz = -b->x;
                } else {
                    vz = b->x;
                    vx = -b->z;
                }
                if (((TObjEneDD *)self)->has_move_failures(1) != 0) {
                    ((TObjEneDD_ST *)self)->set_active();
                } else {
                    ((TObjEneDD *)self)->clear_field_388();
                }
                ((TObjEneDD *)self)->move_with_wall_slide_on_ground(vx, vz, self->f404);
                if (((TObjEneDD *)self)->has_move_failures(10) != 0) {
                    self->f420 = 0;
                    self->f424 = 2;
                }
                break;
            }
            case 2: {
                s32 ang;
                f32 sx;
                f32 cz;
                self->f400 = (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC);
                approach_target__14TObjEneBm5WolfFPvf(self, lbl_805D9E0C);
                self->f420++;
                if (self->f420 >= 40) {
                    ang = self->angle;
                } else {
                    ang = self->angle + (self->f42C << 11);
                }
                sx = sin_table_lookup(ang);
                cz = cos_table_lookup(ang);
                if (((TObjEneDD *)self)->has_move_failures(2) != 0) {
                    self->f420 = 0;
                    ((TObjEneDD_ST *)self)->set_active();
                } else {
                    ((TObjEneDD *)self)->clear_field_388();
                }
                ((TObjEneDD *)self)->move_with_wall_slide_on_ground(sx, cz, self->f404);
                if (self->f420 >= 80) {
                    self->f424 = 0;
                }
                break;
            }
            }
            self->angle = approach_angle_limited(self->angle,
                (s32)((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float(self->pos.x - self->f44, self->pos.z - self->f4C)),
                0x200);
            self->angle = (s16)self->angle;
            self->fC8 = (*(f32 *)&TObjEneBm5Wolf__data_805D9DD0) * self->f404;
            ((TObjEneBm5Wolf *)self)->turn_pose_to_target();
            this->vfunc_89();
            if (self->col->flags & 0x380000) {
                self->f428 = 20;
            }
        }
        break;
    case 5:
        ((TObjEneDD *)self)->clear_field_388();
        break;
    }
}
#pragma pop

void TObjEneBm5Wolf::flanking_state(s32 arg1) {
    s32 *ang = (s32 *)(((u8 *)this) + 0x42C);
    Vec_800B62AC *dst = (Vec_800B62AC *)(((u8 *)this) + 0x444);
    Vec_800B62AC *src = (Vec_800B62AC *)(((u8 *)this) + 0x450);
    switch (arg1) {
    case 4:
        this->requested_action = 3;
        set_field_378(9);
        this->vfunc_96();
        this->desiredSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DBC);
        this->roamingSubstate = 0;
        this->roamingTimer = 0;
        calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, 0x1C71, src, ang);
        VecCopy((Vec *)dst, (const Vec *)src);
        this->m_430 = *ang;
        break;
    case 3:
        if (this->target == 0U) {
            transition_enemy_state__9TObjEneDDFl(this, 7);
        } else if (is_passing_frame__10TObjMotionFf(this, *(f32 *)&this->frame_count - (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0 && this->destinationDistance < (*(f32 *)&TObjEneBm5Wolf__data_805D9DC8)) {
            transition_enemy_state__9TObjEneDDFl(this, 0xA);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        advance_animation();
        if (((TObjEneEpsilon *)((u8 *)this))->update_death_check() != 0) {
            if (is_passing_frame__10TObjMotionFf(((u8 *)this), TObjEneBm5Wolf__data_805D9DE0) != 0) {
                spawn_particle_effect((s32)(((u8 *)this) + 0x38), 0xF3);
            }
            this->play_proximity_effect();
            if (is_passing_frame__10TObjMotionFf(this, TObjEneBm5Wolf__data_805D9DF4) != 0) {
                enemy_copy_target_destination__12TObjEneDD_STFv(this);
                update_velocity__9TObjEneDDFv(this);
                if (this->roamingTimer == 0) {
                    this->roamingTimer = 1;
                    calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, -0x1C71, src, ang);
                } else {
                    this->roamingTimer = 0;
                    calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(this, 0x1C71, src, ang);
                }
            }
            if (is_passing_frame__10TObjMotionFf(this, *(f32 *)&this->frame_count - (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0) {
                VecCopy((Vec *)dst, (const Vec *)src);
                this->m_430 = *ang;
            }
            this->rotation_y = approach_angle_limited(this->rotation_y, this->m_430, 0x800);
            this->rotation_y = (s16)this->rotation_y;
            if (this->frame >= TObjEneBm5Wolf__data_805D9DF4) {
                this->currentSpeed *= (*(f32 *)&TObjEneBm5Wolf__data_805D9DB0);
                this->play_speed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC) * this->currentSpeed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->currentSpeed);
            } else {
                approach_target__14TObjEneBm5WolfFPvf(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                this->play_speed = (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC) * this->currentSpeed;
                this->move_with_wall_slide_on_ground(dst->x, dst->z, this->currentSpeed);
            }
            this->turn_pose_to_target();
            this->vfunc_89();
        }
        break;
    }
}

void TObjEneBm5Wolf::chasing_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;
    switch (arg1) {
    case 4:
        this->requested_action = 2;
        ((TObjEneDD *)arg0)->set_field_378(8);
        this->vfunc_96();
        this->desiredSpeed = (f32) (*(f32 *)&lbl_805D9DC4);
        this->roamingSubstate = 0;
        break;
    case 3:
        if ((u32) this->target == 0U) {
            transition_enemy_state__9TObjEneDDFl(arg0, 7);
            break;
        }
        if (((TObjEneDD *)arg0)->has_move_failures(0xA) != 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 9);
            break;
        }
        if (((s32) this->roamingSubstate == 0) && (is_passing_frame__10TObjMotionFf(arg0, *(f32 *)&this->frame_count - (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) != 0) && (this->destinationDistance < (*(f32 *)&TObjEneBm5Wolf__data_805D9DC8))) {
            transition_enemy_state__9TObjEneDDFl(arg0, 0xA);
            break;
        }
    case 5:
    case 1:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (is_passing_frame__10TObjMotionFf(arg0, TObjEneBm5Wolf__data_805D9DE0) != 0) {
            spawn_particle_effect((s32)(arg0 + 0x38), 0xF3);
        }
        if ((s16) this->requested_action == 2) {
            play_proximity_effect();
        }
        if (((TObjEneEpsilon *)arg0)->update_death_check() != 0) {
            enemy_copy_target_destination__12TObjEneDD_STFv(arg0);
            update_velocity__9TObjEneDDFv(arg0);
            if (this->frame >= TObjEneBm5Wolf__data_805D9DF4) {
                this->currentSpeed = (f32) (this->currentSpeed * (*(f32 *)&TObjEneBm5Wolf__data_805D9DB0));
                this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DA4) * this->currentSpeed);
                temp_f1 = this->currentSpeed;
                enemy_turn_and_move_on_ground(arg0, (lbl_805D9E10 * temp_f1), temp_f1);
            } else {
                approach_target__14TObjEneBm5WolfFPvf(arg0, (*(f32 *)&TObjEneBm5Wolf__data_805D9DA8));
                this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DA4) * this->currentSpeed);
                temp_f1_2 = this->currentSpeed;
                enemy_turn_and_move_on_ground(arg0, (lbl_805D9E10 * temp_f1_2), temp_f1_2);
            }
            turn_pose_to_target();
            this->vfunc_89();
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::roaming_state(int event) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f31;
    f32 temp_f3;
    f32 square;
    s32 temp_r30;
    u8 *temp_r3;
    switch (event) {
    case 4:
        this->requested_action = 1;
        set_field_378(7);
        this->vfunc_96();
        this->roamingTimer = 0;
        this->roamingSubstate = 0;
        this->randomPhase = actor_rand_int((s32)this, 0x14);
        this->nearTarget = 0;
        temp_r30 = (s32) (lbl_805D9E14 * random_ratio__9TObjCharaFv((s32)this));
        temp_f31 = lbl_805D9E18 * random_ratio__9TObjCharaFv((s32)this);
        this->destination[0] = (f32) ((temp_f31 * sin_table_lookup(temp_r30)) + this->groupAnchor[0]);
        this->destination[2] = (f32) ((temp_f31 * cos_table_lookup(temp_r30)) + this->groupAnchor[2]);
        this->desiredSpeed = (f32) ((lbl_805D9DF8 * random_ratio__9TObjCharaFv((s32)this)) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D84));
        this->currentSpeed = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        this->stoppingDistance = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
        update_velocity__9TObjEneDDFv(this);
        return;
    case 3:
        if ((s32) this->nearTarget != 0) {
            set_state_by_timer__14TObjEneBm5WolfFi(this);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (play_variant_sound__14TObjEneBm5WolfFPv(this) != 0) {
            temp_r3 = (u8 *)this->target;
            temp_f3 = *(f32 *)((s8 *)temp_r3 + 0x38) - this->position.x;
            temp_f1 = *(f32 *)((s8 *)temp_r3 + 0x40) - this->position.z;
            square = temp_f3 * temp_f3;
            square = (temp_f1 * temp_f1) + square;
            if (square < lbl_805D9E1C) {
                this->nearTarget = 1;
            }
            turn_pose_to_target();
        } else {
            advance_pose_turn__14TObjEneBm5WolfFPvi(this, this->rotation_y);
        }
        switch (this->roamingSubstate) {
        case 0:
            play_footsteps__14TObjEneBm5WolfFPv(this);
            update_velocity__9TObjEneDDFv(this);
            approach_target__14TObjEneBm5WolfFPvf(this, lbl_805D9E20);
            this->roamingTimer = (this->roamingTimer + 1);
            if ((this->destinationDistance < this->stoppingDistance) || ((s32) this->roamingTimer > 0x64)) {
                this->roamingSubstate = 1;
                this->desiredSpeed = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
            } else if (((s32)has_move_failures(0x14)) != 0) {
                this->roamingTimer = 0;
                choose_roaming_destination();
                this->desiredSpeed = rand_range__9TObjEneDDFff(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D84), (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                this->stoppingDistance = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
            }
            this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DD0) * this->currentSpeed);
            temp_f1_2 = this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, (s32)(lbl_805D9E24 * temp_f1_2), (f32)temp_f1_2);
            break;
        case 1:
            play_footsteps__14TObjEneBm5WolfFPv(this);
            update_velocity__9TObjEneDDFv(this);
            approach_target__14TObjEneBm5WolfFPvf(this, lbl_805D9E28);
            if (this->currentSpeed <= (*(f32 *)&TObjEneBm5Wolf__data_805D9DA8)) {
                this->roamingSubstate = 2;
                this->roamingTimer = (s32) rand_range__9TObjEneDDFff(this, lbl_805D9E2C, lbl_805D9E30);
                this->requested_action = 0;
            }
            this->play_speed = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DD0) * this->currentSpeed);
            temp_f1_3 = this->currentSpeed;
            enemy_turn_and_move_on_ground((u8 *)this, (s32)(lbl_805D9E24 * temp_f1_3), (f32)temp_f1_3);
            break;
        case 2:
            this->requested_action = 0;
            this->roamingTimer = (this->roamingTimer - 1);
            if ((s32) this->roamingTimer <= 0) {
                choose_roaming_destination();
                this->desiredSpeed = rand_range__9TObjEneDDFff(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D84), (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
                this->currentSpeed = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
                this->stoppingDistance = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) + TObjBoss2Tunnel::calc_scaled_value(0x200, this->desiredSpeed));
                this->roamingSubstate = 0;
                this->requested_action = 1;
            }
            this->vfunc_102();
            break;
        }
        this->vfunc_89();
        break;
    }
}
#pragma pop

void TObjEneBm5Wolf::empty_state() {  }

#define VTABLE_ENE ((VObj2_800B4820 *) arg0)

typedef struct VBase_18_7b3d65 VBase_18_7b3d65;
typedef struct VObj_18_7b3d65 VObj_18_7b3d65;

void TObjEneBm5Wolf::howling_state(s32 arg1) {
    Node_800B6B50 *p;
    void *r;
    switch (arg1) {
    case 4:
        this->requested_action = 0x10;
        set_field_378(7);
        this->vfunc_95();
        this->roamingSubstate = 0;
        break;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            transition_enemy_state__9TObjEneDDFl(this, 7);
        }
        break;
    case 5:
        break;
    case 0:
        (this->roamingSubstate)++;
        advance_animation();
        if (this->requested_action == 0x10) {
            is_passing_frame__10TObjMotionFf(this, TObjEneBm5Wolf__data_805D9DEC);
        } else if (this->requested_action == 0xB && is_passing_frame__10TObjMotionFf(this, lbl_805D9E34) != 0) {
            play_sound_effect((void *)((TObjEnemy *)(this))->remap_sound_for_area((s32)(0x3A819)), ((u8 *)this) + 0x38, 0, 0);
            play_effect_if_v2__10TObjPlayerFl(-0x200);
        }
        if (this->roamingSubstate == 0x3C) {
            for (p = (*(List_800B6B50 *)&TObjEneBm5Wolf__instance_list).head; p != NULL; p = p->next) {
                r = play_sound__14TObjEneBm5WolfFPv(p);
                if (*(s32 *)&this->_pad3DC == get_group_id__14TObjEneBm5WolfFPv()) {
                    ((TObjEneBm5Wolf *)r)->set_attack_flag();
                }
            }
        }
        if (enemy_validate_retained_target(this) != 0) {
            if (this->requested_action == 0x10) {
                this->turn_pose_to_target();
            } else {
                this->turnOffset = 0;
            }
        } else {
            play_variant_sound__14TObjEneBm5WolfFPv(this);
        }
        this->vfunc_102();
        this->vfunc_88();
        break;
    }
}

void TObjEneBm5Wolf::standing_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  switch (arg1)
  {
    case 4:
      this->requested_action = 5;
      ((TObjEneDD *)arg0)->set_field_378(7);
      (this->vfunc_95());
      this->roamingSubstate = 0;
      return;
    case 3:
      if ((this->roamingSubstate) > 0x3C)
    {
      transition_enemy_state__9TObjEneDDFl(arg0, 7);
    }
    case 5:
      return;
    case 0:
      this->roamingSubstate = (s32) ((this->roamingSubstate) + 1);
      ((TObjMotion *)arg0)->advance_animation();
      is_passing_frame__10TObjMotionFf(arg0, TObjEneBm5Wolf__data_805D9DEC);
      if (enemy_validate_retained_target(arg0) != 0)
    {
      enemy_copy_target_destination__12TObjEneDD_STFv(arg0);
      update_velocity__9TObjEneDDFv(arg0);
      turn_pose_to_target();
    }
    else
    {
      play_variant_sound__14TObjEneBm5WolfFPv(arg0);
    }
      (this->vfunc_102());
      (this->vfunc_88());
      break;
  }
  return;
}

void TObjEneBm5Wolf::alerted_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  s32 new_var;
  switch (arg1)
  {
    case 4:
      this->requested_action = 4;
      ((TObjEneDD *)arg0)->set_field_378(4);
      (this->vfunc_95());
      new_var = (s32) (((s32) (lbl_805D9E38 * random_ratio__9TObjCharaFv((s32) arg0))) + 0xA);
      this->roamingSubstate = new_var;
      return;
    case 3:
      if ((this->roamingSubstate) <= 0)
    {
      set_anim_state();
    }
    case 5:
      return;
      return;
    case 0:
      this->roamingSubstate = (s32) ((this->roamingSubstate) - 1);
      play_variant_sound__14TObjEneBm5WolfFPv(arg0);
      ((TObjMotion *)arg0)->advance_animation();
      (this->vfunc_102());
      (this->vfunc_88());
      break;
  }
}

void TObjEneBm5Wolf::sleeping_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  u8 *entity;
  switch (arg1)
  {
    case 4:
      this->requested_action = 4;
      ((TObjEneDD *)arg0)->set_field_378(2);
      (this->vfunc_95());
      enemy_clear_target__12TObjEneDD_STFUs(arg0);
      this->turnOffset = 0;
      this->m_408 = (s32) ((this->m_408) & 0xFFFFFFFE);
      return;
    case 3:
      if ((this->m_408) & 1)
    {
      transition_enemy_state__9TObjEneDDFl(arg0, 4);
      return;
      return;
    }
      if (((u32) (*((u32 *) (((s8 *) arg0) + 0x390)))) != 0U)
    {
      enemy_copy_target_destination__12TObjEneDD_STFv(arg0);
      set_anim_state();
      entity = (u8 *) find_entity_by_id(this->m_3e0);
      if (entity != 0)
      {
        ((TObjEneBm5Wolf *)entity)->set_attack_flag();
      }
    }
      return;
    case 0:
      play_variant_sound__14TObjEneBm5WolfFPv(arg0);
      ((TObjMotion *)arg0)->advance_animation();
      (this->vfunc_102());
      (this->vfunc_88());
      return;
    case 5:
      this->m_408 = (s32) ((this->m_408) & 0xFFFFFFFE);
      break;
  }
}

extern const f32 lbl_805D9E3C;
extern const f32 lbl_805D9E40;
#pragma push
#pragma fp_contract on
void appearing_state__14TObjEneBm5WolfFPvi(Obj_800B7018 *o, s32 arg1) {
    Vec_800B7018 *home = &o->f444;
    f32 t;

    switch (arg1) {
    case 4:
        o->fB8 = 0x11;
        ((TObjEneDD *)o)->set_field_378(7);
        ((TObjEneBm5Wolf *)o)->vfunc_95();
        o->f408 &= ~3;
        o->f408 |= 4;
        enemy_clear_target__12TObjEneDD_STFUs(o);
        o->f3E4 = 0;
        VecCopy((Vec *)home, (const Vec *)&o->pos);
        o->pos.x -= lbl_805D9E3C * sin_table_lookup(o->angle);
        o->pos.z -= lbl_805D9E3C * cos_table_lookup(o->angle);
        o->f434 = lbl_805D9E40;
        o->f40C = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        o->f438 = o->pos.y;
        break;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            if (select_target__14TObjEneBm5WolfFPv(o) != 0) {
                transition_enemy_state__9TObjEneDDFl(o, 7);
            } else {
                transition_enemy_state__9TObjEneDDFl(o, 2);
            }
        }
        break;
    case 0:
        ((TObjMotion *)o)->advance_animation();
        if (!(o->fB0 & 4)) {
            if (is_passing_frame__10TObjMotionFf(o, TObjEneBm5Wolf__data_805D9DE0) != 0 ||
                is_passing_frame__10TObjMotionFf(o, TObjEneBm5Wolf__data_805D9DF0) != 0) {
                spawn_particle_effect((s32)&o->pos, 0xF3);
            }
            if (is_passing_frame__10TObjMotionFf(o, lbl_805D9DE4) != 0) {
                play_sound_effect((void *)((TObjEnemy *)(o))->remap_sound_for_area((s32)(0x3E420)), &o->pos, 0, 0);
            }
            if (is_passing_frame__10TObjMotionFf(o, TObjEneBm5Wolf__data_805D9DE8) != 0) {
                play_sound_effect((void *)((TObjEnemy *)(o))->remap_sound_for_area((s32)(0x4003A821)), &o->pos, 0, 0);
                play_effect_if_v2__10TObjPlayerFl(-0x500);
            }
            if (o->fC0 <= TObjEneBm5Wolf__data_805D9DF0) {
                t = o->fC0 - TObjEneBm5Wolf__data_805D9DF4;
                o->f40C = (o->f438 + (lbl_805D9DDC * (t * t) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D74))) - o->pos.y;
            } else {
                o->f434 *= (*(f32 *)&TObjEneBm5Wolf__data_805D9DA4);
            }
            o->pos.x += o->f434 * sin_table_lookup(o->angle);
            o->pos.z += o->f434 * cos_table_lookup(o->angle);
        }
        ((TObjEneBm5Wolf *)o)->vfunc_102();
        ((TObjEneBm5Wolf *)o)->vfunc_88();
        break;
    case 5:
        o->f40C = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
        break;
    }
}

#pragma pop
void TObjEneBm5Wolf::anchor_state(s32 arg1) {
    u32 temp_r3;
    u8 *arg0 = (u8 *)this;

    switch (arg1) {
    case 4:
        this->roamingTimer = 0;
        ((TObjEneDD *)arg0)->set_field_378(0);
        VTABLE_ENE->m93();
        this->m_408 = (s32) (this->m_408 | 2);
        return;
    case 3:
        if ((s32) this->roamingTimer > 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 1);
        }
    case 5:
        return;
    case 0:
        temp_r3 = find_pack_leader__14TObjEneBm5WolfFi((s32)(*(s32 *)((s8 *)arg0 + 0x3DC)));
        if (temp_r3 != 0U) {
            this->m_3e0 = get_entity_id();
        }
        if (((s32) this->m_3d8 != 0) || (temp_r3 == 0U)) {
            VecCopy((Vec *)(arg0 + 0x3F4), (const Vec *)(arg0 + 0x3E8));
        } else {
            VecCopy((Vec *)(arg0 + 0x3F4), (const Vec *)(fn_800B8B00((void *)temp_r3)));
        }
        this->roamingTimer = (this->roamingTimer + 1);
        break;
    }
}

extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
void vfunc_6__8TObjBaseFPsl(void);
void apply_object_set_data__8TObjBaseFPv(void);
void reset_motion_fields__9TObjCharaFv(void);
void get_center__9TObjCharaFv(void);
void update_object_view_visibility__8TObjBaseFff(void);
void classify_actor_view_detail__8TObjBaseFfff(void);
void get_name__9TObjEnemyFv(void);
void interact__14TObjCollidableFl(void);
void add_actor_exp__9TObjCharaFl(void);
void consume_timer_field__9TObjCharaFl(void);
void get_actor_level_index__9TObjCharaFv(void);
void update_actor_ground_y__9TObjCharaFv(void);
void vfunc_18__9TObjCharaFPUc(void);
void is_actor_cadence_frame__9TObjCharaFl(void);
void select_melee_contact_body__9TObjCharaFPvf(void);
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf(void);
void receive_physical_attack__9TObjCharaFPvf(void);
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void);
void receive_weapon_special_attack__9TObjCharaFPvPv(void);
void apply_defense_stat_status__9TObjCharaFPv();
void apply_knockback_from_attacker__9TObjCharaFPUcf(void);
void try_start_action__9TObjCharaFll(void);
void roll_physical_accuracy__9TObjCharaFPvlf(void);
void vfunc_28__14TObjEneBm5WolfFv(void);
void vfunc_29__9TObjCharaFv(void);
void is_target_in_attack_range__9TObjCharaFv(void);
void update_poison_status__9TObjCharaFv(void);
void update_action_hold_status__9TObjCharaFv(void);
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv(void);
void update_movement_status__9TObjCharaFv(void);
void update_shock_clock__9TObjCharaFv(void);
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void vfunc_43__9TObjCharaFv(void);
void apply_poison_status__9TObjCharaFv(void);
void apply_paralysis__9TObjCharaFv(void);
void apply_slow_status__9TObjCharaFv(void);
void apply_confusion_status__9TObjCharaFv(void);
void apply_movement_ailment__9TObjCharaFl(void);
void apply_shock_status__9TObjCharaFv(void);
void clear_harmful_statuses__9TObjCharaFv(void);
void apply_attack_stat_status__9TObjCharaFPv(void);
void cure_poison_ailment__9TObjCharaFv(void);
void cure_paralysis__9TObjCharaFv(void);
void clear_all_status_effects__9TObjCharaFv(void);
void apply_action_hold_status__9TObjCharaFf(void);
void apply_anti_technique__9TObjCharaFl(void);
void vfunc_58__9TObjCharaFv(void);
void vfunc_59__9TObjCharaFv(void);
void vfunc_60__9TObjCharaFv(void);
void vfunc_61__14TObjEneBm5WolfFv(void);
void reset_pose__9TObjCharaFv(void);
void get_anim_node_position__9TObjCharaFlP3Vec(void);
void vfunc_66__9TObjCharaFv(void);
void vfunc_67__9TObjCharaFf(void);
void get_pos__9TObjCharaFl(void);
void apply_switch_attack__9TObjCharaFv(void);
void enemy_spawn_jellen_effect__9TObjCharaFv(void);
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void enemy_spawn_zalure_effect__9TObjCharaFv(void);
void recalc_stats__9TObjCharaFv(void);
void vfunc_74__9TObjEnemyFl(void);
void vfunc_75__9TObjCharaFf(void);
void vfunc_76__9TObjCharaFv(void);
void vfunc_77__9TObjCharaFv(void);
void vfunc_78__9TObjCharaFl(void);
void vfunc_79__9TObjEneDDFPl(void);
void apply_hit_message_flags__9TObjEnemyFPv(void);
void apply_set_data__9TObjEnemyFPv(void);
void clear_lobby_object_state__9TObjEnemyFv(void);
void vfunc_83__12TObjEneDD_STFv(void);
void vfunc_84__9TObjEneDDFv(void);
void vfunc_85__9TObjEneDDFv(void);
void vfunc_86__9TObjEneDDFv(void);
void vfunc_89__9TObjEneDDFv(void);
void vfunc_90__9TObjEneDDFv(void);
void vfunc_91__9TObjEneDDFv(void);
void vfunc_92__9TObjEneDDFv(void);
void vfunc_93__9TObjEneDDFv(void);
void vfunc_94__9TObjEneDDFv(void);
void vfunc_95__9TObjEneDDFv(void);
void vfunc_96__9TObjEneDDFv(void);
void vfunc_97__9TObjEneDDFv(void);
void vfunc_98__9TObjEneDDFv(void);
void vfunc_99__9TObjEneDDFv(void);
void vfunc_100__9TObjEneDDFv(void);
void vfunc_101__9TObjEneDDFPUc(void);
void vfunc_102__9TObjEneDDFv(void);
void vfunc_103__9TObjEneDDFPUc(void);
int vfunc_104__12TObjEneDD_STFf(void *p);
void *lbl_804922F8[107] = {
    0,
    0,
    (void *)__dt__14TObjEneBm5WolfFv,
    (void *)run_task__14TObjEneBm5WolfFv,
    (void *)render__14TObjEneBm5WolfFv,
    (void *)render_shadows__9TObjEnemyFv,
    (void *)vfunc_6__8TObjBaseFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf,
    (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (void *)receive_physical_attack__9TObjCharaFPvf,
    (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv,
    (void *)apply_knockback_from_attacker__9TObjCharaFPUcf,
    (void *)try_start_action__9TObjCharaFll,
    (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__14TObjEneBm5WolfFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__14TObjEneBm5WolfFv,
    (void *)vfunc_62__14TObjEneBm5WolfFv,
    (void *)vfunc_63__14TObjEneBm5WolfFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjEnemyFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFv,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
    (void *)vfunc_79__9TObjEneDDFPl,
    (void *)apply_hit_message_flags__9TObjEnemyFPv,
    (void *)apply_set_data__9TObjEnemyFPv,
    (void *)clear_lobby_object_state__9TObjEnemyFv,
    (void *)vfunc_83__12TObjEneDD_STFv,
    (void *)vfunc_84__9TObjEneDDFv,
    (void *)vfunc_85__9TObjEneDDFv,
    (void *)vfunc_86__9TObjEneDDFv,
    (void *)dispatch_state__14TObjEneBm5WolfFPvUii,
    (void *)vfunc_88__14TObjEneBm5WolfFv,
    (void *)vfunc_89__9TObjEneDDFv,
    (void *)vfunc_90__9TObjEneDDFv,
    (void *)vfunc_91__9TObjEneDDFv,
    (void *)vfunc_92__9TObjEneDDFv,
    (void *)vfunc_93__9TObjEneDDFv,
    (void *)vfunc_94__9TObjEneDDFv,
    (void *)vfunc_95__9TObjEneDDFv,
    (void *)vfunc_96__9TObjEneDDFv,
    (void *)vfunc_97__9TObjEneDDFv,
    (void *)vfunc_98__9TObjEneDDFv,
    (void *)vfunc_99__9TObjEneDDFv,
    (void *)vfunc_100__9TObjEneDDFv,
    (void *)vfunc_101__9TObjEneDDFPUc,
    (void *)vfunc_102__9TObjEneDDFv,
    (void *)vfunc_103__9TObjEneDDFPUc,
    (void *)vfunc_104__12TObjEneDD_STFf,
    (void *)update_state__14TObjEneBm5WolfFPv,
    (void *)render_debug__14TObjEneBm5WolfFPv,
};
}
typedef void (*State_800B73A8)(u8 *, s32);
void dispatch_state__14TObjEneBm5WolfFPvUii(TObjEneBm5Wolf *arg0, u32 state, s32 event) {
    switch (state) {
    case 0:
        ((TObjEneBm5Wolf *)arg0)->anchor_state(event);
        break;
    case 1:
        appearing_state__14TObjEneBm5WolfFPvi((Obj_800B7018 *)arg0, event);
        break;
    case 2:
        arg0->sleeping_state(event);
        break;
    case 3:
        ((State_800B73A8)TObjEneBm5Wolf::empty_state)((u8 *)arg0, event);
        break;
    case 4:
        arg0->alerted_state(event);
        break;
    case 5:
        arg0->standing_state(event);
        break;
    case 6:
        arg0->howling_state(event);
        break;
    case 7:
        arg0->roaming_state(event);
        break;
    case 8:
        arg0->chasing_state(event);
        break;
    case 9:
        arg0->flanking_state(event);
        break;
    case 10:
        arg0->circling_state(event);
        break;
    case 11:
        arg0->update_lunge(event);
        break;
    case 12:
        returning_state__14TObjEneBm5WolfFPvi((u8 *)arg0, event);
        break;
    case 13:
        arg0->repositioning_state(event);
        break;
    case 14:
        arg0->action(event);
        break;
    case 15:
        arg0->hurt_state(event);
        break;
    case 16:
        arg0->update_dying_state(event);
        break;
    case 17:
        arg0->despawn_state(event);
        break;
    }
}

void TObjEneBm5Wolf::apply_mourning_jellen() {
    Obj_800B74B8 *self = (Obj_800B74B8 *)this;
    u8 *target = (u8 *)find_entity_by_id(self->target_id);
    if (target != 0) {
        Arg_800B74B8 arg;
        arg.kind = 0xb;
        arg.fval = (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C);
        arg.val = *(s32 *)&arg.fval;
        arg.kind2 = 0xb;
        self->m21(target, &arg, 0, -1, -1);
    }
}

void TObjEneBm5Wolf::apply_mourning_zalure() {
    Obj_800B7530 *self = (Obj_800B7530 *)this;
    u8 *target = (u8 *)find_entity_by_id(self->target_id);
    if (target != 0) {
        Arg_800B7530 arg;
        arg.kind = 0xc;
        arg.fval = (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C);
        arg.val = *(s32 *)&arg.fval;
        arg.kind2 = 0xc;
        self->m21(target, &arg, 0, -1, -1);
    }
}
}

#undef play_footsteps__14TObjEneBm5WolfFPv
#undef play_variant_sound__14TObjEneBm5WolfFPv
#undef set_state_by_timer__14TObjEneBm5WolfFi
#undef spawn_recoil_dust__14TObjEneBm5WolfFiPv
#undef get_flag_bit0__14TObjEneBm5WolfFPv
#undef select_target__14TObjEneBm5WolfFPv
#undef schedule_pack_reaction__14TObjEneBm5WolfFPvis
#undef calc_death_slide_speed__14TObjEneBm5WolfFPvf
#undef select_death_direction__14TObjEneBm5WolfFPvPv
#undef calc_lunge_aim__14TObjEneBm5WolfFPv

#include <stddef.h>
struct Stack_800B7808 {
    f32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
};

struct Seq_800B76E0 { u8 pad0[4]; u32 count; };

struct Ent_800B76E0 { s32 w0; Seq_800B76E0 *seq; };

struct Cur_800B76E0 { u8 pad0[0x94]; s32 idx; };

struct Obj_800B76E0 { u8 pad0[0xD8]; Cur_800B76E0 *cur; Ent_800B76E0 *ents; };

typedef struct Vec_800B78F8 {
    f32 x, y, z;
} Vec_800B78F8;

typedef struct Wolf_800B78F8 {
    u8 pad0[0x60];
    s32 facing;
    u8 pad64[0x308 - 0x64];
    Vec_800B78F8 knockback;
} Wolf_800B78F8;

struct Vec_800B79E0 { f32 x, y, z; };

struct Obj_800B79E0 { u8 pad[0x38]; Vec_800B79E0 pos; };

extern "C" {
#define play_sound_effect ((s32 (*)(void *, void *, int, int))&play_sound_effect)
#define play_effect_if_v2__10TObjPlayerFl ((s32 (*)(int))&play_effect_if_v2__10TObjPlayerFl)
#define enemy_copy_target_destination__12TObjEneDD_STFv ((s32 (*)(void *))&enemy_copy_target_destination__12TObjEneDD_STFv)
#define update_velocity__9TObjEneDDFv ((s32 (*)(void *))&update_velocity__9TObjEneDDFv)
s32 transform_relative_position__9TObjEneDDFPv(void *, int);
#define sin_table_lookup ((f32 (*)(int))&sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))&cos_table_lookup)
extern const f32 lbl_805D9E44;
f32 newton_sqrtf(f32);
#define random_ratio__9TObjCharaFv ((f32 (*)())&random_ratio__9TObjCharaFv)
s32 select_and_apply_target__12TObjEneDD_STFf(f32);
s32 update_linked_position__12TObjEneDD_STFf(f32);

void schedule_pack_reaction__14TObjEneBm5WolfFPvis(void *arg0, s32 arg1, s16 arg2) {
    *(s32 *)((s8 *)arg0 + 0x414) = arg1;
    *(s16 *)((s8 *)arg0 + 0x418) = arg2;
}

#pragma push
#pragma fp_contract on
s32 calc_lunge_aim__14TObjEneBm5WolfFPv(u8 *arg0) {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    if (transform_relative_position__9TObjEneDDFPv(arg0, (int) (*(s32 *)((s8 *)arg0 + 0x390))) != 0) {
        enemy_copy_target_destination__12TObjEneDD_STFv(arg0);
        update_velocity__9TObjEneDDFv(arg0);
        if (((s32)get_flag_bit0__14TObjEneBm5WolfFPv(arg0)) != 0) {
            var_f0 = TObjEneBm5Wolf__data_805D9DEC;
        } else {
            var_f0 = lbl_805D9E44;
        }
        temp_f5 = *(f32 *)((s8 *)arg0 + 0x3A8);
        temp_f4 = *(f32 *)((s8 *)arg0 + 0x3A0);
        *(f32 *)((s8 *)arg0 + 0x394) = (f32) (*(f32 *)((s8 *)arg0 + 0x394) + (((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) * temp_f4) + (temp_f5 * var_f0)));
        *(f32 *)((s8 *)arg0 + 0x39C) = (f32) (*(f32 *)((s8 *)arg0 + 0x39C) + (((*(f32 *)&TObjEneBm5Wolf__data_805D9DBC) * temp_f5) - (temp_f4 * var_f0)));
        update_velocity__9TObjEneDDFv(arg0);
        return (s32) ((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float((f64) *(f32 *)((s8 *)arg0 + 0x3A0), (f64) *(f32 *)((s8 *)arg0 + 0x3A8)));
    }
    *(f32 *)((s8 *)arg0 + 0x3A0) = sin_table_lookup((int) (((TObjEneBm5Wolf *)arg0)->rotation_y));
    *(f32 *)((s8 *)arg0 + 0x3A4) = (f32) (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)arg0 + 0x3A8) = cos_table_lookup((int) (((TObjEneBm5Wolf *)arg0)->rotation_y));
    VecCopy((Vec *)(arg0 + 0x394), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x394) = (f32) ((TObjEneBm5Wolf__data_805D9DF0 * *(f32 *)((s8 *)arg0 + 0x3A0)) + *(f32 *)((s8 *)arg0 + 0x394));
    *(f32 *)((s8 *)arg0 + 0x39C) = (f32) ((TObjEneBm5Wolf__data_805D9DF0 * *(f32 *)((s8 *)arg0 + 0x3A8)) + *(f32 *)((s8 *)arg0 + 0x39C));
    ((TObjEneBm5Wolf *)arg0)->destinationDistance = (f32) TObjEneBm5Wolf__data_805D9DF0;
    return ((TObjEneBm5Wolf *)arg0)->rotation_y;
}
#pragma pop

int get_flag_bit0__14TObjEneBm5WolfFPv(void* p) { return *(u16*)((char*)p + 0x1c) & 0x1; }

extern const f32 lbl_805D9E48;

f32 calc_death_slide_speed__14TObjEneBm5WolfFPvf(Obj_800B76E0 *arg0, f32 farg0) {
    return (*(f32 *)&lbl_805D9D9C) / ((arg0->ents[arg0->cur->idx].seq->count - 1) / farg0);
}

void TObjEneBm5Wolf::play_proximity_effect() {
    s32 arg0 = (s32)this;
    if (is_passing_frame__10TObjMotionFf((void *)arg0, lbl_805D9E48) != 0) {
        play_sound_effect((void *)((TObjEnemy *)((void *)arg0))->remap_sound_for_area((s32)(0x3C618)), (void *)(arg0 + 0x38), 0, 0);
        play_effect_if_v2__10TObjPlayerFl(-0x1000);
    }
}

extern f32 lbl_805D9E4C;
extern f32 lbl_805D9E50;

void play_footsteps__14TObjEneBm5WolfFPv(u8 *ene_panarms) {
    if ((is_passing_frame__10TObjMotionFf(ene_panarms, TObjEneBm5Wolf__data_805D9DEC) != 0) || (is_passing_frame__10TObjMotionFf(ene_panarms, TObjEneBm5Wolf__data_805D9DE8) != 0)) {
        play_sound_effect((void *)(((s32)((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x3C618)))), ene_panarms + 0x38, 0, 0);
        play_effect_if_v2__10TObjPlayerFl(-0x1000);
    }
}

#pragma push
#pragma fp_contract on
void spawn_recoil_dust__14TObjEneBm5WolfFiPv(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800B7808, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800B7808, sp10) == 0x8) ? 1 : -1];
    Stack_800B7808 stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
    stack.sp8 += TObjEneBm5Wolf__data_805D9DE0 * *(f32 *)((s8 *)arg1 + 0);
    stack.sp10 += TObjEneBm5Wolf__data_805D9DE0 * *(f32 *)((s8 *)arg1 + 8);
    spawn_particle_effect((s32) &stack.sp8, 0xF3);
}
#pragma pop

void play_variant_sound__14TObjEneBm5WolfFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3D8) != 0) {
        update_linked_position__12TObjEneDD_STFf(lbl_805D9E4C);
        return;
    }
    update_linked_position__12TObjEneDD_STFf(lbl_805D9E50);
}

void select_target__14TObjEneBm5WolfFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3D8) != 0) {
        select_and_apply_target__12TObjEneDD_STFf(lbl_805D9E4C);
        return;
    }
    select_and_apply_target__12TObjEneDD_STFf(lbl_805D9E50);
}

void TObjEneBm5Wolf::set_attack_flag() { this->m_408 |= 0x1; }

s32 select_death_direction__14TObjEneBm5WolfFPvPv(Wolf_800B78F8 *s, s32 *heading) {
    Vec_800B78F8 v;
    Vec_800B78F8 side;
    s32 ret;
    VecCopy((Vec *)&v, (const Vec *)&s->knockback);
    v.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    if ((*(f32 *)&TObjEneBm5Wolf__data_805D9D78) != normalize_vector_xz__FP3Vec(&v)) {
        *heading = (s32)((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float(v.x, v.z));
        side.x = sin_table_lookup(s->facing);
        side.z = cos_table_lookup(s->facing);
        if (is_vec_xz_cross_negative(&side, &v) != 0) {
            ret = 0;
            *heading += 0x4000;
        } else {
            ret = 1;
            *heading -= 0x4000;
        }
    } else {
        ret = 0;
        *heading = s->facing;
    }
    *heading = (s16)*heading;
    return ret;
}

#pragma push
#pragma fp_contract on
f32 calc_circle_offset__14TObjEneBm5WolfFPvPvPv(Obj_800B79E0 *self, Vec_800B79E0 *target, Vec_800B79E0 *out) {
    f32 dx;
    f32 dz;
    dz = self->pos.z - target->z;
    dx = self->pos.x - target->x;
    f32 distSq = dx * dx + dz * dz;
    f32 inv = (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C) / ((f32 (*)(f32, f32))newton_sqrtf)(distSq, self->pos.x);
    out->x = dx * inv;
    out->y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    out->z = dz * inv;
    return distSq * inv;
}
#pragma pop

void TObjEneBm5Wolf::set_anim_state() {
    if ((s32) this->m_3d8 != 0) {
        transition_enemy_state__9TObjEneDDFl(this, 6);
        return;
    }
    transition_enemy_state__9TObjEneDDFl(this, 5);
}

void set_state_by_timer__14TObjEneBm5WolfFi(s32 arg0) {
    if (random_ratio__9TObjCharaFv() < (*(f32 *)&TObjEneBm5Wolf__data_805D9DAC)) {
        transition_enemy_state__9TObjEneDDFl((void *)arg0, 8);
        return;
    }
    transition_enemy_state__9TObjEneDDFl((void *)arg0, 9);
}

}

#undef enemy_copy_target_destination__12TObjEneDD_STFv
#undef update_velocity__9TObjEneDDFv
#undef random_ratio__9TObjCharaFv
#undef sin_table_lookup
#undef cos_table_lookup
#undef play_effect_if_v2__10TObjPlayerFl
#undef play_sound_effect
__declspec(section ".sdata2") extern const f32 lbl_805D9DD8 = 13.333333015441895f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DDC = -0.08888889104127884f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DE0 = 5.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DE4 = 6.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DE8 = 24.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DEC = 7.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DF0 = 30.0f;
__declspec(section ".sdata2") extern const f32 TObjEneBm5Wolf__data_805D9DF4 = 15.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DF8 = 0.699999988079071f;
__declspec(section ".sdata2") extern const f32 lbl_805D9DFC = 10000.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E00 = 900.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E04 = 80.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E08 = -0.20000000298023224f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E0C = 0.11999999731779099f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E10 = 768.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E14 = 65536.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E18 = 120.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E1C = 22500.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E20 = 0.05000000074505806f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E24 = 512.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E28 = 0.020000001415610313f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E2C = 240.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E30 = 360.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E34 = 9.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E38 = 60.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E3C = 100.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E40 = 3.3333332538604736f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E44 = -7.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E48 = 18.0f;
__declspec(section ".sdata2") f32 lbl_805D9E4C = 350.0f;
__declspec(section ".sdata2") f32 lbl_805D9E50 = 250.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E54 = 32768.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D9E58 = 25.0f;
#undef approach_target__14TObjEneBm5WolfFPvf
#undef advance_pose_turn__14TObjEneBm5WolfFPvi
#undef play_sound__14TObjEneBm5WolfFPv
#undef get_group_id__14TObjEneBm5WolfFPv
#undef calc_rotated_vector__14TObjEneBm5WolfFPviPvPv
#undef select_subtype__14TObjEneBm5WolfFv
#undef find_pack_leader__14TObjEneBm5WolfFi
#undef update_collision_center__14TObjEneBm5WolfFv
#undef vfunc_62__14TObjEneBm5WolfFv
#undef vfunc_63__14TObjEneBm5WolfFv
#undef vfunc_88__14TObjEneBm5WolfFv

#pragma fp_contract on

#define atan2_float ((f64 (*)(f32, f32))atan2_float)
#define sin_table_lookup ((f32 (*)(s32))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(s32))cos_table_lookup)

extern "C" {

void calc_rotated_vector__14TObjEneBm5WolfFPviPvPv(void *arg0, s32 arg1, void *arg2, s32 *arg3) {
    f32 temp_f1;
    f32 temp_f31;

    temp_f31 = sin_table_lookup(arg1);
    temp_f1 = cos_table_lookup(arg1);
    *(f32 *)((s8 *)arg2 + 8) = (f32) ((temp_f1 * *(f32 *)((s8 *)arg0 + 0x3A8)) - (temp_f31 * *(f32 *)((s8 *)arg0 + 0x3A0)));
    *(f32 *)((s8 *)arg2 + 0) = (f32) ((temp_f31 * *(f32 *)((s8 *)arg0 + 0x3A8)) + (temp_f1 * *(f32 *)((s8 *)arg0 + 0x3A0)));
    *arg3 = (s32) ((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * atan2_float(*(f32 *)((s8 *)arg2 + 0), *(f32 *)((s8 *)arg2 + 8)));
}

}
#undef atan2_float
#undef sin_table_lookup
#undef cos_table_lookup

#define random_ratio__9TObjCharaFv ((f32 (*)(void *))random_ratio__9TObjCharaFv)
#define approach_angle_limited ((s32 (*)(s32, s32, s32))approach_angle_limited)
#define normalize_vector_xz__FP3Vec ((f32 (*)(f32 *))normalize_vector_xz__FP3Vec)
#define rotate_xz_pair_by_angle ((void (*)(f32 *, f32 *, s32))rotate_xz_pair_by_angle)

#include <stddef.h>
struct Stack_800B7C14 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

typedef struct Wolf_800B7DDC {
    u8 pad0[0x60];
    s32 facing;
    u8 pad64[0x3E4 - 0x64];
    s32 turn;
} Wolf_800B7DDC;

extern "C" {
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
void *csnVector(void *from, void *to, u32 flags);
s32 angle_diff_s16(s32, s32);

void approach_target__14TObjEneBm5WolfFPvf(void *arg0, f32 farg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg0 + 0x404);
    temp_f0 = *(f32 *)((s8 *)arg0 + 0x400);
    if (temp_f2 != temp_f0) {
        if (temp_f2 > temp_f0) {
            *(f32 *)((s8 *)arg0 + 0x404) = (f32) (temp_f2 - farg0);
            if (*(f32 *)((s8 *)arg0 + 0x404) < *(f32 *)((s8 *)arg0 + 0x400)) {
                *(f32 *)((s8 *)arg0 + 0x404) = *(f32 *)((s8 *)arg0 + 0x400);
            }
        } else {
            *(f32 *)((s8 *)arg0 + 0x404) = (f32) (temp_f2 + farg0);
            if (*(f32 *)((s8 *)arg0 + 0x404) > *(f32 *)((s8 *)arg0 + 0x400)) {
                *(f32 *)((s8 *)arg0 + 0x404) = *(f32 *)((s8 *)arg0 + 0x400);
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5Wolf::choose_roaming_destination() {
    typedef char sp8_offset[(offsetof(Stack_800B7C14, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800B7C14, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800B7C14, sp10) == 0x8) ? 1 : -1];
    Stack_800B7C14 stack;
    f32 temp_f3;
    f32 temp_f3_2;
    u8 *temp_r3;
    u8 *temp_r4;
    stack.sp8 = this->position.x - this->groupAnchor[0];
    stack.spC = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    stack.sp10 = this->position.z - this->groupAnchor[2];
    normalize_vector_xz__FP3Vec(&stack.sp8);
    rotate_xz_pair_by_angle(&stack.sp8, &stack.sp10, (s32) ((*(f32 *)&lbl_805D9E54) * random_ratio__9TObjCharaFv(this)) + 0x4000);
    temp_f3 = (*(f32 *)&lbl_805D9E18) * rand_range__9TObjEneDDFff(this, (*(f32 *)&TObjEneBm5Wolf__data_805D9D84), (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C));
    this->destination[0] = (f32) ((stack.sp8 * temp_f3) + this->groupAnchor[0]);
    this->destination[2] = (f32) ((stack.sp10 * temp_f3) + this->groupAnchor[2]);
    temp_r3 = (u8 *)(csnVector((u8 *)this + 0x2FC, (u8 *)this + 0x394, 0x88E0U));
    if (temp_r3 != NULL) {
        temp_r4 = (u8 *)(*(u8 **)((s8 *)temp_r3 + 4));
        stack.sp8 = *(f32 *)((s8 *)temp_r4 + 0) - this->position.x;
        stack.sp10 = *(f32 *)((s8 *)temp_r4 + 8) - this->position.z;
        temp_f3_2 = normalize_vector_xz__FP3Vec(&stack.sp8) - (*(f32 *)&lbl_805D9E58);
        this->destination[0] = (f32) ((stack.sp8 * temp_f3_2) + this->position.x);
        this->destination[2] = (f32) ((stack.sp10 * temp_f3_2) + this->position.z);
    }
}
#pragma pop

void TObjEneBm5Wolf::turn_pose_to_target() {
    f32 x;
    f32 z;
    sin_table_lookup(this->rotation_y);
    x = *(f32 *)((s8 *)this + 0x38) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    cos_table_lookup(this->rotation_y);
    z = *(f32 *)((s8 *)this + 0x40) + (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    f32 dx = *(f32 *)((s8 *)this->target + 0x38) - x;
    f32 dz = *(f32 *)((s8 *)this->target + 0x40) - z;
    z = atan2_float((0, dx), dz);
    advance_pose_turn__14TObjEneBm5WolfFPvi((Wolf_800B7DDC *)this, (s32) ((*(f64 *)&TObjEneBm5Wolf__data_8043B5B0) * z));
}

void advance_pose_turn__14TObjEneBm5WolfFPvi(Wolf_800B7DDC *s, s32 target) {
    s32 d;
    d = angle_diff_s16(s->facing, target);
    if (d > 0x4000) {
        d = 0x4000;
    } else if (d < -0x4000) {
        d = -0x4000;
    }
    if (s->turn * d >= 0) {
        s->turn = approach_angle_limited(s->turn, d, 0x800);
    } else if (s->turn * angle_diff_s16(s->turn, d) >= 0) {
        if (s->turn >= 0) {
            s->turn -= 0x800;
        } else {
            s->turn += 0x800;
        }
    } else {
        s->turn = approach_angle_limited(s->turn, d, 0x800);
    }
    s->turn = (s16)s->turn;
}

void TObjEneBm5Wolf::select_subtype() {
    *(s32 *)&this->_pad3DC = (s32) get_random_float__21TObjEneMe3ShinowaRealFv((f32) (*(f32 *)((s8 *)((u8 *)this) + 0x354)));
    if (this->parameters[1] >= (*(f32 *)&TObjEneBm5Wolf__data_805D9D8C)) {
        this->m_3d8 = 1;
        (*(s32 *)&this->model) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8**)&TObjEneBm5Wolf__bml_resource) + 0x42C)) + 0x18);
        this->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8**)&TObjEneBm5Wolf__bml_resource) + 0x42C)) + 0xC);
        return;
    }
    this->m_3d8 = 0;
    (*(s32 *)&this->model) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8**)&TObjEneBm5Wolf__bml_resource) + 0x42C)) + 8);
    this->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8**)&TObjEneBm5Wolf__bml_resource) + 0x42C)) + 0xC);
}

void TObjEneBm5Wolf::vfunc_88() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) ((*(f32 *)&TObjEneBm5Wolf__data_805D9DB4) + *(f32 *)((s8 *)this + 0x40C));
}

}
#undef random_ratio__9TObjCharaFv
#undef approach_angle_limited
#undef normalize_vector_xz__FP3Vec
#undef rotate_xz_pair_by_angle

#define transition_enemy_state__9TObjEneDDFl ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)
#define play_sound__14TObjEneBm5WolfFPv ((Wolf_800B850C * (*)(Node_800B850C *))play_sound__14TObjEneBm5WolfFPv)
#define select_subtype__14TObjEneBm5WolfFv ((s32 (*)(void *))select_subtype__14TObjEneBm5WolfFv)
#define TObjEneBm5Wolf__sub_800B8A24 ((s32 (*)(void *))TObjEneBm5Wolf__sub_800B8A24)
#define lbl_804922F8 ((u8 *)&lbl_804922F8)

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
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
    virtual s32 m81();
    virtual void m82();
    virtual s32 m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

struct RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800B85D0_TObjEneBm5Wolf__data_80500B78 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800B85A0_TObjEneBm5Wolf__data_80500B8C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800B8600_TObjEneBm5Wolf__data_80500B78 {
    s32 value;
    u8 remaining[0x10];
};

struct Node_800B850C { void *obj; Node_800B850C *next; };

struct Wolf_800B850C { u8 pad[0x3dc]; s32 id; };

struct DBase_800B8174 { u8 pad[0x18]; };
struct D_800B8174 : DBase_800B8174 { virtual ~D_800B8174(); };

struct VBase_18_484afe { char pad[0x18]; };

struct VObj_18_484afe : VBase_18_484afe {
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
    virtual s32 m85(s16, s32);
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual s32 m96();
};

struct HpTbl_800B8244 { s32 a[2]; s32 b[2]; s32 c[2]; };

struct WolfRes_800B8244 { u8 f0[0x1C]; };

extern "C" {
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
s32 __ct__12TObjEneDD_STFP7TObject(void *, void *);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 init_model__9TObjEneDDFv(void *, void *, int);
s32 invoke_initialization_hook__9TObjEneDDFv(void *, void *);
s32 init_collision_body_parts(void *, void *, int);
void *__ct__14TObjCollidableFP7TObject(void *, int);
void *__nw__7TObjectFUl(int);
extern s32 bm5_wolf_class_name;
void TLobby__sub_8001FE7C(void*, int);

void TObjEneBm5Wolf::update_collision_center() {

    this->m_2fc = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x38);
    this->m_300 = (f32) ((*(f32 *)&this->_pad40C) + ((*(f32 *)&TObjEneBm5Wolf__data_805D9DB4) + *(f32 *)((s8 *)((u8 *)this) + 0x3C)));
    this->m_304 = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x40);
    VecCopy((Vec *)(((u8 *)this) + 0x74), (const Vec *)(((u8 *)this) + 0x2FC));
}

void TObjEneBm5Wolf::vfunc_61() {  }
void TObjEneBm5Wolf::vfunc_62() { if (this->mode != 15) { transition_enemy_state__9TObjEneDDFl(this, (void*)15); } }
void TObjEneBm5Wolf::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0x10) && (temp_r0 != 0x11)) {
        transition_enemy_state__9TObjEneDDFl(this, (void*)(0x10));
    }
}
void TObjEneBm5Wolf::vfunc_28() {  }

void TObjEneBm5Wolf::run_task() {
    s16 temp_r0;
    s16 temp_r3_2;
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18 *)(this))->m103();
        return;
    }
    if (find_entity_by_id((this->m_3e0)) != 0U) {
        all_parents_unqueued_for_destruction__7TObjectFv();
    }
    if (this->vfunc_83() != 4) {
        temp_r3 = this->m_414;
        if (temp_r3 != 0) {
            this->m_414 = (temp_r3 - 1);
            if ((s32) this->m_414 == 0) {
                temp_r0 = this->mode;
                if ((temp_r0 != 0x10) && (temp_r0 != 0x11)) {
                    transition_enemy_state__9TObjEneDDFl(this, (void*)(0xE));
                }
            }
        }
        this->vfunc_85();
    } else {
        temp_r3_2 = this->mode;
        if (temp_r3_2 == 0) {
            this->vfunc_85();
        } else if (temp_r3_2 == 1) {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((u8 *)this) + 0x50));
            transition_enemy_state__9TObjEneDDFl(this, (void*)(7));
            this->vfunc_85();
        }
    }
    update_collision_center__14TObjEneBm5WolfFv(((u8 *)this));
    ((TObjEnemy *)((u8 *)this))->submit_default_cursor_candidate();
    this->vfunc_100();
}

u8 *__dt__14TObjEneBm5WolfFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(u8 **)((s8 *)arg0 + 0x18) = lbl_804922F8;
        if (*(D_800B8174 **)((s8 *)arg0 + 0x410) != NULL) {
            free_collision_body_parts(*(D_800B8174 **)((s8 *)arg0 + 0x410));
            delete *(D_800B8174 **)((s8 *)arg0 + 0x410);
            *(D_800B8174 **)((s8 *)arg0 + 0x410) = NULL;
        }
        ((TObjEneBm5Wolf *)arg0)->update_with_default_state();
        if (*(s32 *)&((TObjEneBm5Wolf *)arg0)->m_3d8 != 0) {
            ((TObjEneBm5Wolf *)arg0)->update_default();
        }
        free_collision_body_parts(arg0);
        destroy__14TObjEneBm5WolfFis((s32)(arg0 + 0x3CC), -1);
        destroy__14TObjEneBm5WolfFis((s32)(arg0 + 0x3C0), -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C_size[sizeof(RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C) == 0xC ? 1 : -1];

#define WV_800B8244(x) ((VObj_18_484afe *)(x))
#pragma push
#pragma bool off
u8 *TObjEneBm5Wolf__ct(u8 *ene_bm5_wolf, void *arg1, void *arg2) {
    s32 n;
    void *o;
    __ct__12TObjEneDD_STFP7TObject(ene_bm5_wolf, arg1);
    *(u8 **)((s8 *)ene_bm5_wolf + 0x18) = (u8 *)lbl_804922F8;
    TObjEneBm5Wolf__sub_800B8A24(ene_bm5_wolf + 0x3C0);
    TObjEneBm5Wolf__sub_800B8A24(ene_bm5_wolf + 0x3CC);
    *(s32 *)((s8 *)ene_bm5_wolf + 0) = bm5_wolf_class_name;
    invoke_initialization_hook__9TObjEneDDFv(ene_bm5_wolf, arg2);
    select_subtype__14TObjEneBm5WolfFv(ene_bm5_wolf);
    ((TObjEneDD *)ene_bm5_wolf)->init_position_vectors();
    init_model__9TObjEneDDFv(ene_bm5_wolf, (void *)TObjEneBm5Wolf__collider_params, 1);
    ((TObjMotion *)ene_bm5_wolf)->set_field_d8((s32)((void *)wolf_action_table));
    ((TObjMotion *)ene_bm5_wolf)->set_field_dc(*(s32 *)((s8 *)(*(u32 *)&TObjEneBm5Wolf__bml_resource) + 0x430));
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->requested_action = 0;
    ((TObjMotion *)ene_bm5_wolf)->set_animation(((TObjEneBm5Wolf *)ene_bm5_wolf)->requested_action);
    ((TObjMotion *)ene_bm5_wolf)->set_field_b8(((TObjEneBm5Wolf *)ene_bm5_wolf)->requested_action);
    n = *(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3d8;
    reset_hp__9TObjEneDDFv(ene_bm5_wolf, TObjEneBm5Wolf__stat_params[n != 0], wolf_stat_handle_a_table[n != 0], wolf_stat_handle_b_table[n != 0], n);
    ((TObjEneDD *)ene_bm5_wolf)->check_state_flag_1();
    *(u8 * *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->movementParameters = (u8 *)bm5_wolf_decision_row;
    if (*(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3d8 != 0) {
        initialize_enemy_state__9TObjEneDDFv(ene_bm5_wolf, 8);
    } else {
        initialize_enemy_state__9TObjEneDDFv(ene_bm5_wolf, 7);
    }
    *(f32 *)((s8 *)ene_bm5_wolf + 0x37C) = (*(f32 *)&TObjEneBm5Wolf__data_805D9DF4);
    ((TObjEneDD_ST *)ene_bm5_wolf)->enemy_init_acquire_period(0x14);
    ((TObjEneDD_ST *)ene_bm5_wolf)->enemy_init_validate_period(0x14);
    ((TObjEneBm5Wolf *)(ene_bm5_wolf + 0x3C0))->set_field8_from_obj((s32)ene_bm5_wolf);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->apply_position_to_node_list();
    if (*(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3d8 != 0) {
        ((TObjEneBm5Wolf *)(ene_bm5_wolf + 0x3CC))->set_field8_from_obj((s32)ene_bm5_wolf);
        ((TObjEneBm5Wolf *)ene_bm5_wolf)->apply_global_to_position();
    }
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_3e0 = 0xFFFF;
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->turnOffset = 0;
    VecCopy((Vec *)(ene_bm5_wolf + 0x3E8), (const Vec *)(ene_bm5_wolf + 0x38));
    VecCopy((Vec *)(ene_bm5_wolf + 0x3F4), (const Vec *)(ene_bm5_wolf + 0x38));
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->desiredSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->currentSpeed = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_408 = 0;
    *(f32 *)((s8 *)ene_bm5_wolf + 0x40C) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    o = __nw__7TObjectFUl(0xAC);
    if (o != NULL) {
        o = __ct__14TObjCollidableFP7TObject(o, 0);
    }
    *(void **)((s8 *)ene_bm5_wolf + 0x410) = o;
    init_collision_body_parts(*(void **)((s8 *)ene_bm5_wolf + 0x410), (void *)((u8 *)TObjEneBm5Wolf__collider_params + 0x2C), 1);
    *(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_414 = 0;
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_418 = 0xFFFF;
    WV_800B8244(ene_bm5_wolf)->m96();
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->roamingSubstate = 0;
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->roamingTimer = 0;
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->randomPhase = 0;
    *(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_428 = 0;
    *(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_42c = 0;
    *(s32 *)&((TObjEneBm5Wolf *)ene_bm5_wolf)->m_430 = 0;
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->stoppingDistance = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)ene_bm5_wolf + 0x438) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_43c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)ene_bm5_wolf + 0x440) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_444 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)ene_bm5_wolf + 0x448) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_44c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)ene_bm5_wolf + 0x450) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_454 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)ene_bm5_wolf + 0x458) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_45c = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    *(f32 *)((s8 *)ene_bm5_wolf + 0x460) = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->m_464 = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->nearTarget = 0;
    update_collision_center__14TObjEneBm5WolfFv(ene_bm5_wolf);
    WV_800B8244(ene_bm5_wolf)->m86();
    ((TObjEneDD *)ene_bm5_wolf)->transform_part_positions();
    ((TObjEneBm5Wolf *)ene_bm5_wolf)->mode = 0;
    WV_800B8244(ene_bm5_wolf)->m85(((TObjEneBm5Wolf *)ene_bm5_wolf)->mode, 4);
    return ene_bm5_wolf;
}
#pragma pop

Wolf_800B850C *find_pack_leader__14TObjEneBm5WolfFi(s32 id) {
    Node_800B850C *n;
    for (n = ((Node_800B850C * *)&(*(RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C *)&TObjEneBm5Wolf__instance_list))[0]; n != 0; n = n->next) {
        Wolf_800B850C *w = play_sound__14TObjEneBm5WolfFPv(n);
        if (w != 0 && w->id == id) {
            return w;
        }
    }
    return 0;
}

void TObjEneBm5Wolf::update_default() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5Wolf *)((s32) &(*(RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C *)&TObjEneBm5Wolf__instance_list).value))->update((void *)(arg0 + 0x3CC));
}

typedef char RecoveredGlobal_800B85D0_TObjEneBm5Wolf__data_80500B78_size[sizeof(RecoveredGlobal_800B85D0_TObjEneBm5Wolf__data_80500B78) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_800B85A0_TObjEneBm5Wolf__data_80500B8C_size[sizeof(RecoveredGlobal_800B85A0_TObjEneBm5Wolf__data_80500B8C) == 0xC ? 1 : -1];
void TObjEneBm5Wolf::apply_global_to_position() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5Wolf *)((s32) &(*(RecoveredGlobal_800B85A0_TObjEneBm5Wolf__data_80500B8C *)&(*(RecoveredGlobal_800B8570_TObjEneBm5Wolf__data_80500B8C *)&TObjEneBm5Wolf__instance_list)).value))->apply_to_position((void *)(arg0 + 0x3CC));
}

void TObjEneBm5Wolf::update_with_default_state() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5Wolf *)((s32) &(*(RecoveredGlobal_800B85D0_TObjEneBm5Wolf__data_80500B78 *)&TObjEneBm5Wolf__pack_member_list).value))->update((void *)(arg0 + 0x3C0));
}

typedef char RecoveredGlobal_800B8600_TObjEneBm5Wolf__data_80500B78_size[sizeof(RecoveredGlobal_800B8600_TObjEneBm5Wolf__data_80500B78) == 0x14 ? 1 : -1];
void TObjEneBm5Wolf::apply_position_to_node_list() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5Wolf *)((s32) &(*(RecoveredGlobal_800B8600_TObjEneBm5Wolf__data_80500B78 *)&(*(RecoveredGlobal_800B85D0_TObjEneBm5Wolf__data_80500B78 *)&TObjEneBm5Wolf__pack_member_list)).value))->apply_to_position((void *)(arg0 + 0x3C0));
}

void TObjEneBm5Wolf::release_global_805D5120() {
    if ((u32) (*(u32 *)&TObjEneBm5Wolf__bml_resource) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&TObjEneBm5Wolf__bml_resource), 1);
        (*(u32 *)&TObjEneBm5Wolf__bml_resource) = 0U;
    }
}

}
#undef transition_enemy_state__9TObjEneDDFl
#undef play_sound__14TObjEneBm5WolfFPv
#undef select_subtype__14TObjEneBm5WolfFv
#undef TObjEneBm5Wolf__sub_800B8A24
#undef lbl_804922F8

#define check_v2_mode__9TObjEneDDFv ((s32 (*)(void))check_v2_mode__9TObjEneDDFv)
#define get_entity_id ((s16 (*)(s32))get_entity_id)
#define TObjEneBm5Wolf__collider_params ((f32 *)&TObjEneBm5Wolf__collider_params)
#define bm_ene_bm5_wolf_resource_descriptor ((u8 *)&bm_ene_bm5_wolf_resource_descriptor)

struct Vec_800B86B4 { f32 x, y, z; };
struct G_800B86B4 {
    s32 a[2]; s32 b[2]; s32 c[2]; s32 d[2];
    Vec_800B86B4 v;
};
struct Spawn_800B86B4 { s32 a, b, c, d; };
struct Obj_800B86B4 { u8 pad[0x18]; s32 x18; };
struct Wolf_800B86B4 { u8 pad[0x42c]; s32 *p42c; s32 x430; };

struct O_800B8A24 { s32 a; s32 b; u16 c; };

struct Globals_800B8A40 {
    u8 pad[0x2c];
    u8 chain0[0xc];
    u8 list0[0x8];
    u8 chain1[0xc];
    u8 list1[0x8];
};

extern "C" {
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
Wolf_800B86B4 *load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
s32 spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, f32, f32);
extern s32 lbl_8043B3A8[];
extern s32 lbl_8043B3B0[];
extern s32 lbl_8043B3B8[];
extern s32 lbl_8043B3C0[];
extern Spawn_800B86B4 bm5_wolf_spawn_descriptor;
extern u8 lbl_8043B5C0[];
Vec_800B86B4 lbl_80500B60;
u32 lbl_80500B6C[3];
u32 TObjEneBm5Wolf__pack_member_list[5];
u32 TObjEneBm5Wolf__instance_list[3];
s32 __dt__14TObjEneBm5WolfFis(s32 arg0, s16 arg1);
void __register_global_object(void *obj, void *dtor, void *chain);
void __dl__FPv(void);

extern void *tl_04;

void *TObjEneBm5Wolf::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x46C);
    if (o != NULL) {
        o = TObjEneBm5Wolf__ct((u8 *)o, tl_04, arg0);
    }
    return o;
}

void TObjEneBm5Wolf::load_resources() {
    s32 i;

    if (check_v2_mode__9TObjEneDDFv() != 0) {
        TObjEneBm5Wolf__bml_resource = load_enemy_bml_resource_named(bm_ene_bm5_wolf_resource_descriptor, lbl_8043B5C0);
    } else {
        TObjEneBm5Wolf__bml_resource = (Wolf_800B86B4 *)load_enemy_bml_resource(bm_ene_bm5_wolf_resource_descriptor);
    }
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__pack_member_list)->reset_fields();
    ((TObjEneBm5Wolf *)TObjEneBm5Wolf__instance_list)->reset_fields();
    TObjEneBm5Wolf__spawn_timer = 0;
    TObjEneBm5Wolf__data_805D5128 = 0;
    lbl_80500B60.x = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    lbl_80500B60.y = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    lbl_80500B60.z = (*(f32 *)&TObjEneBm5Wolf__data_805D9D78);
    for (i = 0; i < 2; i++) {
        TObjEneBm5Wolf__stat_params[i] = register_boss__6TLobbyFl(lbl_8043B3A8[i]);
        wolf_stat_handle_a_table[i] = dispatch_shared_handler_b__6TLobbyFl(lbl_8043B3B0[i]);
        wolf_stat_handle_b_table[i] = register_object__6TLobbyFl(lbl_8043B3B8[i]);
        lbl_80500B58[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_8043B3C0[i]);
    }
    {
    Spawn_800B86B4 sp = bm5_wolf_spawn_descriptor;
    sp.a = TObjEneBm5Wolf__bml_resource->x430;
    spawn_npc_enemy__6TLobbyFslllff(9, TObjEneBm5Wolf__bml_resource->p42c[6], TObjEneBm5Wolf__bml_resource->p42c[3], &sp, TObjEneBm5Wolf__collider_params[3], (*(f32 *)&TObjEneBm5Wolf__data_805D9D78));
    spawn_npc_enemy__6TLobbyFslllff(10, TObjEneBm5Wolf__bml_resource->p42c[2], TObjEneBm5Wolf__bml_resource->p42c[3], &sp, TObjEneBm5Wolf__collider_params[3], (*(f32 *)&TObjEneBm5Wolf__data_805D9D78));
    }
}

void TObjEneBm5Wolf::update(void* a1) { ((TObjEneBm5Wolf *)a1)->unlink_list_node((void ***)(this), (void **)((void*)((char*)this + 0x4))); }
void TObjEneBm5Wolf::apply_to_position(void* a1) { ((TObjEneBm5Wolf *)a1)->push_list_node((void **)(this), (void **)((void*)((char*)this + 0x4))); }
void TObjEneBm5Wolf::reset_fields() { *(s32 *)&this->m_name = 0; *(s32 *)&this->m_flags = 0; }
s32 __dt__14TObjEneBm5WolfFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void*TObjEneBm5Wolf::reset() { reset_fields(); return this; }
void play_sound__14TObjEneBm5WolfFPv(void *arg0) {
    find_entity_by_id(*(u16 *)((s8 *)arg0 + 8));
}
void TObjEneBm5Wolf::set_field8_from_obj(s32 arg1) {
    *(s16 *)((s8 *)this + 8) = get_entity_id(arg1);
}

void TObjEneBm5Wolf::push_list_node(void **arg1, void **arg2) {
    u8 *arg0 = (u8 *)this;
    u8 *name;
    name = (u8 *)(*arg2);
    if (name != NULL) {
        *(void * *)&this->m_name = name;
        *(void **)((s8 *)(*arg2) + 4) = arg0;
    } else {
        *(void * *)&this->m_name = NULL;
        *arg1 = arg0;
    }
    *arg2 = arg0;
    *(s32 *)&this->m_flags = 0;
}

void TObjEneBm5Wolf::unlink_list_node(void ***arg1, void **arg2) {
    void **temp_r4;
    u8 *temp_r6;
    temp_r6 = *(u8 * *)&this->m_name;
    if (temp_r6 != NULL) {
        *(void ***)((s8 *)temp_r6 + 4) = (void **) (*(void * * *)&this->m_flags);
    } else {
        *arg1 = (*(void * * *)&this->m_flags);
    }
    temp_r4 = (*(void * * *)&this->m_flags);
    if (temp_r4 != NULL) {
        *temp_r4 = *(u8 * *)&this->m_name;
        return;
    }
    *arg2 = *(u8 * *)&this->m_name;
}

s32 destroy__14TObjEneBm5WolfFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TObjEneBm5Wolf__sub_800B8A24(O_800B8A24 *self) {
    self->a = 0;
    self->b = 0;
    self->c = 0xFFFF;
}

#pragma push
#pragma opt_propagation off
void TObjEneBm5Wolf::register_global_objects() {
    Globals_800B8A40 *g = (Globals_800B8A40 *)TObjEneBm5Wolf__stat_params;
    __register_global_object(((void *)((TObjEneBm5Wolf *)(g->list0))->reset()), (void *)__dt__14TObjEneBm5WolfFis, g->chain0);
    __register_global_object(((void *)((TObjEneBm5Wolf *)(g->list1))->reset()), (void *)__dt__14TObjEneBm5WolfFis, g->chain1);
}
}
#pragma pop

s32 actor_rand_int(s32 actor, s32 arg1) {
    return (s32) ((f32) arg1 * random_ratio__9TObjCharaFv(actor));
}
extern "C" {

s32 get_group_id__14TObjEneBm5WolfFPv(void* p) { return *(s32*)((char*)p + 0x3dc); }
}

#undef check_v2_mode__9TObjEneDDFv
#undef get_entity_id
#undef TObjEneBm5Wolf__collider_params
#undef bm_ene_bm5_wolf_resource_descriptor

__declspec(section ".ctors") static void *const __sinit_TObjEneBm5Wolf_cpp_ref = (void *)TObjEneBm5Wolf::register_global_objects;
