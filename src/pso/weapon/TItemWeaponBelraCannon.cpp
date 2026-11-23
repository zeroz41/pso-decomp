#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804A0CB8.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/player/TObjPlayer_80122014.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

void TUnk_804A0CB8::emit_marker_effects() {
    WeaponVector v;
    if (is_mode_two_and_ready() != 0) {
        shot_callback = (WeaponShotCallback)belra_cannon_create_extra_shot;
        shot_ready = 0;
        TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)belra_cannon_return_timer, 0x1E);
        launch_rare_weapon_special(0, 1, 1.0f);
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

u32 belra_cannon_create_extra_shot(void *player, s32 pos, s32 dir, f32 life) {
    uaddr model_shot;
    uaddr particle_shot;
    NJS_OBJECT *model;
    u32 flags;

    model_shot = TObjPlayer::create_shoot_model((uaddr)player, pos, dir, life);
    particle_shot = (uaddr)TObjPlayer::spawn_shoot_particle((saddr)player, pos, dir, life);
    if ((model_shot != 0U) && (particle_shot != 0U)) {
        model = ((TItemWeapon *)player)->second_model;
        if (model != NULL) {
            flags = model->evalflags;
            if ((flags & (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL)) == (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL)) {
                model->evalflags = flags & ~NJD_EVAL_UNIT_ANG;
                model->ang[0] = -0x4000;
                model->ang[2] = 0x8000;
            }
        }
        ((TItemShootParticle *)particle_shot)->spawn_slot_emitter(0xDD, 0);
        ((TObject *)particle_shot)->set_parent((TObject *)model_shot);
    }
    return model_shot;
}

saddr belra_cannon_create_shot(void *owner, s32 pos, s32 dir, f32 life) {
    uaddr shot = TObjPlayer::create_shoot_model((uaddr)owner, pos, dir, life);
    if (shot != 0) {
        NJS_OBJECT *model = ((TItemWeapon *)owner)->second_model;
        if (model != NULL) {
            u32 flags = model->evalflags;
            if ((flags & (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL)) == (NJD_EVAL_UNIT_POS | NJD_EVAL_UNIT_ANG | NJD_EVAL_UNIT_SCL)) {
                model->evalflags = flags & ~NJD_EVAL_UNIT_ANG;
                model->ang[0] = -0x4000;
                model->ang[2] = 0x8000;
            }
        }
    }
    return shot;
}

TUnk_804A0CB8::~TUnk_804A0CB8() {}

TUnk_804A0CB8::TUnk_804A0CB8(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    shot_speed = 7.0f;
    set_weapon_flags(2);
    shot_ready = 1;
}

TItem *create_belra_cannon(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A0CB8(tl_05, item);
    }
    return NULL;
}
