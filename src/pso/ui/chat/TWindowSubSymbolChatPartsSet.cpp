#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/vector.h"




#pragma push
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
s32 TWindowSubSymbolChatPartsSet::select_symbol_chat_record(s8 *selection, s32 *result) {
    SymbolChatPayload *data_ptr;
    s32 i;
    s16 part_index;
    s32 free_slots;
    s32 skip;
    u16 *part_flags;
    u16 *second_entry;
    u16 *third_entry;
    u16 facial;
    u32 sign;
    const SymbolChatPart *part;
    SymbolChatPreset *instance;
    result_out = result;
    *(result_out) = 0;
    instance = reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance());
    data_ptr = instance->get_data_ptr();
    free_slots = TWindowSubSymbolChat::calc_remaining_slots();
    part_index = *(s16 *)((s8 *)(this) + 0x6E);
    if (free_slots > part_index) {
        m_94 = 2.0f;
        part = &data_ptr->parts[part_index];
        first_part_index = (s32) *(s16 *)((s8 *)(this) + 0x6E);
        second_part_index = instance->find_free_entry(0);
        i = 0;
        *(s16 *)((s8 *)(this) + 0x6E) = (s16) part->id;
        *(s16 *)((s8 *)(this) + 0x6A) = (s16) part->x;
        *(s16 *)((s8 *)(this) + 0x6C) = (s16) part->y;
        *first_flag_out = part->flags & 1;
        *second_flag_out = ((u8) part->flags >> 1U) & 1;
        do {
            part_flags = get_parts_entry(this, i);
            second_entry = get_parts_entry((saddr)i);
            third_entry = TWindowSubSymbolChatPartsSet__sub_802482B8(this, i);
            i += 1;
            *part_flags |= 2;
            *second_entry |= 2;
            *third_entry |= 2;
        } while (i < 4);
        selection_mode = 2;
        return 0;
    }
    selection_out = selection;
    i = 0;
    selection_mode = 3;
    skip = *(s16 *)((s8 *)(this) + 0x6E) - free_slots;
    for (; i < 4; i++) {
        if (TWindowSubSymbolChat__sub_800771C4(instance, i) != 0) {
            if (skip-- <= 0) {
                sign = (u32) i >> 0x1FU;
                facial = data_ptr->facial_parts[i];
                first_part_index = i;
                second_part_index = i;
                *(s16 *)((s8 *)(this) + 0x6A) = (s16) (((i & 1) ^ sign) - sign);
                *(s16 *)((s8 *)(this) + 0x6C) = (s16) (i / 2);
                *(s16 *)((s8 *)(this) + 0x6E) = (s16) (u8) facial;
                *selection_out = (facial >> 8U) & 7;
                *first_flag_out = (facial >> 0xBU) & 1;
                *second_flag_out = (facial >> 0xCU) & 1;
                return 1;
            }
        }
    }
    return 1;
}
#pragma pop

void TWindowSubSymbolChatPartsSet::set_selection_and_refresh(s8 *selection) {
    first_part_index = 0;
    selection_out = selection;
    selection_mode = 1;
    sub_8028625C();
}
void TWindowSubSymbolChatPartsSet::init_symbol_layout(s32 *result) {
  s32 sel;
  u16 *parts_entry;
  u16 *second_entry;
  u16 *third_entry;
  SymbolChatPreset *instance;
  result_out = result;
  m_94 = 2.0f;
  if (((s32) (*result)) == 1)
  {
    cursor_x = 0x14;
    cursor_y = 0x20;
  }
  else
  {
    cursor_x = 0x20;
    cursor_y = 0x20;
  }
  sel = 0;
  do
  {
    parts_entry = TWindowSubSymbolChatPartsSet::get_parts_entry(this, sel);
    second_entry = (u16 *) this->get_parts_entry((saddr)sel);
    third_entry = (u16 *) TWindowSubSymbolChatPartsSet__sub_802482B8(this, sel);
    sel += 1;
    *parts_entry |= 2;
    *second_entry |= 2;
    *third_entry |= 2;
  }
  while (sel < 4);
  instance = reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance());
  first_part_index = instance->find_free_entry(0);
  second_part_index = instance->find_free_entry((first_part_index) + 1);
  selection_mode = 0;
  sub_8028625C();
}



struct PartsSetCursorView {
    u8 pad0[0x69];
    s8 mode;
    s16 x;
    s16 y;
    s16 color;
    s8 *p70;
    s32 cur;
    u32 sel;
    s32 *p7C;
    s32 *p80;
    s32 *p84;
};

struct PartsSetInputView {
    u8 pad0[0x69];
    u8 f69;
    s16 x;
    s16 y;
    u8 pad6e[0x74 - 0x6E];
    s32 f74;
};

