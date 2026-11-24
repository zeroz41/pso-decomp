#ifndef PSO_SYSTEM_PRS_H
#define PSO_SYSTEM_PRS_H

#include "types.h"

// PRS control-bit and byte reader (inferred role; the base of the PRS decoder).
class TUnk_8036F574 {
public:
    TUnk_8036F574();
    ~TUnk_8036F574();

    u8 prs_read_control_bit();
    u8 sub_8036F590();

    u8 *dst_begin;
    u8 *dst_history;
    u8 bits_left;
    u8 control_bits;
    u8 pad_0A[2];
    u8 *src;
};

// PRS decoder with a 0x17FF-byte window at 0x80001800 (inferred role).
class TUnk_8036F868 : public TUnk_8036F574 {
public:
    TUnk_8036F868();
    ~TUnk_8036F868();

    void sub_8036F5A4();
    s32 prs_decompress(u8 *out, u8 *in, s32 arg3);
    u8 prs_read_byte_at(u32 offset);
    u8 *prs_next_output_byte();

    u8 *window;
    u8 *src_begin;
    u8 *dst;
    u32 window_len;
    s32 pad_20;
    u32 flushed;
    s32 pad_28;
    u32 error;
};

#endif
