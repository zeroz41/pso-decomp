#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneRe4Bit.h"
struct Obj_800ED4BC;

#include "types.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe4Bit.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneRe4Sorcerer.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/object/TObjFish.h"

#include "pso/player/TUnk_80490470.h"
#pragma defer_codegen on

struct VBase_18_f9c8ca
{
  char pad[0x18];
};

struct VObj_18_f9c8ca : VBase_18_f9c8ca {
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
    virtual s32 m100();
};

struct VBase_14_c143b1 { char pad[0x14]; };

struct VObj_14_c143b1 : VBase_14_c143b1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    virtual s32 m5();
};


struct LBase_800ECA40 { char pad[0x14]; };

struct Light_800ECA40 : LBase_800ECA40 {
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
};

struct Ent_800ECA40 { s32 a; s32 b; s32 c; };

struct Model_800ECA40 {
    Ent_800ECA40 ents[3];
    u8 pad24[0x2C - 0x24];
    s32 x2C;
};

struct VBase_800ECA40 { char pad[0x18]; };

struct Bit_800ECA40 : VBase_800ECA40 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    u8 pad1C[0x24 - 0x1C];
    Model_800ECA40 **x24;
    u8 pad28[0x34 - 0x28];
    void *x34;
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 x60;
    u8 pad64[0x300 - 0x64];
    f32 x300;
    u8 pad304[0x3CC - 0x304];
    s32 flags;
    s32 idx;
    u8 pad3D4[0x3DC - 0x3D4];
    Light_800ECA40 light;
};

extern "C" {
void set_state_flags__18TObjEneRe4SorcererFPv(u8 *arg0);
void set_hold_flags__18TObjEneRe4SorcererFPv(u8 *arg0);
void TObjEneRe4Sorcerer__sub_800ED47C(void* p);
s32 play_sound_effect(s32, void *, int, int);
extern const f32 TObjEneRe4Bit__data_805DA770;
void TObjEneRe4Bit__sub_800ECC14(u8 *arg0, s32 arg1);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 clear_attack_receipts__9TObjEneDDFv(void *);
void TObjEneRe4Bit__sub_800ECD28(u8 *arg0, s32 arg1);
extern const f32 lbl_805DA76C;
extern const f32 lbl_805DA778;
void TObjEneRe4Bit__sub_800ECED0(TObjEneRe4Bit *arg0, s32 arg1);
void TObjEneRe4Bit__sub_800ECE04(TObjEneRe4Bit *arg0, s32 arg1);
s32 is_main_phase_15__9TObjEneDDFv();
s32 defer_render__7TObjectFv(void *);
int scale_matrix(int, f32, f32, f32);
int rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
int push_matrix();
s32 pop_matrix(void);
int post_translate_matrix(void *);
void draw_chunk_object(void *child);
extern Vec re4_bit_render_vec;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805DA768;
extern const f32 lbl_805DA774;
void render__13TObjEneRe4BitFv(Bit_800ECA40 *self);


extern "C" {
void vfunc_28__13TObjEneRe4BitFv(void);
void apply_poison_status__13TObjEneRe4BitFv(void);
void apply_paralysis__13TObjEneRe4BitFv(void);
void apply_slow_status__13TObjEneRe4BitFv(void);
void apply_confusion_status__13TObjEneRe4BitFv(void);
void apply_movement_ailment__13TObjEneRe4BitFl(void);
void apply_shock_status__13TObjEneRe4BitFv(void);
void clear_harmful_statuses__13TObjEneRe4BitFv(void);
void apply_attack_stat_status__13TObjEneRe4BitFPv(void);
void apply_defense_stat_status__13TObjEneRe4BitFPv(void);
void vfunc_61__13TObjEneRe4BitFv(void);
void vfunc_62__13TObjEneRe4BitFv(u8 *arg0);
void vfunc_63__13TObjEneRe4BitFv(u8 *arg0);
void vfunc_88__13TObjEneRe4BitFv(void *arg0);
void * __dt__13TObjEneRe4BitFv(void *arg0, s16 arg1);
void run_task__13TObjEneRe4BitFv(u8 *arg0);
}

void *re4_bit_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *re4_bit_model_node_desc[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
extern void *__vt__13TObjEneRe4Bit[];
#define re4_bit_init_params ((u8 *)re4_bit_init_params)
#define re4_bit_model_node_desc ((u8 *)re4_bit_model_node_desc)
#define __vt__13TObjEneRe4Bit ((s32 *)__vt__13TObjEneRe4Bit)



typedef struct VBase_18_f9c8ca VBase_18_f9c8ca;
typedef struct VObj_18_f9c8ca VObj_18_f9c8ca;








struct ED300Base_800ed300_800ED258 { char pad[0x14]; };
struct ED300Obj_800ed300_800ED258 : ED300Base_800ed300_800ED258 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3(void *);
};





struct ED384Base_800ed384_800ED34C { char pad[0x14]; };
struct ED384Obj_800ed384_800ED34C : ED384Base_800ed384_800ED34C {
    virtual void m0();
    virtual void m1();
    virtual void m2(void *);
};



int TObjEneRe4Sorcerer__sub_800ED498(u8 *arg0);




}

