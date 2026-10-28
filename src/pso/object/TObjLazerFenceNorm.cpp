#include "types.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjLazerFenceNorm.h"
#include "pso/object/TObjLazerFenceExtra.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct LazerFenceExtraBase_801925F8 { char pad[0x18]; };
struct LazerFenceExtraVObj_801925F8 : LazerFenceExtraBase_801925F8 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Motion_801926D0 { u8 pad[4]; u32 frames; };
struct TObjLazerFenceExtra_801926D0 {
    u8 pad[0xB0];
    s16 switchId;
    u8 padb2[2];
    s32 state;
    f32 frame;
    u8 padbc[8];
    Motion_801926D0 *motion;
};

extern "C" {

void render__19TObjLazerFenceExtraFv(TObjLazerFenceExtra *arg0);
void reset_by_door__19TObjLazerFenceExtraFPv(void *arg0);
void update_wait_switch__19TObjLazerFenceExtraFv(TObjLazerFenceExtra_801926D0 *self);
u8 is_current_floor_switch_set(u16);
void post_translate_matrix(void *);
void draw_ginja_object(void *);
void rotate_matrix_y(int, void *);
void push_matrix(void);
s32 pop_matrix(void);

extern void *lazer_fence_norm_texture_list;

static const f32 lbl_805DBE58[1] = {0.0f};

void TObjLazerFenceExtra::render_lazer_fence_model() {
    TObjFish::set_global_param((s32)lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    rotate_matrix_y(0, *(void * *)&this->rotation_y);
    draw_ginja_object(*(void * *)&this->m_d8);
    pop_matrix();
}

void render__19TObjLazerFenceExtraFv(TObjLazerFenceExtra *lazer_fence_extra) {

    if ((((LazerFenceExtraVObj_801925F8*)lazer_fence_extra)->m8(3e+02f, 4e+01f) != 0) && ((s32) *(s32 *)((s8 *)lazer_fence_extra + 0xD8) != 0)) {
        switch (lazer_fence_extra->m_b4) {
        case 0:
            lazer_fence_extra->draw_lazer_fence_extra_model();
            return;
        case 1:
            lazer_fence_extra->render_lazer_fence_model();
            break;
        }
    }
}

void TObjLazerFenceExtra::update_wait_switch() {
    ((TObjLazerFenceExtra_801926D0 *)this)->frame += 0.9f;
    if ((f32)(((TObjLazerFenceExtra_801926D0 *)this)->motion->frames - 1) < ((TObjLazerFenceExtra_801926D0 *)this)->frame) {
        ((TObjLazerFenceExtra_801926D0 *)this)->frame = lbl_805DBE58[0];
    }
    if (is_current_floor_switch_set((u16)((TObjLazerFenceExtra_801926D0 *)this)->switchId) == 1) {
        clear_player_status_flag(0, 1);
        ((TObjLazerFenceExtra_801926D0 *)this)->state = 1;
    }
}

void reset_by_door__19TObjLazerFenceExtraFPv(void *arg0) {
    if (is_current_floor_switch_set((u16) *(s16 *)((s8 *)arg0 + 0xB0)) == 0) {
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 1);
        *(s32 *)((s8 *)arg0 + 0xB4) = 0;
    }
}

}

struct Node_80192A3C { u32 flags; void *model; u8 pad8[0x24]; Node_80192A3C *child; Node_80192A3C *sibling; };

struct Fish_80192A3C { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x2C]; Node_80192A3C *fBC; Node_80192A3C *fC0; s32 fC4; void *fC8[4]; };

struct VBase_80192874 { char pad[0x18]; };

struct VObj_80192874 : VBase_80192874 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(void *);
};

struct Ent_80192874 { u8 b[0x84]; };

