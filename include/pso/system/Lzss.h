#ifndef PSO_SYSTEM_LZSS_H
#define PSO_SYSTEM_LZSS_H

#include "types.h"

// The big-endian header in front of an LZSS-coded stream: the decoded and the coded size.
struct LzssHeader {
    u32 size;
    u32 coded_size;
};

// The LZSS coder: a 4 KB ring buffer with binary search trees over its 18-byte keys, and the
// input and output ranges it codes between.
class Lzss {
public:
    s32 decode(u8 *src, s32 size, void *dst);
    s32 encode(void *src, s32 size, u8 *dst);
    void delete_node(s32 p);
    void insert_node(s32 r);
    void init_tree();
    void put_byte(u8 c);
    int at_end();
    u8 get_byte();
    void set_range(u8 *src, s32 size, u8 *dst);

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

#endif
