#include "types.h"
#include "pso/unk/TUnk_804999D0.h"
#include "pso/unk/TUnk_804999B8.h"
#include "pso/unk/TUnk_804999A0.h"
#include "pso/boss/TUnk_804999E8.h"
#include "pso/TObject.h"
#include "pso/unk/TUnk_80499988.h"
#include "pso/unk/TUnk_80499970.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/THunterGuildSeqOffline.h"
#include "pso/misc/TLobby.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/object/TObjLuker.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_800F81A8_lbl_80499970 {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_800F81A8_lbl_80499970_size[sizeof(RecoveredGlobal_800F81A8_lbl_80499970) == 0x18 ? 1 : -1];

struct RecoveredGlobal_800F8428_lbl_80499988 {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_800F8428_lbl_80499988_size[sizeof(RecoveredGlobal_800F8428_lbl_80499988) == 0x18 ? 1 : -1];

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

void queue_destruction__7TObjectFv(void *);
void __ct__13TUnk_804999E8FP7TObject(void *, void *);
void *__dt__13TUnk_804999E8Fv(void *, s16);
void TCameraCtrl__sub_80068EF0(void);
u32 prs_decompress_buffer(s32 arg0, s32 arg1);
}
void step_fade_opacity_increase(u8 *arg0);
extern "C" {
void step_fade_opacity_decrease__13TUnk_80499970Fv(u8 *arg0);
u8 * __dt__13TUnk_80499988Fv(u8 *arg0, s16 arg1);
void * TLobby__sub_800F8498(void *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);
void * __dt__13TUnk_804999A0Fv(void *arg0, s16 arg1);
void * __dt__13TUnk_804999B8Fv(void *arg0, s16 arg1);
void * __dt__13TUnk_804999D0Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, int);
void __ct__7TObjectFP7TObject(void *);
s32 TWindowCtrlMain__sub_8024CD5C(s32 viewport_index);
u32 prs_decompress(int, int, int, int);
u32 reset_counters__6TLobbyFv();
void set_cached_blend_factor(s32, s32);

extern RecoveredGlobal_800F81A8_lbl_80499970 lbl_80499970;
extern RecoveredGlobal_800F8428_lbl_80499988 lbl_80499988;
extern s32 lbl_804999A0[];
extern s32 lbl_804999B8[];
extern s32 lbl_804999D0[];
extern void *screen_fade_controller;
extern s32 local_client_id;
extern void *tl_fade;

#pragma push
#pragma scheduling off
u32 prs_decompress_buffer(s32 arg0, s32 arg1) {
  s32 var_r28;
  s32 var_r29;
  s32 src;
  s32 var_r5;
  s32 var_r6;
  u32 var_r30;
  u32 var_r31;
  u32 var_r3;
  u32 phi_r30;
  s32 saved_reg_r30;
  var_r30 = saved_reg_r30;
  var_r28 = arg0;
  var_r29 = arg1;
  var_r3 = 0x30U;
  var_r31 = (int)::operator new(0x30);
  phi_r30 = saved_reg_r30;
  if (var_r31 != 0U)
  {
    var_r31 = reset_counters__6TLobbyFv();
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

void TUnk_80499970::render() {
    Quad_800F7E28 q;
    u32 col[4];
    f32 pos[8];

    TCameraCtrl::restore_full_screen_view();
    set_cached_blend_factor(0, 8);
    set_cached_blend_factor(1, 6);
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
        ((TObjCMHairMenu *)(&q))->draw_tri_fan_2d(4, 0x16, (-1e+01f));
    }
    TCameraCtrl__sub_80068EF0();
}

void TLobby::dispatch_state() {

    switch (*(s32 *)((s8 *)this + 0x24)) {
    case 1:
        step_fade_opacity_decrease__13TUnk_80499970Fv((u8 *)this);
        return;
    case 2:
        step_fade_opacity_increase((u8 *)this);
        return;
    case 3:
        tick_fade_counter();
    case 0:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
void TLobby::tick_fade_counter() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) += 1.0f;
    if (*(f32 *)((s8 *)arg0 + 0x1C) >= (128.0f)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (128.0f);
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        *(s32 *)((s8 *)arg0 + 0x24) = 0;
    }
}
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void step_fade_opacity_increase(u8 *arg0) {
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) += 8.0f;
    if (*(f32 *)((s8 *)arg0 + 0x1C) >= (255.0f)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (255.0f);
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        *(s32 *)((s8 *)arg0 + 0x24) = 0;
    }
}
#pragma pop

