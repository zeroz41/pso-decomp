#pragma dont_inline on
#include <dolphin/ar.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSInterrupt.h>
#include "musyx/runtime/musyx_internal.h"

extern "C" {

static ARAMTransferQueue aramQueueLo;
static ARAMTransferQueue aramQueueHi;
static ARAMStreamBuffer aramStreamBuffers[64];

u32 aramTop;
u32 aramWrite;
u32 aramStream;
ARAMUploadCallback aramUploadCallback;
u32 aramUploadChunkSize; // MusyX hw_aramdma.c name
ARAMStreamBuffer *aramUsedStreamBuffers;
ARAMStreamBuffer *aramFreeStreamBuffers;
ARAMStreamBuffer *aramIdleStreamBuffers;

void aramQueueCallback(uaddr ptr) {
    u32 i;
    ARQRequest *arq;
    ARAMTransferQueue *aramQueue;

    arq = (ARQRequest *)ptr;
    aramQueue = arq->priority == 1 ? &aramQueueHi : &aramQueueLo;
    for (i = 0; i < 16; ++i) {
        if (arq == &aramQueue->queue[i].arq && aramQueue->queue[i].callback) {
            aramQueue->queue[i].callback(aramQueue->queue[i].user);
        }
    }
    --aramQueue->valid;
}

void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, void *cb, void *arg) {
    ARAMTransferQueue *q;
    s32 lvl;
    q = (u32)dir != 0 ? &aramQueueHi : &aramQueueLo;
    while (1) {
        lvl = OSDisableInterrupts();
        if (q->valid < 16) {
            q->queue[q->write].arq.owner = 0x2A;
            q->queue[q->write].arq.type = 0;
            q->queue[q->write].arq.priority = (u32)dir != 0 ? 1 : 0;
            q->queue[q->write].arq.source = (uaddr)src;
            q->queue[q->write].arq.dest = dst;
            q->queue[q->write].arq.length = len;
            q->queue[q->write].arq.callback = aramQueueCallback;
            q->queue[q->write].callback = (ARAMTransferCallback)cb;
            q->queue[q->write].user = (u32)arg;
            ARQPostRequest(&q->queue[q->write].arq, q->queue[q->write].arq.owner,
                           q->queue[q->write].arq.type, q->queue[q->write].arq.priority,
                           q->queue[q->write].arq.source, q->queue[q->write].arq.dest,
                           q->queue[q->write].arq.length, q->queue[q->write].arq.callback);
            q->valid++;
            q->write = (q->write + 1) % 16;
            OSRestoreInterrupts(lvl);
            return;
        }
        OSRestoreInterrupts(lvl);
    }
}

