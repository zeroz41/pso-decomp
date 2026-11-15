#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/SoundEffect.h"

extern "C" {


void TBoss7Joint::read_state() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }
void TBoss7Joint::byteswap_action_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }
void TBoss7Joint::update_and_send_60() { byteswap_action_packet(); send_subcommand((u8 *)this); }
void TBoss7Joint__sub_802EE7B8(void* p) { *(u8*)((char*)p + 0x0) = 169; *(u8*)((char*)p + 0x1) = 2; }
void TBoss7Joint::broadcast_state() { read_state(); send_subcommand((u8 *)this); }
void TBoss7Joint__sub_802EE800(void* p) { *(u8*)((char*)p + 0x0) = 170; *(u8*)((char*)p + 0x1) = 3; }

}
