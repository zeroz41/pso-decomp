#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaUvScroll.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/door/TObjDoorKey.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/ambient/TObjEnvSoundGlobal.h"
#include <dolphin/base/PPCArch.h>
#include "pso/render/ChunkMaterialColor.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/render/DebugFont.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/key/TOKey.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/psoLoadTexture.h"


struct BmlResource;
struct NJS_TEXLIST;

const char *abeno_fs_obj001_fosuno_model_names[4] = { "abeno_fs_obj001_fosuno.gj", "abesu_fs_obj001_fosu.gj", "abesu_fs_obj001_fotutu.gj", NULL };
const char *abeno_fs_obj001_fosuno_motion_names[1] = { NULL };
BmlResourceDescriptor door_key_resource_descriptor = { "abeno_fs_obj001_fosuno.bml", abeno_fs_obj001_fosuno_model_names, abeno_fs_obj001_fosuno_motion_names, 3, 0 };
CollisionBody door_key_collision_body_parts[] = {
    {{0.0f, 10.0f, 0.0f}, 7.0f, 50.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
/* beam colour (a, r, g, b) per key id */
NJS_ARGB door_key_beam_color_table[10] = {
    { 1.0f, 0.8235294f, 0.09803922f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.8235294f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.8235294f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.5019608f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.5019608f, 0.8235294f },
    { 1.0f, 0.7058824f, 0.9019608f, 0.09803922f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.39215687f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
};
const char *door_key_class_name = "TObjDoorKey";

NJS_OBJECT *door_key_ginja_model_table[4];
BmlResource *door_key_resource_handle;
NJS_TEXLIST *door_key_texture_handle;
u16 door_key_id_counter;
s32 beam_uv_scroll_last_tick;

TObjDoorKey *find_door_key_by_id(u16 id) {
    TObject *next = tl_05->m_down;
    TObject *cur;
    while (tl_05->m_down != NULL && next != NULL) {
        cur = next;
        next = cur->m_next;
        if (cur->check_value_equals(door_key_class_name) != 0 && cur->m_id == id) {
            return static_cast<TObjDoorKey *>(cur);
        }
    }
    return NULL;
}

void activate_door_key(u16 id, u16) {
    TObjDoorKey *key;

    key = find_door_key_by_id(id);
    if (key != NULL) {
        key->activated = 1;
    }
}


void TObjDoorKey::render() {

    if (this->update_object_view_visibility(400.0f, 20.0f) == 0) {
        if (particle != NULL) {
            particle->enable();
        }
    } else {
        if (particle != NULL) {
            particle->clear_active_flag();
        }
        switch (this->is_on) {
        case 0:
            draw_inactive_badge();
            return;
        case 1:
            draw_active_beam();
            return;
        }
    }
}

void TObjDoorKey::draw_active_beam() {
    if (beam_uv_scroll_last_tick != actor_frame_tick) {
        scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(door_key_ginja_model_table[1]->model), 0, 0x14, 0xE, 1);
        PPCSync();
        beam_uv_scroll_last_tick = actor_frame_tick;
    }
    set_texture_list(door_key_texture_handle);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_ginja_object(door_key_ginja_model_table[0]);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    set_constant_material(&door_key_beam_color_table[set_params[2]]);
    draw_ginja_object(door_key_ginja_model_table[1]);
    rotate_matrix_y(0, spin_angle);
    NJS_OBJECT **g = door_key_ginja_model_table;
    set_ginja_model_texture_slot(reinterpret_cast<void *>(g[2]->model), ((u16)set_params[2]));
    draw_ginja_object(g[2]);
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoorKey::draw_inactive_badge() {
    set_texture_list(door_key_texture_handle);
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    draw_ginja_object(door_key_ginja_model_table[0]);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    set_constant_material(&door_key_beam_color_table[set_params[2]]);
    NJS_OBJECT **g = door_key_ginja_model_table;
    set_ginja_model_texture_slot(reinterpret_cast<void *>(g[2]->model), ((u16)set_params[2]));
    draw_ginja_object(g[2]);
    set_constant_material(&chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoorKey::debug_draw_key_id() {
    TOKey::debug_draw_key_id();
    VecCopy(&center, &position);
    center.y += 8.0f;
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x130022, "PLATE NUM : %d", set_params[2]);
    set_debug_text_color(0xF0F0F0FF);
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    if (set_params[2] > 9) {
        set_params[2] = 9;
    }
}

void TObjDoorKey::trigger_deactivate_sound() {  }

void TObjDoorKey::trigger_activate_sound() {
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x42D0A, &position, 0, 0);
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4C601, &position, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C601, &position, 0, 0);
        break;
    default:
        play_sound_effect(0x4C60A, &position, 0, 0);
        break;
    }
    activated = 1;
}

void TObjDoorKey::update_switch_on() {
    unk_F4 = unk_F4 + 0x14;
    spin_angle = (spin_angle + 0x200);
}

void TObjDoorKey::update_switch_off() { submit_cursor_candidate(this, -1); }
void TObjDoorKey::update_armed_switch() { TOKey::update_armed_switch(); }

void TObjDoorKey::run_task() {
    update_armed_switch();
}
TObjDoorKey::~TObjDoorKey() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
    if (particle != NULL) {
        particle->queue_destruction();
        particle = NULL;
    }
}
TObjDoorKey::TObjDoorKey(TObject *parent, void *set_entry) : TOKey(parent) {
    this->m_name = door_key_class_name;
    init_key(set_entry);
    activated = 0;
    spin_angle = 0;
    unk_EC = 0x14;
    unk_F4 = 0;
    particle = NULL;
    this->m_id = door_key_id_counter++;
    if (this->set_params[2] < 0) {
        this->set_params[2] = 0;
    }
    if (this->set_params[2] > 9) {
        this->set_params[2] = 9;
    }
    init_collision_body_parts(this, door_key_collision_body_parts, 1);
    this->actorFlags |= 0x40000000;
    this->register_object_by_id();
    Vec pos = this->position;
    pos.y += 10.0f;
    particle = spawn_continuous_particle_effect_with_flags(&pos, 0x60, 0x40);
    this->cursor_action.set_use();
}


void *TObjDoorKey::create(void *set_entry) {
    void *o = new TObjDoorKey((TObject *)tl_05, set_entry);
    return o;
}

void TObjDoorKey::free_key() {
    if (door_key_resource_handle != NULL) {
        delete door_key_resource_handle;
        door_key_resource_handle = NULL;
    }
    TObjPlayer::free_if_valid(door_key_texture_handle);
    door_key_texture_handle = NULL;
    beam_uv_scroll_last_tick = 0;
}

void TObjDoorKey::load_resources() {
    saddr r = (saddr)new BmlResource(5, &door_key_resource_descriptor, 0, 0, NULL);
    door_key_resource_handle = (BmlResource *)r;
    door_key_texture_handle = LoadPvmFileTls("fe_obj_switch.gvm");
    door_key_ginja_model_table[0] = get_bml_model(door_key_resource_handle, 1);
    door_key_ginja_model_table[1] = get_bml_model(door_key_resource_handle, 2);
    NJS_OBJECT *t = get_bml_model(door_key_resource_handle, 0);
    door_key_id_counter = 0;
    door_key_ginja_model_table[2] = t;
    beam_uv_scroll_last_tick = 0;
}

void *TObjEnvSoundGlobal::create(void *rader_map_core) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return NULL;
    }
    return new TObjEnvSoundGlobal((TObject *)tl_05, rader_map_core);
}

