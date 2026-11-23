#include "types.h"
#include "pso/ui/window/TWindowMainMenu_8024E3CC.h"
#include "pso/unk/text_8026ACDC.h"
#include "pso/ui/window/TWindowCtrl.h"


void TWindowCtrl::close() {
    TWindowMainMenu__sub_8024E3D0();
    TLobby__sub_8026ACDC();
    instance = NULL;
}
