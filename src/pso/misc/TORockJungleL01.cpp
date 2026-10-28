#include "types.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TORockJungleL01.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/map/CurrentArea.h"

struct Base_8029c054_8029C030 { char pad[0x14]; };
struct VObj_8029c054_8029C030 : Base_8029c054_8029C030 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct VBase_8029C094 { char pad[0x14]; };

struct VObj_8029C094 : VBase_8029C094 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Vec_8029C094 { f32 x, y, z; };

struct Rd_8029C094 {
    u8 pad0[0x38];
    u8 pos[0xB4 - 0x38];
    VObj_8029C094 fade;
    u8 padd[0xD0 - 0xB4 - sizeof(VObj_8029C094)];
    s32 fading;
};

extern "C" {
s32 isFading__15RenderFadeStateCFv(void *);
void matrix_mult_vec(s32, void *, void *);

int update_obstruction_fade(void*);

void TORockJungleL01::run_task() { update_obstruction_fade((char*)this + 0xb4); }

void TORockJungleL01::vfunc_15() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_d0 != 0) {
        ((VObj_8029c054_8029C030*)(arg0 + 0xB4))->m7();
    }
    TObjFish::set_cull_none();
}
void TORockJungleL01::vfunc_14() {
    Rd_8029C094 *arg0 = (Rd_8029C094 *)this;
    Vec_8029C094 v;
    TObjFish::set_cull_back();
    matrix_mult_vec(0, arg0->pos, &v);
    if (-v.z < 38.0f) {
        ((RenderFadeState *)(&arg0->fade))->fadeOut();
    } else {
        ((RenderFadeState *)(&arg0->fade))->restore();
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        arg0->fading = 0;
    } else {
        arg0->fading = isFading__15RenderFadeStateCFv(&arg0->fade);
    }
    if (arg0->fading != 0) {
        arg0->fade.m6();
    }
}

}

#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800D7BFC.h"
#include "pso/unk/text_8029C214.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TORockJungleL01.h"

extern "C" {

void __dl__7TObjectFPv(void *);
void *__dt__10TORockCaveFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
void free_collision_body_parts(void *);

void *TORockJungleL01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TORockJungleL01__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

extern void *lbl_804DC448[];

void *TORockJungleL01::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = (s32 *)lbl_804DC448;
        if (*(void * *)&this->m_d4 != NULL) { queue_destruction__7TObjectFv(*(void * *)&this->m_d4); *(s32 *)&this->m_d4 = 0; }
        unregister_object_by_id();
        free_collision_body_parts(this);
        __dt__13TUnk_804949A8Fv((s8 *)this + 0xB4, -1);
        __dt__10TORockCaveFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}

#include "types.h"
#include "pso/TObject.h"
#include "pso/misc/TORockCave.h"
#include "pso/unk/text_8029C214.h"
#include "pso/misc/TORockJungleL01.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TORockJungleS01.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Inner_8029C214 { u8 pad[0x58]; s32 v; };

struct Copy_8029C214 { u32 w[15]; };

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void *__ct__10TORockCaveFv(void *arg0);
extern "C" void vfunc_15__15TORockJungleL01Fv();
extern "C" void vfunc_14__15TORockJungleL01Fv();
extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void draw_model__10TORockCaveFv();
extern "C" void run_task__15TORockJungleL01Fv();
extern "C" void interact__13TUnk_804AF8A0Fl();
extern "C" void get_name__13TUnk_804B9870Fv();
extern "C" void get_center__13TUnk_804B9870Fv();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void destroy__15TORockJungleL01Fs();
extern "C" u8 lbl_80465788[];
extern "C" u8 lbl_8046579C[];
extern "C" u8 lbl_804657B4[];
extern "C" u8 lbl_804657C8[];
extern "C" u8 lbl_804657E0[];
extern "C" u8 lbl_804657F4[];
extern "C" u8 bm_o_rock_jungle_motion_names[];
extern "C" void reset_motion_fields__13TUnk_804AF8A0Fv();
extern "C" void render_shadows__7TObjectFv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern void *bm_o_rock_jungle_model_names[6];
extern s32 TORockJungleL01_name_ref;

