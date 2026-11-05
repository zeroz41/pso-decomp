#include "types.h"
#include "pso/item/TUnk_804A2770.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 __vt__13TUnk_804A2770[];

TUnk_804A2770::~TUnk_804A2770() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TObjPlayer__sub_80125F24(void *arg0) {
    __ct__11TItemWeaponFP7TObjectPUc(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804A2770;
    return arg0;
}

}
