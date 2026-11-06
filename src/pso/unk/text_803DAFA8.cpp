#include "types.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803DAF30.h"
#include "pso/unk/text_803DAFA8.h"
#include "pso/unk/TLobby.h"
struct Obj_803DB20C { u8 pad[0x1c]; void *p; };

struct Tex_803DB15C { u32 fmt; u32 pad4; u32 pad8; u32 w; u32 h; u32 sz; u32 flags; };

struct Buf_803DB1B4 { u8 pad[0x14]; u32 size; u32 pad18; void *mem; };

struct Hdr_803DAFA8 {
    s32 magic;
    s32 size;
    u16 f8;
    s16 fa;
    s16 fc;
    s16 fe;
    u8 data[1];
};

struct Out_803DAFA8 {
    void *buf;
    u16 f4;
    s16 f6;
    s16 f8;
    s16 fa;
};

extern "C" {
extern void *locked_cache_heap_handle;
void OSFreeToHeap(void *heap, void *p);
s32 fn_803DB20C(Obj_803DB20C *o);
void GXInitTlutObj(void *, void *, s32, s32, s32);
void GXLoadTlut(void *, s32);
s32 GXGetTexBufferSize(u16, u16, u32, u8, u8);
void fn_803DB15C(Tex_803DB15C *arg0);
void *OSAllocFromHeap(void *, u32);
s32 alloc_buffer_from_heap(Buf_803DB1B4 *arg0);
s32 fn_803DAFA8(struct Hdr_803DAFA8 *arg0, struct Out_803DAFA8 *arg1);
s32 init_ginja_texture_header(Tex_803DB15C *arg0, u32 arg1, u32 arg2, u32 arg3);

s32 fn_803DAFA8(struct Hdr_803DAFA8 *arg0, struct Out_803DAFA8 *arg1) {
    s32 sp8;
    TObjPlayer__sub_803DA7E0();
    sp8 = arg0->magic;
    fn_803DAF30((u32 *)&sp8);
    switch (sp8) {
    case 0x4C505647:
        sp8 = arg0->size;
        fn_803DAF30((u32 *)&sp8);
        ((TLobby *)(arg1->buf))->move_data(arg0->data, sp8 - 8);
        arg1->f6 = arg0->fa;
        arg1->f8 = arg0->fc;
        arg1->fa = arg0->fe;
        arg1->f4 = arg0->f8;
        break;
    default:
        return -1;
    }
    return 1;
}

void init_and_load_tlut(s32 arg0, s32 arg1, u16 arg2, void *arg3) {
    u32 sp8[3];
    GXInitTlutObj(sp8, arg3, arg1, arg2, arg1);
    GXLoadTlut(sp8, arg0);
}

s32 init_ginja_texture_header(Tex_803DB15C *arg0, u32 arg1, u32 arg2, u32 arg3) {
    s32 ret = 0;
    u32 flags = 0;
    arg0->fmt = (u8)arg3;
    arg0->w = arg1;
    arg0->h = arg2;
    if ((arg3 & 0x100) && arg1 != arg2) {
        ret = 4;
    }
    arg0->flags = 0;
    if (arg3 & 0x100) {
        flags |= 0x80000000;
    }
    if (arg3 & 0x200) {
        flags |= 0x8000;
    }
    if (arg3 & 0x800) {
        flags |= 0x40000000;
    }
    arg0->flags |= flags;
    arg0->sz = ((s32 (*)(Tex_803DB15C *))fn_803DB15C)(arg0);
    return ret;
}

void fn_803DB15C(Tex_803DB15C *arg0) {
    u8 mip;
    if (arg0->flags & 0x80000000) {
        mip = 1;
    } else {
        mip = 0;
    }
    GXGetTexBufferSize(arg0->w, arg0->h, arg0->fmt, mip, 100);
}

s32 alloc_buffer_from_heap(Buf_803DB1B4 *arg0) {
    s32 ret = 0;
    void *p = OSAllocFromHeap(locked_cache_heap_handle, arg0->size);
    if (p == 0) {
        ret = 3;
    } else {
        arg0->mem = p;
    }
    return ret;
}

#pragma push
#pragma scheduling off
#pragma peephole off
s32 fn_803DB20C(Obj_803DB20C *o) {
    OSFreeToHeap(locked_cache_heap_handle, o->p);
    return 0;
}
#pragma pop

}
