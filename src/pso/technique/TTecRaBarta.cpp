#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/technique/TechniqueEmitter.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/unk/TLobby_8001EF5C.h"

#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"

#include "pso/unk/TLobby_80226070.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/technique/TFireExplosion.h"
#include "pso/technique/TTecCircle.h"
#pragma readonly_strings on

#include <stddef.h>

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecPlayerInfluence.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

// Per band: the particle emitters spawn_effects places.
extern const TechniqueEmitter rabarta_band_emitters_0[3] = {{473, 0, 0.0f}, {475, 0, 0.0f}, {479, 0x20060, 1.0f}};
extern const TechniqueEmitter rabarta_band_emitters_1[3] = {{473, 0, 0.0f}, {475, 0x40, 1.2f}, {404, 0x20060, 1.2f}};
extern const TechniqueEmitter rabarta_band_emitters_2[3] = {{473, 0, 0.0f}, {475, 0x40, 1.2f}, {405, 0x20060, 1.4f}};
extern const TechniqueEmitter rabarta_band_emitters_3[3] = {{473, 0, 0.0f}, {406, 0, 0.0f}, {409, 0x30060, 1.6f}};
extern const TechniqueEmitter rabarta_band_emitters_4[3] = {{473, 0, 0.0f}, {406, 0x40, 1.2f}, {410, 0x30060, 1.8f}};
extern const TechniqueEmitter rabarta_band_emitters_5[3] = {{473, 0, 0.0f}, {407, 0, 0.0f}, {411, 0x40060, 1.0f}};
extern const TechniqueEmitterSet rabarta_band_emitter_table[6] = {
    {rabarta_band_emitters_0, 3}, {rabarta_band_emitters_1, 3}, {rabarta_band_emitters_2, 3},
    {rabarta_band_emitters_3, 3}, {rabarta_band_emitters_4, 3}, {rabarta_band_emitters_5, 3},
};
// The extra effect band 5 spawns above the point, raised by rabarta_top_effect_height.
extern const TechniqueEmitter rabarta_top_effect = {470, 0x10828, 0.0f};
const char *TTecRaBarta_class_name = "TTecRaBarta";
__declspec(section ".sdata2") extern const f32 rabarta_top_effect_height;

void TTecRaBarta::spawn_effects(Vec *pos) {
    u32 i;
    Vec point;
    const TechniqueEmitter *binding;
    emitters = (TParticleCtrl **)mem_alloc(rabarta_band_emitter_table[band].count * sizeof(TParticleCtrl *));
    for (i = 0; i < rabarta_band_emitter_table[band].count; i++) {
        VecCopy(&point, &source->position);
        if (pos != NULL) {
            VecCopy(&point, pos);
        }
        emitters[i] = create_particle_emitter(&point, rabarta_band_emitter_table[band].emitters[i].entry);
        binding = &rabarta_band_emitter_table[band].emitters[i];
        if ((binding->flags & 0x40) && (emitters[i] != NULL)) {
            emitters[i]->set_scale(binding->scale, binding->scale);
        }
        if (rabarta_band_emitter_table[band].emitters[i].flags & 0x20) {
            u32 model = rabarta_band_emitter_table[band].emitters[i].flags >> 16;
            if (pos && pos) {  // empty test carried over: only a two-term condition here keeps the model shift scheduled as built
            }
            attach_particle_model(emitters[i], get_bml_model(technique_effect_bml, model), technique_texture_list, 0, 0, 1.0f);
        }
    }
    if (band == 5) {
        Vec top;
        const TechniqueEmitter *effect = &rabarta_top_effect;
        f32 height = rabarta_top_effect_height;
        u32 model;
        TParticleCtrl *emitter;
        if (pos != NULL) {
            VecCopy(&top, pos);
        } else {
            VecCopy(&top, &source->position);
        }
        top.y += height;
        emitter = spawn_particle_effect(&top, effect->entry);
        model = effect->flags >> 16;
        if (emitter != NULL) {
            attach_particle_model(emitter, get_bml_model(technique_effect_bml, model), technique_texture_list, get_bml_motion(technique_effect_bml, 1), 0, 1.0f);
        }
    }
}

