#ifndef PSO_SYSTEM_SAVE_CARD_SAVE_FILE_H
#define PSO_SYSTEM_SAVE_CARD_SAVE_FILE_H

#include "types.h"
#include <stddef.h>

struct CardSaveDescriptor {
    char filename[0x12];
    char title[0x22];
    u8 key[0x10];
    const void *banner;
    const void *icon;
    s16 field_4c;
    s16 field_4e;
    s32 field_50;
    u16 omit_title_space;
    u8 *data;
    s32 size;
};

LAYOUT_ASSERT(CardSaveDescriptor_banner_offset, offsetof(CardSaveDescriptor, banner) == 0x44);
LAYOUT_ASSERT(CardSaveDescriptor_data_offset, offsetof(CardSaveDescriptor, data) == 0x58);
LAYOUT_ASSERT(CardSaveDescriptor_size, sizeof(CardSaveDescriptor) == 0x60);

extern "C" {
void TAdPlayerLoadGC__sub_801E14E8(CardSaveDescriptor *file, s32 index);
s32 TAdPlayerLoadGC__sub_801E1538(CardSaveDescriptor *file, void *image);
void TAdPlayerLoadGC__sub_801E14E4(CardSaveDescriptor *file);
}

#endif
