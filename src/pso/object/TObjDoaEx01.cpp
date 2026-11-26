#include "pso/system/BmlResource.h"
#include "pso/object/base/TObjCollidable.h"
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
#include "pso/object/door/TODoorBase.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/map/FloorArea.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/render/ModelDrawContext.h"

__declspec(section ".data") const char *fs_obj_ex_doa01_model_names[2] = { "fs_obj_ex_doa01.gj", NULL };
__declspec(section ".data") const char *fs_obj_ex_doa01_motion_names[2] = { "fs_obj_ex_doa01.njm", NULL };
BmlResourceDescriptor doa_ex01_resource_descriptor = { "fs_obj_ex_doa01.bml", fs_obj_ex_doa01_model_names, fs_obj_ex_doa01_motion_names, 1, 1 };
CollisionBody doa_ex01_collision_body_parts = {{0.0f, 20.0f, -5.0f}, 10.0f, 20.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *doa_ex01_name = "TObjDoaEx01";

BmlResource *doa_ex01_resource_bundle;
u8 *doa_ex01_alpha_model_node;
u8 *doa_ex01_alpha_model_sibling;


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjDoaEx01::update_closing() {
    this->animation_frame = (f32) (this->animation_frame - this->animation_step);
    if (this->animation_frame < 0.0f) {
        this->animation_frame = 0.0f;
        this->object_state = 0;
        clear_player_status_flag(0, 8);
    }
}
#pragma pop

void TObjDoaEx01::update_open() {
    if (door_flags & 1) {
        if (is_any_player_within_radius_xz((f32)1e+04f) == 0) {
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
    this->animation_frame += this->animation_step;
    if (this->animation_frame > this->animation_end_frame - 1.0f) {
        this->animation_frame = this->animation_end_frame - 1.0f;
        this->object_state = 2;
    }
}
void TObjDoaEx01::update_closed() {
    if (door_flags & 1) {
        if (is_any_player_within_radius_xz(4.9e+03f) == 1) {
            this->object_state = 1;
            set_indexed_flags(0, 8);
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
    } else if (door_flags & 0x100000) {
        glow_phase += 0.1f;
        if (1.0f <= glow_phase) {
            door_flags &= ~0x100000;
        }
    } else {
        glow_phase -= 0.1f;
        if (glow_phase <= 0.0f) {
            door_flags |= 0x100000;
        }
    }
}


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
        if ((u8 *)obj == doa_ex01_alpha_model_node || (u8 *)obj == doa_ex01_alpha_model_sibling) {
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            model_render_flags = model_render_flags | 0x10;
            set_constant_material((const NJS_ARGB *)(((u8 *)this + 0xD4)));
            draw_ginja_model(obj->model);
            set_constant_material(&chunk_material_color_half_alpha_f32);
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

    bml_model = (saddr)get_bml_model(doa_ex01_resource_bundle, 0);
    if (this->update_object_view_visibility(4e+02f, 2e+01f) != 0) {
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(doa_ex01_alpha_model_node)->model, 1);
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(doa_ex01_alpha_model_sibling)->model, 1);
        TObjFish::set_global_param(get_bml_texlist(doa_ex01_resource_bundle, 0));
        push_matrix();
        post_translate_matrix(&this->position.x);
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
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(doa_ex01_alpha_model_node)->model, 0);
        set_ginja_model_texture_slot(reinterpret_cast<NJS_OBJECT *>(doa_ex01_alpha_model_sibling)->model, 0);
        temp_r31 = (saddr)get_bml_model(doa_ex01_resource_bundle, 0);
        TObjFish::set_global_param(get_bml_texlist(doa_ex01_resource_bundle, 0));
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, (this->rotation_y));
        animation_frame = this->animation_frame;
        if (animation_frame > 0.0f) {
            temp_r31 = reinterpret_cast<saddr>(get_bml_motion(doa_ex01_resource_bundle, 0));
            draw_ginja_model_with_motion(get_bml_model(doa_ex01_resource_bundle, 0), reinterpret_cast<void *>(temp_r31), animation_frame);
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
extern "C" {

s32 init_collision_body_parts(void *, void *, int);
}

TObjDoaEx01::~TObjDoaEx01() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


TObjDoaEx01::TObjDoaEx01(saddr parent, saddr set_data) : TODoorBase((TObject *)parent) {
    *(saddr *)((s8 *)this + 0) = (saddr) doa_ex01_name;
    ((TObjDoaEx01 *)(((u8 *)this)))->apply_object_set_data((void *)set_data);
    ((TObjDoaEx01 *)(((u8 *)this)))->init_door_switch_binding();
    init_collision_body_parts(((u8 *)this), &doa_ex01_collision_body_parts, 1);
    ((TObjCollidable *)this)->refresh_collision_body_centers();
    ((TObjPlayer *)this)->register_object_by_id();
    this->animation_frame = 0.0f;
    this->animation_step = 0.5f;
    this->animation_end_frame = (f32) *(u32 *)((s8 *)(get_bml_motion(doa_ex01_resource_bundle, 0)) + 4);
    this->door_flags = 0x100001;
    *(f32 *)((s8 *)this + 0xD4) = 1.0f;
    this->glow_phase = 1.0f;
    *(f32 *)((s8 *)this + 0xDC) = 1.0f;
    this->m_e0 = 1.0f;
}

void *TObjDoaEx01::create(void *set_data) {
    void *o = (void *)new TObjDoaEx01((saddr)tl_05, (saddr)set_data);
    return o;
}

void TObjDoaEx01::free_resource() {
    if (doa_ex01_resource_bundle != NULL) {
        delete doa_ex01_resource_bundle;
        doa_ex01_resource_bundle = NULL;
    }
}
void TObjDoaEx01::load_resources() {
    BmlResource *resource;
    u8 *temp_r3_2;
    resource = new BmlResource(1, &doa_ex01_resource_descriptor, 0, 0, NULL);
    doa_ex01_resource_bundle = resource;
    temp_r3_2 = (u8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(get_bml_model(resource, 0)) + 0x2C)) + 0x30)) + 0x2C)) + 0x2C));
    doa_ex01_alpha_model_node = temp_r3_2;
    doa_ex01_alpha_model_sibling = (u8 *)*(saddr *)((s8 *)temp_r3_2 + 0x30);
}

