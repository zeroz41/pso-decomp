#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/render/reflection.h"
#include "pso/math/AngleLookup.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TUnk_804EF130.h"
#include "pso/system/task/TObject.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/morfos/TObjEneMorfosArm.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/network/IPv6.h"
// .rodata holds the table strings, the class name, the 803350AC binding template, then the Vecs in
// reverse .text order and the doubles in .text order: deferred codegen, functions written last to first.
#pragma defer_codegen on

struct Stack_80332594 {
    s32 sp8;
    f32 spC;
};

struct VBase_803323D8 { char pad[0x18]; };

struct VObj_803323D8 : VBase_803323D8 {
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


struct Anim_803323D8 { s32 a; u32 count; };

struct Bone_803323D8 { s32 a; Anim_803323D8 *anim; };

struct Mot_803323D8 { s32 a; s32 bone; s32 c; s32 d; };

struct O_803323D8 {
    u8 pad0[0x24]; s32 f24;
    u8 pad28[0x60 - 0x28]; s32 f60;
    u8 pad64[0xD8 - 0x64]; Mot_803323D8 *mots; Bone_803323D8 *bones;
    u8 padE0[0x326 - 0xE0]; s16 f326;
    u8 pad328[0x354 - 0x328]; f32 f354; f32 frame;
};

// inferred: the boss, object and handler-a ids 803350AC registers; one each
static const s32 morfos_boss_ids[1] = { 0x40 };
static const s32 morfos_object_ids[1] = { 0x40 };
static const s32 morfos_handler_a_ids[1] = { 0x40 };

extern "C" {
extern s32 actor_frame_tick;
s32 post_translate_matrix(void *);
void* TObjEneMorfosArm__sub_803326B4(void* p);
s32 TObjEneMorfosArm__sub_803326BC(void* p);
}



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
f32 atan2_float(f32, f32);
extern saddr TObjEneMorfos__param_table;
void TObjEneMorfos__sub_80333AD0(u8 *ene_morfos, s32 ev);
s32 play_sound_effect(s32, u32, s16, s32);
void TObjEneMorfos__sub_80333690(TObjEneMorfos *owner, s32 ev);
void TObjEneMorfos__sub_80332FD4(TObjEneMorfos *arg0, s32 ev);
s32 is_split_screen();
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
s32 check_value_in_range__13TObjEneMorfosFPvUsUsUs(void *, int, int, int);
s32 TObjEneMorfos__sub_803344F0(void *arg0);
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

struct RecoveredFields_803326CC_arg0 {
    u8 unknown_0[0x60];
    s32 field_60;
    u8 unknown_64[0x35C];
    s32 field_3C0;
};

struct O_80334588 { u8 pad[0x60]; s32 f60; u8 pad2[0x2FC - 0x64]; Vec pos; };

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


LAYOUT_ASSERT(RecoveredFields_803326CC_arg0_60_offset, offsetof(RecoveredFields_803326CC_arg0, field_60) == 0x60);

LAYOUT_ASSERT(RecoveredFields_803326CC_arg0_3C0_offset, offsetof(RecoveredFields_803326CC_arg0, field_3C0) == 0x3C0);


struct Obj_8033496C { u8 pad[0x60]; s32 f60; u8 pad1[0x2D4 - 0x64]; u16 f2D4; u8 pad2[0x2FC - 0x2D6]; Vec pos; u8 pad3[0x326 - 0x308]; s16 f326; u8 pad4[0x3C0 - 0x328]; s32 f3C0; };

struct Pl_8033496C { u8 pad[0x2FC]; Vec pos; };

struct Obj_80334A4C { u8 pad[0x60]; s32 f60; u8 pad1[0x2FC - 0x64]; Vec pos; u8 pad4[0x3C0 - 0x308]; s32 f3C0; u8 pad5[0x498 - 0x3C4]; u8 snd[4]; };

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

u16 get_entity_id(void *);
s32 TObjPlayer__sub_800A04F0(void *);
void TObjPlayer__sub_800A0554(void *);
s32 angle_difference_abs(s32, s32);
s32 angle_diff_s16(s32);
s32 free_collision_body_parts(void *);
void *get_player_by_client_id(s32 i);
void TObjEneMorfos__sub_80332DBC(u8 *ene_morfos, s32 ev);
void TObjEneMorfos__sub_80333E48(u8 *ene_dd_st, s32 ev);
void TObjEneMorfos__sub_80334030(u8 *ene_dd, s32 ev);
void TObjEneMorfos__sub_803342B8(u8 *ene_dd, s32 ev);
int TObjEneMorfos__sub_80334704(void);
void subtract_vector(void *, void *);
}
void draw_chunk_model(void *arg0);

extern BmlResource *TObjEneMorfos__instance;
extern s32 TObjEneMorfos__phase;
extern Vec *TObjEneMorfos__camera_path_cursor;
extern s16 *lbl_805D6D20;
extern s16 *lbl_805D6D24;
extern s32 lbl_805D6D28;
extern s32 lbl_805D6D2C;
extern float morfos_projectile_speed;
extern float morfos_param_table_speed_copy;


