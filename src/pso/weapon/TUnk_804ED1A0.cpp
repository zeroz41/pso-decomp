#include "types.h"
#include <stddef.h>
#include "pso/weapon/TUnk_804ED1A0.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/unk/text_80120908.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804ED1A0::update_weapon() {
    refresh_owner_stats();
}

void TUnk_804ED1A0::reserved_53() {
    draw_weapon_at_joint((s32)this, 0x30);
    update_trail_slot(0);
    update_trail_slot(1);
    update_trail_slot(2);
}

TUnk_804ED1A0::TUnk_804ED1A0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_trail_joints((s32)this, 2, 6, 5);
    set_weapon_flags(1);
}

u8 *create_morning_glory(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804ED1A0(tl_05, arg0);
    }
    return NULL;
}
