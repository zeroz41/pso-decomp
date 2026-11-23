// CRI adx_fsvr.c: ADXT_ExecFsSvr, one pass of the file-system servers.
#include "types.h"
#include "pso/audio/AdxFsServer.h"
#include "pso/unk/text_803D31A4.h"
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

s32 adxt_fs_svr_phase;

void ADXT_ExecFsSvr(void) {
    if ((s32) adxt_fs_svr_phase == 0) {
        TLobby::init_once();
        adxt_fs_svr_phase = 1;
        update_active_stream_reads();
        adxt_fs_svr_phase = 2;
        TLobby__sub_803CEF60();
        adxt_fs_svr_phase = 5;
        update_active_stream_reads();
        adxt_fs_svr_phase = 6;
        TLobby__sub_803CC884();
        adxt_fs_svr_phase = 0;
        TLobby::release_ref();
    }
}
