#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/unk/text_803DAFA8.h"
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_80144AC8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/render/render_util.h"

#pragma readonly_strings on

/* Colours of the "\tC0".."\tC9" text control codes (parse_text_control_codes), ARGB. */
const u32 text_control_color_palette[10] = {
    0xFF000000, 0xFF0000FF, 0xFF00FF00, 0xFF00FFFF, 0xFFFF0000,
    0xFFFF00FF, 0xFFFFFF00, 0xFFFFFFFF, 0xFFFF8080, 0xFF8080FF,
};

extern "C" {
s32 DCFlushRange(void *, int);
extern s32 menu_font_upload_flags;
extern u8 menu_font_upload_epoch;
extern "C" u8 lbl_8050C090[];
__declspec(section ".data") void *menu_font_texture_list[2] = {
    (void *)&lbl_8050C090, (void *)0x2,
};
s32 menu_font_char_advance_table[191] = {
    7, 9, 13, 11, 15, 14, 7, 8, 8, 11, 11, 7, 11, 7, 11, 12,
    12, 12, 12, 12, 12, 12, 12, 12, 12, 7, 7, 9, 11, 9, 10, 15,
    13, 12, 13, 12, 11, 11, 13, 12, 8, 11, 12, 11, 15, 12, 13, 11,
    13, 12, 11, 13, 12, 13, 15, 12, 13, 11, 8, 11, 8, 8, 9, 8,
    12, 11, 12, 11, 12, 10, 12, 11, 6, 9, 11, 6, 14, 11, 12, 11,
    11, 9, 11, 10, 11, 12, 15, 11, 11, 11, 9, 8, 9, 9, 9, 12,
    7, 10, 13, 10, 10, 7, 10, 8, 17, 9, 12, 11, 9, 17, 9, 7,
    11, 8, 8, 8, 11, 11, 8, 7, 6, 9, 12, 13, 13, 13, 10, 13,
    13, 13, 13, 13, 13, 17, 13, 11, 11, 11, 11, 8, 8, 8, 8, 12,
    12, 13, 13, 13, 13, 13, 11, 13, 12, 12, 12, 12, 15, 11, 10, 12,
    12, 12, 12, 12, 12, 17, 12, 12, 12, 12, 12, 6, 6, 6, 6, 11,
    11, 12, 12, 12, 12, 12, 11, 12, 11, 11, 11, 11, 11, 11, 11,
};
void TNECFontEORFunction::run_task() {
    if (menu_font_upload_flags & 2) {
        DCFlushRange(menu_font_palette, 0x80);
        init_and_load_tlut(0, 2, 0x80, menu_font_palette);
        menu_font_upload_flags &= 0xFFFFFFFD;
    }
    if (menu_font_upload_flags & 1) {
        menu_font_upload_flags &= 0xFFFFFFFE;
        menu_font_upload_epoch += 1;
    }
}
TNECFontEORFunction::~TNECFontEORFunction() {}

}

extern "C" {
const char *nec_font_eor_class_name = "TNECFontEORFunction";
}
TNECFontEORFunction::TNECFontEORFunction() : TObject((TObject *)(&end_of_render_root)) {
    this->m_name = nec_font_eor_class_name;
}

// ---- font text helpers (formerly the TWindowSubStatusDisp_80144B14 fragment)
struct MenuGlyphEntry {
    u16 code;
    u8 width;
    u8 epoch;   // stamped with menu_font_upload_epoch when the glyph was uploaded
    u8 page;
    u8 x;
    u8 y;
};


