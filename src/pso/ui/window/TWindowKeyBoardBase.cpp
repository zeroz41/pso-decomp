#include "pso/ui/font/TNECFontEORFunction.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/system/ResourceFile.h"
#include "pso/system/TGStream.h"
#include "types.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include <stddef.h>
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/quest/TQuestVmDownLoadServer_803E6970.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/Language.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/memory.h"
#include "pso/system/AramPool.h"
#include <string.h>
#include "pso/ui/window/WindowLayout.h"


#pragma push
#pragma readonly_strings on
const char *keyboard_base_type_name_pointer = "TWindowKeyBoardBase";
#pragma pop

WindowDescriptor TWindowKeyBoardBase__window_descriptor = {
    {0.0f, 0.0f}, 50026.0f, NULL, 0x23,
};
u32 lbl_804CFA84[3] = { 0x00000000, 0xC03040C0, 0x1030A0C0 };
// Shift-JIS characters, zero-terminated, scanned by TWindowKeyBoardBase::sub_8025CFA8.
u16 soft_keyboard_conversion_exclusions[20] = {
    0x8141, 0x8142, 0x8145, 0x8158, 0x815B, 0x815F, 0x8175, 0x8176, 0x8177, 0x8178,
    0x818F, 0x8191, 0x8192, 0x81CA, 0x8396, 0x8199, 0x8163, 0x81F4, 0x0000, 0x0000,
};

struct Rec_8025D3CC { u8 a; s8 len; };

struct Desc_8025DECC { f32 *pos; u32 *col; s32 a; s32 b; };

struct KbRec_8025D264 {
    u8 tag;
    s8 len;
    u8 kind;
    char str[1];
};

