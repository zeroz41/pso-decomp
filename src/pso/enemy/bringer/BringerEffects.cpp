#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/bringer/BringerEffects.h"
#include "pso/enemy/bringer/TObjEneDf2Bringer_Eff_Rush.h"
#include "pso/enemy/TUnk_8048FE08.h"
#include "pso/enemy/TUnk_8048FE64.h"
#include "pso/enemy/TUnk_8048FE7C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/FloatRounding.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"

// Written last-to-first: the unit is built with -inline off,deferred, which emits the functions
// (and pools their constants) in reverse order.

extern "C" {
u16 get_entity_id(void *);
s32 is_player_entity_id(u16);
s32 is_vec_xz_cross_negative(void *, void *);
s32 rotate_xz_pair_by_angle(void *, void *, s32);
s32 rand();
s32 fill_value_array(int);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__26TObjEneDf2Bringer_Eff_Rush[];
}

// The first argument of TUnk_804928CC::call_vt13_with_default (contents {3.0f, 3}; fields unknown),
// as in TObjEneDellBiterEffects.
struct BringerTpAbsorbHitParams {
    f32 unk_0;
    s32 unk_4;
};

const char *bringer_rush_effect_name = "TObjEneDf2Bringer_Eff_Rush";
const char *bringer_tp_absorb_effect_name = "TObjEneDf2Bringer_Eff_TpAbsorb1";
extern const BringerTpAbsorbHitParams lbl_8043A164 = {3.0f, 3};
extern const DirectAttackPayload lbl_8043A16C = {0, 20.0f};

Vec bringer_effect_vec_table[6];
u32 bringer_effect_color_table[12];

#pragma fp_contract on

// TObjEneDf2Bringer__sub_80099248 calls this on TObject::operator new(0x34)'s result; written as
// `new TObjEneDf2Bringer_Eff_Rush(...)` that caller allocates its registers differently, so the
// constructor stays a free function for now (parent, source, recipient, speed as in
// TObjEneDellBiter_Eff_Rush's ctor).
u8 *construct_bringer_rush_effect(u8 *rush, s32 parent, u8 *source, s32 recipient, f32 speed) {
    TObjEneDf2Bringer_Eff_Rush *self = (TObjEneDf2Bringer_Eff_Rush *)rush;
    Vec displacement;
    __ct__7TObjectFP7TObject(self, (void *)parent);
    *(s32 **)((u8 *)self + 0x18) = __vt__26TObjEneDf2Bringer_Eff_Rush;
    self->m_name = bringer_rush_effect_name;
    self->target = (TObjChara *)recipient;
    self->strength = speed;
    self->field_30 = 0;
    VecCopy(&displacement, &((TObjChara *)recipient)->position);
    subtract_vector(&displacement, &((TObjBase *)source)->position);
    displacement.y = 0.0f;
    self->direction.x = sin_table_lookup(((TObjBase *)source)->rotation_y);
    self->direction.y = 0.0f;
    self->direction.z = cos_table_lookup(((TObjBase *)source)->rotation_y);
    if (is_vec_xz_cross_negative(&self->direction, &displacement) != 0) {
        rotate_xz_pair_by_angle(&self->direction.x, &self->direction.z, -0x1800);
    } else {
        rotate_xz_pair_by_angle(&self->direction.x, &self->direction.z, 0x1800);
    }
    return rush;
}

TObjEneDf2Bringer_Eff_Rush::~TObjEneDf2Bringer_Eff_Rush() {}

void TObjEneDf2Bringer_Eff_Rush::run_task() {
    if (is_player_entity_id(get_entity_id(target)) != 0) {
        queue_destruction();
        return;
    }
    if (target->is_alive() == 0) {
        queue_destruction();
        return;
    }
    if (target->obj_isState2_324() != 0) {
        queue_destruction();
        return;
    }
    f32 speed = strength;
    if (speed <= 0.02f) {
        queue_destruction();
        return;
    }
    target->x_speed = direction.x * speed;
    target->m_310 = direction.z * strength;
    strength *= 0.8f;
}

void TObjEneDf2Bringer_Eff_Rush::render() {}

void init_bringer_effect_tables(void) {
    s32 angle;
    Vec *v;
    f32 green;
    s32 i;
    u32 blue;
    u32 *p;
    u32 c;
    s32 j;
    f32 sn;
    f32 cs;
    angle = 0;
    v = bringer_effect_vec_table;
    for (i = 0; i < 6; i++) {
        sn = sin_table_lookup(angle);
        cs = cos_table_lookup(angle);
        v->x = sn;
        v->y = 0.0f;
        v->z = cs;
        angle += 0x6666;
        v++;
    }

    blue = (u8)((u32)floor_to_float(255.0f * (3.0517578125e-05f * rand())));
    green = floor_to_float(255.0f * (3.0517578125e-05f * rand()));
    c = (((u8)((u32)green)) << 8) | blue;
    p = bringer_effect_color_table;
    for (j = 0; j < 12; j++) {
        c = ((u16)c) << 8;
        c |= (u8)((u32)floor_to_float(255.0f * (3.0517578125e-05f * rand())));
        *p = c;
        p++;
    }
}

void bringer_effect_cleanup_noop(void) {}

TUnk_8048FE7C::TUnk_8048FE7C(TObject *parent, const Vec *pos, f32 max_radius) : TObject(parent) {
    m_name = bringer_tp_absorb_effect_name;
    VecCopy(&position, pos);
    state = 0;
    radius = 10.0f;
    this->max_radius = max_radius;
    angle = 0;
    alpha = 1.0f;
    frame = 0;
    sub_8009A640();
    sub_8009A598();
}

TUnk_8048FE7C::~TUnk_8048FE7C() {}

