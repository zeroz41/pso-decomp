#include "types.h"
#include "pso/unk/text_8006E82C.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

s32 fn_8006E82C(void *p) {
    return TBoss8Dragon::test_card_flag_2((saddr)p) ? 0x10000 : 0x20000;
}
