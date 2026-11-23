#include "types.h"

// Data-only unit split off TAdMultiPlyChrSelectGC.cpp: its .rodata tables.
// The referencing unit keeps these as extern, so its per-object lis/addi
// codegen stays byte-identical; this unit only provides the bytes.

__declspec(section ".rodata") extern const u32 multi_chr_select_widget_layout[4] = {
    0x43340000, 0x42180000, 0xDD904800, 0x00000000,
};

__declspec(section ".rodata") extern const u32 TAdMultiPlyChrSelectGC__character_slot_positions[8] = {
    0x41E00000, 0x43360000, 0x41E00000, 0x43610000,
    0x41E00000, 0x43860000, 0x41E00000, 0x439B8000,
};

__declspec(section ".rodata") extern const u32 multi_play_chr_select_slot_positions[6] = {
    0x436A0000, 0x43360000, 0x436A0000, 0x43610000,
    0x436A0000, 0x43860000,
};

__declspec(section ".rodata") extern const u32 multi_chr_select_item_rect_table[8] = {
    0x43D90000, 0x43360000, 0x43D90000, 0x43610000,
    0x43D90000, 0x43860000, 0x43D90000, 0x439B8000,
};

__declspec(section ".rodata") extern const u32 multi_chr_select_cursor_size[2] = {
    0x43340000, 0x42180000,
};

extern "C" __declspec(section ".rodata") const char TAdMultiPlyChrSelectGC__class_name_string[] = "TAdMultiPlyChrSelectGC";

__declspec(section ".rodata") extern const u32 multi_chr_select_cursor_position[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 multi_chr_select_layout_table[6] = {
    0x431C0000, 0x43D28000, 0x43958000, 0x43D28000,
    0x43D80000, 0x43D28000,
};

__declspec(section ".rodata") extern const u32 lbl_80472848[2] = {
    0x00000000, 0x00000000,
};

__declspec(section ".rodata") extern const u32 lbl_80472850[2] = {
    0x42B60000, 0x43200000,
};

__declspec(section ".rodata") extern const u32 lbl_80472858[2] = {
    0x43D60000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472860[2] = {
    0x42B60000, 0x43200000,
};

__declspec(section ".rodata") extern const u32 lbl_80472868[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472870[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472878[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472880[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472888[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472890[2] = {
    0x43C68000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_80472898[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_804728A0[2] = {
    0x43610000, 0x43040000,
};

__declspec(section ".rodata") extern const u32 lbl_804728A8[2] = {
    0x43CB8000, 0x432C0000,
};
