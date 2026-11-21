#include "types.h"
#include "pso/unk/text_80290B3C.h"
#include "pso/item/TUnk_8049C658.h"
#include "pso/item/drop/TItemDrop.h"

// Relocates a loaded data block in place through a temporary resource file
// object (the same pass as apply_rel_relocations) and returns its root.
uaddr relocate_data_block_pointers(uaddr arg0, u32 arg1) {
    TUnk_8049C658 c;
    u16 *idx;
    uaddr p;
    RelFileTrailer *h;
    u32 i;
    u32 n;
    uaddr r;
    c.data = (u8 *)arg0;
    c.size = arg1;
    h = (RelFileTrailer *)((uaddr)c.data + c.size) - 1;
    p = (uaddr)c.data;
    idx = (u16 *)(h->reloc_offset + (uaddr)c.data);
    n = h->reloc_count;
    for (i = 0; i < n; i++) {
        p += *idx++ * 4;
        *(u32 *)p += (uaddr)c.data;
    }
    r = h->root_offset + (uaddr)c.data;
    c.root = (void *)r;
    return r;
}
