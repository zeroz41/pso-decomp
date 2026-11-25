// The card weapons. One TU: its vtables and the jump table of create fill
// .data in text order, which -inline off,deferred only gives with the source
// written last to first (as below).
#include "pso/weapon/TItemWeaponCard.h"
#include "types.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemLoad.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/item/TItemEffNeedle.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/effect/item/TItemEffCane.h"
#include "pso/effect/item/TItemWpnCardEffect.h"
#include "pso/unk/text_80120908.h"
#include "pso/unk/text_80120D50.h"
#include "pso/unk/text_803D96A8.h"

struct W_802D5B78 { s32 a; s32 b; s32 c; };

extern "C" {
void get_weapon_color__11TItemWeaponFv(void *, void *);
}

TItemWeaponCard::~TItemWeaponCard() {}

TItemWeaponHitogata::~TItemWeaponHitogata() {}

TItemWeaponDancingHitogata::~TItemWeaponDancingHitogata() {}

TItemWeaponAmoreRose::~TItemWeaponAmoreRose() {}

TItemWeaponSectionIdCard::~TItemWeaponSectionIdCard() {}

TItemWeaponMahu::~TItemWeaponMahu() {}

TItemWeaponTalis::~TItemWeaponTalis() {}

TItem *TItemWeaponCard::create(u8 *item) {
    if (item != NULL) {
        switch (item[1]) {
        case 0x8C:
            switch (item[2]) {
            case 0:
                break;
            case 1:
                return new TItemWeaponMahu(tl_05, item);
            case 2:
                return new TItemWeaponHitogata(tl_05, item);
            case 3:
                return new TItemWeaponDancingHitogata(tl_05, item);
            }
            break;
        case 0x93:
            return new TItemWeaponSectionIdCard(tl_05, item);
        case 0xA4:
            return new TItemWeaponAmoreRose(tl_05, item);
        case 0x96:
            return new TItemWeaponGalWind(tl_05, item);
        }
        return new TItemWeaponTalis(tl_05, item);
    }
    return NULL;
}

TItemWeaponCard::TItemWeaponCard(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(3);
    fan_flags = 0;
    effect_id = 445;
    wall_effect = (void *)start_wall_card;
    hit_effect = (void *)TObjPlayer::create_network_object;
    effect_scale = 4.0f;
}

void TItemWeaponCard::draw_held_model() {
    if (test_weapon_flags(0x01000000) == 0) {
        draw_weapon_model();
    }
}

