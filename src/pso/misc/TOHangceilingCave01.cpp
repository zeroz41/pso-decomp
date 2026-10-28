#include "types.h"
#include "pso/object/obj_band.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_804B1B80.h"
#include "pso/misc/TOHangceilingCave01KeyQuick.h"
#include "pso/misc/TOHangceilingCave01Key.h"
#include "pso/misc/TOHangceilingCave01Normal.h"
#include "pso/misc/TUnk_804B2578.h"
#include "pso/misc/TOHangceilingCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOFenceAncient01.h"
#include "pso/misc/TOFenceAncient04.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/map/CurrentArea.h"

struct RecoveredGlobal_80167878_lbl_804B1F80 {
    s32 value;
    u8 remaining[0x15C];
};

struct RecoveredGlobal_80167878___vt__16TOFenceAncient04 {
    s32 value;
    u8 remaining[0x44];
};

struct Inner_8016775C { u8 pad[0xC]; s32 f0C; };

struct Big_8016775C { u8 pad[0x42C]; Inner_8016775C *p; };

typedef char RecoveredGlobal_80167878_lbl_804B1F80_size[sizeof(RecoveredGlobal_80167878_lbl_804B1F80) == 0x160 ? 1 : -1];

typedef char RecoveredGlobal_80167878___vt__16TOFenceAncient04_size[sizeof(RecoveredGlobal_80167878___vt__16TOFenceAncient04) == 0x48 ? 1 : -1];

struct RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick {
    s32 value;
    u8 remaining[0x144];
};

typedef char RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick_size[sizeof(RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick) == 0x148 ? 1 : -1];

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
    virtual s32 m77();
};

struct Obj_80168010 : VObj_18 {
    u8 pad1C[0xA4 - 0x1C];
    u8 *fA4;
    u8 padA8[0xC0 - 0xA8];
    f32 fC0;
    f32 fC4;
    u8 padC8[0x326 - 0xC8];
    s16 state;
    u8 pad328[0x354 - 0x328];
    f32 f354;
};

struct Q_801681D0 { f32 w[4]; };

struct Obj_80168244 { u8 pad[0x33c]; u32 arr[4]; s32 count; };

struct Obj_80168280 { u8 pad[0x33c]; u32 arr[4]; s32 count; };

struct VB_80168488 { char pad[0x18]; };

struct VO_80168488 : VB_80168488 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, void *, s32, s32, s32);
    virtual void m22(); virtual void m23(); virtual void m24();
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
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78();
    virtual f32 m79(f32);
};

struct Pair_80168488 { s32 a; f32 b; };

struct Fish_801682E4 { u32 pad0; u32 f4; };

struct Obj_801682E4 { u8 pad0[0xC0]; f32 f0C0; f32 f0C4; f32 f0C8; u8 pad1[0x2C]; Fish_801682E4 *fish; u8 pad2[0x22A]; s16 mode; };
extern "C" {

s32 memset(void *, int, int);
s32 obj_setFlags30(void *, s32);
s32 get_current_floor();
void * get_bml_motion(s32, s32);
void TLobby__sub_8001FE7C(void*, int);
Big_8016775C * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void mem_free(void *p);
void *mem_alloc(u32 size);
void * __dt__27TOHangceilingCave01KeyQuickFv(void *arg0, s16 arg1);
u8 * TOHangceilingCave01KeyQuick__ct(u8 *arg0, s32 arg1);
void * __dt__22TOHangceilingCave01KeyFv(void *arg0, s16 arg1);
void * TOHangceilingCave01Key__ct(void *arg0);
void * __dt__25TOHangceilingCave01NormalFv(void *arg0, s16 arg1);
void * TOHangceilingCave01Normal__ct(void *arg0);
f32 TOHangceilingCave01Normal__sub_801681D0(f32 farg0);
void advance_wrap_offset__13TUnk_804B2578Fv(void *arg0);
void reset_state(u8 *arg0);
void sub_801682E4__13TUnk_804B2578Fl(Obj_801682E4 *o, s32 arg1);
void init_base__27TOHangceilingCave01KeyQuickFll(void *);
void set_scale__13TUnk_804B2578Ff(void *, f32);
void * get_player_by_client_id(s32);
u8 *load_gvm_texture_file(s32 arg0);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
u8 is_current_floor_switch_set(int);
}
void clear_current_floor_switch(s32 id);
extern "C" {
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);