void *lbl_804EE0C0[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804EE0DC[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
const char *bm_ene_morfos_model_names[4] = {
    "kabe_arm.nj", "kabe_body.nj", "kabe_wall.nj", NULL,
};
const char *bm_ene_morfos_motion_names[7] = {
    "attack_kabe_arm.njm", "attack_kabe_body.njm", "beam_kabe_body.njm", "damage_kabe_body.njm",
    "dead_kabe_body.njm", "wait_kabe_body.njm", NULL,
};
BmlResourceDescriptor morfos_resource_descriptor = {
    "bm_ene_morfos.bml", bm_ene_morfos_model_names, bm_ene_morfos_motion_names, 3, 6,
};
const char *bm_ene_morfos_low_model_names[4] = {
    "lo_kabe_arm.nj", "lo_kabe_body.nj", "kabe_wall.nj", NULL,
};
const char *bm_ene_morfos_low_motion_names[7] = {
    "attack_kabe_arm.njm", "attack_kabe_body.njm", "beam_kabe_body.njm", "damage_kabe_body.njm",
    "dead_kabe_body.njm", "wait_kabe_body.njm", NULL,
};
BmlResourceDescriptor bm_ene_morfos_low_resource_descriptor = {
    "bm_ene_morfos_low.bml", bm_ene_morfos_low_model_names, bm_ene_morfos_low_motion_names, 3, 6,
};
TObjMotionAction morfos_motion_param_table[5] = {
    { 1, 0, 5, 0.5f, 0 },
    { 3, 0, 1, 0.7f, 0 },
    { 3, 0, 2, 0.7f, 0 },
    { 3, 0, 3, 0.7f, 0 },
    { 3, 0, 4, 0.7f, 0 },
};
const char *morfos_class_name = "TObjEneMorfos";
extern "C" {

struct Self_803329E4;

struct O_80334588;

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
extern s32 lbl_804774A8[];
extern s32 lbl_804774B0[];
extern s32 lbl_804774B8[];
f32 lbl_805434D0[3];
saddr lbl_805434DC[3];
extern saddr lbl_805D6D08[1];
extern saddr lbl_805D6D0C[1];

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// MojaAnimationBinding and GeeAnimationBinding).

extern f32 lbl_805434D0[3];
extern const s32 lbl_804774A0[2];
void TObjEneMorfos__sub_803350AC(void);

void TObjEneMorfos__sub_803350AC(void) {
    BmlResource *mgr;
    s32 i;

    if (is_split_screen() != 0) {
        mgr = load_enemy_bml_resource(&bm_ene_morfos_low_resource_descriptor);
    } else {
        mgr = load_enemy_bml_resource(&morfos_resource_descriptor);
    }
    TObjEneMorfos__instance = mgr;
    lbl_805434D0[0] = 0.0f;
    lbl_805434D0[1] = 0.0f;
    lbl_805434D0[2] = 0.0f;
    TObjEneMorfos__phase = 0;
    TObjEneMorfos__camera_path_cursor = NULL;
    lbl_805D6D20 = ((NJS_CNK_MODEL *)mgr->models[1].model->child->model)->polygon_list;
    lbl_805D6D24 = ((NJS_CNK_MODEL *)mgr->models[2].model->model)->polygon_list;
    lbl_805D6D28 = 0;
    lbl_805D6D2C = 0;
    for (i = 0; i < 1; i++) {
        lbl_805D6D08[i] = (saddr)TLobby::register_boss(morfos_boss_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        lbl_805434DC[i] = (saddr)TLobby::dispatch_shared_handler_b(lbl_804774A0[i]);
    }
    for (i = 0; i < 1; i++) {
        lbl_805D6D0C[i] = (saddr)TLobby::register_object(morfos_object_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        (&TObjEneMorfos__param_table)[i] = (saddr)TLobby::dispatch_shared_handler_a(morfos_handler_a_ids[i]);
    }
    TObjEneMorfosArm::init_global();
    {
        NpcAnimationBinding desc = { TObjEneMorfos__instance->motions, reinterpret_cast<TObjMotionAction *>(morfos_motion_param_table), 0, 0, 6 };
        NpcModelRegistry::register_animated_chunk(0x4D, TObjEneMorfos__instance->models[1].model,
                                TObjEneMorfos__instance->models[1].m_c, &desc,
                                8.0f, 0.0f);
    }
}

void *TObjEneMorfos::create() {
    return new TObjEneMorfos((TObject *)tl_04, this);
}

void TObjEneMorfos::unload_static_data() {
    TObjEneMorfosArm__sub_8033542C();
    if (TObjEneMorfos__instance != NULL) {
        delete TObjEneMorfos__instance;
        TObjEneMorfos__instance = NULL;
    }
}
TObjEneMorfos::TObjEneMorfos(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = morfos_class_name;
    invoke_initialization_hook(set_data);
    init_target_offsets();
    init_instance();
    m_494 = NULL;
}
void TObjEneMorfos::init_instance() {
    s32 i;

    init_position_vectors();
    model = TObjEneMorfos__instance->models[1].model;
    this->texlist = (saddr)TObjEneMorfos__instance->models[1].m_c;
    init_model((CollisionBody *)lbl_804EE0DC, (s32)1);
    set_field_d8((saddr)morfos_motion_param_table);
    set_field_dc((saddr)TObjEneMorfos__instance->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    reset_hp((u8 *)(lbl_805D6D08[lbl_804774A8[0]]), (u8 *)(lbl_805434DC[lbl_804774B0[0]]), (u8 *)(lbl_805D6D0C[lbl_804774B8[0]]));
    ((void (*)(void *))TObjEneMorfos__sub_80334704)(this);
    set_state_8();
    this->movementParameters = (Hdr_80334D74 *)lbl_804EE0C0;
    initialize_enemy_state(0x42);
    *(f32 *)((s8 *)this + 0x37C) = 10.0f;
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
    *(f32 *)((s8 *)this + 0x498) = 0.0f;
    this->m_49c = 0.0f;
    *(f32 *)((s8 *)this + 0x4A0) = 0.0f;
    this->m_4a4 = 0.0f;
    *(f32 *)((s8 *)this + 0x4A8) = 0.0f;
    this->m_4ac = 0.0f;
    *(s32 *)((s8 *)this + 0x4B0) = 0;
    this->m_4b4 = 0;
    this->m_4bc = 0;
    *(s32 *)((s8 *)this + 0x4C0) = 0;
    this->m_4c4 = 0.0f;
    *(f32 *)((s8 *)this + 0x4C8) = 0.0f;
    this->m_4cc = 0.0f;
    *(f32 *)((s8 *)this + 0x4D0) = 0.0f;
    this->m_4d4 = 0.0f;
    this->set_intangible();
    this->mode = 0;
    ((VObj_80334D74 *)this)->m85(this->mode, 4);
}

TObjEneMorfos::~TObjEneMorfos() {
    if (m_494 != NULL) {
        m_494->queue_destruction();
        m_494 = NULL;
    }
    free_collision_body_parts(this);
}

#define ene_morfos ((u8 *)this)
void TObjEneMorfos::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneMorfos *)(ene_morfos))->run_demo_task();
        return;
    }
    if (((TObjEneMorfos *)(ene_morfos))->update_status_effects() != 4) {
        ((TObjEneMorfos *)(ene_morfos))->update_action_state();
        if ((s32) lbl_805D6D28 != (s32) actor_frame_tick) {
            lbl_805D6D28 = actor_frame_tick;
            TObjPlayer__sub_8023DEE0(lbl_805D6D20, (s16)((s16) *(s32 *)((s8 *)ene_morfos + 0x3D4)), (s16)(0), (u16)(2U));
        }
        if ((s32) lbl_805D6D2C != (s32) actor_frame_tick) {
            lbl_805D6D2C = actor_frame_tick;
            TObjPlayer__sub_8023DEE0(lbl_805D6D24, (s16)(0), (s16) ((f32) *(s32 *)((s8 *)ene_morfos + 0x3D4) / 2.0f), (u16)(0U));
        }
    }
    ((TObjEneMorfos *)ene_morfos)->set_hover_target_position();
    ((TObjEnemy *)ene_morfos)->submit_default_cursor_candidate();
    ((TObjEneMorfos *)(ene_morfos))->render_minimap_dot();
    ((TObjEneMorfos *)ene_morfos)->update_ground_probe();
}
#undef ene_morfos

void TObjEneMorfos::refresh_target() {  }

void TObjEneMorfos::run_death_reaction() { if (this->mode != 11) { transition_enemy_state((saddr)((void*)11)); } }

#define self ((Obj_80334A4C *)this)
#define att ((Obj_80334A4C *)attacker)
f32 TObjEneMorfos::receive_physical_attack(void *attacker, f32 scale) {
    Vec v;
    f32 ret = 0.0f;
    s32 d;
    if (att != 0) {
        VecCopy((Vec *)&v, (const Vec *)&att->pos);
        subtract_vector(&v, &self->pos);
        d = angle_difference_abs(self->f60, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
    } else {
        d = 0;
    }
    if (self->f3C0 & 0x10) {
        if (d < 0x4000) {
            spawn_particle_effect((const Vec *)&m_498, 0x214);
            spawn_particle_effect((const Vec *)&m_498, 0x21A);
        } else {
            self->f3C0 &= ~0x10;
            self->f3C0 |= 0x20;
            ret = ((TObjChara *)self)->TObjChara::receive_physical_attack(att, scale);
        }
    } else {
        ret = ((TObjChara *)self)->TObjChara::receive_physical_attack(att, scale);
    }
    return ret;
}
#undef self
#undef att

void TObjEneMorfos::run_hit_reaction() {
    Obj_8033496C *self = (Obj_8033496C *)this;
    Vec v;
    Pl_8033496C *pl;
    s32 d;
    if (this->mode == 0xA) {
        return;
    }
    pl = (Pl_8033496C *)get_player_by_client_id(this->attacker_id);
    if (pl != 0) {
        VecCopy((Vec *)&v, (const Vec *)&pl->pos);
        subtract_vector(&v, &self->pos);
        d = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
    } else {
        d = 0;
    }
    if (d < 0x4000) {
        ((TObjEneDD *)self)->clear_attack_receipts();
        if (((TObjEneMorfos *)self)->check_low_hp_trigger() == 0) {
            ((TObjEneMorfos *)self)->try_enter_low_hp_state();
        }
    } else if (self->f3C0 & 4) {
        ((TObjEneDD *)self)->clear_attack_receipts();
    } else {
        ((TObjEneDD *)self)->transition_enemy_state((saddr)((void *)0xA));
    }
}

void TObjEneMorfos::run_miss_reaction() {  }

s32 TObjEneMorfos::check_low_hp_trigger() {
    u8 *self = (u8 *)this;
    if (!(*(s32 *)((s8 *)self + 0x3C0) & 0x10) && ((s16) this->hp <= (s32) ((s16) this->hpmax / 2)) && (((TObjChara *)self)->random_ratio() <= *(f32 *)((s8 *)self + 0x3E0))) {
        *(s32 *)((s8 *)self + 0x3C0) = (s32) (*(s32 *)((s8 *)self + 0x3C0) | 0x10);
        return 1;
    }
    return 0;
}

s32 TObjEneMorfos::try_enter_low_hp_state() {
    u8 *self = (u8 *)this;
    if (((s16) this->hp <= (s32) ((s16) this->hpmax / 2)) && (((TObjChara *)self)->random_ratio() <= *(f32 *)((s8 *)self + 0x3E4))) {
        ((TObjEneDD *)self)->transition_enemy_state((saddr)((void*)(9)));
        return 1;
    }
    return 0;
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

void TObjEneMorfos::set_hover_target_position() {
    u8 *self = (u8 *)this;
    this->body_center.x = (f32) *(f32 *)((s8 *)self + 0x38);
    this->body_center.y = (f32) (20.0f + *(f32 *)((s8 *)self + 0x3C));
    this->body_center.z = (f32) *(f32 *)((s8 *)self + 0x40);
    VecCopy((Vec *)(self + 0x74), (const Vec *)(self + 0x2FC));
}
void TObjEneMorfos::update_body_colliders() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (this->body_center.y - *(f32 *)((s8 *)this + 0x3C));
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneMorfos::init_target_offsets() {
    u8 *self = (u8 *)this;
    if ((s32) this->variant <= 0) {
        *(s32 *)((s8 *)self + 0x3E8) = 1;
    } else {
        *(s32 *)((s8 *)self + 0x3E8) = 0;
    }
    *(f32 *)((s8 *)self + 0x3D8) = (f32) (0.28f + *(f32 *)((s8 *)self + 0x354));
    if (*(f32 *)((s8 *)self + 0x3D8) < 0.1f) {
        *(f32 *)((s8 *)self + 0x3D8) = 0.1f;
    }
    *(f32 *)((s8 *)self + 0x3DC) = (f32) (20.0f + *(f32 *)((s8 *)self + 0x358));
    if (*(f32 *)((s8 *)self + 0x3DC) < 5.0f) {
        *(f32 *)((s8 *)self + 0x3DC) = 5.0f;
    }
    *(f32 *)((s8 *)self + 0x3E0) = (f32) (0.1f + *(f32 *)((s8 *)self + 0x35C));
    *(f32 *)((s8 *)self + 0x3E4) = (f32) (0.1f + *(f32 *)((s8 *)self + 0x360));
}
#pragma pop

int TObjEneMorfos__sub_80334704(void) { morfos_projectile_speed = *(float*)((char*)TObjEneMorfos__param_table + 0x0); morfos_param_table_speed_copy = *(float*)((char*)TObjEneMorfos__param_table + 0x4); return TObjEneMorfos__param_table; }

#pragma push
#pragma fp_contract on
s32 TObjEneMorfos::select_target_in_view() {
    Vec v;
    s32 n;
    u8 *p;
    u16 id;
    s32 i;
    f32 dz;
    f32 dx;
    f32 cosLim;
    f32 d;
    f32 best;
    O_80334588 *self = (O_80334588 *)this;
    best = 0.0f;
    id = 0xFFFF;
    cosLim = cos_table_lookup(0xAAA);
    dx = sin_table_lookup(self->f60);
    dz = cos_table_lookup(self->f60);
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (((TObjBase *)p)->is_alive() == 0) {
            continue;
        }
        VecCopy((Vec *)&v, (const Vec *)(p + 0x38));
        subtract_vector(&v, &self->pos);
        v.y = 0.0f;
        d = normalize_vector_xz((Vec *)(&v));
        if (d < 400.0f && d > best && dx * v.x + dz * v.z > cosLim &&
            csnLookAt((Vec *)&self->pos, (Vec *)(p + 0x2FC)) == 0) {
            id = get_entity_id(p);
            best = d;
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(this, id);
        return 1;
    }
    return 0;
}
#pragma pop


void TObjEneMorfos::play_sound_in_band() {
    u8 *self = (u8 *)this;
    if ((((TObjMotion *)self)->is_passing_frame(4.0f) != 0) || (((TObjMotion *)self)->is_passing_frame(20.0f) != 0)) {
        play_sound_effect(0x4003A823, (uaddr)(self + 0x38), 0, 0);
    }
}

s32 TObjEneMorfos__sub_803344F0(void *arg0) {
    struct VObj_803344F0 *o = (struct VObj_803344F0 *)arg0;
    return o->m97() ? 1 : 0;
}

#define ene_morfos ((u8 *)this)
void TObjEneMorfos::dispatch_action(u32 state, s32 ev) {
    switch (state) {
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
#undef ene_morfos

void TObjEneMorfos::handle_event_transition(s32 ev) {
    switch (ev) {
    case 0:
        return;
    case 3:
        transition_enemy_state((s32)1);
        break;
    }
}

void TObjEneMorfos__sub_803342B8(u8 *ene_dd, s32 ev) {
    s32 temp_r31;
    switch (ev) {
    case 4:
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        ((TObjEneDD *)(ene_dd))->set_intangible();
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & ~5);
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) | 2);
        ((TObjEneDD *)ene_dd)->set_field_378(3);
        TObjPlayer__sub_800A0554(ene_dd + 0x3EC);
        ((TUnk_80494938 *)(ene_dd + 0x408))->start_fade_in();
        play_area_se_with_particle((Vec *)(ene_dd + 0x38));
        return;
    case 3:
        temp_r31 = ((VObj_14_948132 *)(ene_dd + (1032)))->m5();
        if ((((VObj_14_948132 *)(ene_dd + (1004)))->m5() != 0) && (temp_r31 != 0)) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state((s32)3);
        }
        return;
    case 0:
        ((TObjMotion *)ene_dd)->advance_animation();
        ((TObjEneDD *)(ene_dd))->update_ground_contact();
        ((TObjEneDD *)(ene_dd))->update_body_colliders();
        return;
    case 5:
        *(s32 *)((s8 *)ene_dd + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C0) & 0xFFFFFFFD);
        break;
    }
}

void TObjEneMorfos::state_appear(s32 ev) {

    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->set_intangible();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF8);
        set_field_378(4);
        *(s32 *)((s8 *)this + 0x3D4) = 0;
        *(s32 *)((s8 *)this + 0x4B0) = 0;
        this->m_4c4 = 0.0f;
        return;
    case 3:
        if (((s32) *(s32 *)((s8 *)this + 0x4B0) == 2) && (TObjEneMorfos__sub_803344F0(this) == 0)) {
            transition_enemy_state((s32)4);
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)this + 0x4B0)) {
        case 0:
            if (update_linked_position(400.0f) != 0) {
                *(s32 *)((s8 *)this + 0x4B0) = 1;
                enemy_copy_target_destination();
                update_velocity();
            }
            break;
        case 1:
            this->m_4c4 += 0.5f;
            *(s32 *)((s8 *)this + 0x3D4) = (s32) floor_to_float(this->m_4c4);
            if ((s32) *(s32 *)((s8 *)this + 0x3D4) >= 0xC) {
                *(s32 *)((s8 *)this + 0x3D4) = 0xC;
                *(s32 *)((s8 *)this + 0x4B0) = 2;
            }
            TObjPlayer::play_effect_if_v2(-0x100);
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        return;
    case 5:
        *(s32 *)((s8 *)this + 0x3D4) = 0xC;
        this->clear_intangible();
        break;
    }
}

