#include "pso/network/protocol/packet_classes.h"
#include "pso/player/TPlySmth.h"
#include "pso/network/TProtocol.h"

struct ByteBlock_8 { u8 bytes[0x8]; };

#pragma inline_depth(1)
#pragma auto_inline on
#pragma dont_inline off
extern "C" {

void __as__8TPlySmthFRC8TPlySmth(saddr arg0, saddr arg1) {
    *(ByteBlock_8 *)(arg0) = *(const ByteBlock_8 *)(arg1);
}

}

TSendLogin::TSendLogin() {}

TPlySmth::TPlySmth() {}

#pragma push
#pragma auto_inline off
#pragma dont_inline on
TCreateGame::TCreateGame() {}
#pragma pop
