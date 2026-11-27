#include "pso/system/memory.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/technique/TTecShot.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

void TTecFoie::play_foie_cast_sound() {
    s32 h;
    switch (band) {
    case 0:
        h = play_sound_effect(0x4002A600, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 1:
    case 2:
        play_sound_effect(0x4002A600, &position, 0, 0);
        break;
    case 3:
        h = play_sound_effect(0x4002A600, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    case 4:
        h = play_sound_effect(0x4002A600, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    case 5:
        h = play_sound_effect(0x4002A600, &position, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
}

// foie_emitter_rows_N: the particle parts entry N of
// TTecFoie::emitter_bands spawns; the scale of part 0x14 grows with the band.
static const TechniqueEmitterSourceRow foie_emitter_rows_0[1] = {{0x14, 2, 1.0f}};
static const TechniqueEmitterSourceRow foie_emitter_rows_1[1] = {{0x14, 2, 1.2f}};
static const TechniqueEmitterSourceRow foie_emitter_rows_2[1] = {{0x14, 2, 1.4f}};
static const TechniqueEmitterSourceRow foie_emitter_rows_3[2] = {{0x14, 2, 1.6f}, {0xAC, 1, 1.0f}};
static const TechniqueEmitterSourceRow foie_emitter_rows_4[2] = {{0x14, 2, 1.8f}, {0xAC, 1, 1.0f}};
static const TechniqueEmitterSourceRow foie_emitter_rows_5[4] = {
    {0x19E, 0x1000, 1.0f}, {0x14, 2, 2.2f}, {0xAC, 1, 1.0f}, {0x19C, 2, 1.0f},
};
const TechniqueEmitterSourceTable TTecFoie::emitter_bands[6] = {
    {foie_emitter_rows_0, 1}, {foie_emitter_rows_1, 1}, {foie_emitter_rows_2, 1},
    {foie_emitter_rows_3, 2}, {foie_emitter_rows_4, 2}, {foie_emitter_rows_5, 4},
};
const char *TTecFoie::name = "TTecFoie";

void TTecFoie::create_particle_emitters() {
  Angle3 fwd;
  Angle3 rev;
  u32 i;
  s32 f;
  fwd.x = angles[0];
  fwd.y = 0;
  fwd.z = angles[2];
  spawn_directional_particle(&position, &fwd, 0x18);
  emitters = (void **) mem_alloc(TTecFoie::emitter_bands[band].count * 4);
  for (i = 0; i < TTecFoie::emitter_bands[band].count; i++)
  {
    const TechniqueEmitterSourceRow *b = &TTecFoie::emitter_bands[band].rows[i];
    f = (b->flags & 0x1000) ? (0x2000) : (0);
    if (TTecFoie::emitter_bands[band].rows[i].flags & 1)
    {
      rev.x = angles[0] + 0x8000;
      rev.y = 0;
      rev.z = angles[2];
      emitters[i] = spawn_particle_effect_with_rotation(&position, &rev, TTecFoie::emitter_bands[band].rows[i].entry, f);
    }
    else
      if (TTecFoie::emitter_bands[band].rows[i].flags & 2)
    {
      emitters[i] = spawn_particle_effect_with_rotation(&position, &fwd, TTecFoie::emitter_bands[band].rows[i].entry, f);
    }
    else
    {
      emitters[i] = spawn_continuous_particle_effect_with_flags(&position, b->entry, f);
    }
    if (emitters[i] != 0)
    {
      if (TTecFoie::emitter_bands[band].rows[i].flags & 0x20)
      {
        attach_particle_model(static_cast<TParticleCtrl *>(emitters[i]), TParticleCtrl::get_particle_model(0), technique_texture_list, 0, 1, 1.0f);
      }
      ((TParticleCtrl *)(emitters[i]))->set_scale(TTecFoie::emitter_bands[band].rows[i].scale, TTecFoie::emitter_bands[band].rows[i].scale);
    }
  }
}

void TTecFoie::init_projectile_params() {
    TechniqueParams *scaled = calc_technique_parameters(0, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[0].base + tech_high_level_linear_power_table[0].per_level * level);
    } else {
        params.power = params.power + (f32)(params.power_per_level * level);
        if (is_technique_ready() != 0) {
            params.power = params.power * technique_scale_table[0].power;
        }
    }
    speed = params.speed + (f32)clamp_nonnegative_int(level - 4);
    range = params.range;
}

void TTecFoie::spawn_miss_effect() {
    spawn_particle_effect(&position, 0x1DC);
    spawn_particle_effect(&position, 0x1DD);
}

void TTecFoie::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 1;
    hit.power = this->params.power;
    target->receive_direct_attack(source, hit, contact, 0, -1);
    play_sound_effect(0x4002A828, &target->position, 0, 0);
    queue_destruction();
}

void TTecFoie::create_ex(TObjBase *source, Vec *origin, Vec *aim, s32 level) {
    new TTecFoie(source, origin, aim, level);
}

void TTecFoie::create(TObjBase *source, Vec *origin, s32 angle, s32 level) {
    new TTecFoie(source, origin, angle, level);
}
TTecFoie::~TTecFoie() {
    for (u32 i = 0; i < TTecFoie::emitter_bands[band].count; ++i) {
        ((TObject *)emitters[i])->queue_destruction();
    }
    mem_free(emitters);
}

void TTecFoie::render() {  }

void TTecFoie::run_task() {
    u32 i;
    this->source = find_entity_by_id(sourceId);
    if (this->source == NULL) {
        queue_destruction();
        return;
    }
    for (i = 0; i < TTecFoie::emitter_bands[band].count; i++) {
        if (emitters[i] != 0) {
            ((TParticleCtrl *)emitters[i])->set_position(&position);
        }
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_technique_contact(1);
}

// The aimed form (create_ex): flies from `pos` towards `target`.
TTecFoie::TTecFoie(TObjBase *source, Vec *pos, Vec *target, s32 level)
    : TTecShot(source, pos, target, level) {
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
    init_projectile_params();
    create_particle_emitters();
    play_foie_cast_sound();
}

// The facing form (create): flies along the y angle `angle`.
TTecFoie::TTecFoie(TObjBase *source, Vec *pos, s32 angle, s32 level)
    : TTecShot(source, pos, angle, level) {
    m_name = TTecFoie::name;
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
    init_projectile_params();
    create_particle_emitters();
    play_foie_cast_sound();
}
