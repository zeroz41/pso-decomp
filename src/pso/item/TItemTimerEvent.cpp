#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/item/TItemTimerEvent.h"
#include "pso/item/TUnk_804A0568.h"
#include "pso/item/TUnk_804A0588.h"
#include "pso/item/TUnk_804A05A8.h"
#include "pso/item/TUnk_804A05C8.h"
#include "pso/item/TUnk_804A05E8.h"
#include "pso/item/TUnk_804A0608.h"
#include "pso/item/TUnk_804A0628.h"
#include "pso/item/TUnk_804A0648.h"
#include "pso/item/TUnk_804A0668.h"
#include "pso/item/TUnk_804A0688.h"
#include "pso/player/TObjPlayer_80011014.h"
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

extern const char TItemTimerEvent__class_name_string[] = "TItemTimerEvent";
const char *TItemTimerEvent__class_name = TItemTimerEvent__class_name_string;

struct Base_8011D94C_8011D414 { char pad[0x18]; };
struct VObj_8011D94C_8011D414 : Base_8011D94C_8011D414 {
    virtual void m0();   virtual void m1();   virtual void m2();   virtual void m3();
    virtual void m4();   virtual void m5();   virtual void m6();   virtual void m7();
    virtual void m8();   virtual void m9();   virtual void m10();  virtual void m11();
    virtual void m12();  virtual void m13();  virtual void m14();  virtual void m15();
    virtual void m16();  virtual void m17();  virtual void m18();  virtual void m19();
    virtual void m20();  virtual void m21();  virtual void m22();  virtual void m23();
    virtual void m24();  virtual void m25();  virtual void m26();  virtual void m27();
    virtual void m28();  virtual void m29();  virtual void m30();  virtual void m31();
    virtual void m32();  virtual void m33();  virtual void m34();  virtual void m35();
    virtual void m36();  virtual void m37();  virtual void m38();  virtual void m39();
    virtual void m40();  virtual void m41();  virtual void m42();  virtual void m43();
    virtual void m44();  virtual void m45();  virtual void m46();  virtual void m47();
    virtual void m48();  virtual void m49();  virtual void m50();  virtual void m51();
    virtual void m52();  virtual void m53();  virtual void m54();  virtual void m55();
    virtual void m56();  virtual void m57();  virtual void m58();  virtual void m59();
    virtual void m60();  virtual void m61();  virtual void m62();  virtual void m63();
    virtual void m64();  virtual void m65();  virtual void m66();  virtual void m67();
    virtual void m68();  virtual void m69();  virtual void m70();  virtual void m71();
    virtual void m72();  virtual void m73(f32);
};

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

