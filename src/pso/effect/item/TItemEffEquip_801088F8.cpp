#include "types.h"
#include "pso/effect/item/TItemEffEquip_801088F8.h"

extern "C" {

s32 release_effect__13TItemEffEquipFv();

void TItemEffEquip__sub_801088F8(u32 arg0) {
    if (arg0 != 0U) {
        release_effect__13TItemEffEquipFv();
    }
}

}
