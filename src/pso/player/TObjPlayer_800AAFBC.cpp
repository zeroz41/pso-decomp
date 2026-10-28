#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/player/TUnk_80491460.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TUnk_80491478.h"

#include "pso/enemy/TObjEneDubchik.h"
#include "pso/enemy/TObjEneShark.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

struct RecoveredGlobal_800ABA9C_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_800ABA9C_lbl_8058D490_size[sizeof(RecoveredGlobal_800ABA9C_lbl_8058D490) == 0x30 ? 1 : -1];

struct RecoveredGlobal_800ABA9C_lbl_8058D490;
typedef struct Vec_800AB31C {
    f32 x, y, z;
} Vec_800AB31C;

typedef struct Rot_800AB31C {
    s32 x, y, z;
} Rot_800AB31C;

typedef struct Obj_800AB31C {
    u8 pad0[0x18];
    void *vptr;
    Vec_800AB31C pos;
    Vec_800AB31C pos2;
    u8 mtx34[0x58 - 0x34];
    f32 f58;
    s32 f5C;
    s32 f60;
    s32 f64;
    s32 f68;
} Obj_800AB31C;

typedef struct Vec_800ABB38 {
    f32 x, y, z;
} Vec_800ABB38;

struct VBase_800ABB38 { char pad[0x18]; };

struct VObj_800ABB38 : VBase_800ABB38 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_800ABB38 *, Vec_800ABB38 *);
};

typedef struct Obj_800ABB38 {
    u8 pad0[0x38];
    Vec_800ABB38 pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C4 - 0xC4];
    VObj_800ABB38 *effs[2];
} Obj_800ABB38;

typedef struct Pair_800AB0EC {
    s32 a;
    f32 b;
} Pair_800AB0EC;

struct VBase_800AB0EC { char pad[0x18]; };

struct VObj_800AB0EC : VBase_800AB0EC {
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
    virtual s32 m21(s32, Pair_800AB0EC *, s32, s32, s32);
};

typedef struct Obj_800AB0EC {
    u8 pad0[0x1C];
    u8 pos[0x64 - 0x1C];
    s32 f64;
    s32 f68;
} Obj_800AB0EC;

struct Vec_800AB4F4 { f32 x, y, z; };

struct Vec_800AB7A0 { f32 x, y, z; };

struct Arr_800AB7A0 { u8 pad[0x3D4]; Vec_800AB7A0 arr[4]; };

struct VBase_14_800ABDD8
{
  char pad[0x14];
};

struct VObj_14_800ABDD8 : VBase_14_800ABDD8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
};

struct VBase_18_800ABDD8
{
  char pad[0x18];
};

struct VObj_18_800ABDD8 : VBase_18_800ABDD8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};

struct Fade_800ABDD8 : VBase_14_800ABDD8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    u32 x18;
};

struct Owner_800ABDD8
{
  u8 pad[0x3CC];
  Fade_800ABDD8 fades[4];
};

struct Vec_800ABDD8
{
  f32 x;
  f32 y;
  f32 z;
};

extern "C" {
void obj_setFlags30(void *, u32);
s32 post_translate_matrix(void *);
s32 scale_matrix(s32, f32, f32, f32);
void draw_chunk_object(void *child);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
extern s32 lbl_805D5094;
extern s32 model_render_flags;

void __dl__7TObjectFPv(void *);
void queue_destruction__7TObjectFv(void *);
extern s32 lbl_80491478[];
s32 VecCopy__FP3VecPC3Vec(void *, void *);
u32 csnVector(void *, void *, int);
void *get_player_by_client_id(s32 i);
s32 vec3_add_to(void *, void *);
extern const f32 lbl_805D9B5C;
extern const f32 lbl_805D9B60;
f32 fabs_float(f32);
extern const f32 lbl_805D9B10;
s32 rotate_vector_by_matrix(int, void *, void *);
s32 push_matrix_from(void *);
extern RecoveredGlobal_800ABA9C_lbl_8058D490 identity_matrix;
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
extern Vec_800AB31C lbl_8043ACE0[];
extern s32 __vt__13TUnk_80491460[];
extern void *tl_06;
extern const f32 lbl_805D9B64;
void *spawn_particle_effect(void *pos, s32 id);
extern Pair_800AB0EC lbl_8043ACEC[];
extern const f32 lbl_805D9B58;
f32 newton_sqrtf();
s32 project_actor_to_ground(void *, Vec_800AB4F4 *, int);
s32 subtract_vector(void *, void *);

s16 get_entity_id(void *);
u8 *csnLookAt(void *, Vec_800AB7A0 *);
u32 TObjPlayer__sub_800A4204(void *, void *, void *, void *, int);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, void *);
void *__nw__7TObjectFUl(int);
extern s32 player_sub_800ab7a0_id_table[];
extern void *lbl_805D5090;

