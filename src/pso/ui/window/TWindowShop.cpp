#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TUnk_804D0948.h"
#include "pso/unk/TLobby.h"

#pragma readonly_strings on

extern "C" {

s32 ensure_status_display__19TWindowMenuIconLineFl();

const char *lbl_805D39D0 = "TWindowShop";

void TUnk_804D0948::sub_8026DE94() {
    this->m_name = lbl_805D39D0;
    ensure_status_display__19TWindowMenuIconLineFl();
    create_menu_scroll_bar();
    this->set_depth(39000.0f);
    if (TCameraCtrl::get_camera_id() > 2) {
        set_position_xy(0.75f, 0.75f);
    }
    *(s32 *)&this->unk_88 = 0;
}

}
