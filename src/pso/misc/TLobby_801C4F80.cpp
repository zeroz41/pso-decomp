#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_801C4F80.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"

extern "C" {

s32 TObjPlayer__sub_801C19C8(f32);

extern const f32 lbl_805DC300;

void TLobby::update_child_player() {
    s32 arg0 = (s32)this;
    TObjPlayer__sub_801C19C8(lbl_805DC300);
    set_float_4(lbl_805DC300);
}

void TLobby::set_float_4(f32 v) { *(f32 *)&this->m_flags = v; }
s32 TLobby__sub_801C4FC4(void* p) { return *(s32*)((char*)p + 0x14); }
void TLobby::set_pos_z(f32 v) { *(f32 *)&this->m_prev = v; }
void TLobby::set_scale(f32 v) { *(f32 *)&this->m_next = v; }
void TLobby::send_set_battle_mode_data() { bswap_set_battle_mode_data(); send_subcommand((u8 *)this); }
void TLobby::bswap_set_battle_mode_data() { ((G_ClientIDHeader *)this)->bswap(); { int i; for (i = 0; i < 4; i++) { bswap_32((u32 *)((char*)this + 0x8 + i * 4)); } } }
void build_6x7D_set_battle_mode_data(void* p) { *(u8*)((char*)p + 0x0) = 125; *(u8*)((char*)p + 0x1) = 6; }
void TLobby::send_6x7D_set_battle_mode_data() { bswap_set_battle_mode_data(); send_subcommand_to_leader(this); }

}
