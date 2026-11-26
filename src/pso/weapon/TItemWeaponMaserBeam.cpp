#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TItemWeaponMaserBeam.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/player/TargetCursorList.h"


void TItemWeaponMaserBeam::emit_marker_effects() {
    CapturedTarget *item;
    saddr kind;
    CapturedTargetList *ext;
    s32 i;
    Vec buf;
    switch (owner->is_status_subsystem_ready()) {
    case 1:
        kind = 8;
        break;
    case 0:
        kind = 3;
        break;
    default:
        kind = 8;
        break;
    }
    if (get_joint_position(1, &buf) != 0) {
        ext = owner->get_extended_state();
        if (ext != 0) {
            for (i = 0; i != ext->get_captured_target_count(); i++) {
                item = ext->get_captured_target_entry(i);
                if (item != NULL) {
                    TargetCursorList targets;
                    targets.count = 1;
                    targets.records[0].id = item->uid;
                    targets.records[0].flag = item->collider_index;
                    TTecGiZonde::create(owner, &buf, &targets, kind);
                }
            }
        }
    }
}

TItemWeaponMaserBeam::~TItemWeaponMaserBeam() {}

TItemWeaponMaserBeam::TItemWeaponMaserBeam(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *TItemWeaponMaserBeam::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponMaserBeam(tl_05, item);
    }
    return NULL;
}
