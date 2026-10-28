#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneRe4Sorcerer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/map/CurrentArea.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/TParticleCtrl.h"

#include "pso/enemy/TObjEneRe4Bit.h"
#include "pso/object/TObjFish.h"

#include "pso/player/TUnk_80490470.h"

extern "C" {

void vfunc_106__18TObjEneRe4SorcererFv(u8 *arg0);
s32 post_translate_matrix(void *);
s32 update_player_state__9TObjEneDDFv(void *, int, int);
s32 TObjEneRe4Sorcerer__sub_801E3F1C(f32, f32);
s32 get_target_info__9TObjEneDDFv();
s32 scroll_strip_uvs(int, int, int);
s32 rotate_matrix_y(int, int);
s32 translate_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 pop_matrix();
void draw_chunk_object(void *child);

extern u32 TObjEneRe4Sorcerer__uv_scroll_buffer;
extern s32 model_render_flags;

struct Base { u8 pad[0x18]; };
struct VObj : Base {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual s32 m8(f32, f32) = 0;
};

extern "C" {
__declspec(section ".sdata2") extern void *const lbl_805DA788[1] = {
    (void *)0x43c80000,
};
__declspec(section ".sdata2") extern void *const TObjEneRe4Sorcerer__data_805DA78C[1] = {
    (void *)0x41700000,
};
__declspec(section ".sdata2") extern void *const TObjEneRe4Sorcerer__data_805DA790[1] = {
    (void *)0x0,
};
__declspec(section ".sdata2") extern void *const TObjEneRe4Sorcerer__data_805DA794[1] = {
    (void *)0x41b00000,
};
}
#define lbl_805DA788 (*(const f32 *)lbl_805DA788)
#define TObjEneRe4Sorcerer__data_805DA78C (*(const f32 *)TObjEneRe4Sorcerer__data_805DA78C)
#define TObjEneRe4Sorcerer__data_805DA790 (*(const f32 *)TObjEneRe4Sorcerer__data_805DA790)
#define TObjEneRe4Sorcerer__data_805DA794 (*(const f32 *)TObjEneRe4Sorcerer__data_805DA794)

void TObjEneRe4Sorcerer::vfunc_106() {
    u8 *arg0 = (u8 *)this;
    get_target_info__9TObjEneDDFv();
    if (((VObj *)arg0)->m8(lbl_805DA788, TObjEneRe4Sorcerer__data_805DA78C) != 0) {
        update_player_state__9TObjEneDDFv(arg0, 0, 0);
        TObjFish::set_global_param(*(s32 *)((s8 *)arg0 + 0x24));
        ((s32 (*)())push_matrix)();
        ((s32 (*)(void *))post_translate_matrix)(arg0 + 0x38);
        ((s32 (*)(s32, f32, f32, f32))translate_matrix)(0, TObjEneRe4Sorcerer__data_805DA790, TObjEneRe4Sorcerer__data_805DA794, TObjEneRe4Sorcerer__data_805DA790);
        ((s32 (*)(s32, s32))rotate_matrix_y)(0, *(s32 *)((s8 *)arg0 + 0x60));
        *(s16 *)((s8 *)arg0 + 0x3C0) = (s16) (*(s16 *)((s8 *)arg0 + 0x3C0) + 5);
        ((s32 (*)(s32, s16, s32))scroll_strip_uvs)(TObjEneRe4Sorcerer__uv_scroll_buffer, *(s16 *)((s8 *)arg0 + 0x3C0), 0);
        *(f32 *)((s8 *)arg0 + 0x3C4) += 0.01f;
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C(TObjEneRe4Sorcerer__data_805DA790, *(f32 *)((s8 *)arg0 + 0x3C4));
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
        TParticleCtrl::end_effect_render();
        model_render_flags &= 0xFFFDFFFF;
        ((s32 (*)())pop_matrix)();
    }
}

__declspec(section ".sdata2") extern void *const lbl_805DA79C[1] = {
    (void *)0x3f4ccccd,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7A0[1] = {
    (void *)0x42c80000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7A4[1] = {
    (void *)0x43700000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7A8[1] = {
    (void *)0x42b40000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7AC[1] = {
    (void *)0x41300000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7B0[1] = {
    (void *)0x42700000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7B4[1] = {
    (void *)0x41a00000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7B8[1] = {
    (void *)0x43200000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7BC[1] = {
    (void *)0x461c4000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7C0[1] = {
    (void *)0x481c4000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7C4[1] = {
    (void *)0x42a00000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7C8[1] = {
    (void *)0x41f00000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7CC[1] = {
    (void *)0x3e4ccccd,
};
#define lbl_805DA79C (*(const f32 *)lbl_805DA79C)
#define lbl_805DA7A0 (*(const f32 *)lbl_805DA7A0)
#define lbl_805DA7A4 (*(const f32 *)lbl_805DA7A4)
#define lbl_805DA7A8 (*(const f32 *)lbl_805DA7A8)
#define lbl_805DA7AC (*(const f32 *)lbl_805DA7AC)
#define lbl_805DA7B0 (*(const f32 *)lbl_805DA7B0)
#define lbl_805DA7B4 (*(const f32 *)lbl_805DA7B4)
#define lbl_805DA7B8 (*(const f32 *)lbl_805DA7B8)
#define lbl_805DA7BC (*(const f32 *)lbl_805DA7BC)
#define lbl_805DA7C0 (*(const f32 *)lbl_805DA7C0)
#define lbl_805DA7C4 (*(const f32 *)lbl_805DA7C4)
#define lbl_805DA7C8 (*(const f32 *)lbl_805DA7C8)
#define lbl_805DA7CC (*(const f32 *)lbl_805DA7CC)

void vfunc_83__18TObjEneRe4SorcererFv(void* p);

void TObjEneRe4Sorcerer__sub_800EFE30(void);

s32 TObjEneRe4Sorcerer::vfunc_83() { if (((int (*)(void*))get_target_info__9TObjEneDDFv)(this) != 0) { ((int (*)(void*))TObjEneRe4Sorcerer__sub_800EFE30)(this); } }

}

#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/misc/TTecGrants.h"
#include "pso/misc/TTecMegid.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TTecResta.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VBase_14 { char pad[0x14]; };

struct VObj_14 : VBase_14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
};

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
    virtual s32 m104();
};

struct Fade_800EDCCC { u8 b[0x1C]; };

struct Sorc_800EDCCC { u8 pad[0x474]; Fade_800EDCCC fades[2]; };

struct VBase_18_d3ac76 { char pad[0x18]; };

struct VObj_18_d3ac76 : VBase_18_d3ac76 {
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
    virtual s32 m97();
};

struct Obj_800EFB60 : VObj_18_d3ac76 { u8 pad2[0x3e4 - 0x1c]; u16 orbs[2]; };

extern "C" {
f64 atan2_float(f32, f32);
s32 set_field_378__9TObjEneDDFl(void *, s32);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
int TObjEneRe4Sorcerer__sub_800ED498(u8 *arg0);
void TObjEneRe4Sorcerer__sub_800EF214(s32 arg0);
s32 advance_animation_playback(void *);
void *find_entity_by_id(u16 id);
extern const f64 TObjEneRe4Sorcerer__data_8043D408;
void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *arg0, s32 arg1);
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_obstruction_fade(int);
s32 defer_render__7TObjectFv(void *);
extern s32 TObjEneRe4Sorcerer__render_node_index;
extern s32 TObjEneRe4Sorcerer__saved_render_flags;
extern f32 TObjEneRe4Sorcerer__effect_render_scale;
extern s32 re4_sorcerer_render_node_ptr;
extern s32 saved_model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
void render__18TObjEneRe4SorcererFv(u8 *arg0);
int get_player_data__10TObjPlayerFi(int a0);
s16 get_entity_id(void *);
s32 *csnLookAt(s32 arg0, s32 arg1);
s32 enemy_bind_or_clear_target(void *, u16);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
void enemy_set_target_id(void *, u16);
int is_target_ranger(void *p);
s32 is_alive__9TObjEneDDFv(s32);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
f32 horizontal_distance_squared(void *, void *);
s32 select_attack_target__18TObjEneRe4SorcererFiff(s32 arg0, f32 farg0, f32 farg1);
void scale_matrix(s32, s32, f32, f32, f32);
struct VBase_18_aab587
{
  char pad[0x18];
};

struct VObj_18_aab587 : VBase_18_aab587 {
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
};

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

typedef struct { f32 x, y, z; } Vec_800EE0F8;

struct VBase_14_763762 { char pad[0x14]; };

struct VObj_14_763762 : VBase_14_763762 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct Sorc_800EEDE4 {
    u8 pad0[0x3E4];
    u16 ids[2];
};

struct Sorc_800EEC00 {
    u8 pad0[0x3E4];
    u16 ids[2];
};

typedef struct { f32 x, y, z; } Vec_800EF354;

typedef struct VBase_18_aab587 VBase_18_aab587;

typedef struct VObj_18_aab587 VObj_18_aab587;

struct Base_800EF7C8 { u8 pad[0x18]; };

struct V_800EF7C8 : Base_800EF7C8 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79(); virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91(); };

struct Obj_800EF7C8 : V_800EF7C8 { u8 pad2[0x3e4 - 0x1c]; u16 orbs[2]; };

struct Base_800EF844 { u8 pad[0x18]; };

struct V_800EF844 : Base_800EF844 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79(); virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91(); virtual void m92(); };

struct Obj_800EF844 : V_800EF844 { u8 pad2[0x3e4 - 0x1c]; u16 orbs[2]; };

struct Vec_800EF95C { f32 x, y, z; };

struct Base_800EF95C { u8 pad[0x18]; };

struct V_800EF95C : Base_800EF95C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95(); virtual void m96(); virtual void m97(); virtual void m98(); virtual void m99();
    virtual void m100();
};

struct Obj_800EF95C : V_800EF95C {
    u8 pad1c[0x38 - 0x1C];
    Vec_800EF95C pos;
    Vec_800EF95C prev;
    u8 pad50[0x60 - 0x50];
    s32 rot;
    u8 pad64[0x120 - 0x64];
    u8 col[0x394 - 0x120];
    u8 mtx[0x3E4 - 0x394];
    u16 orbs[2];
    u8 pad3e8[0x3F0 - 0x3E8];
    s32 ang;
};

struct Obj_800F0054 { u8 pad[0x3E4]; u16 handles[2]; };

typedef struct { f32 x, y, z; } Vec_800F0464;

struct Params_800F0464 { s32 a, b, c, d; };

struct Map_800F06B4 { s32 base; s32 start; };

struct VBase_14_fa0828 { char pad[0x14]; };

struct VObj_14_fa0828 : VBase_14_fa0828 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual s32 m3();
};

struct VBase_18_be4a70 { char pad[0x18]; };

struct VObj_18_be4a70 : VBase_18_be4a70 {
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
};

struct Vec_800F0118 { f32 x, y, z; };

struct E_800F0118 { u8 pad[0x1C]; };

struct Sorc_800F0118 {
    u8 pad0[0x1C];
    u16 f1C;
    u8 pad1E[0x2C - 0x1E];
    s16 f2C;
    u8 pad2E[0x3CC - 0x2E];
    Vec_800F0118 v3CC[2];
    u16 f3E4;
    u16 f3E6;
    u8 pad3E8[0x474 - 0x3E8];
    E_800F0118 e474[4];
};

s32 VecCopy__FP3VecPC3Vec(void *, void *);
void queue_destruction__7TObjectFv(void *arg0);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void TLobby__sub_8001FE7C(void*, int);
void fn_80044330(void *);
s32 *csnVectorUnder(s32 arg0, u32 *arg1, s32 arg2);
s32 TObjPlayer__sub_800A04F0(void *);
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 reset_hp__9TObjEneDDFv(void *, void *, void *, void *);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
int TObjEneDD__sub_800BA804(u16 arg0);
s32 init_model__9TObjEneDDFv(void *, void *, int, int);
u32 vfunc_102__9TObjEneDDFv();
u32 vfunc_101__9TObjEneDDFPUc();
s32 clear_attack_receipts__9TObjEneDDFv(void *);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
u32 load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
s32 reset_transform__13TObjEneRe4BitFv();
s32 set_flag_and_notify__18TObjEneRe4SorcererFv();
u8 * get_spell_data__18TObjEneRe4SorcererFv();
s32 create_enabled__13TObjEneRe4BitFlll(void *, void *, int, int);
void TObjEneRe4Bit__sub_800EDAB0(void);
void TObjEneRe4Bit__sub_800EDAB4();
void TObjEneRe4Sorcerer__sub_800EE0F8(u8 *arg0, s32 arg1);
void TObjEneRe4Sorcerer__sub_800EE1CC(u8 *arg0, s32 arg1);
s32 TObjEneRe4Sorcerer__sub_800EEC00(void *arg0p, void *arg1p);
s32 TObjEneRe4Sorcerer__sub_800EEDE4(void *arg0p, void *arg1p);
void TObjEneRe4Sorcerer__sub_800EEFE4(u8 *arg0, s32 arg1);
void TObjEneRe4Sorcerer__vt85(s32 arg0, u32 arg1, s32 arg2);
void TObjEneRe4Sorcerer__sub_800EF7C8(Obj_800EF7C8 *self);
void TObjEneRe4Sorcerer__sub_800EF844(Obj_800EF844 *self);
void set_motion_by_state__18TObjEneRe4SorcererFPv(void *arg0);
void TObjEneRe4Sorcerer__sub_800EF95C(Obj_800EF95C *self, f32 speed);
void vfunc_102__18TObjEneRe4SorcererFv(u8 *arg0);
void vfunc_101__18TObjEneRe4SorcererFPUc(u8 *arg0);
void vfunc_88__18TObjEneRe4SorcererFv(void *arg0);
void vfunc_61__18TObjEneRe4SorcererFv(void);
void vfunc_62__18TObjEneRe4SorcererFv(u8 *arg0);
void vfunc_63__18TObjEneRe4SorcererFv(void* p);
void vfunc_28__18TObjEneRe4SorcererFv(void);
void run_task__18TObjEneRe4SorcererFv(u8 *arg0);
Obj_800F0054 * __dt__18TObjEneRe4SorcererFv(Obj_800F0054 *arg0, s16 arg1);
void * TObjEneRe4Sorcerer__ct(void *arg0, void *arg1, void *arg2);
void TBoss3Volopt__sub_800F059C(void);
s32 remap_area_sound_id(s32 arg0, s32 arg1);
}
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
s32 tick_period_counter(s32 arg0, s32 *arg1, s32 arg2);
void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
s32 copy_target_state__14TObjEnePanarmsFPv(void *, s32);
s32 approach_angle_limited(s32, s32, s32);
s32 free_collision_body_parts(void *);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 play_sound_effect(void *, void *, int, int);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
s32 create_ex__11TTecGiBartaFPvPvPv(void *, void *, s32, s32);
void __destroy_arr(void *, void *, u32, u32);
void __construct_array(void *, void *, void *, int, int);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void vec3_add_to(void *, void *);
s32 subtract_vector(void *, void *);

extern s32 __dt__13TUnk_804949A8Fv[];
extern s32 init_and_activate__10TObjPlayerFv[];
extern Params_800F0464 re4_sorcerer_spawn_descriptor;
extern u8 lbl_8043D418[];
extern Map_800F06B4 area_sound_remap_table_a[];
extern Map_800F06B4 area_sound_remap_table_b[];
extern Vec_800F0464 lbl_80501070;
extern void *lbl_805D2AF0;
extern s32 lbl_805D52D0;
extern s32 TObjEneRe4Sorcerer__attack_params;
extern s32 TObjEneRe4Sorcerer__resistance_params;
extern u8 *sorcerer_behavior_params;
extern u32 sorcerer_bml_resource;
extern void *tl_04;

extern "C" {
void vfunc_6__8TObjBaseFPsl();
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
int TObjEneEpsilon__vt101(void *p);
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void vfunc_29__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void vfunc_67__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void vfunc_60__9TObjCharaFv();
}
extern "C" {
void vfunc_59__9TObjCharaFv();
}
extern "C" {
void vfunc_58__9TObjCharaFv();
}
extern "C" {
void apply_slow_status__9TObjCharaFv();
}
extern "C" {
void update_shock_clock__9TObjCharaFv();
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
void vfunc_18__9TObjCharaFPUc();
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void add_actor_exp__9TObjCharaFl();
}
extern "C" {
void apply_action_hold_status__9TObjCharaFf();
}
extern "C" {
void apply_anti_technique__9TObjCharaFl();
}
extern "C" {
void apply_attack_stat_status__9TObjCharaFPv();
}
extern "C" {
void apply_confusion_status__9TObjCharaFv();
}
extern "C" {
void apply_knockback_from_attacker__9TObjCharaFPUc();
}
extern "C" {
void apply_movement_ailment__9TObjCharaFl();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void apply_paralysis__9TObjCharaFv();
}
extern "C" {
void apply_poison_status__9TObjCharaFv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__9TObjCharaFv();
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void clear_all_status_effects__9TObjCharaFv();
}
extern "C" {
void clear_harmful_statuses__9TObjCharaFv();
}
extern "C" {
void cure_paralysis__9TObjCharaFv();
}
extern "C" {
void cure_poison_ailment__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_jellen_effect__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_zalure_effect__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void vfunc_77__9TObjCharaFv();
}
extern "C" {
void vfunc_76__9TObjCharaFv();
}
extern "C" {
void vfunc_75__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__9TObjCharaFv();
}
extern "C" {
void get_actor_level_index__9TObjCharaFv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
void is_actor_cadence_frame__9TObjCharaFl();
}
extern "C" {
void is_target_in_attack_range__9TObjCharaFv();
}
extern "C" {
extern u8 lbl_8043D2F0[];
}
extern "C" {
extern u8 lbl_8043D308[];
}
extern "C" {
extern u8 lbl_8043D318[];
}
extern "C" {
extern u8 lbl_8043D330[];
}
extern "C" {
extern u8 lbl_8043D348[];
}
extern "C" {
extern u8 lbl_8043D360[];
}
extern "C" {
extern u8 lbl_8043D374[];
}
extern "C" {
extern u8 lbl_8043D38C[];
}
extern "C" {
extern u8 lbl_8043D3A0[];
}
extern "C" {
extern u8 lbl_8043D3B8[];
}
extern "C" {
extern u8 lbl_8043D3CC[];
}
extern "C" {
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__9TObjCharaFPvf();
}
extern "C" {
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__9TObjCharaFv();
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void roll_physical_accuracy__9TObjCharaFPvlf();
}
extern "C" {
void select_melee_contact_body__9TObjCharaFPvf();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
void update_action_hold_status__9TObjCharaFv();
}
extern "C" {
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__9TObjCharaFv();
}
extern "C" {
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern "C" {
void update_movement_status__9TObjCharaFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
extern void *bm_ene_re4_sorcerer_model_names[3];
extern void *bm_ene_re4_sorcerer_motion_names[9];
void *re4_sorcerer_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *re4_sorcerer_collision_body_part_table[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *bm_ene_re4_sorcerer_model_names[3] = {
    (void *)&lbl_8043D2F0, (void *)&lbl_8043D308, (void *)0x0,
};
void *bm_ene_re4_sorcerer_motion_names[9] = {
    (void *)&lbl_8043D318, (void *)&lbl_8043D330, (void *)&lbl_8043D348, (void *)&lbl_8043D360,
    (void *)&lbl_8043D374, (void *)&lbl_8043D38C, (void *)&lbl_8043D3A0, (void *)&lbl_8043D3B8,
    (void *)0x0,
};
void *bm_ene_re4_sorcerer_resource_descriptor[4] = {
    (void *)&lbl_8043D3CC, (void *)&bm_ene_re4_sorcerer_model_names, (void *)&bm_ene_re4_sorcerer_motion_names, (void *)0x20008,
};
void *re4_sorcerer_action_params[32] = {
    (void *)0x10000, (void *)0x7, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20002, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f19999a, (void *)0x80000000,
    (void *)0x30000, (void *)0x1, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f000000, (void *)0x0,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x80000000,
};
void *__vt__18TObjEneRe4Sorcerer[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__18TObjEneRe4SorcererFv, (void *)&run_task__18TObjEneRe4SorcererFv,
    (void *)&render__18TObjEneRe4SorcererFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUc, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__18TObjEneRe4SorcererFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__18TObjEneRe4SorcererFv, (void *)&vfunc_62__18TObjEneRe4SorcererFv, (void *)&vfunc_63__18TObjEneRe4SorcererFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&TObjEneRe4Sorcerer__vt85,
    (void *)&vfunc_88__18TObjEneRe4SorcererFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__18TObjEneRe4SorcererFPUc, (void *)&vfunc_102__18TObjEneRe4SorcererFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneEpsilon__vt101, (void *)&vfunc_83__18TObjEneRe4SorcererFv, (void *)&vfunc_106__18TObjEneRe4SorcererFv,
};
#define re4_sorcerer_collision_body_part_table ((f32 *)re4_sorcerer_collision_body_part_table)
#define bm_ene_re4_sorcerer_resource_descriptor ((u8 *)bm_ene_re4_sorcerer_resource_descriptor)
#define __vt__18TObjEneRe4Sorcerer ((s32 *)__vt__18TObjEneRe4Sorcerer)

void render__18TObjEneRe4SorcererFv(u8 *ene_re7_berura) {
    s32 var_r30;
    s32 temp_r31;
    s32 var_r28;
    s32 var_r27;
    if (TObjPlayer::check_demo_mode() == 1) {
        ((VObj_18 *)(ene_re7_berura))->m104();
        return;
    }
    var_r30 = 0;
    if (is_split_screen() != 0) {
        var_r30 = get_camera_mode__11TCameraCtrlFv();
    }
    var_r30 = (s32)&((Sorc_800EDCCC *)ene_re7_berura)->fades[var_r30];
    update_obstruction_fade((int) (((u8 *)var_r30)));
    temp_r31 = ((RenderFadeState *)var_r30)->updateFromCamera((const f32*)(ene_re7_berura + 0x2FC));
    if (!(*(s32 *)((s8 *)ene_re7_berura + 0x3C8) & 2)) {
        var_r28 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r28 = ((VObj_18 *)(ene_re7_berura))->m9(lbl_805D9E88, lbl_805D9E84, (*(f32 *)&TObjEneRe4Sorcerer__data_805DA78C));
    } else if (((VObj_18 *)(ene_re7_berura))->m8(lbl_805DA788, (*(f32 *)&TObjEneRe4Sorcerer__data_805DA78C)) != 0) {
        var_r28 = 1;
    } else {
        var_r28 = 0;
    }
    if (var_r28 != 0) {
        if (*(s32 *)((s8 *)ene_re7_berura + 0x3C8) & 0x10) {
            update_player_state__9TObjEneDDFv(ene_re7_berura, 0, 0);
        }
        ((TObjEneDD *)ene_re7_berura)->update_secondary_light();
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)ene_re7_berura + 0x24)));
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        scroll_strip_uvs((int) ((*(s32 *)&TObjEneRe4Sorcerer__uv_scroll_buffer)), (int) (*(s16 *)((s8 *)ene_re7_berura + 0x3C0)), 0);
        model_render_flags |= 0x20000;
        TObjEneRe4Sorcerer__sub_801E3F1C((f32) ((*(f32 *)&TObjEneRe4Sorcerer__data_805DA790)), (f32) (*(f32 *)((s8 *)ene_re7_berura + 0x3C4)));
        TObjPlayer::toggle_particle_effect();
        var_r27 = 1;
        if (*(s32 *)((s8 *)ene_re7_berura + 0x3C8) & 4) {
            ((VObj_14 *)(ene_re7_berura + 0x3FC))->m6();
            if (defer_render__7TObjectFv(ene_re7_berura) != 0) {
                var_r27 = 0;
            }
        } else if (temp_r31 != 0) {
            ((VObj_14 *)(((u8 *)var_r30)))->m6();
            if (defer_render__7TObjectFv(ene_re7_berura) != 0) {
                var_r27 = 0;
            }
        }
        if (var_r27 != 0) {
            push_matrix();
            post_translate_matrix(ene_re7_berura + 0x38);
            translate_matrix(0, (f32) ((*(f32 *)&TObjEneRe4Sorcerer__data_805DA790)), (f32) ((*(f32 *)&TObjEneRe4Sorcerer__data_805DA794)), (f32) ((*(f32 *)&TObjEneRe4Sorcerer__data_805DA790)));
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)ene_re7_berura + 0x60)));
            TObjEneRe4Sorcerer__render_node_index = 0;
            TObjEneRe4Sorcerer__saved_render_flags = 0;
            TObjEneRe4Sorcerer__effect_render_scale = *(f32 *)((s8 *)ene_re7_berura + 0x3F8);
            (*(u8 * *)&re4_sorcerer_render_node_ptr) = ene_re7_berura + 0x3CC;
            TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneRe4Sorcerer::step_effect_sequence));
            model_render_flags |= 0x01000000;
            if (var_r28 == 1) {
                ((TObjMotion *)ene_re7_berura)->draw();
            } else {
                ((TObjEnemy *)ene_re7_berura)->render_world_model();
            }
            model_render_flags &= 0xFEFFFFFF;
            TObjEneRe7Berura::set_global_state((s32)NULL);
            pop_matrix();
        }
        if (*(s32 *)((s8 *)ene_re7_berura + 0x3C8) & 4) {
            ((VObj_14 *)(ene_re7_berura + 0x3FC))->m7();
        } else if (temp_r31 != 0) {
            ((VObj_14 *)(((u8 *)var_r30)))->m7();
        }
        model_render_flags = saved_model_render_flags;
        ((TObjEneDD *)ene_re7_berura)->update_primary_light();
        TParticleCtrl::end_effect_render();
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneRe4Sorcerer::step_effect_sequence() {
    s32 t;
    switch (TObjEneRe4Sorcerer__render_node_index) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 0x34:
        f32 k = TObjEneRe4Sorcerer__effect_render_scale;
        t = model_render_flags;
        TObjEneRe4Sorcerer__saved_render_flags = t;
        model_render_flags = t & 0xFFFF7FFF;
        scale_matrix(0, t, k, k, k);
        TParticleCtrl::begin_effect_render();
        break;
    case 0x37:
        model_render_flags = TObjEneRe4Sorcerer__saved_render_flags;
        TObjPlayer::toggle_particle_effect();
        break;
    }
    TObjEneRe4Sorcerer__render_node_index += 1;
}
#pragma pop

