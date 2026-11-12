#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/player/TUnk_80491460.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TUnk_80491478.h"

#include "pso/enemy/dubchik/TObjEneDubchik.h"
#include "pso/enemy/shark/TObjEneShark.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/vector.h"

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
extern s32 dubchik_texlist;
extern s32 model_render_flags;

void queue_destruction__7TObjectFv(void *);
s32 VecCopy__FP3VecPC3Vec(void *, void *);
u32 csnVector(void *, void *, int);
void *get_player_by_client_id(s32 i);
s32 vec3_add_to(void *, void *);
extern const f32 lbl_805D9B5C;
extern const f32 lbl_805D9B60;
f32 fabs_float(f32);
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
void *__nw__7TObjectFUl(int);
extern s32 player_sub_800ab7a0_id_table[];
extern void *dubchik_resource;

}

// Written last-to-first: the TU was compiled with deferred codegen, which emits the
// functions (and the vtables, by key function) in reverse definition order.
#pragma defer_codegen on

TUnk_80491478::TUnk_80491478(s32 index, TObjEneDubchik *parent, NJS_TEXLIST *texlist, Vec *offset) : TObjCollidable((TObject *)tl_06) {
    Vec_800AB7A0 v;
    Vec_800AB7A0 out;
    void *obj;
    u8 *temp_r3;
    s32 t;
    part_index = index;
    parent_id = get_entity_id(parent);
    m_ae = 0;
    t = player_sub_800ab7a0_id_table[index];
    m_d8 = texlist;
    m_c8 = find_model_node(*(s32 *)((s8 *)(*(u8 **)((s8 *)dubchik_resource + 0x42C)) + 0x18), t);
    target = &parent->part_offsets[index];
    VecCopy(&pos, VecCopy(&origin, offset));
    m_e8 = 3.0f + parent->position.y;
    ((s32 (*)(void *, f32)) push_matrix_from)((void *) &identity_matrix, 3.0f);
    v.x = v.y = 0.0f;
    v.z = -2.0f;
    rotate_matrix_y(0, parent->rotation_y + ((index - 1) << 0xD));
    rotate_vector_by_matrix(0, &v, unk_B0);
    v.z = range = 3e+01f;
    rotate_vector_by_matrix(0, &v, &out);
    vec3_add_to(&out, &pos);
    temp_r3 = csnLookAt(&pos, &out);
    if (temp_r3 != NULL) {
        range = (10.0f > vec_xz_distance(&pos, *(Vec **)((s8 *)temp_r3 + 4)) - 5.0f) ? 10.0f : vec_xz_distance(&pos, *(Vec **)((s8 *)temp_r3 + 4)) - 5.0f;
    }
    pop_matrix();
    m_b4 = 0.0f;
    obj = __nw__7TObjectFUl(0x348);
    if (obj != NULL) {
        obj = (void *) TObjPlayer__sub_800A4204(obj, this, target, &pos, 0x10);
    }
    m_d0 = (TObject *)obj;
    if (m_d0 != NULL) {
        ((TObjPlayer *)m_d0)->clear_counter();
    }
}

