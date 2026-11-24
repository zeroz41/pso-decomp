#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_80126104.h"
#include "pso/weapon/TUnk_804A2960.h"
#include "pso/item/TUnk_804A05E8.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/armor/TItemProArmor.h"
#include "pso/item/TItemHeapObject.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_80011014.h"

struct VBase_18_f15a7b { char pad[0x18]; };

struct VObj_18_f15a7b : VBase_18_f15a7b {
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
    virtual s32 m46(s32);
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
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual s32 m72(s32);
};

#pragma push
#pragma fp_contract on
void frozen_shooter_freeze_hit(int arg0, u8 *arg1) {
    u8 *temp_r31;
    if (arg1 != NULL && obj_is_hit_receivable(*reinterpret_cast<TObjCollidable **>(arg1)) != 0) {
        temp_r31 = (u8 *)(*(u8 **)((s8 *)arg1 + 0));
        ((VObj_18_f15a7b *)(temp_r31))->m46(*(s32 *)((s8 *)temp_r31 + 0xA4) + (*(s32 *)((s8 *)arg1 + 4) * 0x2C));
        ((VObj_18_f15a7b *)(temp_r31))->m72(0);
    }
}
#pragma pop

void TUnk_804A2960::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    if (skip_freeze == 0) {
        desc->hit_effect = (void *)frozen_shooter_freeze_hit;
    }
    desc->hits = unk_1f8;
    desc->spin[0] = 0x4000;
    desc->scale = 2.0f;
    desc->particle = unk_200;
}

void TUnk_804A2960::emit_marker_effects() {
    Vec point;
    u8 *p;
    get_gun_point(&point);
    skip_freeze = 0;
    p = reinterpret_cast<u8 *>(&point);
    if (is_mode_two_and_ready() != 0) {
        fire_shot_at_target(p, second_model, 0);
    } else if (get_item_index() == 1) {
        skip_freeze = 1;
        fire_shot_at_target(p, second_model, 0);
    } else {
        launch_shot(p, 0, 0, 1);
    }
}

// Starts the freeze curse timer on the equip effect objects.
void TUnk_804A2960::on_equipped() {
    if (effect_objects != NULL) {
        new TUnk_804A05E8(effect_objects, get_owner_client(), 0xE10, 0.25f);
    }
}

TUnk_804A2960::~TUnk_804A2960() {}


TUnk_804A2960::TUnk_804A2960(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(0x22);
    if (get_item_index() == 1) {
        unk_1f8 = 10;
        unk_200 = 0x1F5;
    } else {
        unk_1f8 = 1;
        unk_200 = 0x95;
    }
    skip_freeze = 0;
}

TItem *frozen_shooter_create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A2960(tl_05, item);
    }
    return NULL;
}

// This object's copy of the freeze curse timer's constructor (on_equipped
// calls it first).
TUnk_804A05E8::TUnk_804A05E8(TItemHeapObject *parent, u16 client, s32 period, f32 rate)
    : TItemTimerEvent(parent, client, period) {
    unk_2C = rate;
}
