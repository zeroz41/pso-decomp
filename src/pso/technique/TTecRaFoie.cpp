#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/system/BmlAccessors.h"
#include "pso/unk/text_803D96A8.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TUnk_804CC148.h"
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
#include "pso/unk/text_80087278.h"
#include "pso/system/SoundEffect.h"
#pragma readonly_strings on

struct RafoieBurst { s32 entry; s32 flags; f32 scale; };

struct RafoieBurstList { const RafoieBurst *entries; u32 count; };

struct Obj_80237DAC {
    u8 pad0[0x20];
    u16 band;
    u8 pad22[0x28 - 0x22];
    Vec position;
};

extern "C" {

u16 get_entity_id(void *);
s32 is_split_screen();


struct RecoveredGlobal_80238388_lbl_8044DAF0 {
    s32 value;
    u8 remaining[0xC];
};
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
extern const RecoveredGlobal_80238388_lbl_8044DAF0 lbl_8044DAF0 = {0};
}

void TUnk_804CCB28::spawn_rafoie_explosion_bursts() {
    Obj_80237DAC *self = (Obj_80237DAC *)this;
    Vec higher;
    u32 i;
    VecCopy(&higher, &self->position);
    higher.y = (8.0f) + self->position.y;
    for (i = 0; i < rafoie_burst_table[*(u16 *)&this->m_20].count; i++) {
        const RafoieBurst *row = &rafoie_burst_table[*(u16 *)&this->m_20].entries[i];
        s32 mode = 0;
        void *p;
        if (row->flags & 0x1000) {
            mode = 0x2000;
        }
        if (row->flags & 0x10) {
            p = spawn_particle_effect_with_flags(&self->position, row->entry, mode);
        } else {
            p = spawn_particle_effect_with_flags(&higher, row->entry, mode);
        }
        if (p != NULL) {
            ((TParticleCtrl *)p)->set_scale(rafoie_burst_table[*(u16 *)&this->m_20].entries[i].scale, rafoie_burst_table[*(u16 *)&this->m_20].entries[i].scale);
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
    void *emitter;
    TObjChara *chara;
    if (m_148 == 1) {
        if (is_split_screen() != 0) {
            spawn_particle_effect(&target, 0x39);
        } else {
            emitter = spawn_particle_effect(&target, 0x1A);
            if (emitter != NULL) {
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, 9), lbl_805D63B0, 0, 1, 1.0f);
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
                attach_particle_model((u8 *)emitter, get_bml_model(technique_effect_bml, 9), lbl_805D63B0, 0, 1, 1.0f);
            }
        }
    }
}

}

#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecAnti.h"

#include "pso/technique/TechniqueParams.h"
struct Stack_80238388 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
};

struct RaFoie_802381F8 {
    u8 pad0[0x22];
    u16 level;
    TUnk_804DDF04 *tev;
    u8 m28[0x34 - 0x28];
    f32 sx;
    f32 sy;
    f32 sz;
    u8 pad40[0x48 - 0x40];
    u8 m48[1];
};

