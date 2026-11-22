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
extern "C" {

s32 post_translate_matrix(void *);
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

}


void TUnk_804A5340::hook() {  }

struct Obj_8012C4E4 { u8 pad[0x18]; void *vt; };

extern "C" {
void __ct__15TItemShootModelFPvPC3VecPC3Vecf(void *self, void *owner, const void *a, const void *b, f32 f);
extern char __vt__13TUnk_804A5340[];
Obj_8012C4E4 *TObjPlayer__sub_8012C4E4(Obj_8012C4E4 *self, void *owner, const void *a, const void *b, f32 f);
Obj_8012C4E4 *TObjPlayer__sub_8012C4E4(Obj_8012C4E4 *self, void *owner, const void *a, const void *b, f32 f) {
    __ct__15TItemShootModelFPvPC3VecPC3Vecf(self, owner, a, b, f);
    self->vt = __vt__13TUnk_804A5340;
    ((TItemShootModel *)self)->set_render_model((NJS_OBJECT *)((TObjPlayer *)owner)->get_hp_by_flag(), (GinjaTextureList *)((TObjBase *)owner)->get_texlist());
    return self;
}

}

uaddr rocket_punch_create_shot(saddr owner, saddr arg1, saddr arg2, f32 farg0) {
    uaddr var_r31;
    uaddr temp_r30;

    var_r31 = 0U;
    if (owner != 0) {
        var_r31 = (uaddr)TObject::operator new(0x6C);
        if (var_r31 != 0U) {
            var_r31 = (uaddr)TObjPlayer__sub_8012C4E4((Obj_8012C4E4 *)var_r31, (void *)owner, (const void *)arg1, (const void *)arg2, farg0);
        }
        temp_r30 = (uaddr)TObjPlayer::spawn_shoot_particle(owner, arg1, arg2, farg0);
        if ((var_r31 != 0U) && (temp_r30 != 0U)) {
            ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0x1BB, 0);
            ((TObject *)temp_r30)->set_parent((TObject *)var_r31);
        }
    }
    return var_r31;
}

struct Obj_8012C714 { u8 pad[0x184]; void *f184; void *f188; u8 pad2[0x1f8 - 0x18c]; u8 f1f8[4]; };

extern "C" {
s32 test_flags_any(s32 *flags, s32 mask);

void TUnk_804A535C::emit_marker_effects() {
    saddr temp_r31;
    s32 var_r30;
    u32 temp_r3;
    u8 *arg0 = (u8 *)this;
    temp_r3 = *(u32 *)((s8 *)arg0 + 0xF0);
    if (temp_r3 == 0U) return;
    temp_r31 = temp_r3 + 0x7CC;
    if (get_burst_counter((void *)temp_r31) == 0) {
        var_r30 = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            var_r30 += 1;
        } while (var_r30 != 2);
        ((FlagWord *)(arg0 + 0x1F8))->set(2);
        TItemAttacker::spawn_item_timer((TObject *)arg0, (ItemTimerCallback)rocket_punch_return_timer, 0x3C);
        ((FlagWord *)(arg0 + 0x1F8))->set(4);
        if (this->launch_shot(arg0 + 0x1FC, 0, 0, 1) == 1) {
            ((FlagWord *)(arg0 + 0x1F8))->clear(4);
            this->launch_shot(arg0 + 0x208, 0, 0, 0);
            return;
        }
        ((FlagWord *)(arg0 + 0x1F8))->clear(4);
        this->launch_shot(arg0 + 0x208, 0, 0, 1);
    }
}

void TUnk_804A535C::vfunc_60() {
    void *p;
    Obj_8012C714 *self = (Obj_8012C714 *)this;
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
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;

    temp_r31 = *(s32 *)((s8 *)arg0 + 0xF4);
    ((FlagWord *)(arg0 + 0x1F8))->set(1);
    ((TItemWeapon *)arg0)->draw_weapon_model();
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x1FC));
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) *(s32 *)((s8 *)arg0 + 0x180);
    ((FlagWord *)(arg0 + 0x1F8))->clear(1);
    draw_weapon_at_joint((saddr)arg0, 0x23);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x208));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}

extern s32 __vt__13TUnk_804A535C[];

TUnk_804A535C::~TUnk_804A535C() {

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

struct VOff_8012C868_arg0_8012c868 { char pad_0[0x1F8]; char f_1F8[1]; };

void *TUnk_804A535C::init_trade_action() {
    struct VOff_8012C868_arg0_8012c868 *self = (struct VOff_8012C868_arg0_8012c868 *)this;
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
    u8 *temp_r3;
    u8 *var_r0;
    if (item != NULL) {
        temp_r3 = (u8 *)TItem::operator new(0x214);
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_trade_action__13TUnk_804A535CFv(temp_r3, tl_05, (saddr)item));
        }
        return reinterpret_cast<TItem *>(var_r0);
    }
    return NULL;
}

}

TUnk_804A5340::~TUnk_804A5340() {

}
void rocket_punch_return_timer(uaddr arg0) {
    if (arg0 != 0U) {
        ((FlagWord *)(arg0 + 0x1F8))->clear(2);
    }
}

saddr TObjPlayer::get_hp_by_flag() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any((s32 *)&this->unk_1F8, 4) != 0) {
        return *(s32 *)((s8 *)arg0 + 0x188);
    }
    return this->m_184;
}