void TObjEneMorfos__sub_80334030(u8 *ene_dd, s32 ev) {
    switch (ev) {
    case 4:
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        ((TObjEneDD *)(ene_dd))->set_intangible();
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
        if (((TObjEneDD_ST *)ene_dd)->update_linked_position(400.0f) != 0) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state((s32)1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMorfos__sub_80333E48(u8 *ene_dd_st, s32 ev) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r31;

    switch (ev) {
    case 4:
        ((TObjEneDD_ST *)ene_dd_st)->requested_action = 0;
        ((TObjEneDD *)(ene_dd_st))->set_intangible();
        *(s32 *)((s8 *)ene_dd_st + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_dd_st + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)ene_dd_st)->set_field_378(7);
        *(s32 *)((s8 *)ene_dd_st + 0x4B0) = 0;
        *(s32 *)((s8 *)ene_dd_st + 0x4B4) = 0;
        return;
    case 3:
        if (TObjEneMorfos__sub_803344F0(ene_dd_st) == 0) {
            temp_r0 = *(s32 *)((s8 *)ene_dd_st + 0x4B0);
            if (temp_r0 == 2) {
                ((TObjEneDD *)ene_dd_st)->transition_enemy_state((s32)4);
            } else if (temp_r0 == 3) {
                ((TObjEneDD *)ene_dd_st)->transition_enemy_state((s32)2);
            }
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_dd_st)->advance_animation();
        temp_r0_2 = *(s32 *)((s8 *)ene_dd_st + 0x4B0);
        switch (temp_r0_2) {
        case 0:
            if (((TObjEneDD_ST *)ene_dd_st)->update_linked_position(400.0f) != 0) {
                ((TObjEneDD_ST *)ene_dd_st)->enemy_copy_target_destination();
                ((TObjEneDD_ST *)ene_dd_st)->update_velocity();
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
        ((TObjEneDD *)(ene_dd_st))->update_ground_contact();
        ((TObjEneDD *)(ene_dd_st))->check_collisions();
        break;
    }
}

void TObjEneMorfos__sub_80333AD0(u8 *ene_morfos, s32 ev) {
    switch (ev) {
    case 4:
        ((TObjEneMorfos *)ene_morfos)->requested_action = 0;
        ((TObjEneDD *)ene_morfos)->clear_intangible();
        *(s32 *)((s8 *)ene_morfos + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_morfos + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)ene_morfos)->set_field_378(4);
        *(s32 *)((s8 *)ene_morfos + 0x4B0) = 0;
        *(s32 *)((s8 *)ene_morfos + 0x4BC) = 0;
        *(s32 *)((s8 *)ene_morfos + 0x4B4) = 0;
        *(f32 *)((s8 *)ene_morfos + 0x4C4) = 0.0f;
        *(f32 *)((s8 *)ene_morfos + 0x4CC) = 0.0f;
        *(f32 *)((s8 *)ene_morfos + 0x4D0) = 0.0f;
        *(f32 *)((s8 *)ene_morfos + 0x4D4) = 0.0f;
        return;
    case 3:
        if (TObjEneMorfos__sub_803344F0(ene_morfos) == 0) {
            if ((u32) *(u32 *)((s8 *)ene_morfos + 0x390) == 0U) {
                ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)7);
            } else if (*(f32 *)((s8 *)ene_morfos + 0x3AC) <= 30.0f) {
                if (((TObjChara *)ene_morfos)->random_ratio() < 0.3f) {
                    ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)6);
                } else {
                    ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)5);
                }
            } else if ((s32) *(s32 *)((s8 *)ene_morfos + 0x4B4) == 3) {
                ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)6);
            }
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)ene_morfos)->advance_animation();
        ((TObjEneMorfos *)ene_morfos)->play_sound_in_band();
        if (((TObjEneDD_ST *)ene_morfos)->update_linked_position(400.0f) != 0) {
            ((TObjEneDD_ST *)ene_morfos)->enemy_copy_target_destination();
            ((TObjEneDD_ST *)ene_morfos)->update_velocity();
        }
        switch (*(s32 *)((s8 *)ene_morfos + 0x4B4)) {
        case 0:
            if (((TObjEneDD_ST *)ene_morfos)->enemy_has_live_target() != 0) {
                *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) (u16) (s32) (10430.38043493439 * ((f64 (*)(f32, f32)) atan2_float)((f32) (*(f32 *)((s8 *)ene_morfos + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_morfos + 0x3A8))));
            } else {
                *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) ((TObjEneMorfos *)ene_morfos)->rotation_y;
            }
            *(s32 *)((s8 *)ene_morfos + 0x4B4) = 1;
        case 1:
            if (((TObjEneMorfos *)ene_morfos)->approach_value((s32)((int) (*(s32 *)((s8 *)ene_morfos + 0x4BC))), (s32)((int) (*(s32 *)((s8 *)((u8 *) TObjEneMorfos__param_table) + 0x18)))) != 0) {
                *(s32 *)((s8 *)ene_morfos + 0x4B4) = 2;
                *(f32 *)((s8 *)ene_morfos + 0x4CC) = sin_table_lookup((int) (((TObjEneMorfos *)ene_morfos)->rotation_y));
                *(f32 *)((s8 *)ene_morfos + 0x4D4) = cos_table_lookup((int) (((TObjEneMorfos *)ene_morfos)->rotation_y));
            }
            ((TObjEneDD *)(ene_morfos))->update_ground_contact();
            break;
        case 2:
            if (TObjEneDD::check_v2_mode() != 0) {
                if (((TObjEneMorfos *)ene_morfos)->select_target_in_view() != 0) {
                    ((TObjEneDD_ST *)ene_morfos)->enemy_copy_target_destination();
                    ((TObjEneDD_ST *)ene_morfos)->update_velocity();
                    *(s32 *)((s8 *)ene_morfos + 0x4B4) = 3;
                } else if (((TObjEneDD_ST *)ene_morfos)->enemy_has_live_target() != 0) {
                    *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) (u16) (s32) (10430.38043493439 * ((f64 (*)(f32, f32)) atan2_float)((f32) (*(f32 *)((s8 *)ene_morfos + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_morfos + 0x3A8))));
                } else {
                    *(s32 *)((s8 *)ene_morfos + 0x4BC) = (s32) ((TObjEneMorfos *)ene_morfos)->rotation_y;
                }
                ((TObjEneMorfos *)ene_morfos)->approach_value((s32)((int) (*(s32 *)((s8 *)ene_morfos + 0x4BC))), (s32)((int) (*(s32 *)((s8 *)((u8 *) TObjEneMorfos__param_table) + 0x18))));
            } else {
                *(f32 *)((s8 *)ene_morfos + 0x4C4) = (f32) (*(f32 *)((s8 *)ene_morfos + 0x4C4) + *(f32 *)((s8 *)ene_morfos + 0x3D8));
                if (*(f32 *)((s8 *)ene_morfos + 0x4C4) >= *(f32 *)((s8 *)ene_morfos + 0x3DC)) {
                    *(f32 *)((s8 *)ene_morfos + 0x4C4) = 0.0f;
                    *(s32 *)((s8 *)ene_morfos + 0x4B0) = (s32) (*(s32 *)((s8 *)ene_morfos + 0x4B0) + 1);
                    if (((s32) *(s32 *)((s8 *)ene_morfos + 0x4B0) >= 2) && (((TObjEneMorfos *)ene_morfos)->select_target_in_view() != 0)) {
                        *(s32 *)((s8 *)ene_morfos + 0x4B0) = 0;
                        ((TObjEneDD_ST *)ene_morfos)->enemy_copy_target_destination();
                        ((TObjEneDD_ST *)ene_morfos)->update_velocity();
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
        ((TObjEneDD *)(ene_morfos))->check_collisions();
        break;
    }
}
void TObjEneMorfos__sub_80333690(TObjEneMorfos *owner, s32 ev) {
    switch (ev) {
    case 4:
        ((TObjEneDD *)(owner))->clear_intangible();
        *(s32 *)((s8 *)owner + 0x3C0) = (s32) (*(s32 *)((s8 *)owner + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)owner)->set_field_378(6);
        if (((TObjEneDD_ST *)owner)->enemy_has_live_target() != 0) {
            owner->m_4bc = (s32) (u16) ((s32) (10430.38043493439 * atan2_float(owner->destination_direction.x, *(f32 *)((s8 *)owner + 0x3A8))) + 0x8000);
            *(s32 *)((s8 *)owner + 0x4B0) = 0;
            owner->m_4b4 = 0;
            owner->requested_action = 0;
            play_sound_effect(0x4003A528, (uaddr)((u8 *)owner + 0x38), 0, 0);
            return;
        }
        *(s32 *)((s8 *)owner + 0x4B0) = 6;
        return;
    case 3:
        if (((s32) *(s32 *)((s8 *)owner + 0x4B0) == 6) && (((s32 (*)(void *))TObjEneMorfos__sub_803344F0)(owner) == 0)) {
            ((TObjEneDD *)owner)->transition_enemy_state((s32)4);
        }
        break;
    case 5:
        break;
    case 0:
        owner->advance_animation();
        switch (*(s32 *)((s8 *)owner + 0x4B0)) {
        case 0:
            if (owner->approach_value(owner->m_4bc, *(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfos__param_table) + 0x1C)) != 0) {
                *(s32 *)((s8 *)owner + 0x4B0) = 1;
                owner->requested_action = 2;
                spawn_particle_effect((const Vec *)((u8 *)owner + 0x498), 0x212);
            }
            break;
        case 1:
            if (((TObjMotion *)owner)->is_passing_frame(1.0f) != 0) {
                *(s32 *)((s8 *)owner + 0x4B0) = 2;
            }
            break;
        case 2:
            if (((TObjMotion *)owner)->is_passing_frame(6.0f) != 0) {
                play_sound_effect(0x4003AD24, (uaddr)((u8 *)owner + 0x38), 0, 0);
                new TUnk_804EF130((Vec *)((u8 *)owner + 0x498), (u16)(owner->m_4bc + 0x8000), owner);
                *(s32 *)((s8 *)owner + 0x4B0) = 3;
            }
            break;
        case 3:
            if (owner->get_flag_b4() != 0) {
                owner->requested_action = 0;
                owner->m_4b4 = (owner->m_4b4 + 1);
                if (((TObjEneDD_ST *)owner)->enemy_has_live_target() != 0) {
                    if ((s32) owner->m_4b4 >= 2) {
                        owner->m_4bc = (s32) (10430.38043493439 * atan2_float(owner->destination_direction.x, *(f32 *)((s8 *)owner + 0x3A8)));
                        *(s32 *)((s8 *)owner + 0x4B0) = 5;
                    } else {
                        owner->requested_action = 0;
                        *(s32 *)((s8 *)owner + 0x4B0) = 4;
                        *(s32 *)((s8 *)owner + 0x4B8) = 0;
                    }
                } else if (owner->select_target_in_view() != 0) {
                    ((TObjEneDD_ST *)owner)->enemy_copy_target_destination();
                    ((TObjEneDD_ST *)owner)->update_velocity();
                    if ((s32) owner->m_4b4 >= 2) {
                        owner->m_4bc = (s32) (10430.38043493439 * atan2_float(owner->destination_direction.x, *(f32 *)((s8 *)owner + 0x3A8)));
                        *(s32 *)((s8 *)owner + 0x4B0) = 5;
                        play_sound_effect(0x4003A528, (uaddr)((u8 *)owner + 0x38), 0, 0);
                    } else {
                        owner->requested_action = 0;
                        *(s32 *)((s8 *)owner + 0x4B0) = 4;
                        *(s32 *)((s8 *)owner + 0x4B8) = 0;
                    }
                } else {
                    owner->m_4bc = (s32) (u16) (owner->m_4bc + 0x8000);
                    *(s32 *)((s8 *)owner + 0x4B0) = 5;
                }
            }
            break;
        case 4:
            *(s32 *)((s8 *)owner + 0x4B8) = (s32) (*(s32 *)((s8 *)owner + 0x4B8) + 1);
            if ((s32) *(s32 *)((s8 *)owner + 0x4B8) >= (s32) *(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfos__param_table) + 0x20)) {
                if (((TObjEneDD_ST *)owner)->enemy_has_live_target() != 0) {
                    ((TObjEneDD_ST *)owner)->enemy_copy_target_destination();
                    ((TObjEneDD_ST *)owner)->update_velocity();
                    owner->m_4bc = (s32) (u16) ((s32) (10430.38043493439 * atan2_float(owner->destination_direction.x, *(f32 *)((s8 *)owner + 0x3A8))) + 0x8000);
                    *(s32 *)((s8 *)owner + 0x4B0) = 0;
                    play_sound_effect(0x4003A528, (uaddr)((u8 *)owner + 0x38), 0, 0);
                } else {
                    *(s32 *)((s8 *)owner + 0x4B0) = 6;
                }
            }
            break;
        case 5:
            if (owner->approach_value(owner->m_4bc, *(s32 *)((s8 *)(*(u8 * *)&TObjEneMorfos__param_table) + 0x1C)) != 0) {
                *(s32 *)((s8 *)owner + 0x4B0) = 6;
            }
            break;
        }
        ((TObjEneDD *)(owner))->update_ground_contact();
        ((TObjEneDD *)(owner))->check_collisions();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#define F(o, t) (*(t *)(self + (o)))
#define D (*(D_80333290 * *)&TObjEneMorfos__param_table)
void TObjEneMorfos::state_rotating_projectile_burst(s32 ev) {
    s32 old;
    s32 n;
    s32 i;
    u8 *pl;
    u8 *self = (u8 *)this;
    switch (ev) {
    case 4:
        ((TObjEneDD *)self)->clear_intangible();
        F(0x3C0, s32) &= ~3;
        F(0x3C0, s32) |= 4;
        ((TObjEneDD *)self)->set_field_378(4);
        F(0x4BC, s32) = 0;
        F(0x4C0, s32) = 0;
        F(0x4B0, s32) = 0;
        F(0x4B8, s32) = 0;
        F(0xB8, s16) = 0;
        F(0x494, u32) = (uaddr)create_particle_emitter(self + 0x498, 0x10A);
        break;
    case 3:
        if (F(0x4B0, s32) == 5 && TObjEneMorfos__sub_803344F0(self) == 0) {
            ((TObjEneDD *)self)->transition_enemy_state((s32)4);
        }
        break;
    case 0:
        ((TObjMotion *)self)->advance_animation();
        switch (F(0x4B0, s32)) {
        case 0:
            if (F(0x494, u32) != 0) {
                ((TParticleCtrl *)F(0x494, void *))->set_position(self + 0x498);
            }
            F(0x4C0, s32) = F(0x60, s32);
            F(0x60, s32) = F(0x60, s32) + D->f28;
            F(0x4B8, s32) = F(0x4B8, s32) + 1;
            if (F(0x4B8, s32) >= D->f24) {
                F(0x4B0, s32) = 1;
                F(0x4B4, s32) = 0;
                if (F(0x494, u32) != 0) {
                    ((TObject *)(F(0x494, void *)))->queue_destruction();
                    F(0x494, u32) = 0;
                }
            }
            break;
        case 1: {
            old = F(0x60, s32);
            F(0x60, s32) += D->f1C;
            n = TLobby::get_game_mode();
            for (i = 0; i < n; i++) {
                pl = (u8 *)TObjPlayer::get_player_data(i);
                if (((TObjBase *)pl)->is_alive() != 0) {
                    if (((TObjBase *)self)->get_room() == ((TObjBase *)pl)->get_room()) {
                        ((TObjEneDD_ST *)self)->enemy_copy_target_destination();
                        ((TObjEneDD_ST *)self)->update_velocity();
                        F(0x4BC, s32) = (u16)((s32)(10430.38043493439 * atan2_float(F(0x3A0, f32), F(0x3A8, f32))) + 0x8000);
                        if (check_value_in_range__13TObjEneMorfosFPvUsUsUs(self, old, F(0x60, s32), F(0x4BC, s32)) != 0) {
                            F(0x60, s32) = F(0x4BC, s32);
                            F(0x4B0, s32) = 2;
                            F(0xB8, s16) = 2;
                            break;
                        }
                    }
                }
            }
            if (F(0x4B0, s32) == 1 && check_value_in_range__13TObjEneMorfosFPvUsUsUs(self, old, F(0x60, s32), F(0x4C0, s32)) != 0) {
                F(0x4B0, s32) = 2;
                F(0xB8, s16) = 2;
            }
            break;
        }
        case 2:
            spawn_particle_effect((const Vec *)(self + 0x498), 0x212);
            if (((TObjMotion *)self)->is_passing_frame(1.0f) != 0) {
                F(0x4B0, s32) = 3;
            }
            break;
        case 3:
            if (((TObjMotion *)self)->is_passing_frame(6.0f) != 0) {
                play_sound_effect(0x4003AD24, (uaddr)(self + 0x38), 0, 0);
                new TUnk_804EF130((Vec *)(self + 0x498), (u16)(F(0x60, s32) + 0x8000), (TObjEneMorfos *)self);
                F(0x4B0, s32) = 4;
            }
            break;
        case 4:
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
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
        ((TObjEneDD *)self)->update_ground_contact();
        ((TObjEneDD *)self)->check_collisions();
        break;
    case 5:
        if (F(0x494, u32) != 0) {
            ((TObject *)(F(0x494, void *)))->queue_destruction();
            F(0x494, u32) = 0;
        }
        break;
    }
}
#pragma pop


void TObjEneMorfos__sub_80332FD4(TObjEneMorfos *arg0, s32 ev) {
    switch (ev) {
    case 4:
        arg0->requested_action = 0;
        ((TObjEneDD *)arg0)->clear_intangible();
        *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFFF8);
        ((TObjEneDD *)arg0)->set_field_378(5);
        *(s32 *)((s8 *)arg0 + 0x4B0) = 0;
        arg0->m_4b4 = 0;
        break;
    case 3:
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if ((((s32 (*)(void *))TObjEneMorfos__sub_803344F0)(arg0) == 0) && ((void *) arg0->current_target == NULL)) {
                ((TObjEneDD *)arg0)->transition_enemy_state((s32)7);
            }
            break;
        case 3:
            ((TObjEneDD *)arg0)->transition_enemy_state((s32)4);
            break;
        }
        break;
    case 5:
        break;
    case 0:
        arg0->advance_animation();
        switch (*(s32 *)((s8 *)arg0 + 0x4B0)) {
        case 0:
            if (enemy_validate_retained_target(arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD_ST *)arg0)->update_velocity();
                if (arg0->approach_value((s32) (10430.38043493439 * atan2_float(arg0->destination_direction.x, *(f32 *)((s8 *)arg0 + 0x3A8))), *(s32 *)((s8 *)((u8 *)TObjEneMorfos__param_table) + 0x1C)) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 1;
                    arg0->requested_action = 1;
                    play_sound_effect(0x4003A725, (uaddr)((u8 *)arg0 + 0x38), 0, 0);
                    TObjEneMorfosArm::create((void *)arg0, (void *)arg0);
                } else if (*(f32 *)((s8 *)arg0 + 0x3AC) >= 30.0f) {
                    *(s32 *)((s8 *)arg0 + 0x4B0) = 3;
                }
                arg0->play_sound_in_band();
            }
            break;
        case 1:
            if ((((TObjMotion *)arg0)->is_passing_frame(8.0f) != 0) && (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0)) {
                if (((VObj_18_76ddf3 *)(arg0->current_target))->m18(arg0, 1.0f) != 0) {
                    ((VObj_18_76ddf3 *)(arg0->current_target))->m20(arg0, 1.0f);
                    ((VObj_18_76ddf3 *)(arg0->current_target))->m23(arg0, 5.0f);
                }
            }
            if (arg0->get_flag_b4() != 0) {
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
        ((TObjEneDD *)arg0)->update_ground_contact();
        ((TObjEneDD *)arg0)->check_collisions();
        break;
    }
}

void TObjEneMorfos::state_patrol(s32 ev) {
    s32 temp_r4;

    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF8);
        set_field_378(8);
        *(s32 *)((s8 *)this + 0x4B0) = 0;
        this->m_4bc = (this->rotation_y + 0x3800);
        break;
    case 3:
        if ((s32) this->rotation_y >= (s32) this->m_4bc) {
            transition_enemy_state((s32)6);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (((TObjEneRe7BeruraPunch *)this)->is_patrol_active() == 0) {
            this->play_speed = 1.6f;
        }
        temp_r4 = this->rotation_y;
        this->rotation_y = (temp_r4 + 0x280);
        ((V_A_803326C4 *) this)->m100(temp_r4);
        this->check_collisions();
        break;
    }

}

