#include "types.h"

// Data-only unit split off TKeyBoardControl float constants at 0x805DC0C0; the referencing unit keeps these extern.


__declspec(section ".sdata2") extern u32 lbl_805DC0C0[1] = {
    0x00000000,
};

__declspec(section ".sdata2") extern u32 lbl_805DC0C4[1] = {
    0x3C000000,
};

__declspec(section ".sdata2") extern u32 lbl_805DC0C8[2] = {
    0x3F800000, 0x00000000,
};
