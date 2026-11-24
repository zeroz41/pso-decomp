#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TechniqueParams.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecShot.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"


struct Row_802304A0 { u32 entry; u32 flags; f32 scale; };
struct Band_802304A0 { const Row_802304A0 *rows; u32 count; };
struct Angles_802304A0 { s32 a[3]; };
struct Shot_802304A0 {
    u8 pad0[0x20];
    Vec pos;
    u8 pad2C[0x54 - 0x2C];
    s32 f54;
    s32 angle;
    s32 f5C;
    u8 pad60[0xC6 - 0x60];
    s16 band;
    u16 source;
    u8 padCA[0x130 - 0xCA];
    void **emitters;
};

extern "C" {


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

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
}
struct Raw_802304A0 { u8 b[12]; };

const Row_802304A0 lbl_8044D180[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.0f},
    {0x182, 0x20022, 0.0f},
};
const Row_802304A0 lbl_8044D1A4[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.2f},
    {0x183, 0x20062, 1.4f},
};
const Row_802304A0 lbl_8044D1C8[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.4f},
    {0x184, 0x20062, 1.4f},
};
const Row_802304A0 lbl_8044D1EC[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.6f},
    {0x185, 0x30062, 1.6f},
};
const Row_802304A0 lbl_8044D210[3] = {
    {0x180, 0x4, 0.0f},
    {0x181, 0x42, 1.8f},
    {0x186, 0x30062, 1.8f},
};
const Row_802304A0 lbl_8044D234[2] = {
    {0x181, 0x42, 2.2f},
    {0x18E, 0x30062, 2.2f},
};
const Band_802304A0 TTecGiBarta__emitter_profile_table[6] = {
    {lbl_8044D180, 3}, {lbl_8044D1A4, 3}, {lbl_8044D1C8, 3},
    {lbl_8044D1EC, 3}, {lbl_8044D210, 3}, {lbl_8044D234, 2},
};
const char *TTecGiBarta__class_name = "TTecGiBarta";
const Vec lbl_8044D288 = {0.0f, 0.0f, 3.0f};


void TTecGiBarta::create_particles() {
    Shot_802304A0 *shot = (Shot_802304A0 *)this;
    Angles_802304A0 angles;
    Vec pos;
    Vec off;
    Vec p2;
    Vec v;
    u32 i;
    void *emitter;
    u8 *src;
    u32 flags;

    angles.a[0] = shot->f54;
    angles.a[1] = 0;
    angles.a[2] = shot->f5C;
    shot->emitters = (void **)mem_alloc(TTecGiBarta__emitter_profile_table[shot->band].count * 4);
    for (i = 0; i < TTecGiBarta__emitter_profile_table[shot->band].count; i++) {
        *(Raw_802304A0 *)&pos = *(Raw_802304A0 *)&shot->pos;
        if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x800) {
            pos.y -= 5.0f;
        }
        if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 2) {
            emitter = spawn_continuous_particle_with_direction(&pos, &angles, TTecGiBarta__emitter_profile_table[shot->band].rows[i].entry);
        } else {
            *(Raw_802304A0 *)&off = *(Raw_802304A0 *)&lbl_8044D288;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, shot->angle);
            matrix_mult_vec(0, &off, &off);
            pop_matrices(1);
            p2.x = shot->pos.x + off.x;
            p2.y = shot->pos.y + off.y;
            p2.z = shot->pos.z + off.z;
            if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x800) {
                p2.y -= 5.0f;
            }
            emitter = create_particle_emitter(&p2, TTecGiBarta__emitter_profile_table[shot->band].rows[i].entry);
        }
        if (emitter != NULL) {
            if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x40) {
                ((TParticleCtrl *)emitter)->set_scale(TTecGiBarta__emitter_profile_table[shot->band].rows[i].scale, TTecGiBarta__emitter_profile_table[shot->band].rows[i].scale);
            }
            if (TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags & 0x20) {
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, (u16)(TTecGiBarta__emitter_profile_table[shot->band].rows[i].flags >> 16)), technique_texture_list, 0, 0, 1.0f);
            }
        }
        shot->emitters[i] = emitter;
    }
    if (shot->band == 5) {
        VecCopy((Vec *)&v, (const Vec *)&shot->pos);
        v.y -= 15.0f;
        spawn_particle_effect(&v, 0x1E0);
        spawn_particle_effect(&v, 0x1E1);
        src = (u8 *)find_entity_by_id(shot->source);
        if (src != NULL) {
            emitter = spawn_particle_effect((const Vec *)(src + 0x38), 0x18B);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, 6), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(src + 0x38, 0x18B, 5, 1);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, 7), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(src + 0x38, 0x18B, 10, 1);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, 8), technique_texture_list, get_bml_motion(technique_effect_bml, 2), 0, 1.0f);
            }
            emitter = create_timed_particle_emitter(src + 0x38, 0x18F, 20, 1);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
            }
        }
    }
}
#pragma auto_inline off

void TTecGiBarta::calc_params() {
    TechniqueParams *scaled = calc_technique_parameters(4, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[4].base + tech_high_level_linear_power_table[4].per_level * level);
    } else {
        params.power = params.power + (f32)(params.power_per_level * level);
        if (TTecCtrl::is_technique_ready() != 0) {
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
        target->receive_direct_attack((void *)source, hit, contact, 4, -1);
    }
}

void TTecGiBarta::create(void *source, void *origin, void *aim, s32 level) {
    new TTecGiBarta((saddr)source, (u8 *)origin, (u8 *)aim, level);
}

void TTecGiBarta::create_ex(void *source, void *origin, s32 angle, s32 level) {
    new TTecGiBarta((saddr)source, (Vec *)origin, angle, level);
}

TTecGiBarta::~TTecGiBarta() {
    for (u32 i = 0; i < TTecGiBarta__emitter_profile_table[band].count; ++i) {
        if (emitters[i]) {
            ((TObject *)emitters[i])->queue_destruction();
        }
    }
    mem_free(emitters);
}

void TTecGiBarta::run_task() {
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if ((u32) this->source == 0U) {
        queue_destruction();
        return;
    }
    move_technique_projectile();
    advance_lifetime_or_destroy();
    dispatch_all_technique_contacts();
}

TTecGiBarta::TTecGiBarta(saddr source, u8 *pos, u8 *target, s32 level)
    : TTecShot(source, pos, target, level) {
    s32 i;
    m_name = TTecGiBarta__class_name;
    calc_params();
    halfWidth = 12.0f;
    for (i = 0; i < 32; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    if (this->source) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    create_particles();
    update_technique_by_phase();
}

TTecGiBarta::TTecGiBarta(saddr source, Vec *pos, s32 angle, s32 level)
    : TTecShot(source, pos, angle, level) {
    s32 i;
    m_name = TTecGiBarta__class_name;
    calc_params();
    for (i = 0; i < 0x20; i++) {
        hitIds[i] = 0xFFFF;
    }
    hitCursor = 0;
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    create_particles();
    update_technique_by_phase();
}

void TTecGiBarta::render() {  }
