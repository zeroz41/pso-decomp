#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_80105A2C.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

    extern const float lbl_805DAAB0;

void TLobby::dispatch_packet_wrapper() { bswap_6x60_drop_request_fields(this); send_subcommand_to_leader(this); }

void bswap_6x60_drop_request_fields(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x6)); bswap_16((u16 *)((char*)p + 0x10)); bswap_16((u16 *)((char*)p + 0x12)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); }
void *build_6x06_send_guild_card(void *arg0) {
    build_6x05_write_switch_flag(arg0);
    *(s8 *)((s8 *)arg0 + 0) = 0x60;
    *(s8 *)((s8 *)arg0 + 1) = 6;
    return arg0;
}
void build_6x05_write_switch_flag(void* a0) { *(float*)((char*)a0 + 0xc) = lbl_805DAAB0; *(float*)((char*)a0 + 0x8) = lbl_805DAAB0; *(short*)((char*)a0 + 0x10) = 0; *(short*)((char*)a0 + 0x12) = 0; *(unsigned char*)((char*)a0 + 0x5) = 0; *(unsigned char*)((char*)a0 + 0x4) = 0; *(unsigned char*)((char*)a0 + 0x0) = 96; *(unsigned char*)((char*)a0 + 0x1) = 5; }

void TLobby::process_and_dispatch_packet() { bswap_6xa2_fields(); send_subcommand_to_leader(this); }
void TLobby::bswap_6xa2_fields() { bswap_6x60_drop_request_fields(this); bswap_32((u32 *)((char*)this + 0x18)); bswap_32((u32 *)((char*)this + 0x1c)); bswap_32((u32 *)((char*)this + 0x20)); bswap_32((u32 *)((char*)this + 0x24)); }
void *TLobby::build_6x06_guild_card_packet() {
    build_6x06_send_guild_card(this);
    *((u8 *)this + 0) = 0xA2;
    *((u8 *)this + 1) = 0x0A;
    return this;
}
