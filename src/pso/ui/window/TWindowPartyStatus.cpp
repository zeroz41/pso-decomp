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


#pragma readonly_strings on


const char *TWindowPartyStatus__name = "TWindowPartyStatus";

struct Stack_8030C0C4 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
};

extern "C" {
s32 TWindowSubComCard__sub_802452DC(int);
s32 TWindowSubComCard__sub_80245320(void *, void *);
s32 TWindowSubComCard__sub_802454E4(int);
saddr get_window_layout_position(int);
s32 TWindowSimpleStatus__ct(void *, int, void *, void *);
extern s32 __vt__18TWindowPartyStatus[];
extern s32 local_client_id;
s32 update_lockon_window();
}
void update_status_help_item(saddr arg0);

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

void TWindowPartyStatus::draw() { ((TWindowSubStatusDisp *)this)->update_hp_entry(); ((TWindowSubStatusDisp *)this)->update_status_entry(); }

void TWindowPartyStatus::draw_background(u8 *ctx) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_8030C0C4, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_8030C0C4, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_8030C0C4, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_8030C0C4, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_8030C0C4, sp18) == 0x10);
    LAYOUT_ASSERT(sp1C_offset, offsetof(Stack_8030C0C4, sp1C) == 0x14);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_8030C0C4, sp20) == 0x18);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_8030C0C4, sp24) == 0x1C);
    Stack_8030C0C4 stack;
    f32 temp_f2;
    f32 depth;
    f32 temp_f6;
    depth = -1.0f / this->draw_depth;
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xB, (*(s32 *)((s8 *)ctx + 0x34)));
    temp_f2 = *(f32 *)((s8 *)ctx + 0x10);
    stack.sp8 = temp_f2;
    temp_f6 = *(f32 *)((s8 *)ctx + 0x14);
    stack.spC = temp_f6;
    stack.sp10 = 114.0f + temp_f2;
    stack.sp14 = 46.0f + temp_f6;
    stack.sp18 = 0.0f;
    stack.sp1C = 0.703125f;
    stack.sp20 = 0.4453125f;
    stack.sp24 = 0.8828125f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&stack.sp8);
    draw_textured_quad_at_depth((&stack.sp8), depth);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(ctx, ctx + 0x10, ctx + 0x18) != 0) {
        TWindowSubComCard__sub_802454E4(0xB);
        TWindowSubComCard__sub_80245320(&stack.sp8, ctx);
        TWindowSubComCard__sub_802452DC(0xB);
    }
}
extern "C" {

void TWindowPartyStatus::render() {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    draw_background((u8 *)ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        reinterpret_cast<WindowDrawContext *>(ctx));
}
}

void TWindowPartyStatus::run_task() {
    saddr arg0 = (saddr)this;
    update_lockon_window();
    draw();
    update_status_help_item((arg0));
    ((TWindowSimpleStatus *)arg0)->update_status_icons((void *)(get_window_layout_position(0xAC)));
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((void *)(arg0 + 0x24)));
    ((TWindowSimpleStatus *)arg0)->apply_random_shake();
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
