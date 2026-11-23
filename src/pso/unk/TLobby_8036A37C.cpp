#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"

#include "pso/unk/TLobby.h"


void *TLobby::create_dialing_message_window(void *arg0, void *delay) {
    void *o;
    o = (void *)new TAdDialingMessageWindow((const char *)arg0, (u32)delay);
    return o;
}

