#include "types.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/vector.h"
#include "pso/enemy/recon/TObjEneRecobox.h"
#include "pso/enemy/recon/TObjEneRecon.h"

struct Stack_8031EE54 {
    s32 sp8;
    f32 spC;
};

struct T_8031EDBC { u8 pad[0x424]; u16 ids[30]; };

struct Rec_8031EDF8
{
  u8 pad0[0x1C];
  u16 base;
  u8 pad1[0x3F4 - 0x1E];
  s32 count;
  u8 pad2[0x424 - 0x3F8];
  u16 ids[1];
};

extern s32 actor_frame_tick;

void TObjEneRecon::remove_tracked_id(s32 id) {
    T_8031EDBC *self = (T_8031EDBC *)this;
    s32 i;
    for (i = 0; i < 30; i++) {
        if (self->ids[i] == id) {
            self->ids[i] = 0xFFFF;
            return;
        }
    }
}

#pragma push
#pragma opt_propagation off
typedef struct Rec_8031EDF8 Rec_8031EDF8;
u16 TObjEneRecon::alloc_child_id() {
    Rec_8031EDF8 *o = (Rec_8031EDF8 *)this;
  s32 new_var;
  s32 i;
  s32 v;
  for (i = 0; i < o->count; i++)
  {
    if (o->ids[i] == 0xFFFF)
    {
      v = (0, o->base + i);
      new_var = i;
      o->ids[new_var] = v + 1;
      return o->ids[new_var];
    }
  }
  return 0xFFFF;
}
#pragma pop

void TObjEneRecobox::update_floor_probe() {
    u8 *arg0 = (u8 *)this;
    Stack_8031EE54 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += 15.0f;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)arg0 + 0x3E0) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 0x18);
            VecCopy((Vec *)(arg0 + 0x3E4), (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy((Vec *)(arg0 + 0x3E4), (const Vec *)&this->position);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x3E0) & 0x4000) {
        TObjEneRecon::set_active();
    }
}
