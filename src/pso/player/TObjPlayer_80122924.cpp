#include "types.h"
#include "pso/item/TUnk_804A1190.h"
#include "pso/unk/text_80087278.h"
#include "pso/player/TObjPlayer.h"

void TUnk_804A1190::emit_marker_effects() {
    s32 sp8[6];
    s32 arg0 = (s32)this;

    ((TItemWeapon *)arg0)->get_joint_position(1, sp8);
    spawn_particle_effect(sp8, 0xC1);
}