extern "C" {
void DCStoreRange(void *, u32);
u32 calc_text_width(char *s);
u32 calc_fullwidth_text_width(char *s);
void draw_menu_font_string(const char *s, s32 color, u32 flags, f32 x, f32 y, f32 scale);

const char *parse_text_control_codes(const char *p, s32 *mb, s32 *color) {
    while (*p == '\t') {
        switch (*++p) {
        case 'J':
            p++;
            *mb = 1;
            break;
        case 'E':
            p++;
            *mb = 0;
            break;
        case 'C':
            if (color != NULL) {
                if (p[1] == 'G') {
                    *color = TWindowCtrl::get_field24();
                } else if (p[1] >= '0' && p[1] <= '9') {
                    *color = text_control_color_palette[p[1] - '0'];
                }
            }
            p += 2;
            break;
        }
    }
    return p;
}

#pragma push
#pragma fp_contract on
void set_glyph_quad_extents(u8 advance, TexturedQuad *quad) {
    quad->x1 = quad->x0 + advance;
    quad->y1 = 18.0f + quad->y0;
    quad->u1 = (advance / 256.0f) + quad->u0;
    quad->v1 = 0.0703125f + quad->v0;
}
#pragma pop

u32 TWindowSubStatusDisp::calc_text_width(char *s) {
    f32 max = 0.0f;
    u32 w = 0;
    u8 c;
    s32 hi;
    int new_var;
    u8 lo;
    if (s == NULL) {
        return 0;
    }
    while (*s != 0) {
        c = *s++;
        hi = c;
        if (c == '\n') {
        } else if (c == ' ') {
            w += 9;
        } else {
            if ((c & 0xE0) == 0x80) {
                lo = *s++;
            } else {
                lo = c;
                hi = 0;
            }
            new_var = (hi << 8) & 0xFF00;
            new_var = new_var | lo;
            ((u16 (*)(u32))map_char_to_font_code)(new_var);
            w += (u8)((u32 (*)(void))get_font_char_advance)();
        }
    }
    if (0.0f < (f32)w) {
        max = (f32)w;
    }
    return max;
}

u32 calc_text_width(char *s) {
  f32 max = 0.0f;
  u32 w = 0;
  u8 c;
  s32 hi;
  int new_var;
  u8 lo;
  if (s == 0)
  {
    return 0;
  }
  while ((*s) != 0)
  {
    c = *(s++);
    hi = c;
    if (c == '\n')
    {
      if (max < ((f32) w))
      {
        max = (f32) w;
      }
      w = 0;
    }
    else
      if (c == ' ')
    {
      w += 9;
    }
    else
    {
      if ((c & 0xE0) == 0x80)
      {
        lo = (u8) (*(s++));
      }
      else
      {
        lo = c;
        hi = 0;
      }
      new_var = (hi << 8) & 0xFF00;
      new_var = new_var | lo;
      w += (u8) get_font_char_advance(((u16 (*)(u32)) map_char_to_font_code)(new_var));
    }
  }
  if (max < ((f32) w))
  {
    max = (f32) w;
  }
  return max;
}

u32 calc_fullwidth_text_width(char *s) {
    f32 max = 0.0f;
    u32 w = 0;
    u8 c;
    s32 hi;
    int new_var;
    u8 lo;
    if (s == NULL) {
        return 0;
    }
    while (*s != 0) {
        c = *s++;
        hi = c;
        if (c == '\n') {
            if (max < (f32)w) {
                max = (f32)w;
            }
            w = 0;
        } else if (c == ' ') {
            w += 0x12;
        } else {
            if ((c & 0xE0) == 0xE0) {
                lo = *s++;
            } else {
                lo = c;
                hi = 0;
            }
            new_var = (hi << 8) & 0xFF00;
            new_var = new_var | lo;
            w += (u8)((u32 (*)(u32))get_font_char_advance)(new_var);
        }
    }
    if (max < (f32)w) {
        max = (f32)w;
    }
    return max;
}

u32 get_font_char_advance(u16 c) {
    if (c < 0x21) {
        return 9;
    }
    if (c > 0xDF) {
        return 0x12;
    }
    return (u8)menu_font_char_advance_table[(u16)(c - 0x21)];
}

s32 TWindowSubStatusDisp::is_alpha_char(u16 code) {
    if (code < 0x41U) {
        return 0;
    }
    if (code > 0x7AU) {
        return 0;
    }
    if (code >= 0x61U) {
        return 1;
    }
    return code <= 0x5AU ? 1 : 0;
}

u16 map_char_to_font_code(u16 c) {
    if (c & 0x80) {
        c = c - 1;
    }
    if (c < 0x9F) {
    } else if (c < 0x8140) {
        c -= 0x1F;
    } else if (c < 0x824F) {
        c += 0x5EC0;
    } else if (c < 0x829E) {
        c += 0x5E6E;
    } else if (c < 0x8340) {
        c += 0x5E6B;
    } else if (c < 0x839E) {
        c += 0x5E1C;
    } else if (c < 0x8440) {
        c += 0x5E15;
    } else if (c < 0x849E) {
        c += 0x5DAB;
    } else if (c < 0x889E) {
        c += 0x5D9F;
    } else if (c < 0xF040) {
        if (c > 0xA000) {
            c -= 0x4000;
        }
        c -= (u8)((u32)(c - 0x8800) >> 8) * 0x44;
        c += 0x59BF;
    } else {
        c += 0xB1B;
    }
    return c;
}

void TWindowSubStatusDisp::pack_status_flags(u32 pixel) {
    *(u8 *)&this->m_name = (u8) ((pixel >> 4U) & 3);
    *(u8 *)&this->m_name = (u8) (*(u8 *)&this->m_name | ((pixel >> 2U) & 0x30));
    *(u8 *)((s8 *)this + 1) = (u8) (pixel & 3);
    *(u8 *)((s8 *)this + 1) = (u8) (*(u8 *)((s8 *)this + 1) | ((pixel * 4) & 0x30));
}
}
extern u8 *menu_font_glyph_pixel_buffers[];
extern u8 *menu_font_glyph_data;
void upload_font_glyph(u16 c, void *free_slot);
s32 calc_ci4_tile_offset(u32 x, u32 y);
#define g ((MenuGlyphEntry *)free_slot)