extern s32 __vt__22TOHangceilingCave01Key[];
extern s32 __vt__25TOHangceilingCave01Normal[];
extern s32 __vt__27TOHangceilingCave01KeyQuick[];
extern void *TOHangceilingCave01Normal__class_name;
extern void *TOHangceilingCave01Key__class_name;
extern s32 TOHangceilingCave01KeyQuick__class_name;
extern s32 game_difficulty_selection;
extern s32 TOHangceilingCave01__model_archive;
extern s32 *turiten_singo_texture_lists;
extern s32 hanging_ceiling_motion_index;

extern void *tl_05;

extern const char lbl_804416F8[] = "fe_obj_turiten_kuro.gj";
extern const char lbl_80441710[] = "fe_obj_turiten_moto_taiki.gj";
extern const char lbl_80441730[] = "fs_obj_turiten_singo.gj";
extern const char lbl_80441748[] = "fe_obj_turiten_moto.njm";
extern const char lbl_80441760[] = "fe_obj_turiten_moto_taiki.njm";
extern const char lbl_80441780[] = "fe_obj_turiten_moto.bml";
extern const char lbl_80441798[] = "fe_obj_gc_turiten_moto.gj";
extern const char lbl_804417B4[] = "fe_obj_gc_turiten_moto.njm";
extern const char lbl_804417D0[] = "bm_obj_ruins_turiten.bml";
__declspec(section ".rodata") extern Q_801681D0 hang_ceiling_cave_scale_params = { 1.0f, 2.0f, 3.0f, 6.0f };
extern const char lbl_804417FC[] = "TOHangceilingCave01Normal";
extern const char lbl_80441818[] = "TOHangceilingCave01Key";
extern const char TOHangceilingCave01KeyQuick__class_name_string[] = "TOHangceilingCave01KeyQuick";

void TOHangceilingCave01KeyQuick::vfunc_79() {
    u8 *p;

    this->texlist = turiten_singo_texture_lists[1];
    *(void * *)&this->unknownF8 = get_bml_motion(TOHangceilingCave01__model_archive, 1);
    *(f32 *)&this->unk_354 = 0.0f;
    ((s32 (*)(void *, int))sub_801682E4__13TUnk_804B2578Fl)(this, 3);
    p = *(u8 * *)&this->bodies;
    *(s32 *)((s8 *)p + 0x18) &= ~8;
    this->m_c0 = 0.0f;
    this->m_c8 = 1.0f;
    *(f32 *)&this->unk_C4 = (f32) *(u32 *)((s8 *)(*(u8 * *)&this->unknownF8) + 4) - 1.0f;
    ((s32 (*)(void *))reset_state)(this);
}

static const s32 hang_flag_8[1] = { 8 };

void TOHangceilingCave01KeyQuick::vfunc_80() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u8 *temp_r3;
    u8 *temp_r4;
    switch (this->mode) {
    case 3:
        if ((is_current_floor_switch_set((int) ((u16) *(s32 *)&this->unk_35C)) == 1) && (this->m_c0 <= *(f32 *)&this->unk_C4)) {
            ((s32 (*)(void *, int))sub_801682E4__13TUnk_804B2578Fl)(arg0, 2);
        }
        ((s32 (*)(void *))advance_wrap_offset__13TUnk_804B2578Fv)(arg0);
        return;
    case 1:
        ((s32 (*)(void *))advance_wrap_offset__13TUnk_804B2578Fv)(arg0);
        ((TUnk_804B2578 *)arg0)->sub_80168488();
        if (4.0f < this->m_c0) {
            temp_r3 = (u8 *)(*(u8 * *)&this->bodies);
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFF7);
        }
        if (23.0f == this->m_c0) {
            ((TOHangceilingCave01KeyQuick *)(arg0))->vfunc_79();
        }
        break;
    case 2:
        if (is_current_floor_switch_set((int) ((u16) *(s32 *)&this->unk_35C)) == 1) {
            if (0.0f != this->m_c0) {
                ((s32 (*)(void *))advance_wrap_offset__13TUnk_804B2578Fv)(arg0);
            }
            if (5e+01f == this->m_c0) {
                temp_r4 = (u8 *)(*(u8 * *)&this->bodies);
                *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) | hang_flag_8[0]);
                return;
            }
        } else {
            if ((85.0f <= this->m_c0) && (this->m_c0 <= *(f32 *)&this->unk_C4)) {
                this->m_c0 = (f32) 0.0f;
            } else if (77.0f <= this->m_c0) {
                this->m_c0 = (f32) 1.0f;
            } else if (73.0f <= this->m_c0) {
                this->m_c0 = (f32) 2.0f;
            } else if (65.0f <= this->m_c0) {
                this->m_c0 = (f32) 3.0f;
            } else if (53.0f <= this->m_c0) {
                this->m_c0 = (f32) 4.0f;
            } else {
                this->m_c0 = (f32) 5.0f;
            }
            ((s32 (*)(void *, int))sub_801682E4__13TUnk_804B2578Fl)(arg0, 1);
        }
        break;
    }
}

