#include "types.h"
#include "pso/system/DataBlockRelocation.h"
#include "pso/item/TRelDataFile.h"
#include "pso/item/drop/TItemDrop.h"

// Relocates a loaded data block in place through a temporary resource file
// object (the same pass as apply_rel_relocations) and returns its root.
uaddr relocate_data_block_pointers(uaddr data, u32 size) {
    TRelDataFile c;
    u16 *idx;
    uaddr p;
    RelFileTrailer *h;
    u32 i;
    u32 n;
    uaddr r;
    c.data = (u8 *)data;
    c.size = size;
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
