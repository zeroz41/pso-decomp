#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/boss/TBoss5Gryphon.h"
#include "pso/boss/TBoss5GryphonSnarl.h"
#include "pso/TBoss5GryphonDemo.h"
#include "pso/system/vector.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"

#include <stddef.h>
#include "pso/TObjBoss5Ctrl.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

struct Fade_800653C4 { char b[0x1C]; };

struct Dragon_800653C4 { char pad[0x580]; Fade_800653C4 fade[4]; };

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
    virtual s32 m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual s32 m39();
    virtual s32 m40();
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
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_8006426C { f32 x, y, z; };

struct Obj_8006426C {
    u8 pad0[0x3c0];
    Vec_8006426C a;
    u8 pad3cc[0x444 - 0x3cc];
    Vec_8006426C b;
    u8 pad450[0x578 - 0x450];
    s32 f578;
};

struct Vec_8006442C { f32 x, y, z; };

struct Fx_8006442C { u8 pad0[8]; f32 scale; u8 padC[8]; };

struct Dragon_8006442C {
    u8 pad0[0x3E4];
    Vec_8006442C a, b, c, d;
    Vec_8006442C e, f, g, h;
    u8 pad444[0x578 - 0x444];
    s32 f578;
};

typedef struct Vec_80063088 {
    f32 x, y, z;
} Vec_80063088;

typedef struct Res_80063088 {
    u8 pad0[0xC];
    s32 fC;
    s32 f10;
} Res_80063088;

struct VBase_80063088 { char pad[0x18]; };

struct Obj_80063088 : VBase_80063088 {
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
    u8 pad1C[0x60 - 0x1C];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x38C - 0xBA];
    u16 f38C;
    u8 pad38E[0x394 - 0x38E];
    f32 f394;
    f32 f398;
    f32 f39C;
    u8 pad3A0[0x444 - 0x3A0];
    Vec_80063088 fxPos;
    u8 pad450[0x490 - 0x450];
    s32 f490;
    u8 pad494[0x4C4 - 0x494];
    u8 f4C4[0x5F0 - 0x4C4];
    Res_80063088 *res;
    u8 pad5F4[0x6DC - 0x5F4];
    s32 state;
    s32 f6E0;
    u8 pad6E4[0x724 - 0x6E4];
    void *fx;
};

struct Vec_8005E594 { f32 x, y, z; };

struct Fx_8005E594 { u8 pad[0x14]; s32 f14; };

struct Hit2_8005E594 { u8 pad[4]; f32 y; };

struct Hit_8005E594 { u8 pad[4]; Hit2_8005E594 *p; };

struct Obj_8005E594 {
    u8 pad0[0x3E4];
    Vec_8005E594 cp[8];
    u8 pad444[0x5F0 - 0x444];
    Fx_8005E594 *fx;
    u8 pad5f4[0x734 - 0x5F4];
    void *parts[16];
};

struct VBase_18_81e212 { char pad[0x18]; };

struct VObj_18_81e212 : VBase_18_81e212 {
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
    virtual s32 m72(s32);
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

struct Vec_80062BA0 { f32 x, y, z; };

struct Cam_80062BA0 { s8 a; s8 b; s16 c; f32 d; f32 e; };

struct Part_80064F50 { u8 pad0[4]; f32 f4; u8 pad8[4]; f32 fC; u8 pad10[8]; u32 flags; u8 pad1C[4]; f32 f20; u8 pad24[4]; f32 f28; };

struct Cfg_80064F50 { u8 pad[0x18]; s32 i18; s32 i1C; s32 i20; s32 i24; };

struct Obj_80064F50 { u8 pad0[0xA4]; Part_80064F50 *parts; u8 padA8[0x4C0 - 0xA8]; u32 flags4C0; u8 pad4C4[0x4E4 - 0x4C4]; s32 mode4E4; u8 pos4E8[4]; };

struct Vec_80060020 { f32 x, y, z; };

struct Hit2_80060020 { u8 pad[4]; f32 y; };

struct Hit_80060020 { u8 pad[4]; Hit2_80060020 *p; };

struct Cfg_80060020 { s16 h0; s16 h2; s32 f4; };

struct Fx_80060020 { u8 pad[4]; s32 f4; };

struct ObjBase_80060020 { char pad[0x18]; };

struct Obj_80060020 : ObjBase_80060020 {
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

struct Dragon_80060020 : Obj_80060020 {
    u8 pad1c[0x38 - 0x1C];
    Vec_80060020 pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[0xB8 - 0x68];
    s16 fB8;
    u8 padba[0x4BC - 0xBA];
    Cfg_80060020 *f4BC;
    u32 f4C0;
    u8 pad4c4[0x5F0 - 0x4C4];
    Fx_80060020 *f5F0;
    u8 f5F4[0x6DC - 0x5F4];
    s32 f6DC;
    s32 f6E0;
    u8 pad6e4[0x6E8 - 0x6E4];
    s32 f6E8;
    u8 pad6ec[0x6F4 - 0x6EC];
    f32 f6F4;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct GA_80063FB8 { s32 value; u8 remaining[0x10]; };

struct GB_80063FB8 { s32 value; u8 remaining[0x8]; };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct GA_800640A4 { s32 value; u8 remaining[0x10]; };

struct GB_800640A4 { s32 value; u8 remaining[0x8]; };

extern "C" {
int VecCopy__FP3VecPC3Vec(void*, void*);
void queue_destruction__7TObjectFv(void *);
s32 get_flag_bit6__12TBoss8DragonFv();
void TBoss8Dragon__sub_8005FB90(u8 *arg0);
int check_demo_mode__10TObjPlayerFv(void*);
void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0);
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_obstruction_fade(void *);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
extern const f32 lbl_805D8D58;
extern const f32 lbl_805D8DAC;
void run_task__13TBoss5GryphonFv(u8 *arg0);
s32 fill_value_array(int);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 emit_enemy_effect__9TObjEneDDFllPUcl(void *, int, void *, int);
void TBoss8Dragon__sub_8006426C(Obj_8006426C *arg0);
s32 TBoss1Dragon__sub_80027A80(void *, void *);
s32 TBoss8Dragon__sub_800670E0(int, void *);
extern f32 gryphon_effect_scale_table[];
extern u8 gryphon_effect_param_block[];
extern const f32 lbl_805D8D74;
void TBoss8Dragon__sub_8006442C(Dragon_8006442C *arg0);
s32 TBoss8Dragon__sub_8005FAE0(u8 *arg0);
void set_flag_4e4__12TBoss8DragonFPv(void* p);
s32 spawn_particle_effect_with_flags(void *, s32, s32);
void * spawn_continuous_particle_effect_with_flags(void *, s32, s32);
void advance_animation_playback(void *);
void * __nw__7TObjectFUl(u32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
u8 *__ct__22TBoss5GryphonShockWaveFP7TObjectlPUcPUcls(u8 *arg0, u8 *arg1_parent, s32 arg2, u8 *arg3, u8 *arg4, s32 arg5, s16 arg6);
extern s32 lbl_80437938[];
extern const f32 lbl_805D8D50;
extern const f32 lbl_805D8D54;
extern const f32 lbl_805D8D80;
extern const f32 lbl_805D8E5C;
extern const f32 lbl_805D8E9C;
extern const f32 lbl_805D8EA0;
void TBoss8Dragon__sub_80063088(Obj_80063088 *self, u32 arg1);
u8 * csnVecterUnder(s32 *, s32);
extern const f32 lbl_805D8D70;
extern const f32 lbl_805D8D90;
extern const f32 lbl_805D8D94;
f64 atan2_float(f32, f32);
int TBoss8Dragon__sub_8005D700(void);
s32 *TBoss8Dragon__sub_80065F08(void);
s32 restore_player_cameras(void);
s32 activate_camera_mode(s32 arg0);
void set_scripted_camera_pose(void *, void *, void *);
s32 play_sound_effect(int, void *, int, int);
void play_cue_stream_file(s32 name);
extern Vec_80062BA0 lbl_80437DB8[];
extern const f64 lbl_80437EB0;
extern u8 lbl_80437EC0[];
extern const f32 lbl_805D8D5C;
extern const f32 lbl_805D8DD4;
extern const f32 lbl_805D8E80;
extern const f32 lbl_805D8E84;
extern const f32 lbl_805D8E88;
void TBoss8Dragon__sub_80062BA0(u8 *arg0, u32 arg1);
s32 update_local_colliders_from_world(void *, void *);
extern const f32 lbl_805D8E10;
extern const f32 lbl_805D8EAC;
void vfunc_88__13TBoss5GryphonFv(Obj_80064F50 *arg0);
f32 calc_random_ratio__10TObjPlayerFv(void *);
void move_along_angle__13TBoss5GryphonFPvif(void *arg0, s32 arg1, f32 farg0);
void TBoss8Dragon__sub_800646F0(s32 arg0);
void fn_800660B8(u8 *arg0);
s32 subtractive_rng_seed(void *, s32);
s32 is_alive__9TObjEneDDFv(void *);
u32 get_player_by_client_id(s32);
s32 fn_80351DA8(void *, void *, void *, int, int);
extern const f32 lbl_805D8D7C;
extern const f32 lbl_805D8D88;
extern const f32 lbl_805D8DBC;
extern const f32 lbl_805D8DC0;
extern const f32 lbl_805D8DC4;
extern const f32 lbl_805D8DC8;
extern const f32 lbl_805D8DCC;
extern const f32 lbl_805D8DD0;
extern const f32 lbl_805D8DD8;
extern const f32 lbl_805D8DDC;
extern const f32 lbl_805D8DE0;
extern const f32 lbl_805D8DE4;
void TBoss8Dragon__sub_80060020(Dragon_80060020 *self, u32 arg1);
s32 rand();
extern f32 gryphon_action_probability_table_a[];
extern f32 gryphon_action_probability_table_b[];
extern const f32 lbl_805D8D98;
extern const f32 lbl_805D8DA0;
extern const f32 lbl_805D8DA4;
extern const f32 lbl_805D8DA8;
extern const f32 lbl_805D8DB0;
extern const f32 lbl_805D8DB4;
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *arg1);
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1);
s32 random_in_table_range__12TBoss8DragonFiii(s32 self, s32 arg1, s32 arg2);
extern GA_80063FB8 lbl_80437DA4;
void TBoss8Dragon__sub_80063FB8(s32 arg0, s32 arg1, f32 farg0);
void TBoss8Dragon__sub_8006402C(s32 arg0, s32 arg1, f32 farg0, f32 farg1);
extern GA_800640A4 lbl_80437D7C;
void TBoss8Dragon__sub_800640A4(s32 arg0, s32 arg1);
struct V_8005DC0C { f32 x, y, z; };

struct Obj_8005DC0C {
    u8 pad0[0x326];
    s16 f326;
    u8 pad328[0x3C0 - 0x328];
    V_8005DC0C pts[8];
    u8 pad420[0x4E4 - 0x420];
    s32 f4e4;
};

struct Obj_8005DC0C;

struct VBase_14 { char pad[0x14]; };

struct VObj_14 : VBase_14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    u32 f18;
};

struct Boss_8005DD68 { u8 pad[0x580]; VObj_14 fades[4]; };

struct RecoveredGlobal_8005E17C_lbl_8043797C {
    s32 value;
    u8 remaining[0x3C];
};

struct RecoveredGlobal_8005E17C_lbl_804FF5C0 {
    s32 value;
    u8 remaining[0x8];
};

struct Stack_8005E1E8 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_8005E1E8_lbl_804FF5CC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8005E1E8_lbl_804FF5D8 {
    s32 value;
    u8 remaining[0xC];
};

struct Vec_8005E058 { f32 x, y, z; };

struct Obj_8005E058 { u8 pad0[0x3C0]; Vec_8005E058 src[10]; u8 pad438[0xB0]; Vec_8005E058 dst[10]; };

struct Obj_8005E0C0 { u8 pad[0x34]; s32 f34; u8 pad38[0x24]; s32 f5c; s32 f60; s32 f64; u8 pad68[0x90]; s32 ff8; u8 pad_fc[0x3C0 - 0xFC]; u8 f3c0[0x100]; s32 f4c0; };

typedef char RecoveredGlobal_8005E17C_lbl_8043797C_size[sizeof(RecoveredGlobal_8005E17C_lbl_8043797C) == 0x40 ? 1 : -1];

typedef char RecoveredGlobal_8005E17C_lbl_804FF5C0_size[sizeof(RecoveredGlobal_8005E17C_lbl_804FF5C0) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8005E1E8_lbl_804FF5CC_size[sizeof(RecoveredGlobal_8005E1E8_lbl_804FF5CC) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8005E1E8_lbl_804FF5D8_size[sizeof(RecoveredGlobal_8005E1E8_lbl_804FF5D8) == 0x10 ? 1 : -1];

struct Obj_8005E4D4 { u8 pad[0x734]; void *parts[16]; };

struct Obj_8005E52C { u8 pad[0x734]; void *parts[16]; };

struct Vec_8005E39C { f32 x, y, z; };

struct IVec_8005E39C { s32 x, y, z; };

struct Res_8005E39C { u8 pad[0x18]; s32 f18; s32 f1C; s32 f20; };

struct Obj_8005E39C {
    u8 pad0[0x60];
    s32 ang;
    u8 pad64[0x444 - 0x64];
    Vec_8005E39C pos;
    u8 pad450[0x5F0 - 0x450];
    Res_8005E39C *res;
    u8 pad5F4[0x724 - 0x5F4];
    void *eff[3];
};

struct E_8005E9D8 { s32 a; s32 b; };

struct O_8005E9D8 { u8 pad[8]; E_8005E9D8 e[1]; };

struct O_8005F740 { u8 pad[0x4a8]; u8 buf[0x14]; u8 *cur; u32 flags; };

struct P_8005F740 { u8 pad[0x30]; };

struct Obj_8005F968 { u8 pad[0x60]; s32 f60; u8 pad64[0x480 - 0x64]; s32 f480; };

struct O_8005FCE4 { u8 pad[0x4c0]; u32 flags; };

struct Vec_8005FBC4 { f32 x, y, z; };

struct Shot_8005FBC4 { f32 v[3]; };

struct Obj_8005FBC4 {
    u8 pad0[0x38];
    Vec_8005FBC4 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x474 - 0x64];
    Vec_8005FBC4 vel;
    s32 f480;
    u8 pad484[0x4c0 - 0x484];
    s32 flags;
    u8 pad4c4[0x4e4 - 0x4c4];
    s32 f4e4;
};

struct VBase_80062550 { char pad[0x18]; };

struct VObj_80062550 : VBase_80062550 {
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
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93();
    virtual void m94();
};

struct Vec_80062550 { f32 x, y, z; };

struct Tgt_80062550 {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    f32 fc;
    f32 f10;
};

struct Obj_80062550 {
    u8 pad0[0x38];
    Vec_80062550 pos;
    u8 pad44[0xb8 - 0x44];
    s16 fb8;
    u8 padba[0x490 - 0xba];
    s32 f490;
    u8 pad494[0x4bc - 0x494];
    Tgt_80062550 *f4bc;
};

struct Obj_80060F4C {
    u8 pad0[0x60];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fb8;
    u8 padba[0x4C0 - 0xBA];
    u32 flags;
};

struct Base_80065370_80062BA0 { char pad[0x18]; };

struct VObj_80065370_80062BA0 : Base_80065370_80062BA0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void vcall(s16 a, int b);
};

struct ByteBlock_10 { u8 bytes[0x10]; };

struct Stack_80063F34 {
    s32 sp8;
    f32 spC;
};

struct Stack_800646F0 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    u8 trailing_storage[0x8];
};

struct RecoveredGlobal_800646F0_lbl_80437944 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800646F0_lbl_804FF5B4 {
    s32 value;
    u8 remaining[0x8];
};

struct Stack_8006435C {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    u8 trailing_storage[0x8];
};

struct RecoveredGlobal_8006435C_lbl_80437D2C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8006435C_lbl_804FF5A0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80064CFC_lbl_80487848 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80064CFC_lbl_804FF5A0 {
    s32 value;
    u8 remaining[0x10];
};

struct ByteBlock_14 { u8 bytes[0x14]; };

struct RecoveredGlobal_80064694_lbl_80437CF0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80064114_lbl_80437D68 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80064114_lbl_804FF5B4 {
    s32 value;
    u8 remaining[0x8];
};

struct O_80064AB0 { u8 pad[0x1c]; u16 id; u8 pad2[0x38c - 0x1e]; u16 kind; u8 pad3[6]; f32 x; u8 pad4[4]; f32 z; };

struct P_80064AB0 { u16 a; u16 id; u32 kind; f32 x; f32 z; };

struct VBase_8006369C { u8 pad[0x18]; };

struct Obj_8006369C : VBase_8006369C {
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
    u8 pad1C[0xB8 - 0x1C];
    s16 f_B8;
};

struct Vec_80064968 { f32 x, y, z; };

struct Atk_80064968 {
    u8 pad0[8];
    s32 f8;
};

struct Obj_80064968 {
    u8 pad0[0x3c0];
    Vec_80064968 parts[16];
    u8 pad480[0x578 - 0x480];
    s32 f578;
    u8 pad57c[0x5f0 - 0x57c];
    Atk_80064968 *f5f0;
};

struct VBase_80065658 { char pad[0x18]; };

struct VObj_80065658 : VBase_80065658 {
    virtual ~VObj_80065658();
};

struct Obj_80065658 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x3c0 - 0x1c];
    Vec f3c0[15];
    f32 f474[3];
    u8 pad480[0x484 - 0x480];
    f32 f484[3];
    u8 pad490[0x494 - 0x490];
    Boss5GryphonMotionEntry motions[2];
    u8 pad4bc[0x4c4 - 0x4bc];
    u8 f4c4[0x4e8 - 0x4c4];
    Vec f4e8[10];
    u8 pad560[0x578 - 0x560];
    u32 f578;
    VObj_80065658 *f57c;
    u8 f580[0x6f4 - 0x580];
    f32 f6f4[11];
    u8 pad720[0x734 - 0x720];
    void *objs[16];
};

struct VBase_80063570 { char pad[0x18]; };

struct VObj_80063570 : VBase_80063570 {
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
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93();
    virtual void m94();
};

struct Obj_80063570 {
    u8 pad0[0xb8];
    s16 fb8;
    u8 padba[0x490 - 0xba];
    s32 f490;
    u8 pad494[0x4c0 - 0x494];
    s32 flags;
};

struct VBase_80062E94 { char pad[0x18]; };

struct VObj_80062E94 : VBase_80062E94 {
virtual void m0();virtual void m1();virtual void m2();virtual void m3();virtual void m4();virtual void m5();virtual void m6();virtual void m7();virtual void m8();virtual void m9();virtual void m10();virtual void m11();virtual void m12();virtual void m13();virtual void m14();virtual void m15();virtual void m16();virtual void m17();virtual void m18();virtual void m19();
virtual void m20();virtual void m21();virtual void m22();virtual void m23();virtual void m24();virtual void m25();virtual void m26();virtual void m27();virtual void m28();virtual void m29();virtual void m30();virtual void m31();virtual void m32();virtual void m33();virtual void m34();virtual void m35();virtual void m36();virtual void m37();virtual void m38();virtual void m39();
virtual void m40();virtual void m41();virtual void m42();virtual void m43();virtual void m44();virtual void m45();virtual void m46();virtual void m47();virtual void m48();virtual void m49();virtual void m50();virtual void m51();virtual void m52();virtual void m53();virtual void m54();virtual void m55();virtual void m56();virtual void m57();virtual void m58();virtual void m59();
virtual void m60();virtual void m61();virtual void m62();virtual void m63();virtual void m64();virtual void m65();virtual void m66();virtual void m67();virtual void m68();virtual void m69();virtual void m70();virtual void m71();virtual void m72();virtual void m73();virtual void m74();virtual void m75();virtual void m76();virtual void m77();virtual void m78();virtual void m79();
virtual void m80();virtual void m81();virtual void m82();virtual void m83();virtual void m84();virtual void m85();virtual void m86();virtual void m87();virtual void m88();virtual void m89();virtual void m90();virtual void m91();virtual void m92();virtual void m93();virtual void m94();
};

struct Vec_80062E94 { f32 x, y, z; };

struct VBase_80063320 { char pad[0x18]; };

struct VObj_80063320 : VBase_80063320 {
virtual void m0();virtual void m1();virtual void m2();virtual void m3();virtual void m4();virtual void m5();virtual void m6();virtual void m7();virtual void m8();virtual void m9();virtual void m10();virtual void m11();virtual void m12();virtual void m13();virtual void m14();virtual void m15();virtual void m16();virtual void m17();virtual void m18();virtual void m19();
virtual void m20();virtual void m21();virtual void m22();virtual void m23();virtual void m24();virtual void m25();virtual void m26();virtual void m27();virtual void m28();virtual void m29();virtual void m30();virtual void m31();virtual void m32();virtual void m33();virtual void m34();virtual void m35();virtual void m36();virtual void m37();virtual void m38();virtual void m39();
virtual void m40();virtual void m41();virtual void m42();virtual void m43();virtual void m44();virtual void m45();virtual void m46();virtual void m47();virtual void m48();virtual void m49();virtual void m50();virtual void m51();virtual void m52();virtual void m53();virtual void m54();virtual void m55();virtual void m56();virtual void m57();virtual void m58();virtual void m59();
virtual void m60();virtual void m61();virtual void m62();virtual void m63();virtual void m64();virtual void m65();virtual void m66();virtual void m67();virtual void m68();virtual void m69();virtual void m70();virtual void m71();virtual void m72();virtual void m73();virtual void m74();virtual void m75();virtual void m76();virtual void m77();virtual void m78();virtual void m79();
virtual void m80();virtual void m81();virtual void m82();virtual void m83();virtual void m84();virtual void m85();virtual void m86();virtual void m87();virtual void m88();virtual void m89();virtual void m90();virtual void m91();virtual void m92();virtual void m93();virtual void m94();
};

