#include "pso/system/scene/EndingWallTextures.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "types.h"

#include "pso/system/scene/TEndingC.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/NinjaTypes.h"

#include "pso/system/scene/TEndingC_8008D00C.h"
#include "pso/system/scene/TEnding.h"
#include "pso/system/scene/TEndingPic.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/GinjaTexture.h"
#include "pso/player/TObjPlayer_8023E480.h"

__declspec(section ".rodata") extern char ending_c_texture_ed_128al[] = "ed_128al";
__declspec(section ".rodata") extern char ending_c_texture_ed_512kabe_c[] = "ed_512kabe_C";
__declspec(section ".rodata") extern const char ending_c_class_name_text[] = "TEndingC";
NJS_TEXNAME ending_c_wall_texnames[2] = { {ending_c_texture_ed_128al, 0, 0}, {ending_c_texture_ed_512kabe_c, 0, 0} };
__declspec(section ".data") NJS_TEXLIST ending_c_wall_texlist = { ending_c_wall_texnames, 2 };
const char *ending_c_class_name = ending_c_class_name_text;

// Built with -inline off,deferred: functions are written last to first.

NJS_TEXLIST *ending_c_wall_texture_list;

s32 TObjEneBalClaw::update_action_hold_status() {
    if (TObjChara::update_action_hold_status() != 0) {
        clear_flag_in_state7();
        return 1;
    }
    return 0;
}

s32 TObjEneBalClaw::update_movement_status() {
    if (TObjChara::update_movement_status() != 0) {
        clear_flag_in_state7();
        return 1;
    }
    return 0;
}

void TObjEneBalClaw::clear_flag_in_state7() {
    if (next_action == 7) {
        behavior_flags &= ~1;
        update_if_active(0);
    }
}

u32 get_ending_frame_counter(void) { return ending_frame_counter; }

void start_ending_pic_sequence(void) { TEndingPic__animation_state = 1; }

void start_ending_ab_fade(void) { TEndingAB__fade_sequence_state = 1; }

void register_texture_ed_512kabe_c(void) { ending_c_wall_texture_list = &ending_c_wall_texlist; bind_gvm_texture_list(ending_c_texture_ed_512kabe_c, &ending_c_wall_texlist); }

void TEndingC::release_lobby() {
    if (ending_c_wall_texture_list != NULL) {
        release_texture_list(ending_c_wall_texture_list);
        ending_c_wall_texture_list = NULL;
    }
}

TEndingC::TEndingC(TObject *parent) : TObject(parent) {
    m_name = ending_c_class_name;
    elapsed_ticks = 0;
    phase = 0;
    primary_opacity = 0.0f;
    secondary_opacity = 0.0f;
    cycle_index = 0;
    render_geometry[0][0] = 228.0f;
    render_geometry[0][1] = 0.0f;
    render_geometry[0][2] = 640.0f;
    render_geometry[0][3] = 480.0f;
    render_geometry[0][4] = 0.1953125f;
    render_geometry[0][5] = 0.0f;
    render_geometry[0][6] = 1.0f;
    render_geometry[0][7] = 0.9375f;
    render_geometry[1][0] = 0.0f;
    render_geometry[1][1] = 0.0f;
    render_geometry[1][2] = 100.0f;
    render_geometry[1][3] = 480.0f;
    render_geometry[1][4] = 0.0f;
    render_geometry[1][5] = 0.0f;
    render_geometry[1][6] = 0.1953125f;
    render_geometry[1][7] = 0.9375f;
    render_geometry[2][0] = 10.0f;
    render_geometry[2][1] = 0.0f;
    render_geometry[2][2] = 340.0f;
    render_geometry[2][3] = 480.0f;
    render_geometry[2][4] = 0.0f;
    render_geometry[2][5] = 0.0f;
    render_geometry[2][6] = 1.0f;
    render_geometry[2][7] = 1.0f;
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0:
        timing_rate = 30;
        break;
    case 1:
        timing_rate = 25;
        break;
    }
    fade_in_ticks = 2.0f * (f32)timing_rate;
    fade_out_ticks = 2.0f * (f32)timing_rate;
}

TEndingC::~TEndingC() {}

void TEndingC::run_task() {
    switch (phase) {
    case 0:
        if (get_ending_frame_counter() > (timing_rate * get_ending_c_start_seconds())) {
            phase = 1;
            break;
        }
    default:
        break;
    case 1:
        if (primary_opacity < 1.0f - 1.0f / fade_in_ticks) {
            primary_opacity += 1.0f / fade_in_ticks;
            secondary_opacity = 4.0f * primary_opacity;
            if (secondary_opacity > 1.0f) {
                secondary_opacity = 1.0f;
            }
        } else {
            primary_opacity = 1.0f;
            secondary_opacity = 1.0f;
            start_ending_pic_sequence();
            start_ending_ab_fade();
            phase = 2;
        }
        break;
    case 2:
        if (++elapsed_ticks > timing_rate * 3) {
            phase = 3;
        }
        break;
    case 3:
        if (primary_opacity > 1.0f / fade_out_ticks) {
            primary_opacity -= 1.0f / fade_out_ticks;
        } else {
            primary_opacity = 0.0f;
        }
        if (++elapsed_ticks > timing_rate * 11) {
            phase = 4;
        }
        break;
    case 4:
        if (primary_opacity < 1.0f - 1.0f / fade_in_ticks) {
            primary_opacity += 1.0f / fade_in_ticks;
        } else {
            primary_opacity = 1.0f;
        }
        if (++elapsed_ticks > timing_rate * 14) {
            phase = 5;
        }
        break;
    case 5:
        if (primary_opacity > 1.0f / fade_out_ticks) {
            primary_opacity -= 1.0f / fade_out_ticks;
        } else {
            primary_opacity = 0.0f;
        }
        if (++elapsed_ticks > timing_rate * 22) {
            phase = 6;
            if (++cycle_index > 5) {
                primary_opacity = 0.0f;
                cycle_index = 5;
                phase = 7;
            }
        }
        break;
    case 6:
        if (primary_opacity < 1.0f - 1.0f / fade_in_ticks) {
            primary_opacity += 1.0f / fade_in_ticks;
        } else {
            primary_opacity = 1.0f;
        }
        if (++elapsed_ticks > timing_rate * 24) {
            elapsed_ticks = 0;
            primary_opacity = 1.0f;
            phase = 2;
        }
        break;
    case 8:
        if (primary_opacity > 1.0f / fade_out_ticks) {
            primary_opacity -= 1.0f / fade_out_ticks;
        } else {
            primary_opacity = 0.0f;
        }
        break;
    }
}

void TEndingC::render() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(&ending_c_wall_texlist));
    begin_screen_draw(1);
    set_draw_texture_and_color(1, ((s32) (255.0f * primary_opacity) << 0x18) | 0xFF0000 | 0xFFFF);
    draw_textured_quad_at_depth(render_geometry[0], 0.98f);
    draw_textured_quad_at_depth(render_geometry[1], 0.98f);
    set_draw_texture_and_color(0, ((s32) (255.0f * secondary_opacity) << 0x18) | 0xFF0000 | 0xFFFF);
    draw_textured_quad_at_depth(render_geometry[2], 0.99f);
    TWindowSubStatusDisp::get_player();
}
