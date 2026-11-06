#include "types.h"
#include "pso/item/TUnk_804F112C.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"

// Hits the owner with a direct attack of the given kind (15-18 by the use
// effects below) and no power.
void TUnk_804F112C::send_obj_position_event(s32 kind) {
    if (owner != NULL) {
        DirectAttackPayload payload;
        payload.kind = kind;
        payload.power = 0.0f;
        owner->receive_direct_attack(owner, payload, NULL, -1, -1);
    }
}

// The use effects, picked by apply_use_effect from the item's technique byte.
void TUnk_804F112C::set_phase_18() {
    send_obj_position_event(18);
}

void TUnk_804F112C::fn_803530A0() {
    send_obj_position_event(17);
}

void TUnk_804F112C::update_player_object() {
    if (TObjPlayer::is_locally_controlled(owner) != 0) {
        owner->apply_shock_status();
    }
}

void TUnk_804F112C::fn_80353110() {
    send_obj_position_event(16);
}

void TUnk_804F112C::fn_80353134() {
    send_obj_position_event(15);
}

void TUnk_804F112C::update_shield() {
    add_actor_hp((u8 *)owner, ((TItemProShield *)owner)->get_field_2b8());
}

void TUnk_804F112C::fn_80353194() {
    add_actor_tp((u8 *)owner, obj_getS16_2BA((u8 *)owner));
}

// The Star Atomizer's effect (see send_nearby_player_ids).
void TUnk_804F112C::fn_803531D0() {
    send_nearby_player_ids(owner, 10000.0f);
}

void TUnk_804F112C::fn_803531F8() {}

void TUnk_804F112C::apply_use_effect() {
    void (TUnk_804F112C::*effects[9])() = {
        &TUnk_804F112C::fn_803531F8, &TUnk_804F112C::fn_803531D0, &TUnk_804F112C::fn_80353194,
        &TUnk_804F112C::update_shield, &TUnk_804F112C::fn_80353134, &TUnk_804F112C::fn_80353110,
        &TUnk_804F112C::update_player_object, &TUnk_804F112C::fn_803530A0, &TUnk_804F112C::set_phase_18,
    };
    u8 technique = get_technique();
    if (technique < 9) {
        void (TUnk_804F112C::*effect)() = effects[technique];
        (this->*effect)();
    }
}

TUnk_804F112C::~TUnk_804F112C() {}

TUnk_804F112C::TUnk_804F112C(TObject *parent, u8 *item) : TItemObject(parent, item) {}

TUnk_804F112C *TUnk_804F112C::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F112C(tl_05, item);
    }
    return NULL;
}