void TItemWeaponCard::transform_model_node() {
    if (TObjPlayer::get_player_list() == 0) {
        NJS_POINT3 offset = { 0.0f, 0.0f, 0.5f };
        post_translate_matrix(&offset.x);
        rotate_matrix_x(0, 0x18E3);
        if (fan_flags & 1) {
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

void TItemWeaponCard::emit_marker_effects() {
    Vec pos;
    owner->get_anim_node_position(0x30, &pos);
    if (owner->attack_state.get_validated_attack_stage() == 2) {
        fire_shot_at_target(&pos, item_model, 0);
        fire_shot_at_target(&pos, item_model, 0x1555);
        fire_shot_at_target(&pos, item_model, -0x1555);
    } else {
        fire_shot_at_target(&pos, item_model, 0);
    }
    spawn_throw_effect(&pos);
}

void TItemWeaponCard::spawn_throw_effect(Vec *pos) {
    if (get_attack_stage() == 0) {
        TItemEffCane::create(tl_05, this, -1, effect_id);
    }
}

void TItemWeaponCard::update_weapon() {
    if (get_attack_stage() == 2) {
        fan_flags |= 1;
    } else {
        fan_flags &= ~1;
    }
}

void TItemWeaponCard::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    NJS_ARGB color;
    desc->scale = effect_scale;
    desc->spin[2] = 0xC000;
    desc->flags |= 2;
    get_weapon_color__11TItemWeaponFv(&color, this);
    copy_argb(&desc->color, &color);
    desc->hit_effect = hit_effect;
    desc->wall_effect = wall_effect;
}

#pragma push
#pragma fp_contract on

void get_hit_surface_point(const ActorBodyHit *hit, Vec *out, Vec *direction) {
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

void spawn_hitogata_particle(Vec *pos) {
    NJS_OBJECT *model;
    NJS_TEXLIST *texture;
    TParticleCtrl *particle;

    particle = spawn_particle_effect(pos, 0x1BF);
    if (particle != NULL) {
        TItemLoad::get_item_model(0xD, &model);
        TItemLoad::get_item_texture_list(0xD, &texture);
        attach_particle_model(particle, model, texture, 0, 0, 1.0f);
        particle->set_scale(10.0f, 10.0f);
    }
}

TItemWeaponTalis::TItemWeaponTalis(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    effect_scale = 5.0f;
}

TItemWeaponMahu::TItemWeaponMahu(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    effect_id = 341;
    wall_effect = (void *)start_red_wall_card;
    hit_effect = (void *)TObjPlayer::create_aux_object;
}

TItemWeaponHitogata::TItemWeaponHitogata(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    effect_id = 447;
    wall_effect = (void *)TObjPlayer::alloc_and_init;
    hit_effect = (void *)TObjPlayer::create_and_init_effect;
}

void TItemWeaponHitogata::spawn_throw_effect(Vec *pos) {
    spawn_hitogata_particle(pos);
}

TItemWeaponDancingHitogata::TItemWeaponDancingHitogata(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    s32 i;
    Vec *origin;
    orbit_timer = 0;
    orbit_count = 0;
    origin = orbit_points;
    for (i = 0; i < 5; i++) {
        origin->x = 0.0f;
        origin->y = 0.0f;
        origin->z = 0.0f;
        origin++;
    }
    wall_effect = (void *)TObjPlayer::alloc_and_init;
    hit_effect = (void *)TObjPlayer::create_and_init_effect;
}

void TItemWeaponDancingHitogata::on_equipped() {
    orbit_timer = 0;
    orbit_count = 0;
    orbit_radius = 5.0f + owner->get_body_radius(0);
    orbit_angle = 0;
    update_orbit_points();
}

void TItemWeaponDancingHitogata::update_weapon() {
    s16 frames;
    s16 count;
    frames = orbit_timer;
    frames += 1;
    orbit_timer = frames;
    if (frames == 0x96) {
        count = orbit_count;
        if (count < 5) {
            orbit_count = count + 1;
            send_activate_effect(orbit_count);
        }
        orbit_timer = 0;
    }
    update_orbit_points();
}

__declspec(section ".rodata") Vec ring_point_template = { 0 };
__declspec(section ".rodata") Vec player_pb_zero_vec_block = { 0 };
void TItemWeaponDancingHitogata::update_orbit_points() {
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
    n = orbit_count;
    if (n != 0) {
        angle = orbit_angle;
        count = n;
        origin = orbit_points;
        center = &owner->body_center.x;
        point_base = &ring_point_template;
        axis_base = &player_pb_zero_vec_block;
        tilt = 0x31C7;
        step = 0x10000 / n;
        tilt_step = 0x238E / n;
        while (count != 0) {
            Vec point = *point_base;
            point.z = orbit_radius;
            Vec axis = *axis_base;
            axis.x = cos_table_lookup(tilt);
            axis.y = sin_table_lookup(tilt);
            push_matrix();
            set_matrix_identity(NULL);
            post_translate_matrix(center);
            rotate_matrix_about_axis(NULL, &axis, angle);
            transform_point_by_current_matrix(&point.x, origin);
            pop_matrix();
            angle += step;
            tilt += tilt_step;
            count--;
            origin++;
        }
        orbit_angle += 0x38E;
    }
}

void TItemWeaponDancingHitogata::activate_effect(s32 count) {
    if (count < 5) {
        orbit_count = count;
    }
}

void TItemWeaponDancingHitogata::draw_held_model() {
    Vec *origin;
    s32 n;
    draw_weapon_model();
    if (is_hidden() == 0) {
        n = orbit_count;
        origin = orbit_points;
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

void TItemWeaponDancingHitogata::emit_marker_effects() {
    Vec *origin;
    s32 angle;
    s32 step;
    s32 n;
    s32 count;
    origin = orbit_points;
    count = orbit_count;
    n = count;
    angle = orbit_angle - owner->rotation_y;
    step = 0x10000 / count;
    while (n != 0) {
        fire_shot_at_target(origin++, item_model, angle);
        angle += step;
        n--;
    }
    spawn_throw_effect(&owner->body_center);
    orbit_count = 0;
    orbit_timer = 0x87;
}

void TItemWeaponDancingHitogata::spawn_throw_effect(Vec *pos) {
    spawn_hitogata_particle(pos);
}

void TItemWeaponDancingHitogata::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    TItemWeaponCard::init_weapon_effect_descriptor(desc);
    desc->speed = 5.0f;
}

TItemWeaponSectionIdCard::TItemWeaponSectionIdCard(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    effect_id = 341;
    hit_effect = (void *)spawn_hit_particles_at;
    wall_effect = (void *)spawn_hit_particles_at_vec;
}

void TItemWeaponSectionIdCard::spawn_hit_particles_at(s32 item_id, ActorBodyHit *hit, Vec *dir) {
    Vec pos;
    get_hit_surface_point(hit, &pos, dir);
    spawn_hit_particles(&pos, dir);
}

void TItemWeaponSectionIdCard::spawn_hit_particles_at_vec(s32 item_id, Vec *point, Vec *dir) {
    Vec pos;
    VecCopy(&pos, point);
    spawn_hit_particles(&pos, dir);
}

extern const f64 radians_to_angle_scale[1] = { 10430.38043493439 };
void TItemWeaponSectionIdCard::spawn_hit_particles(Vec *pos, const Vec *dir) {
    s32 angles[3];
    create_timed_particle_emitter(pos, 0x1EF, 0, 0xF);
    angles[0] = 0;
    angles[1] = (s32)(radians_to_angle_scale[0] * atan2_float(dir->x, dir->z));
    angles[2] = 0;
    {
        TParticleCtrl *particle = create_timed_particle_emitter_with_angles(pos, angles, 0x1B8, 0, 0xF, 4);
        if (particle != NULL) {
            particle->set_scale(1.5f, 1.5f);
        }
    }
}

TItemWeaponAmoreRose::TItemWeaponAmoreRose(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    effect_scale = 1.0f;
    wall_effect = (void *)create_needle_pos_effect;
    hit_effect = (void *)create_needle_effect;
}

void TItemWeaponAmoreRose::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    TItemWeaponCard::init_weapon_effect_descriptor(desc);
    desc->spin[0] = 0x8000;
}

TItemWeaponGalWind::TItemWeaponGalWind(TObject *parent, u8 *item) : TItemWeaponCard(parent, item) {
    effect_scale = 5.0f;
    set_weapon_flags(32);
    hit_effect = (void *)spawn_hit_effect;
    wall_effect = (void *)create_needle_pos_effect;
}

void TItemWeaponGalWind::init_weapon_effect_descriptor(WeaponEffectDescriptor *desc) {
    TItemWeaponCard::init_weapon_effect_descriptor(desc);
    if (is_mode_two_and_ready() != 0) {
        ((TItemWeapon *)this)->drain_owner_hp_fraction(0.07f);
        desc->hits = 10;
        desc->model = second_model;
        desc->scale = 1.0f;
    }
}

void TItemWeaponGalWind::spawn_hit_effect(s32 item_id, ActorBodyHit *hit, Vec *dir) {
    Vec pos;
    get_hit_surface_point(hit, &pos, dir);
    spawn_hit_particle(&pos);
}

TParticleCtrl *TItemWeaponGalWind::spawn_hit_particle(Vec *pos) {
    return spawn_particle_effect(pos, 447);
}

TItemWeaponGalWind::~TItemWeaponGalWind() {}
