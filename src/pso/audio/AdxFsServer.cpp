// CRI adx_fsvr.c: ADXT_ExecFsSvr, one pass of the file-system servers.
#include "types.h"
#include "pso/audio/AdxLock.h"
#include "pso/audio/AdxFsServer.h"
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

s32 adxt_fs_svr_phase;

void ADXT_ExecFsSvr(void) {
    if ((s32) adxt_fs_svr_phase == 0) {
        adx_lock();
        adxt_fs_svr_phase = 1;
        update_active_stream_reads();
        adxt_fs_svr_phase = 2;
        exec_device_servers();
        adxt_fs_svr_phase = 5;
        update_active_stream_reads();
        adxt_fs_svr_phase = 6;
        adxf_exec_server();
        adxt_fs_svr_phase = 0;
        adx_unlock();
    }
}
