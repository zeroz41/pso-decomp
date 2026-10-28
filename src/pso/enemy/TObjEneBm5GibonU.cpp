#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/boss/TBoss5Gryphon.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBm5GibonU.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/system/vector.h"
#include "pso/misc/TTecZonde.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TTecFoie.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/misc/TTecMegid.h"
#include "pso/object/TObjFish.h"

#include "pso/enemy/TUnk_80494938.h"

struct Ene_800CCC6C;
struct Ene_800D0FDC;
struct Ene_800D17E8;
struct Gibon_800D13B8;
struct Obj_800D0A94;
struct Obj_800D0AE8;
struct Vec_800D0AE8;

struct Vec_800CCE80 { f32 x, y, z; };

struct Motion_800CCE80 { u32 f0; u32 count; };

struct AnimRef_800CCE80 { s32 f0; Motion_800CCE80 *motion; };

struct AnimSel_800CCE80 { s32 f0; s32 index; s32 f8; s32 fC; };

struct VBase_800CCE80 { char pad[0x18]; };

struct VObj_800CCE80 : VBase_800CCE80 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Gibon_800CCE80 : VObj_800CCE80 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 model;
    Vec_800CCE80 pos;
    u8 pad44[0x60 - 0x44];
    s32 rot_y;
    u8 pad64[0xD8 - 0x64];
    AnimSel_800CCE80 *sel;
    AnimRef_800CCE80 *refs;
    u8 padE0[0x2FC - 0xE0];
    Vec_800CCE80 center;
    u8 pad308[0x360 - 0x308];
    f32 anim;
    f32 frame;
    u8 pad368[0x464 - 0x368];
    s32 f464;
    u8 pad468[0x46C - 0x468];
    s32 f46C;
    s32 f470;
};

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

struct Vec_800D0F44 { f32 x, y, z; };

struct Tgt_800D0F44 { u8 pad0[0x38]; Vec_800D0F44 pos; };

struct Obj_800D0F44 { u8 pad0[0x38]; Vec_800D0F44 pos; u8 pad44[0x60 - 0x44]; s32 h; u8 pad64[0x390 - 0x64]; Tgt_800D0F44 *target; };

struct Spawn_800D1990 { s32 a, b, c, d; };

extern "C" {
s32 update_player_state__9TObjEneDDFv(void *, s32, s32);
s32 get_target_info__9TObjEneDDFv();
s32 pack_debug_text_position(s32, s32);
Ene_800D17E8 *find_enemy_by_id__16TObjEneBm5GibonUFi(s32 id);
s32 TObjMapWarp__sub_80141CB0(void *, void *, u32, u32);
s32 debug_printf_at(s32, const char *, ...);
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 translate_matrix(s32, f32, f32, f32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern char lbl_8043C07C[];
extern char lbl_8043C088[];
extern char lbl_8043C094[];
extern char lbl_8043C0A0[];
extern char lbl_8043C0AC[];
extern char lbl_8043C0B8[];
extern char lbl_8043C0C8[];
extern char lbl_8043C0D8[];
void render_debug__16TObjEneBm5GibonUFv(u8 *arg0);
f32 calc_boss4_scale__10TObjPlayerFi(s32);
s32 enemy_validate_retained_target(void *);
s32 TObjEneDD__sub_800BA378(void *, void *);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
void TObjEneBm5GibonU__sub_800CCD8C(u8 *arg0);
s32 TObjEneBm5GibonU__sub_800D0968(u8 *arg0, int);
void turn_toward_angle__16TObjEneBm5GibonUFPvi(Ene_800D0FDC *arg0, s32 arg1);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 approach_angle_limited(s32, s32, s32);
s32 objInBand__FP7GameObjf(void *, f32);
s32 advance_animation_playback(void *);
s32 play_sound_effect(void *, void *, s32, s32);
void TObjEneBm5GibonU__sub_800CEBD8(u8 *arg0, s32 arg1);
extern const f64 TObjEneBm5GibonU__data_8043C0F8;
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
u8 *load_enemy_bml_resource(void *);
void spawn_npc_enemy__6TLobbyFslllff(s16, s32, s32, void *, f32, f32);
extern const s32 lbl_8043BF30[];
extern const s32 lbl_8043BF38[];
extern const s32 lbl_8043BF40[];
extern const s32 lbl_8043BF48[];
extern const Spawn_800D1990 TObjEneBm5GibonU__spawn_params;
Ene_800D17E8 * find_enemy_by_id__16TObjEneBm5GibonUFi(s32 id);
Gibon_800D13B8 * TObjEneBm5GibonU__sub_800D13B8(Gibon_800D13B8 *arg0, s16 arg1);
s32 rotate_xz_pair_by_angle(f32 *, f32 *, s32);
s32 update_collisions__10TObjPlayerFv(void *);
f32 calc_anim_speed__16TObjEneBm5GibonUFPvf(Obj_800D0A94 *arg0, f32 farg0);
f32 clamp_velocity__15TObjBoss2TunnelFv(void *);
f32 cos_table_lookup(int);
f32 atan2_float(f64, f64);
f32 sin_table_lookup(int);
int spawn_landing_effect__16TObjEneBm5GibonUFPvPv(Ene_800CCC6C *arg0, void *arg1);
int is_active__16TObjEneBm5GibonUFPv(void* p);
s32 TObjEneBm5GibonU__sub_800D1D70(void* p);
s32 get_entity_id(int);
s32 update_angle__10TObjPlayerFlPv(void *, s32, void *);
void *find_entity_by_id(u16 id);
void * __nw__7TObjectFUl(u32);
void render__16TObjEneBm5GibonUFv(u8 *arg0);
void TObjEneBm5GibonU__sub_800D0738(u8 *arg0, u32 arg1, s32 arg2);
void TObjEneBm5GibonU__sub_800D0AE8(Obj_800D0AE8 *self, Vec_800D0AE8 *dir);
void vfunc_88__16TObjEneBm5GibonUFv(u8 *arg0);
void run_task__16TObjEneBm5GibonUFv(u8 *arg0);
void update_shock_clock__13TUnk_804806E8Fv();
void calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(void *arg0, s32 arg1, void *arg2, s32 *arg3);
void vfunc_63__16TObjEneBm5GibonUFv(void *arg0);
void vfunc_62__16TObjEneBm5GibonUFv(void* p);
void update_center_position__16TObjEneBm5GibonUFv(u8 *arg0);
void update_movement_status__13TUnk_804806E8Fv();
void update_photon_mylla__16TObjEneBm5GibonUFPv(void *arg0);
void vfunc_83__16TObjEneBm5GibonUFv(void *arg0);
void update_target__16TObjEneBm5GibonUFPv(void *arg0);
void* TObjEneBm5GibonU__sub_800D1D78(void* p);
extern u8 * TObjEneBm5GibonU__model_archive;
}
extern const f32 TObjEneBm5GibonU__data_805DA158[1];
extern const f32 TObjEneBm5GibonU__data_805DA160[1];
extern const f32 TObjEneBm5GibonU__data_805DA164[1];
extern const f32 TObjEneBm5GibonU__data_805DA168[1];
extern const f32 TObjEneBm5GibonU__data_805DA16C[1];
extern const f32 TObjEneBm5GibonU__data_805DA170[1];
extern const f32 TObjEneBm5GibonU__data_805DA174[1];
extern const f32 TObjEneBm5GibonU__data_805DA178[1];
extern const f32 lbl_805DA17C[1];
extern const f32 lbl_805DA180[1];
extern const f32 TObjEneBm5GibonU__data_805DA184[1];
extern const f32 TObjEneBm5GibonU__data_805DA188[1];
extern const f32 TObjEneBm5GibonU__data_805DA18C[1];
extern const f32 TObjEneBm5GibonU__data_805DA194[1];
extern const f32 lbl_805DA198[1];
extern const f32 lbl_805DA19C[1];
extern const f32 lbl_805DA1A0[1];
extern const f32 lbl_805DA1A4[1];
extern const f32 lbl_805DA1A8[1];
extern const f32 lbl_805DA1AC[1];
extern const f32 TObjEneBm5GibonU__data_805DA1B0[1];
extern const f32 lbl_805DA1B4[1];
extern const f32 TObjEneBm5GibonU__data_805DA1B8[1];
extern const f32 TObjEneBm5GibonU__data_805DA1BC[1];
extern const f32 lbl_805DA1C0[1];
extern const f32 lbl_805DA1C4[1];
extern const f32 TObjEneBm5GibonU__data_805DA1C8[1];
extern const f32 lbl_805DA1CC[1];
extern const f32 TObjEneBm5GibonU__data_805DA1D0[1];
extern const f32 lbl_805DA1D8[1];
extern const f32 lbl_805DA1DC[1];
extern const f32 lbl_805DA1E0[1];
extern const f32 lbl_805DA1E4[1];
extern const f32 lbl_805DA1E8[1];
extern const f32 lbl_805DA1EC[1];
extern const f32 lbl_805DA1F0[1];
extern const f32 lbl_805DA1F4[1];
extern const f32 lbl_805DA1F8[1];
extern const f32 lbl_805DA1FC[1];
extern const f32 lbl_805DA200[1];
extern const f32 lbl_805DA204[1];
extern const f32 lbl_805DA208[1];
extern const f32 lbl_805DA20C[1];
extern const f32 lbl_805DA210[1];
extern const f32 lbl_805DA214[1];
extern const f32 lbl_805DA218[1];
extern const f32 lbl_805DA21C[1];
extern const f32 lbl_805DA220[1];
extern const f32 lbl_805DA224[1];
extern const f32 lbl_805DA228[1];
extern const f32 lbl_805DA22C[1];
extern const f32 lbl_805DA230[1];
extern const f32 lbl_805DA234[1];
extern const f32 lbl_805DA238[1];
extern const f32 lbl_805DA23C[1];
extern const f32 lbl_805DA240[1];
extern const f32 lbl_805DA244[1];
extern const f32 lbl_805DA248[1];
extern const f32 lbl_805DA24C[1];
extern const f32 lbl_805DA250[1];
extern const f32 lbl_805DA254[1];
#define TObjEneBm5GibonU__data_805DA158 (TObjEneBm5GibonU__data_805DA158[0])
#define TObjEneBm5GibonU__data_805DA160 (TObjEneBm5GibonU__data_805DA160[0])
#define TObjEneBm5GibonU__data_805DA164 (TObjEneBm5GibonU__data_805DA164[0])
#define TObjEneBm5GibonU__data_805DA168 (TObjEneBm5GibonU__data_805DA168[0])
#define TObjEneBm5GibonU__data_805DA16C (TObjEneBm5GibonU__data_805DA16C[0])
#define TObjEneBm5GibonU__data_805DA170 (TObjEneBm5GibonU__data_805DA170[0])
#define TObjEneBm5GibonU__data_805DA174 (TObjEneBm5GibonU__data_805DA174[0])
#define TObjEneBm5GibonU__data_805DA178 (TObjEneBm5GibonU__data_805DA178[0])
#define lbl_805DA17C (lbl_805DA17C[0])
#define lbl_805DA180 (lbl_805DA180[0])
#define TObjEneBm5GibonU__data_805DA184 (TObjEneBm5GibonU__data_805DA184[0])
#define TObjEneBm5GibonU__data_805DA188 (TObjEneBm5GibonU__data_805DA188[0])
#define TObjEneBm5GibonU__data_805DA18C (TObjEneBm5GibonU__data_805DA18C[0])
#define TObjEneBm5GibonU__data_805DA194 (TObjEneBm5GibonU__data_805DA194[0])
#define lbl_805DA198 (lbl_805DA198[0])
#define lbl_805DA19C (lbl_805DA19C[0])
#define lbl_805DA1A0 (lbl_805DA1A0[0])
#define lbl_805DA1A4 (lbl_805DA1A4[0])
#define lbl_805DA1A8 (lbl_805DA1A8[0])
#define lbl_805DA1AC (lbl_805DA1AC[0])
#define TObjEneBm5GibonU__data_805DA1B0 (TObjEneBm5GibonU__data_805DA1B0[0])
#define lbl_805DA1B4 (lbl_805DA1B4[0])
#define TObjEneBm5GibonU__data_805DA1B8 (TObjEneBm5GibonU__data_805DA1B8[0])
#define TObjEneBm5GibonU__data_805DA1BC (TObjEneBm5GibonU__data_805DA1BC[0])
#define lbl_805DA1C0 (lbl_805DA1C0[0])
#define lbl_805DA1C4 (lbl_805DA1C4[0])
#define TObjEneBm5GibonU__data_805DA1C8 (TObjEneBm5GibonU__data_805DA1C8[0])
#define lbl_805DA1CC (lbl_805DA1CC[0])
#define TObjEneBm5GibonU__data_805DA1D0 (TObjEneBm5GibonU__data_805DA1D0[0])
#define lbl_805DA1D8 (lbl_805DA1D8[0])
#define lbl_805DA1DC (lbl_805DA1DC[0])
#define lbl_805DA1E0 (lbl_805DA1E0[0])
#define lbl_805DA1E4 (lbl_805DA1E4[0])
#define lbl_805DA1E8 (lbl_805DA1E8[0])
#define lbl_805DA1EC (lbl_805DA1EC[0])
#define lbl_805DA1F0 (lbl_805DA1F0[0])
#define lbl_805DA1F4 (lbl_805DA1F4[0])
#define lbl_805DA1F8 (lbl_805DA1F8[0])
#define lbl_805DA1FC (lbl_805DA1FC[0])
#define lbl_805DA200 (lbl_805DA200[0])
#define lbl_805DA204 (lbl_805DA204[0])
#define lbl_805DA208 (lbl_805DA208[0])
#define lbl_805DA20C (lbl_805DA20C[0])
#define lbl_805DA210 (lbl_805DA210[0])
#define lbl_805DA214 (lbl_805DA214[0])
#define lbl_805DA218 (lbl_805DA218[0])
#define lbl_805DA21C (lbl_805DA21C[0])
#define lbl_805DA220 (lbl_805DA220[0])
#define lbl_805DA224 (lbl_805DA224[0])
#define lbl_805DA228 (lbl_805DA228[0])
#define lbl_805DA22C (lbl_805DA22C[0])
#define lbl_805DA230 (lbl_805DA230[0])
#define lbl_805DA234 (lbl_805DA234[0])
#define lbl_805DA238 (lbl_805DA238[0])
#define lbl_805DA23C (lbl_805DA23C[0])
#define lbl_805DA240 (lbl_805DA240[0])
#define lbl_805DA244 (lbl_805DA244[0])
#define lbl_805DA248 (lbl_805DA248[0])
#define lbl_805DA24C (lbl_805DA24C[0])
#define lbl_805DA250 (lbl_805DA250[0])
#define lbl_805DA254 (lbl_805DA254[0])
extern "C" {
#undef TObjEneBm5GibonU__data_805DA158
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA158[1] = { 0.5f };
#define TObjEneBm5GibonU__data_805DA158 (TObjEneBm5GibonU__data_805DA158[0])
#pragma push
#define render__16TObjEneBm5GibonUFv ((void (*)())render__16TObjEneBm5GibonUFv)
#define vfunc_88__16TObjEneBm5GibonUFv ((void (*)())vfunc_88__16TObjEneBm5GibonUFv)
#define TObjEneBm5GibonU__sub_800D13B8 ((void (*)())TObjEneBm5GibonU__sub_800D13B8)
#define vfunc_63__16TObjEneBm5GibonUFv ((void (*)())vfunc_63__16TObjEneBm5GibonUFv)
#define vfunc_62__16TObjEneBm5GibonUFv ((void (*)())vfunc_62__16TObjEneBm5GibonUFv)
#define vfunc_83__16TObjEneBm5GibonUFv ((void (*)())vfunc_83__16TObjEneBm5GibonUFv)
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_61__16TObjEneBm5GibonUFv();
}
extern "C" {
void vfunc_28__16TObjEneBm5GibonUFv();
}
extern "C" {
void vfunc_103__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_79__9TObjEneDDFv();
}
extern "C" {
void TObjEneDD__vt82();
}
extern "C" {
void vfunc_85__9TObjEneDDFv();
}
extern "C" {
void vfunc_86__9TObjEneDDFv();
}
extern "C" {
void vfunc_89__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void vfunc_91__9TObjEneDDFv();
}
extern "C" {
void vfunc_92__9TObjEneDDFv();
}
extern "C" {
void vfunc_93__9TObjEneDDFv();
}
extern "C" {
void vfunc_94__9TObjEneDDFv();
}
extern "C" {
void vfunc_95__9TObjEneDDFv();
}
extern "C" {
void vfunc_96__9TObjEneDDFv();
}
extern "C" {
void vfunc_97__9TObjEneDDFv();
}
extern "C" {
void vfunc_98__9TObjEneDDFv();
}
extern "C" {
void vfunc_99__9TObjEneDDFv();
}
extern "C" {
void vfunc_100__9TObjEneDDFv();
}
extern "C" {
void vfunc_101__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_102__9TObjEneDDFv();
}
extern "C" {
int TObjEneEpsilon__vt101(void *p);
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_73__13TUnk_804806E8Fv();
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_67__13TUnk_804806E8Ff();
}
extern "C" {
void vfunc_66__13TUnk_804806E8Fv();
}
extern "C" {
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
}
extern "C" {
void vfunc_60__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_59__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_58__13TUnk_804806E8Fv();
}
extern "C" {
void apply_slow_status__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_43__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_18__13TUnk_804806E8FPUc();
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__13TUnk_804806E8Fl();
}
extern "C" {
void apply_action_hold_status__13TUnk_804806E8Ff();
}
extern "C" {
void apply_anti_technique__13TUnk_804806E8Fl();
}
extern "C" {
void apply_attack_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void apply_confusion_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
}
extern "C" {
void apply_movement_ailment__13TUnk_804806E8Fl();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void apply_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void apply_poison_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
void clear_all_status_effects__13TUnk_804806E8Fv();
}
extern "C" {
void clear_harmful_statuses__13TUnk_804806E8Fv();
}
extern "C" {
void cure_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void cure_poison_ailment__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_78__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_77__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_76__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_75__13TUnk_804806E8Ff();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void vfunc_9__13TUnk_804806E8Fv();
}
extern "C" {
void get_actor_level_index__13TUnk_804806E8Fv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__13TUnk_804806E8Fl();
}
extern "C" {
void is_actor_cadence_frame__13TUnk_804806E8Fl();
}
extern "C" {
void is_target_in_attack_range__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 lbl_8043BF50[];
}
extern "C" {
extern u8 lbl_8043BF5C[];
}
extern "C" {
extern u8 lbl_8043BF6C[];
}
extern "C" {
extern u8 lbl_8043BF80[];
}
extern "C" {
extern u8 lbl_8043BF90[];
}
extern "C" {
extern u8 lbl_8043BFA4[];
}
extern "C" {
extern u8 lbl_8043BFB4[];
}
extern "C" {
extern u8 lbl_8043BFC4[];
}
extern "C" {
extern u8 lbl_8043BFD4[];
}
extern "C" {
extern u8 lbl_8043BFE4[];
}
extern "C" {
extern u8 lbl_8043BFF4[];
}
extern "C" {
extern u8 lbl_8043C004[];
}
extern "C" {
extern u8 lbl_8043C01C[];
}
extern "C" {
extern u8 lbl_8043C028[];
}
extern "C" {
extern u8 lbl_8043C03C[];
}
extern "C" {
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__13TUnk_804806E8FPvf();
}
extern "C" {
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__13TUnk_804806E8Fv();
}
extern "C" {
void reset_pose__13TUnk_804806E8Fv();
}
extern "C" {
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
}
extern "C" {
void select_melee_contact_body__13TUnk_804806E8FPvf();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
void update_action_hold_status__13TUnk_804806E8Fv();
}
extern "C" {
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__13TUnk_804806E8Fv();
}
extern "C" {
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
void *TObjEneBm5GibonU__movement_parameters[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *gibon_collision_body_templates[44] = {
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41800000, (void *)0x0, (void *)0x41400000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x40c00000, (void *)0x0, (void *)0x0,
    (void *)0x9d03, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x40c00000, (void *)0x0, (void *)0x0, (void *)0x9d03,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_80493D6C[3] = {
    (void *)lbl_8043BF50, (void *)lbl_8043BF5C, (void *)0x0,
};
void *gibon_u_animation_name_table[10] = {
    (void *)lbl_8043BF6C, (void *)lbl_8043BF80, (void *)lbl_8043BF90, (void *)lbl_8043BFA4,
    (void *)lbl_8043BFB4, (void *)lbl_8043BFC4, (void *)lbl_8043BFD4, (void *)lbl_8043BFE4,
    (void *)lbl_8043BFF4, (void *)0x0,
};
void *lbl_80493DA0[4] = {
    (void *)lbl_8043C004, (void *)lbl_80493D6C, (void *)gibon_u_animation_name_table, (void *)0x20009,
};
void *lbl_80493DB0[3] = {
    (void *)lbl_8043C01C, (void *)lbl_8043C028, (void *)0x0,
};
void *gibon_u_animation_file_table[10] = {
    (void *)lbl_8043BF6C, (void *)lbl_8043BF80, (void *)lbl_8043BF90, (void *)lbl_8043BFA4,
    (void *)lbl_8043BFB4, (void *)lbl_8043BFC4, (void *)lbl_8043BFD4, (void *)lbl_8043BFE4,
    (void *)lbl_8043BFF4, (void *)0x0,
};
void *lbl_80493DE4[4] = {
    (void *)lbl_8043C03C, (void *)lbl_80493DB0, (void *)gibon_u_animation_file_table, (void *)0x20009,
};
void *gibon_u_action_table[68] = {
    (void *)0x10000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x8, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x6, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x6, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f800000, (void *)0x0,
    (void *)0x20008, (void *)0x2, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f800000, (void *)0x0,
    (void *)0x30009, (void *)0x5, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f99999a, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3fa66666, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f800000, (void *)0x0,
    (void *)0x20009, (void *)0x7, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f800000, (void *)0x0,
};
void *lbl_80493F04[107] = {
    (void *)0x0, (void *)0x0, (void *)TObjEneBm5GibonU__sub_800D13B8, (void *)run_task__16TObjEneBm5GibonUFv,
    (void *)render__16TObjEneBm5GibonUFv, (void *)render_shadows__9TObjEnemyFv, (void *)vfunc_6__13TUnk_804B9870FPsl, (void *)apply_object_set_data__13TUnk_804B9870FPv,
    (void *)reset_motion_fields__13TUnk_804806E8Fv, (void *)vfunc_9__13TUnk_804806E8Fv, (void *)update_object_view_visibility__13TUnk_804B9870Fff, (void *)classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)get_name__9TObjEnemyFv, (void *)interact__13TUnk_804AF8A0Fl, (void *)add_actor_exp__13TUnk_804806E8Fl, (void *)consume_timer_field__13TUnk_804806E8Fl,
    (void *)get_actor_level_index__13TUnk_804806E8Fv, (void *)update_actor_ground_y__13TUnk_804806E8Fv, (void *)vfunc_18__13TUnk_804806E8FPUc, (void *)is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)select_melee_contact_body__13TUnk_804806E8FPvf, (void *)calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)receive_physical_attack__13TUnk_804806E8FPvf, (void *)receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)try_start_action__13TUnk_804806E8Fll, (void *)roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)vfunc_28__16TObjEneBm5GibonUFv, (void *)vfunc_29__13TUnk_804806E8Fv, (void *)is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)update_poison_status__13TUnk_804806E8Fv,
    (void *)update_action_hold_status__13TUnk_804806E8Fv, (void *)vfunc_37__13TUnk_804806E8Fv, (void *)update_flag30_timer__13TUnk_804806E8Fv, (void *)update_movement_status__13TUnk_804806E8Fv,
    (void *)update_shock_clock__13TUnk_804806E8Fv, (void *)update_attack_stat_status__13TUnk_804806E8Fv, (void *)update_defense_stat_status__13TUnk_804806E8Fv, (void *)vfunc_43__13TUnk_804806E8Fv,
    (void *)apply_poison_status__13TUnk_804806E8Fv, (void *)apply_paralysis__13TUnk_804806E8Fv, (void *)apply_slow_status__13TUnk_804806E8Fv, (void *)apply_confusion_status__13TUnk_804806E8Fv,
    (void *)apply_movement_ailment__13TUnk_804806E8Fl, (void *)apply_shock_status__13TUnk_804806E8Fv, (void *)clear_harmful_statuses__13TUnk_804806E8Fv, (void *)apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)apply_defense_stat_status__13TUnk_804806E8FPv, (void *)cure_poison_ailment__13TUnk_804806E8Fv, (void *)cure_paralysis__13TUnk_804806E8Fv, (void *)clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)apply_action_hold_status__13TUnk_804806E8Ff, (void *)apply_anti_technique__13TUnk_804806E8Fl, (void *)vfunc_58__13TUnk_804806E8Fv, (void *)vfunc_59__13TUnk_804806E8Fv,
    (void *)vfunc_60__13TUnk_804806E8Fv, (void *)vfunc_61__16TObjEneBm5GibonUFv, (void *)vfunc_62__16TObjEneBm5GibonUFv, (void *)vfunc_63__16TObjEneBm5GibonUFv,
    (void *)reset_pose__13TUnk_804806E8Fv, (void *)get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)vfunc_66__13TUnk_804806E8Fv, (void *)vfunc_67__13TUnk_804806E8Ff,
    (void *)get_pos__13TUnk_804806E8Fl, (void *)apply_switch_attack__13TUnk_804806E8Fv, (void *)enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)vfunc_73__13TUnk_804806E8Fv, (void *)vfunc_74__9TObjEnemyFl, (void *)vfunc_75__13TUnk_804806E8Ff,
    (void *)vfunc_76__13TUnk_804806E8Fv, (void *)vfunc_77__13TUnk_804806E8Fv, (void *)vfunc_78__13TUnk_804806E8Fl, (void *)vfunc_79__9TObjEneDDFv,
    (void *)apply_hit_message_flags__9TObjEnemyFPv, (void *)apply_set_data__9TObjEnemyFPv, (void *)clear_lobby_object_state__9TObjEnemyFv, (void *)vfunc_83__12TObjEneDD_STFv,
    (void *)TObjEneDD__vt82, (void *)vfunc_85__9TObjEneDDFv, (void *)vfunc_86__9TObjEneDDFv, (void *)TObjEneBm5GibonU__sub_800D0738,
    (void *)vfunc_88__16TObjEneBm5GibonUFv, (void *)vfunc_89__9TObjEneDDFv, (void *)vfunc_90__9TObjEneDDFv, (void *)vfunc_91__9TObjEneDDFv,
    (void *)vfunc_92__9TObjEneDDFv, (void *)vfunc_93__9TObjEneDDFv, (void *)vfunc_94__9TObjEneDDFv, (void *)vfunc_95__9TObjEneDDFv,
    (void *)vfunc_96__9TObjEneDDFv, (void *)vfunc_97__9TObjEneDDFv, (void *)vfunc_98__9TObjEneDDFv, (void *)vfunc_99__9TObjEneDDFv,
    (void *)vfunc_100__9TObjEneDDFv, (void *)vfunc_101__9TObjEneDDFPUc, (void *)vfunc_102__9TObjEneDDFv, (void *)vfunc_103__9TObjEneDDFPUc,
    (void *)TObjEneEpsilon__vt101, (void *)vfunc_83__16TObjEneBm5GibonUFv, (void *)render_debug__16TObjEneBm5GibonUFv,
};
__declspec(section ".data") u32 TObjEneBm5GibonU__data_80500E78[2];
__declspec(section ".data") u32 lbl_80500E80[2];
__declspec(section ".data") u32 lbl_80500E88[2];
__declspec(section ".data") u32 lbl_80500E90[2];
__declspec(section ".data") f32 lbl_80500E98[3];
__declspec(section ".data") u32 lbl_80500EA4[3];
__declspec(section ".data") u32 TObjEneBm5GibonU__node_list[5];
__declspec(section ".data") u32 TObjEneBm5GibonU__enemy_list[3];
}

