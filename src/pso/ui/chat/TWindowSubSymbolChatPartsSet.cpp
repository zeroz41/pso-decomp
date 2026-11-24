#include "pso/ui/chat/SymbolChatPreset.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/chat/TWindowChatSymbol_802486A8.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/vector.h"



extern "C" {

#pragma push
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
s32 TWindowSubSymbolChatPartsSet::select_symbol_chat_record(s8 *arg1, s32 *arg2) {
    SymbolChatPayload *data_ptr;
    s32 i;
    s16 temp_r0;
    s32 temp_r3_2;
    s32 var_r29;
    u16 *part_flags;
    u16 *temp_r29_2;
    u16 *temp_r3_3;
    u16 temp_r8;
    u32 temp_r4;
    const SymbolChatPart *part;
    SymbolChatPreset *instance;
    m_84 = arg2;
    *(m_84) = 0;
    instance = reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance());
    data_ptr = instance->get_data_ptr();
    temp_r3_2 = TWindowSubSymbolChat::calc_remaining_slots();
    temp_r0 = *(s16 *)((s8 *)((u8 *)this) + 0x6E);
    if (temp_r3_2 > temp_r0) {
        m_94 = 2.0f;
        part = &data_ptr->parts[temp_r0];
        first_part_index = (s32) *(s16 *)((s8 *)((u8 *)this) + 0x6E);
        second_part_index = instance->find_free_entry(0);
        i = 0;
        *(s16 *)((s8 *)((u8 *)this) + 0x6E) = (s16) part->id;
        *(s16 *)((s8 *)((u8 *)this) + 0x6A) = (s16) part->x;
        *(s16 *)((s8 *)((u8 *)this) + 0x6C) = (s16) part->y;
        *m_7c = part->flags & 1;
        *m_80 = ((u8) part->flags >> 1U) & 1;
        do {
            part_flags = get_parts_entry(this, i);
            temp_r29_2 = get_parts_entry((saddr)i);
            temp_r3_3 = TWindowSubSymbolChatPartsSet__sub_802482B8(this, i);
            i += 1;
            *part_flags |= 2;
            *temp_r29_2 |= 2;
            *temp_r3_3 |= 2;
        } while (i < 4);
        selection_mode = 2;
        return 0;
    }
    m_70 = arg1;
    i = 0;
    selection_mode = 3;
    var_r29 = *(s16 *)((s8 *)((u8 *)this) + 0x6E) - temp_r3_2;
    for (; i < 4; i++) {
        if (TWindowSubSymbolChat__sub_800771C4(instance, i) != 0) {
            if (var_r29-- <= 0) {
                temp_r4 = (u32) i >> 0x1FU;
                temp_r8 = data_ptr->facial_parts[i];
                first_part_index = i;
                second_part_index = i;
                *(s16 *)((s8 *)((u8 *)this) + 0x6A) = (s16) (((i & 1) ^ temp_r4) - temp_r4);
                *(s16 *)((s8 *)((u8 *)this) + 0x6C) = (s16) (i / 2);
                *(s16 *)((s8 *)((u8 *)this) + 0x6E) = (s16) (u8) temp_r8;
                *m_70 = (temp_r8 >> 8U) & 7;
                *m_7c = (temp_r8 >> 0xBU) & 1;
                *m_80 = (temp_r8 >> 0xCU) & 1;
                return 1;
            }
        }
    }
    return 1;
}
#pragma pop

void TWindowSubSymbolChatPartsSet::set_selection_and_refresh(s8 *arg1) {
    first_part_index = 0;
    m_70 = arg1;
    selection_mode = 1;
    sub_8028625C();
}
void TWindowSubSymbolChatPartsSet::init_symbol_layout(s32 *arg1) {
  s32 sel;
  u16 *parts_entry;
  u16 *temp_r31;
  u16 *temp_r3;
  SymbolChatPreset *instance;
  m_84 = arg1;
  m_94 = 2.0f;
  if (((s32) (*arg1)) == 1)
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
    temp_r31 = (u16 *) ((TWindowSubSymbolChatPartsSet *)this)->get_parts_entry((saddr)sel);
    temp_r3 = (u16 *) TWindowSubSymbolChatPartsSet__sub_802482B8(this, sel);
    sel += 1;
    *parts_entry |= 2;
    *temp_r31 |= 2;
    *temp_r3 |= 2;
  }
  while (sel < 4);
  instance = reinterpret_cast<SymbolChatPreset *>(TWindowSubSymbolChat::get_instance());
  first_part_index = instance->find_free_entry(0);
  second_part_index = instance->find_free_entry((first_part_index) + 1);
  selection_mode = 0;
  sub_8028625C();
}

}


