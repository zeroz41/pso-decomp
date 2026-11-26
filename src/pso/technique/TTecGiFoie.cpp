#include "pso/system/SoundEffect.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecCircle.h"
#include "pso/technique/TTecBarta.h"
#include "pso/render/DebugFont.h"

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/technique/TechniqueEmitterTable.h"

const char *TTecGiFoie::name = "TTecGiFoie";

// emitter_rows_N: the N particle parts an entry of gifoie_emitter_bands spawns.
static const TechniqueEmitterSourceRow emitter_rows_1[1] = {{34, 2, 0.0f}};
static const TechniqueEmitterSourceRow emitter_rows_2[2] = {{34, 2, 0.0f}, {172, 1, 0.0f}};
static const TechniqueEmitterSourceRow emitter_rows_3[3] = {{34, 2, 0.0f}, {172, 1, 0.0f}, {414, 0x1000, 1.0f}};

static const TechniqueEmitterSourceTable gifoie_emitter_bands[6] = {
    {emitter_rows_1, 1}, {emitter_rows_1, 1}, {emitter_rows_1, 1},
    {emitter_rows_2, 2}, {emitter_rows_2, 2}, {emitter_rows_3, 3},
};

// orbit_counts: per band, how many orbits TTecGiFoie__ct spaces evenly (360 / count degrees) around the caster.
static const u8 orbit_counts[6] = {1, 1, 1, 2, 2, 3};

// defer_codegen emits these in reverse source order: the last function in the file comes first in .text.
#pragma defer_codegen on

void TTecGiFoie::render() {  }

TTecGiFoie::TTecGiFoie(saddr source, Vec *origin, s32 level) : TTecCircle(source, origin, origin, level) {
    s32 i;
    s32 j;
    s32 k;
    s32 r;
    this->m_name = TTecGiFoie::name;
    calc_params();
    if (this->collidable != NULL) {
        this->collidable->bodies->radius = 5.0f + this->params.range;
    }
    for (i = 0; i < 32; i++) {
        this->hitIds[i] = 0xFFFF;
    }
    for (j = 0; j < 3; j++) {
        this->orbits[j] = NULL;
    }
    this->hitCursor = 0;
    for (k = 0; k < orbit_counts[this->band]; k++) {
        Vec v = {0.0f, 0.0f, -10.0f};
        Vec p;
        s32 angle;
        s32 step;
        step = (s32)(182.04445f * (f32)(360 / orbit_counts[this->band]));
        angle = step * k + 0x4000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        p.x = this->position.x + v.x;
        p.y = this->position.y + v.y;
        p.z = this->position.z + v.z;
        this->orbits[k] = new TTecGiFoieFlame(&p, angle, this->band, this->level, tl_07, 0);
    }
    switch (this->band) {
    case 0:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A801, &this->position, 0, 0);
        break;
    case 2:
    case 3:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x180, 0);
        }
        break;
    case 4:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x250, 0);
        }
        break;
    case 5:
        r = play_sound_effect(0x4002A801, &this->position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    default:
        play_sound_effect(0x4002A801, &this->position, 0, 0);
        break;
    }
    if (this->source != NULL) {
        this->sourceId = this->source->get_entity_id();
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TTecGiFoie::run_task() {
    f32 distance;
    if (this->collidable == NULL) {
        queue_destruction();
        return;
    }
    this->source = find_entity_by_id(this->sourceId);
    if (this->source == 0) {
        queue_destruction();
        return;
    }
    if (TTecLuker::is_parents_unqueued((uaddr)this->orbits[0]) != 0) {
        distance = newton_sqrtf(horizontal_distance_squared(&this->orbits[0]->pos, &this->position));
        if (this->collidable != NULL) {
            this->collidable->bodies->radius = 5.0f + distance;
        }
        apply_technique_to_area_targets();
        if (distance >= this->params.range) {
            queue_destruction();
        }
    }
}
#pragma pop

TTecGiFoie::~TTecGiFoie() {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (TTecLuker::is_parents_unqueued((uaddr)this->orbits[i]) != 0) {
            this->orbits[i]->queue_destruction();
        }
    }
}

void TTecGiFoie::apply_to_target(TObjChara *target) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (hitIds[i] == target->get_entity_id()) {
            found = 1;
        }
    }
    if (found == 0) {
        hitIds[hitCursor] = target->get_entity_id();
        hitCursor += 1;
        if (hitCursor >= 32) {
            hitCursor = 31;
        }
        DirectAttackPayload hit;
        hit.kind = 1;
        hit.power = params.power;
        target->receive_direct_attack(source, hit, contact, 1, -1);
    }
}

void TTecGiFoie::create(void *source, void *origin, s32 level) {
    new TTecGiFoie((saddr)source, (Vec *)origin, level);
}

