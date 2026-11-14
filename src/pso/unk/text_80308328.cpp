#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/ui/frontend/TAdVIConfigGC_80308200.h"
#include "pso/weapon/TUnk_804E71F8.h"
#include "pso/ui/frontend/TAdVIConfigGC.h"

void TUnk_804E71F8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->pad_74 = (void *)spawn_nug2000_hit_explosion;
    desc->pad_70 = (void *)TAdVIConfigGC::apply_config_if_valid;
    desc->pad_50 = -0x4000;
    desc->pad_78 = 0x1bb;
    desc->pad_7c = 0x1bc;
    desc->flags |= 0x80;
}

void TUnk_804E71F8::emit_marker_effects() {
    s32 sp8;
    get_joint_position(1, &sp8);
    fire_shot_at_target(&sp8, second_model, 0);
}
