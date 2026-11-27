#include "pso/system/BmlResource.h"
#include "pso/object/base/TObjCollidable.h"
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
#include "pso/system/scene/UvScrollBuffer.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/MatrixReflect.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/MatrixStack.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/base/ActorCollision.h"


const char *bm_obj_beamdoa_model_names[3] = {"fe_obj_beamdoa.gj", "fe_obj_beamdoa_singo.gj", NULL};
const char *bm_obj_beamdoa_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_beamdoa_resource_descriptor = {
    "bm_obj_beamdoa.bml", bm_obj_beamdoa_model_names, bm_obj_beamdoa_motion_names, 2, 0,
};
CollisionBody door_jung_collision_desc = {{0.0f, 20.0f, 0.0f}, 10.0f, 30.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *door_jung_class_name = "TObjDoorJung";

GinjaModel *door_jung_child_table[4];
BmlResource *door_jung_resource_handle;
NJS_TEXLIST *door_jung_texlist;
GinjaModel *door_jung_child_list;
s32 door_jung_scroll_tick;
UvScrollBuffer *door_jung_door_scene_buffer;
s32 door_jung_signal_red_texture;
s32 door_jung_signal_blue_texture;
s32 door_jung_beam_red_texture;
s32 door_jung_beam_blue_texture;



void TObjDoorJung::free_buffers() {
    if (door_jung_door_scene_buffer != NULL) {
        delete door_jung_door_scene_buffer;
        door_jung_door_scene_buffer = NULL;
    }
    if (door_jung_resource_handle != NULL) {
        delete door_jung_resource_handle;
        door_jung_resource_handle = NULL;
    }
}


void load_door_jung_resources(void) {
    saddr handle;
    NJS_OBJECT *model;
    NJS_OBJECT *node;

    handle = (saddr)new BmlResource(5, &bm_obj_beamdoa_resource_descriptor, 0, 0, NULL);
    door_jung_resource_handle = (BmlResource *)handle;
    door_jung_texlist = get_bml_texlist(door_jung_resource_handle, 0);
    model = get_bml_model(door_jung_resource_handle, 1);
    node = model->child;
    door_jung_child_table[0] = node->ginja_model;
    door_jung_child_table[1] = node->child->ginja_model;
    door_jung_child_table[2] = node->child->child->ginja_model;
    door_jung_child_table[3] = node->child->child->child->ginja_model;
    door_jung_child_list = model->child->sibling->ginja_model;
    door_jung_scroll_tick = 0;
    const char *parts[4] = {"ts032_beamdoa_singo_aka", "ts032_beamdoa_singo_ao", "ts064_beamdoa_aka", "ts064_beamdoa_ao"};
    door_jung_signal_red_texture = find_texture_entry_by_name(door_jung_texlist, parts[0]);
    door_jung_signal_blue_texture = find_texture_entry_by_name(door_jung_texlist, parts[1]);
    door_jung_beam_red_texture = find_texture_entry_by_name(door_jung_texlist, parts[2]);
    door_jung_beam_blue_texture = find_texture_entry_by_name(door_jung_texlist, parts[3]);
    if (door_jung_beam_red_texture != -1) {
        door_jung_door_scene_buffer = new UvScrollBuffer(model->child->sibling, door_jung_beam_red_texture);
    } else {
        door_jung_door_scene_buffer = NULL;
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
            if (door_jung_beam_blue_texture >= 0) {
                set_ginja_model_texture_slot(door_jung_child_list, static_cast<u16>(door_jung_beam_blue_texture));
            }
        } else if (door_jung_beam_red_texture >= 0) {
            set_ginja_model_texture_slot(door_jung_child_list, static_cast<u16>(door_jung_beam_red_texture));
        }
        if (actor_frame_tick != door_jung_scroll_tick) {
            if (door_jung_door_scene_buffer != NULL) {
                door_jung_door_scene_buffer->offset_position(0, -0xA);
            }
            door_jung_scroll_tick = actor_frame_tick;
            PPCSync();
        }
        for (i = 0; i < this->active_light_count; i++) {
            if (is_current_floor_switch_set((u16)(this->switch_id + i)) == 1) {
                if (door_jung_signal_blue_texture >= 0) {
                    set_ginja_model_texture_slot(door_jung_child_table[i], static_cast<u16>(door_jung_signal_blue_texture));
                }
            } else if (door_jung_signal_red_texture >= 0) {
                set_ginja_model_texture_slot(door_jung_child_table[i], static_cast<u16>(door_jung_signal_red_texture));
            }
        }
        for (j = this->active_light_count; j < 4; j++) {
            if (door_jung_signal_blue_texture >= 0) {
                set_ginja_model_texture_slot(door_jung_child_table[j], static_cast<u16>(door_jung_signal_blue_texture));
            }
        }
        set_texture_list(door_jung_texlist);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation.y);
        draw_ginja_object(get_bml_model(door_jung_resource_handle, 0));
        begin_effect_render();
        draw_ginja_object(get_bml_model(door_jung_resource_handle, 1));
        end_effect_render();
        pop_matrix();
    }
}


void TObjDoorJung::update_door_switch_state() {
    s32 ok = 1;
    s32 i = 0;
    while (i < active_light_count) {
        s32 t = is_current_floor_switch_set((u16)(switch_id + i)) - 1;
        i++;
        ok = (t == 0) ? (ok & 1) : 0;
    }
    if (ok != 0) {
        door_flags |= 1;
        set_indexed_flags(0, 8);
        return;
    }
    door_flags &= ~1;
    clear_player_status_flag(0, 8);
}

void TObjDoorJung::run_task() {
    if ((s32) switch_doors_force_closed != 0) {
        this->door_flags = (s32) (this->door_flags & 0xFFFFFFFE);
        this->clear_player_status_flag(0, 8);
    } else {
        this->update_door_switch_state();
    }
    if (this->door_flags & 1) {
        minimap_render_gate(&this->position, 0xFF00FF00, (u16) this->rotation.y, 0, 0);
        return;
    }
    minimap_render_gate(&this->position, 0xFFFF0000, (u16) this->rotation.y, 0, 0);
}
TObjDoorJung::~TObjDoorJung() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

TObjDoorJung::TObjDoorJung(TObject *parent, ObjectSetData *set_data) : TODoorBase(parent) {
    this->m_name = door_jung_class_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, &door_jung_collision_desc, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
    clamp_state();
}

