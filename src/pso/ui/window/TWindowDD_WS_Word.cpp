// Emit the native Word Select methods in their original order.
#pragma defer_codegen on

#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/math/BinomialCoefficient.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

const char *TWindowDD_WS_Word::class_name = "TWindowDD_WS_Word";





#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"


TWindowDD_WS_WordLayout word_select_page_layout = {
    1, 1,
    {3, {0.0f, 0.0f}, 0.2f, window_dd_color_white, 0x40, NULL},
};
__declspec(section ".data") f32 word_page_position[2] = {word_page_x, word_page_y};
WindowDescriptor word_select_page_descriptor = {
    {word_page_width, word_page_height}, word_page_depth, &word_select_page_layout, 3,
};




TWindowDD_WS_Word *TWindowDD_WS_Word::create(s32 element_list, s32 rows) {
    word_select_page_layout.rows = rows;
    return new TWindowDD_WS_Word(element_list, rows);
}

TWindowDD_WS_Word::TWindowDD_WS_Word(s32 list_id, s32 visible_count)
    : TWindowBase((u8 *)&word_select_page_descriptor, 4, (u8 *)word_page_position) {
    m_name = class_name;
    visible_row_count = visible_count;
    strip_point_index = 0;
    scroll_offset = 0.0f;
    pad_84 = 0.0f;
    state_flags = 0;
    element_list_id = list_id;
    reset_fields();
    load_element_list();
    open_tick = 0x01000000;
}

TWindowDD_WS_Word::~TWindowDD_WS_Word() {
    if (token_ids != NULL) {
        mem_free(token_ids);
        token_ids = NULL;
    }
}

s32 TWindowDD_WS_Word::can_accept_input() {
    return !(this->state_flags & 1);
}

s32 TWindowDD_WS_Word::is_input_enabled() {
    return !(this->state_flags & 1);
}

void TWindowDD_WS_Word::add_scroll_offset(int offset) {
    selected_token_index += offset;
    needs_text_refresh = 1;
    TWindowDD::spawn_window();
}

s32 TWindowDD_WS_Word::get_selected_token_index() { return selected_token_index; }

void TWindowDD_WS_Word::get_cursor_pos(NJS_POINT2 *position) {
    position->x = frame_position[0];
    position->y = (f32)selected_row * window_dd_row_height + frame_position[1];
}

char *TWindowDD_WS_Word::get_selected_row_text() {
    if (entry_list.items != NULL) {
        WindowTextEntry *entry = static_cast<WindowTextEntry *>(get_array_entry(selected_row));
        return entry->get_text();
    }
    return 0;
}

s32 TWindowDD_WS_Word::get_selected_row() { return selected_row; }

s32 TWindowDD_WS_Word::get_scroll_top() const {
    return selected_token_index - selected_row;
}

int TWindowDD_WS_Word::get_selected_id() const {
    if (token_ids != NULL) {
        return token_ids[selected_token_index];
    }
    return 0x685;
}

s16 TWindowDD_WS_Word::get_element_list_id() const {
    return static_cast<s16>(element_list_id);
}

s32 TWindowDD_WS_Word::get_token_count() { return token_count; }

void TWindowDD_WS_Word::set_pos_and_data(f32 x) {
    target_position[0] = x;
    tween_ticks = window_dd_tween_ticks;
}

void TWindowDD_WS_Word::load_element_list() {
    TWindowDDValueList *e;
    s32 i;
    s32 n;
    WindowTextEntry *ent;
    e = TWindowDD::get_element_ptr(element_list_id);
    if (e != NULL) {
        token_count = e->count;
        token_ids = (s16 *)mem_alloc(token_count * 2);
        for (i = 0; i < token_count; i++) {
            token_ids[i] = e->values[i];
        }
    } else {
        token_count = 0;
        token_ids = NULL;
    }
    n = token_count;
    if (visible_row_count < n) {
        n = visible_row_count;
    }
    visible_entry_count = n;
    for (i = 0; i < visible_entry_count; i++) {
        ent = (WindowTextEntry *)get_array_entry(i);
        set_text_entry_string(ent, get_word_select_token_text(token_ids[i]), 0xC0);
        ent->y = i * 20;
        measure_message_text_width_default(ent);
    }
}

void TWindowDD_WS_Word::reset_fields() {
    scroll_offset = 0.0f;
    pad_84 = 0.0f;
    selected_token_index = 0;
    selected_row = 0;
    needs_text_refresh = 1;
}

void TWindowDD_WS_Word::init_layout_entries() {
    word_select_page_layout.rows = visible_row_count;
    init_window_layout_entries(&entry_list, &word_select_page_layout, client_index);
}

void TWindowDD_WS_Word::init_child(s32 list_id) {
    free_child();
    element_list_id = list_id;
    init_layout_entries();
    load_element_list();
    reset_fields();
    needs_text_refresh = 1;
}