#undef render__16TObjEneBm5GibonUFv
#undef vfunc_88__16TObjEneBm5GibonUFv
#undef TObjEneBm5GibonU__sub_800D13B8
#undef vfunc_63__16TObjEneBm5GibonUFv
#undef vfunc_62__16TObjEneBm5GibonUFv
#undef vfunc_83__16TObjEneBm5GibonUFv
#pragma pop
#pragma push
#define find_enemy_by_id__16TObjEneBm5GibonUFi ((s32 (*)(s32))find_enemy_by_id__16TObjEneBm5GibonUFi)
#define is_active__16TObjEneBm5GibonUFPv ((s32 (*)(void *))is_active__16TObjEneBm5GibonUFPv)
#define gibon_collision_body_templates ((u8 *)&gibon_collision_body_templates)
#define update_target__16TObjEneBm5GibonUFPv ((s32 (*)(void *))update_target__16TObjEneBm5GibonUFPv)
#define update_photon_mylla__16TObjEneBm5GibonUFPv ((void * (*)(void *))update_photon_mylla__16TObjEneBm5GibonUFPv)
#define TObjEneBm5GibonU__sub_800D1D70 ((s32 (*)())TObjEneBm5GibonU__sub_800D1D70)
#define TObjEneBm5GibonU__sub_800D0AE8 ((s32 (*)(void *, void *))TObjEneBm5GibonU__sub_800D0AE8)
#define turn_toward_angle__16TObjEneBm5GibonUFPvi ((s32 (*)(void *, s32))turn_toward_angle__16TObjEneBm5GibonUFPvi)
#define calc_anim_speed__16TObjEneBm5GibonUFPvf ((f32 (*)(void *, void *, f32))calc_anim_speed__16TObjEneBm5GibonUFPvf)
#define TObjEneBm5GibonU__node_list ((Node_800CE060 * *)&TObjEneBm5GibonU__node_list)
#define calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv ((s32 (*)(void *, s32, Vec_800CF4BC *, s32 *))calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv)
#define update_center_position__16TObjEneBm5GibonUFv ((s32 (*)(void *))update_center_position__16TObjEneBm5GibonUFv)

struct VBase_18_9e83f9
{
  char pad[0x18];
};

struct VObj_18_9e83f9 : VBase_18_9e83f9 {
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
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

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

struct VBase_18_599a64
{
  char pad[0x18];
};

struct VObj_18_599a64 : VBase_18_599a64 {
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
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
};

struct Sub_800CCB24 { u8 pad[0x18]; s32 f18; };

struct Obj_800CCB24 { u8 pad[0x2b0]; Sub_800CCB24 *f2b0; };

struct Dmg_800D086C { s32 kind; f32 amount; };

struct B_800D086C { u8 pad[0x18]; };

struct V_800D086C : B_800D086C {
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
    virtual void m21(u8 *r, Dmg_800D086C d, s32 a, s32 b, s32 c);
};

struct Obj_800D086C : V_800D086C { u8 pad2[0x474 - 0x1c]; u16 f474; };

struct Dmg_800D08E4 { s32 kind; f32 amount; };

struct B_800D08E4 { u8 pad[0x18]; };

struct V_800D08E4 : B_800D08E4 {
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
    virtual void m21(u8 *r, Dmg_800D08E4 d, s32 a, s32 b, s32 c);
};

struct Obj_800D08E4 : V_800D08E4 { u8 pad2[0x474 - 0x1c]; u16 f474; };

struct Base_800CCB74 {
    char pad[0x18];
};

struct Ene_800CCB74 : Base_800CCB74 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80(); virtual void v81(); virtual void v82(); virtual void v83();
    virtual void v84(); virtual void v85(); virtual void v86();
    virtual void m87();
    u8 pad1C[0x60 - 0x1C];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    struct Col_800CCB74 *col;
    u8 padA8[0x464 - 0xA8];
    s32 f464;
};

struct Col_800CCB74 {
    f32 f0;
    f32 f4;
    f32 f8;
    f32 fC;
    f32 f10;
    s32 f14;
    u32 flags;
};

typedef struct Vec_800CCC6C {
    f32 x, y, z;
} Vec_800CCC6C;

typedef struct Hit_800CCC6C {
    u32 flags;
    u8 *obj;
} Hit_800CCC6C;

typedef struct Ene_800CCC6C {
    u8 pad0[0x38];
    Vec_800CCC6C pos;
    u8 pad44[0x120 - 0x44];
    u8 f120[0x464 - 0x120];
    s32 f464;
} Ene_800CCC6C;

struct SubBase_800D02F8 {
    char pad[0x14];
};

struct Sub_800D02F8 : SubBase_800D02F8 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4();
    virtual s32 m5();
};

typedef struct Gibon_800D02F8 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0x3D8 - 0xBA];
    Sub_800D02F8 sub;
    u8 pad3F0[0x478 - 0x3F0];
    s32 f478;
    u8 pad47C[0x4AC - 0x47C];
    u32 f4AC;
    u8 pad4B0[0x540 - 0x4B0];
    f32 home[3];
} Gibon_800D02F8;

struct Node_800CFE34 { void *obj; Node_800CFE34 *next; };

struct List_800CFE34 { Node_800CFE34 *head; u8 pad[8]; };

struct Vec_800CE370 { f32 x, y, z; };

struct FadeBase_800CD204 { char pad[0x14]; };

struct Fade_800CD204 : FadeBase_800CD204 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    char pad2[4];
};

struct ObjBase_800CD204 { char pad[0x18]; };

struct Obj_800CD204 : ObjBase_800CD204 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
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
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    char pad1[0x3D8 - 0x1C];
    Fade_800CD204 sub;
    Fade_800CD204 fades[4];
};

struct Ang_800CD204 { s32 x, y, z; };

struct Vec_800CCC6C;
struct Hit_800CCC6C;
struct Vec_800CE694 { f32 x, y, z; };

struct Vec_800CE978 { f32 x, y, z; };

struct Vec_800CE060 { f32 x, y, z; };

struct Node_800CE060 { void *obj; Node_800CE060 *next; };

struct Vec_800CF4BC { f32 x, y, z; };

struct Ene_800CCB74;
struct VBase_800CDB98 { u8 pad[0x18]; };

struct Pl_800CDB98 : VBase_800CDB98 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual s32 m18(void *, f32); virtual void m19();
    virtual void m20(void *, f32); virtual void m21(); virtual void m22(); virtual void m23(void *, f32);
};

struct VObj_800CDB98 : VBase_800CDB98 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94();
};

struct Inner_800CDB98 { u8 pad[0x18]; u32 flags; };

struct Info_800CDB98 { u8 pad[0xA4]; Inner_800CDB98 *inner; };

struct Obj_800CDB98 : VObj_800CDB98 {
    u8 pad1C[0x38 - 0x1C];
    Vec_800CCC6C pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
    u8 pad64[0xB8 - 0x64];
    s16 fb8;
    u8 padBA[0xC0 - 0xBA];
    f32 fc0;
    u8 padC4[0x120 - 0xC4];
    u8 f120[0x2FC - 0x120];
    Vec_800CCC6C f2fc;
    u8 pad308[0x3A0 - 0x308];
    f32 f3a0;
    f32 f3a4;
    f32 f3a8;
    f32 f3ac;
    u8 pad3B0[0x494 - 0x3B0];
    f32 f494;
    f32 f498;
    u8 pad49C[0x4A8 - 0x49C];
    f32 f4a8;
    u32 f4ac;
    u8 pad4B0[0x50C - 0x4B0];
    Info_800CDB98 *f50c;
    u8 pad510[0x518 - 0x510];
    s32 f518;
    u8 pad51C[0x528 - 0x51C];
    s32 f528;
    s32 f52c;
};

struct VBase_18_444bc5 { char pad[0x18]; };

struct VObj_18_444bc5 : VBase_18_444bc5 {
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
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};

struct Vec_800CD5F4 { f32 x, y, z; };

