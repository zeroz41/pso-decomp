#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubComCardList.h"

extern "C" {


s32 TWindowSubComCard::create_card_list(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    fn_80266378(7);
    return (s32)new TWindowSubComCardList((void *)arg0, arg1, arg2, arg3);
}

}