extern "C" {
s32 map_char_to_font_code(u16);
u8 get_font_char_advance(s32);
struct Stack_8025E6DC {
    NJS_POINT2 caret;
    NJS_POINT2 cursor;
};

u8 calc_gauge_scale__20TWindowSubStatusDispFUsPvl(s32, void *, s32);
s32 dispatch_request_0f__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x10__19TWindowKeyBoardSoftFll(void *, void *);
void draw_textured_quad_at_depth(void *, f32);
s32 dispatch_request_0x27__19TWindowKeyBoardSoftFll(void *, s32 *);
s32 dispatch_request_0x26__19TWindowKeyBoardSoftFll(void *, s32 *);
s32 dispatch_request_0x25__19TWindowKeyBoardSoftFll(void *, s32 *);
s32 dispatch_request_0x24__19TWindowKeyBoardSoftFll(void *, void *);
extern s32 actor_frame_tick;
s32 dispatch_request_0x22__19TWindowKeyBoardSoftFll(void *, void *);
s32 TWindowKeyBoardSoft__sub_803E67D4(void *, void *);
s32 TWindowKeyBoardSoft__sub_803E6868(void *, void *);
s32 dispatch_request_0x14__19TWindowKeyBoardSoftFll(void *, void *);
s32 dispatch_request_0x13__19TWindowKeyBoardSoftFlll(u8 *, s32 *, s8 *);


void TWindowKeyBoardBase::init_keyboard_text_field(u32 width, u32 lines) {
    if (lines == 0) {
        this->target_size[0] = 100000.0f;
        this->target_size[1] = 38.0f;
    } else {
        this->target_size[0] = (f32) (0.1f + (8.0f + (f32) width));
        this->target_size[1] = (f32) (20.0f + (f32) (lines * 0x14));
    }
    this->frame_size[0] = (f32) this->target_size[0];
    this->frame_size[1] = (f32) this->target_size[1];
    m_text.init(width, lines);
    active_text = &m_text;
    this->state_flags = 0;
}

s32 TWindowKeyBoardBase::sub_8025CE00(u8 *text) {
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

void TWindowKeyBoardBase::sub_8025CF50(int count) {
    char tmp[0x100];
    char out[0x100];
    u32 i;

    if (count != 0xF1 && count != 0xF0) {
        for (i = 1; i < count; i++) {
            TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        }
    }
}

void TWindowKeyBoardBase::sub_8025CFA8(s32 *name) {
#define text ((char *)name)
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
        candidate_index++;
        candidate_count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        return;
    }
    dispatch_request_0x26__19TWindowKeyBoardSoftFll(out, (s32 *)tmp);
    if (strcmp(text, out) != 0) {
        candidate_index++;
        candidate_count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
        return;
    }
    TWindowKeyBoardSoft::dispatch_request_0x28(out, tmp);
    if (strcmp(text, out) != 0) {
        candidate_index++;
        candidate_count++;
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
        candidate_index++;
        candidate_count++;
        TWindowKeyBoardSoft__sub_803E6868(out, tmp);
    }
}
#undef text

void TWindowKeyBoardBase::sub_8025D1C8(void *record) {
    s8 *src = (s8 *)record;
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
    candidate_bytes_remaining += len + 3;
    if (last_candidate > current_candidate) {
        last_candidate -= len + 3;
    }
}

#pragma push
#pragma opt_propagation off
void TWindowKeyBoardBase::insert_string(char *src) {
    s32 n;
    u8 *p = current_candidate;
    s8 len = measure_string_len(reinterpret_cast<const char *>(src));
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
    q = (s8 *)current_candidate;
    q[0] = saved;
    q[1] = len;
    q[2] = candidate_index;
    q += 3;
    strncpy((char *)q, (const char *)src, len);
    candidate_bytes_remaining -= n;
    if (last_candidate > current_candidate) {
        last_candidate += n;
    }
}
#pragma pop

void TWindowKeyBoardBase::update_input(void* a1) { sub_8025D1C8(current_candidate); insert_string((char *)(a1)); }

#pragma push
#pragma optimization_level 2
s32 TWindowKeyBoardBase::sub_8025D378(void *window_sub_status_disp) {
    s32 len = ((KbRec_8025D264 *)current_candidate)->len;
    s32 need = measure_string_len(reinterpret_cast<const char *>(window_sub_status_disp));

    return (candidate_bytes_remaining >= need - len) ? 1 : 0;
}
#pragma pop

void TWindowKeyBoardBase::append_text_entry(u8 *text) {
    Rec_8025D3CC *rec;
    s32 idx;
    s32 n;
    u8 *p;
    rec = reinterpret_cast<Rec_8025D3CC *>(current_candidate);
    idx = rec->len;
    p = (u8 *)(idx + (saddr)rec);
    n = TWindowKeyBoardSoft::strnlen((s8 *)text, 0x100);
    p[3] = idx;
    p[4] = n;
    p[5] = 1;
    p += 6;
    strncpy((char *)p, (const char *)text, n);
    p += n;
    *p++ = 0;
    candidate_bytes_remaining = 0x94 - (p - candidate_buffer);
    if (candidate_bytes_remaining < 0) {
        state_flags |= 0x10;
    }
    last_candidate = current_candidate;
}

void TWindowKeyBoardBase::write_name_and_text(char *name, char *text) {
    u8 *p = current_candidate;
    s32 n1 = TWindowKeyBoardSoft::strnlen((s8 *)name, 0x100);
    s32 n2;
    p[1] = n1;
    p[2] = candidate_index;
    p += 3;
    strncpy((char *)p, (const char *)name, n1);
    p += n1;
    n1 = (s8)n1;
    n2 = TWindowKeyBoardSoft::strnlen((s8 *)text, 0x100);
    p[0] = n1;
    p[1] = n2;
    p[2] = 1;
    p += 3;
    strncpy((char *)p, (const char *)text, n2);
    p += n2;
    *p++ = 0;
    candidate_bytes_remaining = 0x94 - (p - candidate_buffer);
    last_candidate = current_candidate;
}

#pragma push
#pragma optimization_level 2
s32 TWindowKeyBoardBase::sub_8025D544(s32 *name, s8 *text) {
    s32 name_len = TWindowKeyBoardSoft::strnlen((s8 *)name, 0x100);
    s32 text_len = TWindowKeyBoardSoft::strnlen(text, 0x100);
    s32 room = 0x94 - (current_candidate - candidate_buffer);

    room -= 3;
    room -= name_len;
    room -= 3;
    room -= text_len;
    room -= 1;
    return (room >= 0) ? 1 : 0;
}
#pragma pop

void TWindowKeyBoardBase::set_kanji_mode() {
    s8 buffers[2][0x100];

    if (!(state_flags & 0x10)) {
        dispatch_request_0x26__19TWindowKeyBoardSoftFll(buffers[0], (s32 *)buffers[1]);
        candidate_index = 0xF0;
        update_input(buffers[0]);
    }
}

void TWindowKeyBoardBase::set_kana_mode() {
    s8 buffers[2][0x100];

    if (!(state_flags & 0x10)) {
        dispatch_request_0x25__19TWindowKeyBoardSoftFll(buffers[0], (s32 *)buffers[1]);
        candidate_index = 0xF1;
        update_input(buffers[0]);
    }
}

void TWindowKeyBoardBase::sub_8025D664() {
    char text[0x100];
    char name[0x100];
    s32 count;
    u8 *rec;
    s32 i;
    u8 kind;

    if (state_flags & 0x10) {
        return;
    }
    count = dispatch_request_0x24__19TWindowKeyBoardSoftFll(name, text);
    if (count == 0) {
        return;
    }
    rec = current_candidate;
    current_candidate += ((KbRec_8025D264 *)rec)->len + 3;
    if (current_candidate > last_candidate) {
        i = 1;
        sub_8025CFA8((s32 *)name);
        while (sub_8025D544((s32 *)name, (s8 *)text) == 0) {
            TWindowKeyBoardSoft__sub_803E6868(name, text);
            i++;
            if (i > count) {
                current_candidate = rec;
                TWindowKeyBoardSoft::dispatch_request_0x23(name, text);
                sub_8025CF50(candidate_index);
                return;
            }
        }
        rec[2] = candidate_index;
        candidate_index = i;
        write_name_and_text(name, text);
    } else {
        kind = current_candidate[2];
        rec[2] = candidate_index;
        candidate_index = kind;
        sub_8025CF50(kind);
    }
    candidate_count = count;
}

void TWindowKeyBoardBase::process_input() {
    u8 text[0x100];
    u8 name[0x100];
    s32 count;
    u8 *cand;

    if (!(state_flags & 0x10)) {
        count = TWindowKeyBoardSoft::dispatch_request_0x23(name, text);
        if (count != 0) {
            candidate_count = count;
            current_candidate[2] = (u8) candidate_index;
            cand = current_candidate;
            current_candidate = cand - (static_cast<s8>(cand[0]) + 3);
            candidate_index = (s32) current_candidate[2];
            this->sub_8025CF50((int) (candidate_index));
        }
    }
}

void TWindowKeyBoardBase::sub_8025D7FC() {
    char text[0x100];
    char name[0x100];
    s32 n;
    s32 i;
    if (state_flags & 0x10) {
        return;
    }
    n = dispatch_request_0x22__19TWindowKeyBoardSoftFll(name, text);
    if (n == 0) {
        return;
    }
    i = 1;
    sub_8025CFA8((s32 *)name);
    while (sub_8025D544((s32 *)name, (s8 *)text) == 0) {
        TWindowKeyBoardSoft__sub_803E6868(name, text);
        i++;
        if (i > n) {
            TWindowKeyBoardSoft__sub_803E67D4(name, text);
            sub_8025CF50(candidate_index);
            append_text_entry((u8 *)text);
            return;
        }
    }
    candidate_index = i;
    candidate_count = n;
    write_name_and_text((char *)((s32 *)name), (char *)((s8 *)text));
}

void TWindowKeyBoardBase::sub_8025D8C8() {
    char text[0x100];
    char name[0x100];
    s32 n;
    s32 i;
    if (state_flags & 0x10) {
        return;
    }
    n = ((s32)TWindowKeyBoardSoft__sub_803E67D4(name, text));
    if (n == 0) {
        return;
    }
    i = 1;
    sub_8025CFA8((s32 *)name);
    while (sub_8025D544((s32 *)name, (s8 *)text) == 0) {
        TWindowKeyBoardSoft__sub_803E6868(name, text);
        i++;
        if (i > n) {
            dispatch_request_0x22__19TWindowKeyBoardSoftFll(name, text);
            sub_8025CF50(candidate_index);
            append_text_entry((u8 *)text);
            return;
        }
    }
    candidate_index = i;
    candidate_count = n;
    write_name_and_text((char *)((s32 *)name), (char *)((s8 *)text));
}

void TWindowKeyBoardBase::select_next() {
    struct { u8 _pad[0x100]; } text;
    struct { u8 _pad[0x100]; } name;

    if (!(state_flags & 0x10)) {
        do {
            TWindowKeyBoardSoft__sub_803E6868(&name, &text);
            candidate_index = (s32) (candidate_index + 1);
            if ((s32) candidate_index > (s32) candidate_count) {
                candidate_index = 1;
            }
        } while (sub_8025D378(&name) == 0);
        update_input(&name);
    }
}

void TWindowKeyBoardBase::update() {
    u8 text[0x100];
    u8 name[0x100];

    if (!(state_flags & 0x10)) {
        do {
            dispatch_request_0x14__19TWindowKeyBoardSoftFll(name, text);
            candidate_index = (s32) (candidate_index - 1);
            if ((s32) candidate_index <= 0) {
                candidate_index = (s32) candidate_count;
            }
        } while (sub_8025D378(name) == 0);
        update_input(name);
    }
}

void TWindowKeyBoardBase::convert_input_text() {
    s8 text[0x100];
    s8 name[0x100];
    u16 *src;
    int code;
    u8 *dst;

    if (!(state_flags & 0x80)) {
        sub_8025DBDC(1);
    }
    src = this->m_text2.buffer;
    dst = candidate_buffer;
    while ((code = *src) != 0) {
        *dst = (u8) (code >> 8);
        if ((s8) *dst != 0) {
            dst += 1;
        }
        code = *src;
        src = (u16 *)((u8 *)src + 2);
        *dst = (u8) code;
        dst += 1;
    }
    *dst = 0;
    current_candidate = candidate_buffer;
    if (sub_8025CE00(candidate_buffer) != 0) {
        state_flags = (u16) (state_flags | 0x10);
        candidate_count = 1;
        candidate_index = 1;
        strncpy((char *)name, (const char *)candidate_buffer, 0x100);
        text[0] = 0;
    } else {
        state_flags = (u16) (state_flags & 0xFFFFFFEF);
        candidate_count = dispatch_request_0x13__19TWindowKeyBoardSoftFlll(candidate_buffer, (s32 *)name, text);
        candidate_index = 1;
        sub_8025CFA8((s32 *)name);
    }
    candidate_bytes_remaining = 0x94;
    if (sub_8025D544((s32 *)name, text) != 0) {
        write_name_and_text((char *)((s32 *)name), (char *)(text));
        state_flags = (u16) (state_flags | 4);
    }
}

void TWindowKeyBoardBase::sub_8025DBDC(s32 finalize) {
    u16 *p;
    s32 lim; u32 n; s32 j; s32 rb; s32 ret; s8 c; s8 *q;
    u32 cnt;
    s8 out[5]; s8 scratch[8];
    cnt = m_text2.cursor;
    if (cnt == 0) return;
    p = m_text2.buffer + cnt - 1;
    lim = cnt;
    n = 0;
    if ((s32)cnt > 4) lim = 4;
    while (TWindowSubStatusDisp::is_alpha_char(*p) != 0) { lim--; p--; n++; if (lim <= 0) break; }
    p++; j = 0;
    while (j < n) { out[j] = (u8)*p; j++; p++; }
    out[j] = 0;
    q = out;
    for (;;) {
        rb = n * 2;
        if (n == 0) break;
        if (finalize == 0 && n == 1) { c = *q; if (c == 'n' || c == 'N') return; }
        if (composition_flags & 8) { ret = dispatch_request_0f__19TWindowKeyBoardSoftFll(q, scratch); } else { ret = dispatch_request_0x10__19TWindowKeyBoardSoftFll(q, scratch); }
        if (ret != 0 && n > 1 && q[0] == q[1]) {
            if (composition_flags & 8) {
                *(u16 *)((s8*)m_text2.buffer + m_text2.cursor * 2 - rb) = 0x8362;
            } else {
                *(u16 *)((s8*)m_text2.buffer + m_text2.cursor * 2 - rb) = 0x82C1;
            }
        }
        q++; n--; rb -= 2;
        if (ret != 0) continue;
        s32 bytes = 0;
        s8 *w = scratch;
        u16 *dst = (u16 *)((char *)m_text2.buffer + m_text2.cursor * 2 - ((n + 1) * 2));
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
        m_text2.delete_chars(m_text2.cursor - m, m);
        m_text2.cursor = m_text2.cursor - m;
        break;
    }
}

void fn_8025DE10(WindowDrawContext *context, NJS_POINT2 *cursor) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 bottom;
    f32 depth;

    if (actor_frame_tick & 0x10) {
        return;
    }
    depth = 0.1794f + context->depth;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    d.col[0].color = 0xFF0080;
    d.col[1].color = 0xFF0080;
    d.col[2].color = 0xFF0080;
    d.col[3].color = 0xFF0080;
    pos[0].x = cursor->x;
    pos[0].y = cursor->y;
    pos[1].x = 5.0f + pos[0].x;
    pos[1].y = pos[0].y;
    pos[2].x = 5.0f + pos[0].x;
    bottom = 18.0f + pos[0].y;
    pos[2].y = bottom;
    pos[3].x = pos[0].x;
    pos[3].y = bottom;
    draw_polygon_2d(&d, 4, 6, depth);
}

