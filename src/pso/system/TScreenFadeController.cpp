#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/system/TScreenFadeOut.h"
#include "pso/system/TScreenFadeIn.h"
#include "pso/system/TDeathTintFade.h"
#include "pso/system/TScreenFade.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/TColorOverlayFade.h"
#include "pso/system/TScreenFadeController.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/network/TLobby.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/network/client_id.h"
#include "pso/system/prs.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"



TScreenFadeController *screen_fade_controller;

#pragma defer_codegen on

void TScreenFade::render() {
    NJS_POINT2COL q;
    NJS_COLOR col[4];
    NJS_POINT2 pos[4];

    TCameraCtrl::restore_full_screen_view();
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    q.p = pos;
    q.col = col;
    q.tex = NULL;
    q.num = 4;
    color[3] = (s32)alpha;
    q.p[0].x = (0.0f);
    q.p[0].y = (0.0f);
    q.col[0].color = fade_color.color;
    q.p[1].x = (6.4e+02f);
    q.p[1].y = (0.0f);
    q.col[1].color = fade_color.color;
    q.p[2].x = (6.4e+02f);
    q.p[2].y = (4.8e+02f);
    q.col[2].color = fade_color.color;
    q.p[3].x = (0.0f);
    q.p[3].y = (4.8e+02f);
    q.col[3].color = fade_color.color;
    if ((0.0f) != (f32)color[3]) {
        draw_polygon_2d(&q, 4, 0x16, (-1e+01f));
    }
    TCameraCtrl::restore_saved_view();
}

TScreenFadeOut::TScreenFadeOut(TObject *parent, void (*callback)(TObject *)) : TScreenFade(tl_fade) {
    this->callback = callback;
    alpha = 0.0f;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
}

TScreenFadeOut::~TScreenFadeOut() {}

#pragma push
#pragma opt_common_subs off
void TScreenFadeOut::run_task() {
    this->alpha += 8.0f;
    if (this->alpha >= (255.0f)) {
        this->alpha = 255.0f;
        if (callback != NULL) {
            callback(this);
        }
        this->suspend_update();
    }
}
#pragma pop

TScreenFadeIn::TScreenFadeIn(TObject *parent, void (*callback)(TObject *)) : TScreenFade(tl_fade) {
    this->callback = callback;
    alpha = 255.0f;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
}

TScreenFadeIn::~TScreenFadeIn() {}

#pragma push
#pragma opt_common_subs off
void TScreenFadeIn::run_task() {
    this->alpha = (f32) (this->alpha - (8.0f));
    if (this->alpha <= 0.0f) {
        this->alpha = 0.0f;
        if (callback != NULL) {
            callback(this);
        }
        this->suspend_update();
    }
}
#pragma pop

TDeathTintFade::TDeathTintFade(TObject *parent, void (*callback)(TDeathTintFade *fade), s32 viewport_index) : TScreenFade(parent) {
    this->callback = callback;
    alpha = 0.0f;
    color[1] = 0;
    color[2] = 0;
    color[0] = 255;
    this->viewport_index = viewport_index;
}

TDeathTintFade::~TDeathTintFade() {
    TWindowCtrlMain::set_fill_color(viewport_index, 0);
}

void TDeathTintFade::run_task() {
    alpha += 2.0f;
    if (alpha >= 128.0f) {
        alpha = 128.0f;
        if (callback != NULL) {
            callback(this);
        }
        suspend_update();
    }
    color[3] = (s8)alpha;
    TWindowCtrlMain::set_fill_color(viewport_index, packed_color);
}

void TDeathTintFade::render() {  }

TColorOverlayFade::TColorOverlayFade(TObject *parent, s32 unk_1C, s32 duration, u8 c3, u8 c0, u8 c1, u8 c2) : TObject(parent) {
    u32 c;
    this->unk_1C = unk_1C;
    frame = 0;
    this->duration = duration;
    c = get_viewport_fill_color(local_client_id);
    start_color[3] = c;
    start_color[2] = c >> 8;
    start_color[1] = c >> 16;
    start_color[0] = c >> 24;
    target_color[3] = c3;
    target_color[0] = c0;
    target_color[1] = c1;
    target_color[2] = c2;
}

TColorOverlayFade::~TColorOverlayFade() {
    TWindowCtrlMain::set_fill_color((s32)local_client_id, (s32)this->lerp_color((1.0f)));
}

