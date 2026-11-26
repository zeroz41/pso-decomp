// CRI adx_crs.c: the ADX critical section (ADXCRS_Unlock, ADXCRS_Lock, ADXCRS_Init).
#include "types.h"
#include "pso/audio/AdxLock.h"
#include "pso/audio/CriSvm.h"
#include "pso/network/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/system/Adxf.h"
#include "pso/system/CvFs.h"


s32 init_ref_count;

void adx_unlock() {
    s32 depth;

    depth = init_ref_count - 1;
    init_ref_count = depth;
    if (depth == 0) {
        svm_unlock();
    }
}

void adx_lock() {
    if (init_ref_count == 0) {
        svm_lock();
    }
    init_ref_count += 1;
}

void reset_init_ref_count(void) {
    init_ref_count = 0;
}

