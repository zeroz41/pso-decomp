#include "types.h"
#include "pso/unk/TLobby_802A0F3C.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"

extern "C" {


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

}
