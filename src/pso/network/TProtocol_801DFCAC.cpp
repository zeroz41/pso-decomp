#include "pso/network/protocol/packet_classes.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TPlyCharData_8007214C.h"
#include "pso/network/TProtocol_801DFCAC.h"
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

s32 destroy__9TProtocolFis(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        ((TPlyJoinData *)arg0)->char_data.~TPlyCharData();
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

s32 TProtocol::init_char_data() {
    saddr arg0 = (saddr)this;
    __ct__12TPlyCharDataFv(arg0 + 4);
    return arg0;
}

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
