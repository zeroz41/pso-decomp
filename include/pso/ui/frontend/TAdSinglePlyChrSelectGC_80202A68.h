#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_80202A68_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_80202A68_H

#include "types.h"
#include <stddef.h>
#include "pso/player/TPlyCharData.h"
#include "pso/ui/city/BankItemRecord.h"

struct Record_80203190 {
    Record_80203190();

    u8 pad_0[0x450];
    BankItemRecord items[4];
    // Set up by init_guild_card_tag.
    u8 guild_card[0x3598 - 0x4B0];
};

struct Slot_80202C68 {
    Slot_80202C68();
    ~Slot_80202C68();

    TPlyCharData chardata;
    Record_80203190 record;
};

struct Words_80202C68 { u32 w[32]; };

struct Blk_80202C68 { u32 a; Words_80202C68 b; };

struct Pair_80202C68 { u32 a; u32 b; };

struct Tail_80202C68 { Pair_80202C68 p0, p1, p2, p3, p4, p5, p6; };

struct Save_80202C68 {
    Save_80202C68();
    ~Save_80202C68();

    s32 hdr;
    Slot_80202C68 slots[7];
    Tail_80202C68 tail;
    Blk_80202C68 blk;
    s32 f194AC;
};

LAYOUT_ASSERT(Slot_80202C68_record_offset, offsetof(Slot_80202C68, record) == 0x41C);
LAYOUT_ASSERT(Slot_80202C68_size, sizeof(Slot_80202C68) == 0x39B4);
LAYOUT_ASSERT(Save_80202C68_size, sizeof(Save_80202C68) == 0x194B0);

extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_80202A68(u8 *arg0);
u8 TAdSinglePlyChrSelectGC__sub_80202B30(void *p);
void *TAdSinglePlyChrSelectGC__sub_80202D7C(void *a0, void *a1);
void TAdSinglePlyChrSelectGC__sub_80203210(void *p);
int fn_8020325C(void *arg0);
}

// --- C functions defined in TAdSinglePlyChrSelectGC_80202A68.cpp ---
extern "C" {
s32 TAdSinglePlyChrSelectGC__sub_80202A68(u8 *arg0);
u8 TAdSinglePlyChrSelectGC__sub_80202B30(void *p);
void *TAdSinglePlyChrSelectGC__sub_80202D7C(void *a0, void *a1);
void TAdSinglePlyChrSelectGC__sub_80203210(void *p);
int fn_8020325C(void *arg0);
}
// --- end of C functions

#endif
