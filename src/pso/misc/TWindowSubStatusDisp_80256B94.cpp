#include "types.h"
#include "pso/system/memory.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TUnk_804CF930.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TTecRaFoie.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdChrMoveEffectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80256BDC_lbl_804CF918 {
    s32 value;
    u8 remaining[0x14];
};

struct Bar_80256C00 {
    u8 pad0[0x14];
    f32 scale;
    u8 pad1[4];
    f32 width;
    f32 max;
    f32 target;
};

struct Gauge_802571B4 {
    u16 flags;
    u8 pad2[0x12];
    f32 scale;
    u8 pad18[4];
    f32 cur;
    f32 max;
    f32 val;
};

struct Gauge_80256E0C { u8 p0[0x14]; f32 max; };

struct Pos_80256E0C { f32 x; f32 y; };

struct Quad_80256E0C { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

extern "C" {
extern s32 lbl_804CF918[];
void sub_80256BDC__13TUnk_804CF930Fs(u8 *arg0, s16 arg1);
void calc_bar_width__20TWindowSubStatusDispFPv(struct Bar_80256C00 *bar);
f32 fabs_float(f32);
extern const f32 lbl_805DCE58;
extern const f32 lbl_805DCECC;
void step_gauge_bar_width(Gauge_802571B4 *g);
s32 try_open__19TWindowKeyBoardSoftFii(void *, void *);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void draw_status_gauge_bar__13TUnk_804CF930FPvPvff(Gauge_80256E0C *self, void *ctx, Pos_80256E0C *pos, f32 depth, f32 len);
void TWindowSubStatusDisp__sub_80256BF8(void);
void TWindowSubStatusDisp__sub_80256BFC(void);
void *destroy__13TUnk_804CF930Fs(void *arg0, s16 arg1);

void *TUnk_804CF930::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 4) = lbl_804CF918;
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

typedef char RecoveredGlobal_80256BDC_lbl_804CF918_size[sizeof(RecoveredGlobal_80256BDC_lbl_804CF918) == 0x18 ? 1 : -1];
void TUnk_804CF930::sub_80256BDC(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_80256BDC_lbl_804CF918 *)&lbl_804CF918).value;
    *(s16 *)((s8 *)arg0 + 0) = 0;
    this->m_2 = arg1;
}

void TWindowSubStatusDisp__sub_80256BF8(void) {  }
void TWindowSubStatusDisp__sub_80256BFC(void) {  }
void calc_bar_width__20TWindowSubStatusDispFPv(struct Bar_80256C00 *bar) {
    f32 target;
    f32 max = bar->max;
    f32 v;
    if (max <= 0.0f || (target = bar->target) <= 0.0f) {
        v = 0.0f;
    } else {
        v = (target * bar->scale) / max;
    }
    bar->width = v;
}

void TWindowSubStatusDisp__sub_80256C40(Gauge_80256E0C *self, TWindowKeyBoardSoft *ctx, Pos_80256E0C *pos, f32 depth) {
    Quad_80256E0C q;
    f32 w;
    w = self->max - -2.0f;
    q.x0 = -1.0f + pos->x;
    q.y0 = -1.0f + pos->y;
    q.x1 = 20.0f + q.x0;
    q.y1 = 9.0f + q.y0;
    q.u0 = 0.1484375f;
    q.v0 = 0.93359375f;
    q.u1 = 0.2265625f;
    q.v1 = 0.96875f;
    if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
    q.x0 = 20.0f + (-1.0f + pos->x);
    q.y0 = -1.0f + pos->y;
    q.x1 = ((q.x0 + w) - 20.0f) - 20.0f;
    q.y1 = 9.0f + q.y0;
    q.u0 = 0.23046875f;
    q.v0 = 0.93359375f;
    q.u1 = 0.30859375f;
    q.v1 = 0.96875f;
    if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
    q.x0 = ((-1.0f + pos->x) + w) - 20.0f;
    q.y0 = -1.0f + pos->y;
    q.x1 = 20.0f + q.x0;
    q.y1 = 9.0f + q.y0;
    q.u0 = 0.41015625f;
    q.v0 = 0.93359375f;
    q.u1 = 0.48828125f;
    q.v1 = 0.96875f;
    if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
}