extern "C" {
s32 get_bml_motion(s32, s32);
Node_80192A3C *get_bml_model(s32, s32);
extern s32 lazer_fence_norm_bml_resource;
void init_collision_body_parts(void *, void *, s32);
void __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
extern Ent_80192874 laser_fence_collision_body_parts[];
extern s32 __vt__19TObjLazerFenceExtra[];
extern s32 lazer_fence_extra_class_name;
void *TObjLazerFenceExtra__ct(void *arg0, void *arg1, void *arg2);
void *TObjLazerFenceExtra__create(void *arg0);
void *__dt__19TObjLazerFenceExtraFv(void *arg0, s16 arg1);
void run_task__19TObjLazerFenceExtraFv(TObjLazerFenceExtra *arg0);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void run_task__19TObjLazerFenceExtraFv(TObjLazerFenceExtra *lazer_fence_extra) {

    switch (lazer_fence_extra->m_b4) {
    case 0:
        ((s32 (*)())update_wait_switch__19TObjLazerFenceExtraFv)();
        return;
    case 1:
        ((s32 (*)())reset_by_door__19TObjLazerFenceExtraFPv)();
        return;
    }
}

void *__dt__19TObjLazerFenceExtraFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TObjLazerFenceExtra;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

#define self ((u8 *)arg0)
void *TObjLazerFenceExtra__ct(void *arg0, void *arg1, void *arg2) {
    s32 i;
    __ct__13TUnk_804AF8A0FP7TObject(arg0, arg1);
    *(s32 **)((s8 *)self + 0x18) = __vt__19TObjLazerFenceExtra;
    *(s32 *)((s8 *)self + 0) = lazer_fence_extra_class_name;
    ((VObj_80192874 *)self)->m5(arg2);
    *(s32 *)((s8 *)self + 0xB4) = 0;
    *(f32 *)((s8 *)self + 0xB8) = lbl_805DBE58[0];
    *(s32 *)((s8 *)self + 0xAC) = (s32)*(f32 *)((s8 *)self + 0x68);
    if (*(s32 *)((s8 *)self + 0xAC) < 0) {
        *(s32 *)((s8 *)self + 0xAC) = 0;
    }
    if (*(s32 *)((s8 *)self + 0xAC) > 3) {
        *(s32 *)((s8 *)self + 0xAC) = 3;
    }
    *(s16 *)((s8 *)self + 0xB0) = *(s32 *)((s8 *)self + 0x84);
    if (*(s32 *)((s8 *)self + 0x8C) < 0 || *(s32 *)((s8 *)self + 0x8C) > 1) {
        *(s32 *)((s8 *)self + 0xD8) = 0;
        *(s32 *)((s8 *)self + 0x8C) = 0;
    } else {
        *(s32 *)((s8 *)self + 0xD8) = 1;
    }
    ((TObjLazerFenceExtra *)self)->init_models();
    init_collision_body_parts(self, &laser_fence_collision_body_parts[*(s32 *)((s8 *)self + 0x8C) % 2], 3);
    *(u32 *)((s8 *)self + 0x30) |= 0x40000000;
    *(f32 *)((s8 *)(*(u8 **)((s8 *)self + 0xA4)) + 0x10) = *(f32 *)((s8 *)self + 0x6C);
    *(f32 *)((s8 *)(*(u8 **)((s8 *)self + 0xA4)) + 0xC) = *(f32 *)((s8 *)self + 0x70);
    ((TObjPlayer *)self)->reset_photon_effect();
    ((TUnk_804AF8A0 *)self)->refresh_collision_body_centers();
    if (*(s32 *)((s8 *)self + 0xD8) == 0) {
        for (i = 1; i < *(s32 *)((s8 *)self + 0xA8); i++) {
            ((TUnk_804AF8A0 *)self)->clear_player_status_flag(i, 1);
        }
    }
    return arg0;
}
#undef self

void *TObjLazerFenceExtra__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xDC);
    if (o != NULL) {
        o = TObjLazerFenceExtra__ct(o, tl_05, arg0);
    }
    return o;
}
void TObjLazerFenceNorm::select_models() {
    Fish_80192A3C *arg0 = (Fish_80192A3C *)this;
    s32 i;
    Node_80192A3C *node;
    s32 j;
    if (*(s32 *)&this->set_params[2] % 2 == 0) {
        *(Node_80192A3C * *)&this->m_bc = get_bml_model(lazer_fence_norm_bml_resource, 1);
        arg0->fC0 = get_bml_model(lazer_fence_norm_bml_resource, 0);
        this->m_c4 = get_bml_motion(lazer_fence_norm_bml_resource, 0);
    } else {
        *(Node_80192A3C * *)&this->m_bc = get_bml_model(lazer_fence_norm_bml_resource, 3);
        arg0->fC0 = get_bml_model(lazer_fence_norm_bml_resource, 2);
        this->m_c4 = get_bml_motion(lazer_fence_norm_bml_resource, 1);
    }
    for (j = 0; j < 4; j++) {
        arg0->fC8[j] = 0;
    }
    i = 0;
    node = arg0->fC0->child;
    if (node != 0) {
        arg0->fC8[i++] = node->model;
        node = node->sibling;
        while (node != 0 && i < 4) {
            arg0->fC8[i++] = node->model;
            node = node->sibling;
        }
    }
}

}

