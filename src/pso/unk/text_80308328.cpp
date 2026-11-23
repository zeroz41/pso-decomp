#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/ui/frontend/TAdVIConfigGC_80308200.h"
#include "pso/weapon/TUnk_804E71F8.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

void TUnk_804E71F8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->hit_effect = (void *)spawn_nug2000_hit_explosion;
    desc->wall_effect = (void *)TAdVIConfigGC::apply_config_if_valid;
    desc->spin[0] = -0x4000;
    desc->particle = 0x1bb;
    desc->trail_particle = 0x1bc;
    desc->flags |= 0x80;
}

void TUnk_804E71F8::emit_marker_effects() {
    s32 origin;
    get_joint_position(1, &origin);
    fire_shot_at_target(&origin, second_model, 0);
}
