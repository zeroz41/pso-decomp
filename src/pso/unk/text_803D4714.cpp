#include "types.h"
#include "pso/unk/TLobby.h"
struct Strm_803D4770;
struct StrmVt_803D4770 {
    void *pad[6];
    void (*read)(Strm_803D4770 *, s32, s32, void *);
    void (*release)(Strm_803D4770 *, s32, void *);
    void (*submit)(Strm_803D4770 *, s32, void *);
};

struct Strm_803D4770 { StrmVt_803D4770 *vt; };

struct Pair_803D4770 { u8 *a; u32 b; };

struct Obj_803D4770 {
    u8 pad0[8];
    u32 flags;
    u8 padC[4];
    s32 count;
    u8 pad14[0xC];
    u8 *base[2];
    Strm_803D4770 *src[2];
    Strm_803D4770 *dst[2];
    u8 pad38[8];
    u32 stid[2];
    u8 pad48[0xC];
    u32 f54;
};

struct Ch_803D4770 {
    u8 pad0[0x20];
    u8 *base;
    u8 pad24[4];
    Strm_803D4770 *src;
    u8 pad2c[4];
    Strm_803D4770 *dst;
    u8 pad34[0xC];
    u32 stid;
};

struct S_803D4714 { u8 f; u8 pad[0x7f]; };

extern "C" {
void sndStreamARAMUpdate(u32 stid, u32 off1, u32 len1, u32 off2, u32 len2);
void TLobby__sub_803D3130(void *, s32, void *, void *);
void *memcpy(void *, const void *, u32);
void *memset(void *, int, u32);
extern S_803D4714 gcrna_stream_pool[];
inline s32 flagA_803D4770(Obj_803D4770 *o) {
    if (o == NULL) {
        return -1;
    }
    return o->flags & 1;
}
inline s32 flagB_803D4770(Obj_803D4770 *o) {
    if (o == NULL) {
        return -1;
    }
    return (o->flags >> 1) & 1;
}

struct Obj_803D4770;
void TLobby::update_active_streams() {
    u32 i;
    for (i = 0; i < 0x10; i++) {
        if ((s32)gcrna_stream_pool[i].f == 1) {
            ((TLobby *)((Obj_803D4770 *)&gcrna_stream_pool[i]))->update_stream_buffers();
        }
    }
}

void TLobby::update_stream_buffers() {
    Obj_803D4770 *o = (Obj_803D4770 *)this;
    Pair_803D4770 f;
    Pair_803D4770 e;
    Pair_803D4770 d;
    Pair_803D4770 c;
    Pair_803D4770 a;
    Pair_803D4770 b;
    Ch_803D4770 *p;
    s32 i;
    s32 n;
    if (o == NULL) {
        return;
    }
    if (flagA_803D4770(o) == 1 && flagB_803D4770(o) == 0) {
        s32 i;
        Ch_803D4770 *p = (Ch_803D4770 *)o;
        for (i = 0; i < o->count; i++) {
            p->src->vt->read(p->src, 0, 0x2000, &a);
            p->dst->vt->read(p->dst, 1, a.b, &b);
            memcpy(a.a, b.a, b.b);
            TLobby__sub_803D3130(&b, b.b, &c, &d);
            p->dst->vt->submit(p->dst, 0, &c);
            p->dst->vt->release(p->dst, 1, &d);
            TLobby__sub_803D3130(&a, b.b, &c, &d);
            p->src->vt->submit(p->src, 1, &c);
            p->src->vt->release(p->src, 0, &d);
            sndStreamARAMUpdate(p->stid, (u32)(a.a - p->base) >> 1, b.b >> 1, 0, 0);
            p = (Ch_803D4770 *)((u8 *)p + 4);
        }
    }
    if (flagB_803D4770(o) == 1) {
        if (flagA_803D4770(o) == 1) {
            Ch_803D4770 *p = (Ch_803D4770 *)o;
            for (s32 i = 0; i < o->count; i++) {
                p->src->vt->read(p->src, 0, 0x2000, &e);
                p->dst->vt->read(p->dst, 1, e.b, &f);
                memcpy(e.a, f.a, f.b);
                p->dst->vt->submit(p->dst, 0, &f);
                n = f.b;
                p->dst->vt->read(p->dst, 1, e.b - n, &f);
                memcpy(e.a + n, f.a, f.b);
                p->dst->vt->submit(p->dst, 0, &f);
                n += f.b;
                memset(e.a + n, 0, e.b - n);
                p->src->vt->submit(p->src, 1, &e);
                sndStreamARAMUpdate(p->stid, (u32)(e.a - p->base) >> 1, e.b >> 1, 0, 0);
                p = (Ch_803D4770 *)((u8 *)p + 4);
            }
        } else if (o->f54 < 0x1000) {
            p = (Ch_803D4770 *)o;
            for (i = 0; i < o->count; i++) {
                p->src->vt->read(p->src, 0, 0x1000, &e);
                memset(e.a, 0, e.b);
                p->src->vt->submit(p->src, 1, &e);
                sndStreamARAMUpdate(p->stid, (u32)(e.a - p->base) >> 1, e.b >> 1, 0, 0);
                if (i == 0) {
                    o->f54 += e.b >> 1;
                }
                p = (Ch_803D4770 *)((u8 *)p + 4);
            }
        }
    }
}

}
