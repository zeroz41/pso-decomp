#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaTexture.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/window/TWindowSubStatusDisp_800FBD74.h"
#include "libc/ctype.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdEndText_80307A34.h"
#include "pso/system/scene/TEnding.h"

NJS_TEXNAME TAdEndText::ending_font_textures[5] = {
    { "end_font-gc_01", 0, 0 },
    { "end_font-gc_02", 0, 0 },
    { "end_font-gc_03", 0, 0 },
    { "adx_logo", 0, 0 },
    { "sofdec_logo", 0, 0 },
};
NJS_TEXLIST TAdEndText::ending_font_texture_list = { TAdEndText::ending_font_textures, 5 };
const f32 TAdEndText::font_heights[2] = { 281.992f, 322.958f };
const f32 TAdEndText::glyph_widths[3][36] = {
    { 14.0f, 13.0f, 14.0f, 13.0f, 12.0f, 12.0f, 14.0f, 13.0f, 6.0f, 12.0f, 13.0f, 12.0f,
      15.0f, 13.0f, 15.0f, 13.0f, 14.0f, 13.0f, 13.0f, 13.0f, 13.0f, 14.0f, 16.0f, 13.0f,
      13.0f, 13.0f, 9.0f, 9.0f, 13.0f, 6.0f, 7.0f, 15.0f, 14.0f, 20.0f, 10.0f, 6.0f },
    { 13.0f, 13.0f, 12.0f, 12.0f, 12.0f, 10.0f, 14.0f, 13.0f, 7.0f, 8.0f, 12.0f, 8.0f,
      16.0f, 13.0f, 13.0f, 13.0f, 13.0f, 10.0f, 13.0f, 10.0f, 13.0f, 12.0f, 12.0f, 13.0f,
      13.0f, 13.0f, 12.0f, 9.0f, 12.0f, 12.0f, 13.0f, 12.0f, 12.0f, 12.0f, 12.0f, 12.0f },
    { 9.0f, 13.0f, 16.0f, 17.0f, 15.0f, 17.0f, 19.0f, 20.0f, 17.0f, 15.0f, 20.0f, 20.0f,
      20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f,
      20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f, 20.0f },
};
const char *TAdEndText::class_name = "TAdEndText";

s32 get_ending_scene_active(void) {
    return ending_scene_active;
}

s32 get_end_text_font_loaded_flag(void) {
    return TAdEndText::font_loaded_flag;
}


void TAdEndText::draw_end_font_text(s32 col, char *str, f32 x, f32 y, f32 depth) {
    u8 glyph;
    f32 u_end;
    u8 cur_row;
    u8 ch[2];
    f32 quad[8];
    f32 raised_y;
    u8 row;
    f32 width;
    int glyph_row;
    f32 v_end;
    u8 u;

    cur_row = 0xFE;
    set_default_alpha_blend();
    begin_screen_draw(1);
    set_texlist(loaded_font_texture_list);
    raised_y = scroll_step + y;
    while (*str) {
        ch[0] = *(str++);
        glyph = ch[0];
        if (ch[0] == '#') {
            continue;
        }
        quad[0] = x;
        quad[1] = is_lower(ch[0]) ? raised_y : y;
        if (is_alnum(ch[0])) {
            if (is_upper(ch[0])) {
                glyph = ch[0] - 'A';
            } else if (is_lower(ch[0])) {
                glyph = ch[0] - '=';
            } else if (is_digit(ch[0])) {
                glyph = ch[0] + 14;
            }
        } else {
            switch (ch[0]) {
            case '(': glyph = 26; break;
            case ')': glyph = 27; break;
            case '/': glyph = 28; break;
            case '.': glyph = 29; break;
            case ':': glyph = 30; break;
            case '&': glyph = 31; break;
            case '~': glyph = 32; break;
            case '^': glyph = 33; break;
            case '-': glyph = 34; break;
            case ',': glyph = 35; break;
            case '<': glyph = 72; break;
            case '>': glyph = 73; break;
            default: glyph = 82; break;
            }
        }
        if (glyph == 82) {
            x += space_width;
            quad[2] = space_width + quad[0];
            quad[3] = glyph_size + quad[1];
            quad[4] = zero;
            quad[5] = zero;
            quad[6] = zero;
            quad[7] = zero;
        } else {
            f32 size = glyph_size;
            glyph_row = glyph / 36;
            u = (u8)(size * (f32)((glyph - (glyph / 36) * 36) % 6));
            ch[1] = (u8)(size * (f32)((glyph % 36) / 6));
            width = glyph_widths[glyph_row][glyph % 36];
            x += width;
            quad[2] = quad[0] + width;
            quad[3] = size + quad[1];
            quad[4] = (f32)u * texel_scale;
            quad[5] = (f32)ch[1] * texel_scale;
            u_end = (f32)u + width;
            quad[6] = u_end * texel_scale;
            v_end = size + (f32)ch[1];
            quad[7] = v_end * texel_scale;
        }
        row = glyph / 36;
        if (row != cur_row) {
            set_draw_texture_and_color(row, col);
            cur_row = row;
        }
        draw_textured_quad_at_depth(quad, depth);
    }

    TWindowSubStatusDisp::get_player();
}

