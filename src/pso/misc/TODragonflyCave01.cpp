#include "types.h"
#include "pso/system/vector.h"
#include "pso/misc/TODragonfly.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TODragonflyCave01.h"
#include "pso/system/BmlResourceDescriptor.h"

extern char lbl_80441100[];
extern char lbl_80441110[];
extern char lbl_80441124[];
extern char lbl_80441138[];
extern char lbl_80441150[];
extern char lbl_80441168[];
extern const char *bm_fs_obj_tombo_model_names[2];
extern const char *bm_fs_obj_tombo_motion_names[2];
extern BmlResourceDescriptor dragonfly_cave01_resource_descriptor;
extern const char *fs_obj_ex_entombo_model_names[2];
extern const char *fs_obj_ex_entombo_motion_names[2];
extern BmlResourceDescriptor TODragonflyCave01__resource_descriptor;

extern "C" {
u8 *TODragonfly__ct(TODragonfly *arg0);
f32 sin_table_lookup(s32);
s32 rand(void);
extern s32 __vt__17TODragonflyCave01[];
extern s32 TODragonflyCave01__class_name;
extern u32 TODragonflyCave01__static_model_resource;
extern const f32 lbl_805DB560;
extern const f32 lbl_805DB564;
extern const f32 lbl_805DB568;
extern const f32 lbl_805DB56C;
extern const f32 lbl_805DB570;
extern const f32 lbl_805DB574;
extern const f32 lbl_805DB578;
extern const f32 lbl_805DB57C;
u8 *TODragonflyCave01__ct(TODragonflyCave01 *arg0, void *arg1);
void *TODragonflyCave01__create(void *arg0);
void *__dt__17TODragonflyCave01Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);
void *__dt__11TODragonflyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void *TODragonflyCave01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x100);
    if (o != NULL) {
        o = TODragonflyCave01__ct((TODragonflyCave01 *)((u8 *)o), (void *)arg0);
    }
    return o;
}

void TODragonflyCave01::release_static_instance() {
    if ((u32) TODragonflyCave01__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TODragonflyCave01__static_model_resource, 1);
        TODragonflyCave01__static_model_resource = 0U;
    }
}

void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

void TODragonflyCave01::load_resources() {
    void *o;

    switch (TOKeyMachine01::get_global_state()) {
    default:
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &dragonfly_cave01_resource_descriptor, 0, 0, 0);
        }
        TODragonflyCave01__static_model_resource = (u32)o;
        break;
    case 0x10:
    case 0x15:
    case 0x16:
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &TODragonflyCave01__resource_descriptor, 0, 0, 0);
        }
        TODragonflyCave01__static_model_resource = (u32)o;
        break;
    }
}

void *__dt__17TODragonflyCave01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TODragonflyCave01;
        __dt__11TODragonflyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on

#pragma pop

}

#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80164764_lbl_8050BEE0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80164764_lbl_8050BFA0 {
    s32 value;
    u8 remaining[0x3C];
};

struct RecoveredGlobal_80164764_lbl_8058D490 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_80164DEC___vt__11TODragonfly { s32 value; u8 remaining[0x38]; };

struct Self_8016492C { u8 pad[0x38]; u8 pos[0x70 - 0x38]; f32 radius; u8 pad74[0xAC - 0x74]; s32 state; u8 padb0[0xD4 - 0xB0]; u8 target[0xE0 - 0xD4]; u8 vec[0xC]; };

struct O_80164A90 { u8 pad[0x38]; u8 pos[0x34]; f32 f6c; f32 f70; u8 pad74[0xAC - 0x74]; s32 st; u8 padb0[0xCC - 0xB0]; s32 cc; u8 padd0[4]; u8 d4[0xC]; u8 e0[0xC]; };

