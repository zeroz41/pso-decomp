// The TUnk_804E23F0 weapon family: TUnk_804E23F0 with the seven
// TUnk_804E23F0 subclasses that create_object_by_type picks from the item
// code, 0x802D526C-0x802D6348. One TU: its vtables and jump table fill
// .data 0x804E1CA8-0x804E24F0 in text order, which -inline off,deferred only
// gives with the source written last to first (as below).
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TObjPlayer_802D5174.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemLoad.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/effect/item/TItemWpnCardEffect.h"
#include "pso/unk/text_80120908.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/unk/text_80120D50.h"
#include "pso/weapon/TUnk_804E1CA8.h"
#include "pso/weapon/TUnk_804E1E08.h"
#include "pso/weapon/TUnk_804E1F04.h"
#include "pso/weapon/TUnk_804E2000.h"
#include "pso/weapon/TUnk_804E20FC.h"
#include "pso/weapon/TUnk_804E21F8.h"
#include "pso/weapon/TUnk_804E22F4.h"
#include "pso/weapon/TUnk_804E23F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/item/TItemEffCane.h"

struct W_802D5B78 { s32 a; s32 b; s32 c; };

extern "C" {
void spawn_hit_particles__10TObjPlayerFiPv(saddr pos, const Vec *dir);
void get_weapon_color__11TItemWeaponFPv(void *, void *);
s32 rotate_matrix_about_axis(int, void *, int);
void set_matrix_identity(u8 *matrix);
}

TUnk_804E23F0::~TUnk_804E23F0() {}

TUnk_804E22F4::~TUnk_804E22F4() {}

TUnk_804E21F8::~TUnk_804E21F8() {}

TUnk_804E20FC::~TUnk_804E20FC() {}

TUnk_804E2000::~TUnk_804E2000() {}

TUnk_804E1F04::~TUnk_804E1F04() {}

TUnk_804E1E08::~TUnk_804E1E08() {}

TItem *TObjPlayer::create_object_by_type(u8 *item) {
    if (item != NULL) {
        switch (item[1]) {
        case 0x8C:
            switch (item[2]) {
            case 0:
                break;
            case 1:
                return new TUnk_804E1F04(tl_05, item);
            case 2:
                return new TUnk_804E22F4(tl_05, item);
            case 3:
                return new TUnk_804E21F8(tl_05, item);
            }
            break;
        case 0x93:
            return new TUnk_804E2000(tl_05, item);
        case 0xA4:
            return new TUnk_804E20FC(tl_05, item);
        case 0x96:
            return new TUnk_804E1CA8(tl_05, item);
        }
        return new TUnk_804E1E08(tl_05, item);
    }
    return NULL;
}

TUnk_804E23F0::TUnk_804E23F0(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(3);
    pad_1f8 = 0;
    effect_id = 445;
    pad_204 = (void *)start_wall_card;
    pad_208 = (void *)TObjPlayer::create_network_object;
    pad_200 = 4.0f;
}

void TUnk_804E23F0::draw_held_model() {
    if (test_weapon_flags(0x01000000) == 0) {
        draw_weapon_model();
    }
}

void TUnk_804E23F0::transform_model_node() {
    if (TObjPlayer::get_player_list() == 0) {
        NJS_POINT3 offset = { 0.0f, 0.0f, 0.5f };
        post_translate_matrix(&offset.x);
        rotate_matrix_x(0, 0x18E3);
        if (pad_1f8 & 1) {
            push_matrix();
            rotate_matrix_x(0, 0x2AAA);
            draw_model();
            pop_matrix();
            push_matrix();
            rotate_matrix_x(0, -0x2AAA);
            draw_model();
            pop_matrix();
        }
    }
}

void TUnk_804E23F0::emit_marker_effects() {
    Vec pos;
    owner->get_anim_node_position(0x30, &pos);
    if (owner->attack_state.get_validated_attack_stage() == 2) {
        fire_shot_at_target(&pos, item_model, 0);
        fire_shot_at_target(&pos, item_model, 0x1555);
        fire_shot_at_target(&pos, item_model, -0x1555);
    } else {
        fire_shot_at_target(&pos, item_model, 0);
    }
    vfunc_62(&pos);
}

void TUnk_804E23F0::vfunc_62(Vec *pos) {
    if (get_attack_stage() == 0) {
        TItemEffCane::create(tl_05, this, -1, effect_id);
    }
}

void TUnk_804E23F0::update_weapon() {
    if (get_attack_stage() == 2) {
        pad_1f8 |= 1;
    } else {
        pad_1f8 &= ~1;
    }
}

