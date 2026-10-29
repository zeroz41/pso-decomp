#include "types.h"
#include "pso/render/render_util.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/misc/TOMonumentAncient02.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialColor.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMapObject.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/player/TObjPlayer.h"

// One monument model per area: Cave 1 (default), Cave 2 and Mine 2.
const char *bm_fs_obj_o_monument01_model_names[] = {"fs_obj_o_monument01.gj", NULL};
const char *bm_fs_obj_o_monument01_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_o_monument01_resource_descriptor = {
    "bm_fs_obj_o_monument01.bml", bm_fs_obj_o_monument01_model_names, bm_fs_obj_o_monument01_motion_names, 1, 0,
};
const char *bm_fs_obj_o_monument02_model_names[] = {"fs_obj_o_monument02.gj", NULL};
const char *bm_fs_obj_o_monument02_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_o_monument02_resource_descriptor = {
    "bm_fs_obj_o_monument02.bml", bm_fs_obj_o_monument02_model_names, bm_fs_obj_o_monument02_motion_names, 1, 0,
};
const char *bm_fs_obj_o_monument03_model_names[] = {"fs_obj_o_monument03.gj", NULL};
const char *bm_fs_obj_o_monument03_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_o_monument03_resource_descriptor = {
    "bm_fs_obj_o_monument03.bml", bm_fs_obj_o_monument03_model_names, bm_fs_obj_o_monument03_motion_names, 1, 0,
};
CollisionBody monument_ancient02_collision_parts[] = {
    {{0.0f, 10.0f, 0.0f}, 20.0f, 0.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOMonumentAncient02__class_name = "TOMonumentAncient02";
BmlResource *TOMonumentAncient02__bml_resource;
// TBoss4DarkFalz.h declares this with a u16 flag, but this caller passes the
// full word (no clrlwi); 35 callers share that declaration.
extern "C" s32 dispatch_by_main_phase__14TBoss4DarkFalzFUs(u32 flag);

// Restores the saved state: 2 (activated) replays its main-phase step. Once
// all three tablets' flags (0x2C-0x2E) are set, phase 0x2F runs.
void TOMonumentAncient02::vfunc_6(s16 *state, s32) {
    object_state = *state;
    switch (object_state) {
    case 2:
        dispatch_by_main_phase__14TBoss4DarkFalzFUs(story_flag);
        activated = 1;
        break;
    default:
        if (get_story_flag(story_flag) != 0) {
            object_state = 2;
            activated = 1;
        }
        break;
    }
    if (get_story_flag(0x2C) != 0 && get_story_flag(0x2D) != 0 && get_story_flag(0x2E) != 0) {
        dispatch_by_main_phase__14TBoss4DarkFalzFUs(0x2F);
    }
    access_object_saved_state(state, 0);
}

void TOMonumentAncient02::interact(s32 client) {
    s16 state;
    TObjPlayer *player;
    switch (object_state) {
    case 1:
        player = get_player_by_client_id((u16)client);
        if (player != NULL) {
            object_state = 2;
            player->start_camera_pan(0xC, calc_angle_to(&player->position, &position));
            if (access_object_saved_state(&state, 1) != 0) {
                state = object_state;
                access_object_saved_state(&state, 0);
                send_object_state_update(&state);
            }
        }
        break;
    }
}

void TOMonumentAncient02::run_task() {

    switch (object_state) {
    default:
        object_state = 1;
        if (effect != NULL) {
            effect->enable();
        }
        return;
    case 1:
        if ((TRaderMapCore::is_not_split_screen() != 1) && (in_view == 1)) {
            submit_cursor_candidate(this, -1);
        }
        if (effect != NULL) {
            effect->enable();
            return;
        }
        break;
    case 2:
        play_persistent_sound(sound_id, (s32)this, (u32)&position, 0, 0);
        break;
    }
}

void TOMonumentAncient02::render() {
    NJS_OBJECT *node;
    in_view = update_object_view_visibility(view_range, model_radius);
    if (in_view == 1) {
        push_matrix();
        if (activated == 1) {
            scale.x = 0.1f * (3.0517578125e-05f * (f32)rand()) - 0.05f;
            scale.z = 0.1f * (3.0517578125e-05f * (f32)rand()) - 0.05f;
            post_translate_matrix(&scale.x);
        }
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        node = (NJS_OBJECT *)model;
        post_translate_matrix(node->pos);
        draw_ginja_model((s32)node->model);
        if (activated == 1) {
            if (brightening != 0) {
                light_color.a += 0.05f;
                if (0.0f <= light_color.a) {
                    light_color.a = 0.0f;
                    brightening = 0;
                }
            } else {
                light_color.a -= 0.05f;
                if (light_color.a <= -1.0f) {
                    light_color.a = -1.0f;
                    brightening = 1;
                }
            }
            node = node->child;
            push_matrix();
            translate_matrix(0, node->pos[0], node->pos[1], node->pos[2]);
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x20;
            set_constant_material(&light_color);
            draw_ginja_model((s32)node->model);
            set_constant_material(&chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            TParticleCtrl::end_effect_render();
            pop_matrix();
        }
        pop_matrix();
    }
}

void *TOMonumentAncient02::create(void *set_data) {
    return new TOMonumentAncient02(tl_05, set_data);
}

void TOMonumentAncient02::free_shared_data() {
    if (TOMonumentAncient02__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TOMonumentAncient02__bml_resource, 1);
        TOMonumentAncient02__bml_resource = NULL;
    }
}

void TOMonumentAncient02::load_resources() {
    BmlResource *resource;
    switch (get_current_floor_area()) {
    default:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 5, &bm_fs_obj_o_monument01_resource_descriptor, 0, 0, 0);
        }
        TOMonumentAncient02__bml_resource = resource;
        break;
    case AREA_CAVE2:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 5, &bm_fs_obj_o_monument02_resource_descriptor, 0, 0, 0);
        }
        TOMonumentAncient02__bml_resource = resource;
        break;
    case AREA_MINE2:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 5, &bm_fs_obj_o_monument03_resource_descriptor, 0, 0, 0);
        }
        TOMonumentAncient02__bml_resource = resource;
        break;
    }
}

TOMonumentAncient02::~TOMonumentAncient02() {
    TParticleCtrl::release(effect);
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOMonumentAncient02::TOMonumentAncient02(TObject *parent, void *set_data) : TObjMapObject(parent) {
    s32 area;
    m_name = TOMonumentAncient02__class_name;
    apply_object_set_data(set_data);
    model = (void *)TOMonumentAncient02__bml_resource->models[0].model;
    texlist = TOMonumentAncient02__bml_resource->models[0].m_c;
    init_collision_body_parts(this, monument_ancient02_collision_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    area = get_current_floor_area();
    switch (area) {
    default:
        story_flag = 0x2C;
        sound_id = 0x4C119;
        break;
    case AREA_CAVE2:
        story_flag = 0x2D;
        sound_id = 0x44116;
        break;
    case AREA_MINE2:
        story_flag = 0x2E;
        sound_id = 0x4004C10F;
        break;
    }
    object_state = 0;
    activated = 0;
    brightening = 0;
    cursor_action.set_use();
    view_range = 500.0f;
    model_radius = 50.0f;
    light_color.a = (f32) 0.0f;
    light_color.r = (f32) 0.0f;
    light_color.g = (f32) 0.0f;
    light_color.b = (f32) 0.0f;
    effect = create_particle_emitter(&position, 0x7F);
    in_view = 1;
    if (enable_v2_features == 1) {
        if (get_game_play_mode() == 1) {
            queue_destruction();
        }
    }
}
