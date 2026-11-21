#include "pso/network/protocol/packet_classes.h"
#include "pso/ui/window/TMessageBox.h"
#include "pso/player/TPlyGuildCardTag.h"

extern "C" {


void bswap__11TMessageBoxFv(saddr arg0) {
    ((packet_header *)arg0)->bswap();
    ((TPlyGuildCardTag *)(arg0 + 4))->bswap();
}

}

TMessageBox::TMessageBox() {}
