#include "types.h"
#include "pso/object/door/TODoorFourLightRuins.h"
#include "pso/object/door/TODoorFourLightSpace.h"
#include "pso/render/NinjaUtil.h"
#include "pso/unk/text_8028A714.h"
#include "pso/object/base/TObjMapObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/object/ambient/TObjFish.h"


#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_8028A820.h"

#include "pso/object/door/TODoorAncient01.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/render/ModelDrawContext.h"

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

struct Door_80289EE0 { u8 pad[0xD8]; saddr sw[8]; };


extern "C" {
s32 init_collision_body_parts(void *, void *, int);
u8 is_current_floor_switch_set(u16);
s32 post_translate_matrix(void *);
void fn_802898E8(void);
void fn_802898EC(void);
void free_collision_body_parts(void *);

}


struct Tbl_8028A5C4 { s32 v[8]; };

const char *TODoorFourLightRuins__class_name = "TODoorFourLightRuins";
const Tbl_8028A5C4 door_four_light_ruins_index_table = {3, 4, 6, 8, 2, 5, 7, 9};
const char *TODoorFourLightSpace__class_name = "TODoorFourLightSpace";
const Tbl_80289EE0 door_four_light_space_index_table = {4, 6, 8, 10, 5, 7, 9, 11};
#pragma defer_codegen on

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
TODoorFourLightRuins::TODoorFourLightRuins(saddr parent, saddr set_data) : TODoorBase((TObject *)parent) {
    s32 i;
    *(saddr *)((s8 *)this + 0) = (saddr) TODoorFourLightRuins__class_name;
    ((TODoorFourLightRuins *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    ((TODoorFourLightRuins *)(((u8 *)this)))->init_door_switch_binding();
    init_collision_body_parts(((u8 *)this), &TODoorFourLight__collision_body_params, 1);
    ((TObjCollidable *)this)->refresh_collision_body_centers();
    ((TObjPlayer *)this)->register_object_by_id();
    this->m_d4 = (saddr)fn_8028A78C(0);
    this->texlist = fn_8028A750(0);
    *(u8 **)((s8 *)this + 0xBC) = fn_8028A714(0);
    this->animation_end_frame = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)this + 0xBC)) + 4) - 1.0f);
    this->animation_step = 0.5f;
    {
        Tbl_8028A5C4 t = door_four_light_ruins_index_table;
        for (i = 0; i < 8; i++) {
            this->light_nodes[i] = find_object_node((NJS_OBJECT *)(this->m_d4), t.v[i]);
        }
    }
}

#pragma pop

TODoorFourLightRuins::~TODoorFourLightRuins() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TODoorFourLightRuins::render() {
    u8 *arg0 = (u8 *)this;
    s32 cc;

    if ((this->update_object_view_visibility(this->view_range, this->model_radius) == 1) && (((TObjMapObject *)arg0)->is_in_view_depth(30.0f) == 1)) {
        switch (this->object_state) {
        case 1:
        case 3:
            push_matrix();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion((void *)this->m_d4, (void *)this->motion, this->animation_frame);
            pop_matrix();
            return;
        case 2:
            push_matrix();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion((void *)this->m_d4, (void *)this->motion, this->animation_end_frame);
            pop_matrix();
            return;
        case 0:
            cc = this->lock_mode;
            if ((cc == 2) || (cc == 3)) {
                draw_model_and_lights();
                return;
            }
            push_matrix();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_object((void *)this->m_d4);
            pop_matrix();
            break;
        }
    }
}

