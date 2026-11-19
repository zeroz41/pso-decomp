#include "types.h"

// Data-only unit split off float constants at 0x805D85B8; referencing units keep these extern.


__declspec(section ".sdata2") extern u32 lbl_805D85B8[1] = {
    0x00000000,
};

__declspec(section ".sdata2") extern u32 lbl_805D85BC[1] = {
    0x40C00000,
};

__declspec(section ".sdata2") extern u32 lbl_805D85C0[1] = {
    0x462AAAAB,
};

__declspec(section ".sdata2") extern u32 lbl_805D85C4[1] = {
    0x3F333333,
};

__declspec(section ".sdata2") extern u32 lbl_805D85C8[2] = {
    0x3DAAAAAB, 0x00000000,
};
