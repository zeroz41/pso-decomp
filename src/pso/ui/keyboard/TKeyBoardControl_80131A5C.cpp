#include "types.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

extern "C" {


void TKeyBoardControl::set_flag62_bit2() { m_base->set_flag62_bit2(); }

void TKeyBoardControl::set_depth(f32 depth) { m_base->set_depth(depth); }

}
