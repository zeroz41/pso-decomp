#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/weapon/TItemWeaponSBerillsHands.h"
#include "pso/effect/TIndirectEffectDrawTask.h"
#include "pso/render/render_util.h"
#include "pso/render/CameraCapture.h"
#include "pso/render/GinjaDrawUtil.h"
#include "pso/player/TObjPlayer_803DC834.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TEffIndirectSampler.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/ambient/TObjFish.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTev.h>
#include <dolphin/gx/GXGeometry.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/mtx.h>

// Defined at the end of the file, where the original places it after the unit's other functions.
static void set_tex_coord_gen(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx);

#pragma readonly_strings on

// The battle-control texts TPlayerBattleCtrl's constructor picks by language (shift-JIS
// first); TPlayerBattleCtrl4P keeps the same table for its four-player window.
const char *player_battle_ctrl_text_japanese[7] = {
    "\x82\xE0\x82\xA4\x88\xEA\x93\x78\x81\x41\x93\xAF\x82\xB6\x83\x8B\x81\x5B\x83\x8B\x82\xC5\n\x8C\x88\x93\xAC\x82\xF0\x8D\x73\x82\xA2\x82\xDC\x82\xB7\x82\xA9\x81\x48", // もう一度、同じルールで 決闘を行いますか？
    "\x82\xCD\x82\xA2", // はい
    "\x82\xA2\x82\xA2\x82\xA6", // いいえ
    "\x83\x8D\x83\x72\x81\x5B\x82\xD6", // ロビーへ
    "\x91\xBC\x82\xCC\x90\x6C\x82\xC6\x82\xCC\x89\xF1\x90\xFC\x82\xAA\n\x82\xAB\x82\xEA\x82\xDC\x82\xB5\x82\xBD\n\x8E\x8E\x8D\x87\x8C\x8B\x89\xCA\x82\xCD\x96\xB3\x8C\xF8\x82\xC6\x82\xB5\x82\xDC\x82\xB7\n\n\x83\x72\x83\x57\x83\x85\x83\x41\x83\x8B\x83\x8D\x83\x72\x81\x5B\x82\xD6\n\x93\x5D\x91\x97\x82\xB5\x82\xDC\x82\xB7\x81\x42\nPress start button.", // 他の人との回線が きれました 試合結果は無効とします  ビジュアルロビーへ 転送します。 Press start button.
    "\x91\xBC\x82\xCC\x90\x6C\x82\xC6\x82\xCC\x89\xF1\x90\xFC\x82\xAA\n\x82\xAB\x82\xEA\x82\xDC\x82\xB5\x82\xBD\n\n\x83\x72\x83\x57\x83\x85\x83\x41\x83\x8B\x83\x8D\x83\x72\x81\x5B\x82\xD6\n\x93\x5D\x91\x97\x82\xB5\x82\xDC\x82\xB7\x81\x42\nPress start button.", // 他の人との回線が きれました  ビジュアルロビーへ 転送します。 Press start button.
    "\x8D\xA1\x89\xF1\x82\xCD\x83\x60\x81\x5B\x83\x80\x90\xED\x82\xC5\x82\xB7\x81\x42\n\x82\x60\x83\x60\x81\x5B\x83\x80\n  %s\n  %s\n\x82\x61\x83\x60\x81\x5B\x83\x80\n  %s\n  %s\n", // 今回はチーム戦です。 Ａチーム   %s   %s Ｂチーム   %s   %s
};
const char *player_battle_ctrl_text_english[7] = {
    "Do you want to \nfight the same\nrules?",
    "Yes",
    "No",
    "Lobby",
    "I'm sorry that you \nweren't able to do \nit. Please try again.\n\nTransporting to the \nvisual lobby.\nPress start button.",
    "I'm sorry that you \nweren't able to do \nit. Please try again.\n\nTransporting to the \nvisual lobby.\nPress start button.",
    "Team battle ok.\nA-TEAM\n  %s\n  %s\nB-TEAM\n  %s\n  %s\n",
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


void TIndirectEffectDrawTask::bind_capture_texture() {
    TObjFish::set_global_param(get_shared_capture_texture_list());
    load_list_texture(0, 0, 0, 2);
}

void TIndirectEffectDrawTask::reset_projection_tex_matrix() {
    set_ginja_post_tev_stage_count(0);
    set_ginja_post_texgen_count(0);
    set_global_effect_state(0);
    model_render_flags &= ~0x80000;
}

void TIndirectEffectDrawTask::setup_projection_tex_matrix() {
    GinjaMatrix mtx;
    f32 offset_x;
    f32 offset_y;
    f32 fovY;
    if (camera_ctrl_instance != NULL) {
        push_matrix();
        calc_projection_screen_offset(&offset_x, &offset_y);
        fovY = 0.0054931640625 * calc_camera_vertical_fov();
        if (TCameraCtrl::is_view_offset() != 0) {
            C_MTXLightPerspective(mtx, fovY, 1.1333334f, 0.5f, -0.5f, 0.5f - offset_x, 0.5f - offset_y);
        } else {
            C_MTXLightPerspective(mtx, fovY, 1.1333334f, 0.5f, -0.5f, 0.5f, 0.5f);
        }
        PSMTXConcat(mtx, *current_matrix, *current_matrix);
        load_current_tex_matrix(2);
        pop_matrix();
        load_current_pos_matrix(2);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE1, GX_DECAL);
        set_tex_coord_gen(GX_TEXCOORD1, GX_TG_MTX3x4, GX_TG_POS, GX_TEXMTX2);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
        set_global_effect_state(1);
    }
}