typedef struct PartsSetToggleView {
    u8 pad[0x69];
    s8 f69;
    u8 pad6a[0x78 - 0x6A];
    u32 f78;
    u8 pad7c[0x84 - 0x7C];
    s32 *f84;
} PartsSetToggleView;

const char *window_sub_symbol_chat_parts_set_name = "TWindowSubSymbolChatPartsSet";
static const NJS_POINT2 lbl_8044FC30 = {178.0f, 188.0f};

struct PartSpriteView { u8 pad[8]; f32 f8; f32 fc; };

struct PartsSetIndexView { u8 pad[0x69]; s8 f69; u8 pad6a[0xA]; s32 index; };

extern "C" {
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(void *, void *, void *, u16, s32, s32, s32, s32);
void TWindowSubSymbolChatFaceType__sub_80283C84(void *, void *, f32, f32);


void TWindowSubSymbolChatPartsSet::draw_selected_part_cursor(void *ctx) {
#define view ((PartsSetIndexView *)this)
    NJS_POINT2 corner;
    PartSpriteView *e;
    switch (view->f69) {
    case 1:
    case 3:
        e = (PartSpriteView *)TWindowSubSymbolChatPartsSet::get_parts_entry(view, view->index);
        corner.x = e->f8 - 3.0f;
        corner.y = e->fc - 3.0f;
        TWindowSubSymbolChatFaceType__sub_80283C84(ctx, &corner, 38.0f, 0.1f);
        break;
    case 0:
    case 2:
        return;
    }
#undef view
}

void TWindowSubSymbolChatPartsSet::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->m_68 = (u8) (this->m_68 | 2);
    }
}

void TWindowSubSymbolChatPartsSet::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->m_68 = (u8) (this->m_68 | 1);
    this->heading_display->set_entry_state(2);
}

void TWindowSubSymbolChatPartsSet::sub_8028625C() {
    PartsSetCursorView *view = (PartsSetCursorView *)this;
    u16 *e2;
    void *b3;
    void *a1;
    void *a3;
    void *b1;
    u16 *e;
    void *c;
    switch (view->mode) {
    case 0:
    case 2:
        e = get_entry_offset_d(view->cur);
        ((TWindowSubSymbolChatPartsSet *)e)->set_pos(view->x, view->y);
        TWindowSubSymbolChatPartsSet::set_part_sprite(e, view->color, *view->p7C, *view->p80);
        if (*view->p84 != 0) {
            e2 = get_entry_offset_d(view->sel);
            *e2 &= ~2;
            ((TWindowSubSymbolChatPartsSet *)e2)->set_pos((s16)(0x40 - view->x), view->y);
            TWindowSubSymbolChatPartsSet::set_part_sprite(e2, view->color, *view->p7C == 0, *view->p80);
        } else if (view->sel < 0xC) {
            *get_entry_offset_d(view->sel) |= 2;
        }
        break;
    case 3:
        a3 = get_parts_entry(this, view->sel);
        b3 = get_parts_entry((saddr)view->sel);
        c = TWindowSubSymbolChatPartsSet__sub_802482B8(this, view->sel);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a3, b3, c, 0xFF, 0, 0, 0, 0);
    case 1:
        a1 = get_parts_entry(this, view->cur);
        b1 = get_parts_entry((saddr)view->cur);
        c = TWindowSubSymbolChatPartsSet__sub_802482B8(this, view->cur);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a1, b1, c, view->color, *view->p70, *view->p7C, *view->p80, view->cur);
        break;
    }
}

void TWindowSubSymbolChatPartsSet::toggle_selected_part() {
    PartsSetToggleView *view = (PartsSetToggleView *)this;
    switch (view->f69) {
    case 0:
    case 2:
        if (view->f78 < 12 && test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) {
            if (*view->f84 != 0) {
                *view->f84 = 0;
            } else {
                *view->f84 = 1;
            }
        }
        break;
    case 1:
        break;
    case 3:
        break;
    }
}

