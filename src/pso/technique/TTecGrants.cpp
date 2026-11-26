#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/TEffClitical.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/TEffect.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/technique/TTecGrantsFlash.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecGrantsEffect.h"
#include "pso/technique/TTimedSoundEffect.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecGrants.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"
#include "pso/technique/TechniqueRingwaveList.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecCircle.h"
#include <stddef.h>
#include "pso/technique/TTecLuker.h"
#include "pso/player/TargetCursorList.h"

// ---- pso/unk/text_80232934

struct Quad_80232934 { u32 a; u32 b; u32 c; u32 d; };


extern "C" {

void draw_ginja_object(void);

// ---- pso/unk/text_80232AA4

}

// One-texture list that render() fills with a copy of the ring-wave frame and draws with; same shape as
// TEffClitical's clitical_texture_list (the 8-byte list is placed in .data, its name in .bss).
NJS_TEXNAME grants_ring_texname[1];
NJS_TEXLIST grants_ring_texlist = { grants_ring_texname, 1 };

// ---- pso/unk/text_80232B24

// ---- pso/unk/text_80232B7C

struct GrantsEmitterPart { s32 id; u32 flags; u8 pad_08[4]; };

struct GrantsEmitterSet { const GrantsEmitterPart *parts; u32 count; };

struct GrantsEffectEntry { s32 effect; u32 flags; s32 pad_08; };

struct GrantsEffectSet { const GrantsEffectEntry *ents; u32 count; };

