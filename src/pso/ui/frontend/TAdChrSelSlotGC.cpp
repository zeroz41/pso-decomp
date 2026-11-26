#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"

NJS_TEXNAME chr_sel_slot_texnames_eng[1] = { { "f256_slot_eng", 0, 0 } };
__declspec(section ".data") NJS_TEXLIST chr_sel_slot_texlist_eng = { chr_sel_slot_texnames_eng, 1 };
NJS_TEXNAME chr_sel_slot_texnames[1] = { { "f256_slot", 0, 0 } };
__declspec(section ".data") NJS_TEXLIST chr_sel_slot_texlist = { chr_sel_slot_texnames, 1 };
const char *TAdChrSelSlotGC__name = "TAdChrSelSlotGC";
/* per current_language: texture archive and texture list */
const char *const chr_sel_slot_resource_name_table[5] = { "f256_slot", "f256_slot_eng", "f256_slot_eng", "f256_slot_eng", "f256_slot_eng" };
NJS_TEXLIST *const chr_sel_slot_texlist_table[6] = { &chr_sel_slot_texlist, &chr_sel_slot_texlist_eng, &chr_sel_slot_texlist_eng, &chr_sel_slot_texlist_eng, &chr_sel_slot_texlist_eng, NULL };

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#include <stddef.h>
#include "pso/ui/frontend/TAdMcSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/vector.h"
#include "pso/render/GinjaTexture.h"

NJS_TEXLIST *chr_sel_slot_texlist_current;
f32 char_select_slot_quad_width, char_select_slot_quad_height;
extern const s32 current_language;


void TAdChrSelSlotGC::draw_slot_icons() {
    u32 i;
    for (i = 0; i < 5; i++) {
        if (visible[i] != 0) {
            begin_screen_draw(1);
            TObjFish::set_global_param(chr_sel_slot_texlist_current);
            set_draw_texture_and_color(0, colors[i]);
            draw_textured_quad_at_depth((f32 *)&quads[i], 0.1f);
            TWindowSubStatusDisp::get_player();
        }
    }
}

void TAdChrSelSlotGC::render() {
    if ((s32) this->enabled == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
        goto block_5;
    }
    if ((s32)this->defer_render() == 0) {
        set_depth_buffer_settings_2();
block_5:
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        draw_slot_icons();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        if ((s32) this->enabled == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

void TAdChrSelSlotGC::reset_all_slots() {
    sub_802C754C(0);
    sub_802C754C(1);
    hide_slot_entry(0);
    hide_slot_entry(1);
    hide_slot_entry(2);
}

void TAdChrSelSlotGC::hide_slot_entry(s32 i) {
    visible[i + 2] = 0;
}

void TAdChrSelSlotGC::init_slot_entry(s32 slot, void *position) {
    visible[slot + 2] = 1;
    copy_vec2(&positions[slot + 2], position);
    quads[slot + 2].left = positions[slot + 2].x;
    quads[slot + 2].top = positions[slot + 2].y;
    quads[slot + 2].right = 174.0f + positions[slot + 2].x;
    quads[slot + 2].bottom = 24.0f + positions[slot + 2].y;
    alpha[slot + 2] = 0;
}

void TAdChrSelSlotGC::sub_802C754C(s32 i) {
    visible[i] = 0;
}

void TAdChrSelSlotGC::init_slot(s32 slot, void *position) {
    visible[slot] = 1;
    copy_vec2(&positions[slot], position);
    quads[slot].left = positions[slot].x;
    quads[slot].top = positions[slot].y;
    quads[slot].right = 174.0f + positions[slot].x;
    quads[slot].bottom = 32.0f + positions[slot].y;
    alpha[slot] = 0;
}

void TAdChrSelSlotGC::run_task() {
    ++frame;
    for (u32 i = 0; i < 5; ++i) {
        if (i < 2) {
            char_select_slot_quad_width = 174.0f;
            char_select_slot_quad_height = 32.0f;
        } else {
            char_select_slot_quad_width = 174.0f;
            char_select_slot_quad_height = 24.0f;
        }
        quads[i].left = positions[i].x;
        quads[i].top = positions[i].y;
        quads[i].right = positions[i].x + char_select_slot_quad_width;
        quads[i].bottom = positions[i].y + char_select_slot_quad_height;
        if (visible[i]) {
            alpha[i] += 22;
            alpha[i] = alpha[i] > 255 ? 255 : alpha[i];
            colors[i] = (alpha[i] << 24) | 0x00FFFFFF;
        } else {
            alpha[i] = 0;
            colors[i] = (alpha[i] << 24) | 0x00FFFFFF;
        }
    }
}

TAdChrSelSlotGC::~TAdChrSelSlotGC() {}

#pragma push
#pragma fp_contract on
TAdChrSelSlotGC::TAdChrSelSlotGC(TObject*object) : TObject((object)) {
    u32 i;
    u32 j;
    u32 k;
    f32 t;
    m_name = TAdChrSelSlotGC__name;
    frame = -1;
    enabled = 1;
    for (i = 0; i < 5; i++) {
        colors[i] = 0;
        alpha[i] = 0;
    }
    for (j = 0; j < 2; j++) {
        visible[j] = 0;
        quads[j].u0 = 0.0f;
        t = 32.0f * (f32)j;
        quads[j].v0 = t / 256.0f;
        quads[j].u1 = 174.0f / 256.0f;
        quads[j].v1 = (32.0f + t) / 256.0f;
    }
    for (k = 0; k < 3; k++) {
        visible[k + 2] = 0;
        quads[k + 2].u0 = 0.0f;
        quads[k + 2].v0 = (24.0f * (f32)k + 64.0f) / 256.0f;
        quads[k + 2].u1 = 174.0f / 256.0f;
        quads[k + 2].v1 = (24.0f * (k + 1) + 64.0f) / 256.0f;
    }
}

#pragma pop

void TLobby__sub_802C78EC(void) {
    if (chr_sel_slot_texlist_current != NULL) {
        release_texture_list(chr_sel_slot_texlist_current);
        chr_sel_slot_texlist_current = NULL;
    }
}
struct ByteBlock_14 { saddr v[5]; };

void TLobby__sub_802C7920(void) {
    TLobby::update_menu_cursor();
    ByteBlock_14 a = *(const ByteBlock_14 *)chr_sel_slot_resource_name_table;
    ByteBlock_14 b = *(const ByteBlock_14 *)chr_sel_slot_texlist_table;
    NJS_TEXLIST *list = (NJS_TEXLIST *)b.v[current_language];
    chr_sel_slot_texlist_current = list;
    load_streamed_prs_texture((const char *)a.v[current_language], list);
}
