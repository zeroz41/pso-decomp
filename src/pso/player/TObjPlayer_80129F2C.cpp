#include "types.h"
#include "pso/player/TUnk_804A4648.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void construct_srank_weapon(void *);

extern s32 s_rank_needle_weapon_vtable[];
extern s32 spawn_target_needle[];
extern s32 spawn_needle_wall_impact[];
extern s32 create_shoot_model__10TObjPlayerFUiiif[];

void *TUnk_804A4648::enter_state_2() {
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = s_rank_needle_weapon_vtable;
    ((TItemWeapon *)this)->set_weapon_flags(2);
    (*(s32 * *)((u8 *)this + 0x1F4)) = spawn_target_needle;
    (*(s32 * *)((u8 *)this + 0x1EC)) = spawn_needle_wall_impact;
    *(s32 **)((s8 *)this + 0x1F0) = create_shoot_model__10TObjPlayerFUiiif;
    return this;
}

}
