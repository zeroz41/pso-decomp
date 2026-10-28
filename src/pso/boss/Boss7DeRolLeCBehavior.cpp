#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/obj_band.h"
#include "pso/boss/TBoss7PhotonBullet.h"
#include "pso/TBoss7Tentacle.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss7Joint.h"
#include "pso/boss/TBoss7LaserPtcl.h"
#include "pso/boss/TBoss7LaserLight.h"
#include "pso/object/TUnk_804E4788.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss7DeRolLeC.h"
#include "pso/TObject.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss7PhotonBullet_802EF26C.h"
#include <stddef.h>

struct Vec_802E7888 { f32 x, y, z; };

struct Ang_802E7888 { s32 x, y, z; };

struct Obj_802E7888 {
    u8 pad0[0x7B0];
    u32 f7B0;
    Vec_802E7888 pos;
    Vec_802E7888 v7C0;
};

extern "C" {
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32);
f32 subtract_vector(void *, void *);
void queue_destruction__7TObjectFv(void *arg0);
}

void TObjFish::update_attached_orientation() {
    Obj_802E7888 *o = (Obj_802E7888 *)this;
    if (o->f7B0 != 0) {
        Vec_802E7888 d = o->pos;
        Ang_802E7888 ang;
        subtract_vector(&d, &o->v7C0);
        ang.x = -(s32)(10430.38043493439 * atan2_float(d.y, newton_sqrtf(d.x * d.x + d.z * d.z))) - 0x4000;
        ang.y = (s32)(10430.38043493439 * atan2_float(d.x, d.z));
        ang.z = 0;
        ((TNowLoading *)(o->f7B0))->copy_pos(&o->pos);
        ((TBoss4Type2 *)(o->f7B0))->copy_vec3(&ang);
    }
}

void TObjFish::destroy_child() {
    Obj_802E7888 *o = (Obj_802E7888 *)this;
    if (o->f7B0 != 0) {
        queue_destruction__7TObjectFv((void *)o->f7B0);
        o->f7B0 = 0;
    }
}

extern "C" {
s32 advance_animation_playback(void *);
s32 TBoss7DeRolLeC__try_spawn_pattern_crawfish(void *, s32, s32);
void TBoss7DeRolLeC__handle_crawfish_spawn_state(u8 *arg0, u32 arg1, s32 arg2);
}

extern const f32 lbl_805DEA10[1];
extern const f32 lbl_805DEA14[1];
extern const f32 lbl_805DEA18[1];
extern const f32 lbl_805DEA1C[1];
extern const f32 lbl_805DEA20[1];
extern const f32 lbl_805DEA24[1];
extern const f32 lbl_805DEA28[1];
extern const f32 lbl_805DEA2C[1];
extern const f32 lbl_805DEA34[1];
extern const f32 lbl_805DEA38[1];
extern const f32 lbl_805DEA3C[1];
extern const f32 lbl_805DEA40[1];
extern const f32 lbl_805DEA44[1];
extern const f32 lbl_805DEA48[1];
extern const f32 lbl_805DEA4C[1];
extern const f32 lbl_805DEA50[1];
extern const f32 lbl_805DEA54[1];
extern const f32 lbl_805DEA58[1];
extern const f32 lbl_805DEA5C[1];
extern const f32 lbl_805DEA60[1];
extern const f32 lbl_805DEA64[1];
extern const f32 lbl_805DEA68[1];
extern const f32 lbl_805DEA6C[1];
extern const f32 lbl_805DEA70[1];
extern const f32 lbl_805DEA74[1];
extern const f32 lbl_805DEA78[1];
extern const f32 lbl_805DEA7C[1];
extern const f32 lbl_805DEA80[1];
extern const f32 lbl_805DEA84[1];
extern const f32 lbl_805DEA88[1];
extern const f32 lbl_805DEA8C[1];
extern const f32 lbl_805DEA90[1];
extern const f32 lbl_805DEA94[1];
extern const f32 lbl_805DEA98[1];
extern const f32 lbl_805DEA9C[1];
extern const f32 lbl_805DEAA0[1];
extern const f32 lbl_805DEAA4[1];
extern const f32 lbl_805DEAA8[1];
extern const f32 lbl_805DEAAC[1];
extern const f32 lbl_805DEAB0[1];
extern const f32 lbl_805DEAB4[1];
extern const f32 lbl_805DEAB8[1];
extern const f32 lbl_805DEABC[1];
extern const f32 lbl_805DEAC0[1];
extern const f32 lbl_805DEAC4[1];
extern const f32 lbl_805DEAC8[1];
extern const f32 lbl_805DEACC[1];
extern const f32 lbl_805DEAD0[1];
extern const f32 lbl_805DEAD4[1];
extern const f32 lbl_805DEAD8[1];
extern const f32 lbl_805DEADC[1];
extern const f32 lbl_805DEAE0[1];
extern const f32 lbl_805DEAE4[1];
extern const f32 lbl_805DEAE8[1];
extern const f32 lbl_805DEAEC[1];
extern const f32 lbl_805DEAF0[1];
extern const f32 lbl_805DEAF4[1];
extern const f32 lbl_805DEAF8[1];
extern const f32 lbl_805DEAFC[1];
extern const f32 lbl_805DEB00[1];
extern const f32 lbl_805DEB04[1];
extern const f32 lbl_805DEB08[1];
extern const f32 lbl_805DEB0C[1];
extern const f32 lbl_805DEB10[1];
extern const f32 lbl_805DEB14[1];
extern const f32 lbl_805DEB18[1];
extern const f32 lbl_805DEB1C[1];
extern const f32 lbl_805DEB20[1];
extern const f32 lbl_805DEB24[1];
extern const f32 lbl_805DEB28[1];
extern const f32 lbl_805DEB2C[1];
extern const f32 lbl_805DEB30[1];
extern const f32 lbl_805DEB34[1];
extern const f32 lbl_805DEB38[1];
extern const f32 lbl_805DEB3C[1];
extern const f32 lbl_805DEB40[1];
extern const f32 lbl_805DEB44[1];
extern const f32 lbl_805DEB48[1];
extern const f32 lbl_805DEB4C[1];
extern const f32 lbl_805DEB50[1];
extern const f32 lbl_805DEB54[1];
extern const f32 lbl_805DEB58[1];
extern const f32 lbl_805DEB5C[1];
extern const f32 lbl_805DEB60[1];
extern const f32 lbl_805DEB64[1];
extern const f32 lbl_805DEB68[1];
extern const f32 lbl_805DEB6C[1];
extern const f32 lbl_805DEB70[1];
extern const f32 lbl_805DEB74[1];
extern const f32 lbl_805DEB78[1];
extern const f32 lbl_805DEB7C[1];
extern const f32 lbl_805DEB80[1];
extern const f32 lbl_805DEB84[1];
extern const f32 lbl_805DEB88[1];
extern const f32 lbl_805DEB8C[1];
extern const f32 lbl_805DEB90[1];
extern const f32 lbl_805DEB94[1];
extern const f32 lbl_805DEB98[1];
extern const f32 lbl_805DEB9C[1];
extern const f32 lbl_805DEBA0[1];
#define lbl_805DEA10 (lbl_805DEA10[0])
#define lbl_805DEA14 (lbl_805DEA14[0])
#define lbl_805DEA18 (lbl_805DEA18[0])
#define lbl_805DEA1C (lbl_805DEA1C[0])
#define lbl_805DEA20 (lbl_805DEA20[0])
#define lbl_805DEA24 (lbl_805DEA24[0])
#define lbl_805DEA28 (lbl_805DEA28[0])
#define lbl_805DEA2C (lbl_805DEA2C[0])
#define lbl_805DEA30 (20.0f)
#define lbl_805DEA34 (lbl_805DEA34[0])
#define lbl_805DEA38 (lbl_805DEA38[0])
#define lbl_805DEA3C (lbl_805DEA3C[0])
#define lbl_805DEA40 (lbl_805DEA40[0])
#define lbl_805DEA44 (lbl_805DEA44[0])
#define lbl_805DEA48 (lbl_805DEA48[0])
#define lbl_805DEA4C (lbl_805DEA4C[0])
#define lbl_805DEA50 (lbl_805DEA50[0])
#define lbl_805DEA54 (lbl_805DEA54[0])
#define lbl_805DEA58 (lbl_805DEA58[0])
#define lbl_805DEA5C (lbl_805DEA5C[0])
#define lbl_805DEA60 (lbl_805DEA60[0])
#define lbl_805DEA64 (lbl_805DEA64[0])
#define lbl_805DEA68 (lbl_805DEA68[0])
#define lbl_805DEA6C (lbl_805DEA6C[0])
#define lbl_805DEA70 (lbl_805DEA70[0])
#define lbl_805DEA74 (lbl_805DEA74[0])
#define lbl_805DEA78 (lbl_805DEA78[0])
#define lbl_805DEA7C (lbl_805DEA7C[0])
#define lbl_805DEA80 (lbl_805DEA80[0])
#define lbl_805DEA84 (lbl_805DEA84[0])
#define lbl_805DEA88 (lbl_805DEA88[0])
#define lbl_805DEA8C (lbl_805DEA8C[0])
#define lbl_805DEA90 (lbl_805DEA90[0])
#define lbl_805DEA94 (lbl_805DEA94[0])
#define lbl_805DEA98 (lbl_805DEA98[0])
#define lbl_805DEA9C (lbl_805DEA9C[0])
#define lbl_805DEAA0 (lbl_805DEAA0[0])
#define lbl_805DEAA4 (lbl_805DEAA4[0])
#define lbl_805DEAA8 (lbl_805DEAA8[0])
#define lbl_805DEAAC (lbl_805DEAAC[0])
#define lbl_805DEAB0 (lbl_805DEAB0[0])
#define lbl_805DEAB4 (lbl_805DEAB4[0])
#define lbl_805DEAB8 (lbl_805DEAB8[0])
#define lbl_805DEABC (lbl_805DEABC[0])
#define lbl_805DEAC0 (lbl_805DEAC0[0])
#define lbl_805DEAC4 (lbl_805DEAC4[0])
#define lbl_805DEAC8 (lbl_805DEAC8[0])
#define lbl_805DEACC (lbl_805DEACC[0])
#define lbl_805DEAD0 (lbl_805DEAD0[0])
#define lbl_805DEAD4 (lbl_805DEAD4[0])
#define lbl_805DEAD8 (lbl_805DEAD8[0])
#define lbl_805DEADC (lbl_805DEADC[0])
#define lbl_805DEAE0 (lbl_805DEAE0[0])
#define lbl_805DEAE4 (lbl_805DEAE4[0])
#define lbl_805DEAE8 (lbl_805DEAE8[0])
#define lbl_805DEAEC (lbl_805DEAEC[0])
#define lbl_805DEAF0 (lbl_805DEAF0[0])
#define lbl_805DEAF4 (lbl_805DEAF4[0])
#define lbl_805DEAF8 (lbl_805DEAF8[0])
#define lbl_805DEAFC (lbl_805DEAFC[0])
#define lbl_805DEB00 (lbl_805DEB00[0])
#define lbl_805DEB04 (lbl_805DEB04[0])
#define lbl_805DEB08 (lbl_805DEB08[0])
#define lbl_805DEB0C (lbl_805DEB0C[0])
#define lbl_805DEB10 (lbl_805DEB10[0])
#define lbl_805DEB14 (lbl_805DEB14[0])
#define lbl_805DEB18 (lbl_805DEB18[0])
#define lbl_805DEB1C (lbl_805DEB1C[0])
#define lbl_805DEB20 (lbl_805DEB20[0])
#define lbl_805DEB24 (lbl_805DEB24[0])
#define lbl_805DEB28 (lbl_805DEB28[0])
#define lbl_805DEB2C (lbl_805DEB2C[0])
#define lbl_805DEB30 (lbl_805DEB30[0])
#define lbl_805DEB34 (lbl_805DEB34[0])
#define lbl_805DEB38 (lbl_805DEB38[0])
#define lbl_805DEB3C (lbl_805DEB3C[0])
#define lbl_805DEB40 (lbl_805DEB40[0])
#define lbl_805DEB44 (lbl_805DEB44[0])
#define lbl_805DEB48 (lbl_805DEB48[0])
#define lbl_805DEB4C (lbl_805DEB4C[0])
#define lbl_805DEB50 (lbl_805DEB50[0])
#define lbl_805DEB54 (lbl_805DEB54[0])
#define lbl_805DEB58 (lbl_805DEB58[0])
#define lbl_805DEB5C (lbl_805DEB5C[0])
#define lbl_805DEB60 (lbl_805DEB60[0])
#define lbl_805DEB64 (lbl_805DEB64[0])
#define lbl_805DEB68 (lbl_805DEB68[0])
#define lbl_805DEB6C (lbl_805DEB6C[0])
#define lbl_805DEB70 (lbl_805DEB70[0])
#define lbl_805DEB74 (lbl_805DEB74[0])
#define lbl_805DEB78 (lbl_805DEB78[0])
#define lbl_805DEB7C (lbl_805DEB7C[0])
#define lbl_805DEB80 (lbl_805DEB80[0])
#define lbl_805DEB84 (lbl_805DEB84[0])
#define lbl_805DEB88 (lbl_805DEB88[0])
#define lbl_805DEB8C (lbl_805DEB8C[0])
#define lbl_805DEB90 (lbl_805DEB90[0])
#define lbl_805DEB94 (lbl_805DEB94[0])
#define lbl_805DEB98 (lbl_805DEB98[0])
#define lbl_805DEB9C (lbl_805DEB9C[0])
#define lbl_805DEBA0 (lbl_805DEBA0[0])

typedef struct Vec_802E79B0 { f32 x, y, z; } Vec_802E79B0;

typedef struct Obj_802E79B0 {
    u8 pad0[0x3EC];
    Vec_802E79B0 pts[20];
    u8 pad[0x530 - 0x3EC - 20 * 12];
    Vec_802E79B0 out[10];
} Obj_802E79B0;

extern "C" {
s32 VecCopy__FP3VecPC3Vec(int, void *);
s32 vec3_add_to(int, void *);
void fn_802E79B0(Obj_802E79B0 *arg0);
#define VecCopy__FP3VecPC3Vec ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)
#define vec3_add_to ((void (*)(void *, void *))vec3_add_to)
void fn_802E79B0(Obj_802E79B0 *arg0) {
    Vec_802E79B0 v;
    Vec_802E79B0 *out;
    s32 i;
    out = arg0->out;
    VecCopy__FP3VecPC3Vec(&v, &arg0->pts[0]);
    vec3_add_to(&v, &arg0->pts[9]);
    v.x *= lbl_805DEA14;
    v.y *= lbl_805DEA14;
    v.z *= lbl_805DEA14;
    VecCopy__FP3VecPC3Vec(&out[0], &v);
    VecCopy__FP3VecPC3Vec(&v, &arg0->pts[9]);
    vec3_add_to(&v, &arg0->pts[11]);
    v.x *= lbl_805DEA14;
    v.y *= lbl_805DEA14;
    v.z *= lbl_805DEA14;
    VecCopy__FP3VecPC3Vec(&out[1], &v);
    out += 2;
    for (i = 0; i < 8; i++, out++) {
        VecCopy__FP3VecPC3Vec(&v, &arg0->pts[i + 11]);
        vec3_add_to(&v, &arg0->pts[i + 12]);
        v.x *= lbl_805DEA14;
        v.y *= lbl_805DEA14;
        v.z *= lbl_805DEA14;
        VecCopy__FP3VecPC3Vec(out, &v);
    }
}

#undef VecCopy__FP3VecPC3Vec
#undef vec3_add_to

void render_shadows__9TObjEnemyFv(u8 *arg0);

void TBoss7DeRolLeC::set_flag_800() { *(u32*)((char*)this + 0x628) |= 0x800; }

}

struct RecoveredGlobal_802E7F30_lbl_804739AC
{
  s32 value;
  u8 remaining[0x24];
};

struct RecoveredGlobal_802E7F30_lbl_804739D4
{
  s32 value;
  u8 remaining[0x24];
};

struct RecoveredFields_802E7F30_temp_r3
{
  u8 unknown_0[0x4];
  u8 *field_4;
};

struct RecoveredFields_802E7F30_var_r3
{
  u8 unknown_0[0x4];
  s32 field_4;
};

struct RecoveredFields_802E7F30_temp_r3_2
{
  u8 unknown_0[0x4];
  u8 *field_4;
};

struct Fish_802E7B40 { u8 pad[0x6DC]; void* t[4]; };

struct Fish_802E7B94 { u8 pad[0x6DC]; void* t[4]; };

extern "C" {
void queue_boss_effect__10TObjPlayerFPv(void* a0);
extern const RecoveredGlobal_802E7F30_lbl_804739AC lbl_804739AC;
extern const RecoveredGlobal_802E7F30_lbl_804739D4 lbl_804739D4;
void TObjPlayer__sub_802E7F30(void *unused, s32 arg1);
void TBoss7Tentacle__sub_802F0B80(void* p);
void TObjFish__sub_802E7B40(Fish_802E7B40* o);
void TBoss7Tentacle__sub_802F0B70(void* p);
void TObjFish__sub_802E7B94(Fish_802E7B94* o);
#define queue_boss_effect__10TObjPlayerFPv ((u32 (*)(int))queue_boss_effect__10TObjPlayerFPv)
void TBoss7DeRolLeC::render_shadows() {
    if (*(s32 *)((s8 *)this->m_a4 + 0x18) & 1) {
        render_shadows__9TObjEnemyFv((u8 *)this);
    }
}

void TObjFish__sub_802E7B40(Fish_802E7B40* o) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (o->t[i] != 0) {
            TBoss7Tentacle__sub_802F0B80(o->t[i]);
        }
    }
}

typedef struct RecoveredFields_802E7F30_temp_r3 RecoveredFields_802E7F30_temp_r3;
typedef struct RecoveredFields_802E7F30_temp_r3_2 RecoveredFields_802E7F30_temp_r3_2;
typedef struct RecoveredFields_802E7F30_var_r3 RecoveredFields_802E7F30_var_r3;
typedef struct RecoveredGlobal_802E7F30_lbl_804739AC RecoveredGlobal_802E7F30_lbl_804739AC;
typedef struct RecoveredGlobal_802E7F30_lbl_804739D4 RecoveredGlobal_802E7F30_lbl_804739D4;
typedef char RecoveredGlobal_802E7F30_lbl_804739AC_size[((sizeof(RecoveredGlobal_802E7F30_lbl_804739AC)) == 0x28) ? (1) : (-1)];
typedef char RecoveredGlobal_802E7F30_lbl_804739D4_size[((sizeof(RecoveredGlobal_802E7F30_lbl_804739D4)) == 0x28) ? (1) : (-1)];

void TObjFish__sub_802E7B94(Fish_802E7B94* o) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (o->t[i] != 0) {
            TBoss7Tentacle__sub_802F0B70(o->t[i]);
        }
    }
}


extern "C" {
void *memset(void *, int, unsigned long);
u16 obj_getField1c(void *);
s16 TObjFish__sub_802E7CC4(void *self);
}


struct Boss_802E7CC4 { u8 pad[0x7A4]; TObject *group; };

s16 TObjFish__sub_802E7CC4(void *self) {
    u8 used[36];
    u16 base;
    TObject *child;
    s16 i;
    memset(used, 0, sizeof(used));
    base = obj_getField1c(self) + 11;
    for (child = ((Boss_802E7CC4 *)self)->group->m_down; child != NULL; child = child->m_next) {
        used[obj_getField1c(child) - base] = 1;
    }
    for (i = 35; i >= 0; i--) {
        if (used[i] == 0) {
            return i;
        }
    }
    return -1;
}


struct EffectNode_802E7EA0 { u8 pad[4]; s32 value; };

struct EffectRef_802E7EA0 { u8 pad[4]; EffectNode_802E7EA0 *node; };

struct Saved_802E7EA0 { u8 pad[0x5A8]; s32 a[10]; s32 b[10]; };

void TObjPlayer__sub_802E7EA0(void *arg0) {
    u32 effect;
    s32 i;
    effect = queue_boss_effect__10TObjPlayerFPv(0);
    for (i = 0; i != 10; i++) {
        ((Saved_802E7EA0 *)arg0)->a[i] = ((EffectRef_802E7EA0 *)find_model_node(effect, (&lbl_804739AC.value)[i]))->node->value;
        ((Saved_802E7EA0 *)arg0)->b[i] = ((EffectRef_802E7EA0 *)find_model_node(effect, (&lbl_804739D4.value)[i]))->node->value;
    }
}