void *bm_o_rock_jungle_model_names[6] = {
    (void *)&lbl_80465788, (void *)&lbl_8046579C, (void *)&lbl_804657B4, (void *)&lbl_804657C8,
    (void *)&lbl_804657E0, (void *)0x0,
};
void *TORockJungleS01_resource_descriptor[4] = {
    (void *)&lbl_804657F4, (void *)&bm_o_rock_jungle_model_names, (void *)&bm_o_rock_jungle_motion_names, (void *)0x50000,
};
void *rock_jungle_collision_body_parts[33] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x40a00000,
    (void *)0x0, (void *)0x0, (void *)0x10003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41000000, (void *)0x41400000,
    (void *)0x1, (void *)0x10003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x41a00000, (void *)0x1,
    (void *)0x10003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *rock_jungle_vec3_table[9] = {
    (void *)0x42000000, (void *)0x41a00000, (void *)0x41400000, (void *)0x42000000,
    (void *)0x41a00000, (void *)0x41400000, (void *)0x42000000, (void *)0x41a00000,
    (void *)0x41400000,
};
void *lbl_804DC448[16] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__15TORockJungleL01Fs, (void *)&run_task__15TORockJungleL01Fv,
    (void *)&draw_model__10TORockCaveFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804AF8A0Fv, (void *)&get_center__13TUnk_804B9870Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__13TUnk_804B9870Fv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&vfunc_14__15TORockJungleL01Fv, (void *)&vfunc_15__15TORockJungleL01Fv,
};
#define rock_jungle_collision_body_parts (*(Inner_8029C214 *)rock_jungle_collision_body_parts)
u8 *TORockJungleL01__ct(u8 *rock_cave, s32 arg1) {
    __ct__10TORockCaveFv(rock_cave);
    *(s32 **)((s8 *)rock_cave + 0x18) = (s32 *)lbl_804DC448;
    ((TObjPlayer *)(rock_cave + 0xB4))->init_and_activate();
    *(s32 *)((s8 *)rock_cave + 0) = TORockJungleL01_name_ref;
    ((TORockJungleL01 *)(rock_cave))->apply_object_set_data((void *)arg1);
    ((TORockJungleL01 *)rock_cave)->model = TORockJungleS01::get_model(4);
    ((TORockJungleL01 *)rock_cave)->texlist = get_jungle_rock_texture_resource(4);
    ((TORockJungleL01 *)rock_cave)->m_b0 = 5e+01f + *(f32 *)((s8 *)(*(void **)((s8 *)(((TORockJungleL01 *)rock_cave)->model) + 4)) + 0x14);
    ((s32 (*)(void *, void *, int, f32))init_collision_body_parts)(rock_cave, &rock_jungle_collision_body_parts.v, 1, 5e+01f);
    ((TUnk_804AF8A0 *)rock_cave)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_cave)->register_object_by_id();
    {
        Copy_8029C214 c = *(Copy_8029C214 *)arg1;
        VecCopy((Vec *)((u8 *)&c + 0x24), (const Vec *)rock_jungle_vec3_table);
        ((TORockJungleL01 *)rock_cave)->m_d4 = TObjMapCsn::create((s32)&c);
    }
    ((TObjPlayer *)(rock_cave + 0xB4))->activate_and_dispatch();
    return rock_cave;
}
#undef rock_jungle_collision_body_parts

}

#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800D7BFC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TORockCaveBrakable.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TORockJungleM01.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TORockJungleS01.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"

struct Base_8029C320 { char pad[0x14]; };
struct VObj_8029C320 : Base_8029C320 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_3C { u8 bytes[0x3C]; };

struct RecoveredGlobal_8029C588_lbl_804DC3A0 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_8029C588_lbl_804DC424 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_8029C588___vt__15TORockJungleM01 {
    s32 value;
    u8 remaining[0x4C];
};

