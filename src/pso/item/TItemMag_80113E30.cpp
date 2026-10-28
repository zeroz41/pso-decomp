#include "types.h"
#include "pso/item/TItemData_801146A4.h"
#include "pso/item/TItemMagSub_80114524.h"
#include "pso/item/TItemMag_80113E30.h"
#include "pso/item/TItemMag.h"
#include "pso/item/TItemData.h"
#include "pso/item/TItemMagSub.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PhotonBlastGauge.h"

struct Obj_80113EDC { u8 pad[0x44]; u8 arr[1]; };

struct MagData_80113F64 { u8 pad[0xC]; u8 flags; u8 blasts; };

struct Mag_801143E8
{
  u8 pad[0xC];
  u8 flags;
  u8 blasts;
};

extern "C" {
void TItemMag__sub_80113EDC(Obj_80113EDC *self, s16 i, u8 v);
extern const u8 lbl_805DABC4[3];
extern const u8 lbl_805DABC0[2];
void *memset(void *, s32, u32);
int test_flags_any(void*, int);

int TItemMag::get_status_flag() { return this->m_18c & 0x10; }
void TItemMag__sub_80113E3C(void* p) { *(s8*)((char*)p + 0x0) = -32; }

void MagNodeOscillationState::copy_from(MagNodeOscillationState *src) {
    flags = src->flags;
    speed = src->speed;
    value = src->value;
    minimum = src->minimum;
    maximum = src->maximum;
}

u8 TItemMag__sub_80113E74(void* p) { return *(u8*)((char*)p + 0xe); }
s16 TItemMag::get_item_type() { return *(s16*)((char*)this + 0x0); }
s16 TItemMag::get_sync() { return *(s16*)((char*)this + 0x2); }
int TItemMag::is_active() { return (*(u32*)((char*)this + 0x334) >> 9) & 0x1; }
s32 TItemMag::get_sub_value() {
    s32 arg0 = (s32)this;
    return (s32) TItemMag__sub_80113EEC((void*)(arg0 + 0x4AC));
}

u8 obj_isState7_324(u8 *arg0) {
    return (u8) (*(s16 *)((s8 *)arg0 + 0x324) == 7);
}

void TItemMag__sub_80113EDC(Obj_80113EDC *self, s16 i, u8 v) {
    self->arr[i] = v;
}

f32 TItemMag__sub_80113EEC(void* p) { return *(f32*)((char*)p + 0x3c); }

extern f32 TItemMag__data_805DABA4;

void PhotonBlastGauge::clear_charge() {
    charge = TItemMag__data_805DABA4;
}

s32 TItemMag::get_mag_id() { return *(s32*)((char*)this + 0x0); }
f32 TItemMag::get_stat_f32() { return *(f32*)((char*)this + 0x8); }
int TItemMag::check_state_flag_1() { return test_flags_any((char*)this + 0x4, 1); }
void MagOwnerWatch::clear_flags(u32 mask) { flags &= ~mask; }
void MagOwnerWatch::set_flags(u32 mask) { flags |= mask; }
u32 MagOwnerWatch::test_flags(u32 mask) { return flags & mask; }

void TItemMag::add_photon_blast(u8 blast) {
    MagData_80113F64 *data = (MagData_80113F64 *)this;
    u8 ord;
    if (blast >= 6) {
        return;
    }
    if (((TItemMag *)data)->is_pb_registered(blast) != 0) {
        return;
    }
    if (!(data->flags & lbl_805DABC4[0])) {
        data->blasts |= blast;
        data->flags |= lbl_805DABC4[0];
    } else if (!(data->flags & 2)) {
        data->blasts |= blast << 3;
        data->flags |= lbl_805DABC4[1];
    } else if (!(data->flags & 4)) {
        ord = blast;
        if ((data->blasts & lbl_805DABC0[0]) < blast) {
            ord--;
        }
        if (((data->blasts & lbl_805DABC0[1]) >> 3) < blast) {
            ord--;
        }
        if (ord < 4) {
            data->blasts |= ord << 6;
        }
        data->flags |= lbl_805DABC4[2];
    }
}

void TItemMag::add_clamped_stat(s32 arg1) {
    *(s16 *)((s8 *)this + 2) = (s16) (*(s16 *)((s8 *)this + 2) + arg1);
    if (*(s16 *)((s8 *)this + 2) < 0) {
        *(s16 *)((s8 *)this + 2) = 0;
    }
    if (*(s16 *)((s8 *)this + 2) > 0x78) {
        *(s16 *)((s8 *)this + 2) = 0x78;
    }
}

void TItemMag::add_stat_clamped(s16 *arg0, s32 arg1) {
    *arg0 += arg1;
    if (*arg0 < 0) {
        *arg0 = 0;
    }
    if (*arg0 > 0xC8) {
        *arg0 = 0xC8;
    }
}
}