typedef char RecoveredGlobal_800646F0_lbl_80437944_size[sizeof(RecoveredGlobal_800646F0_lbl_80437944) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_800646F0_lbl_804FF5B4_size[sizeof(RecoveredGlobal_800646F0_lbl_804FF5B4) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8006435C_lbl_80437D2C_size[sizeof(RecoveredGlobal_8006435C_lbl_80437D2C) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_8006435C_lbl_804FF5A0_size[sizeof(RecoveredGlobal_8006435C_lbl_804FF5A0) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_80064114_lbl_80437D68_size[sizeof(RecoveredGlobal_80064114_lbl_80437D68) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_80064114_lbl_804FF5B4_size[sizeof(RecoveredGlobal_80064114_lbl_804FF5B4) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80064694_lbl_80437CF0_size[sizeof(RecoveredGlobal_80064694_lbl_80437CF0) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_80064CFC_lbl_80487848_size[sizeof(RecoveredGlobal_80064CFC_lbl_80487848) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_80064CFC_lbl_804FF5A0_size[sizeof(RecoveredGlobal_80064CFC_lbl_804FF5A0) == 0x14 ? 1 : -1];

struct Vec_8005D880 { f32 x, y, z; };

struct Obj_8005D880 {
    u8 pad0[0x38];
    Vec_8005D880 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
};

struct Vec_8005D9BC { f32 x, y, z; };

struct Ent_8005E868 { s32 a; s32 b; s32 f8[]; };

struct Seg_80063CDC { f32 x, y, z, w; };

f32 newton_sqrtf(f32);
s32 get_bml_model(s32, s32);
s32 get_player_pos_in_arc__13TBoss5GryphonFPviiPvPv(Obj_8005D880 *arg0, s32 arg1, s32 arg2, Vec_8005D880 *org, Vec_8005D880 *out);
s32 TBoss8Dragon__sub_8005DC0C(Obj_8005DC0C *arg0);
void render_shadows__13TBoss5GryphonFv(void* p);
void TBoss8Dragon__sub_8005E040(void *arg0);
void TBoss8Dragon__sub_8005E17C(void);
s32 TBoss8Dragon__sub_8005E1E8(f32 farg0);
void TBoss8Dragon__sub_8005E39C(Obj_8005E39C *self);
s32 get_random_sign__12TBoss8DragonFiPvi(s32 arg0, Ent_8005E868 *arg1, s32 arg2);
s32 calc_product__12TBoss8DragonFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2);
s32 TBoss8Dragon__sub_8005E9D8(void *self, O_8005E9D8 *o, s32 i);
f32 TBoss8Dragon__sub_8005EAD0(void *arg0, void *arg1, int arg2);
void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void TBoss8Dragon__sub_8005EBDC(u8 *arg0, u8 *arg1, u8 *arg2);
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2);
void set_animation_by_state__12TBoss8DragonFPv(TBoss8Dragon *arg0);
s32 TBoss8Dragon__sub_8005EE04(TBoss8Dragon *self, void *out, u32 *entry);
void TBoss8Dragon__sub_8005F684(TBoss8Dragon *self, void *params);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void turn_toward_angle_limited__13TBoss5GryphonFPvii(void *selfv, s32 arg1, s32 arg2);
void handle_message__13TBoss5GryphonFPvi(O_8005FCE4 *self, s32 msg);
void state_move__13TBoss5GryphonFPvi(Obj_80060F4C *arg0, s32 arg1);
void TBoss8Dragon__sub_80062550(Obj_80062550 *arg0, s32 arg1);
void update_active_player_count__19TPlayerBattleCtrl4PFPvi(void *arg0, s32 arg1);
void TBoss3Volopt__sub_800627E4(u8 *arg0, u32 arg1);
void TBoss8Dragon__sub_80062E94(u8 *arg0, u32 arg1);
void TBoss8Dragon__sub_80063320(u8 *arg0, u32 arg1);
void TBoss8Dragon__sub_80063570(Obj_80063570 *arg0, s32 arg1);
void TBoss8Dragon__sub_8006369C(Obj_8006369C *self, u32 arg1);
void TBoss8Dragon__sub_80063714(void);
void TBoss8Dragon__sub_80063EF4(s32 arg0);
void TBoss8Dragon__sub_80064114(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_800641A8(u8 *arg0);
void TBoss8Dragon__sub_8006435C(u8 *arg0);
void TBoss8Dragon__sub_80064828(u8 *arg0);
void TBoss8Dragon__sub_800648C8(u8 *arg0);
int emit_part_attack_effect__13TBoss5GryphonFPvi(void *arg0, int arg1);
void TBoss8Dragon__sub_80064AB0(O_80064AB0 *self);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *arg0, u8 *arg1);
void TBoss8Dragon__sub_80064DB8(u8 *arg0);
void TBoss8Dragon__sub_80064E3C(u8 *arg0);
void spawn_ancient_trap__12TBoss8DragonFii(s32 arg0, s32 arg1);
void vfunc_61__13TBoss5GryphonFv(void);
void vfunc_62__13TBoss5GryphonFv(void);
void vfunc_63__13TBoss5GryphonFv(void);
void vfunc_28__13TBoss5GryphonFv(void);
Obj_80065658 * __dt__13TBoss5GryphonFv(Obj_80065658 *o, s16 flag);
void TBoss8Dragon__sub_800660A4(void *);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 __ct__17TBoss5GryphonDemoFP7TObjectlf(void *, s32, void *, f32);
s32 fn_800666C4(s32);
void TBoss8Dragon__sub_80067074(s32 arg0, s32 arg1);
void TCameraCtrl__sub_8006A044(s32 id, f32 v);
void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0);
s32 enemy_validate_retained_target(u8 *arg0);
int copy_position__14TObjEneEpsilonFPv(void *p, void *_w1);
s32 enemy_copy_target_destination__12TObjEneDD_STFv(void *);
s32 update_linked_position__12TObjEneDD_STFf(f32);
s32 enemy_set_target_id(void *, u16);
s32 update_velocity__9TObjEneDDFv();
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, int, int, int);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
s32 delete_buffer__12TBoss8DragonFis(s32 arg0, s16 arg1);
s32 isFading__15RenderFadeStateCFv(int);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
u8 *get_enemy_entity(u16 arg0);
s32 TObjLight__sub_801337F8(void *);
s32 angle_diff_s16(s32, s32);
s32 draw__10TObjMotionFv(void *);
u8 * find_entity_by_id();
void free_collision_body_parts(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void __dl__7TObjectFPv(void *);
s32 render_nodes__7TObjectFv(s32, s32);
void __dt__7TObjectFv(void *, int);
void TBoss5GryphonLightningEff__sub_80325064(void *p);
void * __ct__25TBoss5GryphonLightningEffFv(void *, void *, void *, s32, f32, f32, f32);
s32 spawn_lightning_wing__12TBoss8DragonFiiiiii(s32 arg0, s32 arg1, s32 mid, s32 arg3, s32 arg4, s32 arg5);
void __destroy_arr(void *, void *, int, int);
f32 vec3_dot(void *, void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
void subtract_vector(void *, void *);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void set_material_alpha_compare_reference(s32 reference);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);

extern RecoveredGlobal_800646F0_lbl_80437944 boss5_gryphon_params_b;
extern RecoveredGlobal_8005E17C_lbl_8043797C boss5_gryphon_bone_capture_node_indices;
extern s32 gryphon_part_attack_index_table[];
extern ByteBlock_14 gryphon_part_attack_params;
extern RecoveredGlobal_80064694_lbl_80437CF0 gryphon_collider_desc;
extern RecoveredGlobal_8006435C_lbl_80437D2C boss8_dragon_attack_params;
extern s32 lbl_80437D54[];
extern RecoveredGlobal_80064114_lbl_80437D68 lbl_80437D68;
extern s32 lbl_80437DC4[];
extern s32 lbl_80437DD0[];
extern s32 boss5_gryphon_waypoint_vecs[];
extern f32 boss5_gryphon_scale_x_table[];
extern f32 boss5_gryphon_scale_y_table[];
extern f32 gryphon_velocity_scale_z_table[];
extern s32 gryphon_bone_copy_index_table[];
extern s32 boss5_gryphon_point_index_table[];
extern RecoveredGlobal_8006435C_lbl_804FF5A0 boss5_gryphon_attack_params;
extern RecoveredGlobal_800646F0_lbl_804FF5B4 boss5_gryphon_behavior_params;
extern RecoveredGlobal_8005E17C_lbl_804FF5C0 boss5_gryphon_bone_capture_origin;
extern u8 boss5_gryphon_camera_pos_vec[];
extern u8 boss5_gryphon_direction_vec[];
extern s32 boss5_gryphon_base_params;
extern s32 boss5_gryphon_resistance_params;
extern u8 *boss5_gryphon_body_bml_resource;
extern s32 boss5_gryphon_bml_resource;
extern s32 boss5_gryphon_texture_list;
extern s32 boss5_gryphon_render_node_index;
extern s32 boss5_gryphon_bone_capture_index;
extern s32 boss5_gryphon_bone_capture_output;
extern s32 boss5_gryphon_render_flags;
extern Obj_80065658 *boss5_gryphon_instance;
extern f32 lbl_805D4DC0;
extern u8 *camera_ctrl_instance;
extern s32 current_scene_light;
extern s32 saved_model_render_flags;
extern const f32 lbl_805D8D60;
extern const f32 lbl_805D8D64;
extern const f32 lbl_805D8D68;
extern const f32 lbl_805D8D6C;
extern const f32 lbl_805D8D78;
extern const float lbl_805D8D84;
extern const f32 lbl_805D8D8C;
extern const f32 lbl_805D8D9C;
extern const float lbl_805D8DEC;
extern const f32 lbl_805D8DF4;
extern const f32 lbl_805D8DF8;
extern const f32 lbl_805D8E00;
extern const f32 lbl_805D8E04;
extern const f32 lbl_805D8E08;
extern const f32 lbl_805D8E0C;
extern const f32 lbl_805D8E14;
extern const float lbl_805D8E20;
extern const f32 lbl_805D8E34;
extern const f32 lbl_805D8E60;
extern const f32 lbl_805D8E64;
extern const f32 lbl_805D8E68;
extern const f32 lbl_805D8E6C;
extern const f32 lbl_805D8E70;
extern const f32 lbl_805D8E74;
extern const f32 lbl_805D8E78;
extern const f32 lbl_805D8E7C;
extern const f32 lbl_805D8E8C;
extern const f32 lbl_805D8E90;
extern const f32 lbl_805D8E94;
extern const f32 lbl_805D8E98;
extern const f32 lbl_805D8EA4;
extern const f32 lbl_805D8EA8;
extern const f32 lbl_805D8EB0;
extern const f32 lbl_805D8EB4;
extern const f32 lbl_805D8EB8;
extern const f32 lbl_805D8EBC;
extern const f32 lbl_805D8EC0;
extern const float lbl_805D8EC4;
extern const f32 lbl_805D8EC8;
extern s32 model_render_flags;
extern s32 tl_01;

#pragma push
#pragma fp_contract on
extern "C" {
extern ByteBlock_14 lbl_80437D40;
}

extern "C" {
void vfunc_105__13TBoss5GryphonFv();
}
extern "C" {
void vfunc_83__13TBoss5GryphonFv();
}
extern "C" {
s32 is_split_screen();
void TBoss8Dragon__sub_8005DF60(TBoss5Gryphon *self);
}
extern "C" {
void TBoss8Dragon__sub_8005FD34(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_8005FE18(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_8005FEF8(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_800605E8(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80060788(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void set_matrix_identity(u8 *mtx);
void matrix_mult_vec(s32 mtx, void *in, void *out);
void TBoss8Dragon__sub_8006084C(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80060A58(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80060B18(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80060BF8(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80060CA4(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80060D9C(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_800610D0(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void handle_takeoff_state__13TBoss5GryphonFPvi();
}
extern "C" {
void handle_descend_state__13TBoss5GryphonFPvi(TBoss5Gryphon *, s32);
}
extern "C" {
void TBoss8Dragon__sub_800615FC(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void update_dive_motion__12TBoss8DragonFPvi(u8 *arg0, s32 arg1);
}
extern "C" {
void TBoss8Dragon__sub_80061B8C(TBoss5Gryphon *self, s32 event);
}
extern "C" {
f32 fabs_float(f32);
void TBoss8Dragon__sub_80061D34(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80062018(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_80062114(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void TBoss8Dragon__sub_800623E4();
}
extern "C" {
void TBoss8Dragon__sub_80062660(TBoss5Gryphon *self, s32 event);
}
extern "C" {
void dispatch_state_event__13TBoss5GryphonFPvii();
}
extern "C" {
void apply_poison_status__13TBoss5GryphonFv();
}
extern "C" {
void apply_paralysis__13TBoss5GryphonFv();
}
extern "C" {
void apply_slow_status__13TBoss5GryphonFv();
}
extern "C" {
void apply_confusion_status__13TBoss5GryphonFv();
}
extern "C" {
void apply_movement_ailment__13TBoss5GryphonFl();
}
extern "C" {
void apply_shock_status__13TBoss5GryphonFv();
}
extern "C" {
void clear_harmful_statuses__13TBoss5GryphonFv();
}
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
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
void recalc_stats__13TUnk_804806E8Fv();
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
void update_shock_clock__13TUnk_804806E8Fv();
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
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
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
extern u8 lbl_804378C8[];
}
extern "C" {
extern u8 lbl_804378D8[];
}
extern "C" {
extern u8 lbl_804378F0[];
}
extern "C" {
extern u8 lbl_80437908[];
}
extern "C" {
extern u8 lbl_80437918[];
}
extern "C" {
extern u8 lbl_804379BC[];
}
extern "C" {
extern u8 lbl_804379CC[];
}
extern "C" {
extern u8 lbl_804379E0[];
}
extern "C" {
extern u8 lbl_804379F4[];
}
extern "C" {
extern u8 lbl_80437A08[];
}
extern "C" {
extern u8 lbl_80437A20[];
}
extern "C" {
extern u8 lbl_80437A38[];
}
extern "C" {
extern u8 lbl_80437A50[];
}
extern "C" {
extern u8 lbl_80437A6C[];
}
extern "C" {
extern u8 lbl_80437A88[];
}
extern "C" {
extern u8 lbl_80437AA0[];
}
extern "C" {
extern u8 lbl_80437AB8[];
}
extern "C" {
extern u8 lbl_80437ACC[];
}
extern "C" {
extern u8 lbl_80437AE4[];
}
extern "C" {
extern u8 lbl_80437AFC[];
}
extern "C" {
extern u8 lbl_80437B18[];
}
extern "C" {
extern u8 lbl_80437B30[];
}
extern "C" {
extern u8 lbl_80437B4C[];
}
extern "C" {
extern u8 lbl_80437B64[];
}
extern "C" {
extern u8 lbl_80437B7C[];
}
extern "C" {
extern u8 lbl_80437B94[];
}
extern "C" {
extern u8 lbl_80437BAC[];
}
extern "C" {
extern u8 lbl_80437BC4[];
}
extern "C" {
extern u8 lbl_80437BE0[];
}
extern "C" {
extern u8 lbl_80437BF8[];
}
extern "C" {
extern u8 lbl_80437C14[];
}
extern "C" {
extern u8 lbl_80437C2C[];
}
extern "C" {
extern u8 lbl_80437C44[];
}
extern "C" {
extern u8 lbl_80437C5C[];
}
extern "C" {
extern u8 lbl_80437C74[];
}
extern "C" {
extern u8 lbl_80437C8C[];
}
extern "C" {
extern u8 lbl_80437CA4[];
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
void update_movement_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
extern void *lbl_80487848[4];
extern void *lbl_80487858[14];
extern void *lbl_80487A88[5];
extern void *lbl_80487A9C[32];
void *lbl_80487848[4] = {
    (void *)&lbl_804378C8, (void *)&lbl_804378D8, (void *)&lbl_804378F0, (void *)0x0,
};
void *lbl_80487858[14] = {
    (void *)&lbl_80437908, (void *)0x0, (void *)&lbl_80437918, (void *)&lbl_80487848,
    (void *)&lbl_80487858, (void *)0x30001, (void *)0x1e, (void *)0x1f,
    (void *)0x20, (void *)0x21, (void *)0x22, (void *)0x1e,
    (void *)0x1f, (void *)0x20,
};
void *lbl_80487890[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8048789C[3] = {
    (void *)0x0, (void *)0x1, (void *)0x2,
};
void *lbl_804878A8[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804878B4[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804878D0[110] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41700000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *lbl_80487A88[5] = {
    (void *)&lbl_804379BC, (void *)&lbl_804379CC, (void *)&lbl_804379E0, (void *)&lbl_804379F4,
    (void *)0x0,
};
void *lbl_80487A9C[32] = {
    (void *)&lbl_80437A08, (void *)&lbl_80437A20, (void *)&lbl_80437A38, (void *)&lbl_80437A50,
    (void *)&lbl_80437A6C, (void *)&lbl_80437A88, (void *)&lbl_80437AA0, (void *)&lbl_80437AB8,
    (void *)&lbl_80437ACC, (void *)&lbl_80437AE4, (void *)&lbl_80437AFC, (void *)&lbl_80437B18,
    (void *)&lbl_80437B30, (void *)&lbl_80437B4C, (void *)&lbl_80437B64, (void *)&lbl_80437B7C,
    (void *)&lbl_80437B94, (void *)&lbl_80437BAC, (void *)&lbl_80437BC4, (void *)&lbl_80437BE0,
    (void *)&lbl_80437BF8, (void *)&lbl_80437C14, (void *)&lbl_80437C2C, (void *)&lbl_80437C44,
    (void *)&lbl_80437C5C, (void *)&lbl_80437C74, (void *)&lbl_80437C8C, (void *)0x0,
    (void *)&lbl_80437CA4, (void *)&lbl_80487A88, (void *)&lbl_80487A9C, (void *)0x4001b,
};
void *lbl_80487B1C[108] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3edc28f6, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f451eb8, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3ef5c28f, (void *)0x0,
    (void *)0x20007, (void *)0x2, (void *)0x3f333333, (void *)0x6,
    (void *)0x10000, (void *)0x5, (void *)0x3f666666, (void *)0x7,
    (void *)0x30000, (void *)0x4, (void *)0x3f11eb85, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f333333, (void *)0x0,
    (void *)0x2000b, (void *)0x16, (void *)0x3f800000, (void *)0xa,
    (void *)0x10000, (void *)0x15, (void *)0x3f800000, (void *)0xb,
    (void *)0x30000, (void *)0x17, (void *)0x3f800000, (void *)0x0,
    (void *)0x2000e, (void *)0xf, (void *)0x3ecccccd, (void *)0xd,
    (void *)0x10000, (void *)0xe, (void *)0x3eb33333, (void *)0xe,
    (void *)0x30000, (void *)0xc, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x20011, (void *)0x19, (void *)0x3f400000, (void *)0x10,
    (void *)0x10000, (void *)0x18, (void *)0x3eb33333, (void *)0x11,
    (void *)0x30000, (void *)0x1a, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20014, (void *)0x13, (void *)0x3f000000, (void *)0x13,
    (void *)0x10000, (void *)0x11, (void *)0x3f800000, (void *)0x14,
    (void *)0x30000, (void *)0x14, (void *)0x3f000000, (void *)0x15,
    (void *)0x30000, (void *)0x12, (void *)0x3ecccccd, (void *)0x16,
    (void *)0x30000, (void *)0xd, (void *)0x3eb33333, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f266666, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f800000, (void *)0x80000000,
    (void *)0x30000, (void *)0x10, (void *)0x3f000000, (void *)0x0,
};
void *boss8_dragon_follow_camera_offsets[3] = {
    (void *)0x0, (void *)0x419e6666, (void *)0xc0a00000,
};
void *lbl_80487CD8[213] = {
    (void *)0x0, (void *)0x41cb70a4, (void *)0x4235ae14, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80063714, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_8006369C, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80063570,
    (void *)0x0, (void *)0xffffffff, (void *)&update_active_player_count__19TPlayerBattleCtrl4PFPvi, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss3Volopt__sub_800627E4, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_80062BA0, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80063320,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80063088, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80062660, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_80062550, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_800623E4,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80062E94, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80062114, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_80062018, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80061D34,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80061B8C, (void *)0x0,
    (void *)0xffffffff, (void *)&update_dive_motion__12TBoss8DragonFPvi, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_800615FC, (void *)0x0, (void *)0xffffffff, (void *)&handle_descend_state__13TBoss5GryphonFPvi,
    (void *)0x0, (void *)0xffffffff, (void *)&handle_takeoff_state__13TBoss5GryphonFPvi, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_800610D0, (void *)0x0, (void *)0xffffffff,
    (void *)&state_move__13TBoss5GryphonFPvi, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80060D9C,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80060CA4, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80060BF8, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_80060B18, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80060A58,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_8006084C, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80060788, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_800605E8, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_80060020,
    (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_8005FEF8, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon__sub_8005FE18, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon__sub_8005FD34, (void *)0x0, (void *)0xffffffff, (void *)&handle_message__13TBoss5GryphonFPvi,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_8048802C[16] = {
    (void *)0x0, (void *)0x42860000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x42d60000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x43130000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x42820000, (void *)0x0, (void *)0x0,
};
void *boss5_gryphon_descend_bezier_points[16] = {
    (void *)0x0, (void *)0x42860000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x431d0000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x43998000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x42820000, (void *)0x0, (void *)0x0,
};
void *lbl_804880AC[3] = {
    (void *)0xc1c80000, (void *)0x0, (void *)0x428a0000,
};
void *lbl_804880B8[126] = {
    (void *)0x41980000, (void *)0x0, (void *)0x428a0000, (void *)0x0,
    (void *)0xffffffff, (void *)&calc_product_and_ratio__12TBoss8DragonFiPvi, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon::calc_params, (void *)0x0, (void *)0xffffffff, (void *)&TBoss8Dragon__sub_8005EBDC,
    (void *)0x0, (void *)0xffffffff, (void *)&calc_attack_params__12TBoss8DragonFiPvi, (void *)0x0,
    (void *)0xffffffff, (void *)&TBoss8Dragon::set_random_param, (void *)0x0, (void *)0xffffffff,
    (void *)&TBoss8Dragon::set_random_param, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
void *gryphon_particle_enable_pos[3] = {
    (void *)0x0, (void *)0xc61c4000, (void *)0x0,
};
void *gryphon_particle_position_vec[3] = {
    (void *)0x0, (void *)0xc61c4000, (void *)0x0,
};
void *__vt__13TBoss5Gryphon[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TBoss5GryphonFv, (void *)&run_task__13TBoss5GryphonFv,
    (void *)&TBoss8Dragon__sub_8005DF60, (void *)&render_shadows__13TBoss5GryphonFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__13TBoss5GryphonFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TBoss5GryphonFv, (void *)&apply_paralysis__13TBoss5GryphonFv, (void *)&apply_slow_status__13TBoss5GryphonFv, (void *)&apply_confusion_status__13TBoss5GryphonFv,
    (void *)&apply_movement_ailment__13TBoss5GryphonFl, (void *)&apply_shock_status__13TBoss5GryphonFv, (void *)&clear_harmful_statuses__13TBoss5GryphonFv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__13TBoss5GryphonFv, (void *)&vfunc_62__13TBoss5GryphonFv, (void *)&vfunc_63__13TBoss5GryphonFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_state_event__13TBoss5GryphonFPvii,
    (void *)&vfunc_88__13TBoss5GryphonFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneEpsilon__vt101, (void *)&vfunc_83__13TBoss5GryphonFv, (void *)&vfunc_105__13TBoss5GryphonFv,
};
#define lbl_80487848 (*(RecoveredGlobal_80064CFC_lbl_80487848 *)lbl_80487848)
#define gryphon_particle_enable_pos ((u8 *)gryphon_particle_enable_pos)
#define gryphon_particle_position_vec ((s32 *)gryphon_particle_position_vec)
#define __vt__13TBoss5Gryphon ((u8 *)__vt__13TBoss5Gryphon)

s32 get_player_pos_in_arc__13TBoss5GryphonFPviiPvPv(Obj_8005D880 *arg0, s32 arg1, s32 arg2, Vec_8005D880 *org, Vec_8005D880 *out) {
    Obj_8005D880 *p;
    f32 dx;
    f32 dz;
    f32 px;
    f32 pz;
    s32 ang;

    p = ((Obj_8005D880 * (*)(s32))get_player_by_client_id)(arg2);
    if (p == 0) {
        return 0;
    }
    pz = p->pos.z;
    px = p->pos.x;
    dz = pz - arg0->pos.z;
    dx = px - arg0->pos.x;
    if (dx * dx + dz * dz < lbl_805D8D60) {
        return 0;
    }
    ang = angle_diff_s16((s32)(((const f64 *)&lbl_80437EB0)[0] * atan2_float(px - org->x, pz - org->z)), arg0->f60);
    if (arg1 != 0) {
        if ((f32)(s32)(u16)ang > lbl_805D8D64) {
            return 0;
        }
    } else {
        if ((f32)(s32)(u16)ang < lbl_805D8D68) {
            return 0;
        }
    }
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(out, &p->pos);
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2) {
    Vec_8005D9BC pos;
    Vec_8005D9BC mid;
    Vec_8005D9BC out;
    Vec_8005D9BC tmp;
    f32 r;
    s32 ang;
    u8 *p;

    r = calc_random_ratio__10TObjPlayerFv(arg0 + 0x5F4);
    r = lbl_805D8D6C * r + lbl_805D8D6C;
    ang = (s32)(lbl_805D8D64 * calc_random_ratio__10TObjPlayerFv(arg0 + 0x5F4) + (f32)*(s32 *)((s8 *)arg0 + 0x60));
    if (arg1 != 0) {
        if (*(u32 *)((s8 *)arg0 + 0x6DC) == 0) return;
        ((TBoss8Dragon *)(*(u32 *)((s8 *)arg0 + 0x6DC)))->copy_position((s32)(&pos));
    } else {
        if (*(u32 *)((s8 *)arg0 + 0x6E0) == 0) return;
        ((TBoss8Dragon *)(*(u32 *)((s8 *)arg0 + 0x6E0)))->copy_position((s32)(&pos));
    }
    if (((s32 (*)(void *, s32, s32, void *, void *))get_player_pos_in_arc__13TBoss5GryphonFPviiPvPv)(arg0, arg1, arg2, &pos, &out) == 0) {
        if (arg1 != 0) {
            ang = (s32)((f32)ang + lbl_805D8D68);
        }
        out.x = r * sin_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x38);
        out.y = *(f32 *)((s8 *)arg0 + 0x3C);
        out.z = r * cos_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x40);
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&tmp, &out);
        p = ((u8 * (*)(void *, s32))csnVecterUnder)(&tmp, 0x16EF);
        if (p == NULL || *(f32 *)((s8 *)(*(u8 **)((s8 *)p + 4)) + 4) > lbl_805D8D70) {
            out.x = lbl_805D8D6C * sin_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x38);
            out.y = *(f32 *)((s8 *)arg0 + 0x3C);
            out.z = lbl_805D8D6C * cos_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x40);
        }
    }
    mid.x = lbl_805D8D74 * (pos.x + out.x);
    mid.y = lbl_805D8D78 + pos.y;
    mid.z = lbl_805D8D74 * (pos.z + out.z);
    spawn_lightning_wing__12TBoss8DragonFiiiiii((s32)arg0, (s32)&pos, (s32)&mid, (s32)&out, 0x14, 0x11);
}
#pragma pop

void TBoss5Gryphon::render_nodes_with_flag() {
    s32 arg0 = (s32)this;
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x400;
    render_nodes__7TObjectFv(arg0 + 0x4C4, temp_r4);
    model_render_flags = saved_model_render_flags;
}

s32 TBoss8Dragon__sub_8005DC0C(Obj_8005DC0C *arg0) {
    V_8005DC0C cam;
    V_8005DC0C dir;
    f32 len;
    u8 *pl;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (arg0->f326 == 4) {
        return 0;
    }
    if (get_flag_bit6__12TBoss8DragonFv() != 0) {
        return 0;
    }
    if (arg0->f4e4 != 0) {
        return 0;
    }
    TCameraCtrl::get_camera_target_id(-1);
    pl = find_entity_by_id();
    if (pl == 0) {
        return 0;
    }
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&cam, camera_ctrl_instance + 0x178);
    cam.y = lbl_805D8D5C;
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&dir, pl + 0x38);
    subtract_vector(&dir, &cam);
    dir.y = lbl_805D8D5C;
    len = ((TObjBoss2Tunnel *)(&dir))->clamp_velocity();
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(boss5_gryphon_camera_pos_vec, &cam);
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(boss5_gryphon_direction_vec, &dir);
    lbl_805D4DC0 = len;
    for (i = 0; i < 4; i++) {
        if (((s32 (*)(void *, void *, f32))TBoss8Dragon__sub_8005E1E8)(arg0, &arg0->pts[boss5_gryphon_point_index_table[i]], lbl_805D8D80) != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss5Gryphon::render_with_fade(s32 arg1) {
    u8 *temp_r31;
    TObjFish::set_global_param(this->texture_id);
    TObjEneDD::clear_global_flag_400();
    saved_model_render_flags = model_render_flags;
    set_material_alpha_compare_reference(0);
    if (TBoss8Dragon__sub_8005DC0C((Obj_8005DC0C *) (this)) != 0) {
        ((RenderFadeState *)(&((Boss_8005DD68 *)((u8 *)this))->fades[arg1]))->fadeOut();
    } else {
        ((RenderFadeState *)(&((Boss_8005DD68 *)((u8 *)this))->fades[arg1]))->restore();
    }
    temp_r31 = (u8 *)&((Boss_8005DD68 *)((u8 *)this))->fades[arg1];
    if (isFading__15RenderFadeStateCFv((int)temp_r31) != 0) {
        ((VObj_14 *)(temp_r31))->m6();
    }
    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, (int) (this->rotation_x));
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, lbl_805D8D58, lbl_805D8D58, lbl_805D8D58);
    TObjPlayer::toggle_particle_effect();
    draw__10TObjMotionFv((void *) (this));
    TParticleCtrl::end_effect_render();
    TObjLight__sub_801337F8((void *)current_scene_light);
    pop_matrix();
    set_chunk_material_override_pair(0xFF00, 0);
    set_material_alpha_compare_reference(0xBF);
    model_render_flags = saved_model_render_flags;
}

void TBoss5Gryphon::render_model() {
    s32 temp_r31;
    u8 *temp_r4;

    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, (int) (this->rotation_x));
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, lbl_805D8D58, lbl_805D8D58, lbl_805D8D58);
    temp_r31 = *(s32 *)&this->model;
    temp_r4 = (unsigned char *) (*(void **)((s8 *)boss5_gryphon_body_bml_resource + 0x42C));
    *(s32 *)&this->model = (s32) *(s32 *)((s8 *)temp_r4 + 0x18);
    ((s32 (*)(void *, int))draw__10TObjMotionFv)((void *) (this), (int)temp_r4);
    *(s32 *)&this->model = temp_r31;
    pop_matrix();
}

void TBoss5Gryphon::render_shadows() { if (check_demo_mode__10TObjPlayerFv(this) == 0) { render_model(); } }

void TBoss8Dragon__sub_8005DF60(TBoss5Gryphon *self) {
    s32 view = 0;
    if (TObjPlayer::check_demo_mode() != 0) {
        self->vfunc_105();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    if (self->defer_render() != 0) {
        TBoss8Dragon__sub_8005E040(self);
        self->draw_body();
        self->copy_bone_positions();
        if (self->renderFadeStates[view].isFading() == 0) {
            self->render_with_fade(view);
        }
        self->render_nodes_with_flag();
    } else if (self->renderFadeStates[view].isFading() != 0) {
        self->render_with_fade(view);
    }
}

void TBoss8Dragon__sub_8005E040(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x4E4) == 0) {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)&lbl_805D8D84);
    }
}

void TBoss5Gryphon::copy_bone_positions() {
    s32 i;
    Vec_8005E058 *d = ((Obj_8005E058 *)this)->dst;
    for (i = 0; i < 10; i++) {
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(d, &((Obj_8005E058 *)this)->src[gryphon_bone_copy_index_table[i]]);
        d++;
    }
}

void TBoss5Gryphon::draw_body() {
    boss5_gryphon_render_node_index = 0;
    boss5_gryphon_bone_capture_index = 0;
    boss5_gryphon_bone_capture_output = (s32)((Obj_8005E0C0 *)this)->f3c0;
    boss5_gryphon_render_flags = ((Obj_8005E0C0 *)this)->f4c0;
    TObjEneRe7Berura::set_global_state((s32)((void *)TBoss8Dragon__sub_8005E17C));
    ((void (*)(void))push_matrix)();
    TObjPlayer::set_global_flag();
    ((void (*)(void *))post_translate_matrix)((u8 *)this + 0x38);
    ((void (*)(int, int))rotate_matrix_y)(0, ((Obj_8005E0C0 *)this)->f60);
    ((void (*)(int, int))rotate_matrix_x)(0, ((Obj_8005E0C0 *)this)->f5c);
    ((void (*)(int, int))rotate_matrix_z)(0, ((Obj_8005E0C0 *)this)->f64);
    ((void (*)(int, f32, f32, f32))scale_matrix)(0, lbl_805D8D58, lbl_805D8D58, lbl_805D8D58);
    this->get_speed_or_default();
    ((TBoss8Dragon *)((void *)((Obj_8005E0C0 *)this)->f34))->render_model_tree((void *)((Obj_8005E0C0 *)this)->ff8);
    TObjPlayer::clear_global_state();
    ((void (*)(void))pop_matrix)();
    TObjEneRe7Berura::set_global_state(0);
}

void TBoss8Dragon__sub_8005E17C(void) {
    s32 pos;
    if ((s32) boss5_gryphon_render_node_index == (s32) *(s32 *)((s8 *)(&boss5_gryphon_bone_capture_node_indices.value) + (boss5_gryphon_bone_capture_index * 4))) {
        pos = boss5_gryphon_bone_capture_output;
        boss5_gryphon_bone_capture_output = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &boss5_gryphon_bone_capture_origin.value, pos);
        boss5_gryphon_bone_capture_index += 1;
    }
    boss5_gryphon_render_node_index += 1;
}

#pragma push
#pragma fp_contract on
s32 TBoss8Dragon__sub_8005E1E8(f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_8005E1E8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8005E1E8, spC) == 0x4) ? 1 : -1];
    Stack_8005E1E8 stack;
    f32 temp_f1;
    f32 temp_f31;
    ((s32 (*)(void *))VecCopy__FP3VecPC3Vec)((void *) (&stack.sp8));
    stack.spC = lbl_805D8D5C;
    ((s32 (*)(void *, void *))subtract_vector)((void *) (&stack.sp8), (void *) (&(*(RecoveredGlobal_8005E1E8_lbl_804FF5CC *)&boss5_gryphon_camera_pos_vec).value));
    temp_f1 = ((TObjBoss2Tunnel *)(&stack.sp8))->clamp_velocity();
    if ((temp_f1 + farg0) < (*(const f32 *)&lbl_805D4DC0)) {
        temp_f31 = temp_f1 * (lbl_805D8D88 / newton_sqrtf((f32) ((temp_f1 * temp_f1) + (farg0 * farg0))));
        if (vec3_dot((void *) (&stack.sp8), (void *) (&(*(RecoveredGlobal_8005E1E8_lbl_804FF5D8 *)&boss5_gryphon_direction_vec).value)) >= temp_f31) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

void TBoss5Gryphon::free_parts() {
    if ((u32) *(u32 *)((s8 *)this + 0x72C) != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(*(void **)((s8 *)this + 0x72C));
        *(u32 *)((s8 *)this + 0x72C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x728) != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(*(void **)((s8 *)this + 0x728));
        *(u32 *)((s8 *)this + 0x728) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)this + 0x724) != 0U) {
        ((s32 (*)(void *))queue_destruction__7TObjectFv)(*(void **)((s8 *)this + 0x724));
        *(u32 *)((s8 *)this + 0x724) = 0U;
    }
}

void TBoss5Gryphon::update_particle_positions() {
    if (*(void **)((s8 *)this + 0x724) != NULL) {
        ((TNowLoading *)(*(void **)((s8 *)this + 0x724)))->copy_pos(gryphon_particle_position_vec);
        ((TParticleCtrl *)(*(void **)((s8 *)this + 0x724)))->enable();
    }
    if (*(void **)((s8 *)this + 0x728) != NULL) {
        ((TNowLoading *)(*(void **)((s8 *)this + 0x728)))->copy_pos(gryphon_particle_position_vec);
        ((TParticleCtrl *)(*(void **)((s8 *)this + 0x728)))->enable();
    }
    if (*(void **)((s8 *)this + 0x72C) != NULL) {
        ((TNowLoading *)(*(void **)((s8 *)this + 0x72C)))->copy_pos(gryphon_particle_position_vec);
        ((TParticleCtrl *)(*(void **)((s8 *)this + 0x72C)))->enable();
    }
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_8005E39C(Obj_8005E39C *self) {
    Vec_8005E39C pos;
    IVec_8005E39C rot;
    pos.x = lbl_805D8D8C * sin_table_lookup(self->ang) + self->pos.x;
    pos.y = self->pos.y;
    pos.z = lbl_805D8D8C * cos_table_lookup(self->ang) + self->pos.z;
    rot.x = 0;
    rot.y = self->ang;
    rot.x = 0x4000;
    if (self->eff[0] == NULL) {
        self->eff[0] = spawn_continuous_particle_effect_with_flags(&pos, self->res->f18, 0x2040);
        ((TBoss4Type2 *)(self->eff[0]))->copy_vec3(&rot);
    } else {
        ((TNowLoading *)(self->eff[0]))->copy_pos(&pos);
        ((TBoss4Type2 *)(self->eff[0]))->copy_vec3(&rot);
    }
    if (self->eff[1] == NULL) {
        self->eff[1] = spawn_continuous_particle_effect_with_flags(&pos, self->res->f1C, 0x40);
    } else {
        ((TNowLoading *)(self->eff[1]))->copy_pos(&pos);
    }
    if (self->eff[2] == NULL) {
        self->eff[2] = spawn_continuous_particle_effect_with_flags(&pos, self->res->f20, 0x40);
        ((TBoss4Type2 *)(self->eff[2]))->copy_vec3(&rot);
    } else {
        ((TNowLoading *)(self->eff[2]))->copy_pos(&pos);
        ((TBoss4Type2 *)(self->eff[2]))->copy_vec3(&rot);
    }
}
#pragma pop

void TBoss5Gryphon::destroy_parts() {
    s32 i;
    for (i = 15; i >= 0; i--) {
        if (((Obj_8005E4D4 *)this)->parts[i] != 0) {
            queue_destruction__7TObjectFv(((Obj_8005E4D4 *)this)->parts[i]);
            ((Obj_8005E4D4 *)this)->parts[i] = 0;
        }
    }
}

void TBoss5Gryphon::enable_particles() {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((Obj_8005E52C *)this)->parts[i] != 0) {
            ((TNowLoading *)(((Obj_8005E52C *)this)->parts[i]))->copy_pos(gryphon_particle_enable_pos);
            ((TParticleCtrl *)(((Obj_8005E52C *)this)->parts[i]))->enable();
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_ground_effects() {
    Obj_8005E594 *arg0 = (Obj_8005E594 *)this;
    Vec_8005E594 pts[16];
    Vec_8005E594 *p;
    Vec_8005E594 *q;
    s32 i;
    p = pts;
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->cp[0]));
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->cp[1]));
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->cp[2]));
    VecCopy__FP3VecPC3Vec(p, (void*)(&arg0->cp[3]));
    p[1].x = (lbl_805D8D58 * arg0->cp[0].x + arg0->cp[1].x) / lbl_805D8D90;
    p[1].y = (lbl_805D8D58 * arg0->cp[0].y + arg0->cp[1].y) / lbl_805D8D90;
    p[1].z = (lbl_805D8D58 * arg0->cp[0].z + arg0->cp[1].z) / lbl_805D8D90;
    p[2].x = (lbl_805D8D58 * arg0->cp[1].x + arg0->cp[0].x) / lbl_805D8D90;
    p[2].y = (lbl_805D8D58 * arg0->cp[1].y + arg0->cp[0].y) / lbl_805D8D90;
    p[2].z = (lbl_805D8D58 * arg0->cp[1].z + arg0->cp[0].z) / lbl_805D8D90;
    p[3].x = lbl_805D8D74 * (arg0->cp[1].x + arg0->cp[2].x);
    p[3].y = lbl_805D8D74 * (arg0->cp[1].y + arg0->cp[2].y);
    p[3].z = lbl_805D8D74 * (arg0->cp[1].z + arg0->cp[2].z);
    p[4].x = lbl_805D8D74 * (arg0->cp[2].x + arg0->cp[3].x);
    p[4].y = lbl_805D8D74 * (arg0->cp[2].y + arg0->cp[3].y);
    p[4].z = lbl_805D8D74 * (arg0->cp[2].z + arg0->cp[3].z);
    p += 5;
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->cp[4]));
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->cp[5]));
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->cp[6]));
    VecCopy__FP3VecPC3Vec(p, (void*)(&arg0->cp[7]));
    p[1].x = (lbl_805D8D58 * arg0->cp[4].x + arg0->cp[5].x) / lbl_805D8D90;
    p[1].y = (lbl_805D8D58 * arg0->cp[4].y + arg0->cp[5].y) / lbl_805D8D90;
    p[1].z = (lbl_805D8D58 * arg0->cp[4].z + arg0->cp[5].z) / lbl_805D8D90;
    p[2].x = (lbl_805D8D58 * arg0->cp[5].x + arg0->cp[4].x) / lbl_805D8D90;
    p[2].y = (lbl_805D8D58 * arg0->cp[5].y + arg0->cp[4].y) / lbl_805D8D90;
    p[2].z = (lbl_805D8D58 * arg0->cp[5].z + arg0->cp[4].z) / lbl_805D8D90;
    p[3].x = lbl_805D8D74 * (arg0->cp[5].x + arg0->cp[6].x);
    p[3].y = lbl_805D8D74 * (arg0->cp[5].y + arg0->cp[6].y);
    p[3].z = lbl_805D8D74 * (arg0->cp[5].z + arg0->cp[6].z);
    p[4].x = lbl_805D8D74 * (arg0->cp[6].x + arg0->cp[7].x);
    p[4].y = lbl_805D8D74 * (arg0->cp[6].y + arg0->cp[7].y);
    p[4].z = lbl_805D8D74 * (arg0->cp[6].z + arg0->cp[7].z);
    q = pts;
    for (i = 0; i < 16; i++, q++) {
        Hit_8005E594 *hit = (Hit_8005E594 *)csnVecterUnder((s32 *)q, 0x16EF);
        if (hit == NULL) {
            q->y = lbl_805D8D94;
        } else {
            f32 y = hit->p->y;
            if (y > lbl_805D8D70) {
                q->y = lbl_805D8D70;
            } else {
                q->y = y;
            }
        }
        if (arg0->parts[i] == NULL) {
            arg0->parts[i] = spawn_continuous_particle_effect_with_flags(q, arg0->fx->f14, 0x40);
        } else {
            ((TNowLoading *)(arg0->parts[i]))->copy_pos(q);
        }
    }
}
#pragma pop

s32 get_random_sign__12TBoss8DragonFiPvi(s32 arg0, Ent_8005E868 *arg1, s32 arg2) {
    s32 v;

    v = arg1[arg2].f8[0];
    if (v > 0) {
        return 1;
    }
    if (v < 0) {
        return -1;
    }
    if ((lbl_805D8D98 * (f32) rand()) >= lbl_805D8D74) {
        return 1;
    }
    return -1;
}

s32 calc_product__12TBoss8DragonFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r31;

    temp_r31 = random_in_table_range__12TBoss8DragonFiii(arg0, arg1, arg3);
    return temp_r31 * ((s32 (*)(s32, s32, s32))get_random_sign__12TBoss8DragonFiPvi)(arg0, arg1, arg2);
}