struct VBase_8029C6FC { char pad[0x14]; };

struct VObj_8029C6FC : VBase_8029C6FC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct Vec_8029C6FC { f32 x, y, z; };

struct Rd_8029C6FC {
    u8 pad0[0x38];
    u8 pos[0xBC - 0x38];
    VObj_8029C6FC fade;
    u8 padd[0xD8 - 0xBC - sizeof(VObj_8029C6FC)];
    s32 fading;
};

struct Vec_8029C390 { f32 x, y, z; };

struct ChipParam_8029C390 {
    u32 x00;
    u32 x04;
    u32 x08;
    Vec_8029C390 pos;
    u8 pad18[0x20];
    f32 y2;
    u32 pad3C;
    s32 res;
    s32 res2;
    u32 x48;
};

struct Offs_8029C390 { Vec_8029C390 v[1]; };

struct Rock_8029C390 {
    u8 pad[0x38];
    Vec_8029C390 pos;
    u8 pad44[0x60 - 0x44];
    s32 x60;
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void *TORockCaveBrakable__ct(void *arg0);
extern s32 __vt__15TORockJungleM01[];
extern s32 TORockJungleM01_name_ref;

s32 isFading__15RenderFadeStateCFv(void *);
void matrix_mult_vec(s32, void *, void *);

void *__nw__7TObjectFUl(int);
int vec3_add_to(void *, void *);
int rotate_vector_by_matrix(int, void *, void *);
int rotate_matrix_y(int, int);
extern Offs_8029C390 lbl_80465884;
extern ChipParam_8029C390 lbl_80465890;
extern u8 identity_matrix[];
extern void *tl_05;
s32 play_sound_effect(s32, s32, s32, s32);
void free_collision_body_parts(void *);
int update_obstruction_fade(void*);
void __dl__7TObjectFPv(void *);
void *__dt__18TORockCaveBrakableFv(void *arg0, s16 arg1);

void TORockJungleM01::run_task() { update_obstruction_fade((char*)this + 0xbc); update_break_state(); }

void TORockJungleM01::vfunc_18() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4BC19, arg0 + 0x38, 0, 0);
}

void TORockJungleM01::vfunc_16() {
    Rock_8029C390 *self = (Rock_8029C390 *)this;
    Offs_8029C390 a = lbl_80465884;
    ChipParam_8029C390 chip = lbl_80465890;
    Vec_8029C390 v;
    s32 i;
    void *o;
    chip.pos.x = self->pos.x;
    chip.pos.y = self->pos.y;
    chip.pos.z = self->pos.z;
    chip.y2 = chip.pos.y;
    for (i = 0; i < 1; i++) {
        VecCopy((Vec *)&v, (const Vec *)&a.v[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->x60);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        VecCopy((Vec *)&chip.pos, (const Vec *)&self->pos);
        vec3_add_to(&chip.pos, &v);
        chip.res = (s32)TORockJungleS01::get_model(3);
        chip.res2 = get_jungle_rock_texture_resource(3);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&chip);
        }
    }
}

