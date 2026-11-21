#include "types.h"

// Data-only unit split off technique_ringwave_texture_list at 0x804CC8C8 (list + descriptor); referencing units keep these extern.

extern u8 lbl_8044D5D0[];
extern u8 lbl_8044D5E4[];
extern u8 lbl_8044D5F0[];
extern u8 lbl_8044D5FC[];
extern u8 lbl_8044D608[];
extern u8 lbl_8044D614[];
extern u8 lbl_8044D620[];
extern u8 lbl_8044D62C[];
extern u8 lbl_8044D638[];

__declspec(section ".data") extern u32 lbl_804CC8C8[27] = {
    (uaddr)lbl_8044D5D0, 0x00000000, 0x00000000, (uaddr)lbl_8044D5E4,
    0x00000000, 0x00000000, (uaddr)lbl_8044D5F0, 0x00000000,
    0x00000000, (uaddr)lbl_8044D5FC, 0x00000000, 0x00000000,
    (uaddr)lbl_8044D608, 0x00000000, 0x00000000, (uaddr)lbl_8044D614,
    0x00000000, 0x00000000, (uaddr)lbl_8044D620, 0x00000000,
    0x00000000, (uaddr)lbl_8044D62C, 0x00000000, 0x00000000,
    (uaddr)lbl_8044D638, 0x00000000, 0x00000000,
};

__declspec(section ".data") extern u32 technique_ringwave_texture_list[3] = {
    (uaddr)lbl_804CC8C8, 0x00000009, 0x00000000,
};
