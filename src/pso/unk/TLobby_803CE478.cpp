#include "types.h"
#include "pso/unk/TLobby_803CE200.h"
#include "pso/unk/TLobby_803CE478.h"
#include "pso/unk/TLobby.h"

void TLobby::update_scroll() {
    u8 *arg0 = (u8 *)this;
    s32 spC;
    s32 sp8;

    *(s32 *)((s8 *)arg0 + 0x1B0) = (s32) (*(s32 *)((s8 *)arg0 + 0x1B0) + 1);
    if (((s32) *(u8 *)((s8 *)arg0 + 0x1A8) == 1) && ((s32) *(s32 *)((s8 *)arg0 + 0x1B0) >= (s32) *(s32 *)((s8 *)arg0 + 0x1BC))) {
        *(s32 *)((s8 *)arg0 + 0x1B0) = (s32) *(s32 *)((s8 *)arg0 + 0x1B8);
    }
    if (((s32) *(u8 *)((s8 *)arg0 + 0x1A9) == 1) && ((s32) *(s32 *)((s8 *)arg0 + 0x1B0) < ((TLobby *)(*(s32 *)&this->m_flags))->get_scroll_offset())) {
        TLobby__sub_803CE220();
        ((TLobby *)(*(s32 *)&this->m_flags))->get_entry_pair((s32)((int) (*(s32 *)((s8 *)arg0 + 0x1B0))), &spC, &sp8);
        ((TLobby *)(*(s32 *)&this->m_prev))->set_scroll_offset((int) (spC / 2048));
        ((TLobby *)(*(s32 *)&this->m_prev))->set_scroll_position((s32)((void *) ((s32) (spC + sp8) / 2048)));
        ((TLobby *)(*(s32 *)&this->m_prev))->init_stream_position();
        TLobby::update_scroll_impl();
    }
}

extern u32 cvfs_completion_callback;
extern s32 lbl_805D75FC;

void TLobby__sub_803CE544(u32 arg0, s32 arg1) {
    if (arg0 == 0U) {
        cvfs_completion_callback = 0U;
        lbl_805D75FC = 0;
        return;
    }
    cvfs_completion_callback = arg0;
    lbl_805D75FC = arg1;
}