extern "C" {
s32 is_any_player_within_radius_xz(u8 *self, f32 radius);
extern const f32 lbl_805DB588;
extern const f32 lbl_805DB58C;
extern const f32 lbl_805DB590;
f32 atan2_float(f32 y, f32 x);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(s32, s32);
f32 subtract_vector(void *, void *);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern const f64 lbl_804411B0;
extern RecoveredGlobal_80164764_lbl_8050BEE0 lbl_8050BEE0;
extern RecoveredGlobal_80164764_lbl_8050BFA0 dragonfly_random_destination;
extern RecoveredGlobal_80164764_lbl_8058D490 identity_matrix;
extern const f32 lbl_805DB580;
s32 init_map_object_base(void *, int);
extern s32 __vt__11TODragonfly[];
extern s32 TODragonfly__class_name;
extern s32 tl_05;
extern const f32 lbl_805DB594;
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805DB584;
struct Base_80164c34_80164760 { char pad[0x18]; };
struct VObj_80164c34_80164760 : Base_80164c34_80164760 {
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

s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(s32, s32, f32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();

#pragma push
#pragma fp_contract on
u8 *TODragonflyCave01__ct(TODragonflyCave01 *dragonfly_cave01, void *arg1) {
    TODragonfly__ct(dragonfly_cave01);
    *(s32 **)((s8 *)dragonfly_cave01 + 0x18) = __vt__17TODragonflyCave01;
    *(s32 *)((s8 *)dragonfly_cave01 + 0) = TODragonflyCave01__class_name;
    ((TODragonflyCave01 *)(dragonfly_cave01))->apply_object_set_data(arg1);
    dragonfly_cave01->model = *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODragonflyCave01__static_model_resource) + 0x42C)) + 8);
    dragonfly_cave01->texture_id = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODragonflyCave01__static_model_resource) + 0x42C)) + 0xC);
    *(void **)((s8 *)dragonfly_cave01 + 0xBC) = *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODragonflyCave01__static_model_resource) + 0x430)) + 4);
    *(f32 *)((s8 *)dragonfly_cave01 + 0xB4) = (f32)*(u32 *)((s8 *)(*(u8 **)((s8 *)dragonfly_cave01 + 0xBC)) + 4) - lbl_805DB560;
    dragonfly_cave01->m_b8 = lbl_805DB564;
    dragonfly_cave01->m_c0 = lbl_805DB568;
    *(f32 *)((s8 *)dragonfly_cave01 + 0xC4) = *(f32 *)((s8 *)(*(u8 **)((s8 *)dragonfly_cave01->model + 4)) + 0x14);
    dragonfly_cave01->m_ac = 0;
    dragonfly_cave01->m_f4 = lbl_805DB56C * (f32)dragonfly_cave01->m_84 + lbl_805DB560;
    dragonfly_cave01->m_f8 = (s32)(lbl_805DB570 * (lbl_805DB574 / (lbl_805DB578 / dragonfly_cave01->m_f4)));
    dragonfly_cave01->m_fc = (s32)(lbl_805DB570 * (lbl_805DB574 * (lbl_805DB57C * (f32)rand())));
    dragonfly_cave01->m_ec = lbl_805DB56C * (f32)*(s32 *)((s8 *)dragonfly_cave01 + 0x88) + lbl_805DB560;
    *(f32 *)((s8 *)dragonfly_cave01 + 0xF0) = dragonfly_cave01->m_ec * sin_table_lookup(dragonfly_cave01->m_fc);
    return (u8 *)dragonfly_cave01;
}
#pragma pop

void TODragonfly::vfunc_14() {  }

