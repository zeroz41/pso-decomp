#include "types.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804A4948.h"

struct VBase_18_24931d
{
  char pad[0x18];
};

struct VObj_18_24931d : VBase_18_24931d {
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
    virtual s32 m30();
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
    virtual s32 m49(s32 *, s32, s32, s32);
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
    virtual s32 m60();
};

struct Param_8012A508 { s32 kind; f32 val; };

struct VBase_8012A508 { char pad[0x18]; };

struct VObj_8012A508 : VBase_8012A508 {
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
    virtual void m21(u32, Param_8012A508 *, u8 *, s32, s32);
    u8 pad1c[0xA4 - 0x1C];
    u8 *recs;
};

struct Self_8012A508 { u8 pad[0xF0]; u32 fF0; u8 padF4[0x1F8 - 0xF4]; s32 mode; };

typedef struct Pl_8012A470
{
  u8 pad[0xF0];
  void *f0;
} Pl_8012A470;

extern "C" {
s8 get_mode__5TItemFv();
u8 * TObjPlayer__sub_8012A3B4(void *, s32, s32);
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
extern const f32 lbl_805DAE60;
extern const f32 lbl_805DAE64;
s32 get_extended_state__10TObjPlayerFv(void *);
s32 get_captured_target_collider_index(s32);
s32 get_captured_target_entry(s32, s32);
s32 get_captured_target_count(s32 *arg0);
s32 resolve_hittable_target(s32, s32);

u8 *TObjPlayer::create_state_8012a418(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != 0) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x218));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(TObjPlayer__sub_8012A3B4(temp_r3, tl_05, arg0));
        }
        return var_r0;
    }
    return NULL;
}

typedef struct Pl_8012A470 Pl_8012A470;
void TUnk_804A4948::send_srank_stat_extra_to_locks() {
  s32 st;
  s32 i;
  s32 e;
  u16 uid;
  s32 r;
  s32 v;
  st = get_extended_state__10TObjPlayerFv(((Pl_8012A470 *)this)->f0);
  if (st != 0)
  {
    for (i = 0; i != get_captured_target_count((s32 *)((((((((((((st & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF)); i++)
    {
      e = get_captured_target_entry(st, i);
      uid = ((TObjPlayer *)e)->get_uid();
      r = resolve_hittable_target(uid, v = (s16) ((unsigned long long) get_captured_target_collider_index(e)));
      if (r != 0)
      {
        this->send_srank_stat_extra(r, v);
      }
    }
  }
}

s32 TUnk_804A4948::send_srank_stat_extra(u32 arg1, s32 arg2) {
    Self_8012A508 *self = (Self_8012A508 *)this;
    VObj_8012A508 *obj = (VObj_8012A508 *)arg1;
    u32 f;
    Param_8012A508 t1;
    Param_8012A508 t2;
    if (obj != NULL && (f = self->fF0) != 0) {
        switch (self->mode) {
        case 1: {
            t1.kind = 0xB;
            t1.val = lbl_805DAE60;
            Param_8012A508 p = t1;
            obj->m21(f, &p, obj->recs + arg2 * 0x2C, -1, -1);
            break;
        }
        case 2: {
            t2.kind = 0xC;
            t2.val = lbl_805DAE64;
            Param_8012A508 p = t2;
            obj->m21(f, &p, obj->recs + arg2 * 0x2C, -1, -1);
            break;
        }
        }
    }
}
}
void receive_srank_hit(TItemWeapon *arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, f32 farg0);
void receive_srank_hit(TItemWeapon *item_weapon, s32 arg1, u32 arg2, s32 arg3, s32 arg4, f32 farg0) {
    u32 f;
    if (get_mode__5TItemFv() == 2) {
        f = *(u32 *)((s8 *)item_weapon + 0xF0);
        if ((f != 0U) && (arg2 != 0U)) {
            switch (*(s32 *)((s8 *)item_weapon + 0x1F8)) {
            case 1:
            case 2:
                if (arg3 == 2) {
                    ((TUnk_804A4948 *)item_weapon)->send_srank_stat_extra(arg2, arg4);
                } else {
                    item_weapon->deliver_hit((s32)f, (u8 *)arg2, (s32)arg3, (s32)arg4, (f32)farg0);
                }
                break;
            default:
                item_weapon->deliver_hit((s32)f, (u8 *)arg2, (s32)arg3, (s32)arg4, (f32)farg0);
                break;
            }
        }
    }
}
typedef struct VBase_18_24931d VBase_18_24931d;
typedef struct VObj_18_24931d VObj_18_24931d;
#define PSO_VCALL_VObj_18_24931d_m60(_self) (((VObj_18_24931d *)(_self))->m60())
#define PSO_VCALL_VObj_18_24931d_m30(_self) (((VObj_18_24931d *)(_self))->m30())
#define PSO_VCALL_VObj_18_24931d_m49(_self, _arg0, _arg1, _arg2, _arg3) (((VObj_18_24931d *)(_self))->m49((_arg0), (_arg1), (_arg2), (_arg3)))

void TUnk_804A4948::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
  s32 sp8;
  s32 temp_r0;
  s32 temp_r3;
  s32 new_var;
  PSO_VCALL_VObj_18_24931d_m60(arg0);
  temp_r3 = PSO_VCALL_VObj_18_24931d_m30(arg0);
  if (temp_r3 & 1)
  {
    temp_r0 = *((s32 *) (((s8 *) arg0) + 0x1F8));
    if (temp_r0 < 3)
    {
      if (temp_r0 < 1)
      {
        if ((arg0 && arg0) && arg0)
        {
        }
        goto block_7;
      }
      if (((TObjPlayer *)arg0)->is_mode_two_and_ready() != 0)
      {
        ((TUnk_804A4948 *)arg0)->send_srank_stat_extra_to_locks();
        return;
      }
      ((TObjPlayer *)arg0)->update_active_game_effect();
      return;
    }
    block_7:
    ((TObjPlayer *)arg0)->update_active_game_effect();
    return;
  }
  if ((new_var = temp_r3) & 2)
  {
    ((TObjPlayer *)arg0)->draw_status_icon((s32)&sp8);
    PSO_VCALL_VObj_18_24931d_m49(arg0, &sp8, 0, 0, 1);
  }
}
