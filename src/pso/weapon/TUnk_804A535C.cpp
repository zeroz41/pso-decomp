#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TItemWeaponRocketPunch.h"
#include "pso/player/TObjPlayer_8012C3F4.h"
#include "pso/weapon/shoot/TItemShootRocketPunch.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/shoot/TItemShootModel.h"
#include "pso/player/TObjPlayer_8012C548.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"

#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"
#include "pso/system/task/TMainTask.h"

struct TargetEntityPosition {
    u8 pad[0x1c];
    u8 position[0x10];
};

struct TargetEntityManager {
    u8 pad[0xa4];
    TargetEntityPosition *ents;
    s32 count;
};

extern "C" {
TargetEntityManager *find_entity_by_id(u32);
}

void rocket_punch_target_impact(void *self, u32 weapon, u32 target, s32 extra) {
    TargetEntityManager *m;
    rocket_punch_return_timer(weapon);
    m = find_entity_by_id(target);
    if (m && m->ents && extra < m->count) {
        spawn_particle_effect((const Vec *)m->ents[extra].position, 0x45);
    }
}

void rocket_punch_wall_impact(u32 layer, u32 weapon, u32 target, uaddr pos) {
    if ((weapon != 0U) && (pos != 0U)) {
        rocket_punch_return_timer(weapon);
        spawn_particle_effect((const Vec *)pos, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}
extern "C" s32 post_translate_matrix(void *);

void TItemShootRocketPunch::render() {
    u8 *self = (u8 *)this;
    if ((TItemShootModel::is_owner_alive() != 0) && ((uaddr) this->model != 0U) && ((uaddr) this->texture_list != 0U)) {
        push_matrix();
        set_texlist(this->texture_list);
        post_translate_matrix(self + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28 - 0x4000);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}


void TItemShootRocketPunch::hook() {  }

TItemShootRocketPunch::TItemShootRocketPunch(TItemWeaponRocketPunch *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    set_render_model(owner->get_shot_model(), (NJS_TEXLIST *)owner->get_texlist());
}

uaddr rocket_punch_create_shot(saddr owner, saddr pos, saddr dir, f32 life) {
    TItemShootRocketPunch *shot = NULL;
    TItemShootParticle *particle;

    if (owner != 0) {
        shot = new TItemShootRocketPunch((TItemWeaponRocketPunch *)owner, (const Vec *)pos, (const Vec *)dir, life);
        particle = (TItemShootParticle *)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
        if ((shot != NULL) && (particle != NULL)) {
            particle->spawn_slot_emitter(0x1BB, 0);
            particle->set_parent(shot);
        }
    }
    return (uaddr)shot;
}

void TItemWeaponRocketPunch::emit_marker_effects() {
    saddr burst_counter;
    s32 burst_count;
    TObjPlayer *player = owner;
    if (player == NULL) return;
    burst_counter = (saddr)player + 0x7CC;
    if (get_burst_counter((void *)burst_counter) == 0) {
        burst_count = 0;
        do {
            increment_burst_counter((u8 *)burst_counter);
            burst_count += 1;
        } while (burst_count != 2);
        punch_flags.set(2);
        TItemAttacker::spawn_item_timer(this, (ItemTimerCallback)rocket_punch_return_timer, 0x3C);
        punch_flags.set(4);
        if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) == 1) {
            punch_flags.clear(4);
            launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
            return;
        }
        punch_flags.clear(4);
        launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
    }
}

void TItemWeaponRocketPunch::vfunc_60() {
    void *model;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any(&punch_flags.bits, 2) == 0) {
            if (test_flags_any(&punch_flags.bits, 1)) {
                model = second_model;
            } else {
                model = model_data[1];
            }
            if (model) {
                draw_ginja_object(model);
            }
        }
        break;
    }
}

void TItemWeaponRocketPunch::reserved_53() {
    NJS_OBJECT *saved_model = item_model;
    punch_flags.set(1);
    draw_weapon_model();
    get_joint_position(1, &shot_origins[0]);
    item_model = (NJS_OBJECT *)model_data[0];
    punch_flags.clear(1);
    draw_weapon_at_joint((saddr)this, 0x23);
    get_joint_position(1, &shot_origins[1]);
    item_model = saved_model;
}

TItemWeaponRocketPunch::~TItemWeaponRocketPunch() {

}

TItemWeaponRocketPunch::TItemWeaponRocketPunch(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    effect_flags.set(32);
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)rocket_punch_wall_impact;
    hit_callback = (WeaponHitCallback)rocket_punch_target_impact;
    shot_callback = (WeaponShotCallback)rocket_punch_create_shot;
    shot_speed = 8.0f;
    punch_flags.reset();
}

TItem *TObjPlayer::create_trade_action_state(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponRocketPunch(tl_05, item);
    }
    return NULL;
}

TItemShootRocketPunch::~TItemShootRocketPunch() {

}

void rocket_punch_return_timer(uaddr weapon) {
    if (weapon != 0U) {
        ((TItemWeaponRocketPunch *)weapon)->punch_flags.clear(2);
    }
}

NJS_OBJECT *TItemWeaponRocketPunch::get_shot_model() {
    if (test_flags_any(&punch_flags.bits, 4) != 0) {
        return second_model;
    }
    return (NJS_OBJECT *)model_data[1];
}