struct LBase_800ED7FC { char pad[0x14]; };
struct Light_800ED7FC : LBase_800ED7FC {
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3(f32);
};

struct VBase_800ED7FC { char pad[0x18]; };
struct Bit_800ED7FC : VBase_800ED7FC {
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
    u8 pad1C[0x24 - 0x1C];
    s32 x24;
    u8 pad28[0x34 - 0x28];
    s32 x34;
    u8 pad38[0x326 - 0x38];
    s16 state;
    u8 pad328[0x350 - 0x328];
    void *x350;
    u8 pad354[0x37C - 0x354];
    f32 x37C;
    u8 pad380[0x3C8 - 0x380];
    s32 kind;
    s32 x3CC;
    s32 x3D0;
    s32 x3D4;
    f32 x3D8;
    Light_800ED7FC light;
    u32 pad3F4;
    f32 x3F8;
    f32 x3FC;
    f32 x400;
    s32 x404;
    s32 x408;
    s32 x40C;
};

extern "C" {
__declspec(section ".data") s32 TObjEneRe4Bit_boss_handles[2];
__declspec(section ".data") s32 lbl_80501058[2];
__declspec(section ".data") s32 lbl_80501060[2];
__declspec(section ".data") s32 lbl_80501068[2];
}

struct Vec_800ED4BC { f32 x, y, z; };

struct Obj_800ED4BC { u8 pad0[0x38]; f32 f38; u8 pad3C[4]; f32 f40; u8 pad44[0x2FC - 0x44]; Vec_800ED4BC v2FC; u8 pad308[0x3C0 - 0x308]; Vec_800ED4BC *f3C0; u8 pad3C4[0x3D8 - 0x3C4]; f32 f3D8; u8 pad3DC[0x3F8 - 0x3DC]; Vec_800ED4BC v3F8; };

extern "C" {
void vec3_add_to(void *, void *);
void subtract_vector(void *, void *);
extern const f32 lbl_805DA77C;
extern const f32 lbl_805DA780;
u8 *TObjEneRe4Bit__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
void *__dt__13TObjEneRe4BitFv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 __ct__12TObjEneDD_STFP7TObject();
s16 get_entity_id(void *);








}
extern "C" {

int reset_hp__9TObjEneDDFPUcPUcPUc(void *, s32, s32, s32);
int initialize_enemy_state__9TObjEneDDFl(void *, int);
int init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, int);
extern s32 TObjEneRe4Bit__model;
extern s32 re4_bit_texture_list;
extern const f32 lbl_805DA784;


extern s32 lbl_805D2AE8;


}

struct Inner_800EDAB4 { u8 pad0[0xC]; s32 fC; u8 pad10[8]; s32 f18; };

struct Obj_800EDAB4 { u8 pad0[0x42C]; Inner_800EDAB4 *f42C; };

