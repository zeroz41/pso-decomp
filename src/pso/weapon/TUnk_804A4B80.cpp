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


extern "C" {
u32 *copy_attack_targets(u32 *dst, u32 *src);
s32 get_captured_target_collider_index(s32);
s32 get_captured_target_entry(void *, s32);
s32 get_captured_target_count(void *);
extern saddr tl_05;

void TUnk_804A4B80::activate_effect(s32 effect_variant) {
  if (owner != NULL)
  {
    if (is_current_area_item_enabled() != 0)
    {
      if (get_current_floor() == owner->get_floor())
      {
        if (effect_variant == 0)
        {
          (this->launch_shot((u8 *)&captured_muzzle, (0), (0), (1)));
          return;
        }
        if (effect_variant == 1)
        {
          heaven_punisher_strike_locks();
        }
      }
    }
  }
}

void TUnk_804A4B80::heaven_punisher_strike_locks() {
    Vec muzzle;
    s16 v;
    s32 i;
    saddr e;
    if (get_captured_target_count(captured_targets) > 0) {
        for (i = 0; i != get_captured_target_count(captured_targets); i++) {
            e = get_captured_target_entry(captured_targets, i);
            v = get_captured_target_collider_index(e);
            spawn_heaven_effect((TObject *)tl_05, owner, ((TObjPlayer *)e)->get_uid(), v);
        }
    } else {
        get_gun_point(&muzzle);
        launch_shot(reinterpret_cast<u8 *>(&muzzle), 0, 0, 1);
    }
}

void TUnk_804A4B80::emit_marker_effects() {
    Vec sp8;
    s32 effect;
    if (is_mode_two_and_ready() != 0) {
        copy_attack_targets(captured_targets, reinterpret_cast<u32 *>(owner->get_extended_state()));
        get_gun_point(&captured_muzzle);
        effect = 0;
        if (!((TLobby::get_internet_beat() / 100) & 1)) {
            effect = 1;
        }
        send_activate_effect(effect);
        return;
    }
    this->get_gun_point(&sp8);
    this->launch_shot((u8 *)&sp8, 0, 0, 1);
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

struct Obj_8012AF00;

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *, s32, s32);
Obj_8012AF00 *TObjPlayer__sub_8012AF00(Obj_8012AF00 *self);
}

extern s32 __vt__13TUnk_804A4B80[];

void *heaven_punisher_ct(void *weapon, s32 parent, s32 item) {
    __ct__11TItemWeaponFP7TObjectPUc(weapon, parent, item);
    *(s32 **)((s8 *)weapon + 0x18) = __vt__13TUnk_804A4B80;
    TObjPlayer__sub_8012AF00((Obj_8012AF00 *)((char *)weapon + 504));
    ((TItemWeapon *)weapon)->set_weapon_flags(34);
    return weapon;
}
TItem *create_heaven_punisher(u8 *item) {
    u8 *weapon;
    u8 *created;
    if (item != NULL) {
        weapon = (u8 *)TItem::operator new(0x230);
        created = weapon;
        if (created != NULL) {
            created = (u8 *)(heaven_punisher_ct(weapon, tl_05, (saddr)item));
        }
        return reinterpret_cast<TItem *>(created);
    }
    return NULL;
}


TUnk_804A4B80::~TUnk_804A4B80() {}

struct Elem_8012AF00 { u8 b[4]; };

struct Obj_8012AF00 { u32 f0; Elem_8012AF00 arr[10]; };

struct Obj_8012AF80 { u16 a; u16 b; };

extern "C" {
void *__construct_array(void *, void *, void *, u32, u32);
void clear_lockon_list__10TObjPlayerFPvPvff(void *p);
Obj_8012AF80 *TObjPlayer__sub_8012AF50(Obj_8012AF80 *self);
Obj_8012AF00 *TObjPlayer__sub_8012AF00(Obj_8012AF00 *self) {
    __construct_array(self->arr, (void *)TObjPlayer__sub_8012AF50, 0, 4, 10);
    clear_lockon_list__10TObjPlayerFPvPvff(self);
    return self;
}

void TObjPlayer__sub_8012AF80(Obj_8012AF80 *self);

Obj_8012AF80 *TObjPlayer__sub_8012AF50(Obj_8012AF80 *self) {
    TObjPlayer__sub_8012AF80(self);
    return self;
}

void TObjPlayer__sub_8012AF80(Obj_8012AF80 *self) {
    self->a = 0xffff;
    self->b = 0;
}

}
