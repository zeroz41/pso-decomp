#ifndef PSO_UNK_TEXT_8028EC70_H
#define PSO_UNK_TEXT_8028EC70_H

#include "types.h"

extern "C" {
void TAdSinglePlyChrSelectGC__sub_8028ED54(saddr part);
}

// Steps one appearance part up, then down, to the first variant no saved character uses.
s32 select_unused_appearance_part(void *appearance, s32 part);

struct ByteBlock_50 { u8 bytes[0x50]; };

struct CopySlotDataDst { u8 pad[4]; s16 a[5]; u8 b; };

struct CopySlotDataSrc { u8 pad[0x30]; u8 b; u8 pad2[7]; s16 a[5]; };

struct TAdSinglePlyChrSelectGCChr { u8 pad[0x38]; s16 sel[5]; u8 pad2[0x50 - 0x42]; };

struct IsEntryEqualA { u8 pad0[4]; s16 v[5]; s8 e; };

struct IsEntryEqualB { u8 pad0[0x30]; s8 e; u8 pad31[7]; s16 v[5]; };

struct CountCharDiffsA { u8 pad0[4]; s16 v[5]; s8 e; };

struct CountCharDiffsB { u8 pad0[0x30]; s8 e; u8 pad31[7]; s16 v[5]; };

#endif