extern "C" {
void enemy_clear_target__12TObjEneDD_STFUs(void *);
void TObjEneBm5GibonU__sub_800D01DC(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800D00F0(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CCDE4(u8 *arg0);
void TObjEneBm5GibonU__sub_800CCE28(u8 *arg0);
void TObjEneBm5GibonU__sub_800CFFBC(u8 *arg0, s32 arg1);
s32 transform_relative_position__9TObjEneDDFPv(void *, int);
void queue_destruction__7TObjectFv(void *self);
extern s32 game_difficulty_selection;
void fn_8002B630(u8 *arg0, u8 *arg1);
u8 check_hit_sphere__16TObjEneBm5GibonUFPvif(Ene_800CCB74 *arg0, s32 arg1, f32 scale);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
Hit_800CCC6C *csnVectorUnder(Vec_800CCC6C *, void *, s32);
void *spawn_particle_effect(void *, s32);
s32 fn_800D88E4(void *);
void TObjEneMe3SinowZoa__sub_800D758C(void *);
void TObjEneBm5GibonU__sub_800D02F8(Gibon_800D02F8 *g, s32 arg1);
void TObjEneBm5GibonU__sub_800CFE30(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CFA48(TObjEneBm5GibonU *self, s32 arg1);
void action__16TObjEneBm5GibonUFPvi(TObjEneBm5GibonU *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CFE34(u8 *arg0, s32 arg1);
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
void TObjEneBm5GibonU__sub_800CE370(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800D0420(u8 *arg0, s32 arg1);
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_obstruction_fade(void *);
s32 draw_blob_shadow(s32);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_z(s32, s32);
s32 rotate_matrix_x(s32, s32);
extern s32 TObjEneBm5GibonU__render_node_index;
extern s32 TObjEneBm5GibonU__render_joint_y_rotation;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
u32 enemy_probe_wall_ahead__13TBoss5GryphonFfff(void *, f32, f32, f32);
void TObjEneBm5GibonU__sub_800CE694(u8 *arg0, s32 arg1);
s32 is_vec_xz_cross_negative(void *, void *);
void TObjEneBm5GibonU__sub_800CE978(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800D095C(void *arg0, s32 arg1, s16 arg2);
s32 spawn_dead_spot_scale15(void *, s32);
s32 vec3_add_to(void *, void *);
void TObjEneBm5GibonU__sub_800CE060(u8 *arg0, s32 arg1);
void TObjEneBm5GibonU__sub_800CF4BC(u8 *arg0, s32 arg1);
Pl_800CDB98 *get_battle_param__10TObjPlayerFi(s32);
s32 obj_is_hit_receivable(void *);
void TObjEneBm5GibonU__sub_800CDB98(Obj_800CDB98 *arg0, s32 arg1);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
void move_with_wall_slide(u8 *arg0);
extern "C" {
void enemy_set_heading_velocity(TObjEnemy *arg0, s32 arg1, f32 farg0);
s32 select_enemy_destination(void *, Vec_800CD5F4, s32);
void copy_position_if_valid__10TObjPlayerFii(void *, Vec_800CD5F4);
s32 enemy_turn_toward_dest(void *, s32);
f32 newton_sqrtf(f32);
void fn_80044330(void *);
void *spawn_directional_particle(void *pos, void *dir, s32 id);
void rotate_vector_by_matrix(s32, void *, void *);
void subtract_vector(void *, void *);
s32 push_matrix_from(void *src);
s32 pop_matrices(s32 arg0);
extern u8 identity_matrix[];
extern s32 tl_07;
void TObjEneBm5GibonU__sub_800CF7CC(u8 *arg0, s32 arg1);

s32 TObjEneBm5GibonU::get_clamped_level() {
    Sub_800CCB24 *p = ((Obj_800CCB24 *)this)->f2b0;
    s32 v = 0;
    if (p != 0) {
        v = p->f18;
        if (v < 0) {
            v = 0;
        } else if (game_difficulty_selection == 3) {
            if (v > 0x1d) {
                v = 0x1d;
            }
        } else if (v > 0xe) {
            v = 0xe;
        }
    }
    return v;
}

u8 check_hit_sphere__16TObjEneBm5GibonUFPvif(Ene_800CCB74 *arg0, s32 arg1, f32 scale) {
    Col_800CCB74 *col;
    u8 hit;
    s32 saved60;
    u32 savedFlags;
    f32 r;
    r = scale * TObjEneBm5GibonU__data_805DA158;
    col = arg0->col;
    saved60 = arg0->f60;
    savedFlags = col->flags;
    col->f0 = 0.0f;
    col->f8 = r;
    col->fC = r;
    col->f10 = TObjEneBm5GibonU__data_805DA160;
    col->f14 = 1;
    col->flags = 0x9D01;
    arg0->f60 = arg1;
    arg0->m87();
    ((TObjPlayer *)arg0)->update_enemy_collision_flags();
    hit = (col->flags & 0x380000) != 0;
    if (arg0->f464 == 1) {
        fn_8002B630((u8 *)col, gibon_collision_body_templates + 0x2C);
    } else {
        fn_8002B630((u8 *)col, gibon_collision_body_templates);
    }
    col->flags = savedFlags;
    arg0->f60 = saved60;
    return hit;
}

int TObjEneBm5GibonU::get_attack_state(void * _w1) { return spawn_landing_effect__16TObjEneBm5GibonUFPvPv((Ene_800CCC6C *)(this), _w1); }

int spawn_landing_effect__16TObjEneBm5GibonUFPvPv(Ene_800CCC6C *arg0, void *arg1) {
    Vec_800CCC6C v;
    Hit_800CCC6C *hit;
    void *p;
    VecCopy((Vec *)&v, (const Vec *)arg1);
    v.y += TObjEneBm5GibonU__data_805DA164;
    hit = csnVectorUnder(&v, arg0->f120, 5);
    if (hit != NULL && (hit->flags & 4)) {
        p = spawn_particle_effect(hit->obj + 0x38, 0x49);
        if (p != NULL) {
            attach_particle_model((u8 *)p, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneBm5GibonU__data_805DA168);
            if (arg0->f464 == 1) {
                ((TObjPlayer *)p)->set_position_xy(TObjEneBm5GibonU__data_805DA16C, TObjEneBm5GibonU__data_805DA168);
            }
        }
        p = spawn_particle_effect(hit->obj + 0x38, 0xA4);
        if (p != NULL && arg0->f464 == 1) {
            ((TObjPlayer *)p)->set_position_xy(TObjEneBm5GibonU__data_805DA16C, TObjEneBm5GibonU__data_805DA168);
        }
        return fn_800D88E4(&arg0->pos);
    }
    return ((s32)play_sound_effect((void *)((void *)((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3BC21))), &arg0->pos, 0, 0));
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800CCD8C(u8 *arg0) {
    if ((objInBand__FP7GameObjf(arg0, TObjEneBm5GibonU__data_805DA170) != 0) || (objInBand__FP7GameObjf(arg0, TObjEneBm5GibonU__data_805DA174) != 0)) {
        spawn_landing_effect__16TObjEneBm5GibonUFPvPv((Ene_800CCC6C *)(arg0), arg0 + 0x38);
    }
}
#pragma pop

void TObjEneBm5GibonU__sub_800CCDE4(u8 *ene_bm5_gibon_u) {
    if (objInBand__FP7GameObjf(ene_bm5_gibon_u, TObjEneBm5GibonU__data_805DA178) != 0) {
        ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->get_attack_state(ene_bm5_gibon_u + 0x38);
    }
}

void TObjEneBm5GibonU__sub_800CCE28(u8 *ene_bm5_gibon_u) {
    if ((objInBand__FP7GameObjf(ene_bm5_gibon_u, lbl_805DA17C) != 0) || (objInBand__FP7GameObjf(ene_bm5_gibon_u, TObjEneBm5GibonU__data_805DA174) != 0)) {
        ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->get_attack_state(ene_bm5_gibon_u + 0x38);
    }
}

extern "C" {
#undef TObjEneBm5GibonU__data_805DA160
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA160[1] = { 8.0f };
#undef TObjEneBm5GibonU__data_805DA164
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA164[1] = { 15.0f };
#undef TObjEneBm5GibonU__data_805DA168
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA168[1] = { 1.0f };
#undef TObjEneBm5GibonU__data_805DA16C
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA16C[1] = { 1.5f };
#undef TObjEneBm5GibonU__data_805DA170
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA170[1] = { 7.0f };
#undef TObjEneBm5GibonU__data_805DA174
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA174[1] = { 28.0f };
#undef TObjEneBm5GibonU__data_805DA178
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA178[1] = { 10.0f };
#undef lbl_805DA17C
__declspec(section ".sdata2") const f32 lbl_805DA17C[1] = { 12.0f };
#undef lbl_805DA180
__declspec(section ".sdata2") const f32 lbl_805DA180[1] = { 400.0f };
#undef TObjEneBm5GibonU__data_805DA184
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA184[1] = { 20.0f };
#undef TObjEneBm5GibonU__data_805DA188
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA188[1] = { 2.0f };
#undef TObjEneBm5GibonU__data_805DA18C
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA18C[1] = { -10.0f };
}
#define TObjEneBm5GibonU__data_805DA160 (TObjEneBm5GibonU__data_805DA160[0])
#define TObjEneBm5GibonU__data_805DA164 (TObjEneBm5GibonU__data_805DA164[0])
#define TObjEneBm5GibonU__data_805DA168 (TObjEneBm5GibonU__data_805DA168[0])
#define TObjEneBm5GibonU__data_805DA16C (TObjEneBm5GibonU__data_805DA16C[0])
#define TObjEneBm5GibonU__data_805DA170 (TObjEneBm5GibonU__data_805DA170[0])
#define TObjEneBm5GibonU__data_805DA174 (TObjEneBm5GibonU__data_805DA174[0])
#define TObjEneBm5GibonU__data_805DA178 (TObjEneBm5GibonU__data_805DA178[0])
#define lbl_805DA17C (lbl_805DA17C[0])
#define lbl_805DA180 (lbl_805DA180[0])
#define TObjEneBm5GibonU__data_805DA184 (TObjEneBm5GibonU__data_805DA184[0])
#define TObjEneBm5GibonU__data_805DA188 (TObjEneBm5GibonU__data_805DA188[0])
#define TObjEneBm5GibonU__data_805DA18C (TObjEneBm5GibonU__data_805DA18C[0])
void TObjEneBm5GibonU::render_debug() {
    u8 *arg0 = (u8 *)this;
    Gibon_800CCE80 *self = (Gibon_800CCE80 *)arg0;
    Vec_800CCE80 v;
    s32 idx;
    f32 frame;
    Motion_800CCE80 *motion;
    s32 other;
    if (get_target_info__9TObjEneDDFv() != 0) {
        debug_printf_at(pack_debug_text_position(0, 2), lbl_8043C07C, self->f46C);
        if (self->f470 == 1) {
            debug_printf_at(pack_debug_text_position(0, 3), lbl_8043C088);
        } else {
            debug_printf_at(pack_debug_text_position(0, 3), lbl_8043C094);
        }
        if (self->f464 != 0) {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_8043C0A0);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_8043C0AC);
        }
        debug_printf_at(pack_debug_text_position(0, 4), lbl_8043C0B8);
        debug_printf_at(pack_debug_text_position(0, 5), lbl_8043C0C8);
        debug_printf_at(pack_debug_text_position(0, 6), lbl_8043C0D8);
    }
    if (self->m8(lbl_805DA180, TObjEneBm5GibonU__data_805DA184) != 0) {
        update_player_state__9TObjEneDDFv(self, 0, 0);
        TObjFish::set_global_param(self->f24);
        push_matrix();
        post_translate_matrix(&self->pos);
        rotate_matrix_y(0, self->rot_y);
        if (self->f464 == 1) {
            scale_matrix(0, TObjEneBm5GibonU__data_805DA16C, TObjEneBm5GibonU__data_805DA16C, TObjEneBm5GibonU__data_805DA16C);
        } else {
            scale_matrix(0, TObjEneBm5GibonU__data_805DA188, TObjEneBm5GibonU__data_805DA188, TObjEneBm5GibonU__data_805DA188);
        }
        idx = (s32)self->anim;
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x11) {
            idx = 0x10;
        }
        motion = self->refs[self->sel[idx].index].motion;
        frame = self->frame;
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (motion->count - 1)) {
            frame = (f32)motion->count;
        }
        translate_matrix(0, 0.0f, 0.0f, TObjEneBm5GibonU__data_805DA18C);
        TObjPlayer::toggle_particle_effect();
        TObjPlayer::set_global_flag();
        draw_model_motion((void *)self->model, motion, frame);
        TObjPlayer::clear_global_state();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
    other = ((s32)find_enemy_by_id__16TObjEneBm5GibonUFi(self->f46C));
    if (other != 0) {
        TObjMapWarp__sub_80141CB0(&self->center, (void *)(other + 0x2FC), 0xFFC0C0C0, 0xFF6060FF);
        return;
    }
    VecCopy((Vec *)&v, (const Vec *)&self->center);
    v.y += 50.0f;
    TObjMapWarp__sub_80141CB0(&self->center, &v, 0xFFC0C0C0, 0xFF6060FF);
}

s32 TObjEneBm5GibonU::vfunc_83() {
    s32 temp_r31;

    if (get_target_info__9TObjEneDDFv() != 0) {
        temp_r31 = *(s32 *)((s8 *)this + 0x464);
        sub_800D10A0();
        if (temp_r31 != (s32) *(s32 *)((s8 *)this + 0x464)) {
            if (temp_r31 != 0) {
                forward_hit_to_enemy_list();
            } else {
                init_child_from_list();
            }
        }
        update_center_position__16TObjEneBm5GibonUFv(this);
    }
}

void TObjEneBm5GibonU::render() {
    Ang_800CD204 rot;
    s32 cam;
    s32 vis;
    s32 fade;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((Obj_800CD204 *)((u8 *)this))->m104();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (!(*(s32 *)((s8 *)((u8 *)this) + 0x4AC) & 2) && this->mode != 0x12) {
        fade = 0;
        if (*(s32 *)((s8 *)((u8 *)this) + 0x464) != 0) {
            update_obstruction_fade(&((Obj_800CD204 *)((u8 *)this))->fades[cam]);
            fade = ((RenderFadeState *)(&((Obj_800CD204 *)((u8 *)this))->fades[cam]))->updateFromCamera((const f32*)(((u8 *)this) + 0x2FC));
        }
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            vis = ((Obj_800CD204 *)((u8 *)this))->m9(lbl_805D9E88, lbl_805D9E84, TObjEneBm5GibonU__data_805DA184);
        } else if (((Obj_800CD204 *)((u8 *)this))->m8(lbl_805DA180, TObjEneBm5GibonU__data_805DA184) != 0) {
            vis = 1;
        } else {
            vis = 0;
        }
        if (vis != 0) {
            if (this->mode != 0x11) {
                direction_to_rotation_xz(((u8 *)this) + 0x248, &rot.x, &rot.z);
                push_matrix();
                post_translate_matrix(((u8 *)this) + 0x38);
                translate_matrix(0, 0.0f, TObjEneBm5GibonU__data_805DA194, 0.0f);
                rotate_matrix_z(0, rot.z);
                rotate_matrix_x(0, rot.x);
                rotate_matrix_y(0, this->rotation_y);
                translate_matrix(0, 0.0f, 0.0f, lbl_805DA198);
                scale_matrix(0, TObjEneBm5GibonU__data_805DA188, TObjEneBm5GibonU__data_805DA168, lbl_805DA19C);
                rotate_matrix_x(0, -0x4000);
                draw_blob_shadow(0);
                pop_matrix();
            }
            this->update_secondary_light();
            TObjFish::set_global_param(this->texture_id);
            push_matrix();
            if (this->mode == 1 || this->mode == 2) {
                ((Obj_800CD204 *)((u8 *)this))->sub.m6();
            } else if (fade != 0) {
                ((Obj_800CD204 *)((u8 *)this))->fades[cam].m6();
            }
            post_translate_matrix(((u8 *)this) + 0x38);
            rotate_matrix_y(0, this->rotation_y);
            translate_matrix(0, 0.0f, 0.0f, TObjEneBm5GibonU__data_805DA18C);
            if (*(s32 *)((s8 *)((u8 *)this) + 0x464) == 1) {
                scale_matrix(0, TObjEneBm5GibonU__data_805DA16C, TObjEneBm5GibonU__data_805DA16C, TObjEneBm5GibonU__data_805DA16C);
            } else {
                scale_matrix(0, TObjEneBm5GibonU__data_805DA188, TObjEneBm5GibonU__data_805DA188, TObjEneBm5GibonU__data_805DA188);
            }
            TObjEneBm5GibonU__render_node_index = 0;
            TObjEneBm5GibonU__render_joint_y_rotation = -(*(s32 *)((s8 *)((u8 *)this) + 0x478) / 2);
            TObjEneRe7Berura::set_global_state((s32)((s32 *)TObjEneBm5GibonU::advance_anim_frame));
            TObjEneDD::clear_global_flag_400();
            TObjPlayer::toggle_particle_effect();
            if (fade != 0) {
                if (defer_render__7TObjectFv(this) == 0) {
                    if (vis == 1) {
                        this->draw();
                    } else {
                        this->render_world_model();
                    }
                }
            } else if (vis == 1) {
                this->draw();
            } else {
                this->render_world_model();
            }
            TObjEneRe7Berura::set_global_state((s32)NULL);
            if (this->mode == 1 || this->mode == 2) {
                ((Obj_800CD204 *)((u8 *)this))->sub.m7();
            } else if (fade != 0) {
                ((Obj_800CD204 *)((u8 *)this))->fades[cam].m7();
            }
            pop_matrix();
            this->update_primary_light();
        }
        TParticleCtrl::end_effect_render();
    }
}

void TObjEneBm5GibonU::advance_anim_frame() {
    if (((s32) TObjEneBm5GibonU__render_node_index >= 0x30) && ((s32) TObjEneBm5GibonU__render_node_index < 0x32)) {
        rotate_matrix_y(0, TObjEneBm5GibonU__render_joint_y_rotation);
    }
    TObjEneBm5GibonU__render_node_index += 1;
}

void TObjEneBm5GibonU::handle_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction__7TObjectFv(this);
        return;
    }
}

struct Obj_800CCB24;
#define F(t, o) (*(t *)(arg0 + (o)))
#define VO ((VObj_18_444bc5 *)(arg0))
#define V(o) (*(Vec_800CD5F4 *)(arg0 + (o)))
#define CB24(a) ((TObjEneBm5GibonU *)a)->get_clamped_level()
void TObjEneBm5GibonU::state_cast_technique(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec_800CD5F4 v;
    Vec_800CD5F4 p;
    s32 ang[3];
    s32 r;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0;
        ((TObjEneDD *)arg0)->set_field_378(14);
        VO->m94();
        F(s32, 0x4AC) &= ~2;
        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        F(s32, 0x518) = 0;
        break;
    case 3:
        if (F(s32, 0x518) == 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 8);
        }
        break;
    case 0:
        ((TObjEnemy *)arg0)->update_prev_position();
        if (F(s32, 0x518) != 1) {
            if (F(u32, 0x390) == 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 8);
            } else {
                if (select_enemy_destination(arg0, V(0x394), 1) != 0) {
                    copy_position_if_valid__10TObjPlayerFii(arg0, V(0x2FC));
                    r = enemy_turn_toward_dest(arg0, *(s32 *)(F(u8 *, 0x350) + 8));
                    enemy_set_heading_velocity((TObjEnemy *)arg0, F(s32, 0x60), *(f32 *)(F(u8 *, 0x350) + 4));
                    move_with_wall_slide(arg0);
                } else {
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x394));
                    subtract_vector(&v, arg0 + 0x2FC);
                    r = update_angle__10TObjPlayerFlPv(arg0, *(s32 *)(F(u8 *, 0x350) + 8), &v);
                }
                if (r < 0x100) {
                    F(s32, 0x518) = 1;
                    F(s16, 0xB8) = 13;
                } else {
                    F(s16, 0xB8) = 1;
                }
            }
        } else {
            advance_animation_playback(arg0);
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x518) = 2;
            }
            if (objInBand__FP7GameObjf(arg0, TObjEneBm5GibonU__data_805DA164) != 0) {
                p.x = 0.0f;
                p.y = TObjEneBm5GibonU__data_805DA164;
                p.z = lbl_805DA17C;
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, F(s32, 0x60));
                rotate_vector_by_matrix(0, &p, &p);
                pop_matrices(1);
                vec3_add_to(&p, arg0 + 0x2FC);
                if (F(u32, 0x390) != 0) {
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x394));
                    subtract_vector(&v, arg0 + 0x2FC);
                    r = update_angle__10TObjPlayerFlPv(arg0, *(s32 *)(F(u8 *, 0x350) + 8), &v);
                } else {
                    r = ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c();
                }
                if (game_difficulty_selection == 3) {
                    switch (F(s32, 0x468)) {
                    case 1:
                        if (r < ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c() / 2 && F(u32, 0x390) != 0) {
                            TTecMegid::create((s32)arg0, (s32)&p, (s32)(arg0 + 0x394), (s32)(CB24(arg0)));
                        } else {
                            TTecMegid::create_ex((s32)arg0, (s32)&p, (s32)(F(s32, 0x60)), (s32)(CB24(arg0)));
                        }
                        play_sound_effect((void *)0x4002A60B, &p, 0, 0);
                        break;
                    default:
                        if (r < ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c() / 2 && F(u32, 0x390) != 0) {
                            fn_80044330(arg0 + 0x4B0);
                            F(s32, 0x4B0) = 1;
                            F(s16, 0x4B4) = get_entity_id(F(u32, 0x390));
                            F(s16, 0x4B6) = 0;
                            ((TTecGiZonde *)arg0)->create(&p, arg0 + 0x4B0, (void *)(CB24(arg0)));
                        } else {
                            void *e;
                            spawn_particle_effect(&p, 0xB9);
                            spawn_particle_effect(&p, 0xBA);
                            v.x = 0.0f;
                            v.y = 0.0f;
                            v.z = TObjEneBm5GibonU__data_805DA168;
                            push_matrix_from(identity_matrix);
                            rotate_matrix_y(0, F(s32, 0x60));
                            rotate_vector_by_matrix(0, &v, &v);
                            pop_matrix();
                            e = __nw__7TObjectFUl(0x260);
                            if (e != 0) {
                                ((TTecZonde *)e)->construct_bolt_effect((u8 *)tl_07, (u8 *)&p, (u8 *)&v, 0x14000000, 20, (f32)(((TObjPlayer *)(F(s32, 0x318)))->get_pos_x()), (f32)lbl_805DA1A0);
                            }
                        }
                        play_sound_effect((void *)0x4002A408, &p, 0, 0);
                        break;
                    }
                } else {
                    switch (F(s32, 0x468)) {
                    case 1:
                        ((TTecGiBarta *)arg0)->create_ex(&p, (void *)(F(s32, 0x60)), (void *)(CB24(arg0)));
                        break;
                    default:
                        if (r < ((TObjPlayer *)(F(s32, 0x318)))->get_field_0c() / 2 && F(u32, 0x390) != 0) {
                            TTecFoie::create_ex((void *)arg0, &p, (void *)(F(u8 *, 0x390) + 0x2FC), (void *)(CB24(arg0)));
                        } else {
                            TTecFoie::create((void *)arg0, &p, (void *)(F(s32, 0x60)), (void *)(CB24(arg0)));
                        }
                        break;
                    }
                    v.x = 0.0f;
                    v.y = 0.0f;
                    v.z = 0.0f;
                    push_matrix_from(identity_matrix);
                    rotate_matrix_y(0, F(s32, 0x60));
                    rotate_vector_by_matrix(0, &v, &v);
                    pop_matrices(1);
                    if (F(s32, 0x468) != 1) {
                        ang[0] = (s32)(TObjEneBm5GibonU__data_8043C0F8 * atan2_float(v.z, newton_sqrtf(v.x * v.x + v.y * v.y)));
                        ang[1] = 0;
                        ang[2] = -(s32)(TObjEneBm5GibonU__data_8043C0F8 * atan2_float(v.x, v.y));
                        spawn_directional_particle(&p, ang, 0xCC);
                    }
                }
            }
        }
        break;
    case 5:
        break;
    }
    update_collisions__10TObjPlayerFv(arg0);
}

void TObjEneBm5GibonU__sub_800CDB98(Obj_800CDB98 *actor, s32 arg1) {
    s32 offs[3];
    switch (arg1) {
    case 4:
        actor->fb8 = 0xC;
        ((TObjEneDD *)actor)->set_field_378(0xE);
        actor->m94();
        actor->f4ac &= ~2;
        actor->f518 = 0;
        actor->f52c = 0;
        offs[0] = (s32)(lbl_805DA19C * calc_boss4_scale__10TObjPlayerFi((s32)actor)) - 1;
        offs[1] = (s32)(TObjEneBm5GibonU__data_805DA188 * calc_boss4_scale__10TObjPlayerFi((s32)actor)) - 1;
        if (offs[1] <= offs[0]) {
            offs[1]++;
        }
        actor->f3a0 = 0.0f;
        actor->f3a4 = 0.0f;
        actor->f3a8 = 0.0f;
        offs[2] = -(offs[0] + offs[1]);
        actor->f3ac = 0.0f;
        if (update_target__16TObjEneBm5GibonUFPv(actor) != 0) {
            s32 d;
            s32 ang;
            s32 i;
            ((TObjEneDD_ST *)actor)->enemy_copy_target_destination();
            ((TObjEneDD *)actor)->update_velocity();
            actor->f528 = (s32)(TObjEneBm5GibonU__data_8043C0F8 * atan2_float(actor->f3a0, actor->f3a8));
            for (i = 0; i < 3; i++) {
                d = offs[i] * 0x1FFF;
                ang = actor->f528 + 0x10000 + d - 0x8000;
                if (((s32 (*)(void *, s32, f32))check_hit_sphere__16TObjEneBm5GibonUFPvif)(actor, ang, lbl_805DA1A4) == 0) {
                    f32 dx = TObjEneBm5GibonU__data_805DA188 * (lbl_805DA1A8 * sin_table_lookup(ang));
                    f32 dz = TObjEneBm5GibonU__data_805DA188 * (lbl_805DA1A8 * cos_table_lookup(ang));
                    if (enemy_probe_wall_ahead__13TBoss5GryphonFfff(actor, dx, dz, TObjEneBm5GibonU__data_805DA168) == 0) {
                        Vec_800CCC6C v;
                        VecCopy((Vec *)&v, (const Vec *)&actor->f2fc);
                        v.x += dx;
                        v.z += dz;
                        if (csnVectorUnder(&v, actor->f120, 0x15) != 0) {
                            actor->f3a0 = sin_table_lookup(ang);
                            actor->f3a4 = 0.0f;
                            actor->f3a8 = cos_table_lookup(ang);
                            actor->f3ac = lbl_805DA1A8;
                            actor->f528 += d / 2;
                            break;
                        }
                    }
                }
            }
        }
        actor->f498 = actor->f494 = actor->f3ac / lbl_805DA1AC;
        actor->f518 = 0;
        actor->m89();
        break;
    case 3:
        if (actor->f518 == 1) {
            if (calc_boss4_scale__10TObjPlayerFi((s32)actor) < actor->f4a8) {
                transition_enemy_state__9TObjEneDDFs(actor, 0x14);
            } else {
                transition_enemy_state__9TObjEneDDFs(actor, 8);
            }
        }
        break;
    case 0:
        switch (actor->f518) {
        case 0:
            advance_animation_playback(actor);
            if (((TObjEneDD *)actor)->get_flag_b4() != 0) {
                actor->f518 = 1;
            }
            TObjEneBm5GibonU__sub_800CCD8C((u8 *)actor);
            if (objInBand__FP7GameObjf(actor, TObjEneBm5GibonU__data_805DA160) != 0) {
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(actor, 0x3B22A), &actor->pos, 0, 0);
            }
            if (objInBand__FP7GameObjf(actor, lbl_805DA1AC) != 0) {
                actor->m90();
                TObjPlayer::init_all_slots();
                ((TObjPlayer *)actor)->check_object_collisions();
                if (actor->f50c->inner->flags & 0x80000) {
                    s32 i;
                    for (i = 0; i < 16; i++) {
                        Pl_800CDB98 *p = get_battle_param__10TObjPlayerFi(i);
                        if (p == 0) {
                            break;
                        }
                        if (obj_is_hit_receivable(p) != 0 && p->m18(actor, TObjEneBm5GibonU__data_805DA168) != 0) {
                            p->m23(actor, TObjEneBm5GibonU__data_805DA168);
                            p->m20(actor, TObjEneBm5GibonU__data_805DA168);
                        }
                    }
                }
            }
            ((TObjEneBm5GibonU *)actor)->approach_target(TObjEneBm5GibonU__data_805DA1B0);
            actor->rotY = approach_angle_limited(actor->rotY, actor->f528, 0x1000);
            actor->rotY = (s16)actor->rotY;
            turn_toward_angle__16TObjEneBm5GibonUFPvi(actor, actor->rotY);
            if (actor->fc0 <= lbl_805DA1AC) {
                ((TObjEneDD *)actor)->move_with_wall_slide_on_ground(actor->f3a0, actor->f3a8, actor->f498);
            }
            break;
        }
        actor->m87();
        ((TObjPlayer *)actor)->update_enemy_collision_flags();
        break;
    case 5:
        ((TObjEneBm5GibonU *)actor)->play_sound_variant();
        actor->m90();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CE060(u8 *arg0, s32 arg1) {
    Vec_800CE060 sp14;
    Vec_800CE060 sp8;
    f32 k;
    Node_800CE060 *n;
    u8 *o;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)arg0)->vfunc_96();
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3A826), arg0 + 0x38, 0, 0);
        *(s16 *)((s8 *)arg0 + 0xB8) = 0xB;
        TBoss8Dragon__sub_800BB7D4(arg0, 0xF1);
        *(s32 *)((s8 *)arg0 + 0x518) = 0;
        *(f32 *)((s8 *)arg0 + 0x530) = calc_anim_speed__16TObjEneBm5GibonUFPvf(arg0, *(u8 **)((s8 *)arg0 + 0xD8), *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xD8)) + 0x78));
        *(f32 *)((s8 *)arg0 + 0x538) = 0.0f;
        *(f32 *)((s8 *)arg0 + 0x37C) = 0.0f;
        if (*(s32 *)((s8 *)arg0 + 0x464) != 0) {
            k = 50.0f;
            for (n = TObjEneBm5GibonU__node_list[0]; n != NULL; n = n->next) {
                o = (u8 *)update_photon_mylla__16TObjEneBm5GibonUFPv(n);
                if (o != NULL && *(s32 *)((s8 *)o + 0x46C) == *(s32 *)((s8 *)arg0 + 0x46C)) {
                    ((void (*)(void *, s32, u16))TObjEneBm5GibonU__sub_800D095C)(o, (s32)(k * calc_boss4_scale__10TObjPlayerFi((s32)arg0)) + 0x14, *(u16 *)((s8 *)arg0 + 0x2D4));
                }
            }
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        return;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x518) == 2) {
            transition_enemy_state__9TObjEneDDFs(arg0, 0x12);
        }
    case 1:
        return;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x518)) {
        case 0:
            advance_animation_playback(arg0);
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x518) = 1;
                sp14.x = 0.0f;
                sp14.y = 0.0f;
                sp14.z = TObjEneBm5GibonU__data_805DA18C;
                rotate_xz_pair_by_angle(&sp14.x, &sp14.z, *(s32 *)((s8 *)arg0 + 0x60));
                vec3_add_to(&sp14, arg0 + 0x38);
                if (*(s32 *)((s8 *)arg0 + 0x464) == 1) {
                    spawn_dead_spot_scale15(&sp14, 0x32);
                } else {
                    TObjPlayer::spawn_dead_spot_type2((s32)&sp14, 0x32);
                }
                ((TObjPlayer *)(&sp14))->spawn_effect_at_ground(0x46);
            }
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited(*(s32 *)((s8 *)arg0 + 0x60), *(s32 *)((s8 *)arg0 + 0x528), 0x300);
            *(s32 *)((s8 *)arg0 + 0x60) = (s16)*(s32 *)((s8 *)arg0 + 0x60);
            if (*(f32 *)((s8 *)arg0 + 0x37C) < TObjEneBm5GibonU__data_805DA174) {
                *(f32 *)((s8 *)arg0 + 0x37C) += *(f32 *)((s8 *)arg0 + 0x530);
            }
            VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0x308));
            {
                f32 v = clamp_velocity__15TObjBoss2TunnelFv(&sp8);
                ((TObjEneDD *)arg0)->move_clamped_on_ground(sp8.x, sp8.z, v);
            }
            if (objInBand__FP7GameObjf(arg0, lbl_805DA1B4) != 0) {
                TObjEneBm5GibonU__sub_800D0AE8(arg0, &sp8);
            }
            *(f32 *)((s8 *)arg0 + 0x308) *= TObjEneBm5GibonU__data_805DA1B8;
            *(f32 *)((s8 *)arg0 + 0x310) *= TObjEneBm5GibonU__data_805DA1B8;
            turn_toward_angle__16TObjEneBm5GibonUFPvi(arg0, *(s32 *)((s8 *)arg0 + 0x60));
            ((TObjEneDD *)arg0)->vfunc_88();
            break;
        case 1:
            *(f32 *)((s8 *)arg0 + 0x3C) -= TObjEneBm5GibonU__data_805DA1B0;
            *(f32 *)((s8 *)arg0 + 0x538) += TObjEneBm5GibonU__data_805DA1B0;
            if (*(f32 *)((s8 *)arg0 + 0x538) > TObjEneBm5GibonU__data_805DA184) {
                *(s32 *)((s8 *)arg0 + 0x518) = 2;
            }
            break;
        }
        break;
    case 5:
        ((TObjEneDD *)arg0)->clear_field_388();
        return;
    }
}

