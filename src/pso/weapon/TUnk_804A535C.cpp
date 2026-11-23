#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/weapon/TUnk_804A535C.h"
#include "pso/player/TObjPlayer_8012C3F4.h"
#include "pso/player/TObjPlayer_8012C950.h"
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
#include "pso/unk/text_8012C5F8.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/weapon/TItemAttacker.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer_8012C78C.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_80120CF8.h"
#include "pso/item/TItemEquipVariant_8012C810.h"
#include "pso/item/TItem.h"
#include "pso/weapon/shoot/TItemShootModel_dtor.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

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

void rocket_punch_wall_impact(u32 layer, u32 weapon, u32 target, uaddr extra) {
    if ((weapon != 0U) && (extra != 0U)) {
        rocket_punch_return_timer(weapon);
        spawn_particle_effect((const Vec *)extra, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}
extern "C" {

s32 post_translate_matrix(void *);
void TUnk_804A5340::render() {
    u8 *self = (u8 *)this;
    if ((TItemShootModel::is_owner_alive() != 0) && ((uaddr) this->model != 0U) && ((uaddr) this->texture_list != 0U)) {
        push_matrix();
        set_texlist((uaddr)this->texture_list);
        post_translate_matrix(self + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28 - 0x4000);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

}


void TUnk_804A5340::hook() {  }

struct RocketPunchShot {
    u8 pad[0x18];
    void *vt;
};

extern "C" {
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *self, void *owner, const void *a, const void *b, f32 f);
extern char __vt__13TUnk_804A5340[];
RocketPunchShot *TObjPlayer__sub_8012C4E4(RocketPunchShot *self, void *owner, const void *a, const void *b, f32 f);
RocketPunchShot *TObjPlayer__sub_8012C4E4(RocketPunchShot *self, void *owner, const void *a, const void *b, f32 f) {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(self, owner, a, b, f);
    self->vt = __vt__13TUnk_804A5340;
    ((TItemShootModel *)self)->set_render_model((NJS_OBJECT *)((TObjPlayer *)owner)->get_hp_by_flag(), (GinjaTextureList *)((TObjBase *)owner)->get_texlist());
    return self;
}

}

uaddr rocket_punch_create_shot(saddr owner, saddr pos, saddr dir, f32 life) {
    uaddr shot;
    uaddr particle;

    shot = 0U;
    if (owner != 0) {
        shot = (uaddr)TObject::operator new(0x6C);
        if (shot != 0U) {
            shot = (uaddr)TObjPlayer__sub_8012C4E4((RocketPunchShot *)shot, (void *)owner, (const void *)pos, (const void *)dir, life);
        }
        particle = (uaddr)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
        if ((shot != 0U) && (particle != 0U)) {
            ((TItemShootParticle *)particle)->spawn_slot_emitter(0x1BB, 0);
            ((TObject *)particle)->set_parent((TObject *)shot);
        }
    }
    return shot;
}

struct RocketPunchWeaponView {
    u8 pad[0x184];
    void *f184;
    void *f188;
    u8 pad2[0x1f8 - 0x18c];
    u8 f1f8[4];
};

extern "C" {

void TUnk_804A535C::emit_marker_effects() {
    saddr burst_counter;
    s32 burst_count;
    u32 owner;
    u8 *self = (u8 *)this;
    owner = *(u32 *)((s8 *)self + 0xF0);
    if (owner == 0U) return;
    burst_counter = owner + 0x7CC;
    if (get_burst_counter((void *)burst_counter) == 0) {
        burst_count = 0;
        do {
            increment_burst_counter((u8 *)burst_counter);
            burst_count += 1;
        } while (burst_count != 2);
        ((FlagWord *)(self + 0x1F8))->set(2);
        TItemAttacker::spawn_item_timer((TObject *)self, (ItemTimerCallback)rocket_punch_return_timer, 0x3C);
        ((FlagWord *)(self + 0x1F8))->set(4);
        if (this->launch_shot(self + 0x1FC, 0, 0, 1) == 1) {
            ((FlagWord *)(self + 0x1F8))->clear(4);
            this->launch_shot(self + 0x208, 0, 0, 0);
            return;
        }
        ((FlagWord *)(self + 0x1F8))->clear(4);
        this->launch_shot(self + 0x208, 0, 0, 1);
    }
}

void TUnk_804A535C::vfunc_60() {
    void *p;
    RocketPunchWeaponView *self = (RocketPunchWeaponView *)this;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any((s32 *)self->f1f8, 2) == 0) {
            if (test_flags_any((s32 *)self->f1f8, 1)) {
                p = self->f188;
            } else {
                p = self->f184;
            }
            if (p) {
                draw_ginja_object(p);
            }
        }
        break;
    }
}

}

void TUnk_804A535C::reserved_53() {
    s32 saved_model;
    u8 *self = (u8 *)this;

    saved_model = *(s32 *)((s8 *)self + 0xF4);
    ((FlagWord *)(self + 0x1F8))->set(1);
    ((TItemWeapon *)self)->draw_weapon_model();
    ((TItemWeapon *)self)->get_joint_position(1, (self + 0x1FC));
    *(s32 *)((s8 *)self + 0xF4) = (s32) *(s32 *)((s8 *)self + 0x180);
    ((FlagWord *)(self + 0x1F8))->clear(1);
    draw_weapon_at_joint((saddr)self, 0x23);
    ((TItemWeapon *)self)->get_joint_position(1, (self + 0x208));
    *(s32 *)((s8 *)self + 0xF4) = saved_model;
}

extern s32 __vt__13TUnk_804A535C[];

TUnk_804A535C::~TUnk_804A535C() {

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

struct WeaponFlagWordView {
    char pad_0[0x1F8];
    char f_1F8[1];
};

void *TUnk_804A535C::init_trade_action() {
    struct WeaponFlagWordView *self = (struct WeaponFlagWordView *)this;
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_804A535C;
    __ct__8FlagWordFv((self->f_1F8));
    ((FlagWord *)((char *)this + 376))->set(32);
    set_weapon_flags(515);
    (*(void **)((u8 *)this + 0x1EC)) = (void *)rocket_punch_wall_impact;
    (*(void **)((u8 *)this + 0x1F4)) = (void *)rocket_punch_target_impact;
    *(void **)((s8 *)this + 0x1F0) = (void *)rocket_punch_create_shot;
    *(f32 *)&(*(float *)((u8 *)this + 0x1E4)) = 8.0f;
    ((FlagWord *)(self->f_1F8))->reset();
    return this;
}

u8 * init_trade_action__13TUnk_804A535CFv(void *, s32, s32);
extern s32 tl_05;
TItem *TObjPlayer::create_trade_action_state(u8 *item) {
    u8 *weapon;
    u8 *initialized;
    if (item != NULL) {
        weapon = (u8 *)TItem::operator new(0x214);
        initialized = weapon;
        if (initialized != NULL) {
            initialized = (u8 *)(init_trade_action__13TUnk_804A535CFv(weapon, tl_05, (saddr)item));
        }
        return reinterpret_cast<TItem *>(initialized);
    }
    return NULL;
}

}

TUnk_804A5340::~TUnk_804A5340() {

}
void rocket_punch_return_timer(uaddr weapon) {
    if (weapon != 0U) {
        ((FlagWord *)(weapon + 0x1F8))->clear(2);
    }
}

saddr TObjPlayer::get_hp_by_flag() {
    u8 *self = (u8 *)this;
    if (test_flags_any((s32 *)&this->unk_1F8, 4) != 0) {
        return *(s32 *)((s8 *)self + 0x188);
    }
    return this->m_184;
}