void TObjEneRe4Sorcerer::handle_death_state(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 6;
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 6);
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        *(s32 *)((s8 *)arg0 + 0x4E4) = 0;
        ((TObjPlayer *)(arg0 + 0x2FC))->request_two_effects();
        TObjPlayer__sub_800A04F0(arg0 + 0x3FC);
        *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) TObjEneRe4Sorcerer__data_805DA790;
        play_sound_effect((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD19))), arg0 + 0x38, 0, 0);
        return;
    case 0:
        advance_animation_playback(arg0);
        if (((VObj_14_c1c33b *)(arg0 + (1020)))->m4() != 0) {
            TObjPlayer::apply_effect_variant_b((s32)(arg0 + 0x38), 0);
            queue_destruction__7TObjectFv((arg0));
        }
    case 3:
    case 5:
        return;
    }
}

void TObjEneRe4Sorcerer__sub_800EE0F8(u8 *ene_dd, s32 arg1) {
    Vec_800EE0F8 v;
    f32 c;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_dd + 0xB8) = 5;
        advance_animation_playback(ene_dd);
        break;
    case 3:
        if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, *(s32 *)((s8 *)ene_dd + 0x378));
        }
        break;
    case 0:
        advance_animation_playback(ene_dd);
        VecCopy__FP3VecPC3Vec(&v, ene_dd + 0x308);
        c = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)ene_dd)->move_to_wall_clamped_destination(v.x, v.z, c);
        *(f32 *)((s8 *)ene_dd + 0x308) *= lbl_805DA79C;
        *(f32 *)((s8 *)ene_dd + 0x310) *= lbl_805DA79C;
        TObjEneRe4Sorcerer__sub_800EF214((s32) ene_dd);
        break;
    case 5:
        clear_attack_receipts__9TObjEneDDFv(ene_dd);
        break;
    }
}

