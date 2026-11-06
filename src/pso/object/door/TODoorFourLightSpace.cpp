#include "types.h"
#include "pso/object/door/TODoorFourLightRuins.h"
#include "pso/object/door/TODoorFourLightSpace.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/text_8028A714.h"
#include "pso/object/base/TObjMapObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/object/door/TODoorFourLightRuins.h"
#include "pso/object/door/TODoorFourLightSpace.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

__declspec(section ".data") const char *bm_obj_door_ruins_model_names[2] = {"obj_o_vs2door02l.gj", NULL};
__declspec(section ".data") const char *bm_obj_door_ruins_motion_names[2] = {"obj_o_vs2door02l.njm", NULL};
BmlResourceDescriptor bm_obj_door_ruins_resource_descriptor = {"bm_obj_door_ruins.bml", bm_obj_door_ruins_model_names, bm_obj_door_ruins_motion_names, 1, 1};
__declspec(section ".data") const char *bm_obj_door_space_model_names[2] = {"fs_obj_ex_doa02.gj", NULL};
__declspec(section ".data") const char *bm_obj_door_space_motion_names[2] = {"fs_obj_ex_doa02.njm", NULL};
BmlResourceDescriptor bm_obj_door_space_resource_descriptor = {"bm_obj_door_space.bml", bm_obj_door_space_model_names, bm_obj_door_space_motion_names, 1, 1};

CollisionBody TODoorFourLight__collision_body_params = {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

struct Tbl_80289EE0 { s32 v[8]; };

struct Door_80289EE0 { u8 pad[0xD8]; s32 sw[8]; };

struct Door_8028A28C {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x10];
    u8 f38[0x28];
    s32 f60;
    u8 pad64[0x24];
    s32 f88;
    u8 pad8c[0x3C];
    s32 fc8;
    u8 padcc[4];
    s32 fd0;
    u8 *fd4;
    u8 *fd8[4];
    u8 *fe8[4];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__10TODoorBaseFP7TObject();
extern s32 __vt__20TODoorFourLightSpace[];
u8 *TODoorFourLightSpace__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 is_current_floor_switch_set(u16);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 set_global_param__8TObjFishFl();
void draw_ginja_model(s32);
struct Base_802898E8 { char pad[0x18]; };
struct VObj_802898E8 : Base_802898E8 {
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

void *__dt__20TODoorFourLightSpaceFv(void *arg0, s16 arg1);
void fn_802898E8(void);
void fn_802898EC(void);
void draw_ginja_object(void *child);
s32 draw_ginja_model_with_motion(s32, s32, f32);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
s32 get_main_phase();

}

extern "C" {

struct Base_8028A030 { char pad[0x18]; };
struct VObj_8028A030 : Base_8028A030 {
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

void *__dt__20TODoorFourLightRuinsFv(void *arg0, s16 arg1);

}

extern "C" {

extern s32 __vt__20TODoorFourLightRuins[];

}

struct Tbl_8028A5C4 { s32 v[8]; };
struct Door_8028A5C4 { u8 pad[0xD8]; s32 sw[8]; };

const char *TODoorFourLightRuins__class_name = "TODoorFourLightRuins";
const Tbl_8028A5C4 door_four_light_ruins_index_table = {3, 4, 6, 8, 2, 5, 7, 9};
const char *TODoorFourLightSpace__class_name = "TODoorFourLightSpace";
const Tbl_80289EE0 door_four_light_space_index_table = {4, 6, 8, 10, 5, 7, 9, 11};
extern "C" {


}

#pragma defer_codegen on

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
u8 *TODoorFourLightRuins__ct(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;

    __ct__10TODoorBaseFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TODoorFourLightRuins;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorFourLightRuins__class_name;
    ((TODoorFourLightRuins *)(arg0))->apply_object_set_data((void *)arg2);
    ((TODoorFourLightRuins *)(arg0))->init_door_switch_binding();
    init_collision_body_parts(arg0, &TODoorFourLight__collision_body_params, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorFourLightRuins *)arg0)->m_d4 = (s32)fn_8028A78C(0);
    ((TODoorFourLightRuins *)arg0)->texlist = (s32)fn_8028A750(0);
    *(u8 **)((s8 *)arg0 + 0xBC) = fn_8028A714(0);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1.0f);
    ((TODoorFourLightRuins *)arg0)->animation_step = 0.5f;
    {
        Tbl_8028A5C4 t = door_four_light_ruins_index_table;
        for (i = 0; i < 8; i++) {
            ((Door_8028A5C4 *)arg0)->sw[i] = (s32)find_object_node((NJS_OBJECT *)(((TODoorFourLightRuins *)arg0)->m_d4), t.v[i]);
        }
    }
    return arg0;
}
}