void TWindowKeyBoardBase::draw_text_glyphs(WindowDrawContext *context, NJS_POINT2 *cursor) {
    TexturedQuad q;
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 depth;
    u8 adv;
    u8 n;
    u16 ch;
    char *p;
    s32 ci;
    p = reinterpret_cast<char *>(candidate_buffer);
    if (p == NULL) {
        return;
    }
    depth = 0.0598f + context->depth;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    while (*p != 0) {
        ci = (p == reinterpret_cast<char *>(current_candidate)) ? 1 : 2;
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
            if (cursor->x + (f32)adv > context->inner_x + context->inner_w) {
                cursor->x = context->inner_x;
                cursor->y += 20.0f;
            }
            if ((s32)ch == 0x20) {
                cursor->x += (f32)(s32)adv;
            } else {
                q.x0 = cursor->x;
                q.y0 = cursor->y;
                set_glyph_quad_extents(adv, &q);
                context->transform_quad(&q);
                d.col[0].color = lbl_804CFA84[ci];
                d.col[1].color = d.col[0].color;
                d.col[2].color = d.col[0].color;
                d.col[3].color = d.col[0].color;
                pos[0].x = q.x0;
                pos[0].y = q.y0;
                pos[1].x = q.x1;
                pos[1].y = q.y0;
                pos[2].x = q.x1;
                pos[2].y = q.y1;
                pos[3].x = q.x0;
                pos[3].y = q.y1;
                draw_polygon_2d(&d, 4, 6, depth);
                cursor->x += (f32)(s32)adv;
            }
        }
    }
}

