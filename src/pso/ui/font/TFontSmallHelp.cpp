#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/font/TFontSmallHelp.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "types.h"
#include <string.h>
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

const char *font_small_help_class_name = "TFontSmallHelp";

// The view axis the label must face to be drawn (render's dot test); the name is inferred.
static const Vec help_text_forward = {0.0f, 0.0f, -1.0f};

void TWindowSubStatusDisp::render_forward() {
    begin_render();
}

void TWindowSubStatusDisp::begin_render() {
    TObjFish::set_global_param(localized_alphabet_list);
}

void TFontSmallHelp::set_color(u32 text_color) {
    color = text_color & 0xFFFFFF;
}
void TFontSmallHelp::set_help_text(const char *text_source) {
    if (text_source == NULL) {
        text[0] = 0;
        text_width = 0.0f;
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
    uaddr rgba;

    player = get_player_by_client_id(player_id);
    if (player != NULL && ((TObjPlayer *)player)->is_body_collision_inactive() != 0) {
        return;
    }
    Vec forward = help_text_forward;
    Vec diff;
    Vec pos;
    f32 screen[2];
    VecCopy(&pos, &position);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(NULL, camera_ctrl_instance->yaw);
    rotate_matrix_x(NULL, camera_ctrl_instance->pitch);
    rotate_matrix_z(NULL, camera_ctrl_instance->roll);
    rotate_vector_by_matrix(NULL, &forward, &forward);
    pop_matrix();
    diff.x = pos.x - camera_ctrl_instance->pos.x;
    diff.y = pos.y - camera_ctrl_instance->pos.y;
    diff.z = pos.z - camera_ctrl_instance->pos.z;
    {
        f32 xx = diff.x * diff.x;
        f32 yy = diff.y * diff.y;
        f32 zz = diff.z * diff.z;
        if (zz + (xx + yy) > 122500.0f) {
            return;
        }
    }
    if (vec3_dot(&forward, &diff) <= 0.0f) {
        return;
    }
    push_matrix();
    project_world_to_screen(NULL, &pos, screen);
    pop_matrix();
    if (is_split_screen() != 0) {
        screen[0] -= (f32)TCameraCtrl::get_viewport_x();
        screen[0] /= TCameraCtrl::get_view_scale();
        screen[1] -= (f32)TCameraCtrl::get_viewport_y();
        screen[1] /= TCameraCtrl::get_fov();
    }
    screen[0] -= 0.5f * text_width;
    fade = (f32)age_ticks;
    if (lifetime_ticks > 0 && fade > (lifetime_ticks - 6)) {
        fade = (f32)(lifetime_ticks - age_ticks);
    }
    if (fade < 6.0f) {
        rgba = (u32)(0.16666667f * (255.0f * fade));
        rgba <<= 24;
    } else {
        rgba = 0xFF000000;
    }
    rgba |= color;
    TCameraCtrl::get_camera_no();
    f32 scale = TWindowCtrlMain::get_scale();
    f32 size = -1.0f;
    size /= 0.1495f + scale;
    draw_small_font_text((void *)rgba, text, screen[0], screen[1], size);
}
#pragma pop

void TFontSmallHelp::run_task() {
    HelpTextPlayerState *player = (HelpTextPlayerState *)get_player_by_client_id(player_id);
    if (player == NULL) {
        queue_destruction();
        return;
    }
    if (owner_identity != player->identity) {
        queue_destruction();
        return;
    }
    VecCopy(&position, &player->position);
    age_ticks += 1;
    s32 lifetime = lifetime_ticks;
    if (lifetime > 0 && age_ticks >= lifetime) {
        disallow_rendering();
        queue_destruction();
    }
}

TFontSmallHelp::~TFontSmallHelp() {}

TFontSmallHelp::TFontSmallHelp(u32 player, u32 text_color, s32 lifetime, uaddr text_id)
    : TObject((TObject *)TWindowCtrlMain::get_instance()) {
    m_name = font_small_help_class_name;
    HelpTextPlayerState *owner = (HelpTextPlayerState *)get_player_by_client_id(player);
    if (owner == NULL) {
        disallow_rendering();
        queue_destruction();
        return;
    }
    player_id = player;
    VecCopy(&position, &owner->position);
    owner_identity = owner->identity;
    set_color(text_color);
    age_ticks = 0;
    lifetime_ticks = lifetime;
    set_help_text((const char *)text_id);
}