#pragma pop

TODoorFourLightRuins::~TODoorFourLightRuins() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TODoorFourLightRuins::render() {
    u8 *arg0 = (u8 *)this;
    s32 cc;

    if ((((VObj_8028A030 *)arg0)->m8(this->view_range, *(f32 *)&this->model_radius) == 1) && (((TObjMapObject *)arg0)->is_in_view_depth(30.0f) == 1)) {
        switch (*(s32 *)&this->object_state) {
        case 1:
        case 3:
            push_matrix();
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion(*(s32 *)&this->m_d4, *(s32 *)&this->motion, this->animation_frame);
            pop_matrix();
            return;
        case 2:
            push_matrix();
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion(*(s32 *)&this->m_d4, *(s32 *)&this->motion, this->animation_end_frame);
            pop_matrix();
            return;
        case 0:
            cc = this->lock_mode;
            if ((cc == 2) || (cc == 3)) {
                TODoorFourLightRuins::draw_model_and_lights(arg0);
                return;
            }
            push_matrix();
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_object((void *)(*(s32 *)&this->m_d4));
            pop_matrix();
            break;
        }
    }
}

typedef s32 (*SetParam_8028A28C)(s32);
#define self ((Door_8028A28C *)arg0)
s32 TODoorFourLightRuins::draw_model_and_lights(void *arg0) {
    s32 lit[4];
    u8 **a;
    u8 **b;
    for (s32 k = 0; k < 4; k++) {
        lit[k] = 1;
    }
    if (!(self->fd0 & 1)) {
        s32 j;
        for (j = 0; j < self->f88; j++) {
            if (is_current_floor_switch_set(self->fc8 + j) == 1) {
                lit[j] = 1;
            } else {
                lit[j] = 0;
            }
        }
    }
    a = self->fd8;
    b = self->fe8;
    {
    u8 *p = self->fd4;
    push_matrix();
    ((SetParam_8028A28C)set_global_param__8TObjFishFl)(self->f24);
    post_translate_matrix(self->f38);
    rotate_matrix_y(0, self->f60);
    draw_ginja_model(*(s32 *)((s8 *)p + 4));
    draw_ginja_model(*(s32 *)((s8 *)(*(u8 **)((s8 *)p + 0x2C)) + 4));
    }
    TParticleCtrl::begin_effect_render();
    for (s32 i = 0; i < 4; i++) {
        if (lit[i] == 1) {
            ((SetParam_8028A28C)set_global_param__8TObjFishFl)(TBoss8Dragon::get_instance());
        } else {
            ((SetParam_8028A28C)set_global_param__8TObjFishFl)(self->f24);
        }
        if (*a != 0) {
            push_matrix();
            post_translate_matrix(*a + 8);
            draw_ginja_model(*(s32 *)((s8 *)(*a) + 4));
            pop_matrix();
        }
        if (*b != 0) {
            push_matrix();
            post_translate_matrix(*b + 8);
            draw_ginja_model(*(s32 *)((s8 *)(*b) + 4));
            pop_matrix();
        }
        a++;
        b++;
    }
    TParticleCtrl::end_effect_render();
    pop_matrix();
}
#undef self

