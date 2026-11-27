#include "pso/render/ColorLineList.h"
#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/ChatShortcuts.h"
#include "pso/ui/font/MenuFontGlyphs.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/ListPageIndicator.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/TextureState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/ControllerInput.h"


/* Layout table of the soft keyboard: one 16-column key-code grid per page. */

#include <stddef.h>
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/system/SoundEffect.h"
#include "pso/network/client_id.h"
#include "pso/render/ColorLineList.h"
#include "pso/system/TLanguage.h"


WindowDescriptor soft_keyboard_window_and_action_data = { {307.0f, 161.0f}, 50040.0f, NULL, 0x803 };


const char *TWindowKeyBoardSoft::class_name = "TWindowKeyBoardSoft";

/* Per key class (indexed through soft_keyboard_key_class): steps back to the class's first column,
   and soft_keyboard_key_columns_to_last the columns left to its last one (read from the cursor moves in handle_cursor_move). */
const s8 soft_keyboard_key_first_column_offsets[20] = { 0, 0, 0, -1, 0, -1, -2, -3, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, 0, 0 };
const u8 soft_keyboard_key_columns_to_last[20] = { 0, 0, 1, 0, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0 };
const KeyUV keyboard_key_frame_uv_table[3] = { { 185.0f, 0.0f }, { 185.0f, 119.0f }, { 185.0f, 141.0f } };

/* Function keys below the character grid: grid cell, size and texture origin. */
const NJS_POINT2 soft_keyboard_button_cells[10] = {
    { 0.0f, 6.0f }, { 12.0f, 6.0f }, { 0.0f, 5.0f }, { 0.0f, 0.0f }, { 14.0f, 0.0f },
    { 2.0f, 6.0f }, { 0.0f, 1.0f }, { 0.0f, 2.0f }, { 0.0f, 3.0f }, { 0.0f, 4.0f },
};
const NJS_POINT2 soft_keyboard_button_sizes[10] = {
    { 37.0f, 18.0f }, { 37.0f, 18.0f }, { 37.0f, 18.0f }, { 37.0f, 18.0f }, { 37.0f, 18.0f },
    { 66.0f, 18.0f }, { 18.0f, 18.0f }, { 18.0f, 18.0f }, { 18.0f, 18.0f }, { 18.0f, 18.0f },
};
const KeyUV soft_keyboard_button_uvs[10] = {
    { 62.0f, 0.0f }, { 62.0f, 18.0f }, { 62.0f, 36.0f }, { 62.0f, 54.0f }, { 62.0f, 72.0f },
    { 62.0f, 108.0f }, { 107.0f, 0.0f }, { 107.0f, 18.0f }, { 107.0f, 36.0f }, { 107.0f, 54.0f },
};

void TWindowKeyBoardSoft::calc_cursor_step(s32 *first_page, s32 *last_page) {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        if ((get_flag_bit5() != 0) || (get_flag_bit6() != 0) || (is_cursor_locked() != 0)) {
            *first_page = 4;
            *last_page = 4;
            return;
        }
        if (get_flag_bit0() != 0) {
            *first_page = 4;
            *last_page = 5;
            return;
        }
        *first_page = 0;
        *last_page = 5;
        return;
    case LANGUAGE_ENGLISH:
        if ((get_flag_bit5() != 0) || (get_flag_bit6() != 0) || (is_cursor_locked() != 0)) {
            *first_page = 0;
            *last_page = 0;
            return;
        }
        *first_page = 0;
        *last_page = 1;
        return;
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        if ((get_flag_bit5() != 0) || (get_flag_bit6() != 0) || (is_cursor_locked() != 0)) {
            *first_page = 0;
            *last_page = 0;
            return;
        }
        if (get_flag_bit0() != 0) {
            *first_page = 0;
            *last_page = 1;
            return;
        }
        *first_page = 0;
        *last_page = 2;
        return;
    }
}

