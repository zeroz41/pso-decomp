#include "types.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/memory.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"

extern "C" {
void draw_window_uv_sprite_part(WindowSpritePart *sprite, WindowDrawContext *context);
}

void *window_uv_sprite_part_vtable[6] = {
    0, 0,
    (void *)TWindowSubStatusDisp__sub_8025B2DC,
    (void *)TWindowSubStatusDisp::update_palette_sprite,
    (void *)draw_window_uv_sprite_part,
    0,
};

void swap_sprite_v_edges(WindowSpritePart *sprite) {
    f32 v = sprite->v0;
    sprite->v0 = sprite->v1;
    sprite->v1 = v;
}

void swap_sprite_u_edges(WindowSpritePart *sprite) {
    f32 u = sprite->u0;
    sprite->u0 = sprite->u1;
    sprite->u1 = u;
}

void set_sprite_uv_bounds(WindowSpritePart *sprite, f32 u0, f32 v0, f32 u1, f32 v1) {
    sprite->u0 = u0;
    sprite->v0 = v0;
    sprite->u1 = u1;
    sprite->v1 = v1;
}

void set_sprite_uv_from_pixels(WindowSpritePart *sprite, f32 x, f32 y) {
    sprite->u0 = x / 256.0f;
    sprite->v0 = y / 256.0f;
    sprite->u1 = (x + sprite->w) / 256.0f;
    sprite->v1 = (y + sprite->h) / 256.0f;
}

void set_sprite_dimensions(WindowSpritePart *sprite, f32 width, f32 height) {
    sprite->w = width;
    sprite->h = height;
}

#pragma push
#pragma fp_contract on

void draw_window_uv_sprite_part(WindowSpritePart *sprite, WindowDrawContext *context) {
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
    x = context->inner_x + sprite->x;
    y = context->inner_y + sprite->y;
    scale = (-1.0f) / ((0.299f) * sprite->depth + context->depth);
    a = sprite->y / (21.0f);
    t = a + sprite->x / context->inner_w;
    t *= (7.5f);
    len = (17.0f) * ((f32)context->open_tick - t);
    len /= (3.5f) * sprite->w;
    if (len <= (0.0f)) {
        return;
    }
    if (len > (0.5f)) {
        len = (0.5f);
    }
    if (sprite->flags & 8) {
        set_additive_blend();
    }
    if (sprite->flags & 0xC) {
        begin_screen_draw(1);
    } else {
        begin_screen_draw(0);
    }
    TObjFish::set_global_param(*sprite->texture_list_slot);
    set_draw_texture_and_color(sprite->kind, sprite->color);
    w = sprite->w;
    lo = (0.5f) - len;
    hi = (0.5f) + len;
    q.x0 = w * lo + x;
    q.y0 = sprite->h * lo + y;
    q.x1 = w * hi + x;
    q.y1 = sprite->h * hi + y;
    q.u0 = sprite->u0;
    q.v0 = sprite->v0;
    q.u1 = sprite->u1;
    q.v1 = sprite->v1;
    if (sprite->flags & 0x10) {
        context->transform_quad(&q);
        draw_textured_quad_at_depth((f32 *)&q, scale);
    } else if (context->clip_and_transform_quad(&q) != 0) {
        draw_textured_quad_at_depth((f32 *)&q, scale);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TWindowSubStatusDisp::update_palette_sprite() {  }

void *TWindowSubStatusDisp__sub_8025B2DC(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 4) = window_uv_sprite_part_vtable;
        __dt__18TWindowLayoutEntryFv(arg0, 0);
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

WindowSpritePart *WindowSpritePart::init_part_direct(DirectSpritePartLayoutRecord *source, s32 client) {
    __ct__18TWindowLayoutEntryFl(this, client);
    *reinterpret_cast<void ***>(reinterpret_cast<u8 *>(this) + 4) = window_uv_sprite_part_vtable;
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
    return this;
}

WindowSpritePart *WindowSpritePart::init_part_scaled(SpritePartLayoutRecord *source, s32 client) {
    __ct__18TWindowLayoutEntryFl(this, client);
    *reinterpret_cast<void ***>(reinterpret_cast<u8 *>(this) + 4) = window_uv_sprite_part_vtable;
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
    return this;
}