void TODoorFourLightRuins::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    s32 off;
    s32 i;
    s32 off2;
    s32 j;
    switch (this->lock_mode) {
    case 1:
        ((TODoorBase *)arg0)->play_door_sound();
        this->door_flags |= 1;
        break;
    case 2:
        off = 0;
        for (i = 0; i < *(s32 *)&this->set_params[1]; i++) {
            if (is_current_floor_switch_set(this->switch_id + i) == 0) {
                off = 1;
            }
        }
        if (off != 0) {
            this->door_flags &= ~1;
        } else {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags |= 1;
        }
        break;
    case 3:
        if (this->door_flags & 1) {
            break;
        }
        off2 = 0;
        for (j = 0; j < *(s32 *)&this->set_params[1]; j++) {
            if (is_current_floor_switch_set(this->switch_id + j) == 0) {
                off2 = 1;
            }
        }
        if (off2 != 0) {
            this->door_flags &= ~1;
        } else {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags |= 1;
        }
        if (off2 == 0 && this->set_entry != 0 && ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) == 1) {
            sp8 = 1;
            ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
            ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        }
        break;
    default:
        this->door_flags &= ~1;
        break;
    }
}

void TODoorFourLightRuins::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
        this->door_flags = (s32) (this->door_flags | 1);
    }
}

s32 TODoorFourLightRuins::init_door_switch_binding() {
    s32 temp_r0;

    this->switch_id = (s32) this->set_params[0];
    temp_r0 = this->switch_id;
    if (temp_r0 > 0x100) {
        this->lock_mode = 0;
    } else if (temp_r0 < 0) {
        this->lock_mode = 1;
    } else if ((s32) this->set_params[2] < 0) {
        if ((get_main_phase() == 0xF) || (TRaderMapCore::is_not_split_screen() == 1)) {
            this->lock_mode = 3;
        } else {
            this->lock_mode = 2;
        }
    } else {
        this->lock_mode = 2;
    }
    return this->switch_id;
}

extern "C" {
u8 *TODoorFourLightSpace__ct(u8 *arg0, s32 arg1, s32 arg2) {
    s32 i;
    __ct__10TODoorBaseFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TODoorFourLightSpace;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorFourLightSpace__class_name;
    ((TODoorFourLightSpace *)(arg0))->apply_object_set_data((void *)arg2);
    ((TODoorFourLightSpace *)(arg0))->init_door_switch_binding();
    init_collision_body_parts(arg0, &TODoorFourLight__collision_body_params, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorFourLightSpace *)arg0)->m_d4 = (s32)fn_8028A78C(0);
    ((TODoorFourLightSpace *)arg0)->texlist = (s32)fn_8028A750(0);
    *(u8 **)((s8 *)arg0 + 0xBC) = fn_8028A714(0);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1.0f);
    ((TODoorFourLightSpace *)arg0)->animation_step = 0.5f;
    {
        Tbl_80289EE0 t = door_four_light_space_index_table;
        for (i = 0; i < 8; i++) {
            ((Door_80289EE0 *)arg0)->sw[i] = (s32)find_object_node((NJS_OBJECT *)(((TODoorFourLightSpace *)arg0)->m_d4), t.v[i]);
        }
    }
    return arg0;
}
}

TODoorFourLightSpace::~TODoorFourLightSpace() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TODoorFourLightSpace::render() {
    u8 *arg0 = (u8 *)this;
    s32 cc;

    if ((((VObj_802898E8 *)arg0)->m8(this->view_range, *(f32 *)&this->model_radius) == 1) && (((TObjMapObject *)arg0)->is_in_view_depth(30.0f) == 1)) {
        switch (*(s32 *)&this->object_state) {
        case 1:
        case 3:
            push_matrix();
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion(*(s32 *)&this->m_d4, *(s32 *)&this->motion, this->animation_frame);
            pop_matrix();
            return;
        case 2:
            push_matrix();
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion(*(s32 *)&this->m_d4, *(s32 *)&this->motion, *(f32 *)&this->animation_end_frame);
            pop_matrix();
            return;
        case 0:
            cc = this->lock_mode;
            if ((cc == 2) || (cc == 3)) {
                draw_lights();
                return;
            }
            push_matrix();
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_object((void *)(*(s32 *)&this->m_d4));
            pop_matrix();
            break;
        }
    }
}