void TObjEneBm5GibonU__sub_800CE370(u8 *arg0, s32 arg1) {
    Vec_800CE370 sp8;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)(arg0))->vfunc_96();
        TBoss8Dragon__sub_800BB7D4(arg0, 0xF1);
        *(s32 *)((s8 *)arg0 + 0x51C) = 0;
        *(s32 *)((s8 *)arg0 + 0x528) = 0;
        *(s16 *)((s8 *)arg0 + 0xB8) = 6;
        *(s32 *)((s8 *)arg0 + 0x518) = 0;
        if (*(s16 *)((s8 *)arg0 + 0x33E) - *(s16 *)((s8 *)arg0 + 0x32C) < 0x14) {
            play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3A824), arg0 + 0x38, 0, 0);
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0xB0) & 0x10) {
            switch (*(s32 *)((s8 *)arg0 + 0x378)) {
            case 12:
                transition_enemy_state__9TObjEneDDFs(arg0, 0xE);
                break;
            case 3:
                transition_enemy_state__9TObjEneDDFs(arg0, 8);
                break;
            default:
                transition_enemy_state__9TObjEneDDFs(arg0, *(s32 *)((s8 *)arg0 + 0x378));
                break;
            }
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0x308));
        {
            f32 v = clamp_velocity__15TObjBoss2TunnelFv(&sp8);
            ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(sp8.x, sp8.z, v);
        }
        if (*(s32 *)((s8 *)arg0 + 0x518) == 0) {
            *(f32 *)((s8 *)arg0 + 0x308) *= TObjEneBm5GibonU__data_805DA158;
            *(f32 *)((s8 *)arg0 + 0x310) *= TObjEneBm5GibonU__data_805DA158;
        } else {
            *(f32 *)((s8 *)arg0 + 0x308) *= TObjEneBm5GibonU__data_805DA1BC;
            *(f32 *)((s8 *)arg0 + 0x310) *= TObjEneBm5GibonU__data_805DA1BC;
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited(*(s32 *)((s8 *)arg0 + 0x60), *(s32 *)((s8 *)arg0 + 0x528), 0x300);
            *(s32 *)((s8 *)arg0 + 0x60) = (s16) *(s32 *)((s8 *)arg0 + 0x60);
            if (objInBand__FP7GameObjf(arg0, lbl_805DA1B4) != 0) {
                TObjEneBm5GibonU__sub_800D0AE8(arg0, &sp8);
            }
        }
        ((TObjEneDD *)(arg0))->vfunc_89();
        ((TObjPlayer *)arg0)->update_enemy_collision_flags();
        break;
    case 5:
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

void action__16TObjEneBm5GibonUFPvi(TObjEneBm5GibonU *ene_bm5_gibon_u, s32 arg1) {
    s32 temp_r0;

    switch (arg1) {
    case 4:
        ene_bm5_gibon_u->vfunc_96();
        ((TObjEneDD *)ene_bm5_gibon_u)->set_field_378(8);
        ene_bm5_gibon_u->m_b8 = 9;
        *(s32 *)((s8 *)ene_bm5_gibon_u + 0x518) = 0;
        find_enemy_by_id__16TObjEneBm5GibonUFi(*(s32 *)((s8 *)ene_bm5_gibon_u + 0x46C));
        return;
    case 3:
        if (((TObjEneDD *)ene_bm5_gibon_u)->get_flag_b4() != 0) {
            transition_enemy_state__9TObjEneDDFs(ene_bm5_gibon_u, 8);
        }
    case 5:
        return;
    case 0:
        advance_animation_playback(ene_bm5_gibon_u);
        turn_toward_angle__16TObjEneBm5GibonUFPvi(ene_bm5_gibon_u, ene_bm5_gibon_u->rotation_y);
        if (objInBand__FP7GameObjf(ene_bm5_gibon_u, TObjEneBm5GibonU__data_805DA178) != 0) {
            play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(ene_bm5_gibon_u, 0x3AA22), (u8 *)ene_bm5_gibon_u + 0x38, 0, 0);
        }
        *(s32 *)((s8 *)ene_bm5_gibon_u + 0x518) = (s32) (*(s32 *)((s8 *)ene_bm5_gibon_u + 0x518) + 1);
        temp_r0 = *(s32 *)((s8 *)ene_bm5_gibon_u + 0x518);
        if (temp_r0 == 0x1E) {
            ene_bm5_gibon_u->damage_linked_entity_type10();
        } else if (temp_r0 == 0x28) {
            ene_bm5_gibon_u->damage_linked_entity();
        }
        ene_bm5_gibon_u->vfunc_89();
        ((TObjPlayer *)ene_bm5_gibon_u)->update_enemy_collision_flags();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CE694(u8 *arg0, s32 arg1) {
    Vec_800CE694 v;
    f32 dx;
    f32 dz;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((TObjEneDD *)arg0)->set_field_378(0xE);
        ((TBoss5Gryphon *)arg0)->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x518) = 0;
        *(s32 *)((s8 *)arg0 + 0x528) = 0;
        *(s32 *)((s8 *)arg0 + 0x51C) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x518) == 2) {
            if (*(u32 *)((s8 *)arg0 + 0x390) != 0U) {
                transition_enemy_state__9TObjEneDDFs(arg0, 0xB);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, 8);
            }
        }
        break;
    case 5:
        break;
    case 0:
        ((s32 (*)(void *, s32))advance_animation_playback)(arg0, arg1);
        switch (*(s32 *)((s8 *)arg0 + 0x518)) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x528) = ((*(s32 *)((s8 *)arg0 + 0x51C) >> 1) << 0xC) + 0x1800;
            if (*(s32 *)((s8 *)arg0 + 0x51C) & 1) {
                *(s32 *)((s8 *)arg0 + 0x528) = -*(s32 *)((s8 *)arg0 + 0x528);
            }
            if (is_active__16TObjEneBm5GibonUFPv(arg0) == 0) {
                *(s32 *)((s8 *)arg0 + 0x528) = -*(s32 *)((s8 *)arg0 + 0x528);
            }
            *(s32 *)((s8 *)arg0 + 0x528) += *(s32 *)((s8 *)arg0 + 0x60);
            (*(s32 *)((s8 *)arg0 + 0x51C))++;
            if (*(s32 *)((s8 *)arg0 + 0x51C) > 8) {
                *(s32 *)((s8 *)arg0 + 0x518) = 2;
            }
            dx = lbl_805DA1C0 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x528));
            dz = lbl_805DA1C0 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x528));
            *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x50C)) + 0x38) = *(f32 *)((s8 *)arg0 + 0x38) + dx;
            *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x50C)) + 0x3C) = *(f32 *)((s8 *)arg0 + 0x3C);
            *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x50C)) + 0x40) = *(f32 *)((s8 *)arg0 + 0x40) + dz;
            update_collisions__10TObjPlayerFv(*(u8 **)((s8 *)arg0 + 0x50C));
            if (!(*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x50C)) + 0xA4)) + 0x18) & 0x380000)) {
                dx *= TObjEneBm5GibonU__data_805DA188;
                dz *= TObjEneBm5GibonU__data_805DA188;
                if (enemy_probe_wall_ahead__13TBoss5GryphonFfff(arg0, dx, dz, TObjEneBm5GibonU__data_805DA168) == 0U) {
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x2FC));
                    v.x += dx;
                    v.z += dz;
                    if (csnVectorUnder((Vec_800CCC6C *)&v, arg0 + 0x120, 0x15) != NULL) {
                        *(s32 *)((s8 *)arg0 + 0x518) = 1;
                        *(s16 *)((s8 *)arg0 + 0xB8) = 0x10;
                        *(f32 *)((s8 *)arg0 + 0x3A0) = sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x528));
                        *(f32 *)((s8 *)arg0 + 0x3A4) = 0.0f;
                        *(f32 *)((s8 *)arg0 + 0x3A8) = cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x528));
                    }
                }
            }
            break;
        case 1:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                update_target__16TObjEneBm5GibonUFPv(arg0);
                *(s32 *)((s8 *)arg0 + 0x518) = 2;
            }
            TObjEneBm5GibonU__sub_800CCDE4(arg0);
            ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), lbl_805DA1A0);
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited(*(s32 *)((s8 *)arg0 + 0x60), *(s32 *)((s8 *)arg0 + 0x528), 0xF00);
            turn_toward_angle__16TObjEneBm5GibonUFPvi(arg0, *(s32 *)((s8 *)arg0 + 0x528));
            ((TBoss5Gryphon *)arg0)->vfunc_89();
            ((TObjPlayer *)arg0)->update_enemy_collision_flags();
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800CE978(u8 *actor, s32 arg1) {
    Vec_800CE978 dir;
    Vec_800CE978 diff;
    Vec_800CE978 *home = (Vec_800CE978 *)(actor + 0x54C);
    f32 range = *(f32 *)((s8 *)actor + 0x530);
    u8 *tgt;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 1;
        ((TObjEneDD *)actor)->set_field_378(0xD);
        ((TObjEneDD *)(actor))->vfunc_96();
        *(f32 *)((s8 *)actor + 0x494) = lbl_805DA1C4;
        *(s32 *)((s8 *)actor + 0x518) = 0;
        VecCopy((Vec *)home, (const Vec *)(actor + 0x38));
        TObjBoss2Tunnel::calc_scaled_value(0x200, lbl_805DA1C4);
        *(s32 *)((s8 *)actor + 0x52C) = *(s32 *)((s8 *)actor + 0x60);
        if (((TObjEneDD_ST *)actor)->enemy_has_live_target() != 0) {
            dir.x = sin_table_lookup(*(s32 *)((s8 *)actor + 0x60));
            dir.z = cos_table_lookup(*(s32 *)((s8 *)actor + 0x60));
            tgt = *(u8 **)((s8 *)actor + 0x390);
            diff.x = *(f32 *)((s8 *)tgt + 0x38) - *(f32 *)((s8 *)actor + 0x38);
            diff.z = *(f32 *)((s8 *)tgt + 0x40) - *(f32 *)((s8 *)actor + 0x40);
            if (is_vec_xz_cross_negative(&dir, &diff) != 0) {
                *(s32 *)((s8 *)actor + 0x528) = 0x5000;
            } else {
                *(s32 *)((s8 *)actor + 0x528) = -0x5000;
            }
        } else if (calc_boss4_scale__10TObjPlayerFi((s32)actor) < TObjEneBm5GibonU__data_805DA158) {
            *(s32 *)((s8 *)actor + 0x528) = 0x5000;
        } else {
            *(s32 *)((s8 *)actor + 0x528) = -0x5000;
        }
        *(s32 *)((s8 *)actor + 0x528) += *(s32 *)((s8 *)actor + 0x52C);
        return;
    case 3:
        if (*(u8 **)((s8 *)actor + 0x390) == NULL || *(s32 *)((s8 *)actor + 0x518) > 0x96) {
            transition_enemy_state__9TObjEneDDFs(actor, 8);
            return;
        }
        if (*(f32 *)((s8 *)actor + 0x3AC) < range) {
            transition_enemy_state__9TObjEneDDFs(actor, 0xB);
        }
    case 5:
        return;
    case 0:
        (*(s32 *)((s8 *)actor + 0x518))++;
        advance_animation_playback(actor);
        if (((TObjEneEpsilon *)actor)->update_death_check() != 0) {
            TObjEneBm5GibonU__sub_800CCE28(actor);
            *(s32 *)((s8 *)actor + 0x528) = approach_angle_limited(*(s32 *)((s8 *)actor + 0x528), *(s32 *)((s8 *)actor + 0x52C), 0x100);
            *(f32 *)((s8 *)actor + 0x394) = TObjEneBm5GibonU__data_805DA1C8 * sin_table_lookup(*(s32 *)((s8 *)actor + 0x528)) + home->x;
            *(f32 *)((s8 *)actor + 0x39C) = TObjEneBm5GibonU__data_805DA1C8 * cos_table_lookup(*(s32 *)((s8 *)actor + 0x528)) + home->z;
            ((TObjEneDD *)actor)->update_velocity();
            ((TObjEneBm5GibonU *)actor)->approach_target(lbl_805DA1CC);
            *(f32 *)((s8 *)actor + 0xC8) = TObjEneBm5GibonU__data_805DA1D0 * *(f32 *)((s8 *)actor + 0x498);
            enemy_turn_and_move_on_ground(actor, 0x500, *(f32 *)((s8 *)actor + 0x498));
            ((TObjEneBm5GibonU *)actor)->face_target();
            ((TObjEneDD *)(actor))->vfunc_89();
            ((TObjPlayer *)actor)->update_enemy_collision_flags();
        }
        break;
    }
}
#pragma pop

struct Ene_800CCC6C;

extern "C" {
#undef TObjEneBm5GibonU__data_805DA194
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA194[1] = { 0.3f };
#undef lbl_805DA198
__declspec(section ".sdata2") const f32 lbl_805DA198[1] = { -3.0f };
#undef lbl_805DA19C
__declspec(section ".sdata2") const f32 lbl_805DA19C[1] = { 3.0f };
#undef lbl_805DA1A0
__declspec(section ".sdata2") const f32 lbl_805DA1A0[1] = { 1.8f };
#undef lbl_805DA1A4
__declspec(section ".sdata2") const f32 lbl_805DA1A4[1] = { 160.0f };
#undef lbl_805DA1A8
__declspec(section ".sdata2") const f32 lbl_805DA1A8[1] = { 60.0f };
#undef lbl_805DA1AC
__declspec(section ".sdata2") const f32 lbl_805DA1AC[1] = { 33.0f };
#undef TObjEneBm5GibonU__data_805DA1B0
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA1B0[1] = { 0.1f };
#undef lbl_805DA1B4
__declspec(section ".sdata2") const f32 lbl_805DA1B4[1] = { 26.0f };
#undef TObjEneBm5GibonU__data_805DA1B8
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA1B8[1] = { 0.8f };
#undef TObjEneBm5GibonU__data_805DA1BC
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA1BC[1] = { 0.9f };
#undef lbl_805DA1C0
__declspec(section ".sdata2") const f32 lbl_805DA1C0[1] = { 16.0f };
#undef lbl_805DA1C4
__declspec(section ".sdata2") const f32 lbl_805DA1C4[1] = { 1.6f };
#undef TObjEneBm5GibonU__data_805DA1C8
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA1C8[1] = { 90.0f };
#undef lbl_805DA1CC
__declspec(section ".sdata2") const f32 lbl_805DA1CC[1] = { 0.2f };
#undef TObjEneBm5GibonU__data_805DA1D0
__declspec(section ".sdata2") const f32 TObjEneBm5GibonU__data_805DA1D0[1] = { 1.05f };
}
#define TObjEneBm5GibonU__data_805DA194 (TObjEneBm5GibonU__data_805DA194[0])
#define lbl_805DA198 (lbl_805DA198[0])
#define lbl_805DA19C (lbl_805DA19C[0])
#define lbl_805DA1A0 (lbl_805DA1A0[0])
#define lbl_805DA1A4 (lbl_805DA1A4[0])
#define lbl_805DA1A8 (lbl_805DA1A8[0])
#define lbl_805DA1AC (lbl_805DA1AC[0])
#define TObjEneBm5GibonU__data_805DA1B0 (TObjEneBm5GibonU__data_805DA1B0[0])
#define lbl_805DA1B4 (lbl_805DA1B4[0])
#define TObjEneBm5GibonU__data_805DA1B8 (TObjEneBm5GibonU__data_805DA1B8[0])
#define TObjEneBm5GibonU__data_805DA1BC (TObjEneBm5GibonU__data_805DA1BC[0])
#define lbl_805DA1C0 (lbl_805DA1C0[0])
#define lbl_805DA1C4 (lbl_805DA1C4[0])
#define TObjEneBm5GibonU__data_805DA1C8 (TObjEneBm5GibonU__data_805DA1C8[0])
#define lbl_805DA1CC (lbl_805DA1CC[0])
#define TObjEneBm5GibonU__data_805DA1D0 (TObjEneBm5GibonU__data_805DA1D0[0])
void TObjEneBm5GibonU__sub_800CEBD8(u8 *actor, s32 arg1) {
    f32 temp_f0;
    s32 temp_r4;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 0xA;
        ((TObjEneDD *)actor)->set_field_378(0xE);
        ((TObjEneDD *)(actor))->vfunc_96();
        temp_r4 = *(s32 *)((s8 *)actor + 0x4AC) & 0xFFFFFFFD;
        *(s32 *)((s8 *)actor + 0x4AC) = temp_r4;
        *(s32 *)((s8 *)actor + 0x518) = 0;
        *(s32 *)((s8 *)actor + 0x51C) = 0;
        *(s32 *)((s8 *)actor + 0x528) = TObjEneBm5GibonU__sub_800D0968(actor, temp_r4);
        *(s32 *)((s8 *)actor + 0x52C) = 0;
        {
            f32 lim = 40.0f;
            if (*(f32 *)((s8 *)actor + 0x3AC) > lim) {
                *(f32 *)((s8 *)actor + 0x3AC) = lim;
            }
        }
        temp_f0 = *(f32 *)((s8 *)actor + 0x3AC) / lbl_805DA1D8;
        *(f32 *)((s8 *)actor + 0x494) = temp_f0;
        *(f32 *)((s8 *)actor + 0x498) = temp_f0;
        *(s32 *)((s8 *)actor + 0x564) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)actor + 0x518) == 1) {
            transition_enemy_state__9TObjEneDDFs(actor, 0xE);
        }
        break;
    case 5:
        break;
    case 0:
        switch (*(s32 *)((s8 *)actor + 0x518)) {
        case 0:
            ((s32)advance_animation_playback(actor));
            if (((TObjEneDD *)actor)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)actor + 0x518) = 1;
            }
            TObjEneBm5GibonU__sub_800CCD8C(actor);
            if (objInBand__FP7GameObjf(actor, TObjEneBm5GibonU__data_805DA160) != 0) {
                play_sound_effect((void *)(copy_target_state__14TObjEnePanarmsFPv(actor, 0x3A828)), actor + 0x38, 0, 0);
            }
            if (objInBand__FP7GameObjf(actor, lbl_805DA1DC) != 0) {
                play_sound_effect((void *)(copy_target_state__14TObjEnePanarmsFPv(actor, 0x3A529)), actor + 0x38, 0, 0);
            }
            if (objInBand__FP7GameObjf(actor, lbl_805DA1DC) != 0) {
                *(s32 *)((s8 *)actor + 0x564) = 0;
                if (enemy_validate_retained_target(actor) != 0) {
                    if (((VObj_18_a3e1a1 *)((u8 *)(*(u8 **)((s8 *)actor + 0x390))))->m18(actor, TObjEneBm5GibonU__data_805DA168) != 0) {
                        ((VObj_18_a3e1a1 *)((u8 *)(*(u8 **)((s8 *)actor + 0x390))))->m20(actor, TObjEneBm5GibonU__data_805DA168);
                        ((VObj_18_a3e1a1 *)((u8 *)(*(u8 **)((s8 *)actor + 0x390))))->m23(actor, TObjEneBm5GibonU__data_805DA170);
                        *(s32 *)((s8 *)actor + 0x564) = 1;
                        if ((TObjEneDD::check_v2_mode() != 0) && (calc_boss4_scale__10TObjPlayerFi((s32)actor) <= TObjEneBm5GibonU__data_805DA1B0)) {
                            if ((s32) *(s32 *)((s8 *)actor + 0x464) != 0) {
                                TObjEneDD__sub_800BA378(actor, (void *) (*(u8 **)((s8 *)actor + 0x390)));
                            } else {
                                TObjEneDD::send_damage_message((s32)actor, (u8 *)(*(u8 **)((s8 *)actor + 0x390)));
                            }
                        }
                    }
                }
            }
            ((TObjEneBm5GibonU *)actor)->approach_target(TObjEneBm5GibonU__data_805DA1B0);
            *(s32 *)((s8 *)actor + 0x60) = approach_angle_limited((s32)((int) (*(s32 *)((s8 *)actor + 0x60))), (s32)((int) (*(s32 *)((s8 *)actor + 0x528))), 0x1000);
            *(s32 *)((s8 *)actor + 0x60) = (s32) (s16) *(s32 *)((s8 *)actor + 0x60);
            turn_toward_angle__16TObjEneBm5GibonUFPvi((Ene_800D0FDC *)(actor), (s32)((int) (*(s32 *)((s8 *)actor + 0x60))));
            if (*(f32 *)((s8 *)actor + 0xC0) <= TObjEneBm5GibonU__data_805DA174) {
                ((TObjEneDD *)actor)->move_with_wall_slide_on_ground((f32) (*(f32 *)((s8 *)actor + 0x3A0)), (f32) (*(f32 *)((s8 *)actor + 0x3A8)), (f32) (*(f32 *)((s8 *)actor + 0x498)));
            } else if ((s32) *(s32 *)((s8 *)actor + 0x564) == 0) {
                *(f32 *)((s8 *)actor + 0x498) = (f32) (*(f32 *)((s8 *)actor + 0x498) * TObjEneBm5GibonU__data_805DA1B8);
                ((TObjEneDD *)actor)->move_with_wall_slide_on_ground((f32) (*(f32 *)((s8 *)actor + 0x3A0)), (f32) (*(f32 *)((s8 *)actor + 0x3A8)), (f32) (*(f32 *)((s8 *)actor + 0x498)));
            }
            break;
        }
        ((TObjEneDD *)(actor))->vfunc_89();
        ((TObjPlayer *)actor)->update_enemy_collision_flags();
        break;
    }
}
extern "C" {
#undef lbl_805DA1D8
__declspec(section ".sdata2") const f32 lbl_805DA1D8[1] = { 14.666667f };
#undef lbl_805DA1DC
__declspec(section ".sdata2") const f32 lbl_805DA1DC[1] = { 22.0f };
#undef lbl_805DA1E0
__declspec(section ".sdata2") const f32 lbl_805DA1E0[1] = { 0.7f };
#undef lbl_805DA1E4
__declspec(section ".sdata2") const f32 lbl_805DA1E4[1] = { 10000.0f };
#undef lbl_805DA1E8
__declspec(section ".sdata2") const f32 lbl_805DA1E8[1] = { 900.0f };
#undef lbl_805DA1EC
__declspec(section ".sdata2") const f32 lbl_805DA1EC[1] = { 80.0f };
#undef lbl_805DA1F0
__declspec(section ".sdata2") const f32 lbl_805DA1F0[1] = { -0.2f };
#undef lbl_805DA1F4
__declspec(section ".sdata2") const f32 lbl_805DA1F4[1] = { 0.12f };
#undef lbl_805DA1F8
__declspec(section ".sdata2") const f32 lbl_805DA1F8[1] = { 1.0001f };
#undef lbl_805DA1FC
__declspec(section ".sdata2") const f32 lbl_805DA1FC[1] = { 13.0f };
#undef lbl_805DA200
__declspec(section ".sdata2") const f32 lbl_805DA200[1] = { 18.0f };
#undef lbl_805DA204
__declspec(section ".sdata2") const f32 lbl_805DA204[1] = { 6.0f };
#undef lbl_805DA208
__declspec(section ".sdata2") const f32 lbl_805DA208[1] = { 4.0f };
#undef lbl_805DA20C
__declspec(section ".sdata2") const f32 lbl_805DA20C[1] = { 768.0f };
#undef lbl_805DA210
__declspec(section ".sdata2") const f32 lbl_805DA210[1] = { 65536.0f };
#undef lbl_805DA214
__declspec(section ".sdata2") const f32 lbl_805DA214[1] = { 120.0f };
#undef lbl_805DA218
__declspec(section ".sdata2") const f32 lbl_805DA218[1] = { 22500.0f };
#undef lbl_805DA21C
__declspec(section ".sdata2") const f32 lbl_805DA21C[1] = { 0.05f };
#undef lbl_805DA220
__declspec(section ".sdata2") const f32 lbl_805DA220[1] = { 512.0f };
#undef lbl_805DA224
__declspec(section ".sdata2") const f32 lbl_805DA224[1] = { 0.020000001f };
#undef lbl_805DA228
__declspec(section ".sdata2") const f32 lbl_805DA228[1] = { 240.0f };
#undef lbl_805DA22C
__declspec(section ".sdata2") const f32 lbl_805DA22C[1] = { 360.0f };
#undef lbl_805DA230
__declspec(section ".sdata2") const f32 lbl_805DA230[1] = { 100.0f };
#undef lbl_805DA234
__declspec(section ".sdata2") const f32 lbl_805DA234[1] = { 3.5714285f };
#undef lbl_805DA238
__declspec(section ".sdata2") const f32 lbl_805DA238[1] = { -7.0f };
#undef lbl_805DA23C
__declspec(section ".sdata2") const f32 lbl_805DA23C[1] = { 30.0f };
#undef lbl_805DA240
__declspec(section ".sdata2") const f32 lbl_805DA240[1] = { 5.0f };
#undef lbl_805DA244
__declspec(section ".sdata2") const f32 lbl_805DA244[1] = { 350.0f };
#undef lbl_805DA248
__declspec(section ".sdata2") const f32 lbl_805DA248[1] = { 250.0f };
#undef lbl_805DA24C
__declspec(section ".sdata2") const f32 lbl_805DA24C[1] = { 32768.0f };
#undef lbl_805DA250
__declspec(section ".sdata2") const f32 lbl_805DA250[1] = { 25.0f };
#undef lbl_805DA254
__declspec(section ".sdata2") const f32 lbl_805DA254[1] = { 0.4f };
}
#define lbl_805DA1D8 (lbl_805DA1D8[0])
#define lbl_805DA1DC (lbl_805DA1DC[0])
#define lbl_805DA1E0 (lbl_805DA1E0[0])
#define lbl_805DA1E4 (lbl_805DA1E4[0])
#define lbl_805DA1E8 (lbl_805DA1E8[0])
#define lbl_805DA1EC (lbl_805DA1EC[0])
#define lbl_805DA1F0 (lbl_805DA1F0[0])
#define lbl_805DA1F4 (lbl_805DA1F4[0])
#define lbl_805DA1F8 (lbl_805DA1F8[0])
#define lbl_805DA1FC (lbl_805DA1FC[0])
#define lbl_805DA200 (lbl_805DA200[0])
#define lbl_805DA204 (lbl_805DA204[0])
#define lbl_805DA208 (lbl_805DA208[0])
#define lbl_805DA20C (lbl_805DA20C[0])
#define lbl_805DA210 (lbl_805DA210[0])
#define lbl_805DA214 (lbl_805DA214[0])
#define lbl_805DA218 (lbl_805DA218[0])
#define lbl_805DA21C (lbl_805DA21C[0])
#define lbl_805DA220 (lbl_805DA220[0])
#define lbl_805DA224 (lbl_805DA224[0])
#define lbl_805DA228 (lbl_805DA228[0])
#define lbl_805DA22C (lbl_805DA22C[0])
#define lbl_805DA230 (lbl_805DA230[0])
#define lbl_805DA234 (lbl_805DA234[0])
#define lbl_805DA238 (lbl_805DA238[0])
#define lbl_805DA23C (lbl_805DA23C[0])
#define lbl_805DA240 (lbl_805DA240[0])
#define lbl_805DA244 (lbl_805DA244[0])
#define lbl_805DA248 (lbl_805DA248[0])
#define lbl_805DA24C (lbl_805DA24C[0])
#define lbl_805DA250 (lbl_805DA250[0])
#define lbl_805DA254 (lbl_805DA254[0])

