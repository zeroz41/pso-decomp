#include "types.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

extern "C" {


void TKeyBoardControl::set_flag62_bit2() { ((TWindowKeyBoardBase *)m_20)->set_flag62_bit2(); }

void TKeyBoardControl::set_depth(f32 depth) { ((TWindowBase *)m_20)->set_depth(depth); }

}