typedef char RecoveredGlobal_80164764_lbl_8050BEE0_size[sizeof(RecoveredGlobal_80164764_lbl_8050BEE0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80164764_lbl_8050BFA0_size[sizeof(RecoveredGlobal_80164764_lbl_8050BFA0) == 0x40 ? 1 : -1];
typedef char RecoveredGlobal_80164764_lbl_8058D490_size[sizeof(RecoveredGlobal_80164764_lbl_8058D490) == 0x30 ? 1 : -1];
s32 TODragonfly::pick_random_destination(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)&lbl_8050BEE0.value + 0) = (f32) lbl_805DB580;
    *(f32 *)((s8 *)&lbl_8050BEE0.value + 4) = farg0;
    *(f32 *)((s8 *)&lbl_8050BEE0.value + 8) = (f32) (*(f32 *)&this->_padD0 * (lbl_805DB57C * (f32) rand()));
    *(s32 *)((s8 *)&dragonfly_random_destination.value + 4) = (s32) (lbl_805DB570 * (lbl_805DB574 * (lbl_805DB57C * (f32) rand())));
    push_matrix_from((void *)&identity_matrix.value);
    rotate_matrix_y(0, (s32)((int) (*(s32 *)((s8 *)&dragonfly_random_destination.value + 4))));
    rotate_vector_by_matrix(0, (void *)&lbl_8050BEE0.value, (void *)&lbl_8050BEE0.value);
    pop_matrix();
    vec3_add_to((void *)&lbl_8050BEE0.value, (u8 *)&this->m_50);
    VecCopy((Vec *)(arg0 + 0xD4), (const Vec *)(&lbl_8050BEE0.value));
    subtract_vector((void *)&lbl_8050BEE0.value, (u8 *)&this->position);
    if (((TObjPlayer *)(&lbl_8050BEE0.value))->check_camera_distance() == 1) {
        *(s32 *)&this->m_ac = 1;
        *(s32 *)&this->m_cc = 0;
        this->rotation_y = (s32) (lbl_804411B0 * atan2_float((f64) *(f32 *)((s8 *)&lbl_8050BEE0.value + 0), (f64) *(f32 *)((s8 *)&lbl_8050BEE0.value + 8)));
        this->m_e0 = (f32) (*(f32 *)((s8 *)&lbl_8050BEE0.value + 0) * *(f32 *)&this->m_70);
        *(f32 *)&this->unk_E4 = (f32) (*(f32 *)((s8 *)&lbl_8050BEE0.value + 4) * *(f32 *)&this->m_70);
        this->m_e8 = (f32) (*(f32 *)((s8 *)&lbl_8050BEE0.value + 8) * *(f32 *)&this->m_70);
        return 1;
    }
    return 0;
}

void TODragonfly::move_toward_target() {
    Self_8016492C *self = (Self_8016492C *)this;
    f32 d = horizontal_distance_squared(self->target, self->pos);
    if (d < (lbl_805DB584 + self->radius) * (lbl_805DB584 + self->radius)) {
        this->m_ac = 2;
    } else {
        vec3_add_to(self->pos, self->vec);
    }
}

#pragma push
#pragma fp_contract on
void TODragonfly::sub_80164990() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r5;
    temp_r5 = this->m_cc;
    this->m_cc = (temp_r5 + 1);
    if (lbl_805DB578 < (f32) temp_r5) {
        if (is_any_player_within_radius_xz(arg0, lbl_805DB588) == 1) {
            if (((TODragonfly *)arg0)->pick_random_destination(lbl_805DB578 + this->target_scale) == 1) {
                this->m_ac = 3;
                this->m_cc = 0;
            }
        } else if (((TODragonfly *)arg0)->pick_random_destination(this->target_scale * ((lbl_805DB58C * (lbl_805DB57C * (f32) rand())) - lbl_805DB560)) == 1) {
            this->m_ac = 1;
            this->m_cc = 0;
        }
    }
}
#pragma pop

void TODragonfly::sub_80164A90() {
    O_80164A90 *arg0 = (O_80164A90 *)this;
    f32 t;
    f32 d;
    if (is_any_player_within_radius_xz((u8 *)arg0, lbl_805DB590) == 1) {
        if (((TODragonfly *)arg0)->pick_random_destination(lbl_805DB578 + this->target_scale) == 1) {
            this->m_ac = 3;
            this->m_cc = 0;
        }
    } else {
        d = horizontal_distance_squared(arg0->d4, arg0->pos);
        t = lbl_805DB584 + arg0->f70;
        if (d < t * t) {
            this->m_ac = 0;
            return;
        }
        vec3_add_to(arg0->pos, arg0->e0);
    }
}

#pragma push
#pragma fp_contract on
void TODragonfly::update_idle() {
    s32 arg0 = (s32)this;
    s32 temp_r4;
    if (is_any_player_within_radius_xz((u8 *)arg0, lbl_805DB590) == 1) {
        if (pick_random_destination(lbl_805DB578 + *(f32 *)((s8 *)arg0 + 0x6C)) == 1) {
            *(s32 *)((s8 *)arg0 + 0xAC) = 3;
            *(s32 *)((s8 *)arg0 + 0xCC) = 0;
        }
    } else {
        temp_r4 = *(s32 *)((s8 *)arg0 + 0xCC);
        *(s32 *)((s8 *)arg0 + 0xCC) = (temp_r4 + 1);
        if ((lbl_805DB578 < (f32) temp_r4) && (pick_random_destination(*(f32 *)((s8 *)arg0 + 0x6C) * ((lbl_805DB58C * (lbl_805DB57C * (f32) rand())) - lbl_805DB560)) == 1)) {
            *(s32 *)((s8 *)arg0 + 0xAC) = 1;
            *(s32 *)((s8 *)arg0 + 0xCC) = 0;
        }
    }
}
#pragma pop

