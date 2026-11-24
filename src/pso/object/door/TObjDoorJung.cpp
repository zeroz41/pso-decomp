#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaTexture.h"
#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/base/TObjMotion.h"

struct BmlResource;
struct NJS_TEXLIST;

#include "pso/object/door/TODoorBase.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/system/scene/TScene.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D8F74.h"


const char *bm_obj_beamdoa_model_names[3] = {"fe_obj_beamdoa.gj", "fe_obj_beamdoa_singo.gj", NULL};
const char *bm_obj_beamdoa_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_beamdoa_resource_descriptor = {
    "bm_obj_beamdoa.bml", bm_obj_beamdoa_model_names, bm_obj_beamdoa_motion_names, 2, 0,
};
CollisionBody TObjDoorJung__collision_desc = {{0.0f, 20.0f, 0.0f}, 10.0f, 30.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TObjDoorJung__class_name = "TObjDoorJung";

s32 TObjDoorJung__child_table[4];
BmlResource *TObjDoorJung__resource_handle;
NJS_TEXLIST *lbl_805D5BD4;
s32 door_jung_child_list;
s32 lbl_805D5BDC;
void *TObjDoorJung__door_scene_buffer;
s32 lbl_805D5BE4;
s32 lbl_805D5BE8;
s32 lbl_805D5BEC;
s32 lbl_805D5BF0;

struct Jung_8018F808 { u8 pad0[0xC8]; s32 fC8; u8 padCC[4]; u32 fD0; s32 fD4; };

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
/* Ninja object node of the door model: model pointer, transform, then child and sibling links. */
struct Node_8018F4AC {
    u32 eval_flags;
    s32 model;
    f32 position[3];
    s32 angle[3];
    f32 scale[3];
    Node_8018F4AC *child;
    Node_8018F4AC *sibling;
};

void PPCSync();
s32 post_translate_matrix(void *);

s32 free_collision_body_parts(void *);
s32 minimap_render_gate(void *, s32, u16, s32, s32);

void TObjDoorJung::free_buffers() {
    if (TObjDoorJung__door_scene_buffer != NULL) {
        ((TScene *)TObjDoorJung__door_scene_buffer)->destroy_buffers(1);
        TObjDoorJung__door_scene_buffer = NULL;
    }
    if (TObjDoorJung__resource_handle != NULL) {
        delete (BmlResource *)TObjDoorJung__resource_handle;
        TObjDoorJung__resource_handle = NULL;
    }
}


void load_door_jung_resources(void) {
    saddr handle;
    Node_8018F4AC *model;
    Node_8018F4AC *node;
    void *scene;

    handle = (saddr)new BmlResource(5, &bm_obj_beamdoa_resource_descriptor, 0, 0, NULL);
    TObjDoorJung__resource_handle = (BmlResource *)handle;
    lbl_805D5BD4 = get_bml_texlist((BmlResource *)TObjDoorJung__resource_handle, 0);
    model = (Node_8018F4AC *)get_bml_model((BmlResource *)TObjDoorJung__resource_handle, 1);
    node = model->child;
    TObjDoorJung__child_table[0] = node->model;
    TObjDoorJung__child_table[1] = node->child->model;
    TObjDoorJung__child_table[2] = node->child->child->model;
    TObjDoorJung__child_table[3] = node->child->child->child->model;
    door_jung_child_list = model->child->sibling->model;
    lbl_805D5BDC = 0;
    const char *parts[4] = {"ts032_beamdoa_singo_aka", "ts032_beamdoa_singo_ao", "ts064_beamdoa_aka", "ts064_beamdoa_ao"};
    lbl_805D5BE4 = find_texture_entry_by_name(lbl_805D5BD4, parts[0]);
    lbl_805D5BE8 = find_texture_entry_by_name(lbl_805D5BD4, parts[1]);
    lbl_805D5BEC = find_texture_entry_by_name(lbl_805D5BD4, parts[2]);
    lbl_805D5BF0 = find_texture_entry_by_name(lbl_805D5BD4, parts[3]);
    if (lbl_805D5BEC != -1) {
        scene = (void *)::operator new(0x14);
        if (scene != NULL) {
            scene = ((TScene *)scene)->init_buffers((saddr)model->child->sibling, lbl_805D5BEC);
        }
        TObjDoorJung__door_scene_buffer = scene;
    } else {
        TObjDoorJung__door_scene_buffer = NULL;
    }
}

void TObjDoorJung::clamp_state() {
    this->active_light_count = this->set_params[1];
    if (this->active_light_count < 0) {
        this->active_light_count = 0;
    }
    if (this->active_light_count > 4) {
        this->active_light_count = 4;
    }
}

void TObjDoorJung::render() {
    s32 i;
    s32 j;

    if (this->update_object_view_visibility(650.0f, 30.0f) != 0) {
        if (this->door_flags & 1) {
            if (lbl_805D5BF0 >= 0) {
                set_ginja_model_texture_slot(reinterpret_cast<void *>(door_jung_child_list), static_cast<u16>(lbl_805D5BF0));
            }
        } else if (lbl_805D5BEC >= 0) {
            set_ginja_model_texture_slot(reinterpret_cast<void *>(door_jung_child_list), static_cast<u16>(lbl_805D5BEC));
        }
        if (actor_frame_tick != lbl_805D5BDC) {
            if (TObjDoorJung__door_scene_buffer != NULL) {
                ((TScene *)TObjDoorJung__door_scene_buffer)->offset_position(0, -0xA);
            }
            lbl_805D5BDC = actor_frame_tick;
            PPCSync();
        }
        for (i = 0; i < this->active_light_count; i++) {
            if (is_current_floor_switch_set((u16)(this->switch_id + i)) == 1) {
                if (lbl_805D5BE8 >= 0) {
                    set_ginja_model_texture_slot(reinterpret_cast<void *>(TObjDoorJung__child_table[i]), static_cast<u16>(lbl_805D5BE8));
                }
            } else if (lbl_805D5BE4 >= 0) {
                set_ginja_model_texture_slot(reinterpret_cast<void *>(TObjDoorJung__child_table[i]), static_cast<u16>(lbl_805D5BE4));
            }
        }
        for (j = this->active_light_count; j < 4; j++) {
            if (lbl_805D5BE8 >= 0) {
                set_ginja_model_texture_slot(reinterpret_cast<void *>(TObjDoorJung__child_table[j]), static_cast<u16>(lbl_805D5BE8));
            }
        }
        TObjFish::set_global_param(lbl_805D5BD4);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object((Node_8018F4AC *)get_bml_model((BmlResource *)TObjDoorJung__resource_handle, 0));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object((Node_8018F4AC *)get_bml_model((BmlResource *)TObjDoorJung__resource_handle, 1));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}


void TObjDoorJung::update_door_switch_state() {
    s32 ok = 1;
    s32 i = 0;
    while (i < ((Jung_8018F808 *)this)->fD4) {
        s32 t = is_current_floor_switch_set((u16)(((Jung_8018F808 *)this)->fC8 + i)) - 1;
        i++;
        ok = (t == 0) ? (ok & 1) : 0;
    }
    if (ok != 0) {
        ((Jung_8018F808 *)this)->fD0 |= 1;
        set_indexed_flags(0, 8);
        return;
    }
    ((Jung_8018F808 *)this)->fD0 &= ~1;
    ((TObjCollidable *)((Jung_8018F808 *)this))->clear_player_status_flag(0, 8);
}

void TObjDoorJung::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((s32) switch_doors_force_closed != 0) {
        this->door_flags = (s32) (this->door_flags & 0xFFFFFFFE);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    } else {
        this->update_door_switch_state();
    }
    if (this->door_flags & 1) {
        minimap_render_gate((u8 *)&this->position, 0xFF00FF00, (u16) this->rotation_y, 0, 0);
        return;
    }
    minimap_render_gate((u8 *)&this->position, 0xFFFF0000, (u16) this->rotation_y, 0, 0);
}

}
TObjDoorJung::~TObjDoorJung() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

TObjDoorJung::TObjDoorJung(TObject *parent, void *set_data) : TODoorBase(parent) {
    this->m_name = TObjDoorJung__class_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &TObjDoorJung__collision_desc, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
    clamp_state();
}

