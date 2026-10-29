#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/Language.h"
#include "pso/render/render_util.h"

struct RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270 {
    s32 value;
    u8 remaining[0xAC];
};

struct RecoveredGlobal_8000F7FC_lbl_80515F48 {
    s32 value;
    u8 remaining[0x24];
};

struct RecoveredGlobal_8000F9E4_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F90C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F9CC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8FC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F8EC_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8000F91C_lbl_804FE120 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_80144FCC_lbl_804A74F0
{
  s32 value;
  u8 remaining[0x2F8];
};

struct Glyph_80145190 {
    u16 code;
    u8 width;
    u8 f3;
    u8 page;
    u8 x;
    u8 y;
};

typedef struct Pos_8014556C
{
  f32 x;
  f32 y;
  u8 pad[0x1C];
} Pos_8014556C;

extern u8 lbl_805D56C0;
extern RecoveredGlobal_8000F7FC_lbl_80515F48 menu_font_texture_list;
extern const f32 lbl_805DB190;
extern const f32 lbl_805DB194;
extern const f32 lbl_805DB198;
extern "C" {
void set_glyph_quad_extents(u8 arg0, u8 *arg1);
extern RecoveredGlobal_80144FCC_lbl_804A74F0 menu_font_char_advance_table;
u32 get_font_char_advance(u16 arg0);
u16 map_char_to_font_code(u16 c);
extern s32 text_control_color_palette[];
char *parse_text_control_codes(char *p, s32 *a, s32 *b);
void DCStoreRange(void *, u32);
}
extern u8 *menu_font_glyph_pixel_buffers[];
extern u8 *menu_font_glyph_data;
extern u32 menu_font_upload_flags;
void upload_font_glyph(u16 c, void *arg1);
s32 calc_ci4_tile_offset(u32 arg0, u32 arg1);
extern const f32 lbl_805DB19C;
extern "C" {
u32 calc_text_width(char *s);
u32 TWindowSubStatusDisp__sub_80144E9C(char *s);
u8 calc_gauge_scale__20TWindowSubStatusDispFPvPvi(void *arg0, void *arg1, s32 arg2);
int end_render_forward__20TWindowSubStatusDispFPv(void* p);
extern const f32 lbl_805DB1A0;
extern const f32 lbl_805DB1A4;
void draw_menu_font_string(const char *s, s32 arg1, u32 flags, f32 x, f32 y, f32 scale);
void *find_cached_glyph__20TWindowSubStatusDispFUs(u16 code);
int get_player__20TWindowSubStatusDispFv(void*);

char *parse_text_control_codes(char *p, s32 *a, s32 *b) {
    while (*p == '\t') {
        switch (*++p) {
        case 'J':
            p++;
            *a = 1;
            break;
        case 'E':
            p++;
            *a = 0;
            break;
        case 'C':
            if (b != NULL) {
                if (p[1] == 'G') {
                    *b = TWindowCtrl::get_field24();
                } else if (p[1] >= '0' && p[1] <= '9') {
                    *b = text_control_color_palette[p[1] - '0'];
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
void set_glyph_quad_extents(u8 arg0, u8 *arg1) {
    *(f32 *)((s8 *)arg1 + 8) = (f32) (*(f32 *)((s8 *)arg1 + 0) + (f32) arg0);
    *(f32 *)((s8 *)arg1 + 0xC) = (f32) (lbl_805DB190 + *(f32 *)((s8 *)arg1 + 4));
    *(f32 *)((s8 *)arg1 + 0x18) = (f32) (((f32) arg0 * lbl_805DB194) + *(f32 *)((s8 *)arg1 + 0x10));
    *(f32 *)((s8 *)arg1 + 0x1C) = (f32) (lbl_805DB198 + *(f32 *)((s8 *)arg1 + 0x14));
}
#pragma pop

typedef struct RecoveredGlobal_80144FCC_lbl_804A74F0 RecoveredGlobal_80144FCC_lbl_804A74F0;
typedef char RecoveredGlobal_80144FCC_lbl_804A74F0_size[((sizeof(RecoveredGlobal_80144FCC_lbl_804A74F0)) == 0x2FC) ? (1) : (-1)];

u32 TWindowSubStatusDisp::calc_text_width(char *s) {
    f32 max = lbl_805DB19C;
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
    if (lbl_805DB19C < (f32)w) {
        max = (f32)w;
    }
    return max;
}

u32 calc_text_width(char *s) {
  f32 max = lbl_805DB19C;
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

u32 TWindowSubStatusDisp__sub_80144E9C(char *s) {
    f32 max = lbl_805DB19C;
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

u32 get_font_char_advance(u16 arg0) {
  volatile unsigned long pad;
  unsigned short new_var;
  if (arg0 < 0x21U)
  {
    new_var = (0, 9U);
    return new_var;
  }
  if (arg0 > 0xDFU)
  {
    return 0x12U;
  }
  new_var = arg0 - 0x21;
  return (u8) (*((s32 *) (0 + ((s8 *) (((u8 *)&menu_font_char_advance_table.value) + ((new_var * 4) & 0x3FFFC))))));
}

s32 TWindowSubStatusDisp::is_alpha_char(u16 arg0) {
    if (arg0 < 0x41U) {
        return 0;
    }
    if (arg0 > 0x7AU) {
        return 0;
    }
    if (arg0 >= 0x61U) {
        return 1;
    }
    return arg0 <= 0x5AU ? 1 : 0;
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

void TWindowSubStatusDisp::pack_status_flags(u32 arg1) {
    *(u8 *)&this->m_name = (u8) ((arg1 >> 4U) & 3);
    *(u8 *)&this->m_name = (u8) (*(u8 *)&this->m_name | ((arg1 >> 2U) & 0x30));
    *(u8 *)((s8 *)this + 1) = (u8) (arg1 & 3);
    *(u8 *)((s8 *)this + 1) = (u8) (*(u8 *)((s8 *)this + 1) | ((arg1 * 4) & 0x30));
}
}

#define g ((Glyph_80145190 *)arg1)

s32 calc_ci4_tile_offset(u32 arg0, u32 arg1) {
    s32 tile = (arg0 * 4) & 0x7FFFFFE0;
    s32 r = tile + ((s32)(arg0 & 6) >> 1);
    r += (arg1 << 7) & 0x7FFFFC00;
    r += (s32)((arg1 & 7) << 3) >> 1;
    return r;
}

void upload_font_glyph(u16 c, void *arg1) {
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

s32 TWindowSubStatusDisp::upload_glyph_if_needed(u16 arg0, u8 *arg1, void **arg2) {
    u8 temp_r7;
    temp_r7 = *(u8 *)((s8 *)arg1 + 3);
    if (temp_r7 == (u8) lbl_805D56C0) {
        return 0;
    }
    if (temp_r7 != (u8)(lbl_805D56C0 - 1)) {
        upload_font_glyph(arg0, arg1);
        return 1;
    }
    if ((void *) *arg2 == NULL) {
        *arg2 = arg1;
    }
    return 0;
}

typedef struct Glyph_801452DC { u16 code; u16 data[4]; } Glyph_801452DC;
extern Glyph_801452DC *menu_font_glyph_table;
void *find_cached_glyph__20TWindowSubStatusDispFUs(u16 code) {
    void *free_slot;
    Glyph_801452DC *g;
    Glyph_801452DC *p;
    Glyph_801452DC *q;
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

u8 calc_gauge_scale__20TWindowSubStatusDispFPvPvi(void *arg0, void *arg1, s32 arg2) {
    void *temp_r3;

    temp_r3 = ((void *(*)(void))find_cached_glyph__20TWindowSubStatusDispFUs)();
    *(u8 *)((s8 *)temp_r3 + 3) = (u8) lbl_805D56C0;
    set_draw_texture_and_color((*(u8 *)((s8 *)temp_r3 + 4)), (arg2));
    *(f32 *)((s8 *)arg1 + 0x10) = (f32) ((f32) *(u8 *)((s8 *)temp_r3 + 5) * lbl_805DB194);
    *(f32 *)((s8 *)arg1 + 0x14) = (f32) ((f32) *(u8 *)((s8 *)temp_r3 + 6) * lbl_805DB194);
    return *(u8 *)((s8 *)temp_r3 + 2);
}

typedef char RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270_size[sizeof(RecoveredGlobal_8000F764_TKeyBoardControl__data_80506270) == 0xB0 ? 1 : -1];
typedef char RecoveredGlobal_8000F7FC_lbl_80515F48_size[sizeof(RecoveredGlobal_8000F7FC_lbl_80515F48) == 0x28 ? 1 : -1];
void TWindowSubStatusDisp::set_gauge_param(s32 _w0) {
    TObjFish::set_global_param((s32)&menu_font_texture_list.value);
}
typedef char RecoveredGlobal_8000F90C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F90C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8FC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8FC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F8EC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F8EC_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F91C_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F91C_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9E4_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9E4_lbl_804FE120) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8000F9CC_lbl_804FE120_size[sizeof(RecoveredGlobal_8000F9CC_lbl_804FE120) == 0x18 ? 1 : -1];

int end_render_forward__20TWindowSubStatusDispFPv(void* p) { return get_player__20TWindowSubStatusDispFv(p); }
void TWindowSubStatusDisp::reset_gauge(void* p) { begin_screen_draw((s32)((void*)1)); TWindowSubStatusDisp::set_gauge_param((s32)p); set_draw_texture_and_color((s32)((void*)0), (s32)((void*)-1)); }
typedef struct Pos_8014556C Pos_8014556C;
void draw_menu_font_string(const char *s, s32 arg1, u32 flags, f32 x, f32 y, f32 scale) {
  s32 mb = 0;
  Pos_8014556C pos;
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
  pos.x = x;
  pos.y = y;
  set_default_alpha_blend();
  TWindowSubStatusDisp::reset_gauge((void*)(0));
  flags &= 1;
  while ((*s) != 0)
  {
    s = parse_text_control_codes((char *) s, &mb, 0);
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
        pos.x += lbl_805DB1A0;
      }
      else
      {
        pos.x = x;
        pos.y += lbl_805DB1A4;
      }
    }
    else
      if (c == 0x20)
    {
      pos.x += lbl_805DB1A0;
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
      w = ((u8 (*)(u16, void *, s32)) calc_gauge_scale__20TWindowSubStatusDispFPvPvi)(((u16 (*)(u32)) map_char_to_font_code)(code), &pos, arg1);
      set_glyph_quad_extents(w, (u8 *)&pos);
      draw_textured_quad_at_depth((f32 *)&pos, scale);
      pos.x += (f32) w;
    }
  }
  ((int (*)(void)) end_render_forward__20TWindowSubStatusDispFPv)();
}