void *__dt__27TOHangceilingCave01KeyQuickFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__27TOHangceilingCave01KeyQuick;
        ((TOHangceilingCave01KeyQuick *)arg0)->destroy_hanging_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TOHangceilingCave01KeyQuick__ct(u8 *arg0, s32 arg1) {
    ((u8 * (*)(void *, s32))init_base__27TOHangceilingCave01KeyQuickFll)(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80167C78___vt__27TOHangceilingCave01KeyQuick *)&__vt__27TOHangceilingCave01KeyQuick).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOHangceilingCave01KeyQuick__class_name;
    ((TUnk_804B2578 *)arg0)->init_geometry();
    set_scale__13TUnk_804B2578Ff(arg0, 1e+02f + *(f32 *)((s8 *)arg0 + 0x70));
    return arg0;
}

void TOHangceilingCave01Key::vfunc_79() {
    u8 *p;

    this->texlist = turiten_singo_texture_lists[1];
    *(void * *)&this->unknownF8 = get_bml_motion(TOHangceilingCave01__model_archive, 1);
    *(f32 *)&this->unk_354 = 0.0f;
    ((s32 (*)(void *, int))sub_801682E4__13TUnk_804B2578Fl)(this, 3);
    p = *(u8 * *)&this->bodies;
    *(s32 *)((s8 *)p + 0x18) &= ~8;
    this->m_c0 = 0.0f;
    this->m_c8 = 1.0f;
    *(f32 *)&this->unk_C4 = (f32) *(u32 *)((s8 *)(*(u8 * *)&this->unknownF8) + 4) - 1.0f;
    ((s32 (*)(void *))reset_state)(this);
}

void TOHangceilingCave01Key::vfunc_80() {
    u8 *arg0 = (u8 *)this;
    switch (*(s16 *)(arg0 + 0x326)) {
    case 3:
        if (is_current_floor_switch_set((u16)*(s32 *)(arg0 + 0x35C)) == 1 && *(f32 *)(arg0 + 0xC0) <= *(f32 *)(arg0 + 0xC4)) {
            ((s32 (*)(void *, int))sub_801682E4__13TUnk_804B2578Fl)(arg0, 2);
        }
        ((s32 (*)(void *))advance_wrap_offset__13TUnk_804B2578Fv)(arg0);
        break;
    case 1:
        ((s32 (*)(void *))advance_wrap_offset__13TUnk_804B2578Fv)(arg0);
        ((TUnk_804B2578 *)arg0)->sub_80168488();
        if (4.0f == *(f32 *)(arg0 + 0xC0)) {
            *(s32 *)(*(u8 **)(arg0 + 0xA4) + 0x18) &= ~8;
        } else if (23.0f == *(f32 *)(arg0 + 0xC0)) {
            ((TOHangceilingCave01Key *)(arg0))->vfunc_79();
            clear_current_floor_switch((u16)*(s32 *)(arg0 + 0x35C));
        }
        break;
    case 2:
        ((s32 (*)(void *))advance_wrap_offset__13TUnk_804B2578Fv)(arg0);
        if (5e+01f == *(f32 *)(arg0 + 0xC0)) {
            *(s32 *)(*(u8 **)(arg0 + 0xA4) + 0x18) |= hang_flag_8[0];
        } else if (*(f32 *)(arg0 + 0xC0) == *(f32 *)(arg0 + 0xC4)) {
            ((s32 (*)(void *, int))sub_801682E4__13TUnk_804B2578Fl)(arg0, 1);
        }
        break;
    }
}