void TWindowKeyBoardBase::draw_composition_background(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count) {
    TexturedQuad q;
    NJS_POINT2 pos[4];
    NJS_POINT2COL d;
    NJS_COLOR col[4];
    f32 depth;
    u16 ch;
    u8 adv;

    depth = 0.0598f + box->depth;
    d.p = pos;
    d.col = col;
    d.tex = NULL;
    d.num = 4;
    d.col[0].color = lbl_804CFA84[2];
    d.col[1].color = d.col[0].color;
    d.col[2].color = d.col[0].color;
    d.col[3].color = d.col[0].color;
    while ((s32)*text != 0 && count-- != 0) {
        ch = *text++;
        adv = get_font_char_advance(map_char_to_font_code(ch));
        if (cursor->x + (f32)adv > box->inner_x + box->inner_w) {
            cursor->x = box->inner_x;
            cursor->y += 20.0f;
        }
        if ((s32)ch == 0x20) {
            cursor->x += (f32)(s32)adv;
        } else {
            q.x0 = cursor->x;
            q.y0 = cursor->y;
            set_glyph_quad_extents(adv, &q);
            box->transform_quad(&q);
            pos[0].x = q.x0;
            pos[0].y = q.y0;
            pos[1].x = q.x1;
            pos[1].y = q.y0;
            pos[2].x = q.x1;
            pos[2].y = q.y1;
            pos[3].x = q.x0;
            pos[3].y = q.y1;
            draw_polygon_2d(&d, 4, 6, depth);
            cursor->x += (f32)adv;
        }
    }
}

