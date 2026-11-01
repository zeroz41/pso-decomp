#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubInformationBoard.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct RecoveredGlobal_8034CC68_lbl_80478C3C {
    s32 value;
    u8 remaining[0x8];
};

extern const RecoveredGlobal_8034CC68_lbl_80478C3C lbl_80478C3C;

extern "C" {

s32 TKeyBoardControl__ct(s32, s32, s32, s32, s32, s32);
s32 get_info_board_ptr__6TLobbyFv();
s32 get_window_layout_position(s32);
s32 __nw__7TObjectFUl(s32);
s32 get_keyboard_field_6c__15TWindowMakeTeamFv(s32, s32);

void TWindowSubInformationBoard::set_page(s32 arg1) {
    s32 temp_r3;

    if (((s32) this->m_24 != arg1) && (arg1 != -1)) {
        temp_r3 = get_info_board_ptr__6TLobbyFv();
        if (temp_r3 != 0) {
            this->m_24 = arg1;
            ((TWindowMessage *)(this->m_34))->append_line(temp_r3 + (arg1 * 0xBC) + 0x14, 0x80);
        }
    }
}

extern s32 local_client_id;

typedef char RecoveredGlobal_8034CC68_lbl_80478C3C_size[sizeof(RecoveredGlobal_8034CC68_lbl_80478C3C) == 0xC ? 1 : -1];
void TWindowSubInformationBoard::set_message_index(s32 arg1) {
    if ((s32) this->m_24 != arg1) {
        this->m_24 = arg1;
        ((TWindowMessage *)(this->m_34))->append_line((s32)(TWindowSubStatusDisp::get_message_10((int) (*(s32 *)((s8 *)&lbl_80478C3C.value + (arg1 * 4))))), 0x80);
    }
}

s32 TWindowSubInformationBoard::open_keyboard(s32 arg0) {
    s32 keyboard;

    keyboard = __nw__7TObjectFUl(0x2C);
    if (keyboard != 0) {
        keyboard = TKeyBoardControl__ct(keyboard, arg0, 0xC6, 5, 4, local_client_id);
    }
    get_keyboard_field_6c__15TWindowMakeTeamFv(keyboard, TLobby::get_card_window_field());
    ((TWindowMakeTeam *)keyboard)->set_sub_position((u8 *)(get_window_layout_position(0xBB)));
    ((TWindowMakeTeam *)keyboard)->set_keyboard_flag62_bit2();
    ((TWindowSubComCard *)keyboard)->destroy_keyboard();
    return keyboard;
}

extern s32 lbl_80478C34[];

void TWindowSubInformationBoard::show_card_a7() {
    s32 window_layout_position;
    window_layout_position = get_window_layout_position(0xA7);
    TWindowMessage::create((void *)window_layout_position, (s32)lbl_80478C34, 1);
    this->m_24 = -1;
}

}
