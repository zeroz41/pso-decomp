#include "types.h"
#include "pso/misc/TWindowKeyBoardBase_8008102C.h"
#include "pso/misc/TWindowKeyBoardBase.h"
#include <stddef.h>
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/TObjCMHairMenu.h"

struct Rec_8025D3CC { u8 a; s8 len; };

struct Desc_8025DECC { f32 *pos; u32 *col; s32 a; s32 b; };

struct KbRec_8025D264 {
    u8 tag;
    s8 len;
    u8 kind;
    char str[1];
};

struct KbSoft_8025D264 {
    u8 pad0[0xa0];
    u8 *buf;
    u8 *cursor;
    s32 kind;
    u8 padac[4];
    s32 remain;
};

extern "C" {
s32 strnlen__19TWindowKeyBoardSoftFPScUl(void *, u32);
s32 strncpy(s32 *, u8 *, s32);
void set_glyph_quad_extents(u8, void *);
s32 map_char_to_font_code(u16);
u8 get_font_char_advance(s32);
void apply_context_transform_to_rect(void *, void *);
extern u32 lbl_804CFA84[];
extern const f32 lbl_805DD048;
extern const f32 lbl_805DD058;
s32 measure_string_len__20TWindowSubStatusDispFv(void *);
struct KbSoft_8025CFA8 {
    u8 pad0[0xA8];
    s32 sel;
    s32 count;
};

struct KbSoft_8025D47C {
    u8 pad0[0x9c];
    u8 *base;
    u8 *buf;
    u8 *cursor;
    s32 kind;
    u8 padac[4];
    s32 remain;
};

struct KbSoft_8025D664 {
    u8 pad0[0x60];
    u16 flags;
    u8 pad62[0xa0 - 0x62];
    u8 *buf;
    u8 *cursor;
    s32 sel;
    s32 count;
};

struct KbSoft_8025D7FC {
    u8 pad0[0x60];
    u16 flags;
    u8 pad62[0xa8 - 0x62];
    s32 sel;
    s32 count;
};

struct KbSoft_8025D8C8 {
    u8 pad0[0x60];
    u16 flags;
    u8 pad62[0xa8 - 0x62];
    s32 sel;
    s32 count;
};

struct KbSoft_8025DBDC {
    u8 pad0[0x84];
    u16 *buf;
    s32 count;
    u8 pad8c[0xb4 - 0x8c];
    u32 mode;
};

struct Stack_8025E6DC {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

struct Box_8025E350 {
    u8 pad0[0x10];
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    u8 pad20[0x38 - 0x20];
    f32 z;
};

struct Quad_8025E350 {
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    f32 uv[4];
};

u8 calc_gauge_scale__20TWindowSubStatusDispFPvPvi(s32, void *, s32);
s32 end_render_forward__20TWindowSubStatusDispFPv();
s32 fn_8025CE00(void *, u8 *);
void TWindowKeyBoardSoft__sub_8025CF50(void *, int, int);
void TWindowKeyBoardSoft__sub_8025CFA8(void *, s32 *);
void TWindowKeyBoardSoft__sub_8025D1C8(void *, void *);
s32 TWindowKeyBoardSoft__sub_8025D378(void *, void *);
s32 TWindowKeyBoardSoft__sub_8025D544(void *, s32 *, s8 *);
void TWindowKeyBoardSoft__sub_8025D7FC(KbSoft_8025D7FC *self);
void TWindowKeyBoardSoft__sub_8025D8C8(KbSoft_8025D8C8 *self);
void TWindowKeyBoardSoft__sub_8025DBDC(void *, s32);
s32 dispatch_request_0f__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x10__19TWindowKeyBoardSoftFll(void *, void *);
s32 is_alpha_char__20TWindowSubStatusDispFUs(u16);
void delete_chars__19TWindowKeyBoardSoftFll(void *, s32, s32);
void fn_8025DE10(void *, void *);
void TWindowSubStatusDisp__sub_8025E148(TWindowKeyBoardBase *, TWindowKeyBoardSoft *, f32 *, u16 *, u32);
void TWindowSubStatusDisp__sub_8025E530(TWindowKeyBoardBase *, TWindowKeyBoardSoft *, f32 *, u16 *, u32, s32);
void draw_textured_quad_at_depth(void *, f32);
s32 dispatch_request_0x27__19TWindowKeyBoardSoftFll(void *, s32 *);
s32 dispatch_request_0x26__19TWindowKeyBoardSoftFll(void *, s32 *);
int strcmp(const char *, const char *);
extern u16 soft_keyboard_conversion_exclusions[];
s32 dispatch_request_0x25__19TWindowKeyBoardSoftFll(void *, s32 *);
s32 dispatch_request_0x23__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x24__19TWindowKeyBoardSoftFll(void *, void *);
extern s32 actor_frame_tick;
extern const f32 lbl_805DD04C;
extern const f32 lbl_805DD050;
extern const f32 lbl_805DD054;
s32 dispatch_request_0x22__19TWindowKeyBoardSoftFll(void *, void *);
s32 TWindowKeyBoardSoft__sub_803E67D4(void *, void *);
s32 TWindowKeyBoardSoft__sub_803E6868(void *, void *);
s32 dispatch_request_0x14__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x13__19TWindowKeyBoardSoftFlll(u8 *, s32 *, s8 *);

extern const f32 lbl_805DD038;
extern const f32 lbl_805DD03C;
extern const f32 lbl_805DD040;
extern const f32 lbl_805DD044;
extern const f32 lbl_805DD05C;
extern const f32 lbl_805DD060;

void TWindowKeyBoardBase::init_keyboard_text_field(u32 arg1, u32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 == 0) {
        this->m_38 = (f32) lbl_805DD038;
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) lbl_805DD03C;
    } else {
        this->m_38 = (f32) (lbl_805DD040 + (lbl_805DD044 + (f32) arg1));
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (lbl_805DD048 + (f32) (arg2 * 0x14));
    }
    this->m_48 = (f32) this->m_38;
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
    init_keyboard_text_buffer((u8 *)&this->m_6c, arg1, arg2);
    *(u8 **)((s8 *)arg0 + 0x68) = (unsigned char *) (arg0 + 0x6C);
    this->m_60 = 0;
}

