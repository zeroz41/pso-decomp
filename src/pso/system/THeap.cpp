// Adapted from pso-gc-reference (mrb0nk500) for GPOE8P (MWCC 2.6)

#include "pso/THeap.h"
#include <string.h>

THeap *obj_heap;
THeap *alt_heap;

void xfree(void *ptr);

void *xmalloc(size_t size);

void THeap::heap_free(void *ptr) {
    #define heap_ptr &ptr_u8[-sizeof(heap_node)]
    #define ptr_heap ((heap_node *)heap_ptr)
    const u8 *ptr_u8 = (u8 *)ptr;
    if (ptr == NULL) {
        return;
    } else {
        heap_node *prev_node = heap_nodes;
        heap_node *node;

        for (; node = prev_node->next, node < ptr_heap; prev_node = node);

        if (((u8 *)&ptr_heap->next + ptr_heap->remaining_size) == (u8 *)&node->next) {
            ptr_heap->next = node->next;
            ptr_heap->remaining_size += node->remaining_size;
        } else {
            ptr_heap->next = node;
        }

        if (((u8 *)&prev_node->next + prev_node->remaining_size) == heap_ptr) {
            prev_node->next = ptr_heap->next;
            prev_node->remaining_size += ptr_heap->remaining_size;
        } else {
            prev_node->next = ptr_heap;
        }
    }
    #undef ptr_heap
    #undef heap_ptr
}

void *THeap::heap_zalloc(size_t size) {
    void *ptr = heap_alloc(size);
    if (ptr != NULL) {
        memset(ptr, 0, size);
    }
    return ptr;
}

void *THeap::heap_alloc(size_t size) {
    heap_node *prev_node = heap_nodes;
    heap_node *node;
    heap_node *tmp;

    u32 node_size = (sizeof(heap_node) - 1) + align + size;
    node_size &= -align;

    for (; node = prev_node->next, node != NULL; prev_node = node) {
        if (node->remaining_size >= node_size) {
            if (node_size == node->remaining_size) {
                prev_node->next = node->next;
            } else {
                const u8 *next_u8 = (u8 *)&node->next;
                tmp = (heap_node *)&next_u8[node_size];

                tmp->next = node->next;
                tmp->remaining_size = node->remaining_size - node_size;

                node->remaining_size = node_size;
                prev_node->next = tmp;
            }
            return node + 1;
        }
    }
    return NULL;
}

THeap::~THeap() {
    xfree(heap_nodes);
}

THeap::THeap(size_t size, int alignment) {
    mbr_0x0C = 0;
    mbr_0x10 = 0;
    align = alignment;
    heap_nodes = (heap_node *)xmalloc(size);
    if (heap_nodes != NULL) {
        heap_node *tmp_node;
        heap_node *next_tmp_node;

        memset(heap_nodes, 0, size);

        tmp_node = heap_nodes;
        next_tmp_node = &tmp_node[1];
        tmp_node->next = next_tmp_node;

        heap_nodes->remaining_size = 0;

        next_tmp_node->next = NULL;
        next_tmp_node->remaining_size = size - sizeof(heap_node);
    }
}

void THeap::operator delete(void *ptr) {
    xfree(ptr);
}

void *THeap::operator new(size_t size) {
    return xmalloc(size);
}
