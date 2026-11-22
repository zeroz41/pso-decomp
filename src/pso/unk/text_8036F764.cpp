#include "types.h"
#include <string.h>
#include "pso/unk/text_8036F764.h"


u8 prs_read_byte_at(u8 *arg0, u32 off) {
    u32 temp_r4;
    u32 temp_r5;
    temp_r5 = *(u32 *)((s8 *)arg0 + 0x24);
    if (temp_r5 > off) {
        return *(u8 *)((s8 *)(*(saddr *)((s8 *)arg0 + 4) + off) + 0);
    }
    temp_r4 = off - temp_r5;
    if (temp_r4 >= (u32) *(u32 *)((s8 *)arg0 + 0x1C)) {
        *(s32 *)((s8 *)arg0 + 0x2C) = 1;
        return 0U;
    }
    return *(u8 *)((s8 *)(*(saddr *)((s8 *)arg0 + 0x10) + temp_r4) + 0);
}

u8 *prs_next_output_byte(void *arg0) {
  u32 temp_r3;
  if ((((u32) (*((u32 *) (((s8 *) arg0) + 0x1C)))) >= 0x17FFU) != 0)
  {
    *((u32 *) (((s8 *) arg0) + 0x1C)) = 0U;
    memmove(*(u8 **)((s8 *)arg0 + 0x18) + *(s32 *)((s8 *)arg0 + 0x24), *(u8 **)((s8 *)arg0 + 0x10), 0x17FF);
    *((s32 *) (((s8 *) arg0) + 0x24)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x24))) + 0x17FF);
  }
  {
    u8 *base = *(u8 **)((s8 *)arg0 + 0x10);
    temp_r3 = *((u32 *) (((s8 *) arg0) + 0x1C));
    *((u32 *) (((s8 *) arg0) + 0x1C)) = (u32) ((temp_r3 + 1) & 0xFFFFFFFFFFFFFFFFu);
    return base + temp_r3;
  }
}