s32 fn_8025CE00(void *keyboard, u8 *text) {
    char *p = (char *)text;
    u16 ch;

    while (*p != 0) {
        ch = *p++;
        if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
            ch <<= 8;
            ch |= *p++ & 0xFF;
        }
        if (ch == 0x814A) {
            return 1;
        }
        if (ch == 0x814B) {
            return 1;
        }
        if (ch == 0x819B) {
            return 1;
        }
        if (ch == 0x817E) {
            return 1;
        }
        if (ch == 0x81A8) {
            return 1;
        }
        if (ch == 0x81A9) {
            return 1;
        }
        if (ch == 0x81AA) {
            return 1;
        }
        if (ch == 0x81AB) {
            return 1;
        }
        if (ch == 0x8163) {
            return 1;
        }
        if (ch == 0x81A2) {
            return 1;
        }
        if (ch == 0x81A4) {
            return 1;
        }
        if (ch == 0x81F4) {
            return 1;
        }
        if (ch == 0x8199) {
            return 1;
        }
        if (ch >= 0xE000) {
            return 1;
        }
        if (ch >= 0xE0 && ch <= 0xFF) {
            return 1;
        }
    }
    return 0;
}

void TWindowKeyBoardSoft__sub_8025CF50(void *keyboard, int count, int unused) {
    char tmp[0x100];
    char out[0x100];
    u32 i;

    if (count != 0xF1 && count != 0xF0) {
        for (i = 1; i < count; i++) {
            TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        }
    }
}

#define self ((KbSoft_8025CFA8 *)arg0)
void TWindowKeyBoardSoft__sub_8025CFA8(void *arg0, s32 *arg1) {
#define text ((char *)arg1)
    char out[0x100];
    char tmp[0x100];
    char *p;
    u16 ch;
    s32 c;
    s32 c2;
    u16 *t;

    p = text;
    while (*p != 0) {
        ch = *p++;
        if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
            ch <<= 8;
            ch |= *p++ & 0xFF;
        }
        if ((s32)(u16)ch == 0x5C) {
            return;
        }
        if ((u16)ch >= 0xA0 && (u16)ch <= 0xFF) {
            return;
        }
    }
    dispatch_request_0x25__19TWindowKeyBoardSoftFll(out, (s32 *)tmp);
    if (strcmp(text, out) != 0) {
        self->sel++;
        self->count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        return;
    }
    dispatch_request_0x26__19TWindowKeyBoardSoftFll(out, (s32 *)tmp);
    if (strcmp(text, out) != 0) {
        self->sel++;
        self->count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        return;
    }
    TWindowKeyBoardSoft::dispatch_request_0x28((s32)out, (s32)((s32 *)tmp));
    if (strcmp(text, out) != 0) {
        self->sel++;
        self->count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        return;
    }
    p = text;
    while (*p != 0) {
        ch = *p++;
        if ((ch & 0xE0) == 0x80 && (ch & 0xE0) == 0x80) {
            ch <<= 8;
            ch |= *p++ & 0xFF;
            for (t = soft_keyboard_conversion_exclusions; *t != 0; t++) {
                if ((u16)ch == *t) {
                    return;
                }
            }
        }
    }
    dispatch_request_0x27__19TWindowKeyBoardSoftFll(out, (s32 *)tmp);
    if (strcmp(text, out) != 0) {
        self->sel++;
        self->count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
    }
}
#undef self
#undef text

