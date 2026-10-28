#include "types.h"
#include "pso/player/TUnk_804A1C38.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);
void __ct__11TItemWeaponFP7TObjectPUc(void *);

void TUnk_804A1C38::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot(0); update_trail_slot(1); }

extern s32 lbl_804A1C38[];

void *TUnk_804A1C38::set_vtable_mode1() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A1C38;
    set_weapon_flags(1);
    return this;
}

}
