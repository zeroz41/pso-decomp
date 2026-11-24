#include "types.h"
#include "pso/object/ambient/TObjMistCtrl.h"
#include "pso/network/TLobby.h"


void *TLobby::create_mist_ctrl(void *parent, void *set_data) {
    void *o;
    o = (void *)new TObjMistCtrl((saddr)parent, (uaddr)set_data);
    return o;
}