void TODragonfly::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_80164c34_80164760 *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        translate_matrix(0, lbl_805DB580, *(f32 *)((s8 *)arg0 + 0xF0), lbl_805DB580);
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        draw_ginja_model_with_motion(*(s32 *)&this->model, *(s32 *)&this->m_bc, this->m_b0);
        pop_matrix();
    }
}

void TODragonfly::run_task() {

    this->m_fc = (s32) (this->m_fc + this->m_f8);
    *(f32 *)((s8 *)this + 0xF0) = (f32) (this->m_ec * sin_table_lookup(this->m_fc));
    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_14();
        return;
    }
    update_anim_phase();
    switch (this->m_ac) {
    case 0:
        update_idle();
        return;
    case 1:
        sub_80164A90();
        return;
    case 2:
        sub_80164990();
        return;
    case 3:
        move_toward_target();
        return;
    }
}

void *__dt__11TODragonflyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TODragonfly;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
u8 *TODragonfly__ct(TODragonfly *dragonfly) {
    init_map_object_base(dragonfly, tl_05);
    *(s32 **)((s8 *)dragonfly + 0x18) = &(*(RecoveredGlobal_80164DEC___vt__11TODragonfly *)&__vt__11TODragonfly).value;
    *(s32 *)((s8 *)dragonfly + 0) = (s32) TODragonfly__class_name;
    dragonfly->m_cc = 0;
    *(f32 *)((s8 *)dragonfly + 0xD0) = (f32) (lbl_805DB594 + dragonfly->scale);
    VecCopy((Vec *)((u8 *)dragonfly + 0xD4), (const Vec *)((u8 *)dragonfly + 0x38));
    dragonfly->m_e8 = (f32) lbl_805DB580;
    *(f32 *)((s8 *)dragonfly + 0xE4) = (f32) lbl_805DB580;
    dragonfly->m_e0 = (f32) lbl_805DB580;
    dragonfly->m_f4 = (f32) ((lbl_805DB56C * (f32) dragonfly->m_84) + lbl_805DB560);
    dragonfly->m_f8 = (s32) (lbl_805DB570 * (lbl_805DB574 / (lbl_805DB578 / dragonfly->m_f4)));
    dragonfly->m_fc = (s32) (lbl_805DB570 * (lbl_805DB574 * (lbl_805DB57C * (f32) rand())));
    dragonfly->m_ec = (f32) ((lbl_805DB56C * (f32) *(s32 *)((s8 *)dragonfly + 0x88)) + lbl_805DB560);
    *(f32 *)((s8 *)dragonfly + 0xF0) = (f32) (dragonfly->m_ec * sin_table_lookup(dragonfly->m_fc));
    return (u8 *)dragonfly;
}
#pragma pop

__declspec(section ".data") const char *bm_fs_obj_tombo_model_names[2] = { lbl_80441100, NULL };
__declspec(section ".data") const char *bm_fs_obj_tombo_motion_names[2] = { lbl_80441110, NULL };
BmlResourceDescriptor dragonfly_cave01_resource_descriptor = { lbl_80441124, bm_fs_obj_tombo_model_names, bm_fs_obj_tombo_motion_names, 1, 1 };
__declspec(section ".data") const char *fs_obj_ex_entombo_model_names[2] = { lbl_80441138, NULL };
__declspec(section ".data") const char *fs_obj_ex_entombo_motion_names[2] = { lbl_80441150, NULL };
BmlResourceDescriptor TODragonflyCave01__resource_descriptor = { lbl_80441168, fs_obj_ex_entombo_model_names, fs_obj_ex_entombo_motion_names, 1, 1 };
}
