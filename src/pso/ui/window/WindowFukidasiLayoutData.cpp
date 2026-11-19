#include "types.h"

// Data-only unit split off the fukidasi layout tables at 0x804CF080; the referencing unit keeps these extern (TUnk_804CF0B8 vtable at 0x804CF0B8 left for real-class work).


__declspec(section ".data") extern u32 window_fukidasi_layout_entries[9] = {
    0x00000001, 0x00000001, 0x00000003, 0x00000000,
    0x00000000, 0x3F000000, 0xFFFFFFFF, 0x00000000,
    0x00000000,
};

__declspec(section ".data") extern u32 window_fukidasi_addition_params[5] = {
    0x00000000, 0x00000000, 0x476A6000, 0x00000000,
    0x00007023,
};
