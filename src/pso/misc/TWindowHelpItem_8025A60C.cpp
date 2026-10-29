#include "types.h"
#include "pso/misc/TWindowHelpItem_8025A60C.h"
#include "pso/system/memory.h"
#include "pso/misc/TUnk_804CF930.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#pragma readonly_strings on

struct RecoveredGlobal_8025A95C_lbl_804CFA10 {
    s32 value;
    u8 remaining[0x14];
};

struct UV_8025A650 { f32 u; f32 v; };

struct Quad_8025A650 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct Item_8025A650 { u8 p0[8]; f32 x; f32 y; s32 count; };

struct Ctx_8025A650 { u8 p0[0x10]; f32 x; f32 y; u8 p18[0x18]; s32 f30; u8 p34[4]; f32 z; };

f32 get_item_star_row_width(u8 *arg0);
extern "C" {
s32 sub_80256BDC__13TUnk_804CF930Fs(void *, void *);
s32 try_open__19TWindowKeyBoardSoftFii(void *, void *);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern s32 lbl_805D63F0;
void render_item_rarity_stars(Item_8025A650 *item, Ctx_8025A650 *ctx);
}

extern const UV_8025A650 item_rarity_star_uv_table[4] = {
    { 0.0f, 239.0f }, { 17.0f, 239.0f }, { 34.0f, 239.0f }, { 51.0f, 239.0f },
};

void *lbl_804CFA10[6] = {
    0, 0,
    (void *)TWindowHelpItem__sub_8025A904,
    (void *)TWindowHelpItem__sub_8025A900,
    (void *)render_item_rarity_stars,
    0,
};

f32 get_item_star_row_width(u8 *arg0) {
    s32 var_r0;
    var_r0 = *(s32 *)((s8 *)arg0 + 0x10);
    if (var_r0 < 0xA) {
        var_r0 = 0xA;
    }
    return 17.0f * (f32) var_r0;
}

void render_item_rarity_stars(Item_8025A650 *item, Ctx_8025A650 *ctx) {
    Quad_8025A650 q;
    f32 depth2;
    f32 x;
    f32 y;
    s32 i;
    s32 n;
    const UV_8025A650 *uv;
    f32 depth;
    if (ctx->f30 < 0) {
        return;
    }
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(1, -1);
    x = ctx->x + item->x;
    y = ctx->y + item->y;
    depth = -1.0f / (0.1196f + ctx->z);
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
        if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
        x += 17.0f;
    }
    uv = item_rarity_star_uv_table;
    x = ctx->x + item->x;
    y = ctx->y + item->y;
    depth2 = -1.0f / (0.0897f + ctx->z);
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
        if (try_open__19TWindowKeyBoardSoftFii(ctx, &q) != 0) {
            draw_textured_quad_at_depth((f32 *)&q, depth2);
        }
        x += 17.0f;
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}

void TWindowHelpItem__sub_8025A900(void) {  }

void *TWindowHelpItem__sub_8025A904(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((s8 *)arg0 + 4) = lbl_804CFA10;
        ((TUnk_804CF930 *)arg0)->destroy((s16)(0));
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8025A95C_lbl_804CFA10_size[sizeof(RecoveredGlobal_8025A95C_lbl_804CFA10) == 0x18 ? 1 : -1];
u8 *TWindowHelpItem__sub_8025A95C(u8 *arg0, s32 arg1, s32 arg2) {
    sub_80256BDC__13TUnk_804CF930Fs((void *)arg0, (void *)arg2);
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_8025A95C_lbl_804CFA10 *)&lbl_804CFA10).value;
    ((TWindowSubSymbolChatPartsSet *)(arg0 + 8))->copy_vec2((void *)(arg1 + 4));
    *(s32 *)((s8 *)arg0 + 0x10) = 0;
    return arg0;
}