void *__dt__22TOHangceilingCave01KeyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TOHangceilingCave01Key;
        ((TOHangceilingCave01KeyQuick *)arg0)->destroy_hanging_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOHangceilingCave01Key__ct(void *arg0) {
    init_base__27TOHangceilingCave01KeyQuickFll(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TOHangceilingCave01Key;
    *(void * *)&((TOHangceilingCave01Key *)arg0)->m_name = TOHangceilingCave01Key__class_name;
    ((TUnk_804B2578 *)arg0)->init_geometry();
    return arg0;
}

void TOHangceilingCave01Normal::vfunc_79() {
    void *temp_r6;
    union { f64 d; u32 i[2]; } cvt;

    s32 *p;
    *(void * *)&this->unknownF8 = get_bml_motion(TOHangceilingCave01__model_archive, hanging_ceiling_motion_index);
    p = turiten_singo_texture_lists;
    this->texlist = (s32) *p;
    *(f32 *)&this->unk_354 = (f32) (4.0f * this->m_350);
    ((s32 (*)(void *, s32, s32 *, f32))sub_801682E4__13TUnk_804B2578Fl)(this, 0, p, 4.0f);
    temp_r6 = this->bodies;
    *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) | hang_flag_8[0]);
    this->m_c0 = (f32) 0.0f;
    this->m_c8 = (f32) 1.0f;
    *(f32 *)&this->unk_C4 = (f32) *(u32 *)((s8 *)(*(void * *)&this->unknownF8) + 4) - 1.0f;
}

void TOHangceilingCave01Normal::vfunc_80() {
    Obj_80168010 *arg0 = (Obj_80168010 *)this;
    switch (arg0->state) {
    case 0:
        if (0.0f < arg0->f354) {
            arg0->f354 = arg0->f354 - 1.0f;
            return;
        }
        ((s32 (*)(void *, int)) sub_801682E4__13TUnk_804B2578Fl)(arg0, 1);
        ((s32 (*)(void *))reset_state)(arg0);
        return;
    case 1:
        ((s32 (*)(void))advance_wrap_offset__13TUnk_804B2578Fv)();
        ((TUnk_804B2578 *)arg0)->sub_80168488();
        if (4.0f == arg0->fC0) {
            *(s32 *)((s8 *)arg0->fA4 + 0x18) &= ~8;
            return;
        }
        if (23.0f == arg0->fC0) {
            ((s32 (*)(void *, int)) sub_801682E4__13TUnk_804B2578Fl)(arg0, 2);
        }
        return;
    case 2:
        ((s32 (*)(void))advance_wrap_offset__13TUnk_804B2578Fv)();
        if (5e+01f == arg0->fC0) {
            *(s32 *)((s8 *)arg0->fA4 + 0x18) |= hang_flag_8[0];
            return;
        }
        if (arg0->fC0 == arg0->fC4) {
            arg0->m77();
        }
        break;
    }
}

