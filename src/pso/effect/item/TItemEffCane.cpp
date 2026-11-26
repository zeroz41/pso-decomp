#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffCane.h"
#include "pso/item/TItem.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"

const char *TItemEffCane::class_name = "TItemEffCane";

void TItemEffCane::create(TObject *parent, TItem *item, s32 attachment, s32 effect_id) {
    if (parent != NULL && item != NULL && item->all_parents_unqueued_for_destruction() != 0) {
        new TItemEffCane(parent, item, attachment, effect_id);
    }
}

void TItemEffCane::spawn(TObject *parent, TItem *item, s32 attachment) {
    if (parent != NULL && item != NULL && item->all_parents_unqueued_for_destruction() != 0) {
        new TItemEffCane(parent, item, attachment, 0x1BD);
    }
}

void TItemEffCane::spawn_pair(TObject *parent, TItem *item, s32 first_attachment, s32 second_attachment) {
    if (parent != NULL && item != NULL && item->all_parents_unqueued_for_destruction() != 0) {
        new TItemEffCane(parent, item, first_attachment, 0x1BD);
        new TItemEffCane(parent, item, second_attachment, 0x1BD);
    }
}

void TItemEffCane::run_task() {
    f32 position[3];
    TItemWeapon *item = (TItemWeapon *)find_item_by_id(item_id);
    if (item == NULL) {
        queue_destruction();
        return;
    }
    if (item->get_mode() != 2 || item->test_weapon_flags(0x10) == 0 || effect == NULL) {
        queue_destruction();
        return;
    }
    item->get_joint_position(attachment_index, position);
    ((TParticleCtrl *)effect)->set_position(position);
}

TItemEffCane::~TItemEffCane() {
    TParticleCtrl::release(effect);
}

TItemEffCane::TItemEffCane(TObject* parent, TItem* item, s32 attachment, s32 effect_id)
    : TObject(parent) {
    f32 position[3];
    m_name = class_name;
    item_id = item->get_item_id();
    attachment_index = attachment;
    ((TItemWeapon *)item)->get_joint_position(attachment_index, position);
    if (effect_id != -1) {
        effect = create_particle_emitter(position, effect_id);
    } else {
        effect = NULL;
    }
    disallow_rendering();
}

u32 TItemWeapon::test_weapon_flags(u32 mask) { return weapon_flags & mask; }
