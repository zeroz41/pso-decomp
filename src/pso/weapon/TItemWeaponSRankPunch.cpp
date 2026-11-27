#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/TItemWeaponSRankPunch.h"
#include "pso/weapon/shoot/TItemShootSRankPunch.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixReflect.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"

extern "C" {
TObjCollidable *find_entity_by_id(s32);
}

void debug_weapon_attack_hook(void) {  }

void s_rank_punch_hit_effect(s32 layer, TObject *player, s32 target_id, s32 body) {
    TObjCollidable *o;
    TItemWeaponSRankPunch::clear_rico_ring_flag(player);
    o = find_entity_by_id(target_id);
    if (o != 0 && o->bodies != 0 && body < o->body_count) {
        spawn_particle_effect(&o->bodies[body].center, 0x45);
    }
}

void TObjPlayer::notify_hit_target(u32 layer, uaddr player, u32 target, uaddr pos) {
    if ((player != 0U) && (pos != 0U)) {
        TItemWeaponSRankPunch::clear_rico_ring_flag((TObject *)player);
        spawn_particle_effect((const Vec *)pos, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}

void TItemShootSRankPunch::render() {
    if ((is_owner_alive() != 0) && ((uaddr)model != 0U) && ((uaddr)texture_list != 0U)) {
        push_matrix();
        set_texlist(texture_list);
        post_translate_matrix(&m_pos.x);
        rotate_matrix_y(NULL, rot_y);
        rotate_matrix_x(NULL, rot_x - 0x4000);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void TItemShootSRankPunch::hook() {  }

TItemShootSRankPunch::TItemShootSRankPunch(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    set_render_model(get_punch_shot_model((u8 *)owner), (NJS_TEXLIST *)((TObjBase *)owner)->get_texlist());
}

TItemShoot *TObjPlayer::spawn_shot_effect(TItemWeapon *owner, const Vec *origin, const Vec *end, f32 frames) {
    TItemShootSRankPunch *model = NULL;
    TItemShootParticle *particle;
    if (owner != NULL) {
        model = new TItemShootSRankPunch(owner, origin, end, frames);
        particle = spawn_shoot_particle(owner, origin, end, frames);
        if ((model != NULL) && (particle != NULL)) {
            particle->spawn_slot_emitter(0x1BB, 0);
            particle->set_parent(model);
        }
    }
    return model;
}

extern "C" {

void TItemWeaponSRankPunch::emit_marker_effects() {
    PlayerAttackController *attack_state;
    s32 i;
    TObjPlayer *player;
    debug_weapon_attack_hook();
    player = owner;
    if (player == NULL) return;
    attack_state = &player->attack_state;
    if (attack_state->get_burst_counter() == 0) {
        i = 0;
        do {
            attack_state->increment_burst_counter();
            i += 1;
        } while (i != 2);
        this->flags.set(2);
        TItemAttacker::spawn_item_timer(this, clear_rico_ring_flag, 0x3C);
        this->flags.set(4);
        if (launch_shot(&shot_origins[0], 0, 0, 1) == 1) {
            this->flags.clear(4);
            launch_shot(&shot_origins[1], 0, 0, 0);
            return;
        }
        this->flags.clear(4);
        launch_shot(&shot_origins[1], 0, 0, 1);
    }
}

void TItemWeaponSRankPunch::transform_model_node() {
    NJS_OBJECT *p;
    switch (get_model_node_counter()) {
    case 1:
        if (flags.test_flags_any(2) == 0) {
            if (flags.test_flags_any(1)) {
                p = second_model;
            } else {
                p = model_data[1];
            }
            if (p) {
                draw_ginja_object(p);
            }
        }
        break;
    }
}

}

void TItemWeaponSRankPunch::draw_held_model() {
    NJS_OBJECT *saved_model;

    saved_model = item_model;
    this->flags.set(1);
    draw_weapon_at_joint(0x30);
    get_joint_position(1, &shot_origins[0]);
    item_model = model_data[0];
    this->flags.clear(1);
    draw_weapon_at_joint(0x23);
    get_joint_position(1, &shot_origins[1]);
    item_model = saved_model;
}

TItemWeaponSRankPunch::~TItemWeaponSRankPunch() {}

TItemWeaponSRankPunch::TItemWeaponSRankPunch(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    this->effect_flags.set(32);
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)TObjPlayer::notify_hit_target;
    hit_callback = (WeaponHitCallback)s_rank_punch_hit_effect;
    shot_callback = TObjPlayer::spawn_shot_effect;
    shot_speed = 10.0f;
    flags.reset();
}

TItem *TItemWeaponSRankPunch::create(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponSRankPunch(tl_05, item);
    }
    return NULL;
}

TItemShootSRankPunch::~TItemShootSRankPunch() {

}

void TItemWeaponSRankPunch::clear_rico_ring_flag(TObject *object) {
    TItemWeaponSRankPunch *weapon = (TItemWeaponSRankPunch *)object;
    if (weapon != NULL) {
        weapon->flags.clear(2);
    }
}


NJS_OBJECT *get_punch_shot_model(u8 *weapon) {
    TItemWeaponSRankPunch *punch = (TItemWeaponSRankPunch *)weapon;
    if (punch->flags.test_flags_any(4) != 0) {
        return punch->second_model;
    }
    return punch->model_data[1];
}


void TItemShootModel::set_render_model(NJS_OBJECT *new_model, NJS_TEXLIST *new_texture_list) {
    model = new_model;
    texture_list = new_texture_list;
}
