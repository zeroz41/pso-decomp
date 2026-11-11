// CRI adx_inis.c: ADXT_Finish, ADXT_Init and the SVM server callbacks they register.
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
s32 memset(void *, int, int);
void flush_update__6TLobbyFv(void *, int);
extern s32 lbl_805D4658;
extern s32 TLobby_init_ref_count;
extern s32 TLobby__svm_cb_svr_handle;
extern s32 lbl_805D7540;
extern const s32 lbl_805E0D30;
void TLobby__sub_803CE240(void);
}

Ent_803C9608 adx_stream_player_pool[16];

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
        TLobby::SVM_DelCbSvr(2, (s32)((void *) (1)));
        TLobby::SVM_DelCbSvr(2, (s32)((void *) (3)));
        TLobby::SVM_DelCbSvr(4, TLobby__svm_cb_svr_handle);
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
    s32 v = lbl_805E0D30;
    if (TLobby_init_ref_count == 0) {
        ((void (*)(s32))TLobby__sub_803C4698)(v);
        TLobby::init_once();
        TLobby__sub_803D2ED4();
        sj_ring_buffer_init();
        sj_memory_buffer_init();
        TLobby::clear_error_callback_state();
        TLobby::clear_buffer_a00();
        TLobby::reset_sound_buffers();
        TLobby::init_afs_adxf_state();
        TLobby__sub_803CC114();
        flush_update__6TLobbyFv((void *)TLobby::forward_notify_error, 0);
        memset(adx_stream_player_pool, 0, 0xA80);
        lsc_init();
        if (lbl_805D4658 == 1) {
            TLobby::SVM_SetCbSvrId(2, 1, (s32)((void *)TLobby::get_state_zero), 0);
            TLobby::SVM_SetCbSvrId(2, 3, (s32)((void *)TLobby::ar_alloc), 0);
            TLobby__svm_cb_svr_handle = TLobby::svm_set_cb_svr(4, (s32)((void *)TLobby::process_connection_state), 0);
        }
        lbl_805D7540 = 0;
        TLobby::release_ref();
    }
    TLobby_init_ref_count += 1;
}

extern "C" {

s32 TLobby::ar_alloc() {
    ARAlloc();
    return 0;
}

s32 TLobby::get_state_zero() {
    TLobby__sub_803C9608();
    return 0;
}

s32 TLobby::process_connection_state() {
    if (TLobby__sub_803CB844() == 1) {
        lsc_poll_all();
        TLobby__sub_803CE240();
    } else {
        TLobby__sub_803CBA38();
        lsc_poll_all();
        TLobby__sub_803CE240();
    }
    return 0;
}

void TLobby::forward_notify_error(s32 arg0, s32 arg1) {
    TLobby::notify_error((const char *)arg1);
}
}
