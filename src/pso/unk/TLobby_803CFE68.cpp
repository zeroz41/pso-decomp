#include "types.h"
#include "pso/unk/TLobby_803CFE68.h"
#include "pso/unk/TLobby.h"

extern s32 (*cvfs_completion_callback)(s32);

extern s32 lbl_805D75FC;

void TLobby::call_callback() {
    if (((s32 (*)(s32)) cvfs_completion_callback) != NULL) {
        cvfs_completion_callback(lbl_805D75FC);
    }
}

void TLobby__sub_803CFE9C(void) {

}