extern "C" {
s32 register_boss__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
extern s32 lbl_8043D2B0[];
extern s32 lbl_8043D2B8[];
extern s32 lbl_8043D2C0[];
extern s32 lbl_8043D2C8[];
extern Obj_800EDAB4 *sorcerer_bml_resource;
void TObjEneRe4Bit__sub_800EDAB0(void);
void *__nw__7TObjectFUl(int);



extern void *tl_04;




}


#undef re4_bit_init_params
#undef re4_bit_model_node_desc
#undef __vt__13TObjEneRe4Bit
extern "C" void init__13TObjEneRe4BitFPv(Bit_800ED7FC *self);
extern "C" void TObjEneRe4Bit__sub_800EDAB4(void);

#define re4_bit_init_params ((u8 *)re4_bit_init_params)
#define re4_bit_model_node_desc ((u8 *)re4_bit_model_node_desc)
#define __vt__13TObjEneRe4Bit ((s32 *)__vt__13TObjEneRe4Bit)
extern "C" {
void TObjEneRe4Bit::apply_defense_stat_status(void *) {  }

void TObjEneRe4Bit::apply_attack_stat_status(void *) {  }

void TObjEneRe4Bit::clear_harmful_statuses() {  }

void TObjEneRe4Bit::apply_shock_status() {  }

void TObjEneRe4Bit::apply_movement_ailment(s32) {  }

void TObjEneRe4Bit::apply_confusion_status() {  }

void TObjEneRe4Bit::apply_slow_status() {  }

void TObjEneRe4Bit::apply_paralysis() {  }

void TObjEneRe4Bit::apply_poison_status() {  }

void TObjEneRe4Bit__sub_800EDAB4(void) {
    s32 i;
    TObjEneRe4Bit__model = sorcerer_bml_resource->f42C->f18;
    re4_bit_texture_list = sorcerer_bml_resource->f42C->fC;
    for (i = 0; i < 2; i++) {
        TObjEneRe4Bit_boss_handles[i] = register_boss__6TLobbyFl(lbl_8043D2B0[i]);
        lbl_80501058[i] = dispatch_shared_handler_b__6TLobbyFl(lbl_8043D2B8[i]);
        lbl_80501060[i] = register_object__6TLobbyFl(lbl_8043D2C0[i]);
        lbl_80501068[i] = dispatch_shared_handler_a__6TLobbyFl(lbl_8043D2C8[i]);
    }
}

void TObjEneRe4Bit__sub_800EDAB0(void) {  }

void *TObjEneRe4Bit::create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    void *o;
    o = __nw__7TObjectFUl(0x410);
    if (o != NULL) {
        o = ((void *(*)(void *, void *, void *, void *, void *, void *, void *)) TObjEneRe4Bit__ct)(o, tl_04, arg0, arg1, arg2, arg3, arg4);
    }
    return o;
}

void TObjEneRe4Bit::create_disabled(s32 arg1, s32 arg2, s32 kind) {
    s32 arg0 = (s32)this;
    TObjEneRe4Bit::create((void *)arg0, (void *)arg1, (void *)(0), (void *)arg2, (void *)kind);
}

void TObjEneRe4Bit::create_enabled(s32 arg1, s32 arg2, s32 kind) {
    s32 arg0 = (s32)this;
    TObjEneRe4Bit::create((void *)arg0, (void *)arg1, (void *)(1), (void *)arg2, (void *)kind);
}

u8 *TObjEneRe4Bit__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6) {
    __ct__12TObjEneDD_STFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TObjEneRe4Bit;
    __ct__13TUnk_80490470Fv((arg0 + 0x3DC));
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2AE8;
    ((TObjEneDD *)arg0)->init_common_from((u8 *)arg2);
    *(s16 *)((s8 *)arg0 + 0x3C4) = get_entity_id((void *)arg2);
    ((TObjEneRe4Bit *)arg0)->entity_id = arg5;
    *(s16 *)((s8 *)arg0 + 0x2C) = arg6;
    *(s32 *)((s8 *)arg0 + 0x3C0) = arg3;
    *(s32 *)((s8 *)arg0 + 0x3C8) = arg4;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg3));
    init__13TObjEneRe4BitFPv((Bit_800ED7FC *) (arg0));
    return arg0;
}

