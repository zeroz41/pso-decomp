#include "types.h"
#include "pso/unk/text_80127EE8.h"
#include "pso/item/TUnk_804A3830.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/TUnk_804A3928.h"
#include "pso/TMainTask.h"

extern "C" {
s32 draw_weapon_at_joint(void *, int);
}


void TUnk_804A3830::reserved_53() {
    s32 temp_r31;
    draw_weapon_at_joint(this, 0x31);
    update_trail_slot(0);
    update_trail_slot(1);
    temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0xF4);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = (s32) this->second_model;
    draw_weapon_at_joint(this, 0x24);
    *(s32 *)((s8 *)((u8 *)this) + 0xF4) = temp_r31;
    update_trail_slot(2);
    update_trail_slot(3);
}

TUnk_804A3830::~TUnk_804A3830() {}

TUnk_804A3830::TUnk_804A3830(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints((s32)this, 2, 1, 2);
    set_weapon_trail_joints((s32)this, 3, 3, 4);
    set_weapon_flags(513);
}

u8 *TObjPlayer::create_state_variant(u8 *item) {
    if (item != NULL) {
        return (u8 *)new TUnk_804A3830(tl_05, item);
    }
    return NULL;
}
