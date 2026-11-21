#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCardList.h"

extern "C" {


s32 TWindowSubComCard::create_card_list(saddr parent, s32 card_slot, s32 arg2, s32 arg3) {
    fn_80266378(7);
    return (saddr)new TWindowSubComCardList((void *)parent, card_slot, arg2, arg3);
}

}
