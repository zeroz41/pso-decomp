#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/render/reflection.h"
#include "pso/system/vector.h"
extern "C" void *__ct__12TObjEneDD_STFP7TObject(void *);
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMorfos.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/object/TObjMotion.h"

#include "pso/enemy/TObjEneRecon.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/enemy/TUnk_80494938.h"
#include <stddef.h>
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneMorfosArm.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

struct VBase_18_76ddf3 { char pad[0x18]; };

struct VObj_18_76ddf3 : VBase_18_76ddf3 {
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
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct VBase_80332850 { char pad[0x18]; };

struct VObj_80332850 : VBase_80332850 {
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
};

struct Vec_80332850 { s32 a, b, c; };

struct Base_803344F0 { char pad[0x18]; };

struct VObj_803344F0 : Base_803344F0 {
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
    virtual int m97();
};

struct D_80333290 { u8 pad0[0x1C]; s32 f1C; u8 pad20[4]; s32 f24; s32 f28; };

extern "C" {
f32 random_ratio__9TObjCharaFv(s32);
f32 atan2_float(f32, f32);
s32 update_linked_position__12TObjEneDD_STFf(f32);
s32 transition_enemy_state__9TObjEneDDFl(void *, s32);
s32 advance_animation_playback(void *);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern const f64 TObjEneMorfos__data_80477610;
extern int TObjEneMorfos__param_table;
extern const f32 TObjEneMorfos__data_805DF86C;
extern const f32 TObjEneMorfos__data_805DF874;
extern const f32 lbl_805DF87C;
extern const f32 lbl_805DF890;
void TObjEneMorfos__sub_80333AD0(u8 *arg0, s32 arg1);
s32 get_flag_b4__9TObjEneDDFv();
void spawn_particle_effect(void *, int);
s32 play_sound_effect(s32, u32, s16, s32);
u8 * TObjEneMorfos__sub_80337824(void *, void *, s32, s32);
void * __nw__7TObjectFUl(int);
extern const f32 TObjEneMorfos__data_805DF884;
extern const f32 lbl_805DF88C;
void TObjEneMorfos__sub_80333690(TObjEneMorfos *arg0, s32 arg1);
s32 enemy_validate_retained_target(u8 *arg0);
extern const f32 lbl_805DF880;
extern const f32 lbl_805DF888;
void TObjEneMorfos__sub_80332FD4(TObjEneMorfos *arg0, s32 arg1);
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, Vec_80332850 *, s32);
extern Vec_80332850 lbl_804775E4;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 TObjEneMorfos__data_805DF870;
void render__13TObjEneMorfosFv(u8 *arg0);
u8 * get_player_data__10TObjPlayerFi(int);
s32 queue_destruction__7TObjectFv(void *);
void *create_particle_emitter(void *pos, s32 id);
s32 is_alive__8TObjBaseFv(void *);
s32 check_value_in_range__13TObjEneMorfosFPvUsUsUs(void *, int, int, int);
s32 TObjEneMorfos__sub_803344F0(void *arg0);
extern s32 game_difficulty_selection;
struct Base_A_803326C4 { char pad[0x18]; };

struct V_A_803326C4 : Base_A_803326C4 {
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void m87();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void m94();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void m100(s32);
};

struct VBase_14_80333E48 { char pad[0x14]; };

struct VObj_14_80333E48 : VBase_14_80333E48 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
};

struct VBase_14_2f517b { char pad[0x14]; };

struct VObj_14_2f517b : VBase_14_2f517b {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
};

struct VBase_14_948132 { char pad[0x14]; };

struct VObj_14_948132 : VBase_14_948132 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct VBase_14_fddec9 { char pad[0x14]; };

struct VObj_14_fddec9 : VBase_14_fddec9 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
};

struct RecoveredGlobal_803326CC_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredFields_803326CC_TObjEneMorfos__data_805D6D14 {
    u8 unknown_0[0x42C];
    u8 * field_42C;
};

struct RecoveredFields_803326CC_arg0 {
    u8 unknown_0[0x60];
    s32 field_60;
    u8 unknown_64[0x35C];
    s32 field_3C0;
};

struct Stack_80332B7C
{
  s32 sp8;
  s32 spC;
  s32 sp10;
};

struct RecoveredGlobal_80332B7C_lbl_804775D8
{
  s32 value;
  u8 remaining[0x8];
};

struct V3_80334588 { f32 x, y, z; };

struct O_80334588 { u8 pad[0x60]; s32 f60; u8 pad2[0x2FC - 0x64]; V3_80334588 pos; };

struct Part_803329E4 : VObj_14_fddec9 { u8 pad18[4]; };

struct Self_803329E4 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x38 - 0x28];
    u8 pos[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    u8 cam[0x3C0 - 0x2FC];
    s32 f3C0;
    u8 pad3C4[0x3EC - 0x3C4];
    VObj_14_fddec9 body;
    u8 pad404[0x424 - 0x404];
    Part_803329E4 parts[4];
    u8 pad494[0x498 - 0x494];
    u8 f498[4];
};

typedef char RecoveredGlobal_803326CC_main_task_size[sizeof(RecoveredGlobal_803326CC_main_task) == 0x34 ? 1 : -1];

typedef char RecoveredFields_803326CC_TObjEneMorfos__data_805D6D14_42C_offset[offsetof(RecoveredFields_803326CC_TObjEneMorfos__data_805D6D14, field_42C) == 0x42C ? 1 : -1];

typedef char RecoveredFields_803326CC_arg0_60_offset[offsetof(RecoveredFields_803326CC_arg0, field_60) == 0x60 ? 1 : -1];

typedef char RecoveredFields_803326CC_arg0_3C0_offset[offsetof(RecoveredFields_803326CC_arg0, field_3C0) == 0x3C0 ? 1 : -1];

typedef struct RecoveredGlobal_80332B7C_lbl_804775D8 RecoveredGlobal_80332B7C_lbl_804775D8;

typedef struct Stack_80332B7C Stack_80332B7C;

typedef char RecoveredGlobal_80332B7C_lbl_804775D8_size[((sizeof(RecoveredGlobal_80332B7C_lbl_804775D8)) == 0xC) ? (1) : (-1)];

struct RecoveredGlobal_80334CC8___vt__13TObjEneMorfos {
    s32 value;
    u8 remaining[0x1A8];
};

struct Vec_8033496C { f32 x, y, z; };

struct Obj_8033496C { u8 pad[0x60]; s32 f60; u8 pad1[0x2D4 - 0x64]; u16 f2D4; u8 pad2[0x2FC - 0x2D6]; Vec_8033496C pos; u8 pad3[0x326 - 0x308]; s16 f326; u8 pad4[0x3C0 - 0x328]; s32 f3C0; };

struct Pl_8033496C { u8 pad[0x2FC]; Vec_8033496C pos; };

struct Vec_80334A4C { f32 x, y, z; };

struct Obj_80334A4C { u8 pad[0x60]; s32 f60; u8 pad1[0x2FC - 0x64]; Vec_80334A4C pos; u8 pad4[0x3C0 - 0x308]; s32 f3C0; u8 pad5[0x498 - 0x3C4]; u8 snd[4]; };

typedef char RecoveredGlobal_80334CC8___vt__13TObjEneMorfos_size[sizeof(RecoveredGlobal_80334CC8___vt__13TObjEneMorfos) == 0x1AC ? 1 : -1];

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

