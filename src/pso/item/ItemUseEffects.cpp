#include "types.h"
#include "pso/item/ItemUseEffects.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"

// Hits the owner with a direct attack of the given kind (15-18 by the use
// effects below) and no power.
void TItemToolUseEffect::inflict_status(s32 kind) {
    if (owner != NULL) {
        DirectAttackPayload payload;
        payload.kind = kind;
        payload.power = 0.0f;
        owner->receive_direct_attack(owner, payload, NULL, -1, -1);
    }
}

// The use effects, picked by apply_use_effect from the item's technique byte: kinds 15-18 are poison, paralysis, slow and confusion.
void TItemToolUseEffect::inflict_confusion() {
    inflict_status(18);
}

void TItemToolUseEffect::inflict_slow() {
    inflict_status(17);
}

void TItemToolUseEffect::inflict_shock() {
    if (owner->is_locally_controlled() != 0) {
        owner->apply_shock_status();
    }
}

void TItemToolUseEffect::inflict_paralysis() {
    inflict_status(16);
}

void TItemToolUseEffect::inflict_poison() {
    inflict_status(15);
}

void TItemToolUseEffect::restore_hp() {
    add_actor_hp(owner, owner->get_hpmax());
}

void TItemToolUseEffect::restore_tp() {
    add_actor_tp(owner, owner->get_tpmax());
}

// The Star Atomizer's effect (see send_nearby_player_ids).
void TItemToolUseEffect::send_nearby_players() {
    owner->send_nearby_player_ids(10000.0f);
}

void TItemToolUseEffect::no_effect() {}

void TItemToolUseEffect::apply_use_effect() {
    void (TItemToolUseEffect::*effects[9])() = {
        &TItemToolUseEffect::no_effect, &TItemToolUseEffect::send_nearby_players, &TItemToolUseEffect::restore_tp,
        &TItemToolUseEffect::restore_hp, &TItemToolUseEffect::inflict_poison, &TItemToolUseEffect::inflict_paralysis,
        &TItemToolUseEffect::inflict_shock, &TItemToolUseEffect::inflict_slow, &TItemToolUseEffect::inflict_confusion,
    };
    u8 technique = get_technique();
    if (technique < 9) {
        void (TItemToolUseEffect::*effect)() = effects[technique];
        (this->*effect)();
    }
}

TItemToolUseEffect::~TItemToolUseEffect() {}

TItemToolUseEffect::TItemToolUseEffect(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TItem *TItemToolUseEffect::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolUseEffect(tl_05, item);
    }
    return NULL;
}