#pragma push
#pragma fp_contract on
s32 TWindowKeyBoardSoft::get_cursor_key() {
    s32 idx = calc_key_index(cursor_column, cursor_row);
    return idx + soft_keyboard_key_first_column_offsets[soft_keyboard_key_class[idx]];
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TWindowKeyBoardSoft::calc_key_x(s32 col, s32 row) {
  f32 key_width;
  s32 count;
  s32 first_col;
  s32 key;
  key = calc_key_index(col, row);
  first_col = col + soft_keyboard_key_first_column_offsets[soft_keyboard_key_class[key]];
  get_key_style((int) key, &count, NULL);
  key_width = calc_key_coord(count);
  return 1.0f + ((19.0f * ((f32) first_col)) + (0.5f * key_width));
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TWindowKeyBoardSoft::calc_key_index(s32 col, s32 row) {
    return col + (row * 0x10);
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TWindowKeyBoardSoft::get_tab_bar_x() {
    SoftKeyboardLayout *layout = (SoftKeyboardLayout *)soft_keyboard_layouts;
    return -((0.5f * (f32) (layout->page_count * layout->tab_width)) - 153.0f);
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TWindowKeyBoardSoft::calc_key_coord(s32 count) {
    return (19.0f * (f32) count) + 1.0f;
}
#pragma pop

void TWindowKeyBoardSoft::get_key_style(s32 key, s32 *count, u32 *color) {
    s32 n;
    u32 c;
    switch (soft_keyboard_key_class[key]) {
    case 0:
        n = 1;
        c = 0xFF173D84;
        break;
    case 1:
        n = 1;
        c = 0xFF621784;
        break;
    case 2:
    case 3:
        n = 2;
        c = 0xFF6A6E13;
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        n = 4;
        c = 0xFF4F700C;
        break;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
        n = 10;
        c = 0xFF842317;
        break;
    }
    if (count != NULL) {
        *count = n;
    }
    if (color != NULL) {
        *color = c;
    }
}

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::handle_backspace_button(s32 port) {
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0) && (m_control != NULL)) {
        this->state_flags = (s32) (this->state_flags & 0xFFFFFFEF);
        play_sound_effect(0x52F16, 0, 0, 0);
        m_control->handle_backspace();
    }
}
#pragma pop

void TWindowKeyBoardSoft::update_keyboard_child_input_from_controller(s32 port) {
    TWindowKeyBoardBase *control;
    if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 0x400) != 0) {
        control = m_control;
        if (control != NULL) {
            control->update_input_state2();
            if (m_control->is_key_state_2() != 0) {
                state_flags |= 0x10;
            }
        }
    }
}

void TWindowKeyBoardSoft::handle_key_press(s32 port) {
    SoftKeyboardLayout *layout = (SoftKeyboardLayout *)soft_keyboard_layouts;
    static void (TWindowKeyBoardBase::*key_actions[])() = {
        &TWindowKeyBoardBase::key_enter,  &TWindowKeyBoardBase::key_backspace,  &TWindowKeyBoardBase::key_clear,
        &TWindowKeyBoardBase::key_f1,  &TWindowKeyBoardBase::key_f2,  &TWindowKeyBoardBase::key_f3,
        &TWindowKeyBoardBase::key_f4,  &TWindowKeyBoardBase::key_f5,  &TWindowKeyBoardBase::key_f6,
        &TWindowKeyBoardBase::key_f7,  &TWindowKeyBoardBase::key_f8, &TWindowKeyBoardBase::key_f9,
        &TWindowKeyBoardBase::key_f10, &TWindowKeyBoardBase::key_f11, &TWindowKeyBoardBase::key_f12,
        &TWindowKeyBoardBase::key_right, &TWindowKeyBoardBase::key_left, &TWindowKeyBoardBase::key_up,
        &TWindowKeyBoardBase::key_down, &TWindowKeyBoardBase::key_space, &TWindowKeyBoardBase::key_delete,
        &TWindowKeyBoardBase::key_escape,
    };
    u16 code;

    if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 4) == 0) {
        return;
    }
    if (m_control == NULL) {
        return;
    }
    if (!(state_flags & 1)) {
        update_focus_flags();
    }
    spawn_key_effect(cursor_column, cursor_row);
    if (state_flags & 0x10) {
        m_control->key_enter();
        if (m_control->is_key_state_2() == 0) {
            state_flags &= ~0x10;
        }
        return;
    }
    code = *(layout->pages[layout_page] + cursor_column + cursor_row * 16);
    if (code >= 3 && code <= 14) {
        if (m_control->get_flag62_bit8() != 0) {
            play_sound_effect(0x53F06, 0, 0, 0);
        } else if (*(u32 *)get_chat_shortcut(code + 5) != 3) {
            play_sound_effect(0x52D01, 0, 0, 0);
        }
    } else if (code == 2 && (state_flags & 8)) {
        play_sound_effect(0x53F06, 0, 0, 0);
    } else {
        play_sound_effect(0x52D01, 0, 0, 0);
    }
    if (code < 0x20) {
        if (code < 22) {
            (m_control->*key_actions[code])();
        }
        return;
    }
    if (get_flag_bit5() != 0 && (code < 'A' || code > 'Z')) {
        return;
    }
    if (get_flag_bit6() != 0 && TWindowKeyBoardBase::is_alnum(code) == 0) {
        return;
    }
    if (is_cursor_locked() != 0 && (code < '0' || code > '9')) {
        return;
    }
    m_control->set_input_mode(2);
    m_control->insert_character(code);
}