extern "C" {
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void post_translate_matrix(void *);
void draw_ginja_object(void);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
#pragma push
#pragma opt_common_subs off

void TTecRaFoie::calc_area_parameters() {
    TechniqueParams *params = calc_technique_parameters(2, m_78, 0xFFFF);
    ((TechniqueParams *)&m_88)->copy(params);
    if (m_78 >= 15 && TTecCtrl::is_technique_ready() == 0) {
        m_88 = (f32)(tech_high_level_linear_power_table[2].base + tech_high_level_linear_power_table[2].per_level * m_78);
        return;
    }
    m_88 = m_88 + (f32)(((TechniqueParams *)&m_88)->pad_24 * m_78);
    if (TTecCtrl::is_technique_ready()) {
        m_88 = m_88 * lbl_804CC55C[2].pad_00;
    }
}

void TUnk_804CCB28::render() {
    RaFoie_802381F8 *o = (RaFoie_802381F8 *)this;
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
    ((void (*)(void *, s32))set_constant_material)(o->m48, id);
    if (o->tev != 0) {
        enable_indirect_tev(o->tev, 2, 0, 0);
    }
    lv = o->level;
    x = o->sx;
    y = o->sy;
    z = o->sz;
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
    post_translate_matrix(o->m28);
    scale_matrix(0, x, y, z);
    rotate_matrix_y(0, *(s32 *)(camera_ctrl_instance + 0x194));
    TObjFish::set_global_param((saddr)lbl_805D63B0);
    set_cull_back();
    set_draw_list_mask(3);
    get_bml_model(technique_effect_bml, 0xB);
    draw_ginja_object();
    restore_draw_list_mask();
    set_cull_none();
    pop_matrix();
    model_render_flags = saved_model_render_flags;
    if (o->tev != 0) {
        disable_indirect_tev(o->tev, 0);
    }
    TParticleCtrl::end_effect_render();
}

void TUnk_804CCB28::run_task() {
    u8 *arg0 = (u8 *)this;
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80238388, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80238388, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80238388, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_80238388, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_80238388, sp18) == 0x10);
    LAYOUT_ASSERT(sp1C_offset, offsetof(Stack_80238388, sp1C) == 0x14);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_80238388, sp20) == 0x18);
    Stack_80238388 stack;
    f32 temp_f1;
    this->m_58 = (this->m_58 + 1);
    this->m_5c = (s32) (this->m_5c + 1);
    if ((s32) this->m_5c >= 0x10) {
        this->m_5c = 0;
    }
    if ((s32) this->m_58 > 0x6E) {
        queue_destruction();
    }
    stack.sp8 = *(s32 *)((s8 *)&lbl_8044DAF0.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8044DAF0.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8044DAF0.value + 8);
    stack.sp14 = *(s32 *)((s8 *)&lbl_8044DAF0.value + 0xC);
    temp_f1 = this->m_40;
    stack.sp18 = temp_f1;
    stack.sp1C = temp_f1;
    stack.sp20 = temp_f1;
    if (this->m_34 >= (temp_f1 - (1.0f))) {
        if ((s32) this->m_60 != 0) {
            this->m_60 = 0;
        }
        approach_position_if_far(((u8 *)&this->m_34), (u8 *)&stack.sp18, (f32) ((0.05f)));
    } else {
        approach_position_if_far(((u8 *)&this->m_34), (u8 *)&stack.sp18, (f32) ((0.15f)));
    }
    approach_alpha_clamped((f32 *)(arg0 + 0x48), (const f32 *)&stack.sp8, 0.035f);
}
#pragma pop

}
struct RecoveredGlobal_802384E0_lbl_804CCB28;

extern RecoveredGlobal_802384E0_lbl_804CCB28 __vt__13TUnk_804CCB28;

TUnk_804CCB28::~TUnk_804CCB28() {

}

struct Stack_802384E0 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_802384E0_lbl_804CCB28 { s32 value; u8 remaining[0x14]; };


extern "C" {
void run_task__10TTecRaFoieFv(TTecRaFoie *arg0);
extern s32 tl_particle;
s32 __ct__7TObjectFP7TObject(void *, void *);
void copy_technique_target_list(void *, void *);
}

u8 *create_rafoie_explosion(u8 *arg0, s32 *arg1, s16 band, s16 arg3, saddr arg4, f32 farg0) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802384E0, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802384E0, spC) == 0x4);
    Stack_802384E0 stack;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804CCB28.value;
    ((TUnk_804CCB28 *)arg0)->m_20 = band;
    *(s16 *)((s8 *)arg0 + 0x22) = arg3;
    ((TUnk_804CCB28 *)arg0)->m_60 = 1;
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(arg1));
    *(f32 *)((s8 *)arg0 + 0x44) = farg0;
    ((TUnk_804CCB28 *)arg0)->m_58 = 0;
    *(s32 *)((s8 *)arg0 + 0x5C) = 0;
    ((TUnk_804CCB28 *)arg0)->m_34 = (f32) (1.2f);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) (1.2f);
    ((TUnk_804CCB28 *)arg0)->m_3c = (f32) (1.2f);
    ((TUnk_804CCB28 *)arg0)->m_48 = (f32) (1.0f);
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) (1.0f);
    ((TUnk_804CCB28 *)arg0)->m_50 = (f32) (1.0f);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) (1.0f);
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x28));
    stack.spC += (5.0f);
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(&stack.sp8));
    ((TUnk_804CCB28 *)arg0)->spawn_rafoie_explosion_bursts();
    ((TUnk_804CCB28 *)arg0)->indirect_effect = new TUnk_804DDF04(0x11, (TObject *)arg0);
    ((TUnk_804CCB28 *)arg0)->m_40 = (f32) (1.9f);
    return arg0;
}