void TObjEneRe4Sorcerer__sub_800EE1CC(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    s32 var_r3;
    u8 *entity;

    entity = (u8 *)(find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x3E6)));
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 0;
        set_field_378__9TObjEneDDFl(arg0, 3);
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0xA);
        *(s32 *)((s8 *)arg0 + 0x4E4) = 0;
        *(s32 *)((s8 *)arg0 + 0x4E8) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4E8) == 5) {
            ((TObjEneRe4Sorcerer *)arg0)->advance_anim_frame();
            transition_enemy_state__9TObjEneDDFs(arg0, 3);
        }
        return;
    case 0:
        advance_animation_playback(arg0);
        *(s32 *)((s8 *)arg0 + 0x4E4) = (s32) (*(s32 *)((s8 *)arg0 + 0x4E4) + 1);
        temp_r0 = *(s32 *)((s8 *)arg0 + 0x4E8);
        switch (temp_r0) {
        case 0:
            if ((entity != NULL) && (TObjEneRe4Sorcerer__sub_800ED498((entity)) != 0)) {
                *(s32 *)((s8 *)arg0 + 0x4E4) = 0;
                if (is_alive__9TObjEneDDFv(*(s32 *)((s8 *)arg0 + 0x390)) != 0) {
                    if ((void *) *(u8 **)((s8 *)arg0 + 0x390) != arg0) {
                        ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                        ((TObjEneDD *)arg0)->update_velocity();
                        if (*(f32 *)((s8 *)arg0 + 0x3AC) >= lbl_805DA7A0) {
                            *(s32 *)((s8 *)arg0 + 0x4E8) = 4;
                        } else {
                            *(s32 *)((s8 *)arg0 + 0x4E8) = 1;
                            *(s16 *)((s8 *)arg0 + 0xB8) = 1;
                            *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 8);
                            ((TObjEneRe4Sorcerer *)arg0)->apply_mylla_effect();
                        }
                        *(s32 *)((s8 *)arg0 + 0x60) = (s32) (TObjEneRe4Sorcerer__data_8043D408 * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8)));
                    } else {
                        *(s32 *)((s8 *)arg0 + 0x4E8) = 1;
                        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
                        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 8);
                        ((TObjEneRe4Sorcerer *)arg0)->apply_mylla_effect();
                    }
                } else {
                    *(s32 *)((s8 *)arg0 + 0x4E8) = 4;
                }
            } else if ((f32) *(s32 *)((s8 *)arg0 + 0x4E4) >= lbl_805DA7A4) {
                *(s32 *)((s8 *)arg0 + 0x4E8) = 5;
            }
            break;
        case 1:
            if ((entity != NULL) && (TObjEneRe4Sorcerer__sub_800ED498((entity)) == 0)) {
                *(s32 *)((s8 *)arg0 + 0x4E8) = 5;
            } else if ((f32) *(s32 *)((s8 *)arg0 + 0x4E4) >= lbl_805DA7A8) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 4;
                *(s32 *)((s8 *)arg0 + 0x4E8) = 3;
            }
            play_persistent_sound((s32)(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A814)), (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
            break;
        case 2:
        case 3:
            if ((*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805DA7AC) && (temp_r0 == 3)) {
                if (entity != NULL) {
                    var_r3 = ((TObjEneRe4Sorcerer *)entity)->get_state();
                } else {
                    var_r3 = 3;
                }
                switch (var_r3) {
                case 2:
                    *(s32 *)((s8 *)arg0 + 0x4E8) = 2;
                    ((TObjEneRe4Sorcerer *)arg0)->cast_resta();
                    break;
                case 3:
                    *(s32 *)((s8 *)arg0 + 0x4E8) = 2;
                    break;
                }
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x4E8) = 5;
                if (entity != NULL) {
                    ((TObjEneRe4Sorcerer *)entity)->set_attack_flag();
                }
            }
            break;
        case 4:
            if ((f32) *(s32 *)((s8 *)arg0 + 0x4E4) >= lbl_805DA7B0) {
                *(s32 *)((s8 *)arg0 + 0x4E8) = 5;
            }
            break;
        case 5:
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_89();
        ((TObjEneDD *)(arg0))->vfunc_88();
        TObjEneRe4Sorcerer__sub_800EF214((s32)arg0);
        return;
    case 5:
        if (entity != NULL) {
            ((TObjEneRe4Sorcerer *)entity)->set_attack_flag();
        }
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFFF7);
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        break;
    }
}

