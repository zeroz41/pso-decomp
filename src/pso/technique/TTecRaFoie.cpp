#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TUnk_804CC148.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/unk/TUnk_804CCB28.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/effect/TEffect.h"
#include "pso/effect/TEffClitical.h"
#include "pso/unk/text_802A8210.h"
#include "pso/effect/TEffIndirectCtrl.h"

#include "pso/system/vector.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/technique/TTecRaBarta.h"
#include "pso/technique/TTecRaZonde.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"


#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#pragma readonly_strings on

struct RafoieBurst_80237DAC { s32 entry; s32 flags; f32 scale; };

struct RafoieBursts_80237DAC { RafoieBurst_80237DAC *entries; u32 count; };

struct Obj_80237DAC {
    u8 pad0[0x20];
    u16 band;
    u8 pad22[0x28 - 0x22];
    Vec position;
};

typedef struct TTecRaFoie_80237FB8 {
    u8 pad0[0x7C];
    Vec target;
    u8 pad1[0xEC - 0x88];
    s32 target_count;
    u16 first_id;
    u8 pad2[0x148 - 0xF2];
    s32 explicit_position;
} TTecRaFoie_80237FB8;

typedef struct TObjPlayer_80237FB8 {
    u8 pad0[0x2FC];
    Vec pos;
} TObjPlayer_80237FB8;


extern "C" {
u32 find_entity_by_id(int);
void *spawn_particle_effect_with_flags(const void *pos, s32 id, s32 flags);

u16 get_entity_id(void *);
s32 is_split_screen();
void get_bml_model(void *, s32);
#define get_bml_model ((void * (*)(void *, int))get_bml_model)
void attach_particle_model(void *, void *, void *, int, int, f32);
void spawn_particle_effect(void *, s32, void *);
#define spawn_particle_effect ((void * (*)(Vec *, int))spawn_particle_effect)
extern void *technique_effect_bml;
extern void *lbl_805D63B0;

s32 play_sound_effect(s32 id, void *pos, s32 a, s32 b);
#define play_sound_effect ((s32 (*)(s32, s32, s32, s32))play_sound_effect)

struct RecoveredGlobal_80238388_lbl_8044DAF0 {
    s32 value;
    u8 remaining[0xC];
};
extern "C" {
extern const RafoieBurst_80237DAC lbl_8044DA48[1] = {{494, 0, 1.0f}};
extern const RafoieBurst_80237DAC lbl_8044DA54[2] = {{491, 0, 1.0f}, {494, 0, 1.0f}};
extern const RafoieBurst_80237DAC lbl_8044DA6C[2] = {{393, 0, 1.0f}, {494, 0, 1.0f}};
extern const RafoieBurst_80237DAC lbl_8044DA84[4] = {{396, 0, 1.0f}, {494, 0, 1.0f}, {482, 0x1000, 1.0f}, {486, 0x10, 1.0f}};
extern const RafoieBursts_80237DAC rafoie_burst_table[6] = {
    {(RafoieBurst_80237DAC *)lbl_8044DA48, 1}, {(RafoieBurst_80237DAC *)lbl_8044DA48, 1}, {(RafoieBurst_80237DAC *)lbl_8044DA48, 1},
    {(RafoieBurst_80237DAC *)lbl_8044DA54, 2}, {(RafoieBurst_80237DAC *)lbl_8044DA6C, 2}, {(RafoieBurst_80237DAC *)lbl_8044DA84, 4},
};
const char *TTecRaFoie_class_name = "TTecRaFoie";
extern const RecoveredGlobal_80238388_lbl_8044DAF0 lbl_8044DAF0 = {0};
}

#pragma push
#pragma opt_common_subs off

#pragma pop

void TUnk_804CCB28::spawn_rafoie_explosion_bursts() {
    Obj_80237DAC *self = (Obj_80237DAC *)this;
    Vec higher;
    u32 i;
    VecCopy((Vec *)&higher, (const Vec *)&self->position);
    higher.y = (8.0f) + self->position.y;
    for (i = 0; i < rafoie_burst_table[*(u16 *)&this->m_20].count; i++) {
        RafoieBurst_80237DAC *row = &rafoie_burst_table[*(u16 *)&this->m_20].entries[i];
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
    u8 *arg0 = (u8 *)this;
    s32 handle;

    switch (this->band) {
    case 0:
        handle = play_sound_effect(0x4002A602, (int)(arg0 + 0x7C), 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, 0x100, 0);
        }
        return;
    case 1:
        play_sound_effect(0x4002A602, (int)(arg0 + 0x7C), 0, 0);
        return;
    case 2:
    case 3:
        handle = play_sound_effect(0x4002A602, (int)(arg0 + 0x7C), 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x180, 0);
        }
        break;
    case 4:
        handle = play_sound_effect(0x4002A602, (int)(arg0 + 0x7C), 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x250, 0);
        }
        break;
    case 5:
        handle = play_sound_effect(0x4002A602, (int)(arg0 + 0x7C), 0, 0);
        if (handle >= 0) {
            set_sound_pitch_request(handle, -0x100, 0);
        }
        break;
    }
}
void TTecRaFoie::vfunc_8(void *) {
    TTecRaFoie_80237FB8 *self = (TTecRaFoie_80237FB8 *)this;
    void *emitter;
    TObjPlayer_80237FB8 *target;
    if (self->explicit_position == 1) {
        if (is_split_screen() != 0) {
            spawn_particle_effect(&self->target, 0x39);
        } else {
            emitter = spawn_particle_effect(&self->target, 0x1A);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 9), lbl_805D63B0, 0, 1, (1.0f));
            }
        }
        spawn_particle_effect(&self->target, 0x3A);
        spawn_particle_effect(&self->target, 0x3B);
        return;
    }
    if (self->target_count != 0) {
        target = (TObjPlayer_80237FB8 *) find_entity_by_id(self->first_id);
        if (TTecLuker::is_parents_unqueued((u32)target) != 0 && TObjPlayer::is_valid_and_active((u32)target) != 0) {
            Vec point = target->pos;
            spawn_particle_effect(&point, 0x39);
            emitter = spawn_particle_effect(&point, 0x1A);
            if (emitter != NULL) {
                attach_particle_model(emitter, get_bml_model(technique_effect_bml, 9), lbl_805D63B0, 0, 1, (1.0f));
            }
        }
    }
}

}

