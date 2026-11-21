#include "types.h"
#include "pso/unk/text_8006E82C.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"

s32 fn_8006E82C(s32 client_id) {
    return TWindowKeyBoardHard::test_card_flag_2(client_id) ? 0x10000 : 0x20000;
}