void TObjPlayer__sub_802E7F30(void *unused, s32 arg1) {
  s32 *var_r4;
  s32 var_r31;
  u8 *temp_r3;
  u8 *temp_r3_2;
  u8 *var_r3;
  var_r31 = arg1;
  if ((var_r31 >= 0) && (var_r31 < 0xA))
  {
    var_r3 = (u8 *) 0;
    var_r4 = (s32 *)&lbl_804739AC.value;
    var_r31 *= 4;
    if (1)
    {
      var_r4 = (s32 *)&lbl_804739AC.value;
      var_r4 = (s32 *) (*((s32 *) (((s8 *)&lbl_804739AC.value) + var_r31)));
      temp_r3 = (u8 *) find_model_node(queue_boss_effect__10TObjPlayerFPv(0), (s32) var_r4);
    }
    if (temp_r3 != 0)
    {
      var_r3 = (u8 *) ((RecoveredFields_802E7F30_temp_r3 *) temp_r3)->field_4;
      ((RecoveredFields_802E7F30_var_r3 *) var_r3)->field_4 = 0;
    }
    var_r3 = (u8 *) 0;
    var_r4 = (s32 *)&lbl_804739D4.value;
    var_r4 = (s32 *)&lbl_804739D4.value;
    var_r4 = (s32 *) (*((s32 *) (((s8 *)&lbl_804739D4.value) + var_r31)));
    temp_r3_2 = (u8 *) find_model_node(queue_boss_effect__10TObjPlayerFPv(0), (s32) var_r4);
    if (temp_r3_2 != 0)
    {
      var_r3 = (u8 *) ((RecoveredFields_802E7F30_temp_r3_2 *) temp_r3_2)->field_4;
      ((RecoveredFields_802E7F30_var_r3 *) var_r3)->field_4 = 0;
    }
  }
}

void TObjPlayer__sub_802E7FC0(void *arg0) {
    u32 effect;
    s32 i;
    EffectRef_802E7EA0 *ref;
    effect = queue_boss_effect__10TObjPlayerFPv(0);
    for (i = 0; i != 10; i++) {
        ref = (EffectRef_802E7EA0 *)find_model_node(effect, (&lbl_804739AC.value)[i]);
        ref->node->value = ((Saved_802E7EA0 *)arg0)->a[i];
        ref = (EffectRef_802E7EA0 *)find_model_node(effect, (&lbl_804739D4.value)[i]);
        ref->node->value = ((Saved_802E7EA0 *)arg0)->b[i];
    }
}

}

#undef queue_boss_effect__10TObjPlayerFPv

#include <stddef.h>
struct Stack_802E8274 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp28;
};

struct RecoveredGlobal_802E8274_lbl_80472CB0 { s32 value; u8 remaining[0x50]; };
typedef char RecoveredGlobal_802E8274_lbl_80472CB0_size[sizeof(RecoveredGlobal_802E8274_lbl_80472CB0) == 0x54 ? 1 : -1];

struct RecoveredGlobal_802E8274_lbl_804E3BFC { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_802E8274_lbl_804E3BFC_size[sizeof(RecoveredGlobal_802E8274_lbl_804E3BFC) == 0x30 ? 1 : -1];

struct RecoveredGlobal_802E80F4_lbl_8050BEC0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802E80F4_main_task {
    s32 value;
    u8 remaining[0x30];
};

struct RecoveredGlobal_802E80F4_lbl_805412C0 {
    s32 value;
    u8 remaining[0x264];
};

struct RecoveredGlobal_802E80F4_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s32 mult_vec_array__10TObjPlayerFUll(int, void *, void *, int);
}
void get_current_matrix(void *m);
extern "C" {
f32 subtract_vector(void *, void *);
s32 transform_point_by_current_matrix(void *, void *);
s32 push_matrix();
s32 pop_matrix();
extern RecoveredGlobal_802E8274_lbl_80472CB0 lbl_80472CB0;
extern RecoveredGlobal_802E8274_lbl_804E3BFC lbl_804E3BFC;
extern s32 boss7_derolle_c_motion_id;
extern s32 lbl_805D6920;
extern s32 lbl_805D6924;
extern s32 lbl_805D6928;
extern s32 lbl_805D692C;
extern s32 lbl_805D6930;
extern s32 lbl_805D6934;
extern s32 lbl_805D6944;
void TObjPlayer__sub_802E8274(void);
s32 get_mode__11TCameraCtrlFPv(void *);
void TObjPlayer__sub_802E7FC0(void *arg0);
extern RecoveredGlobal_802E80F4_lbl_8050BEC0 saved_model_draw_color;
extern RecoveredGlobal_802E80F4_lbl_805412C0 boss7_derolle_light_pool;
extern RecoveredGlobal_802E80F4_lbl_8058D4C0 model_material_color;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern u8 *lbl_805D693C;
extern s32 *lbl_805D6940;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void TObjPlayer__sub_802E80A0(void);
int get_bml_motion(void*, void*);
int TObjFish__sub_8001EDB0(void*, void*);
int get_bml_model(void*, void*);
int set_global_param__8TObjFishFl(void);

    extern int lbl_805D6918;
void TObjPlayer::notify_fish_obj(void* a0) { get_bml_motion((void*)lbl_805D6918, a0); }

void queue_boss_effect__10TObjPlayerFPv(void* a0) { get_bml_model((void*)lbl_805D6918, a0); }

void TObjPlayer__sub_802E80A0(void) { TObjFish__sub_8001EDB0((void*)lbl_805D6918, (void*)0); }

void TObjPlayer::draw_effect() { TObjFish__sub_8001EDB0((void*)lbl_805D6918, (void*)0); set_global_param__8TObjFishFl(); }

typedef char RecoveredGlobal_802E80F4_lbl_8050BEC0_size[sizeof(RecoveredGlobal_802E80F4_lbl_8050BEC0) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_802E80F4_main_task_size[sizeof(RecoveredGlobal_802E80F4_main_task) == 0x34 ? 1 : -1];
typedef char RecoveredGlobal_802E80F4_lbl_805412C0_size[sizeof(RecoveredGlobal_802E80F4_lbl_805412C0) == 0x268 ? 1 : -1];
typedef char RecoveredGlobal_802E80F4_lbl_8058D4C0_size[sizeof(RecoveredGlobal_802E80F4_lbl_8058D4C0) == 0x10 ? 1 : -1];
void TBoss7DeRolLeC::render() {
    s32 *var_r30;
    s32 var_r29;
    if (!(get_mode__11TCameraCtrlFPv((void *) (&(*(RecoveredGlobal_802E80F4_main_task *)&main_task).value)) & 0x20) || !(*(f32 *)((s8 *)((u8 *)this) + 0x3C) < lbl_805DEA1C)) {
        var_r30 = (s32 *)(((u8 *)this) + 0x5F8);
        var_r29 = 0;
        do {
            if (((TBoss7Joint *)(*var_r30))->is_part_active() != 0U) {
                TObjPlayer__sub_802E7F30(this, var_r29);
            }
            var_r29 += 1;
            var_r30 = (s32 *)((u8 *)var_r30 + (4));
        } while (var_r29 != 0xA);
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&saved_model_draw_color.value, (NJS_ARGB *)&model_material_color.value);
        TObjEneDD::clear_global_flag_400();
        TParticleCtrl::begin_effect_render();
        push_matrix();
        if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x7AC) != 0U) {
            if (*(s32 *)((s8 *)((u8 *)this) + 0x628) & 0x40) {
                *(s32 **)((s8 *)lbl_805D693C + 0x2C) = &boss7_derolle_light_pool.value;
            } else {
                *(s32 **)((s8 *)lbl_805D693C + 0x2C) = (s32 *) lbl_805D6940;
            }
            TObjPlayer::draw_effect();
            ((TObjPlayer *)(*(u32 *)((s8 *)((u8 *)this) + 0x7AC)))->draw_node_tree_if_visible();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&saved_model_draw_color.value);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
        TObjPlayer__sub_802E7FC0(this);
        ((TObject *)(((u8 *)this) + 0x690))->render_nodes();
    }
}

void TBoss7DeRolLeC::sub_802E8234() {
    boss7_derolle_c_motion_id = 0;
    lbl_805D6924 = *(s32 *)((s8 *)((u8 *)this) + 0x628);
    lbl_805D6920 = 0;
    lbl_805D6928 = (long) (((u8 *)this) + 0x3EC);
    lbl_805D6930 = *(s32 *)((s8 *)((u8 *)this) + 0x6D8);
    lbl_805D6934 = *(s32 *)((s8 *)((u8 *)this) + 0x6D4);
    lbl_805D692C = (long) (((u8 *)this) + 0x4DC);
    lbl_805D6944 = (long) (((u8 *)this) + 0x7B4);
}
void TObjPlayer__sub_802E8274(void) {
    typedef char sp8_offset[(offsetof(Stack_802E8274, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802E8274, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802E8274, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802E8274, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_802E8274, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_802E8274, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_802E8274, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_802E8274, sp24) == 0x1C) ? 1 : -1];
    typedef char sp28_offset[(offsetof(Stack_802E8274, sp28) == 0x20) ? 1 : -1];
    Stack_802E8274 stack;
    if ((s32) boss7_derolle_c_motion_id == 0x5F) {
        stack.sp20 = lbl_805DEA10;
        stack.sp24 = lbl_805DEA10;
        stack.sp28 = lbl_805DEA10;
        transform_point_by_current_matrix((void *)&stack.sp20, (void *)lbl_805D6944);
    }
    if ((s32) boss7_derolle_c_motion_id == 0x71) {
        stack.sp14 = lbl_805DEA10;
        stack.sp18 = lbl_805DEA10;
        stack.sp1C = lbl_805DEA10;
        transform_point_by_current_matrix((void *)&stack.sp14, (void *)(lbl_805D6944 + 0xC));
    }
    if ((s32) boss7_derolle_c_motion_id == (s32) *(s32 *)((s8 *)&lbl_80472CB0.value + (lbl_805D6920 * 4))) {
        stack.sp8 = lbl_805DEA10;
        stack.spC = lbl_805DEA10;
        stack.sp10 = lbl_805DEA10;
        transform_point_by_current_matrix((void *)&stack.sp8, (void *)lbl_805D6928);
        lbl_805D6920 += 1;
        lbl_805D6928 += 0xC;
    }
    if ((s32) boss7_derolle_c_motion_id == 0x33) {
        push_matrix();
        mult_vec_array__10TObjPlayerFUll(0, (void *)&lbl_804E3BFC.value, (void *)lbl_805D692C, 4);
        pop_matrix();
        subtract_vector((void *)(lbl_805D692C + 0xC), (void *)lbl_805D692C);
    }
    if ((lbl_805D6924 & 0x80) && ((s32) boss7_derolle_c_motion_id >= 0x4D) && ((s32) boss7_derolle_c_motion_id <= 0x58)) {
        push_matrix();
        get_current_matrix((void *)lbl_805D6934);
        pop_matrix();
        lbl_805D6934 += 0x30;
    }
    if (((s32) boss7_derolle_c_motion_id >= 0x1D) && ((s32) boss7_derolle_c_motion_id <= 0x20)) {
        push_matrix();
        get_current_matrix((void *)lbl_805D6930);
        pop_matrix();
        lbl_805D6930 += 0x30;
    }
    boss7_derolle_c_motion_id += 1;
}
}

#include <stddef.h>

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

extern "C" {
void TBoss7LaserPtcl__sub_802ECE28(u8 *arg0);
void release_laser_light__15TBoss7LaserPtclFPv(void *arg0);
void TObjFish__sub_802ED4AC(u8 *arg0, s32 arg1);
f32 TObjFish__sub_802ED3E4(u8 *arg0);
void set_swim_direction__8TObjFishFPv(void *arg0);
}
#define release_laser_light__15TBoss7LaserPtclFPv ((s32 (*)(void *, int))release_laser_light__15TBoss7LaserPtclFPv)
#define set_swim_direction__8TObjFishFPv ((void (*)(void *, s32))set_swim_direction__8TObjFishFPv)

struct ByteBlock_14 { u8 bytes[0x14]; };

struct Pt_802E95F8 { f32 x, y, z; };

struct Fish_802E95F8 { u8 pad[0x534]; Pt_802E95F8 pts[16]; u8 pad2[0x728 - 0x534 - 16 * 12]; s32 idx; };

struct Vec_802EBBC8 { f32 x, y, z; };

struct Cam_802EBBC8 { s8 a; s8 b; s16 c; f32 d; f32 e; };

struct Vec_802E85E0 { f32 x, y, z; };

struct Tgt_802E85E0 { u8 pad[0x38]; Vec_802E85E0 pos; };

struct Fish_802E85E0 {
    u8 pad0[0x390];
    Tgt_802E85E0 *target;
    u8 pad394[0x628 - 0x394];
    u32 flags;
    u8 pad62C[0x6B4 - 0x62C];
    s32 f6B4;
    u8 pad6B8[0x6C0 - 0x6B8];
    s32 dir;
    u8 pad6C4[0x6DC - 0x6C4];
    s32 kids[4];
    u8 pad6EC[0x728 - 0x6EC];
    s32 state;
    s32 timer;
    s32 fired;
    s32 wait;
    s32 f738;
};

struct V_802EAAC8 { f32 x, y, z; };

struct Fish_802EAAC8 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xB0 - 0x44];
    u32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x50C - 0xC4];
    u8 eff[0x530 - 0x50C];
    V_802EAAC8 recs[10];
    u8 pad5A8[0x628 - 0x5A8];
    u32 flags;
    u8 pad62C[0x670 - 0x62C];
    u8 mover[0x680 - 0x670];
    f32 f680;
    u8 pad684[0x688 - 0x684];
    f32 f688;
    u8 pad68C[0x6C0 - 0x68C];
    s32 mode;
    s32 next_mode;
    u8 pad6C8[0x6F0 - 0x6C8];
    f32 f6F0;
    u8 pad6F4[0x728 - 0x6F4];
    s32 phase;
    s32 f72C;
    s32 step;
    s32 tick;
    u8 pad738[0x744 - 0x738];
    f32 dir;
    f32 f748;
    f32 f74C;
    f32 vy;
    f32 vx;
    f32 ay;
    u8 pad75C[0x7B0 - 0x75C];
    s32 ptcl;
    u8 ppos[0xC];
};

struct Vec_802EC550 { f32 x, y, z; };

struct PCtrl_802EC550 {
    u8 pad0[0x530];
    Vec_802EC550 pos[(0x788 - 0x530) / 0xC];
    void *objs[6];
    s32 idx;
};

struct Vec_802E8B50 { f32 x, y, z; };

struct Cam_802E8B50 { s8 a; s8 b; s16 c; f32 d; f32 e; };

struct Body_802E8B50 { u8 pad[8]; s32 flags; };

struct Fish_802E8B50 {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[0x38 - 0x34];
    Vec_802E8B50 pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    u8 pad60[0x5F8 - 0x60];
    void *kids[10];
    u8 pad620[0x624 - 0x620];
    Body_802E8B50 *body;
    s32 flags;
    u8 pad62C[0x6C0 - 0x62C];
    s32 dir;
    u8 pad6C4[0x6DC - 0x6C4];
    void *tent[4];
    f32 f6EC_pad;
    f32 f6F0;
    u8 pad6F4[0x6FC - 0x6F4];
    s32 f6FC;
    u8 pad700[0x728 - 0x700];
    s32 phase;
    s32 timer;
    u8 pad730[0x73C - 0x730];
    s32 f73C;
    u8 pad740[0x7A4 - 0x740];
    void *nodes;
    u8 pad7A8[0x7B0 - 0x7A8];
    s32 f7B0;
    u8 f7B4[4];
};

struct Vec_802E9ADC { f32 x, y, z; };

struct Fish_802E9ADC {
    u8 pad0[0x390];
    u8 *target;
    u8 pad394[0x628 - 0x394];
    s32 flags;
    u8 pad62C[0x6C0 - 0x62C];
    s32 dir;
    u8 pad6C4[0x6DC - 0x6C4];
    s32 tent[4];
    u8 pad6EC[0x728 - 0x6EC];
    s32 phase;
    s32 timer;
    s32 idx;
    s32 interval;
    s32 arg;
};

struct Fish_802E979C {
    u8 pad0[0x38];
    f32 x38;
    u8 pad3C[0x40 - 0x3C];
    f32 y40;
    u8 pad44[0x64 - 0x44];
    s32 rot64;
    u8 pad68[0x628 - 0x68];
    u32 flags;
    u8 pad62C[0x6C0 - 0x62C];
    s32 dir;
    u8 pad6C4[0x6DC - 0x6C4];
    u8 *kids[4];
    u8 pad6EC[0x6F0 - 0x6EC];
    f32 depth;
    u8 pad6F4[0x728 - 0x6F4];
    s32 state;
    s32 fired;
    u8 pad730[0x73C - 0x730];
    s32 angle;
    u8 pad740[0x744 - 0x740];
    f32 v744;
    f32 v748;
    f32 v74C;
    f32 v750;
};

struct Vec_802E9DBC { f32 x, y, z; };

struct Fish_802E9DBC {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xB0 - 0x44];
    u32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x440 - 0xC4];
    Vec_802E9DBC p440;
    Vec_802E9DBC p44C;
    u8 pad458[0x4DC - 0x458];
    Vec_802E9DBC p4DC;
    u8 pad4E8[0x50C - 0x4E8];
    u8 eff[0x624 - 0x50C];
    u8 *f624;
    u32 flags;
    u8 pad62C[0x6C0 - 0x62C];
    s32 mode;
    u8 pad6C4[0x6DC - 0x6C4];
    s32 tent[4];
    u8 pad6EC[0x6F0 - 0x6EC];
    f32 f6F0;
    u8 pad6F4[0x728 - 0x6F4];
    s32 state;
    s32 timer;
    s32 tick;
    s32 count;
    u8 pad738[0x744 - 0x738];
    f32 f744;
    f32 f748;
    f32 f74C;
    f32 f750;
    f32 f754;
    f32 f758;
    f32 f75C;
    f32 f760;
    u8 pad764[0x784 - 0x764];
    void *ptcl;
};

struct Vec_802EA4D8 { f32 x, y, z; };

struct Ctl_802EB90C { u8 pad[8]; u32 buttons; };

