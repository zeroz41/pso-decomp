#include "pso/system/scene/EndingWallTextures.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "types.h"

#include "pso/system/scene/TEndingC.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/NinjaTypes.h"

extern "C" {
int TKeyBoardControl__sub_8000F828(void);
extern "C" {
__declspec(section ".rodata") extern const char lbl_804398E0[] = "ed_128al";
__declspec(section ".rodata") extern const char lbl_804398EC[] = "ed_512kabe_C";
__declspec(section ".rodata") extern const char TEndingC__class_name_string[] = "TEndingC";
}
NJS_TEXNAME lbl_8048EB18[2] = { {(void *)lbl_804398E0, 0, 0}, {(void *)lbl_804398EC, 0, 0} };
__declspec(section ".data") NJS_TEXLIST TEndingC__wall_texture_list_entry = { lbl_8048EB18, 2 };
const char *lbl_805D2960 = TEndingC__class_name_string;
int TEndingC__sub_8008C6F4(void);
void TEndingAB__sub_8008D5A0(void);
void TEndingPic__sub_8008D5AC(void);
int TEnding__sub_8008D5B8(void);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void begin_screen_draw(s32 mode);
s32 set_draw_texture_and_color(s32, s32, f32);


}

// Built with -inline off,deferred: functions are written last to first.

extern "C" {
void release_texture_list(void*);
int bind_gvm_texture_list(const char *, NJS_TEXLIST *);
extern int TEndingPic__animation_state;
extern int ending_frame_counter;
}

uaddr TEndingC__wall_texture_list;

s32 TObjEneBalClaw::update_action_hold_status() {
    saddr arg0 = (saddr)this;
    if (TObjChara::update_action_hold_status() != 0) {
        ((TObjEneBalClaw *)arg0)->clear_flag_in_state7();
        return 1;
    }
    return 0;
}

s32 TObjEneBalClaw::update_movement_status() {
    saddr arg0 = (saddr)this;
    if (TObjChara::update_movement_status() != 0) {
        ((TObjEneBalClaw *)arg0)->clear_flag_in_state7();
        return 1;
    }
    return 0;
}

void TObjEneBalClaw::clear_flag_in_state7() {
    u8 *arg0 = (u8 *)this;
    if (this->next_action == 7) {
        this->behavior_flags = (s32) (this->behavior_flags & 0xFFFFFFFE);
        ((TObjEnemyCustom *)arg0)->update_if_active(0);
    }
}

extern "C" {
int TEnding__sub_8008D5B8(void) {  return ending_frame_counter; }

void TEndingPic__sub_8008D5AC(void) { TEndingPic__animation_state = 1; }

void TEndingAB__sub_8008D5A0(void) { TEndingAB__fade_sequence_state = 1; }
}

void register_texture_ed_512kabe_c(void) { TEndingC__wall_texture_list = (saddr)&TEndingC__wall_texture_list_entry; bind_gvm_texture_list(lbl_804398EC, &TEndingC__wall_texture_list_entry); }

void TEndingC::release_lobby() {
    if ((u32) TEndingC__wall_texture_list != 0U) {
        release_texture_list((void*)TEndingC__wall_texture_list);
        TEndingC__wall_texture_list = 0U;
    }
}