#pragma push
#pragma fp_contract on
s32 rand_scaled_offset__12TBoss8DragonFiii(s32 arg0, s32 arg1, s32 arg2) {
    return (s32) (((f32) arg2 * (lbl_805D8D98 * (f32) rand())) + (f32) arg1);
}
#pragma pop

s32 TBoss8Dragon__sub_8005E9D8(void *self, O_8005E9D8 *o, s32 i) {
    return o->e[i].a;
}

s32 random_in_table_range__12TBoss8DragonFiii(s32 self, s32 arg1, s32 arg2) {
    u8 *temp_r8;
    temp_r8 = (u8 *)(arg1 + (arg2 * 8));
    return (s32) ((f32 (*)(s32, f32, f32))random_in_range__12TBoss8DragonFff)(self, (f32) *(s32 *)((s8 *)temp_r8 + 8), (f32) *(s32 *)((s8 *)temp_r8 + 0xC));
}

#pragma push
#pragma fp_contract on
f32 random_in_range__12TBoss8DragonFff(f32 farg0, f32 farg1) {
    return (farg1 * (lbl_805D8D98 * (f32) rand())) + farg0;
}
#pragma pop

#pragma push
#pragma scheduling off
f32 TBoss8Dragon__sub_8005EAD0(void *arg0, void *arg1, int arg2) {
  u8 *temp_r4;
  temp_r4 = (u8 *)arg1 + (arg2 * 8);
  return ((f32 (*)(int, f32, f32))random_in_range__12TBoss8DragonFff)((int)arg0, (f32) (*((f32 *) (((s8 *) temp_r4) + 0x28))), (f32) (*((f32 *) (((s8 *) temp_r4) + 0x2C))));
}
#pragma pop

