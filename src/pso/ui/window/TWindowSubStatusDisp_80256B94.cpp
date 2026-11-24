#pragma defer_codegen on

#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80256B94.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/player/TObjPlayer_80011014.h"


extern "C" {
void TWindowSubStatusDisp__sub_80256C40(TWindowStatusGauge *self, WindowDrawContext *ctx, NJS_POINT2 *pos, f32 depth);
TWindowStatusGauge::TWindowStatusGauge(StatusGaugeLayout *source, s32 client)
    : TWindowLayoutEntry(client) {
    width = 0.0f;
    x = source->pos[0];
    y = source->pos[1];
    depth = source->depth;
    scale = source->scale;
    color = source->color;
    flags = (u16)source->flags;
    maximum = source->maximum;
    target = source->target;
}

TWindowStatusGauge::~TWindowStatusGauge() {}

void TWindowStatusGauge::update() {
    f32 goal;
    f32 diff;
    flags &= ~4;
    if (maximum <= 0.0f || target <= 0.0f) {
        goal = 0.0f;
    } else {
        goal = (target * scale) / maximum;
    }
    diff = goal - width;
    if (fabs_float(diff) < 2.0f) {
        width = goal;
        flags |= 4;
    } else if (diff > 0.0f) {
        width += 2.0f;
    } else {
        width -= 2.0f;
    }
}

void TWindowStatusGauge::render(WindowDrawContext *ctx) {
    NJS_POINT2 pos;
    f32 depth;
    f32 len;
    f32 width;
    f32 used = this->y / 21.0f + this->x / ctx->inner_w;
    used *= 7.5f;
    f32 avail = 17.0f * ((f32)ctx->open_tick - used);
    if (avail <= 0.0f) {
        return;
    }
    width = this->width;
    if (width <= 0.0f && !(this->flags & 8)) {
        return;
    }
    if (width > avail) {
        len = avail;
    } else {
        len = width;
    }
    pos.x = ctx->inner_x + this->x;
    pos.y = ctx->inner_y + this->y;
    depth = -1.0f / (0.299f * this->depth + ctx->depth);
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(11, -1);
    if (this->flags & 8) {
        TWindowSubStatusDisp__sub_80256C40(this, ctx, &pos, depth);
    }
    if (avail > 0.0f) {
        set_constant_material_color(this->color);
        this->draw_status_gauge_bar(ctx, &pos, depth, len);
    }
    TWindowSubStatusDisp::get_player();
}

void TWindowStatusGauge::draw_status_gauge_bar(WindowDrawContext *ctx, NJS_POINT2 *pos, f32 depth, f32 len) {
    TexturedQuad q;
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
    if (ctx->clip_and_transform_quad(&q) != 0) {
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
    if (ctx->clip_and_transform_quad(&q) != 0) {
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
    if (ctx->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
}

void TWindowSubStatusDisp__sub_80256C40(TWindowStatusGauge *self, WindowDrawContext *ctx, NJS_POINT2 *pos, f32 depth) {
    TexturedQuad q;
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
    if (ctx->clip_and_transform_quad(&q) != 0) {
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
    if (ctx->clip_and_transform_quad(&q) != 0) {
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
    if (ctx->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, depth);
    }
}

void TWindowStatusGauge::calc_bar_width() {
    f32 target;
    f32 max = maximum;
    f32 v;
    if (max <= 0.0f || (target = this->target) <= 0.0f) {
        v = 0.0f;
    } else {
        v = (target * this->scale) / max;
    }
    this->width = v;
}

void TWindowLayoutEntry::render(WindowDrawContext *) {  }

void TWindowLayoutEntry::update() {}

TWindowLayoutEntry::TWindowLayoutEntry(s32 client) {
    this->flags = 0;
    this->client = client;
}

TWindowLayoutEntry::~TWindowLayoutEntry() {}
}