struct Fish_802EB90C {
    u8 pad0[0x40]; f32 f40;
    u8 pad44[0x64 - 0x44]; s32 f64;
    u8 pad68[0xB0 - 0x68]; u32 fB0;
    u8 padB4[0xC8 - 0xB4]; f32 fC8;
    u8 padCC[0x624 - 0xCC]; Ctl_802EB90C *ctl; u32 flags628;
    u8 pad62C[0x6C0 - 0x62C]; s32 state;
    u8 pad6C4[0x6F0 - 0x6C4]; f32 f6F0;
    u8 pad6F4[0x728 - 0x6F4]; s32 f728; s32 f72C; s32 f730;
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 fill_value_array(int);
u8 *csnVector(s32 *, void *, s32);
u32 __nw__7TObjectFUl(int);
void set_state_and_send__14TBoss7DeRolLeCFl(u8 *arg0, s32 arg1);
#define set_state_and_send__14TBoss7DeRolLeCFl ((s32 (*)(void *, int))set_state_and_send__14TBoss7DeRolLeCFl)
s32 is_state_2__15TBoss7LaserPtclFv(void *);
u8 *TBoss7LaserPtcl__ct(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3);
extern s32 boss7_laser_particle_params[];
void TBoss7LaserPtcl__sub_802E8FCC(u8 *arg0, u32 arg1);
void TObjFish__sub_802ECE90(void *arg0, int idx, int arg);

void TObjFish__sub_802E95F8(u8 *arg0, u32 arg1, s32 arg2);
s32 restore_player_cameras();
s32 activate_camera_mode(s32 arg0);
u8 *get_scripted_camera_playback();
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 query_teammate_state__9TObjEneDDFv();
int play_sound_effect(void*, void*, void*, void*);

extern Vec_802EBBC8 lbl_80473F78;
extern Vec_802EBBC8 lbl_80473F84;
void TObjFish__sub_802EBBC8(u8 *arg0, u32 arg1);
f32 calc_boss4_scale__10TObjPlayerFi(void *);
s32 get_random_scaled__9TObjEneDDFv(void *);

s32 TBoss7Tentacle__sub_802F0904(s32);
void TBoss7Tentacle__sub_802F0AF0(s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern s32 game_difficulty_selection;
void TObjFish__sub_802E85E0(u8 *arg0, u32 arg1, s32 arg2);
void TObjFish__sub_802E83E8(u8 *, u32);
void TObjFish__sub_802E8528(void* o, u32 k);
void TObjFish__sub_802E8584(void* o, u32 k);
void TObjFish__sub_802E88F8(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8990(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8E34(u8 *arg0, u32 arg1);
void TObjFish__sub_802E8EEC(u8 *arg0, u32 arg1, s32);
void TObjFish__sub_802E9458(u8 *arg0, u32 arg1);
void TObjFish__sub_802EB270(u8 *, u32, s32, s32);
void TObjFish__sub_802EBE50(void* o, u32 k);
void TBoss7DeRolLeC__dispatch_state(u8 *arg0, u32 arg1, u32 arg2);
f32 fabs_float(f32);
s32 advance_scalar_motion_profile(void *);
void set_move_params__13TBoss2DeRolLeFPvffff(u8 *arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
void spawn_particle_201__8TObjFishFii(s32 arg1, s32 arg2);

void TObjFish__sub_802EAAC8(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
void *create_particle_controller_with_angles(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 arg4);
void fn_802EC52C(s32 arg0, s32 arg1);
extern s32 particle_pos_index_table[];
extern f32 lbl_804E3E48[];
void TParticleCtrl__sub_802EC550(PCtrl_802EC550 *o);
void assign_slots_from_list(void *arg0, s32 arg1);
}
void calc_laser_ray_hit_point(u8 *arg0, u8 *arg1);
void *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 a, s32 b, s32 c);
extern "C" {

void TBoss7Tentacle__sub_802F0AD0(void *a0);
extern Vec_802E8B50 lbl_80473F90[];

void handle_tentacle_attack_state__8TObjFishFPvUii(Fish_802E9ADC *o, u32 arg1, s32 arg2);

void TObjFish__sub_802E979C(Fish_802E979C *o, u32 k, s32 dir);
void *create_particle_emitter(void *pos, s32 id);

void TBoss7Tentacle__sub_802F0B58(u8 *arg0);
void TObjBoss2Tunnel__sub_802F22C4(void);
void TObjBoss2Tunnel__sub_802F22DC(void);
u8 *TBoss7LaserPtcl__sub_8035AE54(u8 *arg0, s32 arg1, s32 arg2);
void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2);

void TObjFish__sub_802EA4D8(u8 *arg0, u32 arg1);

void TObjFish__sub_802EB90C(Fish_802EB90C *arg0, u32 arg1);
struct Stack_802EC468 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_802EC468_lbl_804FF5E8 {
    s32 value;
    u8 remaining[0x24];
};


struct Ent_802E88F8 { s32 a; s32 b; };

struct Fish_802E8AD4 { u8 pad[0x628]; u32 flags; };

typedef char RecoveredGlobal_802EC468_lbl_804FF5E8_size[sizeof(RecoveredGlobal_802EC468_lbl_804FF5E8) == 0x28 ? 1 : -1];

struct RecoveredGlobal_802EC7F0_lbl_804E3C2C {
    s32 value;
    u8 remaining[0x2C];
};

struct Ply_802ECAA4 { u8 pad[0x326]; s16 state; };

typedef char RecoveredGlobal_802EC7F0_lbl_804E3C2C_size[sizeof(RecoveredGlobal_802EC7F0_lbl_804E3C2C) == 0x30 ? 1 : -1];

struct VBase_802ECBDC { char pad[0x18]; };

struct VObj_802ECBDC : VBase_802ECBDC {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
};

struct Fish_802ECBDC {
    u8 pad0[0x5F8];
    VObj_802ECBDC *kids[10];
};

struct VBase_802ECC44 { char pad[0x18]; };

struct VObj_802ECC44 : VBase_802ECC44 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
};

struct Fish_802ECC44 {
    u8 pad0[0x5F8];
    VObj_802ECC44 *kids[10];
};

int get_player_data__10TObjPlayerFi(int a0);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
s32 enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 enemy_set_target_id(void * a0 = 0, u16 a1 = 0);
void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0);
s32 is_alive__9TObjEneDDFv();
u8 *get_enemy_entity(u16 arg0);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
#define TObjFish__sub_802E7B40 ((s32 (*)(void *))TObjFish__sub_802E7B40)
#define TObjFish__sub_802E7B94 ((s32 (*)(void *))TObjFish__sub_802E7B94)
void TObjFish__sub_802E8AD4(Fish_802E8AD4* o, u32 k);
void TObjFish__sub_802EC32C(void);
void TObjFish__sub_802EC468(s32 arg0, f32 farg0, f32 farg1);
void TBoss7DeRolLeC__sub_802EC994(void* p);
void fn_802EC9A4(void *arg0, void *arg1);
void fn_802EC9F0(TObjEneDD *arg0, void *arg1);
void TObjFish__sub_802ECBDC(Fish_802ECBDC *self);
void TObjFish__sub_802ECC44(Fish_802ECC44 *self);

s32 spawn_default_particle__8TObjFishFv(s32, s32);
s32 TObjFish__sub_802F18E8(void *);

extern Ent_802E88F8 *lbl_804E3C2C[];
extern RecoveredGlobal_802EC468_lbl_804FF5E8 lbl_804FF5E8;

struct Boss_802E83E8 { u8 pad[0x728]; s32 timer; s32 count; u8 pad730[0x7CC - 0x730]; u16 targets[4]; };

extern "C" {
void *get_player_by_client_id(s32 i);
void *TBoss7TentacleNeedle__ct(void *o, void *boss, void *pos);
}

void TObjFish__sub_802E83E8(u8 *boss, u32 k) {
    Boss_802E83E8 *self = (Boss_802E83E8 *)boss;
    u8 *player;
    void *o;
    u16 id;
    u16 n;
    switch (k) {
    case 4:
        ((TObjMotion *)boss)->set_field_b8(1);
        TObjFish__sub_802ED4AC(boss, 9);
        self->timer = 20;
        self->count = 12;
        id = 0;
        n = 0;
        while (n != 4) {
            if (get_player_by_client_id(id = (id + 1) & 3) != NULL) {
                self->targets[n++] = id;
            }
        }
        break;
    case 9:
        if (self->count == 0) {
            ((TBoss7DeRolLeC *)boss)->advance_action_sequence();
        }
        break;
    case 0:
        advance_animation_playback(boss);
        if (self->count > 0) {
            if (self->timer == 0) {
                self->timer = 20;
                self->count--;
                player = (u8 *)get_player_by_client_id(self->targets[self->count & 3]);
                if (player != NULL) {
                    o = TObject::operator new(0x7C);
                    if (o != NULL) {
                        TBoss7TentacleNeedle__ct(o, boss, player + 0x38);
                    }
                }
            } else {
                self->timer--;
            }
        }
        break;
    case 6:
        ((TObjFish *)boss)->pick_random_target();
        break;
    }
}

void TObjFish__sub_802E8528(void* o, u32 k) {
    switch (k) {
    case 0:
        advance_animation_playback(o);
        TObjFish__sub_802E7B40(o);
        ((TBoss7DeRolLeC *)o)->advance_action_sequence();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 4: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TObjFish__sub_802E8584(void* o, u32 k) {
    switch (k) {
    case 0:
        advance_animation_playback(o);
        TObjFish__sub_802E7B94(o);
        ((TBoss7DeRolLeC *)o)->advance_action_sequence();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 4: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

#define self ((Fish_802E85E0 *)arg0)
void TObjFish__sub_802E85E0(u8 *arg0, u32 arg1, s32 arg2) {
    Vec_802E85E0 v;
    f32 scale;
    s32 r;
    s32 ok;
    s32 j;
    s32 i;
    s32 k;
    switch (arg1) {
    case 4:
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)arg0);
        self->flags &= ~4;
        self->flags &= ~0x100;
        self->dir = arg2;
        set_swim_direction__8TObjFishFPv(self, self->dir);
        if (self->dir == 0) {
            ((TObjMotion *)self)->set_field_b8(9);
        } else {
            ((TObjMotion *)self)->set_field_b8(0xA);
        }
        self->state = 0;
        self->timer = 0;
        self->fired = 0;
        self->wait = 0xB4;
        self->f738 = 0x78;
        return;
    case 2:
        if (self->state == 3) {
            if (self->dir == 0) {
                set_state_and_send__14TBoss7DeRolLeCFl(self, 0x15);
            } else {
                set_state_and_send__14TBoss7DeRolLeCFl(self, 0x16);
            }
        }
        return;
    case 9:
        if (self->state == 3) {
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
        }
        return;
    case 0:
        advance_animation_playback(self);
        switch (self->state) {
        case 0:
            self->timer++;
            if (self->timer > lbl_804E3C2C[game_difficulty_selection][self->f6B4].b * 0x1E) {
                self->state = 1;
                self->timer = 0;
                self->fired = 0;
            }
            break;
        case 1:
            self->timer++;
            if (self->timer >= self->wait) {
                if (self->fired == 0) {
                    self->timer = 0;
                    if (((TObjEneDD_ST *)self)->enemy_has_live_target() != 0) {
                        ((s32 (*)(Vec_802E85E0 *, Vec_802E85E0 *))VecCopy__FP3VecPC3Vec)(&v, &self->target->pos);
                    } else {
                        scale = lbl_805DEA20 * calc_boss4_scale__10TObjPlayerFi(self);
                        r = get_random_scaled__9TObjEneDDFv(self);
                        v.x = scale * sin_table_lookup(r);
                        v.y = lbl_805DEA24;
                        v.z = scale * cos_table_lookup(r);
                        TObjBoss2Tunnel::adjust_to_ground((s32)&v, (void *)&v);
                    }
                    for (j = 0; j != 4; j++) {
                        ((TBoss7Tentacle *)(self->kids[j]))->start_attack_at_position((u8 *)&v, self->f738);
                    }
                    self->fired = 1;
                    self->timer = 0;
                } else {
                    self->state = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            self->timer++;
            for (i = 0; i < 4; i++) {
                if (TBoss7Tentacle__sub_802F0904(self->kids[i]) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || self->timer > 600) {
                self->state = 3;
            }
            break;
        }
        return;
    case 6:
        ((TObjFish *)arg0)->pick_random_target();
        return;
    case 5:
        for (k = 0; k < 4; k++) {
            TBoss7Tentacle__sub_802F0AF0(self->kids[k]);
        }
        return;
    case 1:
    case 3:
    case 7:
    case 8:
        return;
    }
}
#undef self

void TObjFish__sub_802E88F8(u8 *boss7_de_rol_le_c, u32 arg1) {
    s32 temp_r3;
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)boss7_de_rol_le_c + 0x728) = lbl_804E3C2C[game_difficulty_selection][*(s32 *)((s8 *)boss7_de_rol_le_c + 0x6B4)].b * 0x1E;
        return;
    case 0:
        advance_animation_playback(boss7_de_rol_le_c);
        temp_r3 = *(s32 *)((s8 *)boss7_de_rol_le_c + 0x728);
        *(s32 *)((s8 *)boss7_de_rol_le_c + 0x728) = temp_r3 - 1;
        if (temp_r3 == 0) {
            ((TBoss7DeRolLeC *)boss7_de_rol_le_c)->advance_action_sequence();
        }
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TObjFish__sub_802E8990(u8 *boss7_de_rol_le_c, u32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)boss7_de_rol_le_c + 0x728) = *(s16 *)((s8 *)boss7_de_rol_le_c + 0xF4);
        *(s16 *)((s8 *)boss7_de_rol_le_c + 0xF4) = 1;
        return;
    case 0:
        advance_animation_playback(boss7_de_rol_le_c);
        if (((TObject *)(*(s32 *)((s8 *)boss7_de_rol_le_c + 0x7A4)))->get_node_count() == 0) {
            ((TBoss7DeRolLeC *)boss7_de_rol_le_c)->advance_action_sequence();
        }
        return;
    case 5:
        *(s16 *)((s8 *)boss7_de_rol_le_c + 0xF4) = *(s32 *)((s8 *)boss7_de_rol_le_c + 0x728);
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC__handle_crawfish_spawn_state(u8 *self, u32 event, s32 variant) {
    s32 index;
    switch (event) {
    case 4:
        *(s32 *)((s8 *)self + 0x72C) = 9;
        *(s32 *)((s8 *)self + 0x728) = 0;
        *(s32 *)((s8 *)self + 0x730) = 0;
        ((TObjMotion *)self)->set_field_b8(1);
        return;
    case 0:
        advance_animation_playback(self);
        index = *(s32 *)((s8 *)self + 0x728);
        if (index < *(s32 *)((s8 *)self + 0x72C)) {
            if (*(s32 *)((s8 *)self + 0x730) <= 0) {
                *(s32 *)((s8 *)self + 0x728) = index + 1;
                TBoss7DeRolLeC__try_spawn_pattern_crawfish(self, variant, index);
                *(s32 *)((s8 *)self + 0x730) = 5;
            } else {
                (*(s32 *)((s8 *)self + 0x730))--;
            }
            return;
        }
        ((TBoss7DeRolLeC *)self)->advance_action_sequence();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TObjFish__sub_802E8AD4(Fish_802E8AD4* o, u32 k) {
    switch (k) {
    case 4:
        ((TObjMotion *)o)->set_field_b8(0x10);
        ((s32 (*)(void *))TObjFish__sub_802ECC44)(o);
        o->flags |= 4;
        o->flags &= 0xFFFFFEFF;
        TObjBoss2Tunnel::set_flag_0x200();
        return;
    case 0:
        queue_destruction__7TObjectFv(o);
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

#undef lbl_805DEA10
__declspec(section ".sdata2") const f32 lbl_805DEA10[1] = { 0.0f };
#define lbl_805DEA10 (lbl_805DEA10[0])
#undef lbl_805DEA14
__declspec(section ".sdata2") const f32 lbl_805DEA14[1] = { 0.5f };
#define lbl_805DEA14 (lbl_805DEA14[0])
#undef lbl_805DEA18
__declspec(section ".sdata2") const f32 lbl_805DEA18[1] = { 1.0f };
#define lbl_805DEA18 (lbl_805DEA18[0])
#undef lbl_805DEA1C
__declspec(section ".sdata2") const f32 lbl_805DEA1C[1] = { -35.0f };
#define lbl_805DEA1C (lbl_805DEA1C[0])
#undef lbl_805DEA20
__declspec(section ".sdata2") const f32 lbl_805DEA20[1] = { 120.0f };
#define lbl_805DEA20 (lbl_805DEA20[0])
#undef lbl_805DEA24
__declspec(section ".sdata2") const f32 lbl_805DEA24[1] = { -1.85f };
#define lbl_805DEA24 (lbl_805DEA24[0])
#undef lbl_805DEA28
__declspec(section ".sdata2") const f32 lbl_805DEA28[1] = { 0.7f };
#define lbl_805DEA28 (lbl_805DEA28[0])
#undef lbl_805DEA2C
__declspec(section ".sdata2") const f32 lbl_805DEA2C[1] = { 85.0f };
#define lbl_805DEA2C (lbl_805DEA2C[0])
void TObjFish::handle_death_state(u32 arg1) {
    Fish_802E8B50 *o = (Fish_802E8B50 *)this;
    Cam_802E8B50 cam;
    s32 i;
    switch (arg1) {
    case 4:
        o->flags &= ~0x300;
        o->flags |= 4;
        TObjFish__sub_802ECC44((Fish_802ECC44 *)o);
        ((TObjMotion *)o)->set_field_b8(0x10);
        o->dir = 3;
        TObjFish__sub_802ED4AC((u8 *)o, o->dir);
        o->f5C = 0;
        o->f6F0 = lbl_805DEA10;
        o->phase = 0;
        o->timer = 0;
        o->f73C = 0;
        o->f6FC = 0;
        for (i = 0; i < 4; i++) {
            TBoss7Tentacle__sub_802F0AD0(o->tent[i]);
        }
        if (o->nodes != NULL) {
            ((TObject *)(o->nodes))->queue_destruction_for_each_node();
        }
        TObjBoss2Tunnel::clear_flags_0x3000();
        TWindowCtrl::init_all_slots();
        {
            cam.b = 0;
            cam.a = 2;
            cam.c = 0;
            cam.d = lbl_805DEA10;
            cam.e = lbl_805DEA28;
            activate_camera_mode(5);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x1C71);
        }
        break;
    case 2:
        if (o->body->flags & 0x400) {
            o->f30 &= ~0x800;
            TObjFish__sub_802ECBDC((Fish_802ECBDC *)o);
            set_state_and_send__14TBoss7DeRolLeCFl(o, 2);
        }
        break;
    case 9:
        if (o->phase == 1) {
            set_state_and_send__14TBoss7DeRolLeCFl(o, 0x1D);
        }
        break;
    case 0:
        advance_animation_playback(o);
        if (*(u16 *)(get_scripted_camera_playback() + 2) & 1) {
            o->phase = 1;
            TWindowCtrl::init_all_slots2();
            restore_player_cameras();
        }
        if (objInBand((GameObj *)o, (f32)lbl_805DEA2C) != 0) {
            Vec_802E8B50 v = lbl_80473F90[0];
            create_timed_particle_emitter_with_flags(&v, 0x20C, 0, 0xA0, 0x40);
            play_sound_effect((void *)0x39614, 0, 0, 0);
        }
        if (objInBand((GameObj *)o, (f32)lbl_805DEA30) != 0) {
            ((TObjFish *)o)->destroy_child();
            o->f7B0 = (s32)spawn_continuous_particle_effect_with_flags(o->f7B4, 0x20F, 0x40);
        }
        if (objInBand((GameObj *)o, (f32)lbl_805DEA34) != 0) {
            ((TObjFish *)o)->destroy_child();
        }
        ((TObjFish *)o)->update_attached_orientation();
        break;
    case 5: {
        Vec_802E8B50 saved;
        VecCopy__FP3VecPC3Vec((int)&saved, &o->pos);
        o->pos.x = lbl_805DEA10;
        o->pos.y = lbl_805DEA38;
        o->pos.z = lbl_805DEA3C;
        ((TObjEnemy *)o)->update_prev_position();
        for (i = 0; i != 10; i++) {
            assign_slots_from_list(o, (s32)o->kids[i]);
        }
        ((TBoss8Dragon *)o)->refresh_and_send_entity_flags();
        TBoss4DarkFalz::dispatch_by_main_phase(0x4C);
        VecCopy__FP3VecPC3Vec((int)&o->pos, &saved);
        ((TObjEnemy *)o)->update_prev_position();
        o->f30 = 0x12008;
        ((TBoss7DeRolLeC *)o)->vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    }
    }
}

void TObjFish__sub_802E8E34(u8 *boss7_de_rol_le_c, u32 arg1) {
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)boss7_de_rol_le_c + 0x628) = *(s32 *)((s8 *)boss7_de_rol_le_c + 0x628) | 4;
        *(s32 *)((s8 *)boss7_de_rol_le_c + 0x628) = *(s32 *)((s8 *)boss7_de_rol_le_c + 0x628) & 0xFFFFFEFF;
        ((s32 (*)(void *))TObjFish__sub_802ECC44)(boss7_de_rol_le_c);
        *(s32 *)((s8 *)boss7_de_rol_le_c + 0x5C) = 0;
        *(f32 *)((s8 *)boss7_de_rol_le_c + 0x6F0) = lbl_805DEA10;
        return;
    case 9:
        if (*(s16 *)((s8 *)boss7_de_rol_le_c + 0xB8) == 1) {
            ((TBoss7DeRolLeC *)boss7_de_rol_le_c)->advance_action_sequence();
        }
        return;
    case 8:
        if (*(f32 *)((s8 *)boss7_de_rol_le_c + 0x6F0) < lbl_805DEA40) {
            set_state_and_send__14TBoss7DeRolLeCFl(boss7_de_rol_le_c, 0x1C);
        }
        return;
    case 0:
        *(f32 *)((s8 *)boss7_de_rol_le_c + 0x6F0) = *(f32 *)((s8 *)boss7_de_rol_le_c + 0x6F0) - lbl_805DEA44;
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    }
}

void TObjFish__sub_802E8EEC(u8 *arg0, u32 arg1, s32 _w2) {
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) & 0xFFFFFFFB);
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) | 0x100);
        ((TObjMotion *)arg0)->set_field_b8(0xE);
        ((s32 (*)(void *))TObjFish__sub_802ECBDC)(arg0);
        *(s32 *)((s8 *)arg0 + 0x6C0) = 3;
        TObjFish__sub_802ED4AC((arg0), (*(s32 *)((s8 *)arg0 + 0x6C0)));
        break;
    case 2:
        if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == 1) {
            set_state_and_send__14TBoss7DeRolLeCFl(arg0, 2);
            break;
        }
    default:
        break;
    case 9:
        if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == 1) {
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
            break;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        if (objInBand((GameObj *)(arg0), lbl_805DEA48) != 0) {
            TObjFish::set_effect_target_position(arg0, (void*)(0x39906), arg0 + 0x50C);
        }
        break;
    }
}