void *TORockJungleM01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE0);
    if (o != NULL) {
        o = TORockJungleM01__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

void *__dt__15TORockJungleM01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TORockJungleM01;
        if (*(void **)((s8 *)arg0 + 0xDC) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xDC)); ((TORockJungleM01 *)arg0)->m_dc = 0; }
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804949A8Fv((s8 *)arg0 + 0xBC, -1);
        __dt__18TORockCaveBrakableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8029C588_lbl_804DC3A0_size[sizeof(RecoveredGlobal_8029C588_lbl_804DC3A0) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_8029C588_lbl_804DC424_size[sizeof(RecoveredGlobal_8029C588_lbl_804DC424) == 0x24 ? 1 : -1];
typedef char RecoveredGlobal_8029C588___vt__15TORockJungleM01_size[sizeof(RecoveredGlobal_8029C588___vt__15TORockJungleM01) == 0x50 ? 1 : -1];
u8 *TORockJungleM01__ct(u8 *rock_cave_brakable, s32 arg1) {
    struct CopyStack_8029C588 { u8 bytes[0x3C]; };
    CopyStack_8029C588 copy_storage_8029C588;
    s32 temp_r0;
    TORockCaveBrakable__ct((rock_cave_brakable));
    *(s32 **)((s8 *)rock_cave_brakable + 0x18) = &(*(RecoveredGlobal_8029C588___vt__15TORockJungleM01 *)&__vt__15TORockJungleM01).value;
    ((TObjPlayer *)(rock_cave_brakable + 0xBC))->init_and_activate();
    *(s32 *)((s8 *)rock_cave_brakable + 0) = (s32) TORockJungleM01_name_ref;
    ((TORockJungleM01 *)(rock_cave_brakable))->apply_object_set_data((void *)arg1);
    ((TORockJungleM01 *)rock_cave_brakable)->model = TORockJungleS01::get_model(2);
    ((TORockJungleM01 *)rock_cave_brakable)->texlist = get_jungle_rock_texture_resource(2);
    ((TORockJungleM01 *)rock_cave_brakable)->m_b0 = (f32) (5e+01f + *(f32 *)((s8 *)(*(void **)((s8 *)(((TORockJungleM01 *)rock_cave_brakable)->model) + 4)) + 0x14));
    init_collision_body_parts(rock_cave_brakable, (void *) ((u8 *)rock_jungle_collision_body_parts + 0x2C), 1);
    ((TUnk_804AF8A0 *)rock_cave_brakable)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_cave_brakable)->register_object_by_id();
    ((TORockJungleM01 *)rock_cave_brakable)->m_b8 = (s32) ((TORockJungleM01 *)rock_cave_brakable)->set_params[0];
    temp_r0 = ((TORockJungleM01 *)rock_cave_brakable)->m_b8;
    if ((temp_r0 < 0) || (temp_r0 >= 0x100)) {
        ((TORockJungleM01 *)rock_cave_brakable)->m_b8 = -1;
    }
    *(ByteBlock_3C *)(copy_storage_8029C588.bytes) = *(const ByteBlock_3C *)((arg1 - 4) + 4);
    VecCopy((Vec *)((copy_storage_8029C588.bytes + 0x24)), (const Vec *)rock_jungle_vec3_table);
    ((TORockJungleM01 *)rock_cave_brakable)->m_dc = TObjMapCsn::create((s32)((void *) ((copy_storage_8029C588.bytes))));
    ((TObjPlayer *)(rock_cave_brakable + 0xBC))->activate_and_dispatch();
    return rock_cave_brakable;
}

void TORockJungleM01::vfunc_15() {
    u8 *arg0 = (u8 *)this;
    if ((s32) this->m_d8 != 0) {
        ((VObj_8029C320*)(arg0 + 0xBC))->m7();
    }
    TObjFish::set_cull_none();
}
void TORockJungleM01::vfunc_14() {
    Rd_8029C6FC *arg0 = (Rd_8029C6FC *)this;
    Vec_8029C6FC v;
    TObjFish::set_cull_back();
    matrix_mult_vec(0, arg0->pos, &v);
    if (-v.z < 38.0f) {
        ((RenderFadeState *)(&arg0->fade))->fadeOut();
    } else {
        ((RenderFadeState *)(&arg0->fade))->restore();
    }
    if (TRaderMapCore::is_not_split_screen() == 1) {
        arg0->fading = 0;
    } else {
        arg0->fading = isFading__15RenderFadeStateCFv(&arg0->fade);
    }
    if (arg0->fading != 0) {
        arg0->fade.m6();
    }
}

}

