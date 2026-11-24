#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/ControllerInput.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
struct TWindowSubComCard;
#include "pso/ui/window/TWindowMenuMainMenu.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/system/TLanguage.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/vector.h"

struct UV_802AD538 { f32 u, v; };

extern "C" {


const char *TWindowMenuMainMenu__class_name = "TWindowMenuMainMenu";

const UV_802AD538 main_menu_label_uv_table[31] = {
    {0.0f, 18.0f},  {0.0f, 18.0f},  {0.0f, 0.0f},   {0.0f, 54.0f},
    {0.0f, 54.0f},  {0.0f, 36.0f},  {0.0f, 72.0f},  {0.0f, 90.0f},
    {0.0f, 90.0f},  {0.0f, 108.0f}, {0.0f, 108.0f}, {0.0f, 126.0f},
    {0.0f, 162.0f}, {0.0f, 162.0f}, {0.0f, 234.0f}, {0.0f, 180.0f},
    {0.0f, 180.0f}, {0.0f, 198.0f}, {0.0f, 216.0f}, {98.0f, 0.0f},
    {98.0f, 0.0f},  {98.0f, 18.0f}, {98.0f, 72.0f}, {0.0f, 144.0f},
    {0.0f, 144.0f}, {98.0f, 36.0f}, {98.0f, 54.0f}, {98.0f, 54.0f},
    {98.0f, 54.0f}, {98.0f, 54.0f}, {98.0f, 54.0f},
};

void TMainMenuEntry::draw_item_labels(WindowDrawContext *context) {
    TexturedQuad r;
    f32 scale;
    const UV_802AD538 *uv;
    u32 color;
    u32 rgb;
    f32 a;

    if (is_item_active() != 0 && fade > 0) {
        scale = -1.0f / (0.299f + context->depth);
        uv = &main_menu_label_uv_table[icon];
        TWindowSubStatusDisp::begin_render();
        switch (kind) {
        case 0:
            rgb = 0xFFFFFF;
            if (flags & 2) {
                rgb = 0x686868;
            }
            if (fade >= 4) {
                a = 1.0f;
            } else {
                a = (f32)fade / 4.0f;
            }
            color = rgb | ((s32)(255.0f * a) << 24);
            break;
        case 1:
            TLanguage::set_entry_index(2, 0x4C);
            color = 0xFFFF6121;
            break;
        case 2:
            TLanguage::set_entry_index(2, 0x4C);
            color = 0xFF51EAFF;
            break;
        }
        begin_screen_draw(1);
        set_draw_texture_and_color(2, color);
        r.x0 = context->clip_x0 + position.current[0];
        r.y0 = context->clip_y0 + position.current[1];
        r.x1 = 98.0f + r.x0;
        r.y1 = 16.0f + r.y0;
        r.u0 = uv->u / 256.0f;
        r.v0 = uv->v / 256.0f;
        r.u1 = (98.0f + uv->u) / 256.0f;
        r.v1 = (16.0f + uv->v) / 256.0f;
        if (context->clip_and_transform_quad(&r) != 0) {
            draw_textured_quad_at_depth(&r.x0, scale);
        }
        TWindowSubStatusDisp::get_player();
        TLanguage::set_entry_index(2, 0x4B);
    }
}

int TMainMenuEntry::is_item_active() { return flags & 1; }

void TMainMenuEntry::disable_choice() { flags |= 2; }

void TMainMenuEntry::set_row_target(NJS_POINT2 *row) {
    copy_vec2(this, row);
    tween = 8;
}

void TMainMenuEntry::init_row_entry(NJS_POINT2 *row, s8 icon, s8 fade) {
    copy_vec2(this, row);
    copy_vec2(&position.current[0], row);
    this->fade = fade;
    this->icon = icon;
    kind = 0;
    flags |= 1;
}

void TMainMenuEntry::update_item_tween() {
    if (is_item_active() != 0) {
        if (tween <= 0) {
            position.current[0] = position.target[0];
            position.current[1] = position.target[1];
        } else {
            position.current[0] += (position.target[0] - position.current[0]) / tween;
            position.current[1] += (position.target[1] - position.current[1]) / tween;
            tween--;
        }
        if (fade < 4) {
            fade++;
        }
    }
}

void TMainMenuEntry::init_color() {
    position.target[0] = 0.0f;
    position.target[1] = 0.0f;
    position.current[0] = 0.0f;
    position.current[1] = 0.0f;
    fade = 0;
    icon = -1;
    kind = 0;
    flags = 0;
    tween = 0;
}

void TWindowMenuMainMenu::pop_level() {
    s32 i;
    parked_row_count--;
    state_flags |= 8;
    for (i = 0; i < 8; i++) {
        if (slots[i] != 0) {
            slots[i]->init_color();
            slots[i] = 0;
        }
    }
}

void TWindowMenuMainMenu::park_selection() {
    TMainMenuEntry buf;
    NJS_POINT2 row;
    s32 i;
    TMainMenuEntry *slot;
    buf.copy_color_entry(slots[selected_slot]);
    for (i = 0; i < 8; i++) {
        if (slots[i] != NULL) {
            slots[i]->init_color();
            slots[i] = NULL;
        }
    }
    get_row_position(&row, parked_row_count);
    slot = find_free_slot();
    slot->copy_color_entry(&buf);
    slot->set_row_target(&row);
    slot->kind = 2;
    state_flags |= 4;
    parked_row_count++;
}

void TMainMenuEntry::copy_color_entry(TMainMenuEntry *src) {
    position = src->position;
    fade = src->fade;
    icon = src->icon;
    kind = src->kind;
    flags = src->flags;
    tween = src->tween;
    b5 = src->b5;
    b6 = src->b6;
    b7 = src->b7;
}

int TWindowMenuMainMenu::get_selected_item_type() {
    TMainMenuEntry *p = slots[selected_slot];
    if (p == 0) return 0x1f;
    return p->icon;
}

void TWindowMenuMainMenu::set_selected_slot(int slot) {
    selected_slot = slot;
    slots[selected_slot]->kind = 1;
}

int TWindowMenuMainMenu::get_selected_slot() {
  return selected_slot;
}

void TWindowMenuMainMenu::clear_menu_flags() { state_flags &= 0xfc; }

int TWindowMenuMainMenu::is_flag_set() { return (this->state_flags >> 1) & 0x1; }

int TWindowMenuMainMenu::get_menu_flag() { return this->state_flags & 0x1; }

TMainMenuEntry *TWindowMenuMainMenu::find_active_item_by_id(int id) {
    s32 var_r31;
    TMainMenuEntry *entry;
    s32 var_r29;
    var_r29 = id;
    if (var_r29 == 0x1B) {
        var_r29 = 0x1A;
    }
    entry = entries;
    var_r31 = 0;
loop_3:
    if ((entry->is_item_active() != 0) && ((s8)entry->icon == var_r29)) {
        return entry;
    }
    var_r31 += 1;
    entry += 1;
    if (var_r31 >= 8) {
        return NULL;
    }
    goto loop_3;
}

TMainMenuEntry *TWindowMenuMainMenu::find_free_slot() {
    s32 counter;
    TMainMenuEntry *entry;

    entry = entries;
    counter = 0;
loop_1:
    if (entry->is_item_active() == 0) {
        return entry;
    }
    counter += 1;
    entry += 1;
    if (counter >= 8) {
        return 0;
    }
    goto loop_1;
}

int TWindowMenuMainMenu::find_free_item_slot() {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (slots[i] == 0) return i;
    }
    return 8;
}

