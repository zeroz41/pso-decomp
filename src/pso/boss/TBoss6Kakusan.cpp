#include "types.h"
#include "pso/boss/TBoss6Kakusan.h"
#include "pso/system/vector.h"

#include "pso/boss/TBoss6Type1.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdLdQuestPrtGC.h"
#include "pso/TParticleCtrl.h"

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
extern const f32 TBoss6Kakusan__data_805DF518;
extern const f32 TBoss6Kakusan__data_805DF51C;
extern const f32 lbl_805DF53C;
u8 *TBoss6Kakusan__ct(u8 *arg0, s32 arg1, u8 *arg2, u8 *arg3, s16 arg4, f32 farg0);
extern const f32 lbl_805DF52C;
extern const f32 lbl_805DF530;
extern const f32 lbl_805DF534;
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
extern const f32 lbl_805DF538;
int get_player_data__10TObjPlayerFi(int a0);
extern const f32 lbl_805DF520;
extern const f32 lbl_805DF524;
extern const f32 lbl_805DF528;

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
    t = TBoss6Kakusan__data_805DF518;
    if (len > TBoss6Kakusan__data_805DF51C)
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
      f32 hi = ar + (lbl_805DF520 + y);
      f32 lo = y - ar;
      if ((!(py < (y - ar))) && (!(py > hi)))
      {
        VecCopy((Vec *)&q, (const Vec *)&p);
        subtract_vector(&q, pl + 0x38);
        q.y = TBoss6Kakusan__data_805DF518;
        if (vector_length(&q) <= lbl_805DF524)
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
      h.f = (f32) TBoss6PlotFalz::rand_vary_count(this->m_1c, lbl_805DF528);
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
    if (arg0->pos.y < lbl_805DF52C || arg0->pos.y > lbl_805DF530) {
        return 1;
    }
    V3_80322644 v = arg0->pos;
    v.y = TBoss6Kakusan__data_805DF518;
    return vector_length(&v) > lbl_805DF534;
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
        if (!(speed <= TBoss6Kakusan__data_805DF51C)) {
            pl = (u8 *)get_player_by_client_id(this->m_20);
            if (is_active__14TBoss6PlotFalzFv() != 0) {
                VecCopy((Vec *)&v, (const Vec *)(pl + 0x38));
                v.y += lbl_805DF538;
                subtract_vector(&v, (u8 *)&this->m_30);
                if (!(vector_length(&v) <= TBoss6Kakusan__data_805DF51C)) {
                    normalize_vector(&v);
                    v.x *= this->m_28;
                    v.y *= this->m_28;
                    v.z *= this->m_28;
                    VecCopy((Vec *)&w, (const Vec *)&this->m_3c);
                    normalize_vector(&w);
                    vec3_add_to(&v, &w);
                    if (!(vector_length(&v) <= TBoss6Kakusan__data_805DF51C)) {
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
u8 *TBoss6Kakusan__ct(u8 *boss6_kakusan, s32 arg1, u8 *arg2, u8 *arg3, s16 arg4, f32 farg0) {
    f32 temp_f2;
    u32 temp_r3;
    __ct__7TObjectFP7TObject((void *)boss6_kakusan, (void *)arg1);
    *(s32 **)((s8 *)boss6_kakusan + 0x18) = &(*(RecoveredGlobal_80322994___vt__13TBoss6Kakusan *)&__vt__13TBoss6Kakusan).value;
    *(s32 *)((s8 *)boss6_kakusan + 0) = (s32) TBoss6Kakusan__name;
    ((TBoss6Kakusan *)boss6_kakusan)->m_20 = arg4;
    ((TBoss6Kakusan *)boss6_kakusan)->m_24 = farg0;
    if (((TBoss6Kakusan *)boss6_kakusan)->m_24 <= TBoss6Kakusan__data_805DF518) {
        ((TBoss6Kakusan *)boss6_kakusan)->m_24 = (f32) lbl_805DF53C;
    }
    VecCopy((Vec *)(boss6_kakusan + 0x3C), (const Vec *)(arg3));
    if (vector_length(boss6_kakusan + 0x3C) <= TBoss6Kakusan__data_805DF51C) {
        *(f32 *)((s8 *)boss6_kakusan + 0x40) = (f32) lbl_805DF53C;
    }
    VecCopy((Vec *)(boss6_kakusan + 0x30), (const Vec *)(arg2));
    VecCopy((Vec *)(boss6_kakusan + 0x48), (const Vec *)(boss6_kakusan + 0x30));
    temp_f2 = *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2B)) + 4);
    ((TBoss6Kakusan *)boss6_kakusan)->m_1c = (s32) temp_f2;
    if (TBoss6Kakusan__data_805DF518 == temp_f2) {
        ((TBoss6Kakusan *)boss6_kakusan)->m_1c = 0x14;
    }
    ((TBoss6Kakusan *)boss6_kakusan)->m_28 = (f32) *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0x2F)) + 0x10);
    if (((TBoss6Kakusan *)boss6_kakusan)->m_28 < TBoss6Kakusan__data_805DF518) {
        ((TBoss6Kakusan *)boss6_kakusan)->m_28 = (f32) TBoss6Kakusan__data_805DF518;
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

u8 *TBoss6Type1::create_kakusan(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3, f32 farg0) {
    u8 *boss6_kakusan;
    u8 *var_r0;
    boss6_kakusan = (u8 *)(__nw__7TObjectFUl(0x58));
    var_r0 = boss6_kakusan;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(TBoss6Kakusan__ct(boss6_kakusan, arg0, arg1, arg2, arg3, farg0));
    }
    return var_r0;
}
