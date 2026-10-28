#include "pso/TItemReverseTechBG.h"
#include "pso/item/TItemReverseTechBG.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/TObject_80019A50.h"
#include "types.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItemReverseTechPart2_801198F8.h"
#include "pso/TItemReverseTechPart2.h"
#include "pso/item/TItemReverseTechPart2.h"
#include "pso/item/TItemReverseTech_8011A1E8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct TItemReverseTechBG_80119658 {
    u8 pad0[0x1C];
    s32 m1C;
    s32 m20;
    u32 alpha;
    s32 step;
    u8 pad2C[0x34 - 0x2C];
    u32 color;
    u8 pad38[0x5C - 0x38];
    s32 timer;
    s32 state;
};

extern "C" {
s32 __ct__7TObjectFP7TObject(void *, void *);

extern void *__vt__18TItemReverseTechBG[];
extern s32 lbl_805D2C54;

}

extern "C" {

u32 __nw__7TObjectFUl(s32);

}

struct RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2 { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2_size[sizeof(RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2) == 0x18 ? 1 : -1];

extern "C" {

extern RecoveredGlobal_80119B28___vt__21TItemReverseTechPart2 __vt__21TItemReverseTechPart2;
extern s32 lbl_805D2C50;

extern void *TItemReverseTechPart1__instance;

}

static const f32 lbl_805DAC08[1] = {0.0f};
static const f32 lbl_805DAC0C[1] = {480.0f};

#pragma defer_codegen on

void TItemReverseTechPart2::destroy_and_flag() {
    queue_destruction__7TObjectFv(this);
    if ((void *) TItemReverseTechPart1__instance != NULL) {
        *(s32 *)((s8 *)TItemReverseTechPart1__instance + 0x1C) = 1;
    }
}

extern "C" {
u8 *__ct__21TItemReverseTechPart2Fv(u8 *object, s32 arg1, s32 arg2) {
    u32 temp_r3;
    __ct__7TObjectFP7TObject((void *)object, (void *)arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__21TItemReverseTechPart2.value;
    TItemReverseTech__sub_8011A54C((object + 0x1C));
    TItemReverseTech__sub_8011A54C((object + 0x48));
    TItemReverseTech__sub_8011A54C((object + 0x74));
    TItemReverseTech__sub_8011A54C((object + 0xA0));
    TItemReverseTech__sub_8011A54C((object + 0xCC));
    TItemReverseTech__sub_8011A54C((object + 0xF8));
    TItemReverseTech__sub_8011A54C((object + 0x124));
    *(s32 *)((s8 *)object + 0) = (s32) lbl_805D2C50;
    *(s32 *)((s8 *)object + 0x1C) = 0x12C;
    *(s32 *)((s8 *)object + 0x20) = 0;
    *(s32 *)((s8 *)object + 0x24) = arg2;
    *(s32 *)((s8 *)object + 0x28) = 0;
    *(f32 *)((s8 *)object + 0x2C) = (f32) 128.0f;
    *(f32 *)((s8 *)object + 0x30) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x34) = (f32) 512.0f;
    *(f32 *)((s8 *)object + 0x38) = (f32) 512.0f;
    *(f32 *)((s8 *)object + 0x44) = (f32) 0.5f;
    *(s32 *)((s8 *)object + 0x48) = 0x12C;
    *(s32 *)((s8 *)object + 0x4C) = 0;
    *(s32 *)((s8 *)object + 0x50) = arg2;
    *(s32 *)((s8 *)object + 0x54) = 0xE;
    *(f32 *)((s8 *)object + 0x58) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x5C) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x60) = (f32) 1e+02f;
    *(f32 *)((s8 *)object + 0x64) = (f32) lbl_805DAC0C[0];
    *(f32 *)((s8 *)object + 0x70) = (f32) 0.5f;
    *(f32 *)((s8 *)object + 0x68) = (f32) 0.1953125f;
    *(f32 *)((s8 *)object + 0x6C) = (f32) 0.9375f;
    *(s32 *)((s8 *)object + 0x74) = 0x3C;
    *(s32 *)((s8 *)object + 0x78) = 0x3C;
    *(s32 *)((s8 *)object + 0x7C) = arg2;
    *(s32 *)((s8 *)object + 0x80) = 0xE;
    *(f32 *)((s8 *)object + 0x84) = (f32) 128.0f;
    *(f32 *)((s8 *)object + 0x88) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x8C) = (f32) 512.0f;
    *(f32 *)((s8 *)object + 0x90) = (f32) 512.0f;
    *(f32 *)((s8 *)object + 0x9C) = (f32) 0.6f;
    *(s32 *)((s8 *)object + 0xA0) = 0x3C;
    *(s32 *)((s8 *)object + 0xA4) = 0x3C;
    *(s32 *)((s8 *)object + 0xA8) = arg2;
    *(s32 *)((s8 *)object + 0xAC) = 0xE;
    *(f32 *)((s8 *)object + 0xB0) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0xB4) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0xB8) = (f32) 1e+02f;
    *(f32 *)((s8 *)object + 0xBC) = (f32) lbl_805DAC0C[0];
    *(f32 *)((s8 *)object + 0xC8) = (f32) 0.6f;
    *(f32 *)((s8 *)object + 0xC0) = (f32) 0.1953125f;
    *(f32 *)((s8 *)object + 0xC4) = (f32) 0.9375f;
    *(s32 *)((s8 *)object + 0xCC) = 0x12C;
    *(s32 *)((s8 *)object + 0xD0) = 0;
    *(s32 *)((s8 *)object + 0xD4) = arg2;
    *(s32 *)((s8 *)object + 0xD8) = 0;
    *(f32 *)((s8 *)object + 0xDC) = (f32) 316.0f;
    *(f32 *)((s8 *)object + 0xE0) = (f32) 32.0f;
    *(f32 *)((s8 *)object + 0xE4) = (f32) 3e+02f;
    *(f32 *)((s8 *)object + 0xE8) = (f32) 3e+02f;
    *(f32 *)((s8 *)object + 0xF4) = (f32) 0.3f;
    *(s32 *)((s8 *)object + 0xF8) = 0x12C;
    *(s32 *)((s8 *)object + 0xFC) = 0;
    *(s32 *)((s8 *)object + 0x100) = arg2;
    *(s32 *)((s8 *)object + 0x104) = 0;
    *(f32 *)((s8 *)object + 0x108) = (f32) 316.0f;
    *(f32 *)((s8 *)object + 0x10C) = (f32) 148.0f;
    *(f32 *)((s8 *)object + 0x110) = (f32) 3e+02f;
    *(f32 *)((s8 *)object + 0x114) = (f32) 3e+02f;
    *(f32 *)((s8 *)object + 0x120) = (f32) 0.3f;
    *(s32 *)((s8 *)object + 0x124) = 0x1194;
    *(s32 *)((s8 *)object + 0x128) = 0x1E;
    *(s32 *)((s8 *)object + 0x12C) = arg2;
    *(s32 *)((s8 *)object + 0x130) = 0xF;
    *(f32 *)((s8 *)object + 0x134) = (f32) 1e+01f;
    *(f32 *)((s8 *)object + 0x138) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)object + 0x13C) = (f32) 3.4e+02f;
    *(f32 *)((s8 *)object + 0x140) = (f32) lbl_805DAC0C[0];
    *(f32 *)((s8 *)object + 0x14C) = (f32) 0.75f;
    temp_r3 = __nw__7TObjectFUl(0x64);
    if (temp_r3 != 0U) {
        __ct__18TItemReverseTechBGFv((void *)temp_r3, (void *)object, object + 0x124);
    }
    *(s32 *)((s8 *)object + 0x150) = 0;
    *(s32 *)((s8 *)object + 0x154) = 0;
    return object;
}
}

