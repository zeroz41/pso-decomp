#include "pso/misc/TODoorMachine01.h"

#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TSwitch.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialColor.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

const char *fs_obj_ki_doa_model_names[] = {"fs_obj_ki_doa.gj", NULL};
const char *fs_obj_ki_doa_motion_names[] = {"fs_obj_ki_doa.njm", NULL};
BmlResourceDescriptor door_machine01_resource_descriptor = {
    "bm_fs_obj_ki_doa.bml", fs_obj_ki_doa_model_names, fs_obj_ki_doa_motion_names, 1, 1,
};
// The version-2 model set.
const char *fs_obj_ki_doa_a_model_names[] = {"fs_obj_ki_doa.gj", NULL};
const char *fs_obj_ki_doa_a_motion_names[] = {"fs_obj_ki_doa.njm", NULL};
BmlResourceDescriptor door_machine01_a_resource_descriptor = {
    "bm_fs_obj_ki_doa_a.bml", fs_obj_ki_doa_a_model_names, fs_obj_ki_doa_a_motion_names, 1, 1,
};

const char *door_machine01_class_name = "TODoorMachine01";

static CollisionBody door_machine01_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 20.0f, 1, 0x10003},
};

BmlResource *TODoorMachine01::bml_resource;
s32 *TODoorMachine01::texture_lists;

void TODoorMachine01::update_demo() {}

void TODoorMachine01::update_open() {
    if (!(door_flags & 1) || is_any_player_within_radius_xz(10000.0f) != 1) {
        m_ac = DOOR_CLOSING;
        clear_player_status_flag(0, 8);
        play_sound_effect(0x4004BC01, &position, 0, 0);
    }
}

