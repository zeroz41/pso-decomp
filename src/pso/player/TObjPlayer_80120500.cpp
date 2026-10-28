#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"

void TItemWeapon::remove_owner_bonuses() {
    s32 i;
    void *temp_r3;

    ((TObjPlayer *)(this->owner))->set_model_id(0);
    ((TObjPlayer *)(this->owner))->set_model_param(0);
    i = 0;
    do {
        temp_r3 = ((TObjPlayer *)(this->owner))->get_attribute_entry(i);
        *(s8 *)((s8 *)temp_r3 + 0) = 0;
        i += 1;
        *(s8 *)((s8 *)temp_r3 + 1) = 0;
    } while (i != 3);
}
