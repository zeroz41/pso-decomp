#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TOBiwaMushi.h"
#include "pso/misc/TOMekaFish00.h"
#include "pso/misc/TOMekaFish01.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_8046FCB8[];
extern char lbl_8046FCC8[];
extern char lbl_8046FCDC[];
extern char lbl_8046FCF4[];
extern char lbl_8046FD08[];
extern char lbl_8046FD1C[];
extern const char *bm_obj_meka_fish_0_model_names[2];
extern const char *bm_obj_meka_fish_0_motion_names[2];
extern BmlResourceDescriptor TOMekaFish00__resource_descriptor;
extern const char *bm_obj_meka_fish_1_model_names[2];
extern const char *bm_obj_meka_fish_1_motion_names[2];
extern BmlResourceDescriptor TOMekaFish01__shared_resource_descriptor;

struct RecoveredGlobal_802AA354_lbl_804DE000 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802AA354_lbl_804DE000_size[sizeof(RecoveredGlobal_802AA354_lbl_804DE000) == 0x10 ? 1 : -1];

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_802AA354_lbl_804DE000 biwamushi_resource_desc;
extern u32 TOBiwaMushi__shared_model_resource;
void *TOBiwaMushi__create(void *arg0);
void *__dt__11TOBiwaMushiFv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void *TOBiwaMushi__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__dt__11TODragonflyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void *TOBiwaMushi__create(void *dragonfly) {
    void *o = __nw__7TObjectFUl(0x100);
    if (o != NULL) {
        o = TOBiwaMushi__ct(o, dragonfly);
    }
    return o;
}

void TOBiwaMushi::free_shared_data() {
    if ((u32) TOBiwaMushi__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOBiwaMushi__shared_model_resource, 1);
        TOBiwaMushi__shared_model_resource = 0U;
    }
}

extern s32 __vt__11TOBiwaMushi[];

void TOBiwaMushi::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &biwamushi_resource_desc.value, 0, 0, 0));
    }
    (*(s32 *)&TOBiwaMushi__shared_model_resource) = var_r0;
}

void *__dt__11TOBiwaMushiFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TOBiwaMushi;
        __dt__11TODragonflyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
struct VBase_802AA3FC { u8 pad[0x18]; };
struct Obj_802AA3FC : VBase_802AA3FC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4();
    virtual void m5(void *);
};

struct Model_802AA3FC { u8 pad[0x14]; f32 f14; };
struct ModelRef_802AA3FC { u8 pad[4]; Model_802AA3FC *m; };
struct Anim_802AA3FC { u8 pad[4]; u32 frames; };

struct Self_802AA3FC : Obj_802AA3FC {
    u8 pad1c[0x24 - 0x1c];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    ModelRef_802AA3FC *f34;
    u8 pad38[0x84 - 0x38];
    s32 f84;
    s32 f88;
    u8 pad8c[0xac - 0x8c];
    s32 fAC;
    u8 padb0[4];
    f32 fB4;
    f32 fB8;
    Anim_802AA3FC *fBC;
    f32 fC0;
    f32 fC4;
    u8 padc8[0xec - 0xc8];
    f32 fEC;
    f32 fF0;
    f32 fF4;
    s32 fF8;
    s32 fFC;
};

Anim_802AA3FC *get_bml_motion(u32, s32);
s32 TObjFish__sub_8001EDB0(u32, s32);
ModelRef_802AA3FC *get_bml_model(u32, s32);
void __ct__11TODragonflyFv(void *, void *);
s32 rand();
f32 sin_table_lookup(s32);
extern s32 lbl_805D3E48;
extern const f32 lbl_805DE068;
extern const f32 lbl_805DE06C;
extern const f32 lbl_805DE070;
extern const f32 lbl_805DE074;
extern const f32 lbl_805DE078;
extern const f32 lbl_805DE07C;
extern const f32 lbl_805DE080;
extern const f32 lbl_805DE084;

#pragma fp_contract on
#define self ((Self_802AA3FC *)arg0)
void *TOBiwaMushi__ct(void *arg0, void *dragonfly) {
    __ct__11TODragonflyFv(self, dragonfly);
    *(s32 **)((u8 *)self + 0x18) = __vt__11TOBiwaMushi;
    *(s32 *)self = lbl_805D3E48;
    self->m5(dragonfly);
    self->f34 = get_bml_model(TOBiwaMushi__shared_model_resource, 0);
    self->f24 = TObjFish__sub_8001EDB0(TOBiwaMushi__shared_model_resource, 0);
    self->fBC = get_bml_motion(TOBiwaMushi__shared_model_resource, 0);
    self->fB4 = (f32)self->fBC->frames - lbl_805DE068;
    self->fB8 = lbl_805DE06C;
    self->fC0 = lbl_805DE070;
    self->fC4 = self->f34->m->f14;
    self->fAC = 0;
    self->fF4 = lbl_805DE074 * self->f84 + lbl_805DE068;
    self->fF8 = lbl_805DE078 * (lbl_805DE07C / (lbl_805DE080 / self->fF4));
    self->fFC = lbl_805DE078 * (lbl_805DE07C * (lbl_805DE084 * rand()));
    self->fEC = lbl_805DE074 * self->f88 + lbl_805DE068;
    self->fF0 = self->fEC * sin_table_lookup(self->fFC);
    return arg0;
}
#undef self
#pragma pop
}