s32 calc_ci4_tile_offset(u32 x, u32 y) {
    s32 tile = (x * 4) & 0x7FFFFFE0;
    s32 r = tile + ((s32)(x & 6) >> 1);
    r += (y << 7) & 0x7FFFFC00;
    r += (s32)((y & 7) << 3) >> 1;
    return r;
}

void upload_font_glyph(u16 c, void *free_slot) {
    u8 *tex;
    u32 i;
    u32 j;
    u8 *src;
    u8 x;
    u8 y;
    g->code = c;
    if (c >= 0xE000) {
        c -= 0xDF20;
    }
    g->width = get_font_char_advance(c);
    tex = menu_font_glyph_pixel_buffers[g->page];
    y = g->y;
    x = g->x;
    src = menu_font_glyph_data + (u16)(c - 0x20) * 0x5A;
    for (j = 0; j < 0x12; j++) {
        for (i = 0; i < 5; i++) {
            u8 b = *src;
            u8 *dst = tex + calc_ci4_tile_offset((u32)(x + i * 4), (u32)(y + j));
            ((TWindowSubStatusDisp *)dst)->pack_status_flags(b);
            src++;
        }
    }
    DCStoreRange(tex, 0x8000);
    menu_font_upload_flags |= 1;
}
#undef g

s32 TWindowSubStatusDisp::upload_glyph_if_needed(u16 code, u8 *free_slot, void **pending_slot) {
    u8 slot_epoch;
    slot_epoch = ((MenuGlyphEntry *)free_slot)->epoch;
    if (slot_epoch == (u8) menu_font_upload_epoch) {
        return 0;
    }
    if (slot_epoch != (u8)(menu_font_upload_epoch - 1)) {
        upload_font_glyph(code, free_slot);
        return 1;
    }
    if ((void *) *pending_slot == NULL) {
        *pending_slot = free_slot;
    }
    return 0;
}