void TObjEneRe4Sorcerer::update_state_machine(void *arg1p) {
  f32 *t = (f32 *) (((u8 *) this) + 0x4EC);
  s32 mask;
  s32 n;
  s32 i;
  u8 *p;
  s32 j;
  switch ((s32) arg1p)
  {
    case 4:
      set_field_378__9TObjEneDDFl((u8 *) this, 6);
      this->vfunc_95();
      *((s32 *) (((s8 *) ((u8 *) this)) + 0x3C8)) &= ~2;
      enemy_clear_target__12TObjEneDD_STFUs((u8 *) this);
      init_float_params();
      if (((VObj_18_d3ac76 *)this)->m97() != 0)
    {
      *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 3;
    }
    else
    {
      *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 0;
    }
      *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E8)) = 0;
      *t = TObjEneRe4Sorcerer__data_805DA790;
      break;

    case 3:
      if ((*((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4))) == 4)
    {
      transition_enemy_state__9TObjEneDDFs((u8 *) this, 2);
    }
      break;

    case 5:
      break;

    case 0:
      switch (*((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)))
    {
      case 3:
        mask = 0;
        n = TLobby::get_game_mode();
        *t = TObjEneRe4Sorcerer__data_805DA790;
        for (i = 0; i < n; i++)
      {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        mask |= update_farthest_target((s32) p, t);
      }

        if (mask != 0)
      {
        *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 2;
      }
      else
      {
        *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 0;
      }
        break;

      case 0:
        if (TObjEneRe4Sorcerer::check_shield((s32) this, (u8 *) this) != 0)
      {
        *((u8 **) (((s8 *) ((u8 *) this)) + 0x390)) = (u8 *) this;
        *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 2;
      }
      else
      {
        *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 1;
      }
        break;

      case 1:
        j = TLobby::get_game_mode();
        n = j + TObjEneDD::get_enemy_count();
        *t = TObjEneRe4Sorcerer__data_805DA790;
        for (; j < n; j++)
      {
        p = (u8 *)get_player_data__10TObjPlayerFi(j);
        if (p == ((u8 *) this))
        {
          continue;
        }
        if (p != 0)
        {
          s16 a = *((s16 *) (((s8 *) p) + 0x28));
          if (a != (*((s16 *) (((s8 *) ((u8 *) this)) + 0x28))))
          {
            continue;
          }
        }
        update_farthest_target((s32) p, t);
      }

        *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 2;
        break;

      case 2:
        if ((*((void **) (((s8 *) ((u8 *) this)) + 0x390))) != 0)
      {
        ((s32 (*)(void *, f32))TObjEneRe4Sorcerer__sub_800EF95C)(this, lbl_805DA7B4);
      }
      else
      {
        VecCopy__FP3VecPC3Vec(((u8 *) this) + 0x394, ((u8 *) this) + 0x38);
        ((s32 (*)(void *, f32))TObjEneRe4Sorcerer__sub_800EF95C)(this, lbl_805DA7B8);
      }
        *((s32 *) (((s8 *) ((u8 *) this)) + 0x4E4)) = 4;
        break;

    }

      break;

  }

}

void TObjEneRe4Sorcerer__sub_800EE7DC(TObjEneRe4Sorcerer *ene_re4_sorcerer, s32 arg1) {
    s32 temp_r0;
    s32 var_r3;
    u32 entity;
    entity = (u32)find_entity_by_id(*(u16 *)((s8 *)ene_re4_sorcerer + 0x3E4));
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_re4_sorcerer + 0xB8) = 0;
        set_field_378__9TObjEneDDFl(ene_re4_sorcerer, 3);
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) | 0xA);
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) = 0;
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) == 5) {
            ene_re4_sorcerer->advance_anim_frame();
            *(s32 *)((s8 *)ene_re4_sorcerer + 0x3EC) = ((*(s32 *)((s8 *)ene_re4_sorcerer + 0x3EC)) + 1);
            transition_enemy_state__9TObjEneDDFs(ene_re4_sorcerer, 3);
        }
        return;
    case 0:
        advance_animation_playback(ene_re4_sorcerer);
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) + 1);
        temp_r0 = *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8);
        switch (temp_r0) {
        case 0:
            if ((entity != 0U) && (TObjEneRe4Sorcerer__sub_800ED498((u8 *)entity) != 0)) {
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) = 0;
                if (ene_re4_sorcerer->try_attack(lbl_805DA7BC, lbl_805DA7BC) == 0) {
                    *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 4;
                } else {
                    ((TObjEneDD_ST *)ene_re4_sorcerer)->enemy_copy_target_destination();
                    ((TObjEneDD *)ene_re4_sorcerer)->update_velocity();
                    if (*(f32 *)((s8 *)ene_re4_sorcerer + 0x3AC) >= lbl_805DA7A0) {
                        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 4;
                    } else {
                        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 1;
                        *(s16 *)((s8 *)ene_re4_sorcerer + 0xB8) = 1;
                        *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) | 8);
                        ene_re4_sorcerer->set_photon_state();
                    }
                    *(s32 *)((s8 *)ene_re4_sorcerer + 0x60) = (s32) (TObjEneRe4Sorcerer__data_8043D408 * atan2_float((f32) (*(f32 *)((s8 *)ene_re4_sorcerer + 0x3A0)), (f32) (*(f32 *)((s8 *)ene_re4_sorcerer + 0x3A8))));
                }
            } else if ((s32) *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) >= 0xF0) {
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 5;
            }
            ene_re4_sorcerer->turn_to_target();
            ene_re4_sorcerer->create_effect();
            break;
        case 1:
            if ((entity != 0U) && (TObjEneRe4Sorcerer__sub_800ED498((u8 *)entity) == 0)) {
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 5;
            } else if ((s32) *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) >= 0x5A) {
                *(s16 *)((s8 *)ene_re4_sorcerer + 0xB8) = 3;
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 3;
            }
            ene_re4_sorcerer->turn_to_target();
            ene_re4_sorcerer->create_effect();
            break;
        case 2:
        case 3:
            if ((*(f32 *)((s8 *)ene_re4_sorcerer + 0xC0) >= lbl_805DA7AC) && (temp_r0 == 3)) {
                if (entity != 0U) {
                    var_r3 = ((TObjEneRe4Sorcerer *)entity)->get_state();
                } else {
                    var_r3 = 3;
                }
                switch (var_r3) {
                case 2:
                    *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 2;
                    ene_re4_sorcerer->cast_technique();
                    break;
                case 3:
                    *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 2;
                    break;
                }
            }
            if (((TObjEneDD *)ene_re4_sorcerer)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 5;
                if (entity != 0U) {
                    ((TObjEneRe4Sorcerer *)entity)->set_attack_flag();
                }
            }
            break;
        case 4:
            if ((s32) *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) >= 0x3C) {
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 5;
            }
            break;
        case 5:
            break;
        }
        ((TObjEneDD *)(ene_re4_sorcerer))->vfunc_89();
        ((TObjEneDD *)(ene_re4_sorcerer))->vfunc_88();
        TObjEneRe4Sorcerer__sub_800EF214((s32)ene_re4_sorcerer);
        return;
    case 5:
        if (entity != 0U) {
            ((TObjEneRe4Sorcerer *)entity)->set_attack_flag();
        }
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) & 0xFFFFFFF7);
        break;
    }
}

