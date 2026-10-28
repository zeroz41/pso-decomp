#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemMagSub.h"
#include "pso/item/TItem.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/item/TItemMagSub_80114524.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/system/vector.h"

#include "types.h"

extern "C" {
int set_flags__11TItemMagSubFUl(void *, int);
}
void TItemMagSub::release_model_and_destroy() {
    u8* arg0=(u8*)this;
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    this->textures = 0;
    set_flags__11TItemMagSubFUl(arg0, 0x80U);
}
#define TOBJECT_OUT_OF_LINE_HELPERS

struct Base_80114950 { char pad[0x18]; };
struct VObj_80114950 : Base_80114950 {
    virtual void m00(); virtual void m01(); virtual void m02(); virtual void m03();
    virtual void m04(); virtual void m05(); virtual void m06(); virtual void m07();
    virtual void m08(); virtual void m09(); virtual void m10(); virtual void m11();
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
    virtual void m60(); virtual void m61(); virtual void m62();
    virtual void m63(s32, void *);
};

extern "C" {

void reset__11TItemMagSubFv(u8*);
void reset_oscillation__11TItemMagSubFv(u8*);

extern s32 item_mag_param_table;

}
void TItemMagSub::set_motion_type(s32 arg1) {
    u8* arg0=(u8*)this;
    u8 *temp_r5;

    ((void(*)(void))reset__11TItemMagSubFv)();
    this->motion_type = arg1;
    *(s32 * *)&this->motion = (s32 *) (item_mag_param_table + (arg1 * 0x64));
    temp_r5 = (unsigned char *) (this->owner);
    if (temp_r5 != NULL) {
        s32 elem = **(s32 * *)&this->motion;
        if (elem == -1) {
            VecCopy((Vec *)(arg0 + 0xA0), (const Vec *)(temp_r5 + 0x2FC));
            return;
        }
        ((VObj_80114950 *)temp_r5)->m63(elem, (u8 *)&this->follow_anchor);
    }
}
void TItemMagSub::transition_motion_type(s32 type) {
    set_flags(0x18);
    ((void(*)(void*,s32,s32))reset_oscillation__11TItemMagSubFv)(this, motion_type, type);
    motion_type = type;
    motion = (MagFollowParameters*)(item_mag_param_table + (type*0x64));
}

#define TOBJECT_OUT_OF_LINE_HELPERS

#include <stddef.h>
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/player/TObjPlayer.h"

struct Stack_80114DB8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_80114DB8_lbl_8043E5A8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80114DB8_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Vec_80114CD8 { f32 x, y, z; };

typedef struct TItemMagSub_801152AC {
    u8 pad0[0x34];
    f32 vec34[3];
    u8 pad40[0x58 - 0x40];
    f32 vec58[3];
    u8 pad64[0x7C - 0x64];
    f32 timer;
    u8 pad80[0x94 - 0x80];
    f32 f94;
    f32 f98;
    f32 f9C;
} TItemMagSub_801152AC;

typedef struct MagSub_80115800 { u8 pad0[0x70]; s32 slots[3]; } MagSub_80115800;

struct RecoveredGlobal_801151E0_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct Vec_801151E0 { f32 x, y, z; };

struct Base_801151E0 { u8 pad0[0x18]; };

struct Player_801151E0 : Base_801151E0 {
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
    virtual void get_joint_pos(s32, void *);
};

struct Joint_801151E0 { s32 id; };

struct MagSub_801151E0 {
    u8 pad0[0x20];
    Player_801151E0 *player;
    u8 pad24[0xC];
    Joint_801151E0 *joint;
    u8 pad34[0x6C];
    Vec_801151E0 posA0;
};

typedef struct TItemMagSub_80114F0C {
    u8 pad0[0x24];
    void *model;
    void *animation;
    u32 textures;
    u8 pad30[0x6C - 0x30];
    s32 selected_node;
    u8 pad70[0x80 - 0x70];
    f32 animation_frame;
} TItemMagSub_80114F0C;

struct Feed_80114AB4 { u8 data[8]; };

