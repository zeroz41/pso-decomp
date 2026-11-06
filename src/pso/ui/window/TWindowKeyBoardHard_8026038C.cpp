#include "types.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"

void TWindowKeyBoardHard::set_bits_shift7(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 7), -0x81);
}
void TWindowKeyBoardHard::update_card_window_page_flags(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 6), -0x41);
}
void TWindowKeyBoardHard::clear_card_window_flag(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 4), -0x11);
}
void TWindowKeyBoardHard::set_card_window_flag(s32 arg0, s32 arg1) {
    TWindowKeyBoardHard::set_card_window_flags((void *)arg0, (s32)(arg1 << 5), -0x21);
}
int TWindowKeyBoardHard::sub_8026042C() { return (this->m_60 >> 6) & 0x1; }
int TWindowKeyBoardHard::sub_80260438() { return (this->m_60 >> 10) & 0x1; }
int TWindowKeyBoardHard::is_key_active() { return this->m_60 & 0x200; }