u8 *TObjPlayer__sub_800AB7A0(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4);
void TObjPlayer__sub_800AAFF0(void* p, f32 v);
void __dt__7TObjectFv(void *, int);

extern s32 lbl_805D5098;

void TObjEneDubchik::init_level_stats(s32 arg1) {
    s32 var_r0;

    *(s32 *)&this->model = (s32) *(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D5090 + 0x42C)) + 8);
    if (arg1 == 0) {
        var_r0 = *(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D5090 + 0x42C)) + 0xC);
    } else {
        var_r0 = lbl_805D5098;
    }
    this->texture_id = var_r0;
}

void TObjPlayer__sub_800AAFF0(void* p, f32 v) { *(f32*)((char*)p + 0x8) = v; }

void TObjPlayer::clear_flag_04000000() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;
    temp_r6 = (u8 *)this->m_a4;
    *(s32 *)((s8 *)temp_r6 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r6 + 0x18) & 0xF5FFFFFF);
    ((TUnk_804B9870 *)arg0)->obj_clearFlags30(0x04000000U);
}

void TObjPlayer::set_invuln_flags() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    temp_r5 = (u8 *)this->m_a4;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 0x0A000000);
    obj_setFlags30(arg0, 0x04000000U);
}

s32 TObjEneDubchik::sub_800AB068() {
    u8 *arg0 = (u8 *)this;
  u8 *new_var;
  f32 temp_f31;
  ;
  if ((fabs_float((*((f32 *) (((s8 *) arg0) + 0x38))) - (*((f32 *) (((s8 *) arg0) + 0x44)))) + fabs_float((*((f32 *) (((s8 *) arg0) + 0x40))) - (*((f32 *) (((s8 *) arg0) + 0x4C))))) > lbl_805D9B10)
  {
    VecCopy__FP3VecPC3Vec((void *) ((new_var = arg0) + 0x38), (u8 *)&this->m_44);
    return 1;
  }
  return 0;
}

s32 TUnk_80491460::try_hit_target(int arg1) {
    u8 *e = (u8 *)arg1;
    Obj_800AB0EC *o = (Obj_800AB0EC *)this;
    if (e != NULL && !(*(s32 *)(e + 0x30) & 0xA00) && !(xz_distance_squared((Vec *)o->pos, (Vec *)(e + 0x2FC)) > lbl_805D9B58)) {
        Pair_800AB0EC tmp = lbl_8043ACEC[0];
        tmp.b = (f32)this->m_68;
        Pair_800AB0EC arg = tmp;
        ((VObj_800AB0EC *)e)->m21(o->f64, &arg, 0, -1, -1);
        spawn_particle_effect(e + 0x2FC, 0xFB);
        queue_destruction__7TObjectFv(o);
    }
}

