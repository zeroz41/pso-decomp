#include "pso/item/TItemFollowStarLight.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "types.h"

struct StarLightPosition { f32 x, y, z; };

struct WeaponStarLightParameterWords { u32 w[5]; };
LAYOUT_ASSERT(WeaponStarLightParameterWordsExtent, sizeof(WeaponStarLightParameterWords) == 0x14);

static const WeaponStarLightParameterWords weapon_star_light_parameters[] = {
    { { 0x40400000, 0x40E00000, 0xB4FF0019, 0, 0x41A00000 } }
};

void TItemFollowStarLight::run_task() {
    s32 position;
    saddr item;
    if (item_generation != (u32)get_item_system_generation()) {
        queue_destruction();
        return;
    }
    if (star_light != NULL) {
        item = ((saddr)find_item_by_id(item_id));
        if ((item != 0) && (((TItem *)item)->get_mode() == 2) && (((TItemWeapon *)item)->get_joint_position(joint, &position) != 0)) {
            if (((TItem *)item)->is_hidden() == 0) {
                star_light->copy_position((const Vec *)&position);
                return;
            }
            star_light->queue_child_destruction();
            return;
        }
    }
    queue_destruction();
}

TItemFollowStarLight::~TItemFollowStarLight() {}

TItemFollowStarLight::TItemFollowStarLight(TObject *parent, s32 item_id, s32 joint) : TObject(parent) {
    StarLightPosition v;
    void *p;
    this->item_id = item_id;
    this->joint = joint;
    star_light = NULL;
    item_generation = get_item_system_generation();
    p = find_item_by_id(this->item_id);
    if (p != NULL && ((TItemWeapon *)p)->get_joint_position(this->joint, &v) != 0) {
        WeaponStarLightParameterWords blk = weapon_star_light_parameters[0];
        star_light = (TEffStarLight2D *)spawn_star_light_2d((saddr)&v, (saddr)&blk, (saddr)this);
    }
}


void spawn_item_follow_star_light(TObject *parent, s32 item_id, s32 joint) {
    if (parent != NULL) {
        new TItemFollowStarLight(parent, item_id, joint);
    }
}
