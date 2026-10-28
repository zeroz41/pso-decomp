#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TWindowSubSymbolChat_8007763C.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TWindowSubSymbolChat.h"

extern "C" {


void*TWindowSubSymbolChat::get_data_ptr() { return (char*)this + 0x1c; }
void TWindowSubSymbolChat::bswap_symbol_chat_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x4)); ((TWindowSubSymbolChat *)((char*)this + 0x8))->byteswap_entry(); }
void TWindowSubSymbolChat::byteswap_entry() { bswap_32((u32 *)this); { int i; for (i = 0; i < 4; i++) { bswap_16((u16 *)((char*)this + 0x4 + i * 2)); } } }
void TWindowSubSymbolChat::send_symbol_chat() { bswap_symbol_chat_packet(); update_players__6TLobbyFv((s32)this); }
void TWindowSubSymbolChat__sub_80077704(void* p) { *(u8*)((char*)p + 0x0) = 7; *(u8*)((char*)p + 0x1) = 17; }

    extern int selected_symbol_chat_preset;
int TWindowSubSymbolChat::get_instance() {  return selected_symbol_chat_preset; }

int TWindowSubSymbolChat::is_initialized() { return *(u32 *)&this->m_name & 0x1; }
void TWindowSubSymbolChat::bswap_entry() { bswap_32((u32 *)this); ((TWindowSubSymbolChat *)((char*)this + 0x1c))->byteswap_entry(); }

}