void TAdEndText::render() {
    f32 hi;
    f32 lo;
    f32 y;
    u32 i;
    s32 col;
    lo = fade_top;
    hi = fade_out_start;
    for (i = 0; i < m_line_count; i++) {
        col = -1;
        y = m_line_pos[i].y;
        if (y <= lo || fade_bottom <= y) {
            col = 0xFFFFFF;
        }
        if (lo < y && y < fade_in_end) {
            col = ((u32)((alpha_max * (y - lo)) / lo) << 24) | 0xFF0000 | 0xFFFF;
        }
        if (hi < y && y < fade_bottom) {
            col = ((u32)((alpha_max * (fade_bottom - y)) / fade_top) << 24) | 0xFF0000 | 0xFFFF;
        }
        switch ((s8)credit_script_lines[i][0]) {
        case 0x23:
            if (col != 0xFFFFFF) {
                draw_end_font_text(col, credit_script_lines[i], m_line_pos[i].x, y, text_depth);
            }
            break;
        case 0x21:
            TObjFish::set_global_param(loaded_font_texture_list);
            begin_screen_draw(1);
            set_draw_texture_and_color(3, -1);
            draw_textured_quad_at_depth(&m_adx_logo.x0, text_depth);
            TWindowSubStatusDisp::get_player();
            break;
        case 0x40:
            TObjFish::set_global_param(loaded_font_texture_list);
            begin_screen_draw(1);
            set_draw_texture_and_color(4, -1);
            draw_textured_quad_at_depth(&m_sofdec_logo.x0, text_depth);
            TWindowSubStatusDisp::get_player();
            break;
        default:
            if (col != 0xFFFFFF) {
                draw_small_font_text((void *)col, credit_script_lines[i], m_line_pos[i].x, y, text_depth);
            }
            break;
        }
    }
}

#pragma push
#pragma fp_contract on
void TAdEndText::run_task() {
    u32 count;
    u32 i;
    count = m_line_count;
    if (font_loaded_flag == 1) {
        count -= 9;
    }
    m_line_pos[0].y = scroll_start_y - (one / (font_heights[m_size_index] / font_heights[0])) * ((m_height / scroll_height_scale) * (m_scroll / scroll_time_scale));
    for (i = 0; i < count; i++) {
        switch ((s8)credit_script_lines[i][0]) {
        case 0x23:
            m_line_pos[i].x = text_x;
            m_line_pos[i + 1].y = glyph_size + m_line_pos[i].y;
            break;
        case 0x21:
            m_line_pos[i].x = logo_x;
            m_line_pos[i + 1].y = logo_size + m_line_pos[i].y;
            m_adx_logo.x0 = m_line_pos[i].x;
            m_adx_logo.y0 = m_line_pos[i].y;
            m_adx_logo.x1 = logo_size + m_adx_logo.x0;
            m_adx_logo.y1 = logo_size + m_adx_logo.y0;
            break;
        case 0x40:
            m_line_pos[i].x = logo_x;
            m_line_pos[i + 1].y = logo_size + m_line_pos[i].y;
            m_sofdec_logo.x0 = m_line_pos[i].x;
            m_sofdec_logo.y0 = m_line_pos[i].y;
            m_sofdec_logo.x1 = logo_size + m_sofdec_logo.x0;
            m_sofdec_logo.y1 = logo_size + m_sofdec_logo.y0;
            break;
        default:
            m_line_pos[i].x = text_x;
            m_line_pos[i + 1].y = line_height + m_line_pos[i].y;
            break;
        }
    }
    m_scroll = m_scroll + m_speed;
    if (m_line_pos[m_line_count].y < end_y) {
        font_loaded_flag = 1;
    }
}

TAdEndText::~TAdEndText() {}
#pragma pop