void TObjEneMorfos__sub_80332DBC(u8 *ene_morfos, s32 ev) {
    s32 temp_r3;
    switch (ev) {
    case 4:
        ((TObjEneMorfos *)ene_morfos)->requested_action = 3;
        ((TObjEneDD *)ene_morfos)->clear_intangible();
        *(s32 *)((s8 *)ene_morfos + 0x3C0) = (s32) (*(s32 *)((s8 *)ene_morfos + 0x3C0) & 0xFFFFFFF8);
        ((TObjMotion *)ene_morfos)->advance_animation();
        ((TObjEneDD_ST *)ene_morfos)->set_active();
        return;
    case 3:
        if (((TObjEneDD *)ene_morfos)->get_flag_b4() != 0) {
            temp_r3 = *(s32 *)((s8 *)ene_morfos + 0x3C0);
            if (temp_r3 & 0x20) {
                *(s32 *)((s8 *)ene_morfos + 0x3C0) = (s32) (temp_r3 & 0xFFFFFFDF);
                if (((TObjEneMorfos *)ene_morfos)->try_enter_low_hp_state() == 0) {
                    ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)((s32)((int) (((TObjEneMorfos *)ene_morfos)->next_mode))));
                }
            } else {
                if (((TObjEneMorfos *)ene_morfos)->check_low_hp_trigger() != 0) {
                    ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)((s32)((int) (((TObjEneMorfos *)ene_morfos)->next_mode))));
                } else if (((TObjEneMorfos *)ene_morfos)->try_enter_low_hp_state() == 0) {
                    ((TObjEneDD *)ene_morfos)->transition_enemy_state((s32)((s32)((int) (((TObjEneMorfos *)ene_morfos)->next_mode))));
                }
            }
        }
        break;
    case 0:
        ((TObjMotion *)ene_morfos)->advance_animation();
        return;
    case 5:
        ((TObjEneDD *)ene_morfos)->clear_attack_receipts();
        ((TObjEneDD *)ene_morfos)->clear_field_388();
        break;
    }
}