void *__dt__25TOHangceilingCave01NormalFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__25TOHangceilingCave01Normal;
        ((TOHangceilingCave01KeyQuick *)arg0)->destroy_hanging_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOHangceilingCave01Normal__ct(void *arg0) {
    init_base__27TOHangceilingCave01KeyQuickFll(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__25TOHangceilingCave01Normal;
    *(void * *)&((TOHangceilingCave01Normal *)arg0)->m_name = TOHangceilingCave01Normal__class_name;
    ((TUnk_804B2578 *)arg0)->init_geometry();
    return arg0;
}

f32 TOHangceilingCave01Normal__sub_801681D0(f32 farg0) {
    Q_801681D0 q = hang_ceiling_cave_scale_params;
    return farg0 * q.w[game_difficulty_selection];
}

void TUnk_804B2578::advance_wrap_offset() {
    this->m_c0 = (f32) (this->m_c0 + this->m_c8);
    if (*(f32 *)&this->unk_C4 < this->m_c0) {
        this->m_c0 = (f32) (0.0f);
    }
}

s32 TUnk_804B2578::sub_80168244(u32 v) {
    s32 i;
    for (i = 0; i != ((Obj_80168244 *)this)->count; i++) {
        if (((Obj_80168244 *)this)->arr[i] == v) {
            return 1;
        }
    }
    return 0;
}

void TUnk_804B2578::sub_80168280(u32 v) {
    Obj_80168280 *self = (Obj_80168280 *)this;
    if (this->m_34c < 4) {
        self->arr[this->m_34c++] = v;
    }
}

void reset_state(u8 *arg0) {
    memset(arg0 + 0x33C, 0, 0x10);
    ((TUnk_804B2578 *)arg0)->m_34c = 0;
}

void TUnk_804B2578::sub_801682E4(s32 arg1) {
    s16 sp8;
    if (arg1 != this->mode) {
        this->mode = arg1;
        if (access_object_saved_state(&sp8, 1) != 0) {
            sp8 = this->mode;
        }
        switch (this->mode) {
        case 0:
        case 1:
            break;
        case 2:
            ((Obj_801682E4 *)this)->fish = ((Fish_801682E4 * (*)(s32, s32))get_bml_motion)(TOHangceilingCave01__model_archive, hanging_ceiling_motion_index);
            ((Obj_801682E4 *)this)->f0C0 = 22.0f;
            ((Obj_801682E4 *)this)->f0C8 = 1.0f;
            ((Obj_801682E4 *)this)->f0C4 = (f32)((Obj_801682E4 *)this)->fish->f4 - 1.0f;
            break;
        }
    }
}

void TUnk_804B2578::sub_80168398() {
    s32 state = get_current_area();
    s32 id = 0;
    switch (this->mode) {
    case 2:
        switch (state) {
        case 0x13:
        case 0x14:
            id = 0x4BC11;
            break;
        case 0x15:
        case 0x16:
            id = 0x4004BC11;
            break;
        default:
            id = 0x43C18;
            break;
        }
        break;
    case 1:
        switch (state) {
        case 0x13:
        case 0x14:
            id = 0x4B212;
            break;
        case 0x15:
        case 0x16:
            id = 0x4004B212;
            break;
        default:
            id = 0x4321A;
            break;
        }
        break;
    }
    if (id != 0) {
        play_persistent_sound((s32)id, (s32)this, (u32)(((u8 *)this) + 0x38), 0, 0);
    }
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
static inline void hit_80168488(VO_80168488 *o, VO_80168488 *a, Pair_80168488 p) { o->m21(a, &p, 0, -1, -1); }
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TUnk_804B2578::sub_80168488() {
    s32 var_r30;
    VO_80168488 *temp_r3;
    var_r30 = 0;
    do {
        temp_r3 = (VO_80168488 *)get_player_by_client_id(var_r30);
        if ((temp_r3 != NULL) && (sub_80168244((u32)temp_r3) == 0)) {
            if ((((TObjPlayer *)temp_r3)->get_field_3e4() == get_current_floor()) && (check_actor_body_contact(temp_r3, 1e+02f) != 0U)) {
                Pair_80168488 t;
                t.a = 0;
                t.b = ((VO_80168488 *)this)->m79(this->m_338);
                hit_80168488(temp_r3, ((VO_80168488 *)this), t);
                obj_setFlags30(temp_r3, 0x400);
                sub_80168280((u32)temp_r3);
            }
        }
        var_r30 += 1;
    } while (var_r30 != 0xC);
}
#pragma pop

s32 TOHangceilingCave01__create(u8 *arg0);
bool sub_801688C0__13TUnk_804B2578Fv(u8 *arg0);
s32 push_matrix(void);
s32 pop_matrix(void);
f32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
void draw_ginja_object(void *child);
void draw_ginja_model(s32 model);
s32 draw_ginja_model_with_motion(void *, void *, f32);
extern u8 *TOHangceilingCave01__model_root;
struct VBase_80168588 { char pad[0x18]; };
struct VObj_80168588 : VBase_80168588 {
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
    virtual void v76(); virtual void v77();
};
struct VBase_18_26a62c { char pad[0x18]; };
struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

bool sub_801688C0__13TUnk_804B2578Fv(u8 *);
void *spawn_particle_effect(void *pos, s32 id);
f32 xz_distance_squared(void *, void *);
s32 transform_point_by_current_matrix(void *, void *);
extern s32 camera_ctrl_instance;

void TUnk_804B2578::init_geometry() {
    f32 temp_f2;
    VObj_80168588 *self = (VObj_80168588 *)this;

    *(s32 *)((s8 *)this + 0x35C) = (s32) this->set_params[0];
    this->m_358 = (u32) this->set_params[2];
    if ((u32) this->m_358 >= 3U) {
        this->m_358 = 2U;
    }
    temp_f2 = 3e+01f + this->scale.x;
    this->m_350 = (f32) (temp_f2 - 1.0f);
    ((void (*)(void *, f32, f32))set_scale__13TUnk_804B2578Ff)(this, 1e+02f + this->scale.z, temp_f2);
    self->v77();
    *(f32 *)&this->unk_354 = (f32) (1.0f - this->scale.y);
}

int TUnk_804B2578::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TUnk_804B2578::receive_weapon_special_attack(void *, void *) {
    return 0.0f;
}

f32 TUnk_804B2578::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return 0.0f;
}

void TUnk_804B2578::vfunc_80() {  }
void TUnk_804B2578::vfunc_79() {  }

void TUnk_804B2578::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f2;
    s32 temp_r29;
    s32 temp_r30;
    s32 temp_r31;
    if ((((s32 (*)(u8 *))sub_801688C0__13TUnk_804B2578Fv)(arg0) != 0) || (TObjPlayer::check_demo_mode() == 1)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(*(s32 *)((s8 *)turiten_singo_texture_lists + 8));
        if (this->model != NULL && this->unknownF8 != NULL) {
            draw_ginja_model_with_motion(*(void * *)&this->model, *(void * *)&this->unknownF8, this->m_c0);
        }
        if ((void *) TOHangceilingCave01__model_root != NULL) {
            TParticleCtrl::begin_effect_render();
            if ((u32) this->m_358 == 0U) {
                temp_f2 = *(f32 *)&this->unk_354;
                temp_f1 = this->m_350;
                temp_r29 = temp_f2 <= temp_f1;
                temp_r30 = temp_f2 <= (2.0f * temp_f1);
                temp_r31 = temp_f2 <= (3.0f * temp_f1);
                TObjFish::set_global_param(*(s32 *)((s8 *)turiten_singo_texture_lists + 4));
                if (temp_r29 == 1) {
                    draw_ginja_model((*(s32 *)((s8 *)(*(u8 **)((s8 *)TOHangceilingCave01__model_root + 0x2C)) + 4)));
                }
                if (temp_r30 == 1) {
                    draw_ginja_model((*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)TOHangceilingCave01__model_root + 0x2C)) + 0x2C)) + 4)));
                }
                if (temp_r31 == 1) {
                    draw_ginja_model((*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)TOHangceilingCave01__model_root + 0x2C)) + 0x2C)) + 0x2C)) + 4)));
                }
                TObjFish::set_global_param(*(s32 *)((s8 *)turiten_singo_texture_lists + 0));
                if (temp_r29 == 0) {
                    draw_ginja_model((*(s32 *)((s8 *)(*(u8 **)((s8 *)TOHangceilingCave01__model_root + 0x2C)) + 4)));
                }
                if (temp_r30 == 0) {
                    draw_ginja_model((*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)TOHangceilingCave01__model_root + 0x2C)) + 0x2C)) + 4)));
                }
                if (temp_r31 == 0) {
                    draw_ginja_model((*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)TOHangceilingCave01__model_root + 0x2C)) + 0x2C)) + 0x2C)) + 4)));
                }
            } else {
                if (is_current_floor_switch_set((int) ((u16) *(s32 *)((s8 *)arg0 + 0x35C))) == 1) {
                    TObjFish::set_global_param(*(s32 *)((s8 *)turiten_singo_texture_lists + 0));
                } else {
                    TObjFish::set_global_param(*(s32 *)((s8 *)turiten_singo_texture_lists + 4));
                }
                draw_ginja_object((TOHangceilingCave01__model_root));
            }
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void TUnk_804B2578::run_task() {
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() == 0) {
        this->vfunc_80();
        ((TUnk_804B2578 *)arg0)->sub_80168398();
        if ((((s32 (*)(void *))sub_801688C0__13TUnk_804B2578Fv)(arg0) != 0) && ((s16) this->mode != 3) && (objInBand((GameObj *)arg0, (f32)8.0f) != 0)) {
            spawn_particle_effect(&this->position, 0x64);
        }
    }
}

