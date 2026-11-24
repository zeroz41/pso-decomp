#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"

#include "pso/network/TLobby.h"


void *TLobby::create_dialing_message_window(void *message, void *delay) {
    void *o;
    o = (void *)new TAdDialingMessageWindow((const char *)message, (u32)delay);
    return o;
}

