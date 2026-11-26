#include "types.h"
#include "pso/ui/frontend/TAdDialingMessageWindow.h"

#include "pso/network/TLobby.h"


TAdDialingMessageWindow *TLobby::create_dialing_message_window(const char *message, u32 delay) {
    return new TAdDialingMessageWindow(message, delay);
}

