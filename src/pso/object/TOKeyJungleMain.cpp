#include "types.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TOKeyJungleMain.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"

extern s32 game_difficulty_selection;

extern "C" {
// TOKeyJungleMain::dispatch_by_phase: the call passes the flag word without the u16 truncation the
// header's (s32, u16) signature makes the compiler emit; the real parameter type is still open.
void dispatch_by_phase__15TOKeyJungleMainFlUs(s32 bank, s32 flag);
}

const char *bm_obj_jungle_mkey_model_names[] = {"fe_obj_start_sw_naka.gj", "fe_obj_start_switch.gj", NULL};
const char *bm_obj_jungle_mkey_motion_names[] = {"fe_obj_start_sw_naka.njm", "fe_obj_start_switch.njm", NULL};
BmlResourceDescriptor bm_obj_jungle_mkey_resource_descriptor = {
    "bm_obj_jungle_mkey.bml", bm_obj_jungle_mkey_model_names, bm_obj_jungle_mkey_motion_names, 2, 2,
};
CollisionBody TOKeyJungleMain_collision_body_parts[] = {
    {{0.0f, 10.0f, 0.0f}, 5.0f, 5.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOKeyJungleMain__class_name = "TOKeyJungleMain";
BmlResource *TOKeyJungleMain__static_model_resource;

void TOKeyJungleMain::play_activate_sound() {
    s32 sound = 0x4AD12;

    switch (get_current_floor_area()) {
    case AREA_SEASIDE_NIGHT:
        sound = 0x4004AD12;
        break;
    case AREA_TOWER:
        sound = 0x4004AD12;
        break;
    }
    play_sound_effect(sound, &position, 0, 0);
}

void *TOKeyJungleMain::create(void *set_data) {
    return new TOKeyJungleMain(tl_05, set_data);
}

void TOKeyJungleMain::release_static_resource() {
    if (TOKeyJungleMain__static_model_resource != NULL) {
        TLobby__sub_8001FE7C(TOKeyJungleMain__static_model_resource, 1);
        TOKeyJungleMain__static_model_resource = NULL;
    }
}

void TOKeyJungleMain::load_static_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);

    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_jungle_mkey_resource_descriptor, 0, 0, 0);
    }
    TOKeyJungleMain__static_model_resource = resource;
}

void TOKeyJungleMain::debug_draw_key_id() {
    switch_id = set_params[0];
    if (switch_id < 0) {
        switch_id = 0;
    }
    if (switch_id > 2) {
        switch_id = 2;
    }
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- GLOBAL FLAG : %d", TOKeyJungleMain__data_804653C8[switch_id]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TOKeyJungleMain::render() {
    if (update_object_view_visibility(view_range, model_radius) == 1) {
        switch (is_on) {
        case 0:
            TObjFish::set_global_param(TObjFish__sub_8001EDB0(TOKeyJungleMain__static_model_resource, 1));
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            draw_ginja_object((void *)get_bml_model(TOKeyJungleMain__static_model_resource, 1));
            pop_matrix();
            return;
        case 1:
            TObjFish::set_global_param(TObjFish__sub_8001EDB0(TOKeyJungleMain__static_model_resource, 1));
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            draw_ginja_model_with_motion((void *)get_bml_model(TOKeyJungleMain__static_model_resource, 1),
                                         get_bml_motion(TOKeyJungleMain__static_model_resource, 1), switch_frame);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion((void *)get_bml_model(TOKeyJungleMain__static_model_resource, 0),
                                         get_bml_motion(TOKeyJungleMain__static_model_resource, 0), sw_naka_frame);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            break;
        }
    }
}

void TOKeyJungleMain::send_switch_on() {
    dispatch_by_phase__15TOKeyJungleMainFlUs(game_difficulty_selection, TOKeyJungleMain__data_804653C8[switch_id]);
}

void TOKeyJungleMain::update_lock_state() {
    if (mode != KEY_MODE_NONE) {
        s32 was_on = is_on;

        if (TLevelSelect::get_difficulty_flag_bit(game_difficulty_selection, TOKeyJungleMain__data_804653C8[switch_id]) != 0) {
            is_on = 1;
        } else {
            is_on = 0;
        }
        if (was_on != is_on) {
            play_activate_sound();
        }
    }
}

// Plays the switch motion once and loops the sw_naka motion.
void TOKeyJungleMain::update_switch_on() {
    AnimationMotion *motion = get_bml_motion(TOKeyJungleMain__static_model_resource, 1);

    switch_frame += 1.0f;
    if (switch_frame > (f32)(motion->frameCount - 1)) {
        switch_frame = motion->frameCount - 1;
    }
    motion = get_bml_motion(TOKeyJungleMain__static_model_resource, 0);
    sw_naka_frame += 1.0f;
    if (sw_naka_frame > (f32)(motion->frameCount - 1)) {
        sw_naka_frame = 0.0f;
    }
}

void TOKeyJungleMain::update_switch_off() {
    submit_cursor_target();
}

TOKeyJungleMain::~TOKeyJungleMain() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

TOKeyJungleMain::TOKeyJungleMain(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = TOKeyJungleMain__class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    init_collision_body_parts(this, TOKeyJungleMain_collision_body_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    mode = KEY_MODE_ONCE;
    switch_id = set_params[0];
    if (switch_id < 0) {
        switch_id = 0;
    }
    if (switch_id > 2) {
        switch_id = 2;
    }
    switch_frame = 0.0f;
    sw_naka_frame = 0.0f;
}
