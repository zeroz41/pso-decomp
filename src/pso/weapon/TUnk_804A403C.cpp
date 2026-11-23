#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/weapon/TUnk_804A403C.h"
#include "pso/weapon/shoot/TUnk_804A4020.h"
#include "pso/weapon/SpecialProjectileWeapons.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/player/TObjPlayer_80128A70.h"
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
#include "pso/ui/frontend/TAdRicoRing_8001BEE8.h"

struct Elem_80128A74 { u8 pad[0x1c]; u8 position[0x2c - 0x1c]; };

struct Obj_80128A74 { u8 pad[0xa4]; Elem_80128A74 *elems; s32 count; };

struct Obj_80128E08 { u8 pad[0x184]; void *f184; void *f188; u8 pad2[0x1fc - 0x18c]; u8 flags[4]; };

extern "C" {
Obj_80128A74 *find_entity_by_id(s32);

void TObjPlayer__sub_80128A70(void) {  }

void TObjPlayer__sub_80128A74(s32 a, uaddr b, s32 c, s32 d) {
    Obj_80128A74 *o;
    ((TObjPlayer *)b)->clear_rico_ring_flag();
    o = find_entity_by_id(c);
    if (o != 0 && o->elems != 0 && d < o->count) {
        spawn_particle_effect((const Vec *)o->elems[d].position, 0x45);
    }
}

}

void TObjPlayer::notify_hit_target(u32 arg0, uaddr player, u32 arg2, uaddr pos) {
    if ((player != 0U) && (pos != 0U)) {
        ((TObjPlayer *)player)->clear_rico_ring_flag();
        spawn_particle_effect((const Vec *)pos, 0x45);
        play_sound_effect(0x4001C112, 0, 0, 0);
    }
}

void TUnk_804A4020::render() {
    if ((is_owner_alive() != 0) && ((uaddr)model != 0U) && ((uaddr)texture_list != 0U)) {
        push_matrix();
        set_texlist(texture_list);
        post_translate_matrix(&m_pos.x);
        rotate_matrix_y(NULL, m_count);
        rotate_matrix_x(NULL, m_28 - 0x4000);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void TUnk_804A4020::hook() {  }

TUnk_804A4020::TUnk_804A4020(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    set_render_model(TObjPlayer__sub_801290D0((u8 *)owner), (NJS_TEXLIST *)((TObjBase *)owner)->get_texlist());
}

u32 TObjPlayer::spawn_shot_effect(saddr owner, saddr origin, saddr end, f32 frames) {
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
    return (uaddr)model;
}

extern "C" {
void clear_rico_ring_flag__10TObjPlayerFv(u32);

void TUnk_804A403C::emit_marker_effects() {
    saddr temp_r31;
    s32 i;
    u32 temp_r3;
    u8 *arg0 = (u8 *)this;
    TObjPlayer__sub_80128A70();
    temp_r3 = *(u32 *)((s8 *)arg0 + 0xF0);
    if (temp_r3 == 0U) return;
    temp_r31 = temp_r3 + 0x7CC;
    if (get_burst_counter((void *)temp_r31) == 0) {
        i = 0;
        do {
            increment_burst_counter((u8 *)temp_r31);
            i += 1;
        } while (i != 2);
        this->flags.set(2);
        TItemAttacker::spawn_item_timer((TObject *)arg0, (ItemTimerCallback)clear_rico_ring_flag__10TObjPlayerFv, 0x3C);
        this->flags.set(4);
        if (launch_shot(arg0 + 0x200, 0, 0, 1) == 1) {
            this->flags.clear(4);
            launch_shot(arg0 + 0x20C, 0, 0, 0);
            return;
        }
        this->flags.clear(4);
        launch_shot(arg0 + 0x20C, 0, 0, 1);
    }
}

void TUnk_804A403C::vfunc_60() {
    void *p;
    Obj_80128E08 *self = (Obj_80128E08 *)this;
    switch (TObjPlayer::get_player_list()) {
    case 1:
        if (test_flags_any((s32 *)self->flags, 2) == 0) {
            if (test_flags_any((s32 *)self->flags, 1)) {
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
    this->flags.set(1);
    draw_weapon_at_joint((saddr)arg0, 0x30);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x200));
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) *(s32 *)((s8 *)arg0 + 0x180);
    this->flags.clear(1);
    draw_weapon_at_joint((saddr)arg0, 0x23);
    ((TItemWeapon *)arg0)->get_joint_position(1, (arg0 + 0x20C));
    *(s32 *)((s8 *)arg0 + 0xF4) = temp_r31;
}

TUnk_804A403C::~TUnk_804A403C() {}

TUnk_804A403C::TUnk_804A403C(TObject *parent, u8 *item) : TUnk_804A4948(parent, item) {
    this->effect_flags.set(32);
    set_weapon_flags(515);
    impact_callback = (WeaponHitCallback)TObjPlayer::notify_hit_target;
    hit_callback = (WeaponHitCallback)TObjPlayer__sub_80128A74;
    shot_callback = (WeaponShotCallback)TObjPlayer::spawn_shot_effect;
    shot_speed = 10.0f;
    flags.reset();
}

TItem *TObjPlayer::create_event_callbacks_state(u8 *item) {
    if (item != NULL) {
        return new TUnk_804A403C(tl_05, item);
    }
    return NULL;
}

TUnk_804A4020::~TUnk_804A4020() {

}

void TObjPlayer::clear_rico_ring_flag() {
    uaddr arg0 = (uaddr)this;
    if (arg0 != 0U) {
        ((FlagWord *)(arg0 + 0x1FC))->clear(2);
    }
}


NJS_OBJECT *TObjPlayer__sub_801290D0(u8 *owner) {
    if (test_flags_any((s32 *)(owner + 0x1FC), 4) != 0) {
        return *(NJS_OBJECT **)((s8 *)owner + 0x188);
    }
    return *(NJS_OBJECT **)((s8 *)owner + 0x184);
}


void TItemShootModel::set_render_model(NJS_OBJECT *new_model, NJS_TEXLIST *new_texture_list) {
    model = new_model;
    texture_list = new_texture_list;
}
