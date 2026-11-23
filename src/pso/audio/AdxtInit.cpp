// CRI adx_inis.c: ADXT_Finish, ADXT_Init and the SVM server callbacks they register.
#include <string.h>
#include "pso/unk/text_803D31A4.h"
#include "pso/unk/text_803CE240.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/AdxFsServer.h"
#include "pso/audio/AdxLock.h"
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
s32 lbl_805D4658 = 1;
s32 TLobby_init_ref_count;
s32 svm_cb_svr_handle;
s32 lbl_805D7540;
static const char *const volatile lbl_805E0D30 = "\nADXT/GC Ver.8.05 Build:Jun 13 2002 19:01:36\n";
}

AdxStreamPlayer adx_stream_player_pool[16];

void TLobby::dec_ref_and_shutdown() {
    s32 temp_r0;

    temp_r0 = TLobby_init_ref_count - 1;
    TLobby_init_ref_count = temp_r0;
    if (temp_r0 == 0) {
        TLobby::shutdown_cleanup();
        TLobby::dec_ref_and_reset_tables();
        TLobby::si_get_type_async();
        lsc_shutdown();
        TLobby::init_once();
        TLobby::SVM_DelCbSvr(2, (saddr)((void *) (1)));
        TLobby::SVM_DelCbSvr(2, (saddr)((void *) (3)));
        TLobby::SVM_DelCbSvr(4, svm_cb_svr_handle);
        TLobby__sub_803D3194();
        TLobby::release_ref();
        TLobby::init_once();
        TLobby::clear_session_buffer();
        TLobby::clear_error_callback();
        sj_memory_buffer_shutdown();
        sj_ring_buffer_shutdown();
        TLobby::dec_ref_and_clear_buffer();
        TLobby::release_ref();
    }
}
void TLobby::init_and_add_ref() {
    lbl_805E0D30;
    if (TLobby_init_ref_count == 0) {
        TLobby__sub_803C4698();
        TLobby::init_once();
        TLobby__sub_803D2ED4();
        sj_ring_buffer_init();
        sj_memory_buffer_init();
        TLobby::clear_error_callback_state();
        TLobby::clear_buffer_a00();
        TLobby::reset_sound_buffers();
        TLobby::init_afs_adxf_state();
        TLobby__sub_803CC114();
        TLobby::flush_update(TLobby::forward_notify_error, NULL);
        memset(adx_stream_player_pool, 0, 0xA80);
        lsc_init();
        if (lbl_805D4658 == 1) {
            TLobby::SVM_SetCbSvrId(2, 1, TLobby::get_state_zero, 0);
            TLobby::SVM_SetCbSvrId(2, 3, TLobby::ar_alloc, 0);
            svm_cb_svr_handle = TLobby::svm_set_cb_svr(4, TLobby::process_connection_state, 0);
        }
        lbl_805D7540 = 0;
        TLobby::release_ref();
    }
    TLobby_init_ref_count += 1;
}

s32 TLobby::ar_alloc(s32) {
    ADXT_ExecFsSvr();
    return 0;
}

s32 TLobby::get_state_zero(s32) {
    TLobby__sub_803C9608();
    return 0;
}

s32 TLobby::process_connection_state(s32) {
    if (is_adxm_initialized() == 1) {
        lsc_poll_all();
        TLobby__sub_803CE240();
    } else {
        exec_vsync_servers();
        lsc_poll_all();
        TLobby__sub_803CE240();
    }
    return 0;
}

void TLobby::forward_notify_error(void *, const char *message) {
    TLobby::notify_error(message);
}
