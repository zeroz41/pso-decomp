#include "pso/ui/frontend/TAdGameStartShadowGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

struct Rec_80320CB8 { f32 x, y, x2, y2; f32 u0, v0, u1, v1; };

struct Shadow_80320CB8 {
    s32 f0;
    u8 pad4[0x14];
    s32 *vt;
    Rec_80320CB8 r[5];
    s32 fbc, fc0, fc4;
};

extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__20TAdGameStartShadowGC[];
extern s32 TAdGameStartShadowGC__name;
extern s32 TAdGameStartShadowGC__texture_list;
Shadow_80320CB8 *__ct__20TAdGameStartShadowGCFv(Shadow_80320CB8 *arg0, void *parent);

struct Q_80320B38 { u8 b[0x20]; };

struct W_80320B38 { u8 pad[0x1C]; Q_80320B38 q[5]; s32 tex; };

void TAdGameStartShadowGC::sub_80320B38() {
    W_80320B38 *arg0 = (W_80320B38 *)this;
    u32 i;
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)((void *)TAdGameStartShadowGC__texture_list));
    set_draw_texture_and_color(0, arg0->tex);
    for (i = 0; i < 5; i++) {
        draw_textured_quad_at_depth((f32 *)&arg0->q[i], 0.74f);
    }
    TWindowSubStatusDisp::get_player();
}

void TAdGameStartShadowGC::render() { if (TMainTask::get_render_pass() != 1) { sub_80320B38(); } }

void TAdGameStartShadowGC::run_task() {
    s32 temp_r0;
    s32 var_r0;
    s32 var_r0_2;

    *(s32 *)((s8 *)this + 0xC4) = (s32) (*(s32 *)((s8 *)this + 0xC4) + 1);
    temp_r0 = *(s32 *)((s8 *)this + 0xC4);
    if (temp_r0 < 0xA) {
        *(s32 *)((s8 *)this + 0xC0) = (s32) (*(s32 *)((s8 *)this + 0xC0) + 0x19);
        var_r0 = *(s32 *)((s8 *)this + 0xC0);
        if (var_r0 > 0xFF) {
            var_r0 = 0xFF;
        }
        *(s32 *)((s8 *)this + 0xC0) = var_r0;
    } else if (temp_r0 > 0x1C) {
        *(s32 *)((s8 *)this + 0xC0) = (s32) (*(s32 *)((s8 *)this + 0xC0) - 0x19);
        var_r0_2 = *(s32 *)((s8 *)this + 0xC0);
        if (var_r0_2 < 0) {
            var_r0_2 = 0;
        }
        *(s32 *)((s8 *)this + 0xC0) = var_r0_2;
    }
    *(s32 *)((s8 *)this + 0xBC) = (s32) ((*(s32 *)((s8 *)this + 0xC0) << 0x18) | 0xFF0000 | 0xFFFF);
}
TAdGameStartShadowGC::~TAdGameStartShadowGC() {}
Shadow_80320CB8 *__ct__20TAdGameStartShadowGCFv(Shadow_80320CB8 *arg0, void *parent) {
    u32 i;
    __ct__7TObjectFP7TObject(arg0, parent);
    arg0->vt = __vt__20TAdGameStartShadowGC;
    arg0->f0 = TAdGameStartShadowGC__name;
    arg0->fbc = -1;
    arg0->fc0 = 0;
    arg0->fc4 = -1;
    TAdGameStartShadowGC__texture_list = TObjPlayer::get_instance();
    for (i = 0; i < 5; i++) {
        arg0->r[i].x = 128.0f * (f32)i;
        arg0->r[i].x2 = 128.0f + arg0->r[i].x;
        arg0->r[i].y = 190.0f;
        arg0->r[i].y2 = 128.0f + arg0->r[i].y;
    }
    arg0->r[0].u0 = 0.0f;
    arg0->r[0].v0 = 0.75f;
    arg0->r[0].u1 = 0.25f;
    arg0->r[0].v1 = 1.0f;
    for (i = 1; i < 4; i++) {
        arg0->r[i].u0 = 0.25f;
        arg0->r[i].v0 = 0.75f;
        arg0->r[i].u1 = 0.5f;
        arg0->r[i].v1 = 1.0f;
    }
    arg0->r[4].u0 = 0.5f;
    arg0->r[4].v0 = 0.75f;
    arg0->r[4].u1 = 0.75f;
    arg0->r[4].v1 = 1.0f;
    return arg0;
}

}
