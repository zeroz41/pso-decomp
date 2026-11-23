#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TUnk_804A535C.h"
#include "pso/player/TObjPlayer_8012C3F4.h"
#include "pso/weapon/shoot/TUnk_804A5340.h"
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

struct Ent_8012C384 { u8 pad[0x1c]; u8 f1c[0x10]; };

struct Mylla_8012C384 { u8 pad[0xa4]; Ent_8012C384 *ents; s32 count; };

extern "C" {
Mylla_8012C384 *find_entity_by_id(u32);
}

void rocket_punch_target_impact(void *self, u32 a, u32 b, s32 idx) {
    Mylla_8012C384 *m;
    rocket_punch_return_timer(a);
    m = find_entity_by_id(b);
    if (m && m->ents && idx < m->count) {
        spawn_particle_effect((const Vec *)m->ents[idx].f1c, 0x45);
    }
}

void rocket_punch_wall_impact(u32 arg0, u32 arg1, u32 arg2, uaddr arg3) {
    if ((arg1 != 0U) && (arg3 != 0U)) {
        rocket_punch_return_timer(arg1);
        spawn_particle_effect((const Vec *)arg3, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}
extern "C" s32 post_translate_matrix(void *);

void TUnk_804A5340::render() {
    u8 *arg0 = (u8 *)this;
    if ((TItemShootModel::is_owner_alive() != 0) && ((uaddr) this->model != 0U) && ((uaddr) this->texture_list != 0U)) {
        push_matrix();
        set_texlist((uaddr)this->texture_list);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28 - 0x4000);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}


void TUnk_804A5340::hook() {  }

TUnk_804A5340::TUnk_804A5340(TUnk_804A535C *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    set_render_model(owner->fn_8012C9D8(), (GinjaTextureList *)owner->get_texlist());
}

uaddr rocket_punch_create_shot(saddr owner, saddr pos, saddr dir, f32 life) {
    TUnk_804A5340 *shot = NULL;
    TItemShootParticle *particle;

    if (owner != 0) {
        shot = new TUnk_804A5340((TUnk_804A535C *)owner, (const Vec *)pos, (const Vec *)dir, life);
        particle = (TItemShootParticle *)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
        if ((shot != NULL) && (particle != NULL)) {
            particle->spawn_slot_emitter(0x1BB, 0);
            particle->set_parent(shot);
        }
    }
    return (uaddr)shot;
}

void TUnk_804A535C::emit_marker_effects() {
    saddr counter;
    s32 i;
    TObjPlayer *player = owner;
    if (player == NULL) return;
    counter = (saddr)player + 0x7CC;
    if (get_burst_counter((void *)counter) == 0) {
        i = 0;
        do {
            increment_burst_counter((u8 *)counter);
            i += 1;
        } while (i != 2);
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

void TUnk_804A535C::vfunc_60() {
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

void TUnk_804A535C::reserved_53() {
    NJS_OBJECT *model = item_model;
    punch_flags.set(1);
    draw_weapon_model();
    get_joint_position(1, &shot_origins[0]);
    item_model = (NJS_OBJECT *)model_data[0];
    punch_flags.clear(1);
    draw_weapon_at_joint((saddr)this, 0x23);
    get_joint_position(1, &shot_origins[1]);
    item_model = model;
}

TUnk_804A535C::~TUnk_804A535C() {

}

TUnk_804A535C::TUnk_804A535C(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
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
        return new TUnk_804A535C(tl_05, item);
    }
    return NULL;
}

TUnk_804A5340::~TUnk_804A5340() {

}

void rocket_punch_return_timer(uaddr arg0) {
    if (arg0 != 0U) {
        ((TUnk_804A535C *)arg0)->punch_flags.clear(2);
    }
}

NJS_OBJECT *TUnk_804A535C::fn_8012C9D8() {
    if (test_flags_any(&punch_flags.bits, 4) != 0) {
        return second_model;
    }
    return (NJS_OBJECT *)model_data[1];
}