void TObjEneMorfos::state_death(s32 arg1) {
    u8 *self = (u8 *)this;
    s32 temp_r0;
    s32 temp_r30;

    switch (arg1) {
    case 4:
        this->requested_action = 4;
        this->clear_intangible();
        *(s32 *)((s8 *)self + 0x3C0) = (s32) (*(s32 *)((s8 *)self + 0x3C0) & 0xFFFFFFF8);
        ((TObjMotion *)self)->advance_animation();
        ((TObjEnemy *)self)->refresh_and_send_entity_flags();
        this->m_4c4 = (f32) *(s32 *)((s8 *)self + 0x3D4);
        this->m_4b4 = 0;
        *(s32 *)((s8 *)self + 0x4B0) = 0;
        ((TObjEneMe3SinowZoa *)(self + 0x408))->init_death_params();
        play_sound_effect(0x4003A626, (uaddr)(self + 0x38), 0, 0);
        return;
    case 3:
        if ((s32) this->m_4b4 == 2) {
            queue_destruction();
        }
    case 5:
        return;
    case 0:
        temp_r0 = this->m_4b4;
        switch (temp_r0) {
        case 0:
            ((TObjMotion *)self)->advance_animation();
            temp_r30 = ((VObj_14_c1c33b *)(self + (1032)))->m4();
            if ((((TObjEneDD *)self)->get_flag_b4() != 0) && (temp_r30 != 0)) {
                fn_800D911C((Vec *)(self + 0x38));
                play_sound_effect(0x4003A830, (uaddr)(self + 0x38), 0, 0);
                TObjPlayer__sub_800A04F0((u8 *)&this->m_3ec);
                *(s32 *)((s8 *)self + 0x3C0) = (s32) (*(s32 *)((s8 *)self + 0x3C0) | 2);
                this->m_4b4 = 1;
                return;
            }
            break;
        case 1:
            if (((VObj_14_c1c33b *)(self + (1004)))->m4() != 0) {
                this->m_4b4 = 2;
                *(s32 *)((s8 *)self + 0x3C0) = (s32) (*(s32 *)((s8 *)self + 0x3C0) | 1);
                TObjPlayer::apply_effect_variant_b((saddr)(self + 0x38), 0);
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

// inferred name, from its only user (get_camera_ctrl in record_camera_path_point).
static const Vec morfos_camera_path_origin = {0.0f, 0.0f, 0.0f};
void TObjEneMorfos::record_camera_path_point(NJS_OBJECT *) {
    switch (TObjEneMorfos__phase) {
    case 6:
    case 10: {
        Vec pos = morfos_camera_path_origin;
        forward_transform_to_view((const Vec *)&pos, TObjEneMorfos__camera_path_cursor);
        TObjEneMorfos__camera_path_cursor++;
        break;
    }
    }
    TObjEneMorfos__phase += 1;
}

void TObjEneMorfos::render_part(s32 idx, s32 mode) {
    s32 vis;
    Part_803329E4 *part;
    Self_803329E4 *self = (Self_803329E4 *)this;
    part = &self->parts[idx];
    ((RenderFadeState *)part)->update();
    vis = ((RenderFadeState *)part)->updateFromCamera((const f32*)(self->cam));
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, this->rotation_y);
    TObjEneMorfos__phase = 0;
    TObjEneMorfos__camera_path_cursor = (Vec *)self->f498;
    set_chunk_model_node_callback(TObjEneMorfos::record_camera_path_point);
    if (self->f3C0 & 2) {
        if (self->body.m8() != 0) {
            self->body.m6();
            if ((s32)main_task.get_task_flags() & 0x200) {
                ((TObjMotion *)self)->draw();
            }
            self->body.m7();
        }
    } else if (vis != 0) {
        part->m6();
        if ((s32)main_task.get_task_flags() & 0x200) {
            ((TObjMotion *)self)->draw();
        }
        part->m7();
    } else if (!((s32)main_task.get_task_flags() & 0x200)) {
        if (mode == 1) {
            ((TObjMotion *)self)->draw();
        } else {
            ((TObjEnemy *)self)->draw_motion_model();
        }
    }
    set_chunk_model_node_callback(NULL);
    pop_matrix();
    ((TObjEneDD *)self)->update_primary_light();
    TParticleCtrl::end_effect_render();
}

// inferred name: the draw_ground_shadow scale in render.
static const Vec morfos_render_shadow_scale = {2.0f, 1.0f, 2.0f};
#define ene_morfos ((u8 *)this)
void TObjEneMorfos::render() {
    s32 cam;
    s32 vis;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_80332850 *)ene_morfos)->m104();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (*(u32 *)((s8 *)ene_morfos + 0x3C0) & 1) {
        vis = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        vis = ((TObjEneMorfos *)ene_morfos)->classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
    } else if (((TObjEneMorfos *)ene_morfos)->update_object_view_visibility(400.0f, 15.0f) != 0) {
        vis = 1;
    } else {
        vis = 0;
    }
    if (vis != 0 && ((TObjEneMorfos *)ene_morfos)->render_model_if_visible() == 0) {
        ((TObject *)ene_morfos)->defer_render();
        ((TObjEneMorfos *)ene_morfos)->render_part(cam, vis);
        if (((TObjEneMorfos *)ene_morfos)->mode != 0xB && !(*(u32 *)((s8 *)ene_morfos + 0x3C4) & 0x4000)) {
            Vec v = morfos_render_shadow_scale;
            ((TObjEneDD *)(ene_morfos))->draw_ground_shadow(&v, 0);
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
#undef ene_morfos
s32 TObjEneMorfos::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x3C8)) != 0) {
            TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(this->texlist));
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

#pragma push
#pragma opt_common_subs off
void TObjEneMorfos::draw_body() {
    u8 *self = (u8 *)this;
    if ((s32)main_task.get_task_flags() & 0x200) {
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(TObjEneMorfos__instance->models[2].m_c));
        push_matrix();
        post_translate_matrix(self + 0x498);
        rotate_matrix_y(0, (int) (((RecoveredFields_803326CC_arg0 *)self)->field_60));
        if (((RecoveredFields_803326CC_arg0 *)self)->field_3C0 & 2) {
            if (((VObj_14_fddec9 *)(self + (1032)))->m8() != 0) {
                ((VObj_14_fddec9 *)(self + (1032)))->m6();
                draw_chunk_model(TObjEneMorfos__instance->models[2].model->model);
                ((VObj_14_fddec9 *)(self + (1032)))->m7();
            }
        } else {
            draw_chunk_model(TObjEneMorfos__instance->models[2].model->model);
        }
        pop_matrix();
    }
}
#pragma pop