void TBoss8Dragon::set_random_param(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg1 + 4) = (s32) (lbl_805D8D9C * (lbl_805D8D98 * (f32) rand()));
}

void calc_attack_params__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2) {
    f32 temp_f1;
    temp_f1 = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 1);
    *(f32 *)((s8 *)arg1 + 0xC) = (f32) (temp_f1 * temp_f1);
    *(f32 *)((s8 *)arg1 + 8) = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 0);
    *(s32 *)((s8 *)arg1 + 4) = ((s32 (*)(void *, void *, int, int))calc_product__12TBoss8DragonFiiii)((void *)arg0, (void *)arg2, 0, 1);
}

void TBoss8Dragon__sub_8005EBDC(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r3;
    temp_r3 = ((s32 (*)(void *, void *, int))random_in_table_range__12TBoss8DragonFiii)(arg0, arg2, 0);
    switch (temp_r3) {
    case 0:
        temp_r31 = (s32) (lbl_80437EB0 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x38)), (f32) (*(f32 *)((s8 *)arg0 + 0x40))));
        temp_f31 = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 1);
        *(f32 *)((s8 *)arg1 + 4) = (f32) (temp_f31 * ((f32 (*)(int))sin_table_lookup)(temp_r31));
        *(f32 *)((s8 *)arg1 + 8) = (f32) (temp_f31 * ((f32 (*)(int))cos_table_lookup)(temp_r31));
        break;
    case 1:
        *(f32 *)((s8 *)arg1 + 4) = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 1);
        *(f32 *)((s8 *)arg1 + 8) = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 2);
        break;
    }
    *(f32 *)((s8 *)arg1 + 0xC) = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 0);
    *(s32 *)((s8 *)arg1 + 0x10) = ((s32 (*)(void *, void *, int))random_in_table_range__12TBoss8DragonFiii)(arg0, arg2, 1);
}

void TBoss8Dragon::calc_params(s32 arg0, void *arg1, s32 arg2) {
    *(s32 *)((s8 *)arg1 + 4) = random_in_table_range__12TBoss8DragonFiii(arg0, arg2, 1);
    *(f32 *)((s8 *)arg1 + 0xC) = ((f32 (*)(s32, s32, s32))TBoss8Dragon__sub_8005EAD0)(arg0, arg2, 0);
    *(f32 *)((s8 *)arg1 + 0x10) = ((f32 (*)(s32, s32, s32))TBoss8Dragon__sub_8005EAD0)(arg0, arg2, 1);
    *(s32 *)((s8 *)arg1 + 8) = ((s32 (*)(s32, s32, s32))get_random_sign__12TBoss8DragonFiPvi)(arg0, arg2, 0);
}

#pragma push
#pragma fp_contract on
void calc_product_and_ratio__12TBoss8DragonFiPvi(s32 arg0, u8 *arg1, s32 arg2) {
    *(s32 *)((s8 *)arg1 + 4) = calc_product__12TBoss8DragonFiiii(arg0, arg2, 0, 1);
    *(f32 *)((s8 *)arg1 + 8) = TBoss8Dragon__sub_8005EAD0((void *)arg0, (void *)arg2, 0);
}
#pragma pop

void TBoss8Dragon::copy_angle_state(void *arg0, void *dst, void *src) {
    *(s16 *)((s8 *)dst + 0) = (s16) *(s32 *)((s8 *)src + 0);
    *(s16 *)((s8 *)dst + 2) = ((s16 (*)(void *, s16, s16))rand_scaled_offset__12TBoss8DragonFiii)(arg0, *(s16 *)((s8 *)src + 4), *(s16 *)((s8 *)src + 6));
}

#define F(t, o) (*(t *)(arg0 + (o)))
#define TBL(o) (*(s32 *)((s8 *)(F(u8 *, 0x778)) + (o)))
#define LEVEL (*(s32 *)((s8 *)(*(u8 **)(boss5_gryphon_behavior_params.remaining + 4)) + 0x28))
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *arg1) {
    f32 r;
    if (*arg1 != 0x21) {
        ((TBoss8Dragon *)arg0)->update_target_from_state();
        return;
    }
    r = lbl_805D8D98 * (f32)rand();
    switch (TBoss8Dragon__sub_8005E9D8(arg0, (O_8005E9D8 *)arg1, 0)) {
    case 0:
        if (r < lbl_805D8DA0) {
            F(s32, 0x774) = TBL(8);
        } else if (r < lbl_805D8DA4) {
            F(s32, 0x774) = TBL(0xC);
        } else {
            F(s32, 0x774) = TBL(0x10);
        }
        break;
    case 1:
        if ((F(s32, 0x4C0) & 0x200) && LEVEL >= 5) {
            F(s32, 0x774) = TBL(0x24);
            F(s32, 0x4C0) &= ~0x200;
            break;
        }
        F(s32, 0x4C0) |= 0x200;
        if (r < gryphon_action_probability_table_a[LEVEL]) {
            F(s32, 0x774) = TBL(0x24);
            break;
        }
        r = (f32)F(s16, 0x32C) / (f32)F(s16, 0x2B8);
        if (lbl_805D8D98 * (f32)rand() < gryphon_action_probability_table_b[LEVEL]) {
            if (lbl_805D8D98 * (f32)rand() < r) {
                F(s32, 0x774) = TBL(0x1C);
            } else {
                F(s32, 0x774) = TBL(0x20);
            }
        } else {
            if (lbl_805D8D98 * (f32)rand() < r) {
                F(s32, 0x774) = TBL(0x14);
            } else {
                F(s32, 0x774) = TBL(0x18);
            }
        }
        break;
    case 2:
        if (r < gryphon_action_probability_table_a[LEVEL]) {
            F(s32, 0x774) = TBL(0x24);
        } else {
            F(s32, 0x774) = TBL(0x28);
        }
        break;
    case 3:
        if (r < lbl_805D8DA8) {
            F(s32, 0x774) = TBL(0x2C);
        } else if (r < lbl_805D8DAC) {
            F(s32, 0x774) = TBL(0x30);
        } else if (r < lbl_805D8DA0) {
            F(s32, 0x774) = TBL(0x34);
        } else if (r < lbl_805D8DB0) {
            F(s32, 0x774) = TBL(0x38);
        } else {
            F(s32, 0x774) = TBL(0x3C);
        }
        break;
    case 4:
        if (r < lbl_805D8DB4) {
            if (LEVEL >= 2) {
                F(s32, 0x774) = TBL(0x4C);
            } else {
                F(s32, 0x774) = TBL(0x40);
            }
        } else if (r < lbl_805D8DA0) {
            if (LEVEL >= 4) {
                F(s32, 0x774) = TBL(0x50);
            } else {
                F(s32, 0x774) = TBL(0x44);
            }
        } else {
            if (LEVEL >= 6) {
                F(s32, 0x774) = TBL(0x54);
            } else {
                F(s32, 0x774) = TBL(0x48);
            }
        }
        break;
    case 5:
        F(s32, 0x774) = TBL(0x58);
        break;
    case 6:
        F(s32, 0x774) = TBL(0x10);
        break;
    }
}

void TBoss8Dragon::update_target_from_state() {
    s32 temp_r0;

    temp_r0 = this->m_4e4;
    switch (temp_r0) {
    default:
    case 0:
        this->m_774 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x778)) + 0x40);
        return;
    case 1:
        this->m_774 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x778)) + 8);
        return;
    case 3:
        this->m_774 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x778)) + 0x60);
        return;
    case 2:
        this->m_774 = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)this + 0x778)) + 0x5C);
        return;
    }
}

void TBoss8Dragon::play_animation_index(s32 arg1) {
    struct { u8 pad[0x30]; } sp8;
    s32 temp_r5;
    ((TBoss8Dragon *)(&sp8))->init_color();
    temp_r5 = *(s32 *)((s8 *)((u8 *)this) + 0x778);
    this->m_774 = (s32) *(s32 *)((s8 *)temp_r5 + (arg1 * 4));
    ((s32 (*)(void *, void *, int))trigger_effect__12TBoss8DragonFPvi)((void *) (this), (void *) (&sp8), temp_r5);
    TBoss8Dragon__sub_8005F684(this, (void *) (&sp8));
    this->copy_spawn_params((void *) (&sp8));
}

void set_animation_by_state__12TBoss8DragonFPv(TBoss8Dragon *boss8_dragon) {
    s32 temp_r0;

    *(s32 *)((s8 *)boss8_dragon + 0x4C0) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x4C0) | 8);
    temp_r0 = *(s32 *)((s8 *)boss8_dragon + 0x4E4);
    switch (temp_r0) {
    default:
    case 0:
        boss8_dragon->play_animation_index(0x19);
        return;
    case 1:
        boss8_dragon->play_animation_index(0x1A);
        return;
    case 3:
        boss8_dragon->play_animation_index(0x1B);
        return;
    case 2:
        boss8_dragon->play_animation_index(0x1C);
        return;
    }
}

void TBoss8Dragon::init_state_zero(void *boss8_dragon) {
    ((TBoss8Dragon *)boss8_dragon)->play_animation_index(0);
}

void TBoss8Dragon__sub_8005F684(TBoss8Dragon *self, void *params) {
    s32 i;
    u8 *out;

    if ((u32 *)self->m_774 == NULL) {
        self->update_target_from_state();
    }
    out = (u8 *)params + 0x14;
    for (i = 0; i < 1;) {
        u32 *entry = (u32 *)self->m_774;
        if (*entry == 0x21) {
            choose_next_action__13TBoss5GryphonFPvPv((u8 *)self, entry);
            continue;
        }
        if (TBoss8Dragon__sub_8005EE04(self, out, entry) != 0) {
            break;
        }
        i++;
        out += 0x14;
        self->m_774 += 0x48;
    }
}

void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1) {
    fn_800666C4(arg1 + 0x14);
}

void TBoss8Dragon::flush_pending_effect() {
    O_8005F740 *self = (O_8005F740 *)this;
    P_8005F740 p;
    if ((this->m_4c0 & 2) && this->m_4bc >= self->buf) {
        ((TBoss8Dragon *)(&p))->init_color();
        ((void (*)(void *, void *))trigger_effect__12TBoss8DragonFPvi)(self, &p);
        ((void (*)(void *, void *))TBoss8Dragon__sub_8005F684)(self, &p);
        this->m_4c0 &= ~2;
        copy_spawn_params(&p);
    }
}

void TBoss8Dragon::update_periodic_effect() {
    TBoss8Dragon::update_epsilon_position();
    if (!(this->m_490 & 0x1F)) {
        if (enemy_validate_retained_target((u8 *)this) != 0) {
            enemy_copy_target_destination__12TObjEneDD_STFv(this);
        } else {
            copy_position__14TObjEneEpsilonFPv(this, lbl_80437938);
        }
        ((s32 (*)(void *))TBoss8Dragon__sub_80064AB0)(this);
    }
    this->m_490 = (s32) (this->m_490 + 1);
}

void TBoss8Dragon::scale_size(f32 farg0, f32 farg1, f32 farg2) {
    this->m_474 = (f32) (this->m_474 * farg0);
    *(f32 *)&this->unk_478 = (f32) (*(f32 *)&this->unk_478 * farg1);
    this->m_47c = (f32) (this->m_47c * farg0);
    *(s32 *)((s8 *)this + 0x480) = (s32) ((f32) *(s32 *)((s8 *)this + 0x480) * farg2);
}

void TBoss8Dragon::fire_at_angle(s32 arg1) {
    turn_toward_angle_limited__13TBoss5GryphonFPvii(this, arg1, (s32) (lbl_80437EB0 * atan2_float(-*(f32 *)&this->m_38, -this->m_40)));
}

void TBoss5Gryphon::update_heading(s32 arg1) {
    update_velocity__9TObjEneDDFv();
    turn_toward_angle_limited__13TBoss5GryphonFPvii(this, arg1, (s32) (lbl_80437EB0 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), this->m_3a8)));
}

void turn_toward_angle_limited__13TBoss5GryphonFPvii(void *selfv, s32 arg1, s32 arg2) {
    s32 t;
    s32 v;

    t = angle_diff_s16(((Obj_8005F968 *)selfv)->f60, arg2);
    t = angle_diff_s16((s32)((f32)t * lbl_805D8DA0), ((Obj_8005F968 *)selfv)->f480);
    v = (t < -arg1) ? -arg1 : ((t < arg1) ? t : arg1);
    ((Obj_8005F968 *)selfv)->f480 = ((Obj_8005F968 *)selfv)->f480 - v;
}

void TBoss8Dragon::update_facing(f32 farg0) {
    update_velocity__9TObjEneDDFv();
    ((s32 (*)(void *, s32, f32))move_along_angle__13TBoss5GryphonFPvif)(this, (s32) (lbl_80437EB0 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), this->m_3a8)), farg0);
}

#pragma push
#pragma fp_contract on
void move_along_angle__13TBoss5GryphonFPvif(void *arg0, s32 arg1, f32 farg0) {
    *(f32 *)((s8 *)arg0 + 0x474) = (f32) ((farg0 * sin_table_lookup(arg1)) + *(f32 *)((s8 *)arg0 + 0x474));
    *(f32 *)((s8 *)arg0 + 0x47C) = (f32) ((farg0 * cos_table_lookup(arg1)) + *(f32 *)((s8 *)arg0 + 0x47C));
}
#pragma pop

s32 TBoss8Dragon__sub_8005FAE0(u8 *arg0) {
    return *(f32 *)((s8 *)arg0 + 0xC8) <= lbl_805D8D5C;
}

void TBoss5Gryphon::advance_motion_entry() {
    s16 *ptr;
    ptr = (s16 *) (*(s32 *)((s8 *)this + 0x4BC) + 0x14);
    *(s32 *)((s8 *)this + 0x4BC) = (s32) ptr;
    ptr = (s16 *) *(s32 *)((s8 *)this + 0x4BC);
    if ((s16) this->mode != *ptr) {
        transition_enemy_state(*ptr);
    }
}

void TBoss5Gryphon::advance_motion_timer() {
    int temp_r4;
    void *temp_r5;
    void *temp_r4b;

    if ((s16) this->mode != 4) {
        temp_r5 = *(void **)((s8 *)this + 0x4BC);
        temp_r4 = (s16) *(s16 *)((s8 *)temp_r5 + 2);
        if (temp_r4 > 0) {
            *(s16 *)((s8 *)temp_r5 + 2) = (s16) (temp_r4 - 1);
            temp_r4b = *(void **)((s8 *)this + 0x4BC);
            if (*(s16 *)((s8 *)temp_r4b + 2) == 0) {
                advance_motion_entry();
            }
        }
    }
}

void TBoss8Dragon__sub_8005FB90(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) (*(f32 *)((s8 *)arg0 + 0x38) + *(f32 *)((s8 *)arg0 + 0x484));
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) (*(f32 *)((s8 *)arg0 + 0x40) + *(f32 *)((s8 *)arg0 + 0x48C));
    *(f32 *)((s8 *)arg0 + 0x484) = (f32) lbl_805D8D5C;
    *(f32 *)((s8 *)arg0 + 0x488) = (f32) lbl_805D8D5C;
    *(f32 *)((s8 *)arg0 + 0x48C) = (f32) lbl_805D8D5C;
}

void TBoss5Gryphon::apply_velocity() {
    Shot_8005FBC4 shot;
    Vec_8005FBC4 v;
    f32 len;
    if (((Obj_8005FBC4 *)this)->flags & 0x10) {
        ((Obj_8005FBC4 *)this)->pos.y += ((Obj_8005FBC4 *)this)->vel.y;
        ((Obj_8005FBC4 *)this)->f60 += ((Obj_8005FBC4 *)this)->f480;
        v.x = ((Obj_8005FBC4 *)this)->vel.x;
        v.y = lbl_805D8D5C;
        v.z = ((Obj_8005FBC4 *)this)->vel.z;
        len = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        this->calc_shot_position((u8 *)(&shot), (f32)v.x, (f32)v.z, (f32)len);
        this->try_move_actor_xz_on_ground((u8 *)&shot);
    } else {
        ((Obj_8005FBC4 *)this)->pos.x += ((Obj_8005FBC4 *)this)->vel.x;
        ((Obj_8005FBC4 *)this)->pos.y += ((Obj_8005FBC4 *)this)->vel.y;
        ((Obj_8005FBC4 *)this)->pos.z += ((Obj_8005FBC4 *)this)->vel.z;
        ((Obj_8005FBC4 *)this)->f60 += ((Obj_8005FBC4 *)this)->f480;
    }
    if (!(((Obj_8005FBC4 *)this)->flags & 0x20)) {
        ((TBoss8Dragon *)((Obj_8005FBC4 *)this))->scale_size(boss5_gryphon_scale_x_table[((Obj_8005FBC4 *)this)->f4e4], boss5_gryphon_scale_y_table[((Obj_8005FBC4 *)this)->f4e4], gryphon_velocity_scale_z_table[((Obj_8005FBC4 *)this)->f4e4]);
    }
}

void handle_message__13TBoss5GryphonFPvi(O_8005FCE4 *self, s32 msg) {
    switch (msg) {
    case 4:
        self->flags |= 0x80;
        queue_destruction__7TObjectFv(self);
        break;
    case 5:
        break;
    case 6: case 7: case 8: case 9: case 10: case 11:
        return;
    }
}

void TBoss8Dragon__sub_8005FD34(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        switch (self->m_4e4) {
        case 0:
            self->m_b8 = 0;
            break;
        case 1:
            self->m_b8 = 4;
            break;
        case 2:
            self->m_b8 = 7;
            break;
        }
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->m_4e4) {
        case 0:
            break;
        case 1:
            TBoss8Dragon__sub_80063EF4((s32)self);
            break;
        case 2:
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8D90, self, self->rotation_y);
            break;
        }
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_8005FE18(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0x17;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        self->m_4c0 &= ~4;
        break;
    case 0:
        advance_animation_playback(self);
        if (objInBand((GameObj *)self, lbl_805D8D80) != 0) {
            self->play_se(0x4003A817);
        }
        if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}


#pragma push
#pragma fp_contract on
#define PLAY_SE(o, id) ((TBoss5Gryphon *)o)->play_se((id))
extern const f32 lbl_805D8DB8;

