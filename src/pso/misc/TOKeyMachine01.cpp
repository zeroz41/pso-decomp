#include "types.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/TProtocol.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLanguage_801E4874.h"
#include "pso/misc/TOBoss4Rock.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/network/client_id.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/protocol/protocol_types.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"

// The default constant-material colour (owner unit not split yet; 27 files
// declare it with their own types, see the lane report).
extern u8 chunk_material_color_half_alpha_f32[];

const char *bm_fs_obj_ki_doa_panel_model_names[] = {"fs_obj_ki_doa_panel.gj", NULL};
const char *bm_fs_obj_ki_doa_panel_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_ki_doa_panel_resource_descriptor = {
    "bm_fs_obj_ki_doa_panel.bml", bm_fs_obj_ki_doa_panel_model_names, bm_fs_obj_ki_doa_panel_motion_names, 1, 0,
};
// The press and release sound for each floor area (-1 for none).
const s32 key_machine01_switch_sounds[] = {
    0x4004B206, 0x4B20D, 0x4B20D, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206,
    0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B204, 0x4004B204,
    0x4004B206, 0x4B204, 0x4B204, 0x4004B204, 0x4004B204, 0x4C611, 0x4C611, 0x4C611, 0x4C611,
    0x4C611, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4004B206, 0x4C611, 0x4C611,
};
const char *TOKeyMachine01__class_name = "TOKeyMachine01";
BmlResource *TOKeyMachine01__resource_bundle;
s32 *TOKeyMachine01__texture_lists;

void TOKeyMachine01::vfunc_25() {}

// Pressed while a player stands on it (in once mode, latched once on).
s32 TOKeyMachine01::is_confirm_pressed() {
    s32 pressed = 0;
    s32 in_range;

    switch (mode) {
    case KEY_MODE_ONCE:
        if (is_split_screen() == 1) {
            in_range = is_any_player_in_range();
        } else {
            in_range = is_local_player_in_range();
        }
        if (is_on == 1 || in_range == 1) {
            pressed = 1;
        }
        break;
    case KEY_MODE_TOGGLE:
        pressed = is_any_player_in_range();
        break;
    }
    return pressed;
}

void TOKeyMachine01::send_switch_changed(s32 flags) {
    G_SwitchStateChanged_6x05 cmd;
    cmd.init();
    cmd.header.client_id = entity_id;
    cmd.unused1 = local_client_id;
    cmd.switch_id = switch_id;
    cmd.floor = get_current_floor();
    cmd.flags = flags;
    cmd.send();
}

void TOKeyMachine01::trigger_deactivate_sound() {
    s32 sound;
    if (enable_v2_features == 1 && (get_current_floor_area() == AREA_BATTLE1 || get_current_floor_area() == AREA_BATTLE2)) {
        sound = key_machine01_switch_sounds[get_current_floor_area()];
        if (sound >= 0) {
            play_sound_effect(sound, &position, 0, 0);
        }
    } else if (enable_v2_features == 1 && (get_current_floor_area() == AREA_FOREST1 || get_current_floor_area() == AREA_FOREST2)) {
        sound = key_machine01_switch_sounds[get_current_floor_area()];
        if (sound >= 0) {
            play_sound_effect(sound, &position, 0, 0);
        }
    } else {
        sound = key_machine01_switch_sounds[get_current_floor_area()];
        if (sound >= 0) {
            play_sound_effect(sound, &position, 0, 0);
        }
    }
}

void TOKeyMachine01::trigger_activate_sound() {
    s32 sound;
    if (enable_v2_features == 1 && (get_current_floor_area() == AREA_BATTLE1 || get_current_floor_area() == AREA_BATTLE2)) {
        sound = key_machine01_switch_sounds[get_current_floor_area()];
        if (sound >= 0) {
            play_sound_effect(sound, &position, 0, 0);
        }
    } else if (enable_v2_features == 1 && (get_current_floor_area() == AREA_FOREST1 || get_current_floor_area() == AREA_FOREST2)) {
        sound = key_machine01_switch_sounds[get_current_floor_area()];
        if (sound >= 0) {
            play_sound_effect(sound, &position, 0, 0);
        }
    } else {
        sound = key_machine01_switch_sounds[get_current_floor_area()];
        if (sound >= 0) {
            play_sound_effect(sound, &position, 0, 0);
        }
    }
}