void TUnk_804E23F0::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    NJS_ARGB color;
    desc->scale = pad_200;
    desc->spin[2] = 0xC000;
    desc->flags |= 2;
    get_weapon_color__11TItemWeaponFPv(&color, this);
    copy_argb(&desc->color, &color);
    desc->hit_effect = pad_208;
    desc->wall_effect = pad_204;
}

#pragma push
#pragma fp_contract on

void TObjPlayer__sub_802D5B78(const ActorBodyHit *hit, Vec *out, Vec *direction) {
    s32 *wsrc;
    s32 a;
    s32 b;
    s32 c;
    W_802D5B78 w;
    // Copy the input words before normalization so the output may alias it.
    wsrc = (s32 *)direction;
    c = wsrc[0];
    a = c;
    b = wsrc[1];
    c = wsrc[2];
    w.a = a;
    w.b = b;
    w.c = c;
    normalize_vector((Vec *)&w);
    const CollisionBody *body = &hit->target->bodies[hit->body];
    const f32 radius = body->radius;
    out->x = body->center.x - (*(f32 *)&w.a) * radius;
    out->y = body->center.y - (*(f32 *)&w.b) * radius;
    out->z = body->center.z - (*(f32 *)&w.c) * radius;
}

#pragma pop

void TObjPlayer::spawn_item() {
    NJS_OBJECT *model;
    NJS_TEXLIST *texture;
    TParticleCtrl *particle;

    particle = spawn_particle_effect(((Vec *)this), 0x1BF);
    if (particle != NULL) {
        TItemLoad::get_item_model(0xD, &model);
        TItemLoad::get_item_texture_list(0xD, &texture);
        attach_particle_model(particle, model, texture, 0, 0, 1.0f);
        particle->set_scale(10.0f, 10.0f);
    }
}

TUnk_804E1E08::TUnk_804E1E08(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    pad_200 = 5.0f;
}

TUnk_804E1F04::TUnk_804E1F04(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    effect_id = 341;
    pad_204 = (void *)start_red_wall_card;
    pad_208 = (void *)TObjPlayer::create_aux_object;
}

TUnk_804E22F4::TUnk_804E22F4(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    effect_id = 447;
    pad_204 = (void *)TObjPlayer::alloc_and_init;
    pad_208 = (void *)TObjPlayer::create_and_init_effect;
}

void TUnk_804E22F4::vfunc_62(Vec *pos) {
    ((TObjPlayer *)pos)->spawn_item();
}

TUnk_804E21F8::TUnk_804E21F8(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    s32 i;
    Vec *origin;
    pad_248 = 0;
    pad_24a = 0;
    origin = pad_20c;
    for (i = 0; i < 5; i++) {
        origin->x = 0.0f;
        origin->y = 0.0f;
        origin->z = 0.0f;
        origin++;
    }
    pad_204 = (void *)TObjPlayer::alloc_and_init;
    pad_208 = (void *)TObjPlayer::create_and_init_effect;
}

void TUnk_804E21F8::on_equipped() {
    pad_248 = 0;
    pad_24a = 0;
    pad_24c = 5.0f + TObjPlayer__sub_8017A1A4(owner, 0);
    pad_250 = 0;
    sub_802D577C();
}

void TUnk_804E21F8::update_weapon() {
    s16 frames;
    s16 count;
    frames = pad_248;
    frames += 1;
    pad_248 = frames;
    if (frames == 0x96) {
        count = pad_24a;
        if (count < 5) {
            pad_24a = count + 1;
            send_activate_effect(pad_24a);
        }
        pad_248 = 0;
    }
    sub_802D577C();
}

__declspec(section ".rodata") Vec ring_point_template = { 0 };
__declspec(section ".rodata") Vec player_pb_zero_vec_block = { 0 };
void TUnk_804E21F8::sub_802D577C() {
    Vec *axis_base;
    Vec *point_base;
    Vec *origin;
    f32 *center;
    s32 tilt;
    s16 n;
    s32 angle;
    s32 step;
    s32 tilt_step;
    s32 count;
    n = pad_24a;
    if (n != 0) {
        angle = pad_250;
        count = n;
        origin = pad_20c;
        center = &owner->body_center.x;
        point_base = &ring_point_template;
        axis_base = &player_pb_zero_vec_block;
        tilt = 0x31C7;
        step = 0x10000 / n;
        tilt_step = 0x238E / n;
        while (count != 0) {
            Vec point = *point_base;
            point.z = pad_24c;
            Vec axis = *axis_base;
            axis.x = cos_table_lookup(tilt);
            axis.y = sin_table_lookup(tilt);
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(center);
            rotate_matrix_about_axis(0, &axis, angle);
            transform_point_by_current_matrix(&point.x, origin);
            pop_matrix();
            angle += step;
            tilt += tilt_step;
            count--;
            origin++;
        }
        pad_250 += 0x38E;
    }
}

