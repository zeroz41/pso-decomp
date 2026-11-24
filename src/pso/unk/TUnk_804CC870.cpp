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
#include "pso/unk/TUnk_804CC870.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80232B24.h"
#include "pso/unk/TUnk_804CC888.h"
#include "pso/unk/TUnk_804CCA78.h"
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

// ---- pso/unk/text_80232934

struct Quad_80232934 { u32 a; u32 b; u32 c; u32 d; };


extern "C" {

void scale_matrix(s32, f32, f32, f32);
void draw_ginja_object(void);

// ---- pso/unk/text_80232AA4

}

// One-texture list that render() fills with a copy of the ring-wave frame and draws with; same shape as
// TEffClitical's clitical_texture_list (the 8-byte list is placed in .data, its name in .bss).
NJS_TEXNAME lbl_80516140[1];
NJS_TEXLIST lbl_804CC868 = { lbl_80516140, 1 };

// ---- pso/unk/text_80232B24

// ---- pso/unk/text_80232B7C

struct Part_80232EC0 { s32 id; u32 flags; u8 pad8[4]; };

struct Profile_80232EC0 { const Part_80232EC0 *parts; u32 count; };

struct Obj_80232E0C {
    u8 pad0[0x18];
    void *vt;
    void **items;
    s32 f20;
    s32 kind;
};

struct SEnt_80232C50 { s32 a; u32 flags; s32 c; };

struct SGrp_80232C50 { const SEnt_80232C50 *ents; u32 count; };

struct Ctl_80232C50 {
    u8 pad0[0x24];
    s32 kind;
    u8 pad28[4];
    s16 timer;
    u16 id;
    u8 pos[4];
};


