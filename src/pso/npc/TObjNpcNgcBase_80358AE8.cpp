#include "types.h"
#include "pso/unk/text_80359420.h"
#include "pso/npc/TObjNpcNgcBase_80358AE8.h"
#include "pso/npc/TObjNpcNgcBase.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct RecoveredGlobal_803591D0_TObjNpcNgcBase__data_805439A8
{
  u32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358D08_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8
{
  s32 value;
  u8 remaining[0x34];
};

struct Rec_803592B8 {
    s32 idx;
    void *data;
};

extern "C" {
s32 TObjControl__ct(int, int);
s32 __nw__7TObjectFUl(int);
extern RecoveredGlobal_803591D0_TObjNpcNgcBase__data_805439A8 TObjNpcNgcBase__data_805439A8;
extern s32 tl_04;
s32 TLobby__sub_8001FE7C(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern Rec_803592B8 npc_delta_w_body_model_names[];
typedef struct RecoveredGlobal_803591D0_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_803591D0_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_803591D0_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_803591D0_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];
s32 TObjNpcNgcBase::create_variant_13(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x34)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl((int) ((0, 0x20))));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x34))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__sub_80358B70(s32 arg0) {
  s32 temp_r3;
  s32 player;
  int new_var;
  s32 var_r0;
  s32 var_r30;
  new_var = 0x3B8;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x30)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(new_var);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358B70_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x30))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__sub_80358BF8(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x2C)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358BF8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x2C))));
    }
    return var_r0;
  }
  return 0;
}

typedef struct RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];
s32 TObjNpcNgcBase__sub_80358C80(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x28)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358C80_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x28))));
    }
    return var_r0;
  }
  return 0;
}

typedef struct RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358D08_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358D08_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358D08_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358D08_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];
s32 TObjNpcNgcBase__sub_80358D08(s32 arg0) {
  s8 *new_var;
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  new_var = (s8 *) (&(*(RecoveredGlobal_80358D08_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value);
  if (((u32) (*((u32 *)(new_var + 0x24)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *)(new_var + 0x24))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase::create_variant_8(s32 arg0) {
  s32 temp_r3;
  s32 player;
  u32 *new_var;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x20)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    var_r0 = __nw__7TObjectFUl(0x3B8);
    player = var_r0;
    var_r0 = player;
    if (var_r0 != 0)
    {
      new_var = (u32 *) (((s8 *) (&(*(RecoveredGlobal_80358D90_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x20);
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*new_var));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase::create_variant_7(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  s8 *new_var;
  new_var = (s8 *) (&(*(RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value);
  if (((u32) (*((u32 *)(new_var + 0x1C)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358E18_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x1C))));
    }
    return var_r0;
  }
  return 0;
}

typedef struct RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];
s32 TObjNpcNgcBase::create_variant_6(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x18)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358EA0_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x18))));
    }
    return var_r0;
  }
  return 0;
}

typedef struct RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];

typedef struct RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8 RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8;
typedef char RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8_size[((sizeof(RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8)) == 0x38) ? (1) : (-1)];
s32 TObjNpcNgcBase::create_variant_5(s32 arg0) {
  int new_var;
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x14)))) != 0U)
  {
    new_var = 0x20;
    temp_r3 = (var_r30 = __nw__7TObjectFUl((int) new_var));
    if (1)
    {
      if (var_r30 != 0)
      {
        var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
      }
      player = __nw__7TObjectFUl(0x3B8);
      var_r0 = player;
      if (var_r0 != 0)
      {
        var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358F28_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x14))));
      }
      return var_r0;
    }
  }
  return 0;
}

s32 TObjNpcNgcBase__sub_80358FB0(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x10)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl((int) ((0, 0x20))));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x10))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__sub_80359038(s32 arg0) {
  s32 player;
  s32 var_r0;
  s32 var_r30;
  s32 temp_r3;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0xC)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80359038_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0xC))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__sub_803590C0(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 8)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl(0x20));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player & 0xFFFFFFFFFFFFFFFF;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_803590C0_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 8))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__sub_80359148(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r30;
  if (((u32) (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x4)))) != 0U)
  {
    temp_r3 = (var_r30 = __nw__7TObjectFUl((int) ((0, 0x20))));
    if (var_r30 != 0)
    {
      var_r30 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r30, arg0, (*((u32 *) (((s8 *) (&(*(RecoveredGlobal_80358AE8_TObjNpcNgcBase__data_805439A8 *)&TObjNpcNgcBase__data_805439A8).value)) + 0x4))));
    }
    return var_r0;
  }
  return 0;
}

s32 TObjNpcNgcBase__create(s32 arg0) {
  s32 temp_r3;
  s32 player;
  s32 var_r0;
  s32 var_r31;
  if (((u32) TObjNpcNgcBase__data_805439A8.value) != 0U)
  {
    temp_r3 = (var_r31 = __nw__7TObjectFUl(0x20));
    if (var_r31 != 0)
    {
      var_r31 = TObjControl__ct((int) temp_r3, (int) tl_04);
    }
    player = __nw__7TObjectFUl(0x3B8);
    var_r0 = player;
    if (var_r0 != 0)
    {
      var_r0 = (s32)TObjNpcNgcBase__ct((u8 *)player, var_r31, arg0, TObjNpcNgcBase__data_805439A8.value);
    }
    return var_r0;
  }
  return 0;
}
void TObjNpcNgcBase::free_shared_resources() {
    s32 i;
    for (i = 0xd; i >= 0; i--) {
        if (((void * *)&TObjNpcNgcBase__data_805439A8)[i] != 0) {
            TLobby__sub_8001FE7C(((void * *)&TObjNpcNgcBase__data_805439A8)[i], 1);
            ((void * *)&TObjNpcNgcBase__data_805439A8)[i] = 0;
        }
    }
}
void TObjNpcNgcBase::load_resources() {
    Rec_803592B8 *p;
    s32 i;
    void *obj;
    Rec_803592B8 *tbl = npc_delta_w_body_model_names;
    for (i = 0; i < 14; i++) {
        ((u32 *)&TObjNpcNgcBase__data_805439A8)[i] = 0;
    }
    p = NULL;
    switch (TOKeyMachine01::get_global_state()) {
    case 0:
    case 0x12:
        p = &tbl[0x2A];
        break;
    case 0x17: case 0x18: case 0x19: case 0x1A: case 0x1B:
    case 0x22: case 0x23:
        p = &tbl[0x39];
        break;
    case 0x1C: case 0x1D:
        p = &tbl[0x3C];
        break;
    }
    if (p != NULL) {
        while (p->idx != -1) {
            obj = (void *)::operator new(0x440);
            if (obj != NULL) {
                obj = load_resource_from_descriptor(obj, 1, p->data, 0, 0, 0);
            }
            ((void **)&TObjNpcNgcBase__data_805439A8)[p->idx] = obj;
            p++;
        }
    }
}

}