TUnk_80491478::~TUnk_80491478() {
    if (m_d0 != NULL) {
        m_d0->queue_destruction();
        m_d0 = NULL;
    }
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
            ((TUnk_80491478 *)arg0)->pos.x = v.x;
            ((TUnk_80491478 *)arg0)->pos.z = v.z;
            if (((TUnk_80491478 *)arg0)->pos.y < v.y) {
                ((TUnk_80491478 *)arg0)->pos.y = v.y;
                ((TUnk_80491478 *)arg0)->m_b4 = 0.6f * fabs_float(((TUnk_80491478 *)arg0)->m_b4);
            }
            if ((v.y - ((TUnk_80491478 *)arg0)->m_e8) > 2.0f) {
                ((TUnk_80491478 *)arg0)->m_ae = 1;
            } else {
                ((TUnk_80491478 *)arg0)->m_e8 = v.y;
            }
        }
        if (xz_distance_squared(&this->pos, &this->origin) >= ((TUnk_80491478 *)arg0)->range * ((TUnk_80491478 *)arg0)->range) {
            ((TUnk_80491478 *)arg0)->m_ae = 1;
        }
    }
    case 1:
        ((TUnk_80491478 *)arg0)->pos.y += ((TUnk_80491478 *)arg0)->m_b4;
        ((TUnk_80491478 *)arg0)->m_b4 += -0.10888889f;
        if (((TUnk_80491478 *)arg0)->pos.y < ((TUnk_80491478 *)arg0)->m_e8) {
            ((TUnk_80491478 *)arg0)->pos.y = ((TUnk_80491478 *)arg0)->m_e8;
            ((TUnk_80491478 *)arg0)->m_b4 = 0.0f;
        }
        break;
    case 2:
        VecCopy__FP3VecPC3Vec((u8 *)&this->unk_B0, ((TUnk_80491478 *)arg0)->target);
        subtract_vector((u8 *)&this->unk_B0, &this->pos);
        if (*(f32 *)((s8 *)arg0 + 0xB0) * *(f32 *)((s8 *)arg0 + 0xB0) + *(f32 *)((s8 *)arg0 + 0xB8) * *(f32 *)((s8 *)arg0 + 0xB8) > 25.0f) {
            t = 0.8f / newton_sqrtf();
            ((TUnk_80491478 *)arg0)->pos.x = *(f32 *)((s8 *)arg0 + 0xB0) * t + ((TUnk_80491478 *)arg0)->pos.x;
            ((TUnk_80491478 *)arg0)->pos.z = *(f32 *)((s8 *)arg0 + 0xB8) * t + ((TUnk_80491478 *)arg0)->pos.z;
        } else if (fabs_float(((TUnk_80491478 *)arg0)->m_b4) > 5.0f) {
            if (((TUnk_80491478 *)arg0)->m_b4 > 0.0f) {
                var_f1 = 0.8f;
            } else {
                var_f1 = -0.8f;
            }
            ((TUnk_80491478 *)arg0)->pos.y += var_f1;
        } else {
            ((TUnk_80491478 *)arg0)->m_ae = 3;
        }
        break;
    case 3:
        VecCopy(&this->pos, ((TUnk_80491478 *)arg0)->target);
        break;
    }
}
#pragma pop

void TUnk_80491478::render() {
    TObjFish::set_global_param(dubchik_texlist);
    TObjFish::set_global_param((s32)m_d8);
    push_matrix();
    post_translate_matrix(&pos);
    rotate_matrix_y(0, rot_y);
    scale_matrix(0, 1.3f, 1.3f, 1.3f);
    model_render_flags &= 0xFFFFFBFF;
    draw_chunk_object((void *)m_c8);
    pop_matrix();
}

s32 TUnk_80491478::get_action_priority() {
    if (m_ae == 3) {
        return 1;
    }
    return 0;
}

void TUnk_80491478::cancel_action() {
    if (get_action_priority() != 1) {
        if (m_d0 != NULL) {
            ((TObjPlayer *)m_d0)->set_cancel_flag();
        }
        m_ae = 2;
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

TUnk_80491460::~TUnk_80491460() {
    if (particle != NULL) {
        particle->queue_destruction();
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
    ((TParticleCtrl *)now_loading)->set_position((u8 *)&this->unk_1C);
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


typedef struct Fade_800ABDD8 Fade_800ABDD8;
typedef struct Owner_800ABDD8 Owner_800ABDD8;
typedef struct VBase_14_800ABDD8 VBase_14_800ABDD8;
typedef struct VBase_18_800ABDD8 VBase_18_800ABDD8;
typedef struct VObj_14_800ABDD8 VObj_14_800ABDD8;
typedef struct VObj_18_800ABDD8 VObj_18_800ABDD8;
typedef struct Vec_800ABDD8 Vec_800ABDD8;
#define PSO_VCALL_VObj_18_800ABDD8_m9(_self, _arg0, _arg1, _arg2) (((VObj_18_800ABDD8 *)(_self))->m9((_arg0), (_arg1), (_arg2)))

