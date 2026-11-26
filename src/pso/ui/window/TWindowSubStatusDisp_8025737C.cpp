#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/render/ColorCopy.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/unk/TWindowStatusGaugeFeedback.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"


extern "C" {
s32 TWindowSubStatusDisp__sub_80256C40(void *, void *, void *, f32);
}
void set_constant_material_color(u32 x);
extern "C" {
extern const float lbl_805DCE58;

#define CLAMP_8025737C(v, lo, hi) ((v) < (lo) ? (lo) : ((v) < (hi) ? (v) : (hi)))

}

// The four bytes of a colour as copy4 stores them into TWindowStatusGauge::color.
struct ColorBytes { u8 r, g, b, a; };

u32 TWindowStatusGaugeFeedback::update_text_color_transition() {
    s32 done = 1;
    if (fade_current.r < fade_target.r) {
        f32 v = fade_current.r + fade_step.r;
        fade_current.r = CLAMP_8025737C(v, 0.0f, fade_target.r);
        if (fade_current.r < fade_target.r) {
            done = 0;
        }
    } else {
        f32 v = fade_current.r + fade_step.r;
        fade_current.r = CLAMP_8025737C(v, fade_target.r, 255.0f);
        if (fade_current.r > fade_target.r) {
            done = 0;
        }
    }
    if (fade_current.g < fade_target.g) {
        f32 v = fade_current.g + fade_step.g;
        fade_current.g = CLAMP_8025737C(v, 0.0f, fade_target.g);
        if (fade_current.g < fade_target.g) {
            done = 0;
        }
    } else {
        f32 v = fade_current.g + fade_step.g;
        fade_current.g = CLAMP_8025737C(v, fade_target.g, 255.0f);
        if (fade_current.g > fade_target.g) {
            done = 0;
        }
    }
    if (fade_current.b < fade_target.b) {
        f32 v = fade_current.b + fade_step.b;
        fade_current.b = CLAMP_8025737C(v, 0.0f, fade_target.b);
        if (fade_current.b < fade_target.b) {
            done = 0;
        }
    } else {
        f32 v = fade_current.b + fade_step.b;
        fade_current.b = CLAMP_8025737C(v, fade_target.b, 255.0f);
        if (fade_current.b > fade_target.b) {
            done = 0;
        }
    }
    if (done) {
        flags &= ~0x40;
        return goal_color;
    }
    {
        u32 argb = 0xFF00;
        argb |= (u8)fade_current.r;
        argb <<= 8;
        argb |= (u8)fade_current.g;
        argb <<= 8;
        argb |= (u8)fade_current.b;
        return argb;
    }
}

void TWindowStatusGaugeFeedback::start_text_color_transition(u32 rgb, f32 time) {
    ColorBytes c;
    if (goal_color != rgb) {
        goal_color = rgb;
        c.r = rgb >> 16;
        c.g = rgb >> 8;
        c.b = rgb;
        fade_target.r = c.r;
        fade_target.g = c.g;
        fade_target.b = c.b;
        copy4(&c, &color);
        time = 1.0f / time;
        fade_current.r = c.r;
        fade_current.g = c.g;
        fade_current.b = c.b;
        fade_step.r = time * (fade_target.r - fade_current.r);
        fade_step.g = time * (fade_target.g - fade_current.g);
        fade_step.b = time * (fade_target.b - fade_current.b);
        flags |= 0x40;
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
    used = this->y / 21.0f + this->x / context->inner_w;
    used *= 7.5f;
    avail = 17.0f * ((f32)context->open_tick - used);
    if (avail <= 0.0f) {
        return;
    }
    if (this->maximum <= 0.0f || this->target <= 0.0f) {
        ratio = 0.0f;
    } else {
        ratio = this->target * this->scale / this->maximum;
    }
    cur = this->width;
    if (cur <= ratio) {
        lo = cur;
        col = this->rising_color;
        hi = ratio;
    } else {
        hi = cur;
        col = this->falling_color;
        lo = ratio - 1.0f;
    }
    if (lo > avail) {
        lo = avail;
    }
    if (hi > avail) {
        hi = avail;
    }
    if (!(hi <= 0.0f) || (this->flags & 8)) {
        pos.x = context->inner_x + this->x;
        pos.y = context->inner_y + this->y;
        sz = this->depth;
        scale = -1.0f / (0.299f * sz + context->depth);
        begin_screen_draw(1);
        TObjFish::set_global_param(hud_texlist);
        set_draw_texture_and_color(0xB, -1);
        if (this->flags & 8) {
            TWindowSubStatusDisp__sub_80256C40(this, context, &pos, scale);
        }
        if (hi > 0.0f) {
            set_constant_material_color(col);
            draw_status_gauge_bar(context, &pos, scale, hi);
            set_constant_material_color(this->color);
            draw_status_gauge_bar(context, &pos, scale, lo);
        }
        end_screen_draw();
    }
}
#pragma pop

void TWindowStatusGaugeFeedback::update() {
    if (flags & 0x40) {
        color = update_text_color_transition();
    }
    if ((f32)shown != target) {
        f32 max = maximum;
        f32 cur = (f32)shown;
        f32 bar_width;
        if (max <= 0.0f || cur <= 0.0f) {
            bar_width = 0.0f;
        } else {
            bar_width = (cur * scale) / max;
        }
        width = bar_width;
        if ((flags & 0x20) && width > scale) {
            width = scale;
        }
        shown = (s16)target;
        timer = 36;
    }
    flags &= ~4;
    if (timer) {
        --timer;
        if (!timer && (flags & 0x10)) {
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
    goal_color = color;
    timer = 0;
}