BmlResource *TObjEneMorfos::get_instance() {  return TObjEneMorfos__instance; }
s32 TObjEneMorfosArm__sub_803326BC(void* p) { return *(s32*)((char*)p + 0x60); }

void* TObjEneMorfosArm__sub_803326B4(void* p) { return (char*)p + 0x4a4; }

u8 TObjEneMorfos::check_value_in_range(void *arg0, u16 arg1, u16 arg2, u16 arg3) {
    s32 r;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = arg1;
    b = arg2;
    if (a > b) {
        c = arg3;
        r = 0;
        d = a - c;
        if ((d >= 0 && b - c >= 0) || (d <= 0 && b - c <= 0)) {
            r = 1;
        }
        return r;
    } else {
        s32 r2;
        s32 d2;
        s32 c2;
        c2 = arg3;
        r2 = 0;
        d2 = a - c2;
        if ((d2 <= 0 && b - c2 >= 0) || (d2 >= 0 && b - c2 <= 0)) {
            r2 = 1;
        }
        return r2;
    }
}

void TObjEneMorfos::update_ground_probe() {
    u8 *self = (u8 *)this;
    Stack_80332594 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += 15.0f;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (CsnGroup **)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)self + 0x3C4) = (s32) *(s32 *)((s8 *)temp_r3 + 0);
            VecCopy((Vec *)(self + 0x3C8), (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy((Vec *)(self + 0x3C8), (const Vec *)&this->position);
        }
    }
    if (*(s32 *)((s8 *)self + 0x3C4) & 0x4000) {
        request_reflection_render();
    }
}

