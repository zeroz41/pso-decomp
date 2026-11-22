#include "types.h"
#include "pso/boss/olgaflow/TBoss6Type2_803309D8.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowMainMenu.h"

TBoss6Mag *TBoss6Type2::create_mag(TBoss6MagSpawnParams *params) {
    return new TBoss6Mag(new TObjControl(tl_04), params);
}

extern "C" {

// Called by TLobby::reset on the trade main window.
void fn_80330A40(TWindowSubTradeMain *window) {
    window->parent_menu->on_submenu_closed();
    window->m_1c = 0x22;
}

}
