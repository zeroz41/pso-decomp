#include "types.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/misc/TWindowSubTradeMain.h"

extern "C" {

int set_depth__11TWindowBaseFf(void*);
int set_flag62_bit2__16TKeyBoardControlFv(void*);

int TWindowMakeTeam::set_keyboard_flag62_bit2() { return set_flag62_bit2__16TKeyBoardControlFv(*(void* *)&this->m_20); }

int TWindowMakeTeam::get_lobby_field_20() { return set_depth__11TWindowBaseFf(*(void* *)&this->m_20); }

}