TAdEndText::TAdEndText(TObject *parent) : TObject(parent) {
    s32 c;
    m_name = class_name;
    pad_1C = 0;
    m_scroll = zero;
    font_loaded_flag = 0;
    m_adx_logo.x0 = zero;
    m_adx_logo.y0 = zero;
    m_adx_logo.x1 = zero;
    m_adx_logo.y1 = zero;
    m_adx_logo.u0 = zero;
    m_adx_logo.v0 = zero;
    m_adx_logo.u1 = one;
    m_adx_logo.v1 = one;
    m_sofdec_logo.x0 = zero;
    m_sofdec_logo.y0 = zero;
    m_sofdec_logo.x1 = zero;
    m_sofdec_logo.y1 = zero;
    m_sofdec_logo.u0 = zero;
    m_sofdec_logo.v0 = zero;
    m_sofdec_logo.u1 = one;
    m_sofdec_logo.v1 = one;
    m_line_count = 0;
    m_height = zero;
    while (((char)(c = ((u8 **)credit_script_lines)[m_line_count][0])) != 0x2A) {
        switch ((s8)c) {
        case 0x23:
        case 0:
            m_height = m_height + glyph_size;
            break;
        case 0x21:
            m_height = m_height + logo_size;
            break;
        case 0x40:
            m_height = m_height + logo_size;
            break;
        default:
            m_height = m_height + line_height;
            break;
        }
        m_line_count++;
    }
    m_rate = (TKeyBoardControl__sub_8000F828() == 0) ? (one) : (fast_rate);
    m_speed = scroll_step * m_rate;
    m_size_index = (is_ending_sequence_active() != 0) ? (1) : (0);
}

void TAdEndText::free_resources() {
    if (loaded_font_texture_list != 0) {
        release_texture_list(loaded_font_texture_list);
        loaded_font_texture_list = 0;
    }
    if (credit_script_lines != 0) {
        TLobby::free_nodes_with_id((uaddr)credit_script_lines);
        credit_script_lines = 0;
    }
}


void TAdEndText::load_ending_font() {
    loaded_font_texture_list = &ending_font_texture_list;
    bind_gvm_texture_list("ed128_font.gvm", &ending_font_texture_list);
    credit_script_lines = static_cast<char **>(create_named_object("AdEnding.rel"));
    font_loaded_flag = 0;
}

int is_digit(int c) {
    return __ctype_map[(u8)c] & __digit;
}

int is_upper(int c) {
    return __ctype_map[(u8)c] & __upper_case;
}

int is_alnum(int c) {
    return __ctype_map[(u8)c] & __alphanumeric;
}

int is_lower(int c) {
    return __ctype_map[(u8)c] & __lower_case;
}

s32 is_ending_sequence_active(void) {
    return ending_sequence_active;
}

s32 TAdEndText::font_loaded_flag;
NJS_TEXLIST *TAdEndText::loaded_font_texture_list;
char **TAdEndText::credit_script_lines;

// Defined last so the code above loads them instead of folding them.
__declspec(section ".sdata2") const f32 TAdEndText::scroll_step = 2.0f;
__declspec(section ".sdata2") const f32 TAdEndText::space_width = 10.0f;
__declspec(section ".sdata2") const f32 TAdEndText::glyph_size = 20.0f;
__declspec(section ".sdata2") const f32 TAdEndText::zero = 0.0f;
__declspec(section ".sdata2") const f32 TAdEndText::texel_scale = 0.0078125f;
__declspec(section ".sdata2") const f32 TAdEndText::fade_top = 40.0f;
__declspec(section ".sdata2") const f32 TAdEndText::fade_bottom = 422.0f;
__declspec(section ".sdata2") const f32 TAdEndText::fade_in_end = 80.0f;
__declspec(section ".sdata2") const f32 TAdEndText::alpha_max = 255.0f;
__declspec(section ".sdata2") const f32 TAdEndText::fade_out_start = 382.0f;
__declspec(section ".sdata2") const f32 TAdEndText::text_depth = 0.99999f;
__declspec(section ".sdata2") const f32 TAdEndText::scroll_start_y = 431.0f;
__declspec(section ".sdata2") const f32 TAdEndText::one = 1.0f;
__declspec(section ".sdata2") const f32 TAdEndText::scroll_height_scale = 9917.0f;
__declspec(section ".sdata2") const f32 TAdEndText::scroll_time_scale = 1.85f;
__declspec(section ".sdata2") const f32 TAdEndText::text_x = 50.0f;
__declspec(section ".sdata2") const f32 TAdEndText::logo_x = 45.0f;
__declspec(section ".sdata2") const f32 TAdEndText::logo_size = 256.0f;
__declspec(section ".sdata2") const f32 TAdEndText::line_height = 15.0f;
__declspec(section ".sdata2") const f32 TAdEndText::end_y = 250.0f;
__declspec(section ".sdata2") const f32 TAdEndText::fast_rate = 1.2f;