void TWindowKeyBoardSoft__sub_8025D1C8(void *arg0, void *arg1) {
    KbSoft_8025D264 *self = (KbSoft_8025D264 *)arg0;
    s8 *src = (s8 *)arg1;
    s8 *dst = src;
    s32 len = src[1];
    s8 n;

    src += len + 3;
    *src = *dst;
    while (*src != 0) {
        KbRec_8025D264 *from = (KbRec_8025D264 *)src;
        KbRec_8025D264 *to = (KbRec_8025D264 *)dst;
        to->tag = from->tag;
        to->len = n = from->len;
        to->kind = from->kind;
        src += 3;
        dst += 3;
        while (n-- != 0) {
            *dst++ = *src++;
        }
    }
    *dst = *src;
    self->remain += len + 3;
    if (self->cursor > self->buf) {
        self->cursor -= len + 3;
    }
}

#pragma push
#pragma opt_propagation off
void TWindowKeyBoardSoft::insert_string(char *src) {
    KbSoft_8025D264 *self = (KbSoft_8025D264 *)this;
    s32 n;
    u8 *p = self->buf;
    s8 len = measure_string_len__20TWindowSubStatusDispFv(src);
    KbRec_8025D264 *rec;
    u8 *dst;
    s8 total;
    s8 *q;
    u8 saved = p[0];
    total = 0;
    p[0] = len;
    while ((s8)p[0] != 0) {
        s8 step = p[1] + 3;
        p += step;
        total += step;
    }
    n = len + 3;
    dst = p + n;
    do {
        *dst-- = *p--;
    } while (total-- != 0);
    q = (s8 *)self->buf;
    q[0] = saved;
    q[1] = len;
    q[2] = self->kind;
    q += 3;
    strncpy((s32 *)q, (u8 *)src, len);
    self->remain -= n;
    if (self->cursor > self->buf) {
        self->cursor += n;
    }
}
#pragma pop

void TWindowKeyBoardSoft::update_input(void* a1) { TWindowKeyBoardSoft__sub_8025D1C8(this, *(void**)((char*)this + 0xa0)); insert_string((char *)(a1)); }

#pragma push
#pragma optimization_level 2
s32 TWindowKeyBoardSoft__sub_8025D378(void *arg0, void *arg1) {
    KbSoft_8025D264 *self = (KbSoft_8025D264 *)arg0;
    s32 len = ((KbRec_8025D264 *)self->buf)->len;
    s32 need = measure_string_len__20TWindowSubStatusDispFv(arg1);

    return (self->remain >= need - len) ? 1 : 0;
}
#pragma pop

void TWindowKeyBoardSoft::append_text_entry(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    Rec_8025D3CC *rec;
    s32 idx;
    s32 n;
    u8 *p;
    rec = *(Rec_8025D3CC **)(arg0 + 0xA0);
    idx = rec->len;
    p = (u8 *)(idx + (s32)rec);
    n = ((s32 (*)(void *, u32, s32))strnlen__19TWindowKeyBoardSoftFPScUl)(arg1, 0x100, (s32)rec);
    p[3] = idx;
    p[4] = n;
    p[5] = 1;
    p += 6;
    strncpy((s32 *)p, arg1, n);
    p += n;
    *p++ = 0;
    *(s32 *)(arg0 + 0xB0) = 0x94 - (p - *(u8 **)(arg0 + 0x9C));
    if (*(s32 *)(arg0 + 0xB0) < 0) {
        *(u16 *)(arg0 + 0x60) |= 0x10;
    }
    *(u32 *)(arg0 + 0xA4) = *(u32 *)(arg0 + 0xA0);
}

void TWindowKeyBoardSoft::write_name_and_text(char *name, char *text) {
    KbSoft_8025D47C *self = (KbSoft_8025D47C *)this;
    u8 *p = self->buf;
    s32 n1 = strnlen__19TWindowKeyBoardSoftFPScUl(name, 0x100);
    s32 n2;
    p[1] = n1;
    p[2] = self->kind;
    p += 3;
    strncpy((s32 *)p, (u8 *)name, n1);
    p += n1;
    n1 = (s8)n1;
    n2 = strnlen__19TWindowKeyBoardSoftFPScUl(text, 0x100);
    p[0] = n1;
    p[1] = n2;
    p[2] = 1;
    p += 3;
    strncpy((s32 *)p, (u8 *)text, n2);
    p += n2;
    *p++ = 0;
    self->remain = 0x94 - (p - self->base);
    self->cursor = self->buf;
}

