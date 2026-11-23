// CRI adx_crs.c: the ADX critical section (ADXCRS_Unlock, ADXCRS_Lock, ADXCRS_Init).
#include "types.h"
#include "pso/audio/AdxLock.h"
#include "pso/audio/CriSvm.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/text_803CE568.h"


s32 init_ref_count;

void TLobby::release_ref() {
    s32 depth;

    depth = init_ref_count - 1;
    init_ref_count = depth;
    if (depth == 0) {
        svm_unlock();
    }
}

void TLobby::init_once() {
    if ((s32) init_ref_count == 0) {
        svm_lock();
    }
    init_ref_count += 1;
}

void TLobby__sub_803C4698(void) {
    init_ref_count = 0;
}

