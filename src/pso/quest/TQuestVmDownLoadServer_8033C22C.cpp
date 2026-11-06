#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/TAdPlayerLoadGC.h"
#include "pso/system/save/TCheckMemoryCard.h"
#include "pso/ui/window/TWindowSubComCard.h"

void TQuestVmDownLoadServer::init_from_keyboard_state() {
    s32 var_r31;
    s32 var_r6;

    if (TKeyBoardControl__sub_8000F8EC() == 0xF) {
        var_r31 = TQuestVmDownLoadServer__sub_8006EF6C(0xA);
        var_r6 = TQuestVmDownLoadServer__sub_8006EF6C(0xE);
        init((void*)var_r31, (void*)(-2), (void*)var_r6, (void*)0);
        return;
    }
    var_r31 = TQuestVmDownLoadServer__sub_8006EF6C(0x62);
    var_r6 = TQuestVmDownLoadServer__sub_8006EF6C(0xE);
    if (*(s32 *)((s8 *)this + 0x28) & 0x20) {
        var_r31 = TQuestVmDownLoadServer__sub_8006EF6C(0x6D);
        var_r6 = TQuestVmDownLoadServer__sub_8006EF6C(0xE);
    }
    init((void*)var_r31, (void*)(-2), (void*)var_r6, (void*)0);
}