// Per level tier (TObjPlayer::get_level_tier): the particle emitters TUnk_804CC888 keeps alive and
// the effects it spawns when it ends.
// inferred names: grants_emitter_parts_<tier> and grants_effect_entries_<tier> are the rows of
// grants_effect_emitter_table and technique_effect_entry_table for each tier.
static const Part_80232EC0 grants_emitter_parts_0[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const SEnt_80232C50 grants_effect_entries_0[3] = { { 0x1D3, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1CB, 0, 0 } };
static const Part_80232EC0 grants_emitter_parts_1[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const SEnt_80232C50 grants_effect_entries_1[3] = { { 0x1D3, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1D5, 0, 0 } };
static const Part_80232EC0 grants_emitter_parts_2[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const SEnt_80232C50 grants_effect_entries_2[3] = { { 0x1D3, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1CC, 0, 0 } };
static const Part_80232EC0 grants_emitter_parts_3[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const SEnt_80232C50 grants_effect_entries_3[3] = { { 0x1C0, 0, 0 }, { 0x1D4, 0, 0 }, { 0x10F, 0, 0 } };
static const Part_80232EC0 grants_emitter_parts_4[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const SEnt_80232C50 grants_effect_entries_4[3] = { { 0x1C0, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1A4, 0, 0 } };
static const Part_80232EC0 grants_emitter_parts_5[3] = { { 0xB4, 0 }, { 0xB5, 0 }, { 0xB6, 0 } };
static const SEnt_80232C50 grants_effect_entries_5[4] = { { 0x1C2, 0, 0 }, { 0x1D4, 0, 0 }, { 0x1C9, 0, 0 }, { 0x1DA, 0, 0 } };

const Profile_80232EC0 grants_effect_emitter_table[6] = {
    { grants_emitter_parts_0, 3 }, { grants_emitter_parts_1, 3 }, { grants_emitter_parts_2, 3 },
    { grants_emitter_parts_3, 3 }, { grants_emitter_parts_4, 3 }, { grants_emitter_parts_5, 3 },
};

const SGrp_80232C50 technique_effect_entry_table[6] = {
    { grants_effect_entries_0, 3 }, { grants_effect_entries_1, 3 }, { grants_effect_entries_2, 3 },
    { grants_effect_entries_3, 3 }, { grants_effect_entries_4, 3 }, { grants_effect_entries_5, 4 },
};

const char *tec_grants_class_name = "TTecGrants";
extern void *tl_07;

// Function definitions in reverse address order (defer_codegen emits them reversed).
#pragma defer_codegen on

TUnk_804CC888::~TUnk_804CC888() {
    u32 i;
    for (i = 0; i < grants_effect_emitter_table[((Obj_80232E0C *)this)->kind].count; i++) {
        if (((Obj_80232E0C *)this)->items[i] != NULL) {
            ((TObject *)(((Obj_80232E0C *)this)->items[i]))->queue_destruction();
        }
    }
    stop_sound_request(((Obj_80232E0C *)this)->f20);
    mem_free(((Obj_80232E0C *)this)->items);
}

void TUnk_804CC888::run_task() {
    u32 i;
    s32 dir;
    TObjCollidable *obj;
    TParticleCtrl *r;
    ((Ctl_80232C50 *)this)->timer++;
    if (((Ctl_80232C50 *)this)->timer % 5 == 0) {
        new TUnk_804CC870(((Ctl_80232C50 *)this)->id, (TObject *)tl_07, NULL, 1.0f);
    }
    if (((Ctl_80232C50 *)this)->timer >= 30) {
        for (i = 0; i < technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].count; i++) {
            obj = find_entity_by_id(((Ctl_80232C50 *)this)->id);
            if (obj != NULL) {
                const SEnt_80232C50 *e = &technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].ents[i];
                if (e->flags & 0x20) {
                    r = spawn_particle_effect(&obj->position, e->a);
                    if (r != NULL) {
                        attach_particle_model(r, get_bml_model(technique_effect_bml, technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].ents[i].flags >> 16), technique_texture_list, NULL, 1, 1.0f);
                    }
                } else {
                    spawn_particle_effect(&obj->position, e->a);
                }
            }
        }
        switch (((Ctl_80232C50 *)this)->kind) {
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
        new TUnk_804CCA78((Vec *)((Ctl_80232C50 *)this)->pos, 0xF, 0x4002A60D, dir, (TObject *)tl_07);
        ((TObject *)((Ctl_80232C50 *)this))->queue_destruction();
    }
}

TUnk_804CC870::TUnk_804CC870(s32 owner_id, TObject *parent, Vec *pos, f32 start_scale) : TObject(parent) {
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

TUnk_804CC870::~TUnk_804CC870() {

}

void TUnk_804CC870::run_task() {
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

void TUnk_804CC870::render() {
    TextureFrameSlot ctx;
    s32 id;
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_LOBBY) {
        return;
    }
    init_texture_copy_rect(&ctx, &lbl_804CC868, &technique_ringwave_texture_list, 0, frame + 1);
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
    TObjFish::set_global_param(&lbl_804CC868);
    get_bml_model(technique_effect_bml, 10);
    draw_ginja_object();
    pop_matrix();
    copy_slot_to_anim_frame(&ctx);
    restore_draw_list_mask();
    model_render_flags = saved_model_render_flags;
}


void TTecGrants::init_parameters() {
    TechniqueParams *params = calc_technique_parameters(9, level, 0xFFFF);
    ((TechniqueParams *)&power)->copy(params);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        power = (f32)(tech_high_level_linear_power_table[9].base + tech_high_level_linear_power_table[9].per_level * level);
        return;
    }
    power = power + (f32)(((TechniqueParams *)&power)->pad_24 * level);
    if (TTecCtrl::is_technique_ready()) {
        power = power * technique_scale_table[9].power;
    }
}


#pragma defer_codegen off

struct Task_80232EC0 {
    u8 pad0[0x18];
    void **vt;
    uaddr *emitters;
    s32 sound;
    s32 tier;
    s32 level;
    s16 x2c;
    u16 owner;
    u8 pos[0xC];
};

extern "C" {
}
TUnk_804CC888::TUnk_804CC888(u8 *src, s32 level, TObject *parent) : TObject(parent) {
    u32 i;
    VecCopy((Vec *)(((Task_80232EC0 *)this)->pos), (const Vec *)(src + 0x38));
    ((Task_80232EC0 *)this)->x2c = 0;
    ((Task_80232EC0 *)this)->owner = ((TObjBase *)(src))->get_entity_id();
    ((Task_80232EC0 *)this)->level = level;
    if (((Task_80232EC0 *)this)->level < 0) {
        ((Task_80232EC0 *)this)->level = 0;
    } else if (level >= 0x1E) {
        ((Task_80232EC0 *)this)->level = 0x1E;
    }
    ((Task_80232EC0 *)this)->tier = TObjPlayer::get_level_tier(((Task_80232EC0 *)this)->level);
    ((Task_80232EC0 *)this)->emitters = (uaddr *)mem_alloc(grants_effect_emitter_table[((Task_80232EC0 *)this)->tier].count * sizeof(uaddr));
    for (i = 0; i < grants_effect_emitter_table[((Task_80232EC0 *)this)->tier].count; i++) {
        ((Task_80232EC0 *)this)->emitters[i] = (uaddr)spawn_continuous_particle_effect_with_flags(((Task_80232EC0 *)this)->pos, grants_effect_emitter_table[((Task_80232EC0 *)this)->tier].parts[i].id, 0x10);
        if (((Task_80232EC0 *)this)->emitters[i] != 0) {
            ((TParticleCtrl *)(((Task_80232EC0 *)this)->emitters[i]))->set_owner_id(((Task_80232EC0 *)this)->owner);
        }
    }
    switch (((Task_80232EC0 *)this)->tier) {
    case 0:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, reinterpret_cast<const Vec *>(((Task_80232EC0 *)this)->pos), 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, 0x100, 0);
        }
        break;
    case 1:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, reinterpret_cast<const Vec *>(((Task_80232EC0 *)this)->pos), 0, 0);
        break;
    case 2:
    case 3:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, reinterpret_cast<const Vec *>(((Task_80232EC0 *)this)->pos), 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, -0x180, 0);
        }
        break;
    case 4:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, reinterpret_cast<const Vec *>(((Task_80232EC0 *)this)->pos), 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, -0x250, 0);
        }
        break;
    case 5:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, reinterpret_cast<const Vec *>(((Task_80232EC0 *)this)->pos), 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, -0x100, 0);
        }
        break;
    }
}