extern "C" {
TItemLockCountCtrl * item_timer_event_instance;
s32 is_item_area_enabled(s32 area);

void TObjPlayer::clear_state_flags(s32 arg1) {
  s32 *new_var;
  int new_var2;
    TObjPlayer *arg0 = (TObjPlayer *)this;
  new_var2 = ~arg1;
  new_var = (s32 *) (((s8 *) arg0) + 0x334);
  *new_var = (s32) ((arg0->state_flags) & new_var2);
}

void fn_8011E1D4(TObjPlayer *player) {
    if (!(player->class_flags & CLASS_FLAG_ANDROID)) {
        ((TObjPlayer *)player)->clear_state_flags(0x10000);
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

TUnk_804A0688::~TUnk_804A0688() {}

TUnk_804A0668::~TUnk_804A0668() {}

TUnk_804A0648::~TUnk_804A0648() {}

TUnk_804A0628::~TUnk_804A0628() {}

TUnk_804A0608::~TUnk_804A0608() {}

TUnk_804A05E8::~TUnk_804A05E8() {}

TUnk_804A05C8::~TUnk_804A05C8() {}

TUnk_804A05A8::~TUnk_804A05A8() {}

TUnk_804A0588::~TUnk_804A0588() {}

TUnk_804A0568::~TUnk_804A0568() {}

TItemTimerEvent::TItemTimerEvent(TItemHeapObject *parent, u16 client, s32 period) : TItemHeapObject(parent) {
    m_name = TItemTimerEvent__class_name;
    m_1c = client;
    m_28 = 0;
    m_20 = period;
    m_24 = 0;
    disallow_rendering();
}

TItemTimerEvent::~TItemTimerEvent() {}

void TItemTimerEvent::run_task() {
    this->m_28 = (uaddr)get_player_by_client_id((u16)this->m_1c);
    if ((u32) this->m_28 == 0U) {
        queue_destruction();
        return;
    }
    if ((s32) this->m_24 == (s32) this->m_20) {
        this->vfunc_6();
        this->m_24 = 0;
        return;
    }
    this->vfunc_7();
}

void TItemTimerEvent::vfunc_7() {
    this->m_24 = (this->m_24 + 1);
}

void TUnk_804A0688::vfunc_7() {
    if (((TObjPlayer *)this->m_28)->test_action_mask(0x1C) != 0) {
        this->m_24 = (this->m_24 + 1);
    }
}

void TUnk_804A0688::vfunc_6() {
        if ((is_item_area_enabled(((TObjPlayer *)(this->m_28))->get_area()) == 1) && (((TObjChara *)this->m_28)->obj_isState3_324() == 0) && (((TObjCollidable *)this->m_28)->test_actor_flags(0x800) == 0)) {
        TObjectV8047c128_subtract_hp((u8 *)this->m_28, 1);
    }
}

void TUnk_804A0668::vfunc_7() {
    if (((TObjPlayer *)this->m_28)->test_action_mask(0x1C) != 0) {
        this->m_24 = (this->m_24 + 1);
    }
}

void TUnk_804A0668::vfunc_6() {
        if ((is_item_area_enabled(((TObjPlayer *)(this->m_28))->get_area()) == 1) && (((TObjChara *)this->m_28)->obj_isState3_324() == 0) && (((TObjCollidable *)this->m_28)->test_actor_flags(0x800) == 0)) {
        ((TObjChara *)(this->m_28))->subtract_actor_tp(1);
    }
}

void TUnk_804A0648::vfunc_6() {
    if (((TObjCollidable *)this->m_28)->test_actor_flags(0x800) == 0) {
        add_actor_hp((TObjChara *)this->m_28, 1);
    }
}

void TUnk_804A0628::vfunc_6() {
    if (((TObjCollidable *)this->m_28)->test_actor_flags(0x800) == 0) {
        add_actor_tp((TObjChara *)this->m_28, 1);
    }
}

void TUnk_804A0608::vfunc_6() {
    struct VObj_8011D94C_8011D414 *o;

    if (((TObjCollidable *)this->m_28)->test_actor_flags(0x800) == 0) {
        o = (struct VObj_8011D94C_8011D414 *)this->m_28;
        o->m73(1.0f);
    }
}

void TUnk_804A05E8::vfunc_6() {

    if (((TObjChara *)(this->m_28))->obj_isState2_324() == 0) {
        if (((TObjPlayer *)this->m_28)->has_flag_0x800() == 0) {
                        if ((is_item_area_enabled(((TObjPlayer *)(this->m_28))->get_area()) == 1) && ((3.0517578e-05f * (f32) rand()) < this->unk_2C)) {
                ((TObjPlayer *)this->m_28)->apply_movement_ailment(0);
                ((TObjPlayer *)this->m_28)->sync_enemy_state(0);
            }
        }
    }
}

void TUnk_804A05C8::vfunc_6() {
    TParticleCtrl *particle;

    if ((((TObjPlayer *)this->m_28)->is_body_collision_inactive() == 0) && (((TObjPlayer *)(this->m_28))->is_flag_20000_set() == 0)) {
                if ((is_item_area_enabled(((TObjPlayer *)(this->m_28))->get_area()) == 1) && (((TObjCollidable *)((void *)this->m_28))->test_actor_flags(0x800) == 0)) {
            particle = spawn_particle_effect_with_flags((const Vec *)(*(saddr *)&this->m_28 + 0x2FC), this->unk_2C, 0x10);
            if (particle != 0) {
                particle->set_owner_id(((TObjBase *)this->m_28)->get_entity_id());
            }
        }
    }
}

void TUnk_804A05A8::vfunc_6() {
    Timer_8011D5B4 *arg0 = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
        if (is_item_area_enabled(((TObjPlayer *)(arg0->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < arg0->f2c) {
        a.k1 = 0x11;
        a.v2 = 0.0f;
        a.k2 = 0x11;
        a.v1 = *(s32 *)&a.v2;
        arg0->obj->m21(arg0->obj, &a, 0, -1, -1);
    }
}

void TUnk_804A0588::vfunc_6() {
    Timer_8011D5B4 *arg0 = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
        if (is_item_area_enabled(((TObjPlayer *)(arg0->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < arg0->f2c) {
        a.k1 = 0x12;
        a.v2 = 0.0f;
        a.k2 = 0x12;
        a.v1 = *(s32 *)&a.v2;
        arg0->obj->m21(arg0->obj, &a, 0, -1, -1);
    }
}

void TUnk_804A0568::vfunc_6() {
    Timer_8011D5B4 *arg0 = (Timer_8011D5B4 *)this;
    Rec_8011D5B4 a;
        if (is_item_area_enabled(((TObjPlayer *)(arg0->obj))->get_area()) == 1 && 3.0517578e-05f * (f32)rand() < arg0->f2c) {
        a.k1 = 0x10;
        a.v2 = 0.0f;
        a.k2 = 0x10;
        a.v1 = *(s32 *)&a.v2;
        arg0->obj->m21(arg0->obj, &a, 0, -1, -1);
    }
}

}
