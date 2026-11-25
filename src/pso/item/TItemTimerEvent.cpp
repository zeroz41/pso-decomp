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
#include "pso/unk/text_8011085C.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/scene/TScene.h"

extern const char TItemTimerEvent__class_name_string[] = "TItemTimerEvent";
const char *TItemTimerEvent__class_name = TItemTimerEvent__class_name_string;


struct VBase_8011D5B4 { char pad[0x18]; };
struct VObj_8011D5B4 : VBase_8011D5B4 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20();
    virtual void m21(void *, void *, s32, s32, s32);
};
struct Rec_8011D5B4 { s32 k1; s32 v1; s32 k2; f32 v2; };
struct Timer_8011D5B4 { u8 pad[0x28]; VObj_8011D5B4 *obj; f32 f2c; };

void TObjPlayer::set_state_flags(u32 v) { state_flags |= v; }

void TObjPlayer::set_flag_10000() {
    set_state_flags(0x10000);
}

extern "C" {
TItemLockCountCtrl * item_timer_event_instance;

void TObjPlayer::clear_state_flags(s32 mask) {
  s32 *new_var;
  int new_var2;
    TObjPlayer *arg0 = (TObjPlayer *)this;
  new_var2 = ~mask;
  new_var = (s32 *) (((s8 *) arg0) + 0x334);
  *new_var = (s32) ((arg0->state_flags) & new_var2);
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
    if (((void *) (*(u8 * *)&item_timer_event_instance) != NULL) && (client_id < 0xCU)) {
        fn_801108C8((*(u8 * *)&item_timer_event_instance), client_id);
    }
}

void TItemTimerEvent::clear_timer_slot(u16 client_id) {
    if (((void *) (*(u8 * *)&item_timer_event_instance) != NULL) && (client_id < 0xCU)) {
        fn_8011085C((*(u8 * *)&item_timer_event_instance), client_id);
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
    m_name = TItemTimerEvent__class_name;
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
        this->vfunc_6();
        this->elapsed = 0;
        return;
    }
    this->vfunc_7();
}

void TItemTimerEvent::vfunc_7() {
    this->elapsed = (this->elapsed + 1);
}

void TItemTimerEventHpDrain::vfunc_7() {
    if (((TObjPlayer *)this->player)->test_action_mask(0x1C) != 0) {
        this->elapsed = (this->elapsed + 1);
    }
}

void TItemTimerEventHpDrain::vfunc_6() {
        if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && (((TObjChara *)this->player)->obj_isState3_324() == 0) && (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0)) {
        TObjectV8047c128_subtract_hp((u8 *)this->player, 1);
    }
}

void TItemTimerEventTpDrain::vfunc_7() {
    if (((TObjPlayer *)this->player)->test_action_mask(0x1C) != 0) {
        this->elapsed = (this->elapsed + 1);
    }
}

void TItemTimerEventTpDrain::vfunc_6() {
        if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && (((TObjChara *)this->player)->obj_isState3_324() == 0) && (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0)) {
        ((TObjChara *)(this->player))->subtract_actor_tp(1);
    }
}

void TItemTimerEventHpRegen::vfunc_6() {
    if (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0) {
        add_actor_hp((TObjChara *)this->player, 1);
    }
}

void TItemTimerEventTpRegen::vfunc_6() {
    if (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0) {
        add_actor_tp((TObjChara *)this->player, 1);
    }
}

void TItemTimerEventPbCharge::vfunc_6() {
    if (((TObjCollidable *)this->player)->test_actor_flags(0x800) == 0) {
        ((TObjChara *)this->player)->gain_photon_blast_charge(1.0f);
    }
}

void TItemTimerEventFreezeCurse::vfunc_6() {

    if (((TObjChara *)(this->player))->obj_isState2_324() == 0) {
        if (((TObjPlayer *)this->player)->has_flag_0x800() == 0) {
                        if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && ((3.0517578e-05f * (f32) rand()) < this->unk_2C)) {
                ((TObjPlayer *)this->player)->apply_movement_ailment(0);
                ((TObjPlayer *)this->player)->sync_enemy_state(0);
            }
        }
    }
}

void TItemTimerEventArmorParticle::vfunc_6() {
    TParticleCtrl *particle;

    if ((((TObjPlayer *)this->player)->is_body_collision_inactive() == 0) && (((TObjPlayer *)(this->player))->is_flag_20000_set() == 0)) {
                if ((is_item_area_enabled(((TObjPlayer *)(this->player))->get_area()) == 1) && (((TObjCollidable *)((void *)this->player))->test_actor_flags(0x800) == 0)) {
            particle = spawn_particle_effect_with_flags((const Vec *)(*(saddr *)&this->player + 0x2FC), this->unk_2C, 0x10);
            if (particle != 0) {
                particle->set_owner_id(((TObjBase *)this->player)->get_entity_id());
            }
        }
    }
}

void TItemTimerEventSlowCurse::vfunc_6() {
    Timer_8011D5B4 *timer = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
        if (is_item_area_enabled(((TObjPlayer *)(timer->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < timer->f2c) {
        a.k1 = 0x11;
        a.v2 = 0.0f;
        a.k2 = 0x11;
        a.v1 = *(s32 *)&a.v2;
        timer->obj->m21(timer->obj, &a, 0, -1, -1);
    }
}

void TItemTimerEventConfusionCurse::vfunc_6() {
    Timer_8011D5B4 *timer = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
        if (is_item_area_enabled(((TObjPlayer *)(timer->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < timer->f2c) {
        a.k1 = 0x12;
        a.v2 = 0.0f;
        a.k2 = 0x12;
        a.v1 = *(s32 *)&a.v2;
        timer->obj->m21(timer->obj, &a, 0, -1, -1);
    }
}

void TItemTimerEventParalysisCurse::vfunc_6() {
    Timer_8011D5B4 *timer = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
        if (is_item_area_enabled(((TObjPlayer *)(timer->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < timer->f2c) {
        a.k1 = 0x10;
        a.v2 = 0.0f;
        a.k2 = 0x10;
        a.v1 = *(s32 *)&a.v2;
        timer->obj->m21(timer->obj, &a, 0, -1, -1);
    }
}

}
