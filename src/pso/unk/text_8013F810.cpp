#include "pso/map/FloorResourceCallbacks.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/unk/text_8013F810.h"
#include "pso/unk/text_803DF204.h"

#include "types.h"
#include "pso/system/debug_print.h"
#include "pso/misc/TLobby.h"

struct L_8013FF20 { u8 pad0[0x1012]; s16 a[0x1000]; u8 pad1[0x5016 - 0x3012]; s16 b[0x1101]; };

#define NIL_8013FCB0 0x1000
struct Lz_8013FCB0 {
    u8 pad[0x1012];
    s16 dad[0x1001];
    s16 lson[0x1001];
    s16 rson[0x1101];
};

struct Lz_8013FDC4 {
    u8 text_buf[0x1012];
    s16 dad[0x1001];
    s16 lson[0x1001];
    s16 rson[0x1101];
    s32 match_position;
    s32 match_length;
};

struct Lz_8013F99C {
    u8 text_buf[0x1012];
    s16 dad[0x1001];
    s16 lson[0x1001];
    s16 rson[0x1101];
    u32 match_position;
    s32 match_length;
    u8 *in;
    u8 *out;
    u8 *in_end;
    s32 codesize;
};

extern "C" {
void lzss_insert_ring_node(Lz_8013FDC4 *lz, s32 r);
void lzss_remove_ring_node(Lz_8013FCB0 *t, s32 p);
void bswap_32__FPUl(u32 *);
int sprintf(char *, const char *, ...);
s32 TLobby__sub_8013F810(TLobby *lz, u32 *data, s32 len, u8 *out);

#pragma push
#pragma opt_propagation off
#define EOF_8013F99C(c) (((s32 (*)(u8 *))lzss_input_exhausted)(c))
#define PUT_8013F99C(c, v) (((void (*)(u8 *, s32))TLobby__sub_8013FF64)(c, v))
#define GET_8013F99C(c) (((s32 (*)(u8 *))lzss_read_byte)(c))
#pragma push
#pragma opt_lifetimes off
s32 TLobby__sub_8013F810(TLobby *lz, u32 *data, s32 len, u8 *out) {
    s16 r = 0xFEE;
    u32 flags = 0;
    u8 c;
    u8 fc;
    u32 *hdr = data;
    s32 i;
    s32 j;
    u32 k;
    u8 c2;
    bswap_32__FPUl(hdr);
    bswap_32__FPUl(hdr + 1);
    lz->set_range((int)(data + 2), hdr[1], (int)out);
    for (i = 0; i < 0xFEE; i++) {
        ((Lz_8013F99C *)lz)->text_buf[i] = 0;
    }
    for (;;) {
        if (((flags >>= 1) & 0x100) == 0) {
            fc = lzss_read_byte((u8 *)lz);
            if (EOF_8013F99C((u8 *)lz) != 0) {
                break;
            }
            flags = fc | 0xFF00;
        }
        if (flags & 1) {
            c = lzss_read_byte((u8 *)lz);
            if (EOF_8013F99C((u8 *)lz) != 0) {
                break;
            }
            ((void (*)(u8 *, u8))TLobby__sub_8013FF64)((u8 *)lz, c);
            ((Lz_8013F99C *)lz)->text_buf[r++] = c;
            r &= 0xFFF;
        } else {
            i = lzss_read_byte((u8 *)lz);
            if (EOF_8013F99C((u8 *)lz) != 0) {
                break;
            }
            j = lzss_read_byte((u8 *)lz);
            if (EOF_8013F99C((u8 *)lz) != 0) {
                break;
            }
            i |= (j & 0xF0) << 4;
            for (k = 0; k <= (j & 0x0F) + 2; k++) {
                c2 = ((Lz_8013F99C *)lz)->text_buf[(i + k) & 0xFFF];
                ((void (*)(u8 *, u8))TLobby__sub_8013FF64)((u8 *)lz, c2);
                ((Lz_8013F99C *)lz)->text_buf[r++] = c2;
                r &= 0xFFF;
            }
        }
    }
    return ((Lz_8013F99C *)lz)->out - out;
}
#pragma pop

s32 TLobby::lz_compress_packet(void *src, s32 size, s32 *hdr) {
    u8 code_buf[17];
    char msg[256];
    s32 t0;
    s32 *out;
    s32 len;
    s32 code_buf_ptr;
    u8 mask;
    s32 s;
    s32 r;
    s32 c;
    s32 m;
    s32 i;
    s32 t1;
    out = hdr;
    t0 = TLobby__sub_803DF1CC();
    this->set_range((int)src, size, (s32)(hdr + 2));
    this->init_lookup_tables();
    code_buf[0] = 0;
    mask = code_buf_ptr = 1;
    ((Lz_8013F99C *)this)->codesize = 0;
    s = 0;
    r = 0xFEE;
    for (i = 0; i < 0xFEE; i++) {
        ((Lz_8013F99C *)this)->text_buf[i] = 0;
    }
    for (len = 0; len < 0x12; len++) {
        c = GET_8013F99C((u8 *)this);
        if (EOF_8013F99C((u8 *)this) != 0) {
            break;
        }
        ((Lz_8013F99C *)this)->text_buf[0xFEE + len] = c;
    }
    if (len == 0) {
        return ((Lz_8013F99C *)this)->codesize;
    }
    for (i = 1; i <= 0x12; i++) {
        lzss_insert_ring_node((Lz_8013FDC4 *)this, r - i);
    }
    lzss_insert_ring_node((Lz_8013FDC4 *)this, r);
    do {
        if (((Lz_8013F99C *)this)->match_length > len) {
            ((Lz_8013F99C *)this)->match_length = len;
        }
        if (((Lz_8013F99C *)this)->match_length < 3) {
            ((Lz_8013F99C *)this)->match_length = 1;
            code_buf[0] |= mask;
            code_buf[code_buf_ptr++] = ((Lz_8013F99C *)this)->text_buf[r];
        } else {
            code_buf[code_buf_ptr++] = ((Lz_8013F99C *)this)->match_position;
            code_buf[code_buf_ptr++] = ((((Lz_8013F99C *)this)->match_position >> 4) & 0xF0) | (((Lz_8013F99C *)this)->match_length - 3);
        }
        if ((mask <<= 1) == 0) {
            for (i = 0; i < code_buf_ptr; i++) {
                PUT_8013F99C((u8 *)((Lz_8013F99C *)this), code_buf[i]);
            }
            ((Lz_8013F99C *)this)->codesize += code_buf_ptr;
            code_buf[0] = 0;
            code_buf_ptr = mask = 1;
        }
        i = ((Lz_8013F99C *)this)->match_length;
        for (m = 0; m < i; m++) {
            c = GET_8013F99C((u8 *)((Lz_8013F99C *)this));
            if (EOF_8013F99C((u8 *)((Lz_8013F99C *)this)) != 0) {
                break;
            }
            lzss_remove_ring_node((Lz_8013FCB0 *)((Lz_8013F99C *)this), s);
            ((Lz_8013F99C *)this)->text_buf[s] = c;
            if (s < 0x11) {
                ((Lz_8013F99C *)this)->text_buf[s + 0x1000] = c;
            }
            s = (s + 1) & 0xFFF;
            r = (r + 1) & 0xFFF;
            lzss_insert_ring_node((Lz_8013FDC4 *)((Lz_8013F99C *)this), r);
        }
        while (m++ < i) {
            lzss_remove_ring_node((Lz_8013FCB0 *)((Lz_8013F99C *)this), s);
            s = (s + 1) & 0xFFF;
            r = (r + 1) & 0xFFF;
            if (--len) {
                lzss_insert_ring_node((Lz_8013FDC4 *)((Lz_8013F99C *)this), r);
            }
        }
    } while (len > 0);
    if (code_buf_ptr > 1) {
        s32 k;
        for (k = 0; k < code_buf_ptr; k++) {
            PUT_8013F99C((u8 *)((Lz_8013F99C *)this), code_buf[k]);
        }
        ((Lz_8013F99C *)this)->codesize += code_buf_ptr;
    }
    out[0] = size;
    out[1] = ((Lz_8013F99C *)this)->codesize;
    bswap_32__FPUl((u32 *)out);
    bswap_32__FPUl((u32 *)(out + 1));
    ((Lz_8013F99C *)this)->codesize += 8;
    t1 = TLobby__sub_803DF1CC();
    sprintf(msg, "compless size  %d %d time %d", size, ((Lz_8013F99C *)this)->codesize, fn_803DF204(TLobby::calc_delta(t0, t1)));
    ::debug_print(msg);
    return ((Lz_8013F99C *)this)->codesize;
}
#pragma pop

void lzss_remove_ring_node(Lz_8013FCB0 *t, s32 p) {
    s32 q;
    if (t->dad[p] == NIL_8013FCB0) {
        return;
    }
    if (t->rson[p] == NIL_8013FCB0) {
        q = t->lson[p];
    } else if (t->lson[p] == NIL_8013FCB0) {
        q = t->rson[p];
    } else {
        q = t->lson[p];
        if (t->rson[q] != NIL_8013FCB0) {
            do {
                q = t->rson[q];
            } while (t->rson[q] != NIL_8013FCB0);
            t->rson[t->dad[q]] = t->lson[q];
            t->dad[t->lson[q]] = t->dad[q];
            t->lson[q] = t->lson[p];
            t->dad[t->lson[p]] = q;
        }
        t->rson[q] = t->rson[p];
        t->dad[t->rson[p]] = q;
    }
    t->dad[q] = t->dad[p];
    if (t->rson[t->dad[p]] == p) {
        t->rson[t->dad[p]] = q;
    } else {
        t->lson[t->dad[p]] = q;
    }
    t->dad[p] = NIL_8013FCB0;
}

void lzss_insert_ring_node(Lz_8013FDC4 *lz, s32 r) {
    u8 *key;
    s32 i;
    s32 p;
    s32 cmp;

    cmp = 1;
    key = &lz->text_buf[r];
    p = 0x1001 + key[0];
    lz->rson[r] = lz->lson[r] = 0x1000;
    lz->match_length = 0;
    for (;;) {
        if (cmp >= 0) {
            if (lz->rson[p] != 0x1000) {
                p = lz->rson[p];
            } else {
                lz->rson[p] = r;
                lz->dad[r] = p;
                return;
            }
        } else {
            if (lz->lson[p] != 0x1000) {
                p = lz->lson[p];
            } else {
                lz->lson[p] = r;
                lz->dad[r] = p;
                return;
            }
        }
        for (i = 1; i < 0x12; i++) {
            if ((cmp = key[i] - lz->text_buf[p + i]) != 0) {
                break;
            }
        }
        if (i > lz->match_length) {
            lz->match_position = p;
            if ((lz->match_length = i) >= 0x12) {
                break;
            }
        }
    }
    lz->dad[r] = lz->dad[p];
    lz->lson[r] = lz->lson[p];
    lz->rson[r] = lz->rson[p];
    lz->dad[lz->lson[p]] = r;
    lz->dad[lz->rson[p]] = r;
    if (lz->rson[lz->dad[p]] == p) {
        lz->rson[lz->dad[p]] = r;
    } else {
        lz->lson[lz->dad[p]] = r;
    }
    lz->dad[p] = 0x1000;
}

void TLobby::init_lookup_tables() {
    L_8013FF20 *arg0 = (L_8013FF20 *)this;
    s32 i;
    for (i = 0x1001; i < 0x1101; i++) {
        arg0->b[i] = 0x1000;
    }
    for (i = 0; i < 0x1000; i++) {
        arg0->a[i] = 0x1000;
    }
}

void TLobby__sub_8013FF64(u8 *arg0, s8 arg1) {
    s8 *temp_r5;
    temp_r5 = *(s8 **)((s8 *)arg0 + 0x7224);
    *(s8 **)((s8 *)arg0 + 0x7224) = (temp_r5 + 1);
    *temp_r5 = arg1;
}
}

u8 lzss_input_exhausted(u8 *arg0) {
    return (u8) ((u32) *(u32 *)((s8 *)arg0 + 0x7220) > (u32) *(u32 *)((s8 *)arg0 + 0x7228));
}

u8 lzss_read_byte(u8 *arg0) {
    u8 *temp_r4;
    temp_r4 = *(u8 **)((s8 *)arg0 + 0x7220);
    *(u8 **)((s8 *)arg0 + 0x7220) = (temp_r4 + 1);
    return *temp_r4;
}