s32 TWindowMenuMainMenu::count_active_items() {
    s32 counter;
    TMainMenuEntry *entry;

    entry = entries;
    counter = 0;
loop_1:
    if (entry->is_item_active() == 0) {
        return counter;
    }
    counter += 1;
    entry += 1;
    if (counter >= 8) {
        return 8;
    }
    goto loop_1;
}

void TWindowMenuMainMenu::get_row_position(NJS_POINT2 *row, int index) {
    row->x = 0.0f;
    row->y = 16.0f * (f32)index;
}

s32 TWindowMenuMainMenu::is_not_split_screen() {
    return (u32)__cntlzw(is_split_screen()) >> 5;
}

TMainMenuEntry *TWindowMenuMainMenu::update_if_active(s32 id) {
    TMainMenuEntry *entry;

    entry = append_child_rows(id);
    if (entry != 0) {
        entry->disable_choice();
    }
    return entry;
}

TMainMenuEntry *TWindowMenuMainMenu::append_child_rows(int id) {
    NJS_POINT2 row;
    s32 n;
    TMainMenuEntry *slot;
    n = find_free_item_slot();
    if (n >= 8) {
        return 0;
    }
    get_row_position(&row, n + parked_row_count);
    slot = find_active_item_by_id(id);
    if (slot == 0) {
        slot = find_free_slot();
        if (slot == 0) {
            return 0;
        }
        slot->init_row_entry(&row, id, -(n * 2));
    } else {
        slot->set_row_target(&row);
    }
    slots[n] = slot;
    state_flags &= ~4;
    return slot;
}

