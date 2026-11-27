#include "types.h"
#include "pso/item/ItemUseEffects.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"

// Hits the owner with a direct attack of the given kind (15-18 by the use
// effects below) and no power.
void TUnk_804F112C::inflict_status(s32 kind) {
    if (owner != NULL) {
        DirectAttackPayload payload;
        payload.kind = kind;
        payload.power = 0.0f;
        owner->receive_direct_attack(owner, payload, NULL, -1, -1);
    }
}

// The use effects, picked by apply_use_effect from the item's technique byte: kinds 15-18 are poison, paralysis, slow and confusion.
void TUnk_804F112C::inflict_confusion() {
    inflict_status(18);
}

void TUnk_804F112C::inflict_slow() {
    inflict_status(17);
}

void TUnk_804F112C::inflict_shock() {
    if (owner->is_locally_controlled() != 0) {
        owner->apply_shock_status();
    }
}

void TUnk_804F112C::inflict_paralysis() {
    inflict_status(16);
}

void TUnk_804F112C::inflict_poison() {
    inflict_status(15);
}

void TUnk_804F112C::restore_hp() {
    add_actor_hp(owner, owner->get_hpmax());
}

void TUnk_804F112C::restore_tp() {
    add_actor_tp(owner, owner->get_tpmax());
}

// The Star Atomizer's effect (see send_nearby_player_ids).
void TUnk_804F112C::send_nearby_players() {
    send_nearby_player_ids(owner, 10000.0f);
}

void TUnk_804F112C::no_effect() {}

void TUnk_804F112C::apply_use_effect() {
    void (TUnk_804F112C::*effects[9])() = {
        &TUnk_804F112C::no_effect, &TUnk_804F112C::send_nearby_players, &TUnk_804F112C::restore_tp,
        &TUnk_804F112C::restore_hp, &TUnk_804F112C::inflict_poison, &TUnk_804F112C::inflict_paralysis,
        &TUnk_804F112C::inflict_shock, &TUnk_804F112C::inflict_slow, &TUnk_804F112C::inflict_confusion,
    };
    u8 technique = get_technique();
    if (technique < 9) {
        void (TUnk_804F112C::*effect)() = effects[technique];
        (this->*effect)();
    }
}

TUnk_804F112C::~TUnk_804F112C() {}

TUnk_804F112C::TUnk_804F112C(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TUnk_804F112C::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F112C(tl_05, item);
    }
    return NULL;
}
