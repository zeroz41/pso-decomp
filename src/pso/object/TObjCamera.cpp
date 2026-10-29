#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/TObjCamera.h"
#include "pso/TMainTask.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/network/client_id.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

#pragma readonly_strings on

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
void TLobby__sub_8001FE7C(void *, int);
AnimationMotion *get_bml_motion(u32, int);
s32 get_bml_model(u32, int);
void TObjFish__sub_8001EDB0(u32, int);
void set_global_param__8TObjFishFl();
void get_camera_ctrl__9TObjEneDDFv(const Vec *, Vec *);
}

__declspec(section ".data") const char *fe_obj_cam_model_names[2] = { "fe_obj_cam840_841.gj", NULL };
__declspec(section ".data") const char *fe_obj_cam_motion_names[2] = { "fe_obj_cam840_841.njm", NULL };
BmlResourceDescriptor fe_obj_cam_resource_descriptor = { "fe_obj_cam.bml", fe_obj_cam_model_names, fe_obj_cam_motion_names, 1, 1 };

// The model nodes that carry a lamp, one per light (update_camera_slots).
const s32 camera_slot_id_table[8] = { 3, 6, 9, 12, 15, 18, 21, 24 };

// Two sounds a side, relative to the camera; init_sound_events places them.
const CameraSoundEvent camera_sound_events[8] = {
    { { 0.0f, 70.0f, -80.0f }, 50.0f, 0x4004C10E, 0 },
    { { 0.0f, 70.0f, -80.0f }, 90.0f, 0x4004C10F, 0 },
    { { -80.0f, 70.0f, 0.0f }, 0.0f, 0x4004C10E, 0 },
    { { -80.0f, 70.0f, 0.0f }, 100.0f, 0x4004C10F, 0 },
    { { 0.0f, 70.0f, 80.0f }, 40.0f, 0x4004C10E, 0 },
    { { 0.0f, 70.0f, 80.0f }, 80.0f, 0x4004C10F, 0 },
    { { 80.0f, 70.0f, 0.0f }, 30.0f, 0x4004C10E, 0 },
    { { 80.0f, 70.0f, 0.0f }, 100.0f, 0x4004C10F, 0 },
};

const char *obj_camera_class_name = "TObjCamera";

const StarLightParameters camera_object_init_params = { 2.5f, 15.0f, { { 0x00, 0xFF, 0x00, 0x00 } }, 0, 10.0f };

Vec camera_slot_positions[8];
u32 TObjCamera::model_resource;
s32 TObjCamera::camera_slot_scan_index;

void TObjCamera::play_sound_events() {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (sound_events[i].played == 0 && animation_frame >= sound_events[i].frame) {
            play_sound_effect(sound_events[i].sound_id, &sound_events[i].position, 0, 0);
            sound_events[i].played = 1;
        }
    }
}

void TObjCamera::reset_sound_events() {
    s32 i;
    for (i = 0; i < 8; i++) {
        sound_events[i].played = 0;
    }
}

void TObjCamera::init_sound_events() {
    s32 i;
    for (i = 0; i < 8; i++) {
        sound_events[i] = camera_sound_events[i];
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, rotation_y);
        matrix_mult_vec(0, &sound_events[i].position, &sound_events[i].position);
        pop_matrix();
        vec3_add_to(&sound_events[i].position, &position);
        sound_events[i].played = 0;
    }
}

void TObjCamera::update_camera_slots() {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (camera_slot_scan_index == camera_slot_id_table[i]) {
            Vec v = { 0.0f, 0.0f, 0.0f };
            get_camera_ctrl__9TObjEneDDFv(&v, &camera_slot_positions[i]);
        }
    }
    camera_slot_scan_index += 1;
}

#pragma push
#pragma fp_contract on
s32 TObjCamera::update_object_view_visibility(f32 radius, f32 depth) {
    Vec v;
    f32 screen[2];
    matrix_mult_vec(0, &position, &v);
    if (v.z < -radius) {
        return 0;
    }
    if (v.x < 0.0f) {
        v.x = position.x - camera_right[0] * depth;
        v.y = camera_right[1] * depth + position.y;
        v.z = camera_right[2] * depth + position.z;
        project_world_to_screen(0, &v, screen);
        if (screen[0] < 0.0f) {
            return 0;
        }
    } else {
        v.x = camera_right[0] * depth + position.x;
        v.y = position.y - camera_right[1] * depth;
        v.z = position.z - camera_right[2] * depth;
        project_world_to_screen(0, &v, screen);
        if (screen[0] > 640.0f) {
            return 0;
        }
    }
    return 1;
}
#pragma pop

void TObjCamera::render() {
    s32 i;
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish__sub_8001EDB0(model_resource, 0);
        set_global_param__8TObjFishFl();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        camera_slot_scan_index = 0;
        set_model_node_callback((s32)TObjCamera::update_camera_slots);
        draw_ginja_model_with_motion((void *)get_bml_model(model_resource, 0),
                                     get_bml_motion(model_resource, 0), animation_frame);
        set_model_node_callback(0);
        pop_matrix();
        if (lights_visible != 0) {
            for (i = 0; i < 8; i++) {
                if (lights[i] != NULL) {
                    lights[i]->copy_position(&camera_slot_positions[i]);
                }
            }
        }
    }
}

void TObjCamera::run_task() {
    Vec d;
    TObjPlayer *player;
    s32 i;
    s32 j;
    animation_frame += animation_step;
    if (animation_frame > animation_end_frame - 1.0f) {
        animation_frame = 0.0f;
        reset_sound_events();
    }
    if (lights_visible != 0) {
        play_sound_events();
    }
    player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        d.x = player->position.x - position.x;
        d.z = player->position.z - position.z;
        d.y = 0.0f;
        if (vec_squared_length(&d) <= 14400.0f) {
            for (i = 0; i < 8; i++) {
                if (lights[i] != NULL) {
                    lights[i]->allow_rendering();
                }
            }
            lights_visible = 1;
        } else {
            for (j = 0; j < 8; j++) {
                if (lights[j] != NULL) {
                    lights[j]->disallow_rendering();
                    lights[j]->queue_child_destruction();
                }
            }
            lights_visible = 0;
        }
    }
}

TObjCamera::~TObjCamera() {}

TObjCamera::TObjCamera(TObject *parent, void *set_data) : TObjMapObject(parent) {
    s32 i;
    m_name = obj_camera_class_name;
    StarLightParameters params = camera_object_init_params;
    apply_object_set_data(set_data);
    animation_frame = 0.0f;
    animation_step = 0.8f;
    animation_end_frame = get_bml_motion(model_resource, 0)->frameCount;
    if (is_split_screen() != 0) {
        for (i = 0; i < 8; i++) {
            lights[i] = NULL;
        }
    } else {
        for (i = 0; i < 8; i++) {
            lights[i] = new TEffStarLight2D(&position, &params, this);
        }
    }
    lights_visible = 0;
    init_sound_events();
}

void *TObjCamera::create(void *set_data) {
    return new TObjCamera(tl_05, set_data);
}

void TObjCamera::free_resources() {
    if (model_resource != 0) {
        TLobby__sub_8001FE7C((void *)model_resource, 1);
        model_resource = 0;
    }
}

void TObjCamera::load_resources() {
    void *resource;
    u32 loaded;
    camera_slot_scan_index = 0;
    resource = ::operator new(0x440);
    loaded = (u32)resource;
    if (loaded != 0) {
        loaded = (u32)load_resource_from_descriptor(resource, 1, &fe_obj_cam_resource_descriptor, 0, 0, 0);
    }
    model_resource = loaded;
}