void TWindowKeyBoardSoft::handle_cursor_move(s32 port) {
    s8 dx = 0;
    s8 dy = 0;
    ControllerInputContext *input;
    if (state_flags & 2) {
        input = &controller_input_state.controllers[port];
        if (test_buttons_press_or_repeat(input, 0xF0, 6, 2) == 0) {
            return;
        }
        if (test_buttons_press_or_repeat(input, 0x10, 6, 2) != 0) {
            dy = -1;
        }
        if (test_buttons_press_or_repeat(input, 0x20, 6, 2) != 0) {
            dy++;
        }
        if (test_buttons_press_or_repeat(input, 0x40, 6, 2) != 0) {
            dx = -1;
        }
        if (test_buttons_press_or_repeat(input, 0x80, 6, 2) != 0) {
            dx++;
        }
    } else {
        input = &controller_input_state.controllers[port];
        if (test_buttons_press_or_repeat_color(input, 0xF0, 6, 2) == 0) {
            return;
        }
        if (test_buttons_press_or_repeat_color(input, 0x10, 6, 2) != 0) {
            dy = -1;
        }
        if (test_buttons_press_or_repeat_color(input, 0x20, 6, 2) != 0) {
            dy++;
        }
        if (test_buttons_press_or_repeat_color(input, 0x40, 6, 2) != 0) {
            dx = -1;
        }
        if (test_buttons_press_or_repeat_color(input, 0x80, 6, 2) != 0) {
            dx++;
        }
    }
    play_sound_effect(0x54100, 0, 0, 0);
    if (state_flags & 0x10) {
        if (dx > 0) {
            m_control->key_right();
        } else if (dx < 0) {
            m_control->key_left();
        }
        if (dy > 0) {
            m_control->key_down();
        } else if (dy < 0) {
            m_control->key_up();
        }
        return;
    }
    if (dx > 0) {
        cursor_column += soft_keyboard_key_columns_to_last[soft_keyboard_key_class[(s8)cursor_column + (s8)cursor_row * 16]] + 1;
    }
    if (dx < 0) {
        cursor_column += soft_keyboard_key_first_column_offsets[soft_keyboard_key_class[(s8)cursor_column + (s8)cursor_row * 16]] - 1;
    }
    cursor_row += dy;
    if ((s8)cursor_column < 0) {
        cursor_column += 16;
    }
    if ((s8)cursor_column >= 16) {
        cursor_column -= 16;
    }
    if ((s8)cursor_row < 0) {
        cursor_row += 7;
    }
    if ((s8)cursor_row >= 7) {
        cursor_row -= 7;
    }
}

