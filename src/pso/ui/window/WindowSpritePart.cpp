#include "types.h"
#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowLayoutEntry.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"


void WindowSpritePart::swap_sprite_v_edges() {
    f32 v = this->v0;
    this->v0 = this->v1;
    this->v1 = v;
}

void WindowSpritePart::swap_sprite_u_edges() {
    f32 u = this->u0;
    this->u0 = this->u1;
    this->u1 = u;
}

void WindowSpritePart::set_sprite_uv_bounds(f32 u0, f32 v0, f32 u1, f32 v1) {
    this->u0 = u0;
    this->v0 = v0;
    this->u1 = u1;
    this->v1 = v1;
}

void WindowSpritePart::set_sprite_uv_from_pixels(f32 x, f32 y) {
    this->u0 = x / 256.0f;
    this->v0 = y / 256.0f;
    this->u1 = (x + this->w) / 256.0f;
    this->v1 = (y + this->h) / 256.0f;
}

void WindowSpritePart::set_sprite_dimensions(f32 width, f32 height) {
    this->w = width;
    this->h = height;
}

#pragma push
#pragma fp_contract on

void WindowSpritePart::render(WindowDrawContext *context) {
    TexturedQuad q;
    f32 x;
    f32 y;
    f32 scale;
    f32 len;
    f32 a;
    f32 t;
    f32 lo;
    f32 hi;
    f32 w;
    x = context->inner_x + this->x;
    y = context->inner_y + this->y;
    scale = (-1.0f) / ((0.299f) * this->depth + context->depth);
    a = this->y / (21.0f);
    t = a + this->x / context->inner_w;
    t *= (7.5f);
    len = (17.0f) * ((f32)context->open_tick - t);
    len /= (3.5f) * this->w;
    if (len <= (0.0f)) {
        return;
    }
    if (len > (0.5f)) {
        len = (0.5f);
    }
    if (this->flags & 8) {
        set_additive_blend();
    }
    if (this->flags & 0xC) {
        begin_screen_draw(1);
    } else {
        begin_screen_draw(0);
    }
    set_texture_list(*this->texture_list_slot);
    set_draw_texture_and_color(this->kind, this->color);
    w = this->w;
    lo = (0.5f) - len;
    hi = (0.5f) + len;
    q.x0 = w * lo + x;
    q.y0 = this->h * lo + y;
    q.x1 = w * hi + x;
    q.y1 = this->h * hi + y;
    q.u0 = this->u0;
    q.v0 = this->v0;
    q.u1 = this->u1;
    q.v1 = this->v1;
    if (this->flags & 0x10) {
        context->transform_quad(&q);
        draw_textured_quad_at_depth(&q.x0, scale);
    } else if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth(&q.x0, scale);
    }
    end_screen_draw();
    set_default_alpha_blend();
}
#pragma pop

void WindowSpritePart::update() {}

WindowSpritePart::~WindowSpritePart() {}

WindowSpritePart::WindowSpritePart(DirectSpritePartLayoutRecord *source, s32 client) : TWindowLayoutEntry(client) {
    copy_vec2(&x, source->pos);
    copy_vec2(&w, source->size);
    u0 = source->u0;
    v0 = source->v0;
    u1 = source->u1;
    v1 = source->v1;
    depth = source->depth;
    color = source->color;
    texture_list_slot = source->texture_list_slot;
    kind = source->texture;
    flags = (u16)source->flags;
}

WindowSpritePart::WindowSpritePart(SpritePartLayoutRecord *source, s32 client) : TWindowLayoutEntry(client) {
    copy_vec2(&x, source->pos);
    copy_vec2(&w, source->size);
    u0 = source->u / 256.0f;
    v0 = source->v / 256.0f;
    u1 = (source->u + w) / 256.0f;
    v1 = (source->v + h) / 256.0f;
    depth = source->depth;
    color = source->color;
    texture_list_slot = source->texture_list_slot;
    kind = source->texture;
    flags = (u16)source->flags;
}
