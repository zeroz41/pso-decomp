#include "types.h"
#include "pso/unk/text_8033BAB4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


s32 fn_8033BAB4(void) {
    s32 flags = 0;
    switch (TAdSinglePlyChrSelectGC::verify_card_player_data()) {
    case -2:
        flags |= 0x30;
        break;
    case -3:
    case -1:
        flags |= 0x10;
        break;
    }
    return flags;
}
