#include "pso/system/SoundEffect.h"
#include "pso/ui/frontend/TAdMultiOkGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/system/ControllerInput.h"
extern "C" {
void release_texture_list(void *);
const char multi_confirm_texture_archive_name[] = "f064_multiconfirm";
void *multi_confirm_texture_entries[3] = { (void *)multi_confirm_texture_archive_name, 0, 0 };
struct MultiConfirmTextureList { void *entries; u32 count; };
__declspec(section ".data") MultiConfirmTextureList multi_confirm_texture_descriptor = { multi_confirm_texture_entries, 1 };
}
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
extern "C" {
saddr multi_confirm_texture_list;
}

const char *TAdMultiOkGC__name = "TAdMultiOkGC";
// The unit was built with -inline off,deferred: the functions are written
// last-to-first, which gives the original address order.
void load_multi_confirm_textures(void) { multi_confirm_texture_list = (saddr)&multi_confirm_texture_descriptor; load_streamed_prs_texture((saddr)multi_confirm_texture_archive_name, (saddr)&multi_confirm_texture_descriptor); }

void free_multi_confirm_textures(void) {
    if ((u32) multi_confirm_texture_list != 0U) {
        release_texture_list((void*)multi_confirm_texture_list);
        multi_confirm_texture_list = 0U;
    }
}

#pragma push
#pragma fp_contract on

TAdMultiOkGC::TAdMultiOkGC(TObject *parent, TAdMultiOkSetup *setup) : TObject(parent) {
    TAdMultiOkRow rows[11] = { 136.0f, 332.0f, 304.0f, 85.0f, 332.0f, 203.0f, 60.0f, 332.0f, 152.0f };
    u32 colors[12] = { 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF };
    s32 n;
    s32 i;
    s32 k;
    m_name = TAdMultiOkGC__name;
    m_count = setup->count;
    m_flags = 0;
    if (m_count < 2) {
        m_count = 2;
    } else if (m_count > 12) {
        m_count = 12;
    }
    n = 0;
    for (i = 0; i < 12; i++) {
        if (setup->mask & (1 << i)) {
            m_players[n++] = i;
            if (n >= m_count) {
                break;
            }
        }
    }
    if (n < m_count) {
        m_count = n;
    }
    for (i = 0; i < m_count; i++) {
        f32 y = rows[m_count - 2].y;
        f32 x = rows[m_count - 2].x + (f32)i * rows[m_count - 2].step;
        u32 a = ((colors[m_players[i]] >> 24) / 5) << 24;
        m_entries[i].flags = 0;
        m_entries[i].frame = -1;
        m_entries[i].x = 32.0f + x;
        m_entries[i].y = 16.0f + y;
        f32 x1;
        f32 y1;
        y1 = 32.0f + y;
        x1 = 64.0f + x;
        for (k = 0; k < 5; k++) {
            m_entries[i].colors[k] = a | (colors[m_players[i]] & 0xFFFFFF);
            m_entries[i].quads[k].x0 = x;
            m_entries[i].quads[k].y0 = y;
            m_entries[i].quads[k].x1 = x1;
            m_entries[i].quads[k].y1 = y1;
            m_entries[i].quads[k].u0 = 0.0f;
            m_entries[i].quads[k].v0 = 0.0f;
            m_entries[i].quads[k].u1 = 1.0f;
            m_entries[i].quads[k].v1 = 0.5f;
        }
    }
}
#pragma pop

TAdMultiOkGC::~TAdMultiOkGC() {}

void TAdMultiOkGC::run_task() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        handle_player_buttons(i);
        update_entry_animation(i);
    }
}

void TAdMultiOkGC::handle_player_buttons(int i) {
    s32 ports[4] = { 0, 1, 2, 3 };
    if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[ports[m_players[i]]], 4) != 0) {
        if (m_entries[i].flags & 4) {
            m_entries[i].frame = -1;
            m_entries[i].flags &= ~1;
            m_entries[i].flags &= ~4;
            play_sound_effect(0x52F16, 0, 0, 0);
        } else if (!(m_entries[i].flags & 2)) {
            m_entries[i].frame = -1;
            m_entries[i].flags |= 1;
            m_entries[i].flags |= 2;
            play_sound_effect(0x52D01, 0, 0, 0);
        }
    } else if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[ports[m_players[i]]], 2) != 0) {
        if (!(m_entries[i].flags & 2)) {
            m_flags |= 1;
            play_sound_effect(0x52F16, 0, 0, 0);
        }
    }
}

#pragma push
#pragma fp_contract on
void TAdMultiOkGC::update_entry_animation(int index) {
    s32 i;
    s32 d;
    f32 f;
    if (m_entries[index].flags & 2) {
        m_entries[index].frame++;
        for (i = 0; i < 5; i++) {
            d = m_entries[index].frame - (i - 1);
            if (m_entries[index].flags & 1) {
                if (d > 10) {
                    m_entries[index].flags |= 4;
                } else if (d >= 0) {
                    f = 3.0f - 0.2f * (f32)d;
                    m_entries[index].quads[i].x0 = -32.0f * f + m_entries[index].x;
                    m_entries[index].quads[i].y0 = -16.0f * f + m_entries[index].y;
                    m_entries[index].quads[i].x1 = 32.0f * f + m_entries[index].x;
                    m_entries[index].quads[i].y1 = 16.0f * f + m_entries[index].y;
                }
            } else if (d > 5) {
                m_entries[index].flags &= ~2;
            } else if (d >= 0) {
                f = 1.0f - 0.2f * (f32)d;
                m_entries[index].quads[i].x0 = -32.0f * f + m_entries[index].x;
                m_entries[index].quads[i].y0 = -16.0f * f + m_entries[index].y;
                m_entries[index].quads[i].x1 = 32.0f * f + m_entries[index].x;
                m_entries[index].quads[i].y1 = 16.0f * f + m_entries[index].y;
            }
        }
    }
}
#pragma pop

void TAdMultiOkGC::render() {
    s32 i;
    if (TMainTask::get_render_pass() != 1) {
        set_additive_blend();
        for (i = 0; i < m_count; i++) {
            draw_entry(i);
        }
        set_default_alpha_blend();
    }
}

#pragma push
#pragma fp_contract on
void TAdMultiOkGC::draw_entry(int index) {
    s32 i;
    f32 base;
    if (m_entries[index].flags & 2) {
        begin_screen_draw(1);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(multi_confirm_texture_list));
        base = 0.0050000004f * (f32)index;
        for (i = 0; i < 5; i++) {
            set_draw_texture_and_color(0, m_entries[index].colors[i]);
            if (m_entries[index].frame - (i - 1) >= 0) {
                f32 depth = 0.001f * (f32)i + 0.01f;
                draw_textured_quad_at_depth(&m_entries[index].quads[i].x0, depth + base);
            }
        }
        TWindowSubStatusDisp::get_player();
    }
}
#pragma pop

s32 TAdMultiOkGC::are_all_entries_finished() {
    s32 i;
    for (i = 0; i < m_count; i++) {
        if (!(m_entries[i].flags & 4)) return 0;
    }
    return 1;
}

int TAdMultiOkGC::multi_confirm_cancel_requested() { return m_flags & 1; }
