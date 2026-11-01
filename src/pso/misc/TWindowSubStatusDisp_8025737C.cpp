#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_8025737C.h"
#include "pso/system/memory.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/ui/TAdChrMoveEffectGC.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"


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

extern "C" {
void sub_80256BDC__13TUnk_804CF930Fs(u8 *arg0, s16 arg1);
void calc_bar_width__20TWindowSubStatusDispFPv(struct Bar_80256C00 *bar);
extern const f32 lbl_805DCE58;
void step_gauge_bar_width(Gauge_802571B4 *g);
void draw_status_gauge_bar__13TUnk_804CF930FPvPvff(Gauge_80256E0C *self, void *ctx, Pos_80256E0C *pos, f32 depth, f32 len);
void *destroy__13TUnk_804CF930Fs(void *arg0, s16 arg1);
void *TWindowSubStatusDisp__sub_80257298(void *arg0, s16 arg1);
}

struct Gauge_80257784 {
    u16 flags;
    u8 pad2[0x8 - 0x2];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    s32 f18;
    f32 f1C;
    f32 f20;
    f32 f24;
    u8 pad28[0x60 - 0x28];
    s32 f60;
    s32 f64;
};

struct Parent_80257784 {
    u8 pad0[0x10];
    f32 f10;
    f32 f14;
    f32 f18;
    u8 pad1C[0x30 - 0x1C];
    s32 f30;
    u8 pad34[0x38 - 0x34];
    f32 f38;
};

struct Pos_80257784 { f32 x, y; };

