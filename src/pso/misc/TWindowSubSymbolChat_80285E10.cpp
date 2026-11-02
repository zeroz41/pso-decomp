#include "types.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include "pso/misc/TWindowSubSymbolChat.h"

struct Rec_80285E10 { u8 a, b, c, d; };

struct Data_80285E10 { u8 pad[4]; u16 vals[4]; Rec_80285E10 recs[1]; };

extern "C" {
u16 *TWindowSubSymbolChatPartsSet__sub_802482B8(void *, s32);
u16 *get_parts_entry__28TWindowSubSymbolChatPartsSetFl(void *, s32);
u16 *get_parts_entry__28TWindowSubSymbolChatPartsSetFii(void *, s32);
s32 TWindowSubSymbolChat__sub_800771C4(int, int);
s32 get_data_ptr__20TWindowSubSymbolChatFv();

#pragma push
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
s32 TWindowSubSymbolChat::select_symbol_chat_record(s8 *arg1, s32 *arg2) {
    Data_80285E10 *temp_r28;
    s32 var_r31;
    s16 temp_r0;
    s32 temp_r3_2;
    s32 var_r29;
    u16 *temp_r28_2;
    u16 *temp_r29_2;
    u16 *temp_r3_3;
    u16 temp_r8;
    u32 temp_r4;
    u8 *temp_r29;
    s32 instance;
    *(s32 **)((s8 *)((u8 *)this) + 0x84) = arg2;
    *(*(s32 **)((s8 *)((u8 *)this) + 0x84)) = 0;
    instance = TWindowSubSymbolChat::get_instance();
    temp_r28 = (Data_80285E10 *)get_data_ptr__20TWindowSubSymbolChatFv();
    temp_r3_2 = TWindowSubSymbolChat::calc_remaining_slots();
    temp_r0 = *(s16 *)((s8 *)((u8 *)this) + 0x6E);
    if (temp_r3_2 > temp_r0) {
        *(f32 *)((s8 *)((u8 *)this) + 0x94) = 2.0f;
        temp_r29 = (u8 *)&temp_r28->recs[temp_r0];
        *(s32 *)((s8 *)((u8 *)this) + 0x74) = (s32) *(s16 *)((s8 *)((u8 *)this) + 0x6E);
        *(s32 *)((s8 *)((u8 *)this) + 0x78) = ((TWindowSubSymbolChat *)instance)->find_free_entry(0);
        var_r31 = 0;
        *(s16 *)((s8 *)((u8 *)this) + 0x6E) = (s16) (s8) *(u8 *)((s8 *)temp_r29 + 0);
        *(s16 *)((s8 *)((u8 *)this) + 0x6A) = (s16) *(u8 *)((s8 *)temp_r29 + 1);
        *(s16 *)((s8 *)((u8 *)this) + 0x6C) = (s16) *(u8 *)((s8 *)temp_r29 + 2);
        **(s32 **)((s8 *)((u8 *)this) + 0x7C) = *(u8 *)((s8 *)temp_r29 + 3) & 1;
        **(s32 **)((s8 *)((u8 *)this) + 0x80) = ((u8) *(u8 *)((s8 *)temp_r29 + 3) >> 1U) & 1;
        do {
            temp_r28_2 = get_parts_entry__28TWindowSubSymbolChatPartsSetFii(this, var_r31);
            temp_r29_2 = get_parts_entry__28TWindowSubSymbolChatPartsSetFl(this, var_r31);
            temp_r3_3 = TWindowSubSymbolChatPartsSet__sub_802482B8(this, var_r31);
            var_r31 += 1;
            *temp_r28_2 |= 2;
            *temp_r29_2 |= 2;
            *temp_r3_3 |= 2;
        } while (var_r31 < 4);
        *(s8 *)((s8 *)((u8 *)this) + 0x69) = 2;
        return 0;
    }
    *(s8 **)((s8 *)((u8 *)this) + 0x70) = arg1;
    var_r31 = 0;
    *(s8 *)((s8 *)((u8 *)this) + 0x69) = 3;
    var_r29 = *(s16 *)((s8 *)((u8 *)this) + 0x6E) - temp_r3_2;
    for (; var_r31 < 4; var_r31++) {
        if (TWindowSubSymbolChat__sub_800771C4(instance, var_r31) != 0) {
            if (var_r29-- <= 0) {
                temp_r4 = (u32) var_r31 >> 0x1FU;
                temp_r8 = temp_r28->vals[var_r31];
                *(s32 *)((s8 *)((u8 *)this) + 0x74) = var_r31;
                *(s32 *)((s8 *)((u8 *)this) + 0x78) = var_r31;
                *(s16 *)((s8 *)((u8 *)this) + 0x6A) = (s16) (((var_r31 & 1) ^ temp_r4) - temp_r4);
                *(s16 *)((s8 *)((u8 *)this) + 0x6C) = (s16) (var_r31 / 2);
                *(s16 *)((s8 *)((u8 *)this) + 0x6E) = (s16) (u8) temp_r8;
                **(s8 **)((s8 *)((u8 *)this) + 0x70) = (temp_r8 >> 8U) & 7;
                **(s32 **)((s8 *)((u8 *)this) + 0x7C) = (temp_r8 >> 0xBU) & 1;
                **(s32 **)((s8 *)((u8 *)this) + 0x80) = (temp_r8 >> 0xCU) & 1;
                return 1;
            }
        }
    }
    return 1;
}
#pragma pop

void TWindowSubSymbolChat::set_selection_and_refresh(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x74) = 0;
    *(s32 *)((s8 *)arg0 + 0x70) = arg1;
    *(s8 *)((s8 *)arg0 + 0x69) = 1;
    ((TWindowSubSymbolChatPartsSet *)arg0)->sub_8028625C();
}
void TWindowSubSymbolChat::init_symbol_layout(s32 *arg1) {
  s32 var_r29;
  u16 *temp_r30;
  u16 *temp_r31;
  u16 *temp_r3;
  s32 instance;
  *((s32 **) (((s8 *) ((u8 *)this)) + 0x84)) = arg1;
  *((f32 *) (((s8 *) ((u8 *)this)) + 0x94)) = 2.0f;
  if (((s32) (*arg1)) == 1)
  {
    *((s16 *) (((s8 *) ((u8 *)this)) + 0x6A)) = 0x14;
    *((s16 *) (((s8 *) ((u8 *)this)) + 0x6C)) = 0x20;
  }
  else
  {
    *((s16 *) (((s8 *) ((u8 *)this)) + 0x6A)) = 0x20;
    *((s16 *) (((s8 *) ((u8 *)this)) + 0x6C)) = 0x20;
  }
  var_r29 = 0;
  do
  {
    temp_r30 = (u16 *) get_parts_entry__28TWindowSubSymbolChatPartsSetFii(this, var_r29);
    temp_r31 = (u16 *) get_parts_entry__28TWindowSubSymbolChatPartsSetFl(this, var_r29);
    temp_r3 = (u16 *) TWindowSubSymbolChatPartsSet__sub_802482B8(this, var_r29);
    var_r29 += 1;
    *temp_r30 |= 2;
    *temp_r31 |= 2;
    *temp_r3 |= 2;
  }
  while (var_r29 < 4);
  instance = TWindowSubSymbolChat::get_instance();
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x74)) = ((TWindowSubSymbolChat *)instance)->find_free_entry(0);
  *((s32 *) (((s8 *) ((u8 *)this)) + 0x78)) = ((TWindowSubSymbolChat *)instance)->find_free_entry((*((s32 *) (((s8 *) ((u8 *)this)) + 0x74))) + 1);
  *((s8 *) (((s8 *) ((u8 *)this)) + 0x69)) = 0;
  ((TWindowSubSymbolChatPartsSet *)((u8 *)this))->sub_8028625C();
}

}
