#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponChainSawd.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TMainTask.h"

void TItemWeaponChainSawd::emit_marker_effects() {
    Vec pos;

    get_joint_position(2, &pos);
    pos.y -= 15.0f;
    spawn_particle_effect(&pos, 0x1D2);
}

void TItemWeaponChainSawd::update_weapon() {
    NJS_OBJECT *model;

    model = item_model;
    if (model != NULL) {
        scroll_item_model_uvs(model->child, uv_scroll, 0, 0);
    }
}

TItemWeaponChainSawd::TItemWeaponChainSawd(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    uv_scroll = 35;
}

TItem *TItemWeaponChainSawd::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponChainSawd(tl_05, item);
    }
    return NULL;
}
