#include "types.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TUnk_804CF930.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

extern s32 lbl_805D63F0;

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


struct Pos_80256E0C { f32 x; f32 y; };

struct Quad_80256E0C { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

extern "C" {
extern s32 lbl_804CF918[];
void sub_80256BDC__13TUnk_804CF930Fl(void *self, s32 arg1);
void calc_bar_width__13TUnk_804CF930Fv(struct Bar_80256C00 *bar);
f32 fabs_float(f32);
void step_gauge_bar_width(Gauge_802571B4 *g);
s32 try_open__19TWindowKeyBoardSoftFii(void *, void *);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
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
void TUnk_804CF930::sub_80256BDC(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_80256BDC_lbl_804CF918 *)&lbl_804CF918).value;
    *(s16 *)((s8 *)arg0 + 0) = 0;
    this->m_2 = arg1;
}

void TWindowSubStatusDisp__sub_80256BF8(void) {  }
void TWindowSubStatusDisp__sub_80256BFC(void) {  }
void TUnk_804CF930::calc_bar_width() {
    f32 target;
    f32 max = ((struct Bar_80256C00 *)this)->max;
    f32 v;
    if (max <= 0.0f || (target = ((struct Bar_80256C00 *)this)->target) <= 0.0f) {
        v = 0.0f;
    } else {
        v = (target * ((struct Bar_80256C00 *)this)->scale) / max;
    }
    ((struct Bar_80256C00 *)this)->width = v;
}

void TWindowSubStatusDisp__sub_80256C40(TUnk_804CF930 *self, TWindowKeyBoardSoft *ctx, Pos_80256E0C *pos, f32 depth) {
    Quad_80256E0C q;
    f32 w;
    w = self->scale - -2.0f;
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
    w = (len < scale - 4.0f) ? len - 4.0f : scale - 8.0f;
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
    end = scale - 4.0f;
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

void TWindowSubStatusDisp__sub_80257024(TUnk_804CF930 *self, TWindowKeyBoardSoft *ctx) {
    Pos_80256E0C pos;
    f32 depth;
    f32 len;
    f32 width;
    f32 used = self->y / 21.0f + self->x / ctx->inner_w;
    used *= 7.5f;
    f32 avail = 17.0f * ((f32)ctx->open_tick - used);
    if (avail <= 0.0f) {
        return;
    }
    width = self->width;
    if (width <= 0.0f && !(self->flags & 8)) {
        return;
    }
    if (width > avail) {
        len = avail;
    } else {
        len = width;
    }
    pos.x = ctx->inner_x + self->x;
    pos.y = ctx->inner_y + self->y;
    depth = -1.0f / (0.299f * self->depth + ctx->depth);
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(11, -1);
    if (self->flags & 8) {
        TWindowSubStatusDisp__sub_80256C40(self, ctx, &pos, depth);
    }
    if (avail > 0.0f) {
        set_constant_material_color(self->color);
        self->draw_status_gauge_bar(ctx, &pos, depth, len);
    }
    TWindowSubStatusDisp::get_player();
}

void step_gauge_bar_width(Gauge_802571B4 *g) {
    f32 target;
    f32 diff;
    g->flags &= ~4;
    if (g->max <= 0.0f || g->val <= 0.0f) {
        target = 0.0f;
    } else {
        target = (g->val * g->scale) / g->max;
    }
    diff = target - g->cur;
    if (fabs_float(diff) < 2.0f) {
        g->cur = target;
        g->flags |= 4;
    } else if (diff > 0.0f) {
        g->cur += 2.0f;
    } else {
        g->cur -= 2.0f;
    }
}

void *TWindowSubStatusDisp__sub_80257298(void *arg0, s16 arg1);

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


struct RecoveredGlobal_80257B4C_lbl_804CF948 {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_80257B4C_lbl_804CF948_size[sizeof(RecoveredGlobal_80257B4C_lbl_804CF948) == 0x18 ? 1 : -1];

typedef void *(*Ctor_80257D44)(void *, void *, s32);



void*TUnk_804CF930::init_from(void*a1, int a2) { sub_80256BDC__13TUnk_804CF930Fl(this, a2); *(int*)((char*)this + 0x4) = (int)lbl_804CF930; *(float*)((char*)this + 0x1c) = 0.0f; *(float*)((char*)this + 0xc) = *(float*)((char*)a1 + 0x4); *(float*)((char*)this + 0x10) = *(float*)((char*)a1 + 0x8); *(float*)((char*)this + 0x8) = *(float*)((char*)a1 + 0xc); *(float*)((char*)this + 0x14) = *(float*)((char*)a1 + 0x18); *(int*)((char*)this + 0x18) = *(int*)((char*)a1 + 0x10); *(short*)((char*)this + 0x0) = *(int*)((char*)a1 + 0x14); *(float*)((char*)this + 0x20) = *(float*)((char*)a1 + 0x1c); *(float*)((char*)this + 0x24) = *(float*)((char*)a1 + 0x20); return this; }

}

