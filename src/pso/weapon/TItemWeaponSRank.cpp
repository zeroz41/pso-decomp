#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeaponSRank.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/item/armor/TItemProShield.h"
#include "pso/item/TItemTimerEventTpRegen.h"
#include "pso/item/TItemTimerEventHpRegen.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/CapturedTargetList.h"

extern "C" {

s32 resolve_hittable_target(s32, s32);

}


TItem *TItemWeaponSRank::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRank(tl_05, item);
    }
    return NULL;
}

TItemWeaponSRank::TItemWeaponSRank(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
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

TItemWeaponSRank::~TItemWeaponSRank() {}

void TItemWeaponSRank::on_equipped() {
    switch (kind) {
    case 3:
        new TItemTimerEventHpRegen(effect_objects, get_owner_client(), 0x5A);
        return;
    case 4:
        new TItemTimerEventTpRegen(effect_objects, get_owner_client(), 0x5A);
        break;
    }
}

void TItemWeaponSRank::emit_marker_effects() {
  Vec gun_point;
  s32 weapon_kind;
  s32 attack_flags;
  (this->start_attack_effect());
  attack_flags = (this->get_attack_flags());
  if (attack_flags & 1)
  {
    weapon_kind = this->kind;
    if (weapon_kind < 3)
    {
      if (weapon_kind < 1)
      {
        if ((this && this) && this)
        {
        }
        goto block_7;
      }
      if (this->is_mode_two_and_ready() != 0)
      {
        this->send_srank_stat_extra_to_locks();
        return;
      }
      this->update_active_game_effect();
      return;
    }
    block_7:
    this->update_active_game_effect();
    return;
  }
  if (attack_flags & 2)
  {
    this->get_gun_point(&gun_point);
    (this->launch_shot(&gun_point, (0), (0), (1)));
  }
}

void TItemWeaponSRank::deliver_hit(TObjPlayer *attacker, TObjChara *target, s32 attack_kind, f32 scale, s32 body) {
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


void TItemWeaponSRank::send_srank_stat_extra(uaddr target, s32 body) {
    TObjChara *obj = (TObjChara *)target;
    TObjPlayer *sender;
    DirectAttackPayload t1;
    DirectAttackPayload t2;
    if (obj != NULL && (sender = owner) != NULL) {
        switch (kind) {
        case 1: {
            t1.kind = 0xB;
            t1.power = 16.0f;
            DirectAttackPayload p = t1;
            obj->receive_direct_attack(sender, p, &obj->bodies[body], -1, -1);
            break;
        }
        case 2: {
            t2.kind = 0xC;
            t2.power = 32.0f;
            DirectAttackPayload p = t2;
            obj->receive_direct_attack(sender, p, &obj->bodies[body], -1, -1);
            break;
        }
        }
    }
}
void TItemWeaponSRank::send_srank_stat_extra_to_locks() {
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
