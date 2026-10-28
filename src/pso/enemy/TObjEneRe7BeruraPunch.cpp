#include "types.h"
#include "pso/enemy/TObjEneDD_800BA138.h"
#include "pso/enemy/TObjEneRe7BeruraPunch_80095E18.h"
#include "pso/enemy/TObjEneRe7BeruraPunch.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/misc/TNowLoading.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 is_player_entity_id();
void *find_entity_by_id(u16 id);
s32 apply_hit_if_active__13TUnk_804928CCFPvPf();
f32 calc_boss4_scale__10TObjPlayerFi();
u16 get_entity_id(void *);

int TObjEneRe7BeruraPunch::is_patrol_active() { return (*(u32 *)&this->m_b0 >> 2) & 0x1; }

void TObjEneRe7BeruraPunch__vt20(TObjEneRe7BeruraPunch *ene_re7_berura_punch, s32 target) {
    s32 entity;

    apply_hit_if_active__13TUnk_804928CCFPvPf();
    if (TObjEneDD::check_v2_mode() != 0) {
        get_entity_id((void *)target);
        if (is_player_entity_id() != 0) {
            entity = (s32)find_entity_by_id(ene_re7_berura_punch->m_b0);
            if ((entity != 0) && (calc_boss4_scale__10TObjPlayerFi() < 0.1f)) {
                TObjEneDD__sub_800BA438(entity, (u8 *)target);
            }
        }
    }
}

}

struct VBase_14_c1c33b { char pad[0x14]; };

struct VObj_14_c1c33b : VBase_14_c1c33b {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

struct Stack_80096030 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Pair_80096150 { s32 a; s32 b; };

extern "C" {

u8 * csnVector(s32, s32, s32);
void *find_entity_by_id(u16 id);
s32 TObjEneRe7Berura__sub_80094D98();

void TObjEneRe7Berura__sub_80094C68(TObjEneRe7Berura *self);
s32 refresh_collision_body_centers__13TUnk_804AF8A0Fv(void *, void *, f32, f32);
extern Pair_80096150 lbl_80439F28[];

struct VObjHang_80095EA0 {
    char pad[0x14];
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
};

f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 post_translate_matrix(void *);
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 defer_render__7TObjectFv(void *);

extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void TObjEneRe7BeruraPunch::render() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;

    if ((s32) this->m_b4 != 0) {
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        if ((s32) this->m_b4 == 2) {
            ((VObjHang_80095EA0 *)(arg0 + 0xF8))->m6();
            if (defer_render__7TObjectFv(arg0) != 0) {
                model_render_flags = saved_model_render_flags;
                return;
            }
        }
        ((TObjEneDD *)(arg0 + 0x38))->draw_oriented_shadow((s32)(arg0 + 0xE8), 0, (u32)0);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        translate_matrix(0, 0.0f, *(f32 *)&this->unk_CC, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        temp_f1 = this->m_f4;
        scale_matrix(0, temp_f1, temp_f1, 1.0f);
        TObjEneRe7Berura::init_part(this->m_b8);
        pop_matrix();
        if ((s32) this->m_b4 == 2) {
            ((VObjHang_80095EA0 *)(arg0 + 0xF8))->m7();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
    }
}

// 10.0f keeps its data symbol: declared here, defined after its first use so it lands in pool order.
extern const f32 TObjEneRe7BeruraPunch__data_805D97A0[1];

#pragma push
#pragma fp_contract on
void TObjEneRe7BeruraPunch::update_velocity_and_snap() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_14_c1c33b *)(arg0 + (248)))->m4() != 0) {
        this->m_b4 = 0;
    }
    *(f32 *)&this->m_dc = (f32) ((0.2f * (TObjEneRe7BeruraPunch__data_805D97A0[0] * *(f32 *)&this->unk_BC)) + *(f32 *)&this->m_dc);
    this->m_e4 = (f32) ((0.2f * (TObjEneRe7BeruraPunch__data_805D97A0[0] * *(f32 *)&this->unk_C4)) + this->m_e4);
    ((TObjEneRe7BeruraPunch *)arg0)->snap_to_ground();
}
#pragma pop

