#include "pso/effect/item/TItemEffCane.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"

const char *TItemEffCane__class_name = "TItemEffCane";

void TItemEffCane::run_task() {
    f32 position[3];
    TItem* item = (TItem *)find_item_by_id(item_id);
    if (item == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (((TItem *)item)->get_mode() != 2 ||
        ((TItemWeapon *)item)->test_weapon_flags(0x10) == 0 || effect == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    ((TItemWeapon *)item)->get_joint_position(attachment_index, position);
    ((TParticleCtrl *)effect)->set_position(position);
}

TItemEffCane::~TItemEffCane() {
    TParticleCtrl::release(effect);
}

TItemEffCane::TItemEffCane(TObject* parent, TItem* item, s32 attachment, s32 effect_id)
    : TObject(parent) {
    f32 position[3];
    m_name = TItemEffCane__class_name;
    item_id = ((TItem *)item)->get_item_id();
    attachment_index = attachment;
    ((TItemWeapon *)item)->get_joint_position(attachment_index, position);
    if (effect_id != -1) {
        effect = create_particle_emitter(position, effect_id);
    } else {
        effect = NULL;
    }
    disallow_rendering__7TObjectFv(this);
}
