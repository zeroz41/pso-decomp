#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TItemDisconnectCtrl_80105BE8.h"
#include "pso/item/TItemDisconnectCtrl.h"
#include "pso/player/TObjPlayer.h"

    extern int lbl_805D54E0;
void TItemDisconnectCtrl__sub_80105BE8(void) { lbl_805D54E0 = 0; }

extern s32 lbl_805D5440;

void TItemDisconnectCtrl::init_forward() {
    __ct__8FlagWordFv((&lbl_805D5440));
}

__declspec(section ".ctors") static void *const __sinit_TItemDisconnectCtrl_80105BE8_cpp_ref = (void *)TItemDisconnectCtrl::init_forward;