extern const f32 rabarta_top_effect_height = 5.0f;

void TTecRaBarta::play_cast_sound() {
    s32 handle;

    switch (this->band) {
    case 0:
        this->sound = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->sound;
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        this->sound = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        return;
    case 2:
    case 3:
        this->sound = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->sound;
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        this->sound = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->sound;
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        this->sound = play_sound_effect(0x4002A706, &reinterpret_cast<TObjChara *>(this->source)->body_center, 0, 0);
        handle = this->sound;
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}

void TTecRaBarta::calc_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(5, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = tech_high_level_linear_power_table[5].base + tech_high_level_linear_power_table[5].per_level * level;
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (TTecCtrl::is_technique_ready() != 0) {
        params.power = params.power * technique_scale_table[5].power;
    }
}

void TTecRaBarta::apply_to_target(TObjChara *target) {
    s32 found = 0;
    s32 i;
    for (i = 0; i < 32; i++) {
        if (hit_ids[i] == target->get_entity_id()) {
            found = 1;
        }
    }
    if (found == 0) {
        hit_ids[hitCursor] = target->get_entity_id();
        hitCursor += 1;
        if (hitCursor >= 32) {
            hitCursor = 31;
        }
        DirectAttackPayload hit;
        hit.kind = 2;
        hit.power = params.power;
        target->receive_direct_attack(source, hit, contact, 5, -1);
    }
}

void TTecRaBarta::create(void *source, Vec *origin, Vec *pos, s32 level) {
    new TTecRaBarta((saddr)source, origin, pos, level);
}

void TTecRaBarta::create(void *source, void *origin, s32 level) {
    new TTecRaBarta((saddr)source, (Vec *)origin, level);
}

TTecRaBarta::~TTecRaBarta() {
    u32 i;
    TParticleCtrl *emitter;
    for (i = 0; i < rabarta_band_emitter_table[band].count; i++) {
        emitter = emitters[i];
        if (emitter != NULL) {
            emitter->queue_destruction();
        }
    }
    stop_sound_request(sound);
    mem_free(emitters);
}

void TTecRaBarta::render() {  }

void TTecRaBarta::run_task() {
    if ((uaddr) this->collidable == 0U) {
        queue_destruction();
        return;
    }
    this->source = find_entity_by_id((this->sourceId));
    if ((u32) this->source == 0U) {
        queue_destruction();
        return;
    }
    this->age = this->age + 1;
    apply_technique_to_area_targets();
    if ((s32) this->age > (s16) this->params.duration) {
        queue_destruction();
    }
}

#pragma push
#pragma opt_common_subs off

TTecRaBarta::TTecRaBarta(saddr source, Vec *origin, Vec *pos, s32 level) : TTecCircle(source, origin, pos, level) {
    s32 i;
    m_name = TTecRaBarta_class_name;
    calc_parameters();
    has_point = 1;
    VecCopy(&position, VecCopy(&target, pos));
    if (collidable != NULL) {
        collidable->bodies->radius = params.range;
    }
    for (i = 0; i < 32; i++) {
        hit_ids[i] = 0xFFFF;
    }
    hitCursor = 0;
    spawn_effects(&position);
    play_cast_sound();
    if (this->source != 0) {
        sourceId = this->source->get_entity_id();
    }
}
#pragma pop

TTecRaBarta::TTecRaBarta(saddr source, Vec *origin, s32 level) : TTecCircle(source, origin, origin, level) {
    s32 i;
    m_name = TTecRaBarta_class_name;
    has_point = 0;
    calc_parameters();
    if (collidable != NULL) {
        collidable->bodies->radius = params.range;
    }
    for (i = 0; i < 32; i++) {
        hit_ids[i] = 0xFFFF;
    }
    hitCursor = 0;
    spawn_effects(0);
    play_cast_sound();
    if (this->source != 0) {
        sourceId = this->source->get_entity_id();
    }
}