TEndingC::TEndingC(TObject *parent) : TObject(parent) {
    m_name = lbl_805D2960;
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
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    s32 temp_r0_2;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r3_5;
    switch (phase) {
    case 0:
        if (((u32 (*)())TEnding__sub_8008D5B8)() > (timing_rate * TEndingC__sub_8008C6F4())) {
            phase = 1U;
            break;
        }
    default:
        break;
    case 1:
        temp_f1 = primary_opacity;
        temp_f3 = 1.0f / fade_in_ticks;
        if (temp_f1 < (1.0f - temp_f3)) {
            primary_opacity = (f32) (temp_f1 + temp_f3);
            secondary_opacity = (f32) (4.0f * primary_opacity);
            if (secondary_opacity > 1.0f) {
                secondary_opacity = 1.0f;
                break;
            }
        } else {
            primary_opacity = 1.0f;
            secondary_opacity = 1.0f;
            TEndingPic__sub_8008D5AC();
            TEndingAB__sub_8008D5A0();
            phase = 2U;
            break;
        }
        break;
    case 2:
        temp_r3 = elapsed_ticks + 1;
        elapsed_ticks = temp_r3;
        if (temp_r3 > (s32) (timing_rate * 3)) {
            phase = 3U;
            break;
        }
        break;
    case 3:
        temp_f2 = primary_opacity;
        temp_f0 = 1.0f / fade_out_ticks;
        if (temp_f2 > temp_f0) {
            primary_opacity = (f32) (temp_f2 - temp_f0);
        } else {
            primary_opacity = 0.0f;
        }
        temp_r3_2 = elapsed_ticks + 1;
        elapsed_ticks = temp_r3_2;
        if (temp_r3_2 > (s32) (timing_rate * 0xB)) {
            phase = 4U;
            break;
        }
        break;
    case 4:
        temp_f2_2 = primary_opacity;
        temp_f3_2 = 1.0f / fade_in_ticks;
        if (temp_f2_2 < (1.0f - temp_f3_2)) {
            primary_opacity = (f32) (temp_f2_2 + temp_f3_2);
        } else {
            primary_opacity = 1.0f;
        }
        temp_r3_3 = elapsed_ticks + 1;
        elapsed_ticks = temp_r3_3;
        if (temp_r3_3 > (s32) (timing_rate * 0xE)) {
            phase = 5U;
            break;
        }
        break;
    case 5:
        temp_f2_3 = primary_opacity;
        temp_f0_2 = 1.0f / fade_out_ticks;
        if (temp_f2_3 > temp_f0_2) {
            primary_opacity = (f32) (temp_f2_3 - temp_f0_2);
        } else {
            primary_opacity = 0.0f;
        }
        temp_r3_4 = elapsed_ticks + 1;
        elapsed_ticks = temp_r3_4;
        if (temp_r3_4 > (s32) (timing_rate * 0x16)) {
            phase = 6U;
            temp_r0_2 = cycle_index + 1;
            cycle_index = temp_r0_2;
            if (temp_r0_2 > 5) {
                primary_opacity = 0.0f;
                cycle_index = 5;
                phase = 7U;
                break;
            }
        }
        break;
    case 6:
        temp_f2_4 = primary_opacity;
        temp_f3_3 = 1.0f / fade_in_ticks;
        if (temp_f2_4 < (1.0f - temp_f3_3)) {
            primary_opacity = (f32) (temp_f2_4 + temp_f3_3);
        } else {
            primary_opacity = 1.0f;
        }
        temp_r3_5 = elapsed_ticks + 1;
        elapsed_ticks = temp_r3_5;
        if (temp_r3_5 > (s32) (timing_rate * 0x18)) {
            elapsed_ticks = 0;
            primary_opacity = 1.0f;
            phase = 2U;
            break;
        }
        break;
    case 8:
        temp_f2_5 = primary_opacity;
        temp_f0_3 = 1.0f / fade_out_ticks;
        if (temp_f2_5 > temp_f0_3) {
            primary_opacity = (f32) (temp_f2_5 - temp_f0_3);
            break;
        }
        primary_opacity = 0.0f;
        break;
    }
}

void TEndingC::render() {
    TObjFish::set_global_param(reinterpret_cast<GinjaTextureList *>(&TEndingC__wall_texture_list_entry));
    begin_screen_draw(1);
    set_draw_texture_and_color(1, ((s32) (255.0f * primary_opacity) << 0x18) | 0xFF0000 | 0xFFFF, 255.0f);
    draw_textured_quad_at_depth(render_geometry[0], 0.98f);
    draw_textured_quad_at_depth(render_geometry[1], 0.98f);
    set_draw_texture_and_color(0, ((s32) (255.0f * secondary_opacity) << 0x18) | 0xFF0000 | 0xFFFF, 255.0f);
    draw_textured_quad_at_depth(render_geometry[2], 0.99f);
    TWindowSubStatusDisp::get_player();
}
