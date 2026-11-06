#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

void TLobby::bswap_4_words() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }
