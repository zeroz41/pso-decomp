#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"

extern "C" {

s32 TLobby__sub_80077798(s32, s32 *);

extern s32 TLobby__protocol_instance;

void TLobby::send_packet(s32 arg0, s32 arg1) {
    s32 sp8[4];

    TLobby__sub_80077798(arg1, sp8);
    ((TProtocol *)TLobby__protocol_instance)->send_choice_search((ChoiceSearchParameters &)sp8);
}

}