#pragma push
#pragma optimization_level 2
s32 TWindowKeyBoardSoft__sub_8025D544(void *arg0, s32 *name, s8 *text) {
    s32 name_len = strnlen__19TWindowKeyBoardSoftFPScUl(name, 0x100);
    s32 text_len = strnlen__19TWindowKeyBoardSoftFPScUl(text, 0x100);
    s32 room = 0x94 - (((KbSoft_8025D47C *)arg0)->buf - ((KbSoft_8025D47C *)arg0)->base);

    room -= 3;
    room -= name_len;
    room -= 3;
    room -= text_len;
    room -= 1;
    return (room >= 0) ? 1 : 0;
}
#pragma pop

void TWindowKeyBoardSoft::set_kanji_mode() {
    s8 sp8[0x200];

    if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
        dispatch_request_0x26__19TWindowKeyBoardSoftFll(sp8, (s32 *)(sp8 + 0x100));
        *(s32 *)((s8 *)this + 0xA8) = 0xF0;
        update_input(sp8);
    }
}

void TWindowKeyBoardSoft::set_kana_mode() {
    s8 sp8[0x200];

    if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
        dispatch_request_0x25__19TWindowKeyBoardSoftFll(sp8, (s32 *)(sp8 + 0x100));
        *(s32 *)((s8 *)this + 0xA8) = 0xF1;
        update_input(sp8);
    }
}

#define self ((KbSoft_8025D664 *)arg0)
void TWindowKeyBoardSoft__sub_8025D664(void *arg0) {
    char text[0x100];
    char name[0x100];
    s32 count;
    u8 *rec;
    s32 i;
    u8 kind;

    if (self->flags & 0x10) {
        return;
    }
    count = dispatch_request_0x24__19TWindowKeyBoardSoftFll(name, text);
    if (count == 0) {
        return;
    }
    rec = self->buf;
    self->buf += ((KbRec_8025D264 *)rec)->len + 3;
    if (self->buf > self->cursor) {
        i = 1;
        TWindowKeyBoardSoft__sub_8025CFA8(self, (s32 *)name);
        while (TWindowKeyBoardSoft__sub_8025D544(self, (s32 *)name, (s8 *)text) == 0) {
            TWindowKeyBoardSoft__sub_803E6868(name, text);
            i++;
            if (i > count) {
                self->buf = rec;
                TWindowKeyBoardSoft::dispatch_request_0x23((s32)name, (s32)text);
                ((void (*)(void *, int))TWindowKeyBoardSoft__sub_8025CF50)(self, self->sel);
                return;
            }
        }
        rec[2] = self->sel;
        self->sel = i;
        ((TWindowKeyBoardSoft *)self)->write_name_and_text(name, text);
    } else {
        kind = self->buf[2];
        rec[2] = self->sel;
        self->sel = kind;
        ((void (*)(void *, int))TWindowKeyBoardSoft__sub_8025CF50)(self, kind);
    }
    self->count = count;
}
#undef self

void TWindowKeyBoardSoft::process_input() {
    u8 *arg0 = (u8 *)this;
    u8 sp108[0x100];
    u8 sp8[0x100];
    s32 temp_r3;
    u8 *temp_r5;

    if (!(*(u16 *)((s8 *)arg0 + 0x60) & 0x10)) {
        temp_r3 = dispatch_request_0x23__19TWindowKeyBoardSoftFll(sp8, sp108);
        if (temp_r3 != 0) {
            *(s32 *)((s8 *)arg0 + 0xAC) = temp_r3;
            *(u8 *)((s8 *)(*(void **)((s8 *)arg0 + 0xA0)) + 2) = (u8) *(s32 *)((s8 *)arg0 + 0xA8);
            temp_r5 = (unsigned char *) (*(void **)((s8 *)arg0 + 0xA0));
            *(void **)((s8 *)arg0 + 0xA0) = (void *) (temp_r5 - ((s8) *(u8 *)((s8 *)temp_r5 + 0) + 3));
            *(s32 *)((s8 *)arg0 + 0xA8) = (s32) *(u8 *)((s8 *)(*(void **)((s8 *)arg0 + 0xA0)) + 2);
            TWindowKeyBoardSoft__sub_8025CF50((void *)arg0, (int) (*(s32 *)((s8 *)arg0 + 0xA8)), (int)temp_r5);
        }
    }
}