void TUnk_80491460::run_task() {
  s32 var_r31;
  u8 *now_loading;
  s32 new_var;
    u8 *arg0 = (u8 *)this;
  vec3_add_to((u8 *)&this->unk_1C, arg0 + 0x34);
  ((TUnk_80491460 *)arg0)->m_60 = (s32) ((((TUnk_80491460 *)arg0)->m_60) + 1);
  if (!((((TUnk_80491460 *)arg0)->m_60) & 3))
  {
    if (csnVector(arg0 + 0x28, (u8 *)&this->unk_1C, -1) != 0U)
    {
      queue_destruction__7TObjectFv(arg0);
      return;
    }
    VecCopy__FP3VecPC3Vec(arg0 + 0x28, (u8 *)&this->unk_1C);
    goto block_4;
  }
  block_4:
  now_loading = (u8 *) (*((u8 **) (((s8 *) arg0) + 0x5C)));
  if (now_loading != 0)
  {
    ((TNowLoading *)now_loading)->copy_pos((u8 *)&this->unk_1C);
  }
  ((TUnk_80491460 *)arg0)->m_58 = (f32) ((((TUnk_80491460 *)arg0)->m_58) + lbl_805D9B5C);
  if ((((TUnk_80491460 *)arg0)->m_58) >= lbl_805D9B60)
  {
    queue_destruction__7TObjectFv(arg0);
    return;
  }
  var_r31 = 0;
  do
  {
    if (!arg0)
    {
    }
    new_var = (s32)get_player_by_client_id(var_r31);
    ((TUnk_80491460 *)arg0)->try_hit_target((int)((int) new_var));
    var_r31 += 1;
  }
  while (var_r31 < 0xC);
}

void *TObjPlayer::dt(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = __vt__13TUnk_80491460;
        if ((void *)this->m_5c != NULL) { queue_destruction__7TObjectFv((void *)this->m_5c); }
        __dt__7TObjectFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

}
TUnk_80491460::TUnk_80491460(void *arg1, s32 arg2, s32 arg3, s32 arg4) : TObject((TObject *)tl_06) {
    VecCopy__FP3VecPC3Vec(&((Obj_800AB31C *)this)->pos, arg1);
    VecCopy__FP3VecPC3Vec(&((Obj_800AB31C *)this)->pos2, arg1);
    ((Obj_800AB31C *)this)->f58 = lbl_805D9B64;
    push_matrix_from(&identity_matrix);
    Vec_800AB31C v = lbl_8043ACE0[0];
    rotate_matrix_y(0, arg2);
    rotate_vector_by_matrix(0, &v, ((Obj_800AB31C *)this)->mtx34);
    pop_matrix();
    ((Obj_800AB31C *)this)->f64 = arg3;
    Rot_800AB31C r;
    r.x = 0;
    r.y = arg2 + 0x4000;
    r.z = 0x4000;
    ((Obj_800AB31C *)this)->f5C = (s32)spawn_particle_effect_with_rotation(arg1, &r, 0x6D, 2);
    ((Obj_800AB31C *)this)->f60 = 0;
    ((Obj_800AB31C *)this)->f68 = arg4;
}


void TObjPlayer::cancel_action() {
    if (get_action_priority() != 1) {
        if ((u32) *(u32 *)&this->m_d0 != 0U) {
            ((TObjPlayer *)(*(u32 *)&this->m_d0))->set_cancel_flag();
        }
        *(s16 *)((s8 *)this + 0xAE) = 2;
    }
}
s32 TObjPlayer::get_action_priority() {
    return (s32)((u32)__cntlzw(3 - *(s16 *)((s8 *)this + 0xAE)) >> 5);
}
void TObjPlayer::draw_model_no_fog() {
    TObjFish::set_global_param(lbl_805D5094);
    TObjFish::set_global_param((*(s32 *)&this->action_table));
    push_matrix();
    post_translate_matrix((u8 *)&this->unk_F0);
    rotate_matrix_y(0, (*(s32 *)&this->m_c0));
    scale_matrix(0, 1.3f, 1.3f, 1.3f);
    model_render_flags &= 0xFFFFFBFF;
    draw_chunk_object((void *)(*(s32 *)&this->m_c8));
    pop_matrix();
}

