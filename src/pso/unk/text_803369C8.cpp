#include "types.h"
#include "pso/unk/text_803369C8.h"
#include "pso/unk/TUnk_804EEF80.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby_80335E08.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80141A30.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct TitlePulseQuad {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

struct TitleQuad {
    f32 x, y, z;
    f32 bx, by, cx, cy;
    u8 pad_1C[0x4];
    f32 u, v, uw, ux, vx, vh;
    u8 pad_38[0x8];
};

extern "C" {
f32 sin_table_lookup(void *);
f32 cos_table_lookup(void *);
void draw_title_background_layer(void *,s32,s32,f32);
void render_logo_with_default(void *,s32,s32,f32);
extern int lobby_global_flags;

void TCameraCtrl__sub_80068EF0(void);
}

static const f32 ring_offsets[3][2] = {{-137.0f, -79.0f}, {137.0f, -79.0f}, {0.0f, 156.0f}};
static const f32 ring_center[2] = {320.0f, 220.0f};

#pragma push
#pragma fp_contract on
void draw_title_background_pulse(s32 owner, f32 depth, s32 frame) {
    TitlePulseQuad q;
    f32 t;
    u8 c;
    s32 n;
    n = frame % 300;
    if (n >= 150 && n <= 170) {
        t = (n - 150) / 20.0f;
        set_additive_blend();
        begin_screen_draw(1);
        bind_title_texture_list();
        c = (s32)(255.0f * (1.0f + -1.0f * t));
        set_draw_texture_and_color(0xC, 0xFF000000 | (c << 16) | (c << 8) | c);
        q.x0 = 320.0f - 0.5f * (128.0f * (4.2f * t));
        q.y0 = 200.0f - 0.5f * (128.0f * (4.2f * t));
        q.x1 = 320.0f + 0.5f * (128.0f * (4.2f * t));
        q.y1 = 200.0f + 0.5f * (128.0f * (4.2f * t));
        q.u0 = 0.57421875f;
        q.v0 = 0.0f;
        q.u1 = 0.82421875f;
        q.v1 = 0.25f;
        draw_textured_quad_at_depth((f32 *)&q, -1.0f / depth);
        TWindowSubStatusDisp::get_player();
        set_default_alpha_blend();
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void rotate_title_background_quad(s32 owner, u8 *quad, u8 *center, s32 angle, f32 radius) {
    TitleQuad *q = (TitleQuad *)quad;
    const f32 *c = (const f32 *)center;
    f32 sin_r;
    f32 cos_r;
    sin_r = radius * sin_table_lookup((void *)angle);
    cos_r = radius * cos_table_lookup((void *)angle);
    q->x = (0.5f * (sin_r - cos_r)) + c[0];
    q->y = -((0.5f * (sin_r + cos_r)) - c[1]);
    q->bx = cos_r;
    q->by = sin_r;
    q->cx = -sin_r;
    q->cy = cos_r;
}
#pragma pop

#pragma push
#pragma fp_contract on
void draw_title_rings(s32 owner, f32 depth, s32 frame) {
    TitleQuad q;
    f32 pos[2];
    s32 angle;
    s32 i;
    u32 color;

    if (lobby_global_flags & 2) {
        angle = (s32)((frame << 16) / 450.0f);
    } else {
        angle = (u32)(frame << 16) / 900;
    }
    if (lobby_global_flags & 1) {
        angle = -angle;
    }
    color = calc_pulse_flash_color(0, 0x58, 0x73, frame, 300, 150, 165, 180);
    q.ux = 0.0f;
    q.vx = 0.0f;
    set_additive_blend();
    begin_screen_draw(1);
    bind_title_texture_list();
    set_draw_texture_and_color(11, color);
    q.u = 0.0f;
    q.v = 0.0f;
    q.uw = 0.83984375f;
    q.vh = 0.83984375f;
    q.z = -1.0f / depth;
    rotate_title_background_quad(owner, (u8 *)&q, (u8 *)ring_center, -angle, 430.0f);
    DVDConvertEntrynumToPath((f32 *)&q);
    set_draw_texture_and_color(12, color);
    q.u = 0.0f;
    q.v = 0.0f;
    q.uw = 0.34765625f;
    q.vh = 0.34765625f;
    q.z = -1.0f / (1.0f + depth);
    rotate_title_background_quad(owner, (u8 *)&q, (u8 *)ring_center, angle, 178.0f);
    DVDConvertEntrynumToPath((f32 *)&q);
    q.u = 0.349609375f;
    q.v = 0.0f;
    q.uw = 0.203125f;
    q.vh = 0.203125f;
    for (i = 0; i < 3; i++) {
        pos[0] = ring_center[0] - ring_offsets[i][0] * cos_table_lookup((void *)angle) + ring_offsets[i][1] * sin_table_lookup((void *)angle);
        pos[1] = ring_center[1] + ring_offsets[i][0] * sin_table_lookup((void *)angle) + ring_offsets[i][1] * cos_table_lookup((void *)angle);
        q.z = -1.0f / (2.0f + depth);
        rotate_title_background_quad(owner, (u8 *)&q, (u8 *)pos, -angle * 2, 104.0f);
        DVDConvertEntrynumToPath((f32 *)&q);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TUnk_804EEF80::render() {
    if (TMainTask::get_render_pass() != 0) {
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        render_logo_with_default(get_title_texture_list(), 0xD, -1, -150.0f);
        draw_title_background_pulse((s32)this, -140.0f, this->m_20);
        draw_title_background_layer(get_title_texture_list(), 3, -1, -130.0f);
        draw_title_rings((s32)this, -120.0f, this->m_20);
        TCameraCtrl__sub_80068EF0();
        TParticleCtrl::end_effect_render();
    }
}

void TUnk_804EEF80::run_task() {
    this->m_20 = (this->m_20 + 1);
}
TUnk_804EEF80::~TUnk_804EEF80() {

}