void TWindowKeyBoardSoft::reset_layout_page() {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        layout_page = 4;
        break;
    case LANGUAGE_ENGLISH:
        layout_page = 0;
        break;
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        layout_page = 0;
        break;
    }
    update_focus_flags();
}

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::update_focus_flags() {
    if (current_language != LANGUAGE_JAPANESE) {
        if ((s32) current_language < 0) {
            return;
        }
        return;
    }
    if (layout_page == 0) {
        m_control->composition_flags |= 1;
        m_control->composition_flags &= 0xFFFFFFBF;
        return;
    }
    m_control->composition_flags &= 0xFFFFFFFE;
    m_control->composition_flags |= 0x40;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::handle_page_cycle_input(s32 port) {
    s32 first_page;
    s32 last_page;
    ControllerInputContext *controller;
    controller = &controller_input_state.controllers[port];
    if (test_pressed_buttons_packed(controller, 0x30000) != 0) {
        play_sound_effect(0x54100, 0, 0, 0);
        calc_cursor_step(&first_page, &last_page);
        if (test_pressed_buttons_packed(controller, 0x10000) != 0) {
            this->page_slide = 10.0f;
            layout_page = layout_page + 1;
        }
        if (test_pressed_buttons_packed(controller, 0x20000) != 0) {
            this->page_slide = -10.0f;
            layout_page = layout_page - 1;
        }
        if (layout_page < first_page) {
            layout_page = last_page;
        }
        if (layout_page > last_page) {
            layout_page = first_page;
        }
        this->update_focus_flags();
    }
}
#pragma pop

void TWindowKeyBoardSoft::set_mode3() {
    TWindowKeyBoardBase *control;
    state_flags |= 0x80;
    control = m_control;
    if (control != NULL) {
        control->set_mode3();
        set_mode0();
    }
}

void TWindowKeyBoardSoft::set_mode2() {
    TWindowKeyBoardBase *control;
    state_flags |= 0x40;
    control = m_control;
    if (control != NULL) {
        control->set_mode2();
        set_mode0();
    }
}

void TWindowKeyBoardSoft::set_mode1() {
    state_flags |= 0x20;
    if (m_control != NULL) {
        m_control->set_mode1();
        set_mode0();
    }
}

void TWindowKeyBoardSoft::set_mode0() {
    if (m_control != NULL) {
        state_flags |= 1;
        m_control->set_mode0();
        reset_layout_page();
    }
}

void TWindowKeyBoardSoft::update_close_mode() {
    if (m_control != NULL) {
        m_control->update_close_mode();
        update_focus_flags();
    }
}

s32 TWindowKeyBoardSoft::hit_test_relative(WindowDrawContext *ctx, TexturedQuad *quad) {
    f32 y0;
    f32 x0;
    y0 = quad->y0;
    x0 = quad->x0;
    return this->get_key_reveal_ratio(ctx, x0 - ctx->x, y0 - ctx->y, quad->x1 - x0, quad->y1 - y0) >= 1.0f;
}

f32 TWindowKeyBoardSoft::get_key_reveal_ratio(WindowDrawContext *context, f32 x, f32 y, f32 width, f32 height) {
    f32 t;
    f32 v;

    t = get_normalized_progress();
    if (t >= 1.0f) {
        return 1.0f;
    }
    v = (t * (context->w + context->h)) - (x + y);
    if (v <= 0.0f) {
        return 0.0f;
    }
    v = v / (width + height);
    if (v >= 1.0f) {
        v = 1.0f;
    }
    return v;
}

#pragma push
#pragma fp_contract on
void TWindowKeyBoardSoft::spawn_key_effect(s32 col, s32 row) {
    s32 type;
    NJS_POINT2 pos;
    s16 kind;

    get_key_style(calc_key_index(col, row), &type, 0);
    pos.x = this->frame_position[0] + calc_key_x(col, row);
    pos.y = 26.0f + (10.0f + (19.0f * (f32)row + this->frame_position[1]));
    switch (type) {
    case 1:
        kind = 3;
        break;
    case 2:
        kind = 4;
        break;
    case 4:
        kind = 5;
        break;
    case 10:
        kind = 6;
        break;
    }
    TWindowEffectLight::create(&pos, kind, local_client_id);
}
#pragma pop


#pragma push
#pragma fp_contract on
#pragma pool_data off
void TWindowKeyBoardSoft::draw_key_labels(WindowDrawContext *ctx) {
    u32 tab_color;
    u32 page;
    s32 cursor;
    s32 first_page;
    u32 i;
    u32 row;
    s32 last_page;
    u16 *keys;
    u32 col;
    f32 depth;
    SoftKeyboardLayout *layout;
    s32 key;
    f32 tab_x;
    TexturedQuad q;
    u32 color;

    layout = (SoftKeyboardLayout *)soft_keyboard_layouts;
    depth = -1.0f / (0.1196f + ctx->depth);
    cursor = this->get_cursor_key();
    keys = layout->pages[layout_page];
    reset_gauge(NULL);
    for (row = 0; row < 7; row++) {
        for (col = 0; col < 16; col++) {
            u16 code = *keys++;
            if (code < 0x20) {
                continue;
            }
            if (this->get_flag_bit5() != 0 && (code < 'A' || code > 'Z')) {
                code = 22;
            }
            if (this->get_flag_bit6() != 0 && TWindowKeyBoardBase::is_alnum(code) == 0) {
                code = 22;
            }
            if (this->is_cursor_locked() != 0 && (code < '0' || code > '9')) {
                code = 22;
            }
            if (code != 22) {
                u8 width;
                code = map_char_to_font_code(code);
                key = calc_key_index(col, row);
                color = key == cursor ? 0xFF000000 : 0xFF999999;
                q.x0 = 1.0f + (1.0f + (19.0f * (f32)col + ctx->x));
                q.y0 = 1.0f + (26.0f + (ctx->y + 19.0f * (f32)row));
                width = bind_menu_font_glyph(code, &q, color);
                q.x0 = 0.5f * (f32)(18 - width) + q.x0;
                set_glyph_quad_extents(width, &q);
                if (hit_test_relative(ctx, &q) != 0) {
                    ctx->transform_quad(&q);
                    draw_textured_quad_at_depth(&q.x0, depth);
                }
            }
        }
    }
    end_render_forward();
    begin_screen_draw(1);
    TWindowSubStatusDisp::render_forward();
    set_draw_texture_and_color(0, 0xFF999999);

    key = calc_key_index(2, 0);
    for (i = 0; i < 12; i++, key++) {
        q.x0 = 1.0f + (1.0f + (19.0f * (i + 2) + ctx->x));
        q.y0 = 1.0f + (26.0f + ctx->y);
        q.x1 = 18.0f + q.x0;
        q.y1 = 18.0f + q.y0;
        q.u0 = 18.0f * (f32)i / 256.0f;
        q.v0 = 0.0f;
        q.u1 = 18.0f * (i + 1) / 256.0f;
        q.v1 = 18.0f / 256.0f;
        if (hit_test_relative(ctx, &q) != 0) {
            set_constant_material_color(key == cursor ? 0xFF000000 : 0xFF999999);
            ctx->transform_quad(&q);
            draw_textured_quad_at_depth(&q.x0, depth);
        }
    }
    TWindowSubStatusDisp::begin_render();
    set_draw_texture_and_color(3, 0xFF999999);

    tab_x = get_tab_bar_x();
    calc_cursor_step(&first_page, &last_page);
    for (page = 0; page < layout->page_count; page++) {
        if (page == layout_page) {
            tab_color = 0xFF000000;
        } else if (page < first_page) {
            tab_color = 0xFF646464;
        } else if (page > last_page) {
            tab_color = 0xFF646464;
        } else {
            tab_color = 0xFF999999;
        }
        q.x0 = 1.0f + (ctx->x + tab_x);
        q.y0 = 1.0f + (-1.0f + ctx->y);
        q.x1 = (q.x0 + (f32)layout->tab_width) - 2.0f;
        q.y1 = 18.0f + q.y0;
        q.u0 = 0.0f;
        q.v0 = 18.0f * (f32)page / 128.0f;
        q.u1 = ((f32)layout->tab_width - 2.0f) / 128.0f;
        q.v1 = 18.0f * (page + 1) / 128.0f;
        if (hit_test_relative(ctx, &q) != 0) {
            ctx->transform_quad(&q);
            set_constant_material_color(tab_color);
            draw_textured_quad_at_depth(&q.x0, depth);
        }
        tab_x += (f32)layout->tab_width;
    }

    for (i = 0; i < 10; i++) {
        f32 x;
        key = calc_key_index((s32)soft_keyboard_button_cells[i].x, (s32)soft_keyboard_button_cells[i].y);
        color = key == cursor ? 0xFF000000 : 0xFF999999;
        x = ctx->x + calc_key_x((s32)soft_keyboard_button_cells[i].x, (s32)soft_keyboard_button_cells[i].y);
        q.x0 = x - 0.5f * soft_keyboard_button_sizes[i].x;
        q.y0 = 1.0f + (26.0f + (19.0f * soft_keyboard_button_cells[i].y + ctx->y));
        q.x1 = q.x0 + soft_keyboard_button_sizes[i].x;
        q.y1 = q.y0 + soft_keyboard_button_sizes[i].y;
        q.u0 = soft_keyboard_button_uvs[i].u / 128.0f;
        q.v0 = soft_keyboard_button_uvs[i].v / 128.0f;
        q.u1 = (soft_keyboard_button_uvs[i].u + soft_keyboard_button_sizes[i].x) / 128.0f;
        q.v1 = (soft_keyboard_button_uvs[i].v + soft_keyboard_button_sizes[i].y) / 128.0f;
        if (hit_test_relative(ctx, &q) != 0) {
            set_constant_material_color(color);
            ctx->transform_quad(&q);
            draw_textured_quad_at_depth(&q.x0, depth);
        }
    }
    end_screen_draw();
}
#pragma pop

void TWindowKeyBoardSoft::draw_key_area_borders(WindowDrawContext *ctx) {
    ColorLineVertex v[5];
    u32 col[5];
    ColorLineList d;
    f32 depth;
    u8 *res;

    depth = 0.0598f + ctx->depth;
    res = soft_keyboard_layouts;
    d.verts = v;
    d.colors = col;
    d.tex = NULL;
    d.colors[0] = (ctx->color & 0xFF000000) | 0xA6B3;
    d.colors[1] = d.colors[0];
    d.colors[2] = d.colors[0];
    d.colors[3] = d.colors[0];
    d.colors[4] = d.colors[0];
    d.count = 5;
    v[0].x = (1.0f + ctx->x) - 1.0f;
    v[0].y = (26.0f + ctx->y) - 1.0f;
    v[1].x = 3.0f + (304.0f + v[0].x);
    v[1].y = v[0].y;
    v[2].x = v[1].x;
    v[2].y = 3.0f + (133.0f + v[0].y);
    v[3].x = v[0].x;
    v[3].y = v[2].y;
    ctx->scale_point_about_pivot(&v[0].x);
    ctx->scale_point_about_pivot(&v[1].x);
    ctx->scale_point_about_pivot(&v[2].x);
    ctx->scale_point_about_pivot(&v[3].x);
    v[4].x = v[0].x;
    v[4].y = v[0].y;
    draw_color_lines(&d, 5, 0x14, depth);
    v[0].x = (ctx->x + get_tab_bar_x()) - 1.0f;
    v[0].y = (-1.0f + ctx->y) - 1.0f;
    v[1].x = 3.0f + (v[0].x + (f32)(res[0] * res[1]));
    v[1].y = v[0].y;
    v[2].x = 3.0f + (v[0].x + (f32)(res[0] * res[1]));
    v[2].y = 2.0f + (20.0f + v[0].y);
    v[3].x = v[0].x;
    v[3].y = v[2].y;
    ctx->scale_point_about_pivot(&v[0].x);
    ctx->scale_point_about_pivot(&v[1].x);
    ctx->scale_point_about_pivot(&v[2].x);
    ctx->scale_point_about_pivot(&v[3].x);
    v[4].x = v[0].x;
    v[4].y = v[0].y;
    draw_color_lines(&d, 5, 0x14, depth);
}

void TWindowKeyBoardSoft::draw_key_frame(WindowDrawContext *context, f32 x0, f32 y, f32 w, f32 scale, u32 color, s32 idx) {
    TexturedQuad q;
    f32 v;
    f32 y2;
    f32 x2;
    f32 x3;
    f32 x4;
    const KeyUV *uv;

    v = get_key_reveal_ratio(context, x0, y, w, 20.0f);
    if (v <= 0.0f) {
        return;
    }
    if (v < 1.0f) {
        color = ((u32)(255.0f * v) << 24) | (color & 0x00FFFFFF);
    }
    x0 += context->x;
    y += context->y;
    uv = &keyboard_key_frame_uv_table[idx];
    set_constant_material_color(color);
    x2 = 10.0f + x0;
    y2 = 20.0f + y;
    q.x0 = x0;
    q.y0 = y;
    q.x1 = x2;
    q.y1 = y2;
    q.u0 = uv->u / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = (10.0f + uv->u) / 256.0f;
    q.v1 = (20.0f + uv->v) / 256.0f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, scale);
    x3 = x0 + w;
    x4 = x3 - 10.0f;
    q.x0 = x4;
    q.y0 = y;
    q.x1 = x3;
    q.y1 = y2;
    q.u0 = (10.0f + uv->u) / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = (20.0f + uv->u) / 256.0f;
    q.v1 = (20.0f + uv->v) / 256.0f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, scale);
    if (w <= 20.0f) {
        return;
    }
    q.x0 = x2;
    q.y0 = y;
    q.x1 = x4;
    q.y1 = y2;
    q.u0 = (10.0f + uv->u) / 256.0f;
    q.v0 = uv->v / 256.0f;
    q.u1 = (10.0f + uv->u) / 256.0f;
    q.v1 = (20.0f + uv->v) / 256.0f;
    context->transform_quad(&q);
    draw_textured_quad_at_depth(&q.x0, scale);
}