struct Fish_802ECBDC;
void TBoss7LaserPtcl__sub_802E8FCC(u8 *arg0, u32 arg1) {
    struct CopyStack_802E8FCC { u8 bytes[0x14]; };
    CopyStack_802E8FCC copy_storage_802E8FCC;
    struct { f32 v[3]; } sp8;
    s32 temp_r4_2;
    u32 boss7_laser_ptcl;
    u8 *temp_r30;
    u8 *src;
    u8 *temp_r3;
    temp_r30 = (u8 *)((void *)((u8 *)arg0 + 0x76C));
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) & 0xFFFFFFFB);
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) | 0x100);
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)arg0);
        ((TObjMotion *)arg0)->set_field_b8(0xF);
        *(s32 *)((s8 *)arg0 + 0x6C0) = 3;
        TObjFish__sub_802ED4AC((arg0), (*(s32 *)((s8 *)arg0 + 0x6C0)));
        fill_value_array((int) (*(s32 *)((s8 *)arg0 + 0x718)));
        *(s32 *)((s8 *)arg0 + 0x728) = 0;
        *(s32 *)((s8 *)arg0 + 0x72C) = 0;
        *(s32 *)((s8 *)arg0 + 0x730) = 0;
        *(s32 *)((s8 *)arg0 + 0x73C) = 0;
        *(f32 *)((s8 *)arg0 + 0x748) = (f32) lbl_805DEA10;
        *(f32 *)((s8 *)arg0 + 0x76C) = (f32) lbl_805DEA10;
        *(f32 *)((s8 *)temp_r30 + 4) = (f32) lbl_805DEA10;
        *(f32 *)((s8 *)temp_r30 + 8) = (f32) lbl_805DEA10;
        *(u32 *)((s8 *)arg0 + 0x784) = 0U;
        return;
    case 2:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x728) == 4) {
            if ((s32) *(s32 *)((s8 *)arg0 + 0x724) >= 4) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x19);
            } else {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x18);
            }
        }
        break;
    case 9:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x728) == 4) {
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
            return;
        }
        break;
    case 0:
        ((s32)advance_animation_playback(arg0));
        *(s32 *)((s8 *)arg0 + 0x7A0) = 6;
        switch (*(s32 *)((s8 *)arg0 + 0x728)) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x72C) = (s32) (*(s32 *)((s8 *)arg0 + 0x72C) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x72C) >= 0x14) {
                *(s32 *)((s8 *)arg0 + 0x72C) = 0;
                *(s32 *)((s8 *)arg0 + 0x728) = 1;
                fill_value_array((int) (*(s32 *)((s8 *)arg0 + 0x718)));
                ((TObjMotion *)arg0)->set_field_b8(0xD);
                if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0) {
                    VecCopy__FP3VecPC3Vec((int)((int)temp_r30), (void *)((int) (*(s32 *)((s8 *)arg0 + 0x390) + 0x38)));
                } else {
                    *(f32 *)((s8 *)arg0 + 0x76C) = (f32) lbl_805DEA10;
                    *(f32 *)((s8 *)temp_r30 + 4) = (f32) lbl_805DEA10;
                    *(f32 *)((s8 *)temp_r30 + 8) = (f32) lbl_805DEA10;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x7A8));
                }
                boss7_laser_ptcl = __nw__7TObjectFUl(0x58);
                if (boss7_laser_ptcl != 0U) {
                    boss7_laser_ptcl = (u32)TBoss7LaserPtcl__ct((u8 *)boss7_laser_ptcl, (u8 *)arg0, (u8 *)((u8 *)arg0 + 0x4DC), (u8 *)temp_r30);
                }
                *(u32 *)((s8 *)arg0 + 0x7A8) = boss7_laser_ptcl;
                TBoss7LaserPtcl__sub_802ECE28((arg0));
                ((TBoss7LaserPtcl *)arg0)->free_laser_light();
                TObjFish::set_effect_target_position((void *)arg0, (void *) (0x39E0F), (void *) ((u8 *)arg0 + 0x50C));
                return;
            }
            break;
        case 1:
            if ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U) {
                ((TBoss7LaserPtcl *)(*(void **)((s8 *)arg0 + 0x7A8)))->calc_position((u8 *)((u8 *)arg0 + 0x4DC), (u8 *)((u8 *)arg0 + 0x4E8));
            }
            if ((lbl_805DEA38 < *(f32 *)((s8 *)arg0 + 0xC0)) && ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U)) {
                ((TBoss7LaserPtcl *)(*(void **)((s8 *)arg0 + 0x7A8)))->destroy_particles();
            }
            TBoss7LaserPtcl__sub_802ECE28((arg0));
            if (lbl_805DEA4C <= *(f32 *)((s8 *)arg0 + 0xC0)) {
                *(f32 *)((s8 *)arg0 + 0xC0) = (f32) lbl_805DEA4C;
                *(s32 *)((s8 *)arg0 + 0x728) = 2;
                if ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U) {
                    ((TBoss7LaserPtcl *)(*(void **)((s8 *)arg0 + 0x7A8)))->init_laser();
                }
                TObjFish::set_effect_target_position((void *)arg0, (void *) (0x3A310), (void *) ((u8 *)arg0 + 0x50C));
                return;
            }
            break;
        case 2:
            src = (u8 *)((void *)((u8 *)arg0 + 0x778));
            *(f32 *)((s8 *)arg0 + 0xC0) = (f32) lbl_805DEA4C;
            if ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U) {
                ((TBoss7LaserPtcl *)(*(void **)((s8 *)arg0 + 0x7A8)))->calc_position((u8 *)((u8 *)arg0 + 0x4DC), (u8 *)((u8 *)arg0 + 0x4E8));
                ((TBoss7LaserPtcl *)(*(u32 *)((s8 *)arg0 + 0x7A8)))->calc_world_position((void *)src);
                calc_laser_ray_hit_point((u8 *)(*(u32 *)((s8 *)arg0 + 0x7A8)), (u8 *)&sp8);
            }
            temp_r3 = (u8 *)(csnVector((s32 *)&sp8, src, 0x16EF));
            if (temp_r3 != NULL) {
                VecCopy__FP3VecPC3Vec((int)((int)src), (void *)((int) (*(s32 *)((s8 *)temp_r3 + 4))));
                if ((u32) *(u32 *)((s8 *)arg0 + 0x71C) == 0U) {
                    *(TUnk_804E4788 **)((s8 *)arg0 + 0x71C) = new TUnk_804E4788((TObject *)arg0, 6, 0x208);
                } else {
                    (*(TUnk_804E4788 **)((s8 *)arg0 + 0x71C))->push_ring_point((const Vec *)src);
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x720) == 0U) {
                    *(TUnk_804E4788 **)((s8 *)arg0 + 0x720) = new TUnk_804E4788((TObject *)arg0, 0xF, 0x209);
                } else {
                    (*(TUnk_804E4788 **)((s8 *)arg0 + 0x720))->push_ring_point((const Vec *)src);
                }
            }
            *(ByteBlock_14 *)(copy_storage_802E8FCC.bytes) = *(const ByteBlock_14 *)((s32) ((u8 *)((void *)((u8 *)boss7_laser_particle_params + -4))) + 4);
            (*(f32 *)(copy_storage_802E8FCC.bytes + 0x4)) = *(f32 *)((s8 *)(*(f32 **)((s8 *)arg0 + 0x620)) + 0);
            TObjEneDD::setup_instance((s32)((void *)arg0), (s32)((int)src), (u8 *)copy_storage_802E8FCC.bytes, (s32)((int) (*(s32 *)((s8 *)arg0 + 0x718))));
            if ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U) {
                if (is_state_2__15TBoss7LaserPtclFv(*(void **)((s8 *)arg0 + 0x7A8)) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x728) = 3;
                    return;
                }
            } else {
                *(s32 *)((s8 *)arg0 + 0x728) = 3;
                return;
            }
            break;
        case 3:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x728) = 4;
                return;
            }
            break;
        }
        break;
    case 6:
        ((TObjFish *)arg0)->pick_random_target();
        return;
    case 5:
        temp_r4_2 = *(s32 *)((s8 *)arg0 + 0x724);
        *(s32 *)((s8 *)arg0 + 0x724) = (s32)(temp_r4_2 + 1);
        release_laser_light__15TBoss7LaserPtclFPv(arg0, (int)temp_r4_2);
        if ((u32) *(u32 *)((s8 *)arg0 + 0x784) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x784));
            *(u32 *)((s8 *)arg0 + 0x784) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x71C) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x71C));
            *(u32 *)((s8 *)arg0 + 0x71C) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x720) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x720));
            *(u32 *)((s8 *)arg0 + 0x720) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x7A8) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x7A8));
            *(u32 *)((s8 *)arg0 + 0x7A8) = 0U;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjFish__sub_802E9458(u8 *arg0, u32 arg1) {
    struct { f32 x, y, z; } v;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) & 0xFFFFFFFB);
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) | 0x100);
        ((s32 (*)(void *))TObjFish__sub_802ECBDC)(arg0);
        ((TObjMotion *)arg0)->set_field_b8(0xC);
        *(s32 *)((s8 *)arg0 + 0x6C0) = 3;
        TObjFish__sub_802ED4AC((arg0), (*(s32 *)((s8 *)arg0 + 0x6C0)));
        *(s32 *)((s8 *)arg0 + 0x728) = 0;
        *(s32 *)((s8 *)arg0 + 0x724) = 0;
        return;
    case 2:
        if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == 0xF) {
            set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x18);
        }
    default:
        return;
    case 9:
        if ((s16) *(s16 *)((s8 *)arg0 + 0xB8) == 0xF) {
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        *(s32 *)((s8 *)arg0 + 0x728) = (s32) (*(s32 *)((s8 *)arg0 + 0x728) + 1);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0xC0);
        if ((temp_f1 >= lbl_805DEA50) && (temp_f1 <= lbl_805DEA54) && ((f32) *(s32 *)((s8 *)arg0 + 0x728) >= lbl_805DEA58)) {
            *(s32 *)((s8 *)arg0 + 0x728) = 0;
            VecCopy__FP3VecPC3Vec((int)&v, arg0 + 0x38);
            v.x = lbl_805DEA5C * calc_elapsed_scaled__9TObjEneDDFv(arg0) + v.x;
            v.y = lbl_805DEA60;
            v.z = v.z + lbl_805DEA64;
            spawn_particle_201__8TObjFishFii((s32)arg0, (s32)&v);
        }
        if (objInBand((GameObj *)(arg0), (f32)lbl_805DEA50) != 0) {
            TObjFish::set_effect_target_position(arg0, (void *) (0x39905), arg0 + 0x50C);
        }
        break;
    }
}
#pragma pop

void TObjFish__sub_802E95F8(u8 *arg0, u32 arg1, s32 arg2) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        ((TObjMotion *)arg0)->set_field_b8(3);
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)arg0);
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) & 0xFFFFFFFB);
        *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) & 0xFFFFFEFF);
        *(s32 *)((s8 *)arg0 + 0x6C0) = arg2;
        TObjFish__sub_802ED4AC((arg0), (*(s32 *)((s8 *)arg0 + 0x6C0)));
        *(s32 *)((s8 *)arg0 + 0x728) = 0;
        *(s32 *)((s8 *)arg0 + 0x72C) = 0;
        *(f32 *)((s8 *)arg0 + 0x744) = (f32) lbl_805DEA68;
        *(s32 *)((s8 *)arg0 + 0x704) = (s32) (*(s32 *)((s8 *)arg0 + 0x704) + 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x704) >= 3) {
            *(s32 *)((s8 *)arg0 + 0x704) = 0;
        }
    default:
        return;
    case 2:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            set_state_and_send__14TBoss7DeRolLeCFl(arg0, 2);
            return;
        }
        break;
    case 9:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x72C)) {
        case 0:
            if (!(*(s32 *)((s8 *)arg0 + 0xB0) & 4)) {
                TObjFish__sub_802ECE90(arg0, (int) (*(s32 *)((s8 *)arg0 + 0x728)), (int) (*(s32 *)((s8 *)arg0 + 0x704)));
                *(s32 *)((s8 *)arg0 + 0x72C) = 1;
                return;
            }
            break;
        case 1:
            temp_r4 = ((Fish_802E95F8 *)arg0)->idx;
            if (((Fish_802E95F8 *)arg0)->pts[temp_r4].x < ((Fish_802E95F8 *)arg0)->pts[temp_r4 + 1].x) {
                ((Fish_802E95F8 *)arg0)->idx = temp_r4 + 1;
                if ((f32) *(s32 *)((s8 *)arg0 + 0x728) >= lbl_805DEA6C) {
                    *(s32 *)((s8 *)arg0 + 0x72C) = 2;
                }
                TObjFish__sub_802ECE90(arg0, (int) (*(s32 *)((s8 *)arg0 + 0x728)), (int) (*(s32 *)((s8 *)arg0 + 0x704)));
            }
            break;
        }
        break;
    }
}

struct Fish_802ECC44;

#pragma push
#pragma fp_contract on

#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
void TObjFish__sub_802E979C(Fish_802E979C *o, u32 k, s32 dir) {
    switch (k) {
    case 4:
        for (s32 i = 0; i < 4; i++) {
            TBoss7Tentacle__sub_802F0AF0((s32)o->kids[i]);
        }
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)o);
        o->flags |= 4;
        o->flags &= 0xFFFFFEFF;
        o->dir = dir;
        set_swim_direction__8TObjFishFPv(o, o->dir);
        if (o->dir == 0) {
            o->v748 = lbl_805DEA70;
            ((TObjMotion *)o)->set_field_b8(9);
        } else {
            o->v748 = lbl_805DEA18;
            ((TObjMotion *)o)->set_field_b8(0xA);
        }
        o->state = 0;
        o->fired = 0;
        o->v744 = lbl_805DEA10;
        o->v750 = lbl_805DEA70;
        o->v74C = lbl_805DEA10;
        o->angle = 0x500;
        TObjBoss2Tunnel::clear_flags_0x3000();
        o->flags &= 0xFFFFFDFF;
        break;
    case 2:
        if (o->state == 2) {
            set_state_and_send__14TBoss7DeRolLeCFl(o, 2);
        }
        break;
    case 9:
        if (o->state == 2) {
            ((TBoss7DeRolLeC *)o)->advance_action_sequence();
        }
        break;
    case 0:
        advance_animation_playback(o);
        switch (o->state) {
        case 0:
            o->v74C += lbl_805DEA74;
            o->y40 -= o->v74C;
            o->v744 += lbl_805DEA78;
            o->x38 += o->v744 * o->v748;
            o->v750 += lbl_805DEA7C;
            o->depth -= o->v750;
            o->angle += lbl_805DEA80;
            if (o->angle >= lbl_805DEA84) {
                o->angle = 0x4000;
            }
            o->rot64 = o->angle * -o->v748;
            if (o->fired == 0 && o->angle >= 0x2200) {
                o->fired = 1;
                TObjFish::set_effect_target_position(o, (void *)0x39906, (u8 *)o + 0x50C);
            }
            if (o->depth < lbl_805DEA88) {
                o->state = 1;
                TObjFish__sub_802ED4AC((u8 *)o, o->dir);
                o->depth = lbl_805DEA88;
                ((TObjMotion *)o)->set_field_b8(1);
                o->v750 = lbl_805DEA10;
                o->flags &= ~4;
                o->flags |= 0x100;
            }
            break;
        case 1:
            o->depth += lbl_805DEA44;
            if (o->depth >= lbl_805DEA10) {
                o->depth = lbl_805DEA10;
                o->state = 2;
            }
            break;
        }
        break;
    case 5:
        o->flags &= ~4;
        break;
    case 1: case 3: case 6: case 7: case 8:
        break;
    }
}
#pragma pop
#pragma pop

