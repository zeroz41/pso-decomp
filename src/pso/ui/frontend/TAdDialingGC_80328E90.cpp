#include "types.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/unk/TUnk_804ED7D0.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 is_handle_valid__10TObjPlayerFv();
s32 TLobby__sub_802A5154();

extern s32 TAdDialingGC__instance;

void TAdDialingGC::close() {
    TLobby::free_dialing_gc();
    TLobby::free_dialog_global();
    TAdDialingGC__instance = 0;
}

void TAdDialingGC::open() {
    TAdDialingGC__instance = 0;
    TLobby__sub_802A0F70();
    TLobby__sub_802A5154();
}

int TUnk_804ED7D0::vfunc_30() {
    s32 t = is_handle_valid__10TObjPlayerFv();
    s32 r = 2;
    if (t == 2) {
        r = 5;
    }
    return r;
}

int TUnk_804ED7D0::vfunc_22() {
    s32 t = is_handle_valid__10TObjPlayerFv();
    s32 r = 1;
    if (t == 2) {
        r = 4;
    }
    return r;
}

int TUnk_804ED7D0::vfunc_23() {
    return ((is_handle_valid__10TObjPlayerFv() - 2) == 0) ? 3 : 0;
}

}