extern "C" {
struct Obj_800D0BD8;
struct Vec_800D0BD8;
typedef struct Ene_800CEEE8 Ene_800CEEE8;
typedef struct ObjBase_800CEEE8 ObjBase_800CEEE8;
typedef struct Obj_800CEEE8 Obj_800CEEE8;
typedef struct Sub_800CEEE8 Sub_800CEEE8;
typedef struct Vec_800CEEE8 Vec_800CEEE8;
struct Vec_800CEEE8
{
  f32 x;
  f32 y;
  f32 z;
};
struct Sub_800CEEE8
{
  u8 pad[0x18];
  s32 f18;
};
struct ObjBase_800CEEE8
{
  char pad[0x18];
};

struct Obj_800CEEE8 : ObjBase_800CEEE8 {
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
    virtual void m98();
    virtual void m99();
    virtual void m100();
};

struct Ene_800CEEE8 : Obj_800CEEE8 {
    u8 pad1c[0x38 - 0x1C];
    Vec_800CEEE8 pos;
    f32 f44;
    u8 pad48[0x4C - 0x48];
    f32 f4C;
    u8 pad50[0x60 - 0x50];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    Sub_800CEEE8 *fA4;
    u8 pada8[0xB8 - 0xA8];
    s16 fB8;
    u8 padba[0xC8 - 0xBA];
    f32 fC8;
    u8 padcc[0x390 - 0xCC];
    Ene_800CEEE8 *f390;
    u8 pad394[0x494 - 0x394];
    f32 f494;
    f32 f498;
    u8 pad49c[0x4A0 - 0x49C];
    f32 f4A0;
    u8 pad4a4[0x518 - 0x4A4];
    s32 f518;
    s32 f51C;
    s32 f520;
    s32 f524;
    s32 f528;
    u8 pad52c[0x530 - 0x52C];
    f32 f530;
    f32 f534;
    u8 pad538[0x540 - 0x538];
    Vec_800CEEE8 v540;
    Vec_800CEEE8 v54C;
};
f32 rand_range__9TObjEneDDFff(void *, f32, f32);
f32 calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv(Obj_800D0BD8 *arg0, Vec_800D0BD8 *arg1, Vec_800D0BD8 *arg2);
#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU::run_idle_state(s32 arg1) {
  s32 ang;
  Vec_800CEEE8 *a = &((Ene_800CEEE8 *) ((u8 *)this))->v540;
  Vec_800CEEE8 *b = &((Ene_800CEEE8 *) ((u8 *)this))->v54C;
  f32 fx;
  f32 fz;
  switch (arg1)
  {
    case 4:
      ((Ene_800CEEE8 *) ((u8 *)this))->fB8 = 1;
      set_field_378(0xB);
      ((Ene_800CEEE8 *) ((u8 *)this))->m94();
      ((Ene_800CEEE8 *) ((u8 *)this))->f494 = lbl_805DA1E0;
      ((Ene_800CEEE8 *) ((u8 *)this))->f518 = 0;
      ((Ene_800CEEE8 *) ((u8 *)this))->f51C = 0;
      ((Ene_800CEEE8 *) ((u8 *)this))->f520 = 0 & 0xFFFF;
      ((Ene_800CEEE8 *) ((u8 *)this))->f524 = 0;
      ((Ene_800CEEE8 *) ((u8 *)this))->f528 = 0;
      ((Ene_800CEEE8 *) ((u8 *)this))->f530 = 0.0f;
      ((Ene_800CEEE8 *) ((u8 *)this))->f534 = 0.0f;
      (&((Ene_800CEEE8 *) ((u8 *)this))->v540)->x = 0.0f;
      a->y = 0.0f;
      a->z = 0.0f;
      b->x = 0.0f;
      b->y = 0.0f;
      b->z = 0.0f;
      this->set_active();
      break;

    case 3:
      if (((Ene_800CEEE8 *) ((u8 *)this))->f390 == 0)
    {
      transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 8);
      break;
    }
      if (((Ene_800CEEE8 *) ((u8 *)this))->f518 > 0x1C2)
    {
      ((Ene_800CEEE8 *) ((u8 *)this))->f518 = 0;
      if (((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)((Ene_800CEEE8 *) ((u8 *)this)) < TObjEneBm5GibonU__data_805DA158)
      {
        if (((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)((Ene_800CEEE8 *) ((u8 *)this)) < ((Ene_800CEEE8 *) ((u8 *)this))->f4A0)
        {
          transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 0x13);
        }
        else
        {
          transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 0xC);
        }
      }
    }
    else
      if (((Ene_800CEEE8 *) ((u8 *)this))->f518 > 0x2D)
    {
      f32 dz = ((Ene_800CEEE8 *) ((u8 *)this))->pos.z - ((Ene_800CEEE8 *) ((u8 *)this))->f390->pos.z;
      f32 dx = ((Ene_800CEEE8 *) ((u8 *)this))->pos.x - ((Ene_800CEEE8 *) ((u8 *)this))->f390->pos.x;
      f32 d = (dx * dx) + (dz * dz);
      if (d >= lbl_805DA1E4)
      {
        select_attack_by_range();
      }
      else
        if (d < lbl_805DA1E8)
      {
        if (((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)((Ene_800CEEE8 *) ((u8 *)this)) < ((Ene_800CEEE8 *) ((u8 *)this))->f4A0)
        {
          transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 0x13);
        }
        else
        {
          transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 0xC);
        }
      }
      else
      {
        fx = sin_table_lookup(((Ene_800CEEE8 *) ((u8 *)this))->f390->f60);
        fz = cos_table_lookup(((Ene_800CEEE8 *) ((u8 *)this))->f390->f60);
        fz = (fx * b->x) + (fz * b->z);
        if (fz < cos_table_lookup(0x6AAA))
        {
          if (((f32 (*)(void *)) calc_boss4_scale__10TObjPlayerFi)((Ene_800CEEE8 *) ((u8 *)this)) < ((Ene_800CEEE8 *) ((u8 *)this))->f4A0)
          {
            transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 0x13);
          }
          else
          {
            transition_enemy_state__9TObjEneDDFs((Ene_800CEEE8 *) ((u8 *)this), 0xC);
          }
        }
      }
    }
      break;

    case 0:
      advance_animation_playback((Ene_800CEEE8 *) ((u8 *)this));
      if (((TObjEneEpsilon *)((u8 *)this))->update_death_check() != 0)
    {
      if (((Ene_800CEEE8 *) ((u8 *)this))->f520 == 0)
      {
        Vec_800CEEE8 fwd;
        Vec_800CEEE8 to;
        ((Ene_800CEEE8 *) ((u8 *)this))->f520 = 1;
        VecCopy((Vec *)a, (const Vec *)(&((Ene_800CEEE8 *) ((u8 *)this))->f390->pos));
        ((Ene_800CEEE8 *) ((u8 *)this))->f530 = calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv((Obj_800D0BD8 *) ((u8 *)this), (Vec_800D0BD8 *) a, (Vec_800D0BD8 *) b);
        ((Ene_800CEEE8 *) ((u8 *)this))->f534 = rand_range__9TObjEneDDFff((Ene_800CEEE8 *) ((u8 *)this), 50.0f, lbl_805DA1EC);
        fwd.x = sin_table_lookup(((Ene_800CEEE8 *) ((u8 *)this))->f60);
        fwd.y = 0.0f;
        fwd.z = cos_table_lookup(((Ene_800CEEE8 *) ((u8 *)this))->f60);
        to.x = ((Ene_800CEEE8 *) ((u8 *)this))->f390->pos.x - ((Ene_800CEEE8 *) ((u8 *)this))->pos.x;
        to.y = 0.0f;
        to.z = ((Ene_800CEEE8 *) ((u8 *)this))->f390->pos.z - ((Ene_800CEEE8 *) ((u8 *)this))->pos.z;
        if (is_vec_xz_cross_negative(&fwd, &to) != 0)
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f528 = -1;
        }
        else
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f528 = 1;
        }
      }
      ((Ene_800CEEE8 *) ((u8 *)this))->f518++;
      TObjEneBm5GibonU__sub_800CCE28(((u8 *)this));
      if (((Ene_800CEEE8 *) ((u8 *)this))->f524 > 0)
      {
        ((Ene_800CEEE8 *) ((u8 *)this))->f524--;
        if (((Ene_800CEEE8 *) ((u8 *)this))->f528 > 0)
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f530 -= TObjEneBm5GibonU__data_805DA158;
        }
        else
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f530 += TObjEneBm5GibonU__data_805DA158;
        }
      }
      else
      {
        f32 cur = ((Ene_800CEEE8 *) ((u8 *)this))->f530;
        f32 tgt = ((Ene_800CEEE8 *) ((u8 *)this))->f534;
        f32 diff = cur - tgt;
        if (diff > lbl_805DA1CC)
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f530 = cur - lbl_805DA1CC;
        }
        else
          if (diff < lbl_805DA1F0)
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f530 = cur + lbl_805DA1CC;
        }
        else
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f530 = tgt;
        }
      }
      switch (((Ene_800CEEE8 *) ((u8 *)this))->f520)
      {
        case 1:
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f494 = lbl_805DA1E0;
          approach_target(lbl_805DA1F4);
          calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv((Obj_800D0BD8 *) ((u8 *)this), (Vec_800D0BD8 *) &((Ene_800CEEE8 *) ((u8 *)this))->v540, (Vec_800D0BD8 *) b);
          if (((Ene_800CEEE8 *) ((u8 *)this))->f528 >= 0)
          {
            fx = b->z;
            fz = -b->x;
          }
          else
          {
            fz = b->x;
            fx = -b->z;
          }
          if (((TObjEneDD *)((u8 *)this))->has_move_failures(1) != 0)
          {
            ((TObjEneDD_ST *)((u8 *)this))->set_active();
          }
          else
          {
            ((TObjEneDD *)((u8 *)this))->clear_field_388();
          }
          ((TObjEneDD *)((u8 *)this))->move_with_wall_slide_on_ground(fx, fz, ((Ene_800CEEE8 *) ((u8 *)this))->f498);
          if (((TObjEneDD *)((u8 *)this))->has_move_failures(10) != 0)
          {
            ((Ene_800CEEE8 *) ((u8 *)this))->f51C = 0;
            ((Ene_800CEEE8 *) ((u8 *)this))->f520 = 2;
          }
          break;
        }

        case 2:
        {
          ((Ene_800CEEE8 *) ((u8 *)this))->f494 = TObjEneBm5GibonU__data_805DA158;
          approach_target(lbl_805DA1F4);
          ((Ene_800CEEE8 *) ((u8 *)this))->f51C++;
          if (((Ene_800CEEE8 *) ((u8 *)this))->f51C >= 0x28)
          {
            ang = ((Ene_800CEEE8 *) ((u8 *)this))->f60;
          }
          else
          {
            ang = ((Ene_800CEEE8 *) ((u8 *)this))->f60 + (((Ene_800CEEE8 *) ((u8 *)this))->f528 << 11);
          }
          fz = sin_table_lookup(ang);
          fx = cos_table_lookup(ang);
          if (((TObjEneDD *)((u8 *)this))->has_move_failures(2) != 0)
          {
            ((Ene_800CEEE8 *) ((u8 *)this))->f51C = 0;
            ((TObjEneDD_ST *)((u8 *)this))->set_active();
          }
          else
          {
            ((TObjEneDD *)((u8 *)this))->clear_field_388();
          }
          ((TObjEneDD *)((u8 *)this))->move_with_wall_slide_on_ground(fz, fx, ((Ene_800CEEE8 *) ((u8 *)this))->f498);
          if (((Ene_800CEEE8 *) ((u8 *)this))->f51C >= 0x50)
          {
            ((Ene_800CEEE8 *) ((u8 *)this))->f520 = 0;
          }
          break;
        }

      }

      ((Ene_800CEEE8 *) ((u8 *)this))->f60 = approach_angle_limited(((Ene_800CEEE8 *) ((u8 *)this))->f60, (s32) (TObjEneBm5GibonU__data_8043C0F8 * atan2_float(((Ene_800CEEE8 *) ((u8 *)this))->pos.x - ((Ene_800CEEE8 *) ((u8 *)this))->f44, ((Ene_800CEEE8 *) ((u8 *)this))->pos.z - ((Ene_800CEEE8 *) ((u8 *)this))->f4C)), 0x200);
      ((Ene_800CEEE8 *) ((u8 *)this))->f60 = (s16) ((Ene_800CEEE8 *) ((u8 *)this))->f60;
      ((Ene_800CEEE8 *) ((u8 *)this))->fC8 = TObjEneBm5GibonU__data_805DA1D0 * ((Ene_800CEEE8 *) ((u8 *)this))->f498;
      face_target();
      ((Ene_800CEEE8 *) ((u8 *)this))->m87();
      ((TObjPlayer *)((u8 *)this))->update_enemy_collision_flags();
      if (((Ene_800CEEE8 *) ((u8 *)this))->fA4->f18 & 0x380000)
      {
        ((Ene_800CEEE8 *) ((u8 *)this))->f524 = 0x14;
      }
    }
      break;

    case 5:
      ((TObjEneDD *)((u8 *)this))->clear_field_388();
      break;

  }

}
#pragma pop
}
void TObjEneBm5GibonU__sub_800CF4BC(u8 *actor, s32 arg1) {
    s32 *rot = (s32 *)(actor + 0x528);
    Vec_800CF4BC *vel = (Vec_800CF4BC *)(actor + 0x540);
    Vec_800CF4BC *dir = (Vec_800CF4BC *)(actor + 0x54C);
    f32 t;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 3;
        ((TObjEneDD *)actor)->set_field_378(0xA);
        ((TObjEneDD *)actor)->vfunc_96();
        *(f32 *)((s8 *)actor + 0x494) = TObjEneBm5GibonU__data_805DA188;
        *(s32 *)((s8 *)actor + 0x518) = 0;
        *(s32 *)((s8 *)actor + 0x51C) = 0;
        calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(actor, 0x1C71, dir, rot);
        VecCopy((Vec *)vel, (const Vec *)dir);
        *(s32 *)((s8 *)actor + 0x52C) = *rot;
        return;
    case 3:
        if (*(u32 *)((s8 *)actor + 0x390) == 0) {
            transition_enemy_state__9TObjEneDDFs(actor, 8);
            return;
        }
        if (*(s32 *)((s8 *)actor + 0x518) == 1) {
            transition_enemy_state__9TObjEneDDFs(actor, 0x14);
            return;
        }
        if (objInBand__FP7GameObjf(actor, *(f32 *)((s8 *)actor + 0xC4) - lbl_805DA1F8) != 0 &&
            *(f32 *)((s8 *)actor + 0x3AC) < TObjEneBm5GibonU__data_805DA1C8) {
            transition_enemy_state__9TObjEneDDFs(actor, 0xB);
        }
    case 5:
    case 1:
        return;
    case 0:
        advance_animation_playback(actor);
        if (((TObjEneEpsilon *)actor)->update_death_check() == 0) {
            return;
        }
        if (objInBand__FP7GameObjf(actor, lbl_805DA1FC) != 0) {
            spawn_landing_effect__16TObjEneBm5GibonUFPvPv((Ene_800CCC6C *)actor, actor + 0x38);
        }
        TObjEneBm5GibonU__sub_800CCDE4(actor);
        if (objInBand__FP7GameObjf(actor, TObjEneBm5GibonU__data_805DA178) != 0) {
            ((TObjEneDD_ST *)actor)->enemy_copy_target_destination();
            ((TObjEneDD *)actor)->update_velocity();
            if (*(s32 *)((s8 *)actor + 0x51C) == 0) {
                *(s32 *)((s8 *)actor + 0x51C) = 1;
                calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(actor, -0x1C71, dir, rot);
            } else {
                *(s32 *)((s8 *)actor + 0x51C) = 0;
                calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(actor, 0x1C71, dir, rot);
            }
        }
        if (objInBand__FP7GameObjf(actor, *(f32 *)((s8 *)actor + 0xC4) - lbl_805DA1F8) != 0) {
            VecCopy((Vec *)vel, (const Vec *)dir);
            *(s32 *)((s8 *)actor + 0x52C) = *rot;
        }
        *(s32 *)((s8 *)actor + 0x60) = approach_angle_limited(*(s32 *)((s8 *)actor + 0x60), *(s32 *)((s8 *)actor + 0x52C), 0x800);
        *(s32 *)((s8 *)actor + 0x60) = (s16)*(s32 *)((s8 *)actor + 0x60);
        if (objInBand__FP7GameObjf(actor, lbl_805DA200) != 0) {
            *(f32 *)((s8 *)actor + 0x498) = lbl_805DA204;
        }
        t = *(f32 *)((s8 *)actor + 0xC0);
        if (t >= TObjEneBm5GibonU__data_805DA178 && t <= lbl_805DA200) {
            ((TObjEneDD *)actor)->move_with_wall_slide_on_ground(vel->x, vel->z, TObjEneBm5GibonU__data_805DA168);
        } else {
            *(f32 *)((s8 *)actor + 0x498) *= TObjEneBm5GibonU__data_805DA1BC;
            ((TObjEneDD *)actor)->move_with_wall_slide_on_ground(vel->x, vel->z, *(f32 *)((s8 *)actor + 0x498));
        }
        *(f32 *)((s8 *)actor + 0x49C) += *(f32 *)((s8 *)actor + 0x498);
        if (*(f32 *)((s8 *)actor + 0x49C) >= 50.0f) {
            *(f32 *)((s8 *)actor + 0x49C) -= 50.0f;
            if (calc_boss4_scale__10TObjPlayerFi((s32)actor) < *(f32 *)((s8 *)actor + 0x4A4)) {
                *(s32 *)((s8 *)actor + 0x518) = 1;
            }
        }
        ((TObjEneBm5GibonU *)actor)->face_target();
        ((TObjEneDD *)actor)->vfunc_89();
        ((TObjPlayer *)actor)->update_enemy_collision_flags();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CF7CC(u8 *actor, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 2;
        ((TObjEneDD *)actor)->set_field_378(9);
        ((TObjEneDD *)(actor))->vfunc_96();
        *(f32 *)((s8 *)actor + 0x494) = (f32) lbl_805DA1C4;
        *(s32 *)((s8 *)actor + 0x518) = 0;
        return;
    case 3:
        if ((u32) *(u32 *)((s8 *)actor + 0x390) == 0U) {
            transition_enemy_state__9TObjEneDDFs(actor, 8);
        } else if (((TObjEneDD *)actor)->has_move_failures(0xA) != 0) {
            transition_enemy_state__9TObjEneDDFs(actor, 0xA);
        } else if ((s32) *(s32 *)((s8 *)actor + 0x518) == 1) {
            transition_enemy_state__9TObjEneDDFs(actor, 0x14);
        } else if ((objInBand__FP7GameObjf(actor, (f32) (*(f32 *)((s8 *)actor + 0xC4) - lbl_805DA1F8)) != 0) && (*(f32 *)((s8 *)actor + 0x3AC) < TObjEneBm5GibonU__data_805DA1C8)) {
            transition_enemy_state__9TObjEneDDFs(actor, 0xB);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        ((s32 (*)())advance_animation_playback)();
        if (objInBand__FP7GameObjf(actor, lbl_805DA1FC) != 0) {
            spawn_landing_effect__16TObjEneBm5GibonUFPvPv((Ene_800CCC6C *) (actor), actor + 0x38);
        }
        if ((s16) *(s16 *)((s8 *)actor + 0xB8) == 2) {
            TObjEneBm5GibonU__sub_800CCDE4(actor);
        }
        if (((TObjEneEpsilon *)actor)->update_death_check() != 0) {
            ((TObjEneDD_ST *)actor)->enemy_copy_target_destination();
            ((TObjEneDD *)actor)->update_velocity();
            if (objInBand__FP7GameObjf(actor, lbl_805DA200) != 0) {
                *(f32 *)((s8 *)actor + 0x498) = (f32) lbl_805DA208;
            }
            temp_f1 = *(f32 *)((s8 *)actor + 0xC0);
            if ((temp_f1 >= TObjEneBm5GibonU__data_805DA178) && (temp_f1 <= lbl_805DA200)) {
                enemy_turn_and_move_on_ground(actor, (lbl_805DA20C * *(f32 *)((s8 *)actor + 0x498)), TObjEneBm5GibonU__data_805DA168);
            } else {
                *(f32 *)((s8 *)actor + 0x498) = (f32) (*(f32 *)((s8 *)actor + 0x498) * TObjEneBm5GibonU__data_805DA1BC);
                temp_f1_2 = *(f32 *)((s8 *)actor + 0x498);
                enemy_turn_and_move_on_ground(actor, (lbl_805DA20C * temp_f1_2), temp_f1_2);
            }
            *(f32 *)((s8 *)actor + 0x49C) += *(f32 *)((s8 *)actor + 0x498);
            if (*(f32 *)((s8 *)actor + 0x49C) >= 50.0f) {
                *(f32 *)((s8 *)actor + 0x49C) -= 50.0f;
                if (calc_boss4_scale__10TObjPlayerFi((s32) actor) < *(f32 *)((s8 *)actor + 0x4A4)) {
                    *(s32 *)((s8 *)actor + 0x518) = 1;
                }
            }
            ((TObjEneBm5GibonU *)actor)->face_target();
            ((TObjEneDD *)(actor))->vfunc_89();
            ((TObjPlayer *)actor)->update_enemy_collision_flags();
        }
        break;
    }
}

}
s32 actor_rand_int(s32 actor, s32 range);
extern "C" {

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800CFA48(TObjEneBm5GibonU *self, s32 arg1) {
    s32 angle;
    f32 radius;
    TObjPlayer *target;
    f32 dx;
    f32 dz;

    switch (arg1) {
    case 4:
        self->m_b8 = 1;
        self->set_field_378(8);
        self->vfunc_96();
        self->m_51c = 0;
        self->m_518 = 0;
        self->m_520 = actor_rand_int((s32)self, 0x14);
        self->m_564 = 0;
        angle = (s32)(lbl_805DA210 * TObjPlayer::calc_boss4_scale((s32)self));
        radius = lbl_805DA214 * TObjPlayer::calc_boss4_scale((s32)self);
        self->m_394 = radius * sin_table_lookup(angle) + self->m_488.x;
        self->m_39c = radius * cos_table_lookup(angle) + self->m_488.z;
        self->m_494 = lbl_805DA1E0 * TObjPlayer::calc_boss4_scale((s32)self) + TObjEneBm5GibonU__data_805DA194;
        self->m_498 = 0.0f;
        self->m_530 = TObjEneBm5GibonU__data_805DA188 + TObjBoss2Tunnel::calc_scaled_value(0x200, self->m_494);
        self->update_velocity();
        break;
    case 3:
        if (self->m_564 != 0) {
            self->select_attack_by_range();
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(self);
        if (self->play_sound_variant() != 0) {
            f32 dist;
            target = self->m_390;
            dx = target->position[0] - self->position[0];
            dz = target->position[2] - self->position[2];
            dist = dx * dx;
            dist += dz * dz;
            if (dist < lbl_805DA218) {
                self->m_564 = 1;
            }
            self->face_target();
        } else {
            TObjEneBm5GibonU::turn_toward_angle(self, self->rotation_y);
        }
        switch (self->m_518) {
        case 0:
            TObjEneBm5GibonU__sub_800CCE28((u8 *)self);
            self->update_velocity();
            self->approach_target(lbl_805DA21C);
            self->m_51c += 1;
            if (self->m_3ac < self->m_530 || self->m_51c > 100) {
                self->m_518 = 1;
                self->m_494 = 0.0f;
            } else if (self->has_move_failures(0x14) != 0) {
                self->m_51c = 0;
                TObjEneBm5GibonU::pick_wander_destination(self);
                self->m_494 = self->rand_range(TObjEneBm5GibonU__data_805DA194, TObjEneBm5GibonU__data_805DA168);
                self->m_530 = TObjEneBm5GibonU__data_805DA188 + TObjBoss2Tunnel::calc_scaled_value(0x200, self->m_494);
            }
            self->m_c8 = TObjEneBm5GibonU__data_805DA1D0 * self->m_498;
            enemy_turn_and_move_on_ground((u8 *)self, lbl_805DA220 * self->m_498, self->m_498);
            break;
        case 1:
            TObjEneBm5GibonU__sub_800CCE28((u8 *)self);
            self->update_velocity();
            self->approach_target(lbl_805DA224);
            if (self->m_498 <= TObjEneBm5GibonU__data_805DA1B0) {
                self->m_518 = 2;
                self->m_51c = self->rand_range(lbl_805DA228, lbl_805DA22C);
                self->m_b8 = 0;
            }
            self->m_c8 = TObjEneBm5GibonU__data_805DA1D0 * self->m_498;
            enemy_turn_and_move_on_ground((u8 *)self, lbl_805DA220 * self->m_498, self->m_498);
            break;
        case 2:
            self->m_b8 = 0;
            self->m_51c -= 1;
            if (self->m_51c <= 0) {
                TObjEneBm5GibonU::pick_wander_destination(self);
                self->m_494 = self->rand_range(TObjEneBm5GibonU__data_805DA194, TObjEneBm5GibonU__data_805DA168);
                self->m_498 = 0.0f;
                self->m_530 = TObjEneBm5GibonU__data_805DA188 + TObjBoss2Tunnel::calc_scaled_value(0x200, self->m_494);
                self->m_518 = 0;
                self->m_b8 = 1;
            }
            self->vfunc_102();
            break;
        }
        self->vfunc_89();
        ((TObjPlayer *)self)->update_enemy_collision_flags();
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU__sub_800CFE30(u8 * _w0, s32 _w1) {  }

typedef struct VBase_18_9e83f9 VBase_18_9e83f9;
typedef struct VObj_18_9e83f9 VObj_18_9e83f9;

typedef struct VBase_18_7b3d65 VBase_18_7b3d65;
typedef struct VObj_18_7b3d65 VObj_18_7b3d65;

void TObjEneBm5GibonU__sub_800CFE34(u8 *ene_dd_st, s32 arg1) {
    Node_800CFE34 *n;
    void *o;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd_st + 0xB8) = 0xE;
        ((TObjEneDD *)ene_dd_st)->set_field_378(8);
        ((TObjEneDD *)(ene_dd_st))->vfunc_95();
        *(s32 *)((s8 *)ene_dd_st + 0x518) = 0;
        break;
    case 3:
        if (((TObjEneDD *)ene_dd_st)->get_flag_b4() != 0) {
            transition_enemy_state__9TObjEneDDFs(ene_dd_st, 8);
        }
        break;
    case 5:
        break;
    case 0:
        ((void (*)(void *, s32))advance_animation_playback)(ene_dd_st, (*(s32 *)((s8 *)ene_dd_st + 0x518))++);
        if (objInBand__FP7GameObjf(ene_dd_st, TObjEneBm5GibonU__data_805DA184) != 0) {
            play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(ene_dd_st, 0x3A523), ene_dd_st + 0x38, 0, 0);
        }
        if (*(s32 *)((s8 *)ene_dd_st + 0x518) == 0x3C) {
            for (n = (*(List_800CFE34 *)&TObjEneBm5GibonU__enemy_list).head; n != NULL; n = n->next) {
                o = update_photon_mylla__16TObjEneBm5GibonUFPv(n);
                if (*(s32 *)((s8 *)ene_dd_st + 0x46C) == TObjEneBm5GibonU__sub_800D1D70()) {
                    ((TObjEneBm5GibonU *)o)->set_flag();
                }
            }
        }
        if (enemy_validate_retained_target(ene_dd_st) != 0) {
            if (*(s16 *)((s8 *)ene_dd_st + 0xB8) == 0xE) {
                ((TObjEneBm5GibonU *)ene_dd_st)->face_target();
            } else {
                *(s32 *)((s8 *)ene_dd_st + 0x478) = 0;
            }
        } else {
            ((TObjEneBm5GibonU *)ene_dd_st)->play_sound_variant();
        }
        ((TObjEneDD *)(ene_dd_st))->vfunc_102();
        ((TObjEneDD *)(ene_dd_st))->vfunc_88();
        break;
    }
}

void TObjEneBm5GibonU__sub_800CFFBC(u8 *ene_bm5_gibon_u, s32 arg1) {
  switch (arg1)
  {
    case 4:
      ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->m_b8 = 5;
      ((TObjEneDD *)ene_bm5_gibon_u)->set_field_378(8);
      (((TObjEneBm5GibonU *)(ene_bm5_gibon_u))->vfunc_95());
      *((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x518)) = 0;
      return;
    case 3:
      if (((s32) (*((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x518)))) > 0x3C)
    {
      transition_enemy_state__9TObjEneDDFs((void *)((void *) ene_bm5_gibon_u), 8);
    }
    case 5:
      return;
      return;
    case 0:
      *((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x518)) = (s32) ((*((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x518))) + 1);
      advance_animation_playback((void *) ene_bm5_gibon_u);
      if (objInBand__FP7GameObjf((void *) ene_bm5_gibon_u, (f32) TObjEneBm5GibonU__data_805DA184) != 0)
    {
      play_sound_effect((void *)((void *) ((s32)copy_target_state__14TObjEnePanarmsFPv((void *)((void *) ene_bm5_gibon_u), 0x3A523))), ene_bm5_gibon_u + 0x38, 0, 0);
    }
      if (enemy_validate_retained_target((void *) ene_bm5_gibon_u) != 0)
    {
      ((TObjEneDD_ST *)ene_bm5_gibon_u)->enemy_copy_target_destination();
      ((TObjEneDD *)ene_bm5_gibon_u)->update_velocity();
      ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->face_target();
    }
    else
    {
      ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->play_sound_variant();
    }
      (((TObjEneBm5GibonU *)(ene_bm5_gibon_u))->vfunc_102());
      (((TObjEneBm5GibonU *)(ene_bm5_gibon_u))->vfunc_88());
      break;
  }
}

void TObjEneBm5GibonU__sub_800D00F0(u8 *actor, s32 arg1) {
  switch (arg1)
  {
    case 4:
      *((s16 *) (((s8 *) actor) - -0xB8)) = 4;
      ((TObjEneDD *)actor)->set_field_378(5);
      (((TObjEneBm5GibonU *)(actor))->vfunc_95());
      *((s32 *) (((s8 *) actor) + 0x518)) = (s32) (((s32) (lbl_805DA1A8 * calc_boss4_scale__10TObjPlayerFi((s32) actor))) + 0xA);
      return;
      return;
      *((s32 *) (((s8 *) actor) + 0x518)) = (s32) (((s32) (lbl_805DA1A8 * calc_boss4_scale__10TObjPlayerFi((s32) actor))) + 0xA);
    case 3:
      if (((s32) (*((s32 *) (((s8 *) actor) + 0x518)))) <= 0)
    {
      ((TObjEneBm5GibonU *)actor)->set_anim_by_state();
    }
    case 5:
      return;
    case 0:
      *((s32 *) (((s8 *) actor) + 0x518)) = (s32) ((*((s32 *) (((s8 *) actor) + 0x518))) - 1);
      ((TObjEneBm5GibonU *)actor)->play_sound_variant();
      advance_animation_playback((void *) actor);
      (((TObjEneBm5GibonU *)(actor))->vfunc_102());
      (((TObjEneBm5GibonU *)(actor))->vfunc_88());
      break;
  }
}

void TObjEneBm5GibonU__sub_800D01DC(u8 *ene_bm5_gibon_u, s32 arg1) {
  u8 *entity;
  switch (arg1)
  {
    case 4:
      ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->m_b8 = 4;
      ((TObjEneDD *)ene_bm5_gibon_u)->set_field_378(3);
      (((TObjEneBm5GibonU *)(ene_bm5_gibon_u))->vfunc_96());
      enemy_clear_target__12TObjEneDD_STFUs(ene_bm5_gibon_u);
      *((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x478)) = 0;
      *((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x4AC)) = (s32) ((*((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x4AC))) & 0xFFFFFFFE);
      return;
    case 3:
      if ((*((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x4AC))) & 1)
    {
      transition_enemy_state__9TObjEneDDFs(ene_bm5_gibon_u, 5);
      return;
    }
      if (((u32) (((TObjEneBm5GibonU *)ene_bm5_gibon_u)->m_390)) != 0U)
    {
      ((TObjEneDD_ST *)ene_bm5_gibon_u)->enemy_copy_target_destination();
      ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->set_anim_by_state();
      entity = (u8 *) find_entity_by_id(*((u16 *) (((s8 *) ene_bm5_gibon_u) + 0x474)));
      if (entity != 0)
      {
        ((TObjEneBm5GibonU *)entity)->set_flag();
      }
    }
      return;
    case 0:
      ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->play_sound_variant();
      advance_animation_playback(ene_bm5_gibon_u);
      (((TObjEneBm5GibonU *)(ene_bm5_gibon_u))->vfunc_102());
      (((TObjEneBm5GibonU *)(ene_bm5_gibon_u))->vfunc_88());
      return;
      return;
    case 5:
      *((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x4AC)) = (s32) ((*((s32 *) (((s8 *) ene_bm5_gibon_u) + 0x4AC))) & 0xFFFFFFFE);
      break;
  }
}

typedef struct VBase_18_599a64 VBase_18_599a64;
typedef struct VObj_18_599a64 VObj_18_599a64;

void TObjEneBm5GibonU__sub_800D02F8(Gibon_800D02F8 *g, s32 arg1) {
    f32 *home = g->home;
    switch (arg1) {
    case 4:
        g->fB8 = 0;
        ((TObjEneDD *)g)->set_field_378(8);
        ((TObjEneBm5GibonU *)g)->vfunc_95();
        g->f4AC &= ~3;
        enemy_clear_target__12TObjEneDD_STFUs(g);
        g->f478 = 0;
        VecCopy((Vec *)home, (const Vec *)g->pos);
        TObjEneMe3SinowZoa__sub_800D758C(&g->sub);
        ((TBoss3Volopt *)(g->pos))->play_area_sound_effect();
        break;
    case 3:
        if (g->sub.m5() != 0) {
            if (update_target__16TObjEneBm5GibonUFPv(g) != 0) {
                transition_enemy_state__9TObjEneDDFs(g, 8);
            } else {
                transition_enemy_state__9TObjEneDDFs(g, 3);
            }
        }
        break;
    case 5:
        break;
    case 0:
        ((s32)advance_animation_playback(g));
        ((TObjEneBm5GibonU *)g)->vfunc_102();
        ((TObjEneBm5GibonU *)g)->vfunc_88();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800D0420(u8 *arg0, s32 arg1) {
    u8 *home = arg0 + 0x540;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0xF;
        ((TObjEneDD *)arg0)->set_field_378(8);
        ((TObjEneDD_ST *)(arg0))->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x4AC) = (s32) (*(s32 *)((s8 *)arg0 + 0x4AC) & 0xFFFFFFFC);
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        *(s32 *)((s8 *)arg0 + 0x478) = 0;
        VecCopy((Vec *)home, (const Vec *)(arg0 + 0x38));
        *(f32 *)((s8 *)arg0 + 0x38) -= lbl_805DA230 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
        *(f32 *)((s8 *)arg0 + 0x40) -= lbl_805DA230 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
        *(f32 *)((s8 *)arg0 + 0x530) = lbl_805DA234;
        break;
    case 3:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            if (update_target__16TObjEneBm5GibonUFPv(arg0) != 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 8);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, 3);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(arg0);
        if (!(*(s32 *)((s8 *)arg0 + 0xB0) & 4)) {
            TObjEneBm5GibonU__sub_800CCD8C(arg0);
            if (objInBand__FP7GameObjf(arg0, TObjEneBm5GibonU__data_805DA160) != 0) {
                play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3A828), arg0 + 0x38, 0, 0);
            }
            if (objInBand__FP7GameObjf(arg0, lbl_805DA1DC) != 0) {
                play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x3A529), arg0 + 0x38, 0, 0);
            }
            if (*(f32 *)((s8 *)arg0 + 0xC0) > TObjEneBm5GibonU__data_805DA174) {
                *(f32 *)((s8 *)arg0 + 0x530) *= TObjEneBm5GibonU__data_805DA1B8;
            }
            *(f32 *)((s8 *)arg0 + 0x38) += *(f32 *)((s8 *)arg0 + 0x530) * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
            *(f32 *)((s8 *)arg0 + 0x40) += *(f32 *)((s8 *)arg0 + 0x530) * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
        }
        ((TObjEneDD_ST *)(arg0))->vfunc_102();
        ((TObjEneDD_ST *)(arg0))->vfunc_88();
        break;
    }
}
#pragma pop

