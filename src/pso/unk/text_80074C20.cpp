#include "types.h"
#include "pso/unk/text_80074BD0.h"
#include "pso/unk/text_80074C70.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
struct Lobby_80074C20 { u8 pad[0xBC88]; void *cb; };

extern Lobby_80074C20 *TLobby__protocol_instance;
s32 TLobby::start_lobby_name_request() {
    fn_80074C70();
    if (TLobby__protocol_instance == 0) {
        return 0;
    }
    TLobby__protocol_instance->cb = (void *)fn_80074BD0;
    ((TProtocol *)TLobby__protocol_instance)->send_lobby_name_request();
    return 1;
}
