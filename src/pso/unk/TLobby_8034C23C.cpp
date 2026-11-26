#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/network/TProtocol.h"


extern s32 info_board_state_flags;
extern TRecvInfoBoard *information_board_response_buffer;


void TLobby::request_info_board(TRecvInfoBoard *buffer) {
    if (information_board_response_buffer == NULL) {
        information_board_response_buffer = buffer;
        info_board_state_flags &= 0xFFFFFFFD;
        if (protocol_instance != NULL) {
            protocol_instance->send_info_board_request();
        }
    }
}

void TLobby::flush_pending_send() {
    if (info_board_state_flags & 1) {
        if (protocol_instance != NULL) {
            protocol_instance->send_text_packet_D9(TLobby::get_info_board_text());
        }
        info_board_state_flags &= 0xFFFFFFFE;
    }
}

char *TLobby::get_info_board_text() {
    return ((CharacterSaveRecord *)get_character_save_record(0xFFFF))->info_board_text;
}
void TLobby::set_info_board_text(char *text) {
    char *board_text;
    board_text = ((CharacterSaveRecord *)get_character_save_record(0xFFFFU))->info_board_text;
    TWindowSubComCard::mask_profanity_words(text, (char *)get_shared_text_buffer());
    strncpy(board_text, (char *)get_shared_text_buffer(), 0xAB);
    board_text[0xAB] = 0;
    info_board_state_flags |= 1;
}
void TLobby::reset_info_board() { (info_board_state_flags) = 0; (information_board_response_buffer) = 0; }