void handle_tentacle_attack_state__8TObjFishFPvUii(Fish_802E9ADC *o, u32 arg1, s32 arg2) {
    s32 ang;
    Vec_802E9ADC v;
    s32 ok;
    s32 i;
    s32 j;
    switch (arg1) {
    case 4:
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)(o));
        o->flags &= ~4;
        o->flags &= ~0x100;
        o->dir = arg2;
        set_swim_direction__8TObjFishFPv(o, o->dir);
        if (o->dir == 0) {
            ((TObjMotion *)o)->set_field_b8(9);
        } else {
            ((TObjMotion *)o)->set_field_b8(0xA);
        }
        o->phase = 0;
        o->timer = 0;
        o->idx = 0;
        o->interval = 0xB4;
        o->arg = 0x78;
        break;
    case 2:
        if (o->phase == 3) {
            if (o->dir == 0) {
                set_state_and_send__14TBoss7DeRolLeCFl(o, 0x15);
            } else {
                set_state_and_send__14TBoss7DeRolLeCFl(o, 0x16);
            }
        }
        break;
    case 9:
        if (o->phase == 3) {
            ((TBoss7DeRolLeC *)o)->advance_action_sequence();
        }
        break;
    case 0:
        advance_animation_playback(o);
        switch (o->phase) {
        case 0:
            o->timer++;
            if (o->timer > 0x28) {
                o->phase = 1;
                o->timer = 0;
                o->idx = 0;
            }
            break;
        case 1:
            o->timer++;
            if (o->timer >= o->interval) {
                o->timer = 0;
                if (((TObjEneDD_ST *)o)->enemy_has_live_target() != 0) {
                    VecCopy__FP3VecPC3Vec((int)&v, o->target + 0x38);
                } else {
                    f32 r = lbl_805DEA20 * calc_boss4_scale__10TObjPlayerFi(o);
                    ang = get_random_scaled__9TObjEneDDFv(o);
                    v.x = r * sin_table_lookup(ang);
                    v.y = lbl_805DEA24;
                    v.z = r * cos_table_lookup(ang);
                    TObjBoss2Tunnel::adjust_to_ground((s32)&v, (void *)&v);
                }
                ((TBoss7Tentacle *)(o->tent[o->idx]))->start_attack_at_position((u8 *)&v, (s32)o->arg);
                o->idx++;
                if (o->idx >= 4) {
                    o->timer = 0;
                    o->phase = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            o->timer++;
            for (i = 0; i < 4; i++) {
                if (TBoss7Tentacle__sub_802F0904(o->tent[i]) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || o->timer > 0x258) {
                o->phase = 3;
            }
            break;
        }
        break;
    case 6:
        ((TObjFish *)o)->pick_random_target();
        break;
    case 5:
        for (j = 0; j < 4; j++) {
            TBoss7Tentacle__sub_802F0AF0(o->tent[j]);
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
#define self ((Fish_802E9DBC *) arg0)
#pragma push
#pragma opt_common_subs off
void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2) {
    void *p_;
    switch (arg1) {
    case 4:
        ((TObjMotion *)self)->set_field_b8(1);
        TObjFish__sub_802ECBDC((Fish_802ECBDC *) self);
        self->flags |= 4;
        self->flags &= ~0x100;
        self->mode = arg2;
        TObjFish__sub_802ED4AC((u8 *)self, self->mode);
        self->f744 = lbl_805DEA10;
        self->f750 = lbl_805DEA10;
        self->f74C = lbl_805DEA10;
        self->f748 = lbl_805DEA10;
        self->f754 = lbl_805DEA8C;
        self->f758 = lbl_805DEA10;
        self->f75C = self->z;
        self->f760 = lbl_805DEA10;
        self->timer = 0;
        self->state = 0;
        self->tick = 0;
        self->ptcl = NULL;
        self->count = 0;
        break;
    case 2: {
        u32 f = *(u32 *)(self->f624 + 8);
        if (f & 0x400) {
            if (self->mode == 0) {
                set_state_and_send__14TBoss7DeRolLeCFl(self, 0x13);
            } else {
                set_state_and_send__14TBoss7DeRolLeCFl(self, 0x14);
            }
        } else if (f & 4) {
            if (self->mode == 0) {
                set_state_and_send__14TBoss7DeRolLeCFl(self, 0x15);
            } else {
                set_state_and_send__14TBoss7DeRolLeCFl(self, 0x16);
            }
        }
        break;
    }
    case 9:
        if (self->fB8 == 10 || self->fB8 == 9) {
            ((TBoss7DeRolLeC *)self)->advance_action_sequence();
        }
        break;
    case 0:
        advance_animation_playback(self);
        switch (self->state) {
        case 0:
            self->timer++;
            if (self->timer > 10) {
                self->timer = 0;
                self->state = 1;
                if (self->mode == 0) {
                    ((TObjMotion *)self)->set_field_b8(7);
                    self->f744 = lbl_805DEA70;
                } else {
                    ((TObjMotion *)self)->set_field_b8(8);
                    self->f744 = lbl_805DEA18;
                }
            }
            break;
        case 1:
            if (!(self->fB0 & 4)) {
                self->state = 2;
            }
            break;
        case 2:
            if (self->frame >= lbl_805DEA90) {
                self->state = 3;
                self->f750 = lbl_805DEA10;
                self->f748 = self->x;
                self->f74C = (lbl_805DEA94 * self->f744 - self->f748) / lbl_805DEA98;
                self->f754 = -(self->f758 / lbl_805DEA98);
                self->f75C = self->z;
                self->f758 = lbl_805DEA10;
            }
            break;
        case 3:
            if (self->frame >= lbl_805DEA4C) {
                self->state = 4;
                self->f750 = lbl_805DEA10;
                self->f748 = lbl_805DEA94 * self->f744;
                self->f74C = (lbl_805DEA9C * self->f744 - self->f748) / lbl_805DEA98;
                self->f75C = self->z;
                self->f754 = (lbl_805DEA44 * (lbl_805DEA50 - self->z)) / lbl_805DEAA0;
                self->f758 = lbl_805DEA10;
            }
            break;
        case 4:
            if (self->frame >= lbl_805DEA30) {
                self->state = 5;
                self->f750 = lbl_805DEA10;
                self->f748 = lbl_805DEA9C * self->f744;
                self->f74C = (lbl_805DEA94 * self->f744 - self->f748) / lbl_805DEAA4;
                self->f760 = (lbl_805DEAA8 * -self->f744) / lbl_805DEAA4;
            }
            break;
        case 5:
            if (self->frame >= lbl_805DEAAC) {
                s32 i;
                self->state = 6;
                TCameraCtrl::set_shake_preset(1);
                if (self->mode == 0) {
                    TObjBoss2Tunnel__sub_802F22DC();
                } else {
                    TObjBoss2Tunnel__sub_802F22C4();
                }
                TObjFish::set_effect_target_position(self, (void *) 0x3A107, self->eff);
                {
                    u32 o = __nw__7TObjectFUl(0x60);
                    if (o != 0) {
                        TBoss7LaserPtcl__sub_8035AE54((u8 *)o, (s32)self, (s32)&self->p4DC);
                    }
                }
                self->flags |= 0x200;
                for (i = 0; i < 4; i++) {
                    TBoss7Tentacle__sub_802F0B58((u8 *)self->tent[i]);
                }
            }
            break;
        case 6:
            break;
        }
        self->tick++;
        if (self->state != 0 && self->state != 1) {
            if (self->frame >= lbl_805DEAB0 && self->frame <= lbl_805DEAB4 && self->tick >= 2) {
                Vec_802E9DBC v;
                f32 s;
                self->tick = 0;
                ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->p4DC);
                s = lbl_805DEAB8 * calc_boss4_scale__10TObjPlayerFi(self);
                v.x = v.x - self->f744 * s;
                v.y = lbl_805DEA60;
                v.z = v.z + lbl_805DEABC;
                ((void (*)(void *, void *)) spawn_particle_201__8TObjFishFii)(self, &v);
            }
            if (objInBand((GameObj *)self, (f32)lbl_805DEAB0) != 0) {
                TObjFish::set_effect_target_position(self, (void *) 0x39905, self->eff);
            }
            p_ = self->ptcl;
            if (p_ == NULL) {
                self->ptcl = create_particle_emitter(&self->x, 0x161);
                if (self->ptcl != NULL) {
                    ((TParticleCtrl *)(self->ptcl))->enable();
                }
            } else if (self->frame >= lbl_805DEAC0 && self->frame <= lbl_805DEA5C) {
                s32 r;
                self->count++;
                r = self->count % 4;
                if (r == 0) {
                    ((TNowLoading *)(self->ptcl))->copy_pos(&self->p440);
                } else if (r == 2) {
                    ((TNowLoading *)(self->ptcl))->copy_pos(&self->p44C);
                } else {
                    ((TParticleCtrl *)(self->ptcl))->enable();
                }
            } else {
                ((TParticleCtrl *)p_)->enable();
            }
        }
        switch (self->state) {
        case 0:
        case 1:
        case 2:
            self->f758 = self->f758 + self->f754;
            if (self->f758 < lbl_805DEAC4) {
                self->f758 = lbl_805DEAC4;
            }
            self->z = self->z + self->f758;
            break;
        case 3: {
            f32 t = self->frame - lbl_805DEA90;
            self->x = self->f74C * t + self->f748;
            { f32 h_ = lbl_805DEA14 * self->f754; self->z = t * (h_ * t + lbl_805DEAC4) + self->f75C; }
            if (objInBand((GameObj *)self, (f32)lbl_805DEAC8) != 0) {
                TObjFish::set_effect_target_position(self, (void *) 0x39906, self->eff);
            }
            break;
        }
        case 4: {
            f32 t = self->frame - lbl_805DEA4C;
            self->x = self->f74C * t + self->f748;
            { f32 h_ = lbl_805DEA14 * self->f754; self->z = t * (h_ * t) + self->f75C; }
            self->f6F0 = lbl_805DEACC * t;
            if (self->f6F0 > lbl_805DEA6C) {
                self->f6F0 = lbl_805DEA6C;
            }
            break;
        }
        case 5: {
            f32 t = self->frame - 20.0f;
            f32 t2;
            f32 d;
            self->x = self->f74C * t + self->f748;
            t2 = self->frame - lbl_805DEA4C;
            { f32 h_ = lbl_805DEA14 * self->f754; d = t2 * (h_ * t2); }
            self->z = self->f75C + d;
            *(s32 *) ((u8 *) self + 0x64) = self->f760 * t;
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        self->flags &= ~4;
        if (self->ptcl != NULL) {
            queue_destruction__7TObjectFv(self->ptcl);
            self->ptcl = NULL;
        }
        break;
    }
}
#pragma pop
#undef self
#pragma pop

#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
void TObjFish__sub_802EA4D8(u8 *arg0, u32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjMotion *)arg0)->set_field_b8(1);
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)arg0);
        *(s32 *)((s8 *)arg0 + 0x628) |= 4;
        *(s32 *)((s8 *)arg0 + 0x628) &= ~0x100;
        *(s32 *)((s8 *)arg0 + 0x6C0) = 3;
        TObjFish__sub_802ED4AC(arg0, *(s32 *)((s8 *)arg0 + 0x6C0));
        *(s32 *)((s8 *)arg0 + 0x728) = 0;
        *(s32 *)((s8 *)arg0 + 0x730) = 0;
        *(s32 *)((s8 *)arg0 + 0x72C) = 0;
        *(f32 *)((s8 *)arg0 + 0x744) = lbl_805DEA10;
        *(f32 *)((s8 *)arg0 + 0x748) = lbl_805DEA10;
        *(f32 *)((s8 *)arg0 + 0x74C) = lbl_805DEA10;
        *(f32 *)((s8 *)arg0 + 0x750) = lbl_805DEA10;
        *(s32 *)((s8 *)arg0 + 0x734) = 0;
        break;
    case 2:
        if (*(s32 *)((s8 *)arg0 + 0x728) == 3) {
            set_state_and_send__14TBoss7DeRolLeCFl(arg0, 2);
        }
        break;
    case 9:
        if (*(s32 *)((s8 *)arg0 + 0x728) == 3) {
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (*(s32 *)((s8 *)arg0 + 0x728)) {
        case 0:
            (*(s32 *)((s8 *)arg0 + 0x730))++;
            if (*(s32 *)((s8 *)arg0 + 0x730) > 0x14) {
                ((TObjMotion *)arg0)->set_field_b8(4);
                *(s32 *)((s8 *)arg0 + 0x728) = 1;
            }
            *(f32 *)((s8 *)arg0 + 0x74C) -= lbl_805DEA74;
            if (*(f32 *)((s8 *)arg0 + 0x74C) < lbl_805DEAC4) {
                *(f32 *)((s8 *)arg0 + 0x74C) = lbl_805DEAC4;
            }
            *(f32 *)((s8 *)arg0 + 0x40) += *(f32 *)((s8 *)arg0 + 0x74C);
            break;
        case 1:
            if (!(*(s32 *)((s8 *)arg0 + 0xB0) & 4)) {
                *(s32 *)((s8 *)arg0 + 0x728) = 2;
            }
            break;
        case 2:
            switch (*(s32 *)((s8 *)arg0 + 0x72C)) {
            case 0:
                if (*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805DEAD0) {
                    *(s32 *)((s8 *)arg0 + 0x72C) = 1;
                    *(f32 *)((s8 *)arg0 + 0x750) = ((lbl_805DEAD8 * -*(f32 *)((s8 *)arg0 + 0x74C)) + (lbl_805DEAD4 - *(f32 *)((s8 *)arg0 + 0x40))) / lbl_805DEADC;
                    *(s32 *)((s8 *)arg0 + 0x734) = 0;
                }
                break;
            case 1:
                if (*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805DEAE0) {
                    *(s32 *)((s8 *)arg0 + 0x72C) = 2;
                    *(f32 *)((s8 *)arg0 + 0x744) = (lbl_805DEA6C * (lbl_805DEABC - *(f32 *)((s8 *)arg0 + 0x3C))) / lbl_805DEAE4;
                    *(f32 *)((s8 *)arg0 + 0x748) = (lbl_805DEA44 * *(f32 *)((s8 *)arg0 + 0x744)) / lbl_805DEAE4;
                    *(s32 *)((s8 *)arg0 + 0x734) = 0;
                }
                break;
            case 2:
                if (*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805DEAE8) {
                    *(s32 *)((s8 *)arg0 + 0x72C) = 3;
                    *(f32 *)((s8 *)arg0 + 0x74C) *= lbl_805DEA14;
                    *(f32 *)((s8 *)arg0 + 0x750) = lbl_805DEA10;
                }
                break;
            case 3:
                if (*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805DEAEC) {
                    *(s32 *)((s8 *)arg0 + 0x72C) = 4;
                }
                break;
            }
            if (*(s16 *)((s8 *)arg0 + 0xB8) != 1) {
                if (objInBand((GameObj *)arg0, (f32)lbl_805DEA6C) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805DEAE8)) != 0) {
                    TObjFish::set_effect_target_position(arg0, (void *)0x39905, arg0 + 0x50C);
                } else if (objInBand((GameObj *)arg0, (f32)lbl_805DEA54) != 0) {
                    TObjFish::set_effect_target_position(arg0, (void *)0x39906, arg0 + 0x50C);
                }
            }
            switch (*(s32 *)((s8 *)arg0 + 0x72C)) {
            case 1:
                (*(s32 *)((s8 *)arg0 + 0x734))++;
                if (*(f32 *)((s8 *)arg0 + 0xC0) >= lbl_805DEAF0 && *(s32 *)((s8 *)arg0 + 0x734) >= 2) {
                    Vec_802EA4D8 v;
                    *(s32 *)((s8 *)arg0 + 0x734) = 0;
                    VecCopy__FP3VecPC3Vec((int)&v, arg0 + 0x38);
                    v.x = lbl_805DEAB8 * calc_elapsed_scaled__9TObjEneDDFv(arg0) + v.x;
                    v.y = lbl_805DEA60;
                    v.z = v.z + lbl_805DEAF4;
                    spawn_particle_201__8TObjFishFii((s32)arg0, (s32)&v);
                }
                break;
            case 2:
            case 3:
                (*(s32 *)((s8 *)arg0 + 0x734))++;
                if (*(s32 *)((s8 *)arg0 + 0x734) >= 2) {
                    f32 f = *(f32 *)((s8 *)arg0 + 0xC0);
                    if (f >= lbl_805DEAF8 && f <= lbl_805DEAFC) {
                        Vec_802EA4D8 v;
                        *(s32 *)((s8 *)arg0 + 0x734) = 0;
                        VecCopy__FP3VecPC3Vec((int)&v, arg0 + 0x38);
                        v.x = lbl_805DEAB8 * calc_elapsed_scaled__9TObjEneDDFv(arg0) + v.x;
                        v.y = lbl_805DEA60;
                        v.z = v.z + lbl_805DEB00;
                        spawn_particle_201__8TObjFishFii((s32)arg0, (s32)&v);
                    }
                }
                break;
            }
            switch (*(s32 *)((s8 *)arg0 + 0x72C)) {
            case 0:
                *(f32 *)((s8 *)arg0 + 0x74C) -= lbl_805DEA74;
                if (*(f32 *)((s8 *)arg0 + 0x74C) < lbl_805DEAC4) {
                    *(f32 *)((s8 *)arg0 + 0x74C) = lbl_805DEAC4;
                }
                *(f32 *)((s8 *)arg0 + 0x40) += *(f32 *)((s8 *)arg0 + 0x74C);
                break;
            case 1:
                *(f32 *)((s8 *)arg0 + 0x74C) += *(f32 *)((s8 *)arg0 + 0x750);
                *(f32 *)((s8 *)arg0 + 0x40) += *(f32 *)((s8 *)arg0 + 0x74C);
                *(f32 *)((s8 *)arg0 + 0x744) = TObjFish__sub_802ED3E4(arg0);
                break;
            case 2:
                *(f32 *)((s8 *)arg0 + 0x40) += *(f32 *)((s8 *)arg0 + 0x74C);
                *(f32 *)((s8 *)arg0 + 0x6F0) += *(f32 *)((s8 *)arg0 + 0x744);
                *(f32 *)((s8 *)arg0 + 0x744) -= *(f32 *)((s8 *)arg0 + 0x748);
                *(f32 *)((s8 *)arg0 + 0xC0) -= lbl_805DEB04;
                break;
            case 3:
            case 4:
                if (*(f32 *)((s8 *)arg0 + 0x750) <= lbl_805DEA10) {
                    *(f32 *)((s8 *)arg0 + 0x74C) -= lbl_805DEA74;
                    if (*(f32 *)((s8 *)arg0 + 0x74C) <= lbl_805DEA10) {
                        *(f32 *)((s8 *)arg0 + 0x750) = lbl_805DEA18;
                        set_move_params__13TBoss2DeRolLeFPvffff(arg0 + 0x670, lbl_805DEA98, fabs_float(lbl_805DEB08 - *(f32 *)((s8 *)arg0 + 0x40)), lbl_805DEA74, lbl_805DEB0C);
                        *(f32 *)((s8 *)arg0 + 0x74C) = *(f32 *)((s8 *)arg0 + 0x40);
                    } else {
                        *(f32 *)((s8 *)arg0 + 0x40) += *(f32 *)((s8 *)arg0 + 0x74C);
                    }
                } else if (advance_scalar_motion_profile(arg0 + 0x670) == 3) {
                    *(s32 *)((s8 *)arg0 + 0x728) = 3;
                } else {
                    *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x74C) - *(f32 *)((s8 *)arg0 + 0x688);
                }
                ((TObjFish *)arg0)->update_wobble_angle();
                break;
            }
            break;
        }
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x6C0) = 1;
        *(s32 *)((s8 *)arg0 + 0x628) &= ~4;
        break;
    }
}
#pragma pop
#pragma pop

#define self ((Fish_802EAAC8 *) arg0)
void TObjFish__sub_802EAAC8(u8 *arg0, u32 arg1, s32 arg2, s32 arg3) {
    switch (arg1) {
    case 4:
        TObjFish__sub_802ECBDC((Fish_802ECBDC *) self);
        self->flags |= 4;
        self->flags &= ~0x100;
        self->mode = arg2;
        self->next_mode = arg3;
        TObjFish__sub_802ED4AC((u8 *)self, self->mode);
        if (self->mode == 0) {
            ((TObjMotion *)self)->set_field_b8(5);
            self->dir = lbl_805DEA70;
        } else {
            ((TObjMotion *)self)->set_field_b8(6);
            self->dir = lbl_805DEA18;
        }
        self->phase = 0;
        self->f72C = 0;
        self->step = 0;
        self->f748 = lbl_805DEA10;
        self->f74C = lbl_805DEA10;
        self->vx = lbl_805DEA10;
        self->ay = lbl_805DEA10;
        self->vy = lbl_805DEA10;
        self->tick = 0;
        break;
    case 2:
        if (self->phase == 2) {
            set_state_and_send__14TBoss7DeRolLeCFl(self, 2);
        }
        break;
    case 9:
        if (self->phase == 2) {
            if (self->flags & 0x800) {
                self->flags &= ~0x800;
                switch (self->next_mode) {
                case 0:
                    set_state_and_send__14TBoss7DeRolLeCFl(self, 0xF);
                    break;
                case 2:
                    set_state_and_send__14TBoss7DeRolLeCFl(self, 0x10);
                    break;
                case 1:
                default:
                    ((TBoss7DeRolLeC *)self)->advance_action_sequence();
                    break;
                }
            } else {
                ((TBoss7DeRolLeC *)self)->advance_action_sequence();
            }
        }
        break;
    case 0:
        switch (self->phase) {
        case 0:
            advance_animation_playback(self);
            if (!(self->fB0 & 4)) {
                self->phase = 1;
            }
            break;
        case 1:
            advance_animation_playback(self);
            switch (self->step) {
            case 0:
                if (self->frame >= lbl_805DEA50) {
                    self->step = 1;
                    self->vx = lbl_805DEB10 * self->dir;
                }
                break;
            case 1:
                if (self->frame >= lbl_805DEA30) {
                    self->step = 2;
                    self->vx = lbl_805DEB14 * self->dir;
                    self->ay = (lbl_805DEB1C * -self->vy + (lbl_805DEB18 - self->z)) / lbl_805DEB20;
                    self->ptcl = (s32)spawn_continuous_particle_effect_with_flags(self->ppos, 0x20F, 0x40);
                }
                break;
            case 2:
                if (self->frame >= lbl_805DEACC) {
                    self->step = 3;
                    self->f748 = (TObjFish__sub_802ED3E4((u8 *)self) - self->f748) / lbl_805DEB24;
                    self->f74C = (lbl_805DEA44 * self->f748) / lbl_805DEB28;
                    self->vx = lbl_805DEB2C * self->dir;
                    self->tick = 0;
                }
                break;
            case 3:
                if (self->frame >= lbl_805DEB30) {
                    self->step = 4;
                    self->vx = lbl_805DEB34 * self->dir;
                    set_move_params__13TBoss2DeRolLeFPvffff(self->mover, lbl_805DEA98, fabs_float(lbl_805DEAAC - self->z), lbl_805DEA74, lbl_805DEB0C);
                    self->f680 = -(lbl_805DEA14 * self->vy);
                    self->vy = self->z;
                    ((TObjFish *)self)->destroy_child();
                }
                break;
            case 4:
                if (self->frame >= lbl_805DEB38) {
                    self->step = 5;
                    self->vx = self->dir * ((lbl_805DEB3C - self->x * self->dir) / lbl_805DEB40);
                }
                break;
            case 5:
                if (self->frame >= lbl_805DEB44) {
                    self->step = 6;
                }
                break;
            }
            if (self->fB8 != 1) {
                if (objInBand((GameObj *)self, (f32)lbl_805DEA50) != 0 || objInBand((GameObj *)((GameObj *)self), (f32)((f32)lbl_805DEB48)) != 0) {
                    TObjFish::set_effect_target_position(self, (void *) 0x39905, self->eff);
                } else if (objInBand((GameObj *)self, (f32)lbl_805DEAAC) != 0) {
                    TObjFish::set_effect_target_position(self, (void *) 0x39906, self->eff);
                }
            }
            ((TObjFish *)self)->update_attached_orientation();
            self->tick++;
            if (self->step != 6) {
                f32 frame = self->frame;
                if (frame >= lbl_805DEAC0 && frame <= lbl_805DEB4C) {
                    if (self->tick >= 3) {
                        V_802EAAC8 v;
                        s32 i;
                        self->tick = 0;
                        ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->x);
                        for (i = 0; i < 10; i++) {
                            if (v.y * self->recs[i].y < lbl_805DEA10) {
                                break;
                            }
                            ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->recs[i]);
                        }
                        v.x = v.x - self->dir * (lbl_805DEA30 * calc_boss4_scale__10TObjPlayerFi(self) + lbl_805DEABC);
                        v.y = lbl_805DEA60;
                        v.z = v.z + (lbl_805DEA30 * calc_elapsed_scaled__9TObjEneDDFv(self) + lbl_805DEB50);
                        ((void (*)(void *, void *)) spawn_particle_201__8TObjFishFii)(self, &v);
                    }
                } else if (frame >= lbl_805DEB48 && frame <= lbl_805DEB38 && self->tick >= 3) {
                    V_802EAAC8 v;
                    self->tick = 0;
                    ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->x);
                    v.x = v.x + self->dir * (20.0f * calc_boss4_scale__10TObjPlayerFi(self) + 20.0f);
                    v.y = lbl_805DEA60;
                    v.z = v.z + (lbl_805DEB54 * calc_elapsed_scaled__9TObjEneDDFv(self) + lbl_805DEA50);
                    ((void (*)(void *, void *)) spawn_particle_201__8TObjFishFii)(self, &v);
                }
            }
            switch (self->step) {
            case 0:
                self->vy = self->vy - lbl_805DEA74;
                self->z = self->z + self->vy;
                break;
            case 1:
                self->x = self->x + self->vx;
                self->z = self->z + self->vy;
                break;
            case 2:
                self->x = self->x + self->vx;
                self->vy = self->vy + self->ay;
                self->z = self->z + self->vy;
                self->f748 = TObjFish__sub_802ED3E4((u8 *)self);
                break;
            case 3:
                self->x = self->x + self->vx;
                self->frame = self->frame - lbl_805DEB58;
                self->f6F0 = self->f6F0 + self->f748;
                self->f748 = self->f748 - self->f74C;
                self->z = self->z + self->vy;
                break;
            case 4:
                self->x = self->x + self->vx;
                ((TObjFish *)self)->update_wobble_angle();
                advance_scalar_motion_profile(self->mover);
                self->z = self->vy - self->f688;
                break;
            case 5:
                self->x = self->x + self->vx;
                ((TObjFish *)self)->update_wobble_angle();
                advance_scalar_motion_profile(self->mover);
                self->z = self->vy - self->f688;
                break;
            case 6:
                ((TObjFish *)self)->update_wobble_angle();
                if (advance_scalar_motion_profile(self->mover) == 3) {
                    self->phase = 2;
                }
                self->z = self->vy - self->f688;
                if (self->fB8 == 1) {
                    self->flags |= 0x100;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        self->mode = self->next_mode;
        self->flags &= ~4;
        break;
    }
}
#undef self
#pragma pop

