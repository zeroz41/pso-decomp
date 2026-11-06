#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

s32 TWindowSubStatusDisp::calc_layout_hash() {
    return TWindowSubStatusDisp::get_layout_id() * 0x8C9F;
}

s32 TWindowSubStatusDisp::calc_entry_offset() {
    return TWindowSubStatusDisp::get_layout_id() * 0x12C;
}

#include "pso/unk/TLobby.h"
#pragma fp_contract on

struct RecoveredGlobal_8006F23C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_8006F1EC_lbl_8048C9D8
{
  s32 value;
  u8 remaining[0x744];
};

struct O_8006F0D8 { u8 pad[4]; s32 a[(0xec - 4) / 4]; s32 def; };

struct E_8006F134 { s32 a; s32 b; };

struct O_8006F134 { u8 pad[0xc0]; E_8006F134 e[4]; s32 pad2; E_8006F134 def; };

extern "C" {
s32 is_flag_set__6TLobbyFv();
extern RecoveredGlobal_8006F23C_lbl_8048C9D8 challenge_mode_state;
s32 is_split_screen(void);
extern s32 lbl_80438590[];
s32 *TWindowSubStatusDisp__sub_8006F0D8(O_8006F0D8 *self, s32 slot);
extern s32 lbl_80438584[];
E_8006F134 *TWindowSubStatusDisp__sub_8006F134(O_8006F134 *self, s32 slot);
extern s32 lbl_8043859C[];

typedef s32 (*SlotQueryNoArgs_8006F094)(void);

s32 TWindowSubStatusDisp::get_layout_id() {
    if (((SlotQueryNoArgs_8006F094)TWindowSubStatusDisp::resolve_player_slot)() < 3) {
        return lbl_8043859C[((SlotQueryNoArgs_8006F094)TWindowSubStatusDisp::resolve_player_slot)()];
    }
    return 5;
}
typedef char RecoveredGlobal_8006F23C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_8006F23C_lbl_8048C9D8) == 0x748 ? 1 : -1];

typedef struct RecoveredGlobal_8006F1EC_lbl_8048C9D8 RecoveredGlobal_8006F1EC_lbl_8048C9D8;
#pragma optimize_for_size off
typedef char RecoveredGlobal_8006F1EC_lbl_8048C9D8_size[((sizeof(RecoveredGlobal_8006F1EC_lbl_8048C9D8)) == 0x748) ? (1) : (-1)];

s32 *TWindowSubStatusDisp__sub_8006F0D8(O_8006F0D8 *self, s32 slot) {
    s32 idx = TWindowSubStatusDisp::resolve_player_slot(slot);
    if (idx < 3) {
        return &self->a[lbl_80438590[idx]];
    }
    return &self->def;
}

E_8006F134 *TWindowSubStatusDisp__sub_8006F134(O_8006F134 *self, s32 slot) {
    s32 idx = TWindowSubStatusDisp::resolve_player_slot(slot);
    if (idx < 3) {
        return &self->e[lbl_80438584[idx]];
    }
    return &self->def;
}

s32 TWindowSubStatusDisp::resolve_player_slot(s32 slot) {
    switch (slot) {
    case -1:
        if (is_split_screen()) {
            s32 inst = TLobby::get_instance();
            s32 r = 2;
            if (inst == 1) {
                r = 3;
            }
            return r;
        }
        return (TLobby::get_instance() == 1) ? 1 : 0;
    }
    return slot;
}

s32 TLobby::get_flagged_table_entry(s32 arg0) {
  u8 *new_var;
  if (is_flag_set__6TLobbyFv() != 0)
  {
    new_var = (u8 *) (&(*(RecoveredGlobal_8006F1EC_lbl_8048C9D8 *)&challenge_mode_state).value);
    new_var = new_var + (arg0 * 4);
    return *((s32 *) (((s8 *) new_var) + 0x38));
  }
  return 0;
}

s32 TLobby::get_flag_value_if_set() {
    if (is_flag_set__6TLobbyFv() != 0) {
        return *(s32 *)((s8 *)&challenge_mode_state.value + 0x34);
    }
    return 0;
}

}