#undef get_bml_model
#undef play_sound_effect

#undef spawn_particle_effect

#include <stddef.h>
#include "pso/system/scene/TScene.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecResta.h"
struct Stack_80238388 {
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
};

struct RecoveredGlobal_80230D9C_lbl_804CC510
{
  s32 value;
  u8 remaining[0x48];
};

struct RecoveredGlobal_80230D9C_lbl_804CC55C
{
  s32 value;
  u8 remaining[0x94];
};

struct RecoveredFields_80230D9C_arg0
{
  u8 unknown_0[0x78];
  s16 field_78;
  u8 unknown_7A[0xE];
  f32 field_88;
  u8 unknown_8C[0x20];
  s16 field_AC;
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

#pragma fp_contract on


extern "C" {
s32 calc_technique_parameters(int, int, int);
extern RecoveredGlobal_80230D9C_lbl_804CC510 tech_high_level_linear_power_table;
extern RecoveredGlobal_80230D9C_lbl_804CC55C lbl_804CC55C;
void scale_matrix(s32, f32, f32, f32);
void rotate_matrix_y(s32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void draw_ginja_object(void);
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80238388_lbl_8044DAF0_size[sizeof(RecoveredGlobal_80238388_lbl_8044DAF0) == 0x10 ? 1 : -1];

typedef struct RecoveredFields_80230D9C_arg0 RecoveredFields_80230D9C_arg0;
typedef struct RecoveredGlobal_80230D9C_lbl_804CC510 RecoveredGlobal_80230D9C_lbl_804CC510;
typedef struct RecoveredGlobal_80230D9C_lbl_804CC55C RecoveredGlobal_80230D9C_lbl_804CC55C;
typedef char RecoveredGlobal_80230D9C_lbl_804CC510_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC510)) == 0x4C) ? (1) : (-1)];
typedef char RecoveredGlobal_80230D9C_lbl_804CC55C_size[((sizeof(RecoveredGlobal_80230D9C_lbl_804CC55C)) == 0x98) ? (1) : (-1)];
void TTecRaFoie::calc_area_parameters() {
    u8 *arg0 = (u8 *)this;
  int new_var;
 new_var = (int) calc_technique_parameters(0x2, (int) ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78, 0xFFFF); do { ((TTecAnti *)(arg0 + ((0, 0x88))))->copy_params((u8 *)new_var); if ((((s16) ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78) >= 0xF) && (TTecCtrl::is_technique_ready() == 0)) { ((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 = (f32) ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0x8))) + ((*((s16 *) (((s8 *)&tech_high_level_linear_power_table.value) + 0xa))) * ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78)); return; } } while (0);
  ((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 + ((f32) (((RecoveredFields_80230D9C_arg0 *) arg0)->field_AC * ((RecoveredFields_80230D9C_arg0 *) arg0)->field_78)));
  if (TTecCtrl::is_technique_ready())
  {
    ((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 = (f32) (((RecoveredFields_80230D9C_arg0 *) arg0)->field_88 * (*((f32 *) (((s8 *)&lbl_804CC55C.value) + 0x10))));
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
    TObjFish::set_global_param((s32)lbl_805D63B0);
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
    typedef char sp8_offset[(offsetof(Stack_80238388, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80238388, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80238388, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80238388, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80238388, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_80238388, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80238388, sp20) == 0x18) ? 1 : -1];
    Stack_80238388 stack;
    f32 temp_f1;
    this->m_58 = (this->m_58 + 1);
    *(s32 *)&this->unk_5C = (s32) (*(s32 *)&this->unk_5C + 1);
    if ((s32) *(s32 *)&this->unk_5C >= 0x10) {
        *(s32 *)&this->unk_5C = 0;
    }
    if ((s32) this->m_58 > 0x6E) {
        ((TObject *)arg0)->queue_destruction();
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
typedef char RecoveredGlobal_802384E0_lbl_804CCB28_size[sizeof(RecoveredGlobal_802384E0_lbl_804CCB28) == 0x18 ? 1 : -1];

struct Stack_802385EC {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredFields_80238D10_arg0
{
  u8 unknown_0[0x78];
  s16 field_78;
  u8 unknown_7A[0xE];
  f32 field_88;
  u8 unknown_8C[0x20];
  s16 field_AC;
};

struct RaFoie_80238828 {
    u8 pad0[0x20];
    u8 origin[0xC];
    u8 pad2c[0x68 - 0x2C];
    s32 age;
    u8 pad6c[0x78 - 0x6C];
    s16 level;
    s16 band;
    u8 target[0xC];
};

struct Damage_802386F8 { s32 kind; f32 power; };

struct VBase_802386F8 { char pad[0x18]; };

struct VObj_802386F8 : VBase_802386F8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual s32 m21(s32, Damage_802386F8, s32, s32, s32, void *);
};

extern "C" {
void run_task__10TTecRaFoieFv(TTecRaFoie *arg0);
s32 play_sound_effect(s32, void *, s32, s32);
extern s32 tl_particle;
s32 __ct__7TObjectFP7TObject(void *, void *);
u8 *create_fire_explosion_effect(u8 *arg0, s32 *arg1, s16 arg2, s32 arg3, f32 farg0);
void copy_technique_target_list(void *, void *);
void clear_target_cursor_list(void *);
}

u8 *create_rafoie_explosion(u8 *arg0, s32 *arg1, s16 arg2, s16 arg3, s32 arg4, f32 farg0);
u8 *create_rafoie_explosion(u8 *arg0, s32 *arg1, s16 arg2, s16 arg3, s32 arg4, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_802384E0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802384E0, spC) == 0x4) ? 1 : -1];
    Stack_802384E0 stack;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg4);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804CCB28.value;
    ((TUnk_804CCB28 *)arg0)->m_20 = arg2;
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

u8 *create_fire_explosion_effect(u8 *arg0, s32 *arg1, s16 arg2, s32 arg3, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_802385EC, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802385EC, spC) == 0x4) ? 1 : -1];
    Stack_802385EC stack;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg3);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__13TUnk_804CCB28.value;
    ((TUnk_804CCB28 *)arg0)->m_20 = arg2;
    *(s16 *)((s8 *)arg0 + 0x22) = 0;
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

