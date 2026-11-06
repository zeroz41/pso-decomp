#include "types.h"
#include "pso/player/TPlayerBattleCtrl4P.h"

s32 TPlayerBattleCtrl4P::get_state() { return *(s32 *)&this->m_name; }
void TPlayerBattleCtrl4P::set_battle_mode(s32 v) { *(s32 *)&this->m_down = v; }
