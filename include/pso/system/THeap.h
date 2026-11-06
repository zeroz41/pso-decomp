#ifndef PSO_SYSTEM_THEAP_H
#define PSO_SYSTEM_THEAP_H

/* THeap - Custom linked-list heap allocator.
 * Derived from pso-gc-reference decomp (mrb0nk500).
 * Adapted for GPOE8P (PSO EP I&II Plus, MWCC 2.6).
 *
 * THeap manages a contiguous memory region using a free-list
 * allocator with configurable alignment. Block headers (heap_node)
 * are stored inline before each allocated block.
 */

#include "pso/forward.h"
#include "types.h"

extern THeap *obj_heap;
extern THeap *alt_heap;

class THeap {
public:
    struct heap_node {
        heap_node *next;
        size_t remaining_size;
    };

    heap_node *heap_nodes;
    size_t mbr_0x04;
    size_t align;
    size_t mbr_0x0C;
    size_t mbr_0x10;

public:
    THeap(size_t size, int align);
    ~THeap();
    void *operator new(size_t size);
    void  operator delete(void *ptr);
    void *heap_alloc(size_t size);
    void *heap_zalloc(size_t size);
    void  heap_free(void *ptr);
};

#endif