f32 receive_physical_attack__9TObjCharaFPvf(void *, void *, f32);
u16 get_entity_id(void *);
void TLobby__sub_8001FE7C(void*, int);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
s32 get_mode__11TCameraCtrlFPv(void *);
u32 csnLookAt(void *, void *);
s32 is_patrol_active__21TObjEneRe7BeruraPunchFv(void *);
s32 TObjPlayer__sub_800A04F0(void *);
void TObjPlayer__sub_800A0554(void *);
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void enemy_set_target_id(void *, u16);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 get_camera_ctrl__9TObjEneDDFv(void *, int);
s32 clear_attack_receipts__9TObjEneDDFv();
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
void TObjEneMe3SinowZoa__sub_800D758C(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 update__15RenderFadeStateFv(void *);
s32 angle_difference_abs(s32, s32);
s32 angle_diff_s16(s32);
s32 free_collision_body_parts(void *);
Pl_8033496C * get_player_by_client_id(s32);
s32 __dl__7TObjectFPv(void *);
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
void TObjEneMorfos__sub_80332DBC(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_80333E48(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_80334030(u8 *arg0, s32 arg1);
void TObjEneMorfos__sub_803342B8(u8 *arg0, s32 arg1);
void TObjEneMorfos__vt85(u8 *arg0, u32 arg1, s32 arg2);
int TObjEneMorfos__sub_80334704(void);
void vfunc_88__13TObjEneMorfosFv(void *arg0);
void vfunc_61__13TObjEneMorfosFv(void);
void vfunc_62__13TObjEneMorfosFv(Obj_8033496C *arg0);
f32 TObjEneMorfos__vt20(Obj_80334A4C *arg0, Obj_80334A4C *arg1, f32 farg0);
void vfunc_63__13TObjEneMorfosFv(void* p);
void vfunc_28__13TObjEneMorfosFv(void);
void run_task__13TObjEneMorfosFv(u8 *arg0);
u8 * __dt__13TObjEneMorfosFv(u8 *arg0, s16 arg1);
void * TObjEneMorfos__ct(void *arg0, void *arg1, void *arg2);
void TObjEneMorfosArm__sub_8033542C(void);
s32 __destroy_arr(void *, void *, int, int);
void __construct_array(void *, void *, void *, int, int);
s32 rotate_matrix_y(int, int);
void subtract_vector(void *, void *);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void vfunc_6__8TObjBaseFPsl();
void vfunc_103__9TObjEneDDFPUc();
void vfunc_79__9TObjEneDDFPl();
void vfunc_84__9TObjEneDDFv();
void vfunc_85__9TObjEneDDFv();
void vfunc_86__9TObjEneDDFv();
void vfunc_89__9TObjEneDDFv();
void vfunc_90__9TObjEneDDFv();
void vfunc_91__9TObjEneDDFv();
void vfunc_92__9TObjEneDDFv();
void vfunc_93__9TObjEneDDFv();
void vfunc_94__9TObjEneDDFv();
void vfunc_95__9TObjEneDDFv();
void vfunc_96__9TObjEneDDFv();
void vfunc_97__9TObjEneDDFv();
void vfunc_98__9TObjEneDDFv();
void vfunc_99__9TObjEneDDFv();
void vfunc_100__9TObjEneDDFv();
void vfunc_101__9TObjEneDDFPUc();
void vfunc_102__9TObjEneDDFv();
int vfunc_104__12TObjEneDD_STFf(void *p);
void vfunc_83__12TObjEneDD_STFv();
void vfunc_83__13TObjEneMorfosFv();
void vfunc_106__13TObjEneMorfosFv();
void vfunc_29__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFv();
void vfunc_75__9TObjCharaFf();
void clear_lobby_object_state__9TObjEnemyFv();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_name__9TObjEnemyFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void render_shadows__9TObjEnemyFv(u8 *arg0);
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
void update_action_hold_status__9TObjCharaFv();
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_actor_ground_y__9TObjCharaFv();
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
}
void restore_render_scissor(s32 arg0);
void draw_chunk_model(void *arg0);

extern int TObjEneMorfos__instance;
extern s32 TObjEneMorfos__phase;
extern s32 TObjEneMorfos__camera_path_cursor;
extern const f32 TObjEneMorfos__data_805DF89C;
extern s32 __dt__15RenderFadeStateFv[];
extern s32 __ct__15RenderFadeStateFv[];
extern RecoveredGlobal_80332B7C_lbl_804775D8 lbl_804775D8;
extern void *morfos_class_name;
extern s32 actor_frame_tick;
extern u8 *lbl_805D6D20;
extern u8 *lbl_805D6D24;
extern s32 lbl_805D6D28;
extern s32 lbl_805D6D2C;
extern float morfos_projectile_speed;
extern float morfos_param_table_speed_copy;
extern const f32 lbl_805DF878;
extern const f32 lbl_805DF894;
extern const f32 lbl_805DF898;
extern const f32 lbl_805DF8A0;
extern const f32 lbl_805DF8A4;
extern void *tl_04;

extern u8 lbl_804774C0[];
extern u8 lbl_804774CC[];
extern u8 lbl_804774DC[];
extern u8 lbl_804774EC[];
extern u8 lbl_80477500[];
extern u8 lbl_80477518[];
extern u8 lbl_8047752C[];
extern u8 lbl_80477544[];
extern u8 lbl_80477558[];
extern u8 lbl_8047756C[];
extern u8 lbl_80477580[];
extern u8 lbl_80477590[];
extern u8 lbl_804775A0[];
extern void *bm_ene_morfos_model_names[4];
extern void *bm_ene_morfos_motion_names[7];
extern void *bm_ene_morfos_low_model_names[4];
extern void *bm_ene_morfos_low_motion_names[7];

void *lbl_804EE0C0[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804EE0DC[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm_ene_morfos_model_names[4] = {
    (void *)&lbl_804774C0, (void *)&lbl_804774CC, (void *)&lbl_804774DC, (void *)0x0,
};
void *bm_ene_morfos_motion_names[7] = {
    (void *)&lbl_804774EC, (void *)&lbl_80477500, (void *)&lbl_80477518, (void *)&lbl_8047752C,
    (void *)&lbl_80477544, (void *)&lbl_80477558, (void *)0x0,
};
void *morfos_resource_descriptor[4] = {
    (void *)&lbl_8047756C, (void *)&bm_ene_morfos_model_names, (void *)&bm_ene_morfos_motion_names, (void *)0x30006,
};
void *bm_ene_morfos_low_model_names[4] = {
    (void *)&lbl_80477580, (void *)&lbl_80477590, (void *)&lbl_804774DC, (void *)0x0,
};
void *bm_ene_morfos_low_motion_names[7] = {
    (void *)&lbl_804774EC, (void *)&lbl_80477500, (void *)&lbl_80477518, (void *)&lbl_8047752C,
    (void *)&lbl_80477544, (void *)&lbl_80477558, (void *)0x0,
};
void *bm_ene_morfos_low_resource_descriptor[4] = {
    (void *)&lbl_804775A0, (void *)&bm_ene_morfos_low_model_names, (void *)&bm_ene_morfos_low_motion_names, (void *)0x30006,
};
void *morfos_motion_param_table[20] = {
    (void *)0x10000, (void *)0x5, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f333333, (void *)0x0,
};
void *__vt__13TObjEneMorfos[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TObjEneMorfosFv, (void *)&run_task__13TObjEneMorfosFv,
    (void *)&render__13TObjEneMorfosFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&TObjEneMorfos__vt20, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__13TObjEneMorfosFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__13TObjEneMorfosFv, (void *)&vfunc_62__13TObjEneMorfosFv, (void *)&vfunc_63__13TObjEneMorfosFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneMorfos__vt85,
    (void *)&vfunc_88__13TObjEneMorfosFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&vfunc_83__13TObjEneMorfosFv, (void *)&vfunc_106__13TObjEneMorfosFv,
};
#define __vt__13TObjEneMorfos ((s32 *)__vt__13TObjEneMorfos)
extern "C" {

int TObjEneMorfos::get_instance() {  return TObjEneMorfos__instance; }

#pragma push
#pragma opt_common_subs off
void TObjEneMorfos::draw_body() {
    u8 *arg0 = (u8 *)this;
    if (get_mode__11TCameraCtrlFPv((void *) (&(*(RecoveredGlobal_803326CC_main_task *)((s32 *)&main_task)).value)) & 0x200) {
        TObjFish::set_global_param((int)((void *) (*(s32 *)((s8 *)(((RecoveredFields_803326CC_TObjEneMorfos__data_805D6D14 *)(*(u8 * *)&TObjEneMorfos__instance))->field_42C) + 0x2C))));
        push_matrix();
        post_translate_matrix(arg0 + 0x498);
        rotate_matrix_y(0, (int) (((RecoveredFields_803326CC_arg0 *)arg0)->field_60));
        if (((RecoveredFields_803326CC_arg0 *)arg0)->field_3C0 & 2) {
            if (((VObj_14_fddec9 *)(arg0 + (1032)))->m8() != 0) {
                ((VObj_14_fddec9 *)(arg0 + (1032)))->m6();
                draw_chunk_model((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)(((RecoveredFields_803326CC_TObjEneMorfos__data_805D6D14 *)(*(u8 * *)&TObjEneMorfos__instance))->field_42C) + 0x28)) + 4)));
                ((VObj_14_fddec9 *)(arg0 + (1032)))->m7();
            }
        } else {
            draw_chunk_model((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)(((RecoveredFields_803326CC_TObjEneMorfos__data_805D6D14 *)(*(u8 * *)&TObjEneMorfos__instance))->field_42C) + 0x28)) + 4)));
        }
        pop_matrix();
    }
}
#pragma pop