void TWindowKeyBoardSoft__sub_8025D7FC(KbSoft_8025D7FC *self) {
    char text[0x100];
    char name[0x100];
    s32 n;
    s32 i;
    if (self->flags & 0x10) {
        return;
    }
    n = dispatch_request_0x22__19TWindowKeyBoardSoftFll(name, text);
    if (n == 0) {
        return;
    }
    i = 1;
    TWindowKeyBoardSoft__sub_8025CFA8(self, (s32 *)name);
    while (TWindowKeyBoardSoft__sub_8025D544(self, (s32 *)name, (s8 *)text) == 0) {
        TWindowKeyBoardSoft__sub_803E6868(name, text);
        i++;
        if (i > n) {
            TWindowKeyBoardSoft__sub_803E67D4(name, text);
            ((s32 (*)(void *, int))TWindowKeyBoardSoft__sub_8025CF50)(self, self->sel);
            ((TWindowKeyBoardSoft *)self)->append_text_entry((u8 *)text);
            return;
        }
    }
    self->sel = i;
    self->count = n;
    ((TWindowKeyBoardSoft *)self)->write_name_and_text((char *)((s32 *)name), (char *)((s8 *)text));
}

void TWindowKeyBoardSoft__sub_8025D8C8(KbSoft_8025D8C8 *self) {
    char text[0x100];
    char name[0x100];
    s32 n;
    s32 i;
    if (self->flags & 0x10) {
        return;
    }
    n = ((s32)TWindowKeyBoardSoft__sub_803E67D4(name, text));
    if (n == 0) {
        return;
    }
    i = 1;
    TWindowKeyBoardSoft__sub_8025CFA8(self, (s32 *)name);
    while (TWindowKeyBoardSoft__sub_8025D544(self, (s32 *)name, (s8 *)text) == 0) {
        TWindowKeyBoardSoft__sub_803E6868(name, text);
        i++;
        if (i > n) {
            dispatch_request_0x22__19TWindowKeyBoardSoftFll(name, text);
            ((s32 (*)(void *, int))TWindowKeyBoardSoft__sub_8025CF50)(self, self->sel);
            ((TWindowKeyBoardSoft *)self)->append_text_entry((u8 *)text);
            return;
        }
    }
    self->sel = i;
    self->count = n;
    ((TWindowKeyBoardSoft *)self)->write_name_and_text((char *)((s32 *)name), (char *)((s8 *)text));
}

void TWindowKeyBoardSoft::select_next() {
    struct { u8 _pad[0x100]; } sp108;
    struct { u8 _pad[0x100]; } sp8;

    if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
        do {
            TWindowKeyBoardSoft__sub_803E6868(&sp8, &sp108);
            *(s32 *)((s8 *)this + 0xA8) = (s32) (*(s32 *)((s8 *)this + 0xA8) + 1);
            if ((s32) *(s32 *)((s8 *)this + 0xA8) > (s32) *(s32 *)((s8 *)this + 0xAC)) {
                *(s32 *)((s8 *)this + 0xA8) = 1;
            }
        } while (TWindowKeyBoardSoft__sub_8025D378(this, &sp8) == 0);
        update_input(&sp8);
    }
}

void TWindowKeyBoardSoft::update() {
    u8 sp108[0x100];
    u8 sp8[0x100];

    if (!(*(u16 *)((s8 *)this + 0x60) & 0x10)) {
        do {
            dispatch_request_0x14__19TWindowKeyBoardSoftFll(sp8, sp108);
            *(s32 *)((s8 *)this + 0xA8) = (s32) (*(s32 *)((s8 *)this + 0xA8) - 1);
            if ((s32) *(s32 *)((s8 *)this + 0xA8) <= 0) {
                *(s32 *)((s8 *)this + 0xA8) = (s32) *(s32 *)((s8 *)this + 0xAC);
            }
        } while (TWindowKeyBoardSoft__sub_8025D378(this, sp8) == 0);
        update_input(sp8);
    }
}

