#include "types.h"
#include "pso/TMainTask.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/unk/text_80145A94.h"
#include "pso/ui/TAdScrollWinGC.h"

extern "C" {

void TAdScrollWinGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); render_status_value(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }
s32 TAdScrollWinGC::get_scroll_delay_for_mode() {
    TAdScrollWinGC *arg0 = this;
    s32 r = 0;
    switch (arg0->m_44) {
    case 0:
        if (TLobby__sub_80145DB4(4) != 0) {
            r = 0x14;
        } else {
            r = 0;
        }
        break;
    case 1:
        r = 0xA;
        break;
    case 2:
        r = -1;
        break;
    }
    return r;
}

}
