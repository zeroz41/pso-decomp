#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"

#include "pso/unk/TLobby.h"


void *TLobby::create_dialing_message_window(void *arg0, void *arg1) {
    void *o;
    o = (void *)new TAdDialingMessageWindow(arg0, arg1);
    return o;
}

