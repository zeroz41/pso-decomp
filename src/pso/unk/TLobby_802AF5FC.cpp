#include "types.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/unk/TLobby.h"

extern "C" {


void *TLobby::create_mist_ctrl(void *arg0, void *arg1) {
    void *o;
    o = (void *)new TObjMistCtrl((s32)arg0, (u32)arg1);
    return o;
}

}
