#include "types.h"
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubComCard.h"

extern "C" {
s32 strncpy(int, int, int);
extern s32 info_board_state_flags;
extern u32 information_board_response_buffer;
s32 send_info_board_request__9TProtocolFv(u32);

extern u32 TLobby__protocol_instance;

void TLobby::init_once_data(u32 arg0) {
    if ((u32) information_board_response_buffer == 0U) {
        information_board_response_buffer = arg0;
        info_board_state_flags &= 0xFFFFFFFD;
        if ((u32) TLobby__protocol_instance != 0U) {
            send_info_board_request__9TProtocolFv(TLobby__protocol_instance);
        }
    }
}

void TLobby::flush_pending_send() {
    if (info_board_state_flags & 1) {
        if ((u32) TLobby__protocol_instance != 0U) {
            ((TLobby *)TLobby__protocol_instance)->send_text_packet_D9((char *)(TLobby::get_card_window_field()));
        }
        info_board_state_flags &= 0xFFFFFFFE;
    }
}

s32 TLobby::get_card_window_field() {
    return get_character_save_record(0xFFFF) + 0x20FC;
}
void TLobby::set_info_board_text() {
    s32 arg0 = (s32)this;
    u8 *temp_r31;
    temp_r31 = (u8 *)(get_character_save_record((0xFFFFU)) + 0x20FC);
    TWindowSubComCard::mask_profanity_words((char *)arg0, (char *)get_shared_text_buffer());
    strncpy((int)temp_r31, (int) (get_shared_text_buffer()), 0xAB);
    *(s8 *)((s8 *)temp_r31 + 0xAB) = 0;
    info_board_state_flags |= 1;
}
void TLobby::reset_info_board() { (*(int *)&info_board_state_flags) = 0; (*(int *)&information_board_response_buffer) = 0; }

}