struct RecoveredGlobal_802AA644_lbl_804DDFE0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802AA644_lbl_804DDFE0_size[sizeof(RecoveredGlobal_802AA644_lbl_804DDFE0) == 0x10 ? 1 : -1];

extern "C" {
extern u32 TOMekaFish01__shared_model_resource;
void *TOMekaFish01__create(void *arg0);
void *__dt__12TOMekaFish01Fv(void *arg0, s16 arg1);
void *TOMekaFish01__ct(void *, void *);

void *TOMekaFish01__create(void *dragonfly) {
    void *o = __nw__7TObjectFUl(0x100);
    if (o != NULL) {
        o = TOMekaFish01__ct(o, dragonfly);
    }
    return o;
}

void TOMekaFish01::free_static_data() {
    if ((u32) TOMekaFish01__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOMekaFish01__shared_model_resource, 1);
        TOMekaFish01__shared_model_resource = 0U;
    }
}

extern s32 __vt__12TOMekaFish01[];

void TOMekaFish01::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TOMekaFish01__shared_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TOMekaFish01__shared_model_resource) = var_r0;
}

void *__dt__12TOMekaFish01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOMekaFish01;
        __dt__11TODragonflyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
struct VBase_802AA6EC { u8 pad[0x18]; };
struct Obj_802AA6EC : VBase_802AA6EC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4();
    virtual void m5(void *);
};

struct Model_802AA6EC { u8 pad[0x14]; f32 f14; };
struct ModelRef_802AA6EC { u8 pad[4]; Model_802AA6EC *m; };
struct Anim_802AA6EC { u8 pad[4]; u32 frames; };

struct Self_802AA6EC : Obj_802AA6EC {
    u8 pad1c[0x24 - 0x1c];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    ModelRef_802AA6EC *f34;
    u8 pad38[0x84 - 0x38];
    s32 f84;
    s32 f88;
    u8 pad8c[0xac - 0x8c];
    s32 fAC;
    u8 padb0[4];
    f32 fB4;
    f32 fB8;
    Anim_802AA6EC *fBC;
    f32 fC0;
    f32 fC4;
    u8 padc8[0xec - 0xc8];
    f32 fEC;
    f32 fF0;
    f32 fF4;
    s32 fF8;
    s32 fFC;
};

#define get_bml_motion ((Anim_802AA6EC * (*)(u32, s32))get_bml_motion)
#define get_bml_model ((ModelRef_802AA6EC * (*)(u32, s32))get_bml_model)
extern s32 TOMekaFish01__name;

#pragma fp_contract on
#define self ((Self_802AA6EC *)arg0)
void *TOMekaFish01__ct(void *arg0, void *dragonfly) {
    __ct__11TODragonflyFv(self, dragonfly);
    *(s32 **)((u8 *)self + 0x18) = __vt__12TOMekaFish01;
    *(s32 *)self = TOMekaFish01__name;
    self->m5(dragonfly);
    self->f34 = get_bml_model(TOMekaFish01__shared_model_resource, 0);
    self->f24 = TObjFish__sub_8001EDB0(TOMekaFish01__shared_model_resource, 0);
    self->fBC = get_bml_motion(TOMekaFish01__shared_model_resource, 0);
    self->fB4 = (f32)self->fBC->frames - lbl_805DE068;
    self->fB8 = lbl_805DE06C;
    self->fC0 = lbl_805DE070;
    self->fC4 = self->f34->m->f14;
    self->fAC = 0;
    self->fF4 = lbl_805DE074 * self->f84 + lbl_805DE068;
    self->fF8 = lbl_805DE078 * (lbl_805DE07C / (lbl_805DE080 / self->fF4));
    self->fFC = lbl_805DE078 * (lbl_805DE07C * (lbl_805DE084 * rand()));
    self->fEC = lbl_805DE074 * self->f88 + lbl_805DE068;
    self->fF0 = self->fEC * sin_table_lookup(self->fFC);
    return arg0;
}
#undef self
#pragma pop
#undef get_bml_motion
#undef get_bml_model
void *TOMekaFish00__create(void *arg0);
u8 *TOMekaFish00__ct(TOMekaFish00 *arg0, s32 arg1);

void *TOMekaFish00__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x100);
    if (o != NULL) {
        o = TOMekaFish00__ct((TOMekaFish00 *)((u8 *)o), (s32)arg0);
    }
    return o;
}

}