void TBoss8Dragon__sub_8005FEF8(TBoss5Gryphon *self, s32 event) {
    Vec pos;
    Vec *bones;

    switch (event) {
    case 4:
        self->m_b8 = 2;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        break;
    case 0:
        advance_animation_playback(self);
        if (objInBand((GameObj *)self, lbl_805D8DB8) != 0) {
            bones = (Vec *)((u8 *)self + 0x3C0);
            pos.x = lbl_805D8D74 * (bones[1].x + bones[2].x);
            pos.y = lbl_805D8D74 * (bones[1].y + bones[2].y);
            pos.z = lbl_805D8D74 * (bones[1].z + bones[2].z);
            new TBoss5GryphonSnarl((TObject *)&self->m_4c4, &pos);
            TCameraCtrl::set_shake_preset(1);
            self->play_se(0x40032306);
        }
        if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_80060020(Dragon_80060020 *self, u32 arg1) {
    Vec_80060020 w;
    Vec_80060020 v;
    Vec_80060020 p;
    switch (arg1) {
    case 4:
        self->fB8 = 0x14;
        self->m94();
        ((TBoss8Dragon *)self)->set_phase();
        ((TBoss8Dragon *)self)->reset_radius();
        self->f4C0 |= 4;
        PLAY_SE(self, 0x4003A818);
        subtractive_rng_seed(self->f5F4, self->f4BC->f4);
        self->f5C = 0x4000;
        self->f6E8 = 0;
        self->f6E0 = (f32)self->f4BC->h2 - TWindowSubStatusDisp::round_away_from_zero(lbl_805D8DBC);
        self->f6F4 = lbl_805D8DC4 / ((f32)self->f4BC->h2 - TWindowSubStatusDisp::round_away_from_zero(lbl_805D8DC0));
        self->f6DC = 0;
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->f6DC) {
        case 0: {
            u8 *pl;
            s32 a2;
            s32 ang;
            s32 found;
            f32 r;
            f32 xx = self->pos.x * self->pos.x;
            f32 zz = self->pos.z * self->pos.z;
            if (xx + zz > lbl_805D8DC8) {
                ((TBoss8Dragon *)self)->fire_at_angle(0x100);
            } else {
                ((TBoss5Gryphon *)self)->update_heading(0x100);
            }
            ((TBoss8Dragon *)self)->update_facing(lbl_805D8D90);
            self->pos.y -= self->f6F4;
            self->f64 += 0x3311;
            if (self->f6E8 >= self->f6E0) {
                self->fB8 = 0x16;
                fn_800660B8((u8 *)self);
                self->f6DC = 1;
            }
            found = 0;
            ang = lbl_805D8D7C * calc_random_ratio__10TObjPlayerFv(self->f5F4);
            r = calc_random_ratio__10TObjPlayerFv(self->f5F4);
            if (calc_random_ratio__10TObjPlayerFv(self->f5F4) > lbl_805D8D74) {
                pl = ((u8 *(*)(u16))get_player_by_client_id)((s32)(lbl_805D8DCC * calc_random_ratio__10TObjPlayerFv(self->f5F4)));
                if (is_alive__9TObjEneDDFv(pl) != 0) {
                    Hit_80060020 *hit;
                    r *= lbl_805D8DD0;
                    do {
                        v.x = r * sin_table_lookup(ang) + ((Vec_80060020 *)(pl + 0x38))->x;
                        v.y = lbl_805D8DD0 + ((Vec_80060020 *)(pl + 0x38))->y;
                        v.z = r * cos_table_lookup(ang) + ((Vec_80060020 *)(pl + 0x38))->z;
                        hit = (Hit_80060020 *)csnVecterUnder((s32 *)&v, 0x16EF);
                        ang += 0x2000;
                    } while (hit == NULL || hit->p->y > lbl_805D8D70);
                    found = 1;
                }
            }
            if (found == 0) {
                Hit_80060020 *hit;
                r *= lbl_805D8DD4;
                do {
                    v.x = r * sin_table_lookup(ang);
                    v.y = lbl_805D8D5C;
                    v.z = r * cos_table_lookup(ang);
                    hit = (Hit_80060020 *)csnVecterUnder((s32 *)&v, 0x16EF);
                    r -= lbl_805D8DCC;
                } while (hit == NULL || hit->p->y > lbl_805D8D70);
            }
            {
                a2 = lbl_80437EB0 * atan2_float(v.x - self->pos.x, v.z - self->pos.z);
                w.x = lbl_805D8DD0 * sin_table_lookup(a2) + self->pos.x;
                w.y = lbl_805D8DD0 + self->pos.y;
                w.z = lbl_805D8DD0 * cos_table_lookup(a2) + self->pos.z;
            }
            if (self->f6E8 % 5 == 0) {
                fn_80351DA8(self, &w, &v, 0x28, 0x11);
            }
            if (self->f6E8 == 0x14) {
                PLAY_SE(self, 0x40033C12);
            }
            self->f6E8++;
            break;
        }
        case 1: {
            f32 s;
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8D88, self, self->f60);
            self->pos.y -= self->f6F4;
            s = ((TObjEneDD_ST *)self)->get_speed_or_default();
            self->f5C = lbl_805D8D7C - lbl_805D8DD8 * (lbl_805D8D88 - s / lbl_805D8DDC);
            self->f64 = lbl_805D8DE0 * (lbl_805D8DDC - s) * (lbl_805D8DDC - s);
            if (objInBand((GameObj *)self, (f32)lbl_805D8DDC) != 0) {
                self->f5C = 0;
                self->f64 = 0;
                self->f6DC = 2;
            }
            break;
        }
        case 2:
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8D88, self, self->f60);
            self->pos.y -= self->f6F4;
            if (objInBand((GameObj *)self, (f32)lbl_805D8DE4) != 0) {
                ((TBoss8Dragon *)self)->clear_timer();
                ((TBoss8Dragon *)self)->reset_angle();
                PLAY_SE(self, 0x40032D0D);
                p.x = self->pos.x;
                p.y = lbl_805D8D5C;
                p.z = self->pos.z;
                spawn_particle_effect_with_flags(&p, self->f5F0->f4, 0x40);
                TCameraCtrl::set_shake_preset(1);
                ((void (*)(void *))TBoss8Dragon__sub_800646F0)(self);
                self->f6DC = 3;
            }
            break;
        case 3:
            break;
        }
        break;
    case 5:
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        self->f5C = 0;
        self->f64 = 0;
        self->f4C0 &= ~4;
        break;
    case 8:
        switch (self->f6DC) {
        case 0:
        case 1:
            ((TBoss8Dragon *)self)->update_periodic_effect();
            break;
        case 2:
        case 3:
            break;
        }
        break;
    case 11:
        break;
    }
}
#pragma pop

extern const f32 lbl_805D8DE8;
extern const f32 lbl_805D8DF0;

void TBoss8Dragon__sub_800605E8(TBoss5Gryphon *self, s32 event) {
    f32 speed;

    switch (event) {
    case 4:
        self->m_b8 = 0x13;
        self->vfunc_96();
        set_flag_4e4__12TBoss8DragonFPv(self);
        self->reset_float_3c();
        self->m_4c0 |= 4;
        self->m_6e0 = 0;
        self->m_6dc = 0;
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->m_6dc) {
        case 0: {
            f32 t;
            speed = lbl_805D8DE8;
            t = self->get_speed_or_default();
            self->position[1] = lbl_805D8DEC + lbl_805D8DF0 * (t * t) / lbl_805D8DF4;
            if (objInBand((GameObj *)self, lbl_805D8DF8) != 0) {
                self->m_6e0 = 0;
                self->m_6dc = 1;
            }
            break;
        }
        case 1:
            self->position[1] += lbl_805D8D8C;
            speed = lbl_805D8DE8;
            self->m_6e0++;
            if (self->m_6e0 >= 0x28) {
                ((TBoss8Dragon *)self)->set_phase();
                ((TBoss8Dragon *)self)->reset_radius();
                self->rotation_x = 0x4000;
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle__13TBoss5GryphonFPvif(self, self->rotation_y, speed);
        break;
    case 5:
        self->m_4c0 &= ~4;
        ((TBoss8Dragon *)self)->set_phase();
        ((TBoss8Dragon *)self)->reset_radius();
        self->rotation_x = 0x4000;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_80060788(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0x12;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        break;
    case 0:
        advance_animation_playback(self);
        if (objInBand((GameObj *)self, lbl_805D8D70) != 0) {
            self->play_se(0x40032D10);
        }
        if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_8006084C(TBoss5Gryphon *self, s32 event) {
    Vec left;
    Vec right;

    switch (event) {
    case 4:
        self->m_b8 = 0x11;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        self->demo->draw_linked_model(self->position, self->rotation_y);
        self->m_6e4 = 0;
        push_matrix();
        set_matrix_identity(NULL);
        post_translate_matrix(self->position);
        rotate_matrix_y(0, self->rotation_y);
        matrix_mult_vec(0, lbl_804880AC, &left);
        matrix_mult_vec(0, lbl_804880B8, &right);
        pop_matrix();
        self->m_6dc = TBoss8Dragon::spawn_ground_lightning((s32)self, (s32)&left, self->rotation_y);
        self->m_6e0 = TBoss8Dragon::spawn_ground_lightning((s32)self, (s32)&right, self->rotation_y);
        subtractive_rng_seed(self->rng, self->motion->m_4);
        break;
    case 0:
        advance_animation_playback(self);
        TBoss8Dragon__sub_800641A8((u8 *)self);
        if (*(s32 *)(*(u8 **)(boss5_gryphon_behavior_params.remaining + 4) + 0x28) >= 2) {
            self->spawn_lightning_effect();
            TBoss8Dragon__sub_80063FB8((s32)self, (s32)self->position, lbl_805D8DF0);
        }
        if (*(s32 *)(*(u8 **)(boss5_gryphon_behavior_params.remaining + 4) + 0x28) >= 4 && self->m_6e4 % 20 == 0) {
            TBoss8Dragon__sub_8005D9BC((u8 *)self, (self->m_6e4 / 20) & 1 ? 0 : 1, lbl_805D8DCC * calc_random_ratio__10TObjPlayerFv(self->rng));
        }
        spawn_ancient_trap__12TBoss8DragonFii((s32)self, 0x40032D11);
        self->m_6e4++;
        break;
    case 5:
        if ((TBoss8Dragon *)self->m_6e0 != NULL) {
            ((TBoss8Dragon *)self->m_6e0)->queue_destruction();
            self->m_6e0 = 0;
        }
        if ((TBoss8Dragon *)self->m_6dc != NULL) {
            ((TBoss8Dragon *)self->m_6dc)->queue_destruction();
            self->m_6dc = 0;
        }
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8DFC;

void TBoss8Dragon__sub_80060A58(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0x10;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        break;
    case 0:
        advance_animation_playback(self);
        if (objInBand((GameObj *)self, lbl_805D8DFC) != 0) {
            self->play_se(0x4003320F);
        }
        if (self->m_b4 == 0x11) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_80060B18(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0xF;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        self->demo->draw_linked_model(self->position, self->rotation_y);
        break;
    case 0:
        advance_animation_playback(self);
        TBoss8Dragon__sub_800641A8((u8 *)self);
        if (objInBand((GameObj *)self, lbl_805D8DF8) != 0) {
            self->demo->get_state();
        }
        if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_80060BF8(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0xE;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        self->demo->draw_linked_model(self->position, self->rotation_y);
        break;
    case 0:
        advance_animation_playback(self);
        TBoss8Dragon__sub_800641A8((u8 *)self);
        break;
    case 5:
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_80060CA4(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0xD;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        break;
    case 0:
        advance_animation_playback(self);
        TBoss8Dragon__sub_800641A8((u8 *)self);
        if (objInBand((GameObj *)self, lbl_805D8DDC) != 0) {
            self->demo->draw_linked_model(self->position, self->rotation_y);
        }
        if (objInBand((GameObj *)self, lbl_805D8D88) != 0) {
            self->play_se(0x40032D0E);
        }
        if (self->m_b4 == 0xE) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss8Dragon__sub_80060D9C(TBoss5Gryphon *self, s32 event) {
    Vec at;
    f32 v;
    f32 speed;
    f32 scale;
    f32 depth;

    switch (event) {
    case 4:
        self->m_b8 = 0xC;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        self->m_4c0 |= 0x30;
        break;
    case 0:
        advance_animation_playback(self);
        v = self->get_speed_or_default();
        speed = lbl_805D8D5C;
        if (v < lbl_805D8E00) {
            depth = lbl_805D8E04;
            scale = lbl_805D8DA4;
        } else {
            depth = lbl_805D8E04;
            scale = lbl_805D8E08;
        }
        if (objInBand((GameObj *)self, lbl_805D8D90) != 0) {
            speed += lbl_805D8E0C;
        }
        ((TBoss8Dragon *)self)->scale_size(scale, depth, depth);
        move_along_angle__13TBoss5GryphonFPvif(self, self->rotation_y, speed);
        if (objInBand((GameObj *)self, lbl_805D8E00) != 0) {
            at.x = self->position[0];
            at.y = lbl_805D8D5C;
            at.z = self->position[2];
            spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
            TBoss8Dragon__sub_800646F0((s32)self);
            self->play_se(0x40032D0D);
        }
        if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        self->m_4c0 &= ~0x30;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void state_move__13TBoss5GryphonFPvi(Obj_80060F4C *arg0, s32 arg1) {
    f32 speed;
    f32 scale;
    f32 depth;
    f32 v;
    s32 ang;
    switch (arg1) {
    case 4:
        arg0->fb8 = 0xB;
        ((TBoss5Gryphon *)arg0)->vfunc_96();
        ((TBoss8Dragon *)arg0)->clear_timer();
        ((TBoss8Dragon *)arg0)->reset_angle();
        arg0->flags |= 0x30;
        return;
    case 8:
        ((TBoss8Dragon *)arg0)->update_periodic_effect();
        return;
    case 0:
        ((s32 (*)(void *))advance_animation_playback)(arg0);
        ((void (*)(void *))TBoss8Dragon__sub_80064DB8)(arg0);
        ((void (*)(void *))update_velocity__9TObjEneDDFv)(arg0);
        TBoss8Dragon__sub_8006426C((Obj_8006426C *)(arg0));
        ((void (*)(void *))TBoss8Dragon__sub_80064828)(arg0);
        v = ((TObjEneDD_ST *)arg0)->get_speed_or_default();
        if (v < lbl_805D8E10 || v >= lbl_805D8DE4) {
            depth = lbl_805D8E04;
            ang = 0;
            speed = lbl_805D8D5C;
            scale = lbl_805D8DA4;
        } else {
            depth = lbl_805D8E04;
            ang = 0xD0;
            speed = lbl_805D8D88;
            scale = lbl_805D8E08;
        }
        if (objInBand((GameObj *)arg0, (f32)lbl_805D8D74) != 0) {
            ang += 0x500;
            speed += lbl_805D8E14;
        }
        ((TBoss8Dragon *)arg0)->scale_size(scale, depth, depth);
        move_along_angle__13TBoss5GryphonFPvif(arg0, arg0->f60, speed);
        ((TBoss5Gryphon *)arg0)->update_heading(ang);
        return;
    case 5:
        arg0->flags &= ~0x30;
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss8Dragon__sub_800610D0(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 0xA;
        self->vfunc_96();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        break;
    case 0:
        advance_animation_playback(self);
        if (self->m_b4 == 0xB) {
            self->advance_motion_entry();
        }
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}


struct VBase_80061434 { char pad[0x18]; };
struct VObj_80061434 : VBase_80061434 {
#define V(n) virtual void m##n();
V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)
V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)
V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)V(50)V(51)V(52)V(53)V(54)V(55)V(56)V(57)V(58)V(59)
V(60)V(61)V(62)V(63)V(64)V(65)V(66)V(67)V(68)V(69)V(70)V(71)V(72)V(73)V(74)V(75)V(76)V(77)V(78)V(79)
V(80)V(81)V(82)V(83)V(84)V(85)V(86)V(87)V(88)V(89)V(90)V(91)V(92)V(93)V(94)
#undef V
};
struct Vec_80061434 { f32 x, y, z; };

s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, s32, s32, void *, f32);
extern const f32 lbl_805D8E38;

void handle_descend_state__13TBoss5GryphonFPvi(TBoss5Gryphon *arg0, s32 arg1) {
    Vec_80061434 out;
    Vec_80061434 at;

    switch (arg1) {
    case 4:
        arg0->m_b8 = 0x16;
        ((VObj_80061434 *)arg0)->m94();
        set_flag_4e4__12TBoss8DragonFPv(arg0);
        arg0->reset_float_3c();
        *(u32 *)((s8 *)arg0 + 0x4C0) |= 4;
        arg0->update_particle_positions();
        *(s32 *)((s8 *)arg0 + 0x6DC) = 0;
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x6DC)) {
        case 0:
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8E38, arg0, arg0->rotation_y);
            eval_bezier_curve__12TBoss8DragonFPviiPvf(boss5_gryphon_descend_bezier_points, 4, 0, &out, ((TObjEneDD_ST *)arg0)->get_speed_or_default() / lbl_805D8DE4);
            *(f32 *)((s8 *)arg0 + 0x3C) = out.y;
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8DE4) != 0) {
                ((TBoss8Dragon *)arg0)->clear_timer();
                ((TBoss8Dragon *)arg0)->reset_angle();
                arg0->play_se(0x40032D0D);
                at.x = *(f32 *)((s8 *)arg0 + 0x38);
                at.y = lbl_805D8D5C;
                at.z = *(f32 *)((s8 *)arg0 + 0x40);
                spawn_particle_effect_with_flags(&at, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x5F0)) + 4), 0x40);
                TCameraCtrl::set_shake_preset(1);
                TBoss8Dragon__sub_800646F0((s32)arg0);
                *(s32 *)((s8 *)arg0 + 0x6DC) = 1;
            }
            break;
        case 1:
            if (TBoss8Dragon__sub_8005FAE0((u8 *)arg0) != 0) {
                arg0->advance_motion_entry();
            }
            break;
        }
        if (objInBand((GameObj *)arg0, (f32)lbl_805D8DCC) != 0) {
            arg0->spawn_ground_splash();
        }
        break;
    case 5:
        *(u32 *)((s8 *)arg0 + 0x4C0) &= ~0x104;
        arg0->free_parts();
        break;
    case 10: case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8E28;
extern const f32 lbl_805D8E3C;
extern const f32 lbl_805D8E40;
extern const f32 lbl_805D8E44;

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_800615FC(TBoss5Gryphon *self, s32 event) {
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case 4:
        self->m_b8 = 0x13;
        self->vfunc_96();
        set_flag_4e4__12TBoss8DragonFPv(self);
        self->reset_float_3c();
        self->m_4c0 |= 0x104;
        self->m_6dc = 0;
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->m_6dc) {
        case 0:
            speed = lbl_805D8E34;
            self->position[1] = lbl_805D8D50 * sin_table_lookup((s32)(lbl_805D8E28 * self->get_speed_or_default() / lbl_805D8E14)) + lbl_805D8DEC;
            if (objInBand((GameObj *)self, lbl_805D8E14) != 0) {
                self->m_6dc = 1;
                self->m_6e0 = 0;
            }
            break;
        case 1:
            t = self->m_6e0;
            speed = lbl_805D8E3C;
            if ((f32)t < *(const f32 *)&lbl_805D8E10) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E10));
                d = lbl_805D8E40 * d + lbl_805D8E40;
                self->position[1] = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x14 - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E10));
                d = -lbl_805D8E40 * d + lbl_805D8E40;
                self->position[1] = lbl_805D8E20 + d;
            }
            self->rotation_x = (s32)(lbl_805D8E44 * f / lbl_805D8E10);
            self->m_6e0++;
            if (self->m_6e0 > 0x14) {
                ((TBoss8Dragon *)self)->set_attack_phase();
                ((TBoss8Dragon *)self)->set_anim_speed();
                self->rotation_x = 0;
                self->m_6dc = 2;
            }
            break;
        case 2:
            speed = lbl_805D8E3C;
            if (self->m_b4 == 0x14) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle__13TBoss5GryphonFPvif(self, self->rotation_y, speed);
        if (objInBand((GameObj *)self, lbl_805D8DF8) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case 5:
        self->m_4c0 &= ~4;
        ((TBoss8Dragon *)self)->set_attack_phase();
        ((TBoss8Dragon *)self)->set_anim_speed();
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

extern const f32 lbl_805D8E1C;
extern const f32 lbl_805D8E18;
extern const f32 lbl_805D8E28;
extern const f32 lbl_805D8E2C;
extern const f32 lbl_805D8E4C;
extern const f32 lbl_805D8E48;
extern const f32 lbl_805D8E50;
#pragma push
#pragma fp_contract on
void update_dive_motion__12TBoss8DragonFPvi(u8 *arg0, s32 arg1) {
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (arg1) {
    case 10:
    case 11:
        break;
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 7;
        ((VObj_80061434 *)arg0)->m94();
        set_flag_4e4__12TBoss8DragonFPv(arg0);
        ((TBoss5Gryphon *)arg0)->reset_float_3c();
        *(s32 *)((s8 *)arg0 + 0x4C0) |= 4;
        ((TBoss5Gryphon *)arg0)->enable_particles();
        *(s32 *)((s8 *)arg0 + 0x6DC) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x6DC)) {
        case 0:
            t = *(s32 *)((s8 *)arg0 + 0x6E0);
            speed = lbl_805D8E18;
            if ((f32)t < *(const f32 *)&lbl_805D8E1C) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E1C));
                d = -lbl_805D8E48 * d + lbl_805D8E48;
                *(f32 *)((s8 *)arg0 + 0x3C) = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x27 - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E1C));
                d = lbl_805D8E48 * d + lbl_805D8E48;
                *(f32 *)((s8 *)arg0 + 0x3C) = lbl_805D8E20 + d;
            }
            *(s32 *)((s8 *)arg0 + 0x5C) = (s32)(-(lbl_805D8E2C * f) / lbl_805D8E1C);
            (*(s32 *)((s8 *)arg0 + 0x6E0))++;
            if (*(s32 *)((s8 *)arg0 + 0x6E0) == 0x11) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 8;
            } else if (*(s32 *)((s8 *)arg0 + 0x6E0) > 0x27) {
                *(f32 *)((s8 *)arg0 + 0x3C) = lbl_805D8E4C;
                *(s32 *)((s8 *)arg0 + 0x5C) = 0;
                *(s32 *)((s8 *)arg0 + 0x6DC) = 1;
            }
            break;
        case 1:
            speed = lbl_805D8E34;
            f = *(f32 *)((s8 *)arg0 + 0xC4) - lbl_805D8E10;
            d = ((TObjEneDD_ST *)arg0)->get_speed_or_default() - lbl_805D8E10;
            *(f32 *)((s8 *)arg0 + 0x3C) = lbl_805D8E4C - lbl_805D8E50 * sin_table_lookup((s32)(lbl_805D8E28 * d / f));
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8DE4) != 0) {
                ((TBoss5Gryphon *)arg0)->spawn_ground_splash();
            }
            if (TBoss8Dragon__sub_8005FAE0(arg0) != 0) {
                ((TBoss5Gryphon *)arg0)->advance_motion_entry();
            }
            break;
        }
        move_along_angle__13TBoss5GryphonFPvif(arg0, *(s32 *)((s8 *)arg0 + 0x60), speed);
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x4C0) &= ~4;
        ((TBoss5Gryphon *)arg0)->destroy_parts();
        *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        break;
    }
}

#pragma pop