void TWindowSubSymbolChatPartsSet::handle_cursor_input() {
    s16 x;
    void *camera_ctrl;
    PartsSetInputView *w = (PartsSetInputView *)this;
    camera_ctrl = &controller_input_state.controllers[0];
    if ((test_previous_buttons_packed(camera_ctrl, 0xF0) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0xF0) != 0)) {
        if ((test_previous_buttons_packed(camera_ctrl, 0x80) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x80) != 0)) {
            this->cursor_x = (s16)(this->cursor_x + 1);
        }
        if ((test_previous_buttons_packed(camera_ctrl, 0x40) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x40) != 0)) {
            this->cursor_x = (s16)(this->cursor_x - 1);
        }
        if ((test_previous_buttons_packed(camera_ctrl, 0x10) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x10) != 0)) {
            this->cursor_y = (s16)(this->cursor_y - 1);
        }
        if ((test_previous_buttons_packed(camera_ctrl, 0x20) != 0) || (test_previous_buttons_color(&controller_input_state.keyboard, 0x20) != 0)) {
            this->cursor_y = (s16)(this->cursor_y + 1);
        }
        switch ((s8)w->f69) {
        case 0:
        case 2:
            if (w->x < 0) {
                w->x = 0;
            }
            if (w->x >= 0x40) {
                w->x = 0x3F;
            }
            if (w->y < 0) {
                w->y = 0;
            }
            if (w->y >= 0x40) {
                w->y = 0x3F;
            }
            break;
        case 1:
        case 3:
            if (w->x < 0) {
                w->x = 0;
            }
            if (w->x >= 2) {
                w->x = 1;
            }
            if (w->y < 0) {
                w->y = 0;
            }
            if (w->y >= 2) {
                w->y = 1;
            }
            x = w->x;
            w->f74 = x + w->y * 2;
            update_visibility();
            break;
        }
    }
}

void TWindowSubSymbolChatPartsSet::render() {
    NJS_POINT2 saved_pos;
    NJS_POINT2 saved_scale;
    f32 ctx;
    u8 *c_arg;

    c_arg = reinterpret_cast<u8 *>(draw_default_entry());
    copy_vec2((&saved_pos), c_arg + 0x10);
    copy_vec2((&saved_scale), c_arg + 0x28);
    if ((s32) *(s32 *)((s8 *)c_arg + 0x30) < 0) {
        *(f32 *)((s8 *)c_arg + 0x28) = (f32) ((f32) this->open_tick / 7.5f);
        *(f32 *)((s8 *)c_arg + 0x2C) = (f32) *(f32 *)((s8 *)c_arg + 0x28);
    }
    draw_quest_message_frame((void *)c_arg);
    *(f32 *)((s8 *)c_arg + 0x10) = (f32) (*(f32 *)((s8 *)c_arg + 0x10) + *(f32 *)((s8 *)this + 0x8C));
    *(f32 *)((s8 *)c_arg + 0x14) = (f32) (*(f32 *)((s8 *)c_arg + 0x14) + this->m_90);
    *(f32 *)((s8 *)c_arg + 0x28) = (f32) (*(f32 *)((s8 *)c_arg + 0x28) * *(f32 *)((s8 *)this + 0x94));
    ctx = *(f32 *)((s8 *)c_arg + 0x2C);
    *(f32 *)((s8 *)c_arg + 0x2C) = (f32) (ctx * *(f32 *)((s8 *)this + 0x94));
    draw_visible_window_entries(
        this,
        &this->entry_list,
        reinterpret_cast<WindowDrawContext *>(c_arg));
    this->draw_selected_part_cursor(c_arg);
    copy_vec2((c_arg + 0x10), &saved_pos);
    copy_vec2((c_arg + 0x28), &saved_scale);
    this->heading_display->forward_render(c_arg);
}

void TWindowSubSymbolChatPartsSet::run_task() {
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if (this->is_active() == 0) {
        handle_cursor_input();
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            handle_decide();
        }
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    toggle_selected_part();
    this->sub_8028625C();
    if ((f32) this->open_tick >= 7.5f) {
        this->heading_display->update_subwindow();
    }
    update_window();
    this->update_window_entry_list(&entry_list);
}

}
TWindowSubSymbolChatPartsSet::~TWindowSubSymbolChatPartsSet() {
    TWindowSubStatusDisp::destroy_status_display((saddr)heading_display, 1);
}

TWindowSubSymbolChatPartsSet::TWindowSubSymbolChatPartsSet(const NJS_POINT2 *position, s16 index, s32 *first, s32 *second)
    : TWindowChatSymbol(position, (saddr)&lbl_8044FC30) {
    m_name = window_sub_symbol_chat_parts_set_name;
    set_depth(50030.0f);
    m_68 = 0;
    cursor_x = 0;
    cursor_y = 0;
    set_index = index;
    selection_out = NULL;
    first_flag_out = first;
    second_flag_out = second;
    TWindowSubStatusDisp *heading = static_cast<TWindowSubStatusDisp *>(::operator new(0x24));
    if (heading != NULL) {
        heading = (TWindowSubStatusDisp *)heading->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x34), client_index);
    }
    heading_display = heading;
    m_8c = 21.0f;
    m_90 = 49.0f;
    m_94 = 1.0f;
    window_flags |= 0x40;
    set_selection(reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance()));
}

