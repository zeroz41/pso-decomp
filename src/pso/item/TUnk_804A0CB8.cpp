#include "types.h"
#include "pso/item/TUnk_804A0CB8.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemShootParticle.h"
#include "pso/player/TObjPlayer_80122014.h"
#include "pso/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/TObject.h"
#include "pso/TMainTask.h"

extern "C" {
u32 spawn_shoot_particle__10TObjPlayerFUlllf(void *, s32, s32, f32);
u32 create_shoot_model__10TObjPlayerFUiiif();
}

void TUnk_804A0CB8::emit_marker_effects() {
    WeaponVector v;
    if (is_mode_two_and_ready() != 0) {
        shot_callback = (WeaponShotCallback)belra_cannon_create_extra_shot;
        shot_ready = 0;
        TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)belra_cannon_return_timer, 0x1E);
        ((TObjPlayer *)this)->launch_rare_weapon_special(0, 1, 1.0f);
    } else {
        shot_callback = (WeaponShotCallback)belra_cannon_create_shot;
        shot_ready = 0;
        TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)belra_cannon_return_timer, 0x1E);
        get_joint_position(1, &v);
        launch_shot((u8 *)&v, 0, 0, 1);
    }
}

void TUnk_804A0CB8::update_weapon() {
    NJS_OBJECT *model = item_model;
    if (model != NULL) {
        NJS_OBJECT *child = model->child;
        u32 flags = child->evalflags;
        if (shot_ready == 1) {
            if (flags & 8) {
                child->evalflags = flags & ~8;
            }
        } else if (!(flags & 8)) {
            child->evalflags = flags | 8;
        }
    }
}

u32 belra_cannon_create_extra_shot(void *player, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r3;
    u32 temp_r31;
    u32 temp_r30;
    void *temp_r5;

    temp_r31 = create_shoot_model__10TObjPlayerFUiiif();
    temp_r30 = spawn_shoot_particle__10TObjPlayerFUlllf(player, arg1, arg2, farg0);
    if ((temp_r31 != 0U) && (temp_r30 != 0U)) {
        temp_r5 = *(void **)((s8 *)player + 0x188);
        if (temp_r5 != NULL) {
            temp_r3 = *(s32 *)((s8 *)temp_r5 + 0);
            if ((u32) (temp_r3 & 7) == 7) {
                *(s32 *)((s8 *)temp_r5 + 0) = (s32) (temp_r3 & 0xFFFFFFFD);
                *(s32 *)((s8 *)temp_r5 + 0x14) = -0x4000;
                *(s32 *)((s8 *)temp_r5 + 0x1C) = 0x8000;
            }
        }
        ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0xDD, 0);
        ((TObject *)temp_r30)->set_parent((TObject *)temp_r31);
    }
    return temp_r31;
}

long belra_cannon_create_shot(u8 *arg0) {
  s32 temp_r4;
  u8 *temp_r6;
  if (create_shoot_model__10TObjPlayerFUiiif() != 0U)
  {
    temp_r6 = (unsigned char *) (*((void **) (((s8 *) arg0) + 0x188)));
    if (temp_r6 != 0)
    {
      temp_r4 = *((s32 *) (((s8 *) temp_r6) + 0));
      if (((u32) (temp_r4 & 7)) == 7)
      {
        *((s32 *) (((s8 *) temp_r6) + 0)) = (s32) (temp_r4 & 0xFFFFFFFD);
        *((s32 *) (((s8 *) temp_r6) + 0x14)) = -0x4000;
        *((s32 *) (((s8 *) temp_r6) + 0x1C)) = 0x8000;
      }
    }
  }
}

TUnk_804A0CB8::~TUnk_804A0CB8() {}

TUnk_804A0CB8::TUnk_804A0CB8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    shot_speed = 7.0f;
    set_weapon_flags(2);
    shot_ready = 1;
}

u8 *create_belra_cannon(u8 *arg0) {
    if (arg0 != NULL) {
        return (u8 *)new TUnk_804A0CB8(tl_05, arg0);
    }
    return NULL;
}
