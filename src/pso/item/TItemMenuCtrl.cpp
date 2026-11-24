#include "pso/item/TItemMenuCtrl_80115A28.h"
#include "pso/item/TItemMenuCtrl.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

void * TItemMenuCtrl__instance;

TItemMenuCtrl::~TItemMenuCtrl() {
    TItemMenuCtrl__instance = 0;
}


const char *lbl_805D2C18 = "TItemMenuCtrl";

#define item_menu_ctrl ((u8 *)this)
TItemMenuCtrl::TItemMenuCtrl(TObject *parent) : TObject(parent) {
    __ct__8FlagWordFv(((char *)item_menu_ctrl + 28));
    TItemMenuCtrl__instance = item_menu_ctrl;
    ((TItemMenuCtrl *)item_menu_ctrl)->m_name = lbl_805D2C18;
}
#undef item_menu_ctrl
