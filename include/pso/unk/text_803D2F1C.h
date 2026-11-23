#ifndef PSO_UNK_TEXT_803D2F1C_H
#define PSO_UNK_TEXT_803D2F1C_H

#include "types.h"
#include "pso/audio/SjRingBuffer.h"

extern "C" {
void TLobby__sub_803D3130(const SjChunk *chunk, s32 size, SjChunk *prefix, SjChunk *remainder);
s32 size_803D2F1C(u8 *p);
u8 *find_archive_entry(SjChunk *arc, const char *name, const char *stop, SjChunk *out);
}

#endif
