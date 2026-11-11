// CRI adx_crs.c: the ADX critical section (ADXCRS_Unlock, ADXCRS_Lock, ADXCRS_Init).
#include "types.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803CC0B4.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/text_803CE568.h"

extern "C" {

extern s32 TLobby__init_ref_count;

void TLobby::release_ref() {
    s32 temp_r0;

    temp_r0 = TLobby__init_ref_count - 1;
    TLobby__init_ref_count = temp_r0;
    if (temp_r0 == 0) {
        TLobby__sub_803D3988();
    }
}

void TLobby::init_once() {
    if ((s32) TLobby__init_ref_count == 0) {
        TLobby__sub_803D39C0();
    }
    TLobby__init_ref_count += 1;
}

void TLobby__sub_803C4698(void) {
    TLobby__init_ref_count = 0;
}

}
