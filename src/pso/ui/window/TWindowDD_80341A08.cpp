// Emit the native Word Select methods in their original order.
#pragma defer_codegen on

#include "pso/render/GinjaMaterialState.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_WS_Word.h"
#include "pso/ui/window/TWindowDD_803488A8.h"
#include "pso/ui/window/TWindowDD_80341A08.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/unk/text_803D619C.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

const char *lbl_805D42E0 = "TWindowDD_WS_Word";

extern "C" {

extern const s32 TWindowDD__data_805DFC14;
extern const s32 lbl_805DFC18;
}


extern const f32 TWindowDD__data_805DFB18;
extern const f32 TWindowDD__data_805DFB20;
extern const f32 lbl_805DFB40;
extern const f32 lbl_805DFB44;

#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/WindowLayoutRecord.h"

// Entry layout table of the window: one column, one text record (type 3); the row count is
// written before each build (init_layout_entries, TWindowDD__sub_80342384).
struct TWindowDD_WS_WordLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};

extern const f32 TWindowDD__data_805DFB6C;
extern const f32 lbl_805DFB70;
extern const f32 TWindowDD__data_805DFB74;
extern const f32 lbl_805DFB78;
extern const f32 lbl_805DFC1C;

TWindowDD_WS_WordLayout TWindowDD__data_804EFC50 = {
    1, 1,
    {3, {0.0f, 0.0f}, 0.2f, TWindowDD__data_805DFC14, 0x40, NULL},
};
__declspec(section ".data") f32 lbl_804EFC74[2] = {TWindowDD__data_805DFB6C, lbl_805DFB70};
WindowDescriptor lbl_804EFC7C = {
    {TWindowDD__data_805DFB74, lbl_805DFB78}, lbl_805DFC1C, &TWindowDD__data_804EFC50, 3,
};

struct Elem_80341FFC {
    s16 *data;
    s32 count;
};

struct Entry_80341FFC {
    u8 pad[0xC];
    f32 y;
};

