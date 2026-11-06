#include "types.h"
#include "pso/weapon/TUnk_804A535C.h"
#include "pso/player/TObjPlayer_8012C3F4.h"
#include "pso/player/TObjPlayer_8012C950.h"
#include "pso/unk/text_80087278.h"
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
#include "pso/weapon/TUnk_804A535C.h"
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

void rocket_punch_target_impact(void *self, u32 a, u32 b, s32 idx) {
    Mylla_8012C384 *m;
    rocket_punch_return_timer(a);
    m = find_entity_by_id(b);
    if (m && m->ents && idx < m->count) {
        spawn_particle_effect(m->ents[idx].f1c, 0x45);
    }
}

void rocket_punch_wall_impact(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    if ((arg1 != 0U) && (arg3 != 0U)) {
        rocket_punch_return_timer(arg1);
        spawn_particle_effect((void *)arg3, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}

}

extern "C" {

s32 post_translate_matrix(void *);
s32 push_matrix();
s32 is_owner_alive__15TItemShootModelFv();


extern "C" {

void TUnk_804A5340::render() {
    u8 *arg0 = (u8 *)this;
    if ((is_owner_alive__15TItemShootModelFv() != 0) && ((u32) this->m_58 != 0U) && ((u32) this->m_5C != 0U)) {
        push_matrix();
        set_texlist((int)this->m_5C);
        post_translate_matrix(arg0 + 0x1C);
        rotate_matrix_y(0, this->m_count);
        rotate_matrix_x(0, this->m_28 - 0x4000);
        draw_ginja_object(this->m_58);
        pop_matrix();
    }
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
    ((TItemShootModel *)self)->sub_80129118(((TObjPlayer *)owner)->get_hp_by_flag(), ((TObjBase *)owner)->get_texlist());
    return self;
}

}

extern "C" {

u32 spawn_shoot_particle__10TObjPlayerFUlllf(s32, s32, s32, f32);
u32 __nw__7TObjectFUl(s32);

u32 rocket_punch_create_shot(s32 owner, s32 arg1, s32 arg2, f32 farg0) {
    u32 var_r31;
    u32 temp_r30;

    var_r31 = 0U;
    if (owner != 0) {
        var_r31 = __nw__7TObjectFUl(0x6C);
        if (var_r31 != 0U) {
            var_r31 = (u32)TObjPlayer__sub_8012C4E4((Obj_8012C4E4 *)var_r31, (void *)owner, (const void *)arg1, (const void *)arg2, farg0);
        }
        temp_r30 = spawn_shoot_particle__10TObjPlayerFUlllf(owner, arg1, arg2, farg0);
        if ((var_r31 != 0U) && (temp_r30 != 0U)) {
            ((TItemShootParticle *)temp_r30)->spawn_slot_emitter(0x1BB, 0);
            ((TObject *)temp_r30)->set_parent((TObject *)var_r31);
        }
    }
    return var_r31;
}

}

struct Obj_8012C714 { u8 pad[0x184]; void *f184; void *f188; u8 pad2[0x1f8 - 0x18c]; u8 f1f8[4]; };

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual s32 m49(void *, s32, s32, s32);
};

extern "C" {
s32 test_flags_any(void *p, s32 n);

void TUnk_804A535C::emit_marker_effects() {
    s32 temp_r31;
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
        if (((VObj_18 *)(arg0))->m49(arg0 + 0x1FC, 0, 0, 1) == 1) {
            ((FlagWord *)(arg0 + 0x1F8))->clear(4);
            ((VObj_18 *)(arg0))->m49(arg0 + 0x208, 0, 0, 0);
            return;
        }
        ((FlagWord *)(arg0 + 0x1F8))->clear(4);
        ((VObj_18 *)(arg0))->m49(arg0 + 0x208, 0, 0, 1);
    }
}

void TUnk_804A535C::vfunc_60() {
    void *p;
    Obj_8012C714 *self = (Obj_8012C714 *)this;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any(self->f1f8, 2) == 0) {
            if (test_flags_any(self->f1f8, 1)) {
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
    draw_weapon_at_joint((s32)arg0, 0x23);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x208));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}

extern s32 __vt__13TUnk_804A535C[];

TUnk_804A535C::~TUnk_804A535C() {

}

extern "C" {

void __ct__11TItemWeaponFP7TObjectPUc(void *);

extern s32 __vt__13TUnk_804A535C[];
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

}

extern "C" {
u8 * init_trade_action__13TUnk_804A535CFv(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
u8 *TObjPlayer::create_trade_action_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x214));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_trade_action__13TUnk_804A535CFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

TUnk_804A5340::~TUnk_804A5340() {

}
void rocket_punch_return_timer(u32 arg0) {
    if (arg0 != 0U) {
        ((FlagWord *)(arg0 + 0x1F8))->clear(2);
    }
}

s32 TObjPlayer::get_hp_by_flag() {
    u8 *arg0 = (u8 *)this;
    if (test_flags_any((u8 *)&this->unk_1F8, 4) != 0) {
        return *(s32 *)((s8 *)arg0 + 0x188);
    }
    return this->m_184;
}