void TObjEneRe4Sorcerer::state_wait(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)this + 0x4E4) = 0;
        set_field_378__9TObjEneDDFl(this, 4);
        *(s32 *)((s8 *)this + 0x3C8) = (s32) (*(s32 *)((s8 *)this + 0x3C8) & 0xFFFFFFFD);
        this->vfunc_95();
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return;
    case 3:
        if (try_attack(lbl_805DA7C0, lbl_805DA7C0) != 0) {
            if (*(s32 *)((s8 *)this + 0x3EC) & 1) {
                ((s32 (*)(void *, f32))TObjEneRe4Sorcerer__sub_800EF95C)(this, lbl_805DA7C4);
            } else {
                ((s32 (*)(void *, f32))TObjEneRe4Sorcerer__sub_800EF95C)(this, lbl_805DA7C8);
            }
            transition_enemy_state__9TObjEneDDFs(this, 2);
            return;
        }
        if ((s32) *(s32 *)((s8 *)this + 0x4E4) > 0x5A) {
            transition_enemy_state__9TObjEneDDFs(this, 1);
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x4E4) = (s32) (*(s32 *)((s8 *)this + 0x4E4) + 1);
        break;
    }
}

s32 TObjEneRe4Sorcerer__sub_800EEC00(void *arg0p, void *arg1p) {
    u8 *ene_re4_sorcerer = (u8 *)arg0p;
    f32 temp_f2;
    s32 i;
    switch ((s32)arg1p) {
    case 4:
        set_field_378__9TObjEneDDFl(ene_re4_sorcerer, 3);
        ((TObjEneRe4Sorcerer *)(ene_re4_sorcerer))->vfunc_96();
        ((s32 (*)(void *))TObjEneRe4Sorcerer__sub_800EF844)(ene_re4_sorcerer);
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) | 2);
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) & 0xFFFFFFF7);
        for (i = 0; i < 2; i++) {
            if (find_entity_by_id(((Sorc_800EEC00 *)ene_re4_sorcerer)->ids[i]) != 0U) {
                set_flag_and_notify__18TObjEneRe4SorcererFv();
            }
        }
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) = 0;
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 0;
        ((VObj_14_763762 *)(ene_re4_sorcerer + (1020)))->m2();
        ((TBoss3Volopt *)(ene_re4_sorcerer + 0x38))->play_area_variant_sound();
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) >= 0x1E) {
            ((TObjEneRe4Sorcerer *)ene_re4_sorcerer)->request_death_effect();
        }
        break;
    case 0:
        advance_animation_playback(ene_re4_sorcerer);
        switch (*(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8)) {
        case 0:
            temp_f2 = *(f32 *)((s8 *)ene_re4_sorcerer + 0x3F8);
            if (temp_f2 > TObjEneRe4Sorcerer__data_805DA790) {
                *(f32 *)((s8 *)ene_re4_sorcerer + 0x3F8) = (f32) (temp_f2 - lbl_805DA7CC);
                if (*(f32 *)((s8 *)ene_re4_sorcerer + 0x3F8) < TObjEneRe4Sorcerer__data_805DA790) {
                    *(f32 *)((s8 *)ene_re4_sorcerer + 0x3F8) = (f32) TObjEneRe4Sorcerer__data_805DA790;
                    *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) | 4);
                    ((VObj_14_763762 *)(ene_re4_sorcerer + (1020)))->m2();
                }
            } else if (((VObj_14_763762 *)(ene_re4_sorcerer + (1020)))->m4() != 0) {
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) = 0;
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E8) = 1;
                *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) & 0xFFFFFFF9);
            }
            TObjEneRe4Sorcerer__sub_800EF214((s32)ene_re4_sorcerer);
            break;
        case 1:
            *(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x4E4) + 1);
            break;
        }
        ((TObjEneRe4Sorcerer *)(ene_re4_sorcerer))->vfunc_102();
        break;
    case 5:
        *(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) = (s32) (*(s32 *)((s8 *)ene_re4_sorcerer + 0x3C8) & 0xFFFFFFFB);
        *(f32 *)((s8 *)ene_re4_sorcerer + 0x3F8) = (f32) 1.0f;
        break;
    }
}

extern "C" {
__declspec(section ".sdata2") extern void *const lbl_805DA7D4[1] = {
    (void *)0xbf400000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7D8[1] = {
    (void *)0x47742400,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7DC[1] = {
    (void *)0x42480000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7E0[1] = {
    (void *)0x41900000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7E4[1] = {
    (void *)0x471c4000,
};
__declspec(section ".sdata2") extern void *const lbl_805DA7E8[2] = {
    (void *)0x41200000, (void *)0x0,
};
}
#define lbl_805DA7D4 (*(const f32 *)lbl_805DA7D4)
#define lbl_805DA7D8 (*(const f32 *)lbl_805DA7D8)
#define lbl_805DA7DC (*(const f32 *)lbl_805DA7DC)
#define lbl_805DA7E0 (*(const f32 *)lbl_805DA7E0)
#define lbl_805DA7E4 (*(const f32 *)lbl_805DA7E4)
#define lbl_805DA7E8 (*(const f32 *)lbl_805DA7E8)

#define arg0 ((u8 *)arg0p)
#pragma push
#pragma opt_common_subs off
s32 TObjEneRe4Sorcerer__sub_800EEDE4(void *arg0p, void *arg1p) {
    s32 i;
    u32 r;

    switch ((s32)arg1p) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 7;
        set_field_378__9TObjEneDDFl(arg0, 3);
        *(s32 *)((s8 *)arg0 + 0x3C8) |= 0xE;
        ((TObjEneRe4Sorcerer *)(arg0))->vfunc_96();
        ((s32 (*)(void *))TObjEneRe4Sorcerer__sub_800EF844)(arg0);
        ((VObj_14_763762 *)(arg0 + 0x3FC))->m3();
        for (i = 0; i < 2; i++) {
            if ((r = (u32)find_entity_by_id(((Sorc_800EEDE4 *)arg0)->ids[i])) != 0) {
                reset_transform__13TObjEneRe4BitFv();
                ((TObjEneRe4Sorcerer *)r)->clear_state_flag_0x10();
            }
        }
        *(f32 *)((s8 *)arg0 + 0x3F8) = TObjEneRe4Sorcerer__data_805DA790;
        *(s32 *)((s8 *)arg0 + 0x4E4) = 0;
        *(s32 *)((s8 *)arg0 + 0x4E8) = 0;
        ((TBoss3Volopt *)(arg0 + 0x38))->play_area_variant_sound();
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x4E4) >= 0x3C) {
            ((s32 (*)(void))set_motion_by_state__18TObjEneRe4SorcererFPv)();
        }
        break;
    case 0:
        if (*((f32 * (*)(void *))TBoss3Volopt__sub_800F059C)(arg0 + 0x3FC) >= lbl_805DA7D4) {
            advance_animation_playback(arg0);
            ((TObjEneRe4Sorcerer *)arg0)->turn_to_target();
        }
        switch (*(s32 *)((s8 *)arg0 + 0x4E8)) {
        case 0:
            if (((VObj_14_763762 *)(arg0 + 0x3FC))->m5() != 0) {
                *(s32 *)((s8 *)arg0 + 0x4E4) = 0;
                *(s32 *)((s8 *)arg0 + 0x4E8) = 1;
                *(s32 *)((s8 *)arg0 + 0x3C8) &= ~4;
                ((s32 (*)(void *))TObjEneRe4Sorcerer__sub_800EF7C8)(arg0);
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x4E4) += 1;
            if (*(f32 *)((s8 *)arg0 + 0x3F8) < 1.0f) {
                *(f32 *)((s8 *)arg0 + 0x3F8) += lbl_805DA7CC;
            }
            ((TObjEneRe4Sorcerer *)(arg0))->vfunc_89();
            break;
        }
        ((TObjEneRe4Sorcerer *)(arg0))->vfunc_102();
        TObjEneRe4Sorcerer__sub_800EF214((s32)arg0);
        break;
    case 5:
        *(f32 *)((s8 *)arg0 + 0x3F8) = 1.0f;
        *(s32 *)((s8 *)arg0 + 0x3C8) &= ~4;
        break;
    }
}
#pragma pop

#undef arg0
void TObjEneRe4Sorcerer__sub_800EEFE4(u8 *ene_re4_sorcerer, s32 arg1) {
  switch (arg1)
  {
    case 4:
      ((s32)set_field_378__9TObjEneDDFl((void *)((void *) ene_re4_sorcerer), 1));
      VecCopy__FP3VecPC3Vec(ene_re4_sorcerer + 0x38, ene_re4_sorcerer + 0x50);
      VecCopy__FP3VecPC3Vec(ene_re4_sorcerer + 0x44, ene_re4_sorcerer + 0x50);
      VecCopy__FP3VecPC3Vec(ene_re4_sorcerer + 0x2FC, ene_re4_sorcerer + 0x50);
      (((TObjEneRe4Sorcerer *)(ene_re4_sorcerer))->vfunc_95());
      return;
      return;
    case 3:
      if (((TObjEneRe4Sorcerer *)ene_re4_sorcerer)->try_attack((f32) lbl_805DA7C0, (f32) lbl_805DA7D8) != 0)
    {
      ((TObjEneDD_ST *)ene_re4_sorcerer)->enemy_copy_target_destination();
      ((TObjEneDD *)ene_re4_sorcerer)->update_velocity();
      *((s32 *) (((s8 *) ene_re4_sorcerer) + 0x3F0)) = (s32) (TObjEneRe4Sorcerer__data_8043D408 * (atan2_float(-(*((f32 *) (((s8 *) ene_re4_sorcerer) + 0x3A0))), -(*((f32 *) (((s8 *) ene_re4_sorcerer) + 0x3A8))))));
      ((s32 (*)(void *, f32))TObjEneRe4Sorcerer__sub_800EF95C)((void *) ene_re4_sorcerer, (f32) lbl_805DA7DC);
      transition_enemy_state__9TObjEneDDFs((void *)((void *) ene_re4_sorcerer), 2);
    }
    case 5:
      return;
    case 0:
      (((TObjEneRe4Sorcerer *)(ene_re4_sorcerer))->vfunc_88());
      break;
  }
}

s32 TObjEneRe4Sorcerer::handle_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)this + 0x4E4) = 0;
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x4E4) >= 2) {
            transition_enemy_state__9TObjEneDDFs(this, 1);
        }
        break;
    case 5:
        break;
    case 0:
        *(s32 *)((s8 *)this + 0x4E4) = (s32) (*(s32 *)((s8 *)this + 0x4E4) + 1);
        break;
    }
}

