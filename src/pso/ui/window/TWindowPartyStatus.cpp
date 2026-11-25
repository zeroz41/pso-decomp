#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowPartyStatus.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/ui/window/TWindowBase.h"

#include <stddef.h>

#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/text_8030C340.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowSubStatusDisp_8026F6DC.h"


#pragma readonly_strings on


const char *TWindowPartyStatus__name = "TWindowPartyStatus";



struct PartyStatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    TextLayoutRecord rec_4;
};

PartyStatusWindowLayout lbl_804E7750 = {
    5, 1,
    {6, {7.0f, 7.0f}, {34.0f, 29.0f}, 112.0f, 84.0f, 0.5f, -1, &hud_texlist, 0, 4},
    {3, {45.0f, 40.0f}, 0.5f, 0xFFFFFFFF, 4, NULL},
    {4, {100.0f, 19.0f}, 0.5f, 0xFFFFFFFF, 4, 1},
    {{2, {44.0f, 7.0f}, 0.5f, 0xFF00FF15, 0x20, 57.0f, 0, 0}, 0xFF00CA9E, 0xFFFF2924},
    {3, {48.0f, 19.0f}, 0.5f, 0xFFFFFFFF, 4, "Lv"},
};

WindowDescriptor party_status_window_params = {
    {114.0f, 46.0f}, 70100.0f, &lbl_804E7750, 0xB28,
};

void TWindowPartyStatus::draw() { update_hp_entry(); update_status_entry(); }

void TWindowPartyStatus::draw_background(WindowDrawContext *ctx) {
    TexturedQuad q;
    f32 depth;
    depth = -1.0f / this->draw_depth;
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xB, ctx->color);
    q.x0 = ctx->inner_x;
    q.y0 = ctx->inner_y;
    q.x1 = 114.0f + q.x0;
    q.y1 = 46.0f + q.y0;
    q.u0 = 0.0f;
    q.v0 = 0.703125f;
    q.u1 = 0.4453125f;
    q.v1 = 0.8828125f;
    ctx->transform_quad(&q);
    draw_textured_quad_at_depth((f32 *)&q, depth);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(ctx, &ctx->inner_x, &ctx->inner_w) != 0) {
        begin_window_sweep_draw(0xB);
        draw_window_sweep_strip(&q, ctx);
        end_window_sweep_draw(0xB);
    }
}

void TWindowPartyStatus::render() {
    WindowDrawContext *ctx;
    ctx = draw_default_entry();
    draw_background(ctx);
    draw_visible_window_entries(this, &this->entry_list, ctx);
}

void TWindowPartyStatus::run_task() {
    update_lockon_window((u8 *)this);
    draw();
    update_status_help_item((saddr)this);
    update_status_icons((void *)(get_window_layout_position(0xAC)));
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
    apply_random_shake();
}
TWindowPartyStatus::~TWindowPartyStatus() {

}

TWindowPartyStatus::TWindowPartyStatus(s32 slot, u8 *descriptor)
    : TWindowSimpleStatus((void *)get_window_layout_position(0xAB), local_client_id, descriptor) {
    m_name = TWindowPartyStatus__name;
    client_index = (s16)slot;
}


#pragma push
#pragma opt_propagation off
void *create_party_status_window(s32 arg0) {
    s32 n = arg0 + 1;
    s32 g = local_client_id;
    u32 slot = (u32)(g + n) & 3;
    return new TWindowPartyStatus(slot, (u8 *)&party_status_window_params);
}
#pragma pop