extern "C" {

extern s32 TWindowDD__data_805DFB50;

saddr TWindowDD__sub_80342384(s32 element_list, s32 rows) {
    TWindowDD__data_804EFC50.rows = rows;
    return (saddr)new TWindowDD_WS_Word(element_list, rows);
}

TWindowDD_WS_Word::TWindowDD_WS_Word(s32 list_id, s32 visible_count)
    : TWindowBase((u8 *)&lbl_804EFC7C, 4, (u8 *)lbl_804EFC74) {
    m_name = lbl_805D42E0;
    pad_78 = visible_count;
    pad_64 = 0;
    pad_88 = 0.0f;
    pad_84 = 0.0f;
    m_60 = 0;
    pad_70 = list_id;
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

s32 TWindowDD_WS_Word::sub_80342268() {
    TWindowDD_WS_Word *self = this;
    return !(self->m_60 & 1);
}

s32 TWindowDD_WS_Word::sub_80342254() {
    TWindowDD_WS_Word *self = this;
    return !(self->m_60 & 1);
}

void TWindowDD_WS_Word::add_scroll_offset(int offset) {
    selected_token_index += offset;
    m_8c = 1;
    TWindowDD::spawn_window();
}

s32 TWindowDD::get_field_68() { return this->m_64[1]; }

void TWindowDD_WS_Word::get_cursor_pos(NJS_POINT2 *position) {
    position->x = frame_position[0];
    position->y = (f32)selected_row * TWindowDD__data_805DFB20 + frame_position[1];
}

s32 TWindowDD::update_if_field28_set() {
    if ((u32) this->m_24[1] != 0U) {
        TWindowSubComCard *entry = (TWindowSubComCard *)((TWindowBase *)this)->get_array_entry(m_64[2]);
        return entry->get_field_20();
    }
    return 0;
}

s32 TWindowDD::get_cursor_index() { return this->m_64[2]; }

s32 TWindowDD__sub_8034217C(u8 *value) {
    const TWindowDD_WS_Word *page = reinterpret_cast<const TWindowDD_WS_Word *>(value);
    return page->selected_token_index - page->selected_row;
}

int TWindowDD__sub_80342158(const TWindowDD_WS_Word *page) {
    if (page->token_ids != NULL) {
        return page->token_ids[page->selected_token_index];
    }
    return 0x685;
}

s16 TWindowDD__sub_8034214C(u8 *value) {
    const TWindowDD_WS_Word *page = reinterpret_cast<const TWindowDD_WS_Word *>(value);
    return static_cast<s16>(page->pad_70);
}

s32 TWindowDD::get_field_0x74() { return this->m_64[4]; }

void TWindowDD::set_pos_and_data(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x30) = farg0;
    *(s32 *)((s8 *)arg0 + 0x50) = (s32) TWindowDD__data_805DFB50;
}

void TWindowDD_WS_Word::load_element_list() {
    Elem_80341FFC *e;
    s32 i;
    s32 n;
    Entry_80341FFC *ent;
    e = (Elem_80341FFC *)TWindowDD::get_element_ptr(pad_70);
    if (e != NULL) {
        token_count = e->count;
        token_ids = (s16 *)mem_alloc(token_count * 2);
        for (i = 0; i < token_count; i++) {
            token_ids[i] = e->data[i];
        }
    } else {
        token_count = 0;
        token_ids = NULL;
    }
    n = token_count;
    if (pad_78 < n) {
        n = pad_78;
    }
    visible_entry_count = n;
    for (i = 0; i < visible_entry_count; i++) {
        ent = (Entry_80341FFC *)get_array_entry(i);
        set_text_entry_string((u8 *)ent, get_word_select_token_text(token_ids[i]), 0xC0);
        ent->y = i * 20;
        measure_message_text_width_default(ent);
    }
}

void TWindowDD_WS_Word::reset_fields() {
    pad_88 = 0.0f;
    pad_84 = 0.0f;
    selected_token_index = 0;
    selected_row = 0;
    m_8c = 1;
}

void TWindowDD_WS_Word::init_layout_entries() {
    TWindowDD__data_804EFC50.rows = pad_78;
    init_window_layout_entries(&entry_list, &TWindowDD__data_804EFC50, client_index);
}

void TWindowDD_WS_Word::init_child(s32 list_id) {
    free_child();
    pad_70 = list_id;
    init_layout_entries();
    load_element_list();
    reset_fields();
    m_8c = 1;
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

void TWindowDD_WS_Word::init_and_mark_field8C() {
    init_layout_entries();
    load_element_list();
    m_8c = 1;
}

#pragma push
#pragma opt_common_subs off
void TWindowDD_WS_Word::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    s32 temp_r5;
    s32 var_r30;
    s32 var_r30_2;
    if (sub_80342268() != 0) {
        if (TWindowDD::apply_both_choices((saddr)&m_60, 0x20) != 0) {
            temp_r4 = selected_token_index;
            if (temp_r4 < (s32) (token_count - 1)) {
                switch (can_scroll(1)) {
                case 0:
                    selected_row = (s32) (selected_row + 1);
                    break;
                case 1:
                    pad_88 = (f32) (pad_88 + TWindowDD__data_805DFB20);
                    break;
                }
                add_scroll_offset(1);
            } else {
                add_scroll_offset((int)(-temp_r4));
                selected_row = 0;
                pad_88 = 0.0f;
            }
        } else if (TWindowDD::apply_both_choices((saddr)&m_60, 0x10) != 0) {
            if ((s32) selected_token_index > 0) {
                switch (can_scroll(-1)) {
                case 0:
                    selected_row = (s32) (selected_row - 1);
                    break;
                case 1:
                    pad_88 = (f32) (pad_88 - TWindowDD__data_805DFB20);
                    break;
                }
                add_scroll_offset(-1);
            } else {
                selected_row = (s32) (visible_entry_count - 1);
                add_scroll_offset((int)((token_count - selected_token_index) - 1));
                pad_88 = (f32) (TWindowDD__data_805DFB20 * (f32) -(selected_token_index - selected_row));
            }
        } else if ((TWindowDD::apply_both_choices((saddr)&m_60, 0x10000) != 0) && ((s32) selected_token_index < (s32) (token_count - 1))) {
            if (sub_80341AC0() != 0) {
                temp_r4_2 = pad_78;
                temp_r4_3 = temp_r4_2 - 1;
                temp_r5 = selected_token_index + (temp_r4_2 - (selected_row + 1));
                temp_r3_3 = token_count;
                var_r30 = temp_r4_3;
                if ((s32) (temp_r5 + temp_r4_3) >= temp_r3_3) {
                    var_r30 = (temp_r3_3 - temp_r5) - 1;
                }
                if (var_r30 <= 0) {
                    selected_row = temp_r4_3;
                    add_scroll_offset((int)((token_count - 1) - selected_token_index));
                } else {
                    add_scroll_offset(var_r30);
                    pad_88 = (f32) (((f32) var_r30 * TWindowDD__data_805DFB20) + pad_88);
                }
            } else {
                selected_row = (s32) (token_count - 1);
                add_scroll_offset((int)((token_count - 1) - selected_token_index));
            }
        } else if ((TWindowDD::apply_both_choices((saddr)&m_60, 0x20000) != 0) && ((s32) selected_token_index > 0)) {
            if (sub_80341AC0() != 0) {
                var_r30_2 = pad_78 - 1;
                temp_r3_4 = selected_token_index - selected_row;
                if ((temp_r3_4 - var_r30_2) < 0) {
                    var_r30_2 = temp_r3_4;
                }
                if (var_r30_2 <= 0) {
                    selected_row = 0;
                    add_scroll_offset((int)(-selected_token_index));
                } else {
                    add_scroll_offset((int)(-var_r30_2));
                    pad_88 = (f32) -(((f32) var_r30_2 * TWindowDD__data_805DFB20) - pad_88);
                }
            } else {
                selected_row = 0;
                add_scroll_offset((int)(-selected_token_index));
            }
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    update_fade();
    update_window_entry_list(&entry_list);
}

#pragma pop

void TWindowDD::reset_cursor() { this->m_64[0] = 0; }

void TWindowDD::set_mode_2() { this->m_64[0] = 2; }

void TWindowDD__sub_80341AF8(u8 *value) {
    TWindowDD_WS_Word *page = reinterpret_cast<TWindowDD_WS_Word *>(value);
    page->m_60 &= ~1;
    page->m_8c = 1;
}

void TWindowDD__sub_80341AE0(u8 *value) {
    TWindowDD_WS_Word *page = reinterpret_cast<TWindowDD_WS_Word *>(value);
    page->m_60 |= 1;
    page->m_8c = 1;
}

s32 TWindowDD_WS_Word::sub_80341AC0() {
    return this->token_count > this->pad_78;
}

s32 TWindowDD_WS_Word::can_scroll(s32 arg1) {
    s32 selected_row;
    s32 temp_r3;
    s32 temp_r4;
    s32 temp_r5;

    if (sub_80341AC0() == 0) {
        return 0;
    }
    temp_r4 = this->pad_78;
    temp_r5 = temp_r4 / 2;
    if (arg1 > 0) {
        selected_row = this->selected_row;
        if (selected_row < temp_r5) {
            return 0;
        }
        return (this->selected_token_index + (temp_r4 - selected_row)) < this->token_count;
    }
    temp_r3 = this->selected_row;
    if (temp_r3 >= temp_r5) {
        return 0;
    }
    return ((u32) (this->selected_token_index - (temp_r3 + 1)) >> 0x1FU) ^ 1;
}

void TWindowDD__sub_80341674(TWindowDD_WS_Word *self, WindowDrawContext *rect) {
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

    // TWindowDD::get_draw_count(hud_texlist), read inline here (0x80348AE8 is the same load chain)
    tex = hud_texlist->textures[2].texture->surface->id;
    if (rect->open_tick < 0) {
        return;
    }
    c = 0.5f * self->frame_size[1] + self->frame_position[1];
    f32 depth = TWindowDD__sub_80348AD4(self->draw_depth, 0.0f);
    ((TWindowDD *)verts)->reset_entries(depth, -1);
    ((TWindowDD *)verts)->copy_point_table(self->pad_64);
    TWindowDD__sub_80348A2C(rect, verts);
    s = rect->scale[1];
    count = self->pad_78;
    top = -(0.5f * self->frame_size[1]);
    y0 = top * s + c;
    bottom = top + TWindowDD__data_805DFB20;
    y1 = bottom * s + c;
    if (self->pad_64 == 0) {
        v0 = lbl_805DFB40;
        v1 = v0 + TWindowDD__data_805DFB20;
    } else {
        v0 = lbl_805DFB44;
        v1 = v0 + TWindowDD__data_805DFB20;
    }
    v0 *= TWindowDD__data_805DFB18;
    v1 *= TWindowDD__data_805DFB18;
    frac = TWindowDD__data_805DFB20 * fn_803D6308(-self->pad_88 / TWindowDD__data_805DFB20);
    if (0.0f != frac) {
        count = self->pad_78 - 1;
        if (frac < 0.0f) {
            part = frac + TWindowDD__data_805DFB20;
        } else {
            part = frac;
            frac -= TWindowDD__data_805DFB20;
        }
        yb = part * s + y0;
        v = verts;
        for (s32 i = 0; i < 4; i++) {
            v[0].y = y0;
            v[0].v = v1 - part * TWindowDD__data_805DFB18;
            v[1].y = yb;
            v[1].v = v1;
            v += 2;
        }
        ((TWindowDD *)verts)->draw_transformed_primitive(8, tex, 1);
        y0 = yb;
    }
    if (count > 0) {
        step = TWindowDD__data_805DFB20 * s;
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
            ((TWindowDD *)verts)->draw_transformed_primitive(8, tex, 1);
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
            v[1].v = v0 - frac * TWindowDD__data_805DFB18;
            v += 2;
        }
        ((TWindowDD *)verts)->draw_transformed_primitive(8, tex, 1);
    }
    if (self->token_count > 0 && self->sub_80342254() != 0) {
        depth = TWindowDD__sub_80348AD4(self->draw_depth, 0.1f);
        ((TWindowDD *)verts)->reset_entries(depth, -1);
        ((TWindowDD *)verts)->copy_point_table(1);
        TWindowDD__sub_80348A2C(rect, verts);
        f32 row = (f32)self->selected_row;
        f32 first_y = -(0.5f * self->frame_size[1]);
        y0 = row * TWindowDD__data_805DFB20 + first_y;
        s = rect->scale[1];
        bottom = y0 + TWindowDD__data_805DFB20;
        y0 = y0 * s + c;
        y1 = bottom * s + c;
        v = verts;
        for (s32 i = 0; i < 4; i++) {
            v++->y = y0;
            v++->y = y1;
        }
        ((TWindowDD *)verts)->draw_transformed_primitive(8, tex, 1);
    }
}

void TWindowDD_WS_Word::render() {
    TWindowDD_WS_Word *self = this;
    WindowDrawContext *entry;
    WindowTextEntry *item;
    s32 idx;
    s32 i;
    s32 j;
    entry = self->draw_default_entry();
    self->calc_inner_rect(entry);
    TWindowDD__sub_80341674(self, entry);
    if (self->m_8c != 0) {
        self->m_8c = 0;
        idx = self->selected_token_index - self->selected_row;
        for (i = 0; i < self->visible_entry_count; i++, idx++) {
            item = (WindowTextEntry *)self->get_array_entry(i);
            set_text_entry_string((u8 *)item, get_word_select_token_text(self->token_ids[idx]), 0xC0);
            item->y = (f32)(i * 20);
            measure_message_text_width_default(item);
            ((TWindowHelpItem *)item)->reset_float_field();
            item->color = TWindowDD__data_805DFC14;
        }
        if (self->sub_80342254() != 0) {
            for (j = 0; j < self->visible_entry_count; j++) {
                item = (WindowTextEntry *)self->get_array_entry(j);
                if (j == self->selected_row) {
                    item->color = lbl_805DFC18;
                }
            }
        }
    }
    entry->inner_y += 1.0f;
    draw_visible_window_entries(self, &self->entry_list, entry);
}
}
