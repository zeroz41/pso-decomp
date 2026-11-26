#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TechniqueBandSound.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/system/BmlResource.h"
#include "pso/technique/TTecBarta.h"
#include "pso/technique/TTecCircle.h"
#include "pso/technique/TTecShot.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"

#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"


const TechniqueEmitterSourceRow barta_band0_emitters[3] = {
    {0x190, 2, 1.0f}, {0x191, 0, 1.0f}, {0x192, 0, 1.0f},
};
const TechniqueEmitterSourceRow barta_band1_emitters[3] = {
    {0x190, 2, 1.2f}, {0x191, 2, 1.2f}, {0x192, 0, 1.0f},
};
const TechniqueEmitterSourceRow barta_band2_emitters[3] = {
    {0x190, 2, 1.4f}, {0x191, 2, 1.4f}, {0x192, 0, 1.0f},
};
const TechniqueEmitterSourceRow barta_band3_emitters[4] = {
    {0x190, 2, 1.0f}, {0x191, 2, 1.0f}, {0x192, 0, 1.0f}, {0x198, 1, 1.0f},
};
const TechniqueEmitterSourceRow barta_band4_emitters[4] = {
    {0x190, 2, 1.2f}, {0x191, 2, 1.2f}, {0x192, 0, 1.0f}, {0x198, 1, 1.0f},
};
const TechniqueEmitterSourceRow barta_band5_emitters[7] = {
    {0x190, 2, 1.6f}, {0x191, 2, 1.6f}, {0x192, 0, 1.0f}, {0x198, 1, 1.0f},
    {0x193, 0x20, 1.0f}, {0x1D8, 0x20, 1.0f}, {0x1D7, 0x20, 1.0f},
};
static const TechniqueEmitterSourceTable barta_emitter_bands[6] = {
    {barta_band0_emitters, 3}, {barta_band1_emitters, 3}, {barta_band2_emitters, 3},
    {barta_band3_emitters, 4}, {barta_band4_emitters, 4}, {barta_band5_emitters, 7},
};
const char *TTecBarta::class_name = "TTecBarta";

#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
void TTecBarta::update_technique_by_state() {
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A604, &position, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A604, &position, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
#pragma pop


void TTecBarta::create_particle_emitters() {
    s32 angles[3];
    s32 reverse[3];
    u32 i;
    const TechniqueEmitterSourceRow *row;
    u32 flags;
    angles[0] = this->angles[0];
    angles[1] = 0;
    angles[2] = this->angles[2];
    this->emitters = (TechniqueParticleEmitter **)mem_alloc(barta_emitter_bands[this->band].count * 4);
    for (i = 0; i < barta_emitter_bands[this->band].count; i++) {
        row = &barta_emitter_bands[this->band].rows[i];
        flags = row->flags;
        if (flags & 2) {
            this->emitters[i] = (TechniqueParticleEmitter *)spawn_continuous_particle_with_direction(&position, angles, row->entry);
        } else if (flags & 1) {
            reverse[0] = this->angles[0] + 0x8000;
            reverse[1] = 0;
            reverse[2] = this->angles[2];
            this->emitters[i] = (TechniqueParticleEmitter *)spawn_continuous_particle_with_direction(&position, reverse, barta_emitter_bands[this->band].rows[i].entry);
        } else {
            this->emitters[i] = (TechniqueParticleEmitter *)create_particle_emitter(&position, row->entry);
        }
        if (this->emitters[i] != NULL) {
            row = &barta_emitter_bands[this->band].rows[i];
            if (row->flags & 0x20) {
                attach_particle_model(reinterpret_cast<TParticleCtrl *>(this->emitters[i]), get_bml_model(technique_effect_bml, 0), technique_texture_list, get_bml_motion(technique_effect_bml, 0), 0, 1.0f);
            } else {
                ((TParticleCtrl *)(this->emitters[i]))->set_scale(row->scale, row->scale);
            }
        }
    }
}

void TTecBarta::init_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(3, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[3].base + tech_high_level_linear_power_table[3].per_level * level);
    } else {
        params.power = params.power + (f32)(params.power_per_level * level);
        if (TTecCtrl::is_technique_ready() != 0) {
            params.power = params.power * technique_scale_table[3].power;
        }
    }
    speed = params.speed + (f32)((level / 5) * 2);
    range = params.range;
}

void TTecBarta::create(void *source, void *origin, void *aim, s32 level) {
    new TTecBarta((saddr)source, (u8 *)origin, (u8 *)aim, level);
}

void TTecBarta::create_ex(void *source, void *origin, s32 angle, s32 level) {
    new TTecBarta((saddr)source, (Vec *)origin, angle, level);
}

void TTecBarta::apply_to_target(TObjChara *target) {
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
        hit.kind = 19;
        hit.power = params.power;
        target->receive_direct_attack((TObjBase *)source, hit, contact, 3, -1);
    }
}

TTecBarta::~TTecBarta() {
    for (u32 i = 0; i < barta_emitter_bands[band].count; ++i) {
        if (emitters[i]) {
            ((TObject *)emitters[i])->queue_destruction();
            emitters[i] = 0;
        }
    }
    mem_free(emitters);
}

void TTecBarta::run_task() {
    s32 i;
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if (this->source == NULL) {
        queue_destruction();
        return;
    }
    for (i = 0; i < barta_emitter_bands[this->band].count; i++) {
        Vec pos = this->position;
        if (barta_emitter_bands[this->band].rows[i].flags & 0x20) {
            pos.y -= 10.0f;
        }
        if (this->emitters[i] != NULL) {
            ((TParticleCtrl *)this->emitters[i])->set_position(&pos);
        }
        if (this->band == 5 && i == 5 && this->emitters[i] != NULL) {
            ((TParticleCtrl *)this->emitters[i])->set_position(&pos);
        }
    }
    if (this->band == 5) {
        TechniqueParticleEmitter *e = (TechniqueParticleEmitter *)create_timed_particle_emitter(&this->position.x, 0x18A, 0x14, 1);
        if (e != NULL) {
            attach_particle_model(reinterpret_cast<TParticleCtrl *>(e), get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
        }
    }
    move_ground_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

void TTecBarta::render() {  }

TTecBarta::TTecBarta(saddr source, u8 *pos, u8 *target, s32 level)
    : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecBarta::class_name;
    init_parameters();
    collisionBody.flags = 0x40003;
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    create_particle_emitters();
    update_technique_by_state();
    if (this->source) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

// The facing form starts 5 units higher.
TTecBarta::TTecBarta(saddr source, Vec *pos, s32 angle, s32 level)
    : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecBarta::class_name;
    init_parameters();
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    collisionBody.flags = 0x40003;
    position.y += 5.0f;
    create_particle_emitters();
    update_technique_by_state();
    if (this->source) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

void TTecShot::vfunc_6() {  }
struct TechniqueParticleEmitter;
void TTecCircle::apply_technique_to_area_targets() {
    TechniqueContactList *list;
    s32 i;
    TObjChara *target;
    if (collidable == 0) {
        queue_destruction();
        return;
    }
    if (((TObjBase *)source)->get_entity_id() < 4) {
        if (((TObjPlayer *)source)->pk_state.is_enabled() != 0) {
            list = collect_body_contacts_for_target(source);
        } else {
            list = find_area_contact(source);
        }
    } else {
        list = collect_body_contacts_for_target(source);
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active((uaddr)list->actors[i]) != 0) {
            target = (TObjChara *)list->actors[i];
            contact = list->bodies[i];
            apply_to_target(target);
        }
    }
}