void TLobby::init_fadeout_state(s32 arg0) {
    if ((void *) screen_fade_controller != NULL) {
        *(s32 *)((s8 *)screen_fade_controller + 0x28) = arg0;
        *(f32 *)((s8 *)screen_fade_controller + 0x1C) = (f32) (0.0f);
        *(s8 *)((s8 *)screen_fade_controller + 0x20) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x21) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x22) = 0;
        *(s32 *)((s8 *)screen_fade_controller + 0x24) = 2;
    }
}

#pragma push
#pragma opt_common_subs off
void TUnk_80499970::step_fade_opacity_decrease() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) - (8.0f));
    if (*(f32 *)((s8 *)arg0 + 0x1C) <= (0.0f)) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (0.0f);
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        this->m_24 = 0;
    }
}
#pragma pop

void TLobby::set_fade_params(s32 arg0) {
    if ((void *) screen_fade_controller != NULL) {
        *(s32 *)((s8 *)screen_fade_controller + 0x28) = arg0;
        *(f32 *)((s8 *)screen_fade_controller + 0x1C) = (f32) (255.0f);
        *(s8 *)((s8 *)screen_fade_controller + 0x20) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x21) = 0;
        *(s8 *)((s8 *)screen_fade_controller + 0x22) = 0;
        *(s32 *)((s8 *)screen_fade_controller + 0x24) = 1;
    }
}

s32 TLobby::get_quest_thread_state() {
    if ((void *) screen_fade_controller != NULL) {
        return *(s32 *)((s8 *)screen_fade_controller + 0x24);
    }
    return 0;
}

u8 *TLobby::dtor_clear_singleton(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)((u8 *)this) + 0x18) = &lbl_80499970.value;
        (*(s32 *)&screen_fade_controller) = 0;
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            ((s32 (*)(void *))__dl__7TObjectFPv)(this);
        }
    }
    return ((u8 *)this);
}

void *TLobby::ct_register() {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = ((s32 *)&lbl_80499970);
    screen_fade_controller = this;
    *(u32 *)((s8 *)this + 0x24) = 0;
    return this;
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

void TUnk_80499988::run_task() {
    s32 temp_r3;
    TWindowCtrlMain::set_value((s32)local_client_id, (s32)(this->sub_800F8250((f32) this->m_20 / (f32) *(s32 *)((s8 *)((u8 *)this) + 0x24))));
    temp_r3 = this->m_20 + 1;
    this->m_20 = temp_r3;
    if (temp_r3 > (s32) *(s32 *)((s8 *)((u8 *)this) + 0x24)) {
        queue_destruction__7TObjectFv(this);
    }
}

u8 *__dt__13TUnk_80499988Fv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &lbl_80499988.value;
        TWindowCtrlMain::set_value((s32)local_client_id, (s32)(((TUnk_80499988 *)arg0)->sub_800F8250((1.0f))));
        ((u8 * (*)(void *, s16))__dt__7TObjectFv)(arg0, 0);
        if (arg1 > 0) {
            ((void (*)(s32))__dl__7TObjectFPv)((s32) arg0);
        }
    }
    return arg0;
}

