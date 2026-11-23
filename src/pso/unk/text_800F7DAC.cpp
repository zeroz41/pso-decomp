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

struct Fade_800F7E28 {
    u8 pad[0x1C];
    f32 level;
    union {
        u32 color;
        u8 c[4];
    } u;
};

struct Quad_800F88D8 {
    f32 *pos;
    u32 *col;
    s32 start;
    s32 count;
};

struct Fade_800F88D8 {
    u8 pad[0x1C];
    f32 level;
    union {
        u32 color;
        u8 c[4];
    } u;
};
extern "C" {

void __ct__13TUnk_804999E8FP7TObject(void *, void *);
u32 prs_decompress_buffer(s32 arg0, s32 arg1);
void * TLobby__sub_800F8498(void *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void __ct__7TObjectFP7TObject(void *);
s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index);
u32 prs_decompress(int, int, int, int);

extern s32 __vt__13TUnk_80499988[];
extern s32 __vt__13TUnk_804999A0[];
void * screen_fade_controller;
extern s32 local_client_id;
}

#pragma defer_codegen on

void TUnk_804999E8::render() {
    Fade_800F88D8 *self = (Fade_800F88D8 *)this;
    Quad_800F88D8 q;
    u32 col[4];
    f32 pos[8];

    TCameraCtrl::restore_full_screen_view();
    set_color_blending_mode(0, 8);
    set_color_blending_mode(1, 6);
    q.pos = pos;
    q.col = col;
    q.start = 0;
    q.count = 4;
    self->u.c[3] = (s32)self->level;
    q.pos[0] = (0.0f);
    q.pos[1] = (0.0f);
    q.col[0] = self->u.color;
    q.pos[2] = (6.4e+02f);
    q.pos[3] = (0.0f);
    q.col[1] = self->u.color;
    q.pos[4] = (6.4e+02f);
    q.pos[5] = (4.8e+02f);
    q.col[2] = self->u.color;
    q.pos[6] = (0.0f);
    q.pos[7] = (4.8e+02f);
    q.col[3] = self->u.color;
    if ((0.0f) != (f32)self->u.c[3]) {
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

void*TLobby::init_entry_fields(int a1, int a2, int a3) { ((int (*)(void))__ct__13TUnk_804999E8FP7TObject)(); *(int*)((char*)this + 0x18) = (saddr)((unsigned char *)__vt__13TUnk_804999A0); *(int*)((char*)this + 0x28) = a2; *(float*)((char*)this + 0x1c) = (0.0f); *(unsigned char*)((char*)this + 0x21) = 0; *(unsigned char*)((char*)this + 0x22) = 0; *(unsigned char*)((char*)this + 0x20) = 255; *(int*)((char*)this + 0x24) = a3; return this; }

TUnk_804999A0::~TUnk_804999A0() {
    TWindowCtrlMain::set_value((saddr)(*(void **)((s8 *)this + 0x24)), 0);
}

void TUnk_804999A0::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    this->alpha += 2.0f;
    if (this->alpha >= 128.0f) {
        this->alpha = 128.0f;
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        this->suspend_update();
    }
    *(s8 *)((s8 *)arg0 + 0x23) = (s8) this->alpha;
    TWindowCtrlMain::set_value((s32)(*(s32 *)((s8 *)arg0 + 0x24)), this->m_20);
}

void TUnk_804999A0::render() {  }

void *TLobby__sub_800F8498(void *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    u32 c;
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__13TUnk_80499988;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    *(s32 *)((s8 *)arg0 + 0x24) = arg3;
    c = TWindowCtrlMain__sub_8024CD5C(local_client_id);
    *(u8 *)((s8 *)arg0 + 0x2B) = c;
    *(u8 *)((s8 *)arg0 + 0x2A) = c >> 8;
    *(u8 *)((s8 *)arg0 + 0x29) = c >> 16;
    *(u8 *)((s8 *)arg0 + 0x28) = c >> 24;
    *(u8 *)((s8 *)arg0 + 0x2F) = arg4;
    *(u8 *)((s8 *)arg0 + 0x2C) = arg5;
    *(u8 *)((s8 *)arg0 + 0x2D) = arg6;
    *(u8 *)((s8 *)arg0 + 0x2E) = arg7;
    return arg0;
}

TUnk_80499988::~TUnk_80499988() {
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)this->sub_800F8250((1.0f)));
}

