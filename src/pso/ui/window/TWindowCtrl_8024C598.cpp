#include "pso/ui/window/TWindowCtrl_8024A1A8.h"
#include "pso/ui/chat/TWindowChat.h"
#include "types.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowFukidasi.h"

int TWindowCtrl::is_flag_2_set() { return this->m_flags & 0x4; }
void TWindowCtrl::set_flag1e_bit8() { this->m_1e |= 0x8; }
void TWindowCtrl::clear_flag1e_bit8() { this->m_1e &= 0xfffffff7; }

extern "C" {
s32 TWindowCtrl__sub_8024C5C4(const TWindowChat *chat) {
    if (chat->flags & 2) return 0;
    return 1;
}

void TWindowCtrl::set_flag1e_bit40() { this->m_1e |= 0x40; }
u16 TWindowFukidasi::get_speaker_id() { return this->m_76; }
int TWindowFukidasi::get_flag_bit1() { return ((this->m_71) >> 1) & 0x1; }

}