__declspec(section ".sdata2") const f32 TObjEneRe7BeruraPunch__data_805D97A0[1] = {10.0f};

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma fp_contract on
void TObjEneRe7BeruraPunch::update_flight() {
    typedef char sp8_offset[(offsetof(Stack_80096030, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80096030, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80096030, sp10) == 0x8) ? 1 : -1];
    Stack_80096030 stack;
    s32 var_r31;
    u8 *temp_r3;
    this->m_f4 += 0.15f;
    if (this->m_f4 > 2.0f) {
        this->m_f4 = (f32) 2.0f;
    }
    var_r31 = 0;
    this->m_114 += TObjEneRe7BeruraPunch__data_805D97A0[0];
    stack.sp8 = (TObjEneRe7BeruraPunch__data_805D97A0[0] * *(f32 *)&this->unk_BC) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    stack.spC = *(f32 *)&this->unk_E0;
    stack.sp10 = (TObjEneRe7BeruraPunch__data_805D97A0[0] * *(f32 *)&this->unk_C4) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    temp_r3 = (u8 *)(csnVector((s32) (((u8 *)this) + 0xDC), (s32) &stack.sp8, 0x88E0));
    if (temp_r3 != NULL) {
        var_r31 = 1;
        *(f32 *)&this->m_dc = (f32) **(f32 **)((s8 *)temp_r3 + 4);
        *(f32 *)&this->m_dc = (f32) **(f32 **)((s8 *)temp_r3 + 4);
    } else {
        *(f32 *)&this->m_dc = stack.sp8;
        this->m_e4 = stack.sp10;
    }
    this->snap_to_ground();
    if ((var_r31 != 0) || (sub_80096150() != 0) || (this->m_114 > this->m_c8)) {
        this->m_b4 = 2;
        if (find_entity_by_id(this->m_b0) != NULL) {
            TObjEneRe7Berura__sub_80094D98();
        }
    }
}
#pragma pop

s32 TObjEneRe7BeruraPunch::sub_80096150() {
    u8 *entity;
    void *temp_r4_2;
    entity = (u8 *)find_entity_by_id(this->m_b0);
    *(f32 *)((s8 *)this->m_a4 + 4) = *(f32 *)&this->unk_CC;
    *(f32 *)((s8 *)this->m_a4 + 0x30) = *(f32 *)&this->unk_CC;
    temp_r4_2 = this->m_a4;
    *(f32 *)((s8 *)temp_r4_2 + 0x34) = 1.8f * (3.0f * this->m_f4);
    refresh_collision_body_centers__13TUnk_804AF8A0Fv(this, temp_r4_2, 3.0f, 1.8f);
    ((TObjPlayer *)this)->update_enemy_collision_flags();
    temp_r4_2 = this->m_a4;
    if ((*(s32 *)((s8 *)temp_r4_2 + 0x18) | *(s32 *)((s8 *)temp_r4_2 + 0x44)) & 0x200000) {
        return 1;
    }
    if (entity != 0) {
        ((TObjEneRe7Berura *)entity)->reload_stats_from_tables();
    }
    Pair_80096150 p = lbl_80439F28[0];
    if (TObjEneDD::check_v2_mode() != 0) {
        p.b &= ~2;
    }
    this->call_vt16_with_default((void *)&p, (void *)(*(s32 *)&this->_padD8));
    if (entity != 0) {
        TObjEneRe7Berura__sub_80094C68((TObjEneRe7Berura *)entity);
    }
    return 0;
}

void TObjEneRe7BeruraPunch::launch(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    u8 *entity;

    this->m_b8 = arg1;
    VecCopy((Vec *)&this->m_dc, (const Vec *)arg2);
    ((TObjEneRe7BeruraPunch *)arg0)->snap_to_ground();
    entity = (u8 *)find_entity_by_id(this->m_b0);
    if (entity != NULL) {
        this->rotation_y = (s32) *(s32 *)((s8 *)entity + 0x60);
    } else {
        this->rotation_y = 0;
    }
    *(f32 *)&this->unk_BC = sin_table_lookup(this->rotation_y);
    this->m_c0 = (f32) 0.0f;
    *(f32 *)&this->unk_C4 = cos_table_lookup(this->rotation_y);
    this->m_c8 = (f32) 3e+02f;
    ((TObjEneRe7BeruraPunch *)arg0)->reset();
    this->m_b4 = 1;
}

}

struct Stack_80096300
{
  s32 sp8;
  f32 spC;
};

struct RecoveredGlobal_80096750_lbl_8048F930 {
    s32 value;
    u8 remaining[0x54];
};

struct RecoveredGlobal_80096750___vt__21TObjEneRe7BeruraPunch {
    s32 value;
    u8 remaining[0x5C];
};

struct Vec_8009640C { f32 x, y, z; };

struct Ang_8009640C { s32 x, y, z; };