s32 TObjEneMorfos::render_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv((void *) (((s32 *)&main_task))) & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x3C8)) != 0) {
            TObjFish::set_global_param(this->texlist);
            push_matrix();
            post_translate_matrix((void *) (((u8 *)this) + 0x38));
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            if (*(s32 *)((s8 *)((u8 *)this) + 0x3C0) & 0x10) {
                this->draw_body();
            }
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

struct Self_803329E4;
void render__13TObjEneMorfosFv(u8 *ene_morfos) {
    s32 cam;
    s32 vis;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_80332850 *)ene_morfos)->m104();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (*(u32 *)((s8 *)ene_morfos + 0x3C0) & 1) {
        vis = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        vis = ((VObj_80332850 *)ene_morfos)->m9(lbl_805D9E88, lbl_805D9E84, TObjEneMorfos__data_805DF870);
    } else if (((VObj_80332850 *)ene_morfos)->m8(TObjEneMorfos__data_805DF86C, TObjEneMorfos__data_805DF870) != 0) {
        vis = 1;
    } else {
        vis = 0;
    }
    if (vis != 0 && ((TObjEneMorfos *)ene_morfos)->render_model_if_visible() == 0) {
        ((TObject *)ene_morfos)->defer_render();
        ((TObjEneMorfos *)ene_morfos)->render_part(cam, vis);
        if (((TObjEneMorfos *)ene_morfos)->mode != 0xB && !(*(u32 *)((s8 *)ene_morfos + 0x3C4) & 0x4000)) {
            Vec_80332850 v = lbl_804775E4;
            update_player_state__9TObjEneDDFv(ene_morfos, &v, 0);
        }
        ((TObjEneDD *)ene_morfos)->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        model_render_flags &= ~0x810;
        if (*(u32 *)((s8 *)ene_morfos + 0x3C0) & 0x10) {
            ((TObjEneMorfos *)ene_morfos)->draw_body();
        }
        model_render_flags = saved_model_render_flags;
    }
}

void TObjEneMorfos::render_part(s32 idx, s32 mode) {
    s32 vis;
    Part_803329E4 *part;
    Self_803329E4 *self = (Self_803329E4 *)this;
    part = &self->parts[idx];
    update__15RenderFadeStateFv(part);
    vis = ((RenderFadeState *)part)->updateFromCamera((const f32*)(self->cam));
    TObjFish::set_global_param(this->texlist);
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, this->rotation_y);
    TObjEneMorfos__phase = 0;
    TObjEneMorfos__camera_path_cursor = (s32)self->f498;
    TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneMorfos::record_camera_path_point));
    if (self->f3C0 & 2) {
        if (self->body.m8() != 0) {
            self->body.m6();
            if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200) {
                ((TObjMotion *)self)->draw();
            }
            self->body.m7();
        }
    } else if (vis != 0) {
        part->m6();
        if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200) {
            ((TObjMotion *)self)->draw();
        }
        part->m7();
    } else if (!(get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x200)) {
        if (mode == 1) {
            ((TObjMotion *)self)->draw();
        } else {
            ((TObjEnemy *)self)->draw_motion_model();
        }
    }
    TObjEneRe7Berura::set_global_state((s32)NULL);
    pop_matrix();
    ((TObjEneDD *)self)->update_primary_light();
    TParticleCtrl::end_effect_render();
}

void TObjEneMorfos::record_camera_path_point() {
  int new_var;
  Stack_80332B7C stack;
  if (((s32) TObjEneMorfos__phase) != 0xA)
  {
    if (((s32) TObjEneMorfos__phase) < 0xA)
    {
      if (((s32) TObjEneMorfos__phase) != 6)
      {
      }
      else
      {
        goto block_4;
      }
    }
    if (((!TObjEneMorfos__phase) && (!TObjEneMorfos__phase)) && (!TObjEneMorfos__phase))
    {
    }
  }
  else
  {
    new_var = 0;
    block_4:
    stack.sp8 = *((s32 *) (((s8 *)&lbl_804775D8.value) + new_var));
    stack.spC = *((s32 *) (((s8 *)&lbl_804775D8.value) + 4));
    stack.sp10 = *((s32 *) (((s8 *)&lbl_804775D8.value) + 8));
    get_camera_ctrl__9TObjEneDDFv((void *)&stack.sp8, (int) TObjEneMorfos__camera_path_cursor);
    TObjEneMorfos__camera_path_cursor += 0xC;
  }
  TObjEneMorfos__phase += 1;
}

void TObjEneMorfos::state_death(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r30;

    switch (arg1) {
    case 4:
        this->requested_action = 4;
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        advance_animation_playback(arg0);
        ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
        this->m_4c4 = (f32) *(s32 *)((s8 *)arg0 + 0x3D4);
        this->m_4b4 = 0;
        *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
        ((TObjEneMe3SinowZoa *)(arg0 + 0x408))->init_death_params();
        play_sound_effect(0x4003A626, (u32)(arg0 + 0x38), 0, 0);
        return;
    case 3:
        if ((s32) this->m_4b4 == 2) {
            ((s32 (*)(void))queue_destruction__7TObjectFv)();
        }
    case 5:
        return;
    case 0:
        temp_r0 = this->m_4b4;
        switch (temp_r0) {
        case 0:
            advance_animation_playback(arg0);
            temp_r30 = ((VObj_14_c1c33b *)(arg0 + (1032)))->m4();
            if ((((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) && (temp_r30 != 0)) {
                fn_800D911C((Vec *)(arg0 + 0x38));
                play_sound_effect(0x4003A830, (u32)(arg0 + 0x38), 0, 0);
                TObjPlayer__sub_800A04F0((u8 *)&this->m_408);
                *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 2);
                this->m_4b4 = 1;
                return;
            }
            break;
        case 1:
            if (((VObj_14_c1c33b *)(arg0 + (1004)))->m4() != 0) {
                this->m_4b4 = 2;
                *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 1);
                TObjPlayer::apply_effect_variant_b((s32)(arg0 + 0x38), 0);
                return;
            }
            break;
        default:
            this->m_4b4 = 2;
            break;
        }
        break;
    }
}

void TObjEneMorfos__sub_80332DBC(u8 *ene_morfos, s32 arg1) {
    s32 temp_r3;
    switch (arg1) {
    case 4:
        ((TObjEneMorfos *)ene_morfos)->requested_action = 3;
        ((TObjEneDD *)ene_morfos)->vfunc_96();
        *(s32 *)((s8 *)ene_morfos + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_morfos + 0x3C0) & 0xFFFFFFF8);
        advance_animation_playback(ene_morfos);
        ((TObjEneDD_ST *)ene_morfos)->set_active();
        return;
    case 3:
        if (get_flag_b4__9TObjEneDDFv() != 0) {
            temp_r3 = *(s32 *)((s8 *)ene_morfos + 0x3C0);
            if (temp_r3 & 0x20) {
                *(s32 *)((s8 *)ene_morfos + 0x3C0) = (s32) (temp_r3 & 0xFFFFFFDF);
                if (((TObjEneMorfos *)ene_morfos)->try_enter_low_hp_state() == 0) {
                    transition_enemy_state__9TObjEneDDFl(ene_morfos, (s32)((int) (((TObjEneMorfos *)ene_morfos)->m_378)));
                }
            } else {
                if (((TObjEneMorfos *)ene_morfos)->check_low_hp_trigger() != 0) {
                    transition_enemy_state__9TObjEneDDFl(ene_morfos, (s32)((int) (((TObjEneMorfos *)ene_morfos)->m_378)));
                } else if (((TObjEneMorfos *)ene_morfos)->try_enter_low_hp_state() == 0) {
                    transition_enemy_state__9TObjEneDDFl(ene_morfos, (s32)((int) (((TObjEneMorfos *)ene_morfos)->m_378)));
                }
            }
        }
        break;
    case 0:
        advance_animation_playback(ene_morfos);
        return;
    case 5:
        clear_attack_receipts__9TObjEneDDFv();
        ((TObjEneDD *)ene_morfos)->clear_field_388();
        break;
    }
}

void TObjEneMorfos::state_patrol(s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->vfunc_96();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF8);
        set_field_378(8);
        *(s32 *)((s8 *)this + 0x4B0) = 0;
        this->m_4bc = (this->rotation_y + 0x3800);
        break;
    case 3:
        if ((s32) this->rotation_y >= (s32) this->m_4bc) {
            transition_enemy_state__9TObjEneDDFl(this, 6);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(this);
        if (is_patrol_active__21TObjEneRe7BeruraPunchFv(this) == 0) {
            this->play_speed = (f32) lbl_805DF878;
        }
        temp_r4 = this->rotation_y;
        this->rotation_y = (temp_r4 + 0x280);
        ((V_A_803326C4 *) this)->m100(temp_r4);
        this->vfunc_89();
        break;
    }

}

struct O_80334588;

