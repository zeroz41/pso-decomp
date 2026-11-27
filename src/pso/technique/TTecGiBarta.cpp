#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TechniqueBandSound.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/audio/SoundRequests.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/render/DebugFont.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/technique/TechniqueEmitterTable.h"

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TTecGiBarta::update_technique_by_phase() {
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A605, &position, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A605, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
#pragma pop

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off

static const TechniqueEmitterSourceRow giBarta_band0_emitters[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.0f},
    {0x182, 0x20022, 0.0f},
};
static const TechniqueEmitterSourceRow giBarta_band1_emitters[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.2f},
    {0x183, 0x20062, 1.4f},
};
static const TechniqueEmitterSourceRow giBarta_band2_emitters[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.4f},
    {0x184, 0x20062, 1.4f},
};
static const TechniqueEmitterSourceRow giBarta_band3_emitters[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.6f},
    {0x185, 0x30062, 1.6f},
};
static const TechniqueEmitterSourceRow giBarta_band4_emitters[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.8f},
    {0x186, 0x30062, 1.8f},
};
static const TechniqueEmitterSourceRow giBarta_band5_emitters[2] = {
    {0x181, 0x42, 2.2f},
    {0x18E, 0x30062, 2.2f},
};
static const TechniqueEmitterSourceTable gibarta_emitter_bands[6] = {
    {giBarta_band0_emitters, 3}, {giBarta_band1_emitters, 3}, {giBarta_band2_emitters, 3},
    {giBarta_band3_emitters, 3}, {giBarta_band4_emitters, 3}, {giBarta_band5_emitters, 2},
};
const char *TTecGiBarta::class_name = "TTecGiBarta";
const Vec giBarta_emitter_offset = {0.0f, 0.0f, 3.0f};


void TTecGiBarta::create_particles() {
    Angle3 angles;
    Vec pos;
    Vec off;
    Vec p2;
    Vec v;
    u32 i;
    TParticleCtrl *emitter;
    TObjCollidable *src;

    angles.x = this->angles[0];
    angles.y = 0;
    angles.z = this->angles[2];
    emitters = static_cast<TParticleCtrl **>(mem_alloc(gibarta_emitter_bands[band].count * sizeof(*emitters)));
    for (i = 0; i < gibarta_emitter_bands[band].count; i++) {
#ifdef __MWERKS__
        __memcpy(&pos, &position, sizeof(pos));
#else
        pos = position;
#endif
        if (gibarta_emitter_bands[band].rows[i].flags & 0x800) {
            pos.y -= 5.0f;
        }
        if (gibarta_emitter_bands[band].rows[i].flags & 2) {
            emitter = static_cast<TParticleCtrl *>(spawn_continuous_particle_with_direction(
                &pos, &angles, gibarta_emitter_bands[band].rows[i].entry));
        } else {
#ifdef __MWERKS__
            __memcpy(&off, &giBarta_emitter_offset, sizeof(off));
#else
            off = giBarta_emitter_offset;
#endif
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, this->angles[1]);
            matrix_mult_vec(0, &off, &off);
            pop_matrices(1);
            p2.x = position.x + off.x;
            p2.y = position.y + off.y;
            p2.z = position.z + off.z;
            if (gibarta_emitter_bands[band].rows[i].flags & 0x800) {
                p2.y -= 5.0f;
            }
            emitter = create_particle_emitter(&p2, gibarta_emitter_bands[band].rows[i].entry);
        }
        if (emitter != NULL) {
            if (gibarta_emitter_bands[band].rows[i].flags & 0x40) {
                emitter->set_scale(gibarta_emitter_bands[band].rows[i].scale, gibarta_emitter_bands[band].rows[i].scale);
            }
            if (gibarta_emitter_bands[band].rows[i].flags & 0x20) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, (u16)(gibarta_emitter_bands[band].rows[i].flags >> 16)), technique_texture_list, 0, 0, 1.0f);
            }
        }
        emitters[i] = emitter;
    }
    if (band == 5) {
        VecCopy(&v, &position);
        v.y -= 15.0f;
        spawn_particle_effect(&v, 0x1E0);
        spawn_particle_effect(&v, 0x1E1);
        src = find_entity_by_id(sourceId);
        if (src != NULL) {
            emitter = spawn_particle_effect(&src->position, 0x18B);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 6), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(&src->position, 0x18B, 5, 1);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 7), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(&src->position, 0x18B, 10, 1);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 8), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(&src->position, 0x18F, 20, 1);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
            }
        }
    }
}
#pragma auto_inline off

void TTecGiBarta::calc_params() {
    TechniqueParams *scaled = calc_technique_parameters(4, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[4].base + tech_high_level_linear_power_table[4].per_level * level);
    } else {
        params.power = params.power + (f32)(params.power_per_level * level);
        if (is_technique_ready() != 0) {
            params.power = params.power * technique_scale_table[4].power;
        }
    }
    range = params.range;
}

void TTecGiBarta::apply_to_target(TObjChara *target) {
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
        hit.kind = 2;
        hit.power = params.power;
        target->receive_direct_attack(source, hit, contact, 4, -1);
    }
}

void TTecGiBarta::create(TObjBase *owner, Vec *position, Vec *target, s32 level) {
    new TTecGiBarta(owner, position, target, level);
}

void TTecGiBarta::create_ex(TObjBase *owner, Vec *position, s32 angle, s32 level) {
    new TTecGiBarta(owner, position, angle, level);
}

TTecGiBarta::~TTecGiBarta() {
    for (u32 i = 0; i < gibarta_emitter_bands[band].count; ++i) {
        if (emitters[i]) {
            emitters[i]->queue_destruction();
        }
    }
    mem_free(emitters);
}

void TTecGiBarta::run_task() {
    this->source = find_entity_by_id(this->sourceId);
    if (this->source == NULL) {
        queue_destruction();
        return;
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

TTecGiBarta::TTecGiBarta(TObjBase *source, Vec *pos, Vec *target, s32 level)
    : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecGiBarta::class_name;
    calc_params();
    halfWidth = 12.0f;
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    if (this->source) {
        sourceId = this->source->get_entity_id();
    }
    create_particles();
    update_technique_by_phase();
}

TTecGiBarta::TTecGiBarta(TObjBase *source, Vec *pos, s32 angle, s32 level)
    : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecGiBarta::class_name;
    calc_params();
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
    create_particles();
    update_technique_by_phase();
}

void TTecGiBarta::render() {  }
