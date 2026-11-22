#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"

extern "C" {

s32 TLobby__sub_80077798(s32, s32 *);

extern saddr TLobby__protocol_instance;

void TLobby::send_packet(s32 arg0, s32 src) {
    s32 sp8[4];

    TLobby__sub_80077798(src, sp8);
    ((TProtocol *)TLobby__protocol_instance)->send_choice_search((ChoiceSearchParameters &)sp8);
}

}