#pragma push
#pragma fp_contract on
void TUnk_80491478::run_task() {
    f32 t;
    f32 var_f1;
    u8 *arg0 = (u8 *)this;
    switch (((TUnk_80491478 *)arg0)->m_ae) {
    case 0: {
        Vec_800AB4F4 v = *(Vec_800AB4F4 *)(arg0 + 0xF0);
        v.x += *(f32 *)((s8 *)arg0 + 0xB0);
        v.z += *(f32 *)((s8 *)arg0 + 0xB8);
        v.y += 5.0f;
        if (project_actor_to_ground((void *) arg0, &v, 0) == 1) {
            ((TUnk_80491478 *)arg0)->m_f0 = v.x;
            ((TUnk_80491478 *)arg0)->m_f8 = v.z;
            if (*(f32 *)((s8 *)arg0 + 0xF4) < v.y) {
                *(f32 *)((s8 *)arg0 + 0xF4) = v.y;
                ((TUnk_80491478 *)arg0)->m_b4 = 0.6f * fabs_float(((TUnk_80491478 *)arg0)->m_b4);
            }
            if ((v.y - ((TUnk_80491478 *)arg0)->m_e8) > 2.0f) {
                ((TUnk_80491478 *)arg0)->m_ae = 1;
            } else {
                ((TUnk_80491478 *)arg0)->m_e8 = v.y;
            }
        }
        if (xz_distance_squared((Vec *)&this->m_f0, (Vec *)&this->unk_DC) >= *(f32 *)((s8 *)arg0 + 0xEC) * *(f32 *)((s8 *)arg0 + 0xEC)) {
            ((TUnk_80491478 *)arg0)->m_ae = 1;
        }
    }
    case 1:
        *(f32 *)((s8 *)arg0 + 0xF4) += ((TUnk_80491478 *)arg0)->m_b4;
        ((TUnk_80491478 *)arg0)->m_b4 += -0.10888889f;
        if (*(f32 *)((s8 *)arg0 + 0xF4) < ((TUnk_80491478 *)arg0)->m_e8) {
            *(f32 *)((s8 *)arg0 + 0xF4) = ((TUnk_80491478 *)arg0)->m_e8;
            ((TUnk_80491478 *)arg0)->m_b4 = 0.0f;
        }
        break;
    case 2:
        VecCopy__FP3VecPC3Vec((u8 *)&this->unk_B0, *(void **)((s8 *)arg0 + 0xCC));
        subtract_vector((u8 *)&this->unk_B0, (u8 *)&this->m_f0);
        if (*(f32 *)((s8 *)arg0 + 0xB0) * *(f32 *)((s8 *)arg0 + 0xB0) + *(f32 *)((s8 *)arg0 + 0xB8) * *(f32 *)((s8 *)arg0 + 0xB8) > 25.0f) {
            t = 0.8f / newton_sqrtf();
            ((TUnk_80491478 *)arg0)->m_f0 = *(f32 *)((s8 *)arg0 + 0xB0) * t + ((TUnk_80491478 *)arg0)->m_f0;
            ((TUnk_80491478 *)arg0)->m_f8 = *(f32 *)((s8 *)arg0 + 0xB8) * t + ((TUnk_80491478 *)arg0)->m_f8;
        } else if (fabs_float(((TUnk_80491478 *)arg0)->m_b4) > 5.0f) {
            if (((TUnk_80491478 *)arg0)->m_b4 > 0.0f) {
                var_f1 = 0.8f;
            } else {
                var_f1 = -0.8f;
            }
            *(f32 *)((s8 *)arg0 + 0xF4) += var_f1;
        } else {
            ((TUnk_80491478 *)arg0)->m_ae = 3;
        }
        break;
    case 3:
        VecCopy__FP3VecPC3Vec((u8 *)&this->m_f0, *(void **)((s8 *)arg0 + 0xCC));
        break;
    }
}
#pragma pop

