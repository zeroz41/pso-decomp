#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TUnk_804D0948.h"
#include "pso/misc/TLobby.h"

extern "C" {

s32 ensure_status_display__19TWindowMenuIconLineFl();

extern s32 lbl_805D39D0;
extern f32 lbl_805DD340;
extern f32 lbl_805DD344;

void TUnk_804D0948::sub_8026DE94() {
    *(s32 *)&this->m_name = (s32) lbl_805D39D0;
    ensure_status_display__19TWindowMenuIconLineFl();
    create_menu_scroll_bar();
    this->set_depth(lbl_805DD340);
    if (TCameraCtrl::get_camera_id() > 2) {
        set_position_xy(lbl_805DD344, lbl_805DD344);
    }
    *(s32 *)&this->unk_88 = 0;
}

}
