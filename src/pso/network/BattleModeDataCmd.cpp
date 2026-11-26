#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/network/BattleModeDataCmd.h"
#include "pso/network/TGameProtocol.h"
#include "pso/system/byteswap.h"
#include "pso/network/TLobby.h"
#include "pso/player/PlayerBattleScore.h"

void DamageStatSlot::reset() {
    set_total(0.0f);
    set_accumulated(0.0f);
}

void DamageStatSlot::set_accumulated(f32 v) { accumulated = v; }
s32 PlayerSubObjectSlots::get_score() { return score; }
void DamageStatSlot::set_normal_weight(f32 v) { normal_weight = v; }
void DamageStatSlot::set_bonus_weight(f32 v) { bonus_weight = v; }

void TLobby::send_set_battle_mode_data() { bswap_set_battle_mode_data(); send_subcommand((u8 *)this); }
void TLobby::bswap_set_battle_mode_data() { ((G_ClientIDHeader *)this)->bswap(); { int i; for (i = 0; i < 4; i++) { bswap_32((u32 *)((char*)this + 0x8 + i * 4)); } } }
void build_6x7D_set_battle_mode_data(void* p) { *(u8*)((char*)p + 0x0) = 125; *(u8*)((char*)p + 0x1) = 6; }
void TLobby::send_6x7D_set_battle_mode_data() { bswap_set_battle_mode_data(); send_subcommand_to_leader(this); }
