#include "types.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/item/drop/TItemDrop.h"

struct Hdr_800F9C00 { u32 dataOff; u32 count; u8 pad8[8]; u32 rootOff; };

struct Obj_800F9C00 {
    u8 pad0[0x1C];
    u8 *base;
    s32 size;
    u8 *root;
};

extern "C" {
u8 *apply_rel_relocations(Obj_800F9C00 *arg0);
void __ct__7TObjectFP7TObject(void *, s32);

extern s32 lbl_8049C658[];

#pragma opt_propagation off
u8 *apply_rel_relocations(Obj_800F9C00 *arg0) {
    u16 *idx;
    u8 *cur;
    Hdr_800F9C00 *h;
    u32 off;
    u8 *b;
    b = arg0->base;
    h = (Hdr_800F9C00 *)((b + arg0->size) - 0x20);
    idx = (u16 *)(h->dataOff + (u32)b);
    cur = b;
    u32 n = h->count;
    u32 i;
    for (i = 0; i < n; i++) {
        cur += *idx++ * 4;
        *(u32 *)cur += (u32)arg0->base;
    }
    arg0->root = (u8 *)(h->rootOff + (u32)arg0->base);
    return arg0->root;
}

void *TUnk_8049C658::ct_object() {
    ((void (*)(void *))__ct__7TObjectFP7TObject)(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_8049C658;
    return this;
}

void *TUnk_8049C658::construct() {
    __ct__7TObjectFP7TObject(this, 0);
    *(s32 **)((s8 *)this + 0x18) = lbl_8049C658;
    return this;
}

}
