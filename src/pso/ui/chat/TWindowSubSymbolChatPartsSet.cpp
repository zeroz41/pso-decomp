#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/ui/chat/SymbolChatSprite.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/window/WindowDrawContext.h"
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
    part_index = part_id;
    if (free_slots > part_index) {
        scale = 2.0f;
        part = &data_ptr->parts[part_index];
        first_part_index = (s32) part_id;
        second_part_index = instance->find_free_entry(0);
        i = 0;
        part_id = (s16) part->id;
        cursor_x = (s16) part->x;
        cursor_y = (s16) part->y;
        *first_flag_out = part->flags & 1;
        *second_flag_out = ((u8) part->flags >> 1U) & 1;
        do {
            part_flags = get_parts_entry(this, i);
            second_entry = get_parts_entry((saddr)i);
            third_entry = get_shortcut_icon_entry(this, i);
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
    skip = part_id - free_slots;
    for (; i < 4; i++) {
        if (is_facial_part_set(instance, i) != 0) {
            if (skip-- <= 0) {
                sign = (u32) i >> 0x1FU;
                facial = data_ptr->facial_parts[i];
                first_part_index = i;
                second_part_index = i;
                cursor_x = (s16) (((i & 1) ^ sign) - sign);
                cursor_y = (s16) (i / 2);
                part_id = (s16) (u8) facial;
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
    update_part_sprites();
}
void TWindowSubSymbolChatPartsSet::init_symbol_layout(s32 *result) {
  s32 sel;
  u16 *parts_entry;
  u16 *second_entry;
  u16 *third_entry;
  SymbolChatPreset *instance;
  result_out = result;
  scale = 2.0f;
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
    third_entry = (u16 *) get_shortcut_icon_entry(this, sel);
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
  update_part_sprites();
}



const char *window_sub_symbol_chat_parts_set_name = "TWindowSubSymbolChatPartsSet";
static const NJS_POINT2 parts_set_window_size = {178.0f, 188.0f};

extern "C" {
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(void *, void *, void *, u16, s32, s32, s32, s32);
void draw_selection_corners(void *, void *, f32, f32);


void TWindowSubSymbolChatPartsSet::draw_selected_part_cursor(void *ctx) {
    NJS_POINT2 corner;
    SymbolChatSprite *e;
    switch (selection_mode) {
    case 1:
    case 3:
        e = (SymbolChatSprite *)TWindowSubSymbolChatPartsSet::get_parts_entry(this, first_part_index);
        corner.x = e->x - 3.0f;
        corner.y = e->y - 3.0f;
        draw_selection_corners(ctx, &corner, 38.0f, 0.1f);
        break;
    case 0:
    case 2:
        return;
    }
}

void TWindowSubSymbolChatPartsSet::handle_cancel() {
    if (is_active() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->result_flags = (u8) (this->result_flags | 2);
    }
}

void TWindowSubSymbolChatPartsSet::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->result_flags = (u8) (this->result_flags | 1);
    this->heading_display->set_entry_state(2);
}

void TWindowSubSymbolChatPartsSet::update_part_sprites() {
    u16 *e2;
    void *b3;
    void *a1;
    void *a3;
    void *b1;
    u16 *e;
    void *c;
    switch (selection_mode) {
    case 0:
    case 2:
        e = get_entry_offset_d(first_part_index);
        ((TWindowSubSymbolChatPartsSet *)e)->set_pos(cursor_x, cursor_y);
        TWindowSubSymbolChatPartsSet::set_part_sprite(e, part_id, *first_flag_out, *second_flag_out);
        if (*result_out != 0) {
            e2 = get_entry_offset_d((u32)second_part_index);
            *e2 &= ~2;
            ((TWindowSubSymbolChatPartsSet *)e2)->set_pos((s16)(0x40 - cursor_x), cursor_y);
            TWindowSubSymbolChatPartsSet::set_part_sprite(e2, part_id, *first_flag_out == 0, *second_flag_out);
        } else if ((u32)second_part_index < 0xC) {
            *get_entry_offset_d((u32)second_part_index) |= 2;
        }
        break;
    case 3:
        a3 = get_parts_entry(this, (u32)second_part_index);
        b3 = get_parts_entry((saddr)(u32)second_part_index);
        c = get_shortcut_icon_entry(this, (u32)second_part_index);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a3, b3, c, 0xFF, 0, 0, 0, 0);
    case 1:
        a1 = get_parts_entry(this, first_part_index);
        b1 = get_parts_entry((saddr)first_part_index);
        c = get_shortcut_icon_entry(this, first_part_index);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a1, b1, c, part_id, *selection_out, *first_flag_out, *second_flag_out, first_part_index);
        break;
    }
}

void TWindowSubSymbolChatPartsSet::toggle_selected_part() {
    switch (selection_mode) {
    case 0:
    case 2:
        if ((u32)second_part_index < 12 && test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) {
            if (*result_out != 0) {
                *result_out = 0;
            } else {
                *result_out = 1;
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
        switch (selection_mode) {
        case 0:
        case 2:
            if (cursor_x < 0) {
                cursor_x = 0;
            }
            if (cursor_x >= 0x40) {
                cursor_x = 0x3F;
            }
            if (cursor_y < 0) {
                cursor_y = 0;
            }
            if (cursor_y >= 0x40) {
                cursor_y = 0x3F;
            }
            break;
        case 1:
        case 3:
            if (cursor_x < 0) {
                cursor_x = 0;
            }
            if (cursor_x >= 2) {
                cursor_x = 1;
            }
            if (cursor_y < 0) {
                cursor_y = 0;
            }
            if (cursor_y >= 2) {
                cursor_y = 1;
            }
            x = cursor_x;
            first_part_index = x + cursor_y * 2;
            update_visibility();
            break;
        }
    }
}

void TWindowSubSymbolChatPartsSet::render() {
    NJS_POINT2 saved_pos;
    NJS_POINT2 saved_scale;
    f32 ctx;
    WindowDrawContext *c_arg;

    c_arg = reinterpret_cast<WindowDrawContext *>(draw_default_entry());
    copy_vec2((&saved_pos), &c_arg->inner_x);
    copy_vec2((&saved_scale), c_arg->scale);
    if (c_arg->open_tick < 0) {
        c_arg->scale[0] = (f32) ((f32) this->open_tick / 7.5f);
        c_arg->scale[1] = c_arg->scale[0];
    }
    draw_quest_message_frame((void *)c_arg);
    c_arg->inner_x = (f32) (c_arg->inner_x + this->offset_x);
    c_arg->inner_y = (f32) (c_arg->inner_y + this->offset_y);
    c_arg->scale[0] = (f32) (c_arg->scale[0] * this->scale);
    ctx = c_arg->scale[1];
    c_arg->scale[1] = (f32) (ctx * this->scale);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        c_arg);
    this->draw_selected_part_cursor(c_arg);
    copy_vec2((&c_arg->inner_x), &saved_pos);
    copy_vec2((c_arg->scale), &saved_scale);
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
    this->update_part_sprites();
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
    : TWindowChatSymbol(position, (saddr)&parts_set_window_size) {
    m_name = window_sub_symbol_chat_parts_set_name;
    set_depth(50030.0f);
    result_flags = 0;
    cursor_x = 0;
    cursor_y = 0;
    part_id = index;
    selection_out = NULL;
    first_flag_out = first;
    second_flag_out = second;
    TWindowSubStatusDisp *heading = static_cast<TWindowSubStatusDisp *>(::operator new(0x24));
    if (heading != NULL) {
        heading = (TWindowSubStatusDisp *)heading->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x34), client_index);
    }
    heading_display = heading;
    offset_x = 21.0f;
    offset_y = 49.0f;
    scale = 1.0f;
    window_flags |= 0x40;
    set_selection(reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance()));
}

