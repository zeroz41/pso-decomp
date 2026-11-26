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
#include "pso/item/TItemLockCountCtrl_8011E184.h"
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


struct StatusTargetBase { char pad[0x18]; };
struct StatusTarget : StatusTargetBase {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void m21(void *, void *, s32, s32, s32);
};
struct StatusRequest { s32 k1; s32 v1; s32 k2; f32 v2; };
struct CurseTimerView { u8 pad[0x28]; StatusTarget *obj; f32 f2c; };

void TObjPlayer::set_state_flags(u32 v) { state_flags |= v; }

void TObjPlayer::set_flag_10000() {
    set_state_flags(0x10000);
}

TItemLockCountCtrl * item_timer_event_instance;

void TObjPlayer::clear_state_flags(s32 mask) {
  state_flags = state_flags & ~mask;
}

void fn_8011E1D4(TObjPlayer *player) {
    if (!(player->class_flags & CLASS_FLAG_ANDROID)) {
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
    uaddr player;
    if ((player = ((uaddr)get_player_by_client_id((u16)client))) != 0U) {
        ((TObjPlayer *)player)->set_flag_10000();
    }
}

void TItemTimerEvent::check_battle_ctrl(int client) {
    uaddr player = (uaddr)get_player_by_client_id((u16)client);
    if (player != 0U) {
        fn_8011E1D4((TObjPlayer *)player);
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
    this->player = (uaddr)get_player_by_client_id((u16)this->client_id);
    if ((u32) this->player == 0U) {
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
    if (((TObjPlayer *)this->player)->test_action_mask(0x1C) != 0) {
        this->elapsed = (this->elapsed + 1);
    }
}

void TItemTimerEventHpDrain::apply_effect() {
        if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && (((TObjChara *)this->player)->obj_isState3_324() == 0) && (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0)) {
        subtract_actor_hp((TObjChara *)this->player, 1);
    }
}

void TItemTimerEventTpDrain::advance_timer() {
    if (((TObjPlayer *)this->player)->test_action_mask(0x1C) != 0) {
        this->elapsed = (this->elapsed + 1);
    }
}

void TItemTimerEventTpDrain::apply_effect() {
        if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && (((TObjChara *)this->player)->obj_isState3_324() == 0) && (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0)) {
        ((TObjChara *)(this->player))->subtract_actor_tp(1);
    }
}

void TItemTimerEventHpRegen::apply_effect() {
    if (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0) {
        add_actor_hp((TObjChara *)this->player, 1);
    }
}

void TItemTimerEventTpRegen::apply_effect() {
    if (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0) {
        add_actor_tp((TObjChara *)this->player, 1);
    }
}

void TItemTimerEventPbCharge::apply_effect() {
    if (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0) {
        ((TObjChara *)this->player)->gain_photon_blast_charge(1.0f);
    }
}

void TItemTimerEventFreezeCurse::apply_effect() {

    if (((TObjChara *)(this->player))->obj_isState2_324() == 0) {
        if (((TObjPlayer *)this->player)->is_actor_dead() == 0) {
                        if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && ((3.0517578e-05f * (f32) rand()) < this->chance)) {
                ((TObjPlayer *)this->player)->apply_movement_ailment(0);
                ((TObjPlayer *)this->player)->sync_enemy_state(0);
            }
        }
    }
}

void TItemTimerEventArmorParticle::apply_effect() {
    TParticleCtrl *particle;

    if ((((TObjPlayer *)this->player)->is_body_collision_inactive() == 0) && (((TObjPlayer *)(this->player))->is_flag_20000_set() == 0)) {
                if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && (((TObjCollidable *)((void *)this->player))->test_actor_flags(0x800) == 0)) {
            particle = spawn_particle_effect_with_flags((const Vec *)(*(saddr *)&this->player + 0x2FC), this->particle_id, 0x10);
            if (particle != 0) {
                particle->set_owner_id(((TObjBase *)this->player)->get_entity_id());
            }
        }
    }
}

void TItemTimerEventSlowCurse::apply_effect() {
    CurseTimerView *timer = (CurseTimerView *)this;
    StatusRequest a;
        if (is_item_area_enabled(((TObjPlayer *)(timer->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < timer->f2c) {
        a.k1 = 0x11;
        a.v2 = 0.0f;
        a.k2 = 0x11;
        a.v1 = *(s32 *)&a.v2;
        timer->obj->m21(timer->obj, &a, 0, -1, -1);
    }
}

void TItemTimerEventConfusionCurse::apply_effect() {
    CurseTimerView *timer = (CurseTimerView *)this;
    StatusRequest a;
        if (is_item_area_enabled(((TObjPlayer *)(timer->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < timer->f2c) {
        a.k1 = 0x12;
        a.v2 = 0.0f;
        a.k2 = 0x12;
        a.v1 = *(s32 *)&a.v2;
        timer->obj->m21(timer->obj, &a, 0, -1, -1);
    }
}

void TItemTimerEventParalysisCurse::apply_effect() {
    CurseTimerView *timer = (CurseTimerView *)this;
    StatusRequest a;
        if (is_item_area_enabled(((TObjPlayer *)(timer->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < timer->f2c) {
        a.k1 = 0x10;
        a.v2 = 0.0f;
        a.k2 = 0x10;
        a.v1 = *(s32 *)&a.v2;
        timer->obj->m21(timer->obj, &a, 0, -1, -1);
    }
}