#pragma push
#pragma opt_propagation off
void mag_feed_add_mind(u8 *mag, s16 arg1) {
    s16 temp_r31;
    s16 mag_total_level;
    s16 temp_r3_2;
    s16 var_r30;
    var_r30 = arg1;
    temp_r31 = TItemData__sub_801146A4(mag);
    if ((var_r30 > 0) || ((var_r30 < 0) && (-var_r30 < temp_r31))) {
        mag_total_level = get_mag_total_level(mag);
        if (mag_total_level < 0xC8) {
            *(s16 *)((s8 *)mag + 0xA) = *(s16 *)((s8 *)mag + 0xA) + var_r30;
            return;
        }
        if (mag_total_level == 0xC8) {
            temp_r3_2 = 0x63 - temp_r31;
            if (temp_r3_2 < var_r30) {
                var_r30 = temp_r3_2;
            }
            *(s16 *)((s8 *)mag + 0xA) = *(s16 *)((s8 *)mag + 0xA) + var_r30;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off

void TItemMag__sub_80114198(u8 *mag, s16 arg1) {
    s16 temp_r31;
    s16 mag_total_level;
    s16 temp_r3_2;
    s16 var_r30;
    var_r30 = arg1;
    temp_r31 = TItemData__sub_801146C0(mag);
    if ((var_r30 > 0) || ((var_r30 < 0) && (-var_r30 < temp_r31))) {
        mag_total_level = get_mag_total_level(mag);
        if (mag_total_level < 0xC8) {
            *(s16 *)((s8 *)mag + 8) = *(s16 *)((s8 *)mag + 8) + var_r30;
            return;
        }
        if (mag_total_level == 0xC8) {
            temp_r3_2 = 0x63 - temp_r31;
            if (temp_r3_2 < var_r30) {
                var_r30 = temp_r3_2;
            }
            *(s16 *)((s8 *)mag + 8) = *(s16 *)((s8 *)mag + 8) + var_r30;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation off
void TItemMag::add_stat_level_capped(s16 arg1) {
    s16 temp_r31;
    s16 mag_total_level;
    s16 temp_r3_2;
    s16 var_r30;
    var_r30 = arg1;
    temp_r31 = TItemData__sub_801146DC(this);
    if ((var_r30 > 0) || ((var_r30 < 0) && (-var_r30 < temp_r31))) {
        mag_total_level = get_mag_total_level(this);
        if (mag_total_level < 0xC8) {
            *(s16 *)((s8 *)((u8 *)this) + 6) = *(s16 *)((s8 *)((u8 *)this) + 6) + var_r30;
            return;
        }
        if (mag_total_level == 0xC8) {
            temp_r3_2 = 0x63 - temp_r31;
            if (temp_r3_2 < var_r30) {
                var_r30 = temp_r3_2;
            }
            *(s16 *)((s8 *)((u8 *)this) + 6) = *(s16 *)((s8 *)((u8 *)this) + 6) + var_r30;
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void mag_feed_add_def(u8 *mag, s16 arg1) {
    s16 temp_r31;
    s16 mag_total_level;
    s16 temp_r3_2;
    s16 var_r30;
    var_r30 = arg1;
    temp_r31 = TItemData__sub_801146F8(mag);
    if ((var_r30 > 0) || ((var_r30 < 0) && (-var_r30 < temp_r31))) {
        mag_total_level = get_mag_total_level(mag);
        if (mag_total_level < 0xC8) {
            *(s16 *)((s8 *)mag + 4) = *(s16 *)((s8 *)mag + 4) + var_r30;
            return;
        }
        if (mag_total_level == 0xC8) {
            temp_r3_2 = 0x63 - temp_r31;
            if (temp_r3_2 < var_r30) {
                var_r30 = temp_r3_2;
            }
            *(s16 *)((s8 *)mag + 4) = *(s16 *)((s8 *)mag + 4) + var_r30;
        }
    }
}
#pragma pop

s32 TItemMag::is_pb_registered(u8 arg1) {
    s32 slot;
    s32 arg0 = (s32)this;

    if (arg1 < 6U) {
        slot = 0;
loop_2:
        if ((s32) arg1 == ((TItemMag *)arg0)->get_photon_blast_at_slot(slot)) {
            return 1;
        }
        slot += 1;
        if (slot == 3) {
            goto block_5;
        }
        goto loop_2;
    }
block_5:
    return 0;
}
typedef struct Mag_801143E8 Mag_801143E8;
s32 TItemMag::get_photon_blast_at_slot(s32 slot) {
    Mag_801143E8 *mag = (Mag_801143E8 *)this;
  int new_var;
  u8 used[6];
  s32 i;
  u8 ord;
  switch (slot)
  {
    case 0:
      if (mag->flags & lbl_805DABC4[0])
    {
      return mag->blasts & lbl_805DABC0[0];
    }
      break;
    case 1:
      if (mag->flags & lbl_805DABC4[1])
    {
      return (mag->blasts & lbl_805DABC0[1]) >> 3;
    }
      break;
    case 2:
      if (mag->flags & lbl_805DABC4[2])
    {
      memset(used, 0, 6);
      new_var = mag->blasts;
      u8 b = new_var;
      used[(u8) (b & lbl_805DABC0[0])] = 1;
      used[(u8) ((b & lbl_805DABC0[1]) >> 3)] = 1;
      ord = (b & lbl_805DABC0[2]) >> 6;
      for (i = 0; i < 6; i++)
      {
        if (used[i] != 1)
        {
          if (ord == 0)
          {
            return i;
          }
          ord--;
        }
      }
    }
      break;
  }
  return -1;
}