void TObjEneRe4Sorcerer__vt85(s32 arg0p, u32 arg1, s32 arg1p) {
    switch (arg1) {
    case 0:
        ((TObjEneRe4Sorcerer *)arg0p)->handle_state(arg1p);
        return;
    case 1:
        TObjEneRe4Sorcerer__sub_800EEFE4((u8 *)arg0p, (s32)arg1p);
        return;
    case 2:
        TObjEneRe4Sorcerer__sub_800EEDE4((void *)arg0p, (void *)arg1p);
        return;
    case 3:
        TObjEneRe4Sorcerer__sub_800EEC00((void *)arg0p, (void *)arg1p);
        return;
    case 4:
        ((TObjEneRe4Sorcerer *)arg0p)->state_wait(arg1p);
        return;
    case 5:
        TObjEneRe4Sorcerer__sub_800EE7DC((TObjEneRe4Sorcerer *)((u8 *)arg0p), (s32)arg1p);
        return;
    case 6:
        ((TObjEneRe4Sorcerer *)arg0p)->update_state_machine((void *)arg1p);
        return;
    case 7:
        TObjEneRe4Sorcerer__sub_800EE1CC((u8 *)arg0p, (s32)arg1p);
        return;
    case 8:
        TObjEneRe4Sorcerer__sub_800EE0F8((u8 *)arg0p, (s32)arg1p);
        return;
    case 9:
        ((TObjEneRe4Sorcerer *)arg0p)->handle_death_state(arg1p);
    default:
        return;
    }
}

void TObjEneRe4Sorcerer__sub_800EF214(s32 arg0) {
    play_persistent_sound((s32)((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv((void *)arg0, 0x4003A81D)))), (s32)arg0, arg0 + 0x38, 0, 0);
}

void TObjEneRe4Sorcerer::create_effect() {
    u8 *arg0 = (u8 *)this;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x3E8) == 0) {
        play_persistent_sound((s32)(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A812)), (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
        return;
    }
    play_persistent_sound((s32)(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AB13)), (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
}

s32 TObjEneRe4Sorcerer::cast_resta() {
    u8 *arg0 = (u8 *)this;
    u8 *var_r31;

    if (is_alive__9TObjEneDDFv(*(s32 *)((s8 *)arg0 + 0x390)) != 0) {
        if (find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x3E4)) != 0U) {
            var_r31 = get_spell_data__18TObjEneRe4SorcererFv();
        } else {
            var_r31 = arg0 + 0x38;
        }
        TTecResta::create((void *)arg0, (void *)var_r31, (void *)(TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)sorcerer_behavior_params + 0x20))));
        return 1;
    }
    return 0;
}

s32 TObjEneRe4Sorcerer::cast_technique() {
    u8 *arg0 = (u8 *)this;
    Vec_800EF354 v;
    s32 frame;
    u8 *src;
    if (transform_relative_position__9TObjEneDDFPv(arg0, *(void **)((s8 *)arg0 + 0x390)) != 0) {
        if (find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x3E4)) != 0U) {
            src = get_spell_data__18TObjEneRe4SorcererFv();
        } else {
            src = arg0 + 0x38;
        }
        if (*(s32 *)((s8 *)arg0 + 0x3E8) == 0) {
            fn_80044330(arg0 + 0x418);
            *(s32 *)((s8 *)arg0 + 0x418) = 1;
            *(s16 *)((s8 *)arg0 + 0x41C) = get_entity_id(*(void **)((s8 *)arg0 + 0x390));
            *(s16 *)((s8 *)arg0 + 0x41E) = 0;
            if (TObjEneDD::check_v2_mode() != 0) {
                TTecGrants::create((void *)arg0, (void *)src, arg0 + 0x418, (void *)(TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)sorcerer_behavior_params + 0x18))));
            } else if (TLobby::get_instance() == 1) {
                ((TTecGiZonde *)arg0)->create((void *)src, arg0 + 0x418, (void *)(TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)sorcerer_behavior_params + 0x18))));
            } else {
                ((TTecRaFoie *)arg0)->create_ex((void *)src, arg0 + 0x418, (void *)(TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)sorcerer_behavior_params + 0x18))));
            }
        } else if (TObjEneDD::check_v2_mode() != 0) {
            TTecMegid::create((s32)arg0, (s32)src, (s32)(*(u8 **)((s8 *)arg0 + 0x390) + 0x38), (s32)(TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)sorcerer_behavior_params + 0x1C))));
        } else {
            VecCopy__FP3VecPC3Vec(&v, *(u8 **)((s8 *)arg0 + 0x390) + 0x38);
            subtract_vector(&v, src);
            frame = TObjEneDD::clamp_frame_index(*(s32 *)((s8 *)sorcerer_behavior_params + 0x1C));
            create_ex__11TTecGiBartaFPvPvPv(arg0, src, (s32)(TObjEneRe4Sorcerer__data_8043D408 * atan2_float(v.x, v.z)), frame);
        }
        return 1;
    }
    return 0;
}

void TObjEneRe4Sorcerer::turn_to_target() {
    enemy_copy_target_destination();
    update_velocity();
    *(s32 *)((s8 *)this + 0x60) = approach_angle_limited(*(s32 *)((s8 *)this + 0x60), (s32) (TObjEneRe4Sorcerer__data_8043D408 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8))), 0xA00);
}

void TObjEneRe4Sorcerer::calc_orb_positions() {
    f32 temp_f2;
    f32 temp_f31;

    temp_f31 = TObjEneRe4Sorcerer__data_805DA78C * cos_table_lookup(*(s32 *)((s8 *)this + 0x60));
    temp_f2 = TObjEneRe4Sorcerer__data_805DA78C * -sin_table_lookup(*(s32 *)((s8 *)this + 0x60));
    *(f32 *)((s8 *)this + 0x3D8) = (f32) (*(f32 *)((s8 *)this + 0x38) + temp_f31);
    *(f32 *)((s8 *)this + 0x3DC) = (f32) (lbl_805DA7E0 + *(f32 *)((s8 *)this + 0x3C));
    *(f32 *)((s8 *)this + 0x3E0) = (f32) (*(f32 *)((s8 *)this + 0x40) + temp_f2);
    *(f32 *)((s8 *)this + 0x3CC) = (f32) (*(f32 *)((s8 *)this + 0x38) - temp_f31);
    *(f32 *)((s8 *)this + 0x3D0) = (f32) (lbl_805DA7E0 + *(f32 *)((s8 *)this + 0x3C));
    *(f32 *)((s8 *)this + 0x3D4) = (f32) (*(f32 *)((s8 *)this + 0x40) - temp_f2);
}

void TObjEneRe4Sorcerer::apply_mylla_effect() {
    u32 entity;
    entity = (u32)find_entity_by_id(*(u16 *)((s8 *)this + 0x3E6));
    if (entity != 0U) {
        ((TObjEneRe4Sorcerer *)entity)->set_state_flag_and_mode(2);
    }
}

void TObjEneRe4Sorcerer::set_photon_state() {
    u32 entity;
    if ((s32) *(s32 *)((s8 *)this + 0x3E8) == 0) {
        entity = (u32)find_entity_by_id(*(u16 *)((s8 *)this + 0x3E4));
        if (entity != 0U) {
            ((TObjEneRe4Sorcerer *)entity)->set_state_flag_and_mode(0);
        }
    } else {
        entity = (u32)find_entity_by_id(*(u16 *)((s8 *)this + 0x3E4));
        if (entity != 0U) {
            ((TObjEneRe4Sorcerer *)entity)->set_state_flag_and_mode(1);
        }
    }
}

s32 TObjEneRe4Sorcerer::update_farthest_target(s32 item_pro_shield, f32 *arg2) {
    f32 temp_f1;
    if ((((s32 (*)(void *))is_alive__9TObjEneDDFv)((void *)item_pro_shield) != 0) && (TObjEneRe4Sorcerer::check_shield((s32)((void *) (((u8 *)this))), (void *)((void *)item_pro_shield)) != 0)) {
        temp_f1 = horizontal_distance_squared((void *) (((u8 *)this) + 0x38), (void *)(item_pro_shield + 0x38));
        if ((temp_f1 <= lbl_805DA7E4) && (temp_f1 > *arg2)) {
            *arg2 = temp_f1;
            *(s16 *)((s8 *)((u8 *)this) + 0x38C) = get_entity_id((void *)item_pro_shield);
            *(s32 *)((s8 *)((u8 *)this) + 0x390) = item_pro_shield;
            return 1;
        }
    }
    return 0;
}

s32 TObjEneRe4Sorcerer::check_shield(s32 arg0, void *item_pro_shield) {
    if (TObjEneDD::check_v2_mode() != 0) {
        return *(s16 *)((s8 *)item_pro_shield + 0x32C) < ((TItemProShield *)item_pro_shield)->get_field_2b8();
    }
    return *(s16 *)((s8 *)item_pro_shield + 0x32C) < (((TItemProShield *)item_pro_shield)->get_field_2b8() / 4);
}

void TObjEneRe4Sorcerer__sub_800EF7C8(Obj_800EF7C8 *self) {
    s32 i;
    self->m90();
    self->m91();
    for (i = 0; i < 2; i++) {
        u32 p = (u32)find_entity_by_id(self->orbs[i]);
        if (p != 0) {
            ((TObjEneRe4Bit *)p)->call_vt_90_91();
        }
    }
}

void TObjEneRe4Sorcerer__sub_800EF844(Obj_800EF844 *self) {
    s32 i;
    self->m89();
    self->m92();
    for (i = 0; i < 2; i++) {
        u32 p = (u32)find_entity_by_id(self->orbs[i]);
        if (p != 0) {
            ((TObjEneRe4Sorcerer *)p)->invoke_state_callbacks();
        }
    }
}