#pragma push
#pragma opt_common_subs off
void TObjFish__sub_802EB90C(Fish_802EB90C *arg0, u32 arg1) {
    u32 b;
    switch (arg1) {
    case 4:
        ((TObjMotion *)arg0)->set_field_b8(1);
        TObjFish__sub_802ECBDC((Fish_802ECBDC *)arg0);
        arg0->flags628 &= ~4;
        arg0->flags628 |= 0x100;
        arg0->f6F0 = lbl_805DEA10;
        arg0->f64 = 0;
        arg0->f72C = 1;
        arg0->f730 = 0;
        arg0->f728 = 0;
        break;
    case 2:
        switch (arg0->state) {
        case 0:
            b = arg0->ctl->buttons;
            if (b & 0x10) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 3);
            } else if (b & 0x40) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 4);
            } else if (b & 0x20) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 5);
            } else if (b & 0x400) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x11);
            } else if (b & 4) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0xF);
            } else if (b & 2) {
                arg0->f40 = lbl_805DEB6C;
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 1);
            }
            break;
        case 1:
            b = arg0->ctl->buttons;
            if (b & 0x40) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 6);
            } else if (!(b & 0x20)) {
                if (b & 0x80) {
                    set_state_and_send__14TBoss7DeRolLeCFl(arg0, 8);
                } else if (b & 2) {
                    set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x1B);
                }
            }
            break;
        case 2:
            b = arg0->ctl->buttons;
            if (b & 0x20) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 9);
            } else if (b & 0x80) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0xA);
            } else if (b & 0x10) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0xB);
            } else if (b & 0x400) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x12);
            } else if (b & 4) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x10);
            } else if (b & 2) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x1B);
            }
            break;
        case 3:
            b = arg0->ctl->buttons;
            if (b & 0x80) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0xC);
            } else if (b & 0x10) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0xD);
            } else if (b & 0x40) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0xE);
            } else if (b & 4) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x17);
            } else if (!(b & 0x200) && (b & 2)) {
                set_state_and_send__14TBoss7DeRolLeCFl(arg0, 0x1C);
            }
            break;
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        if (!(arg0->fB0 & 4)) {
            arg0->fC8 -= lbl_805DEB70;
            if (arg0->fC8 < lbl_805DEB74) {
                arg0->fC8 = lbl_805DEB74;
            }
        }
        break;
    case 1:
        return;
    case 3:
        return;
    case 5:
        return;
    case 6:
        return;
    case 7:
        return;
    case 8:
        return;
    case 9:
        return;
    }
}
#pragma pop

void TObjFish__sub_802EBBC8(u8 *arg0, u32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjMotion *)arg0)->set_field_b8(0);
        TObjFish__sub_802ECC44((Fish_802ECC44 *) arg0);
        *(s32 *)((s8 *)arg0 + 0x628) &= ~4;
        *(s32 *)((s8 *)arg0 + 0x628) &= ~0x100;
        *(f32 *)((s8 *)arg0 + 0x6F0) = lbl_805DEA10;
        *(s32 *)((s8 *)arg0 + 0x728) = 0;
        *(s32 *)((s8 *)arg0 + 0x72C) = 0;
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)arg0)->get_target_state_b();
        break;
    case 2:
        if (*(s32 *)((s8 *)arg0 + 0x728) == 1) {
            *(s32 *)((s8 *)arg0 + 0x6C0) = 0;
            set_state_and_send__14TBoss7DeRolLeCFl(arg0, 2);
        }
        break;
    case 9:
        if (*(s32 *)((s8 *)arg0 + 0x728) == 1) {
            *(s32 *)((s8 *)arg0 + 0x6C0) = 0;
            ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
        }
        break;
    case 0:
        if (*(s32 *)((s8 *)arg0 + 0x72C) == 0) {
            if (query_teammate_state__9TObjEneDDFv() == 0) {
                Cam_802EBBC8 cam;
                cam.b = 0;
                cam.a = 1;
                cam.c = 0;
                cam.d = lbl_805DEA10;
                cam.e = lbl_805DEA28;
                activate_camera_mode(5);
                ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x1C71);
                *(s32 *)((s8 *)arg0 + 0x72C) = 1;
            }
        } else {
            advance_animation_playback(arg0);
            if (objInBand((GameObj *)arg0, (f32)lbl_805DEB54) != 0) {
                play_sound_effect((void *) 0x39E00, 0, 0, 0);
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805DEB78) != 0) {
                ((TObjFish *)arg0)->destroy_child();
                *(s32 *)((s8 *)arg0 + 0x7B0) = (s32)spawn_continuous_particle_effect_with_flags(arg0 + 0x7B4, 0x20F, 0x40);
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805DEB7C) != 0) {
                ((TObjFish *)arg0)->destroy_child();
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805DEA2C) != 0) {
                Vec_802EBBC8 v = lbl_80473F78;
                spawn_particle_effect_with_flags(&v, 0x20F, 0x40);
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805DEB80) != 0) {
                Vec_802EBBC8 w = lbl_80473F84;
                spawn_particle_effect_with_flags(&w, 0x20F, 0x40);
                play_sound_effect((void *) 0x39906, 0, 0, 0);
            }
            ((TObjFish *)arg0)->update_attached_orientation();
            if (*(u16 *) (get_scripted_camera_playback() + 2) & 1) {
                restore_player_cameras();
                ((TBoss7DeRolLeC *)arg0)->advance_action_sequence();
                *(s32 *)((s8 *)arg0 + 0x728) = 1;
            }
        }
        break;
    case 5:
        restore_player_cameras();
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)arg0)->get_target_state_a();
        break;
    }
}

void TObjFish__sub_802EBE50(void* o, u32 k) {
    switch (k) {
    case 4:
        ((TObjMotion *)o)->set_field_b8(1);
        return;
    case 2:
        set_state_and_send__14TBoss7DeRolLeCFl(o, 1);
        return;
    case 0:
        advance_animation_playback(o);
        return;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

struct Fish_802E8AD4;
void TBoss7DeRolLeC__dispatch_state(u8 *arg0, u32 arg1, u32 arg2) {
    s32 temp_r6;
    switch (arg1) {
    case 0x0:
        TObjFish__sub_802EBE50(arg0, arg2);
        return;
    case 0x1:
        TObjFish__sub_802EBBC8(arg0, arg2);
        return;
    case 0x2:
        TObjFish__sub_802EB90C((Fish_802EB90C *)(arg0), arg2);
        return;
    case 0x3:
        TObjFish__sub_802EB270(arg0, arg2, 0, 1);
        return;
    case 0x4:
        TObjFish__sub_802EAAC8(arg0, arg2, 0, 2);
        return;
    case 0x5:
        TObjFish__sub_802EB270(arg0, arg2, 0, 3);
        return;
    case 0x6:
        TObjFish__sub_802EB270(arg0, arg2, 1, 2);
        return;
    case 0x8:
        TObjFish__sub_802EB270(arg0, arg2, 1, 0);
        return;
    case 0x9:
        TObjFish__sub_802EB270(arg0, arg2, 2, 3);
        return;
    case 0xA:
        TObjFish__sub_802EAAC8(arg0, arg2, 2, 0);
        return;
    case 0xB:
        TObjFish__sub_802EB270(arg0, arg2, 2, 1);
        return;
    case 0xC:
        TObjFish__sub_802EB270(arg0, arg2, 3, 0);
        return;
    case 0xD:
        TObjFish__sub_802EA4D8(arg0, arg2);
        return;
    case 0xE:
        TObjFish__sub_802EB270(arg0, arg2, 3, 2);
        return;
    case 0x11:
        TObjFish__sub_802E9DBC(arg0, arg2, 0);
        return;
    case 0x12:
        TObjFish__sub_802E9DBC(arg0, arg2, 2);
        return;
    case 0x13:
        handle_tentacle_attack_state__8TObjFishFPvUii((Fish_802E9ADC *)(arg0), arg2, 0);
        return;
    case 0x14:
        handle_tentacle_attack_state__8TObjFishFPvUii((Fish_802E9ADC *)(arg0), arg2, 2);
        return;
    case 0x15:
        TObjFish__sub_802E979C((Fish_802E979C *)(arg0), arg2, 0);
        return;
    case 0x16:
        TObjFish__sub_802E979C((Fish_802E979C *)(arg0), arg2, 2);
        return;
    case 0xF:
        TObjFish__sub_802E95F8(arg0, arg2, 0);
        return;
    case 0x10:
        TObjFish__sub_802E95F8(arg0, arg2, 2);
        return;
    case 0x17:
        TObjFish__sub_802E9458(arg0, arg2);
        return;
    case 0x18:
        TBoss7LaserPtcl__sub_802E8FCC(arg0, arg2);
        return;
    case 0x19:
        TObjFish__sub_802E8EEC(arg0, arg2, 0);
        return;
    case 0x1A:
        TObjFish__sub_802E8EEC(arg0, arg2, 1);
        return;
    case 0x1B:
        TObjFish__sub_802E8E34(arg0, arg2);
        return;
    case 0x1C:
        ((TObjFish *)arg0)->handle_death_state(arg2);
        return;
    case 0x1D:
        TObjFish__sub_802E8AD4((Fish_802E8AD4*)((Fish_802E8AD4 *)arg0), arg2);
        return;
    case 0x28:
    case 0x29:
        temp_r6 = *(s32 *)((s8 *)arg0 + 0x6C0);
        if (temp_r6 < 5) {
            TObjFish__sub_802EB270(arg0, arg2, temp_r6, temp_r6 + 5);
            return;
        }
        TObjFish__sub_802EB270(arg0, arg2, temp_r6, temp_r6 - 5);
        return;
    case 0x2A:
        TObjFish__sub_802EB270(arg0, arg2, 6, 7);
        return;
    case 0x2B:
        TObjFish__sub_802EB270(arg0, arg2, 7, 8);
        return;
    case 0x2C:
        TObjFish__sub_802EB270(arg0, arg2, 8, 5);
        return;
    case 0x2D:
        TObjFish__sub_802EB270(arg0, arg2, 5, 6);
        return;
    case 0x2E:
        TObjFish__sub_802EB270(arg0, arg2, 6, 5);
        return;
    case 0x2F:
        TObjFish__sub_802EB270(arg0, arg2, 5, 8);
        return;
    case 0x30:
        TObjFish__sub_802EB270(arg0, arg2, 8, 7);
        return;
    case 0x31:
        TObjFish__sub_802EB270(arg0, arg2, 7, 6);
        return;
    case 0x32:
        TObjFish__sub_802EB270(arg0, arg2, 6, 9);
        return;
    case 0x33:
        TObjFish__sub_802EB270(arg0, arg2, 9, 8);
        return;
    case 0x34:
        TObjFish__sub_802EB270(arg0, arg2, 8, 9);
        return;
    case 0x35:
        TObjFish__sub_802EB270(arg0, arg2, 9, 6);
        return;
    case 0x36:
        TObjFish__sub_802EB270(arg0, arg2, 5, 9);
        return;
    case 0x37:
        TObjFish__sub_802EB270(arg0, arg2, 9, 7);
        return;
    case 0x38:
        TObjFish__sub_802EB270(arg0, arg2, 7, 9);
        return;
    case 0x39:
        TObjFish__sub_802EB270(arg0, arg2, 9, 5);
        return;
    case 0x3A:
        TBoss7DeRolLeC__handle_crawfish_spawn_state(arg0, arg2, 0);
        return;
    case 0x3B:
        TBoss7DeRolLeC__handle_crawfish_spawn_state(arg0, arg2, 1);
        return;
    case 0x3C:
        TBoss7DeRolLeC__handle_crawfish_spawn_state(arg0, arg2, 2);
        return;
    case 0x3D:
        TBoss7DeRolLeC__handle_crawfish_spawn_state(arg0, arg2, 3);
        return;
    case 0x3E:
        TObjFish__sub_802E8990(arg0, arg2);
        return;
    case 0x3F:
        TObjFish__sub_802E88F8(arg0, arg2);
        return;
    case 0x40:
        TObjFish__sub_802E85E0(arg0, arg2, 0);
        return;
    case 0x41:
        TObjFish__sub_802E85E0(arg0, arg2, 2);
        return;
    case 0x42:
        TObjFish__sub_802E8584(arg0, arg2);
        return;
    case 0x43:
        TObjFish__sub_802E8528(arg0, arg2);
        return;
    case 0x44:
        TObjFish__sub_802E83E8(arg0, arg2);
    default:
        return;
    }
}

void TObjFish::spawn_via_trap(s32 arg0, s32 arg1, s32 arg2) {
    play_persistent_sound(arg1, arg0, arg2, 0, 0);
}

void TObjFish::set_effect_target_position(void* p, void* a1, void* a2) { play_sound_effect(a1, a2, (void*)0, (void*)0); }

void TObjFish__sub_802EC32C(void) {  }

void TBoss7DeRolLeC::update_projectile_spawns() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;

    project_sound_origin_from_camera((s32)(arg0 + 0x38), (u8 *)(arg0 + 0x50C), lbl_805DEB68);
    project_sound_origin_from_camera((s32)(arg0 + 0x4C4), (u8 *)(arg0 + 0x518), lbl_805DEB68);
    temp_r31 = arg0 + 0x524;
    VecCopy__FP3VecPC3Vec((int)temp_r31, arg0 + 0x518);
    vec3_add_to((int)temp_r31, arg0 + 0x518);
    *(f32 *)((s8 *)temp_r31 + 0) = (f32) (*(f32 *)((s8 *)temp_r31 + 0) * lbl_805DEA14);
    *(f32 *)((s8 *)temp_r31 + 4) = (f32) (*(f32 *)((s8 *)temp_r31 + 4) * lbl_805DEA14);
    *(f32 *)((s8 *)temp_r31 + 8) = (f32) (*(f32 *)((s8 *)temp_r31 + 8) * lbl_805DEA14);
    if ((*(s32 *)((s8 *)arg0 + 0x628) & 0x100) && ((objInBand((GameObj *)(arg0), lbl_805DEA58) != 0) || (objInBand((GameObj *)(arg0), lbl_805DEA30) != 0))) {
        *(s32 *)((s8 *)arg0 + 0x6BC) = 0;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x6BC) <= 0x10) {
        if (*(s32 *)((s8 *)arg0 + 0x628) & 0x400) {
            TObjFish::spawn_via_trap((s32)arg0, 0x39704, (s32)(arg0 + 0x524));
        } else {
            TObjFish::spawn_via_trap((s32)arg0, 0x3A303, (s32)(arg0 + 0x524));
        }
        *(s32 *)((s8 *)arg0 + 0x6BC) = (s32) (*(s32 *)((s8 *)arg0 + 0x6BC) + 1);
    }
    if (*(s32 *)((s8 *)arg0 + 0x628) & 0x200) {
        TObjFish::spawn_via_trap((s32)arg0, 0x39F08, (s32)(arg0 + 0x50C));
    }
}

#pragma push
#pragma fp_contract on
void TObjFish__sub_802EC468(s32 arg0, f32 farg0, f32 farg1) {
    typedef char sp8_offset[(offsetof(Stack_802EC468, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802EC468, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802EC468, sp10) == 0x8) ? 1 : -1];
    Stack_802EC468 stack;
    VecCopy__FP3VecPC3Vec((int)((void *)&stack.sp8), (void *)arg0);
    stack.sp8 = -((*(f32 *)((s8 *)&lbl_804FF5E8.value + 0xC) * farg1) - stack.sp8);
    stack.spC -= (*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x10) * farg1) - farg0;
    stack.sp10 = -((*(f32 *)((s8 *)&lbl_804FF5E8.value + 0x14) * farg1) - stack.sp10);
    spawn_particle_effect_with_flags((&stack.sp8), 0x127, 0x40);
}
#pragma pop

void spawn_particle_201__8TObjFishFii(s32 arg1, s32 arg2) {
    spawn_default_particle__8TObjFishFv(arg2, 0x201);
}

void fn_802EC52C(s32 arg0, s32 arg1) {
    TObjFish__sub_802F18E8((void *)arg1);
}

#pragma push
#pragma fp_contract on
void TParticleCtrl__sub_802EC550(PCtrl_802EC550 *o) {
    Vec_802EC550 v;
    s32 p[3];
    s32 ok;
    s32 i;
    s32 k;
    f32 w;
    f32 off;
    f32 r;
    f32 kk;
    s32 j;
    s32 m;
    ok = 1;
    for (i = 0; i < 6; i++) {
        if (o->objs[i] == 0) {
            void *r;
            p[2] = 0;
            p[1] = 0;
            p[0] = 0;
            r = create_particle_controller_with_angles(o->pos, p, 0x200, 1, 0x40);
            if (r != 0) {
                o->objs[i] = r;
                ((TBoss4Type2 *)(o->objs[i]))->set_flags(2);
                ((TParticleCtrl *)(o->objs[i]))->enable();
            } else {
                for (ok = 0; ok < i; ok++) {
                    ((TParticleCtrl *)(o->objs[ok]))->enable();
                }
                ok = 0;
                break;
            }
        }
    }
    if (ok != 0) {
        if (o->idx == 0) {
            for (k = 0; k < 3; k++) {
                Vec_802EC550 *src = &o->pos[particle_pos_index_table[k]];
                r = fabs_float(src->y - lbl_805DEB84);
                w = lbl_804E3E48[k];
                if (r < lbl_805DEB64 * w) {
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, src);
                    w -= r;
                    v.y = lbl_805DEA60;
                    v.x += w;
                    ((TNowLoading *)(o->objs[k * 2]))->copy_pos(&v);
                    v.x -= lbl_805DEA44 * w;
                    ((TNowLoading *)(o->objs[k * 2 + 1]))->copy_pos(&v);
                } else {
                    ((TParticleCtrl *)(o->objs[k * 2]))->enable();
                    ((TParticleCtrl *)(o->objs[k * 2 + 1]))->enable();
                }
            }
        } else {
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, &o->pos[o->idx]);
            v.y = lbl_805DEA60;
            v.x += lbl_805DEA30;
            ((TNowLoading *)(o->objs[0]))->copy_pos(&v);
            v.x -= lbl_805DEABC;
            ((TNowLoading *)(o->objs[1]))->copy_pos(&v);
            for (j = 2; j < 6; j++) {
                ((TParticleCtrl *)(o->objs[j]))->enable();
            }
            o->idx = 0;
        }
        for (m = 0; m < 6; m++) {
            ((void (*)(void *, void *))fn_802EC52C)(o, o->objs[m]);
        }
    }
}
#pragma pop

