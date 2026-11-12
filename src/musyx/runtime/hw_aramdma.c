#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

static ARAMTransferQueue_803BDCD0 aramQueueLo;
static ARAMTransferQueue_803BDCD0 aramQueueHi;
static StreamBuffer_803BDCD0 aramStreamBuffers[64];

u32 lbl_805D74C8;
s32 lbl_805D74CC;
s32 lbl_805D74D0;
RecoveredCallback_fa840eeea008 lbl_805D74D4;
u32 lbl_805D74D8;
Rec_803BE1EC *lbl_805D74DC;
Rec_803BE1EC *lbl_805D74E0;
Rec_803BE1EC *lbl_805D74E4;
#define lbl_8056E158 (*(AramQueues_803BDCD0 *)&aramQueueLo)
#define lbl_8056E3DC (*(Obj_803BDCB8 *)&aramQueueHi)
#define lbl_8056E660 ((Rec_803BE1EC *)aramStreamBuffers)

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
    lbl_805D74C8 = aramBase + length;
    if (lbl_805D74C8 > ARGetSize()) {
        lbl_805D74C8 = ARGetSize();
    }

    *(u32 *)&lbl_805D74CC = aramBase + sizeof(s16) * 640;
    lbl_805D74D4 = 0;
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
    start = lbl_805D74CC;
    if (lbl_805D74D4 == 0) {
        DCFlushRange(src, len);
        aramUploadData((u8 *)(src), (u32)(lbl_805D74CC), (u32)(len), (s32)(0), (void *)(0), (void *)(0));
        lbl_805D74CC += len;
        return start;
    } else {
        while (len != 0) {
            chunk = len >= lbl_805D74D8 ? lbl_805D74D8 : len;
            buf = lbl_805D74D4(src, chunk);
            DCFlushRange(buf, chunk);
            aramUploadData((u8 *)(buf), (u32)(lbl_805D74CC), (u32)(chunk), (s32)(0), (void *)(0), (void *)(0));
            len -= chunk;
            src += chunk;
            lbl_805D74CC += chunk;
        }
    }
    return start;
}

void aramRemoveData(s32 arg0, s32 arg1) {
    lbl_805D74CC -= (arg1 + 0x1F) & 0xFFFFFFE0;
}

void InitStreamBuffers(void) {
    u32 i;
    *(StreamBuffer_803BDCD0 **)&lbl_805D74DC = 0;
    *(StreamBuffer_803BDCD0 **)&lbl_805D74E0 = 0;
    *(StreamBuffer_803BDCD0 **)&lbl_805D74E4 = aramStreamBuffers;
    for (i = 1; i < 64; ++i) {
        aramStreamBuffers[i - 1].next = &aramStreamBuffers[i];
    }
    aramStreamBuffers[i - 1].next = 0;
    *(u32 *)&lbl_805D74D0 = lbl_805D74C8;
}

void *aramAllocateStreamBuffer(u32 arg0) {
    Rec_803BE1EC *p;
    Rec_803BE1EC *found;
    Rec_803BE1EC *prev;
    u32 best;
    u32 size;
    p = lbl_805D74E0;
    size = (arg0 + 0x1F) & ~0x1F;
    found = NULL;
    prev = NULL;
    best = -1;
    while (p != NULL) {
        if (p->fc == size) {
            found = p;
            break;
        }
        if (p->fc > size && best > p->fc) {
            found = p;
            best = p->fc;
        }
        prev = p;
        p = (Rec_803BE1EC *)p->f0;
    }
    if (found == NULL) {
        p = lbl_805D74E4;
        if (p != NULL && (u32)(lbl_805D74D0 - size) >= (u32)lbl_805D74CC) {
            found = p;
            lbl_805D74E4 = (Rec_803BE1EC *)p->f0;
            p->fc = size;
            p->f8 = size;
            lbl_805D74D0 -= size;
            p->f4 = lbl_805D74D0;
            p->f0 = (u32)lbl_805D74DC;
            lbl_805D74DC = p;
        }
    } else {
        if (prev != NULL) {
            prev->f0 = found->f0;
        } else {
            lbl_805D74E0 = (Rec_803BE1EC *)found->f0;
        }
        found->f8 = size;
        found->f0 = (u32)lbl_805D74DC;
        lbl_805D74DC = found;
    }
    if (found == NULL) {
        return (void *)0xFF;
    }
    return (void *)(u8)(found - lbl_8056E660);
}

u32 aramGetStreamBufferAddress(u8 i, u32 *out) {
    if (out != 0) {
        *out = aramStreamBuffers[i].length;
    }
    return aramStreamBuffers[i].aram;
}

#define aramTop lbl_805D74C8
#define aramWrite (*(u32 *)&lbl_805D74CC)
#define aramStream (*(u32 *)&lbl_805D74D0)
#define aramUploadCallback lbl_805D74D4
#define aramUsedStreamBuffers (*(StreamBuffer_803BDCD0 **)&lbl_805D74DC)
#define aramFreeStreamBuffers (*(StreamBuffer_803BDCD0 **)&lbl_805D74E0)
#define aramIdleStreamBuffers (*(StreamBuffer_803BDCD0 **)&lbl_805D74E4)
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
#undef aramTop
#undef aramWrite
#undef aramStream
#undef aramUploadCallback
#undef aramUsedStreamBuffers
#undef aramFreeStreamBuffers
#undef aramIdleStreamBuffers

}