void aramSyncTransferQueue(void) {
    while (aramQueueLo.valid != 0) {
    }
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void aramQueueInit(void) {
    aramQueueLo.write = aramQueueLo.valid = 0;
    aramQueueHi.write = aramQueueHi.valid = 0;
}

static inline void aramSyncTransferQueueInline(void) {
    while (aramQueueLo.valid != 0) {
    }
}

void aramInit(u32 length) {
    s16 *tmpMem;
    u32 i;
    u32 aramBase;

    aramBase = ARGetBaseAddress();

    tmpMem = (s16 *)salMalloc(sizeof(s16) * 640);

    for (i = 0; i < 640; ++i) {
        tmpMem[i] = 0;
    }

    DCFlushRange(tmpMem, sizeof(s16) * 640);
    aramQueueInit();
    aramUploadData((u8 *)tmpMem, aramBase, sizeof(s16) * 640, 0, 0, 0);
    aramSyncTransferQueueInline();
    salFree((saddr)tmpMem);
    aramTop = aramBase + length;
    if (aramTop > ARGetSize()) {
        aramTop = ARGetSize();
    }

    aramWrite = aramBase + sizeof(s16) * 640;
    aramUploadCallback = 0;
    InitStreamBuffers();
}
#pragma pop

u32 aramGetZeroBuffer(void) {
    return ARGetBaseAddress();
}

s32 aramStoreData(u8 *src, u32 size) {
    u32 chunk;
    s32 start;
    u8 *buf;
    u32 len;
    len = (size + 0x1F) & ~0x1F;
    start = aramWrite;
    if (aramUploadCallback == 0) {
        DCFlushRange(src, len);
        aramUploadData(src, aramWrite, len, 0, 0, 0);
        aramWrite += len;
        return start;
    } else {
        while (len != 0) {
            chunk = len >= aramUploadChunkSize ? aramUploadChunkSize : len;
            buf = aramUploadCallback(src, chunk);
            DCFlushRange(buf, chunk);
            aramUploadData(buf, aramWrite, chunk, 0, 0, 0);
            len -= chunk;
            src += chunk;
            aramWrite += chunk;
        }
    }
    return start;
}

void aramRemoveData(s32 addr, s32 size) {
    aramWrite -= (size + 0x1F) & 0xFFFFFFE0;
}

void InitStreamBuffers(void) {
    u32 i;
    aramUsedStreamBuffers = 0;
    aramFreeStreamBuffers = 0;
    aramIdleStreamBuffers = aramStreamBuffers;
    for (i = 1; i < 64; ++i) {
        aramStreamBuffers[i - 1].next = &aramStreamBuffers[i];
    }
    aramStreamBuffers[i - 1].next = 0;
    aramStream = aramTop;
}

u8 aramAllocateStreamBuffer(u32 len) {
    ARAMStreamBuffer *p;
    ARAMStreamBuffer *found;
    ARAMStreamBuffer *prev;
    u32 best;
    u32 size;
    p = aramFreeStreamBuffers;
    size = (len + 0x1F) & ~0x1F;
    found = NULL;
    prev = NULL;
    best = -1;
    while (p != NULL) {
        if (p->allocLength == size) {
            found = p;
            break;
        }
        if (p->allocLength > size && best > p->allocLength) {
            found = p;
            best = p->allocLength;
        }
        prev = p;
        p = p->next;
    }
    if (found == NULL) {
        p = aramIdleStreamBuffers;
        if (p != NULL && aramStream - size >= aramWrite) {
            found = p;
            aramIdleStreamBuffers = p->next;
            p->allocLength = size;
            p->length = size;
            aramStream -= size;
            p->aram = aramStream;
            p->next = aramUsedStreamBuffers;
            aramUsedStreamBuffers = p;
        }
    } else {
        if (prev != NULL) {
            prev->next = found->next;
        } else {
            aramFreeStreamBuffers = found->next;
        }
        found->length = size;
        found->next = aramUsedStreamBuffers;
        aramUsedStreamBuffers = found;
    }
    if (found == NULL) {
        return 0xFF;
    }
    return found - aramStreamBuffers;
}

u32 aramGetStreamBufferAddress(u8 i, u32 *out) {
    if (out != 0) {
        *out = aramStreamBuffers[i].length;
    }
    return aramStreamBuffers[i].aram;
}

void aramFreeStreamBuffer(u8 id) {
    ARAMStreamBuffer *fSb;
    ARAMStreamBuffer *sb;
    ARAMStreamBuffer *lastSb;
    ARAMStreamBuffer *nextSb;
    u32 minAddr;

    fSb = &aramStreamBuffers[id];
    lastSb = 0;
    sb = aramUsedStreamBuffers;

    while (sb != 0) {
        if (sb == fSb) {
            if (lastSb != 0) {
                lastSb->next = fSb->next;
            } else {
                aramUsedStreamBuffers = fSb->next;
            }
            break;
        } else {
            lastSb = sb;
            sb = sb->next;
        }
    }

    if (fSb->aram == aramStream) {
        fSb->next = aramIdleStreamBuffers;
        aramIdleStreamBuffers = fSb;
        minAddr = -1;
        sb = aramUsedStreamBuffers;
        while (sb != 0) {
            if (sb->aram <= minAddr) {
                minAddr = sb->aram;
            }
            sb = sb->next;
        }

        lastSb = 0;
        sb = aramFreeStreamBuffers;
        while (sb != 0) {
            nextSb = sb->next;
            if (sb->aram < minAddr) {
                if (lastSb != 0) {
                    lastSb->next = sb->next;
                } else {
                    aramFreeStreamBuffers = sb->next;
                }

                sb->next = aramIdleStreamBuffers;
                aramIdleStreamBuffers = sb;
            }
            sb = nextSb;
        }

        aramStream = minAddr != -1 ? minAddr : aramTop;
        return;
    }
    fSb->next = aramFreeStreamBuffers;
    aramFreeStreamBuffers = fSb;
}

}