void TBoss7DeRolLeC::advance_action_sequence() {
    s32 var_r30;
    s32 var_r4;
    do {
        var_r30 = 0;
        this->m_6d0 = (this->m_6d0 + 1);
        var_r4 = *(s32 *)((s8 *)(*(s32 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_802EC7F0_lbl_804E3C2C *)&lbl_804E3C2C).value) + (game_difficulty_selection * 4)) + 0) + (this->m_6d0 * 8)) + 0);
        switch (var_r4) {
        case 0x1E:
            if (calc_elapsed_scaled__9TObjEneDDFv(this) > lbl_805DEA10) {
                var_r4 = 8;
            } else {
                var_r4 = 6;
            }
            break;
        case 0x1F:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 5;
            } else {
                var_r4 = 9;
            }
            break;
        case 0x20:
            if (calc_elapsed_scaled__9TObjEneDDFv(this) > lbl_805DEA10) {
                var_r4 = 0xC;
            } else {
                var_r4 = 0xE;
            }
            break;
        case 0x21:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 3;
            } else {
                var_r4 = 0xB;
            }
            break;
        case 0x23:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 4;
            } else {
                var_r4 = 0xA;
            }
            break;
        case 0x24:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 0xF;
            } else {
                var_r4 = 0x10;
            }
            break;
        case 0x25:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 0x11;
            } else {
                var_r4 = 0x12;
            }
            break;
        case 0x26:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 0x13;
            } else {
                var_r4 = 0x14;
            }
            break;
        case 0x27:
            if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C4) == 0) {
                var_r4 = 0x15;
            } else {
                var_r4 = 0x16;
            }
            break;
        case 0x45:
            var_r30 = 1;
            this->m_6d0 = 1;
            break;
        }
    } while (var_r30 != 0);
    set_state_and_send__14TBoss7DeRolLeCFl(this, var_r4);
}

void TBoss7DeRolLeC__sub_802EC994(void* p) { *(s32*)((char*)p + 0x6b0) = 0; *(s32*)((char*)p + 0x6b4) = 0; }

void fn_802EC9A4(void *ene_dd, void *arg1) {
    enemy_set_target_id(ene_dd, (u16) *(s32 *)((s8 *)arg1 + 8));
    *(s32 *)((s8 *)ene_dd + 0x6B4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ((TObjEneDD *)ene_dd)->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void fn_802EC9F0(TObjEneDD *ene_dd, void *arg1) {
    *(s32 *)((s8 *)ene_dd + 0x6B4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ene_dd->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}
}
void handle_6xAA_barba_ray_boss_actions(void *arg0);
void handle_6xA9_barba_ray_boss_actions(void *arg0);
void handle_6xAA_barba_ray_boss_actions(void *boss7_joint) {
    void *x;
    ((TBoss7Joint *)boss7_joint)->read_state();
    x = get_enemy_entity(*(u16 *)((s8 *)boss7_joint + 0x2));
    if (x != NULL) {
        fn_802EC9A4(x, boss7_joint);
    }
}

void handle_6xA9_barba_ray_boss_actions(void *boss7_joint) {
    void *x;
    ((TBoss7Joint *)boss7_joint)->byteswap_action_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)boss7_joint + 0x2));
    if (x != NULL) {
        fn_802EC9F0((TObjEneDD *)x, boss7_joint);
    }
}
extern "C" {

void TBoss7DeRolLeC::sub_802ECAA4() {
    if (((Ply_802ECAA4 *)this)->state == 0x1C || ((Ply_802ECAA4 *)this)->state == 0x1D) {
    } else if (((Ply_802ECAA4 *)this)->state == 0x13 || ((Ply_802ECAA4 *)this)->state == 0x14) {
        advance_action_sequence();
    } else if (((Ply_802ECAA4 *)this)->state == 0x15 || ((Ply_802ECAA4 *)this)->state == 0x16) {
        set_state_and_send__14TBoss7DeRolLeCFl(((Ply_802ECAA4 *)this), 0x1C);
    } else {
        set_state_and_send__14TBoss7DeRolLeCFl(((Ply_802ECAA4 *)this), 0x1B);
    }
}

u8 TBoss7DeRolLeC::sub_802ECB10() {
    s32 var_r4;

    var_r4 = 0;
    if (((s32) this->m_718 <= 0) && !(*(s32 *)((s8 *)this + 0x628) & 4)) {
        var_r4 = 1;
    }
    return (u8)var_r4;
}

void TObjFish::set_hooked_effect_target() {
    *(s32 *)((s8 *)((u8 *)this) + 0x628) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x628) | 0x88);
    TObjFish::set_effect_target_position(this, (void *)0x3A312, ((u8 *)this) + 0x38);
}

void TObjFish::apply_damage_and_set_effect(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x6FC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x6FC) - (s32) (lbl_805DEA14 * (f32) arg1));
    TObjFish::set_effect_target_position(this, (void *)0x3B213, ((u8 *)this) + 0x38);
}

void TObjFish__sub_802ECBDC(Fish_802ECBDC *self) {
    s32 i;
    ((VObj_802ECBDC *)self)->v94();
    for (i = 0; i < 10; i++) {
        self->kids[i]->v94();
    }
}

void TObjFish__sub_802ECC44(Fish_802ECC44 *self) {
    s32 i;
    ((VObj_802ECC44 *)self)->v93();
    for (i = 0; i < 10; i++) {
        self->kids[i]->v93();
    }
}

void TObjFish::pick_random_target() {
    s32 n;
    u8 *p;
    s32 idx;
    s32 i;
    n = TLobby::get_game_mode();
    if (n == 0) {
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return;
    }
    if (n == 1) {
        p = (u8 *)get_player_data__10TObjPlayerFi(0);
        ((TObjEneDD_ST *)((u8 *)this))->set_target_player(p);
        return;
    }
    idx = (s32)get_random_float__21TObjEneMe3ShinowaRealFv((f32)n * calc_boss4_scale__10TObjPlayerFi(this));
    enemy_clear_target__12TObjEneDD_STFUs(this);
    for (i = 0; i < n; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(idx);
        if (is_alive__9TObjEneDDFv() != 0) {
            ((TObjEneDD_ST *)((u8 *)this))->set_target_player(p);
            return;
        }
        idx++;
        if (idx >= n) {
            idx = 0;
        }
    }
}

#undef release_laser_light__15TBoss7LaserPtclFPv
#undef set_swim_direction__8TObjFishFPv

#define VecCopy__FP3VecPC3Vec ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)


void release_laser_light__15TBoss7LaserPtclFPv(void *arg0) {
    void *temp_r3 = *(void **)((s8 *)arg0 + 0x708);
    if ((u32) temp_r3 != 0U) {
        ((TBoss7LaserLight *)temp_r3)->turn_off();
    }
    *(s32 *)((s8 *)arg0 + 0x628) = (s32) (*(s32 *)((s8 *)arg0 + 0x628) & 0xFFFFFFEF);
}

void TBoss7LaserPtcl::free_laser_light() {
    void *temp_r3 = *(void **)((s8 *)this + 0x708);
    if ((u32) temp_r3 != 0U) {
        ((TBoss7LaserLight *)temp_r3)->turn_on();
    }
    *(s32 *)((s8 *)this + 0x628) = (s32) (*(s32 *)((s8 *)this + 0x628) | 0x10);
}
#pragma push
#pragma fp_contract on
void TBoss7LaserPtcl__sub_802ECE28(u8 *arg0) {
    VecCopy__FP3VecPC3Vec(arg0 + 0x70C, arg0 + 0x4DC);
    *(f32 *)((s8 *)arg0 + 0x70C) = (f32) ((lbl_805DEA5C * *(f32 *)((s8 *)arg0 + 0x4E8)) + *(f32 *)((s8 *)arg0 + 0x70C));
    *(f32 *)((s8 *)arg0 + 0x710) = (f32) ((lbl_805DEA5C * *(f32 *)((s8 *)arg0 + 0x4EC)) + *(f32 *)((s8 *)arg0 + 0x710));
    *(f32 *)((s8 *)arg0 + 0x714) = (f32) ((lbl_805DEA5C * *(f32 *)((s8 *)arg0 + 0x4F0)) + *(f32 *)((s8 *)arg0 + 0x714));
}
}
#pragma pop
#undef VecCopy__FP3VecPC3Vec

#define VecCopy__FP3VecPC3Vec ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)

struct Boss_802ECE90 { u8 pad[0x530]; Vec pads[16]; u8 pad5F0[0x690 - 0x5F0]; u8 nodes[0x6C0 - 0x690]; s32 mode; };

void TObjFish__sub_802ECE90(void *arg0, int idx, int arg) {
    s32 angle;
    Vec dir;
    void *o;
    angle = 0x3800 - idx * 51;
    dir.x = sin_table_lookup(angle);
    dir.y = lbl_805DEA10;
    dir.z = cos_table_lookup(angle);
    if (((Boss_802ECE90 *)arg0)->mode == 2) {
        dir.x = dir.x * lbl_805DEA70;
    }
    o = TObject::operator new(0x38);
    if (o != NULL) {
        __ct__15TBoss7PhotonPadFllll((u8 *)o, (s32)((Boss_802ECE90 *)arg0)->nodes, (s32)&((Boss_802ECE90 *)arg0)->pads[idx], (s32)&dir, arg);
    }
    play_sound_effect((void *)0x39D11, &((Boss_802ECE90 *)arg0)->pads[idx], (void *)0, (void *)1);
}

struct RecoveredGlobal_802ED4AC_lbl_80472D04 {
    s32 value;
    u8 remaining[0x74];
};

struct Vec_802ED3E4 { f32 x, y, z; };

extern "C" {
extern RecoveredGlobal_802ED4AC_lbl_80472D04 lbl_80472D04;
void bind_motion_context(s32 arg0, f32 farg0);
void compose_motion_node_matrix(void *arg0);
s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix_from(void *);
extern u8 identity_matrix[];
s32 TBoss7Joint_get_shell_max_hp(void);

#pragma push
#pragma opt_common_subs off
u8 TObjFish::update_phase_rising() {
    f32 var_f2;
    s32 var_r3;
    advance_scalar_motion_profile(((u8 *)this) + 0x630);
    if (advance_scalar_motion_profile(((u8 *)this) + 0x650) == 3) {
        *(s32 *)((s8 *)((u8 *)this) + 0x6CC) = 1;
    }
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x6D0)) {
    case 2:
        break;
    case 1:
        var_f2 = *(f32 *)((s8 *)((u8 *)this) + 0x680) - lbl_805DEA7C;
        if (var_f2 < lbl_805DEB88) {
            var_f2 = lbl_805DEB88;
        }
        *(f32 *)((s8 *)((u8 *)this) + 0x680) = var_f2;
        *(f32 *)((s8 *)((u8 *)this) + 0x688) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x688) + var_f2);
        if (*(f32 *)((s8 *)((u8 *)this) + 0x648) > lbl_805DEA5C) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6D0) = 3;
        }
        break;
    case 3:
        if (advance_scalar_motion_profile(((u8 *)this) + 0x670) == 3) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6D0) = 4;
        }
        break;
    }
    *(f32 *)((s8 *)((u8 *)this) + 0xC8) += lbl_805DEA7C;
    if (*(f32 *)((s8 *)((u8 *)this) + 0xC8) > lbl_805DEB64) {
        *(f32 *)((s8 *)((u8 *)this) + 0xC8) = lbl_805DEB64;
    }
    var_r3 = 0;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6D0) == 4) && ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6CC) == 1)) {
        var_r3 = 1;
    }
    return var_r3;
}
#pragma pop

#pragma push
#pragma fp_contract on
u8 TObjFish::update_tail_anim_state() {
    s32 var_r3;
    advance_scalar_motion_profile(((u8 *)this) + 0x670);
    if (((s32)advance_scalar_motion_profile(((u8 *)this) + 0x650)) == 3) {
        *(s32 *)((s8 *)((u8 *)this) + 0x6CC) = 1;
    }
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x6C8)) {
    case 0:
        *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) lbl_805DEB68;
        if (*(f32 *)((s8 *)((u8 *)this) + 0x688) > lbl_805DEA94) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6C8) = 1;
        }
        break;
    case 1:
        if (((s32)advance_scalar_motion_profile(((u8 *)this) + 0x630)) == 3) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6C8) = 2;
        }
        break;
    }
    if (*(f32 *)((s8 *)((u8 *)this) + 0x688) > lbl_805DEA94) {
        *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) lbl_805DEB64;
    }
    var_r3 = 0;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C8) == 2) && ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6CC) == 1)) {
        var_r3 = 1;
    }
    return (u8) var_r3;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
u32 TObjFish::update_phase_settling() {
    u8 var_r3;
    advance_scalar_motion_profile((void *) (((u8 *)this) + 0x630));
    if (((s32)advance_scalar_motion_profile((void *) (((u8 *)this) + 0x650))) == 3) {
        *(s32 *)((s8 *)((u8 *)this) + 0x6CC) = 1;
    }
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x6D0)) {
    case 0:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x648) > lbl_805DEB8C) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6D0) = 2;
        }
        break;
    case 2:
        *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) lbl_805DEB68;
        *(s32 *)((s8 *)((u8 *)this) + 0x6D0) = 3;
        break;
    case 3:
        if (((s32)advance_scalar_motion_profile((void *) (((u8 *)this) + 0x670))) == 3) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6D0) = 4;
        }
        if (*(f32 *)((s8 *)((u8 *)this) + 0x688) > lbl_805DEB90) {
            *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0xC8) + lbl_805DEA7C);
            if (*(f32 *)((s8 *)((u8 *)this) + 0xC8) > lbl_805DEB64) {
                *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) lbl_805DEB64;
            }
        }
        break;
    }
    var_r3 = 0;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6D0) == 4) && ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6CC) == 1)) {
        var_r3 = 1;
    }
    return var_r3;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
u32 TObjFish::update_anim_state() {
    u8 var_r3;
    advance_scalar_motion_profile((void *) (((u8 *)this) + 0x670));
    if (((s32)advance_scalar_motion_profile((void *) (((u8 *)this) + 0x650))) == 3) {
        *(s32 *)((s8 *)((u8 *)this) + 0x6CC) = 1;
    }
    switch (*(s32 *)((s8 *)((u8 *)this) + 0x6C8)) {
    case 0:
        if (*(f32 *)((s8 *)((u8 *)this) + 0x688) > lbl_805DEB94) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6C8) = 1;
        }
        break;
    case 1:
        if (((s32)advance_scalar_motion_profile((void *) (((u8 *)this) + 0x630))) == 3) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6C8) = 2;
        }
        break;
    }
    *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0xC8) + lbl_805DEA7C);
    if (*(f32 *)((s8 *)((u8 *)this) + 0xC8) > lbl_805DEB64) {
        *(f32 *)((s8 *)((u8 *)this) + 0xC8) = (f32) lbl_805DEB64;
    }
    var_r3 = 0;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6C8) == 2) && ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x6CC) == 1)) {
        var_r3 = 1;
    }
    return var_r3;
}
#pragma pop

s32 TObjFish::is_all_parts_done() {
    u8 *arg0 = (u8 *)this;
    advance_scalar_motion_profile(arg0 + 0x670);
    advance_scalar_motion_profile(arg0 + 0x630);
    advance_scalar_motion_profile(arg0 + 0x650);
    if (((s32) *(s32 *)((s8 *)arg0 + 0x630) == 3) && ((s32) *(s32 *)((s8 *)arg0 + 0x650) == 3) && ((s32) *(s32 *)((s8 *)arg0 + 0x670) == 3)) {
        return 1;
    }
    return 0;
}

void TObjFish::update_wobble_angle() {
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)this + 0x6F0);
    if (temp_f2 > lbl_805DEB60) {
        *(f32 *)((s8 *)this + 0x6F0) = (f32) (temp_f2 - lbl_805DEB60);
        return;
    }
    if (temp_f2 < lbl_805DEB98) {
        *(f32 *)((s8 *)this + 0x6F0) = (f32) (temp_f2 + lbl_805DEB60);
        return;
    }
    *(f32 *)((s8 *)this + 0x6F0) = (f32) lbl_805DEA10;
}

f32 TObjFish__sub_802ED3E4(u8 *arg0) {
    Vec_802ED3E4 v;
    v.x = lbl_805DEA10;
    v.y = lbl_805DEA10;
    v.z = lbl_805DEA10;
    push_matrix_from(identity_matrix);
    scale_matrix(0, lbl_805DEB24, lbl_805DEB24, lbl_805DEB24);
    bind_motion_context(*(s32 *)((s8 *)arg0 + 0xF8), *(f32 *)((s8 *)arg0 + 0xC0));
    compose_motion_node_matrix((void *)(*(s32 *)((s8 *)arg0 + 0x34)));
    transform_point_by_current_matrix(&v, &v);
    pop_matrix();
    return v.y;
}

void set_swim_direction__8TObjFishFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x6C0) == 0) {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805DEB9C;
        *(s32 *)((s8 *)arg0 + 0x64) = 0x500;
    } else {
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) lbl_805DEA94;
        *(s32 *)((s8 *)arg0 + 0x64) = -0x500;
    }
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805DEA50;
    *(f32 *)((s8 *)arg0 + 0x6F0) = (f32) lbl_805DEA6C;
}

typedef char RecoveredGlobal_802ED4AC_lbl_80472D04_size[sizeof(RecoveredGlobal_802ED4AC_lbl_80472D04) == 0x78 ? 1 : -1];
void TObjFish__sub_802ED4AC(u8 *arg0, s32 arg1) {
    VecCopy__FP3VecPC3Vec(arg0 + 0x38, (u8 *)&lbl_80472D04.value + (arg1 * 0xC));
    *(f32 *)((s8 *)arg0 + 0x6F0) = (f32) (*(const f32 *)&lbl_805DEA10);
    *(s32 *)((s8 *)arg0 + 0x64) = 0;
}

s32 TBoss7Joint_get_shell_max_hp(void) {
    return *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0xF)) + 0x1C);
}

}
#undef VecCopy__FP3VecPC3Vec

#undef TObjFish__sub_802E7B40
#undef TObjFish__sub_802E7B94
#undef set_state_and_send__14TBoss7DeRolLeCFl

struct VB_802ED62C { u8 pad[0x18]; };

struct V_802ED62C : VB_802ED62C {
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
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85(s32, int);
};

struct PktA_802ED62C { u8 hdr[2]; u16 a; s16 b; s16 c; s32 d; };

struct PktB_802ED62C { u8 hdr[2]; u16 a; s16 b; s16 c; };

struct Elem_802ED73C { u8 pad0[0x18]; s32 flags; u8 pad1C[0x2C - 0x1C]; };

extern "C" {
void TBoss7Joint__sub_802EE7B8(void *);
void TBoss7Joint__sub_802EE800(void *);
s32 register_object__6TLobbyFl(s32);
s32 dispatch_shared_handler_b__6TLobbyFl(s32);
s32 register_boss__6TLobbyFl(s32);
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, s32, s32, s32);
void TBoss7PhotonBullet__sub_802ED5A0(void *arg0, int arg1);
s32 update_local_colliders_from_world(void *, void *);
#define VecCopy__FP3VecPC3Vec ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)
s32 add_radar_scaled_marker(void *, int, int, int, f32);
s32 set_player_state_default__12TBoss8DragonFv(void *);

f32 TBoss7PhotonBullet::get_target_pos_y() {
    return *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0xF)) + 4);
}

extern s32 lbl_80472D7C[];

void TBoss7PhotonBullet::emit_hit_effect(void *arg1) {
    TBoss7PhotonBullet__sub_802ED5A0(this, 2);
    TObjEneDD::emit_effect((void*)this, (int)arg1, (int)lbl_80472D7C);
    ((void (*)(void *, void *))TBoss7PhotonBullet__sub_802ED5A0)(this, *(void **)((s8 *)this + 0x62C));
}

void TBoss7PhotonBullet__sub_802ED5A0(void *arg0, int arg1) {
    s32 v;
    switch (arg1) {
    case 0:
    default:
        v = 0xF;
        break;
    case 1:
        v = 0x10;
        break;
    case 2:
        v = 0x11;
        break;
    }
    reload_stats_keep_hp_tp__9TObjEneDDFv(arg0, register_boss__6TLobbyFl(0xF), dispatch_shared_handler_b__6TLobbyFl(v), register_object__6TLobbyFl(0xF));
}

void TBoss7DeRolLeC::set_state_and_send(s32 arg1) {
    PktA_802ED62C pa;
    PktB_802ED62C pb;
    ((V_802ED62C *)((u8 *)this))->m85(arg1, 6);
    if (((arg1 - 0x13) <= 1U) || ((arg1 - 0x40) <= 1U) || (arg1 == 0x44) || (arg1 == 0x18)) {
        TBoss7Joint__sub_802EE800(&pa);
        pa.a = this->m_1c;
        pa.b = arg1;
        pa.c = (s16)this->m_6d0;
        pa.d = this->m_38c;
        ((TBoss7Joint *)(&pa))->broadcast_state();
        return;
    }
    TBoss7Joint__sub_802EE7B8(&pb);
    pb.a = this->m_1c;
    pb.b = arg1;
    pb.c = (s16)this->m_6d0;
    ((TBoss7Joint *)(&pb))->update_and_send_60();
}