void init__13TObjEneRe4BitFPv(Bit_800ED7FC *self) {
    s32 i;

    ((TObjEneDD *)self)->init_position_vectors();
    self->x34 = TObjEneRe4Bit__model;
    self->x24 = re4_bit_texture_list;
    init_model__9TObjEneDDFP13CollisionBodyl(self, re4_bit_model_node_desc, 1);
    i = self->kind == 1 ? 0 : 1;
    reset_hp__9TObjEneDDFPUcPUcPUc(self, TObjEneRe4Bit_boss_handles[i], lbl_80501058[i], lbl_80501060[i]);
    ((TObjEneDD *)self)->set_state_8();
    self->x350 = re4_bit_init_params;
    if (self->kind == 1) {
        initialize_enemy_state__9TObjEneDDFl(self, 0x20);
    } else {
        initialize_enemy_state__9TObjEneDDFl(self, 0x21);
    }
    self->x37C = lbl_805DA784;
    self->x3CC = 0;
    self->x3D0 = 3;
    self->x3D4 = 3;
    self->x3D8 = TObjEneRe4Bit__data_805DA770;
    self->light.l3(lbl_805DA784);
    self->x3F8 = TObjEneRe4Bit__data_805DA770;
    self->x3FC = TObjEneRe4Bit__data_805DA770;
    self->x400 = TObjEneRe4Bit__data_805DA770;
    self->x404 = 0;
    self->x408 = 0;
    self->x40C = 0;
    ((TObjEneRe4Bit *)self)->sub_800ED408();
    ((TObjEneRe4Bit *)self)->call_vt_90_91();
    self->state = 0;
    self->m85(self->state, 4);
}

}
TObjEneRe4Bit::~TObjEneRe4Bit() {
    free_collision_body_parts(this);
    __dt__13TUnk_80490470Fv((s8 *)this + 0x3DC, -1);
}

extern "C" {
void run_task__13TObjEneRe4BitFv(u8 *arg0) {
    s32 temp_r3;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRe4Bit *)(arg0))->vfunc_105();
        return;
    }
    if ((((TObjEneRe4Bit *)(arg0))->vfunc_83() == 1) || (temp_r3 = *(s32 *)((s8 *)arg0 + 0x3CC), (((temp_r3 & 0x2000) == 0) != 0))) {
        ((TObjEneRe4Bit *)(arg0))->vfunc_85();
        ((TObjEneRe4Bit *)arg0)->clear_state_flags_when_done();
    } else {
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (temp_r3 & 0xFFFFDFFF);
    }
    ((TObjEneRe4Bit *)arg0)->copy_pos();
    ((TObjEneRe4Bit *)(arg0))->vfunc_88();
    ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
}

void TObjEneRe4Bit::vfunc_28() {  }

void TObjEneRe4Bit::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    temp_r0 = this->mode;
    if (temp_r0 != 6) {
        if (temp_r0 == 2) {
            ((TObjEneDD *)arg0)->transition_enemy_state(6);
            *(s32 *)((s8 *)arg0 + 0x404) = 3;
            return;
        }
        ((TObjEneDD *)arg0)->transition_enemy_state(6);
    }
}

void TObjEneRe4Bit::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if ((s16) this->mode != 5) {
        if (*(s32 *)((s8 *)arg0 + 0x3CC) & 0x1000) {
            ((s32 (*)())clear_attack_receipts__9TObjEneDDFv)();
            return;
        }
        ((TObjEneDD *)arg0)->transition_enemy_state(5);
    }
}

void TObjEneRe4Bit::vfunc_61() {  }

void TObjEneRe4Bit::copy_pos() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }

void TObjEneRe4Bit::vfunc_88() {
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (this->m_300 - *(f32 *)((s8 *)this + 0x3C));
}

