#include "pso/TFontSmallHelp.h"
#include "pso/misc/TWindowSubStatusDisp_800FBD74.h"
#include "types.h"
#include <string.h>
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
extern s32 localized_alphabet_list;
extern const f32 lbl_805DA9C0;
extern const f32 lbl_805DA9C4;
extern const f32 lbl_805DA9C8;
extern const f32 lbl_805DA9CC;
extern const f32 lbl_805DA9D0;
extern const f32 lbl_805DA9D4;
extern const f32 lbl_805DA9D8;
extern const f32 lbl_805DA9DC;
extern const Vec lbl_8043DA90;
extern u8 identity_matrix[];
extern TCameraCtrl *camera_ctrl_instance;
void push_matrix_from(void *src);
void rotate_matrix_y(void *m, s32 angle);
void rotate_matrix_x(void *m, s32 angle);
void rotate_matrix_z(void *m, s32 angle);
void rotate_vector_by_matrix(void *m, Vec *src, Vec *dst);
void pop_matrix(void);
f32 vec3_dot(const Vec *a, const Vec *b);
void push_matrix(void);
void project_world_to_screen(void *m, Vec *pos, f32 *screen);
s32 is_split_screen(void);
s32 get_screen_height__11TCameraCtrlFv(void);
s32 get_screen_width__11TCameraCtrlFv(void);
}

void TWindowSubStatusDisp::render_forward(void *context) {
    begin_render((s32)context);
}

void TWindowSubStatusDisp::begin_render(s32) {
    TObjFish::set_global_param(localized_alphabet_list);
}

void TFontSmallHelp::set_color(u32 text_color) {
    color = text_color & 0xFFFFFF;
}
void TFontSmallHelp::set_help_text(const char *text_source) {
    if (text_source == NULL) {
        text[0] = 0;
        text_width = (f32) lbl_805DA9C0;
        return;
    }
    strncpy(text, text_source, sizeof(text) - 1);
    text[31] = 0;
    text_width = (f32) calc_small_font_text_width(text);
}

#pragma push
#pragma fp_contract on
void TFontSmallHelp::render() {
    TObjPlayer *player;
    f32 fade;
    u32 rgba;

    player = get_player_by_client_id(player_id);
    if (player != NULL && ((TObjPlayer *)player)->is_body_collision_inactive() != 0) {
        return;
    }
    Vec forward = lbl_8043DA90;
    Vec diff;
    Vec pos;
    f32 screen[2];
    VecCopy(&pos, &position);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(NULL, camera_ctrl_instance->m_194);
    rotate_matrix_x(NULL, camera_ctrl_instance->m_190);
    rotate_matrix_z(NULL, camera_ctrl_instance->m_198);
    rotate_vector_by_matrix(NULL, &forward, &forward);
    pop_matrix();
    diff.x = pos.x - camera_ctrl_instance->m_178;
    diff.y = pos.y - camera_ctrl_instance->m_17c;
    diff.z = pos.z - camera_ctrl_instance->m_180;
    {
        f32 xx = diff.x * diff.x;
        f32 yy = diff.y * diff.y;
        f32 zz = diff.z * diff.z;
        if (zz + (xx + yy) > lbl_805DA9C4) {
            return;
        }
    }
    if (vec3_dot(&forward, &diff) <= lbl_805DA9C0) {
        return;
    }
    push_matrix();
    project_world_to_screen(NULL, &pos, screen);
    pop_matrix();
    if (is_split_screen() != 0) {
        screen[0] -= (f32)get_screen_height__11TCameraCtrlFv();
        screen[0] /= TCameraCtrl::get_view_scale();
        screen[1] -= (f32)get_screen_width__11TCameraCtrlFv();
        screen[1] /= TCameraCtrl::get_fov();
    }
    screen[0] -= lbl_805DA9C8 * text_width;
    fade = (f32)age_ticks;
    if (lifetime_ticks > 0 && fade > (f32)(lifetime_ticks - 6)) {
        fade = (f32)(lifetime_ticks - age_ticks);
    }
    if (fade < lbl_805DA9CC) {
        rgba = (u32)(lbl_805DA9D0 * (lbl_805DA9D4 * fade));
        rgba <<= 24;
    } else {
        rgba = 0xFF000000;
    }
    rgba |= color;
    TCameraCtrl::get_camera_no();
    f32 sum = lbl_805DA9DC + TWindowCtrlMain::get_scale();
    f32 size = lbl_805DA9D8;
    size /= sum;
    draw_small_font_text((void *)rgba, text, screen[0], screen[1], size);
}
#pragma pop
