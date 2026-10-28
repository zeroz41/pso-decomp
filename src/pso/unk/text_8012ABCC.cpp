#include "types.h"
#include "pso/player/TUnk_804A4B80.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
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
    virtual s32 m49(s32 *, s32, s32, s32);
};

struct VBase_18_382324
{
  char pad[0x18];
};

struct VObj_18_382324 : VBase_18_382324 {
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
    virtual s32 m49(void *, s32, s32, s32);
};

struct RecoveredFields_8012ABCC_arg0
{
  u8 unknown_0[0xF0];
  u32 field_F0;
};

struct PlB_8012AC68 { char pad[0x18]; };

struct Pl_8012AC68 : PlB_8012AC68 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void m49(void *, s32, s32, s32);
    u8 pad2[0xF0-0x1C];
    s32 f0;
    u8 pad3[0x1F8-0xF4];
    u8 f1f8[4];
};

extern "C" {
s32 send_activate_effect__5TItemFl(void *, int);
s32 get_current_floor();
u32 *copy_attack_targets(u32 *dst, u32 *src);
void spawn_heaven_effect__10TObjPlayerFlUlUsl(s32, s32, u32, s16);
s32 get_captured_target_collider_index(s32);
u32 get_uid__10TObjPlayerFv(s32);
s32 get_captured_target_entry(void *, s32);
s32 get_captured_target_count(void *);
extern s32 tl_05;

typedef struct RecoveredFields_8012ABCC_arg0 RecoveredFields_8012ABCC_arg0;
typedef struct VBase_18_382324 VBase_18_382324;
typedef struct VObj_18_382324 VObj_18_382324;
#define PSO_VCALL_VObj_18_382324_m49(_self, _arg0, _arg1, _arg2, _arg3) (((VObj_18_382324 *)(_self))->m49((_arg0), (_arg1), (_arg2), (_arg3)))
void TUnk_804A4B80::vfunc_17(s32 arg1) {
  if (((u32) ((RecoveredFields_8012ABCC_arg0 *) ((u8 *)this))->field_F0) != 0U)
  {
    if (are_items_enabled_here() != 0)
    {
      if (get_current_floor() == ((TObjPlayer *)((int) ((RecoveredFields_8012ABCC_arg0 *) ((u8 *)this))->field_F0))->get_field_3e4())
      {
        if (arg1 == 0)
        {
          PSO_VCALL_VObj_18_382324_m49(this, ((u8 *) ((u8 *)this)) + 0x224, 0, 0, 1);
          return;
        }
        if (arg1 == 1)
        {
          heaven_punisher_strike_locks();
        }
      }
    }
  }
}

void TUnk_804A4B80::heaven_punisher_strike_locks() {
    u8 buf[24];
    s16 v;
    s32 i;
    s32 e;
    Pl_8012AC68 *arg0 = (Pl_8012AC68 *)this;
    if (get_captured_target_count(arg0->f1f8) > 0) {
        for (i = 0; i != get_captured_target_count(arg0->f1f8); i++) {
            e = get_captured_target_entry(arg0->f1f8, i);
            v = get_captured_target_collider_index(e);
            spawn_heaven_effect__10TObjPlayerFlUlUsl(tl_05, arg0->f0, get_uid__10TObjPlayerFv(e), v);
        }
    } else {
        ((TItemWeapon *)arg0)->get_gun_point(buf);
        arg0->m49(buf, 0, 0, 1);
    }
}

void TUnk_804A4B80::emit_marker_effects() {
    s32 sp8;
    s32 var_r31;
    if (is_mode_two_and_ready() != 0) {
        copy_attack_targets((u32 *)((void *) (((u8 *)this) + 0x1F8)), (u32 *)((int) (((TObjPlayer *)(this->owner))->get_extended_state())));
        ((TItemWeapon *)((u8 *)this))->get_gun_point(((void *) (((u8 *)this) + 0x224)));
        var_r31 = 0;
        if (!((TLobby::get_internet_beat() / 100) & 1)) {
            var_r31 = 1;
        }
        send_activate_effect__5TItemFl(this, var_r31);
        return;
    }
    ((TItemWeapon *)((u8 *)this))->get_gun_point(&sp8);
    ((VObj_18 *)(this))->m49(&sp8, 0, 0, 1);
}
u32 *copy_attack_targets(u32 *dst, u32 *src) {
    u32 *d = dst;
    u32 b;
    u32 a;
    s32 i;
    *dst = *src;
    for (i = 0; i < 0x5; i++) {
        a = src[1];
        b = *(src += 2);
        d[1] = a;
        *(d += 2) = b;
    }
    return dst;
}

}