void TBoss7DeRolLeC::flee_if_disturbed() {
    if (*(s32 *)((s8 *)this->m_a4 + 0x18) & 1) {
        set_player_state_default__12TBoss8DragonFv(this);
        add_radar_scaled_marker((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 1, lbl_805DEA44);
    }
}
void TBoss7DeRolLeC::vfunc_88() {
    u8 sp8[0xC];
    f32 f;
    s32 set;
    s32 clr;
    s32 i;
    VecCopy__FP3VecPC3Vec(sp8, ((u8 *)this) + 0x434);
    update_local_colliders_from_world(this, sp8);
    f = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    if (f < lbl_805DEA1C) {
        set = 0;
        clr = 7;
    } else if (f >= lbl_805DEA5C) {
        set = 5;
        clr = 2;
    } else {
        set = 3;
        clr = 4;
    }
    f = *(f32 *)((s8 *)((u8 *)this) + 0x40);
    if (f < lbl_805DEBA0 && lbl_805DEAF4 < f) {
        set = 0;
        clr = 7;
    }
    for (i = 0; i != this->body_count; i++) {
        (*(Elem_802ED73C * *)&this->m_a4)[i].flags |= set;
        (*(Elem_802ED73C * *)&this->m_a4)[i].flags &= ~clr;
    }
}

#undef VecCopy__FP3VecPC3Vec

#define VecCopy__FP3VecPC3Vec ((s32 (*)(s32, s32))VecCopy__FP3VecPC3Vec)
void TObjFish::sync_position_vectors() {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
    VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x2FC);
}
void TBoss7DeRolLeC::vfunc_61() {  }

void TBoss7DeRolLeC::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = this->hpmax - this->hp;
    if (*(s32 *)((s8 *)arg0 + 0x628) & 8) {
        this->m_718 = (s32) (this->m_718 - temp_r4);
        TObjFish__sub_802EC468((int) (*(s32 *)&this->m_a4 + 0x1C), lbl_805DEA44, lbl_805DEA48);
        TObjFish::set_effect_target_position(arg0, (void *)0x3B213, arg0 + 0x50C);
    } else {
        this->m_71c = (s32) (this->m_71c - temp_r4);
        if ((s32) this->m_71c < 0) {
            this->m_71c = 0;
            ((TObjFish *)arg0)->set_hooked_effect_target();
        }
    }
    this->hp = (s16) this->hpmax;
    ((TBoss7DeRolLeC *)arg0)->set_flag_800();
    ((TObjEneDD *)arg0)->clear_attack_receipts();
}

void TBoss7DeRolLeC::vfunc_63() {  }
void TBoss7DeRolLeC::vfunc_28() {  }

#undef VecCopy__FP3VecPC3Vec
#undef lbl_805DEA34
__declspec(section ".sdata2") const f32 lbl_805DEA34[1] = { 123.0f };
#define lbl_805DEA34 (lbl_805DEA34[0])
#undef lbl_805DEA38
__declspec(section ".sdata2") const f32 lbl_805DEA38[1] = { 12.0f };
#define lbl_805DEA38 (lbl_805DEA38[0])
#undef lbl_805DEA3C
__declspec(section ".sdata2") const f32 lbl_805DEA3C[1] = { -90.0f };
#define lbl_805DEA3C (lbl_805DEA3C[0])
#undef lbl_805DEA40
__declspec(section ".sdata2") const f32 lbl_805DEA40[1] = { -200.0f };
#define lbl_805DEA40 (lbl_805DEA40[0])
#undef lbl_805DEA44
__declspec(section ".sdata2") const f32 lbl_805DEA44[1] = { 2.0f };
#define lbl_805DEA44 (lbl_805DEA44[0])
#undef lbl_805DEA48
__declspec(section ".sdata2") const f32 lbl_805DEA48[1] = { 8.0f };
#define lbl_805DEA48 (lbl_805DEA48[0])
#undef lbl_805DEA4C
__declspec(section ".sdata2") const f32 lbl_805DEA4C[1] = { 13.0f };
#define lbl_805DEA4C (lbl_805DEA4C[0])
#undef lbl_805DEA50
__declspec(section ".sdata2") const f32 lbl_805DEA50[1] = { 10.0f };
#define lbl_805DEA50 (lbl_805DEA50[0])
#undef lbl_805DEA54
__declspec(section ".sdata2") const f32 lbl_805DEA54[1] = { 14.0f };
#define lbl_805DEA54 (lbl_805DEA54[0])
#undef lbl_805DEA58
__declspec(section ".sdata2") const f32 lbl_805DEA58[1] = { 3.0f };
#define lbl_805DEA58 (lbl_805DEA58[0])
#undef lbl_805DEA5C
__declspec(section ".sdata2") const f32 lbl_805DEA5C[1] = { 30.0f };
#define lbl_805DEA5C (lbl_805DEA5C[0])
#undef lbl_805DEA60
__declspec(section ".sdata2") const f32 lbl_805DEA60[1] = { -5.0f };
#define lbl_805DEA60 (lbl_805DEA60[0])
#undef lbl_805DEA64
__declspec(section ".sdata2") const f32 lbl_805DEA64[1] = { 80.0f };
#define lbl_805DEA64 (lbl_805DEA64[0])
#undef lbl_805DEA68
__declspec(section ".sdata2") const f32 lbl_805DEA68[1] = { -1000.0f };
#define lbl_805DEA68 (lbl_805DEA68[0])
#undef lbl_805DEA6C
__declspec(section ".sdata2") const f32 lbl_805DEA6C[1] = { 4.0f };
#define lbl_805DEA6C (lbl_805DEA6C[0])
#undef lbl_805DEA70
__declspec(section ".sdata2") const f32 lbl_805DEA70[1] = { -1.0f };
#define lbl_805DEA70 (lbl_805DEA70[0])
#undef lbl_805DEA74
__declspec(section ".sdata2") const f32 lbl_805DEA74[1] = { 0.2f };
#define lbl_805DEA74 (lbl_805DEA74[0])
#undef lbl_805DEA78
__declspec(section ".sdata2") const f32 lbl_805DEA78[1] = { 0.08f };
#define lbl_805DEA78 (lbl_805DEA78[0])
#undef lbl_805DEA7C
__declspec(section ".sdata2") const f32 lbl_805DEA7C[1] = { 0.1f };
#define lbl_805DEA7C (lbl_805DEA7C[0])
#undef lbl_805DEA80
__declspec(section ".sdata2") const f32 lbl_805DEA80[1] = { 256.0f };
#define lbl_805DEA80 (lbl_805DEA80[0])
#undef lbl_805DEA84
__declspec(section ".sdata2") const f32 lbl_805DEA84[1] = { 16384.0f };
#define lbl_805DEA84 (lbl_805DEA84[0])
#undef lbl_805DEA88
__declspec(section ".sdata2") const f32 lbl_805DEA88[1] = { -137.0f };
#define lbl_805DEA88 (lbl_805DEA88[0])
#undef lbl_805DEA8C
__declspec(section ".sdata2") const f32 lbl_805DEA8C[1] = { -0.2f };
#define lbl_805DEA8C (lbl_805DEA8C[0])
#undef lbl_805DEA90
__declspec(section ".sdata2") const f32 lbl_805DEA90[1] = { 6.0f };
#define lbl_805DEA90 (lbl_805DEA90[0])
#undef lbl_805DEA94
__declspec(section ".sdata2") const f32 lbl_805DEA94[1] = { 100.0f };
#define lbl_805DEA94 (lbl_805DEA94[0])
#undef lbl_805DEA98
__declspec(section ".sdata2") const f32 lbl_805DEA98[1] = { 7.0f };
#define lbl_805DEA98 (lbl_805DEA98[0])
#undef lbl_805DEA9C
__declspec(section ".sdata2") const f32 lbl_805DEA9C[1] = { 135.0f };
#define lbl_805DEA9C (lbl_805DEA9C[0])
#undef lbl_805DEAA0
__declspec(section ".sdata2") const f32 lbl_805DEAA0[1] = { 144.0f };
#define lbl_805DEAA0 (lbl_805DEAA0[0])
#undef lbl_805DEAA4
__declspec(section ".sdata2") const f32 lbl_805DEAA4[1] = { 5.0f };
#define lbl_805DEAA4 (lbl_805DEAA4[0])
#undef lbl_805DEAA8
__declspec(section ".sdata2") const f32 lbl_805DEAA8[1] = { 1280.0f };
#define lbl_805DEAA8 (lbl_805DEAA8[0])
#undef lbl_805DEAAC
__declspec(section ".sdata2") const f32 lbl_805DEAAC[1] = { 25.0f };
#define lbl_805DEAAC (lbl_805DEAAC[0])
#undef lbl_805DEAB0
__declspec(section ".sdata2") const f32 lbl_805DEAB0[1] = { 15.0f };
#define lbl_805DEAB0 (lbl_805DEAB0[0])
#undef lbl_805DEAB4
__declspec(section ".sdata2") const f32 lbl_805DEAB4[1] = { 17.0f };
#define lbl_805DEAB4 (lbl_805DEAB4[0])
#undef lbl_805DEAB8
__declspec(section ".sdata2") const f32 lbl_805DEAB8[1] = { 50.0f };
#define lbl_805DEAB8 (lbl_805DEAB8[0])
#undef lbl_805DEABC
__declspec(section ".sdata2") const f32 lbl_805DEABC[1] = { 40.0f };
#define lbl_805DEABC (lbl_805DEABC[0])
#undef lbl_805DEAC0
__declspec(section ".sdata2") const f32 lbl_805DEAC0[1] = { 24.0f };
#define lbl_805DEAC0 (lbl_805DEAC0[0])
#undef lbl_805DEAC4
__declspec(section ".sdata2") const f32 lbl_805DEAC4[1] = { -7.0f };
#define lbl_805DEAC4 (lbl_805DEAC4[0])
#undef lbl_805DEAC8
__declspec(section ".sdata2") const f32 lbl_805DEAC8[1] = { 8.5f };
#define lbl_805DEAC8 (lbl_805DEAC8[0])
#undef lbl_805DEACC
__declspec(section ".sdata2") const f32 lbl_805DEACC[1] = { 28.0f };
#define lbl_805DEACC (lbl_805DEACC[0])
#undef lbl_805DEAD0
__declspec(section ".sdata2") const f32 lbl_805DEAD0[1] = { 10.5f };
#define lbl_805DEAD0 (lbl_805DEAD0[0])
#undef lbl_805DEAD4
__declspec(section ".sdata2") const f32 lbl_805DEAD4[1] = { 300.0f };
#define lbl_805DEAD4 (lbl_805DEAD4[0])
#undef lbl_805DEAD8
__declspec(section ".sdata2") const f32 lbl_805DEAD8[1] = { 49.102562f };
#define lbl_805DEAD8 (lbl_805DEAD8[0])
#undef lbl_805DEADC
__declspec(section ".sdata2") const f32 lbl_805DEADC[1] = { 732.1581f };
#define lbl_805DEADC (lbl_805DEADC[0])
#undef lbl_805DEAE0
__declspec(section ".sdata2") const f32 lbl_805DEAE0[1] = { 16.0f };
#define lbl_805DEAE0 (lbl_805DEAE0[0])
#undef lbl_805DEAE4
__declspec(section ".sdata2") const f32 lbl_805DEAE4[1] = { 30.76923f };
#define lbl_805DEAE4 (lbl_805DEAE4[0])
#undef lbl_805DEAE8
__declspec(section ".sdata2") const f32 lbl_805DEAE8[1] = { 22.0f };
#define lbl_805DEAE8 (lbl_805DEAE8[0])
#undef lbl_805DEAEC
__declspec(section ".sdata2") const f32 lbl_805DEAEC[1] = { 29.0f };
#define lbl_805DEAEC (lbl_805DEAEC[0])
#undef lbl_805DEAF0
__declspec(section ".sdata2") const f32 lbl_805DEAF0[1] = { 13.5f };
#define lbl_805DEAF0 (lbl_805DEAF0[0])
#undef lbl_805DEAF4
__declspec(section ".sdata2") const f32 lbl_805DEAF4[1] = { 180.0f };
#define lbl_805DEAF4 (lbl_805DEAF4[0])
#undef lbl_805DEAF8
__declspec(section ".sdata2") const f32 lbl_805DEAF8[1] = { 21.0f };
#define lbl_805DEAF8 (lbl_805DEAF8[0])
#undef lbl_805DEAFC
__declspec(section ".sdata2") const f32 lbl_805DEAFC[1] = { 26.0f };
#define lbl_805DEAFC (lbl_805DEAFC[0])
#undef lbl_805DEB00
__declspec(section ".sdata2") const f32 lbl_805DEB00[1] = { -20.0f };
#define lbl_805DEB00 (lbl_805DEB00[0])
#undef lbl_805DEB04
__declspec(section ".sdata2") const f32 lbl_805DEB04[1] = { 0.105000004f };
#define lbl_805DEB04 (lbl_805DEB04[0])
#undef lbl_805DEB08
__declspec(section ".sdata2") const f32 lbl_805DEB08[1] = { 500.0f };
#define lbl_805DEB08 (lbl_805DEB08[0])
#undef lbl_805DEB0C
__declspec(section ".sdata2") const f32 lbl_805DEB0C[1] = { 0.05f };
#define lbl_805DEB0C (lbl_805DEB0C[0])
#undef lbl_805DEB10
__declspec(section ".sdata2") const f32 lbl_805DEB10[1] = { 3.25f };
#define lbl_805DEB10 (lbl_805DEB10[0])
#undef lbl_805DEB14
__declspec(section ".sdata2") const f32 lbl_805DEB14[1] = { -5.625f };
#define lbl_805DEB14 (lbl_805DEB14[0])
#undef lbl_805DEB18
__declspec(section ".sdata2") const f32 lbl_805DEB18[1] = { 270.0f };
#define lbl_805DEB18 (lbl_805DEB18[0])
#undef lbl_805DEB1C
__declspec(section ".sdata2") const f32 lbl_805DEB1C[1] = { 72.666664f };
#define lbl_805DEB1C (lbl_805DEB1C[0])
#undef lbl_805DEB20
__declspec(section ".sdata2") const f32 lbl_805DEB20[1] = { 1034.6666f };
#define lbl_805DEB20 (lbl_805DEB20[0])
#undef lbl_805DEB24
__declspec(section ".sdata2") const f32 lbl_805DEB24[1] = { 2.5f };
#define lbl_805DEB24 (lbl_805DEB24[0])
#undef lbl_805DEB28
__declspec(section ".sdata2") const f32 lbl_805DEB28[1] = { 56.666664f };
#define lbl_805DEB28 (lbl_805DEB28[0])
#undef lbl_805DEB2C
__declspec(section ".sdata2") const f32 lbl_805DEB2C[1] = { -6.5294123f };
#define lbl_805DEB2C (lbl_805DEB2C[0])
#undef lbl_805DEB30
__declspec(section ".sdata2") const f32 lbl_805DEB30[1] = { 45.0f };
#define lbl_805DEB30 (lbl_805DEB30[0])
#undef lbl_805DEB34
__declspec(section ".sdata2") const f32 lbl_805DEB34[1] = { -15.0f };
#define lbl_805DEB34 (lbl_805DEB34[0])
#undef lbl_805DEB38
__declspec(section ".sdata2") const f32 lbl_805DEB38[1] = { 46.0f };
#define lbl_805DEB38 (lbl_805DEB38[0])
#undef lbl_805DEB3C
__declspec(section ".sdata2") const f32 lbl_805DEB3C[1] = { -175.0f };
#define lbl_805DEB3C (lbl_805DEB3C[0])
#undef lbl_805DEB40
__declspec(section ".sdata2") const f32 lbl_805DEB40[1] = { 36.0f };
#define lbl_805DEB40 (lbl_805DEB40[0])
#undef lbl_805DEB44
__declspec(section ".sdata2") const f32 lbl_805DEB44[1] = { 64.0f };
#define lbl_805DEB44 (lbl_805DEB44[0])
#undef lbl_805DEB48
__declspec(section ".sdata2") const f32 lbl_805DEB48[1] = { 41.0f };
#define lbl_805DEB48 (lbl_805DEB48[0])
#undef lbl_805DEB4C
__declspec(section ".sdata2") const f32 lbl_805DEB4C[1] = { 32.0f };
#define lbl_805DEB4C (lbl_805DEB4C[0])
#undef lbl_805DEB50
__declspec(section ".sdata2") const f32 lbl_805DEB50[1] = { 70.0f };
#define lbl_805DEB50 (lbl_805DEB50[0])
#undef lbl_805DEB54
__declspec(section ".sdata2") const f32 lbl_805DEB54[1] = { 60.0f };
#define lbl_805DEB54 (lbl_805DEB54[0])
#undef lbl_805DEB58
__declspec(section ".sdata2") const f32 lbl_805DEB58[1] = { 0.19999999f };
#define lbl_805DEB58 (lbl_805DEB58[0])
#undef lbl_805DEB5C
__declspec(section ".sdata2") const f32 lbl_805DEB5C[1] = { 0.16f };
#define lbl_805DEB5C (lbl_805DEB5C[0])
#undef lbl_805DEB60
__declspec(section ".sdata2") const f32 lbl_805DEB60[1] = { 0.4f };
#define lbl_805DEB60 (lbl_805DEB60[0])
#undef lbl_805DEB64
__declspec(section ".sdata2") const f32 lbl_805DEB64[1] = { 0.9f };
#define lbl_805DEB64 (lbl_805DEB64[0])
#undef lbl_805DEB68
__declspec(section ".sdata2") const f32 lbl_805DEB68[1] = { 0.3f };
#define lbl_805DEB68 (lbl_805DEB68[0])
#undef lbl_805DEB6C
__declspec(section ".sdata2") const f32 lbl_805DEB6C[1] = { -210.0f };
#define lbl_805DEB6C (lbl_805DEB6C[0])
#undef lbl_805DEB70
__declspec(section ".sdata2") const f32 lbl_805DEB70[1] = { 0.03f };
#define lbl_805DEB70 (lbl_805DEB70[0])
#undef lbl_805DEB74
__declspec(section ".sdata2") const f32 lbl_805DEB74[1] = { 0.6f };
#define lbl_805DEB74 (lbl_805DEB74[0])
#undef lbl_805DEB78
__declspec(section ".sdata2") const f32 lbl_805DEB78[1] = { 83.0f };
#define lbl_805DEB78 (lbl_805DEB78[0])
#undef lbl_805DEB7C
__declspec(section ".sdata2") const f32 lbl_805DEB7C[1] = { 105.0f };
#define lbl_805DEB7C (lbl_805DEB7C[0])
#undef lbl_805DEB80
__declspec(section ".sdata2") const f32 lbl_805DEB80[1] = { 98.0f };
#define lbl_805DEB80 (lbl_805DEB80[0])
#undef lbl_805DEB84
__declspec(section ".sdata2") const f32 lbl_805DEB84[1] = { -10.0f };
#define lbl_805DEB84 (lbl_805DEB84[0])
#undef lbl_805DEB88
__declspec(section ".sdata2") const f32 lbl_805DEB88[1] = { -4.0f };
#define lbl_805DEB88 (lbl_805DEB88[0])
#undef lbl_805DEB8C
__declspec(section ".sdata2") const f32 lbl_805DEB8C[1] = { 160.0f };
#define lbl_805DEB8C (lbl_805DEB8C[0])
#undef lbl_805DEB90
__declspec(section ".sdata2") const f32 lbl_805DEB90[1] = { 200.0f };
#define lbl_805DEB90 (lbl_805DEB90[0])
#undef lbl_805DEB94
__declspec(section ".sdata2") const f32 lbl_805DEB94[1] = { 380.0f };
#define lbl_805DEB94 (lbl_805DEB94[0])
#undef lbl_805DEB98
__declspec(section ".sdata2") const f32 lbl_805DEB98[1] = { -0.4f };
#define lbl_805DEB98 (lbl_805DEB98[0])
#undef lbl_805DEB9C
__declspec(section ".sdata2") const f32 lbl_805DEB9C[1] = { -100.0f };
#define lbl_805DEB9C (lbl_805DEB9C[0])
#undef lbl_805DEBA0
__declspec(section ".sdata2") const f32 lbl_805DEBA0[1] = { -180.0f };
#define lbl_805DEBA0 (lbl_805DEBA0[0])
}