void TObjEneRe4Sorcerer::advance_anim_frame() {
    *(s32 *)((s8 *)this + 0x3E8) = (s32) (*(s32 *)((s8 *)this + 0x3E8) + 1);
    if ((s32) *(s32 *)((s8 *)this + 0x3E8) >= 3) {
        *(s32 *)((s8 *)this + 0x3E8) = 0;
    }
}

void TObjEneRe4Sorcerer::request_death_effect() {
    if ((s32) *(s32 *)((s8 *)this + 0x3E8) != 2) {
        transition_enemy_state__9TObjEneDDFs(this, 4);
        return;
    }
    transition_enemy_state__9TObjEneDDFs(this, 6);
}

void set_motion_by_state__18TObjEneRe4SorcererFPv(void *ene_dd) {
    if ((s32) *(s32 *)((s8 *)ene_dd + 0x3E8) != 2) {
        transition_enemy_state__9TObjEneDDFs(ene_dd, 5);
        return;
    }
    transition_enemy_state__9TObjEneDDFs(ene_dd, 7);
}

void TObjEneRe4Sorcerer__sub_800EF95C(Obj_800EF95C *self, f32 speed) {
    s32 i;
    Vec_800EF95C out;
    Vec_800EF95C v;
    Vec_800EF95C t;
    u32 p;
    ((TObjEneDD_ST *)self)->enemy_copy_target_destination();
    ((TObjEneDD *)self)->update_velocity();
    v.x = speed * sin_table_lookup(self->ang);
    v.y = TObjEneRe4Sorcerer__data_805DA790;
    v.z = speed * cos_table_lookup(self->ang);
    vec3_add_to(&v, self->mtx);
    ((void (*)(void *, void *))subtract_vector)(&v, &self->pos);
    speed = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
    calc_wall_clamped_destination(self, &out, v.x, v.z, speed);
    t.x = out.x;
    t.y = lbl_805DA7E8 + out.y;
    t.z = out.z;
    if (csnVectorUnder((s32)&t, (u32 *)self->col, 0xE0) == 0) {
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->pos, &out);
    }
    self->m100();
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->prev, &self->pos);
    ((TObjEneRe4Sorcerer *)self)->update_collision_center();
    self->rot = self->ang + 0x8000;
    ((TObjEneRe4Sorcerer *)self)->calc_orb_positions();
    self->ang += 0x2AAA;
    ((TObjEneDD *)self)->transform_part_positions();
    for (i = 0; i < 2; i++) {
        p = (u32)find_entity_by_id(self->orbs[i]);
        if (p != 0) {
            ((void (*)(u32))reset_transform__13TObjEneRe4BitFv)(p);
        }
    }
}

s32 TObjEneRe4Sorcerer::try_attack(f32 farg0, f32 farg1) {
    s32 arg0 = (s32)this;
    if (tick_period_counter(arg0, (s32 *)(arg0 + 0x3B0), 0x1E) != 0) {
        return select_attack_target__18TObjEneRe4SorcererFiff(arg0, farg0, farg1);
    }
    if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
        return 1;
    }
    ((s32 (*)(s32))enemy_clear_target__12TObjEneDD_STFUs)(arg0);
    return 0;
}

s32 select_attack_target__18TObjEneRe4SorcererFiff(s32 arg0, f32 farg0, f32 farg1) {
#define self ((Obj_800EFB60 *)arg0)
    f32 d;
    f32 best;
    s32 id;
    u8 *p;
    s32 n;
    int i;
    u32 o1;
    u32 o2;
    if (self->m97() != 0) {
        best = farg1;
        id = 0xFFFF;
        o1 = (u32)find_entity_by_id(self->orbs[0]);
        o2 = (u32)find_entity_by_id(self->orbs[1]);
        p = (u8 *)TLobby::get_game_mode();
        n = (s32)p + TObjEneDD::get_enemy_count();
        for (i = (s32)p; i < n; i++) {
            p = (u8 *)get_player_data__10TObjPlayerFi(i);
            if (p != (u8 *)self && (u32)p != o1 && (u32)p != o2 && is_alive__9TObjEneDDFv((s32)p) != 0) {
                d = horizontal_distance_squared((void *)(arg0 + 0x2FC), p + 0x38);
                if (d < best && csnLookAt((arg0 + 0x2FC), (s32)(p + 0x2FC)) == 0) {
                    id = ((s32 (*)(void *))get_entity_id)(p);
                    best = d;
                }
            }
        }
        if (((s32 (*)(void *, s32))enemy_bind_or_clear_target)(self, id) != 0) {
            return 1;
        }
    }
    {
    u8 *q; s32 tA; s32 tB; s32 j; s32 m; f32 e;
    tA = 0xFFFF;
    tB = tA;
    m = TLobby::get_game_mode();
    for (j = 0; j < m; j++) {
        q = (u8 *)get_player_data__10TObjPlayerFi(j);
        if (is_alive__9TObjEneDDFv((s32)q) != 0) {
            e = horizontal_distance_squared((void *)(arg0 + 0x2FC), q + 0x2FC);
            if (is_target_ranger(q) != 0) {
                if (e < farg0 && transform_relative_position__9TObjEneDDFPv(self, q) != 0) {
                    farg0 = e;
                    tA = ((s32 (*)(void *))get_entity_id)(q);
                }
            } else if (e < farg1 && transform_relative_position__9TObjEneDDFPv(self, q) != 0) {
                farg1 = e;
                tB = ((s32 (*)(void *))get_entity_id)(q);
            }
        }
    }
    if ((u16)tA != 0xFFFF) {
        ((void (*)(void *, s32))enemy_set_target_id)(self, tA);
        return 1;
    }
    if ((u16)tB != 0xFFFF) {
        ((void (*)(void *, s32))enemy_set_target_id)(self, tB);
        return 1;
    }
    }
    enemy_clear_target__12TObjEneDD_STFUs(self);
    return 0;
#undef self
}

u8 *TObjEneRe4Sorcerer::vfunc_102() {
    u8 *arg0 = (u8 *)this;
    if (vfunc_102__9TObjEneDDFv() == 0U) {
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFFEF);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x10);
}

u8 *TObjEneRe4Sorcerer::vfunc_101(u8 *) {
    u8 *arg0 = (u8 *)this;
    if (vfunc_101__9TObjEneDDFPUc() == 0U) {
        *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) & 0xFFFFFFEF);
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x3C8) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C8) | 0x10);
}

void TObjEneRe4Sorcerer__sub_800EFE30(void) {  }

void TObjEneRe4Sorcerer::vfunc_88() {
    *(f32 *)((s8 *)(*(void **)((s8 *)this + 0xA4)) + 4) = (f32) (*(f32 *)&TObjEneRe4Sorcerer__data_805DA794);
}

void TObjEneRe4Sorcerer::update_collision_center() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x300) = (f32) (TObjEneRe4Sorcerer__data_805DA794 + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x304) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    ((s32 (*)(void *, void *, void *, f32))VecCopy__FP3VecPC3Vec)(arg0 + 0x74, arg0 + 0x2FC, arg0, TObjEneRe4Sorcerer__data_805DA794);
}

void TObjEneRe4Sorcerer::vfunc_61() {  }

void TObjEneRe4Sorcerer::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if ((s16) *(s16 *)((s8 *)arg0 + 0x326) != 8) {
        if (!(*(s32 *)((s8 *)arg0 + 0x3C8) & 8)) {
            ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(8));
            return;
        }
        ((s32 (*)(void))clear_attack_receipts__9TObjEneDDFv)();
    }
}

void TObjEneRe4Sorcerer::vfunc_63() { if (*(short*)((char*)this + 0x326) != 9) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)9); } }

void TObjEneRe4Sorcerer::vfunc_28() {  }

void run_task__18TObjEneRe4SorcererFv(u8 *arg0) {
    s32 i;
    void *p;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRe4Sorcerer *)(arg0))->vfunc_106();
        return;
    }
    if (((TObjEneRe4Sorcerer *)(arg0))->vfunc_83() != 4) {
        if (TObjEneDD__sub_800BA804(*(u16 *)((s8 *)arg0 + 0x38C)) != 0 && find_entity_by_id(*(u16 *)((s8 *)arg0 + 0x38C)) == NULL) {
            enemy_clear_target__12TObjEneDD_STFUs(arg0);
        }
        ((TObjEneRe4Sorcerer *)(arg0))->vfunc_85();
        ((TObjEneRe4Sorcerer *)arg0)->calc_orb_positions();
        *(s16 *)((s8 *)arg0 + 0x3C0) += 5;
        *(s16 *)((s8 *)arg0 + 0x3C0) = (u8) *(s16 *)((s8 *)arg0 + 0x3C0);
        *(f32 *)((s8 *)arg0 + 0x3C4) += 0.01f;
        if (*(f32 *)((s8 *)arg0 + 0x3C4) >= 1.0f) {
            *(f32 *)((s8 *)arg0 + 0x3C4) -= 1.0f;
        }
    } else {
        for (i = 0; i < 2; i++) {
            if ((p = find_entity_by_id(((Obj_800F0054 *)arg0)->handles[i])) != NULL) {
                ((TObjEneRe4Sorcerer *)p)->set_flag3cc_bit2000();
            }
        }
    }
    ((TObjEneRe4Sorcerer *)arg0)->update_collision_center();
    ((TBoss8Dragon *)arg0)->set_player_state_default();
    ((TObjEneRe4Sorcerer *)(arg0))->vfunc_100();
}