void TODoorFourLightRuins::draw_model_and_lights() {
    s32 lit[4];
    NJS_OBJECT **lamp;
    NJS_OBJECT **glow;
    for (s32 k = 0; k < 4; k++) {
        lit[k] = 1;
    }
    if (!(this->door_flags & DOOR_FLAG_UNLOCKED)) {
        s32 j;
        for (j = 0; j < this->set_params[1]; j++) {
            if (is_current_floor_switch_set(this->switch_id + j) == 1) {
                lit[j] = 1;
            } else {
                lit[j] = 0;
            }
        }
    }
    lamp = &this->light_nodes[0];
    glow = &this->light_nodes[4];
    {
    NJS_OBJECT *body = (NJS_OBJECT *)this->m_d4;
    push_matrix();
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    post_translate_matrix(&this->position);
    rotate_matrix_y(0, this->rotation_y);
    draw_ginja_model(body->model);
    draw_ginja_model(body->child->model);
    }
    TParticleCtrl::begin_effect_render();
    for (s32 i = 0; i < 4; i++) {
        if (lit[i] == 1) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
        } else {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        }
        if (*lamp != 0) {
            push_matrix();
            post_translate_matrix((*lamp)->pos);
            draw_ginja_model((*lamp)->model);
            pop_matrix();
        }
        if (*glow != 0) {
            push_matrix();
            post_translate_matrix((*glow)->pos);
            draw_ginja_model((*glow)->model);
            pop_matrix();
        }
        lamp++;
        glow++;
    }
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

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
        for (i = 0; i < this->set_params[1]; i++) {
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
        for (j = 0; j < this->set_params[1]; j++) {
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
    s32 switch_id;

    this->switch_id = (s32) this->set_params[0];
    switch_id = this->switch_id;
    if (switch_id > 0x100) {
        this->lock_mode = 0;
    } else if (switch_id < 0) {
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


TODoorFourLightSpace::TODoorFourLightSpace(saddr parent, saddr set_data) : TODoorBase((TObject *)parent) {
    s32 i;
    *(saddr *)((s8 *)this + 0) = (saddr) TODoorFourLightSpace__class_name;
    ((TODoorFourLightSpace *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    ((TODoorFourLightSpace *)(((u8 *)this)))->init_door_switch_binding();
    init_collision_body_parts(((u8 *)this), &TODoorFourLight__collision_body_params, 1);
    ((TObjCollidable *)this)->refresh_collision_body_centers();
    ((TObjPlayer *)this)->register_object_by_id();
    this->m_d4 = (saddr)fn_8028A78C(0);
    this->texlist = fn_8028A750(0);
    *(u8 **)((s8 *)this + 0xBC) = fn_8028A714(0);
    this->animation_end_frame = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)this + 0xBC)) + 4) - 1.0f);
    this->animation_step = 0.5f;
    {
        Tbl_80289EE0 t = door_four_light_space_index_table;
        for (i = 0; i < 8; i++) {
            ((Door_80289EE0 *)this)->sw[i] = (saddr)find_object_node((NJS_OBJECT *)(this->m_d4), t.v[i]);
        }
    }
}

TODoorFourLightSpace::~TODoorFourLightSpace() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TODoorFourLightSpace::render() {
    u8 *arg0 = (u8 *)this;
    s32 cc;

    if ((this->update_object_view_visibility(this->view_range, this->model_radius) == 1) && (((TObjMapObject *)arg0)->is_in_view_depth(30.0f) == 1)) {
        switch (this->object_state) {
        case 1:
        case 3:
            push_matrix();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion((void *)this->m_d4, (void *)this->motion, this->animation_frame);
            pop_matrix();
            return;
        case 2:
            push_matrix();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_model_with_motion((void *)this->m_d4, (void *)this->motion, this->animation_end_frame);
            pop_matrix();
            return;
        case 0:
            cc = this->lock_mode;
            if ((cc == 2) || (cc == 3)) {
                draw_lights();
                return;
            }
            push_matrix();
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_object((void *)this->m_d4);
            pop_matrix();
            break;
        }
    }
}

void TODoorFourLightSpace::draw_lights() {
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
        for (j = 0; j < this->set_params[1]; j++) {
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
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix(mdl + 8);
    push_matrix();
    post_translate_matrix(*(u8 **)((s8 *)mdl + 0x2C) + 8);
    draw_ginja_model(*(void **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 4));
    pop_matrix();
    post_translate_matrix(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30) + 8);
    draw_ginja_model(*(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30)) + 4));
    post_translate_matrix(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30)) + 0x2C) + 8);
    draw_ginja_model(*(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)mdl + 0x2C)) + 0x30)) + 0x2C)) + 4));
    TParticleCtrl::begin_effect_render();
    i = 0;
    do {
        if (flags[i] == 1) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((saddr)get_green_door_textures()));
        } else {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        }
        if (*pa != NULL) {
            push_matrix();
            post_translate_matrix(*pa + 8);
            draw_ginja_model(*(void **)((s8 *)(*pa) + 4));
            pop_matrix();
        }
        if (*pb != NULL) {
            push_matrix();
            post_translate_matrix(*pb + 8);
            draw_ginja_model(*(void **)((s8 *)(*pb) + 4));
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
        for (i = 0; i < this->set_params[1]; i++) {
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
            for (j = 0; j < this->set_params[1]; j++) {
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
    s32 switch_id;

    this->switch_id = (s32) this->set_params[0];
    switch_id = this->switch_id;
    if (switch_id > 0x100) {
        this->lock_mode = 0;
    } else if (switch_id < 0) {
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