void TObjEneMorfos__sub_80332FD4(TObjEneMorfos *arg0, s32 arg1) {
    s32 temp_r0;
    switch (arg1) {
    case 4:
        arg0->requested_action = 0;
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)arg0)->set_field_378(5);
        *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
        arg0->m_4b4 = 0;
        break;
    case 3:
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if ((((s32 (*)(void *))TObjEneMorfos__sub_803344F0)(arg0) == 0) && ((void *) arg0->m_390 == NULL)) {
                transition_enemy_state__9TObjEneDDFl(arg0, 7);
            }
            break;
        case 3:
            transition_enemy_state__9TObjEneDDFl(arg0, 4);
            break;
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if (enemy_validate_retained_target((u8 *)arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
                if (arg0->approach_value((s32) (TObjEneMorfos__data_80477610 * atan2_float(arg0->m_3a0, *(f32 *)((s8 *)arg0 + 0x3A8))), *(s32 *)((s8 *)((u8 *)TObjEneMorfos__param_table) + 0x1C)) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 1;
                    arg0->requested_action = 1;
                    play_sound_effect(0x4003A725, (u32)((u8 *)arg0 + 0x38), 0, 0);
                    TObjEneMorfosArm::create((void *)arg0, (void *)arg0);
                } else if (*(f32 *)((s8 *)arg0 + 0x3AC) >= lbl_805DF87C) {
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 3;
                }
                arg0->play_sound_in_band();
            }
            break;
        case 1:
            if ((((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF880) != 0) && (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0)) {
                if (((VObj_18_76ddf3 *)(arg0->m_390))->m18(arg0, TObjEneMorfos__data_805DF884) != 0) {
                    ((VObj_18_76ddf3 *)(arg0->m_390))->m20(arg0, TObjEneMorfos__data_805DF884);
                    ((VObj_18_76ddf3 *)(arg0->m_390))->m23(arg0, lbl_805DF888);
                }
            }
            if (((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 2;
                arg0->m_4b4 = 0;
                arg0->requested_action = 0;
            }
            break;
        case 2:
            arg0->m_4b4 = (arg0->m_4b4 + 1);
            if ((s32) arg0->m_4b4 >= 0x32) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 3;
                arg0->requested_action = 0;
            }
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#define F(o, t) (*(t *)(arg0 + (o)))
#define D (*(D_80333290 * *)&TObjEneMorfos__param_table)
void TObjEneMorfos::state_rotating_projectile_burst(s32 arg1) {
    s32 old;
    void *p;
    s32 n;
    s32 i;
    u8 *pl;
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)arg0)->vfunc_96();
        F(0x3C0, s32) &= ~3;
        F(0x3C0, s32) |= 4;
        ((TObjEneDD *)arg0)->set_field_378(4);
        F(0x4BC, s32) = 0;
        F(0x4C0, s32) = 0;
        F(0x4B0, s32) = 0;
        F(0x4B8, s32) = 0;
        F(0xB8, s16) = 0;
        F(0x494, u32) = (u32)create_particle_emitter(arg0 + 0x498, 0x10A);
        break;
    case 3:
        if (F(0x4B0, s32) == 5 && TObjEneMorfos__sub_803344F0(arg0) == 0) {
            transition_enemy_state__9TObjEneDDFl(arg0, 4);
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (F(0x4B0, s32)) {
        case 0:
            if (F(0x494, u32) != 0) {
                ((TParticleCtrl *)F(0x494, void *))->set_position(arg0 + 0x498);
            }
            F(0x4C0, s32) = F(0x60, s32);
            F(0x60, s32) = F(0x60, s32) + D->f28;
            F(0x4B8, s32) = F(0x4B8, s32) + 1;
            if (F(0x4B8, s32) >= D->f24) {
                F(0x4B0, s32) = 1;
                F(0x4B4, s32) = 0;
                if (F(0x494, u32) != 0) {
                    queue_destruction__7TObjectFv(F(0x494, void *));
                    F(0x494, u32) = 0;
                }
            }
            break;
        case 1: {
            old = F(0x60, s32);
            F(0x60, s32) += D->f1C;
            n = TLobby::get_game_mode();
            for (i = 0; i < n; i++) {
                pl = get_player_data__10TObjPlayerFi(i);
                if (is_alive__8TObjBaseFv(pl) != 0) {
                    if (((TObjBase *)arg0)->get_room() == ((TObjBase *)pl)->get_room()) {
                        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                        ((TObjEneDD *)arg0)->update_velocity();
                        F(0x4BC, s32) = (u16)((s32)(TObjEneMorfos__data_80477610 * atan2_float(F(0x3A0, f32), F(0x3A8, f32))) + 0x8000);
                        if (check_value_in_range__13TObjEneMorfosFPvUsUsUs(arg0, old, F(0x60, s32), F(0x4BC, s32)) != 0) {
                            F(0x60, s32) = F(0x4BC, s32);
                            F(0x4B0, s32) = 2;
                            F(0xB8, s16) = 2;
                            break;
                        }
                    }
                }
            }
            if (F(0x4B0, s32) == 1 && check_value_in_range__13TObjEneMorfosFPvUsUsUs(arg0, old, F(0x60, s32), F(0x4C0, s32)) != 0) {
                F(0x4B0, s32) = 2;
                F(0xB8, s16) = 2;
            }
            break;
        }
        case 2:
            spawn_particle_effect(arg0 + 0x498, 0x212);
            if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneMorfos__data_805DF884) != 0) {
                F(0x4B0, s32) = 3;
            }
            break;
        case 3:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF88C) != 0) {
                play_sound_effect(0x4003AD24, (u32)(arg0 + 0x38), 0, 0);
                p = __nw__7TObjectFUl(0xFC);
                if (p != NULL) {
                    TObjEneMorfos__sub_80337824(p, arg0 + 0x498, (u16)(F(0x60, s32) + 0x8000), (s32)arg0);
                }
                F(0x4B0, s32) = 4;
            }
            break;
        case 4:
            if (((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) {
                F(0xB8, s16) = 0;
                F(0x4B4, s32) = F(0x4B4, s32) + 1;
                if (game_difficulty_selection == 3 || game_difficulty_selection == 2) {
                    if (F(0x4B4, s32) >= 5) {
                        F(0x4B0, s32) = 5;
                        break;
                    }
                } else if (F(0x4B4, s32) >= 4) {
                    F(0x4B0, s32) = 5;
                    break;
                }
                F(0x4C0, s32) = F(0x60, s32);
                F(0x60, s32) = F(0x60, s32) + D->f1C;
                F(0x4B0, s32) = 1;
            }
            break;
        }
        ((TObjEneDD *)arg0)->vfunc_102();
        ((TObjEneDD *)arg0)->vfunc_89();
        break;
    case 5:
        if (F(0x494, u32) != 0) {
            queue_destruction__7TObjectFv(F(0x494, void *));
            F(0x494, u32) = 0;
        }
        break;
    }
}
#pragma pop

void TObjEneMorfos__sub_80333690(TObjEneMorfos *arg0, s32 arg1) {
    u8 *temp_r3;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)arg0)->set_field_378(6);
        if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
            arg0->m_4bc = (s32) (u16) ((s32) (TObjEneMorfos__data_80477610 * atan2_float(arg0->m_3a0, *(f32 *)((s8 *)arg0 + 0x3A8))) + 0x8000);
            *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
            arg0->m_4b4 = 0;
            arg0->requested_action = 0;
            play_sound_effect(0x4003A528, (u32)((u8 *)arg0 + 0x38), 0, 0);
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x4B0) = 6;
        return;
    case 3:
        if (((s32) *(s32 *)((s8 *)arg0 + 0x4B0) == 6) && (((s32 (*)(void *))TObjEneMorfos__sub_803344F0)(arg0) == 0)) {
            transition_enemy_state__9TObjEneDDFl(arg0, 4);
        }
        break;
    case 5:
        break;
    case 0:
        ((s32 (*)(void))advance_animation_playback)();
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if (arg0->approach_value(arg0->m_4bc, *(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfos__param_table) + 0x1C)) != 0) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 1;
                arg0->requested_action = 2;
                spawn_particle_effect((u8 *)arg0 + 0x498, 0x212);
            }
            break;
        case 1:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)TObjEneMorfos__data_805DF884) != 0) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 2;
            }
            break;
        case 2:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF88C) != 0) {
                play_sound_effect(0x4003AD24, (u32)((u8 *)arg0 + 0x38), 0, 0);
                temp_r3 = (u8 *)(__nw__7TObjectFUl(0xFC));
                if (temp_r3 != NULL) {
                    TObjEneMorfos__sub_80337824(temp_r3, (u8 *)arg0 + 0x498, (s32) (u16) (arg0->m_4bc + 0x8000), (s32) arg0);
                }
                *(s32 *)((s8 *)arg0 + 0x4B0) = 3;
            }
            break;
        case 3:
            if (((s32 (*)(void *))get_flag_b4__9TObjEneDDFv)(arg0) != 0) {
                arg0->requested_action = 0;
                arg0->m_4b4 = (arg0->m_4b4 + 1);
                if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
                    if ((s32) arg0->m_4b4 >= 2) {
                        arg0->m_4bc = (s32) (TObjEneMorfos__data_80477610 * atan2_float(arg0->m_3a0, *(f32 *)((s8 *)arg0 + 0x3A8)));
                        *(s32 *)((s8 *)arg0 + 0x4B0) = 5;
                    } else {
                        arg0->requested_action = 0;
                        *(s32 *)((s8 *)arg0 + 0x4B0) = 4;
                        *(s32 *)((s8 *)arg0 + 0x4B8) = 0;
                    }
                } else if (arg0->select_target_in_view() != 0) {
                    ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                    ((TObjEneDD *)arg0)->update_velocity();
                    if ((s32) arg0->m_4b4 >= 2) {
                        arg0->m_4bc = (s32) (TObjEneMorfos__data_80477610 * atan2_float(arg0->m_3a0, *(f32 *)((s8 *)arg0 + 0x3A8)));
                        *(s32 *)((s8 *)arg0 + 0x4B0) = 5;
                        play_sound_effect(0x4003A528, (u32)((u8 *)arg0 + 0x38), 0, 0);
                    } else {
                        arg0->requested_action = 0;
                        *(s32 *)((s8 *)arg0 + 0x4B0) = 4;
                        *(s32 *)((s8 *)arg0 + 0x4B8) = 0;
                    }
                } else {
                    arg0->m_4bc = (s32) (u16) (arg0->m_4bc + 0x8000);
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 5;
                }
            }
            break;
        case 4:
            *(s32 *)((s8 *)arg0 + 0x4B8) = (s32) (*(s32 *)((s8 *)arg0 + 0x4B8) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x4B8) >= (s32) *(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfos__param_table) + 0x20)) {
                if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
                    ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                    ((TObjEneDD *)arg0)->update_velocity();
                    arg0->m_4bc = (s32) (u16) ((s32) (TObjEneMorfos__data_80477610 * atan2_float(arg0->m_3a0, *(f32 *)((s8 *)arg0 + 0x3A8))) + 0x8000);
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
                    play_sound_effect(0x4003A528, (u32)((u8 *)arg0 + 0x38), 0, 0);
                } else {
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 6;
                }
            }
            break;
        case 5:
            if (arg0->approach_value(arg0->m_4bc, *(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfos__param_table) + 0x1C)) != 0) {
                *(s32 *)((s8 *)arg0 + 0x4B0) = 6;
            }
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    }
}

