#include "types.h"
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubComCardList.h"



s32 TWindowSubComCard::create_card_list(saddr parent, s32 card_slot, s32 count, s32 empty_message) {
    fn_80266378(7);
    return (saddr)new TWindowSubComCardList((const NJS_POINT2 *)parent, card_slot, count, empty_message);
}

