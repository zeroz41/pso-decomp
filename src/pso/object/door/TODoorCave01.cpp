#include "pso/quest/QuestFloorDesignation.h"
#include "pso/map/FloorPopulation.h"
#include "pso/object/door/TODoorCave01.h"

#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/network/TProtocol.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/network/TLobby.h"
#include "pso/network/ObjectStateSend.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/object/fence/TOBarrierEnergy01.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/ChunkMaterialColor.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/GameModeQueries.h"

const char *fs_obj_do_doa01_model_names[] = {"fs_obj_do_doa01.gj", NULL};
const char *fs_obj_do_doa01_motion_names[] = {"fs_obj_do_doa01.njm", NULL};
BmlResourceDescriptor door_cave01_resource_descriptor = {
    "bm_fs_obj_do_doa01.bml", fs_obj_do_doa01_model_names, fs_obj_do_doa01_motion_names, 1, 1,
};
// The version-2 model set.
const char *fs_obj_do_doa01_a_model_names[] = {"fs_obj_do_doa01.gj", NULL};
const char *fs_obj_do_doa01_a_motion_names[] = {"fs_obj_do_doa01.njm", NULL};
BmlResourceDescriptor door_cave01_a_resource_descriptor = {
    "bm_fs_obj_do_doa01_a.bml", fs_obj_do_doa01_a_model_names, fs_obj_do_doa01_a_motion_names, 1, 1,
};

const char *door_cave01_class_name = "TODoorCave01";

static CollisionBody door_cave01_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorCave01::bml_resource;
NJS_TEXLIST **TODoorCave01::texture_lists;

void TODoorCave01::update_demo() {}

// Sends the 6x0B object-state message for the saved state (or src when given).

void TODoorCave01::send_state(QuestObjectEntry *saved_state) {
    QuestObjectEntry state;
    FloorObjectSetRow *entry;
    if (saved_state != NULL) {
        state.copy_from(saved_state);
    } else {
        access_object_saved_state(&state, 1);
    }
    entry = (FloorObjectSetRow *)set_entry;
    if (entry != NULL) {
        G_UpdateObjectState_6x0B pkt;
        init_collision_subcommand_header(&pkt);
        pkt.header.entity_id = entity_id;
        pkt.flags = state.flags;
        pkt.object_index = entry->placement.set_index;
        send_object_state(&pkt);
    }
}

void TODoorCave01::apply_saved_state(s16 *state, s32) {
    if (*state == 1) {
        door_flags |= LIGHT_LIT_MASK | 1;
    }
}

s32 TODoorCave01::init_door_switch_binding() {
    switch_id = set_params[0];
    if (switch_id > 0x100) {
        lock_mode = 0;
    } else if (switch_id < 0) {
        lock_mode = 1;
    } else if (set_params[2] < 0) {
        if (get_main_phase() == 0xF || TRaderMapCore::is_not_split_screen() == 1) {
            lock_mode = 3;
        } else {
            lock_mode = 2;
        }
    } else {
        lock_mode = 2;
    }
    return switch_id;
}

void TODoorCave01::update_open() {
    if ((u8)!(door_flags & 1) == 1 || is_any_player_within_radius_xz(10000.0f) != 1) {
        object_state = 3;
        clear_player_status_flag(0, 8);
        play_sound_effect(0x42807, &position, 0, 0);
    }
}

void TODoorCave01::update_closed() {
    if ((door_flags & 1) && is_any_player_within_radius_xz(4900.0f) == 1) {
        object_state = 1;
        set_indexed_flags(0, 8);
        play_sound_effect(0x42807, &position, 0, 0);
    }
    if (door_flags & PULSE_RISING) {
        light_color.r += 0.1f;
        if (1.0f <= light_color.r) {
            door_flags &= ~PULSE_RISING;
        }
    } else {
        light_color.r = light_color.r - 0.1f;
        if (light_color.r <= 0.0f) {
            door_flags |= PULSE_RISING;
        }
    }
}