void *TUnk_80491478::destroy_with_particle_cleanup(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_80491478;
        if (*(void * *)&(this->m_d0) != NULL) { queue_destruction__7TObjectFv(*(void * *)&(this->m_d0)); (this->m_d0) = 0; }
        __dt__13TUnk_804AF8A0Fv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

u8 *TObjPlayer__sub_800AB7A0(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4) {
    Vec_800AB7A0 v;
    Vec_800AB7A0 out;
    void *obj;
    u8 *temp_r3;
    s32 t;
    __ct__13TUnk_804AF8A0FP7TObject(arg0, tl_06);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_80491478;
    *(s16 *)((s8 *)arg0 + 0xAC) = arg1;
    *(s16 *)((s8 *)arg0 + 0xD4) = get_entity_id(arg2);
    ((TUnk_80491478 *)arg0)->m_ae = 0;
    t = player_sub_800ab7a0_id_table[arg1];
    ((TUnk_80491478 *)arg0)->m_d8 = arg3;
    ((TUnk_80491478 *)arg0)->m_c8 = (s32)find_model_node(*(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D5090 + 0x42C)) + 0x18), (s32)t);
    *(Vec_800AB7A0 **)((s8 *)arg0 + 0xCC) = &((Arr_800AB7A0 *)arg2)->arr[arg1];
    VecCopy__FP3VecPC3Vec(arg0 + 0xF0, (void *) VecCopy__FP3VecPC3Vec(arg0 + 0xDC, (void *)arg4));
    ((TUnk_80491478 *)arg0)->m_e8 = 3.0f + *(f32 *)((s8 *)arg2 + 0x3C);
    ((s32 (*)(void *, f32)) push_matrix_from)((void *) &identity_matrix, 3.0f);
    v.x = v.y = 0.0f;
    v.z = -2.0f;
    rotate_matrix_y(0, *(s32 *)((s8 *)arg2 + 0x60) + ((arg1 - 1) << 0xD));
    rotate_vector_by_matrix(0, &v, arg0 + 0xB0);
    v.z = *(f32 *)((s8 *)arg0 + 0xEC) = 3e+01f;
    rotate_vector_by_matrix(0, &v, &out);
    vec3_add_to(&out, arg0 + 0xF0);
    temp_r3 = csnLookAt(arg0 + 0xF0, &out);
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)arg0 + 0xEC) = (10.0f > vec_xz_distance((Vec *)(arg0 + 0xF0), *(Vec **)((s8 *)temp_r3 + 4)) - 5.0f) ? 10.0f : vec_xz_distance((Vec *)(arg0 + 0xF0), *(Vec **)((s8 *)temp_r3 + 4)) - 5.0f;
    }
    pop_matrix();
    ((TUnk_80491478 *)arg0)->m_b4 = 0.0f;
    obj = __nw__7TObjectFUl(0x348);
    if (obj != NULL) {
        obj = (void *) TObjPlayer__sub_800A4204(obj, arg0, *(void **)((s8 *)arg0 + 0xCC), arg0 + 0xF0, 0x10);
    }
    *(void **)((s8 *)arg0 + 0xD0) = obj;
    if (*(void **)((s8 *)arg0 + 0xD0) != NULL) {
        ((TObjPlayer *)(*(void **)((s8 *)arg0 + 0xD0)))->clear_counter();
    }
    return arg0;
}

typedef struct Fade_800ABDD8 Fade_800ABDD8;
typedef struct Owner_800ABDD8 Owner_800ABDD8;
typedef struct VBase_14_800ABDD8 VBase_14_800ABDD8;
typedef struct VBase_18_800ABDD8 VBase_18_800ABDD8;
typedef struct VObj_14_800ABDD8 VObj_14_800ABDD8;
typedef struct VObj_18_800ABDD8 VObj_18_800ABDD8;
typedef struct Vec_800ABDD8 Vec_800ABDD8;
#define PSO_VCALL_VObj_18_800ABDD8_m9(_self, _arg0, _arg1, _arg2) (((VObj_18_800ABDD8 *)(_self))->m9((_arg0), (_arg1), (_arg2)))

