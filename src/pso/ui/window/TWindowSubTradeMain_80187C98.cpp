#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/network/TGameProtocol.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/system/byteswap.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"



void TWindowSubTradeMain::send_60_update() { bswap_6x6A_packet(); send_subcommand(this); }

void TWindowSubTradeMain::bswap_6x6A_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void TWindowSubTradeMain::init_pkt_cmd_6A() { *(u8 *)&this->m_name = 106; *(u8*)((char*)this + 0x1) = 2; }

int TWindowSubTradeMain::get_warp_state() {  return quest_warp_enabled; }

void TWindowMenuIconLine::set_close_flag() { state_flags |= 0x80; }
void TWindowMenuIconLine::disable_input() { state_flags |= 0x40; }


void *TObjGbAdvance::create(void *placement) {
    return new TObjGbAdvance(static_cast<TObject *>(tl_05), static_cast<ObjectSetData *>(placement));
}