Obj_800F0054 *__dt__18TObjEneRe4SorcererFv(Obj_800F0054 *arg0, s16 arg1) {
    s32 i;
    void *p;
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjEneRe4Sorcerer;
        for (i = 0; i < 2; i++) {
            if ((p = find_entity_by_id(arg0->handles[i])) != NULL) {
                queue_destruction__7TObjectFv(p);
            }
            arg0->handles[i] = 0xFFFF;
        }
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *) arg0 + 0x474, __dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__13TUnk_80490470Fv((u8 *) arg0 + 0x3FC, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_loop_invariants off
void TObjEneRe4Sorcerer::init_enemy() {
    u8 *arg0 = (u8 *)this;
    Sorc_800F0118 *self = (Sorc_800F0118 *) arg0;
    s32 i;
    u16 id;
    s32 t;
    s32 n;
    u8 *temp_r6;

    ((TObjEneDD *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&sorcerer_bml_resource) + 0x42C)) + 8);
    temp_r6 = (u8 *)(*(u8 **)((s8 *)(*(u8 * *)&sorcerer_bml_resource) + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)temp_r6 + 0xC);
    init_model__9TObjEneDDFv((void *)arg0, (void *) ((void * *)re4_sorcerer_collision_body_part_table), 1, (int)temp_r6);
    ((TObjMotion *)arg0)->set_field_d8((s32)((void *) re4_sorcerer_action_params));
    ((TObjMotion *)arg0)->set_field_dc((int) (*(s32 *)((s8 *)(*(u8 * *)&sorcerer_bml_resource) + 0x430)));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation((*(s16 *)((s8 *)arg0 + 0xB8)));
    ((TObjMotion *)arg0)->set_field_b8((int) (*(s16 *)((s8 *)arg0 + 0xB8)));
    reset_hp__9TObjEneDDFv((void *)arg0, (void *)lbl_805D52D0, (void *)TObjEneRe4Sorcerer__attack_params, (void *)TObjEneRe4Sorcerer__resistance_params);
    ((TObjEneDD *)arg0)->set_state_8();
    *(void **)((s8 *)arg0 + 0x350) = (void *) re4_sorcerer_init_params;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x1F);
    *(f32 *)((s8 *)arg0 + 0x37C) = (f32) TObjEneRe4Sorcerer__data_805DA78C;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0x1E);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0x1E);
    ((TObjEneDD_ST *)arg0)->set_active();
    *(s16 *)((s8 *)arg0 + 0x326) = 0;
    ((VObj_18_be4a70 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
    *(s16 *)((s8 *)arg0 + 0x3C0) = 0;
    *(f32 *)((s8 *)arg0 + 0x3C4) = TObjEneRe4Sorcerer__data_805DA790;
    *(s32 *)((s8 *)arg0 + 0x3C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C8) &= ~2;
    for (i = 0; i < 2; i++) {
        VecCopy__FP3VecPC3Vec(&self->v3CC[i], arg0 + 0x38);
    }
    id = self->f1C + 1;
    n = self->f2C + 1;
    self->f3E4 = id;
    ((TObjEneRe4Bit *)arg0)->create_disabled((s32)&self->v3CC[0], (s32)(id++), (s32)(n++));
    self->f3E6 = id;
    ((void (*)(void *, void *, u16, s32)) create_enabled__13TObjEneRe4BitFlll)(arg0, &self->v3CC[1], id, n);
    *(s32 *)((s8 *)arg0 + 0x3E8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3EC) = 0;
    *(s32 *)((s8 *)arg0 + 0x3F0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3F4) = *(s16 *)((s8 *)arg0 + 0x2CC);
    *(f32 *)((s8 *)arg0 + 0x3F8) = 1.0f;
    ((VObj_14_fa0828 *)(arg0 + (1020)))->m3();
    ((s32 (*)(void *))fn_80044330)(arg0 + 0x418);
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&self->e474[i]))->activate_and_dispatch();
    }
    ((s32 (*)(void *))TObjEneRe4Sorcerer__sub_800EF844)(arg0);
}
#pragma pop

void *TObjEneRe4Sorcerer__ct(void *ene_re4_sorcerer, void *arg1, void *arg2) {
    ((TObjEneDD_ST *)ene_re4_sorcerer)->init_object();
    *(s32 **)((s8 *)ene_re4_sorcerer + 0x18) = __vt__18TObjEneRe4Sorcerer;
    ((TUnk_80490470 *)((char *)ene_re4_sorcerer + 1020))->init_vtable_and_field18();
    ((TObjPlayer *)((char *)ene_re4_sorcerer + 1048))->construct_target_cursor_records();
    __construct_array((void *)((char *)ene_re4_sorcerer + 1140), init_and_activate__10TObjPlayerFv, __dt__13TUnk_804949A8Fv, 28, 4);
    *(void **)((s8 *)ene_re4_sorcerer + 0x0) = lbl_805D2AF0;
    invoke_initialization_hook__9TObjEneDDFv(ene_re4_sorcerer, arg2);
    ((void (*)(void *))TObjEneRe4Sorcerer__sub_800EFE30)(ene_re4_sorcerer);
    ((TObjEneRe4Sorcerer *)ene_re4_sorcerer)->init_enemy();
    return ene_re4_sorcerer;
}

void TObjEneRe4Sorcerer::free_bits() {
    if ((u32) TObjEneRe4Sorcerer__uv_scroll_buffer != 0U) {
        destroy_buffer_pair((void *)TObjEneRe4Sorcerer__uv_scroll_buffer, 1);
        TObjEneRe4Sorcerer__uv_scroll_buffer = 0U;
    }
    TObjEneRe4Bit__sub_800EDAB0();
    if ((u32) sorcerer_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)sorcerer_bml_resource, 1);
        sorcerer_bml_resource = 0U;
    }
}

void *TObjEneRe4Sorcerer::create() {
    void *o = __nw__7TObjectFUl(0x4F0);
    if (o != NULL) {
        o = TObjEneRe4Sorcerer__ct(o, tl_04, this);
    }
    return o;
}

void TObjEneRe4Sorcerer::load_resources() {
    u32 r;
    lbl_80501070.x = TObjEneRe4Sorcerer__data_805DA790;
    lbl_80501070.y = TObjEneRe4Sorcerer__data_805DA790;
    lbl_80501070.z = TObjEneRe4Sorcerer__data_805DA790;
    if (TObjEneDD::check_v2_mode() != 0) {
        sorcerer_bml_resource = load_enemy_bml_resource_named(bm_ene_re4_sorcerer_resource_descriptor, lbl_8043D418);
    } else {
        sorcerer_bml_resource = load_enemy_bml_resource(bm_ene_re4_sorcerer_resource_descriptor);
    }
    lbl_805D52D0 = register_boss__6TLobbyFl(0xA);
    TObjEneRe4Sorcerer__attack_params = dispatch_shared_handler_b__6TLobbyFl(0xA);
    TObjEneRe4Sorcerer__resistance_params = register_object__6TLobbyFl(0xA);
    (*(s32 *)&sorcerer_behavior_params) = dispatch_shared_handler_a__6TLobbyFl(0xA);
    TObjEneRe4Sorcerer__render_node_index = 0;
    TObjEneRe4Sorcerer__saved_render_flags = 0;
    TObjEneRe4Sorcerer__effect_render_scale = TObjEneRe4Sorcerer__data_805DA790;
    re4_sorcerer_render_node_ptr = 0;
    TObjEneRe4Bit__sub_800EDAB4();
    r = (u32) (int)::operator new(0x14);
    if (r != 0) {
        r = (u32) ((TLobby *)r)->alloc_tables(*(s32 *)((s8 *)(*(u8 **)((s8 *)sorcerer_bml_resource + 0x42C)) + 8), 2);
    }
    TObjEneRe4Sorcerer__uv_scroll_buffer = r;
    Params_800F0464 p = re4_sorcerer_spawn_descriptor;
    p.a = *(s32 *)((s8 *)sorcerer_bml_resource + 0x430);
    TLobby::spawn_npc_enemy((s16)0x2A, (s32)(*(s32 *)((s8 *)(*(u8 **)((s8 *)sorcerer_bml_resource + 0x42C)) + 8)), (s32)(*(s32 *)((s8 *)(*(u8 **)((s8 *)sorcerer_bml_resource + 0x42C)) + 0xC)), (s32)&p, re4_sorcerer_collision_body_part_table[3], (f32)TObjEneRe4Sorcerer__data_805DA78C);
}

void TBoss3Volopt__sub_800F059C(void) {  }

s32 TBoss3Volopt::remap_area_sound_id(s32 arg0) {
    s32 masked;
    s32 result;
    s32 state;
    state = get_current_area();
    if (TLobby::get_instance() != 0) {
        if (state != 0x13 && state != 0x14 && state != 0x15 && state != 0x16 && state != 0x22 && state != 0x23) {
            return arg0;
        }
    } else if (state != 0x10 && state != 0x11) {
        return arg0;
    }
    masked = arg0 & 0x8FFFFF00;
    if (TLobby::get_instance() != 0) {
        if (state == 0x13 || state == 0x14) {
            result = 0x3AB42;
        } else if (state == 0x15 || state == 0x16) {
            result = 0x4003AB3D;
        } else if (state == 0x22) {
            result = 0x4003B22A;
        } else if (state == 0x23) {
            result = 0x4003A359;
        }
    } else {
        result = 0x30043;
        result |= masked;
    }
    return result;
}

s32 remap_area_sound_id(s32 arg0, s32 arg1) {
    s32 st;
    s32 base;
    s32 start;
    st = get_current_area();
    if (TLobby::get_instance() != 0) {
        if (st != 0x13 && st != 0x14 && st != 0x15 && st != 0x16 && st != 0x22 && st != 0x23) {
            return arg0;
        }
    } else {
        if (st != 0x10 && st != 0x11) {
            return arg0;
        }
    }
    if ((u32) arg0 == 0x4003B241U) {
        return 0x4003B23E;
    }
    if (((u32) (arg0 & 0xBFFF00FF) >> 16 << 16) != 0x30000) {
        return arg0;
    }
    if (TLobby::get_instance() != 0) {
        base = area_sound_remap_table_b[arg1].base;
    } else {
        base = area_sound_remap_table_a[arg1].base;
    }
    if (base < 0) {
        return arg0;
    }
    if (TLobby::get_instance() != 0) {
        start = area_sound_remap_table_b[arg1].start;
    } else {
        start = area_sound_remap_table_a[arg1].start;
    }
    {
        s32 r = base + (arg0 - start);
        return r | (arg0 & 0x8FFFFF00);
    }
}
}