struct Set_8028625C {
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

struct Win_802864C4 {
    u8 pad0[0x69];
    u8 f69;
    s16 x;
    s16 y;
    u8 pad6e[0x74 - 0x6E];
    s32 f74;
};

typedef struct T_8028642C {
    u8 pad[0x69];
    s8 f69;
    u8 pad6a[0x78 - 0x6A];
    u32 f78;
    u8 pad7c[0x84 - 0x7C];
    s32 *f84;
} T_8028642C;

const char *TWindowSubSymbolChatPartsSet__name = "TWindowSubSymbolChatPartsSet";
static const NJS_POINT2 lbl_8044FC30 = {178.0f, 188.0f};

struct Pt_80286120 { u8 pad[8]; f32 f8; f32 fc; };

struct Ps_80286120 { u8 pad[0x69]; s8 f69; u8 pad6a[0xA]; s32 index; };

extern "C" {
void setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(void *, void *, void *, u16, s32, s32, s32, s32);
void TWindowSubSymbolChatFaceType__sub_80283C84(void *, void *, f32, f32);


void TWindowSubSymbolChatPartsSet::draw_selected_part_cursor(void *ctx) {
#define arg0 ((Ps_80286120 *)this)
    NJS_POINT2 sp;
    Pt_80286120 *e;
    switch (arg0->f69) {
    case 1:
    case 3:
        e = (Pt_80286120 *)TWindowSubSymbolChatPartsSet::get_parts_entry(arg0, arg0->index);
        sp.x = e->f8 - 3.0f;
        sp.y = e->fc - 3.0f;
        TWindowSubSymbolChatFaceType__sub_80283C84(ctx, &sp, 38.0f, 0.1f);
        break;
    case 0:
    case 2:
        return;
    }
#undef arg0
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
    Set_8028625C *arg0 = (Set_8028625C *)this;
    u16 *e2;
    void *b3;
    void *a1;
    void *a3;
    void *b1;
    u16 *e;
    void *c;
    switch (arg0->mode) {
    case 0:
    case 2:
        e = get_entry_offset_d(arg0->cur);
        ((TWindowSubSymbolChatPartsSet *)e)->set_pos(arg0->x, arg0->y);
        TWindowSubSymbolChatPartsSet::set_part_sprite(e, arg0->color, *arg0->p7C, *arg0->p80);
        if (*arg0->p84 != 0) {
            e2 = get_entry_offset_d(arg0->sel);
            *e2 &= ~2;
            ((TWindowSubSymbolChatPartsSet *)e2)->set_pos((s16)(0x40 - arg0->x), arg0->y);
            TWindowSubSymbolChatPartsSet::set_part_sprite(e2, arg0->color, *arg0->p7C == 0, *arg0->p80);
        } else if (arg0->sel < 0xC) {
            *get_entry_offset_d(arg0->sel) |= 2;
        }
        break;
    case 3:
        a3 = get_parts_entry(this, arg0->sel);
        b3 = get_parts_entry((saddr)arg0->sel);
        c = TWindowSubSymbolChatPartsSet__sub_802482B8(this, arg0->sel);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a3, b3, c, 0xFF, 0, 0, 0, 0);
    case 1:
        a1 = get_parts_entry(this, arg0->cur);
        b1 = get_parts_entry((saddr)arg0->cur);
        c = TWindowSubSymbolChatPartsSet__sub_802482B8(this, arg0->cur);
        setup_part_sprites__28TWindowSubSymbolChatPartsSetFPvPvPvUsiiii(a1, b1, c, arg0->color, *arg0->p70, *arg0->p7C, *arg0->p80, arg0->cur);
        break;
    }
}

void TWindowSubSymbolChatPartsSet::toggle_selected_part() {
    T_8028642C *arg0 = (T_8028642C *)this;
    switch (arg0->f69) {
    case 0:
    case 2:
        if (arg0->f78 < 12 && test_pressed_buttons_packed(&controller_input_state.controllers[0], 0x400) != 0) {
            if (*arg0->f84 != 0) {
                *arg0->f84 = 0;
            } else {
                *arg0->f84 = 1;
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
    u8 temp_r0;
    void *camera_ctrl;
    Win_802864C4 *w = (Win_802864C4 *)this;
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
    NJS_POINT2 sp10;
    NJS_POINT2 sp8;
    f32 ctx;
    u8 *c_arg;

    c_arg = reinterpret_cast<u8 *>(draw_default_entry());
    copy_vec2((&sp10), c_arg + 0x10);
    copy_vec2((&sp8), c_arg + 0x28);
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
    copy_vec2((c_arg + 0x10), &sp10);
    copy_vec2((c_arg + 0x28), &sp8);
    this->heading_display->forward_render(c_arg);
}

void TWindowSubSymbolChatPartsSet::run_task() {
    u8 *arg0 = (u8 *)this;
    if (!(this->window_flags & 2)) {
        this->open_tick = 0x01000000;
    }
    if (((TWindowSubSymbolChatPartsSet *)arg0)->is_active() == 0) {
        handle_cursor_input();
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            handle_decide();
        }
        if ((test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    toggle_selected_part();
    ((TWindowSubSymbolChatPartsSet *)arg0)->sub_8028625C();
    if ((f32) this->open_tick >= 7.5f) {
        this->heading_display->update_subwindow();
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list(&entry_list);
}

}
TWindowSubSymbolChatPartsSet::~TWindowSubSymbolChatPartsSet() {
    TWindowSubStatusDisp::destroy_status_display((s32)heading_display, 1);
}

TWindowSubSymbolChatPartsSet::TWindowSubSymbolChatPartsSet(void *position, s16 index, s32 *first, s32 *second)
    : TWindowChatSymbol((saddr)position, (saddr)&lbl_8044FC30) {
    m_name = TWindowSubSymbolChatPartsSet__name;
    set_depth(50030.0f);
    m_68 = 0;
    cursor_x = 0;
    cursor_y = 0;
    m_6e = index;
    m_70 = NULL;
    m_7c = first;
    m_80 = second;
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

