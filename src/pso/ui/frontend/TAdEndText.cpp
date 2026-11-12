#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_800F9B84.h"

#include "types.h"
void set_default_alpha_blend();
s32 set_texlist(u32 texlist);
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

struct RecoveredGlobal_8001B3BC_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_8001B3EC_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_8001B3D4_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_8001B404_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct Pos_8001AD8C { f32 x, y; };

struct Box_8001AD8C { f32 x0, y0, x1, y1; };

struct Self_8001AD8C {
    u8 pad0[0x24];
    f32 scroll;
    Pos_8001AD8C pos[800];
    u32 count;
    Box_8001AD8C box1;
    u8 pad193C[0x194C - 0x193C];
    Box_8001AD8C box2;
};

struct Pos_8001AF80 { f32 x, y; };

struct Box_8001AF80 { f32 x0, y0, x1, y1; };

struct Self_8001AF80 {
    u8 pad0[0x24];
    f32 scroll;
    Pos_8001AF80 pos[800];
    u32 count;
    Box_8001AF80 box1;
    u8 pad193C[0x194C - 0x193C];
    Box_8001AF80 box2;
    u8 pad195C[0x196C - 0x195C];
    f32 speed;
    f32 scale;
    s32 sizeIdx;
};

struct Box_8001B190
{
  f32 x0;
  f32 y0;
  f32 x1;
  f32 y1;
  f32 x2;
  f32 y2;
  f32 w;
  f32 h;
};

struct Self_8001B190
{
  s32 name;
  u8 pad4[0x18 - 0x4];
  void *vtable;
  s32 f1C;
  u8 pad20[0x24 - 0x20];
  f32 scroll;
  u8 pos[0x1928 - 0x28];
  u32 count;
  Box_8001B190 box1;
  Box_8001B190 box2;
  f32 speed;
  f32 height;
  s32 sizeIdx;
  f32 rate;
};