void TUnk_804E21F8::activate_effect(s32 count) {
    if (count < 5) {
        pad_24a = count;
    }
}

void TUnk_804E21F8::draw_held_model() {
    Vec *origin;
    s32 n;
    draw_weapon_model();
    if (is_hidden() == 0) {
        n = pad_24a;
        origin = pad_20c;
        while (n != 0) {
            push_matrix();
            post_translate_matrix(&(origin++)->x);
            rotate_matrix_x(0, -0x4000);
            draw_ginja_object(item_model);
            pop_matrix();
            n--;
        }
    }
}

void TUnk_804E21F8::emit_marker_effects() {
    Vec *origin;
    s32 angle;
    s32 step;
    s32 n;
    s32 count;
    origin = pad_20c;
    count = pad_24a;
    n = count;
    angle = pad_250 - owner->rotation_y;
    step = 0x10000 / count;
    while (n != 0) {
        fire_shot_at_target(origin++, item_model, angle);
        angle += step;
        n--;
    }
    vfunc_62(&owner->body_center);
    pad_24a = 0;
    pad_248 = 0x87;
}

void TUnk_804E21F8::vfunc_62(Vec *pos) {
    ((TObjPlayer *)pos)->spawn_item();
}

void TUnk_804E21F8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    TUnk_804E23F0::init_weapon_effect_descriptor(desc);
    desc->speed = 5.0f;
}

TUnk_804E2000::TUnk_804E2000(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    effect_id = 341;
    pad_208 = (void *)TObjPlayer::spawn_hit_particles_at;
    pad_204 = (void *)TObjPlayer::spawn_hit_particles_at_vec;
}

void TObjPlayer::spawn_hit_particles_at(s32 arg0, saddr hit, saddr dir) {
    Vec pos;
    TObjPlayer__sub_802D5B78(reinterpret_cast<const ActorBodyHit *>(hit), &pos, reinterpret_cast<Vec *>(dir));
    spawn_hit_particles__10TObjPlayerFiPv((saddr)&pos, (const Vec *)dir);
}

void TObjPlayer::spawn_hit_particles_at_vec(s32 arg0, saddr arg1, saddr dir) {
    Vec pos;
    VecCopy(&pos, (const Vec *)arg1);
    spawn_hit_particles__10TObjPlayerFiPv((saddr)&pos, (const Vec *)dir);
}

extern const f64 radians_to_angle_scale[1] = { 10430.38043493439 };
void spawn_hit_particles__10TObjPlayerFiPv(saddr pos, const Vec *dir) {
    s32 angles[3];
    create_timed_particle_emitter((void *)pos, 0x1EF, 0, 0xF);
    angles[0] = 0;
    angles[1] = (s32)(radians_to_angle_scale[0] * atan2_float(dir->x, dir->z));
    angles[2] = 0;
    {
        TParticleCtrl *particle = create_timed_particle_emitter_with_angles((void *)pos, angles, 0x1B8, 0, 0xF, 4);
        if (particle != NULL) {
            particle->set_scale(1.5f, 1.5f);
        }
    }
}

TUnk_804E20FC::TUnk_804E20FC(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    pad_200 = 1.0f;
    pad_204 = (void *)create_needle_pos_effect;
    pad_208 = (void *)create_needle_effect;
}

void TUnk_804E20FC::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    TUnk_804E23F0::init_weapon_effect_descriptor(desc);
    desc->spin[0] = 0x8000;
}

TUnk_804E1CA8::TUnk_804E1CA8(TObject *parent, u8 *item) : TUnk_804E23F0(parent, item) {
    pad_200 = 5.0f;
    set_weapon_flags(32);
    pad_208 = (void *)TObjPlayer::do_action_447_from_packet;
    pad_204 = (void *)create_needle_pos_effect;
}

void TUnk_804E1CA8::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    TUnk_804E23F0::init_weapon_effect_descriptor(desc);
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)this)->drain_owner_hp_fraction(0.07f);
        desc->hits = 10;
        desc->model = second_model;
        desc->scale = 1.0f;
    }
}

void TObjPlayer::do_action_447_from_packet(void *item, void *hit, void *dir) {
    Vec pos;
    TObjPlayer__sub_802D5B78(static_cast<const ActorBodyHit *>(hit), &pos, static_cast<Vec *>(dir));
    ((TObjPlayer *)&pos)->do_action_447();
}

void *TObjPlayer::do_action_447() {
    return spawn_particle_effect((const Vec *)this, 447);
}

TUnk_804E1CA8::~TUnk_804E1CA8() {}