struct Stack_802385EC {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

TUnk_804CCB28 *create_fire_explosion_effect(u8 *arg0, f32 farg0, const Vec *pos, s16 arg2, TObject *parent) {
    LAYOUT_ASSERT(sp8_offset, (offsetof(Stack_802385EC, sp8) == 0x0));
    LAYOUT_ASSERT(spC_offset, (offsetof(Stack_802385EC, spC) == 0x4));
    Stack_802385EC stack;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)parent);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804CCB28.value;
    ((TUnk_804CCB28 *)arg0)->m_20 = arg2;
    *(s16 *)((s8 *)arg0 + 0x22) = 0;
    ((TUnk_804CCB28 *)arg0)->m_60 = 1;
    VecCopy((Vec *)(arg0 + 0x28), pos);
    *(f32 *)((s8 *)arg0 + 0x44) = farg0;
    ((TUnk_804CCB28 *)arg0)->m_58 = 0;
    *(s32 *)((s8 *)arg0 + 0x5C) = 0;
    ((TUnk_804CCB28 *)arg0)->m_34 = (f32) (1.2f);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) (1.2f);
    ((TUnk_804CCB28 *)arg0)->m_3c = (f32) (1.2f);
    ((TUnk_804CCB28 *)arg0)->m_48 = (f32) (1.0f);
    *(f32 *)((s8 *)arg0 + 0x4C) = (f32) (1.0f);
    ((TUnk_804CCB28 *)arg0)->m_50 = (f32) (1.0f);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) (1.0f);
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x28));
    stack.spC += (5.0f);
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(&stack.sp8));
    ((TUnk_804CCB28 *)arg0)->spawn_rafoie_explosion_bursts();
    ((TUnk_804CCB28 *)arg0)->indirect_effect = new TUnk_804DDF04(0x11, (TObject *)arg0);
    ((TUnk_804CCB28 *)arg0)->m_40 = (f32) (1.9f);
    return (TUnk_804CCB28 *)arg0;
}

void TTecRaFoie::vfunc_6(void *target) {
    DirectAttackPayload attack;
    attack.kind = 1;
    attack.power = m_88;
    ((TObjChara *)target)->receive_direct_attack((void *)source, attack, (void *)m_b8, 2, -1);
}

void TTecRaFoie::render() {  }

void run_task__10TTecRaFoieFv(TTecRaFoie *self) {
    TObjChara *chara;
    if (self->m_e8 == 0) {
        self->queue_destruction();
        return;
    }
    self->source = (uaddr)find_entity_by_id(self->m_b4);
    if (self->source == 0) {
        self->queue_destruction();
        return;
    }
    if (self->m_148 == 1) {
        self->update_detonation(&self->target);
        return;
    }
    if (self->m_targets.count == 0) {
        self->queue_destruction();
        return;
    }
    chara = (TObjChara *)find_entity_by_id(self->m_targets.records[0].id);
    if (TTecLuker::is_parents_unqueued((uaddr)chara) != 0 && TObjPlayer::is_valid_and_active((uaddr)chara) != 0) {
        self->update_detonation(&chara->body_center);
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
    p = TObject::operator new(0x64);
    if (p != NULL) {
        create_rafoie_explosion((u8 *)p, (s32 *)&target, band, 10, tl_particle, (f32)m_78);
    }
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

void TTecRaFoie::create(void *origin, void *pos, void *level) {
    new TTecRaFoie((saddr)this, (Vec *)origin, (Vec *)pos, (saddr)level);
}

void TTecRaFoie::create_ex(void *source, void *origin, void *targets, s32 level) {
    new TTecRaFoie((saddr)source, (Vec *)origin, (TargetCursorList *)targets, level);
}

TTecRaFoie::~TTecRaFoie() {

}

#pragma push
#pragma opt_common_subs off
TTecRaFoie::TTecRaFoie(saddr source, Vec *origin, Vec *pos, s32 level) : TUnk_804CC148(source, origin, pos, level) {
    m_name = TTecRaFoie_class_name;
    calc_area_parameters();
    clear_target_cursor_list(&m_targets);
    m_148 = 1;
    if (m_e8 != NULL) {
        m_e8->bodies->radius = m_90;
    }
    if (this->source != 0) {
        m_b4 = get_entity_id((void *)this->source);
    }
    vfunc_8(0);
    vfunc_9();
}
#pragma pop

TTecRaFoie::TTecRaFoie(saddr source, Vec *origin, TargetCursorList *list, s32 level) : TUnk_804CC148(source, origin, origin, level) {
    m_name = TTecRaFoie_class_name;
    calc_area_parameters();
    m_148 = 0;
    copy_technique_target_list(&m_targets, list);
    if (this->source != 0) {
        m_b4 = get_entity_id((void *)this->source);
    }
    if (m_e8 != NULL) {
        m_e8->bodies->radius = m_90;
    }
    vfunc_8(0);
    vfunc_9();
}