bool TUnk_804B2578::sub_801688C0() {
    f32 sp8[3];
    u8 *arg0 = (u8 *)this;

    if (xz_distance_squared((void *)(arg0 + 0x38), (void *)(camera_ctrl_instance + 0x178)) < 2.5e+03f) {
        ((TUnk_804B2578 *)arg0)->visibility = 1;
        return 1;
    }
    if (((VObj_18_26a62c *)(arg0))->m8(3e+02f, 5e+01f) == 0) {
        return 0;
    }
    transform_point_by_current_matrix((u8 *)&this->position, (void *) sp8);
    return (sp8[2] > (-35.0f)) == 0;
}

s32 TOHangceilingCave01__create(u8 *arg0) {
  s32 temp_r3;
  s32 temp_r3_2;
  s32 temp_r3_3;
  s32 var_r0;
  s32 var_r0_2;
  s32 var_r0_3;
  if (arg0 != 0)
  {
    switch (*((s32 *) (((s8 *) arg0) + 0x38)))
    {
      case 0:
        temp_r3 = ((s32 (*)(int))__nw__7TObjectFUl)(0x360);
        var_r0 = temp_r3;
        if (var_r0 != 0)
      {
        var_r0 = ((s32 (*)(int, int, void *))TOHangceilingCave01Normal__ct)((int) temp_r3, (int) tl_05, (void *) arg0);
      }
        return var_r0;
      case 1:
        temp_r3_2 = ((s32 (*)(int))__nw__7TObjectFUl)(0x360);
        var_r0_2 = temp_r3_2;
        if (var_r0_2 != 0)
      {
        var_r0_2 = ((s32 (*)(int, int, void *))TOHangceilingCave01Key__ct)((int) temp_r3_2, (int) tl_05, (void *) arg0);
      }
        return var_r0_2;
      case 2:
        temp_r3_3 = ((s32 (*)(int))__nw__7TObjectFUl)(0x360);
        var_r0_3 = temp_r3_3;
        if (var_r0_3 != 0)
      {
        var_r0_3 = ((s32 (*)(int, int, void *))TOHangceilingCave01KeyQuick__ct)((int) temp_r3_3, (int) tl_05, (void *) arg0);
      }
        return var_r0_3;
    }
  }
  else
  {
  }
  return 0;
}

