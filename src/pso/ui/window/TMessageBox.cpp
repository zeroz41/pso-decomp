#include "pso/network/protocol/packet_classes.h"
#include "pso/ui/window/TMessageBox.h"
#include "pso/player/TPlyGuildCardTag.h"

extern "C" {

s32 bswap__13packet_headerFv();

void bswap__11TMessageBoxFv(s32 arg0) {
    bswap__13packet_headerFv();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
}

}

TMessageBox::TMessageBox() {}