struct Obj_80192B5C { u8 pad0[0x38]; u8 f38[0x24]; s32 f5C; s32 f60; u8 pad64[0x48]; s32 fAC; u8 padB0[8]; f32 fB8; s32 fBC; s32 fC0; s32 fC4; s32 fC8[4]; };

extern "C" {
void draw_ginja_model_with_motion(s32, s32, f32);
extern u16 lbl_80445B7C[];
void TObjLazerFenceNorm::draw_animated_beam() {
    s32 i;
    for (i = 0; i < 4; i++) {
        ((TObjDoorJung *)(((Obj_80192B5C *)this)->fC8[i]))->free_children((void *)(lbl_80445B7C[((Obj_80192B5C *)this)->fAC]));
    }
    TObjFish::set_global_param((s32)lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix(((Obj_80192B5C *)this)->f38);
    rotate_matrix_y(0, (void *)((Obj_80192B5C *)this)->f60);
    draw_ginja_object((void *)((Obj_80192B5C *)this)->fBC);
    TParticleCtrl::begin_effect_render();
    draw_ginja_model_with_motion(((Obj_80192B5C *)this)->fC0, ((Obj_80192B5C *)this)->fC4, ((Obj_80192B5C *)this)->fB8);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

}

struct LazerFenceNormBase_80192C00 { char pad[0x18]; };
struct LazerFenceNormVObj_80192C00 : LazerFenceNormBase_80192C00 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Motion_80192CCC { u8 pad[4]; u32 frames; };

struct TObjLazerFenceNorm_80192CCC {
    u8 pad[0xB0];
    s16 switchId;
    u8 padb2[2];
    s32 state;
    f32 frame;
    u8 padbc[8];
    Motion_80192CCC *motion;
};

void TObjLazerFenceNorm::draw_model() {
    TObjFish::set_global_param((s32)lazer_fence_norm_texture_list);
    push_matrix();
    post_translate_matrix((void *)((char *)this + 56));
    rotate_matrix_y(0, *(void * *)&this->rotation_y);
    draw_ginja_object(this->m_bc);
    pop_matrix();
}

void TObjLazerFenceNorm::render() {

    if (((LazerFenceNormVObj_80192C00*)this)->m8(3e+02f, 4e+01f) != 0) {
        switch (this->m_b4) {
        case 0:
            draw_animated_beam();
            return;
        case 1:
            draw_model();
            break;
        }
    }
}

void TObjLazerFenceNorm::update_closed() {
    ((TObjLazerFenceNorm_80192CCC *)this)->frame += 0.9f;
    if ((f32)(((TObjLazerFenceNorm_80192CCC *)this)->motion->frames - 1) < ((TObjLazerFenceNorm_80192CCC *)this)->frame) {
        ((TObjLazerFenceNorm_80192CCC *)this)->frame = lbl_805DBE58[0];
    }
    if (is_current_floor_switch_set((u16)((TObjLazerFenceNorm_80192CCC *)this)->switchId) == 1) {
        clear_player_status_flag(0, 1);
        ((TObjLazerFenceNorm_80192CCC *)this)->state = 1;
    }
}

void TObjLazerFenceNorm::reset_by_door() {
    if (is_current_floor_switch_set((u16) *(s16 *)&this->m_b0) == 0) {
        set_indexed_flags(0, 1);
        *(s32 *)&this->m_b4 = 0;
    }
}

struct RecoveredGlobal_80192E70_lbl_804B7FB0 {
    s32 value;
    u8 remaining[0x104];
};

struct RecoveredGlobal_80192E70___vt__18TObjLazerFenceNorm {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {

extern s32 __vt__18TObjLazerFenceNorm[];
extern s32 obj_lazer_fence_norm_class_name;

void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
s32 free_collision_body_parts(void *);
s32 update_closed__18TObjLazerFenceNormFv();
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
s32 reset_by_door__18TObjLazerFenceNormFv();

void TObjLazerFenceNorm::run_task() {

    switch (this->m_b4) {
    case 0:
        update_closed__18TObjLazerFenceNormFv();
        return;
    case 1:
        reset_by_door__18TObjLazerFenceNormFv();
        return;
    }
}

void *__dt__18TObjLazerFenceNormFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjLazerFenceNorm;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_80192E70_lbl_804B7FB0_size[sizeof(RecoveredGlobal_80192E70_lbl_804B7FB0) == 0x108 ? 1 : -1];
typedef char RecoveredGlobal_80192E70___vt__18TObjLazerFenceNorm_size[sizeof(RecoveredGlobal_80192E70___vt__18TObjLazerFenceNorm) == 0x38 ? 1 : -1];
u8 *TObjLazerFenceNorm__ct(TObjLazerFenceNorm *lazer_fence_norm, s32 arg1, s32 arg2) {
    u32 temp_r4;
    u32 temp_r6;
    __ct__13TUnk_804AF8A0FP7TObject(lazer_fence_norm, (void *)arg1);
    *(s32 **)((s8 *)lazer_fence_norm + 0x18) = &(*(RecoveredGlobal_80192E70___vt__18TObjLazerFenceNorm *)&__vt__18TObjLazerFenceNorm).value;
    *(s32 *)((s8 *)lazer_fence_norm + 0) = (s32) obj_lazer_fence_norm_class_name;
    ((TObjLazerFenceNorm *)(lazer_fence_norm))->apply_object_set_data((void *)arg2);
    lazer_fence_norm->m_b4 = 0;
    *(f32 *)((s8 *)lazer_fence_norm + 0xB8) = lbl_805DBE58[0];
    lazer_fence_norm->m_ac = (s32) lazer_fence_norm->scale.x;
    if ((s32) lazer_fence_norm->m_ac < 0) {
        lazer_fence_norm->m_ac = 0;
    }
    if ((s32) lazer_fence_norm->m_ac > 3) {
        lazer_fence_norm->m_ac = 3;
    }
    lazer_fence_norm->m_b0 = (s16) lazer_fence_norm->set_params[0];
    lazer_fence_norm->select_models();
    temp_r4 = lazer_fence_norm->set_params[2];
    temp_r6 = temp_r4 >> 0x1FU;
    init_collision_body_parts(lazer_fence_norm, (void *) ((u8 *)laser_fence_collision_body_parts + ((((temp_r4 & 1) ^ temp_r6) - temp_r6) * 0x84)), 3);
    lazer_fence_norm->actorFlags = (s32) (lazer_fence_norm->actorFlags | 0x40000000);
    ((TObjPlayer *)lazer_fence_norm)->reset_photon_effect();
    ((TUnk_804AF8A0 *)lazer_fence_norm)->refresh_collision_body_centers();
    return (u8 *)lazer_fence_norm;
}

void *TObjLazerFenceNorm__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TObjLazerFenceNorm__ct((TObjLazerFenceNorm *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjLazerFenceNorm::free_resources() {
    if ((u32) lazer_fence_norm_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)lazer_fence_norm_bml_resource, 1);
        lazer_fence_norm_bml_resource = 0U;
    }
    if ((u32) lazer_fence_norm_texture_list != 0U) {
        release_texture_list((void*)lazer_fence_norm_texture_list);
        TAdSinglePlyChrSelectGC::safe_free((u32)lazer_fence_norm_texture_list);
        lazer_fence_norm_texture_list = 0;
    }
}

}
