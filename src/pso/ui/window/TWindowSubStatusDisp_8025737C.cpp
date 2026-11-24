#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "types.h"
#include "pso/render/ColorCopy.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/unk/TWindowStatusGaugeFeedback.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80226070.h"


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

extern "C" {
extern const f32 lbl_805DCE58;
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

extern "C" {
s32 TWindowSubStatusDisp__sub_80256C40(void *, void *, void *, f32);
s32 begin_screen_draw(s32, f32, f32, f32);
void set_draw_texture_and_color(s32 idx, s32 color);
}
void set_constant_material_color(u32 x);
extern "C" {
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

u32 update_text_color_transition(Fade_802575C0 *fade);
void start_text_color_transition(Fade_802575C0 *array_entry, u32 rgb, f32 time);

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

void start_text_color_transition(Fade_802575C0 *array_entry, u32 rgb, f32 time) {
    Col_802575C0 c;
    if (array_entry->rgb != rgb) {
        array_entry->rgb = rgb;
        c.r = rgb >> 16;
        c.g = rgb >> 8;
        c.b = rgb;
        array_entry->tr = c.r;
        array_entry->tg = c.g;
        array_entry->tb = c.b;
        copy4(&c, &array_entry->col);
        time = 1.0f / time;
        array_entry->cr = c.r;
        array_entry->cg = c.g;
        array_entry->cb = c.b;
        array_entry->dr = time * (array_entry->tr - array_entry->cr);
        array_entry->dg = time * (array_entry->tg - array_entry->cg);
        array_entry->db = time * (array_entry->tb - array_entry->cb);
        array_entry->flags |= 0x40;
    }
}
}

#pragma push
#pragma scheduling off
void copy4(void *destination, const void *source) {
    u8 *dst = static_cast<u8 *>(destination);
    const u8 *src = static_cast<const u8 *>(source);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}
#pragma pop

void TWindowStatusGaugeFeedback::calc_bar_width() {
    TWindowStatusGauge::calc_bar_width();
    shown = (s16)target;
}

#pragma push
#pragma fp_contract on
#define self ((Gauge_80257784 *)this)
#define parent ((Parent_80257784 *)context)
void TWindowStatusGaugeFeedback::render(WindowDrawContext *context) {
    NJS_POINT2 pos;
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
        TObjFish::set_global_param(hud_texlist);
        set_draw_texture_and_color(0xB, -1);
        if (self->flags & 8) {
            TWindowSubStatusDisp__sub_80256C40(self, parent, &pos, scale);
        }
        if (hi > 0.0f) {
            set_constant_material_color(col);
            ((TWindowStatusGauge *)self)->draw_status_gauge_bar(context, &pos, scale, hi);
            set_constant_material_color(self->f18);
            ((TWindowStatusGauge *)self)->draw_status_gauge_bar(context, &pos, scale, lo);
        }
        TWindowSubStatusDisp::get_player();
    }
}
#undef self
#undef parent
#pragma pop

void TWindowStatusGaugeFeedback::update() {
    Bar_8025799C *bar = (Bar_8025799C *)this;
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
            set_sound_pitch_request(slot, -0x100, 0);
        }
    } else {
        TWindowStatusGauge::update();
    }
}

TWindowStatusGaugeFeedback::~TWindowStatusGaugeFeedback() {}

TWindowStatusGaugeFeedback::TWindowStatusGaugeFeedback(LayoutEntryCopyRecord *source, s32 client)
    : TWindowStatusGauge(&source->gauge, client) {
    shown = (s16)target;
    rising_color = source->color_rising;
    falling_color = source->color_falling;
    m_2c = color;
    timer = 0;
}