TItemReverseTechPart2::~TItemReverseTechPart2() {}

extern "C" {
void run_task__21TItemReverseTechPart2Fv(u8 *object) {
    s32 temp_r3;
    s32 temp_r3_2;
    void *nw;

    if ((*(s32 *)((s8 *)object + 0x150) % 360) == 0) {
        if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
            __ct__18TItemReverseTechBGFv(nw, object, object + 0x74);
        }
        if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
            __ct__18TItemReverseTechBGFv(nw, object, object + 0xA0);
        }
    }
    if ((s32) *(s32 *)((s8 *)object + 0x154) < 0xC) {
        temp_r3 = *(s32 *)((s8 *)object + 0x150);
        if ((temp_r3 >= 0x78) && (((temp_r3 - 0x78) % 720) == 0)) {
            *(s32 *)((s8 *)object + 0x28) = 0xC;
            if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x1C);
            }
            if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x48);
            }
            *(s32 *)((s8 *)object + 0xD8) = (s32) *(s32 *)((s8 *)object + 0x154);
            if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0xCC);
            }
            *(s32 *)((s8 *)object + 0x154) = (s32) (*(s32 *)((s8 *)object + 0x154) + 1);
        }
        temp_r3_2 = *(s32 *)((s8 *)object + 0x150);
        if ((temp_r3_2 >= 0x1E0) && (((temp_r3_2 - 0x1E0) % 720) == 0)) {
            *(s32 *)((s8 *)object + 0x28) = 0xD;
            if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x1C);
            }
            if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0x48);
            }
            *(s32 *)((s8 *)object + 0x104) = (s32) *(s32 *)((s8 *)object + 0x154);
            if ((nw = (void *)__nw__7TObjectFUl(0x64)) != 0U) {
                __ct__18TItemReverseTechBGFv(nw, object, object + 0xF8);
            }
            *(s32 *)((s8 *)object + 0x154) = (s32) (*(s32 *)((s8 *)object + 0x154) + 1);
        }
        goto block_26;
    }
    if ((u32) *(u32 *)((s8 *)object + 0x14) == 0U) {
        queue_destruction__7TObjectFv(object);
        return;
    }