void TWindowKeyBoardSoft::convert_input_text() {
    s8 sp108[0x100];
    s8 sp8[0x100];
    u16 *var_r3;
    int temp_r0;
    u8 *var_r4;

    if (!(*(u16 *)((s8 *)this + 0x60) & 0x80)) {
        TWindowKeyBoardSoft__sub_8025DBDC(this, 1);
    }
    var_r3 = *(u16 **)((s8 *)this + 0x84);
    var_r4 = *(u8 **)((s8 *)this + 0x9C);
    while ((temp_r0 = *var_r3) != 0) {
        *var_r4 = (u8) (temp_r0 >> 8);
        if ((s8) *var_r4 != 0) {
            var_r4 += 1;
        }
        temp_r0 = *var_r3;
        var_r3 = (u16 *)((u8 *)var_r3 + 2);
        *var_r4 = (u8) temp_r0;
        var_r4 += 1;
    }
    *var_r4 = 0;
    *(u8 **)((s8 *)this + 0xA0) = (u8 *) *(u8 **)((s8 *)this + 0x9C);
    if (fn_8025CE00(this, *(u8 **)((s8 *)this + 0x9C)) != 0) {
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 0x10);
        *(s32 *)((s8 *)this + 0xAC) = 1;
        *(s32 *)((s8 *)this + 0xA8) = 1;
        strncpy((s32 *)sp8, *(u8 **)((s8 *)this + 0x9C), 0x100);
        sp108[0] = 0;
    } else {
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) & 0xFFFFFFEF);
        *(s32 *)((s8 *)this + 0xAC) = dispatch_request_0x13__19TWindowKeyBoardSoftFlll(*(u8 **)((s8 *)this + 0x9C), (s32 *)sp8, sp108);
        *(s32 *)((s8 *)this + 0xA8) = 1;
        TWindowKeyBoardSoft__sub_8025CFA8(this, (s32 *)sp8);
    }
    *(s32 *)((s8 *)this + 0xB0) = 0x94;
    if (TWindowKeyBoardSoft__sub_8025D544(this, (s32 *)sp8, sp108) != 0) {
        write_name_and_text((char *)((s32 *)sp8), (char *)(sp108));
        *(u16 *)((s8 *)this + 0x60) = (u16) (*(u16 *)((s8 *)this + 0x60) | 4);
    }
}

void TWindowKeyBoardSoft__sub_8025DBDC(void *arg0, s32 arg1) {
    KbSoft_8025DBDC *self = (KbSoft_8025DBDC *)arg0;
    u16 *p;
    s32 lim; u32 n; s32 j; s32 rb; s32 ret; s8 c; s8 *q;
    u32 cnt;
    s8 out[5]; s8 scratch[8];
    cnt = self->count;
    if (cnt == 0) return;
    p = self->buf + cnt - 1;
    lim = cnt;
    n = 0;
    if ((s32)cnt > 4) lim = 4;
    while (is_alpha_char__20TWindowSubStatusDispFUs(*p) != 0) { lim--; p--; n++; if (lim <= 0) break; }
    p++; j = 0;
    while (j < n) { out[j] = (u8)*p; j++; p++; }
    out[j] = 0;
    q = out;
    for (;;) {
        rb = n * 2;
        if (n == 0) break;
        if (arg1 == 0 && n == 1) { c = *q; if (c == 'n' || c == 'N') return; }
        if (self->mode & 8) { ret = dispatch_request_0f__19TWindowKeyBoardSoftFll(q, scratch); } else { ret = dispatch_request_0x10__19TWindowKeyBoardSoftFll(q, scratch); }
        if (ret != 0 && n > 1 && q[0] == q[1]) {
            if (self->mode & 8) {
                *(u16 *)((s8*)self->buf + self->count * 2 - rb) = 0x8362;
            } else {
                *(u16 *)((s8*)self->buf + self->count * 2 - rb) = 0x82C1;
            }
        }
        q++; n--; rb -= 2;
        if (ret != 0) continue;
        s32 bytes = 0;
        s8 *w = scratch;
        u16 *dst = (u16 *)((char *)self->buf + self->count * 2 - ((n + 1) * 2));
        u16 v;
        while (*w != 0) {
            v = *w++;
            bytes++;
            v <<= 8;
            v |= *w & 0xFF;
            w++;
            *dst = v;
            dst++;
        }
        s32 m = (n + 1) - bytes;
        delete_chars__19TWindowKeyBoardSoftFll((s8 *)self + 0x84, self->count - m, m);
        self->count = self->count - m;
        break;
    }
}

void fn_8025DE10(void *arg0, void *arg1) {
    f32 pos[8];
    Desc_8025DECC d;
    u32 col[4];
    f32 bottom;
    f32 depth;

    if (actor_frame_tick & 0x10) {
        return;
    }
    depth = lbl_805DD04C + ((Box_8025E350 *)arg0)->z;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    d.col[0] = 0xFF0080;
    d.col[1] = 0xFF0080;
    d.col[2] = 0xFF0080;
    d.col[3] = 0xFF0080;
    pos[0] = ((f32 *)arg1)[0];
    pos[1] = ((f32 *)arg1)[1];
    pos[2] = lbl_805DD050 + pos[0];
    pos[3] = pos[1];
    pos[4] = lbl_805DD050 + pos[0];
    bottom = lbl_805DD054 + pos[1];
    pos[5] = bottom;
    pos[6] = pos[0];
    pos[7] = bottom;
    ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 6, depth);
}

