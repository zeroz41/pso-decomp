#include "types.h"
#include <string.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/unk/TLobby.h"
struct AramStream;
struct AramStreamVtbl {
    void *pad[6];
    void (*read)(AramStream *, s32, s32, void *);
    void (*release)(AramStream *, s32, void *);
    void (*submit)(AramStream *, s32, void *);
};

struct AramStream { AramStreamVtbl *vt; };

// Buffer/length segment returned by AramStream read calls.
struct AramBufferSegment { u8 *data; u32 len; };

// ARAM ping-pong streaming set: count channels, each with a raw source and a
// converted destination stream around an ARAM buffer pair (base[]) and DSP
// stream ids (stid[]) fed to sndStreamARAMUpdate.
struct AramStreamSet {
    u8 pad0[8];
    u32 flags;
    u8 padC[4];
    s32 count;
    u8 pad14[0xC];
    u8 *base[2];
    AramStream *src[2];
    AramStream *dst[2];
    u8 pad38[8];
    u32 stid[2];
    u8 pad48[0xC];
    u32 f54;
};

// Per-channel window into an AramStreamSet (4-byte slot stride in the caller).
struct AramStreamChannel {
    u8 pad0[0x20];
    u8 *base;
    u8 pad24[4];
    AramStream *src;
    u8 pad2c[4];
    AramStream *dst;
    u8 pad34[0xC];
    u32 stid;
};

// One 0x80-byte slot of gcrna_stream_pool; active == 1 means the slot streams.
struct AramStreamPoolEntry { u8 active; u8 pad[0x7f]; };

extern "C" {
void sndStreamARAMUpdate(u32 stid, u32 off1, u32 len1, u32 off2, u32 len2);
extern AramStreamPoolEntry gcrna_stream_pool[];
inline s32 flagA_803D4770(AramStreamSet *o) {
    if (o == NULL) {
        return -1;
    }
    return o->flags & 1;
}
inline s32 flagB_803D4770(AramStreamSet *o) {
    if (o == NULL) {
        return -1;
    }
    return (o->flags >> 1) & 1;
}

struct AramStreamSet;
void TLobby::update_active_streams() {
    u32 i;
    for (i = 0; i < 0x10; i++) {
        if ((s32)gcrna_stream_pool[i].active == 1) {
            ((TLobby *)((AramStreamSet *)&gcrna_stream_pool[i]))->update_stream_buffers();
        }
    }
}

void TLobby::update_stream_buffers() {
    AramStreamSet *o = (AramStreamSet *)this;
    AramBufferSegment f;
    AramBufferSegment e;
    AramBufferSegment d;
    AramBufferSegment c;
    AramBufferSegment a;
    AramBufferSegment b;
    AramStreamChannel *p;
    s32 i;
    s32 n;
    if (o == NULL) {
        return;
    }
    if (flagA_803D4770(o) == 1 && flagB_803D4770(o) == 0) {
        s32 i;
        AramStreamChannel *p = (AramStreamChannel *)o;
        for (i = 0; i < o->count; i++) {
            p->src->vt->read(p->src, 0, 0x2000, &a);
            p->dst->vt->read(p->dst, 1, a.len, &b);
            memcpy(a.data, b.data, b.len);
            TLobby__sub_803D3130(&b, b.len, &c, &d);
            p->dst->vt->submit(p->dst, 0, &c);
            p->dst->vt->release(p->dst, 1, &d);
            TLobby__sub_803D3130(&a, b.len, &c, &d);
            p->src->vt->submit(p->src, 1, &c);
            p->src->vt->release(p->src, 0, &d);
            sndStreamARAMUpdate(p->stid, (u32)(a.data - p->base) >> 1, b.len >> 1, 0, 0);
            p = (AramStreamChannel *)((u8 *)p + 4);
        }
    }
    if (flagB_803D4770(o) == 1) {
        if (flagA_803D4770(o) == 1) {
            AramStreamChannel *p = (AramStreamChannel *)o;
            for (s32 i = 0; i < o->count; i++) {
                p->src->vt->read(p->src, 0, 0x2000, &e);
                p->dst->vt->read(p->dst, 1, e.len, &f);
                memcpy(e.data, f.data, f.len);
                p->dst->vt->submit(p->dst, 0, &f);
                n = f.len;
                p->dst->vt->read(p->dst, 1, e.len - n, &f);
                memcpy(e.data + n, f.data, f.len);
                p->dst->vt->submit(p->dst, 0, &f);
                n += f.len;
                memset(e.data + n, 0, e.len - n);
                p->src->vt->submit(p->src, 1, &e);
                sndStreamARAMUpdate(p->stid, (u32)(e.data - p->base) >> 1, e.len >> 1, 0, 0);
                p = (AramStreamChannel *)((u8 *)p + 4);
            }
        } else if (o->f54 < 0x1000) {
            p = (AramStreamChannel *)o;
            for (i = 0; i < o->count; i++) {
                p->src->vt->read(p->src, 0, 0x1000, &e);
                memset(e.data, 0, e.len);
                p->src->vt->submit(p->src, 1, &e);
                sndStreamARAMUpdate(p->stid, (u32)(e.data - p->base) >> 1, e.len >> 1, 0, 0);
                if (i == 0) {
                    o->f54 += e.len >> 1;
                }
                p = (AramStreamChannel *)((u8 *)p + 4);
            }
        }
    }
}

}
