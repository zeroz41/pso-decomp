#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/unk/TUnk_804ED7D0.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/unk/TLobby.h"

extern "C" {
void TLobby__sub_802A5154(void);


void TAdDialingGC::close() {
    TLobby::free_dialing_gc();
    TLobby::free_dialog_global();
    TAdDialingGC__instance = NULL;
}

void TAdDialingGC::open() {
    TAdDialingGC__instance = NULL;
    TLobby__sub_802A0F70();
    TLobby__sub_802A5154();
}

int TUnk_804ED7D0::vfunc_30() {
    s32 t = ((TObjPlayer *)this)->is_handle_valid();
    s32 r = 2;
    if (t == 2) {
        r = 5;
    }
    return r;
}

int TUnk_804ED7D0::vfunc_22() {
    s32 t = ((TObjPlayer *)this)->is_handle_valid();
    s32 r = 1;
    if (t == 2) {
        r = 4;
    }
    return r;
}

int TUnk_804ED7D0::vfunc_23() {
    return ((((TObjPlayer *)this)->is_handle_valid() - 2) == 0) ? 3 : 0;
}

}
