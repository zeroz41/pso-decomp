#include "pso/render/ColorLineList.h"
#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubMag_802627D8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/text_80076BC4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/text_8026C664.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/system/ControllerInput.h"


struct UV_80262038 {
    f32 u;
    f32 v;
};

#include <stddef.h>
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubMag.h"
#include "pso/ui/window/WindowLayout.h"

WindowDescriptor soft_keyboard_window_and_action_data = { {307.0f, 161.0f}, 50040.0f, NULL, 0x803 };

extern "C" {


extern u8 *TWindowKeyBoardSoft__language_text_resources;
extern s32 local_client_id;

const char *keyboard_soft_type_name_pointer = "TWindowKeyBoardSoft";

/* Per key class (indexed through soft_keyboard_key_class): steps back to the class's first column,
   and lbl_8044F138 the columns left to its last one (read from the cursor moves in sub_80260E30). */
const s8 TWindowKeyBoardSoft__data_8044F124[20] = { 0, 0, 0, -1, 0, -1, -2, -3, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, 0, 0 };
const u8 lbl_8044F138[20] = { 0, 0, 1, 0, 3, 2, 1, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0 };
const UV_80262038 keyboard_key_frame_uv_table[3] = { { 185.0f, 0.0f }, { 185.0f, 119.0f }, { 185.0f, 141.0f } };

/* Function keys below the character grid: grid cell, size and texture origin. */
const NJS_POINT2 lbl_8044F164[10] = {
    { 0.0f, 6.0f }, { 12.0f, 6.0f }, { 0.0f, 5.0f }, { 0.0f, 0.0f }, { 14.0f, 0.0f },
    { 2.0f, 6.0f }, { 0.0f, 1.0f }, { 0.0f, 2.0f }, { 0.0f, 3.0f }, { 0.0f, 4.0f },
};
const NJS_POINT2 lbl_8044F1B4[10] = {
    { 37.0f, 18.0f }, { 37.0f, 18.0f }, { 37.0f, 18.0f }, { 37.0f, 18.0f }, { 37.0f, 18.0f },
    { 66.0f, 18.0f }, { 18.0f, 18.0f }, { 18.0f, 18.0f }, { 18.0f, 18.0f }, { 18.0f, 18.0f },
};
const UV_80262038 lbl_8044F204[10] = {
    { 62.0f, 0.0f }, { 62.0f, 18.0f }, { 62.0f, 36.0f }, { 62.0f, 54.0f }, { 62.0f, 72.0f },
    { 62.0f, 108.0f }, { 107.0f, 0.0f }, { 107.0f, 18.0f }, { 107.0f, 36.0f }, { 107.0f, 54.0f },
};

void TWindowKeyBoardSoft::calc_cursor_step(s32 *arg1, s32 *arg2) {
    switch (current_language) {
    case LANGUAGE_JAPANESE:
        if ((get_flag_bit5() != 0) || (get_flag_bit6() != 0) || (is_cursor_locked() != 0)) {
            *arg1 = 4;
            *arg2 = 4;
            return;
        }
        if (get_flag_bit0() != 0) {
            *arg1 = 4;
            *arg2 = 5;
            return;
        }
        *arg1 = 0;
        *arg2 = 5;
        return;
    case LANGUAGE_ENGLISH:
        if ((get_flag_bit5() != 0) || (get_flag_bit6() != 0) || (is_cursor_locked() != 0)) {
            *arg1 = 0;
            *arg2 = 0;
            return;
        }
        *arg1 = 0;
        *arg2 = 1;
        return;
    case LANGUAGE_GERMAN:
    case LANGUAGE_FRENCH:
    case LANGUAGE_SPANISH:
        if ((get_flag_bit5() != 0) || (get_flag_bit6() != 0) || (is_cursor_locked() != 0)) {
            *arg1 = 0;
            *arg2 = 0;
            return;
        }
        if (get_flag_bit0() != 0) {
            *arg1 = 0;
            *arg2 = 1;
            return;
        }
        *arg1 = 0;
        *arg2 = 2;
        return;
    }
}

#pragma push
#pragma fp_contract on
s32 TWindowKeyBoardSoft::sub_802605DC() {
    s32 idx = calc_key_index(cursor_column, cursor_row);
    return idx + TWindowKeyBoardSoft__data_8044F124[soft_keyboard_key_class[idx]];
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TWindowKeyBoardSoft::calc_key_x(s32 col, s32 row) {
  f32 new_var;
  s32 count;
  s32 temp_r31;
  s32 key;
  key = calc_key_index(col, row);
  temp_r31 = col + TWindowKeyBoardSoft__data_8044F124[soft_keyboard_key_class[key]];
  sub_80260760((int) key, &count, NULL);
  new_var = calc_key_coord(count);
  return 1.0f + ((19.0f * ((f32) temp_r31)) + (0.5f * new_var));
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
f32 TWindowKeyBoardSoft::sub_802606E0() {
    return -((0.5f * (f32) (*(u8 *)((s8 *)TWindowKeyBoardSoft__language_text_resources + 0) * *(u8 *)((s8 *)TWindowKeyBoardSoft__language_text_resources + 1))) - 153.0f);
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TWindowKeyBoardSoft::calc_key_coord(s32 count) {
    return (19.0f * (f32) count) + 1.0f;
}
#pragma pop

void TWindowKeyBoardSoft::sub_80260760(s32 key, s32 *count, u32 *color) {
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
void TWindowKeyBoardSoft::sub_80260808(s32 port) {
    if ((test_pressed_buttons_packed(&controller_input_state.controllers[port], 2) != 0) && (m_control != NULL)) {
        this->m_60 = (s32) (this->m_60 & 0xFFFFFFEF);
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
                m_60 |= 0x10;
            }
        }
    }
}

/* Layout table of the soft keyboard: one 16-column key-code grid per page. */
struct SoftKeyLayout_80260904 {
    u8 page_count; /* inferred: bound of the page-tab loop */
    u8 tab_width;  /* inferred: page tab width in pixels */
    u8 pad_2[2];
    u16 **pages;
};

void TWindowKeyBoardSoft::sub_80260904(s32 port) {
    SoftKeyLayout_80260904 *layout = (SoftKeyLayout_80260904 *)TWindowKeyBoardSoft__language_text_resources;
    static void (TWindowKeyBoardBase::*key_actions[])() = {
        &TWindowKeyBoardBase::vt0,  &TWindowKeyBoardBase::vt1,  &TWindowKeyBoardBase::vt2,
        &TWindowKeyBoardBase::vt3,  &TWindowKeyBoardBase::vt4,  &TWindowKeyBoardBase::vt5,
        &TWindowKeyBoardBase::vt6,  &TWindowKeyBoardBase::vt7,  &TWindowKeyBoardBase::vt8,
        &TWindowKeyBoardBase::vt9,  &TWindowKeyBoardBase::vt10, &TWindowKeyBoardBase::vt11,
        &TWindowKeyBoardBase::vt12, &TWindowKeyBoardBase::vt13, &TWindowKeyBoardBase::vt14,
        &TWindowKeyBoardBase::vt15, &TWindowKeyBoardBase::vt16, &TWindowKeyBoardBase::vt17,
        &TWindowKeyBoardBase::vt18, &TWindowKeyBoardBase::vt19, &TWindowKeyBoardBase::vt20,
        &TWindowKeyBoardBase::vt21,
    };
    u16 code;

    if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 4) == 0) {
        return;
    }
    if (m_control == NULL) {
        return;
    }
    if (!(m_60 & 1)) {
        update_focus_flags();
    }
    spawn_key_effect(cursor_column, cursor_row);
    if (m_60 & 0x10) {
        m_control->vt0();
        if (m_control->is_key_state_2() == 0) {
            m_60 &= ~0x10;
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
    } else if (code == 2 && (m_60 & 8)) {
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

void TWindowKeyBoardSoft::sub_80260E30(s32 port) {
    s8 dx = 0;
    s8 dy = 0;
    ControllerInputContext *input;
    if (m_60 & 2) {
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
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0xF0, 6, 2) == 0) {
            return;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x10, 6, 2) != 0) {
            dy = -1;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x20, 6, 2) != 0) {
            dy++;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x40, 6, 2) != 0) {
            dx = -1;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x80, 6, 2) != 0) {
            dx++;
        }
    }
    play_sound_effect(0x54100, 0, 0, 0);
    if (m_60 & 0x10) {
        if (dx > 0) {
            m_control->vt15();
        } else if (dx < 0) {
            m_control->vt16();
        }
        if (dy > 0) {
            m_control->vt18();
        } else if (dy < 0) {
            m_control->vt17();
        }
        return;
    }
    if (dx > 0) {
        cursor_column += lbl_8044F138[soft_keyboard_key_class[(s8)cursor_column + (s8)cursor_row * 16]] + 1;
    }
    if (dx < 0) {
        cursor_column += TWindowKeyBoardSoft__data_8044F124[soft_keyboard_key_class[(s8)cursor_column + (s8)cursor_row * 16]] - 1;
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

void TWindowKeyBoardSoft::sub_80261134() {
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
    s32 spC;
    s32 sp8;
    ControllerInputContext *temp_r30;
    temp_r30 = &controller_input_state.controllers[port];
    if (test_pressed_buttons_packed(temp_r30, 0x30000) != 0) {
        play_sound_effect(0x54100, 0, 0, 0);
        calc_cursor_step(&spC, &sp8);
        if (test_pressed_buttons_packed(temp_r30, 0x10000) != 0) {
            this->page_slide = 10.0f;
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x64) + 1);
        }
        if (test_pressed_buttons_packed(temp_r30, 0x20000) != 0) {
            this->page_slide = -10.0f;
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) (*(u8 *)((s8 *)((u8 *)this) + 0x64) - 1);
        }
        if ((s8) *(u8 *)((s8 *)((u8 *)this) + 0x64) < spC) {
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) sp8;
        }
        if ((s8) *(u8 *)((s8 *)((u8 *)this) + 0x64) > sp8) {
            *(u8 *)((s8 *)((u8 *)this) + 0x64) = (u8) spC;
        }
        this->update_focus_flags();
    }
}
#pragma pop