void TObjEneRe4Bit::update_position_flag() {
    s32 sp8;

    VecCopy((Vec *)(&sp8), (const Vec *)(((u8 *)this) + 0x2FC));
    if (this->vfunc_101((u8 *)&sp8) == 0U) {
        *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3CC) & 0xFFFFF7FF);
        return;
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3CC) | 0x800);
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneRe4Bit::update_homing_velocity() {
    Obj_800ED4BC *arg0 = (Obj_800ED4BC *)this;
    Vec_800ED4BC sp;
    f32 s;
    VecCopy((Vec *)(&sp), (const Vec *)(this->m_3dc));
    sp.y = sp.y + arg0->f3D8;
    subtract_vector(&sp, &arg0->v2FC);
    s = lbl_805DA77C * ((TObjBoss2Tunnel *)(&sp))->update_scale();
    arg0->v3F8.x = lbl_805DA780 * (sp.x * s + arg0->v3F8.x);
    arg0->v3F8.y = lbl_805DA780 * (sp.y * s + arg0->v3F8.y);
    arg0->v3F8.z = lbl_805DA780 * (sp.z * s + arg0->v3F8.z);
    vec3_add_to(&arg0->v2FC, &arg0->v3F8);
    arg0->f38 = arg0->v2FC.x;
    arg0->f40 = arg0->v2FC.z;
}

}
#pragma pop
extern "C" {
int TObjEneRe4Sorcerer__sub_800ED498(u8 *arg0) {
    s16 temp_r3;
    u8 var_r0;
    temp_r3 = *(s16 *)((s8 *)arg0 + 0x326);
    var_r0 = 0;
    if ((temp_r3 != 5) && (temp_r3 != 6)) {
        var_r0 = 1;
    }
    return var_r0;
}

s32 TObjEneRe4Sorcerer::get_state() { return *(s32*)((char*)this + 0x404); }

void*TObjEneRe4Sorcerer::get_spell_data() { return (char*)this + 0x2fc; }

void TObjEneRe4Sorcerer__sub_800ED47C(void* p) { *(s32*)((char*)p + 0x3d0) = 3; }

void TObjEneRe4Sorcerer::set_state_flag_and_mode(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x3CC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3CC) | 1);
    switch (arg1) {
    case 0:
        *(s32 *)((s8 *)((u8 *)this) + 0x3D4) = 4;
        return;
    case 1:
        *(s32 *)((s8 *)((u8 *)this) + 0x3D4) = 5;
        return;
    case 2:
        *(s32 *)((s8 *)((u8 *)this) + 0x3D4) = 6;
        return;
    }
}

void TObjEneRe4Sorcerer::set_attack_flag() { *(u32*)((char*)this + 0x3cc) |= 0x2; }

void TObjEneRe4Bit::sub_800ED408() { *(u32*)((char*)this + 0x3cc) &= 0xfffffeff; }

void TObjEneRe4Sorcerer::set_flag_and_notify() {
    *(s32 *)((s8 *)this + 0x3CC) = (s32) (*(s32 *)((s8 *)this + 0x3CC) | 0x10);
    if (!(*(s32 *)((s8 *)this + 0x3CC) & 4)) {
        ((s32 (*)())set_hold_flags__18TObjEneRe4SorcererFPv)();
    }
}

void set_hold_flags__18TObjEneRe4SorcererFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) | 0x204);
    *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFFF7);
    ((ED384Obj_800ed384_800ED34C*)(arg0 + 0x3DC))->m2(arg0);
}

void TObjEneRe4Sorcerer::clear_state_flag_0x10() {
    *(s32 *)((s8 *)this + 0x3CC) = (s32) (*(s32 *)((s8 *)this + 0x3CC) & 0xFFFFFFEF);
    if (!(*(s32 *)((s8 *)this + 0x3CC) & 0x408)) {
        ((s32 (*)())set_state_flags__18TObjEneRe4SorcererFPv)();
    }
}

void set_state_flags__18TObjEneRe4SorcererFPv(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFFFB);
    *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) | 0x308);
    ((ED300Obj_800ed300_800ED258*)(arg0 + 0x3DC))->m3(arg0);
}

void TObjEneRe4Sorcerer::invoke_state_callbacks() {
    this->vfunc_91();
    this->vfunc_94();
}

