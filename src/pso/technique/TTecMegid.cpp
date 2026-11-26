#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/system/memory.h"
#include "pso/technique/TechniqueBandSound.h"
#include "pso/system/BmlAccessors.h"
#include "pso/unk/text_803D96A8.h"
// ---- pso/technique/TTecMegid
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TTecMegid.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/technique/TTecBarta.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/TObjBase.h"


// The per-band emitter lists of megid_emitter_bands, named after their band (technique level tier)
static const TechniqueEmitterSourceRow megid_band0_emitters[2] = {
    {0x1C5, 0, 0.0f}, {0x1C8, 0, 0.0f},
};
static const TechniqueEmitterSourceRow megid_band1_emitters[2] = {
    {0x1C5, 0x40, 1.4f}, {0x1C8, 0x40, 1.4f},
};
static const TechniqueEmitterSourceRow megid_band2_emitters[2] = {
    {0x1C5, 0x40, 1.8f}, {0x1C8, 0x40, 1.8f},
};
static const TechniqueEmitterSourceRow megid_band3_emitters[3] = {
    {0x1C4, 2, 1.0f}, {0x1C5, 0x40, 2.2f}, {0x1C8, 0x40, 2.2f},
};
static const TechniqueEmitterSourceRow megid_band4_emitters[3] = {
    {0x1C4, 2, 1.0f}, {0x1C5, 0x40, 2.6f}, {0x1C8, 0x40, 2.6f},
};
static const TechniqueEmitterSourceRow megid_band5_emitters[5] = {
    {0x1C4, 2, 1.0f}, {0x1C5, 0x40, 3.0f}, {0x1C8, 0x40, 3.0f}, {0x1C7, 0, 1.0f}, {0x1CF, 0x1002, 1.0f},
};
static const TechniqueEmitterSourceTable megid_emitter_bands[6] = {
    {megid_band0_emitters, 2}, {megid_band1_emitters, 2}, {megid_band2_emitters, 2},
    {megid_band3_emitters, 3}, {megid_band4_emitters, 3}, {megid_band5_emitters, 5},
};
// The class name string, as TTecBarta::class_name
const char *TTecMegid::class_name = "TTecMegid";
static const Vec tec_megid_offset_vec = {0.0f, 0.0f, -5.0f};


#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TTecMegid::update_by_state() {
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A60B, &position, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A60B, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
#pragma pop


void TTecMegid::spawn_particle_emitters() {
  u32 flags;
  const TechniqueEmitterSourceRow *row;
  u32 i;
  long long model_index;
  s32 mode;
  ParticleAngles dir;
  dir.x = angles[0];
  dir.y = 0;
  dir.z = angles[2];
  emitters = static_cast<void **>(mem_alloc(megid_emitter_bands[band].count * sizeof(*emitters)));
  for (i = 0; i < megid_emitter_bands[this->band].count; i++)
  {
    mode = 0;
    row = &megid_emitter_bands[this->band].rows[i];
    flags = row->flags;
    if (flags & 0x1000)
    {
      mode = 0x2000;
    }
    if (flags & 2)
    {
      emitters[i] = spawn_particle_effect_with_rotation(&position, &dir, row->entry, mode | 0x1000);
    }
    else
    {
      emitters[i] = spawn_continuous_particle_effect_with_flags(&position, row->entry, mode | 0x1000);
    }
    if (emitters[i] != 0)
    {
      row = &megid_emitter_bands[this->band].rows[i];
      if (row->flags & 0x40)
      {
        ((TParticleCtrl *)(emitters[i]))->set_scale(row->scale, row->scale);
      }
      if (megid_emitter_bands[this->band].rows[i].flags & 0x20)
      {
        model_index = megid_emitter_bands[this->band].rows[i].flags >> 16;
        attach_particle_model(static_cast<TParticleCtrl *>(emitters[i]), get_bml_model(technique_effect_bml, model_index), technique_texture_list, 0, 1, 1.0f);
      }
    }
  }
}

void TTecMegid::init_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(18, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[18].base + tech_high_level_linear_power_table[18].per_level * level);
    } else {
        params.power = params.power + (f32)(params.power_per_level * level);
        if (TTecCtrl::is_technique_ready() != 0) {
            params.power = params.power * technique_scale_table[18].power;
        }
    }
    speed = params.speed + (f32)((level / 5) * 2);
    range = params.range;
}

void TTecMegid::apply_to_target(TObjChara *target) {
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
        hit.kind = 5;
        hit.power = params.power;
        if (target->get_entity_id() < 4 && target->obj_isState3_324() != 0) {
            return;
        }
        target->receive_direct_attack((void *)source, hit, contact, 0x12, -1);
        play_sound_effect(0x4002AD29, &target->position, 0, 0);
        if (sourceId < 12) {
            if ((get_technique_caster_flags(0x12, sourceId) & 1) == 0) {
                queue_destruction();
            }
        }
    }
}

void TTecMegid::create(saddr source, saddr pos, saddr target, s32 level) {
    new TTecMegid(source, (u8 *)pos, (u8 *)target, level);
}
void TTecMegid::create_ex(saddr source, saddr pos, s32 angle, s32 level) {
    new TTecMegid(source, (Vec *)pos, angle, level);
}
void TTecMegid::render() {  }

TTecMegid::~TTecMegid() {
    for (u32 i = 0; i < megid_emitter_bands[band].count; ++i) {
        if (emitters[i]) {
            ((TObject *)emitters[i])->queue_destruction();
        }
    }
    mem_free(emitters);
}

void TTecMegid::run_task() {
    u32 i;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    for (i = 0; i < megid_emitter_bands[band].count; i++) {
        if (megid_emitter_bands[band].rows[i].flags & 4) {
            Vec off = tec_megid_offset_vec;
            Vec p;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, angles[1]);
            matrix_mult_vec(0, &off, &off);
            pop_matrices(1);
            p.x = position.x + off.x;
            p.y = position.y + off.y;
            p.z = position.z + off.z;
            ((TParticleCtrl *)emitters[i])->set_position(&p);
        } else {
            ((TParticleCtrl *)emitters[i])->set_position(&position);
        }
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_technique_contact(1);
}

// The aimed form: the technique flies from `pos` towards `target`.
TTecMegid::TTecMegid(saddr source, u8 *pos, u8 *target, s32 level) : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecMegid::class_name;
    init_parameters();
    pad_178 = 0.0f;
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    spawn_particle_emitters();
    update_by_state();
    if (TEffect::source != 0) {
        sourceId = ((TObjBase *)TEffect::source)->get_entity_id();
    }
}

// The facing form: the technique starts at `pos` and flies along the y angle `angle`.
TTecMegid::TTecMegid(saddr source, Vec *pos, s32 angle, s32 level) : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecMegid::class_name;
    init_parameters();
    pad_178 = 0.0f;
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    spawn_particle_emitters();
    update_by_state();
    if (TEffect::source != 0) {
        sourceId = ((TObjBase *)TEffect::source)->get_entity_id();
    }
}
