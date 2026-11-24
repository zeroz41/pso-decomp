#include "types.h"
#include <dolphin/ar.h>
#define PSO_SDK_COMPACT_MATH
#include <dolphin/os/OSCache.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/system/AramPool.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"

volatile s32 aram_dma_pending;

void aram_sync_dma_done(uaddr request);

s32 TLobby::aram_dma_blocking(s32 owner, s32 aram, saddr dest, s32 length) {
    ARQRequest request;
    s32 len;
    len = (length + 0x1F) & ~0x1F;
    aram_dma_pending = 1;
    DCInvalidateRange((void *)dest, len);
    ARQPostRequest(&request, owner, 1, 1, aram, dest, len, aram_sync_dma_done);
    for (;;) {
        if (aram_dma_pending == 0) break;
    }
    DCInvalidateRange((void *)dest, len);
    return 1;
}

s32 TLobby::aram_read_sync(s32 owner, s32 aram, saddr dest, s32 length) {
    ARQRequest request;
    s32 len;
    len = (length + 0x1F) & ~0x1F;
    aram_dma_pending = 1;
    DCInvalidateRange((void *)dest, len);
    ARQPostRequest(&request, owner, 1, 1, aram, dest, len, aram_sync_dma_done);
    for (;;) {
        if (aram_dma_pending == 0) break;
        TLobby::run_frame();
    }
    DCInvalidateRange((void *)dest, len);
    return 1;
}
s32 TLobby::aram_transfer_sync(s32 owner, uaddr source, s32 aram, s32 length) {
    ARQRequest request;
    s32 len;
    if (aram == 0 && source == 0) {
        return 0;
    }
    len = (length + 0x1F) & ~0x1F;
    aram_dma_pending = 1;
    DCFlushRange((void *)source, len);
    ARQPostRequest(&request, owner, 0, 1, source, aram, len, aram_sync_dma_done);
    for (;;) {
        if (aram_dma_pending == 0) break;
        TLobby::run_frame();
    }
    return 1;
}

void AramPool::transfer(void *src, void *dst, u32 size, u32 from_aram) {
    if (from_aram == 0) {
        TLobby::aram_transfer_sync(0, (uaddr)src, ((AramBlock *)dst)->addr, size);
        return;
    }
    TLobby::aram_read_sync(0, ((AramBlock *)src)->addr, (saddr)dst, size);
}

void AramPool::merge_free_blocks() {
    AramBlock *cur;
    AramBlock *n;
    cur = m_free_list->next;
    while ((n = cur->next) != 0) {
        if (n->addr == cur->addr + cur->size) {
            cur->next = n->next;
            cur->size = cur->size + n->size;
            if (n->next != 0) {
                n->next->prev = cur;
            }
            n->clear();
        } else {
            cur = n;
        }
    }
}

AramBlock *AramPool::find_unused_block() {
    u32 i;
    if (m_blocks != 0) {
        for (i = 1; i < m_block_count; i++) {
            if (m_blocks[i].size == 0) {
                return &m_blocks[i];
            }
        }
    }
    return 0;
}

void AramPool::free(AramBlock *block) {
    AramBlock *prev;
    AramBlock *cur;
    for (prev = m_free_list; (cur = prev->next) != 0; prev = cur) {
        if (block->addr < cur->addr) {
            prev->next = block;
            block->next = cur;
            block->prev = prev;
            cur->prev = block;
            merge_free_blocks();
            return;
        }
    }
}

AramBlock *AramPool::alloc(u32 size) {
    u32 sz = (size + 0x1F) & ~0x1F;
    AramBlock *prev;
    AramBlock *cur;
    AramBlock *n;
    for (prev = m_free_list; (cur = prev->next) != 0; prev = cur) {
        if (cur->size >= sz) {
            if (cur->size == sz) {
                prev->next = cur->next;
                if (cur->next != 0) {
                    cur->next->prev = prev;
                }
                cur->next = 0;
                cur->prev = 0;
                return cur;
            }
            if (cur->size > sz) {
                n = find_unused_block();
                if (n != 0) {
                    n->next = 0;
                    n->prev = 0;
                    n->addr = cur->addr;
                    n->size = sz;
                    cur->addr += sz;
                    cur->size -= sz;
                    return n;
                }
            }
        }
    }
    return 0;
}

AramPool::~AramPool() {
    if (m_blocks != NULL) {
        xfree(m_blocks);
        m_blocks = NULL;
    }
}

AramPool::AramPool(s32 aram_addr, s32 size, s32 max_blocks) {
    s32 rounded;
    AramBlock *head;
    AramBlock *first;

    m_blocks = (AramBlock *)xcalloc(max_blocks, sizeof(AramBlock));
    if (m_blocks != NULL) {
        m_block_count = max_blocks;
        rounded = (size + 0x1F) & ~0x1F;
        m_size = rounded;
        head = m_blocks;
        m_free_list = head;
        first = head + 1;
        m_free_list->next = first;
        m_free_list->prev = 0;
        m_free_list->addr = 0;
        m_free_list->size = 0;
        first->next = 0;
        first->prev = m_blocks;
        first->addr = aram_addr;
        first->size = rounded;
    }
}

void aram_sync_dma_done(uaddr request) {
    aram_dma_pending = 0;
}

void AramBlock::clear() {
    prev = 0;
    next = 0;
    size = 0;
    addr = 0;
}
