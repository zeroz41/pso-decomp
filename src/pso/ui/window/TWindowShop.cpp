#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TUnk_804D0948.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"
#include "pso/network/client_id.h"
#include "pso/system/NinjaTypes.h"

#pragma readonly_strings on

extern "C" {

s32 ensure_status_display__19TWindowMenuIconLineFl();
u8 *__nw__7TObjectFUl(int);
s32 TShopJudgmentItemWindow__sub_80267F9C(const void *, int);
u8 *construct_item_list__20TWindowSubStatusDispFlls(u8 *, s32, s32, s32);

const char *lbl_805D39D0 = "TWindowShop";

// Item list window position per camera id (1, 2, 3-4).
static const NJS_POINT2 TShopJudgmentItemWindow__item_list_rect_table[3] = {
    { 385.0f, 184.0f }, { 385.0f, 104.0f }, { 300.0f, 104.0f }
};

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

u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2) {
    s32 camera_id;
    u8 *var_r0;
    camera_id = TCameraCtrl::get_camera_id();
    switch (camera_id) {
    case 1:
        TShopJudgmentItemWindow__sub_80267F9C(&TShopJudgmentItemWindow__item_list_rect_table[0], arg1);
        break;
    case 2:
        TShopJudgmentItemWindow__sub_80267F9C(&TShopJudgmentItemWindow__item_list_rect_table[1], arg1);
        break;
    case 3:
    case 4:
        TShopJudgmentItemWindow__sub_80267F9C(&TShopJudgmentItemWindow__item_list_rect_table[2], arg1);
        break;
    }
    var_r0 = __nw__7TObjectFUl(0x8C);
    if (var_r0 != NULL) {
        var_r0 = construct_item_list__20TWindowSubStatusDispFlls(var_r0, arg0, arg1, arg2);
    }
    return var_r0;
}

void TShopJudgmentItemWindow::open_default(s32 a) {
    create_item_list_window(a, 0x40, local_client_id);
}

}