#pragma push
#pragma fp_contract on
/* Key frames of the character grid and the page tabs, then the tab bar ends. */
void TWindowKeyBoardSoft::draw_key_frames(WindowDrawContext *ctx) {
    s32 cursor;
    SoftKeyboardLayout *layout = (SoftKeyboardLayout *)soft_keyboard_layouts;
    f32 depth = -1.0f / ctx->depth;
    s32 i;
    s32 j;
    s32 key;
    s32 count;
    u32 color;
    s32 frame;
    f32 tab_x;
    s32 first_page;
    s32 last_page;

    cursor = this->get_cursor_key();
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(0, -1);
    for (j = 0; j < 7; j++) {
        for (i = 0; i < 16; i += count) {
            key = calc_key_index(i, j);
            get_key_style(key, &count, &color);
            f32 w = calc_key_coord(count);
            if (key == cursor) {
                color = 0xFFFFFFFF;
                frame = 1;
            } else {
                frame = 0;
            }
            draw_key_frame(ctx, 19.0f * (f32)i + 1.0f, 19.0f * (f32)j + 26.0f, w, depth, color, frame);
        }
    }

    tab_x = get_tab_bar_x();
    calc_cursor_step(&first_page, &last_page);
    for (i = 0; i < layout->page_count; i++) {
        if (i == layout_page) {
            color = 0xFFFFFFFF;
            frame = 2;
        } else {
            if (i < first_page) {
                color = 0xFF4D4D4D;
            } else if (i > last_page) {
                color = 0xFF4D4D4D;
            } else {
                color = 0xFF0C5B38;
            }
            frame = 0;
        }
        draw_key_frame(ctx, tab_x, -1.0f, layout->tab_width + 1, depth, color, frame);
        tab_x += (f32)layout->tab_width;
    }

    set_constant_material_color(ctx->color);
    tab_x = get_tab_bar_x();
    draw_page_arrow_left(ctx, (ctx->x + tab_x) - 34.0f, 3.0f + (-1.0f + ctx->y), depth, page_slide);
    tab_x += 1.0f + (f32)(layout->tab_width * layout->page_count);
    draw_page_arrow_right(ctx, 5.0f + (ctx->x + tab_x),
                3.0f + (-1.0f + ctx->y), depth, page_slide);
    end_screen_draw();
}
#pragma pop

