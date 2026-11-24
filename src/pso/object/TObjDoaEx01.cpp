#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "types.h"
#include "pso/object/TObjDoaEx01.h"
#include "pso/object/base/TObjMapObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/TObjDoaEx01_8018DFFC.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"

__declspec(section ".data") const char *fs_obj_ex_doa01_model_names[2] = { "fs_obj_ex_doa01.gj", NULL };
__declspec(section ".data") const char *fs_obj_ex_doa01_motion_names[2] = { "fs_obj_ex_doa01.njm", NULL };
BmlResourceDescriptor TObjDoaEx01__resource_descriptor = { "fs_obj_ex_doa01.bml", fs_obj_ex_doa01_model_names, fs_obj_ex_doa01_motion_names, 1, 1 };
CollisionBody TObjDoaEx01__collision_body_parts = {{0.0f, 20.0f, -5.0f}, 10.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TObjDoaEx01__name = "TObjDoaEx01";

BmlResource *TObjDoaEx01__resource_bundle;
u8 *TObjDoaEx01__alpha_model_node;
u8 *TObjDoaEx01__alpha_model_sibling;


struct Obj_8018DA54 {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    s32 state;
    u8 padb0[0xD0 - 0xB0];
    u32 flags;
};

struct Obj_8018DBCC {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    s32 state;
    u8 padb0[0xD0 - 0xB0];
    u32 flags;
    u8 padd4[0xD8 - 0xD4];
    f32 xd8;
};

extern "C" {


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjDoaEx01::update_closing() {
    u8 *arg0 = (u8 *)this;
    this->animation_frame = (f32) (this->animation_frame - this->animation_step);
    if (this->animation_frame < 0.0f) {
        this->animation_frame = 0.0f;
        this->object_state = 0;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    }
}
#pragma pop

void TObjDoaEx01::update_open() {
    Obj_8018DA54 *self = (Obj_8018DA54 *)this;
    if (self->flags & 1) {
        if (((TObjMapObject *)self)->is_any_player_within_radius_xz((f32)1e+04f) == 0) {
            this->object_state = 3;
            switch (get_current_floor_area()) {
            case AREA_VR_TEMPLE_ALPHA:
            case AREA_VR_TEMPLE_BETA:
                play_sound_effect(0x4BF0B, &position, 0, 0);
                break;
            case AREA_VR_SPACESHIP_ALPHA:
            case AREA_VR_SPACESHIP_BETA:
                play_sound_effect(0x4004AA0B, &position, 0, 0);
                break;
            default:
                play_sound_effect(0x4004AA0B, &position, 0, 0);
                break;
            }
        }
    } else {
        this->object_state = 3;
        switch (get_current_floor_area()) {
        case AREA_VR_TEMPLE_ALPHA:
        case AREA_VR_TEMPLE_BETA:
            play_sound_effect(0x4BF0B, &position, 0, 0);
            break;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            play_sound_effect(0x4004AA0B, &position, 0, 0);
            break;
        default:
            play_sound_effect(0x4004AA0B, &position, 0, 0);
            break;
        }
    }
}

void TObjDoaEx01::update_opening() {
    TObjDoaEx01 *self = this;
    self->animation_frame += self->animation_step;
    if (self->animation_frame > self->animation_end_frame - 1.0f) {
        self->animation_frame = self->animation_end_frame - 1.0f;
        self->object_state = 2;
    }
}
void TObjDoaEx01::update_closed() {
    Obj_8018DBCC *self = (Obj_8018DBCC *)this;
    if (self->flags & 1) {
        if (((TObjMapObject *)self)->is_any_player_within_radius_xz(4.9e+03f) == 1) {
            this->object_state = 1;
            ((TObjCollidable *)self)->set_indexed_flags(0, 8);
            switch (get_current_floor_area()) {
            case AREA_VR_TEMPLE_ALPHA:
            case AREA_VR_TEMPLE_BETA:
                play_sound_effect(0x4BF0B, &position, 0, 0);
                break;
            case AREA_VR_SPACESHIP_ALPHA:
            case AREA_VR_SPACESHIP_BETA:
                play_sound_effect(0x4004AA0B, &position, 0, 0);
                break;
            default:
                play_sound_effect(0x4004AA0B, &position, 0, 0);
                break;
            }
        }
    } else if (self->flags & 0x100000) {
        self->xd8 += 0.1f;
        if (1.0f <= self->xd8) {
            self->flags &= ~0x100000;
        }
    } else {
        self->xd8 -= 0.1f;
        if (self->xd8 <= 0.0f) {
            self->flags |= 0x100000;
        }
    }
}

s32 rotate_matrix_by_node_angles(void *, int);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

s32 draw_ginja_model_with_motion(saddr, s32, f32);

void TObjDoaEx01::draw_object_tree(saddr arg1) {
    NJS_OBJECT *obj = (NJS_OBJECT *)arg1;
    u32 flags = obj->evalflags;
    push_matrix();
    if (!(flags & 1)) {
        post_translate_matrix(obj->pos);
    }
    if (!(flags & 2)) {
        rotate_matrix_by_node_angles(obj->ang, flags & 0x20);
    }
    if (!(flags & 4)) {
        scale_current_matrix(obj->scl);
    }
    if (!(flags & 8) && obj->model != 0) {
        if ((u8 *)obj == TObjDoaEx01__alpha_model_node || (u8 *)obj == TObjDoaEx01__alpha_model_sibling) {
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            model_render_flags = model_render_flags | 0x10;
            set_constant_material((const NJS_ARGB *)(((u8 *)this + 0xD4)));
            draw_ginja_model(obj->model);
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            TParticleCtrl::end_effect_render();
        } else {
            draw_ginja_model(obj->model);
        }
    }
    if (obj->child != 0) {
        draw_object_tree((saddr)obj->child);
    }
    pop_matrix();
    if (obj->sibling != 0) {
        draw_object_tree((saddr)obj->sibling);
    }
}

void TObjDoaEx01::try_open() {
    saddr bml_model;

    bml_model = (saddr)get_bml_model(TObjDoaEx01__resource_bundle, 0);
    if (this->update_object_view_visibility(4e+02f, 2e+01f) != 0) {
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(TObjDoaEx01__alpha_model_node)->model, 1);
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(TObjDoaEx01__alpha_model_sibling)->model, 1);
        TObjFish::set_global_param(get_bml_texlist(TObjDoaEx01__resource_bundle, 0));
        push_matrix();
        post_translate_matrix(((u8 *)this) + 0x38);
        rotate_matrix_y(0, this->rotation_y);
        this->draw_object_tree(bml_model);
        pop_matrix();
    }
}
void TObjDoaEx01::draw_model() {
    f32 animation_frame;
    saddr temp_r31;
    s32 temp_r31_2;
    if (this->update_object_view_visibility(4e+02f, 2e+01f) != 0) {
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(TObjDoaEx01__alpha_model_node)->model, 0);
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(TObjDoaEx01__alpha_model_sibling)->model, 0);
        temp_r31 = (saddr)get_bml_model(TObjDoaEx01__resource_bundle, 0);
        TObjFish::set_global_param(get_bml_texlist(TObjDoaEx01__resource_bundle, 0));
        push_matrix();
        post_translate_matrix((void *) (((u8 *)this) + 0x38));
        rotate_matrix_y(0, (this->rotation_y));
        animation_frame = this->animation_frame;
        if (animation_frame > 0.0f) {
            temp_r31 = reinterpret_cast<saddr>(get_bml_motion(TObjDoaEx01__resource_bundle, 0));
            draw_ginja_model_with_motion((saddr)get_bml_model(TObjDoaEx01__resource_bundle, 0), temp_r31, animation_frame);
        } else {
            this->draw_object_tree((temp_r31));
        }
        pop_matrix();
    }
}


