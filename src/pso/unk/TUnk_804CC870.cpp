#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
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

// ---- pso/unk/text_80232934

struct Quad_80232934 { u32 a; u32 b; u32 c; u32 d; };

struct Obj_80232934 {
    u8 pad[0x20];
    f32 f20[3];
    Vec pos;
    u8 f38[0x10];
    s32 f48;
    f32 f4c;
};

extern "C" {

void init_texture_copy_rect(TextureFrameSlot *, void *, void *, s32, s32);
void approach_position_if_far(Vec *, Vec *, f32);
void scale_matrix(s32, f32, f32, f32);
void draw_ginja_object(void);
extern u8 technique_ringwave_texture_list[];

// ---- pso/unk/text_80232AA4
void *find_entity_by_id(u16 id);

}

// One-texture list that render() fills with a copy of the ring-wave frame and draws with; same shape as
// TEffClitical's clitical_texture_list (the 8-byte list is placed in .data, its name in .bss).
NJS_TEXNAME lbl_80516140[1];
__declspec(section ".data") NJS_TEXLIST lbl_804CC868 = { lbl_80516140, 1 };

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

struct Obj_80232B7C {
    u8 pad0[0x18];
    void *vt;
    u16 id;
    Vec pos;
    Vec scale;
    f32 f38;
    f32 f3c;
    f32 f40;
    f32 f44;
    s32 f48;
    f32 f4c;
};

struct Obj_80232B7C;
struct SEnt_80232C50 { s32 a; u32 flags; s32 c; };

struct SGrp_80232C50 { const SEnt_80232C50 *ents; u32 count; };

struct Ctl_80232C50 {
    u8 pad0[0x24];
    s32 kind;
    u8 pad28[4];
    s16 timer;
    u16 id;
    u8 f30[4];
};

extern "C" {
void mem_free(void *);
void __ct__7TObjectFP7TObject(void *self, void *parent);
extern u8 __vt__13TUnk_804CC870[];

Obj_80232B7C *construct_grants_flash(Obj_80232B7C *self, s32 id, void *parent, Vec *pos, f32 scale);

void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
}

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
    u8 *obj;
    saddr r;
    void *p;
    ((Ctl_80232C50 *)this)->timer++;
    if (((Ctl_80232C50 *)this)->timer % 5 == 0) {
        p = TObject::operator new(0x50);
        if (p != 0) {
            construct_grants_flash((Obj_80232B7C *) p, ((Ctl_80232C50 *)this)->id, tl_07, 0, 1.0f);
        }
    }
    if (((Ctl_80232C50 *)this)->timer >= 30) {
        for (i = 0; i < technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].count; i++) {
            obj = (u8 *)find_entity_by_id(((Ctl_80232C50 *)this)->id);
            if (obj != 0) {
                const SEnt_80232C50 *e = &technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].ents[i];
                if (e->flags & 0x20) {
                    r = (saddr)spawn_particle_effect((const Vec *)(obj + 0x38), e->a);
                    if (r != 0) {
                        attach_particle_model((u8 *)r, (saddr)get_bml_model(technique_effect_bml, technique_effect_entry_table[((Ctl_80232C50 *)this)->kind].ents[i].flags >> 16), (saddr)lbl_805D63B0, 0, 1, 1.0f);
                    }
                } else {
                    spawn_particle_effect((const Vec *)(obj + 0x38), e->a);
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
        new TUnk_804CCA78((Vec *)((Ctl_80232C50 *)this)->f30, 0xF, 0x4002A60D, dir, (TObject *)tl_07);
        ((TObject *)((Ctl_80232C50 *)this))->queue_destruction();
    }
}

Obj_80232B7C *construct_grants_flash(Obj_80232B7C *self, s32 id, void *parent, Vec *pos, f32 scale) {
    __ct__7TObjectFP7TObject(self, parent);
    self->vt = __vt__13TUnk_804CC870;
    self->id = id;
    self->pos.x = 0.0f;
    self->pos.y = 0.0f;
    self->pos.z = 0.0f;
    self->scale.x = 0.05f;
    self->scale.y = 0.05f;
    self->scale.z = 0.05f;
    self->f4c = 0.05f;
    if ((u16)id == 0xffff && pos != 0) {
        VecCopy((Vec *)&self->pos, (const Vec *)pos);
        self->scale.x = scale;
        self->scale.y = scale;
        self->scale.z = scale;
        self->f4c = 2.0f;
    }
    self->f38 = 1.0f;
    self->f3c = 1.0f;
    self->f40 = 1.0f;
    self->f44 = 1.0f;
    self->f48 = 0;
    return self;
}