void TWindowKeyBoardSoft::set_mode3() {
    TWindowKeyBoardBase *control;
    m_60 |= 0x80;
    control = m_control;
    if (control != NULL) {
        control->set_mode3();
        set_mode0();
    }
}

void TWindowKeyBoardSoft::set_mode2() {
    TWindowKeyBoardBase *control;
    m_60 |= 0x40;
    control = m_control;
    if (control != NULL) {
        control->set_mode2();
        set_mode0();
    }
}

void TWindowKeyBoardSoft::set_mode1() {
    m_60 |= 0x20;
    if (m_control != NULL) {
        m_control->set_mode1();
        set_mode0();
    }
}

void TWindowKeyBoardSoft::set_mode0() {
    if (m_control != NULL) {
        m_60 |= 1;
        m_control->set_mode0();
        sub_80261134();
    }
}

void TWindowKeyBoardSoft::update_close_mode() {
    if (m_control != NULL) {
        m_control->update_close_mode();
        update_focus_flags();
    }
}

s32 TWindowKeyBoardSoft::hit_test_relative(u8 *ctx, u8 *arg2) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f3;
    f32 temp_f5;
    temp_f3 = *(f32 *)((s8 *)arg2 + 4);
    temp_f5 = *(f32 *)((s8 *)arg2 + 0);
    return ((TWindowKeyBoardSoft *)arg0)->sub_802614DC((WindowDrawContext *)ctx, temp_f5 - *(f32 *)((s8 *)ctx + 0), temp_f3 - *(f32 *)((s8 *)ctx + 4), *(f32 *)((s8 *)arg2 + 8) - temp_f5, *(f32 *)((s8 *)arg2 + 0xC) - temp_f3) >= 1.0f;
}

