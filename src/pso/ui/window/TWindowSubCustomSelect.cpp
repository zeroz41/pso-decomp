#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

struct Ent_80277AEC { u16 id; u8 pad[0xA]; };

struct Sub_80277AEC { u8 pad[0x34]; s32 flags; };

struct Big_80277AEC { u8 pad[0x85C]; Sub_80277AEC sub; };

struct Ent_802776D0 { u16 id; u16 sub; };


// inferred: window_sub_custom_select_layout_entries, the layout table
// TWindowSubCustomSelect__window_settings points at (two sprite parts and a value entry).
struct SubCustomSelectWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
};
SubCustomSelectWindowLayout window_sub_custom_select_layout_entries = {
    3, 1,
    {6, {3.0f, 9.0f}, {56.0f, 47.0f}, 196.0f, 0.0f, 0.2f, -1, &hud_texlist, 1, 4},
    {6, {6.0f, 11.0f}, {50.0f, 43.0f}, 0.0f, 0.0f, 0.3f, -1, &hud_texlist, 3, 4},
    {4, {0.0f, 0.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
};
WindowDescriptor TWindowSubCustomSelect__window_settings = {
    {204.0f, 188.0f}, 50050.0f, &window_sub_custom_select_layout_entries, 0x43,
};

extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
void *reset_selection__20TWindowSubStatusDispFv(void *, NJS_POINT2 *);
const char *TWindowSubCustomSelect__class_name = "TWindowSubCustomSelect";
s32 can_use_palette_action__10TObjPlayerFPvUcUc(s32, u8, u8);

void TWindowSubCustomSelect::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_73 = (u8) (this->m_73 | 2);
    }
}

void TWindowSubCustomSelect::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_73 = (u8) (this->m_73 | 1);
    ((TWindowSubStatusDisp *)(this->m_7c))->set_entry_state(2);
}

#pragma fp_contract on
void TWindowSubCustomSelect::update_list_scroll() {
  u8 *arg0 = (u8 *) this;
  NJS_POINT2 range;
  f32 *new_var3;
  f32 tgt;
  float new_var2;
  new_var2 = (51.0f * ((f32) ((s8)this->m_71))) + 6.0f;
  tgt = 27.0f + new_var2;
  tgt -= 81.0f;
  new_var3 = &this->scroll_offset[1];
  *new_var3 = (*new_var3) + (tgt - (this->scroll_offset[1]));
  range.x = 0.0f;
  range.y = ((this->frame_size[1]) - 10.0f) - 16.0f;
  scroll_bar->clamp_offset(scroll_offset, &range);
}

