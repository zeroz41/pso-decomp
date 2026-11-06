#include "types.h"
#include "pso/unk/text_80290B3C.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/item/drop/TItemDrop.h"
struct Hdr_80290B3C {
    u32 off;
    u32 count;
    u8 pad[8];
    u32 end;
    u8 pad2[0xC];
};

struct Ctx_80290B3C {
    u8 obj[0x1C];
    u32 base;
    u32 size;
    u32 result;
    u8 pad[0x10];
};

u32 relocate_data_block_pointers(u32 arg0, u32 arg1) {
    Ctx_80290B3C c;
    u16 *idx;
    u32 p;
    Hdr_80290B3C *h;
    u32 i;
    u32 n;
    u32 r;
    ((TUnk_8049C658 *)(&c))->construct();
    c.base = arg0;
    c.size = arg1;
    h = (Hdr_80290B3C *)(c.base + c.size) - 1;
    p = c.base;
    idx = (u16 *)(h->off + c.base);
    n = h->count;
    for (i = 0; i < n; i++) {
        p += *idx++ * 4;
        *(u32 *)p += c.base;
    }
    r = h->end + c.base;
    c.result = r;
    ((TUnk_8049C658 *)(&c))->destroy(-1);
    return r;
}
