#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/TProtocol.h"


extern s32 info_board_state_flags;
extern u32 information_board_response_buffer;


void TLobby::init_once_data(u32 arg0) {
    if ((u32) information_board_response_buffer == 0U) {
        information_board_response_buffer = arg0;
        info_board_state_flags &= 0xFFFFFFFD;
        if (protocol_instance != NULL) {
            protocol_instance->send_info_board_request();
        }
    }
}

void TLobby::flush_pending_send() {
    if (info_board_state_flags & 1) {
        if (protocol_instance != NULL) {
            protocol_instance->send_text_packet_D9((char *)(TLobby::get_card_window_field()));
        }
        info_board_state_flags &= 0xFFFFFFFE;
    }
}

saddr TLobby::get_card_window_field() {
    return get_character_save_record(0xFFFF) + 0x20FC;
}
void TLobby::set_info_board_text() {
    saddr arg0 = (saddr)this;
    u8 *temp_r31;
    temp_r31 = (u8 *)(get_character_save_record((0xFFFFU)) + 0x20FC);
    TWindowSubComCard::mask_profanity_words((char *)arg0, (char *)get_shared_text_buffer());
    strncpy((char *)temp_r31, (char *)get_shared_text_buffer(), 0xAB);
    *(s8 *)((s8 *)temp_r31 + 0xAB) = 0;
    info_board_state_flags |= 1;
}
void TLobby::reset_info_board() { (*(int *)&info_board_state_flags) = 0; (*(int *)&information_board_response_buffer) = 0; }