void TUnk_80499988::run_task() {
    s32 temp_r3;
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)(this->sub_800F8250((f32) this->m_20 / (f32) *(s32 *)((s8 *)((u8 *)this) + 0x24))));
    temp_r3 = this->m_20 + 1;
    this->m_20 = temp_r3;
    if (temp_r3 > (s32) *(s32 *)((s8 *)((u8 *)this) + 0x24)) {
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

    temp_r10 = *(u8 *)((s8 *)this + 0x29);
    temp_r12 = *(u8 *)((s8 *)this + 0x2A);
    temp_r11 = *(u8 *)((s8 *)this + 0x28);
    temp_r31 = *(u8 *)((s8 *)this + 0x2B);
    return (((((((s32) ((farg0 * (f32) (*(u8 *)((s8 *)this + 0x2C) - temp_r11)) + (f32) temp_r11) << 0x18)) | (((s32) ((farg0 * (f32) (*(u8 *)((s8 *)this + 0x2D) - temp_r10)) + (f32) temp_r10) << 0x10) & 0xFF0000 & ~0xFF000000)) & ~0xFF00) | (((s32) ((farg0 * (f32) (*(u8 *)((s8 *)this + 0x2E) - temp_r12)) + (f32) temp_r12) << 8) & 0xFF00)) & ~0xFF) | ((s32) ((farg0 * (f32) (*(u8 *)((s8 *)this + 0x2F) - temp_r31)) + (f32) temp_r31) & 0xFF);
}
#pragma pop

TUnk_80499970::TUnk_80499970(TObject *parent) : TObject(parent) {
    screen_fade_controller = this;
    m_24 = 0;
}

TUnk_80499970::~TUnk_80499970() {
    (*(s32 *)&screen_fade_controller) = 0;
}

s32 TLobby::get_quest_thread_state() {
    if ((void *) screen_fade_controller != NULL) {
        return *(s32 *)((s8 *)screen_fade_controller + 0x24);
    }
    return 0;
}

void TLobby::set_fade_params(s32 fade_params) {
    if ((void *) screen_fade_controller != NULL) {
        *(s32 *)((s8 *)screen_fade_controller + 0x28) = fade_params;
        *(f32 *)((s8 *)screen_fade_controller + 0x1C) = 255.0f;
        *(s8 *)((s8 *)screen_fade_controller + 0x20) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x21) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x22) = 0;
        *(s32 *)((s8 *)screen_fade_controller + 0x24) = 1;
    }
}

#pragma push
#pragma opt_common_subs off
void TUnk_80499970::step_fade_opacity_decrease() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) - (8.0f));
    if (*(f32 *)((s8 *)arg0 + 0x1C) <= (0.0f)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = 0.0f;
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        this->m_24 = 0;
    }
}
#pragma pop

void TLobby::init_fadeout_state(s32 arg0) {
    if ((void *) screen_fade_controller != NULL) {
        *(s32 *)((s8 *)screen_fade_controller + 0x28) = arg0;
        *(f32 *)((s8 *)screen_fade_controller + 0x1C) = 0.0f;
        *(s8 *)((s8 *)screen_fade_controller + 0x20) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x21) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x22) = 0;
        *(s32 *)((s8 *)screen_fade_controller + 0x24) = 2;
    }
}

#pragma push
#pragma opt_common_subs off
void TUnk_80499970::step_fade_opacity_increase() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) += 8.0f;
    if (*(f32 *)((s8 *)arg0 + 0x1C) >= (255.0f)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = 255.0f;
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        *(s32 *)((s8 *)arg0 + 0x24) = 0;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TUnk_80499970::tick_fade_counter() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) += 1.0f;
    if (*(f32 *)((s8 *)arg0 + 0x1C) >= (128.0f)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = 128.0f;
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        *(s32 *)((s8 *)arg0 + 0x24) = 0;
    }
}
#pragma pop

void TUnk_80499970::run_task() {
    switch (*(s32 *)((s8 *)this + 0x24)) {
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
    ((Fade_800F7E28 *)this)->u.c[3] = (s32)((Fade_800F7E28 *)this)->level;
    q.pos[0] = (0.0f);
    q.pos[1] = (0.0f);
    q.col[0] = ((Fade_800F7E28 *)this)->u.color;
    q.pos[2] = (6.4e+02f);
    q.pos[3] = (0.0f);
    q.col[1] = ((Fade_800F7E28 *)this)->u.color;
    q.pos[4] = (6.4e+02f);
    q.pos[5] = (4.8e+02f);
    q.col[2] = ((Fade_800F7E28 *)this)->u.color;
    q.pos[6] = (0.0f);
    q.pos[7] = (4.8e+02f);
    q.col[3] = ((Fade_800F7E28 *)this)->u.color;
    if ((0.0f) != (f32)((Fade_800F7E28 *)this)->u.c[3]) {
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
