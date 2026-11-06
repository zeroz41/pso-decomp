#include "types.h"
#include "pso/ui/city/TShopJudgmentItemWindow_8026DF00.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/city/TShopJudgmentItemWindow.h"

extern "C" {
u8 *__nw__7TObjectFUl(int);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);
u8 *construct_item_list__20TWindowSubStatusDispFlls(u8 *, s32, s32, s32);
extern s32 TShopJudgmentItemWindow__item_list_rect_table[];
extern s32 local_client_id;

u8 *create_item_list_window(s32 arg0, s32 arg1, s32 arg2) {
    s32 camera_id;
    u8 *var_r0;
    camera_id = TCameraCtrl::get_camera_id();
    switch (camera_id) {
    case 1:
        TShopJudgmentItemWindow__sub_80267F9C(TShopJudgmentItemWindow__item_list_rect_table, arg1);
        break;
    case 2:
        TShopJudgmentItemWindow__sub_80267F9C((void *) ((u8 *)TShopJudgmentItemWindow__item_list_rect_table + 8), arg1);
        break;
    case 3:
    case 4:
        TShopJudgmentItemWindow__sub_80267F9C((void *) ((u8 *)TShopJudgmentItemWindow__item_list_rect_table + 0x10), arg1);
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