void TWindowDD_WS_Word::free_child() {
    if (token_ids != NULL) {
        mem_free(token_ids);
        token_ids = NULL;
    }
    entry_list.destroy_all_items();
    token_count = 0;
    visible_entry_count = 0;
}

void TWindowDD_WS_Word::init_and_mark_text_refresh() {
    init_layout_entries();
    load_element_list();
    needs_text_refresh = 1;
}

#pragma push
#pragma opt_common_subs off
void TWindowDD_WS_Word::run_task() {
    s32 count;
    s32 first_visible;
    s32 index;
    s32 rows;
    s32 last_row;
    s32 last_visible;
    s32 steps;
    s32 steps_up;
    if (can_accept_input() != 0) {
        if (TWindowDD::apply_both_choices(&state_flags, 0x20) != 0) {
            index = selected_token_index;
            if (index < (s32) (token_count - 1)) {
                switch (can_scroll(1)) {
                case 0:
                    selected_row = (s32) (selected_row + 1);
                    break;
                case 1:
                    scroll_offset = (f32) (scroll_offset + window_dd_row_height);
                    break;
                }
                add_scroll_offset(1);
            } else {
                add_scroll_offset((int)(-index));
                selected_row = 0;
                scroll_offset = 0.0f;
            }
        } else if (TWindowDD::apply_both_choices(&state_flags, 0x10) != 0) {
            if ((s32) selected_token_index > 0) {
                switch (can_scroll(-1)) {
                case 0:
                    selected_row = (s32) (selected_row - 1);
                    break;
                case 1:
                    scroll_offset = (f32) (scroll_offset - window_dd_row_height);
                    break;
                }
                add_scroll_offset(-1);
            } else {
                selected_row = (s32) (visible_entry_count - 1);
                add_scroll_offset((int)((token_count - selected_token_index) - 1));
                scroll_offset = (f32) (window_dd_row_height * (f32) -(selected_token_index - selected_row));
            }
        } else if ((TWindowDD::apply_both_choices(&state_flags, 0x10000) != 0) && ((s32) selected_token_index < (s32) (token_count - 1))) {
            if (needs_scroll() != 0) {
                rows = visible_row_count;
                last_row = rows - 1;
                last_visible = selected_token_index + (rows - (selected_row + 1));
                count = token_count;
                steps = last_row;
                if ((s32) (last_visible + last_row) >= count) {
                    steps = (count - last_visible) - 1;
                }
                if (steps <= 0) {
                    selected_row = last_row;
                    add_scroll_offset((int)((token_count - 1) - selected_token_index));
                } else {
                    add_scroll_offset(steps);
                    scroll_offset = (f32) (((f32) steps * window_dd_row_height) + scroll_offset);
                }
            } else {
                selected_row = (s32) (token_count - 1);
                add_scroll_offset((int)((token_count - 1) - selected_token_index));
            }
        } else if ((TWindowDD::apply_both_choices(&state_flags, 0x20000) != 0) && ((s32) selected_token_index > 0)) {
            if (needs_scroll() != 0) {
                steps_up = visible_row_count - 1;
                first_visible = selected_token_index - selected_row;
                if ((first_visible - steps_up) < 0) {
                    steps_up = first_visible;
                }
                if (steps_up <= 0) {
                    selected_row = 0;
                    add_scroll_offset((int)(-selected_token_index));
                } else {
                    add_scroll_offset((int)(-steps_up));
                    scroll_offset = (f32) -(((f32) steps_up * window_dd_row_height) - scroll_offset);
                }
            } else {
                selected_row = 0;
                add_scroll_offset((int)(-selected_token_index));
            }
        }
    }
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
}

#pragma pop

void TWindowDD_WS_Word::use_active_strips() { strip_point_index = 0; }

void TWindowDD_WS_Word::use_dim_strips() { strip_point_index = 2; }

void TWindowDD_WS_Word::enable_input() {
    state_flags &= ~1;
    needs_text_refresh = 1;
}

void TWindowDD_WS_Word::disable_input() {
    state_flags |= 1;
    needs_text_refresh = 1;
}

s32 TWindowDD_WS_Word::needs_scroll() {
    return this->token_count > this->visible_row_count;
}

s32 TWindowDD_WS_Word::can_scroll(s32 direction) {
    s32 selected_row;
    s32 row;
    s32 rows;
    s32 half;

    if (needs_scroll() == 0) {
        return 0;
    }
    rows = this->visible_row_count;
    half = rows / 2;
    if (direction > 0) {
        selected_row = this->selected_row;
        if (selected_row < half) {
            return 0;
        }
        return (this->selected_token_index + (rows - selected_row)) < this->token_count;
    }
    row = this->selected_row;
    if (row >= half) {
        return 0;
    }
    return ((u32) (this->selected_token_index - (row + 1)) >> 0x1FU) ^ 1;
}

