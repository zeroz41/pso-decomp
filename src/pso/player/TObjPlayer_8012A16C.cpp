#include "types.h"
#include "pso/item/TUnk_804A4748.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void construct_srank_weapon(void *);

extern s32 s_rank_psychogun_weapon_vtable[];
extern s32 create_gun_shot[];
extern s32 spawn_weapon_impact_effect[];

void *TUnk_804A4748::setup_action() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = s_rank_psychogun_weapon_vtable;
    ((TItemWeapon *)this)->set_weapon_flags(547);
    *(s32 **)((s8 *)this + 0x1F0) = create_gun_shot;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_weapon_impact_effect;
    return this;
}

}