void TObjEneMorfos__sub_80333AD0(u8 *ene_morfos, s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_morfos + 0xB8) = 0;
        ((TObjEneDD *)(ene_morfos))->vfunc_96();
        *(s32 *)((s8 *)ene_morfos + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_morfos + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)ene_morfos)->set_field_378(4);
        *(s32 *)((s8 *)ene_morfos + 0x4B0) = 0;
        *(s32 *)((s8 *)ene_morfos + 0x4BC) = 0;
        *(s32 *)((s8 *)ene_morfos + 0x4B4) = 0;
        *(f32 *)((s8 *)ene_morfos + 0x4C4) = (f32) TObjEneMorfos__data_805DF874;
        *(f32 *)((s8 *)ene_morfos + 0x4CC) = (f32) TObjEneMorfos__data_805DF874;
        *(f32 *)((s8 *)ene_morfos + 0x4D0) = (f32) TObjEneMorfos__data_805DF874;
        *(f32 *)((s8 *)ene_morfos + 0x4D4) = (f32) TObjEneMorfos__data_805DF874;
        return;
    case 3:
        if (TObjEneMorfos__sub_803344F0(ene_morfos) == 0) {
            if ((u32) *(u32 *)((s8 *)ene_morfos + 0x390) == 0U) {
                transition_enemy_state__9TObjEneDDFl(ene_morfos, 7);
            } else if (*(f32 *)((s8 *)ene_morfos + 0x3AC) <= lbl_805DF87C) {
                if (((f32 (*)(void *)) random_ratio__9TObjCharaFv)(ene_morfos) < lbl_805DF890) {
                    transition_enemy_state__9TObjEneDDFl(ene_morfos, 6);
                } else {
                    transition_enemy_state__9TObjEneDDFl(ene_morfos, 5);
                }
            } else if ((s32) *(s32 *)((s8 *)ene_morfos + 0x4B4) == 3) {
                transition_enemy_state__9TObjEneDDFl(ene_morfos, 6);
            }
        }
        break;
    case 5:
        break;
    case 0:
        ((s32 (*)(void)) advance_animation_playback)();
        ((TObjEneMorfos *)ene_morfos)->play_sound_in_band();
        if (((s32 (*)(void *, f32)) update_linked_position__12TObjEneDD_STFf)(ene_morfos, TObjEneMorfos__data_805DF86C) != 0) {
            ((TObjEneDD_ST *)ene_morfos)->enemy_copy_target_destination();
            ((TObjEneDD *)ene_morfos)->update_velocity();
        }
        switch (*(s32 *)((s8 *)ene_morfos + 0x4B4)) {
        case 0:
            if (((TObjEneDD_ST *)ene_morfos)->enemy_has_live_target() != 0) {
                *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) (u16) (s32) (TObjEneMorfos__data_80477610 * ((f64 (*)(f32, f32)) atan2_float)((f32) (*(f32 *)((s8 *)ene_morfos + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_morfos + 0x3A8))));
            } else {
                *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) *(s32 *)((s8 *)ene_morfos + 0x60);
            }
            *(s32 *)((s8 *)ene_morfos + 0x4B4) = 1;
        case 1:
            if (((TObjEneMorfos *)ene_morfos)->approach_value((s32)((int) (*(s32 *)((s8 *)ene_morfos + 0x4BC))), (s32)((int) (*(s32 *)((s8 *)((u8 *) TObjEneMorfos__param_table) + 0x18)))) != 0) {
                *(s32 *)((s8 *)ene_morfos + 0x4B4) = 2;
                *(f32 *)((s8 *)ene_morfos + 0x4CC) = sin_table_lookup((int) (*(s32 *)((s8 *)ene_morfos + 0x60)));
                *(f32 *)((s8 *)ene_morfos + 0x4D4) = cos_table_lookup((int) (*(s32 *)((s8 *)ene_morfos + 0x60)));
            }
            ((TObjEneDD *)(ene_morfos))->vfunc_102();
            break;
        case 2:
            if (TObjEneDD::check_v2_mode() != 0) {
                if (((TObjEneMorfos *)ene_morfos)->select_target_in_view() != 0) {
                    ((TObjEneDD_ST *)ene_morfos)->enemy_copy_target_destination();
                    ((TObjEneDD *)ene_morfos)->update_velocity();
                    *(s32 *)((s8 *)ene_morfos + 0x4B4) = 3;
                } else if (((TObjEneDD_ST *)ene_morfos)->enemy_has_live_target() != 0) {
                    *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) (u16) (s32) (TObjEneMorfos__data_80477610 * ((f64 (*)(f32, f32)) atan2_float)((f32) (*(f32 *)((s8 *)ene_morfos + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_morfos + 0x3A8))));
                } else {
                    *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) *(s32 *)((s8 *)ene_morfos + 0x60);
                }
                ((TObjEneMorfos *)ene_morfos)->approach_value((s32)((int) (*(s32 *)((s8 *)ene_morfos + 0x4BC))), (s32)((int) (*(s32 *)((s8 *)((u8 *) TObjEneMorfos__param_table) + 0x18))));
            } else {
                *(f32 *)((s8 *)ene_morfos + 0x4C4) = (f32) (*(f32 *)((s8 *)ene_morfos + 0x4C4) + *(f32 *)((s8 *)ene_morfos + 0x3D8));
                if (*(f32 *)((s8 *)ene_morfos + 0x4C4) >= *(f32 *)((s8 *)ene_morfos + 0x3DC)) {
                    *(f32 *)((s8 *)ene_morfos + 0x4C4) = (f32) TObjEneMorfos__data_805DF874;
                    *(s32 *)((s8 *)ene_morfos + 0x4B0) = (s32) (*(s32 *)((s8 *)ene_morfos + 0x4B0) + 1);
                    if (((s32) *(s32 *)((s8 *)ene_morfos + 0x4B0) >= 2) && (((TObjEneMorfos *)ene_morfos)->select_target_in_view() != 0)) {
                        *(s32 *)((s8 *)ene_morfos + 0x4B0) = 0;
                        ((TObjEneDD_ST *)ene_morfos)->enemy_copy_target_destination();
                        ((TObjEneDD *)ene_morfos)->update_velocity();
                        *(s32 *)((s8 *)ene_morfos + 0x4B4) = 3;
                    } else {
                        *(s32 *)((s8 *)ene_morfos + 0x4B4) = 0;
                    }
                }
                if ((s32) *(s32 *)((s8 *)ene_morfos + 0x3E8) == 1) {
                    ((TObjEneDD *)ene_morfos)->move_clamped_on_ground((f32) (*(f32 *)((s8 *)ene_morfos + 0x4CC)), (f32) (*(f32 *)((s8 *)ene_morfos + 0x4D4)), (f32) (*(f32 *)((s8 *)ene_morfos + 0x3D8)));
                }
            }
            break;
        }
        ((TObjEneDD *)(ene_morfos))->vfunc_89();
        break;
    }
}