void TWindowMenuMainMenu::set_target_y(f32 target_y) {
    if (is_not_split_screen() != 0) {
        target_y += 51.0f;
    } else {
        target_y += 42.0f;
    }
    target_y += 39.0f;
    if (target_size[1] != target_y) {
        target_size[1] = target_y;
        tween_ticks = 8;
    }
}

void TWindowMenuMainMenu::update_scaled_position() {
    set_target_y(16.0f * (f32)count_active_items());
}

void TWindowMenuMainMenu::draw_entries_reversed(WindowDrawContext *context) {
    s32 drawn;
    u8 *row;
    // Walk the enclosing window's storage so the final decrement stays inside it.
    row = reinterpret_cast<u8 *>(this) + offsetof(TWindowMenuMainMenu, entries) + 7 * sizeof(TMainMenuEntry);
    drawn = 0;
    do {
        reinterpret_cast<TMainMenuEntry *>(row)->draw_item_labels(context);
        ++drawn;
        row -= sizeof(TMainMenuEntry);
    } while (drawn < 8);
}


void TWindowMenuMainMenu::draw_frame(WindowDrawContext *frame) {
    TexturedQuad q;
    f32 quad_depth;
    f32 y;
    f32 h;
    f32 step;

    quad_depth = -1.0f / (0.299f + this->draw_depth);
    y = 0.0f;
    h = frame->inner_h;
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(11, frame->color);
    if (is_not_split_screen() != 0) {
        q.x0 = frame->x;
        q.y0 = frame->y + y;
        q.x1 = 18.0f + q.x0;
        q.y1 = 28.0f + q.y0;
        q.u0 = 230.0f / 256.0f;
        q.v0 = 0.0f;
        q.u1 = 248.0f / 256.0f;
        q.v1 = 28.0f / 256.0f;
        frame->transform_quad(&q);
        draw_textured_quad_at_depth(&q.x0, quad_depth);
        y += 28.0f;
        h -= 28.0f;
        q.x0 = frame->x;
        q.y0 = frame->y + y;
        q.x1 = q.x0 + frame->w;
        q.y1 = 23.0f + q.y0;
        q.u0 = 0.0f;
        q.v0 = 80.0f / 256.0f;
        q.u1 = 116.0f / 256.0f;
        q.v1 = 103.0f / 256.0f;
        frame->transform_quad(&q);
        draw_textured_quad_at_depth(&q.x0, quad_depth);
        y += 23.0f;
        h -= 23.0f;
    } else {
        q.x0 = frame->x;
        q.y0 = frame->y + y;
        q.x1 = q.x0 + frame->w;
        q.y1 = 3.0f + (39.0f + q.y0);
        q.u0 = 116.0f / 256.0f;
        q.v0 = 174.0f / 256.0f;
        q.u1 = 0.0f;
        q.v1 = 132.0f / 256.0f;
        frame->transform_quad(&q);
        draw_textured_quad_at_depth(&q.x0, quad_depth);
        y += 42.0f;
        h -= 42.0f;
    }
    h -= 39.0f;
    while (h >= 4.0f) {
        if (h < 16.0f) {
            step = 4.0f;
        } else {
            step = 16.0f;
        }
        q.x0 = frame->x;
        q.y0 = frame->y + y;
        q.x1 = q.x0 + frame->w;
        q.y1 = q.y0 + step;
        q.u0 = 0.0f;
        q.v0 = 103.0f / 256.0f;
        q.u1 = 116.0f / 256.0f;
        q.v1 = (103.0f + step) / 256.0f;
        frame->transform_quad(&q);
        draw_textured_quad_at_depth(&q.x0, quad_depth);
        y += step;
        h -= step;
    }
    q.x0 = frame->x;
    q.y0 = frame->y + y;
    q.x1 = q.x0 + frame->w;
    q.y1 = 39.0f + q.y0;
    q.u0 = 0.0f;
    q.v0 = 135.0f / 256.0f;
    q.u1 = 116.0f / 256.0f;
    q.v1 = 174.0f / 256.0f;
    frame->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, quad_depth);
    TWindowSubStatusDisp::get_player();
}
WindowDrawContext *TWindowMenuMainMenu::setup_content_frame() {
    f32 v;
    WindowDrawContext *r;
    r = WindowDrawContext::open_singleton(frame_position, frame_size, (f32 *)fn_8026CB68(), draw_depth, window_flags);
    if (is_not_split_screen() != 0) {
        v = 51.0f;
    } else {
        v = 39.0f;
    }
    r->set_bounds(10.0f + r->x, r->y + v, (r->x + r->w) - 10.0f, (r->y + r->h) - 39.0f);
    r->color = ((s32)(255.0f * get_transition_progress()) << 24) | 0xFF0000 | 0xFFFF;
    return r;
}

