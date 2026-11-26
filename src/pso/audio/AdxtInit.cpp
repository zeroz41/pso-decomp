// CRI adx_inis.c: ADXT_Finish, ADXT_Init and the SVM server callbacks they register.
#include "pso/audio/AdxtInit.h"
#include "pso/audio/AdxError.h"
#include "pso/audio/AdxbDecoder.h"
#include <string.h>
#include "pso/audio/CriSvm.h"
#include "pso/audio/AixPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/AdxFsServer.h"
#include "pso/audio/AdxLock.h"
#include "pso/audio/GcrnaBridge.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxtInternal.h"
#include "pso/audio/AdxEncoder.h"
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/system/Adxf.h"
#include "pso/audio/SjMemoryBuffer.h"
#include "pso/audio/SjRingBuffer.h"
#include "pso/system/CvFs.h"

extern "C" {
s32 adxt_svm_server_sw = 1;
s32 adxt_init_count;
s32 svm_cb_svr_handle;
s32 adxt_vblank_count;
static const char *const volatile adxt_build_string = "\nADXT/GC Ver.8.05 Build:Jun 13 2002 19:01:36\n";
}

AdxtPlayer adx_stream_player_pool[16];

void adxt_finish() {
    s32 remaining;

    remaining = adxt_init_count - 1;
    adxt_init_count = remaining;
    if (remaining == 0) {
        gcrna_bridge_shutdown();
        adxf_finish();
        adxstm_finish_fs();
        lsc_shutdown();
        adx_lock();
        SVM_DelCbSvr(2, (saddr)((void *) (1)));
        SVM_DelCbSvr(2, (saddr)((void *) (3)));
        SVM_DelCbSvr(4, svm_cb_svr_handle);
        svm_finish();
        adx_unlock();
        adx_lock();
        adxb_finish();
        adxerr_finish();
        sj_memory_buffer_shutdown();
        sj_ring_buffer_shutdown();
        ref_counted_work_buffer_finish();
        adx_unlock();
    }
}
void adxt_init() {
    adxt_build_string;
    if (adxt_init_count == 0) {
        reset_init_ref_count();
        adx_lock();
        ref_counted_work_buffer_init();
        sj_ring_buffer_init();
        sj_memory_buffer_init();
        adxerr_init();
        adxstm_clear_requests();
        adxb_init();
        adxf_init();
        gcrna_bridge_initialize();
        gcrna_bridge_set_error_callback(adxt_error_callback, NULL);
        memset(adx_stream_player_pool, 0, 0xA80);
        lsc_init();
        if (adxt_svm_server_sw == 1) {
            SVM_SetCbSvrId(2, 1, adxt_exec_main_server_cb, 0);
            SVM_SetCbSvrId(2, 3, adxt_exec_fs_server_cb, 0);
            svm_cb_svr_handle = SVM_SetCbSvr(4, adxt_exec_vsync_server_cb, 0);
        }
        adxt_vblank_count = 0;
        adx_unlock();
    }
    adxt_init_count += 1;
}

s32 adxt_exec_fs_server_cb(s32) {
    ADXT_ExecFsSvr();
    return 0;
}

s32 adxt_exec_main_server_cb(s32) {
    adxt_exec_server();
    return 0;
}

s32 adxt_exec_vsync_server_cb(s32) {
    if (is_adxm_initialized() == 1) {
        lsc_poll_all();
        aix_exec_server();
    } else {
        exec_vsync_servers();
        lsc_poll_all();
        aix_exec_server();
    }
    return 0;
}

void adxt_error_callback(void *, const char *message) {
    adxerr_report(message);
}
