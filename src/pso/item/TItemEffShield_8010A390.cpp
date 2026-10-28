#include "types.h"
#include "pso/item/TUnk_8049F148.h"
#include "pso/boss/TBoss4Type2_80086C44.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEffShield_8010A390.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/TItemEffShield.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8010A404_lbl_8049F148 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8010A5E0___vt__14TItemEffShield {
    s32 value;
    u8 remaining[0x14];
};

struct Base_8010A4C0 { u8 pad0[0x18]; };

struct Player_8010A4C0 : Base_8010A4C0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void get_joint_pos(s32, void *);
};

struct Recipe_8010A4C0 { u8 pad0[0x20]; s32 m_20; s32 m_24; s32 m_28; };

struct Shield_8010A4C0 {
    u8 pad0[0x1C];
    u8 m_1c[0xC];
    u8 m_28[0xC];
    Recipe_8010A4C0 *m_34;
    s32 m_38;
    s32 m_3c;
    s32 m_40;
    u16 m_44;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_8049F148[];
extern RecoveredGlobal_8010A5E0___vt__14TItemEffShield __vt__14TItemEffShield;
extern s32 TItemEffShield__class_name;
void *get_player_by_client_id(s32 i);
void play_sound_effect(s32, void *, s32, s32);
void run_task__14TItemEffShieldFv(Shield_8010A4C0 *self);

}
TUnk_8049F148::~TUnk_8049F148() {
    if (*(void **)((s8 *)this + 0x1C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x1C)); *(s32 *)((s8 *)this + 0x1C) = 0; }
}


typedef char RecoveredGlobal_8010A404_lbl_8049F148_size[sizeof(RecoveredGlobal_8010A404_lbl_8049F148) == 0x18 ? 1 : -1];
u8 *TItemEffShield::ct_init(u8 *arg1, s16 arg2) {
    __ct__7TObjectFP7TObject(this, arg1);
    *(s32 **)((s8 *)((u8 *)this) + 0x18) = &(*(RecoveredGlobal_8010A404_lbl_8049F148 *)&__vt__13TUnk_8049F148).value;
    *(s16 *)((s8 *)((u8 *)this) + 0x24) = arg2;
    *(s32 *)((s8 *)((u8 *)this) + 0x20) = -1;
    *(s32 *)((s8 *)((u8 *)this) + 0x1C) = 0;
    *(s32 *)((s8 *)((u8 *)this) + 0x28) = get_item_system_generation();
    return ((u8 *)this);
}

void TItemEffShield::spawn_recipe_particles() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r5;
  s32 var_r31;
  s32 var_r30;
  var_r30 = 0;
  var_r31 = 0;
  if (temp_r5)
  {
  }
  do
  {
    temp_r5 = *((s32 *) (((s8 *) (*((s32 *) (((s8 *) arg0) + 0x34)))) + var_r31));
    if (temp_r5 != (-1))
    {
      create_oneshot_particle_emitter((arg0 + 0x1C), (arg0 + 0x28), temp_r5, 4);
    }
    var_r30 += 1;
    var_r31 += 4;
  }
  while (var_r30 != 8);
}
typedef char RecoveredGlobal_8010A5E0___vt__14TItemEffShield_size[sizeof(RecoveredGlobal_8010A5E0___vt__14TItemEffShield) == 0x18 ? 1 : -1];

void run_task__14TItemEffShieldFv(Shield_8010A4C0 *self) {
    Player_8010A4C0 *p = (Player_8010A4C0 *)get_player_by_client_id(self->m_44);
    Recipe_8010A4C0 *r;
    if (p != NULL) {
        p->get_joint_pos(self->m_40, self->m_1c);
        ((TObjPlayer *)(self->m_28))->copy_xyz((u8 *)p + 0x5C);
    }
    if (p != NULL && self->m_3c != (r = self->m_34)->m_28) {
        switch (self->m_3c) {
        case 0:
            if (self->m_38 - 1 == r->m_20) {
                play_sound_effect(0x4001A81E, self->m_1c, 0, 0);
                ((TItemEffShield *)self)->spawn_recipe_particles();
                self->m_3c++;
                self->m_38 = 0;
            } else {
                self->m_38++;
            }
            break;
        default:
            if (self->m_38 == r->m_24) {
                ((TItemEffShield *)self)->spawn_recipe_particles();
                self->m_3c++;
                self->m_38 = 0;
            } else {
                self->m_38++;
            }
            break;
        }
    } else {
        queue_destruction__7TObjectFv(self);
    }
}

u8 *__ct__14TItemEffShieldFv(u8 *object, u8 *arg1, s16 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__14TItemEffShield.value;
    *(s32 *)((s8 *)object + 0) = (s32) TItemEffShield__class_name;
    *(s32 *)((s8 *)object + 0x34) = arg3;
    *(s16 *)((s8 *)object + 0x44) = arg2;
    *(s32 *)((s8 *)object + 0x38) = 0;
    *(s32 *)((s8 *)object + 0x3C) = 0;
    *(s32 *)((s8 *)object + 0x40) = 0x24;
    disallow_rendering__7TObjectFv((TObject *)object);
    return object;
}

