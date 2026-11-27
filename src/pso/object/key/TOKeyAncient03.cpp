#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/key/TOKeyAncient03.h"
#include "pso/network/client_id.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/render_util.h"

// The default constant-material colour (owner unit not split yet; 27 files
// declare it with their own types, see the lane report).

const char *bm_fs_obj_o_doorpanel_model_names[] = {"fs_obj_o_doorpanel.gj", NULL};
const char *bm_fs_obj_o_doorpanel_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_o_doorpanel_resource_descriptor = {
    "bm_fs_obj_o_doorpanel.bml", bm_fs_obj_o_doorpanel_model_names, bm_fs_obj_o_doorpanel_motion_names, 1, 0,
};
const char *key_ancient03_class_name = "TOKeyAncient03";
BmlResource *key_ancient03_model_archive;
// The panel's own texture list while up, fs_obj_o_doorpanelg.gvm while down.
NJS_TEXLIST **key_ancient03_texture_variants;

void TOKeyAncient03::vfunc_25() {}

// Pressed while a player stands on it (in once mode, latched once on).
s32 TOKeyAncient03::is_confirm_pressed() {
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

void TOKeyAncient03::send_switch_changed(s32 flags) {
    G_SwitchStateChanged_6x05 cmd;
    cmd.init();
    cmd.header.client_id = entity_id;
    cmd.unused1 = local_client_id;
    cmd.switch_id = switch_id;
    cmd.floor = get_current_floor();
    cmd.flags = flags;
    cmd.send();
}

void TOKeyAncient03::trigger_deactivate_sound() {
    play_sound_effect(0x4004B20D, &position, 0, 0);
}

void TOKeyAncient03::trigger_activate_sound() {
    play_sound_effect(0x4004B20D, &position, 0, 0);
}

void TOKeyAncient03::update_switch_off() {
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

void TOKeyAncient03::update_switch_on() {
    if (-0.7f < scale.y) {
        scale.y += -0.023333333f;
    }
}

void TOKeyAncient03::run_task() {
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

void TOKeyAncient03::render() {
    NJS_OBJECT *object;
    u32 flags;

    if (update_object_view_visibility(view_range, model_radius) != 0) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(key_ancient03_texture_variants[is_on]));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        object = model;
        post_translate_matrix(object->pos);
        draw_ginja_model(object->model);
        if (is_on != 1) {
            flags = model_render_flags;
            saved_model_render_flags = flags;
            model_render_flags = flags | 0x10;
            set_constant_material(&glow_color);
        }
        object = object->child;
        push_matrix();
        post_translate_matrix(&scale.x);
        post_translate_matrix(object->pos);
        draw_ginja_model(object->model);
        object = object->child;
        push_matrix();
        post_translate_matrix(object->pos);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model(object->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
        if (is_on != 1) {
            set_constant_material(&chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
        }
        pop_matrix();
    }
}

void *TOKeyAncient03::create(void *set_data) {
    return new TOKeyAncient03(tl_05, set_data);
}

void TOKeyAncient03::cleanup_refs() {
    if (key_ancient03_texture_variants != NULL) {
        free_if_valid(key_ancient03_texture_variants[1]);
        if (key_ancient03_texture_variants != NULL) {
            mem_free(key_ancient03_texture_variants);
            key_ancient03_texture_variants = NULL;
        }
    }
    if (key_ancient03_model_archive != NULL) {
        delete key_ancient03_model_archive;
        key_ancient03_model_archive = NULL;
    }
}

void TOKeyAncient03::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_fs_obj_o_doorpanel_resource_descriptor, 0, 0, NULL);
    NJS_TEXLIST **textures;
    key_ancient03_model_archive = resource;
    textures = (NJS_TEXLIST **)mem_alloc(2 * sizeof(*textures));
    key_ancient03_texture_variants = textures;
    textures[0] = key_ancient03_model_archive->models[0].texlist;
    key_ancient03_texture_variants[1] = LoadPvmFileTls("fs_obj_o_doorpanelg.gvm");
}

TOKeyAncient03::~TOKeyAncient03() {}

TOKeyAncient03::TOKeyAncient03(TObject *parent, void *set_data) : TOKey(parent) {
    m_name = key_ancient03_class_name;
    apply_object_set_data(set_data);
    init_switch_id();
    texlist = key_ancient03_texture_variants[0];
    model = key_ancient03_model_archive->models[0].model;
    view_range = 400.0f;
    model_radius = ((GinjaModelBounds *)model->model)->radius;
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
