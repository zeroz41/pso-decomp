#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TItemTimerEventParalysisCurse.h"
#include "pso/item/TItemTimerEventConfusionCurse.h"
#include "pso/item/TItemTimerEventSlowCurse.h"
#include "pso/item/TItemTimerEventArmorParticle.h"
#include "pso/item/TItemTimerEventFreezeCurse.h"
#include "pso/item/TItemTimerEventPbCharge.h"
#include "pso/item/TItemTimerEventTpRegen.h"
#include "pso/item/TItemTimerEventHpRegen.h"
#include "pso/item/TItemTimerEventTpDrain.h"
#include "pso/item/TItemTimerEventHpDrain.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/item/TItemLockCountCtrl.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include <stdlib.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/scene/TScene.h"

const char TItemTimerEvent::class_name_string[] = "TItemTimerEvent";
const char *TItemTimerEvent::class_name = TItemTimerEvent::class_name_string;


void TObjPlayer::set_state_flags(u32 v) { state_flags |= v; }

void TObjPlayer::set_flag_10000() {
    set_state_flags(0x10000);
}

TItemLockCountCtrl * item_timer_event_instance;

void TObjPlayer::clear_state_flags(s32 mask) {
  state_flags = state_flags & ~mask;
}

void fn_8011E1D4(TObjPlayer *player) {
    if (!(player->appearance.classFlags & CLASS_FLAG_ANDROID)) {
        player->clear_state_flags(0x10000);
    }
}

void TItemLockCountCtrl::create_instance() {
    item_timer_event_instance = new TItemLockCountCtrl(0, 12, TItemTimerEvent::notify_if_active, TItemTimerEvent::check_battle_ctrl);
}

void TItemTimerEvent::clear_active() {
    delete item_timer_event_instance;
    item_timer_event_instance = NULL;
}

void TItemTimerEvent::notify_if_active(int client) {
    TObjPlayer *player;
    if ((player = get_player_by_client_id((u16)client)) != NULL) {
        player->set_flag_10000();
    }
}

void TItemTimerEvent::check_battle_ctrl(int client) {
    TObjPlayer *player = get_player_by_client_id((u16)client);
    if (player != NULL) {
        fn_8011E1D4(player);
    }
}

void TItemTimerEvent::start_event_by_index(u16 client_id) {
    if ((item_timer_event_instance != NULL) && (client_id < 0xCU)) {
        item_timer_event_instance->lock(client_id);
    }
}

void TItemTimerEvent::clear_timer_slot(u16 client_id) {
    if ((item_timer_event_instance != NULL) && (client_id < 0xCU)) {
        item_timer_event_instance->unlock(client_id);
    }
}

TItemTimerEventHpDrain::~TItemTimerEventHpDrain() {}

TItemTimerEventTpDrain::~TItemTimerEventTpDrain() {}

TItemTimerEventHpRegen::~TItemTimerEventHpRegen() {}

TItemTimerEventTpRegen::~TItemTimerEventTpRegen() {}

TItemTimerEventPbCharge::~TItemTimerEventPbCharge() {}

TItemTimerEventFreezeCurse::~TItemTimerEventFreezeCurse() {}

TItemTimerEventArmorParticle::~TItemTimerEventArmorParticle() {}

TItemTimerEventSlowCurse::~TItemTimerEventSlowCurse() {}

TItemTimerEventConfusionCurse::~TItemTimerEventConfusionCurse() {}

TItemTimerEventParalysisCurse::~TItemTimerEventParalysisCurse() {}

TItemTimerEvent::TItemTimerEvent(TItemHeapObject *parent, u16 client, s32 period) : TItemHeapObject(parent) {
    m_name = TItemTimerEvent::class_name;
    client_id = client;
    player = 0;
    interval = period;
    elapsed = 0;
    disallow_rendering();
}

TItemTimerEvent::~TItemTimerEvent() {}

void TItemTimerEvent::run_task() {
    this->player = get_player_by_client_id((u16)this->client_id);
    if (this->player == NULL) {
        queue_destruction();
        return;
    }
    if ((s32) this->elapsed == (s32) this->interval) {
        this->apply_effect();
        this->elapsed = 0;
        return;
    }
    this->advance_timer();
}

void TItemTimerEvent::advance_timer() {
    this->elapsed = (this->elapsed + 1);
}

void TItemTimerEventHpDrain::advance_timer() {
    if (this->player->test_action_mask(0x1C) != 0) {
        this->elapsed = (this->elapsed + 1);
    }
}

void TItemTimerEventHpDrain::apply_effect() {
        if ((is_item_area_enabled(this->player->get_area()) == 1) && (this->player->obj_isState3_324() == 0) && (this->player->test_actor_flags(0x800) == 0)) {
        subtract_actor_hp(this->player, 1);
    }
}

void TItemTimerEventTpDrain::advance_timer() {
    if (this->player->test_action_mask(0x1C) != 0) {
        this->elapsed = (this->elapsed + 1);
    }
}

void TItemTimerEventTpDrain::apply_effect() {
        if ((is_item_area_enabled(this->player->get_area()) == 1) && (this->player->obj_isState3_324() == 0) && (this->player->test_actor_flags(0x800) == 0)) {
        this->player->subtract_actor_tp(1);
    }
}

void TItemTimerEventHpRegen::apply_effect() {
    if (this->player->test_actor_flags(0x800) == 0) {
        add_actor_hp(this->player, 1);
    }
}

void TItemTimerEventTpRegen::apply_effect() {
    if (this->player->test_actor_flags(0x800) == 0) {
        add_actor_tp(this->player, 1);
    }
}

void TItemTimerEventPbCharge::apply_effect() {
    if (this->player->test_actor_flags(0x800) == 0) {
        this->player->gain_photon_blast_charge(1.0f);
    }
}

void TItemTimerEventFreezeCurse::apply_effect() {

    if (this->player->obj_isState2_324() == 0) {
        if (this->player->is_actor_dead() == 0) {
                        if ((is_item_area_enabled(this->player->get_area()) == 1) && ((3.0517578e-05f * (f32) rand()) < this->chance)) {
                this->player->apply_movement_ailment(0);
                this->player->sync_enemy_state(0);
            }
        }
    }
}

void TItemTimerEventArmorParticle::apply_effect() {
    TParticleCtrl *particle;

    if ((this->player->is_body_collision_inactive() == 0) && (this->player->is_flag_20000_set() == 0)) {
                if ((is_item_area_enabled(this->player->get_area()) == 1) && (this->player->test_actor_flags(0x800) == 0)) {
            particle = spawn_particle_effect_with_flags(&this->player->body_center, this->particle_id, 0x10);
            if (particle != 0) {
                particle->set_owner_id(this->player->get_entity_id());
            }
        }
    }
}

void TItemTimerEventSlowCurse::apply_effect() {
    DirectAttackPayload attack;
    if (is_item_area_enabled(player->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < chance) {
        attack.kind = 0x11;
        attack.power = 0.0f;
        player->receive_direct_attack(player, attack, NULL, -1, -1);
    }
}

void TItemTimerEventConfusionCurse::apply_effect() {
    DirectAttackPayload attack;
    if (is_item_area_enabled(player->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < chance) {
        attack.kind = 0x12;
        attack.power = 0.0f;
        player->receive_direct_attack(player, attack, NULL, -1, -1);
    }
}

void TItemTimerEventParalysisCurse::apply_effect() {
    DirectAttackPayload attack;
    if (is_item_area_enabled(player->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < chance) {
        attack.kind = 0x10;
        attack.power = 0.0f;
        player->receive_direct_attack(player, attack, NULL, -1, -1);
    }
}