#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TORockJungleS01.h"
#include "pso/misc/TMotorcycle.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_8029C9C8_lbl_804DC3A0 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_8029C9C8_lbl_804DC424 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_8029C9C8___vt__15TORockJungleS01 {
    s32 value;
    u8 remaining[0x4C];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Vec_8029C7DC { f32 x, y, z; };

struct Spawn_8029C7DC {
    u8 pad0[0xC];
    Vec_8029C7DC pos;
    u8 pad18[0x20];
    f32 f38;
    u8 pad3c[4];
    s32 f40;
    s32 f44;
    u8 pad48[4];
};

struct Offs_8029C7DC { Vec_8029C7DC v[1]; };

struct Rock_8029C7DC {
    u8 pad0[0x38];
    Vec_8029C7DC pos;
    u8 pad44[0x60 - 0x44];
    s32 rotY;
};

extern "C" {
u8 * get_bml_model(void *, int);
extern u32 TORockJungleS01__bml_resource;
s32 init_collision_body_parts(void *, void *, int);
void *TORockCaveBrakable__ct(void *arg0);
extern s32 __vt__15TORockJungleS01[];
extern s32 TORockJungleS01__name;

extern u32 TORockJungleS01__texture_resource;
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_804658EC[];
extern u8 lbl_80465904[];
extern u8 lbl_8046591C[];

void *__nw__7TObjectFUl(int);
extern Offs_8029C7DC lbl_8046581C;
extern Spawn_8029C7DC lbl_80465828;
extern u8 identity_matrix[];
s32 play_sound_effect(s32, s32, s32, s32);
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void *__dt__18TORockCaveBrakableFv(void *arg0, s16 arg1);

void TORockJungleS01::vfunc_18() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4BC19, arg0 + 0x38, 0, 0);
}

void TORockJungleS01::vfunc_16() {
    Rock_8029C7DC *self = (Rock_8029C7DC *)this;
    Offs_8029C7DC off = lbl_8046581C;
    Spawn_8029C7DC p = lbl_80465828;
    Vec_8029C7DC v;
    s32 i;
    void *o;
    p.pos.x = self->pos.x;
    p.pos.y = self->pos.y;
    p.pos.z = self->pos.z;
    p.f38 = p.pos.y;
    for (i = 0; i < 1; i++) {
        VecCopy((Vec *)&v, (const Vec *)&off.v[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, self->rotY);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        VecCopy((Vec *)&p.pos, (const Vec *)&self->pos);
        vec3_add_to(&p.pos, &v);
        p.f40 = (s32)TORockJungleS01::get_model(1);
        p.f44 = get_jungle_rock_texture_resource(1);
        o = __nw__7TObjectFUl(0x234);
        if (o != NULL) {
            construct_debris__8TObjChipFPvPvPv((u8 *)o, (u8 *)tl_05, (u8 *)&p);
        }
    }
}

void *TORockJungleS01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC0);
    if (o != NULL) {
        o = TORockJungleS01__ct((TORockJungleS01 *)((u8 *)o), (s32)arg0);
    }
    return o;
}