void TOKeyMachine01::update_switch_off() {
    if (glow_rising == 1) {
        glow_color.r += 0.1f;
        if (1.0f <= glow_color.r) {
            glow_rising = 0;
        }
    } else {
        glow_color.r = glow_color.r - 0.1f;
        if (glow_color.r <= 0.0f) {
            glow_rising = 1;
        }
    }
    if (scale.y < 0.0f) {
        scale.y = scale.y - -0.023333333f;
    }
}

void TOKeyMachine01::update_switch_on() {
    if (-0.7f < scale.y) {
        scale.y += -0.023333333f;
    }
}

void TOKeyMachine01::run_task() {
    update_lock_state();
    if (is_on != 1) {
        update_switch_off();
        if (is_confirm_pressed() == 1) {
            send_switch_changed(1);
            trigger_activate_sound();
            is_on = 1;
        }
    } else {
        update_switch_on();
        if (is_confirm_pressed() != 1) {
            send_switch_changed(0);
            trigger_deactivate_sound();
            is_on = 0;
        }
    }
}

void TOKeyMachine01::render() {
    NJS_OBJECT *object;
    u32 flags;

    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        TObjFish::set_global_param(TOKeyMachine01__texture_lists[is_on]);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        object = (NJS_OBJECT *)model;
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        if (is_on != 1) {
            flags = model_render_flags;
            saved_model_render_flags = flags;
            model_render_flags = flags | 0x10;
            set_constant_material(&glow_color);
        }
        TParticleCtrl::begin_effect_render();
        object = object->child;
        push_matrix();
        post_translate_matrix(&scale.x);
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        object = object->child;
        push_matrix();
        post_translate_matrix(object->pos);
        draw_ginja_model((s32)object->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        if (is_on != 1) {
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
        }
        pop_matrix();
    }
}

void *TOKeyMachine01::create(void *set_data) {
    return new TOKeyMachine01(tl_05, set_data);
}

void TOKeyMachine01::free_statics() {
    if (TOKeyMachine01__texture_lists != NULL) {
        TObjPlayer::free_if_valid(TOKeyMachine01__texture_lists[0]);
        TOKeyMachine01__texture_lists[0] = 0;
        if (TOKeyMachine01__texture_lists != NULL) {
            mem_free(TOKeyMachine01__texture_lists);
            TOKeyMachine01__texture_lists = NULL;
        }
    }
    if (TOKeyMachine01__resource_bundle != NULL) {
        TLobby__sub_8001FE7C(TOKeyMachine01__resource_bundle, 1);
        TOKeyMachine01__resource_bundle = NULL;
    }
}

void TOKeyMachine01::load_assets() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_ki_doa_panel_resource_descriptor, 0, 0, 0);
    }
    TOKeyMachine01__resource_bundle = resource;
    TOKeyMachine01__texture_lists = (s32 *)mem_alloc(8);
    TOKeyMachine01__texture_lists[0] = (s32)load_gvm_texture_file((s32) "fs_obj_ki_doa_panel_r.gvm");
    TOKeyMachine01__texture_lists[1] = TOKeyMachine01__resource_bundle->models[0].m_c;
}

TOKeyMachine01::~TOKeyMachine01() {}

TOKeyMachine01::TOKeyMachine01(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = TOKeyMachine01__class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    texlist = TOKeyMachine01__texture_lists[0];
    model = (void *)TOKeyMachine01__resource_bundle->models[0].model;
    m_c0 = 400.0f;
    model_radius = 10.0f;
    activate_range = 10.0f;
    if (get_main_phase() == 0xF || is_split_screen() == 1) {
        if (mode != KEY_MODE_NONE && set_params[1] < 0) {
            mode = KEY_MODE_TOGGLE;
        } else {
            mode = KEY_MODE_ONCE;
        }
    }
    glow_color.a = 1.0f;
    glow_color.r = 1.0f;
    glow_color.g = 1.0f;
    glow_color.b = 1.0f;
    glow_rising = 0;
    scale.z = 0.0f;
    scale.y = 0.0f;
    scale.x = 0.0f;
}