void TColorOverlayFade::run_task() {
    s32 next;
    TWindowCtrlMain::set_fill_color((s32)local_client_id, (s32)(this->lerp_color((f32)frame / (f32)duration)));
    next = frame + 1;
    frame = next;
    if (next > duration) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
s32 TColorOverlayFade::lerp_color(f32 t) {
    u8 g0;
    u8 r0;
    u8 b0;
    u8 a0;

    g0 = start_color[1];
    b0 = start_color[2];
    r0 = start_color[0];
    a0 = start_color[3];
    return (((((((s32) ((t * (f32) (target_color[0] - r0)) + (f32) r0) << 0x18)) | (((s32) ((t * (f32) (target_color[1] - g0)) + (f32) g0) << 0x10) & 0xFF0000 & ~0xFF000000)) & ~0xFF00) | (((s32) ((t * (f32) (target_color[2] - b0)) + (f32) b0) << 8) & 0xFF00)) & ~0xFF) | ((s32) ((t * (f32) (target_color[3] - a0)) + (f32) a0) & 0xFF);
}
#pragma pop

TScreenFadeController::TScreenFadeController(TObject *parent) : TObject(parent) {
    screen_fade_controller = this;
    mode = 0;
}

TScreenFadeController::~TScreenFadeController() {
    screen_fade_controller = NULL;
}

s32 TLobby::get_quest_thread_state() {
    if (screen_fade_controller != NULL) {
        return screen_fade_controller->mode;
    }
    return 0;
}

void TLobby::set_fade_params(void (*callback)()) {
    if (screen_fade_controller != NULL) {
        screen_fade_controller->callback = callback;
        screen_fade_controller->alpha = 255.0f;
        screen_fade_controller->color[0] = 0;
        screen_fade_controller->color[1] = 0;
        screen_fade_controller->color[2] = 0;
        screen_fade_controller->mode = 1;
    }
}

#pragma push
#pragma opt_common_subs off
void TScreenFadeController::step_fade_opacity_decrease() {
    alpha = (f32)(alpha - 8.0f);
    if (alpha <= 0.0f) {
        alpha = 0.0f;
        if (callback != NULL) {
            callback();
        }
        mode = 0;
    }
}
#pragma pop

void TLobby::init_fadeout_state(void (*callback)()) {
    if (screen_fade_controller != NULL) {
        screen_fade_controller->callback = callback;
        screen_fade_controller->alpha = 0.0f;
        screen_fade_controller->color[0] = 0;
        screen_fade_controller->color[1] = 0;
        screen_fade_controller->color[2] = 0;
        screen_fade_controller->mode = 2;
    }
}

#pragma push
#pragma opt_common_subs off
void TScreenFadeController::step_fade_opacity_increase() {
    alpha += 8.0f;
    if (alpha >= 255.0f) {
        alpha = 255.0f;
        if (callback != NULL) {
            callback();
        }
        mode = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TScreenFadeController::tick_fade_counter() {
    alpha += 1.0f;
    if (alpha >= 128.0f) {
        alpha = 128.0f;
        if (callback != NULL) {
            callback();
        }
        mode = 0;
    }
}
#pragma pop

void TScreenFadeController::run_task() {
    switch (mode) {
    case 1:
        step_fade_opacity_decrease();
        return;
    case 2:
        step_fade_opacity_increase();
        return;
    case 3:
        tick_fade_counter();
    case 0:
        return;
    }
}

void TScreenFadeController::render() {
    NJS_POINT2COL q;
    NJS_COLOR col[4];
    NJS_POINT2 pos[4];

    TCameraCtrl::restore_full_screen_view();
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    q.p = pos;
    q.col = col;
    q.tex = NULL;
    q.num = 4;
    color[3] = (s32)alpha;
    q.p[0].x = (0.0f);
    q.p[0].y = (0.0f);
    q.col[0].color = packed_color;
    q.p[1].x = (6.4e+02f);
    q.p[1].y = (0.0f);
    q.col[1].color = packed_color;
    q.p[2].x = (6.4e+02f);
    q.p[2].y = (4.8e+02f);
    q.col[2].color = packed_color;
    q.p[3].x = (0.0f);
    q.p[3].y = (4.8e+02f);
    q.col[3].color = packed_color;
    if ((0.0f) != (f32)color[3]) {
        draw_polygon_2d(&q, 4, 0x16, (-1e+01f));
    }
    TCameraCtrl::restore_saved_view();
}

u32 prs_decompress_buffer(const void *src, void *dst) {
    u32 size;
    PrsDecoder *prs = new PrsDecoder;
    if (prs != NULL) {
        size = prs->prs_decompress((u8 *)dst, (u8 *)src, 0);
    }
    if (prs != NULL) {
        delete prs;
    }
    return size;
}

s32 prs_decompress_alloc(const void *src, void *dst, s32 size_limit) {
    s32 size;
    PrsDecoder *prs = new PrsDecoder;
    if (prs != NULL) {
        size = prs->prs_decompress((u8 *)dst, (u8 *)src, 0);
    }
    if (prs != NULL) {
        delete prs;
    }
    return size;
}
