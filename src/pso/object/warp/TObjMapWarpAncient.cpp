#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/object/warp/TObjMapWarp.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include "pso/object/warp/TObjMapWarpAncient.h"
#include "pso/object/warp/TObjGoalWarpAncient.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

// Built -inline off,deferred: the functions below are written last-to-first, which puts
// __vt__19TObjGoalWarpAncient before __vt__18TObjMapWarpAncient in .data (the key function
// ~TObjGoalWarpAncient is defined after ~TObjMapWarpAncient) and the literals in the order of .text.

const char *bm_o_warp_ancient_model_names[7] = {
    "dd_obj3_swarp_ksita.gj", "de_obj2_swarp_beam.gj", "de_obj1_swarp_beam_n.gj", "fd_obj1_swarp_gawa.gj",
    "fd_obj2_swarp_nsita_1.gj", "fe_obj3_swarp_naka.gj", NULL,
};
const char *bm_o_warp_ancient_motion_names[4] = {
    "de_obj2_swarp_beam.njm", "de_obj1_swarp_beam_n.njm", "fe_obj3_swarp_naka.njm", NULL,
};
BmlResourceDescriptor bm_o_warp_ancient_resource_descriptor = {
    "bm_o_warp_ancient.bml", bm_o_warp_ancient_model_names, bm_o_warp_ancient_motion_names, 6, 3,
};
const char *TObjMapWarpAncient__class_name = "TObjMapWarpAncient";
const char *TObjGoalWarpAncient__class_name = "TObjGoalWarpAncient";
BmlResource *ancient_warp_shared_resource;
NJS_TEXLIST *goal_warp_ancient_gvm_texture;


extern "C" NJS_OBJECT *get_ancient_warp_model(s32 index) {
    return (NJS_OBJECT *)get_bml_model((BmlResource *)ancient_warp_shared_resource, index);
}

AnimationMotion *TObjGoalWarpAncient::register_warp(s32 index) {
    return get_bml_motion(ancient_warp_shared_resource, index);
}

NJS_TEXLIST *TObjGoalWarpAncient::get_goal_beam_textures() {
    return goal_warp_ancient_gvm_texture;
}

NJS_TEXLIST *TObjGoalWarpAncient::get_archive_textures(s32 index) {
    return get_bml_texlist((BmlResource *)ancient_warp_shared_resource, index);
}

void TObjGoalWarpAncient::load_resources() {
    BmlResource *resource = new BmlResource(1, &bm_o_warp_ancient_resource_descriptor, 0, 0, NULL);
    ancient_warp_shared_resource = resource;
    goal_warp_ancient_gvm_texture = load_gvm_texture_file("de_obj2_swarp_beam_r.gvm");
}

void TObjMapWarpAncient::free_globals() {
    TObjPlayer::free_if_valid((saddr)goal_warp_ancient_gvm_texture);
    goal_warp_ancient_gvm_texture = NULL;
    if (ancient_warp_shared_resource != NULL) {
        delete ancient_warp_shared_resource;
        ancient_warp_shared_resource = NULL;
    }
}

TObjMapWarpAncient::TObjMapWarpAncient(TObject *parent, void *set_data) : TObjMapWarp(parent, set_data) {
    m_name = TObjMapWarpAncient__class_name;
    beam_frame = 0.0f;
    beam_model = get_ancient_warp_model(2);
    ksita_model = get_ancient_warp_model(0);
    nsita_model = get_ancient_warp_model(4);
    beam_textures = TObjGoalWarpAncient::get_archive_textures(2);
    ksita_textures = TObjGoalWarpAncient::get_archive_textures(0);
    nsita_textures = TObjGoalWarpAncient::get_archive_textures(4);
    beam_motion = TObjGoalWarpAncient::register_warp(1);
}

TObjMapWarpAncient::~TObjMapWarpAncient() {}

