#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowHelpItem_8025A60C.h"
#include "pso/system/memory.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#pragma readonly_strings on

struct StarUV { f32 u; f32 v; };


struct Item_8025A650 { u8 p0[8]; f32 x; f32 y; s32 count; };

extern "C" {
void render_item_rarity_stars(Item_8025A650 *item, WindowDrawContext *ctx);
}

extern const StarUV item_rarity_star_uv_table[4] = {
    { 0.0f, 239.0f }, { 17.0f, 239.0f }, { 34.0f, 239.0f }, { 51.0f, 239.0f },
};

void *lbl_804CFA10[6] = {
    0, 0,
    (void *)TWindowHelpItem__sub_8025A904,
    (void *)TWindowHelpItem__sub_8025A900,
    (void *)render_item_rarity_stars,
    0,
};

f32 get_item_star_row_width(u8 *row) {
    s32 count;
    count = ((Item_8025A650 *)row)->count;
    if (count < 0xA) {
        count = 0xA;
    }
    return 17.0f * (f32) count;
}

void render_item_rarity_stars(Item_8025A650 *item, WindowDrawContext *ctx) {
    TexturedQuad q;
    f32 depth2;
    f32 x;
    f32 y;
    s32 i;
    s32 n;
    const StarUV *uv;
    f32 depth;
    if (ctx->open_tick < 0) {
        return;
    }
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(1, -1);
    x = ctx->inner_x + item->x;
    y = ctx->inner_y + item->y;
    depth = -1.0f / (0.1196f + ctx->depth);
    for (i = 0; i < item->count; i++) {
        if (i < 9) {
            uv = &item_rarity_star_uv_table[1];
        } else {
            uv = &item_rarity_star_uv_table[2];
        }
        q.x0 = x;
        q.y0 = y;
        q.x1 = 16.0f + x;
        q.y1 = 16.0f + y;
        q.u0 = uv->u / 256.0f;
        q.v0 = uv->v / 256.0f;
        q.u1 = (16.0f + uv->u) / 256.0f;
        q.v1 = (16.0f + uv->v) / 256.0f;
        if (ctx->clip_and_transform_quad(&q) != 0) {
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
        x += 17.0f;
    }
    uv = item_rarity_star_uv_table;
    x = ctx->inner_x + item->x;
    y = ctx->inner_y + item->y;
    depth2 = -1.0f / (0.0897f + ctx->depth);
    n = item->count;
    if (n < 10) {
        n = 10;
    }
    for (i = 0; i < n; i++) {
        q.x0 = x;
        q.y0 = y;
        q.x1 = 16.0f + x;
        q.y1 = 16.0f + y;
        q.u0 = uv->u / 256.0f;
        q.v0 = uv->v / 256.0f;
        q.u1 = (16.0f + uv->u) / 256.0f;
        q.v1 = (16.0f + uv->v) / 256.0f;
        if (ctx->clip_and_transform_quad(&q) != 0) {
            draw_textured_quad_at_depth((f32 *)&q, depth2);
        }
        x += 17.0f;
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}

void TWindowHelpItem__sub_8025A900(void) {  }

void *TWindowHelpItem__sub_8025A904(void *row, s16 flags) {
    if (row != NULL) {
        *(void ***)((s8 *)row + 4) = lbl_804CFA10;
        __dt__18TWindowLayoutEntryFv(row, 0);
        if (flags > 0) {
            ::operator delete(row);
        }
    }
    return row;
}

u8 *TWindowHelpItem__sub_8025A95C(u8 *row, saddr rec, s32 client) {
    __ct__18TWindowLayoutEntryFl(row, client);
    *(s32 **)((s8 *)row + 4) = ((s32 *)&lbl_804CFA10);
    copy_vec2((row + 8), (void *)(rec + 4));
    ((Item_8025A650 *)row)->count = 0;
    return row;
}
