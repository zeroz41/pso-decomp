#include "types.h"
#include "pso/unk/text_80355C1C.h"
#include "pso/item/TItem.h"

extern "C" {
u8 * photon_field_weapon_ct(void *, s32, void *);
}
extern s32 tl_05;
u8 *create_photon_field_weapon(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)((u8 *)TItem::operator new(0x1FC));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(photon_field_weapon_ct(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}
