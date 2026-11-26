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


const char *TWindowPartyStatus::class_name = "TWindowPartyStatus";



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

void TWindowPartyStatus::draw_background(WindowDrawContext *context) {
    TexturedQuad quad;
    f32 depth;
    depth = -1.0f / this->draw_depth;
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xB, context->color);
    quad.x0 = context->inner_x;
    quad.y0 = context->inner_y;
    quad.x1 = 114.0f + quad.x0;
    quad.y1 = 46.0f + quad.y0;
    quad.u0 = 0.0f;
    quad.v0 = 0.703125f;
    quad.u1 = 0.4453125f;
    quad.v1 = 0.8828125f;
    context->transform_quad(&quad);
    draw_textured_quad_at_depth((f32 *)&quad, depth);
    end_screen_draw();
    if (TWindowSubComCard__sub_80245558(context, &context->inner_x, &context->inner_w) != 0) {
        begin_window_sweep_draw(0xB);
        draw_window_sweep_strip(&quad, context);
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
    update_lockon_window(this);
    draw();
    update_status_help_item(this);
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
    m_name = TWindowPartyStatus::class_name;
    client_index = (s16)slot;
}


#pragma push
#pragma opt_propagation off
void *create_party_status_window(s32 slot_offset) {
    s32 n = slot_offset + 1;
    s32 g = local_client_id;
    u32 slot = (u32)(g + n) & 3;
    return new TWindowPartyStatus(slot, (u8 *)&party_status_window_params);
}
#pragma pop