f32 TWindowKeyBoardSoft::sub_802614DC(WindowDrawContext *context, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    f32 t;
    f32 v;

    t = get_normalized_progress();
    if (t >= 1.0f) {
        return 1.0f;
    }
    v = (t * (context->w + context->h)) - (farg0 + farg1);
    if (v <= 0.0f) {
        return 0.0f;
    }
    v = v / (farg2 + farg3);
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

    sub_80260760(calc_key_index(col, row), &type, 0);
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
void TWindowKeyBoardSoft::sub_802616BC(WindowDrawContext *ctx) {
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
    SoftKeyLayout_80260904 *layout;
    s32 key;
    f32 tab_x;
    TexturedQuad q;
    u32 color;

    layout = (SoftKeyLayout_80260904 *)TWindowKeyBoardSoft__language_text_resources;
    depth = -1.0f / (0.1196f + ctx->depth);
    cursor = this->sub_802605DC();
    keys = layout->pages[layout_page];
    TWindowSubStatusDisp::reset_gauge(NULL);
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
                width = TWindowSubStatusDisp::calc_gauge_scale(code, &q, color);
                q.x0 = 0.5f * (f32)(18 - width) + q.x0;
                set_glyph_quad_extents(width, &q);
                if (hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
                    ctx->transform_quad(&q);
                    draw_textured_quad_at_depth((f32 *)&q, depth);
                }
            }
        }
    }
    TWindowSubStatusDisp::end_render_forward();
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
        if (hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
            set_constant_material_color(key == cursor ? 0xFF000000 : 0xFF999999);
            ctx->transform_quad(&q);
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
    }
    TWindowSubStatusDisp::begin_render();
    set_draw_texture_and_color(3, 0xFF999999);

    tab_x = sub_802606E0();
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
        if (hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
            ctx->transform_quad(&q);
            set_constant_material_color(tab_color);
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
        tab_x += (f32)layout->tab_width;
    }

    for (i = 0; i < 10; i++) {
        f32 x;
        key = calc_key_index((s32)lbl_8044F164[i].x, (s32)lbl_8044F164[i].y);
        color = key == cursor ? 0xFF000000 : 0xFF999999;
        x = ctx->x + calc_key_x((s32)lbl_8044F164[i].x, (s32)lbl_8044F164[i].y);
        q.x0 = x - 0.5f * lbl_8044F1B4[i].x;
        q.y0 = 1.0f + (26.0f + (19.0f * lbl_8044F164[i].y + ctx->y));
        q.x1 = q.x0 + lbl_8044F1B4[i].x;
        q.y1 = q.y0 + lbl_8044F1B4[i].y;
        q.u0 = lbl_8044F204[i].u / 128.0f;
        q.v0 = lbl_8044F204[i].v / 128.0f;
        q.u1 = (lbl_8044F204[i].u + lbl_8044F1B4[i].x) / 128.0f;
        q.v1 = (lbl_8044F204[i].v + lbl_8044F1B4[i].y) / 128.0f;
        if (hit_test_relative((u8 *)ctx, (u8 *)&q) != 0) {
            set_constant_material_color(color);
            ctx->transform_quad(&q);
            draw_textured_quad_at_depth((f32 *)&q, depth);
        }
    }
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TWindowKeyBoardSoft::sub_80261DD8(WindowDrawContext *ctx) {
    ColorLineVertex v[5];
    u32 col[5];
    ColorLineList d;
    f32 depth;
    u8 *res;

    depth = 0.0598f + ctx->depth;
    res = TWindowKeyBoardSoft__language_text_resources;
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
    v[0].x = (ctx->x + sub_802606E0()) - 1.0f;
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
    const UV_80262038 *uv;

    v = sub_802614DC(context, x0, y, w, 20.0f);
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
    draw_textured_quad_at_depth((f32 *)&q, scale);
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
    draw_textured_quad_at_depth((f32 *)&q, scale);
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
    draw_textured_quad_at_depth((f32 *)&q, scale);
}

