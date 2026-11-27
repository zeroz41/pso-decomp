#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/key/TODummyKeyCave01Sound.h"
#include "pso/system/task/TObject.h"
#include "pso/object/key/TODummyKeyCave01.h"
#include "pso/object/key/TOKeyAncient03.h"
#include "pso/object/key/TOKeyCave01.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/BmlResource.h"
#include "pso/map/FloorArea.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/render/ChunkMaterialColor.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/DebugFont.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixReflect.h"

const char *dummy_key_cave01_class_name = "TODummyKeyCave01";
const char *dummy_key_cave01_sound_class_name = "TODummyKeyCave01Sound";
TODummyKeyCave01::TODummyKeyCave01(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = dummy_key_cave01_class_name;
    apply_object_set_data(set_data);
    color.b = 1.0f;
    color.g = 1.0f;
    color.r = 1.0f;
    color.a = 1.0f;
    key_offset.z = 0.0f;
    key_offset.y = 0.0f;
    key_offset.x = 0.0f;
    pulse_rising = 1;
    init_from_set_data();
    key_angle = 0;
}

TODummyKeyCave01::~TODummyKeyCave01() {

}


void TODummyKeyCave01::load_resources() {  }
void TODummyKeyCave01::free_resources() {  }
void *TODummyKeyCave01::create(void *set_data) {
    return new TODummyKeyCave01(tl_05, set_data);
}

void TODummyKeyCave01::run_task() {
    u32 st;
    u8 skip;
    if (check_demo_mode() == 1) {
        clear_actor_flags(0x08000000);
    }
    if (this->id < 0x100) {
        st = is_current_floor_switch_set(this->id);
        if (st != this->switch_state) {
            this->switch_state = st;
            skip = 0;
            if (mute_off_sound == 1 && st == 0) {
                skip = 1;
            }
            if (skip == 0) {
                new TODummyKeyCave01Sound(this, sound_kind, sound_delay);
            }
        }
    }
    if (this->switch_state == 1) {
        this->texlist = this->on_textures;
        f32 lo = (-0.7f);
        if (lo < key_offset.y) {
            key_offset.y += (-0.023333333f);
            if (key_offset.y < lo) {
                key_offset.y = lo;
            }
        }
        if (key_angle < 0x2000) {
            key_angle = key_angle + 0x333;
        }
    } else {
        this->texlist = this->off_textures;
        if (key_offset.y < (0.0f)) {
            key_offset.y = key_offset.y - (-0.023333333f);
            if ((0.0f) < key_offset.y) {
                key_offset.y = (0.0f);
            }
        }
        if (pulse_rising == 1) {
            color.r += 0.1f;
            if (1.0f <= color.r) {
                color.r = 1.0f;
                pulse_rising = 0;
            }
        } else {
            color.r -= 0.1f;
            if (color.r <= 0.0f) {
                color.r = 0.0f;
                pulse_rising = 1;
            }
        }
        if (key_angle > 0) {
            key_angle = key_angle - 0x333;
        }
    }
}

void TODummyKeyCave01::render() {
    NJS_TEXLIST *v;
    NJS_OBJECT *node;
    s32 id;
    if (this->update_object_view_visibility((4e+02f), (2e+01f)) != 0 && this->model != NULL &&
        (v = this->texlist) != NULL) {
        set_texlist(v);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_zyx(0, this->rotation.x, this->rotation.y, this->rotation.z);
        scale_current_matrix(&this->scale.x);
        node = model;
        draw_ginja_model(node->model);
        if (switch_state == 0) {
            id = model_render_flags;
            saved_model_render_flags = id;
            model_render_flags = id | 0x10;
            set_constant_material(&color);
        }
        begin_effect_render();
        node = node->child;
        if (spins != 0) {
            rotate_matrix_y(0, key_angle);
        } else {
            post_translate_matrix(&key_offset.x);
        }
        post_translate_matrix(node->pos);
        draw_ginja_model(node->model);
        node = node->child;
        post_translate_matrix(node->pos);
        draw_ginja_model(node->model);
        if (switch_state == 0) {
            set_constant_material(&chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
        }
        end_effect_render();
        pop_matrix();
    }
}

void TODummyKeyCave01::init_from_set_data() {
    spins = 0;
    id = set_params[0];
    if (id < 0x100) {
        switch_state = is_current_floor_switch_set(id);
    } else {
        id = 0xFFFF;
        switch_state = 1;
    }
    model_variant = set_params[1] & 0xFFFF;
    sound_delay = (u32)set_params[1] >> 16;
    sound_kind = set_params[2] & 0xFFFF;
    if (sound_kind > 6) {
        sound_kind = 0;
    }
    mute_off_sound = (u32)set_params[2] >> 16;
    if (mute_off_sound > 1) {
        mute_off_sound = 0;
    }
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        model = get_bml_model(key_cave01_resource_bundle, 0);
        this->off_textures = key_cave01_texture_lists[0];
        this->on_textures = key_cave01_texture_lists[1];
        break;
    case AREA_FOREST1:
    case AREA_FOREST2:
    case AREA_MINE1:
    case AREA_MINE2:
        model = get_bml_model(key_machine01_resource_bundle, 0);
        this->off_textures = key_machine01_texture_lists[0];
        this->on_textures = key_machine01_texture_lists[1];
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        model = get_bml_model((BmlResource *)key_ancient03_model_archive, 0);
        this->off_textures = key_ancient03_texture_variants[0];
        this->on_textures = key_ancient03_texture_variants[1];
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        if (model_variant == 0) {
            model = get_bml_model(key_cave01_resource_bundle, 0);
            this->off_textures = key_cave01_texture_lists[0];
            this->on_textures = key_cave01_texture_lists[1];
        } else {
            model = get_bml_model(key_machine01_resource_bundle, 0);
            this->off_textures = key_machine01_texture_lists[0];
            this->on_textures = key_machine01_texture_lists[1];
        }
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        model = get_bml_model(key_cave01_resource_bundle, 0);
        this->off_textures = key_cave01_texture_lists[0];
        this->on_textures = key_cave01_texture_lists[1];
        spins = 1;
        break;
    default:
        model = 0;
        this->off_textures = 0;
        this->on_textures = 0;
        break;
    }
}


TODummyKeyCave01Sound::TODummyKeyCave01Sound(TObject *parent, s32 kind, s32 delay) : TObject(parent) {
    m_name = dummy_key_cave01_sound_class_name;
    delay_frames = delay;
    sound_kind = kind;
    if ((s32) delay_frames <= 0) {
        play_cave01_key_sound();
        queue_destruction();
    }
}

TODummyKeyCave01Sound::~TODummyKeyCave01Sound() {}
void TODummyKeyCave01Sound::run_task() {
    this->delay_frames = (s32) (this->delay_frames - 1);
    if ((s32) this->delay_frames == 0) {
        play_cave01_key_sound();
        queue_destruction();
    }
}
