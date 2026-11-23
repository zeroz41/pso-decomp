#include "types.h"
// Status byte pair on the lobby stream object; the accessor exposes the second
// byte (callers compare it against 2 = ready, 3 = finished).
struct LobbyStreamStatus { u8 a; s8 status; };

extern "C" {
s32 TLobby__sub_803CE1F4(LobbyStreamStatus *self);
s32 TLobby__sub_803CE1F4(LobbyStreamStatus *self) {
    return self->status;
}

}