void TWindowSubCustomSelect::handle_grid_navigation() {
    u8 temp_r3;
    u8 temp_r3_2;
    u8 temp_r3_3;
    u8 temp_r4;
    u8 temp_r5;
    ControllerInputContext *window_choice_setting;
    window_choice_setting = &controller_input_state.controllers[is_player_input_active(((s32) this->client_index))];
    if ((test_buttons_press_or_repeat(window_choice_setting, 0xF0, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, (s32)(0U), 0, 0);
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->m_71 = (this->m_71 - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->m_71 = (this->m_71 + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->m_70 = (this->m_70 + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            this->m_70 = (this->m_70 - 1);
        }
        temp_r3 = this->m_70;
        if ((s8) temp_r3 < 0) {
            this->m_70 = (temp_r3 + 3);
        }
        temp_r3_2 = this->m_70;
        if ((s8) temp_r3_2 >= 3) {
            this->m_70 = (temp_r3_2 - 3);
        }
        temp_r3_3 = this->m_71;
        if ((s8) temp_r3_3 < 0) {
            this->m_71 = (u8) (temp_r3_3 + this->m_72);
        }
        temp_r4 = this->m_71;
        temp_r5 = this->m_72;
        if ((s8) temp_r4 >= (s8) temp_r5) {
            this->m_71 = (u8) (temp_r4 - temp_r5);
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomSelect::draw_cursor(WindowDrawContext *context) {
    NJS_POINT2 position;
    position.x = (58.0f * (f32) (s8) this->m_70) + 1.0f;
    position.y = (51.0f * (f32) (s8) this->m_71) + (-5.0f);
    TWindowSubCustomEquip::draw_cursor_sprite(0.4f, context, &position, m_74);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
void TWindowSubCustomSelect::draw_palette_cells(WindowDrawContext *ctx) {
    u32 i;
    s32 p;
    Ent_802776D0 *e;
    s16 id;
    s16 sub;
    WindowSpritePart *icon;
    WindowSpritePart *background;
    TUnk_804CF9C8 *label;
    f32 y;
    f32 fx;
    f32 fy;
    p = (saddr)get_player_by_client_id((this->client_index));
    if (p == 0) {
        return;
    }
    e = reinterpret_cast<Ent_802776D0 *>(m_78);
    for (i = 0; e->id != 8; i++, e++) {
        if (e->id == 0) {
            continue;
        }
        fx = 58.0f * (f32)(i % 3);
        fy = 51.0f * (f32)(i / 3);
        y = ctx->inner_y + fy;
        if (47.0f + (8.0f + y) < ctx->clip_y0 || 8.0f + y > ctx->clip_y1) {
            continue;
        }
        icon = static_cast<WindowSpritePart *>(get_array_entry(1));
        background = static_cast<WindowSpritePart *>(get_array_entry(0));
        label = static_cast<TUnk_804CF9C8 *>(get_array_entry(2));
        icon->x = 12.0f + fx;
        icon->y = 10.0f + fy;
        background->x = 9.0f + fx;
        background->y = 8.0f + fy;
        id = e->id;
        sub = e->sub;
        if (can_use_palette_action__10TObjPlayerFPvUcUc(p, id, sub) != 0) {
            icon->color = -1;
        } else {
            icon->color = 0xFF404040;
        }
        draw_action_palette_icon(icon, id, sub);
        update_palette_item_count_label(label, icon, id, sub, client_index);
        draw_visible_window_entries(this, &entry_list, ctx);
    }
}
#pragma pop

void TWindowSubCustomSelect::render() {
    TWindowSubCustomSelect *window_sub_custom_select = this;
    WindowDrawContext *draw_context;
    draw_context = window_sub_custom_select->get_draw_context();
    ((TWindowBase *)window_sub_custom_select)->draw_window_frame(draw_context);
    window_sub_custom_select->draw_palette_cells(draw_context);
    window_sub_custom_select->draw_cursor(draw_context);
    ((TWindowSubStatusDisp *)((void *)(window_sub_custom_select->m_7c)))->forward_render(draw_context);
    draw_window_scrollbar(window_sub_custom_select->scroll_bar, draw_context, window_sub_custom_select->scroll_offset);
}

void TWindowSubCustomSelect::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    ControllerInputContext *context;
    temp_r30 = is_player_input_active(((s32) this->client_index));
    if (!(*(s32 *)&this->window_flags & 2)) {
        *(s32 *)&this->open_tick = 0x01000000;
    }
    if (((TWindowSubCustomSelect *)arg0)->is_active() == 0) {
        handle_grid_navigation();
        context = &controller_input_state.controllers[temp_r30];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            handle_decide();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    update_list_scroll();
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
        ((TWindowSubStatusDisp *)(*(saddr *)&this->m_7c))->update_subwindow();
        scroll_bar->increment_counter();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    *(s32 *)&this->m_74 = (s32) (*(s32 *)&this->m_74 + 1);
}

TWindowSubCustomSelect::~TWindowSubCustomSelect() {
    TWindowSubStatusDisp::destroy_allocation(reinterpret_cast<saddr>(scroll_bar), (s16)1);
    TWindowSubStatusDisp::destroy_status_display((saddr)(*(void **)((s8 *)this + 0x7C)), (s16)1);
}
const u32 custom_select_organic_action_table[40] = {
    0x20000, 0x20001, 0x20002, 0x30000, 0x30006, 0x30003, 0x30001, 0x30007,
    0x30004, 0x30002, 0x30008, 0x30005, 0x30009, 0x30012, 0, 0x3000F,
    0x30010, 0x30011, 0x3000D, 0x3000A, 0x3000B, 0x3000C, 0x3000E, 0,
    0x40000, 0x40001, 0x40002, 0x40003, 0x40004, 0x40005, 0x40006, 0x40007,
    0x40008, 0x40009, 0x4000A, 0, 0x4000B, 0x4000C, 0, 0x80000,
};
const u32 custom_select_android_action_table[20] = {
    0x20000, 0x20001, 0x20002, 0x40000, 0x40001, 0x40002, 0x40009, 0x4000A,
    0, 0x4000B, 0x40008, 0, 0x4000D, 0x4000E, 0, 0x4000F,
    0x40010, 0, 0x80000, 0,
};

#pragma push
#pragma fp_contract on
#pragma fp_contract on
TWindowSubCustomSelect::TWindowSubCustomSelect(s32 client)
    : TWindowAddition((u8 *)&TWindowSubCustomSelect__window_settings,
                      static_cast<s16>(client), (u8 *)get_window_layout_position(0x10)) {
    NJS_POINT2 pos;
    Big_80277AEC *p;
    Sub_80277AEC *q;
    Ent_80277AEC *e;
    void *o;
    m_name = TWindowSubCustomSelect__class_name;
    client_index = client;
    p = (Big_80277AEC *)get_player_by_client_id(client_index);
    if (p == NULL) {
        return;
    }
    q = &p->sub;
    if (q == NULL) {
        return;
    }
    if (q->flags & 0x10) {
        m_78 = reinterpret_cast<uaddr>(custom_select_android_action_table);
    } else {
        m_78 = reinterpret_cast<uaddr>(custom_select_organic_action_table);
    }
    this->m_73 = 0;
    this->m_70 = 0;
    this->m_71 = 0;
    this->m_74 = 0;
    e = reinterpret_cast<Ent_80277AEC *>(m_78);
    this->m_72 = 0;
    while (e->id != 8) {
        e++;
        (this->m_72)++;
    }
    o = ::operator new(0x24);
    if (o != NULL) {
        o = ((TWindowSubStatusDisp *)o)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x22), client_index);
    }
    *(void **)((s8 *)this + 0x7C) = o;
    pos.x = 196.0f;
    pos.y = 51.0f * (f32)(s8)m_72 + 18.0f;
    scroll_bar = new WindowScrollBar(&pos);
}
#pragma pop

}