void TBoss8Dragon__sub_80061B8C(TBoss5Gryphon *self, s32 event) {
    Vec out;
    Vec at;

    switch (event) {
    case 4:
        self->m_b8 = 9;
        self->vfunc_96();
        set_flag_4e4__12TBoss8DragonFPv(self);
        self->reset_float_3c();
        self->m_4c0 |= 4;
        self->enable_particles();
        self->m_6dc = 0;
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->m_6dc) {
        case 0:
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8E38, self, self->rotation_y);
            eval_bezier_curve__12TBoss8DragonFPviiPvf(lbl_8048802C, 4, 0, &out, self->get_speed_or_default() / lbl_805D8D50);
            self->position[1] = out.y;
            if (objInBand((GameObj *)self, lbl_805D8D50) != 0) {
                ((TBoss8Dragon *)self)->clear_timer();
                ((TBoss8Dragon *)self)->reset_angle();
                self->play_se(0x40032D0D);
                at.x = self->position[0];
                at.y = lbl_805D8D5C;
                at.z = self->position[2];
                spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
                TCameraCtrl::set_shake_preset(1);
                TBoss8Dragon__sub_800646F0((s32)self);
                self->m_6dc = 1;
            }
            break;
        case 1:
            if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        break;
    case 5:
        self->m_4c0 &= ~4;
        self->destroy_parts();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8E54;

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_80061D34(TBoss5Gryphon *self, s32 event) {
    s32 ofs;
    s32 a;
    s32 d;
    s32 v;
    f32 speed;

    switch (event) {
    case 4:
        if (self->m_4c0 & 0x100) {
            self->m_b8 = 0x14;
        } else {
            self->m_b8 = 7;
        }
        self->vfunc_96();
        ((TBoss8Dragon *)self)->set_attack_phase();
        ((TBoss8Dragon *)self)->set_anim_speed();
        break;
    case 0:
        advance_animation_playback(self);
        ofs = 0x4000;
        if (self->position[0] * self->position[0] + self->position[2] * self->position[2] > self->motion->m_c) {
            ofs = 0x5000;
        }
        speed = self->motion->m_8;
        a = (s32)(lbl_80437EB0 * atan2_float(self->position[0], self->position[2]));
        if (self->motion->m_4 > 0) {
            a += ofs;
            d = angle_diff_s16(self->rotation_y, a);
            if (d > 0) {
                self->m_480 += self->motion->m_4;
            }
        } else {
            a -= ofs;
            d = angle_diff_s16(self->rotation_y, a);
            if (d < 0) {
                self->m_480 += self->motion->m_4;
            }
        }
        if (fabs_float((f32)d) > lbl_805D8E44) {
            speed *= lbl_805D8DB0;
        }
        move_along_angle__13TBoss5GryphonFPvif(self, self->rotation_y, speed);
        if ((f32)self->motion->timer > lbl_805D8D70) {
            v = (s32)(lbl_805D8E54 * (f32)self->m_480);
            v = (v < -0x600) ? -0x600 : ((v < 0x600) ? v : 0x600);
            d = angle_diff_s16(self->rotation_z, v);
            self->rotation_z = (s32)(lbl_805D8DB4 * (f32)d + (f32)self->rotation_z);
        } else {
            self->rotation_z -= self->rotation_z / self->motion->timer;
        }
        if (self->m_4c0 & 0x100) {
            TBoss8Dragon__sub_8006435C((u8 *)self);
            TBoss8Dragon__sub_8005E39C((Obj_8005E39C *)self);
        } else {
            TBoss8Dragon__sub_8006442C((Dragon_8006442C *)self);
            self->update_ground_effects();
            spawn_ancient_trap__12TBoss8DragonFii((s32)self, 0x40032802);
        }
        break;
    case 5:
        self->rotation_z = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

extern const f32 lbl_805D8E58;

void TBoss8Dragon__sub_80062018(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        if (self->m_4c0 & 0x100) {
            self->m_b8 = 0x14;
        } else {
            self->m_b8 = 7;
        }
        self->vfunc_96();
        ((TBoss8Dragon *)self)->set_attack_phase();
        ((TBoss8Dragon *)self)->set_anim_speed();
        self->m_6e0 = 0;
        break;
    case 0:
        advance_animation_playback(self);
        ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8E58, self, self->rotation_y);
        if (self->m_4c0 & 0x100) {
            TBoss8Dragon__sub_8006435C((u8 *)self);
            TBoss8Dragon__sub_8005E39C((Obj_8005E39C *)self);
        } else {
            TBoss8Dragon__sub_8006442C((Dragon_8006442C *)self);
            self->update_ground_effects();
            spawn_ancient_trap__12TBoss8DragonFii((s32)self, 0x40032802);
        }
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8E48;
extern const f32 lbl_805D8E50;
extern const f32 lbl_805D8E5C;

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_80062114(TBoss5Gryphon *self, s32 event) {
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case 4:
        self->m_b8 = 6;
        self->vfunc_96();
        set_flag_4e4__12TBoss8DragonFPv(self);
        self->reset_float_3c();
        self->m_4c0 |= 4;
        self->m_6dc = 0;
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->m_6dc) {
        case 0:
            speed = lbl_805D8E34;
            self->position[1] = lbl_805D8E50 * sin_table_lookup((s32)(lbl_805D8E28 * self->get_speed_or_default() / lbl_805D8E5C)) + lbl_805D8DEC;
            if (objInBand((GameObj *)self, lbl_805D8E5C) != 0) {
                self->m_6dc = 1;
                self->m_6e0 = 0;
            }
            break;
        case 1:
            t = self->m_6e0;
            speed = lbl_805D8E3C;
            if ((f32)t < *(const f32 *)&lbl_805D8E00) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E00));
                d = lbl_805D8E48 * d + lbl_805D8E48;
                self->position[1] = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x1E - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E00));
                d = -lbl_805D8E48 * d + lbl_805D8E48;
                self->position[1] = lbl_805D8E20 + d;
            }
            self->rotation_x = (s32)(lbl_805D8E44 * f / lbl_805D8E00);
            self->m_6e0++;
            if (self->m_6e0 > 0x1E) {
                ((TBoss8Dragon *)self)->set_attack_phase();
                ((TBoss8Dragon *)self)->set_anim_speed();
                self->rotation_x = 0;
                self->m_6dc = 2;
            }
            break;
        case 2:
            speed = lbl_805D8E3C;
            if (self->m_b4 == 7) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle__13TBoss5GryphonFPvif(self, self->rotation_y, speed);
        if (objInBand((GameObj *)self, lbl_805D8E10) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case 5:
        self->m_4c0 &= ~4;
        ((TBoss8Dragon *)self)->set_attack_phase();
        ((TBoss8Dragon *)self)->set_anim_speed();
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

void TBoss8Dragon__sub_80062550(Obj_80062550 *arg0, s32 arg1) {
    s32 ofs;
    s32 ang;
    s32 a;
    Tgt_80062550 *t;
    switch (arg1) {
    case 4:
        arg0->fb8 = 4;
        ((VObj_80062550 *)arg0)->m94();
        set_flag_4e4__12TBoss8DragonFPv(arg0);
        ((TBoss5Gryphon *)arg0)->reset_float_3c();
        arg0->f490 = 0;
        return;
    case 8:
        ((TBoss8Dragon *)arg0)->update_periodic_effect();
        return;
    case 0:
        ((s32 (*)(void *))advance_animation_playback)(arg0);
        TBoss8Dragon__sub_80063EF4((s32)arg0);
        ofs = 0x4000;
        if (arg0->pos.x * arg0->pos.x + arg0->pos.z * arg0->pos.z > arg0->f4bc->f10 * arg0->f4bc->f10) {
            ofs = 0x5000;
        }
        a = (s32)(((const f64 *)&lbl_80437EB0)[0] * atan2_float(arg0->pos.x, arg0->pos.z));
        t = arg0->f4bc;
        ang = a - ofs;
        if (t->f8 > 0) {
            ang = a + ofs;
        }
        move_along_angle__13TBoss5GryphonFPvif(arg0, ang, t->fc);
        ((TBoss5Gryphon *)arg0)->update_heading(arg0->f4bc->f4);
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss8Dragon__sub_80062660(TBoss5Gryphon *self, s32 event) {
    switch (event) {
    case 4:
        self->m_b8 = 4;
        self->vfunc_96();
        set_flag_4e4__12TBoss8DragonFPv(self);
        self->reset_float_3c();
        break;
    case 0:
        advance_animation_playback(self);
        TBoss8Dragon__sub_80063EF4((s32)self);
        move_along_angle__13TBoss5GryphonFPvif(self, self->rotation_y, self->motion->m_8);
        self->m_480 += self->motion->m_4;
        break;
    case 5:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void update_active_player_count__19TPlayerBattleCtrl4PFPvi(void *ene_dd, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd)->m_b8 = 0;
        *(s32 *)((s8 *)ene_dd + 0x6DC) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_dd + 0x6DC) > 0x96) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(0xB);
        }
    case 5:
    case 1:
        return;
    case 0:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            *(s32 *)((s8 *)ene_dd + 0x6DC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x6DC) + 1);
        }
        break;
    }
}

void TBoss3Volopt__sub_800627E4(u8 *arg0, u32 arg1) {
    s32 *p = (s32 *)(arg0 + 0x6E8);
    u8 sp8[0xC];
    void *obj;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        ((s32 (*)(void))set_flag_4e4__12TBoss8DragonFPv)();
        ((TBoss5Gryphon *)arg0)->reset_float_3c();
        ((s32 (*)(void *))advance_animation_playback)((void *)arg0);
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805D8D5C;
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805D8D5C;
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805D8D5C;
        *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        *(s32 *)((s8 *)arg0 + 0x60) = 0;
        *(s32 *)((s8 *)arg0 + 0x64) = 0;
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x6DC) = 0;
            break;
        }
        *(s32 *)((s8 *)arg0 + 0x4C0) |= 0x80;
        *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        *p = 1;
        obj = __nw__7TObjectFUl(0x28);
        if (obj != NULL) {
            __ct__17TBoss5GryphonDemoFP7TObjectlf(obj, tl_01, p, lbl_805D8D88);
        }
        *(s16 *)((s8 *)arg0 + 0xB8) = 0x19;
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)arg0)->get_target_state_b();
        return;
    case 2:
    case 9:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x6DC) == 1) {
            TBoss8Dragon::init_state_zero((void *)arg0);
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x6DC)) {
        case 0:
            ((s32 (*)(void *))advance_animation_playback)((void *)arg0);
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x6DC) = 1;
                TWindowCtrl::init_all_slots2();
                *(s16 *)((s8 *)arg0 + 0xB8) = 4;
            }
            switch (*(s32 *)((s8 *)arg0 + 0x6E4)) {
            case 0:
                if (objInBand((GameObj *)(arg0), (f32)lbl_805D8E60) != 0) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *)sp8, (void *)boss5_gryphon_waypoint_vecs);
                    ((s32 (*)(void *, void *, int))spawn_particle_effect_with_flags)((void *)sp8, (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x5F0)) + 4)), 0x40);
                    start_pad_rumble_all(0x1C, 0x3C);
                } else if (objInBand((GameObj *)(arg0), (f32)lbl_805D8E64) != 0) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *)sp8, (void *) ((u8 *)boss5_gryphon_waypoint_vecs + 0xC));
                    ((s32 (*)(void *, void *, int))spawn_particle_effect_with_flags)((void *)sp8, (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x5F0)) + 4)), 0x40);
                    start_pad_rumble_all(0xC0, 0xF);
                } else if ((objInBand((GameObj *)(arg0), (f32)lbl_805D8E68) != 0) || (objInBand((GameObj *)(arg0), (f32)lbl_805D8E6C) != 0)) {
                    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *)sp8, (void *) ((u8 *)boss5_gryphon_waypoint_vecs + 0xC));
                    ((s32 (*)(void *, void *, int))spawn_particle_effect_with_flags)((void *)sp8, (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x5F0)) + 0)), 0x40);
                }
                if (objInBand((GameObj *)(arg0), (f32)lbl_805D8E70) != 0) {
                    play_sound_effect(0x40032A00, (void *) (0), 0, 0);
                    start_pad_rumble_all(0xA0, 0x3C);
                }
                if ((objInBand((GameObj *)(arg0), (f32)lbl_805D8D6C) != 0) || (objInBand((GameObj *)(arg0), (f32)lbl_805D8E74) != 0)) {
                    play_sound_effect(0x40033409, (void *) (0), 0, 0);
                }
                if (objInBand((GameObj *)(arg0), (f32)lbl_805D8E64) != 0) {
                    play_sound_effect(0x40032D0D, (void *) (0), 0, 0);
                }
                if (objInBand((GameObj *)(arg0), (f32)lbl_805D8E78) != 0) {
                    play_sound_effect(0x40033409, (void *) (0), 0, 0);
                    start_pad_rumble_all(0x80, 7);
                }
                if (objInBand((GameObj *)(arg0), (f32)lbl_805D8E7C) != 0) {
                    TObjBoss5Ctrl::play_pillar_sound();
                }
                break;
            }
            break;
        case 1:
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) ((u8 *)arg0 + 0x38), (void *)lbl_80437DC4);
            ((TObjPlayer *)((u8 *)arg0 + 0x5C))->copy_xyz((void *)lbl_80437DD0);
            ((s32 (*)(void *))advance_animation_playback)((void *)arg0);
            return;
        }
        break;
    case 5:
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((void *) ((u8 *)arg0 + 0x38), (void *)lbl_80437DC4);
        ((TObjPlayer *)((u8 *)arg0 + 0x5C))->copy_xyz((void *)lbl_80437DD0);
        *(f32 *)((s8 *)arg0 + 0x484) = (f32) lbl_805D8D5C;
        *(f32 *)((s8 *)arg0 + 0x488) = (f32) lbl_805D8D5C;
        *(f32 *)((s8 *)arg0 + 0x48C) = (f32) lbl_805D8D5C;
        *p = 0;
        *(s32 *)((s8 *)arg0 + 0x4C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x4C0) & 0xFFFFFF7F);
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)arg0)->get_target_state_a();
        break;
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma push
#pragma fp_contract on
#define F(t, o) (*(t *)(arg0 + (o)))
void TBoss8Dragon__sub_80062BA0(u8 *arg0, u32 arg1) {
    Cam_80062BA0 cam;
    Vec_80062BA0 v;
    Vec_80062BA0 tmp;
    Vec_80062BA0 *p;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x1A;
        ((VObj_18_81e212 *)(arg0))->m93();
        set_flag_4e4__12TBoss8DragonFPv(arg0);
        ((TBoss5Gryphon *)arg0)->reset_float_3c();
        F(s32, 0x4C0) |= 0xC4;
        F(s32, 0x6DC) = 0;
        F(s32, 0x6E0) = 0;
        F(f32, 0x6F4) = lbl_805D8D5C;
        p = (Vec_80062BA0 *)TBoss8Dragon__sub_80065F08();
        F(s32, 0x60) = (s32)(lbl_80437EB0 * atan2_float(p->x - F(f32, 0x38), p->z - F(f32, 0x40)));
        F(f32, 0x38) = p->x - lbl_805D8E80 * sin_table_lookup(F(s32, 0x60));
        F(f32, 0x3C) = lbl_805D8DD4;
        F(f32, 0x40) = p->z - lbl_805D8E80 * cos_table_lookup(F(s32, 0x60));
        play_cue_stream_file((s32)lbl_80437EC0);
        TWindowCtrl::init_all_slots();
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
            cam.b = 0;
            cam.a = 2;
            cam.c = 0;
            cam.d = lbl_805D8D5C;
            cam.e = lbl_805D8D74;
            activate_camera_mode(5);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x31C7);
            set_scripted_camera_pose(arg0 + 0x38, arg0 + 0x38, arg0 + 0x5C);
            break;
        }
        return;
    case 0:
        advance_animation_playback(arg0);
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
        if (objInBand((GameObj *)arg0, (f32)lbl_805D8E84) != 0) {
            v.x = F(f32, 0x38);
            v.y = lbl_805D8E88;
            v.z = F(f32, 0x40);
            spawn_particle_effect_with_flags(&v, 0x201, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            play_sound_effect(0x4003230C, 0, 0, 0);
        }
        }
        switch (F(s32, 0x6DC)) {
        case 0:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x6DC) = 1;
                F(s32, 0x6E0) = 0;
            }
            break;
        case 1:
            F(s32, 0x6E0)++;
            if (F(s32, 0x6E0) >= 50) {
                ((TBoss5Gryphon *)arg0)->advance_motion_entry();
            }
            break;
        }
        break;
    case 5:
        F(s32, 0x4C0) &= ~0x84;
        VecCopy__FP3VecPC3Vec(&tmp, arg0 + 0x38);
        VecCopy__FP3VecPC3Vec(arg0 + 0x38, lbl_80437DB8);
        ((TObjEnemy *)arg0)->update_prev_position();
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        TBoss4DarkFalz::dispatch_by_main_phase(0x52);
        VecCopy__FP3VecPC3Vec(arg0 + 0x38, &tmp);
        ((TObjEnemy *)arg0)->update_prev_position();
        F(s32, 0x30) = 0x12008;
        ((TUnk_804806E8 *)(arg0))->vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

void TBoss8Dragon__sub_80062E94(u8 *arg0, u32 arg1) {
    Vec_80062E94 at;
    f32 d;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 5;
        ((VObj_80062E94 *)arg0)->m94();
        set_flag_4e4__12TBoss8DragonFPv(arg0);
        ((TBoss5Gryphon *)arg0)->reset_float_3c();
        *(u32 *)((s8 *)arg0 + 0x4C0) |= 4;
        *(s32 *)((s8 *)arg0 + 0x6DC) = 0;
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x6DC)) {
        case 0:
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8E04, arg0, *(s32 *)((s8 *)arg0 + 0x60));
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8D88) != 0) {
                *(s32 *)((s8 *)arg0 + 0x6DC) = 1;
            }
            break;
        case 1:
            d = ((TObjEneDD_ST *)arg0)->get_speed_or_default() - lbl_805D8D88;
            *(f32 *)((s8 *)arg0 + 0x3C) = (*(const f32 *)&lbl_805D8DEC) + lbl_805D8E8C * -(d * d) / lbl_805D8E90;
            move_along_angle__13TBoss5GryphonFPvif(arg0, *(s32 *)((s8 *)arg0 + 0x60), lbl_805D8E04);
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8E94) != 0) {
                ((TBoss8Dragon *)arg0)->clear_timer();
                ((TBoss8Dragon *)arg0)->reset_angle();
                ((TBoss5Gryphon *)arg0)->play_se(0x40032D0D);
                at.x = *(f32 *)((s8 *)arg0 + 0x38);
                at.y = lbl_805D8D5C;
                at.z = *(f32 *)((s8 *)arg0 + 0x40);
                spawn_particle_effect_with_flags((void *)(&at), (s32)(*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x5F0)) + 4)), 0x40);
                TCameraCtrl::set_shake_preset(1);
                TBoss8Dragon__sub_800646F0((s32)arg0);
                *(s32 *)((s8 *)arg0 + 0x6DC) = 2;
            }
            break;
        case 2:
            if (((s32 (*)(void *))TBoss8Dragon__sub_8005FAE0)(arg0) != 0) {
                ((TBoss5Gryphon *)arg0)->advance_motion_entry();
            }
            break;
        }
        if (objInBand((GameObj *)arg0, (f32)lbl_805D8E98) != 0) {
            ((TBoss5Gryphon *)arg0)->spawn_ground_splash();
        }
        break;
    case 5:
        ((TBoss8Dragon *)arg0)->clear_timer();
        ((TBoss8Dragon *)arg0)->reset_angle();
        *(u32 *)((s8 *)arg0 + 0x4C0) &= ~4;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on

void TBoss8Dragon__sub_80063088(Obj_80063088 *self, u32 arg1) {
    Vec_80063088 pos;
    Vec_80063088 vel;
    f32 speed;
    void *p;
    switch (arg1) {
    case 4:
        self->fB8 = 0x18;
        self->m94();
        set_flag_4e4__12TBoss8DragonFPv(self);
        ((TBoss5Gryphon *)self)->reset_float_3c();
        self->state = 0;
        self->f6E0 = 0;
        self->fx = NULL;
        self->f490 = 0;
        break;
    case 8:
        ((TBoss8Dragon *)self)->update_periodic_effect();
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->state) {
        case 0:
            self->state = 1;
        case 1:
            if (objInBand((GameObj *)self, (f32)lbl_805D8D54) != 0) {
                ((TBoss5Gryphon *)self)->play_se(0x40033203);
            }
            if (objInBand((GameObj *)self, (f32)lbl_805D8D50) != 0) {
                ((TBoss5Gryphon *)self)->play_se(0x40033204);
            }
            if (objInBand((GameObj *)self, (f32)lbl_805D8D80) != 0) {
                ((TBoss5Gryphon *)self)->spawn_ground_splash();
            }
            speed = ((TObjEneDD_ST *)self)->get_speed_or_default();
            if (self->fx == NULL) {
                if (speed >= lbl_805D8D54 && speed <= lbl_805D8E5C) {
                    self->fx = spawn_continuous_particle_effect_with_flags(&self->fxPos, self->res->fC, 0x40);
                }
            } else if (speed <= lbl_805D8E5C) {
                ((TNowLoading *)(self->fx))->copy_pos(&self->fxPos);
            } else {
                queue_destruction__7TObjectFv(self->fx);
                self->fx = NULL;
            }
            if (objInBand((GameObj *)self, (f32)lbl_805D8E9C) != 0) {
                pos.x = self->f394;
                pos.y = ((Vec_80063088 *)lbl_80437938)->y;
                pos.z = self->f39C;
                vel.x = lbl_805D8EA0 * sin_table_lookup(self->angle);
                vel.y = lbl_805D8D74 * -(self->fxPos.y - ((Vec_80063088 *)lbl_80437938)->y);
                vel.z = lbl_805D8EA0 * cos_table_lookup(self->angle);
                p = __nw__7TObjectFUl(0x70);
                if (p != NULL) {
                    ((void (*)(void *, void *, void *, void *, void *, void *, u16))__ct__22TBoss5GryphonShockWaveFP7TObjectlPUcPUcls)(
                        p, self->f4C4, self, &self->fxPos, &pos, &vel, self->f38C);
                }
                spawn_particle_effect_with_flags(&self->fxPos, self->res->f10, 0x40);
                self->state = 2;
            }
            break;
        case 2:
            if (TBoss8Dragon__sub_8005FAE0((u8 *)self) != 0) {
                ((TBoss5Gryphon *)self)->advance_motion_entry();
            }
            break;
        }
        break;
    case 5:
        if (self->fx != NULL) {
            queue_destruction__7TObjectFv(self->fx);
            self->fx = NULL;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        break;
    }
}

