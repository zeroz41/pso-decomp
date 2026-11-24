#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/system/BmlAccessors.h"
#include "pso/unk/text_803D96A8.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TTecCircle.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/player/TargetCursorList.h"
#include "pso/unk/TUnk_804CCB28.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/render_util.h"
#include "pso/effect/TEffClitical.h"
#include "pso/effect/TEffIndirectCtrl.h"

#include "pso/system/vector.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/technique/TTecLuker.h"
#include "pso/system/SoundEffect.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/base/TObjBase.h"
#pragma readonly_strings on

struct RafoieBurst { s32 entry; s32 flags; f32 scale; };

struct RafoieBurstList { const RafoieBurst *entries; u32 count; };


extern "C" {

s32 is_split_screen();


extern "C" {
extern const RafoieBurst lbl_8044DA48[1] = {{494, 0, 1.0f}};
extern const RafoieBurst lbl_8044DA54[2] = {{491, 0, 1.0f}, {494, 0, 1.0f}};
extern const RafoieBurst lbl_8044DA6C[2] = {{393, 0, 1.0f}, {494, 0, 1.0f}};
extern const RafoieBurst lbl_8044DA84[4] = {{396, 0, 1.0f}, {494, 0, 1.0f}, {482, 0x1000, 1.0f}, {486, 0x10, 1.0f}};
extern const RafoieBurstList rafoie_burst_table[6] = {
    {lbl_8044DA48, 1}, {lbl_8044DA48, 1}, {lbl_8044DA48, 1},
    {lbl_8044DA54, 2}, {lbl_8044DA6C, 2}, {lbl_8044DA84, 4},
};
const char *TTecRaFoie_class_name = "TTecRaFoie";
// The colour the burst fades to (all clear).
extern const NJS_ARGB lbl_8044DAF0 = {0.0f, 0.0f, 0.0f, 0.0f};
}

void TUnk_804CCB28::spawn_rafoie_explosion_bursts() {
    Vec higher;
    u32 i;
    VecCopy(&higher, &position);
    higher.y = (8.0f) + position.y;
    for (i = 0; i < rafoie_burst_table[band].count; i++) {
        const RafoieBurst *row = &rafoie_burst_table[band].entries[i];
        u16 mode = 0;
        void *p;
        if (row->flags & 0x1000) {
            mode = 0x2000;
        }
        if (row->flags & 0x10) {
            p = spawn_particle_effect_with_flags(&position, row->entry, mode);
        } else {
            p = spawn_particle_effect_with_flags(&higher, row->entry, mode);
        }
        if (p != NULL) {
            ((TParticleCtrl *)p)->set_scale(rafoie_burst_table[band].entries[i].scale, rafoie_burst_table[band].entries[i].scale);
        }
    }
}

void TTecRaFoie::vfunc_9() {
    s32 handle;

    switch (band) {
    case 0:
        handle = play_sound_effect(0x4002A602, &target, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A602, &target, 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A602, &target, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A602, &target, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A602, &target, 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
void TTecRaFoie::vfunc_8(void *) {
    TParticleCtrl *emitter;
    TObjChara *chara;
    if (m_148 == 1) {
        if (is_split_screen() != 0) {
            spawn_particle_effect(&target, 0x39);
        } else {
            emitter = spawn_particle_effect(&target, 0x1A);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 9), technique_texture_list, 0, 1, 1.0f);
            }
        }
        spawn_particle_effect(&target, 0x3A);
        spawn_particle_effect(&target, 0x3B);
        return;
    }
    if (m_targets.count != 0) {
        chara = (TObjChara *)find_entity_by_id(m_targets.records[0].id);
        if (TTecLuker::is_parents_unqueued((uaddr)chara) != 0 && TObjPlayer::is_valid_and_active((uaddr)chara) != 0) {
            Vec point = chara->body_center;
            spawn_particle_effect(&point, 0x39);
            emitter = spawn_particle_effect(&point, 0x1A);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 9), technique_texture_list, 0, 1, 1.0f);
            }
        }
    }
}

}

#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecAnti.h"

#include "pso/technique/TechniqueParams.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/task/TMainTask.h"


extern "C" {
void post_translate_matrix(void *);
void draw_ginja_object(void);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
#pragma push
#pragma opt_common_subs off

void TTecRaFoie::calc_area_parameters() {
    TechniqueParams *params = calc_technique_parameters(2, level, 0xFFFF);
    ((TechniqueParams *)&power)->copy(params);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        power = (f32)(tech_high_level_linear_power_table[2].base + tech_high_level_linear_power_table[2].per_level * level);
        return;
    }
    power = power + (f32)(((TechniqueParams *)&power)->pad_24 * level);
    if (TTecCtrl::is_technique_ready()) {
        power = power * technique_scale_table[2].power;
    }
}

void TUnk_804CCB28::render() {
    f32 x;
    f32 y;
    f32 z;
    s32 id;
    u16 lv;
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_LOBBY) {
        return;
    }
    TParticleCtrl::begin_effect_render();
    id = model_render_flags;
    saved_model_render_flags = id;
    model_render_flags = id | 0x200010;
    ((void (*)(void *, s32))set_constant_material)(&color, id);
    if (indirect_effect != 0) {
        enable_indirect_tev(indirect_effect, 2, 0, 0);
    }
    lv = level;
    x = scale.x;
    y = scale.y;
    z = scale.z;
    if (lv >= 0xF && lv < 0x19) {
        x = (1.3f) * x;
        y = (1.3f) * y;
        z = (1.3f) * z;
    } else if (lv >= 0x19 && lv < 0x1E) {
        x = (1.8f) * x;
        y = (1.8f) * y;
        z = (1.8f) * z;
    }
    push_matrix();
    post_translate_matrix(&position);
    scale_matrix(0, x, y, z);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(technique_texture_list));
    set_cull_back();
    set_draw_list_mask(3);
    get_bml_model(technique_effect_bml, 0xB);
    draw_ginja_object();
    restore_draw_list_mask();
    set_cull_none();
    pop_matrix();
    model_render_flags = saved_model_render_flags;
    if (indirect_effect != 0) {
        disable_indirect_tev(indirect_effect, 0);
    }
    TParticleCtrl::end_effect_render();
}