void TObjEneBm5GibonU::handle_state(s32 arg1) {
  int new_var;
  switch (arg1)
  {
    case 4:
      *((s32 *) (((s8 *) ((u8 *)this)) + 0x51C)) = 0;
      set_field_378(0);
      (this->vfunc_95());
      *((s32 *) (((s8 *) ((u8 *)this)) + 0x4AC)) = (s32) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x4AC))) | 2);
      return;
    case 3:
      u32 temp_r3;
      if (((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x51C)))) > 0)
    {
      if (((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x470)))) < 1)
      {
        transition_enemy_state__9TObjEneDDFs((void *)this, 1);
        return;
      }
      transition_enemy_state__9TObjEneDDFs((void *)this, 2);
    }
    case 5:
      return;
      return;
    case 0:
      new_var = 0x51C;
      temp_r3 = ((u32)find_enemy_by_id__16TObjEneBm5GibonUFi((s32)((int) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x46C))))));
      if (temp_r3)
    {
      *((s16 *) (((s8 *) ((u8 *)this)) + 0x474)) = get_entity_id((int) temp_r3);
    }
      if ((((s32) (*((s32 *) (((s8 *) ((u8 *)this)) + 0x464)))) != 0) || (temp_r3 == 0U))
    {
      VecCopy((Vec *)(((u8 *)this) + 0x488), (const Vec *)(((u8 *)this) + 0x47C));
    }
    else
    {
      VecCopy((Vec *)(((u8 *)this) + 0x488), (const Vec *)((void *) TObjEneBm5GibonU__sub_800D1D78((void *)temp_r3)));
    }
      *((s32 *) (((s8 *) ((u8 *)this)) + new_var)) = (s32) ((*((s32 *) (((s8 *) ((u8 *)this)) + 0x51C))) + 1);
      break;
  }
}

