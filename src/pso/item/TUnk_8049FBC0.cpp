#include "types.h"
#include "pso/TMainTask.h"
#include "pso/unk/TUnk_8049FBC0.h"
#include "pso/player/TObjPlayer_801AEB84.h"
#include "pso/player/TObjPlayer.h"

// Written from the last function back (deferred code generation), which also
// puts the vtable before the switch table.

// calc_base_tp_bonus/calc_base_hp_bonus(u16) as this file's callers see them:
// the client id still in r3 from get_entity_id.
extern "C" s16 calc_base_tp_bonus__FUs();
extern "C" s16 calc_base_hp_bonus__FUs();

extern "C" {
s32 get_entity_id(void *);
s32 check_class_equip_permission(void *, int);
u8 get_item_index__5TItemFv();
}

TItem *create_material_item(u8 *item) {
    if (item != NULL) {
        return new TUnk_8049FBC0(tl_05, item);
    }
    return NULL;
}

TUnk_8049FBC0::TUnk_8049FBC0(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_8049FBC0::~TUnk_8049FBC0() {}

void TUnk_8049FBC0::apply_use_effect() {
    switch (get_item_index__5TItemFv()) {
    case 0:
        ((TObjPlayer *)(this->owner))->add_stat_and_item(2);
        break;
    case 1:
        if (check_class_equip_permission((void *)this->owner, 0xD7) == 0) {
            ((TObjPlayer *)(this->owner))->add_mst_and_item(2);
        }
        break;
    case 2:
        ((TObjPlayer *)(this->owner))->add_evp_material(2);
        break;
    case 3:
        get_entity_id((void *)this->owner);
        if (calc_base_hp_bonus__FUs() < 0xFA) {
            ((TObjPlayer *)(this->owner))->apply_speed_with_camera_scale((u8)(2));
        }
        break;
    case 4:
        get_entity_id((void *)this->owner);
        if ((calc_base_tp_bonus__FUs() < 0xFA) && (check_class_equip_permission((void *)this->owner, 0xD7) == 0)) {
            ((TObjPlayer *)(this->owner))->set_speed_scaled_by_camera((u8)(2));
        }
        break;
    case 5:
        ((TObjPlayer *)(this->owner))->add_dfp_material(2);
        break;
    case 6:
        ((TObjPlayer *)(this->owner))->apply_luck_reward(2);
        break;
    }
    owner->recalc_stats();
}