void TBoss8Dragon__sub_80063320(u8 *arg0, u32 arg1) {
    f32 d;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 3;
        ((VObj_80063320 *)arg0)->m94();
        ((TBoss8Dragon *)arg0)->clear_timer();
        ((TBoss8Dragon *)arg0)->reset_angle();
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x6E0)) {
        case 0:
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8DF4) != 0) {
                ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8DF8, arg0, *(s32 *)((s8 *)arg0 + 0x60));
                *(u32 *)((s8 *)arg0 + 0x4C0) |= 4;
                ((TBoss8Dragon *)arg0)->run_default_state();
                set_flag_4e4__12TBoss8DragonFPv(arg0);
                TCameraCtrl__sub_8006A044(0x14, lbl_805D8EA4);
                ((TBoss5Gryphon *)arg0)->play_se(0x40033409);
                *(s32 *)((s8 *)arg0 + 0x6E0) = 1;
            }
            break;
        case 1:
            d = ((TObjEneDD_ST *)arg0)->get_speed_or_default() - lbl_805D8DF4;
            d = lbl_805D8DD0 * (d * d);
            *(f32 *)((s8 *)arg0 + 0x3C) = d * lbl_805D8E34 + (*(const f32 *)&lbl_805D8D84);
            move_along_angle__13TBoss5GryphonFPvif(arg0, *(s32 *)((s8 *)arg0 + 0x60), lbl_805D8D88);
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8EA8) != 0) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 2;
            }
            break;
        case 2:
            d = lbl_805D8EAC - ((TObjEneDD_ST *)arg0)->get_speed_or_default();
            *(f32 *)((s8 *)arg0 + 0x3C) = (*(const f32 *)&lbl_805D8DEC) + (*(const f32 *)&lbl_805D8D84) * -(d * d) / lbl_805D8E14;
            move_along_angle__13TBoss5GryphonFPvif(arg0, *(s32 *)((s8 *)arg0 + 0x60), lbl_805D8D88);
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8EAC) != 0) {
                *(f32 *)((s8 *)arg0 + 0x3C) = (*(const f32 *)&lbl_805D8DEC);
                *(s32 *)((s8 *)arg0 + 0x6E0) = 3;
            }
            break;
        case 3:
            ((void (*)(f32, void *, s32))move_along_angle__13TBoss5GryphonFPvif)(lbl_805D8D88, arg0, *(s32 *)((s8 *)arg0 + 0x60));
            if (((s32 (*)(void *))TBoss8Dragon__sub_8005FAE0)(arg0) != 0) {
                ((TBoss5Gryphon *)arg0)->advance_motion_entry();
            }
            break;
        }
        if (objInBand((GameObj *)arg0, (f32)lbl_805D8D50) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8EB0)) != 0) {
            ((TBoss5Gryphon *)arg0)->spawn_ground_splash();
        }
        break;
    case 5:
        set_flag_4e4__12TBoss8DragonFPv(arg0);
        ((TBoss5Gryphon *)arg0)->reset_float_3c();
        *(u32 *)((s8 *)arg0 + 0x4C0) &= ~4;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80063570(Obj_80063570 *arg0, s32 arg1) {
    f32 spd;
    switch (arg1) {
    case 4:
        arg0->fb8 = 1;
        ((VObj_80063570 *)arg0)->m94();
        ((TBoss8Dragon *)arg0)->clear_timer();
        ((TBoss8Dragon *)arg0)->reset_angle();
        arg0->flags |= 0x10;
        arg0->f490 = 0;
        return;
    case 8:
        ((TBoss8Dragon *)arg0)->update_periodic_effect();
        return;
    case 0:
        advance_animation_playback(arg0);
        TBoss8Dragon__sub_80064E3C((u8 *)arg0);
        ((s32 (*)(void *))update_velocity__9TObjEneDDFv)(arg0);
        TBoss8Dragon__sub_800648C8((u8 *)arg0);
        spd = ((TObjEneDD_ST *)arg0)->get_speed_or_default();
        if (spd < lbl_805D8DCC) {
            TObjEneEpsilon__sub_800B9384((u8 *)arg0, 0x100, lbl_805D8EB4);
        } else if (!(spd < lbl_805D8E10)) {
            if (spd < lbl_805D8E5C) {
                TObjEneEpsilon__sub_800B9384((u8 *)arg0, 0x100, lbl_805D8EB4);
            } else if (!(spd < lbl_805D8DF4)) {
                TObjEneEpsilon__sub_800B9384((u8 *)arg0, 0x100, lbl_805D8EB4);
            }
        }
        break;
    case 5:
        arg0->flags &= ~0x10;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_8006369C(Obj_8006369C *self, u32 arg1) {
    switch (arg1) {
    case 4:
        self->f_B8 = 0;
        self->m94();
        ((TBoss8Dragon *)self)->clear_timer();
        ((TBoss8Dragon *)self)->reset_angle();
        return;
    case 0:
        advance_animation_playback(self);
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80063714(void) {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::spawn_switch_attack() {
    s32 particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags(this, 0x211, 0x40);
    if (particle_effect_with_flags != 0) {
        attach_particle_model((u8 *)particle_effect_with_flags, (s32)(get_bml_model(boss5_gryphon_bml_resource, 2)), (s32)boss5_gryphon_texture_list, 0, 0, (f32)lbl_805D8D88);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::spawn_attack_effect() {
    s32 particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags(this, 0x210, 0x40);
    if (particle_effect_with_flags != 0) {
        attach_particle_model((u8 *)particle_effect_with_flags, (s32)(get_bml_model(boss5_gryphon_bml_resource, 1)), (s32)boss5_gryphon_texture_list, 0, 0, (f32)lbl_805D8D88);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::spawn_lightning_effect() {
    Seg_80063CDC segs[3];
    s32 a;
    s32 b;
    void *o;

    a = (s32)(lbl_805D8D7C * (lbl_805D8D98 * (f32)rand()));
    b = (s32)(lbl_805D8D7C * (lbl_805D8D98 * (f32)rand()));
    segs[0].x = lbl_805D8EB8 * sin_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    segs[0].y = lbl_805D8D5C;
    segs[0].z = lbl_805D8EB8 * cos_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    segs[0].w = lbl_805D8D5C;
    segs[2].x = lbl_805D8EB8 * sin_table_lookup(b) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    segs[2].y = lbl_805D8D5C;
    segs[2].z = lbl_805D8EB8 * cos_table_lookup(b) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    segs[2].w = lbl_805D8D5C;
    a = (s32)(lbl_805D8D74 * (f32)(a + b));
    if (lbl_805D8D98 * (f32)rand() > lbl_805D8D74) {
        a += 0x8000;
    }
    segs[1].x = lbl_805D8EB8 * sin_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    segs[1].y = lbl_805D8E10;
    segs[1].z = lbl_805D8EB8 * cos_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    segs[1].w = lbl_805D8D5C;
    o = __nw__7TObjectFUl(0x264);
    if (o != NULL) {
        o = __ct__25TBoss5GryphonLightningEffFv(o, this, segs, 3, lbl_805D8D5C, lbl_805D8D88, lbl_805D8D54);
    }
    TBoss5GryphonLightningEff__sub_80325064(o);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80063EF4(s32 arg0) {
    if (objInBand((GameObj *)arg0, lbl_805D8EBC) != 0) {
        ((TBoss5Gryphon *)arg0)->spawn_ground_splash();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::spawn_ground_splash() {
    Stack_80063F34 stack;
    f32 temp_f1;
    u8 *temp_r3;
    VecCopy__FP3VecPC3Vec((void*)((void *) (&stack.sp8)), (void*)((void *) (((u8 *)this) + 0x38)));
    temp_r3 = csnVecterUnder(&stack.sp8, 0x16EF);
    if (temp_r3 != NULL) {
        temp_f1 = *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 4);
        if (!(temp_f1 > lbl_805D8D70)) {
            stack.spC = temp_f1;
            spawn_particle_effect_with_flags((void *)((void *) (&stack.sp8)), (s32)((void *) (**(s32 **)((s8 *)((u8 *)this) + 0x5F0))), 0x40);
            play_se(0x40032D01);
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TBoss8Dragon__sub_80063FB8(s32 arg0, s32 arg1, f32 farg0) {
    struct CopyStack_80063FB8 { u8 bytes[0x14]; };
    u8 *temp;
    CopyStack_80063FB8 copy_storage;
    temp = (u8 *)&lbl_80437DA4.value - 4;
    *(ByteBlock_14 *)(copy_storage.bytes) = *(const ByteBlock_14 *)((s32) temp + 4);
    (*(f32 *)(copy_storage.bytes + 0x4)) = *(f32 *)((s8 *)(*(u8 **)((s8 *)(&(*(GB_80063FB8 *)&boss5_gryphon_behavior_params).value) + 8)) + 0xC);
    (*(f32 *)(copy_storage.bytes + 0x8)) = farg0;
    TObjEneDD::setup_instance(arg0, arg1, copy_storage.bytes, 0);
}

extern ByteBlock_14 lbl_80437D90;

void TBoss8Dragon__sub_8006402C(s32 arg0, s32 arg1, f32 farg0, f32 farg1) {
    ByteBlock_14 desc = lbl_80437D90;
    *(f32 *)(desc.bytes + 4) = **(f32 **)(boss5_gryphon_behavior_params.remaining + 4) * farg1;
    *(f32 *)(desc.bytes + 8) = farg0;
    TObjEneDD::setup_instance(arg0, arg1, desc.bytes, 0);
}
void TBoss8Dragon__sub_800640A4(s32 arg0, s32 arg1) {
    struct CopyStack_800640A4 { u8 bytes[0x14]; };
    u8 *temp;
    CopyStack_800640A4 copy_storage;
    temp = (u8 *)&lbl_80437D7C.value - 4;
    *(ByteBlock_14 *)(copy_storage.bytes) = *(const ByteBlock_14 *)((s32) temp + 4);
    (*(f32 *)(copy_storage.bytes + 0x4)) = *(f32 *)((s8 *)(*(u8 **)((s8 *)(&(*(GB_800640A4 *)&boss5_gryphon_behavior_params).value) + 8)) + 8);
    TObjEneDD::setup_instance(arg0, arg1, copy_storage.bytes, 0);
}

void TBoss8Dragon__sub_80064114(s32 arg0, s32 arg1) {
    struct CopyStack_80064114 { u8 bytes[0x14]; };
    CopyStack_80064114 copy_storage_80064114;
    u8 *temp_r4;
    temp_r4 = (u8 *)&lbl_80437D68.value - 4;
    *(ByteBlock_14 *)(copy_storage_80064114.bytes) = *(const ByteBlock_14 *)((s32) temp_r4 + 4);
    (*(f32 *)(copy_storage_80064114.bytes + 0x4)) = *(f32 *)((s8 *)(*(u8 **)((s8 *)(&(*(RecoveredGlobal_80064114_lbl_804FF5B4 *)&boss5_gryphon_behavior_params).value) + 8)) + 4);
    TBoss8Dragon__sub_80067074((arg1), ((s32)copy_storage_80064114.bytes));
    TObjEneDD::setup_instance(arg0, arg1, (copy_storage_80064114.bytes), 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_800641A8(u8 *ene_dd) {
    struct CopyStack_800641A8 { u8 bytes[0x14]; };
    CopyStack_800641A8 copy_storage_800641A8;
    u8 *temp_r4;
    u8 *pos;
    temp_r4 = (u8 *)lbl_80437D54 - 4;
    *(ByteBlock_14 *)(copy_storage_800641A8.bytes) = *(const ByteBlock_14 *)((s32) temp_r4 + 4);
    pos = ene_dd + 0x468;
    if (!(*(f32 *)((s8 *)ene_dd + 0x46C) > lbl_805D8E00)) {
        fill_value_array((int) (*(s32 *)((s8 *)ene_dd + 0x578)));
        reset_hp__9TObjEneDDFv(ene_dd, 0, (int) (*(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 4)), 0);
        emit_enemy_effect__9TObjEneDDFllPUcl((void *)ene_dd, (int)pos, (void *) ((copy_storage_800641A8.bytes)), (int) (*(s32 *)((s8 *)ene_dd + 0x578)));
        reset_hp__9TObjEneDDFv(ene_dd, 0, (int) (*(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0)), 0);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_8006426C(Obj_8006426C *arg0) {
    Vec_8006426C mid;
    ByteBlock_14 prm;
    prm = lbl_80437D40;
    mid.x = 0.5f * (arg0->a.x - arg0->b.x) + arg0->b.x;
    mid.y = 0.5f * (arg0->a.y - arg0->b.y) + arg0->b.y;
    mid.z = 0.5f * (arg0->a.z - arg0->b.z) + arg0->b.z;
    fill_value_array(arg0->f578);
    reset_hp__9TObjEneDDFv(arg0, 0, *(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0x10), 0);
    emit_enemy_effect__9TObjEneDDFllPUcl(arg0, (int)&mid, &prm, arg0->f578);
    reset_hp__9TObjEneDDFv(arg0, 0, *(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0), 0);
}
#pragma pop

void TBoss8Dragon__sub_8006435C(u8 *ene_dd) {
    typedef char sp8_offset[(offsetof(Stack_8006435C, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8006435C, sp10) == 0x8) ? 1 : -1];
    Stack_8006435C stack;
    u8 *temp_r31;
    u8 *temp_r31_2;
    TBoss1Dragon__sub_80027A80((void *) (&stack.sp8), (void *) (&boss8_dragon_attack_params.value));
    fill_value_array((int) (*(s32 *)((s8 *)ene_dd + 0x578)));
    reset_hp__9TObjEneDDFv(ene_dd, 0, (int) (*(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0xC)), 0);
    temp_r31 = (u8 *)(ene_dd + 0x444);
    stack.sp10 = lbl_805D8EAC;
    TBoss8Dragon__sub_800670E0((int)temp_r31, (void *) (&stack.sp8));
    emit_enemy_effect__9TObjEneDDFllPUcl((void *)ene_dd, (int)temp_r31, (void *) (&stack.sp8), (int) (*(s32 *)((s8 *)ene_dd + 0x578)));
    temp_r31_2 = (u8 *)(ene_dd + 0x3C0);
    stack.sp10 = lbl_805D8DD0;
    TBoss8Dragon__sub_800670E0((int)temp_r31_2, (void *) (&stack.sp8));
    emit_enemy_effect__9TObjEneDDFllPUcl((void *)ene_dd, (int)temp_r31_2, (void *) (&stack.sp8), (int) (*(s32 *)((s8 *)ene_dd + 0x578)));
    reset_hp__9TObjEneDDFv(ene_dd, 0, (int) (*(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0)), 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TBoss8Dragon__sub_8006442C(Dragon_8006442C *arg0) {
    Fx_8006442C fx;
    Vec_8006442C pts[10];
    Vec_8006442C *p;
    s32 i;
    TBoss1Dragon__sub_80027A80(&fx, gryphon_effect_param_block);
    fill_value_array(arg0->f578);
    p = pts;
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->a));
    VecCopy__FP3VecPC3Vec(p, (void*)(&arg0->e));
    p[1].x = lbl_805D8D74 * (arg0->a.x + arg0->b.x);
    p[1].y = lbl_805D8D74 * (arg0->a.y + arg0->b.y);
    p[1].z = lbl_805D8D74 * (arg0->a.z + arg0->b.z);
    p[2].x = lbl_805D8D74 * (arg0->e.x + arg0->f.x);
    p[2].y = lbl_805D8D74 * (arg0->e.y + arg0->f.y);
    p[2].z = lbl_805D8D74 * (arg0->e.z + arg0->f.z);
    p[3].x = lbl_805D8D74 * (arg0->b.x + arg0->c.x);
    p[3].y = lbl_805D8D74 * (arg0->b.y + arg0->c.y);
    p[3].z = lbl_805D8D74 * (arg0->b.z + arg0->c.z);
    p[4].x = lbl_805D8D74 * (arg0->f.x + arg0->g.x);
    p[4].y = lbl_805D8D74 * (arg0->f.y + arg0->g.y);
    p[4].z = lbl_805D8D74 * (arg0->f.z + arg0->g.z);
    p[5].x = lbl_805D8D74 * (arg0->c.x + arg0->d.x);
    p[5].y = lbl_805D8D74 * (arg0->c.y + arg0->d.y);
    p[5].z = lbl_805D8D74 * (arg0->c.z + arg0->d.z);
    p[6].x = lbl_805D8D74 * (arg0->g.x + arg0->h.x);
    p[6].y = lbl_805D8D74 * (arg0->g.y + arg0->h.y);
    p[6].z = lbl_805D8D74 * (arg0->g.z + arg0->h.z);
    p += 7;
    VecCopy__FP3VecPC3Vec((void*)(p++), (void*)(&arg0->d));
    VecCopy__FP3VecPC3Vec(p, (void*)(&arg0->h));
    reset_hp__9TObjEneDDFv(arg0, 0, ((s32 *)&boss5_gryphon_attack_params)[3], 0);
    p = pts;
    for (i = 0; i < 5; i++) {
        fx.scale = gryphon_effect_scale_table[i];
        TBoss8Dragon__sub_800670E0((int)p, &fx);
        emit_enemy_effect__9TObjEneDDFllPUcl(arg0, (int)p++, &fx, arg0->f578);
        TBoss8Dragon__sub_800670E0((int)p, &fx);
        emit_enemy_effect__9TObjEneDDFllPUcl(arg0, (int)p++, &fx, arg0->f578);
    }
    reset_hp__9TObjEneDDFv(arg0, 0, ((s32 *)&boss5_gryphon_attack_params)[0], 0);
}

void TBoss5Gryphon::update_collider_from_table() {
    s32 arg0 = (s32)this;
    struct CopyStack_80064694 { u8 bytes[0x14]; };
    CopyStack_80064694 copy_storage_80064694;
    u8 *temp_r5;
    temp_r5 = (u8 *)&gryphon_collider_desc.value - 4;
    *(ByteBlock_14 *)(copy_storage_80064694.bytes) = *(const ByteBlock_14 *)((s32) temp_r5 + 4);
    TBoss8Dragon__sub_800670E0((int)((void *) (arg0 + 0x3C0)), (void *)((void *) ((copy_storage_80064694.bytes))));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_800646F0(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_800646F0, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800646F0, sp10) == 0x8) ? 1 : -1];
    Stack_800646F0 stack;
    TBoss1Dragon__sub_80027A80((void *) (&stack.sp8), (void *) (&boss5_gryphon_params_b.value));
    stack.sp10 = *(f32 *)((s8 *)(*(u8 **)((s8 *)(&boss5_gryphon_behavior_params.value) + 8)) + 0x10);
    ((TBoss5Gryphon *)arg0)->reload_stats_for_phase((void *)((void *) (*(u8 **)((s8 *)(&boss5_gryphon_behavior_params.value) + 8))));
    TBoss8Dragon__sub_80067074((arg0 + 0x38), (s32)(&stack.sp8));
    ((TObjEneDD *)arg0)->emit_effect_at_position((void *) (&stack.sp8));
    ((TBoss5Gryphon *)arg0)->reload_stats_for_type();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::run_default_state() { query_default(); attack_default(); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TBoss8Dragon::update_state_3() { return emit_part_attack_effect__13TBoss5GryphonFPvi(this, 3); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TBoss8Dragon::set_state_2() { return emit_part_attack_effect__13TBoss5GryphonFPvi(this, 2); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TBoss8Dragon::attack_default() { return emit_part_attack_effect__13TBoss5GryphonFPvi(this, 1); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int TBoss8Dragon::query_default() { return emit_part_attack_effect__13TBoss5GryphonFPvi(this, 0); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80064828(u8 *arg0) {
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8D80) != 0) {
        ((TBoss8Dragon *)arg0)->query_default();
        return;
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8D54) != 0) {
        ((TBoss8Dragon *)arg0)->attack_default();
        return;
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8E00) != 0) {
        ((TBoss8Dragon *)arg0)->set_state_2();
        return;
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8E0C) != 0) {
        ((TBoss8Dragon *)arg0)->update_state_3();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_800648C8(u8 *arg0) {
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8EC0) != 0) {
        ((TBoss8Dragon *)arg0)->query_default();
        return;
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8DF8) != 0) {
        ((TBoss8Dragon *)arg0)->attack_default();
        return;
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8D50) != 0) {
        ((TBoss8Dragon *)arg0)->set_state_2();
        return;
    }
    if (objInBand((GameObj *)arg0, (f32)lbl_805D8D54) != 0) {
        ((TBoss8Dragon *)arg0)->update_state_3();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
int emit_part_attack_effect__13TBoss5GryphonFPvi(void *ene_dd, int arg1) {
    ByteBlock_14 prm;
    Vec_80064968 *p;
    prm = gryphon_part_attack_params;
    fill_value_array(((Obj_80064968 *)ene_dd)->f578);
    p = &((Obj_80064968 *)ene_dd)->parts[gryphon_part_attack_index_table[arg1]];
    reset_hp__9TObjEneDDFv(ene_dd, 0, *(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0), 0);
    TBoss8Dragon__sub_80067074((s32)p, (s32)&prm);
    emit_enemy_effect__9TObjEneDDFllPUcl(ene_dd, (int)p, &prm, ((Obj_80064968 *)ene_dd)->f578);
    reset_hp__9TObjEneDDFv(ene_dd, 0, *(s32 *)((s8 *)(&boss5_gryphon_attack_params.value) + 0), 0);
    spawn_particle_effect_with_flags(p, ((Obj_80064968 *)ene_dd)->f5f0->f8, 0x40);
    ((TBoss8Dragon *)p)->spawn_attack_effect();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::copy_spawn_params(void* a1) { *(short*)((char*)a1 + 0x2) = *(unsigned short *)&this->unk_1C; VecCopy__FP3VecPC3Vec((void*)((char*)a1 + 0x4), (void*)((char*)this + 0x38)); *(void**)((char*)a1 + 0x10) = *(void* *)&this->m_60; ((TBoss8Dragon *)a1)->send_spawn_params_packet(); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80064AB0(O_80064AB0 *self) {
    P_80064AB0 p;
    TBoss8Dragon__sub_800660A4(&p);
    p.id = self->id;
    p.kind = self->kind;
    p.x = self->x;
    p.z = self->z;
    ((TBoss8Dragon *)(&p))->send_boss_actions();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *arg1) {
    s16 temp_r4;
    VecCopy__FP3VecPC3Vec((void*)((void *) (ene_dd + 0x484)), (void*)((void *) (arg1 + 4)));
    ((f32 (*)(void *, void *))subtract_vector)((void *) (ene_dd + 0x484), (void *) (ene_dd + 0x38));
    ((TObjEneDD *)ene_dd)->rotation_y = (s32) *(s32 *)((s8 *)arg1 + 0x10);
    ((TBoss8Dragon *)(ene_dd + 0x494))->copy_action_state((u8 *)((void *) (arg1 + 0x14)));
    *(s16 **)((s8 *)ene_dd + 0x4BC) = (s16 *) (ene_dd + 0x494);
    temp_r4 = **(s16 **)((s8 *)ene_dd + 0x4BC);
    if ((s16) ((TObjEneDD *)ene_dd)->mode != temp_r4) {
        ((TObjEneDD *)ene_dd)->transition_enemy_state(temp_r4);
    }
    *(s32 *)((s8 *)ene_dd + 0x4C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x4C0) | 2);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::copy_action_state(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    *(s16 *)&this->m_0 = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(ByteBlock_10 *)((s32) (u8 *)&this->unk_4) = *(const ByteBlock_10 *)((s32) arg1 + 4);
}
}
void set_collider_contact_low(u8 *arg0);
void set_collider_contact_high(u8 *arg0);
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *arg0);
void handle_6x9F_gal_gryphon_boss_actions(void *arg0);
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon) {
    void *x;
    boss8_dragon->byteswap_action_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)boss8_dragon + 0x2));
    if (x != NULL) {
        apply_remote_action__13TBoss5GryphonFPvPv((u8 *)x, (u8 *)boss8_dragon);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TBoss5Gryphon::set_target_from_action(void *arg1) {
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 4));
    this->m_394 = (f32) *(f32 *)((s8 *)arg1 + 8);
    this->m_39c = (f32) *(f32 *)((s8 *)arg1 + 0xC);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon) {
    void *x;
    ((TBoss8Dragon *)boss8_dragon)->bswap_boss_actions();
    x = get_enemy_entity(*(u16 *)((s8 *)boss8_dragon + 0x2));
    if (x != NULL) {
        ((TBoss5Gryphon *)x)->set_target_from_action(boss8_dragon);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {

s32 TBoss5Gryphon::reload_stats_for_phase(void *) {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, (int)(((s32 *)&boss5_gryphon_base_params)[((s32 *)lbl_80487890)[2]]), (int)(((s32 *)&boss5_gryphon_attack_params)[((s32 *)lbl_8048789C)[2]]), (int)(((s32 *)&boss5_gryphon_resistance_params)[((s32 *)lbl_804878A8)[2]]));
}

void TBoss5Gryphon::reload_stats_for_type() {
    s32 arg0 = (s32)this;
    reload_stats_keep_hp_tp__9TObjEneDDFv((void *)arg0, (int) (*(s32 *)((s8 *)(&boss5_gryphon_base_params) + (*(s32 *)((s8 *)(&lbl_80487848.value) + 0x48) * 4))), (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80064CFC_lbl_804FF5A0 *)&boss5_gryphon_attack_params).value) + (*(s32 *)((s8 *)(&lbl_80487848.value) + 0x54) * 4))), (int) (*(s32 *)((s8 *)(&boss5_gryphon_resistance_params) + (*(s32 *)((s8 *)(&lbl_80487848.value) + 0x60) * 4))));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::reset_radius() { *(float *)&this->unk_3C = lbl_805D8EC4; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::set_anim_speed() { *(float *)&this->unk_3C = lbl_805D8E20; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::reset_float_3c() { *(float*)((char*)this + 0x3c) = lbl_805D8DEC; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::reset_angle() { *(float *)&this->unk_3C = lbl_805D8D84; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::set_phase() { this->m_4e4 = 3; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::set_attack_phase() { this->m_4e4 = 2; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void set_flag_4e4__12TBoss8DragonFPv(void* p) { *(s32*)((char*)p + 0x4e4) = 1; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::clear_timer() { this->m_4e4 = 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80064DB8(u8 *arg0) {
    if ((objInBand((GameObj *)arg0, (f32)lbl_805D8D80) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8D54)) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8E00)) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8E0C)) != 0)) {
        ((TBoss5Gryphon *)arg0)->play_se(0x40032D08);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon__sub_80064E3C(u8 *arg0) {
    if ((objInBand((GameObj *)arg0, (f32)lbl_805D8EC0) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8DF8)) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8D50)) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D8D54)) != 0)) {
        ((TBoss5Gryphon *)arg0)->play_se(0x40032D08);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void spawn_ancient_trap__12TBoss8DragonFii(s32 arg0, s32 arg1) {
    play_persistent_sound(arg1, arg0, arg0 + 0x560, 0, 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::play_se(s32 arg1) {
    s32 arg0 = (s32)this;
    ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(arg1, arg0 + 0x560, 0, 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::update_epsilon_position() {
    update_linked_position__12TObjEneDD_STFf(lbl_805D8EC8);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#define CFG (*(Cfg_80064F50 **)((s8 *)(&boss5_gryphon_behavior_params.value) + 8))
void TBoss5Gryphon::vfunc_88() {
    Obj_80064F50 *arg0 = (Obj_80064F50 *)this;
    if (arg0->flags4C0 & 0x80) {
        for (s32 i = 0; i < 10; i++) {
            arg0->parts[i].flags &= ~1;
        }
        return;
    }
    update_local_colliders_from_world(arg0, arg0->pos4E8);
    {
        f32 lim = lbl_805D8EAC;
        s32 i;
        for (i = 0; i < 10; i++) {
            Part_80064F50 *p;
            arg0->parts[i].flags |= 1;
            p = &arg0->parts[i];
            if (p->f4 + p->f20 >= lim) {
                set_collider_contact_high((u8 *)p);
            } else {
                set_collider_contact_low((u8 *)p);
            }
        }
    }
    if (arg0->mode4E4 == 2) {
        arg0->parts[0].flags |= 0x300;
        arg0->parts[1].flags |= 0x300;
        arg0->parts[2].flags |= 0x300;
        arg0->parts[3].flags |= 0x300;
        arg0->parts[2].flags |= 0x300;
        arg0->parts[6].flags &= ~1;
        arg0->parts[7].flags &= ~1;
        arg0->parts[8].flags &= ~1;
        arg0->parts[9].flags &= ~1;
        arg0->parts[0].fC = lbl_805D8E84;
        set_collider_contact_low((u8 *)&arg0->parts[0]);
        set_collider_contact_low((u8 *)&arg0->parts[1]);
        set_collider_contact_low((u8 *)&arg0->parts[2]);
        set_collider_contact_low((u8 *)&arg0->parts[3]);
        set_collider_contact_low((u8 *)&arg0->parts[2]);
    } else {
        arg0->parts[0].flags &= ~0x300;
        arg0->parts[1].flags &= ~0x300;
        arg0->parts[2].flags &= ~0x300;
        arg0->parts[3].flags &= ~0x300;
        arg0->parts[2].flags &= ~0x300;
        arg0->parts[6].flags |= 1;
        arg0->parts[7].flags |= 1;
        arg0->parts[8].flags |= 1;
        arg0->parts[9].flags |= 1;
        arg0->parts[0].fC = lbl_805D8E10;
    }
    arg0->parts[0].f28 = CFG->i20;
    arg0->parts[1].f28 = CFG->i1C;
    arg0->parts[2].f28 = CFG->i1C;
    arg0->parts[3].f28 = CFG->i1C;
    arg0->parts[4].f28 = CFG->i1C;
    arg0->parts[5].f28 = CFG->i18;
    arg0->parts[6].f28 = CFG->i24;
    arg0->parts[7].f28 = CFG->i24;
    arg0->parts[8].f28 = CFG->i24;
    arg0->parts[9].f28 = CFG->i24;
}

void TBoss5Gryphon::shift_position_history() {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec((void*)(arg0 + 0x2FC), (void*)(arg0 + 0x3C0));
    VecCopy__FP3VecPC3Vec((void*)(arg0 + 0x74), (void*)(arg0 + 0x2FC));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::vfunc_61() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::vfunc_62() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::vfunc_63() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::vfunc_28() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::update_animation_by_state() {
    struct VObj_80065370_80062BA0 *obj = (struct VObj_80065370_80062BA0 *)this;
    if (!(*(s32 *)((s8 *)obj + 0x4C0) & 0xC) && (*(s16 *)((s8 *)obj + 0x32C) <= 0)) {
        ((s32 (*)(void))set_animation_by_state__12TBoss8DragonFPv)();
    } else {
        obj->vcall(*(s16 *)((s8 *)obj + 0x326), 9);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct O_8005F740;
struct Obj_8005FBC4;
struct VObj_80065370_80062BA0;
void TBoss5Gryphon::run_task() {
    s32 temp_r31;
    s32 temp_r31_2;
    s32 var_r30;
    s32 i;
    u8 *arg0 = (u8 *)this;
    if (((int (*)())check_demo_mode__10TObjPlayerFv)() != 0) {
        ((TBoss5Gryphon *)(arg0))->vfunc_83();
        return;
    }
    if (*(s32 *)((s8 *)arg0 + 0x4C0) & 1) {
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        temp_r31 = *(s32 *)((s8 *)arg0 + 0x4E0);
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            *(s32 *)((s8 *)arg0 + 0x4E0) = 0;
            if ((s32) *(s32 *)((s8 *)arg0 + 0x4E0) != temp_r31) {
                *(s32 *)((s8 *)arg0 + 0x730) = 1;
            }
        } else {
            *(s32 *)((s8 *)arg0 + 0x4E0) = 1;
        }
    }
    temp_r31_2 = query_teammate_state__9TObjEneDDFv();
    ((TBoss5Gryphon *)(arg0))->update_attack_stat_status();
    ((TBoss5Gryphon *)(arg0))->update_defense_stat_status();
    if (temp_r31_2 == 0) {
        if (((s32 (*)(void *))get_flag_bit6__12TBoss8DragonFv)(arg0) != 0) {
            this->actorFlags = (s32) (this->actorFlags | 0x800);
        } else {
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4E0) != 1) {
            if (((TBoss5Gryphon *)(arg0))->test_flag30_512() != 0) {
                ((TObjEneDD *)arg0)->clear_attack_receipts();
            }
            ((TBoss8Dragon *)arg0)->update_animation_by_state();
            ((TBoss8Dragon *)arg0)->flush_pending_effect();
            ((VObj_18 *)(arg0))->m85(this->mode, 8);
            ((VObj_18 *)(arg0))->m85(this->mode, 0);
        } else {
            if (((TBoss5Gryphon *)(arg0))->test_flag30_512() != 0) {
                ((TObjEneDD *)arg0)->clear_attack_receipts();
            }
            ((VObj_18 *)(arg0))->m85(this->mode, 0);
        }
    }
    ((TObjEneDD *)arg0)->sub_800BBA0C();
    ((TBoss5Gryphon *)arg0)->apply_velocity();
    TBoss8Dragon__sub_8005FB90(arg0);
    ((TBoss5Gryphon *)arg0)->advance_motion_timer();
    ((TBoss5Gryphon *)(arg0))->vfunc_88();
    ((TBoss5Gryphon *)arg0)->shift_position_history();
    ((TBoss8Dragon *)arg0)->set_player_state_default();
    add_radar_scaled_marker((void *) (arg0 + 0x38), -0x5DB4, 1, 1, lbl_805D8D58);
    VecCopy__FP3VecPC3Vec((void *) (arg0 + 0x56C), (void *) (arg0 + 0x2FC));
    if (temp_r31_2 == 0) {
        ((TObject *)(arg0 + 0x4C4))->run_tasks();
    }
    project_sound_origin_from_camera((s32)(arg0 + 0x38), (u8 *)(arg0 + 0x560), lbl_805D8DAC);
    for (i = 0; i < 4; i++) {
        update_obstruction_fade(&((Dragon_800653C4 *)arg0)->fade[i]);
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x4E4) != 0) {
        ((TBoss5Gryphon *)arg0)->update_collider_from_table();
    }
}

Obj_80065658 *__dt__13TBoss5GryphonFv(Obj_80065658 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = __vt__13TBoss5Gryphon;
        for (i = 15; i >= 0; i--) {
            if (o->objs[i] != 0) {
                queue_destruction__7TObjectFv(o->objs[i]);
                o->objs[i] = 0;
            }
        }
        if (o->f57c != 0) {
            delete o->f57c;
            o->f57c = 0;
        }
        if (o->f578 != 0) {
            delete_buffer__12TBoss8DragonFis(o->f578, 1);
            o->f578 = 0;
        }
        free_collision_body_parts(o);
        if (boss5_gryphon_instance == o) {
            boss5_gryphon_instance = 0;
        }
        __destroy_arr(o->f580, (void *)__dt__13TUnk_804949A8Fv, 0x1c, 4);
        __dt__7TObjectFv(o->f4c4, -1);
        __dt__12TObjEneDD_STFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

extern "C" {
void init_object__12TObjEneDD_STFv(void *, void *, void *);
void __ct__7TObjectFP7TObject(void *, void *);
void __construct_array(void *, void *, void *, int, int);
void init_and_activate__10TObjPlayerFv(void *);
void __ct__14SubtractiveRngFv(void *);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
void init_model__9TObjEneDDFv(void *, void *, s32);
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
void *TBoss8Dragon__sub_800BC5EC(void *, s32);
void *TBoss5GryphonColli__ct(void *, void *);
void activate_and_dispatch__10TObjPlayerFv(void *);
extern const char *boss5_gryphon_type_name_pointer;
extern u8 lbl_80437958[];
extern u8 lbl_804EC238[];

TBoss5Gryphon *TBoss5Gryphon__ct(TBoss5Gryphon *self, void *parent, void *data) {
    u32 flags[4];
    s32 i;
    void *p;

    init_object__12TObjEneDD_STFv(self, parent, data);
    ((Obj_80065658 *)self)->vt = __vt__13TBoss5Gryphon;
    __ct__7TObjectFP7TObject(&self->m_4c4, 0);
    __construct_array(self->renderFadeStates, (void *)init_and_activate__10TObjPlayerFv, (void *)__dt__13TUnk_804949A8Fv, 0x1C, 4);
    __ct__14SubtractiveRngFv(self->rng);
    self->m_name = boss5_gryphon_type_name_pointer;
    if (boss5_gryphon_instance == NULL) {
        boss5_gryphon_instance = (Obj_80065658 *)self;
    }
    invoke_initialization_hook__9TObjEneDDFv(self, data);
    self->m_4c0 = 0;
    if (self->exchange_object_state((s32)flags, 1) != 0 && (flags[0] & 0x12008) == 0x12008) {
        self->m_4c0 |= 1;
    }
    self->init_position_vectors();
    if (is_split_screen() != 0) {
        self->model = *(void **)(*(u8 **)(boss5_gryphon_body_bml_resource + 0x42C) + 0x28);
    } else {
        self->model = *(void **)(*(u8 **)(boss5_gryphon_body_bml_resource + 0x42C) + 0x8);
    }
    self->texture_id = *(s32 *)(*(u8 **)(boss5_gryphon_body_bml_resource + 0x42C) + 0xC);
    init_model__9TObjEneDDFv(self, lbl_804878D0, 10);
    self->animationFlags = 0;
    self->set_field_d8((s32)lbl_80487B1C);
    self->set_field_dc(*(s32 *)(boss5_gryphon_body_bml_resource + 0x430));
    self->m_b8 = 0;
    self->set_animation(self->m_b8);
    self->set_field_b8(self->m_b8);
    reset_hp__9TObjEneDDFv(self, (&boss5_gryphon_base_params)[*(s32 *)lbl_80487890], ((s32 *)&boss5_gryphon_attack_params)[*(s32 *)lbl_8048789C], (&boss5_gryphon_resistance_params)[*(s32 *)lbl_804878A8]);
    self->check_state_flag_2();
    *(void **)((u8 *)self + 0x350) = lbl_804878B4;
    initialize_enemy_state__9TObjEneDDFv(self, 77);
    self->m_37c = lbl_805D8D50;
    copy_position__14TObjEneEpsilonFPv(self, lbl_80437938);
    self->enemy_init_acquire_period(10);
    self->enemy_init_validate_period(10);
    ((Obj_80065658 *)self)->f474[0] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f474[1] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f474[2] = lbl_805D8D5C;
    self->m_480 = 0;
    ((Obj_80065658 *)self)->f484[0] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f484[1] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f484[2] = lbl_805D8D5C;
    for (i = 0; i < 2; i++) {
        fn_800666C4((s32)&((Obj_80065658 *)self)->motions[i]);
    }
    self->motion = ((Obj_80065658 *)self)->motions;
    self->m_4e4 = 0;
    for (i = 0; i < 15; i++) {
        VecCopy__FP3VecPC3Vec(&((Obj_80065658 *)self)->f3c0[i], self->position);
    }
    for (i = 0; i < 10; i++) {
        VecCopy__FP3VecPC3Vec(&((Obj_80065658 *)self)->f4e8[i], self->position);
    }
    for (i = 0; i < 16; i++) {
        ((Obj_80065658 *)self)->objs[i] = 0;
    }
    self->m_774 = 0;
    self->m_778 = (u32)lbl_804EC238;
    VecCopy__FP3VecPC3Vec(&self->m_560, self->position);
    VecCopy__FP3VecPC3Vec(&self->m_56c, self->position);
    *(f32 *)(*(u8 **)((u8 *)self + 0x2B0) + 0x10) = lbl_805D8E10;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x10);
    if (p != NULL) {
        p = TBoss8Dragon__sub_800BC5EC(p, 4);
    }
    self->m_578 = (u32)p;
    p = __nw__7TObjectFUl(0x20);
    if (p != NULL) {
        p = TBoss5GryphonColli__ct(p, &self->m_4c4);
    }
    ((Obj_80065658 *)self)->f57c = (VObj_80065658 *)p;
    for (i = 0; i < 4; i++) {
        activate_and_dispatch__10TObjPlayerFv(&self->renderFadeStates[i]);
    }
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        self->effect_ids = (s32 *)lbl_80437958;
        break;
    }
    self->m_6dc = 0;
    self->m_6e0 = 0;
    self->m_6e4 = 0;
    self->m_6e8 = 0;
    self->m_6ec = 0;
    self->m_6f0 = 0;
    ((Obj_80065658 *)self)->f6f4[0] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[1] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[2] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[3] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[4] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[5] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[6] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[7] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[8] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[9] = lbl_805D8D5C;
    ((Obj_80065658 *)self)->f6f4[10] = lbl_805D8D5C;
    self->m_720 = 0;
    self->m_724 = 0;
    self->m_728 = 0;
    self->m_72c = 0;
    self->mode = 0;
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (self->update_lobby_state() != 0) {
            self->m_4e0 = 0;
        } else {
            self->m_4e0 = 1;
        }
    } else {
        self->m_4e0 = 0;
    }
    self->mode = 4;
    if (!(self->m_4c0 & 1)) {
        ((VObj_18 *)self)->m85(self->mode, 4);
    }
    self->m_730 = 0;
    return self;
}
}
#pragma pop

__declspec(section ".sdata2") const f32 lbl_805D8D78 = 250.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D7C = 65536.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D80 = 12.0f;
extern const f32 lbl_805D8D84;
__declspec(section ".sdata2") const f32 lbl_805D8D84 = 65.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D88 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D8C = 40.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D90 = 3.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D94 = -1000.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D98 = 3.05175781e-05f;
__declspec(section ".sdata2") const f32 lbl_805D8D9C = 4294967300.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DA0 = 0.600000024f;
__declspec(section ".sdata2") const f32 lbl_805D8DA4 = 0.899999976f;
__declspec(section ".sdata2") const f32 lbl_805D8DA8 = 0.300000012f;
__declspec(section ".sdata2") const f32 lbl_805D8DAC = 0.400000006f;
__declspec(section ".sdata2") const f32 lbl_805D8DB0 = 0.800000012f;
__declspec(section ".sdata2") const f32 lbl_805D8DB4 = 0.200000003f;
extern const f32 lbl_805D8DB8;
__declspec(section ".sdata2") const f32 lbl_805D8DB8 = 22.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DBC = 75.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DC0 = 32.5f;
__declspec(section ".sdata2") const f32 lbl_805D8DC4 = 7935.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DC8 = 102400.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DCC = 4.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DD0 = 50.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DD4 = 360.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DD8 = 49152.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DDC = 7.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DE0 = 933.785706f;
__declspec(section ".sdata2") const f32 lbl_805D8DE4 = 17.0f;
extern const f32 lbl_805D8DE8;
__declspec(section ".sdata2") const f32 lbl_805D8DE8 = 0.280000001f;
extern const f32 lbl_805D8DEC;
__declspec(section ".sdata2") const f32 lbl_805D8DEC = 180.0f;
extern const f32 lbl_805D8DF0;
__declspec(section ".sdata2") const f32 lbl_805D8DF0 = 60.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DF4 = 25.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DF8 = 5.0f;
extern const f32 lbl_805D8DFC;
__declspec(section ".sdata2") const f32 lbl_805D8DFC = 19.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E00 = 15.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E04 = 0.75f;
__declspec(section ".sdata2") const f32 lbl_805D8E08 = 0.860000014f;
__declspec(section ".sdata2") const f32 lbl_805D8E0C = 11.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E10 = 10.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E14 = 9.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E18 = 2.29999995f;
__declspec(section ".sdata2") const f32 lbl_805D8E1C = 19.5f;
extern const f32 lbl_805D8E20;
__declspec(section ".sdata2") const f32 lbl_805D8E20 = 67.0f;
extern const f32 lbl_805D8E24;
__declspec(section ".sdata2") const f32 lbl_805D8E24 = 81.5f;
}