extern "C" {
extern RecoveredGlobal_8001B3BC_lbl_804F5800 __ctype_map;
struct EndTextTexName { const char *filename; u32 attr; u32 texaddr; };
struct EndTextTexList { EndTextTexName *textures; u32 nbTexture; };
extern EndTextTexList TAdEndText__ending_font_texture_list;
extern char lbl_804347B0[];
extern char lbl_804347C0[];
extern u32 TAdEndText__loaded_font_texture_list;
extern u32 TAdEndText__credit_script_lines;
extern s32 TAdEndText__font_loaded_flag;
void bind_gvm_texture_list(const char *name, void *data);
void TAdEndText__sub_8001A998(s32, char *, f32, f32, f32);
s32 draw_small_font_text(s32, f32, f32, f32);
u32 __cvt_fp2unsigned(f32);
extern const f32 lbl_805D7E04;
extern const f32 lbl_805D7E08;
extern const f32 lbl_805D7E0C;
extern const f32 lbl_805D7E10;
extern const f32 lbl_805D7E14;
extern const f32 lbl_805D7E18;
extern const f32 lbl_804345D8[];
extern const f32 TAdEndText__data_805D7DF8;
extern const f32 lbl_805D7E1C;
extern const f32 lbl_805D7E20;
extern const f32 lbl_805D7E24;
extern const f32 lbl_805D7E28;
extern const f32 lbl_805D7E2C;
extern const f32 lbl_805D7E30;
extern const f32 lbl_805D7E34;
extern const f32 lbl_805D7E38;
extern const f32 lbl_805D7E3C;
int TKeyBoardControl__sub_8000F828(void);
s32 __ct__7TObjectFP7TObject(void *, TObject *);
extern u8 __vt__10TAdEndText[];
extern const char *TAdEndText__class_name;
extern const f32 lbl_805D7DF0;
extern const f32 lbl_805D7DFC;
extern const f32 lbl_805D7E40;
void release_texture_list(void*);

#pragma push
#pragma readonly_strings on
EndTextTexName lbl_80480950[5] = {
    { "end_font-gc_01", 0, 0 },
    { "end_font-gc_02", 0, 0 },
    { "end_font-gc_03", 0, 0 },
    { "adx_logo", 0, 0 },
    { "sofdec_logo", 0, 0 },
};
__declspec(section ".data") EndTextTexList TAdEndText__ending_font_texture_list = { lbl_80480950, 5 };
extern const f32 lbl_804345D8[2] = { 281.992f, 322.958f };
extern const f32 lbl_804345E0[3][36] = {
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
const char *TAdEndText__class_name = "TAdEndText";
#pragma pop

extern s32 ending_scene_active;

s32 get_ending_scene_active(void) {
    return ending_scene_active;
}

s32 get_end_text_font_loaded_flag(void) {
    return TAdEndText__font_loaded_flag;
}

extern const f32 lbl_805D7DF4;
extern const f32 lbl_805D7E00;

void TAdEndText__sub_8001A998(s32 col, char *str, f32 x, f32 y, f32 depth) {
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
    set_texlist(TAdEndText__loaded_font_texture_list);
    raised_y = lbl_805D7DF0 + y;
    while (*str) {
        ch[0] = *(str++);
        glyph = ch[0];
        if (ch[0] == '#') {
            continue;
        }
        quad[0] = x;
        quad[1] = TAdEndText__sub_8001B404(ch[0]) ? raised_y : y;
        if (TAdEndText__sub_8001B3EC(ch[0])) {
            if (TAdEndText__sub_8001B3D4(ch[0])) {
                glyph = ch[0] - 'A';
            } else if (TAdEndText__sub_8001B404(ch[0])) {
                glyph = ch[0] - '=';
            } else if (TAdEndText__sub_8001B3BC(ch[0])) {
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
            x += lbl_805D7DF4;
            quad[2] = lbl_805D7DF4 + quad[0];
            quad[3] = TAdEndText__data_805D7DF8 + quad[1];
            quad[4] = lbl_805D7DFC;
            quad[5] = lbl_805D7DFC;
            quad[6] = lbl_805D7DFC;
            quad[7] = lbl_805D7DFC;
        } else {
            f32 size = TAdEndText__data_805D7DF8;
            glyph_row = glyph / 36;
            u = (u8)(size * (f32)((glyph - (glyph / 36) * 36) % 6));
            ch[1] = (u8)(size * (f32)((glyph % 36) / 6));
            width = lbl_804345E0[glyph_row][glyph % 36];
            x += width;
            quad[2] = quad[0] + width;
            quad[3] = size + quad[1];
            quad[4] = (f32)u * lbl_805D7E00;
            quad[5] = (f32)ch[1] * lbl_805D7E00;
            u_end = (f32)u + width;
            quad[6] = u_end * lbl_805D7E00;
            v_end = size + (f32)ch[1];
            quad[7] = v_end * lbl_805D7E00;
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

void render__10TAdEndTextFv(u8 *arg0) {
    Self_8001AD8C *self = (Self_8001AD8C *)arg0;
    f32 hi;
    f32 lo;
    f32 y;
    u32 i;
    s32 col;
    lo = lbl_805D7E04;
    hi = lbl_805D7E14;
    for (i = 0; i < self->count; i++) {
        col = -1;
        y = self->pos[i].y;
        if (y <= lo || lbl_805D7E08 <= y) {
            col = 0xFFFFFF;
        }
        if (lo < y && y < lbl_805D7E0C) {
            col = (__cvt_fp2unsigned((lbl_805D7E10 * (y - lo)) / lo) << 24) | 0xFF0000 | 0xFFFF;
        }
        if (hi < y && y < lbl_805D7E08) {
            col = (__cvt_fp2unsigned((lbl_805D7E10 * (lbl_805D7E08 - y)) / lbl_805D7E04) << 24) | 0xFF0000 | 0xFFFF;
        }
        switch ((s8)((char **)TAdEndText__credit_script_lines)[i][0]) {
        case 0x23:
            if (col != 0xFFFFFF) {
                TAdEndText__sub_8001A998(col, ((char **)TAdEndText__credit_script_lines)[i], self->pos[i].x, y, lbl_805D7E18);
            }
            break;
        case 0x21:
            TObjFish::set_global_param(TAdEndText__loaded_font_texture_list);
            begin_screen_draw(1);
            set_draw_texture_and_color(3, -1);
            draw_textured_quad_at_depth((f32 *)&self->box1, lbl_805D7E18);
            TWindowSubStatusDisp::get_player();
            break;
        case 0x40:
            TObjFish::set_global_param(TAdEndText__loaded_font_texture_list);
            begin_screen_draw(1);
            set_draw_texture_and_color(4, -1);
            draw_textured_quad_at_depth((f32 *)&self->box2, lbl_805D7E18);
            TWindowSubStatusDisp::get_player();
            break;
        default:
            if (col != 0xFFFFFF) {
                draw_small_font_text(col, self->pos[i].x, y, lbl_805D7E18);
            }
            break;
        }
    }
}

#pragma push
#pragma fp_contract on
void run_task__10TAdEndTextFv(u8 *arg0) {
    Self_8001AF80 *self = (Self_8001AF80 *)arg0;
    u32 count;
    u32 i;
    count = self->count;
    if (TAdEndText__font_loaded_flag == 1) {
        count -= 9;
    }
    self->pos[0].y = lbl_805D7E1C - (lbl_805D7E20 / (lbl_804345D8[self->sizeIdx] / lbl_804345D8[0])) * ((self->scale / lbl_805D7E24) * (self->scroll / lbl_805D7E28));
    for (i = 0; i < count; i++) {
        switch ((s8)((char **)TAdEndText__credit_script_lines)[i][0]) {
        case 0x23:
            self->pos[i].x = lbl_805D7E2C;
            self->pos[i + 1].y = TAdEndText__data_805D7DF8 + self->pos[i].y;
            break;
        case 0x21:
            self->pos[i].x = lbl_805D7E30;
            self->pos[i + 1].y = lbl_805D7E34 + self->pos[i].y;
            self->box1.x0 = self->pos[i].x;
            self->box1.y0 = self->pos[i].y;
            self->box1.x1 = lbl_805D7E34 + self->box1.x0;
            self->box1.y1 = lbl_805D7E34 + self->box1.y0;
            break;
        case 0x40:
            self->pos[i].x = lbl_805D7E30;
            self->pos[i + 1].y = lbl_805D7E34 + self->pos[i].y;
            self->box2.x0 = self->pos[i].x;
            self->box2.y0 = self->pos[i].y;
            self->box2.x1 = lbl_805D7E34 + self->box2.x0;
            self->box2.y1 = lbl_805D7E34 + self->box2.y0;
            break;
        default:
            self->pos[i].x = lbl_805D7E2C;
            self->pos[i + 1].y = lbl_805D7E38 + self->pos[i].y;
            break;
        }
    }
    self->scroll = self->scroll + self->speed;
    if (self->pos[self->count].y < lbl_805D7E3C) {
        TAdEndText__font_loaded_flag = 1;
    }
}

TAdEndText::~TAdEndText() {}
#pragma pop

typedef struct Box_8001B190 Box_8001B190;
typedef struct Self_8001B190 Self_8001B190;
u8 *__ct__10TAdEndTextFv(u8 *object, TObject *parent) {
  Self_8001B190 *self = (Self_8001B190 *) object;
  s32 c;
  __ct__7TObjectFP7TObject(object, parent);
  self->vtable = __vt__10TAdEndText;
  self->name = (s32)TAdEndText__class_name;
  self->f1C = 0;
  self->scroll = lbl_805D7DFC;
  TAdEndText__font_loaded_flag = 0;
  self->box1.x0 = lbl_805D7DFC;
  self->box1.y0 = lbl_805D7DFC;
  self->box1.x1 = lbl_805D7DFC;
  self->box1.y1 = lbl_805D7DFC;
  self->box1.x2 = lbl_805D7DFC;
  self->box1.y2 = lbl_805D7DFC;
  self->box1.w = lbl_805D7E20;
  self->box1.h = lbl_805D7E20;
  self->box2.x0 = lbl_805D7DFC;
  self->box2.y0 = lbl_805D7DFC;
  self->box2.x1 = lbl_805D7DFC;
  self->box2.y1 = lbl_805D7DFC;
  self->box2.x2 = lbl_805D7DFC;
  self->box2.y2 = lbl_805D7DFC;
  self->box2.w = lbl_805D7E20;
  self->box2.h = lbl_805D7E20;
  self->count = 0;
  self->height = lbl_805D7DFC;
  while (((char) (c = ((u8 **) TAdEndText__credit_script_lines)[self->count][0])) != 0x2A)
  {
    switch ((s8) c)
    {
      case 0x23:
      case 0:
        self->height = self->height + TAdEndText__data_805D7DF8;
        break;
      case 0x21:
        self->height = self->height + lbl_805D7E34;
        break;
      case 0x40:
        self->height = self->height + lbl_805D7E34;
        break;
      default:
        self->height = self->height + lbl_805D7E38;
        break;
    }
    self->count++;
  }
  self->rate = (TKeyBoardControl__sub_8000F828() == 0) ? (lbl_805D7E20) : (lbl_805D7E40);
  self->speed = lbl_805D7DF0 * self->rate;
  self->sizeIdx = (TAdEndText__sub_8001B41C() != 0) ? (1) : (0);
  return object;
}

void TAdEndText::free_resources() {
    if ((u32) TAdEndText__loaded_font_texture_list != 0U) {
        release_texture_list((void*)TAdEndText__loaded_font_texture_list);
        TAdEndText__loaded_font_texture_list = 0U;
    }
    if ((u32) TAdEndText__credit_script_lines != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)TAdEndText__credit_script_lines));
        TAdEndText__credit_script_lines = 0U;
    }
}

extern s32 ending_sequence_active;

typedef char RecoveredGlobal_8001B3BC_lbl_804F5800_size[sizeof(RecoveredGlobal_8001B3BC_lbl_804F5800) == 0x100 ? 1 : -1];

void TAdEndText::load_ending_font() {
    TAdEndText__loaded_font_texture_list = (u32)&TAdEndText__ending_font_texture_list;
    bind_gvm_texture_list(lbl_804347B0, &TAdEndText__ending_font_texture_list);
    TAdEndText__credit_script_lines = (u32)create_named_object((s32)lbl_804347C0);
    TAdEndText__font_loaded_flag = 0;
}

s32 TAdEndText__sub_8001B3BC(u8 arg0) {
    return *(u8 *)((s8 *)((u8 *)&__ctype_map.value + arg0) + 0) & 0x10;
}

typedef char RecoveredGlobal_8001B3EC_lbl_804F5800_size[sizeof(RecoveredGlobal_8001B3EC_lbl_804F5800) == 0x100 ? 1 : -1];

typedef char RecoveredGlobal_8001B3D4_lbl_804F5800_size[sizeof(RecoveredGlobal_8001B3D4_lbl_804F5800) == 0x100 ? 1 : -1];
s32 TAdEndText__sub_8001B3D4(u8 arg0) {
    return *(u8 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_8001B3D4_lbl_804F5800 *)&__ctype_map).value) + arg0) + 0) & 0x80;
}