block_26:
    *(s32 *)((s8 *)object + 0x150) = (s32) (*(s32 *)((s8 *)object + 0x150) + 1);
}
}

void TItemReverseTechPart2::render() {  }

extern "C" {
void *__ct__18TItemReverseTechBGFv(void *arg0, void *parent, void *arg3) {
    s32 temp_r3;

    __ct__7TObjectFP7TObject(arg0, parent);
    *(void **)((s8 *)arg0 + 0x18) = __vt__18TItemReverseTechBG;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2C54;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg3 + 0);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg3 + 4);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)arg3 + 8);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg3 + 0xC);
    *(s32 *)((s8 *)arg0 + 0x24) = 0;
    temp_r3 = *(s32 *)((s8 *)arg0 + 0x20);
    if (temp_r3 != 0) {
        *(s32 *)((s8 *)arg0 + 0x28) = (s32) (0xFF / temp_r3);
        if ((u32) *(s32 *)((s8 *)arg0 + 0x28) == 0U) {
            *(s32 *)((s8 *)arg0 + 0x28) = 1;
        }
    }
    *(s32 *)((s8 *)arg0 + 0x34) = -1;
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg3 + 0x10);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)arg3 + 0x14);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) (*(f32 *)((s8 *)arg3 + 0x10) + *(f32 *)((s8 *)arg3 + 0x18));
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) (*(f32 *)((s8 *)arg3 + 0x14) + *(f32 *)((s8 *)arg3 + 0x1C));
    *(f32 *)((s8 *)arg0 + 0x48) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) lbl_805DAC08[0];
    *(f32 *)((s8 *)arg0 + 0x50) = (f32) *(f32 *)((s8 *)arg3 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) *(f32 *)((s8 *)arg3 + 0x24);
    *(f32 *)((s8 *)arg0 + 0x58) = (f32) *(f32 *)((s8 *)arg3 + 0x28);
    *(s32 *)((s8 *)arg0 + 0x60) = 0;
    *(s32 *)((s8 *)arg0 + 0x5C) = 0;
    return arg0;
}
}

TItemReverseTechBG::~TItemReverseTechBG() {}

void TItemReverseTechBG::run_task() {
    TItemReverseTechBG_80119658 *o = (TItemReverseTechBG_80119658 *)this;
    switch (o->state) {
    case 0:
        if (o->alpha != 0xFF) {
            o->alpha += o->step;
            if (o->alpha > 0xFF) {
                o->alpha = 0xFF;
            }
        }
        if (o->timer == o->m20) {
            o->alpha = 0xFF;
            o->state = 1;
            o->timer = 0;
        } else {
            o->timer++;
        }
        break;
    case 1:
        if (o->timer == o->m1C) {
            o->state = 2;
            o->timer = 0;
        } else {
            o->timer++;
        }
        break;
    case 2:
        if (o->alpha != 0) {
            o->alpha -= o->step;
        }
        if (o->timer == o->m20) {
            o->alpha = 0;
            o->state = 3;
            o->timer = 0;
        } else {
            o->timer++;
        }
        break;
    case 3:
        queue_destruction__7TObjectFv(o);
        return;
    }
    o->color = (o->alpha << 24) | 0xFFFFFF;
}

void TItemReverseTechBG::render() {
    set_default_alpha_blend();
    set_texlist((u32)(*(void **)((s8 *)this + 0x2C)));
    begin_screen_draw(1);
    set_draw_texture_and_color((s32)(*(void **)((s8 *)this + 0x30)), (s32)(*(void **)((s8 *)this + 0x34)));
    draw_textured_quad_at_depth((f32 *)((char *)this + 56), *(f32 *)((s8 *)this + 0x58));
    TWindowSubStatusDisp::get_player();
}
