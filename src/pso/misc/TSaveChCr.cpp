#include "pso/menu/CreationInput.h"
#include "types.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TSaveChCr.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/TSaveChCr.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/misc/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_20 { u8 bytes[0x20]; };

struct RecoveredGlobal_80339F98_lbl_80477CBC {
    s32 value;
    u8 remaining[0x20];
};

extern "C" {
extern RecoveredGlobal_80339F98_lbl_80477CBC TSaveChCr__message_text_ids;
u32 update_window_mode_from_progress__6TLobbyFPv(s32 *, s32 *);
extern s32 lbl_80477CAC[];
extern s32 lbl_80477CB4[];
s32 TAdPlayerLoadGC__sub_801E1B50(s32);
s32 TAdSinglePlyChrSelectGC__sub_80339DBC(void *);
s32 poll_memcard_status__23TAdSinglePlyChrSelectGCFv();

s32 TSaveChCr::poll_memcard_status() {
    s32 var_r31;

    if (TAdPlayerLoadGC::probe_card_slot(0) == 0) {
        this->m_28 = 0;
        return 1;
    }
    if (TAdPlayerLoadGC::probe_and_check_card(0) == 0) {
        this->m_28 = 0;
        return 4;
    }
    if (TAdPlayerLoadGC__sub_801E1B50(0) != 0) {
        this->m_24 = (this->m_24 + 1);
        this->m_28 = 0;
        return 2;
    }
    this->m_24 = 0;
    if (TAdPlayerLoadGC::check_memcard_status(0) != 0) {
        this->m_28 = 0;
        return 4;
    }
    if ((s32) this->m_28 != 0) {
        return this->card_status;
    }
    var_r31 = 0;
    this->m_28 = 1;
    if (poll_memcard_status__23TAdSinglePlyChrSelectGCFv() == 0) {
        var_r31 |= 4;
    }
    if (TAdSinglePlyChrSelectGC__sub_80339DBC(this) == 0) {
        var_r31 |= 4;
    }
    return var_r31;
}

s32 TSaveChCr__sub_80339F30(void) {
    return creation_buttons_pressed(4) ? 1 : 0;
}

void TSaveChCr::close_and_advance(void* a1) { close_window(); set_message_by_index((s32)a1); }
typedef char RecoveredGlobal_80339F98_lbl_80477CBC_size[sizeof(RecoveredGlobal_80339F98_lbl_80477CBC) == 0x24 ? 1 : -1];
void TSaveChCr::set_message_by_index(s32 arg1) {
    s32 arg0 = (s32)this;
    ByteBlock_20 sp8;
    u8 *temp_r4;
    sp8 = *(const ByteBlock_20 *)((s32) ((u8 *)&TSaveChCr__message_text_ids.value + -4) + 4);
    temp_r4 = (u8 *)&sp8 + (arg1 * 8);
    open_message_window((u32)((int) (get_localized_text_entry(*(s32 *)((s8 *)temp_r4 + 0), *(s32 *)((s8 *)temp_r4 + 4)))));
}
void TSaveChCr::open_message_window(u32 arg1) {
    if ((u32) this->owned_window == 0U) {
        *(u32 *)&this->owned_window = update_window_mode_from_progress__6TLobbyFPv(lbl_80477CAC, lbl_80477CB4);
        if ((u32) this->owned_window != 0U) {
            if (arg1 != 0U) {
                ((TWindowMessage *)(this->owned_window))->append_line(arg1, 3);
            }
            ((TWindowMessage *)(this->owned_window))->complete_reveal();
        }
    }
}

}