extern "C" {
s32 *csnVecterUnder(s32 origin, s32 mask);

u16 get_entity_id(void *);
extern RecoveredGlobal_80096750_lbl_8048F930 TObjEneRe7BeruraPunch__collision_body_templates;
extern s32 __vt__21TObjEneRe7BeruraPunch[];
extern s32 lbl_805D2990;
u8 *TObjEneRe7BeruraPunch__ct(u8 *arg0, s32 arg1, s32 arg2);
void queue_destruction__7TObjectFv(void *);
void *create_particle_emitter(void *pos, s32 id);
void *find_entity_by_id(u16 id);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void vec3_add_to(void *, void *);

struct BeruraBase_800962F4 { char pad[0x14]; };
struct BeruraObj_800962F4 : BeruraBase_800962F4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
};
struct EneBBase_800962F4 { char pad[0x14]; };
struct EneBVObj_800962F4 : EneBBase_800962F4 {
    virtual void m0();
    virtual void m1(s32);
};

void TObjEneRe7BeruraPunch__sub_800962F4(void* p);
void *__dt__21TObjEneRe7BeruraPunchFv(void *arg0, s16 arg1);
s32 delete_buffer__12TBoss8DragonFis(s32 arg0, s16 arg1);
u8 *TBoss8Dragon__sub_800BC5EC(u8 *arg0, s32 arg1);
void *__dt__13TUnk_80490470Fv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);
s32 fill_value_array(s32);

void TObjEneRe7BeruraPunch__sub_800962F4(void* p) { *(s32*)((char*)p + 0xb4) = 0; }

typedef struct Stack_80096300 Stack_80096300;
void TObjEneRe7BeruraPunch::snap_to_ground() {
    u8 *arg0 = (u8 *)this;
  Stack_80096300 stack;
  f32 new_var;
  u8 *temp_r3;
  VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0xDC));
  stack.spC = 2e+01f;
  temp_r3 = (u8 *)csnVecterUnder((s32)&stack.sp8, 0x16EF);
  if (temp_r3 != 0)
  {
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(*((s32 *) (((s8 *) temp_r3) + 4))));
    VecCopy((Vec *)(arg0 + 0xE8), (const Vec *)((*((s32 *) (((s8 *) temp_r3) + 4))) + 0xC));
  }
  else
  {
    *((f32 *) (((s8 *) arg0) + 0x38)) = (f32) (*((f32 *) (((s8 *) arg0) + 0xDC)));
    *((f32 *) (((s8 *) arg0) + 0x40)) = this->m_e4;
  }
  new_var = *((f32 *) (((s8 *) arg0) + 0xE0));
  *((f32 *) (((s8 *) arg0) + 0xCC)) = (f32) (new_var - (*((f32 *) (((s8 *) arg0) + 0x3C))));
  if ((*((f32 *) (((s8 *) arg0) + 0xCC))) < TObjEneRe7BeruraPunch__data_805D97A0[0])
  {
    *((f32 *) (((s8 *) arg0) + 0xE0)) = (f32) (TObjEneRe7BeruraPunch__data_805D97A0[0] + (*((f32 *) (((s8 *) arg0) + 0x3C))));
    *((f32 *) (((s8 *) arg0) + 0xCC)) = (f32) TObjEneRe7BeruraPunch__data_805D97A0[0];
  }
  if ((new_var && new_var) && new_var)
  {
  }
}

void TObjEneRe7BeruraPunch::reset() {
    u8 *arg0 = (u8 *)this;
    fill_value_array(*(s32 *)&this->_padD8);
    this->m_f4 = (f32) 1.0f;
    ((BeruraObj_800962F4*)(arg0 + 0xF8))->m2();
    *(s32 *)&this->unk_118 = 0;
    this->m_114 = (f32) 0.0f;
}

