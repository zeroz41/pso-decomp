#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_803CBDE0.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/unk/TLobby.h"

extern "C" {

s32 TLobby__sub_803CBEC8(int);
s32 apply_field__6TLobbyFv(int);
s32 VIWaitForRetrace();

void TKeyBoardControl::flush_input() {
    TLobby::run_worker_callbacks_slot4();
}
}

void wait_for_vi_retrace(void) {
    VIWaitForRetrace();
}

void TLobby__sub_803CBE20(void) {
    TLobby::run_step_60c8();
}

void TLobby__sub_803CBE40(u8 *arg0) {
    apply_field__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0xC)));
}

void TLobby__sub_803CBE64(u8 *arg0) {
    TLobby__sub_803CBEC8((int) (*(s32 *)((s8 *)arg0 + 0xC)));
}
