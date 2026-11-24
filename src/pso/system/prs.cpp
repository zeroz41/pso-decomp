#include "types.h"
#include <string.h>
#include "pso/system/memory.h"
#include "pso/system/prs.h"

u8 PrsReader::prs_read_control_bit() {
    s32 bit;
    if (--bits_left == 0) {
        control_bits = prs_read_src_byte();
        bits_left = 8;
    }
    bit = control_bits;
    control_bits = bit >> 1;
    return bit & 1;
}

PrsReader::~PrsReader() {}

PrsReader::PrsReader() {
    src = NULL;
    dst_begin = NULL;
    dst_history = NULL;
    bits_left = 1;
}

u8 PrsReader::prs_read_src_byte() {
    return *src++;
}

void PrsDecoder::prs_release_window() {
    window = NULL;
}

#pragma push
#pragma opt_lifetimes off
s32 PrsDecoder::prs_decompress(u8 *out, u8 *in, s32 user_data) {
    s32 n;
    s32 off;
    u32 size;
    u8 *p;
    u32 hi;
    u8 a;
    n = 0;
    src = src_begin = in;
    dst = out;
    dst_begin = out;
    dst_history = out;
    this->user_data = user_data;
    window = (u8 *)0x80001800;
    for (;;) {
        if (error != 0) break;
        while (prs_read_control_bit()) {
            p = prs_next_output_byte();
            *p = prs_read_src_byte();
            n++;
        }
        if (prs_read_control_bit()) {
            size = prs_read_src_byte();
            hi = prs_read_src_byte();
            if ((hi | size) == 0) break;
            off = (s32)(hi << 5) + (s32)(size >> 3) - 0x2000;
            size &= 7;
            if (size != 0) {
                size += 2;
            } else {
                size = prs_read_src_byte() + 1;
            }
        } else {
            a = prs_read_control_bit();
            size = (a << 1) + prs_read_control_bit() + 2;
            off = prs_read_src_byte() - 0x100;
        }
        off += n;
        while (size-- != 0) {
            p = prs_next_output_byte();
            *p = prs_read_byte_at(off);
            n++;
            off++;
        }
    }
    if (error != 0) {
        prs_release_window();
        return -1;
    }
    size = n;
    if (window_len != 0) {
        memmove(dst + (n - window_len), window, window_len);
        window_len = 0;
    }
    prs_release_window();
    return size;
}
#pragma pop

u8 PrsDecoder::prs_read_byte_at(u32 offset) {
    u32 window_offset;
    if (flushed > offset) {
        return dst_history[offset];
    }
    window_offset = offset - flushed;
    if (window_offset >= window_len) {
        error = 1;
        return 0;
    }
    return window[window_offset];
}

u8 *PrsDecoder::prs_next_output_byte() {
    if (window_len >= 0x17FF) {
        window_len = 0;
        memmove(dst + flushed, window, 0x17FF);
        flushed += 0x17FF;
    }
    u8 *p = window + window_len;
    window_len++;
    return p;
}

PrsDecoder::~PrsDecoder() {}

PrsDecoder::PrsDecoder() {
    window = NULL;
    src_begin = NULL;
    dst = NULL;
    window_len = 0;
    reserved = 0;
    flushed = 0;
    user_data = 0;
    error = 0;
}
