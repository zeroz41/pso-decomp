#include "types.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"

int TWindowKeyBoardBase::sub_8025EB68() { return (this->m_60 >> 3) & 0x1; }

int test_keyboard_card_flag_128(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 128); }
int test_keyboard_card_flag_64(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 64); }
int test_keyboard_card_flag_32(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 32); }
int test_keyboard_card_flag_16(s32 client) { return TWindowKeyBoardHard::test_card_flag(client, 16); }