void TWindowMenuMainMenu::update_slide_position() {
    if (is_closed() != 0) {
        set_target_y(0.0f);
        this->tween_ticks = (u32) (4.5f - (f32) this->closing_tick);
        return;
    }
    update_scaled_position();
}

void TWindowMenuMainMenu::handle_cancel() {
    play_sound_effect(0x52F16, 0, 0, 0);
    this->state_flags = (u8) (this->state_flags | 2);
}

void TWindowMenuMainMenu::handle_confirm() {
    TMainMenuEntry *item = slots[(s8)selected_slot];
    if (item != NULL) {
        if (item->flags & 2) {
            play_sound_effect(0x53F06, 0, 0, 0);
            return;
        }
        play_sound_effect(0x52D01, 0, 0, 0);
        state_flags |= 1;
    }
}

void TWindowMenuMainMenu::play_cursor_sound(int delta) {
    int n;
    play_sound_effect(0x54100, 0, 0, 0);
    slots[selected_slot]->kind = 0;
    n = find_free_item_slot();
    selected_slot += delta;
    if (selected_slot < 0) {
        selected_slot = n - 1;
    }
    if (selected_slot > n - 1) {
        selected_slot = 0;
    }
    slots[selected_slot]->kind = 1;
}

void TWindowMenuMainMenu::handle_navigation_input() {
    ControllerInputContext *window_choice_setting;
    if ((TWindowBase::is_window_reveal_complete() != 0) && (this->get_menu_flag() == 0) && (this->is_flag_set() == 0) && !(this->state_flags & 4)) {
        window_choice_setting = &controller_input_state.controllers[is_player_input_active((*(s16 *)&this->client_index))];
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            play_cursor_sound(-1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            play_cursor_sound(1);
        }
        if ((test_pressed_buttons_packed(window_choice_setting, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->handle_confirm();
        }
        if ((this->get_menu_flag() == 0) && ((test_pressed_buttons_packed(window_choice_setting, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0))) {
            this->handle_cancel();
        }
    }
}

}
