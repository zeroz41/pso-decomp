#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/unk/TUnk_804999D0.h"
#include "pso/unk/TUnk_804999B8.h"
#include "pso/unk/TUnk_804999A0.h"
#include "pso/boss/TUnk_804999E8.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TUnk_80499988.h"
#include "pso/unk/TUnk_80499970.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/city/THunterGuildSeqOffline.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/ModelDrawContext.h"


struct Quad_800F7E28 {
    f32 *pos;
    u32 *col;
    s32 start;
    s32 count;
};

extern "C" {

u32 prs_decompress_buffer(s32 arg0, s32 arg1);
s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index);
u32 prs_decompress(int, int, int, int);

extern s32 local_client_id;
}

TUnk_80499970 *screen_fade_controller;

#pragma defer_codegen on

void TUnk_804999E8::render() {
    Quad_800F7E28 q;
    u32 col[4];
    f32 pos[8];

    TCameraCtrl::restore_full_screen_view();
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    q.pos = pos;
    q.col = col;
    q.start = 0;
    q.count = 4;
    color[3] = (s32)alpha;
    q.pos[0] = (0.0f);
    q.pos[1] = (0.0f);
    q.col[0] = packed_color;
    q.pos[2] = (6.4e+02f);
    q.pos[3] = (0.0f);
    q.col[1] = packed_color;
    q.pos[4] = (6.4e+02f);
    q.pos[5] = (4.8e+02f);
    q.col[2] = packed_color;
    q.pos[6] = (0.0f);
    q.pos[7] = (4.8e+02f);
    q.col[3] = packed_color;
    if ((0.0f) != (f32)color[3]) {
        draw_polygon_2d((NJS_POINT2COL *)&q, 4, 0x16, (-1e+01f));
    }
    TCameraCtrl::restore_saved_view();
}

TUnk_804999D0::TUnk_804999D0(TObject *parent, void (*callback)(TObject *)) : TUnk_804999E8(tl_fade) {
    this->callback = callback;
    alpha = 0.0f;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
}

TUnk_804999D0::~TUnk_804999D0() {}

#pragma push
#pragma opt_common_subs off
void TUnk_804999D0::run_task() {
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

TUnk_804999B8::TUnk_804999B8(TObject *parent, void (*callback)(TObject *)) : TUnk_804999E8(tl_fade) {
    this->callback = callback;
    alpha = 255.0f;
    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
}

TUnk_804999B8::~TUnk_804999B8() {}

#pragma push
#pragma opt_common_subs off
void TUnk_804999B8::run_task() {
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

TUnk_804999A0::TUnk_804999A0(TObject *parent, void (*callback)(), s32 viewport_index) : TUnk_804999E8(parent) {
    this->callback = callback;
    alpha = 0.0f;
    color[1] = 0;
    color[2] = 0;
    color[0] = 255;
    this->viewport_index = viewport_index;
}

TUnk_804999A0::~TUnk_804999A0() {
    TWindowCtrlMain::set_value(viewport_index, 0);
}

void TUnk_804999A0::run_task() {
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

void TUnk_804999A0::render() {  }

TUnk_80499988::TUnk_80499988(TObject *parent, s32 unk_1C, s32 duration, u8 c3, u8 c0, u8 c1, u8 c2) : TObject(parent) {
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

TUnk_80499988::~TUnk_80499988() {
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)this->sub_800F8250((1.0f)));
}

void TUnk_80499988::run_task() {
    s32 next;
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)(this->sub_800F8250((f32)frame / (f32)duration)));
    next = frame + 1;
    frame = next;
    if (next > duration) {
        queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
s32 TUnk_80499988::sub_800F8250(f32 farg0) {
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

TUnk_80499970::TUnk_80499970(TObject *parent) : TObject(parent) {
    screen_fade_controller = this;
    mode = 0;
}

TUnk_80499970::~TUnk_80499970() {
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
void TUnk_80499970::step_fade_opacity_decrease() {
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
void TUnk_80499970::step_fade_opacity_increase() {
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
void TUnk_80499970::tick_fade_counter() {
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

void TUnk_80499970::run_task() {
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

void TUnk_80499970::render() {
    Quad_800F7E28 q;
    u32 col[4];
    f32 pos[8];

    TCameraCtrl::restore_full_screen_view();
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    q.pos = pos;
    q.col = col;
    q.start = 0;
    q.count = 4;
    color[3] = (s32)alpha;
    q.pos[0] = (0.0f);
    q.pos[1] = (0.0f);
    q.col[0] = packed_color;
    q.pos[2] = (6.4e+02f);
    q.pos[3] = (0.0f);
    q.col[1] = packed_color;
    q.pos[4] = (6.4e+02f);
    q.pos[5] = (4.8e+02f);
    q.col[2] = packed_color;
    q.pos[6] = (0.0f);
    q.pos[7] = (4.8e+02f);
    q.col[3] = packed_color;
    if ((0.0f) != (f32)color[3]) {
        draw_polygon_2d((NJS_POINT2COL *)&q, 4, 0x16, (-1e+01f));
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