void TObjEneMorfos__sub_80333E48(u8 *ene_dd_st, s32 arg1) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r31;

    switch (arg1) {
    case 4:
        ((TObjEneDD_ST *)ene_dd_st)->requested_action = 0;
        ((TObjEneDD *)(ene_dd_st))->vfunc_95();
        *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)ene_dd_st)->set_field_378(7);
        *(s32 *)((s8 *)ene_dd_st + 0x4B0) = 0;
        *(s32 *)((s8 *)ene_dd_st + 0x4B4) = 0;
        return;
    case 3:
        if (TObjEneMorfos__sub_803344F0(ene_dd_st) == 0) {
            temp_r0 = *(s32 *)((s8 *)ene_dd_st + 0x4B0);
            if (temp_r0 == 2) {
                transition_enemy_state__9TObjEneDDFl(ene_dd_st, 4);
            } else if (temp_r0 == 3) {
                transition_enemy_state__9TObjEneDDFl(ene_dd_st, 2);
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(ene_dd_st);
        temp_r0_2 = *(s32 *)((s8 *)ene_dd_st + 0x4B0);
        switch (temp_r0_2) {
        case 0:
            if (((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(ene_dd_st, TObjEneMorfos__data_805DF86C) != 0) {
                ((TObjEneDD_ST *)ene_dd_st)->enemy_copy_target_destination();
                ((TObjEneDD *)ene_dd_st)->update_velocity();
                *(s32 *)((s8 *)ene_dd_st + 0x4B0) = 2;
            } else {
                *(s32 *)((s8 *)ene_dd_st + 0x4B4) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x4B4) + 1);
                if ((s32) *(s32 *)((s8 *)ene_dd_st + 0x4B4) > 0x3C) {
                    *(s32 *)((s8 *)ene_dd_st + 0x4B4) = 0;
                    *(s32 *)((s8 *)ene_dd_st + 0x4B0) = 1;
                    ((VObj_14_80333E48 *)(ene_dd_st + (1004)))->m2();
                    ((VObj_14_80333E48 *)(ene_dd_st + (1032)))->m2();
                    *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) | 2);
                }
            }
            break;
        case 1:
            temp_r31 = ((VObj_14_80333E48 *)(ene_dd_st + (1032)))->m4();
            if ((((VObj_14_80333E48 *)(ene_dd_st + (1004)))->m4() != 0) && (temp_r31 != 0)) {
                *(s32 *)((s8 *)ene_dd_st + 0x4B0) = 3;
            }
            break;
        }
        ((TObjEneDD *)(ene_dd_st))->vfunc_102();
        ((TObjEneDD *)(ene_dd_st))->vfunc_89();
        break;
    }
}

void TObjEneMorfos__sub_80334030(u8 *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & 0xFFFFFFF9);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) | 1);
        ((TObjEneDD *)ene_dd)->set_field_378(2);
        VecCopy((Vec *)(ene_dd + 0x38), (const Vec *)(ene_dd + 0x50));
        VecCopy((Vec *)(ene_dd + 0x44), (const Vec *)(ene_dd + 0x38));
        VecCopy((Vec *)(ene_dd + 0x2FC), (const Vec *)(ene_dd + 0x38));
        ((VObj_14_2f517b *)(ene_dd + (1004)))->m2();
        ((VObj_14_2f517b *)(ene_dd + (1032)))->m2();
        return;
    case 3:
        if (update_linked_position__12TObjEneDD_STFf(TObjEneMorfos__data_805DF86C) != 0) {
            transition_enemy_state__9TObjEneDDFl(ene_dd, 1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMorfos::state_appear(s32 arg1) {

    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->vfunc_95();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF8);
        set_field_378(4);
        *(s32 *)((s8 *)this + 0x3D4) = 0;
        *(s32 *)((s8 *)this + 0x4B0) = 0;
        this->m_4c4 = (f32) TObjEneMorfos__data_805DF874;
        return;
    case 3:
        if (((s32) *(s32 *)((s8 *)this + 0x4B0) == 2) && (TObjEneMorfos__sub_803344F0(this) == 0)) {
            transition_enemy_state__9TObjEneDDFl(this, 4);
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)this + 0x4B0)) {
        case 0:
            if (update_linked_position__12TObjEneDD_STFf(TObjEneMorfos__data_805DF86C) != 0) {
                *(s32 *)((s8 *)this + 0x4B0) = 1;
                enemy_copy_target_destination();
                update_velocity();
            }
            break;
        case 1:
            this->m_4c4 = (f32) (this->m_4c4 + lbl_805DF894);
            *(s32 *)((s8 *)this + 0x3D4) = (s32) get_random_float__21TObjEneMe3ShinowaRealFv(this->m_4c4);
            if ((s32) *(s32 *)((s8 *)this + 0x3D4) >= 0xC) {
                *(s32 *)((s8 *)this + 0x3D4) = 0xC;
                *(s32 *)((s8 *)this + 0x4B0) = 2;
            }
            TObjPlayer::play_effect_if_v2(-0x100);
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        return;
    case 5:
        *(s32 *)((s8 *)this + 0x3D4) = 0xC;
        this->vfunc_96();
        break;
    }
}

void TObjEneMorfos__sub_803342B8(u8 *ene_dd, s32 arg1) {
    s32 temp_r31;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & ~5);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) | 2);
        ((TObjEneDD *)ene_dd)->set_field_378(3);
        TObjPlayer__sub_800A0554(ene_dd + 0x3EC);
        TObjEneMe3SinowZoa__sub_800D758C(ene_dd + 0x408);
        ((TBoss3Volopt *)(ene_dd + 0x38))->play_area_se_with_particle();
        return;
    case 3:
        temp_r31 = ((VObj_14_948132 *)(ene_dd + (1032)))->m5();
        if ((((VObj_14_948132 *)(ene_dd + (1004)))->m5() != 0) && (temp_r31 != 0)) {
            transition_enemy_state__9TObjEneDDFl(ene_dd, 3);
        }
        return;
    case 0:
        advance_animation_playback(ene_dd);
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        ((TObjEneDD *)(ene_dd))->vfunc_88();
        return;
    case 5:
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & 0xFFFFFFFD);
        break;
    }
}

void TObjEneMorfos::handle_event_transition(s32 ev) {
    switch (ev) {
    case 0:
        return;
    case 3:
        transition_enemy_state__9TObjEneDDFl(this, 1);
        break;
    }
}

void TObjEneMorfos__vt85(u8 *ene_morfos, u32 arg1, s32 ev) {
    switch (arg1) {
    case 0: ((TObjEneMorfos *)ene_morfos)->handle_event_transition(ev); break;
    case 1: TObjEneMorfos__sub_803342B8(ene_morfos, ev); break;
    case 3: ((TObjEneMorfos *)ene_morfos)->state_appear(ev); break;
    case 2: TObjEneMorfos__sub_80334030(ene_morfos, ev); break;
    case 7: TObjEneMorfos__sub_80333E48(ene_morfos, ev); break;
    case 4: TObjEneMorfos__sub_80333AD0(ene_morfos, ev); break;
    case 5: TObjEneMorfos__sub_80332FD4((TObjEneMorfos *)ene_morfos, ev); break;
    case 6: TObjEneMorfos__sub_80333690((TObjEneMorfos *)ene_morfos, ev); break;
    case 9: ((TObjEneMorfos *)ene_morfos)->state_rotating_projectile_burst(ev); break;
    case 8: ((TObjEneMorfos *)ene_morfos)->state_patrol(ev); break;
    case 10: TObjEneMorfos__sub_80332DBC(ene_morfos, ev); break;
    case 11: ((TObjEneMorfos *)ene_morfos)->state_death(ev); break;
    }
}

s32 TObjEneMorfos__sub_803344F0(void *arg0) {
    struct VObj_803344F0 *o = (struct VObj_803344F0 *)arg0;
    return o->m97() ? 1 : 0;
}