void TOHangceilingCave01::destroy_instance() {
    if ((void *) turiten_singo_texture_lists != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)turiten_singo_texture_lists + 4));
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)turiten_singo_texture_lists + 0));
        if ((void *) turiten_singo_texture_lists != NULL) {
            mem_free(turiten_singo_texture_lists);
            turiten_singo_texture_lists = NULL;
        }
    }
    if ((u32) TOHangceilingCave01__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOHangceilingCave01__model_archive, 1);
        TOHangceilingCave01__model_archive = 0U;
    }
}

struct Buf_80168AA8 { s32 a; s32 b; s32 c; };
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
}
extern u8 fe_obj_turiten_moto_resource_descriptor[];
extern u8 turiten_singo_resource_descriptor[];
extern s32 lbl_805D59D8;
extern s32 turiten_singo_key_model_index;

extern const char lbl_80441858[] = "fs_obj_turiten_singo.gvm";
extern const char lbl_80441874[] = "fs_obj_turiten_singo_r.gvm";

void load_turiten_singo_resources(void) {
    void *p;

    (*(void **)&TOHangceilingCave01__model_archive) = 0;
    (*(Buf_80168AA8 **)&turiten_singo_texture_lists) = 0;
    switch (get_current_area()) {
    case 19:
    case 20:
        p = ::operator new(0x440);
        if (p != 0) {
            p = ((void *(*)(void *, int, void *, int, int, int))load_resource_from_descriptor)(p, 5, turiten_singo_resource_descriptor, 0, 0, 0);
        }
        (*(void **)&TOHangceilingCave01__model_archive) = p;
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists) = (Buf_80168AA8 *)mem_alloc(0xC);
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists)->b = 0;
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists)->a = 0;
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists)->c = TObjFish__sub_8001EDB0((*(void **)&TOHangceilingCave01__model_archive), 0);
        lbl_805D59D8 = 0;
        (*(s32 *)&TOHangceilingCave01__model_root) = 0;
        turiten_singo_key_model_index = 0;
        hanging_ceiling_motion_index = 0;
        break;
    default:
        p = ::operator new(0x440);
        if (p != 0) {
            p = ((void *(*)(void *, int, void *, int, int, int))load_resource_from_descriptor)(p, 5, fe_obj_turiten_moto_resource_descriptor, 0, 0, 0);
        }
        (*(void **)&TOHangceilingCave01__model_archive) = p;
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists) = (Buf_80168AA8 *)mem_alloc(0xC);
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists)->a = (s32)load_gvm_texture_file((s32)lbl_80441858);
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists)->b = (s32)load_gvm_texture_file((s32)lbl_80441874);
        (*(Buf_80168AA8 **)&turiten_singo_texture_lists)->c = TObjFish__sub_8001EDB0((*(void **)&TOHangceilingCave01__model_archive), 1);
        (*(s32 *)&TOHangceilingCave01__model_root) = get_bml_model((*(void **)&TOHangceilingCave01__model_archive), 2);
        turiten_singo_key_model_index = 1;
        hanging_ceiling_motion_index = 0;
        break;
    }
}

