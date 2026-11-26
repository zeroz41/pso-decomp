#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "types.h"
#include "pso/object/warp/ForestWarpResources.h"
#include "pso/network/TGameProtocol.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/system/byteswap.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"



void G_SetBossWarpFlags_6x6A::send() {
    bswap();
    send_subcommand(this);
}

void G_SetBossWarpFlags_6x6A::bswap() {
    ((G_ClientIDHeader *)&header)->bswap();
    bswap_16((u16 *)&flags);
    bswap_16(&unused);
}

void G_SetBossWarpFlags_6x6A::init() {
    header.subcommand = 0x6A;
    header.size = 2;
}

int TWindowSubTradeMain::get_warp_state() {  return quest_warp_enabled; }

void TWindowMenuIconLine::set_close_flag() { state_flags |= 0x80; }
void TWindowMenuIconLine::disable_input() { state_flags |= 0x40; }


void *TObjGbAdvance::create(void *placement) {
    return new TObjGbAdvance(static_cast<TObject *>(tl_05), static_cast<ObjectSetData *>(placement));
}

