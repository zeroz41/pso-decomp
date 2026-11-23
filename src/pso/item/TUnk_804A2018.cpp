#include "pso/item/TUnk_804A2018.h"
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

void TUnk_804A2018::run_task() {
    s32 sp8;
    saddr item;
    if (item_generation != (u32)get_item_system_generation()) {
        queue_destruction();
        return;
    }
    if (star_light != NULL) {
        item = ((saddr)find_item_by_id(item_id));
        if ((item != 0) && (((TItem *)item)->get_mode() == 2) && (((TItemWeapon *)item)->get_joint_position(joint, &sp8) != 0)) {
            if (((TItem *)item)->is_hidden() == 0) {
                star_light->copy_position((const Vec *)&sp8);
                return;
            }
            star_light->queue_child_destruction();
            return;
        }
    }
    queue_destruction();
}

TUnk_804A2018::~TUnk_804A2018() {}

TUnk_804A2018::TUnk_804A2018(TObject *parent, s32 item_id, s32 joint) : TObject(parent) {
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


void create_icon__10TObjPlayerFiii(saddr parent, s32 arg1, s32 arg2) {
    if (parent != 0) {
        new TUnk_804A2018((TObject *)parent, arg1, arg2);
    }
}
