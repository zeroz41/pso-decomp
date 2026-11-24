#ifndef PSO_UNK_WINDOWLAYOUTRECORD_H
#define PSO_UNK_WINDOWLAYOUTRECORD_H

#include "types.h"

struct NJS_TEXLIST;
#include <stddef.h>

// Records of a window layout table (cols, rows, then cols * rows records), read by
// init_window_layout_entries: the first word is the record type, which selects the entry
// class and the record size.

// Packed layout descriptor for a gauge entry.
struct StatusGaugeLayout {
    u32 kind;
    f32 pos[2];
    f32 depth;
    u32 color;
    u32 flags;
    f32 scale;
    f32 maximum;
    f32 target;
};

LAYOUT_ASSERT(StatusGaugeLayout_size, sizeof(StatusGaugeLayout) == 0x24);

// Type 2 (0x2C bytes), read by TWindowStatusGaugeFeedback::init_layout_entry_copy.
struct LayoutEntryCopyRecord {
    StatusGaugeLayout gauge;
    u32 color_rising;
    u32 color_falling;
};

LAYOUT_ASSERT(LayoutEntryCopyRecord_size, sizeof(LayoutEntryCopyRecord) == 0x2C);

// Type 3 (0x1C bytes), read by construct_text_entry.
struct TextLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    const char *text;
};

// Types 4 and 5 (0x1C bytes), read by the TUnk_804CF9C8 and TUnk_804CF9E0
// constructors.
struct ValueLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    s32 pad_18;
};

// Type 6 (0x30 bytes), read by WindowSpritePart::init_part_scaled: u and v are texel
// coordinates (divided by 256).
struct SpritePartLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 size[2];
    f32 u;
    f32 v;
    f32 depth;
    s32 color;
    NJS_TEXLIST **texture_list_slot;
    s32 texture;
    s32 flags;
};

// Type 7 (0x38 bytes), with normalized texture coordinates.
struct DirectSpritePartLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 size[2];
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    f32 depth;
    s32 color;
    NJS_TEXLIST **texture_list_slot;
    s32 texture;
    s32 flags;
};

LAYOUT_ASSERT(SpritePartLayoutRecordSize, sizeof(SpritePartLayoutRecord) == 0x30);
LAYOUT_ASSERT(DirectSpritePartLayoutRecordSize, sizeof(DirectSpritePartLayoutRecord) == 0x38);

// Types 8, 9 and 12 (4 bytes): the entry reads nothing but the type.
struct TypeLayoutRecord {
    s32 type;
};

// Types 10 and 11 (0xC bytes), read by TWindowHelpItem__sub_8025A95C and
// TWindowHelpItem__sub_8025A594.
struct PointLayoutRecord {
    s32 type;
    f32 pos[2];
};

// Window descriptor passed to the TWindowBase constructor and read by
// TWindowBase::sub_80244F2C: layout goes to init_window_layout_entries, flags bits 1/2/0x20
// select rendering and the open sound.
struct WindowDescriptor {
    f32 pad_00[2];
    f32 pad_08;
    const void *layout;
    u32 flags;
};

LAYOUT_ASSERT(WindowDescriptorSize, sizeof(WindowDescriptor) == 0x14);
LAYOUT_ASSERT(WindowDescriptorLayoutOffset, offsetof(WindowDescriptor, layout) == 0xC);
LAYOUT_ASSERT(WindowDescriptorFlagsOffset, offsetof(WindowDescriptor, flags) == 0x10);

#endif
