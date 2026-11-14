#ifndef MUSYX_DSPVOICE_H
#define MUSYX_DSPVOICE_H

#include "types.h"

typedef struct _PB_803B5500 {
    u8 pad0[0x4];
    u16 currHi;
    u16 currLo;
    u8 pad8[0x38 - 0x8];
    u16 itdBufferHi;
    u16 itdBufferLo;
    u8 pad3C[0x4E - 0x3C];
    u16 updateDataHi;
    u16 updateDataLo;
    u8 pad52[0xBC - 0x52];
} _PB_803B5500;
typedef struct DSPvoice_803B5500 {
    _PB_803B5500 *pb;
    void *patchData;
    void *itdBuffer;
    u8 padC[0x24 - 0xC];
    u32 changed[5];
    u8 pad38[0xE4 - 0x38];
    u8 lastUpdatePitch;
    u8 lastUpdateVol;
    u8 lastUpdateVolA;
    u8 lastUpdateVolB;
    u32 virtualSampleID;
    u8 state;
    u8 postBreak;
    u8 startupBreak;
    u8 padEF[0xF4 - 0xEF];
} DSPvoice_803B5500;

extern DSPvoice_803B5500 *dspVoice;

#endif