void draw_word_row_strips(TWindowDD_WS_Word *self, WindowDrawContext *rect) {
    WindowVertex verts[8];
    WindowVertex *v;
    s32 tex;
    s32 count;
    f32 y1;
    f32 c;
    f32 s;
    f32 v0;
    f32 y0;
    f32 v1;
    f32 frac;
    f32 part;
    f32 yb;
    f32 top;
    f32 bottom;
    f32 step;

    // TWindowDD::get_draw_count(hud_texlist), read inline here
    tex = hud_texlist->textures[2].texture->surface->id;
    if (rect->open_tick < 0) {
        return;
    }
    c = 0.5f * self->frame_size[1] + self->frame_position[1];
    f32 depth = word_select_inverse_depth(self->draw_depth, 0.0f);
    reset_window_vertices(verts, depth, -1);
    copy_window_point_table(verts, self->strip_point_index);
    set_frame_column_vertices_x(rect, verts);
    s = rect->scale[1];
    count = self->visible_row_count;
    top = -(0.5f * self->frame_size[1]);
    y0 = top * s + c;
    bottom = top + window_dd_row_height;
    y1 = bottom * s + c;
    if (self->strip_point_index == 0) {
        v0 = word_row_strip_v;
        v1 = v0 + window_dd_row_height;
    } else {
        v0 = word_row_strip2_v;
        v1 = v0 + window_dd_row_height;
    }
    v0 *= window_dd_texel_scale;
    v1 *= window_dd_texel_scale;
    frac = window_dd_row_height * fractional_part(-self->scroll_offset / window_dd_row_height);
    if (0.0f != frac) {
        count = self->visible_row_count - 1;
        if (frac < 0.0f) {
            part = frac + window_dd_row_height;
        } else {
            part = frac;
            frac -= window_dd_row_height;
        }
        yb = part * s + y0;
        v = verts;
        for (s32 i = 0; i < 4; i++) {
            v[0].y = y0;
            v[0].v = v1 - part * window_dd_texel_scale;
            v[1].y = yb;
            v[1].v = v1;
            v += 2;
        }
        draw_window_vertices(verts, 8, tex, 1);
        y0 = yb;
    }
    if (count > 0) {
        step = window_dd_row_height * s;
        v = verts;
        for (s32 i = 0; i < 4; i++) {
            v[0].v = v0;
            v[1].v = v1;
            v += 2;
        }
        for (s32 i = 0; i < count; i++) {
            y1 = y0 + step;
            v = verts;
            for (s32 j = 0; j < 4; j++) {
                v[0].y = y0;
                v[1].y = y1;
                v += 2;
            }
            draw_window_vertices(verts, 8, tex, 1);
            y0 = y1;
        }
    }
    if (0.0f != frac) {
        yb = 0.5f * self->frame_size[1] * s + c;
        v = verts;
        for (s32 i = 0; i < 4; i++) {
            v[0].y = y1;
            v[0].v = v0;
            v[1].y = yb;
            v[1].v = v0 - frac * window_dd_texel_scale;
            v += 2;
        }
        draw_window_vertices(verts, 8, tex, 1);
    }
    if (self->token_count > 0 && self->is_input_enabled() != 0) {
        depth = word_select_inverse_depth(self->draw_depth, 0.1f);
        reset_window_vertices(verts, depth, -1);
        copy_window_point_table(verts, 1);
        set_frame_column_vertices_x(rect, verts);
        f32 row = (f32)self->selected_row;
        f32 first_y = -(0.5f * self->frame_size[1]);
        y0 = row * window_dd_row_height + first_y;
        s = rect->scale[1];
        bottom = y0 + window_dd_row_height;
        y0 = y0 * s + c;
        y1 = bottom * s + c;
        v = verts;
        for (s32 i = 0; i < 4; i++) {
            v++->y = y0;
            v++->y = y1;
        }
        draw_window_vertices(verts, 8, tex, 1);
    }
}

void TWindowDD_WS_Word::render() {
    WindowDrawContext *entry;
    WindowTextEntry *item;
    s32 idx;
    s32 i;
    s32 j;
    entry = draw_default_entry();
    calc_inner_rect(entry);
    draw_word_row_strips(this, entry);
    if (needs_text_refresh != 0) {
        needs_text_refresh = 0;
        idx = selected_token_index - selected_row;
        for (i = 0; i < visible_entry_count; i++, idx++) {
            item = (WindowTextEntry *)get_array_entry(i);
            set_text_entry_string(item, get_word_select_token_text(token_ids[idx]), 0xC0);
            item->y = (f32)(i * 20);
            measure_message_text_width_default(item);
            item->reveal_all();
            item->color = window_dd_color_white;
        }
        if (is_input_enabled() != 0) {
            for (j = 0; j < visible_entry_count; j++) {
                item = (WindowTextEntry *)get_array_entry(j);
                if (j == selected_row) {
                    item->color = window_dd_color_black;
                }
            }
        }
    }
    entry->inner_y += 1.0f;
    draw_visible_window_entries(this, &entry_list, entry);
}