s32 TAdEndText__sub_8001B3EC(u8 arg0) {
    return *(u8 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_8001B3EC_lbl_804F5800 *)&__ctype_map).value) + arg0) + 0) & 0xD0;
}

typedef char RecoveredGlobal_8001B404_lbl_804F5800_size[sizeof(RecoveredGlobal_8001B404_lbl_804F5800) == 0x100 ? 1 : -1];
s32 TAdEndText__sub_8001B404(u8 arg0) {
    return *(u8 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_8001B404_lbl_804F5800 *)&__ctype_map).value) + arg0) + 0) & 0x40;
}

s32 TAdEndText__sub_8001B41C(void) {
    return ending_sequence_active;
}

s32 TAdEndText__font_loaded_flag;
u32 TAdEndText__loaded_font_texture_list;
u32 TAdEndText__credit_script_lines;
__declspec(section ".rodata") char lbl_804347B0[] = "ed128_font.gvm";
__declspec(section ".rodata") char lbl_804347C0[] = "AdEnding.rel";
__declspec(section ".sdata2") extern const f32 lbl_805D7DF0 = 2.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7DF4 = 10.0f;
__declspec(section ".sdata2") extern const f32 TAdEndText__data_805D7DF8 = 20.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7DFC = 0.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E00 = 0.0078125f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E04 = 40.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E08 = 422.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E0C = 80.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E10 = 255.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E14 = 382.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E18 = 0.99999f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E1C = 431.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E20 = 1.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E24 = 9917.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E28 = 1.85f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E2C = 50.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E30 = 45.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E34 = 256.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E38 = 15.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E3C = 250.0f;
__declspec(section ".sdata2") extern const f32 lbl_805D7E40 = 1.2f;

}