void TWindowKeyBoardBase::draw_text_glyphs(void *arg1, void *arg2) {
    Quad_8025E350 q;
    f32 pos[8];
    Desc_8025DECC d;
    u32 col[4];
    f32 depth;
    u8 adv;
    u8 n;
    u16 ch;
    char *p;
    s32 ci;
    p = *(char **)((u8 *)this + 0x9C);
    if (p == NULL) {
        return;
    }
    depth = lbl_805DD058 + ((Box_8025E350 *)arg1)->z;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    while (*p != 0) {
        ci = (p == *(char **)((u8 *)this + 0xA0)) ? 1 : 2;
        n = p[1];
        p += 3;
        while (n-- != 0) {
            ch = *p++;
            if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
                ch <<= 8;
                n--;
                ch |= *p++ & 0xFF;
            }
            adv = get_font_char_advance(map_char_to_font_code(ch));
            if (((f32 *)arg2)[0] + (f32)adv > ((Box_8025E350 *)arg1)->x + ((Box_8025E350 *)arg1)->w) {
                ((f32 *)arg2)[0] = ((Box_8025E350 *)arg1)->x;
                ((f32 *)arg2)[1] += lbl_805DD048;
            }
            if ((s32)ch == 0x20) {
                ((f32 *)arg2)[0] += (f32)(s32)adv;
            } else {
                q.x = ((f32 *)arg2)[0];
                q.y = ((f32 *)arg2)[1];
                set_glyph_quad_extents(adv, &q);
                apply_context_transform_to_rect(arg1, &q);
                d.col[0] = lbl_804CFA84[ci];
                d.col[1] = d.col[0];
                d.col[2] = d.col[0];
                d.col[3] = d.col[0];
                pos[0] = q.x;
                pos[1] = q.y;
                pos[2] = q.x2;
                pos[3] = q.y;
                pos[4] = q.x2;
                pos[5] = q.y2;
                pos[6] = q.x;
                pos[7] = q.y2;
                ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 6, depth);
                ((f32 *)arg2)[0] += (f32)(s32)adv;
            }
        }
    }
}

void TWindowSubStatusDisp__sub_8025E148(TWindowKeyBoardBase *self, TWindowKeyBoardSoft *box, f32 *cursor, u16 *text, u32 count) {
    Quad_8025E350 q;
    f32 pos[8];
    Desc_8025DECC d;
    u32 col[4];
    f32 depth;
    u16 ch;
    u8 adv;

    depth = lbl_805DD058 + box->depth;
    d.pos = pos;
    d.col = col;
    d.a = 0;
    d.b = 4;
    d.col[0] = lbl_804CFA84[2];
    d.col[1] = d.col[0];
    d.col[2] = d.col[0];
    d.col[3] = d.col[0];
    while ((s32)*text != 0 && count-- != 0) {
        ch = *text++;
        adv = get_font_char_advance(map_char_to_font_code(ch));
        if (cursor[0] + (f32)adv > box->inner_x + box->inner_w) {
            cursor[0] = box->inner_x;
            cursor[1] += lbl_805DD048;
        }
        if ((s32)ch == 0x20) {
            cursor[0] += (f32)(s32)adv;
        } else {
            q.x = cursor[0];
            q.y = cursor[1];
            set_glyph_quad_extents(adv, &q);
            apply_context_transform_to_rect(box, &q);
            pos[0] = q.x;
            pos[1] = q.y;
            pos[2] = q.x2;
            pos[3] = q.y;
            pos[4] = q.x2;
            pos[5] = q.y2;
            pos[6] = q.x;
            pos[7] = q.y2;
            ((TObjCMHairMenu *)(&d))->draw_tri_fan_2d(4, 6, depth);
            cursor[0] += (f32)adv;
        }
    }
}

void TWindowKeyBoardBase::draw_wrapped_text(void *arg1, void *arg2) {
    Quad_8025E350 q;
    f32 scale;
    u8 n;
    char *p;
    u16 ch;
    u8 adv;

    p = *(char **)((u8 *)this + 0x9C);
    if (p == NULL) {
        return;
    }
    scale = lbl_805DD05C / (lbl_805DD060 + ((Box_8025E350 *)arg1)->z);
    while (*p != 0) {
        n = p[1];
        p += 3;
        while (n-- != 0) {
            ch = *p++;
            if ((ch & 0xE0) == 0x80 || (ch & 0xE0) == 0xE0) {
                ch <<= 8;
                n--;
                ch |= *p++ & 0xFF;
            }
            adv = calc_gauge_scale__20TWindowSubStatusDispFPvPvi(map_char_to_font_code(ch), &q, -1);
            if (((f32 *)arg2)[0] + (f32)adv > ((Box_8025E350 *)arg1)->x + ((Box_8025E350 *)arg1)->w) {
                ((f32 *)arg2)[0] = ((Box_8025E350 *)arg1)->x;
                ((f32 *)arg2)[1] += lbl_805DD048;
            }
            if ((s32)ch == 0x20) {
                ((f32 *)arg2)[0] += (f32)(s32)adv;
            } else {
                q.x = ((f32 *)arg2)[0];
                q.y = ((f32 *)arg2)[1];
                set_glyph_quad_extents(adv, &q);
                apply_context_transform_to_rect(((Box_8025E350 *)arg1), &q);
                draw_textured_quad_at_depth(&q, scale);
                ((f32 *)arg2)[0] += (f32)(s32)adv;
            }
        }
    }
}

