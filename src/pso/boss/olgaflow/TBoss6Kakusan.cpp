#include "types.h"
#include "pso/boss/olgaflow/TBoss6Kakusan.h"
#include "pso/system/vector.h"

#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdLdQuestPrtGC.h"
#include "pso/effect/particle/TParticleCtrl.h"

struct RecoveredGlobal_80322994___vt__13TBoss6Kakusan { s32 value; u8 remaining[0x14]; };

struct V3_80322644 { f32 x; f32 y; f32 z; };

struct Obj_80322644 { u8 pad[0x30]; V3_80322644 pos; };

struct Vec_803226C0 { f32 x, y, z; };

struct Vec_80322438
{
  f32 x;
  f32 y;
  f32 z;
};

struct Hit_80322438
{
  s32 a;
  s32 b;
  s32 c;
  f32 f;
};

struct Base_80322438
{
  char pad[0x18];
};

struct VObj_80322438 : Base_80322438 {
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
    virtual void m21(s32, void *, s32, s32, s32);
};

extern "C" {
u8 *__nw__7TObjectFUl(s32);
void *create_particle_emitter(void *pos, s32 id);
s32 __ct__7TObjectFP7TObject(void *, void *);
f32 vector_length(void *);
extern s32 __vt__13TBoss6Kakusan[];
extern s32 TBoss6Kakusan__name;
u8 *TBoss6Kakusan__ct(u8 *arg0, TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 speed);
void queue_destruction__7TObjectFv(void *);
s32 query_teammate_state__9TObjEneDDFv();
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
extern "C" {
void *get_player_by_client_id(s32 i);
s32 is_active__14TBoss6PlotFalzFv();
int TBoss6Kakusan__sub_8032263C(void);
void vec3_add_to(void *, void *);
void subtract_vector(void *, void *);
f32 normalize_vector(void *);
extern s32 TBoss6Kakusan__homing_start_frame;
extern u8 boss6_kakusan_homing_start_initialized;
extern s32 boss6_kakusan_homing_end_frame;
extern u8 TBoss6Kakusan__homing_end_frame_initialized;
int get_player_data__10TObjPlayerFi(int a0);

#pragma push
#pragma opt_propagation off
typedef struct Base_80322438 Base_80322438;
typedef struct Hit_80322438 Hit_80322438;
typedef struct VObj_80322438 VObj_80322438;
typedef struct Vec_80322438 Vec_80322438;
#define PSO_VCALL_VObj_80322438_m21(_self, _arg0, _arg1, _arg2, _arg3, _arg4) (((VObj_80322438 *)(_self))->m21((_arg0), (_arg1), (_arg2), (_arg3), (_arg4)))
void TBoss6Kakusan::check_beam_player_hits() {
    u8 *arg0 = (u8 *)this;
  Vec_80322438 dir;
  Vec_80322438 p;
  Vec_80322438 q;
  Hit_80322438 h;
  s32 n;
  s32 i;
  u8 *pl;
  s32 found;
  f32 len;
  f32 step;
  f32 t;
  n = TLobby::get_game_mode();
  for (i = 0; i < n; i++)
  {
    pl = (u8 *)get_player_data__10TObjPlayerFi(i);
    if (pl == 0)
    {
      continue;
    }
    step = this->m_24;
    found = 0;
    VecCopy((Vec *)&p, (const Vec *)&this->m_30);
    VecCopy((Vec *)&dir, (const Vec *)&this->m_48);
    subtract_vector(&dir, &p);
    len = vector_length(&dir);
    t = 0.0f;
    if (len > 1e-05f)
    {
      f32 s = step / len;
      dir.x *= s;
      dir.y *= s;
      dir.z *= s;
    }
    while (t <= len)
    {
      f32 y = *((f32 *) (((s8 *) pl) + 0x3C));
      f32 ar = this->m_24;
      f32 py = p.y;
      f32 hi = ar + (15.0f + y);
      f32 lo = y - ar;
      if ((!(py < (y - ar))) && (!(py > hi)))
      {
        VecCopy((Vec *)&q, (const Vec *)&p);
        subtract_vector(&q, pl + 0x38);
        q.y = 0.0f;
        if (vector_length(&q) <= 5.0f)
        {
          found = 1;
          break;
        }
      }
      t += step;
      vec3_add_to(&p, &dir);
    }
    if (found != 0)
    {
      h.f = (f32) TBoss6PlotFalz::rand_vary_count(this->m_1c, 0.1f);
      s32 z = 0;
      h.a = z;
      h.c = z;
      h.b = *((s32 *)&h.f);
      PSO_VCALL_VObj_80322438_m21(pl, *((s32 *) (((s8 *) arg0) + 0x10)), &h, 0, -1, -1);
    }
  }
}
#pragma pop

int TBoss6Kakusan__sub_8032263C(void) { return 0; }

s32 TBoss6Kakusan::is_out_of_range() {
    Obj_80322644 *arg0 = (Obj_80322644 *)this;
    if (arg0->pos.y < -200.0f || arg0->pos.y > 200.0f) {
        return 1;
    }
    V3_80322644 v = arg0->pos;
    v.y = 0.0f;
    return vector_length(&v) > 400.0f;
}

void TBoss6Kakusan::render() {  }

void TBoss6Kakusan::run_task() {
    u8 *arg0 = (u8 *)this;
    Vec_803226C0 v;
    Vec_803226C0 w;
    Vec_803226C0 b;
    Vec_803226C0 a;
    f32 speed;
    u8 *pl;
    if (TObjPlayer::check_demo_mode() != 0) return;
    if (query_teammate_state__9TObjEneDDFv() != 0) return;
    VecCopy((Vec *)&this->m_48, (const Vec *)&this->m_30);
    if ((s8)boss6_kakusan_homing_start_initialized == 0) {
        TBoss6Kakusan__homing_start_frame = 7;
        boss6_kakusan_homing_start_initialized = 1;
    }
    if ((s8)TBoss6Kakusan__homing_end_frame_initialized == 0) {
        boss6_kakusan_homing_end_frame = 0x25;
        TBoss6Kakusan__homing_end_frame_initialized = 1;
    }
    if (*(s32 *)&this->m_2c >= TBoss6Kakusan__homing_start_frame && *(s32 *)&this->m_2c <= boss6_kakusan_homing_end_frame) {
        speed = vector_length((u8 *)&this->m_3c);
        if (!(speed <= 1e-05f)) {
            pl = (u8 *)get_player_by_client_id(this->m_20);
            if (is_active__14TBoss6PlotFalzFv() != 0) {
                VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
                v.y += 10.0f;
                subtract_vector(&v, (u8 *)&this->m_30);
                if (!(vector_length(&v) <= 1e-05f)) {
                    normalize_vector(&v);
                    v.x *= this->m_28;
                    v.y *= this->m_28;
                    v.z *= this->m_28;
                    VecCopy((Vec *)&w, (const Vec *)&this->m_3c);
                    normalize_vector(&w);
                    vec3_add_to(&v, &w);
                    if (!(vector_length(&v) <= 1e-05f)) {
                        normalize_vector(&v);
                        v.x *= speed;
                        v.y *= speed;
                        v.z *= speed;
                        VecCopy((Vec *)&this->m_3c, (const Vec *)&v);
                    }
                }
            }
        }
    }
    vec3_add_to((u8 *)&this->m_30, (u8 *)&this->m_3c);
    if (*(void * *)&this->m_54 != NULL) {
        ((TParticleCtrl *)*(void * *)&this->m_54)->set_position((u8 *)&this->m_30);
        VecCopy((Vec *)&a, (const Vec *)&this->m_30);
        subtract_vector(&a, (u8 *)&this->m_48);
        direction_to_rotation_xz((u8 *)&a, (s32 *)&b.x, (s32 *)&b.z);
        *(s32 *)&b.y = 0;
        ((TParticleCtrl *)(*(void * *)&this->m_54))->set_direction(&b);
    }
    if (is_out_of_range() != 0 || ((int (*)(void *))TBoss6Kakusan__sub_8032263C)(arg0) != 0) {
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    check_beam_player_hits();
    *(s32 *)&this->m_2c += 1;
}

}
TBoss6Kakusan::~TBoss6Kakusan() {
    if (*(void **)((s8 *)this + 0x54) != NULL) { TParticleCtrl::release(*(void **)((s8 *)this + 0x54)); this->m_54 = 0; }
}


#pragma push
#pragma opt_common_subs off
u8 *TBoss6Kakusan__ct(u8 *boss6_kakusan, TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 speed) {
    f32 temp_f2;
    u32 temp_r3;
    __ct__7TObjectFP7TObject((void *)boss6_kakusan, parent);
    *(s32 **)((s8 *)boss6_kakusan + 0x18) = &(*(RecoveredGlobal_80322994___vt__13TBoss6Kakusan *)&__vt__13TBoss6Kakusan).value;
    *(s32 *)((s8 *)boss6_kakusan + 0) = (s32) TBoss6Kakusan__name;
    ((TBoss6Kakusan *)boss6_kakusan)->m_20 = target_client;
    ((TBoss6Kakusan *)boss6_kakusan)->m_24 = speed;
    if (((TBoss6Kakusan *)boss6_kakusan)->m_24 <= 0.0f) {
        ((TBoss6Kakusan *)boss6_kakusan)->m_24 = 1.0f;
    }
    VecCopy((Vec *)(boss6_kakusan + 0x3C), dir);
    if (vector_length(boss6_kakusan + 0x3C) <= 1e-05f) {
        *(f32 *)((s8 *)boss6_kakusan + 0x40) = 1.0f;
    }
    VecCopy((Vec *)(boss6_kakusan + 0x30), pos);
    VecCopy((Vec *)(boss6_kakusan + 0x48), (const Vec *)(boss6_kakusan + 0x30));
    temp_f2 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2B)) + 4);
    ((TBoss6Kakusan *)boss6_kakusan)->m_1c = (s32) temp_f2;
    if (0.0f == temp_f2) {
        ((TBoss6Kakusan *)boss6_kakusan)->m_1c = 0x14;
    }
    ((TBoss6Kakusan *)boss6_kakusan)->m_28 = (f32) *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2F)) + 0x10);
    if (((TBoss6Kakusan *)boss6_kakusan)->m_28 < 0.0f) {
        ((TBoss6Kakusan *)boss6_kakusan)->m_28 = 0.0f;
    }
    ((TBoss6Kakusan *)boss6_kakusan)->m_54 = (u32)create_particle_emitter((boss6_kakusan + 0x30), 0x214);
    temp_r3 = ((TBoss6Kakusan *)boss6_kakusan)->m_54;
    if (temp_r3 != 0U) {
        ((TParticleCtrl *)temp_r3)->set_flags(0x40);
    }
    ((TBoss6Kakusan *)boss6_kakusan)->m_2c = 0;
    return boss6_kakusan;
}
#pragma pop

u8 *TBoss6Type1::create_kakusan(TObject *parent, Vec *pos, Vec *dir, u16 target_client, f32 speed) {
    u8 *boss6_kakusan;
    u8 *var_r0;
    boss6_kakusan = (u8 *)(__nw__7TObjectFUl(0x58));
    var_r0 = boss6_kakusan;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TBoss6Kakusan__ct(boss6_kakusan, parent, pos, dir, target_client, speed));
    }
    return var_r0;
}