void TODoorCave01::update_door_switch_state() {
    QuestObjectEntry st;
    s32 i;
    switch (lock_mode) {
    case 1:
        play_door_sound();
        door_flags |= LIGHT_LIT_MASK | 1;
        lit_count = 4;
        break;
    case 2:
        door_flags &= ~LIGHT_LIT_MASK;
        lit_count = 4 - switch_count;
        for (i = 0; i < switch_count; i++) {
            if (is_current_floor_switch_set((u16)(switch_id + i)) == 1) {
                lit_count++;
            }
        }
        for (i = 0; i < lit_count; i++) {
            door_flags |= 1 << (i + LIGHT_LIT_SHIFT);
        }
        if (lit_count == 4) {
            play_door_sound();
            door_flags |= 1;
        } else {
            door_flags &= ~1;
        }
        break;
    case 3:
        if (door_flags & 1) {
            door_flags |= LIGHT_LIT_MASK;
            break;
        }
        door_flags &= ~LIGHT_LIT_MASK;
        lit_count = 4 - switch_count;
        for (i = 0; i < switch_count; i++) {
            if (is_current_floor_switch_set((u16)(switch_id + i)) == 1) {
                lit_count++;
            }
        }
        for (i = 0; i < lit_count; i++) {
            door_flags |= 1 << (i + LIGHT_LIT_SHIFT);
        }
        if (lit_count == 4) {
            play_door_sound();
            door_flags |= 1;
            if (set_entry != NULL && access_object_saved_state(&st, 1) != 0) {
                st.flags = 1;
                send_state(&st);
                access_object_saved_state(&st, 0);
            }
        }
        break;
    default:
        door_flags &= ~(LIGHT_LIT_MASK | 1);
        break;
    }
}

void TODoorCave01::draw_switch_light(NJS_OBJECT *node, s32 lit) {
    u32 flags;
    NJS_OBJECT *child;
    set_texture_list(reinterpret_cast<NJS_TEXLIST *>(texture_lists[lit]));
    push_matrix();
    translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
    draw_ginja_model(node->model);
    child = node->child;
    if (lit != 1) {
        flags = model_render_flags;
        saved_model_render_flags = flags;
        model_render_flags = flags | 0x10;
        set_constant_material(&light_color);
    }
    begin_effect_render();
    push_matrix();
    translate_matrix(0, child->pos[0], child->pos[1], child->pos[2]);
    draw_ginja_model(child->model);
    child = child->child;
    push_matrix();
    translate_matrix(0, child->pos[0], child->pos[1], child->pos[2]);
    draw_ginja_model(child->model);
    pop_matrix();
    pop_matrix();
    end_effect_render();
    if (lit != 1) {
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
    }
    pop_matrix();
}

void TODoorCave01::render() {
    NJS_OBJECT *node;
    s32 i;
    if (update_object_view_visibility(view_range, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation.y);
        if ((s32)object_state == DOOR_CLOSED) {
            i = 0;
            node = model->child;
            do {
                draw_switch_light(node, door_flags & (1 << (i + LIGHT_LIT_SHIFT)) ? 1 : 0);
                i++;
                node = node->sibling;
            } while (i < 4);
        } else {
            set_texture_list(reinterpret_cast<NJS_TEXLIST *>(texture_lists[1]));
            draw_ginja_model_with_motion(model, motion, animation_frame);
        }
        pop_matrix();
    }
}

void *TODoorCave01::create(ObjectSetData *set_data) {
    return new TODoorCave01(tl_05, set_data);
}

void TODoorCave01::destroy() {
    if (texture_lists != NULL) {
        free_if_valid(texture_lists[0]);
        if (texture_lists != NULL) {
            mem_free(texture_lists);
            texture_lists = NULL;
        }
    }
    if (bml_resource != NULL) {
        delete (BmlResource *)bml_resource;
        bml_resource = NULL;
    }
}

void TODoorCave01::load_resources() {
    BmlResource *resource;
    texture_lists = (NJS_TEXLIST **)mem_alloc(2 * sizeof(NJS_TEXLIST *));
    if (enable_v2_features != 0 && is_online_ready() != 0) {
        resource = new BmlResource(1, &door_cave01_a_resource_descriptor, 0, 0, NULL);
        bml_resource = resource;
        texture_lists[0] = LoadPvmFileTls("fs_obj_do_doa01r_a.gvm");
    } else {
        resource = new BmlResource(1, &door_cave01_resource_descriptor, 0, 0, NULL);
        bml_resource = resource;
        texture_lists[0] = LoadPvmFileTls("fs_obj_do_doa01r.gvm");
    }
    texture_lists[1] = bml_resource->models[0].texlist;
}

TODoorCave01::~TODoorCave01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorCave01::TODoorCave01(TObject *parent, ObjectSetData *set_data) : TODoorBase(parent) {
    m_name = door_cave01_class_name;
    apply_object_set_data(set_data);
    model = bml_resource->models[0].model;
    texlist = bml_resource->models[0].texlist;
    motion = bml_resource->motions[0].motion;
    animation_end_frame = (f32)motion->nbFrame - 1.0f;
    animation_step = 0.5f;
    init_collision_body_parts(this, door_cave01_collision_body, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    init_door_switch_binding();
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 4) {
        set_params[1] = 4;
    }
    lit_count = set_params[1];
    switch_count = 4 - lit_count;
    light_color.a = 1.0f;
    light_color.r = 1.0f;
    light_color.g = 1.0f;
    light_color.b = 1.0f;
}