void TTecRaFoie::vfunc_6(void *target_arg) {
    u8 *self = (u8 *)this;
    u8 *target = (u8 *)target_arg;
    Damage_802386F8 d;
    d.kind = 1;
    d.power = *(f32 *)(self + 0x88);
    ((VObj_802386F8 *)target)->m21(*(s32 *)(self + 0x1C), d, *(s32 *)(self + 0xB8), 2, -1, self);
}

void TTecRaFoie::render() {  }

void run_task__10TTecRaFoieFv(TTecRaFoie *tec_ra_foie) {
    u32 entity;
    if ((u32) tec_ra_foie->m_e8 == 0U) {
        tec_ra_foie->queue_destruction();
        return;
    }
    tec_ra_foie->source = find_entity_by_id(tec_ra_foie->m_b4);
    if ((u32) tec_ra_foie->source == 0U) {
        tec_ra_foie->queue_destruction();
        return;
    }
    if ((s32) tec_ra_foie->m_148 == 1) {
        tec_ra_foie->update_detonation((u8 *)tec_ra_foie + 0x7C);
        return;
    }
    if ((s32) tec_ra_foie->m_ec == 0) {
        tec_ra_foie->queue_destruction();
        return;
    }
    entity = find_entity_by_id(tec_ra_foie->m_f0);
    if ((TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
        tec_ra_foie->update_detonation((void *)(entity + 0x2FC));
    }
}

void TTecRaFoie::update_detonation(void *arg1) {
    RaFoie_80238828 *self = (RaFoie_80238828 *)this;
    void *p;
    s32 h;

    VecCopy((Vec *)self->origin, (const Vec *)(VecCopy((Vec *)((Vec *)self->target), (const Vec *)((const Vec *)arg1))));
    self->age++;
    if (self->age != 10) {
        return;
    }
    p = TObject::operator new(0x64);
    if (p != NULL) {
        create_rafoie_explosion((u8 *)p, (s32 *)self->target, self->band, 10, tl_particle, (f32)self->level);
    }
    switch (self->band) {
    case 0:
        h = play_sound_effect(0x4002A803, self->target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A803, self->target, 0, 0);
        break;
    case 2:
    case 3:
        h = play_sound_effect(0x4002A803, self->target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    case 4:
        h = play_sound_effect(0x4002A803, self->target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    case 5:
        h = play_sound_effect(0x4002A803, self->target, 0, 0);
        if (h >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
    ((TUnk_804CC148 *)self)->apply_technique_to_area_targets();
    ((TObject *)self)->queue_destruction();
}

void TTecRaFoie::create(void *origin, void *pos, void *level) {
    new TTecRaFoie((s32)this, (Vec *)origin, (Vec *)pos, (s32)level);
}

void TTecRaFoie::create_ex(void *origin, void *targets, void *level) {
    new TTecRaFoie((s32)this, (Vec *)origin, (TargetCursorList *)targets, (s32)level);
}

TTecRaFoie::~TTecRaFoie() {

}
typedef struct RecoveredFields_80238D10_arg0 RecoveredFields_80238D10_arg0;

#pragma push
#pragma opt_common_subs off
TTecRaFoie::TTecRaFoie(s32 source, Vec *origin, Vec *pos, s32 level) : TUnk_804CC148(source, origin, pos, level) {
    ((TObjPlayer *)&m_ec)->construct_target_cursor_records();
    m_name = TTecRaFoie_class_name;
    calc_area_parameters();
    clear_target_cursor_list(&m_ec);
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

TTecRaFoie::TTecRaFoie(s32 source, Vec *origin, TargetCursorList *list, s32 level) : TUnk_804CC148(source, origin, origin, level) {
    ((TObjPlayer *)&m_ec)->construct_target_cursor_records();
    m_name = TTecRaFoie_class_name;
    calc_area_parameters();
    m_148 = 0;
    copy_technique_target_list(&m_ec, list);
    if (this->source != 0) {
        m_b4 = get_entity_id((void *)this->source);
    }
    if (m_e8 != NULL) {
        m_e8->bodies->radius = m_90;
    }
    vfunc_8(0);
    vfunc_9();
}

