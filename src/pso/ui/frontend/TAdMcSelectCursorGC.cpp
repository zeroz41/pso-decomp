#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC_8032A610.h"
#include "pso/render/render_util.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

extern "C" {
GinjaTextureEntry lbl_804ED990 = { "f256_memorycard_select", 0, NULL };
__declspec(section ".data") GinjaTextureList mc_select_cursor_texture_list = { &lbl_804ED990, 1 };
}

extern "C" {
const char *TAdMcSelectCursorGC__class_name = "TAdMcSelectCursorGC";
void restore_saved_depth_alpha_state(void);

GinjaTextureList *TAdMcSelectCursorGC__texture_entry;

void TAdMcSelectCursorGC::render_cursor() {
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(TAdMcSelectCursorGC__texture_entry));
    set_draw_texture_and_color(0, ((this->m_128 << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth(&quads[0].x0, 0.9f);
    TWindowSubStatusDisp::get_player();
}

void TAdMcSelectCursorGC::render() {
    if ((s32) this->m_13c == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
        goto block_5;
    }
    if ((s32)this->defer_render() == 0) {
        set_depth_buffer_settings_2();
block_5:
        set_additive_blend();
        render_cursor();
        set_default_alpha_blend();
        if ((s32) this->m_13c == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

TAdMcSelectCursorGC *TAdMcSelectCursorGC__instance;

#pragma fp_contract on
void TAdMcSelectCursorGC::run_task() {
    TAdMcCheckGC *t2;
    TAdMcCheckGC *t;
    TAdMcCheckGC *t1;
    s32 i;
    if (m_1c == 0) {
        t = TAdMcSelectCursorGC::get_cursor_type(1 - m_20);
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command(reinterpret_cast<s32>(&controller_physical_port_bank.controllers[0]), 0x80, 6, 1) != 0 ||
            test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0) {
            if (TAdMcSelectCursorGC__sub_8032A6D8(t) >= 4) {
                m_20++;
                if (m_20 > 1) {
                    m_20 = 1;
                }
            }
        } else if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(reinterpret_cast<s32>(&controller_physical_port_bank.controllers[0]), 0x40, 6, 1) != 0 ||
                    test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0) &&
                   TAdMcSelectCursorGC__sub_8032A6D8(t) >= 4) {
            m_20--;
            if (m_20 < 0) {
                m_20 = 0;
            }
        }
    }
    t1 = TAdMcSelectCursorGC::get_cursor_type(m_20);
    t2 = TAdMcSelectCursorGC::get_cursor_type(1 - m_20);
    if (t1 != 0 && TAdMcSelectCursorGC__sub_8032A6D8(t1) == 0) {
        if (t2 != 0 && TAdMcSelectCursorGC__sub_8032A6D8(t2) == 0) {
            m_128 = 0;
        } else {
            m_20 = 1 - m_20;
        }
    } else {
        m_128 += 0x19;
        m_128 = m_128 > 0xFF ? 0xFF : m_128;
    }
    for (i = 0; i < 8; i++) {
        quads[i].x0 = 286.0f * m_20 + 51.0f;
        quads[i].y0 = 116.0f;
        quads[i].x1 = 256.0f + quads[i].x0;
        quads[i].y1 = 372.0f;
    }
    if (m_20 != m_24) {
        play_sound_effect(0x54100, 0, 0, 0);
        m_128 = 0;
    }
    m_24 = m_20;
}

}
TAdMcSelectCursorGC::~TAdMcSelectCursorGC() {
    if (TAdMcSelectCursorGC__instance != NULL) {
        TAdMcSelectCursorGC__instance = NULL;
    }
}

TAdMcSelectCursorGC::TAdMcSelectCursorGC(TObject *parent) : TObject(parent) {
    m_name = TAdMcSelectCursorGC__class_name;
    m_138 = 0;
    m_12c = 0;
    m_134 = 0;
    m_128 = 0;
    m_13c = 1;
    m_1c = 0;
    m_20 = 0;
    m_24 = m_20;
    for (s32 i = 0; i < 8; i++) {
        quads[i].u0 = 0.0f;
        quads[i].v0 = 0.0f;
        quads[i].u1 = 1.0f;
        quads[i].v1 = 1.0f;
    }
}

extern "C" {
s32 release_texture_list(GinjaTextureList *, GinjaTextureEntry *);

TAdMcSelectCursorGC *TAdMcSelectCursorGC::get_instance(TObject *parent) {
    if (TAdMcSelectCursorGC__instance == NULL) {
        TAdMcSelectCursorGC__instance = new TAdMcSelectCursorGC(parent);
    }
    return TAdMcSelectCursorGC__instance;
}

void TAdMcSelectCursorGC::release_cursor_entry() {
    if (TAdMcSelectCursorGC__texture_entry != NULL) {
        GinjaTextureEntry *entry = TAdMcSelectCursorGC__texture_entry->entries;
        if (entry->texture != NULL) {
            release_texture_list(TAdMcSelectCursorGC__texture_entry, entry);
        }
    }
}

void TAdMcSelectCursorGC::init_resource() { TAdMcSelectCursorGC__texture_entry = &mc_select_cursor_texture_list; load_streamed_prs_texture((s32)"f256_memorycard_select", (s32)&mc_select_cursor_texture_list); }

s32 TAdMcSelectCursorGC__sub_8032A6D8(TAdMcCheckGC *card) { return card->m_1c; }

TAdMcCheckGC *TAdMcSelectCursorGC::get_cursor_type(int slot) { return memcard_cursor_instance_table[slot]; }

}
