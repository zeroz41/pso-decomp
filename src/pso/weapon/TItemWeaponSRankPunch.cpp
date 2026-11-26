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
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItem.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"

struct Elem_80128A74 { u8 pad[0x1c]; u8 position[0x2c - 0x1c]; };

struct Obj_80128A74 { u8 pad[0xa4]; Elem_80128A74 *elems; s32 count; };

extern "C" {
Obj_80128A74 *find_entity_by_id(s32);

void TObjPlayer__sub_80128A70(void) {  }

void s_rank_punch_hit_effect(s32 layer, uaddr player, s32 target_id, s32 body) {
    Obj_80128A74 *o;
    TItemWeaponSRankPunch::clear_rico_ring_flag((TObject *)player);
    o = find_entity_by_id(target_id);
    if (o != 0 && o->elems != 0 && body < o->count) {
        spawn_particle_effect((const Vec *)o->elems[body].position, 0x45);
    }
}

}

void TObjPlayer::notify_hit_target(u32 arg0, uaddr player, u32 arg2, uaddr pos) {
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

u32 TObjPlayer::spawn_shot_effect(saddr owner, saddr origin, saddr end, f32 frames) {
    TItemShootSRankPunch *model = NULL;
    TItemShootParticle *particle;
    if (owner != 0) {
        model = new TItemShootSRankPunch((void *)owner, (const Vec *)origin, (const Vec *)end, frames);
        particle = (TItemShootParticle *)spawn_shoot_particle(owner, origin, end, frames);
        if ((model != NULL) && (particle != NULL)) {
            particle->spawn_slot_emitter(0x1BB, 0);
            ((TObject *)particle)->set_parent(model);
        }
    }
    return (uaddr)model;
}

extern "C" {

void TItemWeaponSRankPunch::emit_marker_effects() {
    PlayerAttackController *attack_state;
    s32 i;
    TObjPlayer *player;
    TObjPlayer__sub_80128A70();
    player = owner;
    if (player == NULL) return;
    attack_state = &player->attack_state;
    if (get_burst_counter(attack_state) == 0) {
        i = 0;
        do {
            increment_burst_counter((u8 *)attack_state);
            i += 1;
        } while (i != 2);
        this->flags.set(2);
        TItemAttacker::spawn_item_timer(this, clear_rico_ring_flag, 0x3C);
        this->flags.set(4);
        if (launch_shot((u8 *)&shot_origins[0], 0, 0, 1) == 1) {
            this->flags.clear(4);
            launch_shot((u8 *)&shot_origins[1], 0, 0, 0);
            return;
        }
        this->flags.clear(4);
        launch_shot((u8 *)&shot_origins[1], 0, 0, 1);
    }
}

void TItemWeaponSRankPunch::transform_model_node() {
    void *p;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any((s32 *)&flags, 2) == 0) {
            if (test_flags_any((s32 *)&flags, 1)) {
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
    draw_weapon_at_joint((saddr)this, 0x30);
    get_joint_position(1, &shot_origins[0]);
    item_model = (NJS_OBJECT *)model_data[0];
    this->flags.clear(1);
    draw_weapon_at_joint((saddr)this, 0x23);
    get_joint_position(1, &shot_origins[1]);
    item_model = saved_model;
}

TItemWeaponSRankPunch::~TItemWeaponSRankPunch() {}

TItemWeaponSRankPunch::TItemWeaponSRankPunch(TObject *parent, u8 *item) : TItemWeaponSRank(parent, item) {
    this->effect_flags.set(32);
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)TObjPlayer::notify_hit_target;
    hit_callback = (WeaponHitCallback)s_rank_punch_hit_effect;
    shot_callback = (WeaponShotCallback)TObjPlayer::spawn_shot_effect;
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
    if (test_flags_any((s32 *)&punch->flags, 4) != 0) {
        return punch->second_model;
    }
    return (NJS_OBJECT *)punch->model_data[1];
}


void TItemShootModel::set_render_model(NJS_OBJECT *new_model, NJS_TEXLIST *new_texture_list) {
    model = new_model;
    texture_list = new_texture_list;
}
