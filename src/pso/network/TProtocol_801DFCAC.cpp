#include "pso/network/protocol/packet_classes.h"
#include "pso/player/TPlyCharData.h"
#include "pso/system/memory.h"
#include <stddef.h>
#include "pso/network/TProtocol.h"
LAYOUT_ASSERT(SendActionSize, sizeof(TSendAction<0>) == 12);
LAYOUT_ASSERT(SendActionTagOffset, offsetof(TSendAction<0>, tag) == 4);
LAYOUT_ASSERT(NamedActionSize, sizeof(TSendAction<1>) == 0x1C);
LAYOUT_ASSERT(PasswordActionSize, sizeof(TSendAction<2>) == 0x1C);
LAYOUT_ASSERT(NamedPasswordActionSize, sizeof(TSendAction<3>) == 0x2C);
LAYOUT_ASSERT(NamedActionNameOffset, offsetof(TSendAction<1>, name) == 0xC);
LAYOUT_ASSERT(PasswordActionPasswordOffset, offsetof(TSendAction<2>, password) == 0xC);
LAYOUT_ASSERT(NamedPasswordActionNameOffset, offsetof(TSendAction<3>, name) == 0xC);
LAYOUT_ASSERT(NamedPasswordActionPasswordOffset, offsetof(TSendAction<3>, password) == 0x1C);
LAYOUT_ASSERT(TPlyJoinDataSize, sizeof(TPlyJoinData) == 0x87C);
LAYOUT_ASSERT(TPlyJoinDataAutoReplyOffset, offsetof(TPlyJoinData, auto_reply) == 0x67C);

TPlyJoinData::~TPlyJoinData() {}

TPlyJoinData::TPlyJoinData() {}

template<> void TSendAction<0>::bswap() {
    header.bswap();
    tag.bswap();
}

template<> TSendAction<0>::TSendAction() {}

void TSendAction<3>::bswap() {
    header.bswap();
    tag.bswap();
}

TSendAction<3>::TSendAction() {}

void TSendAction<2>::bswap() {
    header.bswap();
    tag.bswap();
}

TSendAction<2>::TSendAction() {}

void TSendAction<1>::bswap() {
    header.bswap();
    tag.bswap();
}

TSendAction<1>::TSendAction() {}