void TObjEneRe7BeruraPunch::run_task() {
    u8 *arg0 = (u8 *)this;
    Ang_8009640C ang;
    Vec_8009640C v;
    f32 s;
    f32 c;
    if (find_entity_by_id(this->m_b0) == 0U || all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    switch (*(s32 *)&this->m_b4) {
    case 0:
        break;
    case 1:
        ((TObjEneRe7BeruraPunch *)arg0)->update_flight();
        break;
    case 2:
        ((TObjEneRe7BeruraPunch *)arg0)->update_velocity_and_snap();
        break;
    }
    if (*(s32 *)&this->m_b4 == 1) {
        ang.x = 0;
        ang.y = this->rotation_y + 0x4000;
        ang.z = -0x4000;
        s = -sin_table_lookup(this->rotation_y);
        c = -cos_table_lookup(this->rotation_y);
        if (*(void * *)&this->m_d0 == NULL) {
            *(void * *)&this->m_d0 = create_particle_emitter(&this->position, 0xDD);
            if (*(void * *)&this->m_d0 != NULL) {
                ((TBoss4Type2 *)(*(void * *)&this->m_d0))->set_flags(2);
                ((TParticleCtrl *)(*(void * *)&this->m_d0))->enable();
            }
        } else {
            v.x = 4e+01f * s;
            v.y = 3.0f;
            v.z = 4e+01f * c;
            vec3_add_to(&v, (u8 *)&this->m_dc);
            ((TNowLoading *)(*(void * *)&this->m_d0))->copy_pos(&v);
            ((TBoss4Type2 *)(*(void * *)&this->m_d0))->copy_vec3(&ang);
        }
        if (*(void * *)&this->m_d4 == NULL) {
            *(void * *)&this->m_d4 = create_particle_emitter(&this->position, 0x150);
            if (*(void * *)&this->m_d4 != NULL) {
                ((TBoss4Type2 *)(*(void * *)&this->m_d4))->set_flags(2);
                ((TParticleCtrl *)(*(void * *)&this->m_d4))->enable();
            }
        } else {
            v.x = (-2e+01f) * s;
            v.y = 5.0f;
            v.z = (-2e+01f) * c;
            vec3_add_to(&v, (u8 *)&this->m_dc);
            ((TNowLoading *)(*(void * *)&this->m_d4))->copy_pos(&v);
            ((TBoss4Type2 *)(*(void * *)&this->m_d4))->copy_vec3(&ang);
        }
    } else {
        if (*(void * *)&this->m_d0 != NULL) {
            ((TParticleCtrl *)(*(void * *)&this->m_d0))->enable();
        }
        if (*(void * *)&this->m_d4 != NULL) {
            ((TParticleCtrl *)(*(void * *)&this->m_d4))->enable();
        }
    }
}

void *__dt__21TObjEneRe7BeruraPunchFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__21TObjEneRe7BeruraPunch;
        if (*(void **)((s8 *)arg0 + 0xD0) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xD0)); ((TObjEneRe7BeruraPunch *)arg0)->m_d0 = 0; }
        if (*(void **)((s8 *)arg0 + 0xD4) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xD4)); ((TObjEneRe7BeruraPunch *)arg0)->m_d4 = 0; }
        if (*(void **)((s8 *)arg0 + 0xD8) != NULL) { delete_buffer__12TBoss8DragonFis((s32)(*(void **)((s8 *)arg0 + 0xD8)), 1); *(s32 *)((s8 *)arg0 + 0xD8) = 0; }
        __dt__13TUnk_80490470Fv((s8 *)arg0 + 0xF8, -1);
        ((TUnk_804928CC *)arg0)->destroy_enemy_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TObjEneRe7BeruraPunch::init() {
    u8 *arg0 = (u8 *)this;
    s32 var_r0;
    u32 var_a;

    this->m_b4 = 0;
    this->m_b8 = 0;
    *(f32 *)&this->unk_BC = (f32) 0.0f;
    this->m_c0 = (f32) 0.0f;
    *(f32 *)&this->unk_C4 = (f32) 0.0f;
    this->m_c8 = (f32) 0.0f;
    *(f32 *)&this->unk_CC = (f32) 0.0f;
    this->m_d0 = 0;
    this->m_d4 = 0;
    var_a = (int)::operator new(0x10);
    var_r0 = var_a;
    if (var_r0 != 0) {
        var_r0 = (s32)TBoss8Dragon__sub_800BC5EC((u8 *)var_a, 9);
    }
    *(s32 *)&this->_padD8 = var_r0;
    ((EneBVObj_800962F4*)(arg0 + 0xF8))->m1(0);
    reset();
}
typedef char RecoveredGlobal_80096750_lbl_8048F930_size[sizeof(RecoveredGlobal_80096750_lbl_8048F930) == 0x58 ? 1 : -1];
typedef char RecoveredGlobal_80096750___vt__21TObjEneRe7BeruraPunch_size[sizeof(RecoveredGlobal_80096750___vt__21TObjEneRe7BeruraPunch) == 0x60 ? 1 : -1];
u8 *TObjEneRe7BeruraPunch__ct(u8 *ene_re7_berura_punch, s32 arg1, s32 arg2) {
    ((TUnk_804928CC *)ene_re7_berura_punch)->init_instance((void *)arg1, (void *)arg2, &TObjEneRe7BeruraPunch__collision_body_templates.value, (void *)2);
    *(s32 **)((s8 *)ene_re7_berura_punch + 0x18) = &(*(RecoveredGlobal_80096750___vt__21TObjEneRe7BeruraPunch *)&__vt__21TObjEneRe7BeruraPunch).value;
    ((TUnk_80490470 *)(ene_re7_berura_punch + 0xF8))->init_vtable_and_field18();
    *(s32 *)((s8 *)ene_re7_berura_punch + 0) = (s32) lbl_805D2990;
    ((TObjEneRe7BeruraPunch *)ene_re7_berura_punch)->m_b0 = get_entity_id((void *)arg2);
    ((TObjEneRe7BeruraPunch *)ene_re7_berura_punch)->init();
    return ene_re7_berura_punch;
}

}
