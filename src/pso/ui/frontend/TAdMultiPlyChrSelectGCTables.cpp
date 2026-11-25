#include "types.h"
#include "pso/system/NinjaTypes.h"

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

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472850 = {91.0f, 160.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472858 = {428.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472860 = {91.0f, 160.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472868 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472870 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472878 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472880 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472888 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472890 = {397.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_80472898 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_804728A0 = {225.0f, 132.0f};

__declspec(section ".rodata") extern const NJS_POINT2 lbl_804728A8 = {407.0f, 172.0f};
