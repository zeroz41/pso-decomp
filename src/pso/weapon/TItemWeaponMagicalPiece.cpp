#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponMagicalPiece.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TargetCursorList.h"
#include "pso/player/CapturedTargetList.h"

extern "C" {
void TItemWeaponMagicalPiece::emit_marker_effects() {
    u8 pos[12];
    CapturedTargetList *st;
    get_joint_position(2, pos);
    spawn_particle_effect((const Vec *)pos, 0x1BE);
    get_joint_position(3, pos);
    spawn_particle_effect((const Vec *)pos, 0x1BE);
    get_joint_position(0, pos);
    if (owner->is_status_subsystem_ready() == 2) {
        if (is_identified() == 1) {
            st = owner->get_extended_state();
            if (st->get_captured_target_count() != 0) {
                CapturedTarget *e = st->get_captured_target_entry(0);
                TargetCursorList targets;
                targets.count = 1;
                targets.records[0].id = e->get_uid();
                targets.records[0].flag = e->get_captured_target_collider_index();
                TObjPlayer::create_tec_zonde(owner, pos, &targets, 3);
            }
        }
    } else {
        ((TItemWeapon *)this)->update_active_game_effect();
    }
}

}

TItemWeaponMagicalPiece::TItemWeaponMagicalPiece(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(34);
}


TItem *TItemWeaponMagicalPiece::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMagicalPiece(tl_05, item);
    }
    return NULL;
}

TItemWeaponMagicalPiece::~TItemWeaponMagicalPiece() {}