void TWindowKeyBoardBase::draw_wrapped_text(WindowDrawContext *context, NJS_POINT2 *cursor) {
    TexturedQuad q;
    f32 scale;
    u8 n;
    char *p;
    u16 ch;
    u8 adv;

    p = reinterpret_cast<char *>(candidate_buffer);
    if (p == NULL) {
        return;
    }
    scale = -1.0f / (0.0897f + context->depth);
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
            adv = calc_gauge_scale__20TWindowSubStatusDispFUsPvl(map_char_to_font_code(ch), &q, -1);
            if (cursor->x + (f32)adv > context->inner_x + context->inner_w) {
                cursor->x = context->inner_x;
                cursor->y += 20.0f;
            }
            if ((s32)ch == 0x20) {
                cursor->x += (f32)(s32)adv;
            } else {
                q.x0 = cursor->x;
                q.y0 = cursor->y;
                set_glyph_quad_extents(adv, &q);
                context->transform_quad(&q);
                draw_textured_quad_at_depth(&q, scale);
                cursor->x += (f32)(s32)adv;
            }
        }
    }
}

void TWindowKeyBoardBase::layout_wrapped_glyphs(WindowDrawContext *box, NJS_POINT2 *cursor, u16 *text, u32 count, s32 scaled) {
    TexturedQuad q;
    f32 depth;
    s32 code;
    u16 ch;
    u8 adv;

    depth = -1.0f / (0.0897f + box->depth);
    while ((s32)*text != 0 && count-- != 0) {
        ch = *text++;
        code = map_char_to_font_code(ch);
        if (scaled != 0) {
            adv = calc_gauge_scale__20TWindowSubStatusDispFUsPvl(code, &q, -1);
        } else {
            adv = get_font_char_advance(code);
        }
        if (cursor->x + (f32)adv > box->inner_x + box->inner_w) {
            cursor->x = box->inner_x;
            cursor->y += 20.0f;
        }
        if ((s32)ch == 0x20) {
            cursor->x += (f32)(s32)adv;
        } else {
            if (scaled != 0) {
                q.x0 = cursor->x;
                q.y0 = cursor->y;
                set_glyph_quad_extents(adv, &q);
                box->transform_quad(&q);
                draw_textured_quad_at_depth(&q, depth);
            }
            cursor->x += (f32)adv;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TWindowKeyBoardBase::draw_input_text(WindowDrawContext *ctx) {
    Stack_8025E6DC stack;
    s32 composing_cursor;
    s32 text_cursor;
    s32 composing_remaining;
    s32 text_remaining;
    s32 draw_caret;
    u16 flags;
    u16 flags_again;
    draw_caret = 1;
    if (!(this->request_flags & 2) || (ctx->open_tick >= 0)) {
        stack.cursor.x = ctx->inner_x;
        stack.cursor.y = ctx->inner_y;
        layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text.buffer, this->m_text.cursor, 0);
        flags = this->state_flags;
        if (flags & 2) {
            if (flags & 4) {
                this->draw_text_glyphs(ctx, &stack.cursor);
                draw_caret = 0;
            } else {
                draw_composition_background(ctx, &stack.cursor, this->m_text2.buffer, this->m_text2.length);
            }
        }
        TWindowSubStatusDisp::reset_gauge(0);
        stack.cursor.x = ctx->inner_x;
        stack.cursor.y = ctx->inner_y;
        layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text.buffer, this->m_text.cursor, 1);
        flags_again = this->state_flags;
        if (flags_again & 2) {
            if (flags_again & 4) {
                this->draw_wrapped_text(ctx, &stack.cursor);
            } else {
                layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text2.buffer, this->m_text2.cursor, 1);
                stack.caret.x = stack.cursor.x;
                stack.caret.y = stack.cursor.y;
                composing_cursor = this->m_text2.cursor;
                composing_remaining = this->m_text2.length - composing_cursor;
                if (composing_remaining != 0) {
                    layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text2.buffer + composing_cursor, composing_remaining, 1);
                }
            }
        } else {
            stack.caret.x = stack.cursor.x;
            stack.caret.y = stack.cursor.y;
        }
        text_cursor = this->m_text.cursor;
        text_remaining = this->m_text.length - text_cursor;
        if (text_remaining != 0) {
            layout_wrapped_glyphs(ctx, &stack.cursor, this->m_text.buffer + text_cursor, text_remaining, 1);
        }
        TWindowSubStatusDisp::end_render_forward();
        if ((draw_caret != 0) && !(this->window_flags & 2)) {
            fn_8025DE10(ctx, &stack.caret);
        }
    }
}
#pragma pop

}
extern "C" {
s32 ARAlloc(s32);
void aram_dma_setup(u32 aram_addr, s32 size, u32 owner, u32 priority, u32 timeout_ms);

void TWindowKeyBoardBase::render() {
    if ((sub_8025EB68() == 0) && ((sub_8025CB10() != 0) || (this->request_flags & 2))) {
        WindowDrawContext *context = draw_default_entry();
        if (this->request_flags & 2) {
            draw_window_frame(context);
        }
        draw_input_text(context);
    }
}

void TWindowKeyBoardBase::run_task() {
    update_window();
    update_fade();
}

TWindowKeyBoardBase::~TWindowKeyBoardBase() {
    mem_free(candidate_buffer);
}
TWindowKeyBoardBase::TWindowKeyBoardBase() : TWindowBase((u8 *)&TWindowKeyBoardBase__window_descriptor, (s16)(4), (u8 *)(get_window_layout_position(0xB7))) {
    s32 language;

    this->m_name = keyboard_base_type_name_pointer;
    language = current_language;
    this->init_keyboard_text_field(0, 0);
    m_text2.init(0, 0);
    active_text = &m_text;
    composition_flags = 0;
    request_flags = 0;
    active_input_mode = -1;
    candidate_buffer = 0;
    current_candidate = 0;
    last_candidate = 0;
    candidate_index = 0;
    candidate_count = 0;
    if (language == 0) {
        m_text2.init(0x24, 0);
        candidate_buffer = (u8 *)mem_alloc(0x194);
        candidate_bytes_remaining = 0x94;
    }
}

const char lbl_8044F098[10] = "Ask_n.dic";

void TLobby::load_ask_dictionary() {
    u8 *data;
    s32 size;
    s32 aligned;
    s32 aram;
    size = TGStream::get_resource_file_size((const char *)lbl_8044F098);
    aligned = (size + 0x1F) & ~0x1F;
    aram = ARAlloc(aligned);
    data = load_disc_file(lbl_8044F098);
    aram_transfer_sync(3, data, aram, aligned);
    safe_free(data);
    aram_dma_setup(aram, size, 3, 1, 0x2710);
    start_askdic();
}
}