void TObjEneMorfos::run_demo_task() { if (get_target_info() != 0) { this->init_target_offsets(); } }

// inferred name: the draw_ground_shadow scale in vfunc_106.
static const Vec morfos_vfunc_106_shadow_scale = {2.0f, 1.0f, 2.0f};
void TObjEneMorfos::render_demo() {
    O_803323D8 *self = (O_803323D8 *)this;
    s32 idx;
    f32 frame;
    Anim_803323D8 *anim;
    ((TObjEneDD *)self)->get_target_info();
    if (((VObj_803323D8 *)self)->m8(400.0f, 15.0f) != 0) {
        if (self->f326 != 0xB) {
            Vec v = morfos_vfunc_106_shadow_scale;
            ((TObjEneDD *)(self))->draw_ground_shadow(&v, 0);
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(self->f24));
        push_matrix();
        post_translate_matrix((u8 *)self + 0x38);
        rotate_matrix_y(0, self->f60);
        idx = (s32)self->f354;
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 5) {
            idx = 4;
        }
        anim = self->bones[self->mots[idx].bone].anim;
        frame = self->frame;
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (anim->count - 1)) {
            frame = (f32)anim->count;
        }
        set_motion_packed_rotation();
        draw_model_motion(model, anim, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

}

saddr lbl_805D6D08[1];
saddr lbl_805D6D0C[1];
saddr TObjEneMorfos__param_table;
BmlResource *TObjEneMorfos__instance;
s32 TObjEneMorfos__phase;
Vec *TObjEneMorfos__camera_path_cursor;
s16 *lbl_805D6D20;
s16 *lbl_805D6D24;
s32 lbl_805D6D28;
s32 lbl_805D6D2C;
float morfos_projectile_speed;
float morfos_param_table_speed_copy;
