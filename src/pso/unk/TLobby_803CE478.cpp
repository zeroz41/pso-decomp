#include "pso/audio/AdxStreamRuntime.h"
#include "types.h"
#include "pso/unk/TLobby_803CE200.h"
#include "pso/unk/TLobby_803CE478.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_803CE568.h"
#include "pso/audio/AixPlayer.h"

extern "C" void update_file_stream_range(void *context) {
    u8 *arg0 = static_cast<u8 *>(context);
    s32 spC;
    s32 sp8;

    *(s32 *)((s8 *)arg0 + 0x1B0) = (s32) (*(s32 *)((s8 *)arg0 + 0x1B0) + 1);
    if (((s32) *(u8 *)((s8 *)arg0 + 0x1A8) == 1) && ((s32) *(s32 *)((s8 *)arg0 + 0x1B0) >= (s32) *(s32 *)((s8 *)arg0 + 0x1BC))) {
        *(s32 *)((s8 *)arg0 + 0x1B0) = (s32) *(s32 *)((s8 *)arg0 + 0x1B8);
    }
    if (((s32) *(u8 *)((s8 *)arg0 + 0x1A9) == 1) && ((s32) *(s32 *)((s8 *)arg0 + 0x1B0) < (*reinterpret_cast<TLobby **>(arg0 + 4))->get_scroll_offset())) {
        TLobby__sub_803CE220();
        get_entry_pair(*reinterpret_cast<AixDemuxer **>(arg0 + 4), (s32)((int) (*(s32 *)((s8 *)arg0 + 0x1B0))), &spC, &sp8);
        set_scroll_offset__6TLobbyFl(*(AdxStreamFile **)(arg0 + 8), spC / 2048);
        set_scroll_position__6TLobbyFl(*(AdxStreamFile **)(arg0 + 8), (spC + sp8) / 2048);
        init_stream_position__6TLobbyFv(*(AdxStreamFile **)(arg0 + 8));
        TLobby::update_scroll_impl();
    }
}

CvFsErrorCallback cvfs_completion_callback;
s32 lbl_805D75FC;

void cvFsEntryErrFunc(CvFsErrorCallback callback, s32 context) {
    if (callback == NULL) {
        cvfs_completion_callback = NULL;
        lbl_805D75FC = 0;
        return;
    }
    cvfs_completion_callback = callback;
    lbl_805D75FC = context;
}