struct RecoveredGlobal_80168C6C_lbl_804B2174 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80168C6C_lbl_804B2578 {
    s32 value;
    u8 remaining[0x144];
};

extern "C" {
s32 __ct__13TUnk_804806E8FP7TObject(void *);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_80168C6C_lbl_804B2174 lbl_804B2174;
extern s32 lbl_804B2578[];
extern s32 TOHangceilingCave01__model_archive;
extern s32 turiten_singo_key_model_index;
extern s32 hanging_ceiling_motion_index;
s32 free_collision_body_parts(void *);

void *TOHangceilingCave01KeyQuick::destroy_hanging_object(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B2578;
        this->unregister_object_by_id();
        free_collision_body_parts(this);
        this->destroy_motion_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

typedef char RecoveredGlobal_80168C6C_lbl_804B2174_size[sizeof(RecoveredGlobal_80168C6C_lbl_804B2174) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80168C6C_lbl_804B2578_size[sizeof(RecoveredGlobal_80168C6C_lbl_804B2578) == 0x148 ? 1 : -1];
u8 *TOHangceilingCave01KeyQuick::init_base(s32 arg1, s32 arg2) {
    u8 *temp_r4;
    __ct__13TUnk_804806E8FP7TObject(this);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_80168C6C_lbl_804B2578 *)&lbl_804B2578).value;
    this->apply_object_set_data((void *)arg2);
    *(s32 *)&this->model = get_bml_model((void *)TOHangceilingCave01__model_archive, turiten_singo_key_model_index);
    this->unknownF8 = (u32)get_bml_motion(TOHangceilingCave01__model_archive, hanging_ceiling_motion_index);
    init_collision_body_parts(this, &lbl_804B2174.value, 1);
    this->refresh_collision_body_centers();
    ((TObjPlayer *)((u8 *)this))->register_object_by_id();
    reset_state((((u8 *)this)));
    temp_r4 = (u8 *)this->bodies;
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) | 0x1080);
    return ((u8 *)this);
}

s32 TUnk_804B2578::select_melee_contact_body(void *, f32) { return 1; }

f32 TUnk_804B2578::receive_physical_attack(void *, f32) {
    return 0.0f;
}

void TUnk_804B2578::apply_knockback_from_attacker(u8 *) {  }

void TUnk_804B2578::set_scale(f32 v) { this->m_338 = v; }

}
