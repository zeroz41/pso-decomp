#ifndef PSO_SYSTEM_ARAMPOOL_H
#define PSO_SYSTEM_ARAMPOOL_H

#include "types.h"

// A range of auxiliary RAM handed out by an AramPool. Free ranges form a list sorted by address;
// a record whose size is 0 is unused (except record 0, the free-list head).
struct AramBlock {
    AramBlock *next;
    AramBlock *prev;
    u32 addr;
    u32 size;

    void clear();
};

LAYOUT_ASSERT(AramBlock_size, sizeof(AramBlock) == 0x10);

// Allocates ranges of auxiliary RAM, in multiples of 32 bytes, from one fixed region and copies data
// in and out of them by ARQ DMA. Block records come from a fixed table; record 0 heads the free list.
class AramPool {
public:
    AramPool(s32 aram_addr, s32 size, s32 max_blocks);
    ~AramPool();

    // from_aram == 0: copies size bytes from main memory src into the block dst (an AramBlock *).
    // Otherwise copies the block src (an AramBlock *) into main memory dst.
    void transfer(void *src, void *dst, u32 size, u32 from_aram);
    void merge_free_blocks();
    AramBlock *find_unused_block();
    void free(AramBlock *block);
    AramBlock *alloc(u32 size);

    AramBlock *m_blocks;
    u32 m_block_count;
    s32 m_size;
    u8 pad_0C[0x20];
    AramBlock *m_free_list;
};

LAYOUT_ASSERT(AramPool_size, sizeof(AramPool) == 0x30);

#endif
