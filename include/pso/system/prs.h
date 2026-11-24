#ifndef PSO_SYSTEM_PRS_H
#define PSO_SYSTEM_PRS_H

#include "types.h"

// PRS control-bit and source-byte reader, the base of PrsDecoder (class and member names inferred from behaviour).
class PrsReader {
public:
    PrsReader();
    ~PrsReader();

    u8 prs_read_control_bit();
    u8 prs_read_src_byte();

    u8 *dst_begin;
    u8 *dst_history;
    u8 bits_left;
    u8 control_bits;
    u8 pad_0A[2];
    u8 *src;
};

// PRS decoder with a 0x17FF-byte window at 0x80001800 (names inferred from behaviour).
class PrsDecoder : public PrsReader {
public:
    PrsDecoder();
    ~PrsDecoder();

    void prs_release_window();
    s32 prs_decompress(u8 *out, u8 *in, s32 user_data);
    u8 prs_read_byte_at(u32 offset);
    u8 *prs_next_output_byte();

    u8 *window;
    u8 *src_begin;
    u8 *dst;
    u32 window_len;
    s32 reserved;
    u32 flushed;
    s32 user_data;
    u32 error;
};

#endif
