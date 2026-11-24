#include "types.h"
#include "pso/weapon/TItemWeaponNug2000Bazooka.h"
#include "pso/ui/frontend/TAdVIConfigGC_80308200.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponNug2000Bazooka::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->hit_effect = (void *)spawn_nug2000_hit_explosion;
    desc->wall_effect = (void *)TAdVIConfigGC::apply_config_if_valid;
    desc->spin[0] = -0x4000;
    desc->particle = 0x1bb;
    desc->trail_particle = 0x1bc;
    desc->flags |= 0x80;
}

void TItemWeaponNug2000Bazooka::emit_marker_effects() {
    s32 origin;
    get_joint_position(1, &origin);
    fire_shot_at_target(&origin, second_model, 0);
}

TItemWeaponNug2000Bazooka::TItemWeaponNug2000Bazooka(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}

TItem *create_nug2000_bazooka(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponNug2000Bazooka(tl_05, item);
    }
    return NULL;
}

TItemWeaponNug2000Bazooka::~TItemWeaponNug2000Bazooka() {}
