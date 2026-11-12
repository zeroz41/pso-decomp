#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

static ARAMTransferQueue_803BDCD0 aramQueueLo;
static ARAMTransferQueue_803BDCD0 aramQueueHi;
static StreamBuffer_803BDCD0 aramStreamBuffers[64];

u32 aramTop;
u32 aramWrite;
u32 aramStream;
RecoveredCallback_fa840eeea008 aramUploadCallback;
u32 aramUploadChunkSize; // MusyX hw_aramdma.c name
StreamBuffer_803BDCD0 *aramUsedStreamBuffers;
StreamBuffer_803BDCD0 *aramFreeStreamBuffers;
StreamBuffer_803BDCD0 *aramIdleStreamBuffers;
#define lbl_8056E158 (*(AramQueues_803BDCD0 *)&aramQueueLo)
#define lbl_8056E3DC (*(Obj_803BDCB8 *)&aramQueueHi)

void aramQueueCallback(u32 ptr) {
    u32 i;
    ARQRequest_803BDCD0 *arq;
    ARAMTransferQueue_803BDCD0 *aramQueue;

    arq = (ARQRequest_803BDCD0 *)ptr;
    aramQueue = arq->priority == 1 ? &aramQueueHi : &aramQueueLo;
    for (i = 0; i < 16; ++i) {
        if (arq == &aramQueue->queue[i].arq && aramQueue->queue[i].callback) {
            aramQueue->queue[i].callback(aramQueue->queue[i].user);
        }
    }
    --aramQueue->valid;
}

void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, void *cb, void *arg) {
    Q_803BDAE4 *q;
    s32 lvl;
    q = (u32)dir != 0 ? (Q_803BDAE4 *)&lbl_8056E3DC : (Q_803BDAE4 *)&lbl_8056E158;
    while (1) {
        lvl = OSDisableInterrupts();
        if (q->count < 16) {
            q->reqs[q->wp].owner = 0x2A;
            q->reqs[q->wp].type = 0;
            q->reqs[q->wp].prio = (u32)dir != 0 ? 1 : 0;
            q->reqs[q->wp].src = src;
            q->reqs[q->wp].dst = dst;
            q->reqs[q->wp].len = len;
            q->reqs[q->wp].cb = (void *)aramQueueCallback;
            q->reqs[q->wp].f20 = cb;
            q->reqs[q->wp].f24 = arg;
            ARQPostRequest(&q->reqs[q->wp], q->reqs[q->wp].owner, q->reqs[q->wp].type, q->reqs[q->wp].prio,
                           q->reqs[q->wp].src, q->reqs[q->wp].dst, q->reqs[q->wp].len, q->reqs[q->wp].cb);
            q->count++;
            q->wp = (q->wp + 1) % 16;
            OSRestoreInterrupts(lvl);
            return;
        }
        OSRestoreInterrupts(lvl);
    }
}

void aramSyncTransferQueue(void) {
    while (lbl_8056E158.lo.valid != 0) {
    }
}

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)
static inline void aramQueueInit_803BDCD0(void) {
    aramQueueLo.write = aramQueueLo.valid = 0;
    aramQueueHi.write = aramQueueHi.valid = 0;
}

static inline void aramSyncTransferQueue_803BDCD0(void) {
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
    aramQueueInit_803BDCD0();
    aramUploadData((u8 *)tmpMem, aramBase, sizeof(s16) * 640, 0, 0, 0);
    aramSyncTransferQueue_803BDCD0();
    salFree((s32)tmpMem);
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
        aramUploadData((u8 *)(src), (u32)(aramWrite), (u32)(len), (s32)(0), (void *)(0), (void *)(0));
        aramWrite += len;
        return start;
    } else {
        while (len != 0) {
            chunk = len >= aramUploadChunkSize ? aramUploadChunkSize : len;
            buf = aramUploadCallback(src, chunk);
            DCFlushRange(buf, chunk);
            aramUploadData((u8 *)(buf), (u32)(aramWrite), (u32)(chunk), (s32)(0), (void *)(0), (void *)(0));
            len -= chunk;
            src += chunk;
            aramWrite += chunk;
        }
    }
    return start;
}

void aramRemoveData(s32 arg0, s32 arg1) {
    aramWrite -= (arg1 + 0x1F) & 0xFFFFFFE0;
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

void *aramAllocateStreamBuffer(u32 arg0) {
    StreamBuffer_803BDCD0 *p;
    StreamBuffer_803BDCD0 *found;
    StreamBuffer_803BDCD0 *prev;
    u32 best;
    u32 size;
    p = aramFreeStreamBuffers;
    size = (arg0 + 0x1F) & ~0x1F;
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
        return (void *)0xFF;
    }
    return (void *)(u8)(found - aramStreamBuffers);
}

u32 aramGetStreamBufferAddress(u8 i, u32 *out) {
    if (out != 0) {
        *out = aramStreamBuffers[i].length;
    }
    return aramStreamBuffers[i].aram;
}

void aramFreeStreamBuffer(u8 id) {
    StreamBuffer_803BDCD0 *fSb;
    StreamBuffer_803BDCD0 *sb;
    StreamBuffer_803BDCD0 *lastSb;
    StreamBuffer_803BDCD0 *nextSb;
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
