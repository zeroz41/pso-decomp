#include "types.h"
#include "pso/item/TUnk_804A2358.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012105C.h"

extern "C" {

void draw_weapon_at_joint(s32 arg0, s8 arg1);

void TUnk_804A2358::emit_marker_effects() {
    s32 sp8;
    void *owner;

    if (is_mode_two_and_ready() != 0) {
        if (get_joint_position(0, &sp8) != 0) {
            owner = this->owner;
            TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)(((TObjPlayer *)this)->get_tp() + 2));
            roll_technique();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}
void TUnk_804A2358::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot(0); update_trail_slot(1); update_trail_slot(2); }
void TUnk_804A2358::vfunc_57() { ((TItemWeapon *)this)->roll_technique(); ((TItemWeapon *)this)->roll_technique(); }

}

extern s32 __vt__13TUnk_804A2358[];

TUnk_804A2358::~TUnk_804A2358() {}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);


void *TObjPlayer::init_and_configure() {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A2358;
    set_weapon_trail_joints((s32)this, 2, 6, 5);
    ((TItemWeapon *)this)->set_weapon_flags(35);
    set_effect_state(13);
    return this;
}

}

extern "C" {
u8 * init_and_configure__10TObjPlayerFv(void *, s32, void *);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_configured_state(u8 *arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x1F8));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_and_configure__10TObjPlayerFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}