void TUnk_804CCB28::run_task() {
    Vec target;
    f32 s;
    age = age + 1;
    anim_frame = anim_frame + 1;
    if (anim_frame >= 16) {
        anim_frame = 0;
    }
    if (age > 110) {
        queue_destruction();
    }
    NJS_ARGB fade_color = lbl_8044DAF0;
    s = target_scale;
    target.x = s;
    target.y = s;
    target.z = s;
    if (scale.x >= s - 1.0f) {
        if (growing != 0) {
            growing = 0;
        }
        approach_position_if_far(&scale, &target, 0.05f);
    } else {
        approach_position_if_far(&scale, &target, 0.15f);
    }
    approach_alpha_clamped(&color.a, &fade_color.a, 0.035f);
}
#pragma pop

}

TUnk_804CCB28::~TUnk_804CCB28() {

}

TUnk_804CCB28::TUnk_804CCB28(Vec *pos, s16 band, s16 level, TObject *parent, f32 radius) : TObject(parent) {
    Vec raised;
    this->band = band;
    this->level = level;
    growing = 1;
    VecCopy(&position, pos);
    this->radius = radius;
    age = 0;
    anim_frame = 0;
    scale.x = 1.2f;
    scale.y = 1.2f;
    scale.z = 1.2f;
    color.a = 1.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    VecCopy(&raised, &position);
    raised.y += 5.0f;
    VecCopy(&position, &raised);
    spawn_rafoie_explosion_bursts();
    indirect_effect = new TEffIndirect(0x11, this);
    target_scale = 1.9f;
}

TUnk_804CCB28::TUnk_804CCB28(f32 radius, const Vec *pos, s16 band, TObject *parent) : TObject(parent) {
    Vec raised;
    this->band = band;
    level = 0;
    growing = 1;
    VecCopy(&position, pos);
    this->radius = radius;
    age = 0;
    anim_frame = 0;
    scale.x = 1.2f;
    scale.y = 1.2f;
    scale.z = 1.2f;
    color.a = 1.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    VecCopy(&raised, &position);
    raised.y += 5.0f;
    VecCopy(&position, &raised);
    spawn_rafoie_explosion_bursts();
    indirect_effect = new TEffIndirect(0x11, this);
    target_scale = 1.9f;
}

void TTecRaFoie::vfunc_6(void *target) {
    DirectAttackPayload attack;
    attack.kind = 1;
    attack.power = power;
    ((TObjChara *)target)->receive_direct_attack((void *)source, attack, (void *)m_b8, 2, -1);
}

void TTecRaFoie::render() {  }

void TTecRaFoie::run_task() {
    TObjChara *chara;
    if (collidable == 0) {
        queue_destruction();
        return;
    }
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (m_148 == 1) {
        update_detonation(&target);
        return;
    }
    if (m_targets.count == 0) {
        queue_destruction();
        return;
    }
    chara = (TObjChara *)find_entity_by_id(m_targets.records[0].id);
    if (TTecLuker::is_parents_unqueued((uaddr)chara) != 0 && TObjPlayer::is_valid_and_active((uaddr)chara) != 0) {
        update_detonation(&chara->body_center);
    }
}

void TTecRaFoie::update_detonation(void *pos) {
    void *p;
    s32 h;

    VecCopy(&position, VecCopy(&target, (const Vec *)pos));
    age++;
    if (age != 10) {
        return;
    }
    new TUnk_804CCB28((Vec *)&target, band, 10, tl_particle, (f32)level);
    switch (band) {
    case 0:
        h = play_sound_effect(0x4002A803, &target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A803, &target, 0, 0);
        break;
    case 2:
    case 3:
        h = play_sound_effect(0x4002A803, &target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    case 4:
        h = play_sound_effect(0x4002A803, &target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    case 5:
        h = play_sound_effect(0x4002A803, &target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
    apply_technique_to_area_targets();
    queue_destruction();
}

void TTecRaFoie::create(TObject *source, Vec *origin, Vec *pos, s32 level) {
    new TTecRaFoie((saddr)source, origin, pos, level);
}

void TTecRaFoie::create_ex(void *source, void *origin, void *targets, s32 level) {
    new TTecRaFoie((saddr)source, (Vec *)origin, (TargetCursorList *)targets, level);
}

TTecRaFoie::~TTecRaFoie() {

}

#pragma push
#pragma opt_common_subs off
TTecRaFoie::TTecRaFoie(saddr source, Vec *origin, Vec *pos, s32 level) : TTecCircle(source, origin, pos, level) {
    m_name = TTecRaFoie_class_name;
    calc_area_parameters();
    clear_target_cursor_list(&m_targets);
    m_148 = 1;
    if (collidable != NULL) {
        collidable->bodies->radius = scope;
    }
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    vfunc_8(0);
    vfunc_9();
}
#pragma pop

TTecRaFoie::TTecRaFoie(saddr source, Vec *origin, TargetCursorList *list, s32 level) : TTecCircle(source, origin, origin, level) {
    m_name = TTecRaFoie_class_name;
    calc_area_parameters();
    m_148 = 0;
    copy_technique_target_list(&m_targets, list);
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
    if (collidable != NULL) {
        collidable->bodies->radius = scope;
    }
    vfunc_8(0);
    vfunc_9();
}
