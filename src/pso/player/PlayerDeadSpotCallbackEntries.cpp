#include "types.h"

// Data-only unit split off the dead-spot callback entries at 0x804C3E38; the referencing unit keeps these extern.

extern u8 TObjPlayer__sub_801BEDC0[];
extern u8 TObjPlayer__sub_801BFAD4[];

__declspec(section ".data") extern u32 lbl_804C3E38[3] = {
    0x00000000, 0x00000000, (uaddr)TObjPlayer__sub_801BFAD4,
};

__declspec(section ".data") extern u32 lbl_804C3E44[3] = {
    0x00000000, 0x00000000, (uaddr)TObjPlayer__sub_801BEDC0,
};
