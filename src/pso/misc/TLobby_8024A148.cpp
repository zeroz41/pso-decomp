#include "types.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/misc/TLobby.h"
#include "pso/network/TProtocol.h"

extern "C" {

s32 TLobby__sub_80077798(s32, s32 *);
s32 open_hard_keyboard__6TLobbyFPv(s32);

extern s32 local_client_id;
extern s32 TLobby__protocol_instance;

void TLobby::send_card_window_state() {
    s32 sp8[5];
    s32 character_save_record;

    character_save_record = get_character_save_record(0xFFFF);
    sp8[0] = open_hard_keyboard__6TLobbyFPv(local_client_id) ? 1 : 0;
    TLobby__sub_80077798(character_save_record + 0x22EC, sp8);
    ((TProtocol *)TLobby__protocol_instance)->send_choice_search_parameters((ChoiceSearchParameters &)sp8);
}

}
