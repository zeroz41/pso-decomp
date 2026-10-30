#include "pso/misc/MaterialOpacityFade.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_800C2A88.h"
#include "pso/unk/text_800C3A60.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneRe2Flower.h"
#include "pso/player/TObjPlayer.h"

struct VBase_18_9c7b63
{
  char pad[0x18];
};

struct VObj_18_9c7b63 : VBase_18_9c7b63 {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct Stack_800C2AC4
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};

struct VBase_14_00f1d1
{
  char pad[0x14];
};

struct RecoveredFields_800C2AC4_arg0
{
  u8 unknown_0[0x3C];
  f32 field_3C;
  u8 unknown_40[0x20];
  int field_60;
  u8 unknown_64[0x54];
  s16 field_B8;
  u8 unknown_BA[0x30A];
  int field_3C4;
  u8 unknown_3C8[0x48];
  int field_410;
  u8 unknown_414[0x10];
  f32 field_424;
};

extern "C" {
s32 TBoss8Dragon__sub_800BB7D4(void *, int);
s32 play_sound_effect(void *, void *, int, int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
f32 vec3_add_to(void *, void *);
extern const f32 lbl_805D9FAC;
extern const f32 lbl_805D9FC4;
extern const f32 lbl_805D9FC8;
extern const f32 lbl_805D9FCC;
typedef struct RecoveredFields_800C2AC4_arg0 RecoveredFields_800C2AC4_arg0;
typedef struct Stack_800C2AC4 Stack_800C2AC4;
typedef struct VBase_14_00f1d1 VBase_14_00f1d1;
typedef struct VBase_18_9c7b63 VBase_18_9c7b63;
typedef struct MaterialColorFade MaterialColorFade;
typedef struct VObj_18_9c7b63 VObj_18_9c7b63;

void fn_800C2A88(void *self, s32 msg) {
    switch (msg) {
    case 0:
        return;
    case 3:
        queue_destruction__7TObjectFv(self);
        return;
    }
}

void fn_800C2AC4(u8 *arg0, int arg1) {
  Stack_800C2AC4 stack;
  f32 temp_f1;
  switch (arg1)
  {
    return;
    case 4:
      ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_B8 = 5;
      (((TObjEneDD *)(arg0))->vfunc_96());
      ((TObjEneRe2Flower *)arg0)->clear_child_flags();
      ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_3C4 = (int) (((RecoveredFields_800C2AC4_arg0 *) arg0)->field_3C4 & 0xFFFFFFF7);
      ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
      TBoss8Dragon__sub_800BB7D4((void *) arg0, 0xF2);
      ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_410 = 0;
      ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_424 = (f32) lbl_805D9FAC;
      play_sound_effect((void *) fn_800C3A60((s32)arg0, 0x4003A812), arg0 + 0x38, 0, 0);
      TObjPlayer::play_effect_if_v2(-0x200);
      return;
    case 3:
      if (((int) ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_410) == 2)
    {
      ((TObjEneDD *)arg0)->transition_enemy_state(0xB);
    }
    case 5:
      return;
    case 0:
      switch (((RecoveredFields_800C2AC4_arg0 *) arg0)->field_410)
    {
      case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0)
      {
        ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_410 = 1;
        temp_f1 = lbl_805D9FC4 * sin_table_lookup((int) ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_60);
        stack.spC = lbl_805D9FAC;
        stack.sp8 = temp_f1;
        stack.sp10 = lbl_805D9FC4 * cos_table_lookup((int) ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_60);
        vec3_add_to(&stack.sp8, (void *) (arg0 - -0x38));
        if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0)
        {
          TObjPlayer::apply_effect_variant_a((s32)&stack.sp8, 0x32);
          fn_800D911C((Vec *)(&stack.sp8));
          ((TObjEneRe2Flower *)arg0)->fade.start_fade_out();
        }
        else
        {
          TObjPlayer__sub_800D9290((s32)&stack.sp8, 0x32);
          ((TObjPlayer *)(&stack.sp8))->spawn_ground_effect(0x46);
        }
      }
        (((TObjEneDD *)(arg0))->vfunc_102());
        return;
      case 1:
        if (((TObjEneRe2Flower *)arg0)->get_flag_11() != 0)
      {
        if ((((TObjEneRe2Flower *)arg0)->fade.decay_value_toward_floor()) != 0)
        {
          ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_410 = 2;
          return;
        }
      }
      else
      {
        ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_3C = (f32) (((RecoveredFields_800C2AC4_arg0 *) arg0)->field_3C - lbl_805D9FC8);
        ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_424 = (f32) (((RecoveredFields_800C2AC4_arg0 *) arg0)->field_424 + lbl_805D9FC8);
        if (((RecoveredFields_800C2AC4_arg0 *) arg0)->field_424 > lbl_805D9FCC)
        {
          ((RecoveredFields_800C2AC4_arg0 *) arg0)->field_410 = 2;
        }
      }
        break;
    }
      break;
  }
}

}