void TObjEneRe4Bit::call_vt_90_91() {
    this->vfunc_92();
    this->vfunc_93();
}

void TObjEneRe4Sorcerer::set_flag3cc_bit2000() { *(u32*)((char*)this + 0x3cc) |= 0x2000; }

void TObjEneRe4Bit::reset_transform() {
    VecCopy((Vec *)((char *)this + 764), (const Vec *)(*(void **)((s8 *)this + 0x3C0)));
    *(f32 *)((s8 *)this + 0x3F8) = TObjEneRe4Bit__data_805DA770;
    *(f32 *)((s8 *)this + 0x3FC) = TObjEneRe4Bit__data_805DA770;
    *(f32 *)((s8 *)this + 0x400) = TObjEneRe4Bit__data_805DA770;
    update_position_flag();
    this->transform_part_positions();
}

void TObjEneRe4Bit::clear_state_flags_when_done() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    temp_r3 = *(s32 *)((s8 *)arg0 + 0x3CC);
    if (temp_r3 & 4) {
        if (((VObj_14_c143b1 *)(arg0 + (988)))->m4() != 0) {
            *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFFFB);
            *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFDFF);
            *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFEFF);
        }
    } else if ((temp_r3 & 8) && (((VObj_14_c143b1 *)(arg0 + (988)))->m5() != 0)) {
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFFF7);
        *(s32 *)((s8 *)arg0 + 0x3CC) = (s32) (*(s32 *)((s8 *)arg0 + 0x3CC) & 0xFFFFFDFF);
    }
}

void TObjEneRe4Bit::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        handle_state_message(reason);
        return;
    case 1:
        handle_event(reason);
        return;
    case 2:
        TObjEneRe4Bit__sub_800ECED0(this, reason);
        return;
    case 3:
        TObjEneRe4Bit__sub_800ECE04(this, reason);
        return;
    case 5:
        TObjEneRe4Bit__sub_800ECD28((u8 *)this, reason);
        return;
    case 6:
        TObjEneRe4Bit__sub_800ECC14((u8 *)this, reason);
    default:
        return;
    }
}

void TObjEneRe4Bit::handle_state_message(s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        transition_enemy_state(1);
        return;
    }
}