void TObjMapWarpAncient::run_task() {
    if ((s32)set_params[1] >= 0) {
        beam_frame += 4.0f;
        if ((beam_motion->frameCount - 1) < beam_frame) {
            beam_frame = 0.0f;
        }
        process_player_warps();
    }
}

void TObjMapWarpAncient::draw_debug_destinations() {
    if ((s32)set_params[1] < 0) {
        TObjNpcEnemy::set_global_count(0xFF00FF);
        debug_printf_at(0x130021, "<- ONE WAY (POSITIVE: NORMAL)");
        TObjNpcEnemy::set_global_count(0xF0F0F0FF);
        return;
    }
    TObjMapWarp::draw_debug_destinations();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, "<- NORMAL (NEGATIVE: ONE WAY)");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjMapWarpAncient::render() {
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TParticleCtrl::begin_effect_render();
        if ((s32)set_params[1] >= 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(beam_textures));
            draw_ginja_model_with_motion(beam_model, beam_motion, beam_frame);
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(ksita_textures));
        draw_ginja_object(ksita_model);
        TParticleCtrl::end_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(nsita_textures));
        draw_ginja_object(nsita_model);
        pop_matrix();
    }
}

void *TObjMapWarpAncient::create(void *set_data) {
    return new TObjMapWarpAncient(tl_05, set_data);
}

TObjGoalWarpAncient::TObjGoalWarpAncient(TObject *parent, void *set_data) : TObjAreaWarp(parent, set_data) {
    m_name = TObjGoalWarpAncient__class_name;
    naka_frame = 0.0f;
    beam_frame = 0.0f;
    beam_model = get_ancient_warp_model(1);
    gawa_model = get_ancient_warp_model(3);
    naka_model = get_ancient_warp_model(5);
    if ((s32)set_params[2] < 0) {
        beam_textures = get_goal_beam_textures();
    } else {
        beam_textures = get_archive_textures(1);
    }
    gawa_textures = get_archive_textures(3);
    naka_textures = get_archive_textures(5);
    beam_motion = register_warp(0);
    naka_motion = register_warp(2);
    if (get_game_play_mode() == 1 && (s32)set_params[2] >= 0) {
        queue_destruction();
    }
    if (is_split_screen() == 1) {
        void *p = ::operator new(0x88);
        if (p != NULL) {
            p = ((TAdVIConfigGC *)p)->init(&position, 20.0f);
        }
        vi_config = (TAdVIConfigGC *)p;
    } else {
        vi_config = NULL;
    }
}

TObjGoalWarpAncient::~TObjGoalWarpAncient() {}

void TObjGoalWarpAncient::run_task() {
    beam_frame += 4.0f;
    if ((beam_motion->frameCount - 1) < beam_frame) {
        beam_frame = 0.0f;
    }
    naka_frame += 0.25f;
    if ((naka_motion->frameCount - 1) < naka_frame) {
        naka_frame = 0.0f;
    }
    handle_area_selection();
}

void TObjGoalWarpAncient::debug_print_area_num() {
    TObjAreaWarp::debug_print_area_num();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    if ((s32)set_params[2] < 0) {
        beam_textures = get_goal_beam_textures();
        debug_printf_at(0x130022, "<- GOAL (POSITIVE: START)");
    } else {
        beam_textures = get_archive_textures(1);
        debug_printf_at(0x130022, "<- START (NEGATIVE: GOAL)");
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjGoalWarpAncient::render() {
    if (update_object_view_visibility(400.0f, 20.0f) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(beam_textures));
        draw_ginja_model_with_motion(beam_model, beam_motion, beam_frame);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(naka_textures));
        draw_ginja_model_with_motion(naka_model, naka_motion, naka_frame);
        TParticleCtrl::end_effect_render();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(gawa_textures));
        draw_ginja_object(gawa_model);
        pop_matrix();
    }
}

void *TObjGoalWarpAncient::create(void *set_data) {
    return new TObjGoalWarpAncient(tl_05, set_data);
}
