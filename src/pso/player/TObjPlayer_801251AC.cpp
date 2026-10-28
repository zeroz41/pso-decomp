#include "types.h"
#include "pso/item/TUnk_804A2358.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TTecFoie.h"

extern "C" {

s32 is_mode_two_and_ready__10TObjPlayerFv();
int update_trail_slot__11TItemWeaponFPvi(void*, void*);
void draw_weapon_at_joint(s32 arg0, s8 arg1);

s16 TObjPlayer::get_stage_strike_count() { return *(s16*)((char*)this + 0x12); }
void TUnk_804A2358::emit_marker_effects() {
    s32 sp8;
    void *owner;

    if (is_mode_two_and_ready__10TObjPlayerFv() != 0) {
        if (((TObjPlayer *)this)->draw_icon(0, (s32)&sp8) != 0) {
            owner = this->owner;
            TTecFoie::create((void *)owner, &sp8, (void *)(*(s32 *)((s8 *)owner + 0x60)), (void *)(((TObjPlayer *)this)->get_tp() + 2));
            ((TItemWeapon *)this)->roll_technique();
        }
    } else {
        ((TObjPlayer *)this)->update_active_game_effect();
    }
}
void TUnk_804A2358::reserved_53() { draw_weapon_at_joint((s32)this, (s8)((void*)49)); update_trail_slot__11TItemWeaponFPvi(this, (void*)0); update_trail_slot__11TItemWeaponFPvi(this, (void*)1); update_trail_slot__11TItemWeaponFPvi(this, (void*)2); }
void TObjPlayer::apply_11e618_twice() { ((TItemWeapon *)this)->roll_technique(); ((TItemWeapon *)this)->roll_technique(); }

}