TUnk_804CC870::~TUnk_804CC870() {

}

void TUnk_804CC870::run_task() {
    u8 *arg0 = (u8 *)this;
    saddr entity;
    entity = (saddr)find_entity_by_id((*(u16 *)((s8 *)arg0 + 0x1C)));
    if (entity != 0) {
        VecCopy((Vec *)(arg0 + 0x20), (const Vec *)(entity + 0x38));
    }
    this->m_48 = (this->m_48 + 1);
    if ((s32) this->m_48 >= 7) {
        this->m_48 = 0;
    }
    if (this->m_38 <= 0.0f) {
        ((TObject *)arg0)->queue_destruction();
    }
}

void TUnk_804CC870::render() {
    Obj_80232934 *arg0 = (Obj_80232934 *)this;
    TextureFrameSlot ctx;
    s32 id;
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2 ||
        get_current_floor_area() == AREA_LOBBY) {
        return;
    }
    init_texture_copy_rect(&ctx, &lbl_804CC868, technique_ringwave_texture_list, 0, this->m_48 + 1);
    Vec v = { 1.2f, 1.2f, 1.2f };
    Quad_80232934 q = { 0, 0, 0, 0 };
    approach_alpha_clamped((f32 *)arg0->f38, (const f32 *)&q, 0.1f);
    approach_position_if_far(&arg0->pos, &v, arg0->f4c);
    copy_anim_frame_to_slot(&ctx);
    id = model_render_flags;
    saved_model_render_flags = id;
    model_render_flags = id | 0x10;
    ((void (*)(void *, s32))set_constant_material)(arg0->f38, id);
    set_draw_list_mask(3);
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(arg0->f20);
    scale_matrix(0, arg0->pos.x, arg0->pos.y, arg0->pos.z);
    translate_matrix(0, 0.0f, 1e+01f, 0.0f);
    TObjFish::set_global_param((saddr)&lbl_804CC868);
    get_bml_model(technique_effect_bml, 10);
    draw_ginja_object();
    pop_matrix();
    copy_slot_to_anim_frame(&ctx);
    restore_draw_list_mask();
    model_render_flags = saved_model_render_flags;
}

extern "C" {
void TTecGrants::init_parameters() {
    TechniqueParams *params = calc_technique_parameters(9, m_78, 0xFFFF);
    ((TechniqueParams *)&m_88)->copy(params);
    if (m_78 >= 15 && TTecCtrl::is_technique_ready() == 0) {
        m_88 = (f32)(tech_high_level_linear_power_table[9].base + tech_high_level_linear_power_table[9].per_level * m_78);
        return;
    }
    m_88 = m_88 + (f32)(((TechniqueParams *)&m_88)->pad_24 * m_78);
    if (TTecCtrl::is_technique_ready()) {
        m_88 = m_88 * lbl_804CC55C[9].pad_00;
    }
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
u16 get_entity_id(void *);
TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void *mem_alloc(u32 size);
s32 play_sound_effect(s32, void *, s32, s32);
}
TUnk_804CC888::TUnk_804CC888(u8 *src, s32 level, TObject *parent) : TObject(parent) {
    u32 i;
    VecCopy((Vec *)(((Task_80232EC0 *)this)->pos), (const Vec *)(src + 0x38));
    ((Task_80232EC0 *)this)->x2c = 0;
    ((Task_80232EC0 *)this)->owner = get_entity_id(src);
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
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, 0x100, 0);
        }
        break;
    case 1:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        break;
    case 2:
    case 3:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, -0x180, 0);
        }
        break;
    case 4:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, -0x250, 0);
        }
        break;
    case 5:
        ((Task_80232EC0 *)this)->sound = play_sound_effect(0x4002A90C, ((Task_80232EC0 *)this)->pos, 0, 0);
        if (((Task_80232EC0 *)this)->sound >= 0) {
            set_sound_pitch_request(((Task_80232EC0 *)this)->sound, -0x100, 0);
        }
        break;
    }
}
