#include "types.h"
#include "pso/item/TItemEquipVariant_801286D0.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

extern s32 lbl_804A3D20[];

void *__dt__13TUnk_804A3D20Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A3D20;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}
