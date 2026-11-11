// CRI adx_fsvr.c: ADXT_ExecFsSvr, one pass of the file-system servers.
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

extern s32 lbl_805D7530;

void ARAlloc(void) {
    if ((s32) lbl_805D7530 == 0) {
        TLobby::init_once();
        lbl_805D7530 = 1;
        update_active_stream_reads();
        lbl_805D7530 = 2;
        TLobby__sub_803CEF60();
        lbl_805D7530 = 5;
        update_active_stream_reads();
        lbl_805D7530 = 6;
        TLobby__sub_803CC884();
        lbl_805D7530 = 0;
        TLobby::release_ref();
    }
}