// Per level tier (TObjPlayer::get_level_tier): the particle emitters TTecGrantsEffect keeps alive and
// the effects it spawns when it ends.
// inferred names: grants_emitter_parts_<tier> and grants_effect_entries_<tier> are the rows of
// grants_effect_emitter_table and technique_effect_entry_table for each tier.
static const GrantsEmitterPart grants_emitter_parts_0[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const GrantsEffectEntry grants_effect_entries_0[3] = { { 0x1D3, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1CB, 0, 0 } };
static const GrantsEmitterPart grants_emitter_parts_1[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const GrantsEffectEntry grants_effect_entries_1[3] = { { 0x1D3, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1D5, 0, 0 } };
static const GrantsEmitterPart grants_emitter_parts_2[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const GrantsEffectEntry grants_effect_entries_2[3] = { { 0x1D3, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1CC, 0, 0 } };
static const GrantsEmitterPart grants_emitter_parts_3[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const GrantsEffectEntry grants_effect_entries_3[3] = { { 0x1C0, 0, 0 }, { 0x1D4, 0, 0 }, { 0x10F, 0, 0 } };
static const GrantsEmitterPart grants_emitter_parts_4[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const GrantsEffectEntry grants_effect_entries_4[3] = { { 0x1C0, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1A4, 0, 0 } };
static const GrantsEmitterPart grants_emitter_parts_5[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const GrantsEffectEntry grants_effect_entries_5[4] = { { 0x1C2, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1C9, 0, 0 }, { 0x1DA, 0, 0 } };

const GrantsEmitterSet grants_effect_emitter_table[6] = {
    { grants_emitter_parts_0, 3 }, { grants_emitter_parts_1, 3 }, { grants_emitter_parts_2, 3 },
    { grants_emitter_parts_3, 3 }, { grants_emitter_parts_4, 3 }, { grants_emitter_parts_5, 3 },
};

const GrantsEffectSet technique_effect_entry_table[6] = {
    { grants_effect_entries_0, 3 }, { grants_effect_entries_1, 3 }, { grants_effect_entries_2, 3 },
    { grants_effect_entries_3, 3 }, { grants_effect_entries_4, 3 }, { grants_effect_entries_5, 4 },
};

const char *tec_grants_class_name = "TTecGrants";

// Function definitions in reverse address order (defer_codegen emits them reversed).
#pragma defer_codegen on

TTecGrants::TTecGrants(saddr owner, saddr origin, saddr target_list, saddr level) : TTecCircle(owner, origin, level) {
    m_name = tec_grants_class_name;
    init_parameters();
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    frames = 0;
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
}

TTecGrants::~TTecGrants() {

}

void TTecGrants::run_task() {
    uaddr entity;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (targets.count == 0) {
        queue_destruction();
        return;
    }
    entity = (uaddr)find_entity_by_id(targets.records[0].id);
    if ((TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0) && (frames == 0)) {
        new TTecGrantsEffect((u8 *)entity, level, tl_07);
    }
    frames = frames + 1;
    if (frames > 0x1E) {
        if ((entity != 0) && (TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
            apply_to_target((TObjChara *)entity);
        }
        queue_destruction();
    }
}

void TTecGrants::create(void *source, void *origin, void *targets, s32 level) {
    new TTecGrants((saddr)source, (saddr)origin, (saddr)targets, level);
}

void TTecGrants::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 0x4;
    hit.power = this->params.power;
    target->receive_direct_attack((void *)this->source, hit, this->contact, 0x9, -1);
}

void TTecGrants::render() {  }

TTecGrantsEffect::TTecGrantsEffect(u8 *src, s32 level, TObject *parent) : TObject(parent) {
    u32 i;
    VecCopy(&position, (const Vec *)(src + 0x38));
    timer = 0;
    owner_id = ((TObjBase *)(src))->get_entity_id();
    this->level = level;
    if (this->level < 0) {
        this->level = 0;
    } else if (level >= 0x1E) {
        this->level = 0x1E;
    }
    tier = TObjPlayer::get_level_tier(this->level);
    emitters = (TParticleCtrl **)mem_alloc(grants_effect_emitter_table[tier].count * sizeof(TParticleCtrl *));
    for (i = 0; i < grants_effect_emitter_table[tier].count; i++) {
        emitters[i] = spawn_continuous_particle_effect_with_flags(&position, grants_effect_emitter_table[tier].parts[i].id, 0x10);
        if (emitters[i] != NULL) {
            emitters[i]->set_owner_id(owner_id);
        }
    }
    switch (tier) {
    case 0:
        sound = play_sound_effect(0x4002A90C, &position, 0, 0);
        if (sound >= 0) {
            set_sound_pitch_request(sound, 0x100, 0);
        }
        break;
    case 1:
        sound = play_sound_effect(0x4002A90C, &position, 0, 0);
        break;
    case 2:
    case 3:
        sound = play_sound_effect(0x4002A90C, &position, 0, 0);
        if (sound >= 0) {
            set_sound_pitch_request(sound, -0x180, 0);
        }
        break;
    case 4:
        sound = play_sound_effect(0x4002A90C, &position, 0, 0);
        if (sound >= 0) {
            set_sound_pitch_request(sound, -0x250, 0);
        }
        break;
    case 5:
        sound = play_sound_effect(0x4002A90C, &position, 0, 0);
        if (sound >= 0) {
            set_sound_pitch_request(sound, -0x100, 0);
        }
        break;
    }
}







TTecGrantsEffect::~TTecGrantsEffect() {
    u32 i;
    for (i = 0; i < grants_effect_emitter_table[tier].count; i++) {
        if (emitters[i] != NULL) {
            emitters[i]->queue_destruction();
        }
    }
    stop_sound_request(sound);
    mem_free(emitters);
}

void TTecGrantsEffect::run_task() {
    u32 i;
    s32 dir;
    TObjCollidable *obj;
    TParticleCtrl *r;
    timer++;
    if (timer % 5 == 0) {
        new TTecGrantsFlash(owner_id, tl_07, NULL, 1.0f);
    }
    if (timer >= 30) {
        for (i = 0; i < technique_effect_entry_table[tier].count; i++) {
            obj = find_entity_by_id(owner_id);
            if (obj != NULL) {
                const GrantsEffectEntry *e = &technique_effect_entry_table[tier].ents[i];
                if (e->flags & 0x20) {
                    r = spawn_particle_effect(&obj->position, e->effect);
                    if (r != NULL) {
                        attach_particle_model(r, get_bml_model(technique_effect_bml, technique_effect_entry_table[tier].ents[i].flags >> 16), technique_texture_list, NULL, 1, 1.0f);
                    }
                } else {
                    spawn_particle_effect(&obj->position, e->effect);
                }
            }
        }
        switch (tier) {
        case 0:
        case 1:
            dir = 0x100;
            break;
        case 2:
        case 3:
            dir = 0;
            break;
        case 4:
        case 5:
            dir = -0x100;
            break;
        }
        new TTimedSoundEffect(&position, 0xF, 0x4002A60D, dir, tl_07);
        queue_destruction();
    }
}

TTecGrantsFlash::TTecGrantsFlash(s32 owner_id, TObject *parent, Vec *pos, f32 start_scale) : TObject(parent) {
    this->owner_id = owner_id;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    scale.x = 0.05f;
    scale.y = 0.05f;
    scale.z = 0.05f;
    scale_rate = 0.05f;
    if ((u16)owner_id == 0xffff && pos != NULL) {
        VecCopy(&position, pos);
        scale.x = start_scale;
        scale.y = start_scale;
        scale.z = start_scale;
        scale_rate = 2.0f;
    }
    color.a = 1.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    frame = 0;
}

TTecGrantsFlash::~TTecGrantsFlash() {

}

void TTecGrantsFlash::run_task() {
    TObjCollidable *entity;
    entity = find_entity_by_id(owner_id);
    if (entity != NULL) {
        VecCopy(&position, &entity->position);
    }
    frame = frame + 1;
    if (frame >= 7) {
        frame = 0;
    }
    if (color.a <= 0.0f) {
        queue_destruction();
    }
}

void TTecGrantsFlash::render() {
    TextureFrameSlot ctx;
    s32 id;
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_LOBBY) {
        return;
    }
    init_texture_copy_rect(&ctx, &grants_ring_texlist, &technique_ringwave_texture_list, 0, frame + 1);
    Vec v = { 1.2f, 1.2f, 1.2f };
    Quad_80232934 q = { 0, 0, 0, 0 };
    approach_alpha_clamped(&color.a, (const f32 *)&q, 0.1f);
    approach_position_if_far(&scale, &v, scale_rate);
    copy_anim_frame_to_slot(&ctx);
    id = model_render_flags;
    saved_model_render_flags = id;
    model_render_flags = id | 0x10;
    ((void (*)(NJS_ARGB *, s32))set_constant_material)(&color, id);
    set_draw_list_mask(3);
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&position.x);
    scale_matrix(0, scale.x, scale.y, scale.z);
    translate_matrix(0, 0.0f, 1e+01f, 0.0f);
    set_texture_list(&grants_ring_texlist);
    get_bml_model(technique_effect_bml, 10);
    draw_ginja_object();
    pop_matrix();
    copy_slot_to_anim_frame(&ctx);
    restore_draw_list_mask();
    model_render_flags = saved_model_render_flags;
}


void TTecGrants::init_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(9, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[9].base + tech_high_level_linear_power_table[9].per_level * level);
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (TTecCtrl::is_technique_ready()) {
        params.power = params.power * technique_scale_table[9].power;
    }
}

#pragma defer_codegen off
