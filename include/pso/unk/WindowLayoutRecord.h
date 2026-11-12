#ifndef PSO_UNK_WINDOWLAYOUTRECORD_H
#define PSO_UNK_WINDOWLAYOUTRECORD_H

#include "types.h"

// Records of a window layout table (cols, rows, then cols * rows records), read by
// init_window_layout_entries: the first word is the record type, which selects the entry
// class and the record size.

// Type 2 (0x2C bytes), read by TWindowSubStatusDisp::init_layout_entry_copy.
struct LayoutEntryCopyRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    f32 pad_18;
    s32 pad_1C;
    s32 pad_20;
    u32 pad_24;
    u32 pad_28;
};

// Type 3 (0x1C bytes), read by construct_text_entry.
struct TextLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    const char *text;
};

// Types 4 and 5 (0x1C bytes), read by TWindowSubStatusDisp__sub_80259D3C and
// TWindowSubStatusDisp::init_layout_entry_scaled.
struct ValueLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    s32 pad_18;
};

// Type 6 (0x30 bytes), read by TWindowSubStatusDisp::init_part_scaled: u and v are texel
// coordinates (divided by 256).
struct SpritePartLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 size[2];
    f32 u;
    f32 v;
    f32 pad_1C;
    s32 pad_20;
    s32 *pad_24;
    s32 pad_28;
    s32 pad_2C;
};

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

// Window descriptor passed to TWindowDD::construct_base and read by
// TWindowBase::sub_80244F2C: layout goes to init_window_layout_entries, flags bits 1/2/0x20
// select rendering and the open sound.
struct WindowDescriptor {
    f32 pad_00[2];
    f32 pad_08;
    const void *layout;
    u32 flags;
};

#endif
