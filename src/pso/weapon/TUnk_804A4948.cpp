#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TUnk_804A4948.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_8012105C.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/TUnk_804A0628.h"
#include "pso/item/TUnk_804A0648.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"

// The (kind, value) pair send_srank_stat_extra hands to its target.
struct StatExtraParam { s32 kind; f32 val; };

struct StatExtraTargetBase { char pad[0x18]; };

// View onto the stat-extra target: recs is its per-body record table, 0x2C a record.
struct StatExtraTargetView : StatExtraTargetBase {
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
    virtual void m21(u32, StatExtraParam *, u8 *, s32, s32);
    u8 pad1c[0xA4 - 0x1C];
    u8 *recs;
};

extern "C" {

s32 resolve_hittable_target(s32, s32);

}


TItem *TObjPlayer::create_srank_common_weapon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A4948(tl_05, item);
    }
    return NULL;
}

TUnk_804A4948::TUnk_804A4948(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
    kind = get_item_index();
    switch (kind) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
    case 2:
        set_weapon_flags(0x400000);
        set_special_selector(0x1A);
        break;
    case 5:
        set_special_selector(0x1A);
        break;
    case 6:
        set_special_selector(0x1E);
        break;
    case 7:
        set_special_selector(0x12);
        break;
    case 8:
        set_special_selector(0x16);
        break;
    case 9:
        set_special_selector(0x26);
        break;
    case 10:
        set_special_selector(0x22);
        break;
    case 11:
        set_special_selector(0xD);
        break;
    case 12:
        set_special_selector(0xE);
        break;
    case 13:
        set_special_selector(0x28);
        break;
    case 14:
        set_special_selector(4);
        break;
    case 15:
        set_special_selector(8);
        break;
    case 16:
        set_special_selector(0xB);
        break;
    default:
        set_special_selector(0);
        break;
    }
}

TUnk_804A4948::~TUnk_804A4948() {}

void TUnk_804A4948::on_equipped() {
    switch (kind) {
    case 3:
        new TUnk_804A0648(effect_objects, get_owner_client(), 0x5A);
        return;
    case 4:
        new TUnk_804A0628(effect_objects, get_owner_client(), 0x5A);
        break;
    }
}

void TUnk_804A4948::emit_marker_effects() {
  u8 *self_bytes = (u8 *)this;
  Vec gun_point;
  s32 weapon_kind;
  s32 attack_flags;
  s32 new_var;
  (this->vfunc_62());
  attack_flags = (this->get_attack_flags());
  if (attack_flags & 1)
  {
    weapon_kind = this->kind;
    if (weapon_kind < 3)
    {
      if (weapon_kind < 1)
      {
        if ((self_bytes && self_bytes) && self_bytes)
        {
        }
        goto block_7;
      }
      if (((TItemWeapon *)self_bytes)->is_mode_two_and_ready() != 0)
      {
        ((TUnk_804A4948 *)self_bytes)->send_srank_stat_extra_to_locks();
        return;
      }
      ((TItemWeapon *)self_bytes)->update_active_game_effect();
      return;
    }
    block_7:
    ((TItemWeapon *)self_bytes)->update_active_game_effect();
    return;
  }
  if ((new_var = attack_flags) & 2)
  {
    ((TItemWeapon *)self_bytes)->get_gun_point(&gun_point);
    (this->launch_shot((u8 *)(&gun_point), (0), (0), (1)));
  }
}

void TUnk_804A4948::deliver_hit(TObjPlayer *attacker, TObjChara *target, s32 attack_kind, f32 scale, s32 body) {
    TObjPlayer *player;
    if (get_mode() == 2) {
        player = owner;
        if ((player != NULL) && (target != NULL)) {
            switch (kind) {
            case 1:
            case 2:
                if (attack_kind == 2) {
                    send_srank_stat_extra((uaddr)target, body);
                } else {
                    TItemWeapon::deliver_hit(player, target, attack_kind, scale, body);
                }
                break;
            default:
                TItemWeapon::deliver_hit(player, target, attack_kind, scale, body);
                break;
            }
        }
    }
}


void TUnk_804A4948::send_srank_stat_extra(uaddr target, s32 body) {
    StatExtraTargetView *obj = (StatExtraTargetView *)target;
    u32 sender;
    StatExtraParam t1;
    StatExtraParam t2;
    if (obj != NULL && (sender = (u32)owner) != 0) {
        switch (kind) {
        case 1: {
            t1.kind = 0xB;
            t1.val = 16.0f;
            StatExtraParam p = t1;
            obj->m21(sender, &p, obj->recs + body * 0x2C, -1, -1);
            break;
        }
        case 2: {
            t2.kind = 0xC;
            t2.val = 32.0f;
            StatExtraParam p = t2;
            obj->m21(sender, &p, obj->recs + body * 0x2C, -1, -1);
            break;
        }
        }
    }
}
void TUnk_804A4948::send_srank_stat_extra_to_locks() {
  CapturedTargetList *st;
  s32 i;
  CapturedTarget *e;
  u16 uid;
  s32 r;
  s32 v;
  st = owner->get_extended_state();
  if (st != 0)
  {
    for (i = 0; i != st->get_captured_target_count(); i++)
    {
      e = st->get_captured_target_entry(i);
      uid = e->get_uid();
      v = e->get_captured_target_collider_index();
      r = resolve_hittable_target(uid, v);
      if (r != 0)
      {
        this->send_srank_stat_extra(r, v);
      }
    }
  }
}