s32 TObjEneRe4Bit::handle_event(s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        set_field_378(1);
        *(s32 *)((s8 *)this + 0x3CC) = (s32) (*(s32 *)((s8 *)this + 0x3CC) & 0xFFFFEFFF);
        break;
    case 3:
        temp_r4 = *(s32 *)((s8 *)this + 0x3CC);
        if (temp_r4 & 1) {
            *(s32 *)((s8 *)this + 0x3CC) = (s32) (temp_r4 & 0xFFFFFFFE);
            transition_enemy_state(2);
            break;
        }
        if (temp_r4 & 2) {
            *(s32 *)((s8 *)this + 0x3CC) = (s32) (temp_r4 & 0xFFFFFFFD);
            transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        update_homing_velocity();
        update_position_flag();
        break;
    }
}

}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" {
void TObjEneRe4Bit__sub_800ECED0(TObjEneRe4Bit *ene_re4_bit, s32 arg1) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_re4_bit)->set_field_378(3);
        *(s32 *)((s8 *)ene_re4_bit + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_re4_bit + 0x3CC) | 0x1000);
        ene_re4_bit->m_408 = 0;
        *(s32 *)((s8 *)ene_re4_bit + 0x404) = 1;
        *(s32 *)((s8 *)ene_re4_bit + 0x3D0) = (s32) ene_re4_bit->m_3f0;
        return;
    case 3:
        temp_r4 = *(s32 *)((s8 *)ene_re4_bit + 0x3CC);
        if (temp_r4 & 2) {
            *(s32 *)((s8 *)ene_re4_bit + 0x3CC) = (s32) (temp_r4 & 0xFFFFFFFD);
            ((TObjEneDD *)ene_re4_bit)->transition_enemy_state(3);
        }
        return;
    case 0:
        switch (ene_re4_bit->m_408) {
        case 1:
            break;
        case 0:
            *(f32 *)((s8 *)ene_re4_bit + 0x3D8) = *(f32 *)((s8 *)ene_re4_bit + 0x3D8) + lbl_805DA778;
            if (*(f32 *)((s8 *)ene_re4_bit + 0x3D8) > lbl_805DA76C) {
                *(f32 *)((s8 *)ene_re4_bit + 0x3D8) = lbl_805DA76C;
                ene_re4_bit->m_408 = 1;
                *(s32 *)((s8 *)ene_re4_bit + 0x404) = 2;
            }
            ene_re4_bit->rotation_y = (ene_re4_bit->rotation_y + 0x1800);
            break;
        }
        ene_re4_bit->update_homing_velocity();
        ene_re4_bit->update_position_flag();
        return;
    case 5:
        *(s32 *)((s8 *)ene_re4_bit + 0x404) = 0;
        break;
    }
}

}
#pragma pop
#pragma push
#pragma opt_common_subs off
extern "C" {
void TObjEneRe4Bit__sub_800ECE04(TObjEneRe4Bit *ene_re4_bit, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_re4_bit)->set_field_378(3);
        *(s32 *)((s8 *)ene_re4_bit + 0x3CC) = (s32) (*(s32 *)((s8 *)ene_re4_bit + 0x3CC) & 0xFFFFEFFF);
        *(s32 *)((s8 *)ene_re4_bit + 0x3D0) = 3;
        break;
    case 3:
        if (*(f32 *)((s8 *)ene_re4_bit + 0x3D8) <= TObjEneRe4Bit__data_805DA770) {
            ((TObjEneDD *)ene_re4_bit)->transition_enemy_state(1);
            break;
        }
    case 5:
        break;
    case 0:
        *(f32 *)((s8 *)ene_re4_bit + 0x3D8) = (f32) (*(f32 *)((s8 *)ene_re4_bit + 0x3D8) - lbl_805DA778);
        if (*(f32 *)((s8 *)ene_re4_bit + 0x3D8) < TObjEneRe4Bit__data_805DA770) {
            *(f32 *)((s8 *)ene_re4_bit + 0x3D8) = (f32) TObjEneRe4Bit__data_805DA770;
        }
        ene_re4_bit->rotation_y = (ene_re4_bit->rotation_y - 0x1800);
        ene_re4_bit->update_homing_velocity();
        ene_re4_bit->update_position_flag();
        break;
    }
}

}
#pragma pop
extern "C" {
void TObjEneRe4Bit__sub_800ECD28(u8 *ene_dd, s32 arg1) {
  switch (arg1)
  {
    case 4:
      *((s32 *) (((s8 *) ene_dd) + 0x408)) = 0;
      return;
    case 3:
      if (((s32) (*((s32 *) (((s8 *) ene_dd) + 0x408)))) > 0xF)
    {
      ((TObjEneDD *)ene_dd)->transition_enemy_state(1);
    }
      return;
    case 0:
      *((s32 *) (((s8 *) ene_dd) + 0x408)) = (s32) ((*((s32 *) (((s8 *) ene_dd) + 0x408))) + 1);
      VecCopy((Vec *)(ene_dd + 0x2FC), (const Vec *)((int) (*((s32 *) (((s8 *) ene_dd) + 0x3C0)))));
      ((TObjEneDD *)ene_dd)->m_300 = (f32) ((((TObjEneDD *)ene_dd)->m_300) + (*((f32 *) (((s8 *) ene_dd) + 0x3D8))));
      ((TObjEneDD *)ene_dd)->m_2fc = (f32) ((((TObjEneDD *)ene_dd)->m_2fc) + calc_elapsed_scaled__9TObjEneDDFv((void *) ene_dd));
      ((TObjEneDD *)ene_dd)->m_304 = (f32) ((((TObjEneDD *)ene_dd)->m_304) + calc_elapsed_scaled__9TObjEneDDFv((void *) ene_dd));
      (((TObjEneDD *)(ene_dd))->vfunc_102());
      return;
    case 5:
      clear_attack_receipts__9TObjEneDDFv((void *) ene_dd);
      return;
      break;
  }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneRe4Bit__sub_800ECC14(u8 *ene_panarms, s32 arg1) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        ((TObjEnePanarms *)ene_panarms)->m_408 = 0;
        ((s32 (*)(void *))set_hold_flags__18TObjEneRe4SorcererFPv)(ene_panarms);
        ((TObjEnePanarms *)ene_panarms)->m_3cc = (s32) (((TObjEnePanarms *)ene_panarms)->m_3cc | 0x400);
        play_sound_effect(((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003A815)), ene_panarms + 0x38, 0, 0);
        break;
    case 3:
        if (((TObjEnePanarms *)ene_panarms)->m_3cc & 8) {
            play_sound_effect(((TObjEnemy *)(ene_panarms))->remap_sound_for_area((s32)(0x4003AD16)), ene_panarms + 0x38, 0, 0);
            ((TObjEneDD *)ene_panarms)->transition_enemy_state(1);
        }
        break;
    case 0:
        ((TObjEnePanarms *)ene_panarms)->m_408 = (s32) (((TObjEnePanarms *)ene_panarms)->m_408 + 1);
        if ((s32) ((TObjEnePanarms *)ene_panarms)->m_408 >= 0x384) {
            temp_r4 = ((TObjEnePanarms *)ene_panarms)->m_3cc;
            if (!(temp_r4 & 0x10)) {
                ((TObjEnePanarms *)ene_panarms)->m_3cc = (s32) (temp_r4 & 0xFFFFFBFF);
                ((s32 (*)(void *))set_state_flags__18TObjEneRe4SorcererFPv)(ene_panarms);
                return;
            }
        }
        break;
    case 5:
        ((TObjEnePanarms *)ene_panarms)->actorFlags = (s32) (((TObjEnePanarms *)ene_panarms)->actorFlags & 0xFFFFF7FF);
        ((TObjEnePanarms *)ene_panarms)->hp = (s16) ((TObjEnePanarms *)ene_panarms)->hpmax;
        ((s32 (*)())TObjEneRe4Sorcerer__sub_800ED47C)();
        *(f32 *)((s8 *)ene_panarms + 0x3D8) = (f32) TObjEneRe4Bit__data_805DA770;
        break;
    }
}

}
#pragma pop
extern "C" {
void render__13TObjEneRe4BitFv(Bit_800ECA40 *self) {
    f32 range;
    s32 saved;
    s32 draw;
    Model_800ECA40 *m;
    if (TObjPlayer::check_demo_mode() != 0) {
        self->m104();
        return;
    }
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        range = lbl_805D9E84;
    } else {
        range = lbl_805DA768;
    }
    if (!(self->flags & 0x100)) {
        return;
    }
    if (self->m8(range, lbl_805DA76C) == 0) {
        return;
    }
    if (self->flags & 0x800) {
        Vec v = re4_bit_render_vec;
        ((TObjEnemy *)self)->draw_ground_shadow(&v, 0);
    }
    ((TObjEneDD *)self)->update_secondary_light();
    m = *self->x24;
    saved = m->x2C;
    m->x2C = m->ents[self->idx].c;
    TObjFish::set_global_param((s32)self->x24);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    TObjPlayer::toggle_particle_effect();
    draw = 1;
    if (self->flags & 0x200) {
        self->light.l6();
        if (defer_render__7TObjectFv(self) != 0) {
            draw = 0;
        }
    }
    if (draw != 0) {
        push_matrix();
        post_translate_matrix(&self->pos);
        translate_matrix(0, TObjEneRe4Bit__data_805DA770, self->x300 - self->pos.y, TObjEneRe4Bit__data_805DA770);
        rotate_matrix_y(0, self->x60);
        scale_matrix(0, lbl_805DA774, lbl_805DA774, lbl_805DA774);
        draw_chunk_object(self->x34);
        pop_matrix();
    }
    self->light.l7();
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    ((TObjEneDD *)self)->update_primary_light();
    (*self->x24)->x2C = saved;
}

}
#undef re4_bit_init_params
#undef re4_bit_model_node_desc
#undef __vt__13TObjEneRe4Bit
