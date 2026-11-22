#include "types.h"
#include "pso/unk/text_8023F660.h"

extern "C" {
s32 sndStreamMixParameter(u32, u8, u8, u8, u8);
s32 TLobby__sub_803C9CB0(s32);
s32 TLobby__sub_803CBE64(s32, s32);
void fn_8023F660(void *arg0, s32 tracks, s32 vol, s32 pan, s32 arg4, s32 fxvol) {
    if (arg4 < 0) {
        arg4 = 0;
    }
    if (arg4 > 0x7F) {
        arg4 = 0x7F;
    }
    if (vol < 0) {
        vol = 0;
    }
    if (vol > 0x7F) {
        vol = 0x7F;
    }
    if (pan < 0) {
        pan = 0;
    }
    if (pan > 0x7F) {
        pan = 0x7F;
    }
    if (fxvol < 0) {
        fxvol = 0;
    }
    if (fxvol > 0x7F) {
        fxvol = 0x7F;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x2A0) != 2) {
        arg4 = 0;
    }
    if (TLobby__sub_803C9CB0(tracks) == 3) {
        sndStreamMixParameter(TLobby__sub_803CBE64(tracks, 0), (u8) vol, (u8) pan, (u8) arg4, (u8) fxvol);
    }
}

}
