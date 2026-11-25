#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaUvScroll.h"
#include "types.h"
#include "pso/object/fence/TLazerFenceSw.h"

struct BmlResource;
struct NJS_TEXLIST;

#include "pso/render/NinjaUtil.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/render/render_util.h"
#include <dolphin/base/PPCArch.h>
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

#include "pso/object/door/TObjDoorJung.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"

#include "pso/object/fence/TObjLazerFence4.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/object/key/TOKey.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/render/model_render_state.h"



extern const char *fe_obj_switch_laz_model_names[4];
extern const char *fe_obj_switch_laz_motion_names[3];
extern BmlResourceDescriptor laser_fence_switch_resource_descriptor;






extern "C" {

void debug_printf_at(int, void *, ...);
extern u8 lbl_80445CD8[];


__declspec(section ".data") NJS_OBJECT *lazer_fence_sw_ginja_model_table[2];
__declspec(section ".data") uaddr lazer_fence_beam_motions[2];
// The models of the first three children of switch model 0 (the beams).
__declspec(section ".data") void *lazer_fence_beam_node_table[3];
}

__declspec(section ".data") const char *fe_obj_switch_laz_model_names[4] = { "fe_obj_switch_laz.gj", "fs_obj_switch_laz_moto.gj", "fs_obj_switch_laz_moto_taiki.gj", NULL };
__declspec(section ".data") const char *fe_obj_switch_laz_motion_names[3] = { "fe_obj_switch_laz.njm", "fs_obj_switch_laz_moto.njm", NULL };
BmlResourceDescriptor laser_fence_switch_resource_descriptor = { "fe_obj_switch_laz.bml", fe_obj_switch_laz_model_names, fe_obj_switch_laz_motion_names, 3, 2 };
extern "C" {
__declspec(section ".data") const char *fe_obj_switch_laz_j_model_names[4] = { "fe_obj_switch_laz.gj", "fs_obj_switch_laz_moto.gj", "fs_obj_switch_laz_moto_taiki.gj", NULL };
__declspec(section ".data") const char *fe_obj_switch_laz_j_motion_names[3] = { "fe_obj_switch_laz.njm", "fs_obj_switch_laz_moto.njm", NULL };
BmlResourceDescriptor fe_obj_switch_laz_j_resource_descriptor = { "fe_obj_switch_laz_j.bml", fe_obj_switch_laz_j_model_names, fe_obj_switch_laz_j_motion_names, 3, 2 };
CollisionBody lazer_fence_sw_collision_body_part[] = {
    {{0.0f, 10.0f, 0.0f}, 7.0f, 12.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
const u16 lbl_80445CB8[4] = { 0, 1, 2, 3 };
}
const char *TLazerFenceSw::class_name = "TLazerFenceSw";
extern "C" {

BmlResource *lazer_fence_switch_bml_resource;
NJS_TEXLIST *lazer_fence_sw_texture_list;
u8 *lazer_fence_switch_scroll_node;

#pragma push
#pragma opt_common_subs off
void TLazerFenceSw::draw_laser_beam() {
    s32 i;

    for (i = 0; i < 3; i++) {
        set_ginja_model_texture_slot(lazer_fence_beam_node_table[i], color_slot);
    }
    TObjFish::set_global_param(lazer_fence_sw_texture_list);
    if (actor_frame_tick != last_scroll_tick && uv_scroll >= 1.0f) {
        last_scroll_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(reinterpret_cast<NJS_OBJECT *>(lazer_fence_switch_scroll_node)->model), 0, (s32)uv_scroll, 5, 1);
        PPCSync();
        uv_scroll = uv_scroll - (f32)(s32)uv_scroll;
    }
    switch (is_on) {
    case 0:
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_ginja_object(lazer_fence_sw_ginja_model_table[1]);
        TParticleCtrl::begin_effect_render();
        model_render_flags |= 0x01000000;
        draw_ginja_model_with_motion(lazer_fence_sw_ginja_model_table[0], (void *)lazer_fence_beam_motions[0], (f32)animation_frame);
        model_render_flags &= ~0x01000000;
        TParticleCtrl::end_effect_render();
        pop_matrix();
        break;
    case 1:
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        draw_ginja_model_with_motion(lazer_fence_sw_ginja_model_table[1], (void *)lazer_fence_beam_motions[1], (f32)switch_frame);
        TParticleCtrl::begin_effect_render();
        model_render_flags |= 0x01000000;
        draw_ginja_model_with_motion(lazer_fence_sw_ginja_model_table[0], (void *)lazer_fence_beam_motions[0], (f32)animation_frame);
        model_render_flags &= ~0x01000000;
        TParticleCtrl::end_effect_render();
        pop_matrix();
        break;
    }
}
void TLazerFenceSw::render() {
    if (this->update_object_view_visibility(4e+02f, 2e+01f) != 0) {
        if (TMainTask::get_render_pass() != 1) {
            set_draw_list_mask(3);
            set_material_alpha_compare_reference(0x80);
            if (distance_fade.update_visibility(&this->position) != 0) {
                if (distance_fade.is_translucent() != 0) {
                    distance_fade.set_flags_and_apply_damage_color();
                    draw_laser_beam();
                    distance_fade.clear_flag_and_notify();
                } else {
                    draw_laser_beam();
                }
            }
            set_material_alpha_compare_reference(0x8F);
            restore_draw_list_mask();
        }
    }
}
#pragma pop

__declspec(section ".rodata") u8 lbl_80445CD8[16] = "<- SELECT COLOR";
void TLazerFenceSw::debug_draw_key_id() {
    TOKey::debug_draw_key_id();
    if (set_params[2] < 0) {
        set_params[2] = 0;
    }
    color_slot = lbl_80445CB8[set_params[2] % 4];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130022, lbl_80445CD8);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TLazerFenceSw::trigger_activate_sound() {
    this->TOKey::trigger_activate_sound();
    this->animation_frame = 0.0f;
    switch_frame = 0.0f;
}

void TLazerFenceSw::trigger_deactivate_sound() {
    this->TOKey::trigger_deactivate_sound();
    this->animation_frame = 0.0f;
    switch_frame = 0.0f;
}

void TLazerFenceSw::update_switch_on() {
    u32 animation_frame;
    u32 temp_r4_2;
    this->animation_frame = (f32) (this->animation_frame + this->animation_step);
    animation_frame = *(s32 *)((s8 *)lazer_fence_beam_motions[0] + 4) - 1;
    if (this->animation_frame > (f32) animation_frame) {
        this->animation_frame = (f32) animation_frame;
    }
    switch_frame = (f32) (switch_frame + this->animation_step);
    temp_r4_2 = *(s32 *)((s8 *)lazer_fence_beam_motions[1] + 4) - 1;
    if (switch_frame > (f32) temp_r4_2) {
        switch_frame = (f32) temp_r4_2;
    }
}

void TLazerFenceSw::update_switch_off() {
    this->animation_frame = (f32) (this->animation_frame + this->animation_step);
    if (this->animation_frame > (f32) (u32) (*(s32 *)((s8 *)lazer_fence_beam_motions[0] + 4) - 1)) {
        this->animation_frame = (f32) 0.0f;
    }
    this->submit_cursor_target();
}

void TLazerFenceSw::run_task() {
    distance_fade.step_fade();
    TOKey::run_task();
    uv_scroll += 0.2f;
}

void *TLazerFenceSw::create(void *set_data) {
    return new TLazerFenceSw(tl_05, set_data);
}
}

void free_lazer_fence_switch_resources() {
    if (lazer_fence_switch_bml_resource != NULL) {
        delete (BmlResource *)lazer_fence_switch_bml_resource;
        lazer_fence_switch_bml_resource = NULL;
    }
    TObjPlayer::free_if_valid((saddr)lazer_fence_sw_texture_list);
    lazer_fence_sw_texture_list = NULL;
}

#pragma push
#pragma opt_propagation off
void TLazerFenceSw::load_resources() {
    s32 area;
    BmlResource *obj;
    s32 j;
    s32 i;
    NJS_OBJECT *n;
    lazer_fence_switch_bml_resource = NULL;
    area = get_current_floor_area();
    if (TContainerAncient01::is_global_state_in_table() == 1 || area == AREA_SEABED_UPPER || area == AREA_SEABED_LOWER) {
        obj = new BmlResource(5, (BmlResourceDescriptor *)&fe_obj_switch_laz_j_resource_descriptor, 0, 0, NULL);
        lazer_fence_switch_bml_resource = obj;
        lazer_fence_sw_texture_list = LoadPvmFileTls(fe_obj_switch_laz_j_gvm);
    } else {
        obj = new BmlResource(5, &laser_fence_switch_resource_descriptor, 0, 0, NULL);
        lazer_fence_switch_bml_resource = obj;
        if (game_difficulty_selection == 3) {
            lazer_fence_sw_texture_list = LoadPvmFileTls(fe_obj_switch_laz_a_gvm);
        } else {
            lazer_fence_sw_texture_list = LoadPvmFileTls(fe_obj_switch_laz_gvm);
        }
    }
    lazer_fence_sw_ginja_model_table[0] = get_bml_model(lazer_fence_switch_bml_resource, 0);
    lazer_fence_sw_ginja_model_table[1] = get_bml_model(lazer_fence_switch_bml_resource, 1);
    lazer_fence_beam_motions[0] = (uaddr)get_bml_motion(lazer_fence_switch_bml_resource, 0);
    lazer_fence_beam_motions[1] = (uaddr)get_bml_motion(lazer_fence_switch_bml_resource, 1);
    for (j = 0; j < 3; j++) {
        lazer_fence_beam_node_table[j] = NULL;
    }
    i = 0;
    n = lazer_fence_sw_ginja_model_table[0]->child;
    if (n != NULL) {
        lazer_fence_beam_node_table[i] = n->model;
        i++;
        n = n->sibling;
        while (n != NULL && i < 3) {
            lazer_fence_beam_node_table[i] = n->model;
            i++;
            n = n->sibling;
        }
    }
    lazer_fence_switch_scroll_node = (u8 *)find_object_node(lazer_fence_sw_ginja_model_table[1], 3);
}
#pragma pop

__declspec(section ".rodata") const char fe_obj_switch_laz_j_gvm[] = "fe_obj_switch_laz_j.gvm";
__declspec(section ".rodata") const char fe_obj_switch_laz_a_gvm[] = "fe_obj_switch_laz_a.gvm";
__declspec(section ".rodata") const char fe_obj_switch_laz_gvm[] = "fe_obj_switch_laz.gvm";

TLazerFenceSw::~TLazerFenceSw() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_common_subs off
TLazerFenceSw::TLazerFenceSw(TObject *parent, void *set_entry) : TOKey(parent) {
    m_name = class_name;
    init_key(set_entry);
    if (this->set_params[2] < 0) {
        this->set_params[2] = 0;
    }
    color_slot = lbl_80445CB8[this->set_params[2] % 4];
    this->animation_step = 2.0f;
    switch_frame = 0.0f;
    init_collision_body_parts(this, lazer_fence_sw_collision_body_part, 1);
    actorFlags |= 0x40000000;
    this->register_object_by_id();
    distance_fade.reset();
    distance_fade.set_fade_distance(2.9e+02f);
    uv_scroll = 0.0f;
    last_scroll_tick = 0;
}

#pragma pop
