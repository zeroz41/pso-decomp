#include "pso/ui/window/TWindowBase.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/HelpItemRarityStarRow.h"
#include "pso/system/memory.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#pragma readonly_strings on

extern const StarUV item_rarity_star_uv_table[4] = {
    { 0.0f, 239.0f }, { 17.0f, 239.0f }, { 34.0f, 239.0f }, { 51.0f, 239.0f },
};

f32 HelpItemRarityStarRow::get_item_star_row_width() {
    s32 slots;

    slots = stars;
    if (slots < 10) {
        slots = 10;
    }
    return 17.0f * (f32)slots;
}

void HelpItemRarityStarRow::render(WindowDrawContext *context) {
    TexturedQuad q;
    f32 depth2;
    f32 x;
    f32 y;
    s32 i;
    s32 n;
    const StarUV *uv;
    f32 depth;
    if (context->open_tick < 0) {
        return;
    }
    set_additive_blend();
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(1, -1);
    x = context->inner_x + pos[0];
    y = context->inner_y + pos[1];
    depth = -1.0f / (0.1196f + context->depth);
    for (i = 0; i < stars; i++) {
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
        if (context->clip_and_transform_quad(&q) != 0) {
            draw_textured_quad_at_depth(&q.x0, depth);
        }
        x += 17.0f;
    }
    uv = item_rarity_star_uv_table;
    x = context->inner_x + pos[0];
    y = context->inner_y + pos[1];
    depth2 = -1.0f / (0.0897f + context->depth);
    n = stars;
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
        if (context->clip_and_transform_quad(&q) != 0) {
            draw_textured_quad_at_depth(&q.x0, depth2);
        }
        x += 17.0f;
    }
    end_screen_draw();
    set_default_alpha_blend();
}

void HelpItemRarityStarRow::update() {}

HelpItemRarityStarRow::~HelpItemRarityStarRow() {}

HelpItemRarityStarRow::HelpItemRarityStarRow(PointLayoutRecord *rec, s32 client) : TWindowLayoutEntry(client) {
    copy_vec2(pos, rec->pos);
    stars = 0;
}
