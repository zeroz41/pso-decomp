#include "types.h"
#include "pso/unk/TLobby_801DEFC4.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/network/TProtocol_801E08CC.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/item/TItemData.h"
#include "pso/network/protocol/protocol.h"


void bswap_cmd_D3_item_bank(void* p) { ((packet_header *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x4)); bswap_16((u16 *)((char*)p + 0x6)); { int i; for (i = 0; i < 32; i++) { ((TItemData *)((char*)p + 0x8 + i * 20))->bswap(); } } }
void TLobby__sub_801DF024(void *p) { ((packet_header *)p)->bswap(); }
void TLobby::bswap_cmd_d8_header() { ((packet_header *)this)->bswap(); }
void TLobby__sub_801DF064(void *p) { ((packet_header *)p)->bswap(); }
void TLobby::bswap_c6_packet() { ((packet_header *)this)->bswap(); { int i; for (i = 0; i < 30; i++) { bswap_32((u32 *)((char*)this + 0x4 + i * 4)); } } }
void bswap_cmd_c5(void* p) { ((packet_header *)p)->bswap(); { int i; for (i = 0; i < 12; i++) { ((TLobby *)((char*)p + 0x4 + i * 284))->bswap_cmd_c5(); } } }
void TLobby::bswap_cmd_c5() { bswap_32((u32 *)this); ((TLobby *)((char*)this + 0x4))->bswap_challenge_battle_records(); bswap_16((u16 *)((char*)this + 0x104)); bswap_16((u16 *)((char*)this + 0x106)); bswap_16((u16 *)((char*)this + 0x108)); bswap_16((u16 *)((char*)this + 0x10a)); bswap_16((u16 *)((char*)this + 0x10c)); bswap_16((u16 *)((char*)this + 0x10e)); bswap_16((u16 *)((char*)this + 0x110)); bswap_16((u16 *)((char*)this + 0x112)); bswap_32((u32 *)((char*)this + 0x114)); bswap_32((u32 *)((char*)this + 0x118)); }
void TLobby::bswap_guild_card_meet_user() { ((packet_header *)this)->bswap(); ((TPlyGuildCardTag *)((char*)this + 0x4))->bswap(); bswap_ply_smth_pair(((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x14)); bswap__21TPlyMeetUserExtensionFv((saddr)((char*)this + 0xec)); }

