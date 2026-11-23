#ifndef PSO_AUDIO_GCRNABUFFERQUERY_H
#define PSO_AUDIO_GCRNABUFFERQUERY_H

#include "types.h"

struct GcrnaBufferVtable {
    u8 pad_00[0x24];
    s32 (*query_bytes)(struct GcrnaBufferVtable **stream, s32 mode, struct GcrnaBufferVtable *vtable);
};

struct GcrnaBufferQueryState {
    u8 pad_00[0x08];
    u32 flags;
    u8 pad_0C[0x1C];
    GcrnaBufferVtable **stream;
};

#endif