void TObjDoaEx01::render() {
    if (this->door_flags & 1) {
        draw_model();
        return;
    }
    try_open();
}

s32 init_collision_body_parts(void *, void *, int);

s32 free_collision_body_parts(void *);

}
TObjDoaEx01::~TObjDoaEx01() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


TObjDoaEx01::TObjDoaEx01(saddr parent, saddr set_data) : TODoorBase((TObject *)parent) {
    *(saddr *)((s8 *)this + 0) = (saddr) TObjDoaEx01__name;
    ((TObjDoaEx01 *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    ((TObjDoaEx01 *)(((u8 *)this)))->init_door_switch_binding();
    init_collision_body_parts(((u8 *)this), &TObjDoaEx01__collision_body_parts, 1);
    ((TObjCollidable *)this)->refresh_collision_body_centers();
    ((TObjPlayer *)this)->register_object_by_id();
    this->animation_frame = 0.0f;
    this->animation_step = 0.5f;
    this->animation_end_frame = (f32) *(u32 *)((s8 *)(get_bml_motion(TObjDoaEx01__resource_bundle, 0)) + 4);
    this->door_flags = 0x100001;
    *(f32 *)((s8 *)this + 0xD4) = 1.0f;
    this->m_d8 = 1.0f;
    *(f32 *)((s8 *)this + 0xDC) = 1.0f;
    this->m_e0 = 1.0f;
}

void *TObjDoaEx01::create(void *set_data) {
    void *o = (void *)new TObjDoaEx01((saddr)tl_05, (saddr)set_data);
    return o;
}

void TObjDoaEx01::free_resource() {
    if (TObjDoaEx01__resource_bundle != NULL) {
        delete TObjDoaEx01__resource_bundle;
        TObjDoaEx01__resource_bundle = NULL;
    }
}
void TObjDoaEx01::load_resources() {
    BmlResource *resource;
    u8 *temp_r3_2;
    resource = new BmlResource(1, &TObjDoaEx01__resource_descriptor, 0, 0, NULL);
    TObjDoaEx01__resource_bundle = resource;
    temp_r3_2 = (u8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(get_bml_model(resource, 0)) + 0x2C)) + 0x30)) + 0x2C)) + 0x2C));
    TObjDoaEx01__alpha_model_node = temp_r3_2;
    TObjDoaEx01__alpha_model_sibling = (u8 *)*(saddr *)((s8 *)temp_r3_2 + 0x30);
}