extern "C" {
s32 TWindowSubStatusDisp__sub_80256C40(void *, void *, void *, f32);
#define draw_status_gauge_bar__13TUnk_804CF930FPvPvff ((s32 (*)(void *, void *, void *, f32, f32))draw_status_gauge_bar__13TUnk_804CF930FPvPvff)
s32 begin_screen_draw(s32, f32, f32, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);
}
void set_constant_material_color(u32 x);
extern s32 lbl_805D63F0;
extern "C" {
void draw_gauge__20TWindowSubStatusDispFPvPv(Gauge_80257784 *self, Parent_80257784 *parent);
struct Col_802575C0 { u8 r, g, b, a; };

struct Fade_802575C0 {
    u16 flags;
    u8 pad2[0x16];
    Col_802575C0 col;
    u8 pad1c[0x2C - 0x1C];
    u32 rgb;
    u8 pad30[4];
    f32 tr, tg, tb;
    u8 pad40[4];
    f32 cr, cg, cb;
    u8 pad50[4];
    f32 dr, dg, db;
};

struct RecoveredGlobal_80257B4C_lbl_804CF948 {
    s32 value;
    u8 remaining[0x14];
};

typedef char RecoveredGlobal_80257B4C_lbl_804CF948_size[sizeof(RecoveredGlobal_80257B4C_lbl_804CF948) == 0x18 ? 1 : -1];

typedef void *(*Ctor_80257D44)(void *, void *, s32);

struct Bar_8025799C {
    u16 flags;
    u8 pad0[0x14 - 2];
    f32 width_max;
    u32 color18;
    f32 width;
    f32 max;
    f32 target;
    s16 shown;
    s16 timer;
};

void update_technique_slot__10TTecRaFoieFl(s32, s32, s32);
s32 play_sound_effect(u32, s32, s32, s32);
#define destroy__13TUnk_804CF930Fs ((s32 (*)(s32, s32 *))destroy__13TUnk_804CF930Fs)
#define sub_80256BDC__13TUnk_804CF930Fs ((int (*)(void*, int))sub_80256BDC__13TUnk_804CF930Fs)
#define calc_bar_width__20TWindowSubStatusDispFPv ((s32 (*)())calc_bar_width__20TWindowSubStatusDispFPv)
#define step_gauge_bar_width ((void (*)(void *))step_gauge_bar_width)
void* init_from__13TUnk_804CF930FPvi(void* a0, void* a1, int a2);
u32 update_text_color_transition(Fade_802575C0 *fade);
void start_text_color_transition(Fade_802575C0 *arg0, u32 rgb, f32 time);

#define lbl_804CF930 (*(unsigned char (*)[1])&lbl_804CF930)
extern s32 lbl_804CF948[];
extern const float lbl_805DCE58;

#define CLAMP_8025737C(v, lo, hi) ((v) < (lo) ? (lo) : ((v) < (hi) ? (v) : (hi)))

u32 update_text_color_transition(Fade_802575C0 *fade) {
    s32 done = 1;
    if (fade->cr < fade->tr) {
        f32 v = fade->cr + fade->dr;
        fade->cr = CLAMP_8025737C(v, 0.0f, fade->tr);
        if (fade->cr < fade->tr) {
            done = 0;
        }
    } else {
        f32 v = fade->cr + fade->dr;
        fade->cr = CLAMP_8025737C(v, fade->tr, 255.0f);
        if (fade->cr > fade->tr) {
            done = 0;
        }
    }
    if (fade->cg < fade->tg) {
        f32 v = fade->cg + fade->dg;
        fade->cg = CLAMP_8025737C(v, 0.0f, fade->tg);
        if (fade->cg < fade->tg) {
            done = 0;
        }
    } else {
        f32 v = fade->cg + fade->dg;
        fade->cg = CLAMP_8025737C(v, fade->tg, 255.0f);
        if (fade->cg > fade->tg) {
            done = 0;
        }
    }
    if (fade->cb < fade->tb) {
        f32 v = fade->cb + fade->db;
        fade->cb = CLAMP_8025737C(v, 0.0f, fade->tb);
        if (fade->cb < fade->tb) {
            done = 0;
        }
    } else {
        f32 v = fade->cb + fade->db;
        fade->cb = CLAMP_8025737C(v, fade->tb, 255.0f);
        if (fade->cb > fade->tb) {
            done = 0;
        }
    }
    if (done) {
        fade->flags &= ~0x40;
        return fade->rgb;
    }
    {
        u32 argb = 0xFF00;
        argb |= (u8)fade->cr;
        argb <<= 8;
        argb |= (u8)fade->cg;
        argb <<= 8;
        argb |= (u8)fade->cb;
        return argb;
    }
}

void start_text_color_transition(Fade_802575C0 *arg0, u32 rgb, f32 time) {
    Col_802575C0 c;
    if (arg0->rgb != rgb) {
        arg0->rgb = rgb;
        c.r = rgb >> 16;
        c.g = rgb >> 8;
        c.b = rgb;
        arg0->tr = c.r;
        arg0->tg = c.g;
        arg0->tb = c.b;
        ((TAdChrMoveEffectGC *)(&c))->copy4(&arg0->col);
        time = 1.0f / time;
        arg0->cr = c.r;
        arg0->cg = c.g;
        arg0->cb = c.b;
        arg0->dr = time * (arg0->tr - arg0->cr);
        arg0->dg = time * (arg0->tg - arg0->cg);
        arg0->db = time * (arg0->tb - arg0->cb);
        arg0->flags |= 0x40;
    }
}

void TAdChrMoveEffectGC::copy4(void* q) { *(u8 *)&this->m_name = *(u8*)((char*)q + 0x0); *(u8*)((char*)this + 0x1) = *(u8*)((char*)q + 0x1); *(u8*)((char*)this + 0x2) = *(u8*)((char*)q + 0x2); *(u8*)((char*)this + 0x3) = *(u8*)((char*)q + 0x3); }

void TWindowSubStatusDisp::update_disp_value() {
    calc_bar_width__20TWindowSubStatusDispFPv();
    *(s16 *)((s8 *)this + 0x28) = (s16) *(f32 *)&this->m_24;
}

#pragma push
#pragma fp_contract on
void draw_gauge__20TWindowSubStatusDispFPvPv(Gauge_80257784 *self, Parent_80257784 *parent) {
    Pos_80257784 pos;
    f32 scale;
    f32 lo;
    f32 hi;
    f32 used;
    f32 avail;
    f32 cur;
    f32 ratio;
    f32 sz;
    s32 col;
    used = self->f10 / 21.0f + self->fC / parent->f18;
    used *= 7.5f;
    avail = 17.0f * ((f32)parent->f30 - used);
    if (avail <= 0.0f) {
        return;
    }
    if (self->f20 <= 0.0f || self->f24 <= 0.0f) {
        ratio = 0.0f;
    } else {
        ratio = self->f24 * self->f14 / self->f20;
    }
    cur = self->f1C;
    if (cur <= ratio) {
        lo = cur;
        col = self->f60;
        hi = ratio;
    } else {
        hi = cur;
        col = self->f64;
        lo = ratio - 1.0f;
    }
    if (lo > avail) {
        lo = avail;
    }
    if (hi > avail) {
        hi = avail;
    }
    if (!(hi <= 0.0f) || (self->flags & 8)) {
        pos.x = parent->f10 + self->fC;
        pos.y = parent->f14 + self->f10;
        sz = self->f8;
        scale = -1.0f / (0.299f * sz + parent->f38);
        begin_screen_draw(1, sz, 0.299f, -1.0f);
        TObjFish::set_global_param(lbl_805D63F0);
        set_draw_texture_and_color(0xB, -1);
        if (self->flags & 8) {
            TWindowSubStatusDisp__sub_80256C40(self, parent, &pos, scale);
        }
        if (hi > 0.0f) {
            set_constant_material_color(col);
            draw_status_gauge_bar__13TUnk_804CF930FPvPvff(self, parent, &pos, scale, hi);
            set_constant_material_color(self->f18);
            draw_status_gauge_bar__13TUnk_804CF930FPvPvff(self, parent, &pos, scale, lo);
        }
        TWindowSubStatusDisp::get_player();
    }
}
#pragma pop

void update_status_gauge_hold(Bar_8025799C *bar) {
    if (bar->flags & 0x40) {
        bar->color18 = update_text_color_transition((Fade_802575C0 *)bar);
    }
    if ((f32)bar->shown != bar->target) {
        f32 max = bar->max;
        f32 cur = (f32)bar->shown;
        f32 width;
        if (max <= 0.0f || cur <= 0.0f) {
            width = 0.0f;
        } else {
            width = (cur * bar->width_max) / max;
        }
        bar->width = width;
        if ((bar->flags & 0x20) && bar->width > bar->width_max) {
            bar->width = bar->width_max;
        }
        bar->shown = (s16)bar->target;
        bar->timer = 36;
    }
    bar->flags &= ~4;
    if (bar->timer) {
        --bar->timer;
        if (!bar->timer && (bar->flags & 0x10)) {
            s32 slot = play_sound_effect(0x22825, 0, 0, 0);
            update_technique_slot__10TTecRaFoieFl(slot, -0x100, 0);
        }
    } else {
        step_gauge_bar_width(bar);
    }
}

void *TWindowSubStatusDisp__sub_80257AF4(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 4) = lbl_804CF948;
        TWindowSubStatusDisp__sub_80257298(arg0, 0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TWindowSubStatusDisp::init_layout_entry_copy(u8 *arg1) {
    ((s32 (*)(void))init_from__13TUnk_804CF930FPvi)();
    *(s32 * *)&this->m_flags = &(*(RecoveredGlobal_80257B4C_lbl_804CF948 *)&lbl_804CF948).value;
    *(s16 *)((s8 *)((u8 *)this) + 0x28) = (s16) *(f32 *)&this->m_24;
    *(s32 *)((s8 *)((u8 *)this) + 0x60) = (s32) *(s32 *)((s8 *)arg1 + 0x24);
    *(s32 *)((s8 *)((u8 *)this) + 0x64) = (s32) *(s32 *)((s8 *)arg1 + 0x28);
    this->m_2c = (s32) *(s32 *)((s8 *)((u8 *)this) + 0x18);
    this->m_2a = 0;
    return ((u8 *)this);
}
}

#undef draw_status_gauge_bar__13TUnk_804CF930FPvPvff
#undef destroy__13TUnk_804CF930Fs
#undef sub_80256BDC__13TUnk_804CF930Fs
#undef calc_bar_width__20TWindowSubStatusDispFPv
#undef step_gauge_bar_width
#undef lbl_804CF930
