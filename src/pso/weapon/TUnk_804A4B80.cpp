#include "types.h"
#include "pso/weapon/TUnk_804A4B80.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/item/TItemEffHeaven.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_8012AE50.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012AEA8.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_80011014.h"


struct VBase_18_382324
{
  char pad[0x18];
};

struct VObj_18_382324 : VBase_18_382324 {
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
    virtual s32 m49(void *, s32, s32, s32);
};

struct RecoveredFields_8012ABCC_arg0
{
  u8 unknown_0[0xF0];
  uaddr field_F0;
};

extern "C" {
u32 *copy_attack_targets(u32 *dst, u32 *src);
extern saddr tl_05;

typedef struct RecoveredFields_8012ABCC_arg0 RecoveredFields_8012ABCC_arg0;
typedef struct VBase_18_382324 VBase_18_382324;
typedef struct VObj_18_382324 VObj_18_382324;
void TUnk_804A4B80::activate_effect(s32 arg1) {
  if (((u32) ((RecoveredFields_8012ABCC_arg0 *) ((u8 *)this))->field_F0) != 0U)
  {
    if (is_current_area_item_enabled() != 0)
    {
      if (get_current_floor() == ((TObjPlayer *)((saddr) ((RecoveredFields_8012ABCC_arg0 *) ((u8 *)this))->field_F0))->get_floor())
      {
        if (arg1 == 0)
        {
          (this->launch_shot((u8 *)&captured_muzzle, (0), (0), (1)));
          return;
        }
        if (arg1 == 1)
        {
          heaven_punisher_strike_locks();
        }
      }
    }
  }
}

void TUnk_804A4B80::heaven_punisher_strike_locks() {
    Vec muzzle;
    s32 v;
    s32 i;
    CapturedTarget *e;
    if (captured_targets.get_captured_target_count() > 0) {
        for (i = 0; i != captured_targets.get_captured_target_count(); i++) {
            e = captured_targets.get_captured_target_entry(i);
            v = e->get_captured_target_collider_index();
            spawn_heaven_effect((TObject *)tl_05, owner, e->get_uid(), v);
        }
    } else {
        get_gun_point(&muzzle);
        launch_shot(reinterpret_cast<u8 *>(&muzzle), 0, 0, 1);
    }
}

void TUnk_804A4B80::emit_marker_effects() {
    Vec origin;
    s32 effect;
    if (is_mode_two_and_ready() != 0) {
        copy_attack_targets((u32 *)&captured_targets, (u32 *)owner->get_extended_state());
        get_gun_point(&captured_muzzle);
        effect = 0;
        if (!((TLobby::get_internet_beat() / 100) & 1)) {
            effect = 1;
        }
        send_activate_effect(effect);
        return;
    }
    this->get_gun_point(&origin);
    this->launch_shot((u8 *)&origin, 0, 0, 1);
}
u32 *copy_attack_targets(u32 *dst, u32 *src) {
    u32 *d = dst;
    u32 b;
    u32 a;
    s32 i;
    *dst = *src;
    for (i = 0; i < 0x5; i++) {
        a = src[1];
        b = *(src += 2);
        d[1] = a;
        *(d += 2) = b;
    }
    return dst;
}

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *, s32, s32);
}

extern s32 __vt__13TUnk_804A4B80[];

void *heaven_punisher_ct(void *player, s32 parent, s32 item) {
    __ct__11TItemWeaponFP7TObjectPUc(player, parent, item);
    *(s32 **)((s8 *)player + 0x18) = __vt__13TUnk_804A4B80;
    TObjPlayer__sub_8012AF00((CapturedTargetList *)((char *)player + 504));
    ((TItemWeapon *)player)->set_weapon_flags(34);
    return player;
}
TItem *create_heaven_punisher(u8 *item) {
    u8 *player;
    u8 *var_r0;
    if (item != NULL) {
        player = (u8 *)TItem::operator new(0x230);
        var_r0 = player;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(heaven_punisher_ct(player, tl_05, (saddr)item));
        }
        return reinterpret_cast<TItem *>(var_r0);
    }
    return NULL;
}


TUnk_804A4B80::~TUnk_804A4B80() {}

extern "C" {
void *__construct_array(void *, void *, void *, u32, u32);
CapturedTargetList *TObjPlayer__sub_8012AF00(CapturedTargetList *self) {
    __construct_array(self->entries, (void *)TObjPlayer__sub_8012AF50, 0, 4, 10);
    self->clear_lockon_list();
    return self;
}

CapturedTarget *TObjPlayer__sub_8012AF50(CapturedTarget *self) {
    self->fn_8012AF80();
    return self;
}
}

void CapturedTarget::fn_8012AF80() {
    uid = 0xffff;
    collider_index = 0;
}