void TObjEneBm5GibonU__sub_800D0738(u8 *actor, u32 arg1, s32 msg) {
    switch (arg1) {
    case 0:
        ((TObjEneBm5GibonU *)actor)->handle_state(msg);
        break;
    case 1:
        TObjEneBm5GibonU__sub_800D0420(actor, msg);
        break;
    case 2:
        TObjEneBm5GibonU__sub_800D02F8((Gibon_800D02F8 *)(actor), msg);
        break;
    case 3:
        TObjEneBm5GibonU__sub_800D01DC(actor, msg);
        break;
    case 4:
        TObjEneBm5GibonU__sub_800CFE30(actor, msg);
        break;
    case 5:
        TObjEneBm5GibonU__sub_800D00F0(actor, msg);
        break;
    case 6:
        TObjEneBm5GibonU__sub_800CFFBC(actor, msg);
        break;
    case 7:
        TObjEneBm5GibonU__sub_800CFE34(actor, msg);
        break;
    case 8:
        TObjEneBm5GibonU__sub_800CFA48((TObjEneBm5GibonU *)actor, msg);
        break;
    case 9:
        TObjEneBm5GibonU__sub_800CF7CC(actor, msg);
        break;
    case 10:
        TObjEneBm5GibonU__sub_800CF4BC(actor, msg);
        break;
    case 11:
        ((TObjEneBm5GibonU *)actor)->run_idle_state(msg);
        break;
    case 12:
        TObjEneBm5GibonU__sub_800CEBD8(actor, msg);
        break;
    case 13:
        TObjEneBm5GibonU__sub_800CE978(actor, msg);
        break;
    case 14:
        TObjEneBm5GibonU__sub_800CE694(actor, msg);
        break;
    case 15:
        action__16TObjEneBm5GibonUFPvi((TObjEneBm5GibonU *)actor, msg);
        break;
    case 16:
        TObjEneBm5GibonU__sub_800CE370(actor, msg);
        break;
    case 17:
        TObjEneBm5GibonU__sub_800CE060(actor, msg);
        break;
    case 18:
        ((TObjEneBm5GibonU *)actor)->handle_message(msg);
        break;
    case 19:
        TObjEneBm5GibonU__sub_800CDB98((Obj_800CDB98 *)(actor), msg);
        break;
    case 20:
        ((TObjEneBm5GibonU *)actor)->state_cast_technique(msg);
        break;
    }
}

void TObjEneBm5GibonU::damage_linked_entity() {
    u8 *r = (u8 *)find_entity_by_id(((Obj_800D086C *)this)->f474);
    if (r != 0) {
        Dmg_800D086C d;
        d.kind = 9;
        d.amount = TObjEneBm5GibonU__data_805DA16C;
        ((Obj_800D086C *)this)->m21(r, d, 0, -1, -1);
    }
}

void TObjEneBm5GibonU::damage_linked_entity_type10() {
    u8 *r = (u8 *)find_entity_by_id(((Obj_800D08E4 *)this)->f474);
    if (r != 0) {
        Dmg_800D08E4 d;
        d.kind = 10;
        d.amount = TObjEneBm5GibonU__data_805DA16C;
        ((Obj_800D08E4 *)this)->m21(r, d, 0, -1, -1);
    }
}

void TObjEneBm5GibonU__sub_800D095C(void *arg0, s32 arg1, s16 arg2) {
    *(s32 *)((s8 *)arg0 + 0x510) = arg1;
    *(s16 *)((s8 *)arg0 + 0x514) = arg2;
}
#pragma push
#pragma fp_contract on
s32 TObjEneBm5GibonU__sub_800D0968(u8 *arg0, int _w1) {
    f32 temp_f4;
    f32 temp_f5;
    f32 var_f0;
    if (transform_relative_position__9TObjEneDDFPv(arg0, (int) (((TObjEneBm5GibonU *)arg0)->m_390)) != 0) {
        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        ((TObjEneDD *)arg0)->update_velocity();
        if (is_active__16TObjEneBm5GibonUFPv(arg0) != 0) {
            var_f0 = TObjEneBm5GibonU__data_805DA170;
        } else {
            var_f0 = lbl_805DA238;
        }
        temp_f5 = *(f32 *)((s8 *)arg0 + 0x3A8);
        temp_f4 = *(f32 *)((s8 *)arg0 + 0x3A0);
        *(f32 *)((s8 *)arg0 + 0x394) = (f32) (*(f32 *)((s8 *)arg0 + 0x394) + ((TObjEneBm5GibonU__data_805DA188 * temp_f4) + (temp_f5 * var_f0)));
        ((TObjEneBm5GibonU *)arg0)->m_39c = (f32) (((TObjEneBm5GibonU *)arg0)->m_39c + ((TObjEneBm5GibonU__data_805DA188 * temp_f5) - (temp_f4 * var_f0)));
        ((TObjEneDD *)arg0)->update_velocity();
        return (s32) (TObjEneBm5GibonU__data_8043C0F8 * atan2_float((f64) *(f32 *)((s8 *)arg0 + 0x3A0), (f64) *(f32 *)((s8 *)arg0 + 0x3A8)));
    }
    *(f32 *)((s8 *)arg0 + 0x3A0) = sin_table_lookup((int) (((TObjEneBm5GibonU *)arg0)->rotation_y));
    *(f32 *)((s8 *)arg0 + 0x3A4) = (f32) 0.0f;
    *(f32 *)((s8 *)arg0 + 0x3A8) = cos_table_lookup((int) (((TObjEneBm5GibonU *)arg0)->rotation_y));
    VecCopy((Vec *)(arg0 + 0x394), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x394) = (f32) ((lbl_805DA23C * *(f32 *)((s8 *)arg0 + 0x3A0)) + *(f32 *)((s8 *)arg0 + 0x394));
    ((TObjEneBm5GibonU *)arg0)->m_39c = (f32) ((lbl_805DA23C * *(f32 *)((s8 *)arg0 + 0x3A8)) + ((TObjEneBm5GibonU *)arg0)->m_39c);
    *(f32 *)((s8 *)arg0 + 0x3AC) = (f32) lbl_805DA23C;
    return ((TObjEneBm5GibonU *)arg0)->rotation_y;
}
}
#pragma pop

#undef find_enemy_by_id__16TObjEneBm5GibonUFi
#undef is_active__16TObjEneBm5GibonUFPv
#undef gibon_collision_body_templates
#undef update_target__16TObjEneBm5GibonUFPv
#undef update_photon_mylla__16TObjEneBm5GibonUFPv
#undef TObjEneBm5GibonU__sub_800D1D70
#undef TObjEneBm5GibonU__sub_800D0AE8
#undef turn_toward_angle__16TObjEneBm5GibonUFPvi
#undef calc_anim_speed__16TObjEneBm5GibonUFPvf
#undef TObjEneBm5GibonU__node_list
#undef calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv
#undef update_center_position__16TObjEneBm5GibonUFv
#pragma pop
#pragma push
#define spawn_landing_effect__16TObjEneBm5GibonUFPvPv ((int (*)(void *, void *))spawn_landing_effect__16TObjEneBm5GibonUFPvPv)

struct Vec_800D0AE8 { f32 x, y, z; };

struct Obj_800D0AE8 { u8 pad[0x38]; Vec_800D0AE8 pos; };

struct Seq_800D0A94 { u8 pad0[4]; u32 count; };

struct Ent_800D0A94 { s32 w0; Seq_800D0A94 *seq; };

struct Cur_800D0A94 { u8 pad0[0x74]; s32 idx; };

struct Obj_800D0A94 { u8 pad0[0xD8]; Cur_800D0A94 *cur; Ent_800D0A94 *ents; };

struct Vec_800D0BD8 { f32 x, y, z; };

struct Obj_800D0BD8 { u8 pad[0x38]; Vec_800D0BD8 pos; };

extern "C" {
s32 select_and_apply_target__12TObjEneDD_STFf(f32);

int is_active__16TObjEneBm5GibonUFPv(void* p) { return *(u16*)((char*)p + 0x1c) & 0x1; }

f32 calc_anim_speed__16TObjEneBm5GibonUFPvf(Obj_800D0A94 *arg0, f32 farg0) {
    return TObjEneBm5GibonU__data_805DA174 / ((arg0->ents[arg0->cur->idx].seq->count - 1) / farg0);
}

#pragma push
#pragma fp_contract on
void TObjEneBm5GibonU__sub_800D0AE8(Obj_800D0AE8 *self, Vec_800D0AE8 *dir) {
    Vec_800D0AE8 v;
    VecCopy((Vec *)&v, (const Vec *)&self->pos);
    v.x = lbl_805DA240 * dir->x + v.x;
    v.z = lbl_805DA240 * dir->z + v.z;
    spawn_landing_effect__16TObjEneBm5GibonUFPvPv(self, &v);
}
#pragma pop

s32 TObjEneBm5GibonU::play_sound_variant() {
    if ((s32) *(s32 *)((s8 *)this + 0x464) != 0) {
        return this->update_linked_position(lbl_805DA244);
    }
    return this->update_linked_position(lbl_805DA248);
}

void update_target__16TObjEneBm5GibonUFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x464) != 0) {
        select_and_apply_target__12TObjEneDD_STFf(lbl_805DA244);
        return;
    }
    select_and_apply_target__12TObjEneDD_STFf(lbl_805DA248);
}

void TObjEneBm5GibonU::set_flag() { *(u32*)((char*)this + 0x4ac) |= 0x1; }

#pragma push
#pragma fp_contract on
f32 calc_xz_direction_to__16TObjEneBm5GibonUFPvPvPv(Obj_800D0BD8 *arg0, Vec_800D0BD8 *arg1, Vec_800D0BD8 *arg2) {
    f32 dx;
    f32 dz;
    dx = arg0->pos.x - arg1->x;
    dz = arg0->pos.z - arg1->z;
    f32 d = dx * dx + dz * dz;
    f32 inv = TObjEneBm5GibonU__data_805DA168 / newton_sqrtf(d);
    arg2->x = dx * inv;
    arg2->y = 0.0f;
    arg2->z = dz * inv;
    return d * inv;
}
#pragma pop

void TObjEneBm5GibonU::set_anim_by_state() {
    if ((s32) *(s32 *)((s8 *)this + 0x464) != 0) {
        transition_enemy_state__9TObjEneDDFs(this, 7);
        return;
    }
    transition_enemy_state__9TObjEneDDFs(this, 6);
}

#undef spawn_landing_effect__16TObjEneBm5GibonUFPvPv
#pragma pop
#pragma push
#define calc_boss4_scale__10TObjPlayerFi ((f32 (*)())calc_boss4_scale__10TObjPlayerFi)

void TObjEneBm5GibonU::select_attack_by_range() {
    *(f32 *)((s8 *)this + 0x49C) = 0.0f;
    if (calc_boss4_scale__10TObjPlayerFi() < TObjEneBm5GibonU__data_805DA158) {
        transition_enemy_state__9TObjEneDDFs(this, 9);
        return;
    }
    transition_enemy_state__9TObjEneDDFs(this, 0xA);
}

#undef calc_boss4_scale__10TObjPlayerFi
#pragma pop
#pragma push
#define atan2_float ((f64 (*)(f32, f32))atan2_float)
#define sin_table_lookup ((f32 (*)(s32))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(s32))cos_table_lookup)

#pragma fp_contract on

void calc_rotated_vector__16TObjEneBm5GibonUFPviPvPv(void *arg0, s32 arg1, void *arg2, s32 *arg3) {
    f32 temp_f1;
    f32 temp_f31;

    temp_f31 = sin_table_lookup(arg1);
    temp_f1 = cos_table_lookup(arg1);
    *(f32 *)((s8 *)arg2 + 8) = (f32) ((temp_f1 * *(f32 *)((s8 *)arg0 + 0x3A8)) - (temp_f31 * *(f32 *)((s8 *)arg0 + 0x3A0)));
    *(f32 *)((s8 *)arg2 + 0) = (f32) ((temp_f31 * *(f32 *)((s8 *)arg0 + 0x3A8)) + (temp_f1 * *(f32 *)((s8 *)arg0 + 0x3A0)));
    *arg3 = (s32) (TObjEneBm5GibonU__data_8043C0F8 * atan2_float(*(f32 *)((s8 *)arg2 + 0), *(f32 *)((s8 *)arg2 + 8)));
}

}

#undef atan2_float
#undef sin_table_lookup
#undef cos_table_lookup
#pragma pop
#pragma push
#define calc_boss4_scale__10TObjPlayerFi ((f32 (*)(void *))calc_boss4_scale__10TObjPlayerFi)
#define rotate_xz_pair_by_angle ((void (*)(f32 *, f32 *, s32))rotate_xz_pair_by_angle)
#define clamp_velocity__15TObjBoss2TunnelFv ((f32 (*)(Vec_800D0E14 *))clamp_velocity__15TObjBoss2TunnelFv)

typedef struct Vec_800D0E14 {
    f32 x, y, z;
} Vec_800D0E14;

typedef struct Hit_800D0E14 {
    u32 flags;
    Vec_800D0E14 *pos;
} Hit_800D0E14;

typedef struct Ene_800D0E14 {
    u8 pad0[0x38];
    Vec_800D0E14 pos;
    u8 pad44[0x2FC - 0x44];
    u8 f2FC[0x394 - 0x2FC];
    Vec_800D0E14 dest;
    u8 pad3A0[0x488 - 0x3A0];
    Vec_800D0E14 home;
} Ene_800D0E14;

typedef struct Ene_800D0FDC {
    u8 pad0[0x60];
    s32 angle;
    u8 pad64[0x478 - 0x64];
    s32 turn;
} Ene_800D0FDC;

extern "C" {
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
Hit_800D0E14 *csnVector(void *, void *, s32);
void pick_wander_destination__16TObjEneBm5GibonUFPv(Ene_800D0E14 *arg0);
s32 angle_diff_s16(s32, s32);
void TObjEneBm5GibonU::approach_target(f32 farg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)this + 0x498);
    temp_f0 = *(f32 *)((s8 *)this + 0x494);
    if (temp_f2 != temp_f0) {
        if (temp_f2 > temp_f0) {
            *(f32 *)((s8 *)this + 0x498) = (f32) (temp_f2 - farg0);
            if (*(f32 *)((s8 *)this + 0x498) < *(f32 *)((s8 *)this + 0x494)) {
                *(f32 *)((s8 *)this + 0x498) = *(f32 *)((s8 *)this + 0x494);
            }
        } else {
            *(f32 *)((s8 *)this + 0x498) = (f32) (temp_f2 + farg0);
            if (*(f32 *)((s8 *)this + 0x498) > *(f32 *)((s8 *)this + 0x494)) {
                *(f32 *)((s8 *)this + 0x498) = *(f32 *)((s8 *)this + 0x494);
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void pick_wander_destination__16TObjEneBm5GibonUFPv(Ene_800D0E14 *actor) {
    Vec_800D0E14 v;
    f32 d;
    Hit_800D0E14 *hit;
    v.x = actor->pos.x - actor->home.x;
    v.y = 0.0f;
    v.z = actor->pos.z - actor->home.z;
    clamp_velocity__15TObjBoss2TunnelFv(&v);
    rotate_xz_pair_by_angle(&v.x, &v.z, (s32)(lbl_805DA24C * calc_boss4_scale__10TObjPlayerFi(actor)) + 0x4000);
    d = lbl_805DA214 * rand_range__9TObjEneDDFff(actor, TObjEneBm5GibonU__data_805DA194, TObjEneBm5GibonU__data_805DA168);
    actor->dest.x = v.x * d + actor->home.x;
    actor->dest.z = v.z * d + actor->home.z;
    hit = csnVector(actor->f2FC, &actor->dest, 0x88E0);
    if (hit != NULL) {
        v.x = hit->pos->x - actor->pos.x;
        v.z = hit->pos->z - actor->pos.z;
        d = clamp_velocity__15TObjBoss2TunnelFv(&v) - lbl_805DA250;
        actor->dest.x = v.x * d + actor->pos.x;
        actor->dest.z = v.z * d + actor->pos.z;
    }
}
#pragma pop

s32 TObjEneBm5GibonU::face_target() {
    Obj_800D0F44 *arg0 = (Obj_800D0F44 *)this;
    Vec_800D0F44 off;
    Vec_800D0F44 q;
    off.x = sin_table_lookup(this->rotation_y) * 0.0f;
    q.x = arg0->pos.x + off.x;
    off.z = cos_table_lookup(this->rotation_y) * 0.0f;
    q.z = arg0->pos.z + off.z;
    q.x = arg0->target->pos.x - q.x;
    q.z = arg0->target->pos.z - q.z;
    turn_toward_angle__16TObjEneBm5GibonUFPvi((Ene_800D0FDC *)((Ene_800D0FDC *)arg0), (s32)((s32)(((const f64 *)&TObjEneBm5GibonU__data_8043C0F8)[0] * atan2_float(q.x, q.z))));
}

void turn_toward_angle__16TObjEneBm5GibonUFPvi(Ene_800D0FDC *arg0, s32 arg1) {
    s32 d;
    d = angle_diff_s16(arg0->angle, arg1);
    if (d > 0x3000) {
        d = 0x3000;
    } else if (d < -0x3000) {
        d = -0x3000;
    }
    if (arg0->turn * d >= 0) {
        arg0->turn = approach_angle_limited(arg0->turn, d, 0x400);
    } else if (arg0->turn * angle_diff_s16(arg0->turn, d) >= 0) {
        if (arg0->turn >= 0) {
            arg0->turn -= 0x400;
        } else {
            arg0->turn += 0x400;
        }
    } else {
        arg0->turn = approach_angle_limited(arg0->turn, d, 0x400);
    }
    arg0->turn = (s16)arg0->turn;
}

void TObjEneBm5GibonU::sub_800D10A0() {
    *(s32 *)((s8 *)((u8 *)this) + 0x46C) = (s32) get_random_float__21TObjEneMe3ShinowaRealFv((f32) (*(f32 *)((s8 *)((u8 *)this) + 0x354)));
    if (*(f32 *)((s8 *)((u8 *)this) + 0x358) >= TObjEneBm5GibonU__data_805DA168) {
        *(s32 *)((s8 *)((u8 *)this) + 0x470) = 0;
    } else {
        *(s32 *)((s8 *)((u8 *)this) + 0x470) = 1;
    }
    if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x368) >= 1) {
        *(s32 *)((s8 *)((u8 *)this) + 0x464) = 1;
        *(s32 *)((s8 *)((u8 *)this) + 0x468) = 1;
        *(s32 *)((s8 *)((u8 *)this) + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneBm5GibonU__model_archive + 0x42C)) + 0x18);
        *(s32 *)((s8 *)((u8 *)this) + 0x24) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneBm5GibonU__model_archive + 0x42C)) + 0x1C);
    } else {
        *(s32 *)((s8 *)((u8 *)this) + 0x464) = 0;
        *(s32 *)((s8 *)((u8 *)this) + 0x468) = 0;
        *(s32 *)((s8 *)((u8 *)this) + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneBm5GibonU__model_archive + 0x42C)) + 8);
        *(s32 *)((s8 *)((u8 *)this) + 0x24) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneBm5GibonU__model_archive + 0x42C)) + 0xC);
    }
    *(f32 *)((s8 *)((u8 *)this) + 0x4A0) = (f32) (lbl_805DA254 + *(f32 *)((s8 *)((u8 *)this) + 0x35C));
    *(f32 *)((s8 *)((u8 *)this) + 0x4A4) = (f32) (TObjEneBm5GibonU__data_805DA194 + *(f32 *)((s8 *)((u8 *)this) + 0x360));
    *(f32 *)((s8 *)((u8 *)this) + 0x4A8) = (f32) (TObjEneBm5GibonU__data_805DA194 + *(f32 *)((s8 *)((u8 *)this) + 0x364));
}

}

#undef calc_boss4_scale__10TObjPlayerFi
#undef rotate_xz_pair_by_angle
#undef clamp_velocity__15TObjBoss2TunnelFv
#pragma pop
#pragma push
#define transition_enemy_state__9TObjEneDDFs ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)
#define lbl_80493F04 ((u8 *)&lbl_80493F04)
#define update_angle__10TObjPlayerFlPv ((void (*)(void *, s32, void *))update_angle__10TObjPlayerFlPv)
#define update_collisions__10TObjPlayerFv ((void (*)(void *))update_collisions__10TObjPlayerFv)
#define __nw__7TObjectFUl ((void * (*)(int))__nw__7TObjectFUl)
#define update_shock_clock__13TUnk_804806E8Fv ((s32 (*)())update_shock_clock__13TUnk_804806E8Fv)
#define update_movement_status__13TUnk_804806E8Fv ((s32 (*)())update_movement_status__13TUnk_804806E8Fv)
#define get_entity_id ((s16 (*)(s32))get_entity_id)

#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"

struct RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800D187C_TObjEneBm5GibonU__data_80500EC4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800D18AC_TObjEneBm5GibonU__data_80500EB0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800D18DC_TObjEneBm5GibonU__data_80500EB0 {
    s32 value;
    u8 remaining[0x10];
};

struct O_800D1CF8 { s32 f0; s32 f4; u16 f8; };

struct Node_800D17E8 { s32 f0; Node_800D17E8 *next; };

struct Ene_800D17E8 { u8 pad[0x46c]; s32 id; };

struct List_800D17E8 { Node_800D17E8 *head; u8 remaining[0x8]; };

struct G_800D1D14 { u8 pad[0x2c]; u8 chain1[0xc]; u8 obj1[8]; u8 chain2[0xc]; u8 obj2[8]; };

struct Base_800D13B8 {
    char pad[0x18];
};

struct Child_800D13B8 : Base_800D13B8 {
    virtual void v0(s32);
};