struct RecoveredGlobal_802AA934_lbl_804DDFC0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802AA934_lbl_804DDFC0_size[sizeof(RecoveredGlobal_802AA934_lbl_804DDFC0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802AA9DC___vt__12TOMekaFish00 { s32 value; u8 remaining[0x3C]; };

extern "C" {
extern u32 TOMekaFish00__model_resource;
#define get_bml_motion ((s32 (*)(void *, s32))get_bml_motion)
#define TObjFish__sub_8001EDB0 ((s32 (*)(void *, s32))TObjFish__sub_8001EDB0)
#define get_bml_model ((s32 (*)(void *, s32))get_bml_model)
#define __ct__11TODragonflyFv ((u8 * (*)(void *))__ct__11TODragonflyFv)
s32 rand(void);
extern s32 __vt__12TOMekaFish00[];
extern s32 TOMekaFish00__name;
void *__dt__12TOMekaFish00Fv(void *arg0, s16 arg1);

void TOMekaFish00::release_static_instance() {
    if ((u32) TOMekaFish00__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOMekaFish00__model_resource, 1);
        TOMekaFish00__model_resource = 0U;
    }
}

void TOMekaFish00::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TOMekaFish00__resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TOMekaFish00__model_resource) = var_r0;
}

void *__dt__12TOMekaFish00Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOMekaFish00;
        __dt__11TODragonflyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern u32 TBoss6PlotFalz__instance;

#pragma push
#pragma fp_contract on
u8 *TOMekaFish00__ct(TOMekaFish00 *meka_fish00, s32 arg1) {
    __ct__11TODragonflyFv(meka_fish00);
    *(s32 **)((s8 *)meka_fish00 + 0x18) = &(*(RecoveredGlobal_802AA9DC___vt__12TOMekaFish00 *)&__vt__12TOMekaFish00).value;
    *(s32 *)((s8 *)meka_fish00 + 0) = (s32) TOMekaFish00__name;
    ((TOMekaFish00 *)(meka_fish00))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)meka_fish00 + 0x34) = get_bml_model((*(u8 * *)&TOMekaFish00__model_resource), 0);
    meka_fish00->texlist = TObjFish__sub_8001EDB0((*(u8 * *)&TOMekaFish00__model_resource), 0);
    meka_fish00->m_bc = get_bml_motion((*(u8 * *)&TOMekaFish00__model_resource), 0);
    *(f32 *)((s8 *)meka_fish00 + 0xB4) = (f32) ((f32) *(u32 *)(meka_fish00->m_bc + 4) - lbl_805DE068);
    meka_fish00->m_b8 = (f32) lbl_805DE06C;
    meka_fish00->m_c0 = (f32) lbl_805DE070;
    *(f32 *)((s8 *)meka_fish00 + 0xC4) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)(*(s32 *)((s8 *)meka_fish00 + 0x34)) + 4)) + 0x14);
    meka_fish00->m_ac = 0;
    meka_fish00->m_f4 = (f32) ((lbl_805DE074 * (f32) meka_fish00->set_params[0]) + lbl_805DE068);
    meka_fish00->m_f8 = (s32) (lbl_805DE078 * (lbl_805DE07C / (lbl_805DE080 / meka_fish00->m_f4)));
    meka_fish00->m_fc = (s32) (lbl_805DE078 * (lbl_805DE07C * (lbl_805DE084 * (f32) rand())));
    meka_fish00->m_ec = (f32) ((lbl_805DE074 * (f32) *(s32 *)((s8 *)meka_fish00 + 0x88)) + lbl_805DE068);
    *(f32 *)((s8 *)meka_fish00 + 0xF0) = (f32) (meka_fish00->m_ec * sin_table_lookup(meka_fish00->m_fc));
    return (u8 *)meka_fish00;
}
#pragma pop

s32 TBoss6PlotFalz::is_phase_reached() {
    u32 p = TBoss6PlotFalz__instance;
    if (!p) {
        return 0;
    }
    return ((TObjFish *)TBoss6PlotFalz__instance)->get_phase() >= 7 ? 1 : 0;
}

#undef get_bml_motion
#undef TObjFish__sub_8001EDB0
#undef get_bml_model
#undef __ct__11TODragonflyFv
extern char lbl_8046FD7C[];
extern char lbl_8046FD8C[];
s32 TOMekaFish00__name = (s32)lbl_8046FD7C;
s32 TOMekaFish01__name = (s32)lbl_8046FD8C;
__declspec(section ".data") const char *bm_obj_meka_fish_0_model_names[2] = { lbl_8046FCB8, NULL };
__declspec(section ".data") const char *bm_obj_meka_fish_0_motion_names[2] = { lbl_8046FCC8, NULL };
BmlResourceDescriptor TOMekaFish00__resource_descriptor = { lbl_8046FCDC, bm_obj_meka_fish_0_model_names, bm_obj_meka_fish_0_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_obj_meka_fish_1_model_names[2] = { lbl_8046FCF4, NULL };
__declspec(section ".data") const char *bm_obj_meka_fish_1_motion_names[2] = { lbl_8046FD08, NULL };
BmlResourceDescriptor TOMekaFish01__shared_resource_descriptor = { lbl_8046FD1C, bm_obj_meka_fish_1_model_names, bm_obj_meka_fish_1_motion_names, 1, 1 };
}
