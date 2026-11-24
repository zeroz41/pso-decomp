#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_8033E910.h"
#include "pso/player/TObjPlayer_80307618.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"
#include "pso/unk/TUnk_804EFA88.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaTextureMatrices.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TEffIndirectSampler.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_8033ECB0.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/ambient/TObjFish.h"
#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTev.h>
#undef PSO_SDK_COMPACT_MATH
#include <dolphin/mtx.h>

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
struct ByteBlock_C { u8 bytes[0xc]; };


extern "C" {
s32 rotate_matrix_by_node_angles(void *, int);
s32 post_translate_matrix(void *);
void draw_ginja_object(saddr);
void set_material_alpha_compare_reference(s32 reference);
}
f32 calc_camera_fov_degrees(void);
void set_ginja_post_texgen_count(s32 x);
void set_ginja_post_tev_stage_count(s32 x);
void load_current_pos_matrix(s32 arg0);
void load_current_tex_matrix(s32 i);
void load_list_texture(s32 idx, s32 wrapS, s32 wrapT, s32 map);

void init_particle_effect__10TObjPlayerFv(void) { TObjFish::set_global_param(get_shared_capture_texture_list()); load_list_texture(0, 0, 0, 2); }

void reset_effects__10TObjPlayerFv(void) { set_ginja_post_tev_stage_count((saddr)(0)); set_ginja_post_texgen_count((saddr)(0)); TObjPlayer::set_global_effect_state((saddr)(0)); model_render_flags = (model_render_flags & 0xfff7ffff); }

void setup_projection_tex_matrix__10TObjPlayerFv(void) {
    GinjaMatrix mtx;
    f32 spC;
    f32 sp8;
    f32 fovY;
    if (camera_ctrl_instance != NULL) {
        push_matrix();
        calc_projection_screen_offset(&spC, &sp8);
        fovY = (f32) (0.0054931640625 * calc_camera_fov_degrees());
        if (TCameraCtrl::is_view_offset() != 0) {
            C_MTXLightPerspective(mtx, fovY, 1.1333334f, 0.5f, -0.5f, (f32) (0.5f - spC), (f32) (0.5f - sp8));
        } else {
            C_MTXLightPerspective(mtx, fovY, 1.1333334f, 0.5f, -0.5f, 0.5f, 0.5f);
        }
        PSMTXConcat(mtx, *current_matrix, *current_matrix);
        load_current_tex_matrix(2);
        pop_matrix();
        load_current_pos_matrix(2);
        GXSetTevOrder(GX_TEVSTAGE1, GX_TEXCOORD1, GX_TEXMAP2, GX_COLOR0A0);
        GXSetTevOp(GX_TEVSTAGE1, GX_DECAL);
        set_tex_coord_gen2(1, 0, 0, 0x24);
        model_render_flags |= 0x80000;
        set_ginja_post_tev_stage_count(1);
        set_ginja_post_texgen_count(1);
        TObjPlayer::set_global_effect_state((saddr)((1)));
    }
}

void TObjPlayer::free_indexed_entry(s32 _w1) {
    s32 temp_r0;

    temp_r0 = (this->m_20);
    if (temp_r0 < 0x10) {
        ((TObjPlayer *)(*(saddr *)((s8 *)this + 0x1C) + (temp_r0 * 0x24)))->copy_node_record(_w1);
    }
}
void TObjPlayer::copy_node_record(saddr arg1) {
    saddr arg0 = (saddr)this;
    *(ByteBlock_C *)(arg0) = *(const ByteBlock_C *)(arg1);
    *(ByteBlock_C *)(arg0 + 0xC) = *(const ByteBlock_C *)(arg1 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) *(s32 *)((s8 *)arg1 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg1 + 0x1C);
    *(u16 *)((s8 *)arg0 + 0x20) = (u16) *(u16 *)((s8 *)arg1 + 0x20);
    *(u8 *)((s8 *)arg0 + 0x22) = (u8) *(u8 *)((s8 *)arg1 + 0x22);
    *(u8 *)((s8 *)arg0 + 0x23) = (u8) *(u8 *)((s8 *)arg1 + 0x23);
}

void TUnk_804EFA88::render() {
    s32 i;
    for (i = 0; i < this->entry_count; i++) {
        request_indirect_effect(this->entries[i].effect_kind);
        set_material_alpha_compare_reference(this->entries[i].scene);
        set_depth_buffer_settings_1();
        set_draw_list_mask(3);
        push_matrix();
        post_translate_matrix(this->entries[i].a);
        rotate_matrix_by_node_angles(this->entries[i].b, 1);
        play_indirect_effect_recipe(this->entries[i].effect_kind, 1, 1);
        ((void (*)(void *))init_particle_effect__10TObjPlayerFv)(this);
        ((void (*)(void *))setup_projection_tex_matrix__10TObjPlayerFv)(this);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->entries[i].p18));
        draw_ginja_object((this->entries[i].p1C));
        pop_matrix();
        reset_indirect_tev(1);
        ((void (*)(void *))reset_effects__10TObjPlayerFv)(this);
    }
}

void TUnk_804EFA88::run_task() {
    s32 i;
    if (this->entries == 0) {
        this->queue_destruction();
        return;
    }
    for (i = 0; i < this->entry_count; i++) {
        TLobby__sub_8033EE38(&this->entries[i]);
    }
    this->entry_count = 0;
}


TUnk_804EFA88 *lbl_805D6DA0;

TUnk_804EFA88::~TUnk_804EFA88() {
    if (this->entries != NULL) {
        mem_free(this->entries);
    }
    lbl_805D6DA0 = 0;
}


TUnk_804EFA88::TUnk_804EFA88(TObject *parent) : TObject(parent) {
    s32 i;
    entry_count = 0;
    entries = (Item_8033EB4C *)mem_alloc(0x240);
    if (entries != NULL) {
        for (i = 0; i < 0x10; i++) {
            TLobby__sub_8033EE38(&entries[i]);
        }
    }
    lbl_805D6DA0 = this;
}

void TLobby::release_indexed_entry(s32 arg0) {
    if (lbl_805D6DA0 != NULL && lbl_805D6DA0->entry_count < 0x10) {
        ((TObjPlayer *)lbl_805D6DA0)->free_indexed_entry(arg0);
        lbl_805D6DA0->entry_count = lbl_805D6DA0->entry_count + 1;
    }
}

void TLobby__sub_8033EDF8(void) { lbl_805D6DA0 = 0; }

void TLobby__sub_8033EE04(void) { lbl_805D6DA0 = 0; }
