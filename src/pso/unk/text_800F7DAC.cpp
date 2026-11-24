#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/unk/TScreenFadeOut.h"
#include "pso/unk/TScreenFadeIn.h"
#include "pso/unk/TDeathTintFade.h"
#include "pso/unk/TScreenFade.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TColorOverlayFade.h"
#include "pso/unk/TScreenFadeController.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/ModelDrawContext.h"


extern "C" {

u32 prs_decompress_buffer(s32 arg0, s32 arg1);
s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index);
u32 prs_decompress(int, int, int, int);

extern s32 local_client_id;
}

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

TDeathTintFade::TDeathTintFade(TObject *parent, void (*callback)(), s32 viewport_index) : TScreenFade(parent) {
    this->callback = callback;
    alpha = 0.0f;
    color[1] = 0;
    color[2] = 0;
    color[0] = 255;
    this->viewport_index = viewport_index;
}

TDeathTintFade::~TDeathTintFade() {
    TWindowCtrlMain::set_value(viewport_index, 0);
}

void TDeathTintFade::run_task() {
    alpha += 2.0f;
    if (alpha >= 128.0f) {
        alpha = 128.0f;
        if (callback != NULL) {
            callback();
        }
        suspend_update();
    }
    color[3] = (s8)alpha;
    TWindowCtrlMain::set_value(viewport_index, packed_color);
}

void TDeathTintFade::render() {  }

TColorOverlayFade::TColorOverlayFade(TObject *parent, s32 unk_1C, s32 duration, u8 c3, u8 c0, u8 c1, u8 c2) : TObject(parent) {
    u32 c;
    this->unk_1C = unk_1C;
    frame = 0;
    this->duration = duration;
    c = TWindowCtrlMain__sub_8024CD5C(local_client_id);
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
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)this->lerp_color((1.0f)));
}

void TColorOverlayFade::run_task() {
    s32 next;
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)(this->lerp_color((f32)frame / (f32)duration)));
    next = frame + 1;
    frame = next;
    if (next > duration) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
s32 TColorOverlayFade::lerp_color(f32 farg0) {
    u8 temp_r10;
    u8 temp_r11;
    u8 temp_r12;
    u8 temp_r31;

    temp_r10 = start_color[1];
    temp_r12 = start_color[2];
    temp_r11 = start_color[0];
    temp_r31 = start_color[3];
    return (((((((s32) ((farg0 * (f32) (target_color[0] - temp_r11)) + (f32) temp_r11) << 0x18)) | (((s32) ((farg0 * (f32) (target_color[1] - temp_r10)) + (f32) temp_r10) << 0x10) & 0xFF0000 & ~0xFF000000)) & ~0xFF00) | (((s32) ((farg0 * (f32) (target_color[2] - temp_r12)) + (f32) temp_r12) << 8) & 0xFF00)) & ~0xFF) | ((s32) ((farg0 * (f32) (target_color[3] - temp_r31)) + (f32) temp_r31) & 0xFF);
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

#pragma push
#pragma scheduling off
u32 prs_decompress_buffer(s32 arg0, s32 arg1) {
  s32 var_r28;
  s32 var_r29;
  s32 src;
  s32 var_r5;
  s32 var_r6;
  u32 var_r30;
  uaddr var_r31;
  u32 var_r3;
  u32 phi_r30;
  s32 saved_reg_r30;
  var_r30 = saved_reg_r30;
  var_r28 = arg0;
  var_r29 = arg1;
  var_r3 = 0x30U;
  var_r31 = (saddr)::operator new(0x30);
  phi_r30 = saved_reg_r30;
  if (var_r31 != 0U)
  {
    var_r31 = (uaddr)((TLobby *)var_r31)->reset_counters();
  }
  if (var_r31 != 0U)
  {
    var_r3 = var_r31;
    src = var_r29;
    var_r5 = var_r28;
    var_r6 = 0;
    phi_r30 = (prs_decompress((int) var_r3, (int) src, (int) var_r5, 0));
  }
  if (var_r31 != 0U)
  {
    var_r3 = var_r31;
    src = 1;
    TLobby::destroy_ep3_exist((int) var_r3, 1);
  }
  var_r3 = phi_r30;
  return var_r3;
}
#pragma pop