void TWindowKeyBoardSoft::render() {
    WindowDrawContext *ctx;
    ctx = (WindowDrawContext *)(draw_default_entry());
    draw_key_frames(ctx);
    draw_key_area_borders(ctx);
    draw_key_labels(ctx);
}

#pragma push
#pragma fp_contract on


void TWindowKeyBoardSoft::run_task() {
    s32 port;

    if (m_control != NULL) {
        if ((this->is_open_and_unblocked() != 0) && (m_control->is_confirmed() == 0)) {
            port = is_player_input_active(this->client_index);
            handle_page_cycle_input(port);
            handle_cursor_move(port);
            handle_key_press(port);
            update_keyboard_child_input_from_controller(port);
            handle_backspace_button(port);
        }
        update_window();
        this->update_fade();
        this->page_slide -= 0.15f * this->page_slide;
    }
}


#pragma pop

TWindowKeyBoardSoft::~TWindowKeyBoardSoft() {}

TWindowKeyBoardSoft::TWindowKeyBoardSoft(TWindowKeyBoardBase *control, s32 client)
    : TWindowBase((u8 *)&soft_keyboard_window_and_action_data, client, (u8 *)get_window_layout_position(0xBA)) {
    m_name = class_name;
    state_flags = 0;
    layout_page = 0;
    cursor_column = 2;
    cursor_row = 1;
    page_slide = 0.0f;
    m_control = control;
    update_close_mode();
}

int TWindowKeyBoardSoft::get_flag_bit0() { return this->state_flags & 0x1; }
int TWindowKeyBoardSoft::is_cursor_locked() { return (this->state_flags >> 7) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit6() { return (this->state_flags >> 6) & 0x1; }
int TWindowKeyBoardSoft::get_flag_bit5() { return (this->state_flags >> 5) & 0x1; }
int TWindowKeyBoardBase::get_flag62_bit8() { return this->request_flags & 0x8; }
