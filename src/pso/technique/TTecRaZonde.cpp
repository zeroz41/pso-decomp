#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "pso/system/memory.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecRaZonde.h"
#include "pso/technique/TechniqueEmitter.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/technique/TFireExplosion.h"
#include "pso/technique/TTecCircle.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#pragma readonly_strings on

#include <stddef.h>

#include "pso/technique/TTecResta.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/key/TOKeyMachine01.h"
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

#pragma fp_contract on

// Per band: the particle emitters spawn_effects places along the bolt points.
extern const TechniqueEmitter razonde_emitters_low[1] = {{147}};
extern const TechniqueEmitter razonde_emitters_mid[2] = {{170}, {173}};
extern const TechniqueEmitter razonde_emitters_high[2] = {{171}, {174}};
extern const TechniqueEmitterSet razonde_band_emitter_table[6] = {
    {razonde_emitters_low, 1}, {razonde_emitters_low, 1}, {razonde_emitters_low, 1},
    {razonde_emitters_mid, 2}, {razonde_emitters_mid, 2}, {razonde_emitters_high, 2},
};
const char *TTecRaZonde_class_name = "TTecRaZonde";

void TTecRaZonde::spawn_effects(Vec *) {
    u32 i;
    emitters = (TParticleCtrl **)mem_alloc(razonde_band_emitter_table[band].count * sizeof(TParticleCtrl *));
    for (i = 0; i < razonde_band_emitter_table[band].count; i++) {
        emitters[i] = create_particle_emitter(&bolt_points[i], razonde_band_emitter_table[band].emitters[i].entry);
    }
}

void TTecRaZonde::calc_damage() {
    TechniqueParams *scaled = calc_technique_parameters(8, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[8].base + tech_high_level_linear_power_table[8].per_level * level);
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (TTecCtrl::is_technique_ready()) {
        params.power = params.power * technique_scale_table[8].power;
    }

}
void TTecRaZonde::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 3;
    hit.power = this->params.power;
    target->receive_direct_attack(this->source, hit, 0, 8, -1);
}

void TTecRaZonde::create(TObjBase *source, Vec *origin, s32 level) {
    new TTecRaZonde(source, origin, level);
}

TTecRaZonde::~TTecRaZonde() {
    u32 i;
    for (i = 0; i < razonde_band_emitter_table[band].count; i++) {
        if (emitters[i] != NULL) {
            emitters[i]->queue_destruction();
            emitters[i] = NULL;
        }
    }
    mem_free(emitters);
}

void TTecRaZonde::render() {  }

void TTecRaZonde::run_task() {
    s32 i;
    if (this->collidable == NULL) {
        queue_destruction();
        return;
    }
    this->source = find_entity_by_id(this->sourceId);
    if (this->source == NULL) {
        queue_destruction();
        return;
    }
    for (i = 0; i < razonde_band_emitter_table[this->band].count; i++) {
        if (this->sourceId < 12) {
            if (i == 1) {
                create_timed_particle_emitter(&((TObjChara *)this->source)->body_center, razonde_band_emitter_table[this->band].emitters[i].entry, 0, 60);
            } else {
                spawn_particle_effect(&((TObjChara *)this->source)->body_center, razonde_band_emitter_table[this->band].emitters[i].entry);
            }
        }
    }
    apply_technique_to_area_targets();
    queue_destruction();
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
TTecRaZonde::TTecRaZonde(TObjBase *source, Vec *origin, s32 level) : TTecCircle(source, origin, origin, level) {
    s32 ang;
    s32 i;
    s32 j;
    f32 r;
    f32 len;
    Vec a;
    Vec b;
    m_name = TTecRaZonde_class_name;
    calc_damage();
    if (collidable != NULL) {
        collidable->bodies->radius = (5.0f) + params.range;
    }
    spawn_effects(0);
    r = (0.0f);
    ang = 0;
    for (i = 0; i < 8; i++) {
        s16 lv = this->level;
        f32 step = (5.4f);
        if (lv >= 15 && lv < 25) {
            step = (8.1f);
        } else if (lv >= 25 && lv < 30) {
            step = (10.8f);
        }
        r += step;
        ang += 0x2AAA;
        bolt_points[i].x = r * cos_table_lookup(ang) + position.x;
        bolt_points[i].y = position.y;
        bolt_points[i].z = r * sin_table_lookup(ang) + position.z;
    }
    for (j = 0; j < 7; j++) {
        VecCopy(&a, (const Vec *)&bolt_points[j]);
        VecCopy(&b, (const Vec *)&bolt_points[j + 1]);
        b.x = b.x - a.x;
        b.y = b.y - a.y;
        b.z = b.z - a.z;
        len = vector_length(&b);
        if ((0.0f) != len) {
            normalize_vector(&b);
        }
        new TTecZondeEff(tl_07, &a, &b, 0x14000000, 6, len, 5.0f);
        if (band == 5) {
            new TTecZondeEff(tl_07, &a, &b, 0x14000000, 6, len, 0.5f);
        }
    }
    switch (band) {
    case 0: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    }
    case 1:
        play_sound_effect(0x4002A50A, &position, 0, 0);
        break;
    case 2:
    case 3: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    }
    case 4: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    }
    case 5: {
        s32 h = play_sound_effect(0x4002A50A, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
    }
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
}
#pragma pop

void TTecResta::play_launch_sound() {
    s32 h;
    switch (band) {
    case 0:
    case 1:
        h = play_sound_effect(0x4002AB0E, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AB0E, &position, 0, 0);
        break;
    case 4:
    case 5:
        h = play_sound_effect(0x4002AB0E, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
}