typedef struct MenuGlyphSlot { u16 code; u16 data[4]; } MenuGlyphSlot;
extern MenuGlyphSlot *menu_font_glyph_table;
void *TWindowSubStatusDisp::find_cached_glyph(u16 code) {
    void *free_slot;
    MenuGlyphSlot *g;
    MenuGlyphSlot *p;
    MenuGlyphSlot *q;
    u32 i;
    u32 j;

    free_slot = NULL;
    g = &menu_font_glyph_table[code & 0x7F];
    if (g->code == code) {
        return g;
    }
    if (g[0x80].code == code) {
        return &g[0x80];
    }
    if (TWindowSubStatusDisp::upload_glyph_if_needed(code, (u8 *)g, &free_slot) != 0) {
        return g;
    }
    if (TWindowSubStatusDisp::upload_glyph_if_needed(code, (u8 *)&g[0x80], &free_slot) != 0) {
        return &g[0x80];
    }
    p = &menu_font_glyph_table[0x100];
    for (i = 0; i < 0x1F; i++, p++) {
        if (p->code == code) {
            return p;
        }
        if (TWindowSubStatusDisp::upload_glyph_if_needed(code, (u8 *)p, &free_slot) != 0) {
            return p;
        }
    }
    q = menu_font_glyph_table;
    for (j = 0; j < 0x100; j++, q++) {
        if (q->code == code) {
            return q;
        }
        if (TWindowSubStatusDisp::upload_glyph_if_needed(code, (u8 *)q, &free_slot) != 0) {
            return q;
        }
    }
    if (free_slot == NULL) {
        return &menu_font_glyph_table[0x11F];
    }
    upload_font_glyph(code, free_slot);
    return free_slot;
}

u8 TWindowSubStatusDisp::calc_gauge_scale(u16 glyph, void *quad, s32 color) {
    void *cached_glyph;

    cached_glyph = TWindowSubStatusDisp::find_cached_glyph(glyph);
    MenuGlyphEntry *entry = (MenuGlyphEntry *)cached_glyph;
    TexturedQuad *pos = static_cast<TexturedQuad *>(quad);
    entry->epoch = menu_font_upload_epoch;
    set_draw_texture_and_color(entry->page, color);
    pos->u0 = (f32) ((f32) entry->x / 256.0f);
    pos->v0 = (f32) ((f32) entry->y / 256.0f);
    return entry->width;
}

void TWindowSubStatusDisp::set_gauge_param(s32 gauge_param) {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(menu_font_texture_list));
}

void TWindowSubStatusDisp::end_render_forward() { get_player(); }
void TWindowSubStatusDisp::reset_gauge(void* p) { begin_screen_draw((saddr)((void*)1)); TWindowSubStatusDisp::set_gauge_param((saddr)p); set_draw_texture_and_color((saddr)((void*)0), (saddr)((void*)-1)); }
void draw_menu_font_string(const char *s, s32 color, u32 flags, f32 x, f32 y, f32 scale) {
  s32 mb = 0;
  TexturedQuad quad;
  s32 c;
  unsigned char hi;
  u8 lo;
  int code;
  u8 w;
  if ((*s) == 0)
  {
    return;
  }
  if (current_language == LANGUAGE_JAPANESE)
  {
    mb = 1;
  }
  quad.x0 = x;
  quad.y0 = y;
  set_default_alpha_blend();
  TWindowSubStatusDisp::reset_gauge((void*)(0));
  flags &= 1;
  while ((*s) != 0)
  {
    s = parse_text_control_codes(s, &mb, 0);
    c = *((u8 *) s);
    if (((s8) c) == 0)
    {
      continue;
    }
    hi = c;
    s++;
    if (c == 10)
    {
      if (flags != 0)
      {
        quad.x0 += 9.0f;
      }
      else
      {
        quad.x0 = x;
        quad.y0 += 20.0f;
      }
    }
    else
      if (c == 0x20)
    {
      quad.x0 += 9.0f;
    }
    else
    {
      if ((mb != 0) && (((c & 0xE0) == 0x80) || ((c & 0xE0) == 0xE0)))
      {
        lo = *((u8 *) s);
        s++;
      }
      else
      {
        lo = hi;
        hi = 0;
      }
      code = (hi << 8) & 0xFF00;
      code = code | lo;
      w = TWindowSubStatusDisp::calc_gauge_scale(((u16 (*)(u32)) map_char_to_font_code)(code), &quad, color);
      set_glyph_quad_extents(w, &quad);
      draw_textured_quad_at_depth(&quad.x0, scale);
      quad.x0 += (f32) w;
    }
  }
  TWindowSubStatusDisp::end_render_forward();
}
