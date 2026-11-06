#include "types.h"
#include "pso/item/TUnk_804A1B40.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/items/TItemWeapon.h"
#include "pso/TMainTask.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);

void TUnk_804A1B40::reserved_53() {
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0xF4);
    ((TItemWeapon *)this)->draw_weapon_model();
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = (s32) this->second_model;
    draw_weapon_at_joint((s32)this, 0x23);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = temp_r31;
}

}

TUnk_804A1B40::~TUnk_804A1B40() {}

TUnk_804A1B40::TUnk_804A1B40(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x800201);
}

extern "C" {
u8 *TObjPlayer__sub_80123950(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A1B40(tl_05, item);
    }
    return NULL;
}
}
