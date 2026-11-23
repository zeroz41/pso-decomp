#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"

extern "C" {

s32 TLobby__sub_80077798(s32, s32 *);


void TLobby::send_packet(s32 arg0, s32 src) {
    s32 parameters[4];

    TLobby__sub_80077798(src, parameters);
    protocol_instance->send_choice_search((TPlyChoiceSearchConfig &)parameters);
}

}