typedef struct Gibon_800D13B8 {
    u8 pad0[0x18];
    void *vtbl;
    u8 pad1C[0x3C0 - 0x1C];
    u8 f3C0[0xC];
    u8 f3CC[0xC];
    u8 f3D8[0x1C];
    u8 f3F4[4][0x1C];
    s32 f464;
    u8 pad468[0x50C - 0x468];
    Child_800D13B8 *child;
} Gibon_800D13B8;

typedef struct Vec_800D1E4C {
    f32 x, y, z;
} Vec_800D1E4C;

typedef struct Col_800D1E4C {
    u8 pad0[0x18];
    u32 flags;
} Col_800D1E4C;

typedef struct Param_800D1E4C {
    u8 pad0[4];
    f32 speed;
    s32 turn;
} Param_800D1E4C;

typedef struct Ene_800D1E4C {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0x38 - 0x34];
    Vec_800D1E4C pos;
    u8 pad44[0x50 - 0x44];
    Vec_800D1E4C target;
    u8 pad5C[0xA4 - 0x5C];
    Col_800D1E4C *col;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x290 - 0xBA];
    Vec_800D1E4C v290;
    Vec_800D1E4C v29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800D1E4C v2FC;
    u8 v308[0x350 - 0x308];
    Param_800D1E4C *param;
    u8 pad354[0x37C - 0x354];
    s32 state;
} Ene_800D1E4C;

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

struct Model_800D14AC { u8 b[0x2C]; };

struct Sub_800D14AC { u8 b[0x1C]; };

struct Self_800D14AC { u8 pad[0x3F4]; Sub_800D14AC subs[4]; };

extern "C" {
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void TObjEneBm5GibonU__sub_800D1CF8(O_800D1CF8 *self);
s32 __dt__16TObjEneBm5GibonUFis(s32 arg0, s16 arg1);
void __register_global_object(void *obj, void *dtor, void *chain);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, u32, u32);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
void init_object__12TObjEneDD_STFv(void *, s32, s32);
void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);
void invoke_initialization_hook__9TObjEneDDFv(void *, s32);
void init_collision_body_parts(void *, void *, s32);
void *__ct__13TUnk_804AF8A0FP7TObject(void *, s32);
void __construct_array(void *, void *, void *, int, int);
void init_and_activate__10TObjPlayerFv();
extern s32 lbl_805D2A70;
u8 *TObjEneBm5GibonU__ct(u8 *arg0, s32 arg1, s32 arg2);
void vfunc_61__16TObjEneBm5GibonUFv(void);
void vfunc_28__16TObjEneBm5GibonUFv(void);
void TLobby__sub_8001FE7C(void*, int);
void __dl__FPv(void);

void TObjEneBm5GibonU::vfunc_88() {
    *(f32 *)((s8 *)this->m_a4 + 4) = (f32) TObjEneBm5GibonU__data_805DA178;
}

void TObjEneBm5GibonU::update_center_position() {
    u8 *arg0 = (u8 *)this;
    this->m_2fc = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->m_300 = (f32) (TObjEneBm5GibonU__data_805DA178 + *(f32 *)((s8 *)arg0 + 0x3C));
    this->m_304 = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

void TObjEneBm5GibonU::vfunc_61() {  }
void TObjEneBm5GibonU::vfunc_62() { if (this->mode != 16) { transition_enemy_state__9TObjEneDDFs(this, (void*)16); } }
void TObjEneBm5GibonU::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 0x11) && (temp_r0 != 0x12)) {
        transition_enemy_state__9TObjEneDDFs(this, (void*)(0x11));
    }
}
void TObjEneBm5GibonU::vfunc_28() {  }

void TObjEneBm5GibonU::run_task() {
    s16 temp_r0;
    s16 temp_r3_2;
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_debug();
        return;
    }
    if (((u32)find_entity_by_id((*(u16 *)((s8 *)((u8 *)this) + 0x474)))) != 0U) {
        all_parents_unqueued_for_destruction__7TObjectFv();
    }
    if (this->vfunc_83() != 4) {
        temp_r3 = this->m_510;
        if (temp_r3 != 0) {
            this->m_510 = (temp_r3 - 1);
            if ((s32) this->m_510 == 0) {
                temp_r0 = this->mode;
                if ((temp_r0 != 0x11) && (temp_r0 != 0x12)) {
                    transition_enemy_state__9TObjEneDDFs(this, (void*)(0xF));
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
            transition_enemy_state__9TObjEneDDFs(this, (void*)(8));
            this->vfunc_85();
        }
    }
    update_center_position__16TObjEneBm5GibonUFv(((u8 *)this));
    ((TBoss8Dragon *)((u8 *)this))->set_player_state_default();
    this->vfunc_100();
}

typedef char RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4_size[sizeof(RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4) == 0xC ? 1 : -1];

Gibon_800D13B8 *TObjEneBm5GibonU__sub_800D13B8(Gibon_800D13B8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        arg0->vtbl = lbl_80493F04;
        if (arg0->child != NULL) {
            free_collision_body_parts(arg0->child);
            if (arg0->child != NULL) {
                arg0->child->v0(1);
            }
            arg0->child = NULL;
        }
        ((TObjEneBm5GibonU *)arg0)->forward_hit_to_node_list();
        if (arg0->f464 != 0) {
            ((TObjEneBm5GibonU *)arg0)->forward_hit_to_enemy_list();
        }
        free_collision_body_parts(arg0);
        __destroy_arr(arg0->f3F4, (void *)__dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__13TUnk_80494938Fv(arg0->f3D8, -1);
        TObjEneBm5GibonU::destroy((s32)arg0->f3CC, -1);
        TObjEneBm5GibonU::destroy((s32)arg0->f3C0, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#undef TObjEneBm5GibonU__movement_parameters
#define TObjEneBm5GibonU__movement_parameters ((u8 *)TObjEneBm5GibonU__movement_parameters)
#undef gibon_collision_body_templates
#define gibon_collision_body_templates ((Model_800D14AC *)gibon_collision_body_templates)
#undef gibon_u_action_table
#define gibon_u_action_table ((u8 *)gibon_u_action_table)
#undef lbl_80493F04
#define lbl_80493F04 ((u8 *)lbl_80493F04)
u8 *TObjEneBm5GibonU__ct(u8 *ene_bm5_gibon_u, s32 arg1, s32 arg2) {
    void *p;
    s32 i;
    s32 b;
    init_object__12TObjEneDD_STFv(ene_bm5_gibon_u, arg1, arg2);
    *(u8 **)((s8 *)ene_bm5_gibon_u + 0x18) = lbl_80493F04;
    TObjEneBm5GibonU__sub_800D1CF8((O_800D1CF8 *)(ene_bm5_gibon_u + 0x3C0));
    TObjEneBm5GibonU__sub_800D1CF8((O_800D1CF8 *)(ene_bm5_gibon_u + 0x3CC));
    ((TUnk_80494938 *)(ene_bm5_gibon_u + 0x3D8))->init_common();
    __construct_array(ene_bm5_gibon_u + 0x3F4, (void *)&init_and_activate__10TObjPlayerFv, (void *)&__dt__13TUnk_804949A8Fv, 0x1C, 4);
    ((TObjPlayer *)(ene_bm5_gibon_u + 0x4B0))->construct_target_cursor_records();
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0) = lbl_805D2A70;
    invoke_initialization_hook__9TObjEneDDFv(ene_bm5_gibon_u, arg2);
    ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->sub_800D10A0();
    ((TObjEneDD *)ene_bm5_gibon_u)->init_position_vectors();
    if (*(s32 *)((s8 *)ene_bm5_gibon_u + 0x464) == 1) {
        init_model__9TObjEneDDFv(ene_bm5_gibon_u, &gibon_collision_body_templates[1], 1);
    } else {
        init_model__9TObjEneDDFv(ene_bm5_gibon_u, &gibon_collision_body_templates[0], 1);
    }
    ((TObjMotion *)ene_bm5_gibon_u)->set_field_d8((s32)gibon_u_action_table);
    ((TObjMotion *)ene_bm5_gibon_u)->set_field_dc(*(s32 *)((s8 *)(*(u8 * *)&(*(u32 *)&TObjEneBm5GibonU__model_archive)) + 0x430));
    *(s16 *)((s8 *)ene_bm5_gibon_u + 0xB8) = 0;
    ((TObjMotion *)ene_bm5_gibon_u)->set_animation(*(s16 *)((s8 *)ene_bm5_gibon_u + 0xB8));
    ((TObjMotion *)ene_bm5_gibon_u)->set_field_b8(*(s16 *)((s8 *)ene_bm5_gibon_u + 0xB8));
    b = *(s32 *)((s8 *)ene_bm5_gibon_u + 0x464) ? 1 : 0;
    reset_hp__9TObjEneDDFv(ene_bm5_gibon_u, ((s32 *)&(*(G_800D1D14 *)&TObjEneBm5GibonU__data_80500E78))[b],
        lbl_80500E80[b],
        lbl_80500E88[b]);
    ((TObjEneDD *)ene_bm5_gibon_u)->check_state_flag_1();
    *(u8 **)((s8 *)ene_bm5_gibon_u + 0x350) = TObjEneBm5GibonU__movement_parameters;
    if (*(s32 *)((s8 *)ene_bm5_gibon_u + 0x464) != 0) {
        initialize_enemy_state__9TObjEneDDFv(ene_bm5_gibon_u, 0x3C);
    } else {
        initialize_enemy_state__9TObjEneDDFv(ene_bm5_gibon_u, 0x3B);
    }
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x37C) = TObjEneBm5GibonU__data_805DA164;
    ((TObjEneDD_ST *)ene_bm5_gibon_u)->enemy_init_acquire_period(0x14);
    ((TObjEneDD_ST *)ene_bm5_gibon_u)->enemy_init_validate_period(0x14);
    ((TObjEneBm5GibonU *)(ene_bm5_gibon_u + 0x3C0))->set_field8_from_obj((s32)ene_bm5_gibon_u);
    ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->init_child_node();
    if (*(s32 *)((s8 *)ene_bm5_gibon_u + 0x464) != 0) {
        ((TObjEneBm5GibonU *)(ene_bm5_gibon_u + 0x3CC))->set_field8_from_obj((s32)ene_bm5_gibon_u);
        ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->init_child_from_list();
    }
    *(u16 *)((s8 *)ene_bm5_gibon_u + 0x474) = 0xFFFF;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x478) = 0;
    VecCopy((Vec *)(ene_bm5_gibon_u + 0x47C), (const Vec *)(ene_bm5_gibon_u + 0x38));
    VecCopy((Vec *)(ene_bm5_gibon_u + 0x488), (const Vec *)(ene_bm5_gibon_u + 0x38));
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x494) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x498) = 0.0f;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x4AC) = 0;
    p = __nw__7TObjectFUl(0xAC);
    if (p != NULL) {
        p = __ct__13TUnk_804AF8A0FP7TObject(p, 0);
    }
    *(void **)((s8 *)ene_bm5_gibon_u + 0x50C) = p;
    init_collision_body_parts(*(void **)((s8 *)ene_bm5_gibon_u + 0x50C), &gibon_collision_body_templates[2], 1);
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x510) = 0;
    *(u16 *)((s8 *)ene_bm5_gibon_u + 0x514) = 0xFFFF;
    ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->vfunc_98();
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x518) = 0;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x51C) = 0;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x520) = 0;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x524) = 0;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x528) = 0;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x52C) = 0;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x530) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x534) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x538) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x53C) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x540) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x544) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x548) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x54C) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x550) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x554) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x558) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x55C) = 0.0f;
    *(f32 *)((s8 *)ene_bm5_gibon_u + 0x560) = 0.0f;
    *(s32 *)((s8 *)ene_bm5_gibon_u + 0x564) = 0;
    update_center_position__16TObjEneBm5GibonUFv(ene_bm5_gibon_u);
    ((TObjEneBm5GibonU *)ene_bm5_gibon_u)->vfunc_88();
    ((TObjEneDD *)ene_bm5_gibon_u)->transform_part_positions();
    *(s16 *)((s8 *)ene_bm5_gibon_u + 0x326) = 0;
    ((VObj_18_484afe *)ene_bm5_gibon_u)->m85(*(s16 *)((s8 *)ene_bm5_gibon_u + 0x326), 4);
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&((Self_800D14AC *)ene_bm5_gibon_u)->subs[i]))->activate_and_dispatch();
    }
    return ene_bm5_gibon_u;
}

Ene_800D17E8 *find_enemy_by_id__16TObjEneBm5GibonUFi(s32 id) {
    Node_800D17E8 *n;
    for (n = (*(List_800D17E8 *)&(*(RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4 *)&TObjEneBm5GibonU__enemy_list)).head; n != 0; n = n->next) {
        Ene_800D17E8 *e = ((Ene_800D17E8 *(*)(void *))update_photon_mylla__16TObjEneBm5GibonUFPv)(n);
        if (e != 0 && e->id == id) {
            return e;
        }
    }
    return 0;
}

void TObjEneBm5GibonU::forward_hit_to_enemy_list() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5GibonU *)((s32) &(*(RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4 *)&TObjEneBm5GibonU__enemy_list).value))->forward_hit((void*)(arg0 + 0x3CC));
}

typedef char RecoveredGlobal_800D187C_TObjEneBm5GibonU__data_80500EC4_size[sizeof(RecoveredGlobal_800D187C_TObjEneBm5GibonU__data_80500EC4) == 0xC ? 1 : -1];
void TObjEneBm5GibonU::init_child_from_list() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5GibonU *)((s32) &(*(RecoveredGlobal_800D187C_TObjEneBm5GibonU__data_80500EC4 *)&(*(RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4 *)&TObjEneBm5GibonU__enemy_list)).value))->init_child((void*)(arg0 + 0x3CC));
}

typedef char RecoveredGlobal_800D18AC_TObjEneBm5GibonU__data_80500EB0_size[sizeof(RecoveredGlobal_800D18AC_TObjEneBm5GibonU__data_80500EB0) == 0x14 ? 1 : -1];
void TObjEneBm5GibonU::forward_hit_to_node_list() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5GibonU *)((s32) &(*(RecoveredGlobal_800D18AC_TObjEneBm5GibonU__data_80500EB0 *)&TObjEneBm5GibonU__node_list).value))->forward_hit((void*)(arg0 + 0x3C0));
}

typedef char RecoveredGlobal_800D18DC_TObjEneBm5GibonU__data_80500EB0_size[sizeof(RecoveredGlobal_800D18DC_TObjEneBm5GibonU__data_80500EB0) == 0x14 ? 1 : -1];
void TObjEneBm5GibonU::init_child_node() {
    s32 arg0 = (s32)this;
    ((TObjEneBm5GibonU *)((s32) &(*(RecoveredGlobal_800D18DC_TObjEneBm5GibonU__data_80500EB0 *)&(*(RecoveredGlobal_800D18AC_TObjEneBm5GibonU__data_80500EB0 *)&TObjEneBm5GibonU__node_list)).value))->init_child((void*)(arg0 + 0x3C0));
}

void TObjEneBm5GibonU::release_static_resource() {
    if ((u32) (*(u32 *)&TObjEneBm5GibonU__model_archive) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&TObjEneBm5GibonU__model_archive), 1);
        (*(u32 *)&TObjEneBm5GibonU__model_archive) = 0U;
    }
}

extern void *tl_04;

void *TObjEneBm5GibonU::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x568);
    if (o != NULL) {
        o = TObjEneBm5GibonU__ct((u8 *)o, (s32)tl_04, (s32)arg0);
    }
    return o;
}

void TObjEneBm5GibonU::load_resources() {
    Spawn_800D1990 sp;
    s32 i;
    u8 *m;
    f32 *v;
    if (is_split_screen() != 0) {
        m = load_enemy_bml_resource(lbl_80493DE4);
    } else {
        m = load_enemy_bml_resource(lbl_80493DA0);
    }
    (*(u32 *)&TObjEneBm5GibonU__model_archive) = (u32)m;
    ((TObjEneBm5GibonU *)(&(*(RecoveredGlobal_800D18AC_TObjEneBm5GibonU__data_80500EB0 *)&TObjEneBm5GibonU__node_list)))->reset_fields();
    ((TObjEneBm5GibonU *)(&(*(RecoveredGlobal_800D184C_TObjEneBm5GibonU__data_80500EC4 *)&TObjEneBm5GibonU__enemy_list)))->reset_fields();
    TObjEneBm5GibonU__render_node_index = 0;
    TObjEneBm5GibonU__render_joint_y_rotation = 0;
    v = lbl_80500E98;
    lbl_80500E98[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    for (i = 0; i < 2; i++) {
        ((u32 *)&(*(G_800D1D14 *)&TObjEneBm5GibonU__data_80500E78))[i] = register_boss__6TLobbyFl(lbl_8043BF30[i]);
        lbl_80500E80[i] = dispatch_shared_handler_b__6TLobbyFl(lbl_8043BF38[i]);
        lbl_80500E88[i] = register_object__6TLobbyFl(lbl_8043BF40[i]);
        lbl_80500E90[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_8043BF48[i]);
    }
    sp.a = TObjEneBm5GibonU__spawn_params.a;
    sp.b = TObjEneBm5GibonU__spawn_params.b;
    sp.c = TObjEneBm5GibonU__spawn_params.c;
    sp.d = TObjEneBm5GibonU__spawn_params.d;
    m = (u8 *)(*(u32 *)&TObjEneBm5GibonU__model_archive);
    sp.a = *(s32 *)((s8 *)m + 0x430);
    spawn_npc_enemy__6TLobbyFslllff(0xE, *(s32 *)((s8 *)(*(u8 **)((s8 *)m + 0x42C)) + 8), *(s32 *)((s8 *)(*(u8 **)((s8 *)m + 0x42C)) + 0xC), &sp, *(f32 *)((s8 *)gibon_collision_body_templates + 0xC), 0.0f);
    spawn_npc_enemy__6TLobbyFslllff(0xF, *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u32 *)&TObjEneBm5GibonU__model_archive) + 0x42C)) + 0x18), *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u32 *)&TObjEneBm5GibonU__model_archive) + 0x42C)) + 0x1C), &sp, *(f32 *)((s8 *)gibon_collision_body_templates + 0x38), 0.0f);
}

void TObjEneBm5GibonU::forward_hit(void* a1) { ((TObjEneBm5GibonU *)a1)->unlink_list_node((void ***)(this), (void **)((void*)((char*)this + 0x4))); }
void TObjEneBm5GibonU::init_child(void* a1) { ((TObjEneBm5GibonU *)a1)->push_list_node((void **)(this), (void **)((void*)((char*)this + 0x4))); }
void TObjEneBm5GibonU::reset_fields() { *(s32*)((char*)this + 0x0) = 0; *(s32*)((char*)this + 0x4) = 0; }
s32 __dt__16TObjEneBm5GibonUFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
void*TObjEneBm5GibonU::reset() { reset_fields(); return this; }
void update_photon_mylla__16TObjEneBm5GibonUFPv(void *arg0) {
    find_entity_by_id(*(u16 *)((s8 *)arg0 + 8));
}
void TObjEneBm5GibonU::set_field8_from_obj(s32 arg1) {
    *(s16 *)((s8 *)this + 8) = get_entity_id(arg1);
}

void TObjEneBm5GibonU::push_list_node(void **arg1, void **arg2) {
    u8 *arg0 = (u8 *)this;
    u8 *name;
    name = (u8 *)(*arg2);
    if (name != NULL) {
        *(void * *)&this->m_name = name;
        *(void **)((s8 *)(*arg2) + 4) = arg0;
    } else {
        this->m_name = NULL;
        *arg1 = arg0;
    }
    *arg2 = arg0;
    *(s32 *)((s8 *)arg0 + 4) = 0;
}

void TObjEneBm5GibonU::unlink_list_node(void ***arg1, void **arg2) {
    u8 *arg0 = (u8 *)this;
    void **temp_r4;
    u8 *temp_r6;
    temp_r6 = *(u8 * *)&this->m_name;
    if (temp_r6 != NULL) {
        *(void ***)((s8 *)temp_r6 + 4) = (void **) *(void ***)((s8 *)arg0 + 4);
    } else {
        *arg1 = *(void ***)((s8 *)arg0 + 4);
    }
    temp_r4 = *(void ***)((s8 *)arg0 + 4);
    if (temp_r4 != NULL) {
        *temp_r4 = *(u8 * *)&this->m_name;
        return;
    }
    *arg2 = *(u8 * *)&this->m_name;
}

s32 TObjEneBm5GibonU::destroy(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

void TObjEneBm5GibonU__sub_800D1CF8(O_800D1CF8 *self) {
    self->f0 = 0;
    self->f4 = 0;
    self->f8 = 0xFFFF;
}

#pragma push
#pragma opt_propagation off
void TObjEneBm5GibonU::register_global_objects() {
    G_800D1D14 *g = &(*(G_800D1D14 *)&TObjEneBm5GibonU__data_80500E78);
    __register_global_object(((TObjEneBm5GibonU *)(g->obj1))->reset(), (void *)__dt__16TObjEneBm5GibonUFis, g->chain1);
    __register_global_object(((TObjEneBm5GibonU *)(g->obj2))->reset(), (void *)__dt__16TObjEneBm5GibonUFis, g->chain2);
}
#pragma pop

s32 TObjEneBm5GibonU__sub_800D1D70(void* p) { return *(s32*)((char*)p + 0x46c); }
void* TObjEneBm5GibonU__sub_800D1D78(void* p) { return (char*)p + 0x47c; }

void TObjEneBm5GibonU::clear_flag_and_update() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x374) == 7) {
        this->m_388 = (s32) (this->m_388 & 0xFFFFFFFE);
        ((TObjEneMe1GiGue *)arg0)->update_if_active(0);
    }
}

s32 TObjEneBm5GibonU::check_and_update() {
    s32 arg0 = (s32)this;
    if (update_movement_status__13TUnk_804806E8Fv() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}
s32 TObjEneBm5GibonU::try_activate() {
    s32 arg0 = (s32)this;
    if (update_shock_clock__13TUnk_804806E8Fv() != 0) {
        clear_flag_and_update();
        return 1;
    }
    return 0;
}

}

#undef transition_enemy_state__9TObjEneDDFs
#undef lbl_80493F04
#undef update_angle__10TObjPlayerFlPv
#undef update_collisions__10TObjPlayerFv
#undef __nw__7TObjectFUl
#undef update_shock_clock__13TUnk_804806E8Fv
#undef update_movement_status__13TUnk_804806E8Fv
#undef get_entity_id
#pragma pop

__declspec(section ".ctors") static void *const __sinit_TObjEneBm5GibonU_cpp_ref = (void *)TObjEneBm5GibonU::register_global_objects;