void TObjEneMorfos::play_sound_in_band() {
    u8 *arg0 = (u8 *)this;
    if ((((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF898) != 0) || (((TObjMotion *)arg0)->is_passing_frame((f32)((f32)TObjEneMorfos__data_805DF89C)) != 0)) {
        play_sound_effect(0x4003A823, (u32)(arg0 + 0x38), 0, 0);
    }
}

#pragma push
#pragma fp_contract on
s32 TObjEneMorfos::select_target_in_view() {
    V3_80334588 v;
    s32 n;
    u8 *p;
    u16 id;
    s32 i;
    f32 dz;
    f32 dx;
    f32 cosLim;
    f32 d;
    f32 best;
    O_80334588 *arg0 = (O_80334588 *)this;
    best = TObjEneMorfos__data_805DF874;
    id = 0xFFFF;
    cosLim = cos_table_lookup(0xAAA);
    dx = sin_table_lookup(arg0->f60);
    dz = cos_table_lookup(arg0->f60);
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = get_player_data__10TObjPlayerFi(i);
        if (is_alive__8TObjBaseFv(p) == 0) {
            continue;
        }
        VecCopy((Vec *)&v, (const Vec *)(p + 0x38));
        subtract_vector(&v, &arg0->pos);
        v.y = TObjEneMorfos__data_805DF874;
        d = normalize_vector_xz((Vec *)(&v));
        if (d < TObjEneMorfos__data_805DF86C && d > best && dx * v.x + dz * v.z > cosLim &&
            csnLookAt(&arg0->pos, p + 0x2FC) == 0) {
            id = get_entity_id(p);
            best = d;
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(arg0, id);
        return 1;
    }
    return 0;
}
#pragma pop

int TObjEneMorfos__sub_80334704(void) { morfos_projectile_speed = *(float*)((char*)TObjEneMorfos__param_table + 0x0); morfos_param_table_speed_copy = *(float*)((char*)TObjEneMorfos__param_table + 0x4); return TObjEneMorfos__param_table; }

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneMorfos::init_target_offsets() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x368) <= 0) {
        *(s32 *)((s8 *)arg0 + 0x3E8) = 1;
    } else {
        *(s32 *)((s8 *)arg0 + 0x3E8) = 0;
    }
    *(f32 *)((s8 *)arg0 + 0x3D8) = (f32) (lbl_805DF8A0 + *(f32 *)((s8 *)arg0 + 0x354));
    if (*(f32 *)((s8 *)arg0 + 0x3D8) < lbl_805DF8A4) {
        *(f32 *)((s8 *)arg0 + 0x3D8) = (f32) lbl_805DF8A4;
    }
    *(f32 *)((s8 *)arg0 + 0x3DC) = (f32) (TObjEneMorfos__data_805DF89C + *(f32 *)((s8 *)arg0 + 0x358));
    if (*(f32 *)((s8 *)arg0 + 0x3DC) < lbl_805DF888) {
        *(f32 *)((s8 *)arg0 + 0x3DC) = (f32) lbl_805DF888;
    }
    *(f32 *)((s8 *)arg0 + 0x3E0) = (f32) (lbl_805DF8A4 + *(f32 *)((s8 *)arg0 + 0x35C));
    *(f32 *)((s8 *)arg0 + 0x3E4) = (f32) (lbl_805DF8A4 + *(f32 *)((s8 *)arg0 + 0x360));
}
#pragma pop

void TObjEneMorfos::vfunc_88() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (this->m_300 - *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneMorfos::set_hover_target_position() {
    u8 *arg0 = (u8 *)this;
    this->m_2fc = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->m_300 = (f32) (TObjEneMorfos__data_805DF89C + *(f32 *)((s8 *)arg0 + 0x3C));
    this->m_304 = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x2FC));
}

s32 TObjEneMorfos::approach_value(s32 arg1, s32 arg2) {
    s32 temp_r3;
    s32 var_r31;

    var_r31 = 0;
    temp_r3 = angle_diff_s16(this->rotation_y);
    if (temp_r3 > arg2) {
        this->rotation_y = (s32) (this->rotation_y + arg2);
    } else if (temp_r3 < (s32) -arg2) {
        this->rotation_y = (s32) (this->rotation_y - arg2);
    } else {
        this->rotation_y = arg1;
        var_r31 = 1;
    }
    return var_r31;
}

s32 TObjEneMorfos::try_enter_low_hp_state() {
    u8 *arg0 = (u8 *)this;
    if (((s16) *(s16 *)((s8 *)arg0 + 0x32C) <= (s32) ((s16) *(s16 *)((s8 *)arg0 + 0x2B8) / 2)) && (random_ratio__9TObjCharaFv((s32) arg0) <= *(f32 *)((s8 *)arg0 + 0x3E4))) {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(arg0, (void*)(9));
        return 1;
    }
    return 0;
}

s32 TObjEneMorfos::check_low_hp_trigger() {
    u8 *arg0 = (u8 *)this;
    if (!(*(s32 *)((s8 *)arg0 + 0x3C0) & 0x10) && ((s16) *(s16 *)((s8 *)arg0 + 0x32C) <= (s32) ((s16) *(s16 *)((s8 *)arg0 + 0x2B8) / 2)) && (random_ratio__9TObjCharaFv((s32) arg0) <= *(f32 *)((s8 *)arg0 + 0x3E0))) {
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 0x10);
        return 1;
    }
    return 0;
}

void TObjEneMorfos::vfunc_61() {  }

void TObjEneMorfos::vfunc_62() {
    Obj_8033496C *arg0 = (Obj_8033496C *)this;
    Vec_8033496C v;
    Pl_8033496C *pl;
    s32 d;
    if (this->mode == 0xA) {
        return;
    }
    pl = get_player_by_client_id(this->m_2d4);
    if (pl != 0) {
        VecCopy((Vec *)&v, (const Vec *)&pl->pos);
        subtract_vector(&v, &arg0->pos);
        d = angle_difference_abs(this->rotation_y, (s32)(TObjEneMorfos__data_80477610 * atan2_float(v.x, v.z)));
    } else {
        d = 0;
    }
    if (d < 0x4000) {
        ((void (*)(void *))clear_attack_receipts__9TObjEneDDFv)(arg0);
        if (((TObjEneMorfos *)arg0)->check_low_hp_trigger() == 0) {
            ((TObjEneMorfos *)arg0)->try_enter_low_hp_state();
        }
    } else if (arg0->f3C0 & 4) {
        ((void (*)(void *))clear_attack_receipts__9TObjEneDDFv)(arg0);
    } else {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(arg0, (void *)0xA);
    }
}

f32 TObjEneMorfos__vt20(Obj_80334A4C *arg0, Obj_80334A4C *att, f32 scale) {
    Vec_80334A4C v;
    f32 ret = TObjEneMorfos__data_805DF874;
    s32 d;
    if (att != 0) {
        VecCopy((Vec *)&v, (const Vec *)&att->pos);
        subtract_vector(&v, &arg0->pos);
        d = angle_difference_abs(arg0->f60, (s32)(TObjEneMorfos__data_80477610 * atan2_float(v.x, v.z)));
    } else {
        d = 0;
    }
    if (arg0->f3C0 & 0x10) {
        if (d < 0x4000) {
            spawn_particle_effect(arg0->snd, 0x214);
            spawn_particle_effect(arg0->snd, 0x21A);
        } else {
            arg0->f3C0 &= ~0x10;
            arg0->f3C0 |= 0x20;
            ret = receive_physical_attack__9TObjCharaFPvf(arg0, att, scale);
        }
    } else {
        ret = receive_physical_attack__9TObjCharaFPvf(arg0, att, scale);
    }
    return ret;
}

void TObjEneMorfos::vfunc_63() { if (this->mode != 11) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFl)(this, (void*)11); } }

void TObjEneMorfos::vfunc_28() {  }

void run_task__13TObjEneMorfosFv(u8 *arg0) {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneMorfos *)(arg0))->vfunc_106();
        return;
    }
    if (((TObjEneMorfos *)(arg0))->vfunc_83() != 4) {
        ((TObjEneMorfos *)(arg0))->vfunc_85();
        if ((s32) lbl_805D6D28 != (s32) actor_frame_tick) {
            lbl_805D6D28 = actor_frame_tick;
            TObjPlayer__sub_8023DEE0((s16 *)lbl_805D6D20, (s16)((s16) *(s32 *)((s8 *)arg0 + 0x3D4)), (s16)(0), (u16)(2U));
        }
        if ((s32) lbl_805D6D2C != (s32) actor_frame_tick) {
            lbl_805D6D2C = actor_frame_tick;
            TObjPlayer__sub_8023DEE0((s16 *)lbl_805D6D24, (s16)(0), (s16) ((f32) *(s32 *)((s8 *)arg0 + 0x3D4) * lbl_805DF894), (u16)(0U));
        }
    }
    ((TObjEneMorfos *)arg0)->set_hover_target_position();
    ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
    ((TObjEneMorfos *)(arg0))->vfunc_100();
    ((TObjEneMorfos *)arg0)->update_ground_probe();
}