typedef char RecoveredGlobal_80114DB8_lbl_8043E5A8_size[sizeof(RecoveredGlobal_80114DB8_lbl_8043E5A8) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80114DB8_lbl_8058D490_size[sizeof(RecoveredGlobal_80114DB8_lbl_8058D490) == 0x30 ? 1 : -1];

struct MagSub_801151E0;

struct TItemMagSub_801152AC;

struct Vec_80114CD8;

struct Vec_80115334 { f32 x, y, z; };

struct Base_80115334 { u8 pad[0x18]; };

struct VObj_80115334 : Base_80115334 {
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
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(s32, Vec_80115334 *);
};

struct Stat_80115334 { u8 pad[8]; };

struct Sub_80115334 {
    u8 pad0[0x1C];
    s32 x1C;
    VObj_80115334 *owner;
    u8 pad24[0xC];
    u8 *rec;
    s32 x34;
    s32 x38;
    s32 x3C;
    u8 pad40[0xCC - 0x40];
    Stat_80115334 st[2];
};
extern "C" {

s32 memset(void *, int, int);
u32 mag_owner_has_motion_action(s32);
int set_flags__11TItemMagSubFUl(void*, int);
u32 test_flags__11TItemMagSubFUl(void *, u32);
s32 obj_isState7_324(void *);
s32 mag_node_oscillation_is_disabled(Feed_80114AB4 *);
void reset_oscillation__11TItemMagSubFv(u8 *arg0);
void lerp_follow_anchor(Vec_80114CD8 *target, Vec_80114CD8 *cur, f32 *t);
void reset__11TItemMagSubFv(u8 *arg0);
f32 sin_table_lookup(s32);
void vec3_add_to(void *, void *);
s32 rotate_matrix_zyx(int, int, int, int, int);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
f32 transform_point_by_current_matrix(void *, void *);
void push_matrix();
s32 post_translate_matrix(void *);
}
s32 mag_owner_freezes_follow(void *arg0);
void accumulate_mag_axis_oscillation(f32 *arg0, s32 *arg1, void *arg2);
void mag_accumulate_drift(f32 *out, s32 *phase, f32 *amplitude, s32 *velocity, s8 *offset);
int mag_node_oscillation_uses_z(void* p);
int mag_node_oscillation_uses_y(void* p);
s32 mag_node_oscillation_angle(void *arg0);
int mag_node_oscillation_uses_x(void* p);
int mag_node_oscillation_node_index(void* p);
int mag_item_tests_flag_20(void* p);
extern void *TItemMagSub__oscillating_instance;
extern s32 TItemMagSub__feed_sequence_index;
extern const f32 mag_sub_zero;
extern const f32 mag_sub_angle_units_per_degree;
extern const f32 mag_sub_one;
extern Vec_801151E0 mag_sub_special_pose_offset[];
extern RecoveredGlobal_80114DB8_lbl_8043E5A8 mag_sub_local_origin;
extern f32 model_material_color[4], saved_model_draw_color[4];
extern RecoveredGlobal_80114DB8_lbl_8058D490 identity_matrix;
extern f32 mag_sub_transition_frames;
extern f32 item_mag_follow_scale;
extern u32 TItemMagSub_name;
extern u32 model_render_flags, lbl_805D5660;
extern s32 lbl_805D5664;
extern s32 lbl_805D5668;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 mag_sub_render_distance_limit, mag_sub_screen_cull_margin;
extern const f32 mag_sub_height_intercept;
extern const f32 mag_sub_height_slope;
void TItemMagSub::clear_optional_oscillation_flag(void* item_mag_sub) {

    if ((u32) item_mag_sub != 0U) {
        ((TItemMagSub *)item_mag_sub)->clear_flags(2);
    }
}
void TItemMagSub::reset_oscillation() {
    u8* arg0=(u8*)this;
    memset((u8 *)&this->rotation_delta, 0, 0xC);
    memset((u8 *)&this->drift_phase, 0, 0xC);
    *(f32 *)((s8 *)arg0 + 0x9C) = (f32) mag_sub_zero;
    *(f32 *)((s8 *)arg0 + 0x98) = (f32) mag_sub_zero;
    *(f32 *)((s8 *)arg0 + 0x94) = (f32) mag_sub_zero;
}

void TItemMagSub::apply_node_oscillation(void* _w1) {

    s32 i;
    Feed_80114AB4 *f;
    for (i = 0; i != 2; i++) {
        f = (Feed_80114AB4*)&oscillations[i];
        if (mag_node_oscillation_is_disabled(f) == 0 && TItemMagSub__feed_sequence_index == ((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_node_index)(f)) {
            if (((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_uses_x)(f) != 0) {
                rotate_matrix_x(0, ((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_angle)(f));
            } else if (((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_uses_y)(f) != 0) {
                rotate_matrix_y(0, (void *)((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_angle)(f));
            } else if (((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_uses_z)(f) != 0) {
                rotate_matrix_z(0, ((s32 (*)(Feed_80114AB4 *))mag_node_oscillation_angle)(f));
            }
        }
    }
    if (TItemMagSub__feed_sequence_index == node_ids[selected_node]) {
        if (test_flags__11TItemMagSubFUl(this, 0x20) == 0) {
            model_render_flags |= 0x10;
            ((TUnk_80494AE0 *)material_parameters)->set_chunk_material_color();
            TParticleCtrl::begin_effect_render();
            ((s32 (*)(void *, int))set_flags__11TItemMagSubFUl)(this, 0x20);
        }
        if (selected_node != 2) {
            selected_node++;
        }
    } else if (test_flags__11TItemMagSubFUl(this, 0x20) != 0) {
        TParticleCtrl::end_effect_render();
        ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
        model_render_flags = lbl_805D5660;
        clear_flags(0x20);
    }
}
void TItemMagSub::update_node_oscillation(void* arg) {

    if (TItemMagSub__oscillating_instance != 0) {
        ((TItemMagSub *)TItemMagSub__oscillating_instance)->apply_node_oscillation(arg);
        TItemMagSub__feed_sequence_index++;
    }
}
void accumulate_mag_axis_oscillation(f32 *arg0, s32 *arg1, void *arg2) {
    *arg1 = *arg1 + *(s32 *)((s8 *)arg2 + 0xC);
    *arg0 = *(f32 *)((s8 *)arg2 + 0) * sin_table_lookup(*arg1 + *(s32 *)((s8 *)arg2 + 8));
}

#pragma push
#pragma fp_contract on

void lerp_follow_anchor(Vec_80114CD8 *target, Vec_80114CD8 *cur, f32 *t) {
    cur->x += *t * (target->x - cur->x);
    cur->y += *t * (target->y - cur->y);
    cur->z += *t * (target->z - cur->z);
}
#pragma pop

#pragma push
#pragma fp_contract on
void mag_accumulate_drift(f32 *out, s32 *phase, f32 *amplitude, s32 *velocity, s8 *offset) {
    *phase += *velocity;
    *out += *amplitude * sin_table_lookup(*phase + (s32)(mag_sub_angle_units_per_degree * (f32)*offset));
}
#pragma pop
s32 TItemMagSub::get_world_position(void* output) {

    typedef char sp8_offset[(offsetof(Stack_80114DB8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80114DB8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80114DB8, sp10) == 0x8) ? 1 : -1];
    Stack_80114DB8 stack;
    if ((mag_owner_freezes_follow(item) == 0) && (output != 0)) {
        push_matrix_from((void *)&identity_matrix.value);
        apply_placement_matrix();
        stack.sp8 = *(s32 *)((s8 *)&mag_sub_local_origin.value + 0);
        stack.spC = *(s32 *)((s8 *)&mag_sub_local_origin.value + 4);
        stack.sp10 = *(s32 *)((s8 *)&mag_sub_local_origin.value + 8);
        transform_point_by_current_matrix((void *)&stack.sp8, output);
        pop_matrix();
        return 1;
    }
    return 0;
}
void TItemMagSub::apply_placement_matrix() {
    u8* arg0=(u8*)this;
  f32 temp_f1;
  s32 temp_r7;
  u8 *temp_r6;
  void *feed;
  s32 a2;
  s32 a3;
  s32 a4;
  post_translate_matrix((u8 *)&this->follow_anchor);
  if (obj_isState7_324((void *)this->owner) != 0)
  {
    feed = (void *) ((TItemMagSub *)arg0)->resolve_owner_heading();
    rotate_matrix_y(0, feed);
  }
  else
  {
    rotate_matrix_y(0, (void *) (*((s32 *) (((s8 *)this->owner) + 0x60))));
  }
  post_translate_matrix((u8 *)&this->translation_offset);
  temp_r6 = (unsigned char *) (this->motion);
  if (temp_r6 != 0)
  {
    a2 = *((s32 *) (((s8 *) temp_r6) + 0x1C));
    a2 = a2 + (*((s32 *) (((s8 *) arg0) + 0x34)));
    a3 = (*((s32 *) (((s8 *) temp_r6) + 0x20))) + (*((s32 *) (((s8 *) arg0) + 0x38)));
    a4 = (*((s32 *) (((s8 *) temp_r6) + 0x24))) + (*((s32 *) (((s8 *) arg0) + 0x3C)));
    rotate_matrix_zyx(0, (int) a2, (int) a3, (int) a4, (int) (*((s32 *) (((s8 *) temp_r6) + 0x20))));
  }
  temp_f1 = this->owner_height_scale;
  scale_matrix(0, (f32) temp_f1, (f32) temp_f1, (f32) temp_f1);
}

void TItemMagSub::render_shadows() {
    TItemMagSub_80114F0C* self = (TItemMagSub_80114F0C*)this;
    TObjPlayer::reset_transform_state();
    lbl_805D5660 = model_render_flags;
    lbl_805D5664 = chunk_polygon_flags_and_mask;
    lbl_805D5668 = chunk_polygon_flags_or_mask;
    ((TRaderMapCore *)saved_model_draw_color)->copy_vec4(model_material_color);
    if (self->model) {
        TItemMagSub__oscillating_instance = self;
        TObjPlayer::notify_fish_if_valid(self->textures);
        push_matrix();
        ((TItemMagSub *)self)->apply_placement_matrix();
        TItemMagSub__feed_sequence_index = 0;
        self->selected_node = 0;
        if (self->animation) {
            TObjEneRe7Berura::set_global_state((s32)(TItemMagSub::update_node_oscillation));
            TObjPlayer::set_global_flag();
            draw_model_motion(self->model, self->animation, self->animation_frame);
            TObjPlayer::clear_global_state();
            TObjEneRe7Berura::set_global_state(0);
        } else {
            model_render_flags |= 0x8011;
            set_color_blend_mode(1, 4, 5, 0);
            set_shadow_material_state();
            draw_ginja_object(self->model);
            model_render_flags &= ~0x8011;
        }
        TItemMagSub__feed_sequence_index = 0;
        pop_matrix();
        TItemMagSub__oscillating_instance = 0;
        if (test_flags__11TItemMagSubFUl(self, 0x20)) {
            TParticleCtrl::end_effect_render();
            ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
            model_render_flags = lbl_805D5660;
            ((TItemMagSub *)self)->clear_flags(0x20);
        }
    }
    TObjPlayer::reset_transform_state();
    ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
    chunk_polygon_flags_and_mask = lbl_805D5664;
    chunk_polygon_flags_or_mask = lbl_805D5668;
    model_render_flags = lbl_805D5660;
}
void TItemMagSub::render() {
    TItemMagSub* self = this;
    if (is_point_on_screen(self->owner->center, mag_sub_render_distance_limit, mag_sub_screen_cull_margin) && self->model) {
        TItemMagSub__oscillating_instance = self;
        TObjPlayer::notify_fish_if_valid(self->textures);
        push_matrix();
        ((TItemMagSub *)self)->apply_placement_matrix();
        (*(u32 *)&TItemMagSub__feed_sequence_index) = 0;
        self->selected_node = 0;
        if (self->animation) {
            TObjEneRe7Berura::set_global_state((s32)(TItemMagSub::update_node_oscillation));
            TObjPlayer::set_global_flag();
            draw_model_motion(self->model, self->animation, self->animation_frame);
            TObjPlayer::clear_global_state();
            TObjEneRe7Berura::set_global_state(0);
        } else {
            draw_node_tree_with_callback((NJS_OBJECT *)self->model, (void (*)(NJS_OBJECT *))TItemMagSub::update_node_oscillation);
        }
        (*(u32 *)&TItemMagSub__feed_sequence_index) = 0;
        pop_matrix();
        TItemMagSub__oscillating_instance = 0;
        if (test_flags__11TItemMagSubFUl(self, 0x20)) {
            TParticleCtrl::end_effect_render();
            ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
            model_render_flags = lbl_805D5660;
            ((TItemMagSub *)self)->clear_flags(0x20);
        }
    }
}
s32 TItemMagSub::resolve_owner_heading() {
    void* arg0=this;
    s32 temp_r3;
    void **temp_r4_2;
    void *temp_r3_2;
    void *temp_r4;
    void *temp_r4_3;

    temp_r3_2 = *(void **)((s8 *)arg0 + 0x20);
    temp_r4_2 = *(void ***)((s8 *)temp_r3_2 + 0xF8);
    temp_r3 = *(s32 *)((s8 *)temp_r3_2 + 0x60);
    if (temp_r4_2 != NULL) {
        temp_r4_3 = *temp_r4_2;
        if (temp_r4_3 != NULL) {
            temp_r4 = *(void **)((s8 *)temp_r4_3 + 4);
            if (temp_r4 != NULL) {
                return temp_r3 + *(s16 *)((s8 *)temp_r4 + 4);
            }
        }
    }
    return temp_r3;
}

void TItemMagSub::update_special_pose() {
    MagSub_801151E0* self=(MagSub_801151E0*)this;
    if (self->joint != NULL) {
        if (self->joint->id == -1) {
            VecCopy((Vec *)&self->posA0, (const Vec *)((s32)self->player + 0x2FC));
        } else {
            self->player->get_joint_pos(self->joint->id, &self->posA0);
        }
    }
    push_matrix_from((void *) (&(*(RecoveredGlobal_801151E0_lbl_8058D490 *)&identity_matrix).value));
    rotate_matrix_y(0, (void *)(((TItemMagSub *)self)->resolve_owner_heading() + 0x8000));
    Vec_801151E0 in = mag_sub_special_pose_offset[0];
    Vec_801151E0 out;
    transform_point_by_current_matrix(&in, &out);
    vec3_add_to(&self->posA0, &out);
    pop_matrix();
}
void TItemMagSub::update_transition() {
    TItemMagSub_801152AC* self=(TItemMagSub_801152AC*)this;
    self->timer += mag_sub_one;
    if (mag_sub_transition_frames == self->timer) {
        ((TItemMagSub *)self)->clear_flags(0x18);
        memset(self->vec34, 0, 0xC);
        memset(self->vec58, 0, 0xC);
        self->f9C = mag_sub_zero;
        self->f98 = mag_sub_zero;
        self->f94 = mag_sub_zero;
    }
    ((TItemMagSub *)self)->update_follow();
}

#pragma push
#pragma opt_common_subs off
void TItemMagSub::update_follow() {
    Sub_80115334* self=(Sub_80115334*)this;
    Vec_80115334 v;
    s32 i;

    if (self->rec != NULL) {
        if (*(s32 *)self->rec == -1) {
            VecCopy((Vec *)&v, (const Vec *)((u8 *)self->owner + 0x2FC));
        } else {
            self->owner->m63(*(s32 *)self->rec, &v);
        }
        if (((u32 (*)(void *, s32))test_flags__11TItemMagSubFUl)(self, 2) != 0U) {
            VecCopy((Vec *)((u8 *)self + 0xA0), (const Vec *)&v);
        } else if (((u32 (*)(void *, s32))test_flags__11TItemMagSubFUl)(self, 0x10) != 0U) {
            lerp_follow_anchor((Vec_80114CD8 *)&v, (Vec_80114CD8 *)((u8 *)self + 0xA0), &item_mag_follow_scale);
        } else {
            lerp_follow_anchor((Vec_80114CD8 *)&v, (Vec_80114CD8 *)((u8 *)self + 0xA0), (f32 *)(self->rec + 8));
        }
        ((void (*)(void *, void *, void *))accumulate_mag_axis_oscillation)((u8 *)self + 0xAC, (u8 *)self + 0x4C, self->rec + 0x34);
        ((void (*)(void *, void *, void *))accumulate_mag_axis_oscillation)((u8 *)self + 0xB0, (u8 *)self + 0x50, self->rec + 0x44);
        ((void (*)(void *, void *, void *))accumulate_mag_axis_oscillation)((u8 *)self + 0xB4, (u8 *)self + 0x54, self->rec + 0x54);
        ((void (*)(void *, void *, void *, void *, void *))mag_accumulate_drift)((u8 *)self + 0x94, (u8 *)self + 0x58, self->rec + 0x10, self->rec + 0x28, self->rec + 0xD);
        ((void (*)(void *, void *, void *, void *, void *))mag_accumulate_drift)((u8 *)self + 0x98, (u8 *)self + 0x5C, self->rec + 0x14, self->rec + 0x2C, self->rec + 0xE);
        ((void (*)(void *, void *, void *, void *, void *))mag_accumulate_drift)((u8 *)self + 0x9C, (u8 *)self + 0x60, self->rec + 0x18, self->rec + 0x30, self->rec + 0xF);
        vec3_add_to((u8 *)self + 0xAC, (u8 *)self + 0x94);
        if (mag_owner_has_motion_action(self->x1C) != 0U) {
            self->x34 = mag_sub_angle_units_per_degree * (f32)self->rec[0xC];
        } else {
            self->x34 = 0;
        }
        self->x34 += (s32)(mag_sub_angle_units_per_degree * (f32)(s8)self->rec[5]);
        self->x38 += (s32)(mag_sub_angle_units_per_degree * (f32)(s8)self->rec[6]);
        self->x3C += (s32)(mag_sub_angle_units_per_degree * (f32)(s8)self->rec[7]);
    }
    for (i = 0; i != 2; i++) {
        update_mag_node_oscillation_state(&self->st[i]);
    }
}

#pragma pop

void TItemMagSub::run_task() {
    u8* arg0 = (u8*)this;
    if (test_flags__11TItemMagSubFUl(arg0, 0x80U) != 0U) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if (mag_owner_freezes_follow((void *)(*(s32 *)&this->item)) != 0 ||
        ((u32 (*)(void *))mag_item_tests_flag_20)(*(u8 * *)&this->item) != 0U) {
        return;
    }
    if (obj_isState7_324(*(u8 * *)&this->owner) != 0) {
        ((TItemMagSub *)arg0)->update_special_pose();
        return;
    }
    *(f32 *)((s8 *)arg0 + 0xB8) = ((TObjPlayer *)(*(u8 * *)&this->owner + 0x608))->get_mag_scale_f();
    if (test_flags__11TItemMagSubFUl(arg0, 8U) != 0U) {
        ((TItemMagSub *)arg0)->update_transition();
    } else {
        ((TItemMagSub *)arg0)->update_follow();
    }
    if (*(u32 *)((s8 *)arg0 + 0x28) != 0U) {
        *(f32 *)((s8 *)arg0 + 0x80) = *(f32 *)((s8 *)arg0 + 0x80) + mag_sub_one;
        if (*(f32 *)((s8 *)arg0 + 0x84) <= *(f32 *)((s8 *)arg0 + 0x80)) {
            *(f32 *)((s8 *)arg0 + 0x80) = mag_sub_zero;
        }
    }
}
TItemMagSub::~TItemMagSub() {}
TItemHeapObject::~TItemHeapObject() {}
void TItemMagSub::reset() {
    u8* arg0=(u8*)this;
    VecCopy((Vec *)&this->translation_offset, (const Vec *)(*(s32 *)&this->owner + 0x2FC));
    *(s32 *)((s8 *)arg0 + 0x48) = 0;
    *(s32 *)((s8 *)arg0 + 0x44) = 0;
    *(s32 *)((s8 *)arg0 + 0x40) = 0;
    *(s32 *)((s8 *)arg0 + 0x60) = 0;
    *(s32 *)((s8 *)arg0 + 0x5C) = 0;
    *(s32 *)((s8 *)arg0 + 0x58) = 0;
    *(s32 *)((s8 *)arg0 + 0x54) = 0;
    *(s32 *)((s8 *)arg0 + 0x50) = 0;
    *(s32 *)((s8 *)arg0 + 0x4C) = 0;
    *(f32 *)((s8 *)arg0 + 0x9C) = (f32) mag_sub_zero;
    *(f32 *)((s8 *)arg0 + 0x98) = (f32) mag_sub_zero;
    *(f32 *)((s8 *)arg0 + 0x94) = (f32) mag_sub_zero;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    *(s32 *)((s8 *)arg0 + 0x38) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)&this->motion = 0;
}

#pragma push
#pragma fp_contract on
TItemMagSub::TItemMagSub(MagDrawOwner* player, TObject* parent) : TItemHeapObject(parent) {
    s32 i;
    m_name = (const char*)TItemMagSub_name;
    owner = player;
    model = 0;
    textures = 0;
    animation = 0;
    reset();
    flags = 0;
    item = parent;
    animation_frame = mag_sub_zero;
    transition_frame = mag_sub_zero;
    for (i=0; i<3; i++) node_ids[i]=-1;
    if (0.5 < *(f32*)((s8 *)player + 0x8A8)) {
        owner_height_scale = -((mag_sub_height_slope**(f32*)((s8 *)player + 0x8A8))-mag_sub_height_intercept);
    } else {
        owner_height_scale = mag_sub_one;
    }
    disallow_rendering();
    disallow_rendering_shadows();
}

#pragma pop

void TObject::disallow_rendering_shadows() { m_flags = (u16)(m_flags | 0x100); }
void TItemMagSub::clear_growth_flag() {
    void* p=this; ((TItemMagSub *)p)->clear_flags(64); }
void TItemMagSub::clear_flags(u32 v) {
    void* p=this; *(u32*)((char*)p + 0x64) &= ~v; }
int TItemMagSub::set_growth_flag() {
    void* p=this; return set_flags__11TItemMagSubFUl(p, 64); }
int mag_node_oscillation_uses_z(void* p) { return (*(u8*)((char*)p + 0x0) >> 7) & 0x1; }

int mag_node_oscillation_uses_y(void* p) { return (*(u8*)((char*)p + 0x0) >> 6) & 0x1; }

s32 mag_node_oscillation_angle(void *arg0) {
    return (s32) (mag_sub_angle_units_per_degree * (f32) *(s16 *)((s8 *)arg0 + 2));
}

int mag_node_oscillation_uses_x(void* p) { return (*(u8*)((char*)p + 0x0) >> 5) & 0x1; }

int mag_node_oscillation_node_index(void* p) { return *(u8*)((char*)p + 0x0) & 0x7; }

int mag_item_tests_flag_20(void* p) { return *(u32*)((char*)p + 0x18c) & 0x20; }
extern "C" {

__declspec(section ".sdata2") extern const f32 mag_sub_zero = 0.0f;
__declspec(section ".sdata2") extern const f32 mag_sub_angle_units_per_degree = 182.0444488525390625f;
__declspec(section ".sdata2") extern const f32 mag_sub_render_distance_limit = 400.0f;
__declspec(section ".sdata2") extern const f32 mag_sub_screen_cull_margin = 20.0f;
__declspec(section ".sdata2") extern const f32 mag_sub_one = 1.0f;
__declspec(section ".sdata2") extern const f32 mag_sub_height_intercept = 1.10000002384185791015625f;
__declspec(section ".sdata2") extern const f32 mag_sub_height_slope = 0.20000000298023223876953125f;
}
