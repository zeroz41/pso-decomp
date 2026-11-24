#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/network/NetworkWaitIcon.h"
#include "pso/ui/chat/SymbolChatPayload.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/math/AngleLookup.h"

s32 network_wait_icon_frame;

#pragma push
#pragma fp_contract on
void draw_wait_icon_quad(f32 *pos, f32 *scale, s32 angle, s32 uv_angle) {
    f32 q[18];
    f32 s;
    f32 c;
    f32 s2;
    f32 c2;
    s = 128.0f * sin_table_lookup(angle);
    c = 128.0f * cos_table_lookup(angle);
    q[0] = (pos[0] - 0.5f * (c * scale[0])) + 0.5f * (s * scale[1]);
    q[1] = (pos[1] - 0.5f * (s * scale[0])) - 0.5f * (c * scale[1]);
    q[3] = c * scale[0];
    q[4] = s * scale[0];
    q[5] = -s * scale[1];
    q[6] = c * scale[1];
    q[2] = 0.5f;
    s2 = 128.0f * sin_table_lookup(uv_angle);
    c2 = 128.0f * cos_table_lookup(uv_angle);
    q[8] = (0.5f * s2 + (156.0f - 0.5f * c2)) / 256.0f;
    q[9] = ((156.0f - 0.5f * s2) - 0.5f * c2) / 256.0f;
    q[10] = c2 / 256.0f;
    q[11] = s2 / 256.0f;
    q[12] = -s2 / 256.0f;
    q[13] = c2 / 256.0f;
    DVDConvertEntrynumToPath(q);
}
#pragma pop

void draw_network_wait_icon(void) {
    f32 pos[2];
    f32 scale[2];
    s32 uv_angle;
    uv_angle = (-network_wait_icon_frame << 16) / 30;
    set_additive_blend();
    TParticleCtrl::begin_effect_render();
    TCameraCtrl::restore_full_screen_view();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(5, -1);
    pos[0] = (545.0f);
    pos[1] = (3.9e+02f);
    scale[1] = scale[0] = 1.0f;
    draw_wait_icon_quad(pos, scale, 0, uv_angle);
    scale[0] = 1.0f;
    scale[1] = (0.5f);
    draw_wait_icon_quad(pos, scale, 0, uv_angle);
    scale[0] = 1.0f;
    scale[1] = (0.5f);
    draw_wait_icon_quad(pos, scale, 0x2000, uv_angle);
    scale[0] = 1.0f;
    scale[1] = (0.5f);
    draw_wait_icon_quad(pos, scale, -0x2000, uv_angle);
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}

void advance_network_wait_icon(void) {
    s32 frame;

    frame = network_wait_icon_frame + 1;
    network_wait_icon_frame = frame;
    if (frame >= 0x1E) {
        network_wait_icon_frame = frame - 0x1E;
    }
}

void SymbolChatPayload::clear() {
    s32 i;
    appearance = 0;
    for (i = 0; i < 4; i++) {
        facial_parts[i] = 0xFF;
    }
    for (i = 0; i < 12; i++) {
        parts[i].id = -1;
        parts[i].x = 0;
        parts[i].y = 0;
        parts[i].flags = 0;
    }
}