void TUnk_804CF930::draw_status_gauge_bar(void *ctx, void *pos_arg, f32 depth, f32 len) {
    Gauge_80256E0C *self = (Gauge_80256E0C *)this;
    Pos_80256E0C *pos = (Pos_80256E0C *)pos_arg;
    Quad_80256E0C q;
    f32 w;
    f32 end;
    if (len <= 0.0f) {
        return;
    }
    if (len < 4.0f) {
        w = len;
    } else {
        w = 4.0f;
    }
    q.x0 = pos->x;
    q.y0 = pos->y;
    q.x1 = pos->x + w;
    q.y1 = 7.0f + pos->y;
    q.u0 = 0.8984375f;
    q.v0 = 0.1171875f;
    q.u1 = (230.0f + w) / 256.0f;
    q.v1 = 0.14453125f;
    if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
    if (len <= 4.0f) {
        return;
    }
    w = (len < self->max - 4.0f) ? len - 4.0f : self->max - 8.0f;
    q.x0 = 4.0f + pos->x;
    q.y0 = pos->y;
    q.x1 = q.x0 + w;
    q.y1 = 7.0f + pos->y;
    q.u0 = 0.92578125f;
    q.v0 = 0.1171875f;
    q.u1 = 0.97265625f;
    q.v1 = 0.14453125f;
    if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
    end = self->max - 4.0f;
    if (len <= end) {
        return;
    }
    w = len - end;
    q.x0 = pos->x + end;
    q.y0 = pos->y;
    q.x1 = w + q.x0;
    q.y1 = 7.0f + pos->y;
    q.u0 = 0.984375f;
    q.v0 = 0.1171875f;
    q.u1 = (252.0f + w) / 256.0f;
    q.v1 = 0.14453125f;
    if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
}

void step_gauge_bar_width(Gauge_802571B4 *g) {
    f32 target;
    f32 diff;
    g->flags &= ~4;
    if (g->max <= lbl_805DCE58 || g->val <= lbl_805DCE58) {
        target = 0.0f;
    } else {
        target = (g->val * g->scale) / g->max;
    }
    diff = target - g->cur;
    if (fabs_float(diff) < lbl_805DCECC) {
        g->cur = target;
        g->flags |= 4;
    } else if (diff > lbl_805DCE58) {
        g->cur += lbl_805DCECC;
    } else {
        g->cur -= lbl_805DCECC;
    }
}

void *TWindowSubStatusDisp__sub_80257298(void *arg0, s16 arg1);
#define destroy__13TUnk_804CF930Fs ((s32 (*)(void *, s16))destroy__13TUnk_804CF930Fs)

extern s32 lbl_804CF930[];

void *TWindowSubStatusDisp__sub_80257298(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 4) = lbl_804CF930;
        destroy__13TUnk_804CF930Fs(arg0, 0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

#undef destroy__13TUnk_804CF930Fs

#define draw_status_gauge_bar__13TUnk_804CF930FPvPvff ((s32 (*)(void *, void *, void *, f32, f32))draw_status_gauge_bar__13TUnk_804CF930FPvPvff)
struct RecoveredGlobal_80257B4C_lbl_804CF948 {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_80257B4C_lbl_804CF948_size[sizeof(RecoveredGlobal_80257B4C_lbl_804CF948) == 0x18 ? 1 : -1];

typedef void *(*Ctor_80257D44)(void *, void *, s32);

#define destroy__13TUnk_804CF930Fs ((s32 (*)(s32, s32 *))destroy__13TUnk_804CF930Fs)
#define sub_80256BDC__13TUnk_804CF930Fs ((int (*)(void*, int))sub_80256BDC__13TUnk_804CF930Fs)
#define calc_bar_width__20TWindowSubStatusDispFPv ((s32 (*)())calc_bar_width__20TWindowSubStatusDispFPv)
#define step_gauge_bar_width ((void (*)(void *))step_gauge_bar_width)

#define lbl_804CF930 (*(unsigned char (*)[1])&lbl_804CF930)
extern const float lbl_805DCE58;

void*TUnk_804CF930::init_from(void*a1, int a2) { sub_80256BDC__13TUnk_804CF930Fs(this, a2); *(int*)((char*)this + 0x4) = (int)lbl_804CF930; *(float*)((char*)this + 0x1c) = lbl_805DCE58; *(float*)((char*)this + 0xc) = *(float*)((char*)a1 + 0x4); *(float*)((char*)this + 0x10) = *(float*)((char*)a1 + 0x8); *(float*)((char*)this + 0x8) = *(float*)((char*)a1 + 0xc); *(float*)((char*)this + 0x14) = *(float*)((char*)a1 + 0x18); *(int*)((char*)this + 0x18) = *(int*)((char*)a1 + 0x10); *(short*)((char*)this + 0x0) = *(int*)((char*)a1 + 0x14); *(float*)((char*)this + 0x20) = *(float*)((char*)a1 + 0x1c); *(float*)((char*)this + 0x24) = *(float*)((char*)a1 + 0x20); return this; }

}

#undef draw_status_gauge_bar__13TUnk_804CF930FPvPvff
#undef destroy__13TUnk_804CF930Fs
#undef sub_80256BDC__13TUnk_804CF930Fs
#undef calc_bar_width__20TWindowSubStatusDispFPv
#undef step_gauge_bar_width
#undef lbl_804CF930
