#include "types.h"
#include "pso/player/TObjPlayer_8012D620.h"

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 lbl_804A5930[];

void *TObjPlayer__sub_8012D620(void *arg0) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A5930;
    return arg0;
}

}
