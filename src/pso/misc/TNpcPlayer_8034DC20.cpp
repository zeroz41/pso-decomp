#include "types.h"
#include "pso/misc/TNpcPlayer_8034DC20.h"
#include "pso/misc/TUnk_804F07C8.h"
#include "pso/misc/TNpcPlayer.h"
#include "pso/misc/TLobby.h"

struct RecoveredGlobal_8034DE10_lbl_80478C70 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8034DE70_lbl_80478C50 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8034DEA0_TNpcPlayer__data_804ABC90 {
    s32 value;
    u8 remaining[0x9FC];
};

struct RecoveredGlobal_801A51C0_lbl_80446980 {
    s32 value;
    u8 remaining[0x14];
};

struct VBase_18_dac7f3
{
  char pad[0x18];
};

struct VObj_18_dac7f3 : VBase_18_dac7f3 {
    virtual s32 m0(s32);
};

struct RecoveredGlobal_8034DC24_lbl_804F07C8
{
  s32 value;
  u8 remaining[0x14];
};

struct RecoveredGlobal_8034DC24_lbl_804F07C8;
extern "C" {
extern RecoveredGlobal_8034DE10_lbl_80478C70 party_position_table;
extern RecoveredGlobal_8034DE70_lbl_80478C50 npc_lobby_entry_positions;
s32 copy__10TNpcPlayerFPv(void *, void *, int);
extern RecoveredGlobal_8034DEA0_TNpcPlayer__data_804ABC90 TNpcPlayer__template_table;
extern RecoveredGlobal_801A51C0_lbl_80446980 lbl_80478C88;
extern RecoveredGlobal_801A51C0_lbl_80446980 lbl_80478C68;
s32 __dt__7TObjectFv(void *, int);
s32 obj_isState3_324__9TObjCharaFv(int);
s32 is_script_controlled__10TObjPlayerFv();
void *get_player_by_client_id(s32 i);
s32 __dl__7TObjectFPv(void *);
extern RecoveredGlobal_8034DC24_lbl_804F07C8 lbl_804F07C8;
void construct_partner__10TNpcPlayerFPviisPv(void *, u16, u16, s32, void *);
void *__nw__7TObjectFUl(u32);
void __ct__7TObjectFP7TObject(void *, void *);
extern void *tl_00;
void TUnk_804F07C8::run_task() {  }
typedef char RecoveredGlobal_8034DE10_lbl_80478C70_size[sizeof(RecoveredGlobal_8034DE10_lbl_80478C70) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_801A51C0_lbl_80446980_size[sizeof(RecoveredGlobal_801A51C0_lbl_80446980) == 0x18 ? 1 : -1];

typedef struct RecoveredGlobal_8034DC24_lbl_804F07C8 RecoveredGlobal_8034DC24_lbl_804F07C8;
typedef struct VBase_18_dac7f3 VBase_18_dac7f3;
typedef struct VObj_18_dac7f3 VObj_18_dac7f3;
#pragma opt_pointer_analysis on
typedef char RecoveredGlobal_8034DC24_lbl_804F07C8_size[((sizeof(RecoveredGlobal_8034DC24_lbl_804F07C8)) == 0x18) ? (1) : (-1)];
#define PSO_VCALL_VObj_18_dac7f3_m0(_self, _arg0) (((VObj_18_dac7f3 *)(_self))->m0((_arg0)))
u8 *__dt__13TUnk_804F07C8Fv(u8 *arg0, s16 arg1) {
  s32 var_r31;
  u8 *player;
  if (arg0 != 0)
  {
    var_r31 = 0;
    *((s32 **) (((s8 *) arg0) + 0x18)) = &lbl_804F07C8.value;
    do
    {
      player = (u8 *) get_player_by_client_id(var_r31);
      if (player != 0)
      {
        if (is_script_controlled__10TObjPlayerFv() != 0)
        {
          if (player != 0)
          {
            PSO_VCALL_VObj_18_dac7f3_m0(player, 1);
          }
        }
        else
          if (((obj_isState3_324__9TObjCharaFv((int) player) != 0) && (((TNpcPlayer *)player)->get_action_flags() == ((-1U) & 0xFFFFu))) && (player != 0))
        {
          PSO_VCALL_VObj_18_dac7f3_m0(player, 1);
        }
      }
      var_r31 += 1;
    }
    while (var_r31 < 4);
    __dt__7TObjectFv((void *) arg0, 0);
    if (arg1 > 0)
    {
      __dl__7TObjectFPv((void *) arg0);
    }
  }
  return arg0;
}

u8 *TNpcPlayer::construct_party_area(void *parent) {
    void *task;
    s32 slot;
    u8 *player;
    __ct__7TObjectFP7TObject(this, parent);
    *(void **)((s8 *)((u8 *)this) + 0x18) = &lbl_804F07C8;
    this->m_1c = 0;
    for (slot = 0; slot < 4; slot++) {
        player = (u8 *)get_player_by_client_id(slot);
        if (player == NULL || ((s32 (*)(u8 *)) obj_isState3_324__9TObjCharaFv)(player) == 0 || ((TNpcPlayer *)player)->get_action_flags() == 0xFFFF) {
            continue;
        }
        task = __nw__7TObjectFUl(0xE8);
        if (task != NULL) {
            construct_partner__10TNpcPlayerFPviisPv(task, ((TNpcPlayer *)player)->get_action_flags(), (u16) slot, ((TNpcPlayer *)player)->get_field_67c(), tl_00);
        }
        (this->m_1c)++;
    }
    return ((u8 *)this);
}

s32 get_party_yaw(void) {
    return *(s32 *)((s8 *)&lbl_80478C88.value + (TLobby::get_instance() * 4));
}

u8 *get_party_position(void) {
    return (u8 *)&party_position_table.value + (TLobby::get_instance() * 0xC);
}
typedef char RecoveredGlobal_8034DE70_lbl_80478C50_size[sizeof(RecoveredGlobal_8034DE70_lbl_80478C50) == 0x18 ? 1 : -1];

s32 TNpcPlayer__sub_8034DE40(void) {
    return *(s32 *)((s8 *)&lbl_80478C68.value + (TLobby::get_instance() * 4));
}

u8 *TNpcPlayer::get_lobby_entry_ptr() {
    return (u8 *)&npc_lobby_entry_positions.value + (TLobby::get_instance() * 0xC);
}
typedef char RecoveredGlobal_8034DEA0_TNpcPlayer__data_804ABC90_size[sizeof(RecoveredGlobal_8034DEA0_TNpcPlayer__data_804ABC90) == 0xA00 ? 1 : -1];
void TNpcPlayer::copy_entry_by_index(s32 arg1) {
    s32 arg0 = (s32)this;
    s32 temp_r5;
    temp_r5 = arg1 * 0x28;
    copy__10TNpcPlayerFPv((void *) ((u8 *)&TNpcPlayer__template_table.value + temp_r5), (void *)arg0, (int)temp_r5);
}

}
