#include "types.h"
#include "pso/unk/text_803D31A4.h"
#include "pso/misc/TLobby.h"

extern s32 (*mfci_error_callback)(s32, s32 *, s32);

extern s32 lbl_8047E0C8[];
extern s32 mfci_error_callback_context;

void TLobby::release_handle() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) mfci_error_callback) != NULL) {
            mfci_error_callback(mfci_error_callback_context, lbl_8047E0C8, 0);
        }
    } else {
        TLobby__sub_803D39C0();
        *(s8 *)((s8 *)arg0 + 1) = 0;
        TLobby__sub_803D3988();
    }
}