void TIndirectEffectDrawTask::store_record(IndirectDrawRecord *record) {
    if (entry_count < 0x10) {
        entries[entry_count] = *record;
    }
}
IndirectDrawRecord &IndirectDrawRecord::operator=(IndirectDrawRecord &other) {
    placement = other.placement;
    texlist = other.texlist;
    model = other.model;
    scene = other.scene;
    effect_kind = other.effect_kind;
    reserved = other.reserved;
    return *this;
}

void TIndirectEffectDrawTask::render() {
    s32 i;
    for (i = 0; i < this->entry_count; i++) {
        request_indirect_effect(this->entries[i].effect_kind);
        set_material_alpha_compare_reference(this->entries[i].scene);
        set_depth_buffer_settings_1();
        set_draw_list_mask(3);
        push_matrix();
        post_translate_matrix(&this->entries[i].placement.position.x);
        rotate_matrix_by_node_angles(&this->entries[i].placement.angles.x, 1);
        play_indirect_effect_recipe(this->entries[i].effect_kind, 1, 1);
        bind_capture_texture();
        setup_projection_tex_matrix();
        TObjFish::set_global_param(this->entries[i].texlist);
        draw_ginja_object(this->entries[i].model);
        pop_matrix();
        reset_indirect_tev(1);
        reset_projection_tex_matrix();
    }
}

void TIndirectEffectDrawTask::run_task() {
    s32 i;
    if (this->entries == 0) {
        this->queue_destruction();
        return;
    }
    for (i = 0; i < this->entry_count; i++) {
        clear_draw_record(&this->entries[i]);
    }
    this->entry_count = 0;
}


static TIndirectEffectDrawTask *indirect_draw_task;

TIndirectEffectDrawTask::~TIndirectEffectDrawTask() {
    if (this->entries != NULL) {
        mem_free(this->entries);
    }
    indirect_draw_task = 0;
}


TIndirectEffectDrawTask::TIndirectEffectDrawTask(TObject *parent) : TObject(parent) {
    s32 i;
    entry_count = 0;
    entries = (IndirectDrawRecord *)mem_alloc(0x240);
    if (entries != NULL) {
        for (i = 0; i < 0x10; i++) {
            clear_draw_record(&entries[i]);
        }
    }
    indirect_draw_task = this;
}

void TIndirectEffectDrawTask::queue_record(IndirectDrawRecord *record) {
    if (indirect_draw_task != NULL && indirect_draw_task->entry_count < 0x10) {
        indirect_draw_task->store_record(record);
        indirect_draw_task->entry_count = indirect_draw_task->entry_count + 1;
    }
}

void TIndirectEffectDrawTask::clear_instance_on_floor_free() { indirect_draw_task = 0; }

void TIndirectEffectDrawTask::clear_instance_on_floor_load() { indirect_draw_task = 0; }

// The SDK's GXSetTexCoordGen out of line: no normalisation, identity post-transform.
static void set_tex_coord_gen(GXTexCoordID dst_coord, GXTexGenType func, GXTexGenSrc src_param, u32 mtx) {
    GXSetTexCoordGen2(dst_coord, func, src_param, mtx, GX_FALSE, GX_PTIDENTITY);
}