void TWindowSubStatusDisp__sub_8025E530(TWindowKeyBoardBase *self, TWindowKeyBoardSoft *box, f32 *cursor, u16 *text, u32 count, s32 scaled) {
    Quad_8025E350 q;
    f32 depth;
    s32 code;
    u16 ch;
    u8 adv;

    depth = lbl_805DD05C / (lbl_805DD060 + box->depth);
    while ((s32)*text != 0 && count-- != 0) {
        ch = *text++;
        code = map_char_to_font_code(ch);
        if (scaled != 0) {
            adv = calc_gauge_scale__20TWindowSubStatusDispFPvPvi(code, &q, -1);
        } else {
            adv = get_font_char_advance(code);
        }
        if (cursor[0] + (f32)adv > box->inner_x + box->inner_w) {
            cursor[0] = box->inner_x;
            cursor[1] += lbl_805DD048;
        }
        if ((s32)ch == 0x20) {
            cursor[0] += (f32)(s32)adv;
        } else {
            if (scaled != 0) {
                q.x = cursor[0];
                q.y = cursor[1];
                set_glyph_quad_extents(adv, &q);
                apply_context_transform_to_rect(box, &q);
                draw_textured_quad_at_depth(&q, depth);
            }
            cursor[0] += (f32)adv;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TWindowKeyBoardBase::sub_8025E6DC(u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_8025E6DC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8025E6DC, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8025E6DC, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8025E6DC, sp14) == 0xC) ? 1 : -1];
    Stack_8025E6DC stack;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r7;
    s32 temp_r7_2;
    s32 var_r31;
    u16 temp_r3;
    u16 temp_r3_2;
    TWindowKeyBoardSoft *ctx;
    ctx = (TWindowKeyBoardSoft *)arg1;
    var_r31 = 1;
    if (!(this->m_62 & 2) || (ctx->open_tick >= 0)) {
        stack.sp10 = ctx->inner_x;
        stack.sp14 = ctx->inner_y;
        TWindowSubStatusDisp__sub_8025E530(this, ctx, &stack.sp10, this->m_6c, this->m_70, 0);
        temp_r3 = this->m_60;
        if (temp_r3 & 2) {
            if (temp_r3 & 4) {
                this->draw_text_glyphs(ctx, &stack.sp10);
                var_r31 = 0;
            } else {
                TWindowSubStatusDisp__sub_8025E148(this, ctx, &stack.sp10, this->m_84, this->m_94);
            }
        }
        TWindowSubStatusDisp::reset_gauge(0);
        stack.sp10 = ctx->inner_x;
        stack.sp14 = ctx->inner_y;
        TWindowSubStatusDisp__sub_8025E530(this, ctx, &stack.sp10, this->m_6c, this->m_70, 1);
        temp_r3_2 = this->m_60;
        if (temp_r3_2 & 2) {
            if (temp_r3_2 & 4) {
                this->draw_wrapped_text(ctx, &stack.sp10);
            } else {
                TWindowSubStatusDisp__sub_8025E530(this, ctx, &stack.sp10, this->m_84, this->m_88, 1);
                stack.sp8 = stack.sp10;
                stack.spC = stack.sp14;
                temp_r3_3 = this->m_88;
                temp_r7 = this->m_94 - temp_r3_3;
                if (temp_r7 != 0) {
                    TWindowSubStatusDisp__sub_8025E530(this, ctx, &stack.sp10, this->m_84 + temp_r3_3, temp_r7, 1);
                }
            }
        } else {
            stack.sp8 = stack.sp10;
            stack.spC = stack.sp14;
        }
        temp_r3_4 = this->m_70;
        temp_r7_2 = this->m_7c - temp_r3_4;
        if (temp_r7_2 != 0) {
            TWindowSubStatusDisp__sub_8025E530(this, ctx, &stack.sp10, this->m_6c + temp_r3_4, temp_r7_2, 1);
        }
        end_render_forward__20TWindowSubStatusDispFPv();
        if ((var_r31 != 0) && !(this->m_2c & 2)) {
            fn_8025DE10(ctx, &stack.sp8);
        }
    }
}
#pragma pop

}