u8 *__dt__13TObjEneMorfosFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80334CC8___vt__13TObjEneMorfos *)__vt__13TObjEneMorfos).value;
        if ((u32) *(u32 *)((s8 *)arg0 + 0x494) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x494));
            *(u32 *)((s8 *)arg0 + 0x494) = 0U;
        }
        free_collision_body_parts(arg0);
        __destroy_arr(arg0 + 0x424, &__dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__13TUnk_80494938Fv((arg0 + 0x408), -1);
        __dt__13TUnk_80490470Fv((arg0 + 0x3EC), -1);
        __dt__12TObjEneDD_STFv((arg0), 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

struct VBase_14_80334D74 { char pad[0x14]; };
struct VSub_80334D74 : VBase_14_80334D74 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};
struct VBase_18_80334D74 { char pad[0x18]; };
struct VObj_80334D74 : VBase_18_80334D74 {
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
    virtual void m85(s16, s32);
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
};
struct Elem_80334D74 { u8 pad[0x1C]; };
struct Arr_80334D74 { u8 pad[0x424]; Elem_80334D74 e[4]; };
struct Hdr_80334D74 { u8 b[0x1C]; };
struct Res_80334D74 { u8 pad[0x18]; s32 f18; s32 f1C; };
struct Mgr_80334D74 { u8 pad[0x42C]; Res_80334D74 *res; s32 f430; };
void reset_hp__9TObjEneDDFv(void *, s32, s32, s32);
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);
extern s32 lbl_804774A8[];
extern s32 lbl_804774B0[];
extern s32 lbl_804774B8[];
extern s32 lbl_805434DC[];
extern s32 lbl_805D6D08[1];
extern s32 lbl_805D6D0C[1];
extern const f32 lbl_805DF8A8;
void TObjEneMorfos::init_instance() {
    s32 i;

    init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = ((Mgr_80334D74 *)TObjEneMorfos__instance)->res->f18;
    this->texlist = ((Mgr_80334D74 *)TObjEneMorfos__instance)->res->f1C;
    init_model__9TObjEneDDFv(this, lbl_804EE0DC, 1);
    set_field_d8((s32)morfos_motion_param_table);
    set_field_dc(((Mgr_80334D74 *)TObjEneMorfos__instance)->f430);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    reset_hp__9TObjEneDDFv(this, lbl_805D6D08[lbl_804774A8[0]], lbl_805434DC[lbl_804774B0[0]], lbl_805D6D0C[lbl_804774B8[0]]);
    ((void (*)(void *))TObjEneMorfos__sub_80334704)(this);
    set_state_8();
    this->movementParameters = (Hdr_80334D74 *)lbl_804EE0C0;
    initialize_enemy_state__9TObjEneDDFv(this, 0x42);
    *(f32 *)((s8 *)this + 0x37C) = lbl_805DF8A8;
    enemy_init_acquire_period(0x3C);
    enemy_init_validate_period(0x3C);
    *(s32 *)((s8 *)this + 0x3C0) = 0;
    *(s32 *)((s8 *)this + 0x3C4) = 0;
    VecCopy((Vec *)((u8 *)this + 0x3C8), (const Vec *)((u8 *)this + 0x38));
    *(s32 *)((s8 *)this + 0x3D4) = 0;
    ((VSub_80334D74 *)((u8 *)this + 0x3EC))->m2();
    ((VSub_80334D74 *)((u8 *)this + 0x408))->m2();
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&((Arr_80334D74 *)this)->e[i]))->activate_and_dispatch();
    }
    *(f32 *)((s8 *)this + 0x498) = TObjEneMorfos__data_805DF874;
    this->m_49c = TObjEneMorfos__data_805DF874;
    *(f32 *)((s8 *)this + 0x4A0) = TObjEneMorfos__data_805DF874;
    this->m_4a4 = TObjEneMorfos__data_805DF874;
    *(f32 *)((s8 *)this + 0x4A8) = TObjEneMorfos__data_805DF874;
    this->m_4ac = TObjEneMorfos__data_805DF874;
    *(s32 *)((s8 *)this + 0x4B0) = 0;
    this->m_4b4 = 0;
    this->m_4bc = 0;
    *(s32 *)((s8 *)this + 0x4C0) = 0;
    this->m_4c4 = TObjEneMorfos__data_805DF874;
    *(f32 *)((s8 *)this + 0x4C8) = TObjEneMorfos__data_805DF874;
    this->m_4cc = TObjEneMorfos__data_805DF874;
    *(f32 *)((s8 *)this + 0x4D0) = TObjEneMorfos__data_805DF874;
    this->m_4d4 = TObjEneMorfos__data_805DF874;
    this->vfunc_95();
    this->mode = 0;
    ((VObj_80334D74 *)this)->m85(this->mode, 4);
}
void *TObjEneMorfos__ct(void *ene_morfos, void *arg1, void *arg2) {
    __ct__12TObjEneDD_STFP7TObject(ene_morfos);
    *(s32 **)((s8 *)ene_morfos + 0x18) = __vt__13TObjEneMorfos;
    __ct__13TUnk_80490470Fv(((char *)ene_morfos + 1004));
    __ct__13TUnk_80494938Fv(((char *)ene_morfos + 1032));
    __construct_array((void *)((char *)ene_morfos + 1060), __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 28, 4);
    *(void * *)&((TObjEneMorfos *)ene_morfos)->m_name = morfos_class_name;
    invoke_initialization_hook__9TObjEneDDFv(ene_morfos, arg2);
    ((TObjEneMorfos *)ene_morfos)->init_target_offsets();
    ((TObjEneMorfos *)ene_morfos)->init_instance();
    *(u32 *)((s8 *)ene_morfos + 0x494) = 0;
    return ene_morfos;
}

void TObjEneMorfos::unload_static_data() {
    TObjEneMorfosArm__sub_8033542C();
    if ((u32) (*(u32 *)&TObjEneMorfos__instance) != 0U) {
        TLobby__sub_8001FE7C((void*)(*(u32 *)&TObjEneMorfos__instance), 1);
        (*(u32 *)&TObjEneMorfos__instance) = 0U;
    }
}

void *TObjEneMorfos::create() {
    void *o = __nw__7TObjectFUl(0x4D8);
    if (o != NULL) {
        o = TObjEneMorfos__ct(o, tl_04, this);
    }
    return o;
}

struct ModelRes_803350AC {
    u8 pad[0x18];
    u8 *f18;
    u8 *f1C;
    u8 pad20[0x8];
    u8 *f28;
};

struct ResMgr_803350AC {
    u8 pad[0x42C];
    ModelRes_803350AC *res;
    s32 f430;
};

struct SpawnDesc_803350AC {
    s32 w[4];
};

s32 load_enemy_bml_resource(u8 *desc);
extern f32 lbl_805434D0[3];
extern const s32 lbl_805DF860[1];
extern const s32 lbl_805DF864[1];
extern const s32 lbl_805DF868[1];
extern const s32 lbl_804774A0[2];
extern const SpawnDesc_803350AC lbl_804775C8;
void TObjEneMorfos__sub_803350AC(void);

void TObjEneMorfos__sub_803350AC(void) {
    ResMgr_803350AC *mgr;
    s32 i;

    if (is_split_screen() != 0) {
        mgr = (ResMgr_803350AC *)load_enemy_bml_resource((u8 *)bm_ene_morfos_low_resource_descriptor);
    } else {
        mgr = (ResMgr_803350AC *)load_enemy_bml_resource((u8 *)morfos_resource_descriptor);
    }
    TObjEneMorfos__instance = (int)mgr;
    lbl_805434D0[0] = TObjEneMorfos__data_805DF874;
    lbl_805434D0[1] = TObjEneMorfos__data_805DF874;
    lbl_805434D0[2] = TObjEneMorfos__data_805DF874;
    TObjEneMorfos__phase = 0;
    TObjEneMorfos__camera_path_cursor = 0;
    lbl_805D6D20 = *(u8 **)(*(u8 **)(*(u8 **)(mgr->res->f18 + 0x2C) + 4) + 4);
    lbl_805D6D24 = *(u8 **)(*(u8 **)(mgr->res->f28 + 4) + 4);
    lbl_805D6D28 = 0;
    lbl_805D6D2C = 0;
    for (i = 0; i < 1; i++) {
        lbl_805D6D08[i] = (s32)TLobby::register_boss(lbl_805DF860[i]);
    }
    for (i = 0; i < 2; i++) {
        lbl_805434DC[i] = (s32)TLobby::dispatch_shared_handler_b(lbl_804774A0[i]);
    }
    for (i = 0; i < 1; i++) {
        lbl_805D6D0C[i] = (s32)TLobby::register_object(lbl_805DF864[i]);
    }
    for (i = 0; i < 1; i++) {
        (&TObjEneMorfos__param_table)[i] = (int)TLobby::dispatch_shared_handler_a(lbl_805DF868[i]);
    }
    TObjEneMorfosArm::init_global();
    {
        SpawnDesc_803350AC desc = lbl_804775C8;
        desc.w[0] = ((ResMgr_803350AC *)TObjEneMorfos__instance)->f430;
        TLobby::spawn_npc_enemy(0x4D, (s32)((ResMgr_803350AC *)TObjEneMorfos__instance)->res->f18,
                                (s32)((ResMgr_803350AC *)TObjEneMorfos__instance)->res->f1C, (s32)&desc,
                                lbl_805DF880, TObjEneMorfos__data_805DF874);
    }
}
}
