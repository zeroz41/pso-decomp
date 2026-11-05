#include "types.h"
#include "pso/system/FlagWord.h"
#include "pso/item/TUnk_804A403C.h"
#include "pso/unk/TUnk_804A4020.h"
#include "pso/item/SpecialProjectileWeapons.h"
#include "pso/item/TItemShootParticle.h"
#include "pso/player/TObjPlayer_80128A70.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_80087278.h"
#include "pso/TAdRicoRing.h"
#include "pso/TItemAttacker.h"
#include "pso/TObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_80120908.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/item/TItem.h"
#include "pso/TMainTask.h"

struct Elem_80128A74 { u8 pad[0x1c]; u8 f1c[0x2c - 0x1c]; };

struct Obj_80128A74 { u8 pad[0xa4]; Elem_80128A74 *elems; s32 count; };

struct Obj_80128E08 { u8 pad[0x184]; void *f184; void *f188; u8 pad2[0x1fc - 0x18c]; u8 f1fc[4]; };

extern "C" {
Obj_80128A74 *find_entity_by_id(s32);
s32 play_sound_effect(s32, s32, s32, s32);
s32 test_flags_any(void *p, s32 n);

void TObjPlayer__sub_80128A70(void) {  }

void TObjPlayer__sub_80128A74(s32 a, u32 b, s32 c, s32 d) {
    Obj_80128A74 *o;
    ((TObjPlayer *)b)->clear_rico_ring_flag();
    o = find_entity_by_id(c);
    if (o != 0 && o->elems != 0 && d < o->count) {
        spawn_particle_effect(o->elems[d].f1c, 0x45);
    }
}

}

void TObjPlayer::notify_hit_target(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    if ((arg1 != 0U) && (arg3 != 0U)) {
        ((TObjPlayer *)arg1)->clear_rico_ring_flag();
        spawn_particle_effect((void *)arg3, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}

void TUnk_804A4020::render() {
    if ((is_owner_alive() != 0) && ((u32)m_58 != 0U) && ((u32)m_5C != 0U)) {
        push_matrix();
        set_texlist((u32)m_5C);
        post_translate_matrix(&m_pos.x);
        rotate_matrix_y(NULL, m_count);
        rotate_matrix_x(NULL, m_28 - 0x4000);
        draw_ginja_object(m_58);
        pop_matrix();
    }
}

void TUnk_804A4020::hook() {  }

TUnk_804A4020::TUnk_804A4020(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    sub_80129118(TObjPlayer__sub_801290D0((u8 *)owner), ((TObjBase *)owner)->get_texlist());
}

u32 TObjPlayer::spawn_shot_effect(s32 owner, s32 origin, s32 end, f32 frames) {
    TUnk_804A4020 *model = NULL;
    TItemShootParticle *particle;
    if (owner != 0) {
        model = new TUnk_804A4020((void *)owner, (const Vec *)origin, (const Vec *)end, frames);
        particle = (TItemShootParticle *)spawn_shoot_particle(owner, origin, end, frames);
        if ((model != NULL) && (particle != NULL)) {
            particle->spawn_slot_emitter(0x1BB, 0);
            ((TObject *)particle)->set_parent(model);
        }
    }
    return (u32)model;
}

extern "C" {
void clear_rico_ring_flag__10TObjPlayerFv(u32);

void TUnk_804A403C::emit_marker_effects() {
    s32 temp_r31;
    s32 var_r30;
    u32 temp_r3;
    u8 *arg0 = (u8 *)this;
    TObjPlayer__sub_80128A70();
    temp_r3 = *(u32 *)((s8 *)arg0 + 0xF0);
    if (temp_r3 == 0U) return;
    temp_r31 = temp_r3 + 0x7CC;
    if (get_burst_counter((void *)temp_r31) == 0) {
        var_r30 = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            var_r30 += 1;
        } while (var_r30 != 2);
        ((FlagWord *)(arg0 + 0x1FC))->set(2);
        TItemAttacker::spawn_item_timer((TObject *)arg0, (ItemTimerCallback)clear_rico_ring_flag__10TObjPlayerFv, 0x3C);
        ((FlagWord *)(arg0 + 0x1FC))->set(4);
        if (launch_shot(arg0 + 0x200, 0, 0, 1) == 1) {
            ((FlagWord *)(arg0 + 0x1FC))->clear(4);
            launch_shot(arg0 + 0x20C, 0, 0, 0);
            return;
        }
        ((FlagWord *)(arg0 + 0x1FC))->clear(4);
        launch_shot(arg0 + 0x20C, 0, 0, 1);
    }
}

void TUnk_804A403C::vfunc_60() {
    void *p;
    Obj_80128E08 *self = (Obj_80128E08 *)this;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any(self->f1fc, 2) == 0) {
            if (test_flags_any(self->f1fc, 1)) {
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

void TUnk_804A403C::reserved_53() {
    s32 temp_r31;
    u8 *arg0 = (u8 *)this;

    temp_r31 = *(s32 *)((s8 *)arg0 + 0xF4);
    ((FlagWord *)(arg0 + 0x1FC))->set(1);
    draw_weapon_at_joint((s32)arg0, 0x30);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x200));
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) *(s32 *)((s8 *)arg0 + 0x180);
    ((FlagWord *)(arg0 + 0x1FC))->clear(1);
    draw_weapon_at_joint((s32)arg0, 0x23);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x20C));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}

extern s32 lbl_804A403C[];

void *__dt__13TUnk_804A403CFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804A403C;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

extern "C" {

void construct_srank_weapon(void *);

struct VOff_80128F60_arg0_80128f60 { char pad_0[0x1FC]; char f_1FC[1]; };

void *TUnk_804A403C::init_event_callbacks() {
    struct VOff_80128F60_arg0_80128f60 *self = (struct VOff_80128F60_arg0_80128f60 *)this;
    construct_srank_weapon(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804A403C;
    __ct__8FlagWordFv((self->f_1FC));
    ((FlagWord *)((char *)this + 376))->set(32);
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)TObjPlayer::notify_hit_target;
    hit_callback = (WeaponHitCallback)TObjPlayer__sub_80128A74;
    shot_callback = (WeaponShotCallback)TObjPlayer::spawn_shot_effect;
    shot_speed = 10.0f;
    ((FlagWord *)(self->f_1FC))->reset();
    return this;
}

}

extern "C" {
u8 * init_event_callbacks__13TUnk_804A403CFv(void *, TObject *, s32);

u8 *TObjPlayer::create_event_callbacks_state(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(TItem::operator new(0x218));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(init_event_callbacks__13TUnk_804A403CFv(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

}

TUnk_804A4020::~TUnk_804A4020() {

}

void TObjPlayer::clear_rico_ring_flag() {
    u32 arg0 = (u32)this;
    if (arg0 != 0U) {
        ((FlagWord *)(arg0 + 0x1FC))->clear(2);
    }
}

extern "C" {

s32 TObjPlayer__sub_801290D0(u8 *arg0) {
    if (test_flags_any(arg0 + 0x1FC, 4) != 0) {
        return *(s32 *)((s8 *)arg0 + 0x188);
    }
    return *(s32 *)((s8 *)arg0 + 0x184);
}

}

void TItemShootModel::sub_80129118(s32 arg1, s32 arg2) {
    *(s32 *)&this->m_58 = arg1;
    *(s32 *)&this->m_5C = arg2;
}