s32 TODoorFourLightSpace::draw_lights() {
    u8 *self = (u8 *)this;
    s32 flags[4];
    s32 i;
    u8 *mdl;
    u8 **pa;
    u8 **pb;
    for (i = 0; i < 4; i++) {
        flags[i] = 1;
    }
    if (!(this->door_flags & 1)) {
        s32 j;
        for (j = 0; j < *(s32 *)&this->set_params[1]; j++) {
            if (is_current_floor_switch_set(this->switch_id + j) == 1) {
                flags[j] = 1;
            } else {
                flags[j] = 0;
            }
        }
    }
    mdl = *(u8 * *)&this->m_d4;
    pa = (u8 **)(self + 0xD8);
    pb = (u8 **)(self + 0xE8);
    push_matrix();
    ((void (*)(s32))set_global_param__8TObjFishFl)(this->texlist);
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix(mdl + 8);
    push_matrix();
    post_translate_matrix(*(u8 **)((s8 *)mdl + 0x2C) + 8);
    draw_ginja_model(*(s32 *)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 4));
    pop_matrix();
    post_translate_matrix(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30) + 8);
    draw_ginja_model(*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30)) + 4));
    post_translate_matrix(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30)) + 0x2C) + 8);
    draw_ginja_model(*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30)) + 0x2C)) + 4));
    TParticleCtrl::begin_effect_render();
    i = 0;
    do {
        if (flags[i] == 1) {
            TBoss8Dragon::get_instance();
            set_global_param__8TObjFishFl();
        } else {
            ((void (*)(s32))set_global_param__8TObjFishFl)(this->texlist);
        }
        if (*pa != NULL) {
            push_matrix();
            post_translate_matrix(*pa + 8);
            draw_ginja_model(*(s32 *)((s8 *)(*pa) + 4));
            pop_matrix();
        }
        if (*pb != NULL) {
            push_matrix();
            post_translate_matrix(*pb + 8);
            draw_ginja_model(*(s32 *)((s8 *)(*pb) + 4));
            pop_matrix();
        }
        i++;
        pa++;
        pb++;
    } while (i < 4);
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TODoorFourLightSpace::update_door_switch_state() {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    s32 fail;
    s32 i;
    switch (this->lock_mode) {
    case 1:
        ((TODoorBase *)arg0)->play_door_sound();
        this->door_flags |= 1;
        break;
    case 2:
        fail = 0;
        for (i = 0; i < *(s32 *)&this->set_params[1]; i++) {
            if (is_current_floor_switch_set(this->switch_id + i) == 0) {
                fail = 1;
            }
        }
        if (fail != 0) {
            this->door_flags &= ~1;
        } else {
            ((TODoorBase *)arg0)->play_door_sound();
            this->door_flags |= 1;
        }
        break;
    case 3:
        if (!(this->door_flags & 1)) {
            s32 bad;
            s32 j;
            bad = 0;
            for (j = 0; j < *(s32 *)&this->set_params[1]; j++) {
                if (is_current_floor_switch_set(this->switch_id + j) == 0) {
                    bad = 1;
                }
            }
            if (bad == 0) {
                ((TODoorBase *)arg0)->play_door_sound();
                this->door_flags |= 1;
            } else {
                this->door_flags &= ~1;
            }
            if (bad == 0 && this->set_entry != 0 &&
                ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) == 1) {
                sp8 = 1;
                ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
                ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
            }
        }
        break;
    default:
        this->door_flags &= ~1;
        break;
    }
}

void TODoorFourLightSpace::vfunc_6(s16 *arg1, s32) {
    if ((s16) *arg1 == 1) {
        this->door_flags = (s32) (this->door_flags | 1);
    }
}

s32 TODoorFourLightSpace::init_door_switch_binding() {
    s32 temp_r0;

    this->switch_id = (s32) this->set_params[0];
    temp_r0 = this->switch_id;
    if (temp_r0 > 0x100) {
        this->lock_mode = 0;
    } else if (temp_r0 < 0) {
        this->lock_mode = 1;
    } else if ((s32) this->set_params[2] < 0) {
        if ((get_main_phase() == 0xF) || (TRaderMapCore::is_not_split_screen() == 1)) {
            this->lock_mode = 3;
        } else {
            this->lock_mode = 2;
        }
    } else {
        this->lock_mode = 2;
    }
    return this->switch_id;
}

void fn_802898EC(void) {  }

void fn_802898E8(void) {  }
