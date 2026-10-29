#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/render_util.h"
#include "pso/TEndingAB.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TEndingPicStage.h"

extern "C" {
void restore_saved_depth_alpha_state(void);
extern s32 TEndingAB__fade_sequence_state;
extern const f32 lbl_805D9580;
extern s32 game_difficulty_selection;
extern s32 ending_ab_wall_texture_list;
void TEndingAB::advance_fade_sequence() {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 temp_r4_2;

    switch ((s32) TEndingAB__fade_sequence_state) {
    case 1:
        temp_r3 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3;
        temp_r4 = *(s32 *)((s8 *)this + 0xEC);
        if (temp_r3 > (s32) ((temp_r4 * 3) - temp_r4)) {
            TEndingAB__fade_sequence_state = 2;
            TEndingPicStage::set_picture(*(s32 *)((s8 *)this + 0x24));
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
            return;
        }
        break;
    case 2:
        temp_r3_2 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_2;
        if (temp_r3_2 > (s32) (*(s32 *)((s8 *)this + 0xEC) * 0xD)) {
            TEndingAB__fade_sequence_state = 3;
            return;
        }
        break;
    case 3:
        temp_r3_3 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_3;
        temp_r4_2 = *(s32 *)((s8 *)this + 0xEC);
        if (temp_r3_3 > (s32) ((temp_r4_2 * 0xE) - temp_r4_2)) {
            TEndingAB__fade_sequence_state = 4;
            TEndingPicStage::set_picture(*(s32 *)((s8 *)this + 0x24));
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
            return;
        }
        break;
    case 4:
        temp_r3_4 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_4;
        if (temp_r3_4 > (s32) (*(s32 *)((s8 *)this + 0xEC) * 0x18)) {
            *(s32 *)((s8 *)this + 0x1C) = 0;
            TEndingAB__fade_sequence_state = 1;
            temp_r0 = *(s32 *)((s8 *)this + 0x28) + 1;
            *(s32 *)((s8 *)this + 0x28) = temp_r0;
            if (temp_r0 > 5) {
                *(s32 *)((s8 *)this + 0x28) = 5;
                TEndingAB__fade_sequence_state = 5;
                return;
            }
        }
        break;
    case 5:
        *(s32 *)((s8 *)this + 0x28) = 5;
        break;
    }
}
#pragma push
#pragma fp_contract on
void TEndingAB::draw_overlay() {
    u8 *arg0 = (u8 *)this;
    switch ((s32) TEndingAB__fade_sequence_state) {
    case 1:
    case 3:
        break;
    case 2:
        begin_screen_draw(1);
        set_draw_texture_and_color((*(s32 *)((s8 *)arg0 + 0x28) * 2) + 2, -1);
        TWindowSubStatusDisp::get_player();
        set_depth_buffer_settings_2();
        begin_screen_draw(1);
        set_draw_texture_and_color(0, -1);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x2C), lbl_805D9580);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x4C), lbl_805D9580);
        TWindowSubStatusDisp::get_player();
        restore_saved_depth_alpha_state();
        break;
    case 4:
    case 5:
        begin_screen_draw(1);
        set_draw_texture_and_color((*(s32 *)((s8 *)arg0 + 0x28) * 2) + 3, -1);
        TWindowSubStatusDisp::get_player();
        set_depth_buffer_settings_2();
        begin_screen_draw(1);
        set_draw_texture_and_color(1, -1);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x6C), lbl_805D9580);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x8C), lbl_805D9580);
        TWindowSubStatusDisp::get_player();
        restore_saved_depth_alpha_state();
        break;
    }
}
#pragma pop

void TEndingAB::set_fish_global_param() {
    switch (game_difficulty_selection) {
    case 0:
    case 1:
        TObjFish::set_global_param(ending_ab_wall_texture_list);
        break;
    case 2:
        TObjFish::set_global_param(ending_ab_wall_texture_list);
        break;
    case 3:
        TObjFish::set_global_param(ending_ab_wall_texture_list);
        break;
    }
}

}
