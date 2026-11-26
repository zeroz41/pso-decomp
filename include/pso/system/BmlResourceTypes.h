#ifndef PSO_SYSTEM_BMLRESOURCETYPES_H
#define PSO_SYSTEM_BMLRESOURCETYPES_H

#include "types.h"

struct BmlModelLoadRequest {
    const char *name;
    NJS_OBJECT **model;
    NJS_TEXLIST **texture;
    BmlResource *resource;
    BmlModelEntry *entry;
    u32 size;
};
LAYOUT_ASSERT(BmlModelLoadRequestSize, sizeof(BmlModelLoadRequest) == 0x18);
LAYOUT_ASSERT(BmlModelLoadRequestArchiveOffset, offsetof(BmlModelLoadRequest, resource) == 0xC);
LAYOUT_ASSERT(BmlModelLoadRequestSizeOffset, offsetof(BmlModelLoadRequest, size) == 0x14);

struct BmlMotionLoadRequest {
    AnimationMotion **motion;
    BmlResource *resource;
};
LAYOUT_ASSERT(BmlMotionLoadRequestSize, sizeof(BmlMotionLoadRequest) == 8);

struct BmlTextureLoadRequest {
    BmlResource *resource;
    BmlModelEntry *entry;
};
LAYOUT_ASSERT(BmlTextureLoadRequestSize, sizeof(BmlTextureLoadRequest) == 8);

struct BmlArchiveEntry {
    char name[0x20];
    s32 size;
    u8 pad24[4];
    s32 rawSize;
    s32 texSize;
    u8 pad30[0x10];
};
LAYOUT_ASSERT(BmlArchiveEntry_size, sizeof(BmlArchiveEntry) == 0x40);
LAYOUT_ASSERT(BmlArchiveEntry_unpacked_size_offset, offsetof(BmlArchiveEntry, rawSize) == 0x28);
LAYOUT_ASSERT(BmlArchiveEntry_texture_size_offset, offsetof(BmlArchiveEntry, texSize) == 0x2C);

struct BmlArchiveHeader {
    u8 pad0[8];
    u8 compressed;
    s8 small;
    u8 padA[0x36];
    BmlArchiveEntry recs[1];
};
LAYOUT_ASSERT(BmlArchiveHeader_compression_offset, offsetof(BmlArchiveHeader, compressed) == 8);
LAYOUT_ASSERT(BmlArchiveHeader_entries_offset, offsetof(BmlArchiveHeader, recs) == 0x40);

#endif
