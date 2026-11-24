#include "pso/item/TItemMenuCtrl_80115A28.h"
#include "pso/item/TItemMenuCtrl.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

TItemMenuCtrl *TItemMenuCtrl__instance;

TItemMenuCtrl::~TItemMenuCtrl() {
    TItemMenuCtrl__instance = 0;
}


const char *lbl_805D2C18 = "TItemMenuCtrl";

TItemMenuCtrl::TItemMenuCtrl(TObject *parent) : TObject(parent) {
    TItemMenuCtrl__instance = this;
    m_name = lbl_805D2C18;
}