void *__dt__15TORockJungleS01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TORockJungleS01;
        if (*(void **)((s8 *)arg0 + 0xBC) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xBC)); ((TORockJungleS01 *)arg0)->m_bc = 0; }
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__18TORockCaveBrakableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8029C9C8_lbl_804DC3A0_size[sizeof(RecoveredGlobal_8029C9C8_lbl_804DC3A0) == 0x84 ? 1 : -1];
typedef char RecoveredGlobal_8029C9C8_lbl_804DC424_size[sizeof(RecoveredGlobal_8029C9C8_lbl_804DC424) == 0x24 ? 1 : -1];
typedef char RecoveredGlobal_8029C9C8___vt__15TORockJungleS01_size[sizeof(RecoveredGlobal_8029C9C8___vt__15TORockJungleS01) == 0x50 ? 1 : -1];
u8 *TORockJungleS01__ct(TORockJungleS01 *rock_jungle_s01, s32 arg1) {
    struct CopyStack_8029C9C8 { u8 bytes[0x3C]; };
    CopyStack_8029C9C8 copy_storage_8029C9C8;
    s32 temp_r0;
    TORockCaveBrakable__ct((rock_jungle_s01));
    *(s32 **)((s8 *)rock_jungle_s01 + 0x18) = &(*(RecoveredGlobal_8029C9C8___vt__15TORockJungleS01 *)&__vt__15TORockJungleS01).value;
    *(s32 *)((s8 *)rock_jungle_s01 + 0) = (s32) TORockJungleS01__name;
    ((TORockJungleS01 *)(rock_jungle_s01))->apply_object_set_data((void *)arg1);
    rock_jungle_s01->model = TORockJungleS01::get_model(0);
    rock_jungle_s01->texlist = get_jungle_rock_texture_resource(0);
    rock_jungle_s01->m_b0 = (f32) (5e+01f + *(f32 *)((s8 *)(*(void **)((s8 *)rock_jungle_s01->model + 4)) + 0x14));
    init_collision_body_parts(rock_jungle_s01, rock_jungle_collision_body_parts, 1);
    ((TUnk_804AF8A0 *)rock_jungle_s01)->refresh_collision_body_centers();
    ((TObjPlayer *)rock_jungle_s01)->register_object_by_id();
    rock_jungle_s01->m_b8 = (s32) rock_jungle_s01->set_params[0];
    temp_r0 = rock_jungle_s01->m_b8;
    if ((temp_r0 < 0) || (temp_r0 >= 0x100)) {
        rock_jungle_s01->m_b8 = -1;
    }
    *(ByteBlock_3C *)(copy_storage_8029C9C8.bytes) = *(const ByteBlock_3C *)((arg1 - 4) + 4);
    VecCopy((Vec *)((copy_storage_8029C9C8.bytes + 0x24)), (const Vec *)rock_jungle_vec3_table);
    rock_jungle_s01->m_bc = TObjMapCsn::create((s32)((void *) ((copy_storage_8029C9C8.bytes))));
    return (u8 *)rock_jungle_s01;
}

s32 get_jungle_rock_texture_resource(s32 a) {
    if ((*(void * *)&TORockJungleS01__texture_resource) != 0) return (s32)(*(void * *)&TORockJungleS01__texture_resource);
    return 0;
}

u8 *TORockJungleS01::get_model(s32 arg0) {
    if ((void *) (*(u8 * *)&TORockJungleS01__bml_resource) != NULL) {
        return get_bml_model((*(u8 * *)&TORockJungleS01__bml_resource), arg0);
    }
    return NULL;
}

void TORockJungleS01::free_globals() {
    if ((u32) TORockJungleS01__texture_resource != 0U) {
        release_texture_list((void*)TORockJungleS01__texture_resource);
        TAdSinglePlyChrSelectGC::safe_free(TORockJungleS01__texture_resource);
        TORockJungleS01__texture_resource = 0U;
    }
    if ((u32) TORockJungleS01__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TORockJungleS01__bml_resource, 1);
        TORockJungleS01__bml_resource = 0U;
    }
}
void TORockJungleS01::load_resources() {
    void *o;
    o = ::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, TORockJungleS01_resource_descriptor, 0, 0, 0);
    }
    TORockJungleS01__bml_resource = (u32)o;
    switch (get_current_area()) {
    case 27:
        TORockJungleS01__texture_resource = (u32)load_gvm_texture_file((s32)lbl_804658EC);
        break;
    case 26:
        TORockJungleS01__texture_resource = (u32)load_gvm_texture_file((s32)lbl_80465904);
        break;
    case 25:
    default:
        TORockJungleS01__texture_resource = (u32)load_gvm_texture_file((s32)lbl_8046591C);
        break;
    }
    TMotorcycle::add_entry((s16)0x3E, (s32)(TORockJungleS01::get_model(0)), (s32)(get_jungle_rock_texture_resource(0)), (f32)5.0f, (f32)0.0f);
}

}
