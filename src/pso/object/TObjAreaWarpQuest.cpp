#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/object/TObjAreaWarpQuest.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void TObjAreaWarpQuest__sub_8019DCD8(void* p, s32 v);
void fn_8019DD24(void* p, u32 v);

s32 TObjAreaWarpQuest::get_dest_area() { return *(s32 *)&this->m_next; }
void TObjAreaWarpQuest__sub_8019DCD8(void* p, s32 v) { *(s32*)((char*)p + 0x3c8) = v; }
}
void bswap_6x94_inter_level_warp(void* p);
void mask_action_buttons(void* p, u32 v);
void bswap_6x94_inter_level_warp(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16((u16 *)((char*)p + 0x4)); }
void mask_action_buttons(void* p, u32 v) { *(u32*)((char*)p + 0x8) &= ~v; }
void fn_8019DD24(void* p, u32 v) { *(u32*)((char*)p + 0x8) |= v; }
