#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A1380.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecFoie.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A1380::emit_marker_effects() {
    s32 origin;
    TObjPlayer *owner;

    get_joint_position(2, &origin);
    spawn_particle_effect((const Vec *)&origin, 0x1BF);
    if (is_mode_two_and_ready() != 0) {
        owner = this->owner;
        TTecFoie::create(owner, &origin, *(saddr *)((s8 *)owner + 0x60), 3);
        return;
    }
    ((TItemWeapon *)this)->update_active_game_effect();
}

TUnk_804A1380::TUnk_804A1380(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}

TItem *TObjPlayer::create_obj_80122C2C(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A1380(tl_05, item);
    }
    return NULL;
}

TUnk_804A1380::~TUnk_804A1380() {}