void *TLobby__sub_800F8498(void *arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7) {
    u32 c;
    ((void (*)(void *, void *))__ct__7TObjectFP7TObject)(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &lbl_80499988.value;
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

void TUnk_804999A0::render() {  }

void TUnk_804999A0::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 (*temp_r12)();
    *(f32 *)((s8 *)arg0 + 0x1C) += 2.0f;
    if (*(f32 *)((s8 *)arg0 + 0x1C) >= 128.0f) {
        *(f32 *)((s8 *)arg0 + 0x1C) = 128.0f;
        temp_r12 = *(s32 (**)())((s8 *)arg0 + 0x28);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        ((TObject *)arg0)->suspend_update();
    }
    *(s8 *)((s8 *)arg0 + 0x23) = (s8) *(f32 *)((s8 *)arg0 + 0x1C);
    TWindowCtrlMain::set_value((s32)(*(s32 *)((s8 *)arg0 + 0x24)), this->m_20);
}

void *__dt__13TUnk_804999A0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804999A0;
        TWindowCtrlMain::set_value((s32)(*(void **)((s8 *)arg0 + 0x24)), 0);
        __dt__13TUnk_804999E8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void*TLobby::init_entry_fields(int a1, int a2, int a3) { ((int (*)(void))__ct__13TUnk_804999E8FP7TObject)(); *(int*)((char*)this + 0x18) = (int)((unsigned char *)&lbl_804999A0); *(int*)((char*)this + 0x28) = a2; *(float*)((char*)this + 0x1c) = (0.0f); *(unsigned char*)((char*)this + 0x21) = 0; *(unsigned char*)((char*)this + 0x22) = 0; *(unsigned char*)((char*)this + 0x20) = 255; *(int*)((char*)this + 0x24) = a3; return this; }

#pragma push
#pragma opt_common_subs off
void TUnk_804999B8::run_task() {
    s32 (*temp_r12)();
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x1C) - (8.0f));
    if (*(f32 *)((s8 *)((u8 *)this) + 0x1C) <= 0.0f) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) 0.0f;
        temp_r12 = *(s32 (**)())((s8 *)((u8 *)this) + 0x24);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        this->suspend_update();
    }
}
#pragma pop

void *__dt__13TUnk_804999B8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804999B8;
        __dt__13TUnk_804999E8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TLobby::init_fade(void *arg1, void *arg2) {
    __ct__13TUnk_804999E8FP7TObject(this, tl_fade);
    *(s32 **)((s8 *)this + 0x18) = lbl_804999B8;
    *(void **)((s8 *)this + 0x24) = arg2;
    *(f32 *)((s8 *)this + 0x1C) = (255.0f);
    *(u8 *)((s8 *)this + 0x20) = 0;
    *(u8 *)((s8 *)this + 0x21) = 0;
    *(u8 *)((s8 *)this + 0x22) = 0;
    return this;
}

#pragma push
#pragma opt_common_subs off
void TUnk_804999D0::run_task() {
    s32 (*temp_r12)();
    *(f32 *)((s8 *)((u8 *)this) + 0x1C) += 8.0f;
    if (*(f32 *)((s8 *)((u8 *)this) + 0x1C) >= (255.0f)) {
        *(f32 *)((s8 *)((u8 *)this) + 0x1C) = (f32) (255.0f);
        temp_r12 = *(s32 (**)())((s8 *)((u8 *)this) + 0x24);
        if (temp_r12 != NULL) {
            temp_r12();
        }
        this->suspend_update();
    }
}
#pragma pop

void *__dt__13TUnk_804999D0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804999D0;
        __dt__13TUnk_804999E8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *THunterGuildSeqOffline::init(void *arg1, void *arg2) {
    __ct__13TUnk_804999E8FP7TObject(this, tl_fade);
    *(s32 * *)((u8 *)this + 0x18) = lbl_804999D0;
    *(void **)((s8 *)this + 0x24) = arg2;
    *(f32 *)&this->m_38 = (0.0f);
    *(u8 *)((s8 *)this + 0x20) = 0;
    *(u8 *)((s8 *)this + 0x21) = 0;
    *(u8 *)((s8 *)this + 0x22) = 0;
    return this;
}

void TUnk_804999E8::render() {
    Fade_800F88D8 *self = (Fade_800F88D8 *)this;
    Quad_800F88D8 q;
    u32 col[4];
    f32 pos[8];

    TCameraCtrl::restore_full_screen_view();
    set_cached_blend_factor(0, 8);
    set_cached_blend_factor(1, 6);
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
        ((TObjCMHairMenu *)(&q))->draw_tri_fan_2d(4, 0x16, (-1e+01f));
    }
    TCameraCtrl__sub_80068EF0();
}