#pragma push
#pragma fp_contract on
/* Key frames of the character grid and the page tabs, then the tab bar ends. */
void TWindowKeyBoardSoft::sub_8026227C(WindowDrawContext *ctx) {
    s32 cursor;
    SoftKeyLayout_80260904 *layout = (SoftKeyLayout_80260904 *)TWindowKeyBoardSoft__language_text_resources;
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

    cursor = this->sub_802605DC();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0, -1);
    for (j = 0; j < 7; j++) {
        for (i = 0; i < 16; i += count) {
            key = calc_key_index(i, j);
            sub_80260760(key, &count, &color);
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

    tab_x = sub_802606E0();
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
    tab_x = sub_802606E0();
    fn_8026C664((u8 *)ctx, (ctx->x + tab_x) - 34.0f, 3.0f + (-1.0f + ctx->y), depth, page_slide);
    tab_x += 1.0f + (f32)(layout->tab_width * layout->page_count);
    fn_8026C708((u8 *)ctx, 5.0f + (ctx->x + tab_x),
                3.0f + (-1.0f + ctx->y), depth, page_slide);
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TWindowKeyBoardSoft::render() {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    sub_8026227C((WindowDrawContext *)ctx);
    sub_80261DD8((WindowDrawContext *)ctx);
    sub_802616BC((WindowDrawContext *)ctx);
}

#pragma push
#pragma fp_contract on


void TWindowKeyBoardSoft::run_task() {
    f32 temp_f0;
    s32 port;

    if (m_control != NULL) {
        if ((this->sub_80244994() != 0) && (m_control->is_confirmed() == 0)) {
            port = is_player_input_active(this->client_index);
            handle_page_cycle_input(port);
            sub_80260E30(port);
            sub_80260904(port);
            update_keyboard_child_input_from_controller(port);
            sub_80260808(port);
        }
        ((TWindowDD *)this)->initialize_subwindow();
        ((TWindowBase *)this)->update_fade();
        this->page_slide -= 0.15f * this->page_slide;
    }
}

}

#pragma pop

extern "C" {
}

TWindowKeyBoardSoft::~TWindowKeyBoardSoft() {}

TWindowKeyBoardSoft::TWindowKeyBoardSoft(TWindowKeyBoardBase *control, s32 client)
    : TWindowBase((u8 *)&soft_keyboard_window_and_action_data, client, (u8 *)get_window_layout_position(0xBA)) {
    m_name = keyboard_soft_type_name_pointer;
    m_60 = 0;
    layout_page = 0;
    cursor_column = 2;
    cursor_row = 1;
    page_slide = 0.0f;
    m_control = control;
    update_close_mode();
}