void TUnk_8048FE7C::sub_8009A640() {
    s32 i;
    f32 outer = 3.0f + radius;
    f32 inner = radius - 3.0f;
    Vec *src = bringer_effect_vec_table;
    Vertex *dst = vertices;
    for (i = 0; i < 6; i++) {
        f32 x = src->x;
        f32 z = src->z;
        src++;
        dst[0].pos.x = x * outer;
        dst[0].pos.y = 0.0f;
        dst[0].pos.z = z * outer;
        dst[1].pos.x = x * inner;
        dst[1].pos.y = 0.0f;
        dst[1].pos.z = z * inner;
        dst += 2;
    }
}

void TUnk_8048FE7C::sub_8009A598() {
    s32 i;
    s32 n;
    Vertex *p;
    u32 c;
    c = (u32)floor_to_float(255.0f * alpha) << 24;
    n = frame;
    p = vertices;
    for (i = n; i < 12; i++) {
        u32 v = bringer_effect_color_table[n];
        p->color = v | c;
        p++;
    }
    for (i = 0; i < frame; i++) {
        p->color = bringer_effect_color_table[0] | c;
        p++;
    }
}

void TUnk_8048FE7C::run_task() {
    switch (state) {
    case 0:
        radius += 7.0f;
        if (radius >= max_radius) {
            radius = max_radius;
            state = 1;
        }
        sub_8009A640();
        break;
    case 1:
        alpha = alpha - 0.05f;
        if (alpha < 0.0f) {
            alpha = 0.0f;
            queue_destruction();
            return;
        }
        break;
    }
    angle += 0x800;
    frame++;
    if (frame >= 12) {
        frame = 0;
    }
    sub_8009A598();
}

void TUnk_8048FE7C::render() {
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, angle);
    ((TObjPlayer *)&vertices[0])->draw_trail_strip((void *)6, alpha < 1.0f);
    ((TObjPlayer *)&vertices[6])->draw_trail_strip((void *)6, alpha < 1.0f);
    pop_matrix();
}

TUnk_8048FE64::TUnk_8048FE64(TObject *parent, const Vec *from, const Vec *to) : TObject(parent) {
    m_name = bringer_tp_absorb_effect_name;
    VecCopy(&start, from);
    VecCopy(&end, to);
    VecCopy(&position, &start);
    VecCopy(&delta, &end);
    subtract_vector(&delta, &start);
    length = ((TObjBoss2Tunnel *)&delta)->update_scale();
    frames = 0.0f;
}

TUnk_8048FE64::~TUnk_8048FE64() {}

void TUnk_8048FE64::run_task() {
    f32 travelled;
    frames += 1.0f;
    travelled = 6.0f * frames;
    if (travelled >= length) {
        VecCopy(&position, &end);
        queue_destruction();
        return;
    }
    position.x = delta.x * travelled + start.x;
    position.y = delta.y * travelled + start.y;
    position.z = delta.z * travelled + start.z;
}

void TUnk_8048FE64::render() {}

TUnk_8048FE08::TUnk_8048FE08(TObject *parent, TObjBase *owner, AreaAttackHistory *history)
    : TUnk_804928CC(parent, owner) {
    m_name = bringer_tp_absorb_effect_name;
    active = 0;
    power = 0.0f;
    distance = 0.0f;
    sample_distance = 0.0f;
    timer = 0;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = 0.0f;
    attack_history = history;
    bodies->shape = 1;
}

TUnk_8048FE08::~TUnk_8048FE08() {}

void TUnk_8048FE08::setup_dir_shot(const Vec *origin, s32 angle, f32 attack_power) {
    VecCopy(&position, origin);
    rotation_y = angle;
    direction.x = sin_table_lookup(rotation_y);
    direction.y = 0.0f;
    direction.z = cos_table_lookup(rotation_y);
    active = 1;
    fill_value_array((int)attack_history);
    distance = 0.0f;
    sample_distance = 0.0f;
    power = attack_power;
    timer = 25;
}

void TUnk_8048FE08::sub_8009A11C() { active = 0; }

void TUnk_8048FE08::run_task() {
    Vec destination;
    Vec offset;
    Vec sample;
    DirectAttackPayload attack;
    s32 hit;
    f32 step;
    if (active == 0) {
        return;
    }
    hit = 0;
    VecCopy(&destination, &position);
    destination.x = 10.0f * direction.x + destination.x;
    destination.z = 10.0f * direction.z + destination.z;
    step = 10.0f;
    CsnHit *contact = csnVector(&position, &destination, 0x16EF);
    if (contact != NULL) {
        VecCopy(&destination, &contact->contact->point);
        VecCopy(&offset, &position);
        subtract_vector(&offset, &destination);
        step = ((TObjBoss2Tunnel *)&offset)->update_scale();
        hit = 1;
    }
    f32 spacing = 16.0f;
    distance += step;
    while (distance > sample_distance) {
        VecCopy(&sample, &position);
        sample.x = sample_distance * direction.x + sample.x;
        sample.z = sample_distance * direction.z + sample.z;
        create_timed_particle_emitter(&sample, 0xEE, 0, 1);
        sample_distance += spacing;
    }
    sample_distance -= step;
    distance -= step;
    VecCopy(&position, &destination);
    bodies->half_width = 2.5f;
    bodies->radius = 0.5f * step;
    update_enemy_collision_flags();
    if (bodies->flags & 0x200000) {
        sub_8009A11C();
        return;
    }
    attack.kind = lbl_8043A16C.kind;
    attack.power = power;
    call_vt13_with_default((void *)&lbl_8043A164, &attack, (s32)attack_history);
    timer--;
    if (hit != 0 || timer < 0) {
        sub_8009A11C();
    }
}

void TUnk_8048FE08::render() {
    if (active == 0) {
        return;
    }
}