void TODoorMachine01::update_closed() {
    if ((door_flags & 1) && is_any_player_within_radius_xz(4900.0f) == 1) {
        m_ac = DOOR_OPENING;
        set_indexed_flags(0, 8);
        play_sound_effect(0x4004BC01, &position, 0, 0);
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

void TODoorMachine01::update_door_switch_state() {
    s32 i;
    s32 j;
    s32 k;
    switch (lock_mode) {
    case 1:
        play_door_sound();
        door_flags |= LIGHT_LIT_MASK | 1;
        lit_count = 4;
        break;
    case 2:
        door_flags &= ~LIGHT_LIT_MASK;
        if (switch_count == 1) {
            if (is_current_floor_switch_set((u16)switch_id) == 1) {
                lit_count = 4;
                door_flags |= LIGHT_LIT_MASK;
            } else {
                lit_count = 0;
            }
        } else {
            lit_count = 4 - switch_count;
            for (i = 0; i < switch_count; i++) {
                if (is_current_floor_switch_set((u16)(switch_id + i)) == 1) {
                    lit_count++;
                }
            }
            for (j = 0; j < lit_count; j++) {
                door_flags |= 1 << (j + LIGHT_LIT_SHIFT);
            }
        }
        if (lit_count == 4) {
            play_door_sound();
            door_flags |= 1;
        } else {
            door_flags &= ~1;
        }
        break;
    case 3:
        if (switch_count == 1) {
            if (is_current_floor_switch_set((u16)switch_id) == 1) {
                lit_count = 4;
                door_flags |= LIGHT_LIT_MASK;
            } else {
                lit_count = 0;
            }
        } else {
            lit_count = 4 - switch_count;
            for (k = 0; k < switch_count; k++) {
                if (is_current_floor_switch_set((u16)(switch_id + k)) == 1) {
                    lit_count++;
                    door_flags |= 1 << (k + LIGHT_LIT_SHIFT);
                }
            }
        }
        if (lit_count == 4) {
            play_door_sound();
            door_flags |= 1;
        }
        break;
    default:
        door_flags &= ~(LIGHT_LIT_MASK | 1);
        break;
    }
}

void TODoorMachine01::draw_switch_light(NJS_OBJECT *node, s32 lit) {
    u32 flags;
    NJS_OBJECT *child;
    if (lit != 1) {
        flags = model_render_flags;
        saved_model_render_flags = flags;
        model_render_flags = flags | 0x10;
        set_constant_material(&light_color);
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
    draw_ginja_model((s32)node->model);
    child = node->child;
    push_matrix();
    translate_matrix(0, child->pos[0], child->pos[1], child->pos[2]);
    draw_ginja_model((s32)child->model);
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    if (lit != 1) {
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
    }
}

void TODoorMachine01::render() {
    NJS_OBJECT *node;
    s32 lit;
    if (update_object_view_visibility(m_c0, model_radius) != 0 && is_in_view_depth(30.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (m_ac == DOOR_CLOSED) {
            node = ((NJS_OBJECT *)model)->child;
            lit = (door_flags >> LIGHT_LIT_SHIFT) & 1;
            TObjFish::set_global_param(texture_lists[lit]);
            push_matrix();
            translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
            draw_ginja_model((s32)node->model);
            draw_switch_light(node->child, lit);
            pop_matrix();
            node = ((NJS_OBJECT *)model)->child->sibling;
            lit = (door_flags >> (LIGHT_LIT_SHIFT + 1)) & 1;
            TObjFish::set_global_param(texture_lists[lit]);
            push_matrix();
            translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
            draw_ginja_model((s32)node->model);
            node = node->child;
            draw_switch_light(node, lit);
            node = node->sibling;
            lit = (door_flags >> (LIGHT_LIT_SHIFT + 2)) & 1;
            TObjFish::set_global_param(texture_lists[lit]);
            draw_switch_light(node, lit);
            pop_matrix();
            node = ((NJS_OBJECT *)model)->child->sibling->sibling;
            lit = (door_flags >> (LIGHT_LIT_SHIFT + 3)) & 1;
            TObjFish::set_global_param(texture_lists[lit]);
            push_matrix();
            translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
            draw_ginja_model((s32)node->model);
            draw_switch_light(node->child, lit);
            pop_matrix();
        } else {
            TObjFish::set_global_param(texture_lists[1]);
            draw_ginja_model_with_motion(model, motion, m_b0);
        }
        pop_matrix();
    }
}

void *TODoorMachine01::create(void *set_data) {
    return new TODoorMachine01(tl_05, set_data);
}

void TODoorMachine01::destroy() {
    if (texture_lists != NULL) {
        TObjPlayer::free_if_valid(texture_lists[0]);
        if (texture_lists != NULL) {
            mem_free(texture_lists);
            texture_lists = NULL;
        }
    }
    if (bml_resource != NULL) {
        TLobby__sub_8001FE7C(bml_resource, 1);
        bml_resource = NULL;
    }
}

void TODoorMachine01::load_resources() {
    BmlResource *resource;
    texture_lists = (s32 *)mem_alloc(8);
    if (enable_v2_features == 1 && TLobby::is_online_ready() != 0) {
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &door_machine01_a_resource_descriptor, 0, 0, 0);
        }
        bml_resource = resource;
        texture_lists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_ki_doa_r_a.gvm");
    } else {
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &door_machine01_resource_descriptor, 0, 0, 0);
        }
        bml_resource = resource;
        texture_lists[0] = (s32)load_gvm_texture_file((s32)"fs_obj_ki_doa_r.gvm");
    }
    texture_lists[1] = bml_resource->models[0].m_c;
}

TODoorMachine01::~TODoorMachine01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TODoorMachine01::TODoorMachine01(TObject *parent, void *set_data) : TODoorBase(parent) {
    m_name = door_machine01_class_name;
    apply_object_set_data(set_data);
    model = (void *)bml_resource->models[0].model;
    texlist = bml_resource->models[0].m_c;
    motion = bml_resource->motions[0].motion;
    animation_end_frame = (f32)motion->frameCount - 1.0f;
    m_b8 = 0.5f;
    init_collision_body_parts(this, door_machine01_collision_body, 1);
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