TTecGiFoieFlame::TTecGiFoieFlame(Vec *pos, s32 angle, s32 band, s32 level, TObject *parent, u8 single) : TObject(parent) {
    this->planar = 0;
    this->center.x = pos->x;
    this->center.y = pos->y;
    this->center.z = pos->z;
    this->band = band;
    this->level = level;
    VecCopy(&this->pos, &this->center);
    this->angle = angle;
    this->radius = 0.0f;
    this->frames = 0;
    this->single = single;
    if (this->single != 0) {
        ParticleAngles r;
        this->particles = (TParticleCtrl **)mem_alloc(4);
        r.x = 0;
        r.y = 0;
        r.z = 0x4000;
        this->particles[0] = (TParticleCtrl *)spawn_continuous_particle_with_direction(&this->center, &r, 0x19D);
        this->radius = 5.0f;
    } else {
        s32 i;
        this->particles = (TParticleCtrl **)mem_alloc(gifoie_emitter_bands[this->band].count * 4);
        for (i = 0; i < gifoie_emitter_bands[this->band].count; i++) {
            ParticleAngles r;
            const TechniqueEmitterSourceRow *p;
            r.x = 0;
            r.y = 0;
            r.z = 0x4000;
            p = &gifoie_emitter_bands[this->band].rows[i];
            this->particles[i] = (TParticleCtrl *)spawn_particle_effect_with_rotation(&this->center, &r, p->entry, (p->flags & 0x1000) ? (u16)0x2000 : (u16)0);
            if (this->band == 2) {
                if (level >= 0xF && level < 0x19) {
                    if (i <= 1 && this->particles[i] != NULL) {
                        this->particles[i]->set_scale(1.3f, 1.3f);
                    }
                } else if (level >= 0x19 && level < 0x1E) {
                    if (i <= 1 && this->particles[i] != NULL) {
                        this->particles[i]->set_scale(1.3f, 1.8f);
                    }
                }
            }
        }
    }
}

TTecGiFoieFlame::~TTecGiFoieFlame() {
    u32 i;
    if (this->single != 0) {
        this->particles[0]->queue_destruction();
    } else {
        for (i = 0; i < gifoie_emitter_bands[this->band].count; i++) {
            this->particles[i]->queue_destruction();
        }
    }
    mem_free(this->particles);
}

// Flame bob height per orbit slot, scaled by the sine of the bob phase.
static const f32 flame_bob_heights[3] = {0.0f, 3.5f, 7.0f};

void TTecGiFoieFlame::run_task() {
    s32 rot[3];
    s32 bob;
    switch (band) {
    case 0:
        bob = 0;
        break;
    case 1:
        bob = 1;
        break;
    case 2:
        bob = 2;
        break;
    case 3:
        bob = 0;
        break;
    case 4:
        bob = 1;
        break;
    case 5:
        bob = 2;
        break;
    default:
        bob = 0;
        break;
    }
    frames++;
    if (planar) {
        Vec offset;
        radius += 0.015;
        angle += 0x1C71;
        offset.x = radius * cos_table_lookup(angle);
        offset.z = radius * sin_table_lookup(angle);
        offset.y = 0.0f;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, yaw);
        rotate_matrix_x(0, 0x4000);
        rotate_vector_by_matrix(0, &offset, &offset);
        pop_matrix();
        pos.x = center.x + offset.x;
        pos.y = center.y + offset.y;
        pos.z = center.z + offset.z;
    } else {
        radius += 0.55f;
        angle += (s32)(182.04445f * (band + 9));
        pos.y = flame_bob_heights[bob] * sin_table_lookup((s32)(182.04445f * (f32)(frames * 15))) + center.y;
        pos.x = radius * cos_table_lookup(angle) + center.x;
        pos.z = radius * sin_table_lookup(angle) + center.z;
    }
    if (single) {
        Vec dir = {0.0f, 0.0f, 1.0f};
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, yaw);
        rotate_vector_by_matrix(0, &dir, &dir);
        pop_matrix();
        rot[0] = 0;
        rot[1] = 0;
        rot[2] = 0;
        direction_to_rotation_xz((u8 *)&dir, &rot[0], &rot[2]);
        particles[0]->set_position(&pos);
        particles[0]->set_direction(rot);
    } else {
        u32 i;
        s16 roll;
        rot[1] = (s32)(10430.38043493439 * atan2_float(pos.x - center.x, pos.z - center.z));
        roll = i = 0;
        rot[0] = rot[1] - 0x8000;
        rot[1] = roll;
        rot[2] = 0x4000;
        for (; i < gifoie_emitter_bands[band].count; i++) {
            particles[i]->set_position(&pos);
            particles[i]->set_direction(rot);
        }
    }
}

void TTecGiFoie::calc_params() {
    TechniqueParams *scaled = calc_technique_parameters(1, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[1].base + tech_high_level_linear_power_table[1].per_level * level);
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (TTecCtrl::is_technique_ready()) {
        params.power = params.power * technique_scale_table[1].power;
    }
}

#pragma defer_codegen off
