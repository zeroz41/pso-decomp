#include <stdio.h>
#include "pso/system/Lzss.h"

#include "types.h"
#include "pso/system/debug_print.h"
#include "pso/system/byteswap.h"
#include "pso/ui/window/ScreenQuadDraw.h"

#define N 0x1000
#define F 0x12
#define THRESHOLD 2
#define NIL N

#pragma push
#pragma opt_propagation off
#pragma push
#pragma opt_lifetimes off
s32 Lzss::decode(u8 *src, s32 size, void *dst) {
    s16 r = N - F;
    u32 flags = 0;
    u8 c;
    u8 fc;
    LzssHeader *header = (LzssHeader *)src;
    s32 i;
    s32 j;
    u32 k;
    u8 c2;
    bswap_32(&header->size);
    bswap_32(&header->coded_size);
    set_range(src + sizeof(LzssHeader), header->coded_size, (u8 *)dst);
    for (i = 0; i < N - F; i++) {
        text_buf[i] = 0;
    }
    for (;;) {
        if (((flags >>= 1) & 0x100) == 0) {
            fc = get_byte();
            if (at_end() != 0) {
                break;
            }
            flags = fc | 0xFF00;
        }
        if (flags & 1) {
            c = get_byte();
            if (at_end() != 0) {
                break;
            }
            put_byte(c);
            text_buf[r++] = c;
            r &= N - 1;
        } else {
            i = get_byte();
            if (at_end() != 0) {
                break;
            }
            j = get_byte();
            if (at_end() != 0) {
                break;
            }
            i |= (j & 0xF0) << 4;
            for (k = 0; k <= (j & 0x0F) + THRESHOLD; k++) {
                c2 = text_buf[(i + k) & (N - 1)];
                put_byte(c2);
                text_buf[r++] = c2;
                r &= N - 1;
            }
        }
    }
    return out - (u8 *)dst;
}
#pragma pop

s32 Lzss::encode(void *src, s32 size, u8 *dst) {
    u8 code_buf[17];
    char msg[256];
    s32 t0;
    LzssHeader *header;
    s32 len;
    s32 code_buf_ptr;
    u8 mask;
    s32 s;
    s32 r;
    u8 c;
    s32 m;
    s32 i;
    s32 t1;
    header = (LzssHeader *)dst;
    t0 = get_coarse_time();
    set_range((u8 *)src, size, dst + sizeof(LzssHeader));
    init_tree();
    code_buf[0] = 0;
    mask = code_buf_ptr = 1;
    codesize = 0;
    s = 0;
    r = N - F;
    for (i = 0; i < N - F; i++) {
        text_buf[i] = 0;
    }
    for (len = 0; len < F; len++) {
        c = get_byte();
        if (at_end() != 0) {
            break;
        }
        text_buf[N - F + len] = c;
    }
    if (len == 0) {
        return codesize;
    }
    for (i = 1; i <= F; i++) {
        insert_node(r - i);
    }
    insert_node(r);
    do {
        if (match_length > len) {
            match_length = len;
        }
        if (match_length < THRESHOLD + 1) {
            match_length = 1;
            code_buf[0] |= mask;
            code_buf[code_buf_ptr++] = text_buf[r];
        } else {
            code_buf[code_buf_ptr++] = match_position;
            code_buf[code_buf_ptr++] = ((match_position >> 4) & 0xF0) | (match_length - (THRESHOLD + 1));
        }
        if ((mask <<= 1) == 0) {
            for (i = 0; i < code_buf_ptr; i++) {
                put_byte(code_buf[i]);
            }
            codesize += code_buf_ptr;
            code_buf[0] = 0;
            code_buf_ptr = mask = 1;
        }
        i = match_length;
        for (m = 0; m < i; m++) {
            c = get_byte();
            if (at_end() != 0) {
                break;
            }
            delete_node(s);
            text_buf[s] = c;
            if (s < F - 1) {
                text_buf[s + N] = c;
            }
            s = (s + 1) & (N - 1);
            r = (r + 1) & (N - 1);
            insert_node(r);
        }
        while (m++ < i) {
            delete_node(s);
            s = (s + 1) & (N - 1);
            r = (r + 1) & (N - 1);
            if (--len) {
                insert_node(r);
            }
        }
    } while (len > 0);
    if (code_buf_ptr > 1) {
        s32 k;
        for (k = 0; k < code_buf_ptr; k++) {
            put_byte(code_buf[k]);
        }
        codesize += code_buf_ptr;
    }
    header->size = size;
    header->coded_size = codesize;
    bswap_32(&header->size);
    bswap_32(&header->coded_size);
    codesize += 8;
    t1 = get_coarse_time();
    sprintf(msg, "compless size  %d %d time %d", size, codesize, coarse_time_to_usec(calc_delta(t0, t1)));
    ::debug_print(msg);
    return codesize;
}
#pragma pop

void Lzss::delete_node(s32 p) {
    s32 q;
    if (dad[p] == NIL) {
        return;
    }
    if (rson[p] == NIL) {
        q = lson[p];
    } else if (lson[p] == NIL) {
        q = rson[p];
    } else {
        q = lson[p];
        if (rson[q] != NIL) {
            do {
                q = rson[q];
            } while (rson[q] != NIL);
            rson[dad[q]] = lson[q];
            dad[lson[q]] = dad[q];
            lson[q] = lson[p];
            dad[lson[p]] = q;
        }
        rson[q] = rson[p];
        dad[rson[p]] = q;
    }
    dad[q] = dad[p];
    if (rson[dad[p]] == p) {
        rson[dad[p]] = q;
    } else {
        lson[dad[p]] = q;
    }
    dad[p] = NIL;
}

void Lzss::insert_node(s32 r) {
    u8 *key;
    s32 i;
    s32 p;
    s32 cmp;

    cmp = 1;
    key = &text_buf[r];
    p = N + 1 + key[0];
    rson[r] = lson[r] = NIL;
    match_length = 0;
    for (;;) {
        if (cmp >= 0) {
            if (rson[p] != NIL) {
                p = rson[p];
            } else {
                rson[p] = r;
                dad[r] = p;
                return;
            }
        } else {
            if (lson[p] != NIL) {
                p = lson[p];
            } else {
                lson[p] = r;
                dad[r] = p;
                return;
            }
        }
        for (i = 1; i < F; i++) {
            if ((cmp = key[i] - text_buf[p + i]) != 0) {
                break;
            }
        }
        if (i > match_length) {
            match_position = p;
            if ((match_length = i) >= F) {
                break;
            }
        }
    }
    dad[r] = dad[p];
    lson[r] = lson[p];
    rson[r] = rson[p];
    dad[lson[p]] = r;
    dad[rson[p]] = r;
    if (rson[dad[p]] == p) {
        rson[dad[p]] = r;
    } else {
        lson[dad[p]] = r;
    }
    dad[p] = NIL;
}

void Lzss::init_tree() {
    s32 i;
    for (i = N + 1; i <= N + 256; i++) {
        rson[i] = NIL;
    }
    for (i = 0; i < N; i++) {
        dad[i] = NIL;
    }
}

void Lzss::put_byte(u8 c) {
    *out++ = c;
}

int Lzss::at_end() {
    return in > in_end;
}

u8 Lzss::get_byte() {
    return *in++;
}

void Lzss::set_range(u8 *src, s32 size, u8 *dst) {
    in = src;
    out = dst;
    in_end = src + size;
}
